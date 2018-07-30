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
 * ten_synsdsync_tx.c
 *
 * $Id: ten_syncdsync_tx.c,v 1.15 2013/05/10 17:08:54 jccarlis Exp $
 *
 * API's for SYNCDSYNC TX
 *
 */

#include "tenabo40.h"
 
/********************************************************************/
/* $rtn_hdr_start  SYNCDSYNCTX CONFIG                               */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : SYNCDSYNC                                           */
/* CHIP       : Tenabo                                              */
cs_status ten_syncdsynctx_cfg(cs_uint16 module_id,
                              cs_uint8  slice, 
                              cs_uint16 rxdivmux,
                              cs_uint32 numerator_ms,
                              cs_uint32 numerator_ls,
                              cs_uint32 denominator_ms,
                              cs_uint32 denominator_ls,
                              cs_uint32 ac1_ms,
                              cs_uint32 ac1_ls,
                              cs_uint32 ac2_ms,
                              cs_uint32 ac2_ls,
                              cs_uint32 ad1,
                              cs_uint32 ad2,
                              cs_uint16 cfg_mode,
                              cs_uint16 cfg_pd0,
                              cs_uint16 cfg_jc_gen_thrld,
                              cs_uint16 cfg_jc_gen_max_jp)
/* INPUTS     : o Module Id                                         */
/*              o Slice                                             */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Configures TX side of the syncdsync block.                       */
/*                                                                  */
/*   [slice]  Specified as TEN_SLICE0 (0), TEN_SLICE1 (1),          */
/*     TEN_SLICE2 (2), TEN_SLICE3 (3) or TEN_SLICE_ALL (0xFF)       */
/*                                                                  */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  cs_uint16 dev_id = TEN_MOD_ID_TO_DEV_ID(module_id);
  cs_uint16 mod_num = TEN_MOD_ID_TO_MOD_NUM(module_id);
  cs_status rtn = CS_OK;
  
  CS_PRINT("ten_syncdsynctx_cfg, %s, %s\n",  ten_module_strings[module_id&1], ten_slice_strings[slice]);
  CS_PRINT("    RXDIVMUX            = 0x%04X\n", rxdivmux);
  CS_PRINT("    NUMERATOR_MS        = 0x%04X\n", numerator_ms);
  CS_PRINT("    NUMERATOR_LS        = 0x%04X\n", numerator_ls);
  CS_PRINT("    DENOMINATOR_MS      = 0x%04X\n", denominator_ms);
  CS_PRINT("    DENOMINATOR_LS      = 0x%04X\n", denominator_ls);
  CS_PRINT("    AC1_MS              = 0x%04X\n", ac1_ms);
  CS_PRINT("    AC1_LS              = 0x%04X\n", ac1_ls);
  CS_PRINT("    AC2_MS              = 0x%04X\n", ac2_ms);
  CS_PRINT("    AC2_LS              = 0x%04X\n", ac2_ls);
  CS_PRINT("    AD1                 = 0x%04X\n", ad1);
  CS_PRINT("    AD2                 = 0x%04X\n", ad2);
  CS_PRINT("    CFG_MODE            = 0x%04X\n", cfg_mode);
  CS_PRINT("    CFGPD0_DSYNC_PD_MD  = 0x%04X\n", cfg_pd0);
  CS_PRINT("    CFG_JCGEN_THRLD     = 0x%04X\n", cfg_jc_gen_thrld);
  CS_PRINT("    CFG_JCGEN_MAX_JP    = 0x%04X\n", cfg_jc_gen_max_jp);
  
  rtn |= ten_mpif_global_reset_syncdsync(dev_id, mod_num, slice, CS_TX, CS_RESET_TOGGLE);

  rtn |= ten_syncdsynctx_control_sreset(module_id, slice, CS_RESET_ASSERT);

  rtn |= ten_syncdsynctx_set_configuration_rx_div_mux(module_id, slice, rxdivmux);

  rtn |= ten_syncdsynctx_set_numerator(module_id, slice, 
                                       TEN_SYNCDSYNC_LOWER16(numerator_ms), 
                                       TEN_SYNCDSYNC_UPPER16(numerator_ls), 
                                       TEN_SYNCDSYNC_LOWER16(numerator_ls));

  rtn |= ten_syncdsynctx_set_denominator(module_id, slice, 
                                         TEN_SYNCDSYNC_LOWER16(denominator_ms),
                                         TEN_SYNCDSYNC_UPPER16(denominator_ls),
                                         TEN_SYNCDSYNC_LOWER16(denominator_ls));
  
  rtn |= ten_syncdsynctx_set_ac1(module_id, slice, 
                                 TEN_SYNCDSYNC_LOWER16(ac1_ms),
                                 TEN_SYNCDSYNC_UPPER16(ac1_ls),
                                 TEN_SYNCDSYNC_LOWER16(ac1_ls));

  rtn |= ten_syncdsynctx_set_ac2(module_id, slice,
                                 TEN_SYNCDSYNC_LOWER16(ac2_ms),
                                 TEN_SYNCDSYNC_UPPER16(ac2_ls),
                                 TEN_SYNCDSYNC_LOWER16(ac2_ls));

  rtn |= ten_syncdsynctx_set_ad1(module_id, slice, 
                                 TEN_SYNCDSYNC_UPPER16(ad1),
                                 TEN_SYNCDSYNC_LOWER16(ad1));

  rtn |= ten_syncdsynctx_set_ad2(module_id, slice, 
                                 TEN_SYNCDSYNC_UPPER16(ad2),
                                 TEN_SYNCDSYNC_LOWER16(ad2));

  rtn |= ten_syncdsynctx_set_mode(module_id, slice, cfg_mode);

  rtn |= ten_syncdsynctx_cfgtx_cfgpd0(module_id, slice, cfg_pd0);

  rtn |= ten_syncdsynctx_jcgen_configuration(module_id, slice, 
                                             cfg_jc_gen_thrld, cfg_jc_gen_max_jp);
  
  /* Bug 23629 start */
  rtn |= ten_syncdsynctx_set_configuration_init_prot_en(module_id, slice, CS_RESET_ASSERT);
  rtn |= ten_syncdsynctx_control_sreset(module_id, slice, CS_RESET_DEASSERT);
  /* Bug 23629 end */
  
  return (rtn);
}

/****************************************************************/
/* $rtn_hdr_start  SYNCDSYNC CONFIG 1 TO 1                      */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : HIGH LEVEL                                      */
/* CHIP       : Tenabo                                          */
cs_status ten_syncdsync_config_1_to_1(cs_uint16 module_id,
                                         cs_uint8  slice,
                                         cs_uint16 rxdivmux,
                                         cs_dir_t  dir,
                                         cs_uint16 k)
/* INPUTS     : o Module Id                                     */
/*              o Slice                                         */
/*              o Rx Div Mux                                    */
/*              o Direction                                     */
/*              o K                                             */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* Provision syncdsync for 1:1 mapping.                         */
/*                                                              */
/* [slice]  Specified as TEN_SLICE0 (0), TEN_SLICE1 (1),        */
/*     TEN_SLICE2 (2), TEN_SLICE3 (3) or TEN_SLICE_ALL (0xFF)   */
/*                                                              */
/*   [rxdivmux]                                               */
/*     8:1 multiplexer pairs the selected Rx divided clock with */
/*     the Tx:                                                  */
/*     000 = A side #1                                          */
/*     001 = A side #2                                          */
/*     010 = A side #3                                          */
/*     011 = A side #4                                          */
/*     100 = B side #1                                          */
/*     101 = B side #2                                          */
/*     110 = B side #3                                          */
/*     111 = B side #4                                          */
/*                                                              */
/* The [dir] parameter is specified as:                         */
/*   0 = CS_TX                                                  */
/*   1 = CS_RX                                                  */
/*   2 = CS_TX_AND_RX                                           */
/*                                                              */
/* The [k] specified as:  k value.                              */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  cs_status rtn = CS_OK;
  cs_uint16 jc_thresh;
  cs_uint16 num_pjo = 1;
  cs_char8 *func = "ten_syncdsync_config_1_to_1";  

  if (rxdivmux > 7) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, "%s() rxdivmux %d out of range.  s/b 0..7", func, rxdivmux);
    return (CS_ERROR);
  }
  if (dir > CS_TX_AND_RX) { 
    CS_HNDL_ERROR(module_id, ETEN_DEV_INVALID_USER_ARG, "%s() dir %d out of range.  s/b 0..2", func, dir); 
    return CS_ERROR; 
  }
  
  CS_PRINT("%s() %s, ", func, ten_module_strings[module_id&1]);
  if (slice == TEN_SLICE_ALL) {
    CS_PRINT("SLICE_ALL");
  }
  else if (slice < TEN_MAX_SLICES) {
    CS_PRINT("%s", ten_slice_strings[slice]);
  } else {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, "%s() slice %d out of range.  s/b 0..3. 255", func, slice);
    return (CS_ERROR);
  }
  CS_PRINT(", rxdivmux source %s, %s, k=%d\n", ten_syncdsync_rx_div_mux_strings[rxdivmux], ten_dir_strings[dir], k);

  if (dir == CS_RX) {
    rtn |= ten_syncdsyncrx_cfg(module_id,
                               slice, 
                               0,        /* numerator_ms   */
                               1,        /* numerator_ls   */
                               0,        /* denominator_ms */
                               k,        /* denominator_ls */
                               0,        /* ac1_ms         */
                               0,        /* ac1_ls         */
                               0,        /* ac2_ms         */
                               0,        /* ac2_ls         */    /* Bugzilla 24779/24799 */
                               0,        /* ad1            */
                               0,        /* ad2            */    /* Bugzilla 24779/24799 */
                               0);       /* cfg_mode       */
  }
  else {
    jc_thresh = (cs_uint16)(((2 * k)/((2 * num_pjo) + 1)));
    rtn |= ten_syncdsynctx_cfg(module_id,
                               slice, 
                               rxdivmux,   /* rxdivmux          */
                               0,          /* numerator_ms      */
                               1,          /* numerator_ls      */
                               0,          /* denominator_ms    */
                               k,          /* denominator_ls    */
                               0,          /* ac1_ms            */
                               0,          /* ac1_ls            */
                               0,          /* ac2_ms            */
                               0,          /* ac2_ls            */  /* Bugzilla 24779 */
                               0,          /* ad1               */
                               0,          /* ad2               */  /* Bugzilla 24779 */
                               0,          /* cfg_mode          */
                               1,          /* cfg_pd0           */
                               jc_thresh,  /* cfg_jc_gen_thrld  */
                               num_pjo);   /* cfg_jc_gen_max_jp */
  }
  return (rtn);
}

/********************************************************************/
/* $rtn_hdr_start  SYNCDSYNCTX SOFT (LOGIC) RESET                   */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : SYNCDSYNC                                           */
/* CHIP       : Tenabo                                              */
cs_status ten_syncdsynctx_control_sreset(cs_uint16 module_id,
                                         cs_uint8 slice, 
                                         cs_reset_action_t act)
/* INPUTS     : o Module Id                                         */
/*              o Slice                                             */
/*              o Reset Action                                      */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Control SYNCDSYNC TX logic reset.                                */
/*                                                                  */
/*   [slice]  Specified as TEN_SLICE0 (0), TEN_SLICE1 (1),          */
/*     TEN_SLICE2 (2), TEN_SLICE3 (3) or TEN_SLICE_ALL (0xFF)       */
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
  TEN_SYNCDSYNCTX_CFGTX_CFG_t tmp_cfgtx_cfg;
  TEN_MPIF_GLOBAL_RESET_SYNCDSYNC_t tmp_global_reset_syncdsync;
  T41_t *pDev = NULL;
  cs_uint16 tmp = 0;

  if ((slice>=TEN_MAX_SLICES) && (slice != TEN_SLICE_ALL)) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": slice out of range.  s/b 0..3.");
    return(CS_ERROR);
  }

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  
  CS_PRINT("module_id=0x%04X, slice=%d, action=%d\n", module_id, slice, act);
  
  TEN_MOD_LOCK(module_id, TEN_ID_SYNCDSYNC);
  for (sl=0; sl<TEN_MAX_SLICES; sl++) {
    if ((slice == sl) || (slice == TEN_SLICE_ALL)) {
     /* Bugzilla #22850, fix bus errors */
      tmp_global_reset_syncdsync.wrd = TEN_REG_READ(TEN_MPIF_REG_ADDR(pDev, GLOBAL_RESET_SYNCDSYNC));
      tmp = (1 << (sl + (TEN_MOD_ID_TO_MOD_NUM(module_id)*4)));
      CS_PRINT("sl=%d, tmp=%04X\n", sl, tmp);
      if (tmp_global_reset_syncdsync.bf.tx & tmp) {
        CS_PRINT("WARNING:  MPIF_GLOBAL_RESET_SYNCDSYNC tx still in hard reset\n");
      }
      else {
        tmp_cfgtx_cfg.wrd = 0;
        tmp_cfgtx_cfg.bf.RESET_SW = 1; /* set mask */
        ten_reset_action(TEN_SYNCDSYNCTX_REG_ADDR(pDev, module_id, sl, cfgtx_CFG), tmp_cfgtx_cfg.wrd, act);
      }
    }
  }
  TEN_MOD_UNLOCK(module_id, TEN_ID_SYNCDSYNC);

  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  SYNCDSYNCTX SET MODE                             */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : SYNCDSYNC                                           */
/* CHIP       : Tenabo                                              */
cs_status ten_syncdsynctx_set_mode(cs_uint16 module_id, cs_uint8 slice, 
                                   cs_uint16 mode)
/* INPUTS     : o Module Id                                         */
/*              o Slice                                             */
/*              o Mode                                              */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Set the Synchronizer and Desynchronizer Tx Configuration Mode.   */
/*                                                                  */
/*   [slice]  Specified as TEN_SLICE0 (0), TEN_SLICE1 (1),          */
/*     TEN_SLICE2 (2), TEN_SLICE3 (3), or TEN_SLICE_ALL (0xFF)      */
/*                                                                  */
/*   [mode]                                                         */
/*     (0) = OXU2(OPU2) client (monolithic dewrapping 1 level of    */
/*           justification)                                         */
/*     (1) = OXU3(OPU3) client (monolithic dewrapping 1 level of    */
/*           justification)                                         */
/*     (2) = OXU3(ODTU23) client (deagreggation 1 level of          */
/*           justification)                                         */
/*     (3) = OXU3(ODTU23) ODU2(OPU2) client (deagreggation 2 levels */
/*           of justification).                                     */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  cs_uint16 sl;
  TEN_SYNCDSYNCTX_CFGTX_CFG_t tmp_cfgtx_cfg;
  T41_t *pDev = NULL;

  if ((slice>=TEN_MAX_SLICES) && (slice != TEN_SLICE_ALL)) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": slice out of range.  s/b 0..3.");
    return(CS_ERROR);
  }

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_SYNCDSYNC);
  for (sl=0; sl<TEN_MAX_SLICES; sl++) {
    if ((slice == sl) || (slice == TEN_SLICE_ALL)) {
      tmp_cfgtx_cfg.wrd = TEN_REG_READ(TEN_SYNCDSYNCTX_REG_ADDR(pDev, module_id, sl, cfgtx_CFG));
      tmp_cfgtx_cfg.bf.MODE = mode;
      TEN_REG_WRITE(TEN_SYNCDSYNCTX_REG_ADDR(pDev, module_id, sl, cfgtx_CFG), tmp_cfgtx_cfg.wrd);
    }
  }
  TEN_MOD_UNLOCK(module_id, TEN_ID_SYNCDSYNC);

  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  SYNCDSYNCTX SET CONFIGURATION RX DIV MUX         */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : SYNCDSYNC                                           */
/* CHIP       : Tenabo                                              */
cs_status ten_syncdsynctx_set_configuration_rx_div_mux(cs_uint16 module_id, 
                                cs_uint8 slice, 
                                cs_uint16 rx_div_mux)
/* INPUTS     : o Module Id                                         */
/*              o Slice                                             */
/*              o RX DIV MUX                                        */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Sets Rx Div Mux.                                                 */
/*                                                                  */
/*   [slice]  Specified as TEN_SLICE0 (0), TEN_SLICE1 (1),          */
/*     TEN_SLICE2 (2), TEN_SLICE3 (3), or TEN_SLICE_ALL (0xFF)      */
/*                                                                  */
/*   [rx_div_mux]                                                   */
/*     8:1 multiplexer pairs the selected Rx divided clock with     */
/*     the Tx:                                                      */
/*     000 = A side #1                                              */
/*     001 = A side #2                                              */
/*     010 = A side #3                                              */
/*     011 = A side #4                                              */
/*     100 = B side #1                                              */
/*     101 = B side #2                                              */
/*     110 = B side #3                                              */
/*     111 = B side #4                                              */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  cs_uint16 sl;
  TEN_SYNCDSYNCTX_CFGTX_CFG_t tmp_cfgtx_cfg;
  T41_t *pDev = NULL;
  cs_char8 *func = "ten_syncdsynctx_set_configuration_rx_div_mux";  

  CS_PRINT("%s() %s, ", func, ten_module_strings[module_id&1]);

  if (rx_div_mux > 7) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, "%s() rx_div_mux %d out of range.  s/b 0..7", func, rx_div_mux);
    return (CS_ERROR);
  }  

  if (slice == TEN_SLICE_ALL) {
    CS_PRINT("SLICE_ALL");
  }
  else if (slice < TEN_MAX_SLICES) {
    CS_PRINT("%s", ten_slice_strings[slice]);
  } else {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, "%s() slice %d out of range.  s/b 0..3. 255", func, slice);
    return (CS_ERROR);
  }
  CS_PRINT(", rx_div_mux source %s\n", ten_syncdsync_rx_div_mux_strings[rx_div_mux]);


  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_SYNCDSYNC);
  for (sl=0; sl<TEN_MAX_SLICES; sl++) {
    if ((slice == sl) || (slice == TEN_SLICE_ALL)) {
      tmp_cfgtx_cfg.wrd = TEN_REG_READ(TEN_SYNCDSYNCTX_REG_ADDR(pDev, module_id, sl, cfgtx_CFG));
      tmp_cfgtx_cfg.bf.RX_DIV_MUX = rx_div_mux;
      TEN_REG_WRITE(TEN_SYNCDSYNCTX_REG_ADDR(pDev, module_id, sl, cfgtx_CFG), tmp_cfgtx_cfg.wrd);
    }
  }
  TEN_MOD_UNLOCK(module_id, TEN_ID_SYNCDSYNC);

  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  SYNCDSYNCTX SET CONFIGURATION INIT PROT EN       */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : SYNCDSYNC                                           */
/* CHIP       : Tenabo                                              */
cs_status ten_syncdsynctx_set_configuration_init_prot_en(cs_uint16 module_id, 
                                cs_uint8 slice, 
                                cs_uint16 init_prot_en)
/* INPUTS     : o Module Id                                         */
/*              o Slice                                             */
/*              o INIT PROT EN                                      */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Set Protection Switch Mux initialization.                        */
/*                                                                  */
/*   [slice]  Specified as TEN_SLICE0 (0), TEN_SLICE1 (1),          */
/*     TEN_SLICE2 (2), TEN_SLICE3 (3), or TEN_SLICE_ALL (0xFF)      */
/*                                                                  */
/*   [init_prot_en] When set to 1, Protection Switch Mux            */
/*     initialization                                               */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  cs_uint16 sl;
  TEN_SYNCDSYNCTX_CFGTX_CFG_t tmp_cfgtx_cfg;
  T41_t *pDev = NULL;

  if ((slice>=TEN_MAX_SLICES) && (slice != TEN_SLICE_ALL)) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": slice out of range.  s/b 0..3.");
    return(CS_ERROR);
  }

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_SYNCDSYNC);
  for (sl=0; sl<TEN_MAX_SLICES; sl++) {
    if ((slice == sl) || (slice == TEN_SLICE_ALL)) {
      tmp_cfgtx_cfg.wrd = TEN_REG_READ(TEN_SYNCDSYNCTX_REG_ADDR(pDev, module_id, sl, cfgtx_CFG));
      tmp_cfgtx_cfg.bf.INIT_PROT_EN = init_prot_en;
      TEN_REG_WRITE(TEN_SYNCDSYNCTX_REG_ADDR(pDev, module_id, sl, cfgtx_CFG), tmp_cfgtx_cfg.wrd);
    }
  }
  TEN_MOD_UNLOCK(module_id, TEN_ID_SYNCDSYNC);

  return (CS_OK);
}

/* Bugzilla 23629 Start */
/********************************************************************/
/* $rtn_hdr_start  SYNCDSYNCTX SET CONFIGURATION INIT FORCE         */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : SYNCDSYNC                                           */
/* CHIP       : Tenabo                                              */
cs_status ten_syncdsynctx_set_configuration_init_force(cs_uint16 module_id, 
                                                       cs_uint8 slice, 
                                                       cs_reset_action_t act)
/* INPUTS     : o Module Id                                         */
/*              o Slice                                             */
/*              o Reset Action                                      */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Sets TX clock divider initialization.                            */
/*                                                                  */
/*   [slice]  Specified as TEN_SLICE0 (0), TEN_SLICE1 (1),          */
/*     TEN_SLICE2 (2), TEN_SLICE3 (3), or TEN_SLICE_ALL (0xFF)      */
/*                                                                  */
/*   [act]  Reset option specified as CS_RESET_DEASSERT,            */
/*     CS_RESET_ASSERT or CS_RESET_TOGGLE.                          */
/*     The CS_RESET_TOGGLE option will assert reset, hold the       */
/*     reset bit(s) for 20 milliseconds and then de-assert.         */
/*     enabled.                                                     */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  cs_uint16 sl;
  TEN_SYNCDSYNCTX_CFGTX_CFG_t tmp_cfgtx_cfg;
  TEN_MPIF_GLOBAL_RESET_SYNCDSYNC_t tmp_global_reset_syncdsync;
  cs_uint16 tmp = 0;

  T41_t *pDev = NULL;
  cs_char8 *func = "ten_syncdsynctx_set_configuration_init_force";  

  if ((slice >= TEN_MAX_SLICES) && (slice != TEN_SLICE_ALL)) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, "%s()  slice %d out of range.  s/b 0..3.", func, slice);
    return(CS_ERROR);
  }
  if(act > CS_RESET_TOGGLE) { 
    CS_HNDL_ERROR(module_id, ETEN_DEV_INVALID_USER_ARG, "%s() act %d out of range.  s/b 0..2.", func, act); 
    return CS_ERROR; 
  }
  
  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_SYNCDSYNC);
  for (sl=0; sl<TEN_MAX_SLICES; sl++) {
    if ((slice == sl) || (slice == TEN_SLICE_ALL)) {
      /* Bug #39491,  Fix bus errors */
      tmp_global_reset_syncdsync.wrd = TEN_REG_READ(TEN_MPIF_REG_ADDR(pDev, GLOBAL_RESET_SYNCDSYNC));
      tmp = (1 << (sl + (TEN_MOD_ID_TO_MOD_NUM(module_id)*4)));
      CS_PRINT("sl=%d, tmp=%04X\n", sl, tmp);
      if (tmp_global_reset_syncdsync.bf.tx & tmp) {
        CS_PRINT("MPIF_GLOBAL_RESET_SYNCDSYNC tx still in hard reset\n");
      }
      else {
        tmp_cfgtx_cfg.wrd = 0;
        tmp_cfgtx_cfg.bf.INIT_FORCE = 1; /* set mask */
        ten_reset_action(TEN_SYNCDSYNCTX_REG_ADDR(pDev, module_id, sl, cfgtx_CFG), tmp_cfgtx_cfg.wrd, act);
      }
    }
  }
  TEN_MOD_UNLOCK(module_id, TEN_ID_SYNCDSYNC);

  return (CS_OK);
}
/* Bugzilla 23629 End */

/********************************************************************/
/* $rtn_hdr_start  SYNCDSYNCTX SELECT GLOBAL TIMING SOURCE          */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : SYNCDSYNC                                           */
/* CHIP       : Tenabo                                              */
cs_status ten_syncdsynctx_select_global_timing_source(cs_uint16 module_id, 
                                   cs_uint8 slice, 
                                   cs_uint16 select)
/* INPUTS     : o Module Id                                         */
/*              o Slice                                             */
/*              o Select                                            */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Selects one of the eight global timing sources.  Each event      */
/* generated by that source triggers copying of statistics          */
/* counters to the appropriate registers of the processor           */
/*                                                                  */
/*   [slice]  Specified as TEN_SLICE0 (0), TEN_SLICE1 (1),          */
/*     TEN_SLICE2 (2), TEN_SLICE3 (3), or TEN_SLICE_ALL (0xFF)      */
/*                                                                  */
/*   [select] 0-7.                                                  */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  cs_uint16 sl;
  TEN_SYNCDSYNCTX_CFGMONTX_CFG_t tmp_cfgmontx_cfg;
  T41_t *pDev = NULL;

  if ((slice>=TEN_MAX_SLICES) && (slice != TEN_SLICE_ALL)) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": slice out of range.  s/b 0..3.");
    return(CS_ERROR);
  }

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_SYNCDSYNC);
  for (sl=0; sl<TEN_MAX_SLICES; sl++) {
    if ((slice == sl) || (slice == TEN_SLICE_ALL)) {
      tmp_cfgmontx_cfg.wrd = TEN_REG_READ(TEN_SYNCDSYNCTX_REG_ADDR(pDev, module_id, sl, cfgmontx_CFG));
      tmp_cfgmontx_cfg.bf.EOFGCFG = select;
      TEN_REG_WRITE(TEN_SYNCDSYNCTX_REG_ADDR(pDev, module_id, sl, cfgmontx_CFG), tmp_cfgmontx_cfg.wrd);
    }
  }
  TEN_MOD_UNLOCK(module_id, TEN_ID_SYNCDSYNC);

  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  SYNCDSYNCTX CFGTX CFGPD0 PHASE 0 EN              */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : SYNCDSYNC                                           */
/* CHIP       : Tenabo                                              */
cs_status ten_syncdsynctx_cfgtx_cfgpd0_phase0_en(cs_uint16 module_id, 
                                   cs_uint8 slice, 
                                   cs_uint16 phase_0_en)
/* INPUTS     : o Module Id                                         */
/*              o Slice                                             */
/*              o PHASE 0 EN                                        */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Controls phase 0 enable.                                         */
/*                                                                  */
/*   [slice]  Specified as TEN_SLICE0 (0), TEN_SLICE1 (1),          */
/*     TEN_SLICE2 (2), TEN_SLICE3 (3), or TEN_SLICE_ALL (0xFF)      */
/*                                                                  */
/*   [phase_0_en]  When set to 1, OUT_RANGE condition forces the    */
/*     output Phase to zero.                                        */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  cs_uint16 sl;
  TEN_SYNCDSYNCTX_CFGTX_CFGPD0_t tmp_cfgtx_cfgpd0;
  T41_t *pDev = NULL;

  if ((slice >= TEN_MAX_SLICES) && (slice != TEN_SLICE_ALL)) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": slice out of range.  s/b 0..3.");
    return(CS_ERROR);
  }

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_SYNCDSYNC);
  for (sl=0; sl<TEN_MAX_SLICES; sl++) {
    if ((slice == sl) || (slice == TEN_SLICE_ALL)) {
      tmp_cfgtx_cfgpd0.wrd = TEN_REG_READ(TEN_SYNCDSYNCTX_REG_ADDR(pDev, module_id, sl, CFGPD0));
      tmp_cfgtx_cfgpd0.bf.PHASE_0_EN = phase_0_en;
      TEN_REG_WRITE(TEN_SYNCDSYNCTX_REG_ADDR(pDev, module_id, sl, CFGPD0), tmp_cfgtx_cfgpd0.wrd);
    }
  }
  TEN_MOD_UNLOCK(module_id, TEN_ID_SYNCDSYNC);

  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  SYNCDSYNCTX CFGTX CFGPD0                         */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : SYNCDSYNC                                           */
/* CHIP       : Tenabo                                              */
cs_status ten_syncdsynctx_cfgtx_cfgpd0(cs_uint16 module_id, cs_uint8 slice, 
                                   cs_uint16 dsync_pd_md)
/* INPUTS     : o Module Id                                         */
/*              o Slice                                             */
/*              o DSYNC PD MD                                       */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:  Synchronizer and Desynchronizer Tx Configuration   */
/* of two-state vs. three-state phase detector.                     */
/*                                                                  */
/*   [slice]  Specified as TEN_SLICE0 (0), TEN_SLICE1 (1),          */
/*     TEN_SLICE2 (2), TEN_SLICE3 (3), or TEN_SLICE_ALL (0xFF)      */
/*                                                                  */
/*   [dsync_pd_md]  two-state vs. three-state phase detector        */
/*    1 = three-state PD is on.                                     */
/*    0 = two-state PD is on.                                       */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  cs_uint16 sl;
  TEN_SYNCDSYNCTX_CFGTX_CFGPD0_t tmp_cfgtx_cfgpd0;
  T41_t *pDev = NULL;

  if ((slice >= TEN_MAX_SLICES) && (slice != TEN_SLICE_ALL)) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": slice out of range.  s/b 0..3.");
    return(CS_ERROR);
  }

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_SYNCDSYNC);
  for (sl=0; sl<TEN_MAX_SLICES; sl++) {
    if ((slice == sl) || (slice == TEN_SLICE_ALL)) {
      tmp_cfgtx_cfgpd0.wrd = TEN_REG_READ(TEN_SYNCDSYNCTX_REG_ADDR(pDev, module_id, sl, CFGPD0));
      tmp_cfgtx_cfgpd0.bf.DSYNC_PD_MD = dsync_pd_md;
      TEN_REG_WRITE(TEN_SYNCDSYNCTX_REG_ADDR(pDev, module_id, sl, CFGPD0), tmp_cfgtx_cfgpd0.wrd);
    }
  }
  TEN_MOD_UNLOCK(module_id, TEN_ID_SYNCDSYNC);

  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  SYNCDSYNCTX JCGEN CONFIGURATION                  */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : SYNCDSYNC                                           */
/* CHIP       : Tenabo                                              */
cs_status ten_syncdsynctx_jcgen_configuration(cs_uint16 module_id, cs_uint8 slice, 
                                     cs_uint16 jc_gen_thrld, 
                                     cs_uint16 jc_gen_max_jp)
/* INPUTS     : o Module Id                                         */
/*              o Slice                                             */
/*              o JC GEN THRLD                                      */
/*              o JC GEN MAX JP                                     */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Set JC GEN Configuration                                         */
/*                                                                  */
/*   [slice]  Specified as TEN_SLICE0 (0), TEN_SLICE1 (1),          */
/*     TEN_SLICE2 (2), TEN_SLICE3 (3), or TEN_SLICE_ALL (0xFF)      */
/*                                                                  */
/*   [jc_gen_thrld]  Sets the justification threshold size          */
/*     (typically between 16 and 64)                                */
/*                                                                  */
/*   [jc_gen_max_jp]  Sets the number of positive justifications.   */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  cs_uint16 sl;
  TEN_SYNCDSYNCTX_CFGTX_CFGJCGEN_t tmp_cfgtx_cfgjcgen;
  T41_t *pDev = NULL;

  if ((slice>=TEN_MAX_SLICES) && (slice != TEN_SLICE_ALL)) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": slice out of range.  s/b 0..3.");
    return(CS_ERROR);
  }

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_SYNCDSYNC);
  for (sl=0; sl<TEN_MAX_SLICES; sl++) {
    if ((slice == sl) || (slice == TEN_SLICE_ALL)) {
      tmp_cfgtx_cfgjcgen.wrd = TEN_REG_READ(TEN_SYNCDSYNCTX_REG_ADDR(pDev, module_id, sl, CFGJCGEN));
      tmp_cfgtx_cfgjcgen.bf.JC_GEN_THRLD = jc_gen_thrld;
      tmp_cfgtx_cfgjcgen.bf.JC_GEN_MAX_JP = jc_gen_max_jp;
      TEN_REG_WRITE(TEN_SYNCDSYNCTX_REG_ADDR(pDev, module_id, sl, CFGJCGEN), tmp_cfgtx_cfgjcgen.wrd);
    }
  }
  TEN_MOD_UNLOCK(module_id, TEN_ID_SYNCDSYNC);

  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  SYNCDSYNCTX SET DENOMINATOR                      */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : SYNCDSYNC                                           */
/* CHIP       : Tenabo                                              */
cs_status ten_syncdsynctx_set_denominator(cs_uint16 module_id, cs_uint8 slice, 
                                            cs_uint16 denominator2,
                                            cs_uint16 denominator1,
                                            cs_uint16 denominator0)
/* INPUTS     : o Module Id                                         */
/*              o Slice                                             */
/*              o DENOMINATOR2                                      */
/*              o DENOMINATOR1                                      */
/*              o DENOMINATOR0                                      */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Number of bytes per OTN frame multiplied by k (n*k).             */
/* For applications involving a single level of mapping, n is the   */
/* number of bytes per OxUk frame.                                  */
/* For applications involving two levels of mapping, this is the    */
/* product n = n1 * n2, where:                                      */
/* - n1 is the number of bytes per OxU3 frame                       */
/* - n2 is the number of client bytes per ODU2 frame.               */
/*                                                                  */
/*   [slice]  Specified as TEN_SLICE0 (0), TEN_SLICE1 (1),          */
/*     TEN_SLICE2 (2), TEN_SLICE3 (3), or TEN_SLICE_ALL (0xFF)      */
/*                                                                  */
/*   [denominator2]  most significant bits                          */
/*                                                                  */
/*   [denominator1]  middle significant bits                        */
/*                                                                  */
/*   [denominator0]  least significant bits.                        */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  cs_uint16 sl;
  TEN_SYNCDSYNCTX_CFGTX_DENOMINATOR2_t tmp_cfgtx_denominator2;
  TEN_SYNCDSYNCTX_CFGTX_DENOMINATOR1_t tmp_cfgtx_denominator1;
  TEN_SYNCDSYNCTX_CFGTX_DENOMINATOR0_t tmp_cfgtx_denominator0;
  T41_t *pDev = NULL;

  if ((slice>=TEN_MAX_SLICES) && (slice != TEN_SLICE_ALL)) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": slice out of range.  s/b 0..3.");
    return(CS_ERROR);
  }

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_SYNCDSYNC);
  for (sl=0; sl<TEN_MAX_SLICES; sl++) {
    if ((slice == sl) || (slice == TEN_SLICE_ALL)) {
      tmp_cfgtx_denominator2.wrd = TEN_REG_READ(TEN_SYNCDSYNCTX_REG_ADDR(pDev,
                                   module_id, sl, DENOMINATOR2));
      tmp_cfgtx_denominator2.bf.DENOMINATOR2 = denominator2;
      TEN_REG_WRITE(TEN_SYNCDSYNCTX_REG_ADDR(pDev, module_id, sl, DENOMINATOR2), 
                                             tmp_cfgtx_denominator2.wrd);
      
       tmp_cfgtx_denominator1.wrd = TEN_REG_READ(TEN_SYNCDSYNCTX_REG_ADDR(pDev, 
                                    module_id, sl, DENOMINATOR1));
      tmp_cfgtx_denominator1.bf.DENOMINATOR1 = denominator1;
      TEN_REG_WRITE(TEN_SYNCDSYNCTX_REG_ADDR(pDev, module_id, sl, DENOMINATOR1), 
                                             tmp_cfgtx_denominator1.wrd);
      
      tmp_cfgtx_denominator0.wrd = TEN_REG_READ(TEN_SYNCDSYNCTX_REG_ADDR(pDev, 
                                   module_id, sl, DENOMINATOR0));
      tmp_cfgtx_denominator0.bf.DENOMINATOR0 = denominator0;
      TEN_REG_WRITE(TEN_SYNCDSYNCTX_REG_ADDR(pDev, module_id, sl, DENOMINATOR0), 
                                             tmp_cfgtx_denominator0.wrd);
    }
  }
  TEN_MOD_UNLOCK(module_id, TEN_ID_SYNCDSYNC);

  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  SYNCDSYNCTX SET NUMERATOR                        */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : SYNCDSYNC                                           */
/* CHIP       : Tenabo                                              */
cs_status ten_syncdsynctx_set_numerator(cs_uint16 module_id, cs_uint8 slice, 
                                          cs_uint16 numerator2,
                                          cs_uint16 numerator1,
                                          cs_uint16 numerator0)
/* INPUTS     : o Module Id                                         */
/*              o Slice                                             */
/*              o NUMERATOR2                                        */
/*              o NUMERATOR1                                        */
/*              o NUMERATOR0                                        */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* For applications involving a single level mapping this is the    */
/* number of client bytes per OxUk frame in absence of asynchronous */
/* justifications (synchronous component).                          */
/* For applications involving two levels of mapping, this is the    */
/* product m = m1 * m2, where:                                      */
/* - m1 is the number of client bytes per ODTU23 frame in absence   */
/*   f asynchronous justifications (synchronous component)          */
/* - m2 is the number of client bytes per ODU2 frame in absence     */ 
/*   of asynchronous justifications (synchronous component).        */
/*                                                                  */
/*   [slice]  Specified as TEN_SLICE0 (0), TEN_SLICE1 (1),          */
/*     TEN_SLICE2 (2), TEN_SLICE3 (3), or TEN_SLICE_ALL (0xFF)      */
/*                                                                  */
/*   [numerator2] most significant bits                             */
/*                                                                  */
/*   [numerator1] middle significant bits                           */
/*                                                                  */
/*   [numerator2] least significant bits.                           */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  cs_uint16 sl;
  TEN_SYNCDSYNCTX_CFGTX_NUMERATOR2_t tmp_cfgtx_numerator2;
  TEN_SYNCDSYNCTX_CFGTX_NUMERATOR1_t tmp_cfgtx_numerator1;
  TEN_SYNCDSYNCTX_CFGTX_NUMERATOR0_t tmp_cfgtx_numerator0;
  T41_t *pDev = NULL;

  if ((slice>=TEN_MAX_SLICES) && (slice != TEN_SLICE_ALL)) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": slice out of range.  s/b 0..3.");
    return(CS_ERROR);
  }

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_SYNCDSYNC);
  for (sl=0; sl<TEN_MAX_SLICES; sl++) {
    if ((slice == sl) || (slice == TEN_SLICE_ALL)) {
      tmp_cfgtx_numerator2.wrd = TEN_REG_READ(TEN_SYNCDSYNCTX_REG_ADDR(pDev, module_id, sl, NUMERATOR2));
      tmp_cfgtx_numerator2.bf.NUMERATOR2 = numerator2;
      TEN_REG_WRITE(TEN_SYNCDSYNCTX_REG_ADDR(pDev, module_id, sl, NUMERATOR2), tmp_cfgtx_numerator2.wrd);
      
      tmp_cfgtx_numerator1.wrd = TEN_REG_READ(TEN_SYNCDSYNCTX_REG_ADDR(pDev, module_id, sl, NUMERATOR1));
      tmp_cfgtx_numerator1.bf.NUMERATOR1 = numerator1;
      TEN_REG_WRITE(TEN_SYNCDSYNCTX_REG_ADDR(pDev, module_id, sl, NUMERATOR1), tmp_cfgtx_numerator1.wrd);
     
      tmp_cfgtx_numerator0.wrd = TEN_REG_READ(TEN_SYNCDSYNCTX_REG_ADDR(pDev, module_id, sl, NUMERATOR0));
      tmp_cfgtx_numerator0.bf.NUMERATOR0 = numerator0;
      TEN_REG_WRITE(TEN_SYNCDSYNCTX_REG_ADDR(pDev, module_id, sl, NUMERATOR0), tmp_cfgtx_numerator0.wrd);
    }
  }
  TEN_MOD_UNLOCK(module_id, TEN_ID_SYNCDSYNC);

  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  SYNCDSYNCTX SET AC1                              */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : SYNCDSYNC                                           */
/* CHIP       : Tenabo                                              */
cs_status ten_syncdsynctx_set_ac1(cs_uint16 module_id, cs_uint8 slice, 
                                    cs_uint16 ac12,
                                    cs_uint16 ac11,
                                    cs_uint16 ac10)
/* INPUTS     : o Module Id                                         */
/*              o Slice                                             */
/*              o AC12                                              */
/*              o AC11                                              */
/*              o AC10                                              */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* This parameter is only used by applications involving two levels */
/* of asynchronous mapping.  In order to ensure proper operation,   */
/* the AC1 parameter must be configured as n1 * m2, where:          */
/* - n1 is the number of bytes per OxU3 frame                       */
/* - m2 is the number of client bytes per ODU2 frame in absence     */
/*   of asynchronous justifications (synchronous component).        */
/*                                                                  */
/*   [slice]  Specified as TEN_SLICE0 (0), TEN_SLICE1 (1),          */
/*     TEN_SLICE2 (2), TEN_SLICE3 (3), or TEN_SLICE_ALL (0xFF)      */
/*                                                                  */
/*   [ac12]  most significant bits                                  */
/*                                                                  */
/*   [ac11]  middle significant bits                                */
/*                                                                  */
/*   [ac10]  least significant bits.                                */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  cs_uint16 sl;
  TEN_SYNCDSYNCTX_CFGTX_AC12_t tmp_cfgtx_ac12;
  TEN_SYNCDSYNCTX_CFGTX_AC11_t tmp_cfgtx_ac11;
  TEN_SYNCDSYNCTX_CFGTX_AC10_t tmp_cfgtx_ac10;
  T41_t *pDev = NULL;

  if ((slice>=TEN_MAX_SLICES) && (slice != TEN_SLICE_ALL)) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": slice out of range.  s/b 0..3.");
    return(CS_ERROR);
  }

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_SYNCDSYNC);
  for (sl=0; sl<TEN_MAX_SLICES; sl++) {
    if ((slice == sl) || (slice == TEN_SLICE_ALL)) {
      tmp_cfgtx_ac12.wrd = TEN_REG_READ(TEN_SYNCDSYNCTX_REG_ADDR(pDev, module_id, sl, AC12));
      tmp_cfgtx_ac12.bf.AC12 = ac12;
      TEN_REG_WRITE(TEN_SYNCDSYNCTX_REG_ADDR(pDev, module_id, sl, AC12), tmp_cfgtx_ac12.wrd);
     
      tmp_cfgtx_ac11.wrd = TEN_REG_READ(TEN_SYNCDSYNCTX_REG_ADDR(pDev, module_id, sl, AC11));
      tmp_cfgtx_ac11.bf.AC11 = ac11;
      TEN_REG_WRITE(TEN_SYNCDSYNCTX_REG_ADDR(pDev, module_id, sl, AC11), tmp_cfgtx_ac11.wrd);
     
      tmp_cfgtx_ac10.wrd = TEN_REG_READ(TEN_SYNCDSYNCTX_REG_ADDR(pDev, module_id, sl, AC10));
      tmp_cfgtx_ac10.bf.AC10 = ac10;
      TEN_REG_WRITE(TEN_SYNCDSYNCTX_REG_ADDR(pDev, module_id, sl, AC10), tmp_cfgtx_ac10.wrd);
    }
  }
  TEN_MOD_UNLOCK(module_id, TEN_ID_SYNCDSYNC);

  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  SYNCDSYNCTX SET AC2                              */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : SYNCDSYNC                                           */
/* CHIP       : Tenabo                                              */
cs_status ten_syncdsynctx_set_ac2(cs_uint16 module_id, cs_uint8 slice, 
                                    cs_uint16 ac22,
                                    cs_uint16 ac21, 
                                    cs_uint16 ac20)
/* INPUTS     : o Module Id                                         */
/*              o Slice                                             */
/*              o AC22                                              */
/*              o AC21                                              */
/*              o AC20                                              */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* This parameter is only used by applications involving            */
/* asynchronous mapping (one or two levels of mapping).             */
/* In order to ensure proper operation, the AC2 parameter must be   */
/* configured as n:                                                 */
/* For applications involving a single level of mapping, n is the   */
/* number of bytes per OxUk frame.                                  */
/* For applications involving two levels of mapping, this is the    */
/* product n = n1 * n2, where:                                      */
/* - n1 is the number of bytes per OxU3 frame                       */
/* - n2 is the number of client bytes per ODU2 frame.               */
/*                                                                  */
/*   [slice]  Specified as TEN_SLICE0 (0), TEN_SLICE1 (1),          */
/*     TEN_SLICE2 (2), TEN_SLICE3 (3), or TEN_SLICE_ALL (0xFF)      */
/*                                                                  */
/*   [ac22]  most significant bits                                  */
/*                                                                  */
/*   [ac21]  middle significant bits                                */
/*                                                                  */
/*   [ac20]  least significant bits.                                */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  cs_uint16 sl;
  TEN_SYNCDSYNCTX_CFGTX_AC22_t tmp_cfgtx_ac22;
  TEN_SYNCDSYNCTX_CFGTX_AC21_t tmp_cfgtx_ac21;
  TEN_SYNCDSYNCTX_CFGTX_AC20_t tmp_cfgtx_ac20;
  T41_t *pDev = NULL;

  if ((slice>=TEN_MAX_SLICES) && (slice != TEN_SLICE_ALL)) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": slice out of range.  s/b 0..3.");
    return(CS_ERROR);
  }

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_SYNCDSYNC);
  for (sl=0; sl<TEN_MAX_SLICES; sl++) {
    if ((slice == sl) || (slice == TEN_SLICE_ALL)) {
      tmp_cfgtx_ac22.wrd = TEN_REG_READ(TEN_SYNCDSYNCTX_REG_ADDR(pDev, module_id, sl, AC22));
      tmp_cfgtx_ac22.bf.AC22 = ac22;
      TEN_REG_WRITE(TEN_SYNCDSYNCTX_REG_ADDR(pDev, module_id, sl, AC22), tmp_cfgtx_ac22.wrd);
      
      tmp_cfgtx_ac21.wrd = TEN_REG_READ(TEN_SYNCDSYNCTX_REG_ADDR(pDev, module_id, sl, AC21));
      tmp_cfgtx_ac21.bf.AC21 = ac21;
      TEN_REG_WRITE(TEN_SYNCDSYNCTX_REG_ADDR(pDev, module_id, sl, AC21), tmp_cfgtx_ac21.wrd);
      
      tmp_cfgtx_ac20.wrd = TEN_REG_READ(TEN_SYNCDSYNCTX_REG_ADDR(pDev, module_id, sl, AC20));
      tmp_cfgtx_ac20.bf.AC20 = ac20;
      TEN_REG_WRITE(TEN_SYNCDSYNCTX_REG_ADDR(pDev, module_id, sl, AC20), tmp_cfgtx_ac20.wrd);
    }
  }
  TEN_MOD_UNLOCK(module_id, TEN_ID_SYNCDSYNC);

  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  SYNCDSYNCTX SET AD1                              */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : SYNCDSYNC                                           */
/* CHIP       : Tenabo                                              */
cs_status ten_syncdsynctx_set_ad1(cs_uint16 module_id, cs_uint8 slice, 
                                    cs_uint16 ad11,
                                    cs_uint16 ad10)
/* INPUTS     : o Module Id                                         */
/*              o Slice                                             */
/*              o AD11                                              */
/*              o AD10                                              */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* This parameter is only used by applications involving two levels */
/* of asynchronous mapping. In order to ensure proper operation,    */
/* the AD1 parameter must be configured as m2 * dr1, where:         */
/* - m2 is the number of client bytes per ODU2 frame in absence     */
/*   of asynchronous justifications (synchronous component)         */
/* - dr1 is the maximum number of positive justifications used by   */
/*   the ODTU23 structure: 4*1, 4*2, 4*3, ..., or 4*6.              */
/*                                                                  */
/*   [slice]  Specified as TEN_SLICE0 (0), TEN_SLICE1 (1),          */
/*     TEN_SLICE2 (2), TEN_SLICE3 (3), or TEN_SLICE_ALL (0xFF)      */
/*                                                                  */
/*   [ad11]  most significant bits                                  */
/*                                                                  */
/*   [ad10]  least significant bits.                                */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  cs_uint16 sl;
  TEN_SYNCDSYNCTX_CFGTX_AD11_t tmp_cfgtx_ad11;
  TEN_SYNCDSYNCTX_CFGTX_AD10_t tmp_cfgtx_ad10;
  T41_t *pDev = NULL;

  if ((slice>=TEN_MAX_SLICES) && (slice != TEN_SLICE_ALL)) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": slice out of range.  s/b 0..3.");
    return(CS_ERROR);
  }

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_SYNCDSYNC);
  for (sl=0; sl<TEN_MAX_SLICES; sl++) {
    if ((slice == sl) || (slice == TEN_SLICE_ALL)) {
      tmp_cfgtx_ad11.wrd = TEN_REG_READ(TEN_SYNCDSYNCTX_REG_ADDR(pDev, module_id, sl, AD11));
      tmp_cfgtx_ad11.bf.AD11 = ad11;
      TEN_REG_WRITE(TEN_SYNCDSYNCTX_REG_ADDR(pDev, module_id, sl, AD11), tmp_cfgtx_ad11.wrd);
      
      tmp_cfgtx_ad10.wrd = TEN_REG_READ(TEN_SYNCDSYNCTX_REG_ADDR(pDev, module_id, sl, AD10));
      tmp_cfgtx_ad10.bf.AD10 = ad10;
      TEN_REG_WRITE(TEN_SYNCDSYNCTX_REG_ADDR(pDev, module_id, sl, AD10), tmp_cfgtx_ad10.wrd);
    }
  }
  TEN_MOD_UNLOCK(module_id, TEN_ID_SYNCDSYNC);

  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  SYNCDSYNCTX SET AD2                              */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : SYNCDSYNC                                           */
/* CHIP       : Tenabo                                              */
cs_status ten_syncdsynctx_set_ad2(cs_uint16 module_id, cs_uint8 slice, 
                                    cs_uint16 ad21,
                                    cs_uint16 ad20)
/* INPUTS     : o Module Id                                         */
/*              o Slice                                             */
/*              o AD21                                              */
/*              o AD20                                              */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* This parameter is only used by applications involving            */
/* asynchronous mapping (one or two levels of mapping).  In order   */
/* to ensure proper operation, the AD2 parameter must be configured */
/* as follows:                                                      */
/* For applications involving a single level of mapping, AD2 must   */
/* be configured as dr, where dr is the maximum number of positive  */
/* justifications:                                                  */
/* - dr = 1, 2, 3, ... or 6 for applications using a single level   */ 
/*   of mapping over OxU2                                           */
/* - dr = 4*1, 4*2, 4*3, ... or 4*6 for applications using a single */
/*   level of mapping over OxU3                                     */
/* - dr = 4*1, 4*2, 4*3, ... or 4*6 for applications using a single */
/*   level of mapping over ODTU23                                   */
/* For applications involving two levels of mapping, AD2 must be    */
/* configured as m1*dr2, where:                                     */
/* - m1 is the number of client bytes per ODTU23 structure in       */
/* absence of asynchronous justifications (synchronous component)   */
/* - dr2 is the number positive justifications used by the ODU2     */
/* frame: 1, 2, 3, ..., or 6.                                       */
/*                                                                  */
/*   [slice]  Specified as TEN_SLICE0 (0), TEN_SLICE1 (1),          */
/*     TEN_SLICE2 (2), TEN_SLICE3 (3), or TEN_SLICE_ALL (0xFF)      */
/*                                                                  */
/*   [ad21]  most significant bits                                  */
/*                                                                  */
/*   [ad20]  least significant bits.                                */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  cs_uint16 sl;
  TEN_SYNCDSYNCTX_CFGTX_AD21_t tmp_cfgtx_ad21;
  TEN_SYNCDSYNCTX_CFGTX_AD20_t tmp_cfgtx_ad20;
  T41_t *pDev = NULL;

  if ((slice>=TEN_MAX_SLICES) && (slice != TEN_SLICE_ALL)) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": slice out of range.  s/b 0..3.");
    return(CS_ERROR);
  }

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_SYNCDSYNC);
  for (sl=0; sl<TEN_MAX_SLICES; sl++) {
    if ((slice == sl) || (slice == TEN_SLICE_ALL)) {
      tmp_cfgtx_ad21.wrd = TEN_REG_READ(TEN_SYNCDSYNCTX_REG_ADDR(pDev, module_id, sl, AD21));
      tmp_cfgtx_ad21.bf.AD21 = ad21;
      TEN_REG_WRITE(TEN_SYNCDSYNCTX_REG_ADDR(pDev, module_id, sl, AD21), tmp_cfgtx_ad21.wrd);
      
      tmp_cfgtx_ad20.wrd = TEN_REG_READ(TEN_SYNCDSYNCTX_REG_ADDR(pDev, module_id, sl, AD20));
      tmp_cfgtx_ad20.bf.AD20 = ad20;
      TEN_REG_WRITE(TEN_SYNCDSYNCTX_REG_ADDR(pDev, module_id, sl, AD20), tmp_cfgtx_ad20.wrd);
    }
  }
  TEN_MOD_UNLOCK(module_id, TEN_ID_SYNCDSYNC);

  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  SYNCDSYNCTX SET ODTU23 PJO THRESHOLD             */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : SYNCDSYNC                                           */
/* CHIP       : Tenabo                                              */
cs_status ten_syncdsynctx_set_odtu23_pjo_threshold(cs_uint16 module_id, 
                                              cs_uint8 slice, 
                                              cs_uint16 odtu23_pjo_th1,
                                              cs_uint16 odtu23_pjo_th0)
/* INPUTS     : o Module Id                                         */
/*              o Slice                                             */
/*              o ODTU23 PJO TH1                                    */
/*              o ODTU23 PJO TH0                                    */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Sets the threshold for number of PJO to be compared with count   */
/* in ODU23_PJO and produce an interrupt if the threshold is        */
/* exceeded.                                                        */
/*                                                                  */
/*   [slice]  Specified as TEN_SLICE0 (0), TEN_SLICE1 (1),          */
/*     TEN_SLICE2 (2), TEN_SLICE3 (3), or TEN_SLICE_ALL (0xFF)      */
/*                                                                  */
/*   [odtu23_pjo_th1]  most significant bits                        */
/*                                                                  */
/*   [odtu23_pjo_th0]  least significant bits.                      */ 
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  cs_uint16 sl;
  TEN_SYNCDSYNCTX_CFGMONTX_ODTU23_PJO_TH1_t tmp_cfgmontx_odtu23_pjo_th1;
  TEN_SYNCDSYNCTX_CFGMONTX_ODTU23_PJO_TH0_t tmp_cfgmontx_odtu23_pjo_th0;
  T41_t *pDev = NULL;

  if ((slice>=TEN_MAX_SLICES) && (slice != TEN_SLICE_ALL)) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": slice out of range.  s/b 0..3.");
    return(CS_ERROR);
  }

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_SYNCDSYNC);
  for (sl=0; sl<TEN_MAX_SLICES; sl++) {
    if ((slice == sl) || (slice == TEN_SLICE_ALL)) {
      tmp_cfgmontx_odtu23_pjo_th1.wrd = TEN_REG_READ(TEN_SYNCDSYNCTX_REG_ADDR(pDev,
                                        module_id, sl, ODTU23_PJO_TH1));
      tmp_cfgmontx_odtu23_pjo_th1.bf.ODTU23_PJO_TH1 = odtu23_pjo_th1;
      TEN_REG_WRITE(TEN_SYNCDSYNCTX_REG_ADDR(pDev, module_id, sl, ODTU23_PJO_TH1),
                    tmp_cfgmontx_odtu23_pjo_th1.wrd);
                    
       tmp_cfgmontx_odtu23_pjo_th0.wrd = TEN_REG_READ(TEN_SYNCDSYNCTX_REG_ADDR(pDev, 
                                         module_id, sl, ODTU23_PJO_TH0));
      tmp_cfgmontx_odtu23_pjo_th0.bf.ODTU23_PJO_TH0 = odtu23_pjo_th0;
      TEN_REG_WRITE(TEN_SYNCDSYNCTX_REG_ADDR(pDev, module_id, sl, ODTU23_PJO_TH0),
                    tmp_cfgmontx_odtu23_pjo_th0.wrd);
    }
  }
  TEN_MOD_UNLOCK(module_id, TEN_ID_SYNCDSYNC);

  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  SYNCDSYNCTX SET ODTU23 NJO THRESHOLD             */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : SYNCDSYNC                                           */
/* CHIP       : Tenabo                                              */
cs_status ten_syncdsynctx_set_odtu23_njo_threshold(cs_uint16 module_id, cs_uint8 slice, 
                                              cs_uint16 odtu23_njo_th1,
                                              cs_uint16 odtu23_njo_th0)

/* INPUTS     : o Module Id                                         */
/*              o Slice                                             */
/*              o ODTU23 NJO TH1                                    */
/*              o ODTU23 NJO TH0                                    */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Sets the threshold for number of NJO to be compared with count   */
/* in ODU23_NJO and produce an interrupt if the threshold is        */
/* exceeded.                                                        */
/*                                                                  */
/*   [slice]  Specified as TEN_SLICE0 (0), TEN_SLICE1 (1),          */
/*     TEN_SLICE2 (2), TEN_SLICE3 (3), or TEN_SLICE_ALL (0xFF)      */
/*                                                                  */
/*   [odtu23_njo_th1]  most significant bits                        */
/*                                                                  */
/*   [odtu23_njo_th0]  least significant bits.                      */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  cs_uint16 sl;
  TEN_SYNCDSYNCTX_CFGMONTX_ODTU23_NJO_TH1_t tmp_cfgmontx_odtu23_njo_th1;
  TEN_SYNCDSYNCTX_CFGMONTX_ODTU23_NJO_TH0_t tmp_cfgmontx_odtu23_njo_th0;
  T41_t *pDev = NULL;

  if ((slice>=TEN_MAX_SLICES) && (slice != TEN_SLICE_ALL)) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": slice out of range.  s/b 0..3.");
    return(CS_ERROR);
  }

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_SYNCDSYNC);
  for (sl=0; sl<TEN_MAX_SLICES; sl++) {
    if ((slice == sl) || (slice == TEN_SLICE_ALL)) {
      tmp_cfgmontx_odtu23_njo_th1.wrd = TEN_REG_READ(TEN_SYNCDSYNCTX_REG_ADDR(pDev,
                                        module_id, sl, ODTU23_NJO_TH1));
      tmp_cfgmontx_odtu23_njo_th1.bf.ODTU23_NJO_TH1 = odtu23_njo_th1;
      TEN_REG_WRITE(TEN_SYNCDSYNCTX_REG_ADDR(pDev, module_id, sl, ODTU23_NJO_TH1),
                    tmp_cfgmontx_odtu23_njo_th1.wrd);
                    
      tmp_cfgmontx_odtu23_njo_th0.wrd = TEN_REG_READ(TEN_SYNCDSYNCTX_REG_ADDR(pDev, 
                                        module_id, sl, ODTU23_NJO_TH0));
      tmp_cfgmontx_odtu23_njo_th0.bf.ODTU23_NJO_TH0 = odtu23_njo_th0;
      TEN_REG_WRITE(TEN_SYNCDSYNCTX_REG_ADDR(pDev, module_id, sl, ODTU23_NJO_TH0),
                    tmp_cfgmontx_odtu23_njo_th0.wrd);
    }
  }
  TEN_MOD_UNLOCK(module_id, TEN_ID_SYNCDSYNC);

  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  SYNCDSYNCTX SET OXUN PJO THRESHOLD               */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : SYNCDSYNC                                           */
/* CHIP       : Tenabo                                              */
cs_status ten_syncdsynctx_set_oxun_pjo_threshold(cs_uint16 module_id, cs_uint8 slice, 
                                            cs_uint16 oxun_pjo_th1,
                                            cs_uint16 oxun_pjo_th0)

/* INPUTS     : o Module Id                                         */
/*              o Slice                                             */
/*              o OXUN PJO TH1                                      */
/*              o OXUN PJO TH0                                      */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Sets the threshold for number of PJO to be compared with count   */
/* in OXUN_PJO and produce an interrupt if the threshold is         */
/* exceeded.                                                        */
/* Note 1: X denotes D when dewrapping ODU or T when                */
/* dewrapping OTU.  N denotes 2 when dewrapping OTU2/ODU2 or 3      */
/* when dewrapping OTU3/ODU3.                                       */
/* Note 2: OXUN_PJO_TH #3 A-side and #7 B-side are used for         */
/* monolithic OXU3 (ODU3 or OTU3).                                  */
/* OXUN_PJO_TH #0, 1 and 2 are not used.                            */
/*                                                                  */
/*   [slice]  Specified as TEN_SLICE0 (0), TEN_SLICE1 (1),          */
/*     TEN_SLICE2 (2), TEN_SLICE3 (3), or TEN_SLICE_ALL (0xFF)      */
/*                                                                  */
/*   [oxun_pjo_th1]  most significant bits                          */
/*                                                                  */
/*   [oxun_pjo_th0]  least most significant bits.                   */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  cs_uint16 sl;
  TEN_SYNCDSYNCTX_CFGMONTX_OXUN_PJO_TH1_t tmp_cfgmontx_oxun_pjo_th1;
  TEN_SYNCDSYNCTX_CFGMONTX_OXUN_PJO_TH0_t tmp_cfgmontx_oxun_pjo_th0;
  T41_t *pDev = NULL;

  if ((slice>=TEN_MAX_SLICES) && (slice != TEN_SLICE_ALL)) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": slice out of range.  s/b 0..3.");
    return(CS_ERROR);
  }

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_SYNCDSYNC);
  for (sl=0; sl<TEN_MAX_SLICES; sl++) {
    if ((slice == sl) || (slice == TEN_SLICE_ALL)) {
      tmp_cfgmontx_oxun_pjo_th1.wrd = TEN_REG_READ(TEN_SYNCDSYNCTX_REG_ADDR(pDev,
                                      module_id, sl, OXUN_PJO_TH1));
      tmp_cfgmontx_oxun_pjo_th1.bf.OXUN_PJO_TH1 = oxun_pjo_th1;
      TEN_REG_WRITE(TEN_SYNCDSYNCTX_REG_ADDR(pDev, module_id, sl, OXUN_PJO_TH1),
                    tmp_cfgmontx_oxun_pjo_th1.wrd);
      
      tmp_cfgmontx_oxun_pjo_th0.wrd = TEN_REG_READ(TEN_SYNCDSYNCTX_REG_ADDR(pDev, 
                                      module_id, sl, OXUN_PJO_TH0));
      tmp_cfgmontx_oxun_pjo_th0.bf.OXUN_PJO_TH0 = oxun_pjo_th0;
      TEN_REG_WRITE(TEN_SYNCDSYNCTX_REG_ADDR(pDev, module_id, sl, OXUN_PJO_TH0),
                    tmp_cfgmontx_oxun_pjo_th0.wrd);
    }
  }
  TEN_MOD_UNLOCK(module_id, TEN_ID_SYNCDSYNC);

  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  SYNCDSYNCTX SET OXUN NJO THRESHOLD               */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : SYNCDSYNC                                           */
/* CHIP       : Tenabo                                              */
cs_status ten_syncdsynctx_set_oxun_njo_threshold(cs_uint16 module_id, cs_uint8 slice, 
                                            cs_uint16 oxun_njo_th1,
                                            cs_uint16 oxun_njo_th0)

/* INPUTS     : o Module Id                                         */
/*              o Slice                                             */
/*              o OXUN NJO TH1                                      */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Sets the threshold for number of NJO to be compared with count   */
/* in OXUN_NJO and produce an interrupt if the threshold is         */
/* exceeded.  Note 1: X denotes D when dewrapping ODU or T when     */
/* dewrapping OTU.  N denotes 2 when dewrapping OTU2/ODU2 or 3      */
/* when dewrapping OTU3/ODU3.  Note 2: OXUN_NJO_TH #3 A-side and #7 */
/* B-side are used for monolithic OXU3 (ODU3 or OTU3).              */
/* OXUN_NJO_TH #0, 1 and 2 are not used.                            */
/*                                                                  */
/*   [slice]  Specified as TEN_SLICE0 (0), TEN_SLICE1 (1),          */
/*     TEN_SLICE2 (2), TEN_SLICE3 (3), or TEN_SLICE_ALL (0xFF)      */
/*                                                                  */
/*   [oxun_njo_th1]  most significant bits                          */
/*                                                                  */
/*   [oxun_njo_th0]  least significant bits.                        */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  cs_uint16 sl;
  TEN_SYNCDSYNCTX_CFGMONTX_OXUN_NJO_TH1_t tmp_cfgmontx_oxun_njo_th1;
  TEN_SYNCDSYNCTX_CFGMONTX_OXUN_NJO_TH0_t tmp_cfgmontx_oxun_njo_th0;
  T41_t *pDev = NULL;

  if ((slice>=TEN_MAX_SLICES) && (slice != TEN_SLICE_ALL)) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": slice out of range.  s/b 0..3.");
    return(CS_ERROR);
  }

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_SYNCDSYNC);
  for (sl=0; sl<TEN_MAX_SLICES; sl++) {
    if ((slice == sl) || (slice == TEN_SLICE_ALL)) {
      tmp_cfgmontx_oxun_njo_th1.wrd = TEN_REG_READ(TEN_SYNCDSYNCTX_REG_ADDR(pDev,
                                      module_id, sl, OXUN_NJO_TH1));
      tmp_cfgmontx_oxun_njo_th1.bf.OXUN_NJO_TH1 = oxun_njo_th1;
      TEN_REG_WRITE(TEN_SYNCDSYNCTX_REG_ADDR(pDev, module_id, sl, OXUN_NJO_TH1),
                    tmp_cfgmontx_oxun_njo_th1.wrd);
      
      tmp_cfgmontx_oxun_njo_th0.wrd = TEN_REG_READ(TEN_SYNCDSYNCTX_REG_ADDR(pDev, 
                                      module_id, sl, OXUN_NJO_TH0));
      tmp_cfgmontx_oxun_njo_th0.bf.OXUN_NJO_TH0 = oxun_njo_th0;
      TEN_REG_WRITE(TEN_SYNCDSYNCTX_REG_ADDR(pDev, module_id, sl, OXUN_NJO_TH0),
                    tmp_cfgmontx_oxun_njo_th0.wrd);
    }
  }
  TEN_MOD_UNLOCK(module_id, TEN_ID_SYNCDSYNC);

  return (CS_OK);
}

/****************************************************************/
/* $rtn_hdr_start  SYNCDSYNCTX CFGMONTX GET STATUS              */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : SYNCDSYNC                                           */
/* CHIP       : Tenabo                                          */
cs_int16 ten_syncdsynctx_cfgmontx_get_status(cs_uint16 module_id, cs_uint8 slice, 
                                       cs_uint16 select)
/* INPUTS     : o Module Id                                     */
/*              o Slice                                         */
/*              o Select                                        */
/* OUTPUTS    : ----                                            */
/* RETURNS    : Status                                          */
/* DESCRIPTION:                                                 */
/* Returns the selected status bits.                            */ 
/*                                                              */
/*   [slice]  Specified as TEN_SLICE0 (0), TEN_SLICE1 (1),      */
/*     TEN_SLICE2 (2), or TEN_SLICE3 (3)                        */
/*                                                              */
/*   [select]                                                   */
/*   TEN_SYNCDSYNCTX_CFGMONTX_STATUS_JC_OUT_RANGE = 1,          */
/*   TEN_SYNCDSYNCTX_CFGMONTX_STATUS_OUT_RANGE = 2,             */
/*   TEN_SYNCDSYNCTX_CFGMONTX_STATUS_ALL = 0xFFFF.              */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  cs_int16 ret_val;
  TEN_SYNCDSYNCTX_CFGMONTX_STAT_t tmp_cfgmontx_stat;
  T41_t *pDev = NULL;

  if (slice >= TEN_MAX_SLICES) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": slice out of range.  s/b 0..3.");
    return(CS_ERROR);
  }

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  tmp_cfgmontx_stat.wrd = TEN_REG_READ(TEN_SYNCDSYNCTX_REG_ADDR(pDev, module_id, slice, STAT));
  switch (select) {
  case (TEN_SYNCDSYNCTX_CFGMONTX_STATUS_JC_OUT_RANGE):
    ret_val = tmp_cfgmontx_stat.bf.JC_OUT_RANGE;
    break;
    
  case (TEN_SYNCDSYNCTX_CFGMONTX_STATUS_OUT_RANGE):
    ret_val = tmp_cfgmontx_stat.bf.OUT_RANGE;
    break;
    
  case (TEN_SYNCDSYNCTX_CFGMONTX_STATUS_ALL):
    ret_val = tmp_cfgmontx_stat.wrd;
    break;
  
  default:
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": select out of range.");
    ret_val = CS_ERROR;
    break;
  }
  return (ret_val);
}
  
/********************************************************************/
/* $rtn_hdr_start  SYNCDSYNCTX GMP ENABLE                           */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : SYNCDSYNC                                           */
/* CHIP       : Tenabo                                              */
cs_status ten_syncdsynctx_gmp_enbl_t41(cs_uint16 module_id, 
                                       cs_uint8 slice, 
                                       cs_uint16 select)
/* INPUTS     : o Module Id                                         */
/*              o Slice                                             */
/*              o Select (1 = enable, 0 = disable)                  */
/* OUTPUTS    : ----                                                */
/* RETURNS    : Status                                              */
/* DESCRIPTION:                                                     */
/* Sets the GMP enable.                                             */ 
/*                                                                  */
/*   [slice]  Specified as TEN_SLICE0 (0), TEN_SLICE1 (1),          */
/*     TEN_SLICE2 (2), or TEN_SLICE3 (3)                            */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  cs_uint16 sl;
  TEN_SYNCDSYNCTX_CFGTX_CFG_t tmp_cfgtx_cfg;
  T41_t *pDev = NULL;

  if ((slice>=TEN_MAX_SLICES) && (slice != TEN_SLICE_ALL)) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": slice out of range.  s/b 0..3.");
    return(CS_ERROR);
  }

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_SYNCDSYNC);
  for (sl=0; sl<TEN_MAX_SLICES; sl++) {
    if ((slice == sl) || (slice == TEN_SLICE_ALL)) {
      tmp_cfgtx_cfg.wrd = TEN_REG_READ(TEN_SYNCDSYNCTX_REG_ADDR(pDev, module_id, sl, cfgtx_CFG));
      tmp_cfgtx_cfg.bf.GMP_ENABLE = select;
      TEN_REG_WRITE(TEN_SYNCDSYNCTX_REG_ADDR(pDev, module_id, sl, cfgtx_CFG), tmp_cfgtx_cfg.wrd);
    }
  }

  TEN_MOD_UNLOCK(module_id, TEN_ID_SYNCDSYNC);

  return (CS_OK);
}
