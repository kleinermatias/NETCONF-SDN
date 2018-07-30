/******************************************************************************/
/* This file contains information proprietary to Cortina Systems, Inc.        */
/* (Cortina). Any use or disclosure, in whole or in part, of this information */
/* to any unauthorized party, for any purposes other than that for which it   */
/* is provided is expressly prohibited except as authorized by Cortina in     */
/* writing. Cortina reserves its rights to pursue both civil and criminal     */
/* penalties for copying or disclosure of this material without               */
/* authorization. Cortina Systems (R), Cortina (TM) and the Cortina Systems   */
/* Earth Logo are the trademarks or registered trademarks of Cortina Systems, */
/* Inc. and its subsidiaries in the U.S. and other countries. Any other       */
/* product and company names are the trademarks of their respective owners.   */
/* Copyright (C) 2006-2013 Cortina Systems, Inc. All rights reserved.         */
/******************************************************************************/


/*
 * This file is auto-generated from pp40g_config.xml; DO NOT MODIFY
 */

#include "tenabo40.h"


/******************************************************************************/
/* $rtn_hdr_start   PP40G_RX_RX_SOFT_RESET_REMOVAL                            */
/* CATEGORY   : API                                                           */
/* ACCESS     : Public                                                        */
/* BLOCK      : PP40G                                                         */
/* CHIP       : Tenabo                                                        */
cs_status ten_pp40g_rx_rx_soft_reset_removal_t41(cs_uint16 module_id)
/* INPUTS     : o Module_id                                                   */
/* OUTPUTS    : ----                                                          */
/* RETURNS    : CS_OK or CS_ERROR                                             */
/* DESCRIPTION:                                                               */
/*   Remove PP40G RX soft resets                                              */
/* $rtn_hdr_end                                                               */
/******************************************************************************/
{
  TEN_PP40G_PCS_RX_CNTRL_t tmp_pp40g_pcs_rx_cntrl;
  TEN_PP40G_LIF_RX_CNTRL_t tmp_pp40g_lif_rx_cntrl;
  TEN_PP40G_MAC_RX_CNTRL_t tmp_pp40g_mac_rx_cntrl;
  TEN_PP40G_RS_RX_CNTRL_t tmp_pp40g_rs_rx_cntrl;
  T41_t *pDev = NULL;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, FALSE);
  TEN_MOD_LOCK(module_id, TEN_ID_PP40G);
  
  tmp_pp40g_mac_rx_cntrl.wrd = TEN_REG_READ(TEN_PP40G_REG_ADDR(pDev, module_id, mac_rx_CNTRL));
  tmp_pp40g_mac_rx_cntrl.bf.rxrst = 0;
  TEN_REG_WRITE(TEN_PP40G_REG_ADDR(pDev, module_id, mac_rx_CNTRL), tmp_pp40g_mac_rx_cntrl.wrd);

  /* TEN_MDELAY(6); Was used in simulation but probably not needed in a system */

  tmp_pp40g_rs_rx_cntrl.wrd = TEN_REG_READ(TEN_PP40G_REG_ADDR(pDev, module_id, rs_rx_CNTRL));
  tmp_pp40g_rs_rx_cntrl.bf.rxrst = 0;
  TEN_REG_WRITE(TEN_PP40G_REG_ADDR(pDev, module_id, rs_rx_CNTRL), tmp_pp40g_rs_rx_cntrl.wrd);

  /* TEN_MDELAY(6); Was used in simulation but probably not needed in a system */

  tmp_pp40g_pcs_rx_cntrl.wrd = TEN_REG_READ(TEN_PP40G_REG_ADDR(pDev, module_id, pcs_rx_CNTRL));
  tmp_pp40g_pcs_rx_cntrl.bf.rxrst = 0;
  TEN_REG_WRITE(TEN_PP40G_REG_ADDR(pDev, module_id, pcs_rx_CNTRL), tmp_pp40g_pcs_rx_cntrl.wrd);

  /* TEN_MDELAY(6); Was used in simulation but probably not needed in a system */

  tmp_pp40g_lif_rx_cntrl.wrd = TEN_REG_READ(TEN_PP40G_REG_ADDR(pDev, module_id, lif_rx_CNTRL));
  tmp_pp40g_lif_rx_cntrl.bf.rxrst = 0;
  TEN_REG_WRITE(TEN_PP40G_REG_ADDR(pDev, module_id, lif_rx_CNTRL), tmp_pp40g_lif_rx_cntrl.wrd);

  /* TEN_MDELAY(6); Was used in simulation but probably not needed in a system */
  TEN_MOD_UNLOCK(module_id, TEN_ID_PP40G);
  return (CS_OK);
}


/******************************************************************************/
/* $rtn_hdr_start   PP40G_RX_PP40G_RX_BYPASS                                  */
/* CATEGORY   : API                                                           */
/* ACCESS     : Public                                                        */
/* BLOCK      : PP40G                                                         */
/* CHIP       : Tenabo                                                        */
cs_status ten_pp40g_rx_pp40g_rx_bypass_t41(cs_uint16 module_id)
/* INPUTS     : o Module_id                                                   */
/* OUTPUTS    : ----                                                          */
/* RETURNS    : CS_OK or CS_ERROR                                             */
/* DESCRIPTION:                                                               */
/*   Set PP40G RX bypass                                                      */
/* $rtn_hdr_end                                                               */
/******************************************************************************/
{
  TEN_PP40G_MISC_BYPASS_t tmp_pp40g_misc_bypass;
  T41_t *pDev = NULL;
  cs_char8 *func = "ten_pp40g_rx_pp40g_rx_bypass_t41";  

  CS_PRINT("%s()  %s\n", func, ten_module_strings[module_id&1]);

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, FALSE);
  TEN_MOD_LOCK(module_id, TEN_ID_PP40G);
  
  tmp_pp40g_misc_bypass.wrd = TEN_REG_READ(TEN_PP40G_REG_ADDR(pDev, module_id, BYPASS));
  tmp_pp40g_misc_bypass.bf.rx_bypass = 1;
  tmp_pp40g_misc_bypass.bf.rx_csf_en = 0;
  TEN_REG_WRITE(TEN_PP40G_REG_ADDR(pDev, module_id, BYPASS), tmp_pp40g_misc_bypass.wrd);

  TEN_MOD_UNLOCK(module_id, TEN_ID_PP40G);
  return (CS_OK);
}



/******************************************************************************/
/* $rtn_hdr_start   PP40G_RX_40GEP_XCON_CLOCKS                                */
/* CATEGORY   : API                                                           */
/* ACCESS     : Public                                                        */
/* BLOCK      : PP40G                                                         */
/* CHIP       : Tenabo                                                        */
cs_status ten_pp40g_rx_40gep_xcon_clocks_t41(cs_uint16 module_id)
/* INPUTS     : o Module_id                                                   */
/* OUTPUTS    : ----                                                          */
/* RETURNS    : CS_OK or CS_ERROR                                             */
/* DESCRIPTION:                                                               */
/*   Enable PP40G 40GEP RX clken                                              */
/* $rtn_hdr_end                                                               */
/******************************************************************************/
{
  TEN_PP40G_MISC_RX_CLKEN_t tmp_pp40g_misc_rx_clken;
  TEN_PP40G_MISC_CLKEN_t tmp_pp40g_misc_clken;
  T41_t *pDev = NULL;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, FALSE);
  TEN_MOD_LOCK(module_id, TEN_ID_PP40G);
  
  tmp_pp40g_misc_clken.wrd = TEN_REG_READ(TEN_PP40G_REG_ADDR(pDev, module_id, misc_CLKEN));
  tmp_pp40g_misc_clken.bf.clken_rx = 1;
  TEN_REG_WRITE(TEN_PP40G_REG_ADDR(pDev, module_id, misc_CLKEN), tmp_pp40g_misc_clken.wrd);

  /* TEN_MDELAY(6); Was used in simulation but probably not needed in a system */

  tmp_pp40g_misc_clken.bf.clken_pm = 1;
  TEN_REG_WRITE(TEN_PP40G_REG_ADDR(pDev, module_id, misc_CLKEN), tmp_pp40g_misc_clken.wrd);

  /* TEN_MDELAY(6); Was used in simulation but probably not needed in a system */

  tmp_pp40g_misc_rx_clken.wrd = 0x329d;
  TEN_REG_WRITE(TEN_PP40G_REG_ADDR(pDev, module_id, misc_rx_CLKEN), tmp_pp40g_misc_rx_clken.wrd);

  /* TEN_MDELAY(6); Was used in simulation but probably not needed in a system */
  TEN_MOD_UNLOCK(module_id, TEN_ID_PP40G);
  return (CS_OK);
}


/******************************************************************************/
/* $rtn_hdr_start   PP40G_RX_40GEP_XCON                                       */
/* CATEGORY   : API                                                           */
/* ACCESS     : Public                                                        */
/* BLOCK      : PP40G                                                         */
/* CHIP       : Tenabo                                                        */
cs_status ten_pp40g_rx_40gep_xcon_t41(cs_uint16 module_id)
/* INPUTS     : o Module_id                                                   */
/* OUTPUTS    : ----                                                          */
/* RETURNS    : CS_OK or CS_ERROR                                             */
/* DESCRIPTION:                                                               */
/*   Configure PP40G                                                          */
/* $rtn_hdr_end                                                               */
/******************************************************************************/
{
  TEN_PP40G_MISC_RX_FUNCEN_t tmp_pp40g_misc_rx_funcen;
  TEN_PP40G_LIF_RX_CNTRL_t tmp_pp40g_lif_rx_cntrl;
  TEN_PP40G_PCS_RX_CSF_CNTRL_t tmp_pp40g_pcs_rx_csf_cntrl;
  TEN_PP40G_MISC_BYPASS_t tmp_pp40g_misc_bypass;
  TEN_PP40G_MAC_RX_MAXLEN_t tmp_pp40g_mac_rx_maxlen;
  TEN_PP40G_RS_RX_CNTRL_t tmp_pp40g_rs_rx_cntrl;
  T41_t *pDev = NULL;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, FALSE);
  TEN_MOD_LOCK(module_id, TEN_ID_PP40G);
  
  tmp_pp40g_misc_bypass.wrd = TEN_REG_READ(TEN_PP40G_REG_ADDR(pDev, module_id, BYPASS));
  tmp_pp40g_misc_bypass.bf.rx_bypass = 0;
  TEN_REG_WRITE(TEN_PP40G_REG_ADDR(pDev, module_id, BYPASS), tmp_pp40g_misc_bypass.wrd);

  /* TEN_MDELAY(6); Was used in simulation but probably not needed in a system */

  tmp_pp40g_misc_bypass.bf.rx_csf_en = 1;
  TEN_REG_WRITE(TEN_PP40G_REG_ADDR(pDev, module_id, BYPASS), tmp_pp40g_misc_bypass.wrd);

  /* TEN_MDELAY(6); Was used in simulation but probably not needed in a system */

  tmp_pp40g_pcs_rx_csf_cntrl.wrd = TEN_REG_READ(TEN_PP40G_REG_ADDR(pDev, module_id, CSF_CNTRL));
  tmp_pp40g_pcs_rx_csf_cntrl.bf.idle_en = 0;
  tmp_pp40g_pcs_rx_csf_cntrl.bf.rf_en = 0;
  TEN_REG_WRITE(TEN_PP40G_REG_ADDR(pDev, module_id, CSF_CNTRL), tmp_pp40g_pcs_rx_csf_cntrl.wrd);

  tmp_pp40g_misc_rx_funcen.wrd = TEN_REG_READ(TEN_PP40G_REG_ADDR(pDev, module_id, misc_rx_FUNCEN));
  tmp_pp40g_misc_rx_funcen.bf.fen_lif = 1;
  TEN_REG_WRITE(TEN_PP40G_REG_ADDR(pDev, module_id, misc_rx_FUNCEN), tmp_pp40g_misc_rx_funcen.wrd);

  /* TEN_MDELAY(6); Was used in simulation but probably not needed in a system */

  tmp_pp40g_misc_rx_funcen.bf.fen_lba = 1;
  TEN_REG_WRITE(TEN_PP40G_REG_ADDR(pDev, module_id, misc_rx_FUNCEN), tmp_pp40g_misc_rx_funcen.wrd);

  /* TEN_MDELAY(6); Was used in simulation but probably not needed in a system */

  tmp_pp40g_misc_rx_funcen.bf.fen_lds = 1;
  TEN_REG_WRITE(TEN_PP40G_REG_ADDR(pDev, module_id, misc_rx_FUNCEN), tmp_pp40g_misc_rx_funcen.wrd);

  /* TEN_MDELAY(6); Was used in simulation but probably not needed in a system */

  tmp_pp40g_misc_rx_funcen.bf.fen_lro = 1;
  TEN_REG_WRITE(TEN_PP40G_REG_ADDR(pDev, module_id, misc_rx_FUNCEN), tmp_pp40g_misc_rx_funcen.wrd);

  /* TEN_MDELAY(6); Was used in simulation but probably not needed in a system */

  tmp_pp40g_misc_rx_funcen.bf.fen_nra = 0;
  TEN_REG_WRITE(TEN_PP40G_REG_ADDR(pDev, module_id, misc_rx_FUNCEN), tmp_pp40g_misc_rx_funcen.wrd);

  /* TEN_MDELAY(6); Was used in simulation but probably not needed in a system */

  tmp_pp40g_misc_rx_funcen.bf.fen_bds_bdc = 1;
  TEN_REG_WRITE(TEN_PP40G_REG_ADDR(pDev, module_id, misc_rx_FUNCEN), tmp_pp40g_misc_rx_funcen.wrd);

  /* TEN_MDELAY(6); Was used in simulation but probably not needed in a system */

  tmp_pp40g_misc_rx_funcen.bf.fen_bds_rxi = 0;
  TEN_REG_WRITE(TEN_PP40G_REG_ADDR(pDev, module_id, misc_rx_FUNCEN), tmp_pp40g_misc_rx_funcen.wrd);

  /* TEN_MDELAY(6); Was used in simulation but probably not needed in a system */

  tmp_pp40g_misc_rx_funcen.bf.fen_bdc = 1;
  TEN_REG_WRITE(TEN_PP40G_REG_ADDR(pDev, module_id, misc_rx_FUNCEN), tmp_pp40g_misc_rx_funcen.wrd);

  /* TEN_MDELAY(6); Was used in simulation but probably not needed in a system */

  tmp_pp40g_misc_rx_funcen.bf.fen_rs = 1;
  TEN_REG_WRITE(TEN_PP40G_REG_ADDR(pDev, module_id, misc_rx_FUNCEN), tmp_pp40g_misc_rx_funcen.wrd);

  /* TEN_MDELAY(6); Was used in simulation but probably not needed in a system */

  tmp_pp40g_misc_rx_funcen.bf.fen_mac = 1;
  TEN_REG_WRITE(TEN_PP40G_REG_ADDR(pDev, module_id, misc_rx_FUNCEN), tmp_pp40g_misc_rx_funcen.wrd);

  /* TEN_MDELAY(6); Was used in simulation but probably not needed in a system */

  tmp_pp40g_misc_rx_funcen.bf.fen_dil = 0;
  TEN_REG_WRITE(TEN_PP40G_REG_ADDR(pDev, module_id, misc_rx_FUNCEN), tmp_pp40g_misc_rx_funcen.wrd);

  /* TEN_MDELAY(6); Was used in simulation but probably not needed in a system */

  tmp_pp40g_misc_rx_funcen.bf.fen_mba = 0;
  TEN_REG_WRITE(TEN_PP40G_REG_ADDR(pDev, module_id, misc_rx_FUNCEN), tmp_pp40g_misc_rx_funcen.wrd);

  /* TEN_MDELAY(6); Was used in simulation but probably not needed in a system */

  tmp_pp40g_misc_rx_funcen.bf.fen_xdc = 0;
  TEN_REG_WRITE(TEN_PP40G_REG_ADDR(pDev, module_id, misc_rx_FUNCEN), tmp_pp40g_misc_rx_funcen.wrd);

  /* TEN_MDELAY(6); Was used in simulation but probably not needed in a system */

  tmp_pp40g_lif_rx_cntrl.wrd = TEN_REG_READ(TEN_PP40G_REG_ADDR(pDev, module_id, lif_rx_CNTRL));
  tmp_pp40g_lif_rx_cntrl.bf.mono_mode = 0;
  TEN_REG_WRITE(TEN_PP40G_REG_ADDR(pDev, module_id, lif_rx_CNTRL), tmp_pp40g_lif_rx_cntrl.wrd);

  tmp_pp40g_rs_rx_cntrl.wrd = TEN_REG_READ(TEN_PP40G_REG_ADDR(pDev, module_id, rs_rx_CNTRL));
  tmp_pp40g_rs_rx_cntrl.bf.rs_active = 1;
  TEN_REG_WRITE(TEN_PP40G_REG_ADDR(pDev, module_id, rs_rx_CNTRL), tmp_pp40g_rs_rx_cntrl.wrd);

  tmp_pp40g_mac_rx_maxlen.wrd = TEN_REG_READ(TEN_PP40G_REG_ADDR(pDev, module_id, MAXLEN));
  tmp_pp40g_mac_rx_maxlen.bf.maxlen = 10000;
  TEN_REG_WRITE(TEN_PP40G_REG_ADDR(pDev, module_id, MAXLEN), tmp_pp40g_mac_rx_maxlen.wrd);

  TEN_MOD_UNLOCK(module_id, TEN_ID_PP40G);
  return (CS_OK);
}


/******************************************************************************/
/* $rtn_hdr_start   PP40G_RX_40GEP_XCON_RA                                    */
/* CATEGORY   : API                                                           */
/* ACCESS     : Public                                                        */
/* BLOCK      : PP40G                                                         */
/* CHIP       : Tenabo                                                        */
cs_status ten_pp40g_rx_40gep_xcon_ra_t41(cs_uint16 module_id)
/* INPUTS     : o Module_id                                                   */
/* OUTPUTS    : ----                                                          */
/* RETURNS    : CS_OK or CS_ERROR                                             */
/* DESCRIPTION:                                                               */
/*   Configure PP40G                                                          */
/* $rtn_hdr_end                                                               */
/******************************************************************************/
{
  TEN_PP40G_MISC_RX_FUNCEN_t tmp_pp40g_misc_rx_funcen;
  TEN_PP40G_MISC_RESET_t tmp_pp40g_misc_reset;
  TEN_PP40G_MISC_RX_CLKEN_t tmp_pp40g_misc_rx_clken;
  TEN_PP40G_LIF_RX_CNTRL_t tmp_pp40g_lif_rx_cntrl;
  TEN_PP40G_PCS_RX_CSF_CNTRL_t tmp_pp40g_pcs_rx_csf_cntrl;
  TEN_PP40G_MISC_CLKEN_t tmp_pp40g_misc_clken;
  TEN_PP40G_MISC_BYPASS_t tmp_pp40g_misc_bypass;
  TEN_PP40G_MAC_RX_MAXLEN_t tmp_pp40g_mac_rx_maxlen;
  TEN_PP40G_RS_RX_CNTRL_t tmp_pp40g_rs_rx_cntrl;
  TEN_PP40G_PCS_RX_RATE_CNTRL_t tmp_pp40g_pcs_rx_rate_cntrl;
  T41_t *pDev = NULL;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, FALSE);
  TEN_MOD_LOCK(module_id, TEN_ID_PP40G);
  
  tmp_pp40g_misc_clken.wrd = TEN_REG_READ(TEN_PP40G_REG_ADDR(pDev, module_id, misc_CLKEN));
  tmp_pp40g_misc_clken.bf.clken_rx = 1;
  TEN_REG_WRITE(TEN_PP40G_REG_ADDR(pDev, module_id, misc_CLKEN), tmp_pp40g_misc_clken.wrd);

  /* TEN_MDELAY(6); Was used in simulation but probably not needed in a system */

  tmp_pp40g_misc_clken.bf.clken_pm = 1;
  TEN_REG_WRITE(TEN_PP40G_REG_ADDR(pDev, module_id, misc_CLKEN), tmp_pp40g_misc_clken.wrd);

  /* TEN_MDELAY(6); Was used in simulation but probably not needed in a system */

  tmp_pp40g_misc_rx_clken.wrd = 0x3a9d;
  TEN_REG_WRITE(TEN_PP40G_REG_ADDR(pDev, module_id, misc_rx_CLKEN), tmp_pp40g_misc_rx_clken.wrd);

  /* TEN_MDELAY(6); Was used in simulation but probably not needed in a system */

  tmp_pp40g_misc_reset.wrd = TEN_REG_READ(TEN_PP40G_REG_ADDR(pDev, module_id, RESET));
  tmp_pp40g_misc_reset.bf.mpif_rst = 0;
  TEN_REG_WRITE(TEN_PP40G_REG_ADDR(pDev, module_id, RESET), tmp_pp40g_misc_reset.wrd);

  /* TEN_MDELAY(6); Was used in simulation but probably not needed in a system */

  tmp_pp40g_misc_bypass.wrd = TEN_REG_READ(TEN_PP40G_REG_ADDR(pDev, module_id, BYPASS));
  tmp_pp40g_misc_bypass.bf.rx_bypass = 0;
  TEN_REG_WRITE(TEN_PP40G_REG_ADDR(pDev, module_id, BYPASS), tmp_pp40g_misc_bypass.wrd);

  /* TEN_MDELAY(6); Was used in simulation but probably not needed in a system */

  tmp_pp40g_misc_bypass.bf.rx_csf_en = 1;
  TEN_REG_WRITE(TEN_PP40G_REG_ADDR(pDev, module_id, BYPASS), tmp_pp40g_misc_bypass.wrd);

  /* TEN_MDELAY(6); Was used in simulation but probably not needed in a system */

  tmp_pp40g_pcs_rx_csf_cntrl.wrd = TEN_REG_READ(TEN_PP40G_REG_ADDR(pDev, module_id, CSF_CNTRL));
  tmp_pp40g_pcs_rx_csf_cntrl.bf.idle_en = 0;
  tmp_pp40g_pcs_rx_csf_cntrl.bf.rf_en = 0;
  TEN_REG_WRITE(TEN_PP40G_REG_ADDR(pDev, module_id, CSF_CNTRL), tmp_pp40g_pcs_rx_csf_cntrl.wrd);

  tmp_pp40g_misc_rx_funcen.wrd = TEN_REG_READ(TEN_PP40G_REG_ADDR(pDev, module_id, misc_rx_FUNCEN));
  tmp_pp40g_misc_rx_funcen.bf.fen_lif = 1;
  TEN_REG_WRITE(TEN_PP40G_REG_ADDR(pDev, module_id, misc_rx_FUNCEN), tmp_pp40g_misc_rx_funcen.wrd);

  /* TEN_MDELAY(6); Was used in simulation but probably not needed in a system */

  tmp_pp40g_misc_rx_funcen.bf.fen_lba = 1;
  TEN_REG_WRITE(TEN_PP40G_REG_ADDR(pDev, module_id, misc_rx_FUNCEN), tmp_pp40g_misc_rx_funcen.wrd);

  /* TEN_MDELAY(6); Was used in simulation but probably not needed in a system */

  tmp_pp40g_misc_rx_funcen.bf.fen_lds = 1;
  TEN_REG_WRITE(TEN_PP40G_REG_ADDR(pDev, module_id, misc_rx_FUNCEN), tmp_pp40g_misc_rx_funcen.wrd);

  /* TEN_MDELAY(6); Was used in simulation but probably not needed in a system */

  tmp_pp40g_misc_rx_funcen.bf.fen_lro = 1;
  TEN_REG_WRITE(TEN_PP40G_REG_ADDR(pDev, module_id, misc_rx_FUNCEN), tmp_pp40g_misc_rx_funcen.wrd);

  /* TEN_MDELAY(6); Was used in simulation but probably not needed in a system */

  tmp_pp40g_misc_rx_funcen.bf.fen_nra = 1;
  TEN_REG_WRITE(TEN_PP40G_REG_ADDR(pDev, module_id, misc_rx_FUNCEN), tmp_pp40g_misc_rx_funcen.wrd);

  /* TEN_MDELAY(6); Was used in simulation but probably not needed in a system */

  tmp_pp40g_misc_rx_funcen.bf.fen_bds_bdc = 1;
  TEN_REG_WRITE(TEN_PP40G_REG_ADDR(pDev, module_id, misc_rx_FUNCEN), tmp_pp40g_misc_rx_funcen.wrd);

  /* TEN_MDELAY(6); Was used in simulation but probably not needed in a system */

  tmp_pp40g_misc_rx_funcen.bf.fen_bds_rxi = 1;
  TEN_REG_WRITE(TEN_PP40G_REG_ADDR(pDev, module_id, misc_rx_FUNCEN), tmp_pp40g_misc_rx_funcen.wrd);

  /* TEN_MDELAY(6); Was used in simulation but probably not needed in a system */

  tmp_pp40g_misc_rx_funcen.bf.fen_bdc = 1;
  TEN_REG_WRITE(TEN_PP40G_REG_ADDR(pDev, module_id, misc_rx_FUNCEN), tmp_pp40g_misc_rx_funcen.wrd);

  /* TEN_MDELAY(6); Was used in simulation but probably not needed in a system */

  tmp_pp40g_misc_rx_funcen.bf.fen_rs = 1;
  TEN_REG_WRITE(TEN_PP40G_REG_ADDR(pDev, module_id, misc_rx_FUNCEN), tmp_pp40g_misc_rx_funcen.wrd);

  /* TEN_MDELAY(6); Was used in simulation but probably not needed in a system */

  tmp_pp40g_misc_rx_funcen.bf.fen_mac = 1;
  TEN_REG_WRITE(TEN_PP40G_REG_ADDR(pDev, module_id, misc_rx_FUNCEN), tmp_pp40g_misc_rx_funcen.wrd);

  /* TEN_MDELAY(6); Was used in simulation but probably not needed in a system */

  tmp_pp40g_misc_rx_funcen.bf.fen_dil = 0;
  TEN_REG_WRITE(TEN_PP40G_REG_ADDR(pDev, module_id, misc_rx_FUNCEN), tmp_pp40g_misc_rx_funcen.wrd);

  /* TEN_MDELAY(6); Was used in simulation but probably not needed in a system */

  tmp_pp40g_misc_rx_funcen.bf.fen_mba = 0;
  TEN_REG_WRITE(TEN_PP40G_REG_ADDR(pDev, module_id, misc_rx_FUNCEN), tmp_pp40g_misc_rx_funcen.wrd);

  /* TEN_MDELAY(6); Was used in simulation but probably not needed in a system */

  tmp_pp40g_misc_rx_funcen.bf.fen_xdc = 0;
  TEN_REG_WRITE(TEN_PP40G_REG_ADDR(pDev, module_id, misc_rx_FUNCEN), tmp_pp40g_misc_rx_funcen.wrd);

  /* TEN_MDELAY(6); Was used in simulation but probably not needed in a system */

  tmp_pp40g_lif_rx_cntrl.wrd = TEN_REG_READ(TEN_PP40G_REG_ADDR(pDev, module_id, lif_rx_CNTRL));
  tmp_pp40g_lif_rx_cntrl.bf.mono_mode = 0;
  TEN_REG_WRITE(TEN_PP40G_REG_ADDR(pDev, module_id, lif_rx_CNTRL), tmp_pp40g_lif_rx_cntrl.wrd);

  tmp_pp40g_rs_rx_cntrl.wrd = TEN_REG_READ(TEN_PP40G_REG_ADDR(pDev, module_id, rs_rx_CNTRL));
  tmp_pp40g_rs_rx_cntrl.bf.rs_active = 1;
  TEN_REG_WRITE(TEN_PP40G_REG_ADDR(pDev, module_id, rs_rx_CNTRL), tmp_pp40g_rs_rx_cntrl.wrd);

  tmp_pp40g_mac_rx_maxlen.wrd = TEN_REG_READ(TEN_PP40G_REG_ADDR(pDev, module_id, MAXLEN));
  tmp_pp40g_mac_rx_maxlen.bf.maxlen = 10000;
  TEN_REG_WRITE(TEN_PP40G_REG_ADDR(pDev, module_id, MAXLEN), tmp_pp40g_mac_rx_maxlen.wrd);

  tmp_pp40g_pcs_rx_rate_cntrl.wrd = 0;
  TEN_REG_WRITE(TEN_PP40G_REG_ADDR(pDev, module_id, pcs_rx_RATE_CNTRL), tmp_pp40g_pcs_rx_rate_cntrl.wrd);

  TEN_MOD_UNLOCK(module_id, TEN_ID_PP40G);
  return (CS_OK);
}


/******************************************************************************/
/* $rtn_hdr_start   PP40G_RX_40GESBI_XCON_CLOCKS                              */
/* CATEGORY   : API                                                           */
/* ACCESS     : Public                                                        */
/* BLOCK      : PP40G                                                         */
/* CHIP       : Tenabo                                                        */
cs_status ten_pp40g_rx_40gesbi_xcon_clocks_t41(cs_uint16 module_id)
/* INPUTS     : o Module_id                                                   */
/* OUTPUTS    : ----                                                          */
/* RETURNS    : CS_OK or CS_ERROR                                             */
/* DESCRIPTION:                                                               */
/*   Configure PP40G                                                          */
/* $rtn_hdr_end                                                               */
/******************************************************************************/
{
  TEN_PP40G_MISC_RX_CLKEN_t tmp_pp40g_misc_rx_clken;
  TEN_PP40G_MISC_CLKEN_t tmp_pp40g_misc_clken;
  T41_t *pDev = NULL;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, FALSE);
  TEN_MOD_LOCK(module_id, TEN_ID_PP40G);
  
  tmp_pp40g_misc_clken.wrd = TEN_REG_READ(TEN_PP40G_REG_ADDR(pDev, module_id, misc_CLKEN));
  tmp_pp40g_misc_clken.bf.clken_rx = 1;
  TEN_REG_WRITE(TEN_PP40G_REG_ADDR(pDev, module_id, misc_CLKEN), tmp_pp40g_misc_clken.wrd);

  /* TEN_MDELAY(6); Was used in simulation but probably not needed in a system */

  tmp_pp40g_misc_clken.bf.clken_pm = 1;
  TEN_REG_WRITE(TEN_PP40G_REG_ADDR(pDev, module_id, misc_CLKEN), tmp_pp40g_misc_clken.wrd);

  /* TEN_MDELAY(6); Was used in simulation but probably not needed in a system */

  tmp_pp40g_misc_rx_clken.wrd = 0x329f;
  TEN_REG_WRITE(TEN_PP40G_REG_ADDR(pDev, module_id, misc_rx_CLKEN), tmp_pp40g_misc_rx_clken.wrd);

  /* TEN_MDELAY(6); Was used in simulation but probably not needed in a system */
  TEN_MOD_UNLOCK(module_id, TEN_ID_PP40G);
  return (CS_OK);
}


/******************************************************************************/
/* $rtn_hdr_start   PP40G_RX_40GESBI_XCON                                     */
/* CATEGORY   : API                                                           */
/* ACCESS     : Public                                                        */
/* BLOCK      : PP40G                                                         */
/* CHIP       : Tenabo                                                        */
cs_status ten_pp40g_rx_40gesbi_xcon_t41(cs_uint16 module_id)
/* INPUTS     : o Module_id                                                   */
/* OUTPUTS    : ----                                                          */
/* RETURNS    : CS_OK or CS_ERROR                                             */
/* DESCRIPTION:                                                               */
/*   Configure PP40G                                                          */
/* $rtn_hdr_end                                                               */
/******************************************************************************/
{
  TEN_PP40G_MISC_RX_FUNCEN_t tmp_pp40g_misc_rx_funcen;
  TEN_PP40G_MISC_RESET_t tmp_pp40g_misc_reset;
  TEN_PP40G_LIF_RX_CNTRL_t tmp_pp40g_lif_rx_cntrl;
  TEN_PP40G_PCS_RX_CSF_CNTRL_t tmp_pp40g_pcs_rx_csf_cntrl;
  TEN_PP40G_MISC_BYPASS_t tmp_pp40g_misc_bypass;
  TEN_PP40G_MAC_RX_MAXLEN_t tmp_pp40g_mac_rx_maxlen;
  TEN_PP40G_RS_RX_CNTRL_t tmp_pp40g_rs_rx_cntrl;
  T41_t *pDev = NULL;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, FALSE);
  TEN_MOD_LOCK(module_id, TEN_ID_PP40G);
  
  tmp_pp40g_misc_reset.wrd = TEN_REG_READ(TEN_PP40G_REG_ADDR(pDev, module_id, RESET));
  tmp_pp40g_misc_reset.bf.mpif_rst = 0;
  TEN_REG_WRITE(TEN_PP40G_REG_ADDR(pDev, module_id, RESET), tmp_pp40g_misc_reset.wrd);

  /* TEN_MDELAY(6); Was used in simulation but probably not needed in a system */

  tmp_pp40g_misc_bypass.wrd = TEN_REG_READ(TEN_PP40G_REG_ADDR(pDev, module_id, BYPASS));
  tmp_pp40g_misc_bypass.bf.rx_bypass = 0;
  TEN_REG_WRITE(TEN_PP40G_REG_ADDR(pDev, module_id, BYPASS), tmp_pp40g_misc_bypass.wrd);

  /* TEN_MDELAY(6); Was used in simulation but probably not needed in a system */

  tmp_pp40g_misc_bypass.bf.rx_csf_en = 1;
  TEN_REG_WRITE(TEN_PP40G_REG_ADDR(pDev, module_id, BYPASS), tmp_pp40g_misc_bypass.wrd);

  /* TEN_MDELAY(6); Was used in simulation but probably not needed in a system */

  tmp_pp40g_pcs_rx_csf_cntrl.wrd = TEN_REG_READ(TEN_PP40G_REG_ADDR(pDev, module_id, CSF_CNTRL));
  tmp_pp40g_pcs_rx_csf_cntrl.bf.idle_en = 0;
  tmp_pp40g_pcs_rx_csf_cntrl.bf.rf_en = 0;
  TEN_REG_WRITE(TEN_PP40G_REG_ADDR(pDev, module_id, CSF_CNTRL), tmp_pp40g_pcs_rx_csf_cntrl.wrd);

  tmp_pp40g_misc_rx_funcen.wrd = TEN_REG_READ(TEN_PP40G_REG_ADDR(pDev, module_id, misc_rx_FUNCEN));
  tmp_pp40g_misc_rx_funcen.bf.fen_lif = 1;
  TEN_REG_WRITE(TEN_PP40G_REG_ADDR(pDev, module_id, misc_rx_FUNCEN), tmp_pp40g_misc_rx_funcen.wrd);

  /* TEN_MDELAY(6); Was used in simulation but probably not needed in a system */

  tmp_pp40g_misc_rx_funcen.bf.fen_lba = 1;
  TEN_REG_WRITE(TEN_PP40G_REG_ADDR(pDev, module_id, misc_rx_FUNCEN), tmp_pp40g_misc_rx_funcen.wrd);

  /* TEN_MDELAY(6); Was used in simulation but probably not needed in a system */

  tmp_pp40g_misc_rx_funcen.bf.fen_lds = 1;
  TEN_REG_WRITE(TEN_PP40G_REG_ADDR(pDev, module_id, misc_rx_FUNCEN), tmp_pp40g_misc_rx_funcen.wrd);

  /* TEN_MDELAY(6); Was used in simulation but probably not needed in a system */

  tmp_pp40g_misc_rx_funcen.bf.fen_lro = 1;
  TEN_REG_WRITE(TEN_PP40G_REG_ADDR(pDev, module_id, misc_rx_FUNCEN), tmp_pp40g_misc_rx_funcen.wrd);

  /* TEN_MDELAY(6); Was used in simulation but probably not needed in a system */

  tmp_pp40g_misc_rx_funcen.bf.fen_nra = 0;
  TEN_REG_WRITE(TEN_PP40G_REG_ADDR(pDev, module_id, misc_rx_FUNCEN), tmp_pp40g_misc_rx_funcen.wrd);

  /* TEN_MDELAY(6); Was used in simulation but probably not needed in a system */

  tmp_pp40g_misc_rx_funcen.bf.fen_bds_bdc = 1;
  TEN_REG_WRITE(TEN_PP40G_REG_ADDR(pDev, module_id, misc_rx_FUNCEN), tmp_pp40g_misc_rx_funcen.wrd);

  /* TEN_MDELAY(6); Was used in simulation but probably not needed in a system */

  tmp_pp40g_misc_rx_funcen.bf.fen_bds_rxi = 0;
  TEN_REG_WRITE(TEN_PP40G_REG_ADDR(pDev, module_id, misc_rx_FUNCEN), tmp_pp40g_misc_rx_funcen.wrd);

  /* TEN_MDELAY(6); Was used in simulation but probably not needed in a system */

  tmp_pp40g_misc_rx_funcen.bf.fen_bdc = 1;
  TEN_REG_WRITE(TEN_PP40G_REG_ADDR(pDev, module_id, misc_rx_FUNCEN), tmp_pp40g_misc_rx_funcen.wrd);

  /* TEN_MDELAY(6); Was used in simulation but probably not needed in a system */

  tmp_pp40g_misc_rx_funcen.bf.fen_rs = 1;
  TEN_REG_WRITE(TEN_PP40G_REG_ADDR(pDev, module_id, misc_rx_FUNCEN), tmp_pp40g_misc_rx_funcen.wrd);

  /* TEN_MDELAY(6); Was used in simulation but probably not needed in a system */

  tmp_pp40g_misc_rx_funcen.bf.fen_mac = 1;
  TEN_REG_WRITE(TEN_PP40G_REG_ADDR(pDev, module_id, misc_rx_FUNCEN), tmp_pp40g_misc_rx_funcen.wrd);

  /* TEN_MDELAY(6); Was used in simulation but probably not needed in a system */

  tmp_pp40g_misc_rx_funcen.bf.fen_dil = 1;
  TEN_REG_WRITE(TEN_PP40G_REG_ADDR(pDev, module_id, misc_rx_FUNCEN), tmp_pp40g_misc_rx_funcen.wrd);

  /* TEN_MDELAY(6); Was used in simulation but probably not needed in a system */

  tmp_pp40g_misc_rx_funcen.bf.fen_mba = 0;
  TEN_REG_WRITE(TEN_PP40G_REG_ADDR(pDev, module_id, misc_rx_FUNCEN), tmp_pp40g_misc_rx_funcen.wrd);

  /* TEN_MDELAY(6); Was used in simulation but probably not needed in a system */

  tmp_pp40g_misc_rx_funcen.bf.fen_xdc = 0;
  TEN_REG_WRITE(TEN_PP40G_REG_ADDR(pDev, module_id, misc_rx_FUNCEN), tmp_pp40g_misc_rx_funcen.wrd);

  /* TEN_MDELAY(6); Was used in simulation but probably not needed in a system */

  tmp_pp40g_lif_rx_cntrl.wrd = TEN_REG_READ(TEN_PP40G_REG_ADDR(pDev, module_id, lif_rx_CNTRL));
  tmp_pp40g_lif_rx_cntrl.bf.mono_mode = 1;
  TEN_REG_WRITE(TEN_PP40G_REG_ADDR(pDev, module_id, lif_rx_CNTRL), tmp_pp40g_lif_rx_cntrl.wrd);

  tmp_pp40g_rs_rx_cntrl.wrd = TEN_REG_READ(TEN_PP40G_REG_ADDR(pDev, module_id, rs_rx_CNTRL));
  tmp_pp40g_rs_rx_cntrl.bf.rs_active = 1;
  TEN_REG_WRITE(TEN_PP40G_REG_ADDR(pDev, module_id, rs_rx_CNTRL), tmp_pp40g_rs_rx_cntrl.wrd);

  tmp_pp40g_mac_rx_maxlen.wrd = TEN_REG_READ(TEN_PP40G_REG_ADDR(pDev, module_id, MAXLEN));
  tmp_pp40g_mac_rx_maxlen.bf.maxlen = 10000;
  TEN_REG_WRITE(TEN_PP40G_REG_ADDR(pDev, module_id, MAXLEN), tmp_pp40g_mac_rx_maxlen.wrd);

  TEN_MOD_UNLOCK(module_id, TEN_ID_PP40G);
  return (CS_OK);
}


/******************************************************************************/
/* $rtn_hdr_start   PP40G_RX_40GESBI_XCON_RA                                  */
/* CATEGORY   : API                                                           */
/* ACCESS     : Public                                                        */
/* BLOCK      : PP40G                                                         */
/* CHIP       : Tenabo                                                        */
cs_status ten_pp40g_rx_40gesbi_xcon_ra_t41(cs_uint16 module_id)
/* INPUTS     : o Module_id                                                   */
/* OUTPUTS    : ----                                                          */
/* RETURNS    : CS_OK or CS_ERROR                                             */
/* DESCRIPTION:                                                               */
/*   Configure PP40G                                                          */
/* $rtn_hdr_end                                                               */
/******************************************************************************/
{
  TEN_PP40G_MISC_RX_FUNCEN_t tmp_pp40g_misc_rx_funcen;
  TEN_PP40G_MISC_RESET_t tmp_pp40g_misc_reset;
  TEN_PP40G_MISC_RX_CLKEN_t tmp_pp40g_misc_rx_clken;
  TEN_PP40G_LIF_RX_CNTRL_t tmp_pp40g_lif_rx_cntrl;
  TEN_PP40G_PCS_RX_CSF_CNTRL_t tmp_pp40g_pcs_rx_csf_cntrl;
  TEN_PP40G_MISC_CLKEN_t tmp_pp40g_misc_clken;
  TEN_PP40G_MISC_BYPASS_t tmp_pp40g_misc_bypass;
  TEN_PP40G_MAC_RX_MAXLEN_t tmp_pp40g_mac_rx_maxlen;
  TEN_PP40G_RS_RX_CNTRL_t tmp_pp40g_rs_rx_cntrl;
  TEN_PP40G_PCS_RX_RATE_CNTRL_t tmp_pp40g_pcs_rx_rate_cntrl;
  T41_t *pDev = NULL;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, FALSE);
  TEN_MOD_LOCK(module_id, TEN_ID_PP40G);
  
  tmp_pp40g_misc_clken.wrd = TEN_REG_READ(TEN_PP40G_REG_ADDR(pDev, module_id, misc_CLKEN));
  tmp_pp40g_misc_clken.bf.clken_rx = 1;
  TEN_REG_WRITE(TEN_PP40G_REG_ADDR(pDev, module_id, misc_CLKEN), tmp_pp40g_misc_clken.wrd);

  /* TEN_MDELAY(6); Was used in simulation but probably not needed in a system */

  tmp_pp40g_misc_clken.bf.clken_pm = 1;
  TEN_REG_WRITE(TEN_PP40G_REG_ADDR(pDev, module_id, misc_CLKEN), tmp_pp40g_misc_clken.wrd);

  /* TEN_MDELAY(6); Was used in simulation but probably not needed in a system */

  tmp_pp40g_misc_rx_clken.wrd = 0x3a9f;
  TEN_REG_WRITE(TEN_PP40G_REG_ADDR(pDev, module_id, misc_rx_CLKEN), tmp_pp40g_misc_rx_clken.wrd);

  /* TEN_MDELAY(6); Was used in simulation but probably not needed in a system */

  tmp_pp40g_misc_reset.wrd = TEN_REG_READ(TEN_PP40G_REG_ADDR(pDev, module_id, RESET));
  tmp_pp40g_misc_reset.bf.mpif_rst = 0;
  TEN_REG_WRITE(TEN_PP40G_REG_ADDR(pDev, module_id, RESET), tmp_pp40g_misc_reset.wrd);

  /* TEN_MDELAY(6); Was used in simulation but probably not needed in a system */

  tmp_pp40g_misc_bypass.wrd = TEN_REG_READ(TEN_PP40G_REG_ADDR(pDev, module_id, BYPASS));
  tmp_pp40g_misc_bypass.bf.rx_bypass = 0;
  TEN_REG_WRITE(TEN_PP40G_REG_ADDR(pDev, module_id, BYPASS), tmp_pp40g_misc_bypass.wrd);

  /* TEN_MDELAY(6); Was used in simulation but probably not needed in a system */

  tmp_pp40g_misc_bypass.bf.rx_csf_en = 1;
  TEN_REG_WRITE(TEN_PP40G_REG_ADDR(pDev, module_id, BYPASS), tmp_pp40g_misc_bypass.wrd);

  /* TEN_MDELAY(6); Was used in simulation but probably not needed in a system */

  tmp_pp40g_pcs_rx_csf_cntrl.wrd = TEN_REG_READ(TEN_PP40G_REG_ADDR(pDev, module_id, CSF_CNTRL));
  tmp_pp40g_pcs_rx_csf_cntrl.bf.idle_en = 0;
  tmp_pp40g_pcs_rx_csf_cntrl.bf.rf_en = 0;
  TEN_REG_WRITE(TEN_PP40G_REG_ADDR(pDev, module_id, CSF_CNTRL), tmp_pp40g_pcs_rx_csf_cntrl.wrd);

  tmp_pp40g_misc_rx_funcen.wrd = TEN_REG_READ(TEN_PP40G_REG_ADDR(pDev, module_id, misc_rx_FUNCEN));
  tmp_pp40g_misc_rx_funcen.bf.fen_lif = 1;
  TEN_REG_WRITE(TEN_PP40G_REG_ADDR(pDev, module_id, misc_rx_FUNCEN), tmp_pp40g_misc_rx_funcen.wrd);

  /* TEN_MDELAY(6); Was used in simulation but probably not needed in a system */

  tmp_pp40g_misc_rx_funcen.bf.fen_lba = 1;
  TEN_REG_WRITE(TEN_PP40G_REG_ADDR(pDev, module_id, misc_rx_FUNCEN), tmp_pp40g_misc_rx_funcen.wrd);

  /* TEN_MDELAY(6); Was used in simulation but probably not needed in a system */

  tmp_pp40g_misc_rx_funcen.bf.fen_lds = 1;
  TEN_REG_WRITE(TEN_PP40G_REG_ADDR(pDev, module_id, misc_rx_FUNCEN), tmp_pp40g_misc_rx_funcen.wrd);

  /* TEN_MDELAY(6); Was used in simulation but probably not needed in a system */

  tmp_pp40g_misc_rx_funcen.bf.fen_lro = 1;
  TEN_REG_WRITE(TEN_PP40G_REG_ADDR(pDev, module_id, misc_rx_FUNCEN), tmp_pp40g_misc_rx_funcen.wrd);

  /* TEN_MDELAY(6); Was used in simulation but probably not needed in a system */

  tmp_pp40g_misc_rx_funcen.bf.fen_nra = 1;
  TEN_REG_WRITE(TEN_PP40G_REG_ADDR(pDev, module_id, misc_rx_FUNCEN), tmp_pp40g_misc_rx_funcen.wrd);

  /* TEN_MDELAY(6); Was used in simulation but probably not needed in a system */

  tmp_pp40g_misc_rx_funcen.bf.fen_bds_bdc = 1;
  TEN_REG_WRITE(TEN_PP40G_REG_ADDR(pDev, module_id, misc_rx_FUNCEN), tmp_pp40g_misc_rx_funcen.wrd);

  /* TEN_MDELAY(6); Was used in simulation but probably not needed in a system */

  tmp_pp40g_misc_rx_funcen.bf.fen_bds_rxi = 1;
  TEN_REG_WRITE(TEN_PP40G_REG_ADDR(pDev, module_id, misc_rx_FUNCEN), tmp_pp40g_misc_rx_funcen.wrd);

  /* TEN_MDELAY(6); Was used in simulation but probably not needed in a system */

  tmp_pp40g_misc_rx_funcen.bf.fen_bdc = 1;
  TEN_REG_WRITE(TEN_PP40G_REG_ADDR(pDev, module_id, misc_rx_FUNCEN), tmp_pp40g_misc_rx_funcen.wrd);

  /* TEN_MDELAY(6); Was used in simulation but probably not needed in a system */

  tmp_pp40g_misc_rx_funcen.bf.fen_rs = 1;
  TEN_REG_WRITE(TEN_PP40G_REG_ADDR(pDev, module_id, misc_rx_FUNCEN), tmp_pp40g_misc_rx_funcen.wrd);

  /* TEN_MDELAY(6); Was used in simulation but probably not needed in a system */

  tmp_pp40g_misc_rx_funcen.bf.fen_mac = 1;
  TEN_REG_WRITE(TEN_PP40G_REG_ADDR(pDev, module_id, misc_rx_FUNCEN), tmp_pp40g_misc_rx_funcen.wrd);

  /* TEN_MDELAY(6); Was used in simulation but probably not needed in a system */

  tmp_pp40g_misc_rx_funcen.bf.fen_dil = 1;
  TEN_REG_WRITE(TEN_PP40G_REG_ADDR(pDev, module_id, misc_rx_FUNCEN), tmp_pp40g_misc_rx_funcen.wrd);

  /* TEN_MDELAY(6); Was used in simulation but probably not needed in a system */

  tmp_pp40g_misc_rx_funcen.bf.fen_mba = 0;
  TEN_REG_WRITE(TEN_PP40G_REG_ADDR(pDev, module_id, misc_rx_FUNCEN), tmp_pp40g_misc_rx_funcen.wrd);

  /* TEN_MDELAY(6); Was used in simulation but probably not needed in a system */

  tmp_pp40g_misc_rx_funcen.bf.fen_xdc = 0;
  TEN_REG_WRITE(TEN_PP40G_REG_ADDR(pDev, module_id, misc_rx_FUNCEN), tmp_pp40g_misc_rx_funcen.wrd);

  /* TEN_MDELAY(6); Was used in simulation but probably not needed in a system */

  tmp_pp40g_lif_rx_cntrl.wrd = TEN_REG_READ(TEN_PP40G_REG_ADDR(pDev, module_id, lif_rx_CNTRL));
  tmp_pp40g_lif_rx_cntrl.bf.mono_mode = 1;
  TEN_REG_WRITE(TEN_PP40G_REG_ADDR(pDev, module_id, lif_rx_CNTRL), tmp_pp40g_lif_rx_cntrl.wrd);

  tmp_pp40g_rs_rx_cntrl.wrd = TEN_REG_READ(TEN_PP40G_REG_ADDR(pDev, module_id, rs_rx_CNTRL));
  tmp_pp40g_rs_rx_cntrl.bf.rs_active = 1;
  TEN_REG_WRITE(TEN_PP40G_REG_ADDR(pDev, module_id, rs_rx_CNTRL), tmp_pp40g_rs_rx_cntrl.wrd);

  tmp_pp40g_mac_rx_maxlen.wrd = TEN_REG_READ(TEN_PP40G_REG_ADDR(pDev, module_id, MAXLEN));
  tmp_pp40g_mac_rx_maxlen.bf.maxlen = 10000;
  TEN_REG_WRITE(TEN_PP40G_REG_ADDR(pDev, module_id, MAXLEN), tmp_pp40g_mac_rx_maxlen.wrd);

  tmp_pp40g_pcs_rx_rate_cntrl.wrd = 0;
  TEN_REG_WRITE(TEN_PP40G_REG_ADDR(pDev, module_id, pcs_rx_RATE_CNTRL), tmp_pp40g_pcs_rx_rate_cntrl.wrd);

  TEN_MOD_UNLOCK(module_id, TEN_ID_PP40G);
  return (CS_OK);
}


/******************************************************************************/
/* $rtn_hdr_start   PP40G_RX_40GES6466_XCON_CLOCKS                            */
/* CATEGORY   : API                                                           */
/* ACCESS     : Public                                                        */
/* BLOCK      : PP40G                                                         */
/* CHIP       : Tenabo                                                        */
cs_status ten_pp40g_rx_40ges6466_xcon_clocks_t41(cs_uint16 module_id)
/* INPUTS     : o Module_id                                                   */
/* OUTPUTS    : ----                                                          */
/* RETURNS    : CS_OK or CS_ERROR                                             */
/* DESCRIPTION:                                                               */
/*   Configure PP40G                                                          */
/* $rtn_hdr_end                                                               */
/******************************************************************************/
{
  TEN_PP40G_MISC_RESET_t tmp_pp40g_misc_reset;
  TEN_PP40G_MISC_RX_CLKEN_t tmp_pp40g_misc_rx_clken;
  TEN_PP40G_MISC_CLKEN_t tmp_pp40g_misc_clken;
  T41_t *pDev = NULL;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, FALSE);
  TEN_MOD_LOCK(module_id, TEN_ID_PP40G);
  
  tmp_pp40g_misc_clken.wrd = TEN_REG_READ(TEN_PP40G_REG_ADDR(pDev, module_id, misc_CLKEN));
  tmp_pp40g_misc_clken.bf.clken_rx = 1;
  TEN_REG_WRITE(TEN_PP40G_REG_ADDR(pDev, module_id, misc_CLKEN), tmp_pp40g_misc_clken.wrd);

  /* TEN_MDELAY(6); Was used in simulation but probably not needed in a system */

  tmp_pp40g_misc_clken.bf.clken_pm = 1;
  TEN_REG_WRITE(TEN_PP40G_REG_ADDR(pDev, module_id, misc_CLKEN), tmp_pp40g_misc_clken.wrd);

  /* TEN_MDELAY(6); Was used in simulation but probably not needed in a system */

  tmp_pp40g_misc_rx_clken.wrd = 0x32a1;
  TEN_REG_WRITE(TEN_PP40G_REG_ADDR(pDev, module_id, misc_rx_CLKEN), tmp_pp40g_misc_rx_clken.wrd);

  /* TEN_MDELAY(6); Was used in simulation but probably not needed in a system */

  tmp_pp40g_misc_reset.wrd = TEN_REG_READ(TEN_PP40G_REG_ADDR(pDev, module_id, RESET));
  tmp_pp40g_misc_reset.bf.mpif_rst = 0;
  TEN_REG_WRITE(TEN_PP40G_REG_ADDR(pDev, module_id, RESET), tmp_pp40g_misc_reset.wrd);

  TEN_MOD_UNLOCK(module_id, TEN_ID_PP40G);
  return (CS_OK);
}


/******************************************************************************/
/* $rtn_hdr_start   PP40G_RX_40GES6466_XCON                                   */
/* CATEGORY   : API                                                           */
/* ACCESS     : Public                                                        */
/* BLOCK      : PP40G                                                         */
/* CHIP       : Tenabo                                                        */
cs_status ten_pp40g_rx_40ges6466_xcon_t41(cs_uint16 module_id)
/* INPUTS     : o Module_id                                                   */
/* OUTPUTS    : ----                                                          */
/* RETURNS    : CS_OK or CS_ERROR                                             */
/* DESCRIPTION:                                                               */
/*   Configure PP40G                                                          */
/* $rtn_hdr_end                                                               */
/******************************************************************************/
{
  TEN_PP40G_MISC_RX_FUNCEN_t tmp_pp40g_misc_rx_funcen;
  TEN_PP40G_LIF_RX_CNTRL_t tmp_pp40g_lif_rx_cntrl;
  TEN_PP40G_PCS_RX_CSF_CNTRL_t tmp_pp40g_pcs_rx_csf_cntrl;
  TEN_PP40G_MISC_BYPASS_t tmp_pp40g_misc_bypass;
  TEN_PP40G_MAC_RX_MAXLEN_t tmp_pp40g_mac_rx_maxlen;
  TEN_PP40G_RS_RX_CNTRL_t tmp_pp40g_rs_rx_cntrl;
  T41_t *pDev = NULL;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, FALSE);
  TEN_MOD_LOCK(module_id, TEN_ID_PP40G);
  
  tmp_pp40g_misc_bypass.wrd = TEN_REG_READ(TEN_PP40G_REG_ADDR(pDev, module_id, BYPASS));
  tmp_pp40g_misc_bypass.bf.rx_bypass = 0;
  TEN_REG_WRITE(TEN_PP40G_REG_ADDR(pDev, module_id, BYPASS), tmp_pp40g_misc_bypass.wrd);

  /* TEN_MDELAY(6); Was used in simulation but probably not needed in a system */

  tmp_pp40g_misc_bypass.bf.rx_csf_en = 1;
  TEN_REG_WRITE(TEN_PP40G_REG_ADDR(pDev, module_id, BYPASS), tmp_pp40g_misc_bypass.wrd);

  /* TEN_MDELAY(6); Was used in simulation but probably not needed in a system */

  tmp_pp40g_pcs_rx_csf_cntrl.wrd = TEN_REG_READ(TEN_PP40G_REG_ADDR(pDev, module_id, CSF_CNTRL));
  tmp_pp40g_pcs_rx_csf_cntrl.bf.idle_en = 0;
  tmp_pp40g_pcs_rx_csf_cntrl.bf.rf_en = 0;
  TEN_REG_WRITE(TEN_PP40G_REG_ADDR(pDev, module_id, CSF_CNTRL), tmp_pp40g_pcs_rx_csf_cntrl.wrd);

  tmp_pp40g_misc_rx_funcen.wrd = TEN_REG_READ(TEN_PP40G_REG_ADDR(pDev, module_id, misc_rx_FUNCEN));
  tmp_pp40g_misc_rx_funcen.bf.fen_lif = 1;
  TEN_REG_WRITE(TEN_PP40G_REG_ADDR(pDev, module_id, misc_rx_FUNCEN), tmp_pp40g_misc_rx_funcen.wrd);

  /* TEN_MDELAY(6); Was used in simulation but probably not needed in a system */

  tmp_pp40g_misc_rx_funcen.bf.fen_lba = 0;
  TEN_REG_WRITE(TEN_PP40G_REG_ADDR(pDev, module_id, misc_rx_FUNCEN), tmp_pp40g_misc_rx_funcen.wrd);

  /* TEN_MDELAY(6); Was used in simulation but probably not needed in a system */

  tmp_pp40g_misc_rx_funcen.bf.fen_lds = 0;
  TEN_REG_WRITE(TEN_PP40G_REG_ADDR(pDev, module_id, misc_rx_FUNCEN), tmp_pp40g_misc_rx_funcen.wrd);

  /* TEN_MDELAY(6); Was used in simulation but probably not needed in a system */

  tmp_pp40g_misc_rx_funcen.bf.fen_lro = 0;
  TEN_REG_WRITE(TEN_PP40G_REG_ADDR(pDev, module_id, misc_rx_FUNCEN), tmp_pp40g_misc_rx_funcen.wrd);

  /* TEN_MDELAY(6); Was used in simulation but probably not needed in a system */

  tmp_pp40g_misc_rx_funcen.bf.fen_nra = 0;
  TEN_REG_WRITE(TEN_PP40G_REG_ADDR(pDev, module_id, misc_rx_FUNCEN), tmp_pp40g_misc_rx_funcen.wrd);

  /* TEN_MDELAY(6); Was used in simulation but probably not needed in a system */

  tmp_pp40g_misc_rx_funcen.bf.fen_bds_bdc = 1;
  TEN_REG_WRITE(TEN_PP40G_REG_ADDR(pDev, module_id, misc_rx_FUNCEN), tmp_pp40g_misc_rx_funcen.wrd);

  /* TEN_MDELAY(6); Was used in simulation but probably not needed in a system */

  tmp_pp40g_misc_rx_funcen.bf.fen_bds_rxi = 0;
  TEN_REG_WRITE(TEN_PP40G_REG_ADDR(pDev, module_id, misc_rx_FUNCEN), tmp_pp40g_misc_rx_funcen.wrd);

  /* TEN_MDELAY(6); Was used in simulation but probably not needed in a system */

  tmp_pp40g_misc_rx_funcen.bf.fen_bdc = 1;
  TEN_REG_WRITE(TEN_PP40G_REG_ADDR(pDev, module_id, misc_rx_FUNCEN), tmp_pp40g_misc_rx_funcen.wrd);

  /* TEN_MDELAY(6); Was used in simulation but probably not needed in a system */

  tmp_pp40g_misc_rx_funcen.bf.fen_rs = 1;
  TEN_REG_WRITE(TEN_PP40G_REG_ADDR(pDev, module_id, misc_rx_FUNCEN), tmp_pp40g_misc_rx_funcen.wrd);

  /* TEN_MDELAY(6); Was used in simulation but probably not needed in a system */

  tmp_pp40g_misc_rx_funcen.bf.fen_mac = 1;
  TEN_REG_WRITE(TEN_PP40G_REG_ADDR(pDev, module_id, misc_rx_FUNCEN), tmp_pp40g_misc_rx_funcen.wrd);

  /* TEN_MDELAY(6); Was used in simulation but probably not needed in a system */

  tmp_pp40g_misc_rx_funcen.bf.fen_dil = 0;
  TEN_REG_WRITE(TEN_PP40G_REG_ADDR(pDev, module_id, misc_rx_FUNCEN), tmp_pp40g_misc_rx_funcen.wrd);

  /* TEN_MDELAY(6); Was used in simulation but probably not needed in a system */

  tmp_pp40g_misc_rx_funcen.bf.fen_mba = 1;
  TEN_REG_WRITE(TEN_PP40G_REG_ADDR(pDev, module_id, misc_rx_FUNCEN), tmp_pp40g_misc_rx_funcen.wrd);

  /* TEN_MDELAY(6); Was used in simulation but probably not needed in a system */

  tmp_pp40g_misc_rx_funcen.bf.fen_xdc = 0;
  TEN_REG_WRITE(TEN_PP40G_REG_ADDR(pDev, module_id, misc_rx_FUNCEN), tmp_pp40g_misc_rx_funcen.wrd);

  /* TEN_MDELAY(6); Was used in simulation but probably not needed in a system */

  tmp_pp40g_lif_rx_cntrl.wrd = TEN_REG_READ(TEN_PP40G_REG_ADDR(pDev, module_id, lif_rx_CNTRL));
  tmp_pp40g_lif_rx_cntrl.bf.mono_mode = 1;
  TEN_REG_WRITE(TEN_PP40G_REG_ADDR(pDev, module_id, lif_rx_CNTRL), tmp_pp40g_lif_rx_cntrl.wrd);

  tmp_pp40g_rs_rx_cntrl.wrd = TEN_REG_READ(TEN_PP40G_REG_ADDR(pDev, module_id, rs_rx_CNTRL));
  tmp_pp40g_rs_rx_cntrl.bf.rs_active = 1;
  TEN_REG_WRITE(TEN_PP40G_REG_ADDR(pDev, module_id, rs_rx_CNTRL), tmp_pp40g_rs_rx_cntrl.wrd);

  tmp_pp40g_mac_rx_maxlen.wrd = TEN_REG_READ(TEN_PP40G_REG_ADDR(pDev, module_id, MAXLEN));
  tmp_pp40g_mac_rx_maxlen.bf.maxlen = 10000;
  TEN_REG_WRITE(TEN_PP40G_REG_ADDR(pDev, module_id, MAXLEN), tmp_pp40g_mac_rx_maxlen.wrd);

  TEN_MOD_UNLOCK(module_id, TEN_ID_PP40G);
  return (CS_OK);
}


/******************************************************************************/
/* $rtn_hdr_start   PP40G_RX_40GES6466_XCON_RA                                */
/* CATEGORY   : API                                                           */
/* ACCESS     : Public                                                        */
/* BLOCK      : PP40G                                                         */
/* CHIP       : Tenabo                                                        */
cs_status ten_pp40g_rx_40ges6466_xcon_ra_t41(cs_uint16 module_id)
/* INPUTS     : o Module_id                                                   */
/* OUTPUTS    : ----                                                          */
/* RETURNS    : CS_OK or CS_ERROR                                             */
/* DESCRIPTION:                                                               */
/*   Configure PP40G                                                          */
/* $rtn_hdr_end                                                               */
/******************************************************************************/
{
  TEN_PP40G_MISC_RX_FUNCEN_t tmp_pp40g_misc_rx_funcen;
  TEN_PP40G_MISC_RESET_t tmp_pp40g_misc_reset;
  TEN_PP40G_MISC_RX_CLKEN_t tmp_pp40g_misc_rx_clken;
  TEN_PP40G_LIF_RX_CNTRL_t tmp_pp40g_lif_rx_cntrl;
  TEN_PP40G_PCS_RX_CSF_CNTRL_t tmp_pp40g_pcs_rx_csf_cntrl;
  TEN_PP40G_MISC_CLKEN_t tmp_pp40g_misc_clken;
  TEN_PP40G_MISC_BYPASS_t tmp_pp40g_misc_bypass;
  TEN_PP40G_MAC_RX_MAXLEN_t tmp_pp40g_mac_rx_maxlen;
  TEN_PP40G_RS_RX_CNTRL_t tmp_pp40g_rs_rx_cntrl;
  TEN_PP40G_PCS_RX_RATE_CNTRL_t tmp_pp40g_pcs_rx_rate_cntrl;
  T41_t *pDev = NULL;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, FALSE);
  TEN_MOD_LOCK(module_id, TEN_ID_PP40G);
  
  tmp_pp40g_misc_clken.wrd = TEN_REG_READ(TEN_PP40G_REG_ADDR(pDev, module_id, misc_CLKEN));
  tmp_pp40g_misc_clken.bf.clken_rx = 1;
  TEN_REG_WRITE(TEN_PP40G_REG_ADDR(pDev, module_id, misc_CLKEN), tmp_pp40g_misc_clken.wrd);

  /* TEN_MDELAY(6); Was used in simulation but probably not needed in a system */

  tmp_pp40g_misc_clken.bf.clken_pm = 1;
  TEN_REG_WRITE(TEN_PP40G_REG_ADDR(pDev, module_id, misc_CLKEN), tmp_pp40g_misc_clken.wrd);

  /* TEN_MDELAY(6); Was used in simulation but probably not needed in a system */

  tmp_pp40g_misc_rx_clken.wrd = 0x3aa1;
  TEN_REG_WRITE(TEN_PP40G_REG_ADDR(pDev, module_id, misc_rx_CLKEN), tmp_pp40g_misc_rx_clken.wrd);

  /* TEN_MDELAY(6); Was used in simulation but probably not needed in a system */

  tmp_pp40g_misc_reset.wrd = TEN_REG_READ(TEN_PP40G_REG_ADDR(pDev, module_id, RESET));
  tmp_pp40g_misc_reset.bf.mpif_rst = 0;
  TEN_REG_WRITE(TEN_PP40G_REG_ADDR(pDev, module_id, RESET), tmp_pp40g_misc_reset.wrd);

  /* TEN_MDELAY(6); Was used in simulation but probably not needed in a system */

  tmp_pp40g_misc_bypass.wrd = TEN_REG_READ(TEN_PP40G_REG_ADDR(pDev, module_id, BYPASS));
  tmp_pp40g_misc_bypass.bf.rx_bypass = 0;
  TEN_REG_WRITE(TEN_PP40G_REG_ADDR(pDev, module_id, BYPASS), tmp_pp40g_misc_bypass.wrd);

  /* TEN_MDELAY(6); Was used in simulation but probably not needed in a system */

  tmp_pp40g_misc_bypass.bf.rx_csf_en = 1;
  TEN_REG_WRITE(TEN_PP40G_REG_ADDR(pDev, module_id, BYPASS), tmp_pp40g_misc_bypass.wrd);

  /* TEN_MDELAY(6); Was used in simulation but probably not needed in a system */

  tmp_pp40g_pcs_rx_csf_cntrl.wrd = TEN_REG_READ(TEN_PP40G_REG_ADDR(pDev, module_id, CSF_CNTRL));
  tmp_pp40g_pcs_rx_csf_cntrl.bf.idle_en = 0;
  tmp_pp40g_pcs_rx_csf_cntrl.bf.rf_en = 0;
  TEN_REG_WRITE(TEN_PP40G_REG_ADDR(pDev, module_id, CSF_CNTRL), tmp_pp40g_pcs_rx_csf_cntrl.wrd);

  tmp_pp40g_misc_rx_funcen.wrd = TEN_REG_READ(TEN_PP40G_REG_ADDR(pDev, module_id, misc_rx_FUNCEN));
  tmp_pp40g_misc_rx_funcen.bf.fen_lif = 1;
  TEN_REG_WRITE(TEN_PP40G_REG_ADDR(pDev, module_id, misc_rx_FUNCEN), tmp_pp40g_misc_rx_funcen.wrd);

  /* TEN_MDELAY(6); Was used in simulation but probably not needed in a system */

  tmp_pp40g_misc_rx_funcen.bf.fen_lba = 0;
  TEN_REG_WRITE(TEN_PP40G_REG_ADDR(pDev, module_id, misc_rx_FUNCEN), tmp_pp40g_misc_rx_funcen.wrd);

  /* TEN_MDELAY(6); Was used in simulation but probably not needed in a system */

  tmp_pp40g_misc_rx_funcen.bf.fen_lds = 0;
  TEN_REG_WRITE(TEN_PP40G_REG_ADDR(pDev, module_id, misc_rx_FUNCEN), tmp_pp40g_misc_rx_funcen.wrd);

  /* TEN_MDELAY(6); Was used in simulation but probably not needed in a system */

  tmp_pp40g_misc_rx_funcen.bf.fen_lro = 0;
  TEN_REG_WRITE(TEN_PP40G_REG_ADDR(pDev, module_id, misc_rx_FUNCEN), tmp_pp40g_misc_rx_funcen.wrd);

  /* TEN_MDELAY(6); Was used in simulation but probably not needed in a system */

  tmp_pp40g_misc_rx_funcen.bf.fen_nra = 1;
  TEN_REG_WRITE(TEN_PP40G_REG_ADDR(pDev, module_id, misc_rx_FUNCEN), tmp_pp40g_misc_rx_funcen.wrd);

  /* TEN_MDELAY(6); Was used in simulation but probably not needed in a system */

  tmp_pp40g_misc_rx_funcen.bf.fen_bds_bdc = 1;
  TEN_REG_WRITE(TEN_PP40G_REG_ADDR(pDev, module_id, misc_rx_FUNCEN), tmp_pp40g_misc_rx_funcen.wrd);

  /* TEN_MDELAY(6); Was used in simulation but probably not needed in a system */

  tmp_pp40g_misc_rx_funcen.bf.fen_bds_rxi = 1;
  TEN_REG_WRITE(TEN_PP40G_REG_ADDR(pDev, module_id, misc_rx_FUNCEN), tmp_pp40g_misc_rx_funcen.wrd);

  /* TEN_MDELAY(6); Was used in simulation but probably not needed in a system */

  tmp_pp40g_misc_rx_funcen.bf.fen_bdc = 1;
  TEN_REG_WRITE(TEN_PP40G_REG_ADDR(pDev, module_id, misc_rx_FUNCEN), tmp_pp40g_misc_rx_funcen.wrd);

  /* TEN_MDELAY(6); Was used in simulation but probably not needed in a system */

  tmp_pp40g_misc_rx_funcen.bf.fen_rs = 1;
  TEN_REG_WRITE(TEN_PP40G_REG_ADDR(pDev, module_id, misc_rx_FUNCEN), tmp_pp40g_misc_rx_funcen.wrd);

  /* TEN_MDELAY(6); Was used in simulation but probably not needed in a system */

  tmp_pp40g_misc_rx_funcen.bf.fen_mac = 1;
  TEN_REG_WRITE(TEN_PP40G_REG_ADDR(pDev, module_id, misc_rx_FUNCEN), tmp_pp40g_misc_rx_funcen.wrd);

  /* TEN_MDELAY(6); Was used in simulation but probably not needed in a system */

  tmp_pp40g_misc_rx_funcen.bf.fen_dil = 0;
  TEN_REG_WRITE(TEN_PP40G_REG_ADDR(pDev, module_id, misc_rx_FUNCEN), tmp_pp40g_misc_rx_funcen.wrd);

  /* TEN_MDELAY(6); Was used in simulation but probably not needed in a system */

  tmp_pp40g_misc_rx_funcen.bf.fen_mba = 1;
  TEN_REG_WRITE(TEN_PP40G_REG_ADDR(pDev, module_id, misc_rx_FUNCEN), tmp_pp40g_misc_rx_funcen.wrd);

  /* TEN_MDELAY(6); Was used in simulation but probably not needed in a system */

  tmp_pp40g_misc_rx_funcen.bf.fen_xdc = 0;
  TEN_REG_WRITE(TEN_PP40G_REG_ADDR(pDev, module_id, misc_rx_FUNCEN), tmp_pp40g_misc_rx_funcen.wrd);

  /* TEN_MDELAY(6); Was used in simulation but probably not needed in a system */

  tmp_pp40g_lif_rx_cntrl.wrd = TEN_REG_READ(TEN_PP40G_REG_ADDR(pDev, module_id, lif_rx_CNTRL));
  tmp_pp40g_lif_rx_cntrl.bf.mono_mode = 1;
  TEN_REG_WRITE(TEN_PP40G_REG_ADDR(pDev, module_id, lif_rx_CNTRL), tmp_pp40g_lif_rx_cntrl.wrd);

  tmp_pp40g_rs_rx_cntrl.wrd = TEN_REG_READ(TEN_PP40G_REG_ADDR(pDev, module_id, rs_rx_CNTRL));
  tmp_pp40g_rs_rx_cntrl.bf.rs_active = 1;
  TEN_REG_WRITE(TEN_PP40G_REG_ADDR(pDev, module_id, rs_rx_CNTRL), tmp_pp40g_rs_rx_cntrl.wrd);

  tmp_pp40g_mac_rx_maxlen.wrd = TEN_REG_READ(TEN_PP40G_REG_ADDR(pDev, module_id, MAXLEN));
  tmp_pp40g_mac_rx_maxlen.bf.maxlen = 10000;
  TEN_REG_WRITE(TEN_PP40G_REG_ADDR(pDev, module_id, MAXLEN), tmp_pp40g_mac_rx_maxlen.wrd);

  tmp_pp40g_pcs_rx_rate_cntrl.wrd = 0;
  TEN_REG_WRITE(TEN_PP40G_REG_ADDR(pDev, module_id, pcs_rx_RATE_CNTRL), tmp_pp40g_pcs_rx_rate_cntrl.wrd);

  TEN_MOD_UNLOCK(module_id, TEN_ID_PP40G);
  return (CS_OK);
}


/******************************************************************************/
/* $rtn_hdr_start   PP40G_RX_40GEX_XCON_CLOCKS                                */
/* CATEGORY   : API                                                           */
/* ACCESS     : Public                                                        */
/* BLOCK      : PP40G                                                         */
/* CHIP       : Tenabo                                                        */
cs_status ten_pp40g_rx_40gex_xcon_clocks_t41(cs_uint16 module_id)
/* INPUTS     : o Module_id                                                   */
/* OUTPUTS    : ----                                                          */
/* RETURNS    : CS_OK or CS_ERROR                                             */
/* DESCRIPTION:                                                               */
/*   Configure PP40G                                                          */
/* $rtn_hdr_end                                                               */
/******************************************************************************/
{
  TEN_PP40G_MISC_RESET_t tmp_pp40g_misc_reset;
  TEN_PP40G_MISC_RX_CLKEN_t tmp_pp40g_misc_rx_clken;
  TEN_PP40G_MISC_CLKEN_t tmp_pp40g_misc_clken;
  T41_t *pDev = NULL;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, FALSE);
  TEN_MOD_LOCK(module_id, TEN_ID_PP40G);
  
  tmp_pp40g_misc_clken.wrd = TEN_REG_READ(TEN_PP40G_REG_ADDR(pDev, module_id, misc_CLKEN));
  tmp_pp40g_misc_clken.bf.clken_rx = 1;
  TEN_REG_WRITE(TEN_PP40G_REG_ADDR(pDev, module_id, misc_CLKEN), tmp_pp40g_misc_clken.wrd);

  /* TEN_MDELAY(6); Was used in simulation but probably not needed in a system */

  tmp_pp40g_misc_clken.bf.clken_pm = 1;
  TEN_REG_WRITE(TEN_PP40G_REG_ADDR(pDev, module_id, misc_CLKEN), tmp_pp40g_misc_clken.wrd);

  /* TEN_MDELAY(6); Was used in simulation but probably not needed in a system */

  tmp_pp40g_misc_rx_clken.wrd = 0x32c1;
  TEN_REG_WRITE(TEN_PP40G_REG_ADDR(pDev, module_id, misc_rx_CLKEN), tmp_pp40g_misc_rx_clken.wrd);

  /* TEN_MDELAY(6); Was used in simulation but probably not needed in a system */

  tmp_pp40g_misc_reset.wrd = TEN_REG_READ(TEN_PP40G_REG_ADDR(pDev, module_id, RESET));
  tmp_pp40g_misc_reset.bf.mpif_rst = 0;
  TEN_REG_WRITE(TEN_PP40G_REG_ADDR(pDev, module_id, RESET), tmp_pp40g_misc_reset.wrd);

  /* TEN_MDELAY(6); Was used in simulation but probably not needed in a system */
  TEN_MOD_UNLOCK(module_id, TEN_ID_PP40G);
  return (CS_OK);
}


/******************************************************************************/
/* $rtn_hdr_start   PP40G_RX_40GEX_XCON                                       */
/* CATEGORY   : API                                                           */
/* ACCESS     : Public                                                        */
/* BLOCK      : PP40G                                                         */
/* CHIP       : Tenabo                                                        */
cs_status ten_pp40g_rx_40gex_xcon_t41(cs_uint16 module_id)
/* INPUTS     : o Module_id                                                   */
/* OUTPUTS    : ----                                                          */
/* RETURNS    : CS_OK or CS_ERROR                                             */
/* DESCRIPTION:                                                               */
/*   Configure PP40G                                                          */
/* $rtn_hdr_end                                                               */
/******************************************************************************/
{
  TEN_PP40G_MISC_RX_FUNCEN_t tmp_pp40g_misc_rx_funcen;
  TEN_PP40G_LIF_RX_CNTRL_t tmp_pp40g_lif_rx_cntrl;
  TEN_PP40G_PCS_RX_CSF_CNTRL_t tmp_pp40g_pcs_rx_csf_cntrl;
  TEN_PP40G_MISC_BYPASS_t tmp_pp40g_misc_bypass;
  TEN_PP40G_MAC_RX_MAXLEN_t tmp_pp40g_mac_rx_maxlen;
  TEN_PP40G_RS_RX_CNTRL_t tmp_pp40g_rs_rx_cntrl;
  T41_t *pDev = NULL;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, FALSE);
  TEN_MOD_LOCK(module_id, TEN_ID_PP40G);
  
  tmp_pp40g_misc_bypass.wrd = TEN_REG_READ(TEN_PP40G_REG_ADDR(pDev, module_id, BYPASS));
  tmp_pp40g_misc_bypass.bf.rx_bypass = 0;
  TEN_REG_WRITE(TEN_PP40G_REG_ADDR(pDev, module_id, BYPASS), tmp_pp40g_misc_bypass.wrd);

  /* TEN_MDELAY(6); Was used in simulation but probably not needed in a system */

  tmp_pp40g_misc_bypass.bf.rx_csf_en = 1;
  TEN_REG_WRITE(TEN_PP40G_REG_ADDR(pDev, module_id, BYPASS), tmp_pp40g_misc_bypass.wrd);

  /* TEN_MDELAY(6); Was used in simulation but probably not needed in a system */

  tmp_pp40g_pcs_rx_csf_cntrl.wrd = TEN_REG_READ(TEN_PP40G_REG_ADDR(pDev, module_id, CSF_CNTRL));
  tmp_pp40g_pcs_rx_csf_cntrl.bf.idle_en = 0;
  tmp_pp40g_pcs_rx_csf_cntrl.bf.rf_en = 0;
  TEN_REG_WRITE(TEN_PP40G_REG_ADDR(pDev, module_id, CSF_CNTRL), tmp_pp40g_pcs_rx_csf_cntrl.wrd);

  tmp_pp40g_misc_rx_funcen.wrd = TEN_REG_READ(TEN_PP40G_REG_ADDR(pDev, module_id, misc_rx_FUNCEN));
  tmp_pp40g_misc_rx_funcen.bf.fen_lif = 1;
  TEN_REG_WRITE(TEN_PP40G_REG_ADDR(pDev, module_id, misc_rx_FUNCEN), tmp_pp40g_misc_rx_funcen.wrd);

  /* TEN_MDELAY(6); Was used in simulation but probably not needed in a system */

  tmp_pp40g_misc_rx_funcen.bf.fen_lba = 0;
  TEN_REG_WRITE(TEN_PP40G_REG_ADDR(pDev, module_id, misc_rx_FUNCEN), tmp_pp40g_misc_rx_funcen.wrd);

  /* TEN_MDELAY(6); Was used in simulation but probably not needed in a system */

  tmp_pp40g_misc_rx_funcen.bf.fen_lds = 0;
  TEN_REG_WRITE(TEN_PP40G_REG_ADDR(pDev, module_id, misc_rx_FUNCEN), tmp_pp40g_misc_rx_funcen.wrd);

  /* TEN_MDELAY(6); Was used in simulation but probably not needed in a system */

  tmp_pp40g_misc_rx_funcen.bf.fen_lro = 0;
  TEN_REG_WRITE(TEN_PP40G_REG_ADDR(pDev, module_id, misc_rx_FUNCEN), tmp_pp40g_misc_rx_funcen.wrd);

  /* TEN_MDELAY(6); Was used in simulation but probably not needed in a system */

  tmp_pp40g_misc_rx_funcen.bf.fen_nra = 0;
  TEN_REG_WRITE(TEN_PP40G_REG_ADDR(pDev, module_id, misc_rx_FUNCEN), tmp_pp40g_misc_rx_funcen.wrd);

  /* TEN_MDELAY(6); Was used in simulation but probably not needed in a system */

  tmp_pp40g_misc_rx_funcen.bf.fen_bds_bdc = 1;
  TEN_REG_WRITE(TEN_PP40G_REG_ADDR(pDev, module_id, misc_rx_FUNCEN), tmp_pp40g_misc_rx_funcen.wrd);

  /* TEN_MDELAY(6); Was used in simulation but probably not needed in a system */

  tmp_pp40g_misc_rx_funcen.bf.fen_bds_rxi = 0;
  TEN_REG_WRITE(TEN_PP40G_REG_ADDR(pDev, module_id, misc_rx_FUNCEN), tmp_pp40g_misc_rx_funcen.wrd);

  /* TEN_MDELAY(6); Was used in simulation but probably not needed in a system */

  tmp_pp40g_misc_rx_funcen.bf.fen_bdc = 1;
  TEN_REG_WRITE(TEN_PP40G_REG_ADDR(pDev, module_id, misc_rx_FUNCEN), tmp_pp40g_misc_rx_funcen.wrd);

  /* TEN_MDELAY(6); Was used in simulation but probably not needed in a system */

  tmp_pp40g_misc_rx_funcen.bf.fen_rs = 1;
  TEN_REG_WRITE(TEN_PP40G_REG_ADDR(pDev, module_id, misc_rx_FUNCEN), tmp_pp40g_misc_rx_funcen.wrd);

  /* TEN_MDELAY(6); Was used in simulation but probably not needed in a system */

  tmp_pp40g_misc_rx_funcen.bf.fen_mac = 1;
  TEN_REG_WRITE(TEN_PP40G_REG_ADDR(pDev, module_id, misc_rx_FUNCEN), tmp_pp40g_misc_rx_funcen.wrd);

  /* TEN_MDELAY(6); Was used in simulation but probably not needed in a system */

  tmp_pp40g_misc_rx_funcen.bf.fen_dil = 0;
  TEN_REG_WRITE(TEN_PP40G_REG_ADDR(pDev, module_id, misc_rx_FUNCEN), tmp_pp40g_misc_rx_funcen.wrd);

  /* TEN_MDELAY(6); Was used in simulation but probably not needed in a system */

  tmp_pp40g_misc_rx_funcen.bf.fen_mba = 0;
  TEN_REG_WRITE(TEN_PP40G_REG_ADDR(pDev, module_id, misc_rx_FUNCEN), tmp_pp40g_misc_rx_funcen.wrd);

  /* TEN_MDELAY(6); Was used in simulation but probably not needed in a system */

  tmp_pp40g_misc_rx_funcen.bf.fen_xdc = 1;
  TEN_REG_WRITE(TEN_PP40G_REG_ADDR(pDev, module_id, misc_rx_FUNCEN), tmp_pp40g_misc_rx_funcen.wrd);

  /* TEN_MDELAY(6); Was used in simulation but probably not needed in a system */

  tmp_pp40g_lif_rx_cntrl.wrd = TEN_REG_READ(TEN_PP40G_REG_ADDR(pDev, module_id, lif_rx_CNTRL));
  tmp_pp40g_lif_rx_cntrl.bf.mono_mode = 1;
  TEN_REG_WRITE(TEN_PP40G_REG_ADDR(pDev, module_id, lif_rx_CNTRL), tmp_pp40g_lif_rx_cntrl.wrd);

  tmp_pp40g_rs_rx_cntrl.wrd = TEN_REG_READ(TEN_PP40G_REG_ADDR(pDev, module_id, rs_rx_CNTRL));
  tmp_pp40g_rs_rx_cntrl.bf.rs_active = 1;
  TEN_REG_WRITE(TEN_PP40G_REG_ADDR(pDev, module_id, rs_rx_CNTRL), tmp_pp40g_rs_rx_cntrl.wrd);

  tmp_pp40g_mac_rx_maxlen.wrd = TEN_REG_READ(TEN_PP40G_REG_ADDR(pDev, module_id, MAXLEN));
  tmp_pp40g_mac_rx_maxlen.bf.maxlen = 10000;
  TEN_REG_WRITE(TEN_PP40G_REG_ADDR(pDev, module_id, MAXLEN), tmp_pp40g_mac_rx_maxlen.wrd);

  TEN_MOD_UNLOCK(module_id, TEN_ID_PP40G);
  return (CS_OK);
}


/******************************************************************************/
/* $rtn_hdr_start   PP40G_RX_40GEX_XCON_RA                                    */
/* CATEGORY   : API                                                           */
/* ACCESS     : Public                                                        */
/* BLOCK      : PP40G                                                         */
/* CHIP       : Tenabo                                                        */
cs_status ten_pp40g_rx_40gex_xcon_ra_t41(cs_uint16 module_id)
/* INPUTS     : o Module_id                                                   */
/* OUTPUTS    : ----                                                          */
/* RETURNS    : CS_OK or CS_ERROR                                             */
/* DESCRIPTION:                                                               */
/*   Configure PP40G                                                          */
/* $rtn_hdr_end                                                               */
/******************************************************************************/
{
  TEN_PP40G_MISC_RX_FUNCEN_t tmp_pp40g_misc_rx_funcen;
  TEN_PP40G_MISC_RESET_t tmp_pp40g_misc_reset;
  TEN_PP40G_MISC_RX_CLKEN_t tmp_pp40g_misc_rx_clken;
  TEN_PP40G_LIF_RX_CNTRL_t tmp_pp40g_lif_rx_cntrl;
  TEN_PP40G_PCS_RX_CSF_CNTRL_t tmp_pp40g_pcs_rx_csf_cntrl;
  TEN_PP40G_MISC_CLKEN_t tmp_pp40g_misc_clken;
  TEN_PP40G_MISC_BYPASS_t tmp_pp40g_misc_bypass;
  TEN_PP40G_MAC_RX_MAXLEN_t tmp_pp40g_mac_rx_maxlen;
  TEN_PP40G_RS_RX_CNTRL_t tmp_pp40g_rs_rx_cntrl;
  TEN_PP40G_PCS_RX_RATE_CNTRL_t tmp_pp40g_pcs_rx_rate_cntrl;
  T41_t *pDev = NULL;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, FALSE);
  TEN_MOD_LOCK(module_id, TEN_ID_PP40G);
  
  tmp_pp40g_misc_clken.wrd = TEN_REG_READ(TEN_PP40G_REG_ADDR(pDev, module_id, misc_CLKEN));
  tmp_pp40g_misc_clken.bf.clken_rx = 1;
  TEN_REG_WRITE(TEN_PP40G_REG_ADDR(pDev, module_id, misc_CLKEN), tmp_pp40g_misc_clken.wrd);

  /* TEN_MDELAY(6); Was used in simulation but probably not needed in a system */

  tmp_pp40g_misc_clken.bf.clken_pm = 1;
  TEN_REG_WRITE(TEN_PP40G_REG_ADDR(pDev, module_id, misc_CLKEN), tmp_pp40g_misc_clken.wrd);

  /* TEN_MDELAY(6); Was used in simulation but probably not needed in a system */

  tmp_pp40g_misc_rx_clken.wrd = 0x3ac1;
  TEN_REG_WRITE(TEN_PP40G_REG_ADDR(pDev, module_id, misc_rx_CLKEN), tmp_pp40g_misc_rx_clken.wrd);

  /* TEN_MDELAY(6); Was used in simulation but probably not needed in a system */

  tmp_pp40g_misc_reset.wrd = TEN_REG_READ(TEN_PP40G_REG_ADDR(pDev, module_id, RESET));
  tmp_pp40g_misc_reset.bf.mpif_rst = 0;
  TEN_REG_WRITE(TEN_PP40G_REG_ADDR(pDev, module_id, RESET), tmp_pp40g_misc_reset.wrd);

  /* TEN_MDELAY(6); Was used in simulation but probably not needed in a system */

  tmp_pp40g_misc_bypass.wrd = TEN_REG_READ(TEN_PP40G_REG_ADDR(pDev, module_id, BYPASS));
  tmp_pp40g_misc_bypass.bf.rx_bypass = 0;
  TEN_REG_WRITE(TEN_PP40G_REG_ADDR(pDev, module_id, BYPASS), tmp_pp40g_misc_bypass.wrd);

  /* TEN_MDELAY(6); Was used in simulation but probably not needed in a system */

  tmp_pp40g_misc_bypass.bf.rx_csf_en = 1;
  TEN_REG_WRITE(TEN_PP40G_REG_ADDR(pDev, module_id, BYPASS), tmp_pp40g_misc_bypass.wrd);

  /* TEN_MDELAY(6); Was used in simulation but probably not needed in a system */

  tmp_pp40g_pcs_rx_csf_cntrl.wrd = TEN_REG_READ(TEN_PP40G_REG_ADDR(pDev, module_id, CSF_CNTRL));
  tmp_pp40g_pcs_rx_csf_cntrl.bf.idle_en = 0;
  tmp_pp40g_pcs_rx_csf_cntrl.bf.rf_en = 0;
  TEN_REG_WRITE(TEN_PP40G_REG_ADDR(pDev, module_id, CSF_CNTRL), tmp_pp40g_pcs_rx_csf_cntrl.wrd);

  tmp_pp40g_misc_rx_funcen.wrd = TEN_REG_READ(TEN_PP40G_REG_ADDR(pDev, module_id, misc_rx_FUNCEN));
  tmp_pp40g_misc_rx_funcen.bf.fen_lif = 1;
  TEN_REG_WRITE(TEN_PP40G_REG_ADDR(pDev, module_id, misc_rx_FUNCEN), tmp_pp40g_misc_rx_funcen.wrd);

  /* TEN_MDELAY(6); Was used in simulation but probably not needed in a system */

  tmp_pp40g_misc_rx_funcen.bf.fen_lba = 0;
  TEN_REG_WRITE(TEN_PP40G_REG_ADDR(pDev, module_id, misc_rx_FUNCEN), tmp_pp40g_misc_rx_funcen.wrd);

  /* TEN_MDELAY(6); Was used in simulation but probably not needed in a system */

  tmp_pp40g_misc_rx_funcen.bf.fen_lds = 0;
  TEN_REG_WRITE(TEN_PP40G_REG_ADDR(pDev, module_id, misc_rx_FUNCEN), tmp_pp40g_misc_rx_funcen.wrd);

  /* TEN_MDELAY(6); Was used in simulation but probably not needed in a system */

  tmp_pp40g_misc_rx_funcen.bf.fen_lro = 0;
  TEN_REG_WRITE(TEN_PP40G_REG_ADDR(pDev, module_id, misc_rx_FUNCEN), tmp_pp40g_misc_rx_funcen.wrd);

  /* TEN_MDELAY(6); Was used in simulation but probably not needed in a system */

  tmp_pp40g_misc_rx_funcen.bf.fen_nra = 1;
  TEN_REG_WRITE(TEN_PP40G_REG_ADDR(pDev, module_id, misc_rx_FUNCEN), tmp_pp40g_misc_rx_funcen.wrd);

  /* TEN_MDELAY(6); Was used in simulation but probably not needed in a system */

  tmp_pp40g_misc_rx_funcen.bf.fen_bds_bdc = 1;
  TEN_REG_WRITE(TEN_PP40G_REG_ADDR(pDev, module_id, misc_rx_FUNCEN), tmp_pp40g_misc_rx_funcen.wrd);

  /* TEN_MDELAY(6); Was used in simulation but probably not needed in a system */

  tmp_pp40g_misc_rx_funcen.bf.fen_bds_rxi = 1;
  TEN_REG_WRITE(TEN_PP40G_REG_ADDR(pDev, module_id, misc_rx_FUNCEN), tmp_pp40g_misc_rx_funcen.wrd);

  /* TEN_MDELAY(6); Was used in simulation but probably not needed in a system */

  tmp_pp40g_misc_rx_funcen.bf.fen_bdc = 1;
  TEN_REG_WRITE(TEN_PP40G_REG_ADDR(pDev, module_id, misc_rx_FUNCEN), tmp_pp40g_misc_rx_funcen.wrd);

  /* TEN_MDELAY(6); Was used in simulation but probably not needed in a system */

  tmp_pp40g_misc_rx_funcen.bf.fen_rs = 1;
  TEN_REG_WRITE(TEN_PP40G_REG_ADDR(pDev, module_id, misc_rx_FUNCEN), tmp_pp40g_misc_rx_funcen.wrd);

  /* TEN_MDELAY(6); Was used in simulation but probably not needed in a system */

  tmp_pp40g_misc_rx_funcen.bf.fen_mac = 1;
  TEN_REG_WRITE(TEN_PP40G_REG_ADDR(pDev, module_id, misc_rx_FUNCEN), tmp_pp40g_misc_rx_funcen.wrd);

  /* TEN_MDELAY(6); Was used in simulation but probably not needed in a system */

  tmp_pp40g_misc_rx_funcen.bf.fen_dil = 0;
  TEN_REG_WRITE(TEN_PP40G_REG_ADDR(pDev, module_id, misc_rx_FUNCEN), tmp_pp40g_misc_rx_funcen.wrd);

  /* TEN_MDELAY(6); Was used in simulation but probably not needed in a system */

  tmp_pp40g_misc_rx_funcen.bf.fen_mba = 0;
  TEN_REG_WRITE(TEN_PP40G_REG_ADDR(pDev, module_id, misc_rx_FUNCEN), tmp_pp40g_misc_rx_funcen.wrd);

  /* TEN_MDELAY(6); Was used in simulation but probably not needed in a system */

  tmp_pp40g_misc_rx_funcen.bf.fen_xdc = 1;
  TEN_REG_WRITE(TEN_PP40G_REG_ADDR(pDev, module_id, misc_rx_FUNCEN), tmp_pp40g_misc_rx_funcen.wrd);

  /* TEN_MDELAY(6); Was used in simulation but probably not needed in a system */

  tmp_pp40g_lif_rx_cntrl.wrd = TEN_REG_READ(TEN_PP40G_REG_ADDR(pDev, module_id, lif_rx_CNTRL));
  tmp_pp40g_lif_rx_cntrl.bf.mono_mode = 1;
  TEN_REG_WRITE(TEN_PP40G_REG_ADDR(pDev, module_id, lif_rx_CNTRL), tmp_pp40g_lif_rx_cntrl.wrd);

  tmp_pp40g_rs_rx_cntrl.wrd = TEN_REG_READ(TEN_PP40G_REG_ADDR(pDev, module_id, rs_rx_CNTRL));
  tmp_pp40g_rs_rx_cntrl.bf.rs_active = 1;
  TEN_REG_WRITE(TEN_PP40G_REG_ADDR(pDev, module_id, rs_rx_CNTRL), tmp_pp40g_rs_rx_cntrl.wrd);

  tmp_pp40g_mac_rx_maxlen.wrd = TEN_REG_READ(TEN_PP40G_REG_ADDR(pDev, module_id, MAXLEN));
  tmp_pp40g_mac_rx_maxlen.bf.maxlen = 10000;
  TEN_REG_WRITE(TEN_PP40G_REG_ADDR(pDev, module_id, MAXLEN), tmp_pp40g_mac_rx_maxlen.wrd);

  tmp_pp40g_pcs_rx_rate_cntrl.wrd = 0;
  TEN_REG_WRITE(TEN_PP40G_REG_ADDR(pDev, module_id, pcs_rx_RATE_CNTRL), tmp_pp40g_pcs_rx_rate_cntrl.wrd);

  TEN_MOD_UNLOCK(module_id, TEN_ID_PP40G);
  return (CS_OK);
}


/******************************************************************************/
/* $rtn_hdr_start   PP40G_RX_PP40G_PM_TICK_MODE                               */
/* CATEGORY   : API                                                           */
/* ACCESS     : Public                                                        */
/* BLOCK      : PP40G                                                         */
/* CHIP       : Tenabo                                                        */
cs_status ten_pp40g_rx_pp40g_pm_tick_mode_t41(cs_uint16 module_id)
/* INPUTS     : o Module_id                                                   */
/* OUTPUTS    : ----                                                          */
/* RETURNS    : CS_OK or CS_ERROR                                             */
/* DESCRIPTION:                                                               */
/*   Configure PP40G Performance Monitoring for Tick mode and SW tick         */
/* $rtn_hdr_end                                                               */
/******************************************************************************/
{
  TEN_PP40G_PM_CTRL_t tmp_pp40g_pm_ctrl;
  T41_t *pDev = NULL;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, FALSE);
  TEN_MOD_LOCK(module_id, TEN_ID_PP40G);
  
  tmp_pp40g_pm_ctrl.wrd = TEN_REG_READ(TEN_PP40G_REG_ADDR(pDev, module_id, CTRL));
  tmp_pp40g_pm_ctrl.bf.sel_tick1sec = 0x6;
  tmp_pp40g_pm_ctrl.bf.mode = 1;
  TEN_REG_WRITE(TEN_PP40G_REG_ADDR(pDev, module_id, CTRL), tmp_pp40g_pm_ctrl.wrd);

  TEN_MOD_UNLOCK(module_id, TEN_ID_PP40G);
  return (CS_OK);
}


/******************************************************************************/
/* $rtn_hdr_start   PP40G_TX_PP40G_TX_BYPASS                                  */
/* CATEGORY   : API                                                           */
/* ACCESS     : Public                                                        */
/* BLOCK      : PP40G                                                         */
/* CHIP       : Tenabo                                                        */
cs_status ten_pp40g_tx_pp40g_tx_bypass_t41(cs_uint16 module_id)
/* INPUTS     : o Module_id                                                   */
/* OUTPUTS    : ----                                                          */
/* RETURNS    : CS_OK or CS_ERROR                                             */
/* DESCRIPTION:                                                               */
/*   Configure PP40G                                                          */
/* $rtn_hdr_end                                                               */
/******************************************************************************/
{
  TEN_PP40G_MISC_BYPASS_t tmp_pp40g_misc_bypass;
  T41_t *pDev = NULL;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, FALSE);
  TEN_MOD_LOCK(module_id, TEN_ID_PP40G);
  
  tmp_pp40g_misc_bypass.wrd = TEN_REG_READ(TEN_PP40G_REG_ADDR(pDev, module_id, BYPASS));
  tmp_pp40g_misc_bypass.bf.tx_bypass = 1;
  TEN_REG_WRITE(TEN_PP40G_REG_ADDR(pDev, module_id, BYPASS), tmp_pp40g_misc_bypass.wrd);

  /* TEN_MDELAY(6); Was used in simulation but probably not needed in a system */
  TEN_MOD_UNLOCK(module_id, TEN_ID_PP40G);
  return (CS_OK);
}


/******************************************************************************/
/* $rtn_hdr_start   PP40G_TX_XCON_40GEP_CLOCKS                                */
/* CATEGORY   : API                                                           */
/* ACCESS     : Public                                                        */
/* BLOCK      : PP40G                                                         */
/* CHIP       : Tenabo                                                        */
cs_status ten_pp40g_tx_xcon_40gep_clocks_t41(cs_uint16 module_id)
/* INPUTS     : o Module_id                                                   */
/* OUTPUTS    : ----                                                          */
/* RETURNS    : CS_OK or CS_ERROR                                             */
/* DESCRIPTION:                                                               */
/*   Configure PP40G                                                          */
/* $rtn_hdr_end                                                               */
/******************************************************************************/
{
  TEN_PP40G_MISC_CLKEN_t tmp_pp40g_misc_clken;
  TEN_PP40G_MISC_TX_CLKEN_t tmp_pp40g_misc_tx_clken;
  T41_t *pDev = NULL;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, FALSE);
  TEN_MOD_LOCK(module_id, TEN_ID_PP40G);
  
  tmp_pp40g_misc_clken.wrd = TEN_REG_READ(TEN_PP40G_REG_ADDR(pDev, module_id, misc_CLKEN));
  tmp_pp40g_misc_clken.bf.clken_tx = 1;
  TEN_REG_WRITE(TEN_PP40G_REG_ADDR(pDev, module_id, misc_CLKEN), tmp_pp40g_misc_clken.wrd);

  /* TEN_MDELAY(6); Was used in simulation but probably not needed in a system */

  tmp_pp40g_misc_clken.bf.clken_pm = 1;
  TEN_REG_WRITE(TEN_PP40G_REG_ADDR(pDev, module_id, misc_CLKEN), tmp_pp40g_misc_clken.wrd);

  /* TEN_MDELAY(6); Was used in simulation but probably not needed in a system */

  tmp_pp40g_misc_tx_clken.wrd = TEN_REG_READ(TEN_PP40G_REG_ADDR(pDev, module_id, misc_tx_CLKEN));
  
  /* Bugzilla #27275 - Fix Register setting for PP40G in 40gep-otu3 (40gex) */ 
  /* tmp_pp40g_misc_tx_clken.bf.clken_fpg = 0; */
  tmp_pp40g_misc_tx_clken.bf.clken_fpg = 1; 
  
  TEN_REG_WRITE(TEN_PP40G_REG_ADDR(pDev, module_id, misc_tx_CLKEN), tmp_pp40g_misc_tx_clken.wrd);

  /* TEN_MDELAY(6); Was used in simulation but probably not needed in a system */

  tmp_pp40g_misc_tx_clken.bf.clken_xec = 0;
  TEN_REG_WRITE(TEN_PP40G_REG_ADDR(pDev, module_id, misc_tx_CLKEN), tmp_pp40g_misc_tx_clken.wrd);

  /* TEN_MDELAY(6); Was used in simulation but probably not needed in a system */

  tmp_pp40g_misc_tx_clken.bf.clken_mgb = 0;
  TEN_REG_WRITE(TEN_PP40G_REG_ADDR(pDev, module_id, misc_tx_CLKEN), tmp_pp40g_misc_tx_clken.wrd);

  /* TEN_MDELAY(6); Was used in simulation but probably not needed in a system */

  tmp_pp40g_misc_tx_clken.bf.clken_bdb = 1;
  TEN_REG_WRITE(TEN_PP40G_REG_ADDR(pDev, module_id, misc_tx_CLKEN), tmp_pp40g_misc_tx_clken.wrd);

  /* TEN_MDELAY(6); Was used in simulation but probably not needed in a system */

  tmp_pp40g_misc_tx_clken.bf.clken_pra = 0;
  TEN_REG_WRITE(TEN_PP40G_REG_ADDR(pDev, module_id, misc_tx_CLKEN), tmp_pp40g_misc_tx_clken.wrd);

  /* TEN_MDELAY(6); Was used in simulation but probably not needed in a system */

  tmp_pp40g_misc_tx_clken.bf.clken_pbt = 0;
  TEN_REG_WRITE(TEN_PP40G_REG_ADDR(pDev, module_id, misc_tx_CLKEN), tmp_pp40g_misc_tx_clken.wrd);

  /* TEN_MDELAY(6); Was used in simulation but probably not needed in a system */
  TEN_MOD_UNLOCK(module_id, TEN_ID_PP40G);
  return (CS_OK);
}


/******************************************************************************/
/* $rtn_hdr_start   PP40G_TX_INSERT_MARKERS                                   */
/* CATEGORY   : API                                                           */
/* ACCESS     : Public                                                        */
/* BLOCK      : PP40G                                                         */
/* CHIP       : Tenabo                                                        */
cs_status ten_pp40g_tx_insert_markers_t41(cs_uint16 module_id)
/* INPUTS     : o Module_id                                                   */
/* OUTPUTS    : ----                                                          */
/* RETURNS    : CS_OK or CS_ERROR                                             */
/* DESCRIPTION:                                                               */
/*   Configure PP40G                                                          */
/* $rtn_hdr_end                                                               */
/******************************************************************************/
{
  TEN_PP40G_PCS_TX_CNTRL_t tmp_pp40g_pcs_tx_cntrl;
  T41_t *pDev = NULL;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, FALSE);
  TEN_MOD_LOCK(module_id, TEN_ID_PP40G);
  
  tmp_pp40g_pcs_tx_cntrl.wrd = TEN_REG_READ(TEN_PP40G_REG_ADDR(pDev, module_id, pcs_tx_CNTRL));
  tmp_pp40g_pcs_tx_cntrl.bf.mrk_insert = 1;
  TEN_REG_WRITE(TEN_PP40G_REG_ADDR(pDev, module_id, pcs_tx_CNTRL), tmp_pp40g_pcs_tx_cntrl.wrd);

  TEN_MOD_UNLOCK(module_id, TEN_ID_PP40G);
  return (CS_OK);
}



/******************************************************************************/
/* $rtn_hdr_start   PP40G_TX_DISABLE_MARKERS                                  */
/* CATEGORY   : API                                                           */
/* ACCESS     : Public                                                        */
/* BLOCK      : PP40G                                                         */
/* CHIP       : Tenabo                                                        */
cs_status ten_pp40g_tx_disable_markers_t41(cs_uint16 module_id)
/* INPUTS     : o Module_id                                                   */
/* OUTPUTS    : ----                                                          */
/* RETURNS    : CS_OK or CS_ERROR                                             */
/* DESCRIPTION:                                                               */
/*   Configure PP40G                                                          */
/* $rtn_hdr_end                                                               */
/******************************************************************************/
{
  TEN_PP40G_PCS_TX_CNTRL_t tmp_pp40g_pcs_tx_cntrl;
  T41_t *pDev = NULL;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, FALSE);
  TEN_MOD_LOCK(module_id, TEN_ID_PP40G);
  
  tmp_pp40g_pcs_tx_cntrl.wrd = TEN_REG_READ(TEN_PP40G_REG_ADDR(pDev, module_id, pcs_tx_CNTRL));
  tmp_pp40g_pcs_tx_cntrl.bf.mrk_insert = 0;
  TEN_REG_WRITE(TEN_PP40G_REG_ADDR(pDev, module_id, pcs_tx_CNTRL), tmp_pp40g_pcs_tx_cntrl.wrd);

  TEN_MOD_UNLOCK(module_id, TEN_ID_PP40G);
  return (CS_OK);
}


/******************************************************************************/
/* $rtn_hdr_start   PP40G_TX_XCON_40GEP                                       */
/* CATEGORY   : API                                                           */
/* ACCESS     : Public                                                        */
/* BLOCK      : PP40G                                                         */
/* CHIP       : Tenabo                                                        */
cs_status ten_pp40g_tx_xcon_40gep_t41(cs_uint16 module_id)
/* INPUTS     : o Module_id                                                   */
/* OUTPUTS    : ----                                                          */
/* RETURNS    : CS_OK or CS_ERROR                                             */
/* DESCRIPTION:                                                               */
/*   Configure PP40G XCON_40GEP: 40 GE parallel mode TX                       */
/* $rtn_hdr_end                                                               */
/******************************************************************************/
{
  TEN_PP40G_PCS_TX_CNTRL_t tmp_pp40g_pcs_tx_cntrl;
  TEN_PP40G_MISC_BYPASS_t tmp_pp40g_misc_bypass;
  TEN_PP40G_PCS_TX_FAULT_CNTRL_t tmp_pp40g_pcs_tx_fault_cntrl;
  TEN_PP40G_MISC_TX_FUNCEN_t tmp_pp40g_misc_tx_funcen;
  T41_t *pDev = NULL;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, FALSE);
  TEN_MOD_LOCK(module_id, TEN_ID_PP40G);
  
  tmp_pp40g_misc_bypass.wrd = TEN_REG_READ(TEN_PP40G_REG_ADDR(pDev, module_id, BYPASS));
  tmp_pp40g_misc_bypass.bf.tx_bypass = 0;
  TEN_REG_WRITE(TEN_PP40G_REG_ADDR(pDev, module_id, BYPASS), tmp_pp40g_misc_bypass.wrd);

  tmp_pp40g_pcs_tx_fault_cntrl.wrd = TEN_REG_READ(TEN_PP40G_REG_ADDR(pDev, module_id, FAULT_CNTRL));
  tmp_pp40g_pcs_tx_fault_cntrl.bf.idle_auto = 0;
  tmp_pp40g_pcs_tx_fault_cntrl.bf.rf_auto = 0;
  TEN_REG_WRITE(TEN_PP40G_REG_ADDR(pDev, module_id, FAULT_CNTRL), tmp_pp40g_pcs_tx_fault_cntrl.wrd);

  tmp_pp40g_misc_tx_funcen.wrd = TEN_REG_READ(TEN_PP40G_REG_ADDR(pDev, module_id, misc_tx_FUNCEN));
  tmp_pp40g_misc_tx_funcen.bf.fen_pra = 0;
  TEN_REG_WRITE(TEN_PP40G_REG_ADDR(pDev, module_id, misc_tx_FUNCEN), tmp_pp40g_misc_tx_funcen.wrd);

  /* TEN_MDELAY(6); Was used in simulation but probably not needed in a system */

  tmp_pp40g_misc_tx_funcen.bf.fen_pbt = 0;
  TEN_REG_WRITE(TEN_PP40G_REG_ADDR(pDev, module_id, misc_tx_FUNCEN), tmp_pp40g_misc_tx_funcen.wrd);

  /* TEN_MDELAY(6); Was used in simulation but probably not needed in a system */

  tmp_pp40g_misc_tx_funcen.bf.fen_bdb = 1;
  TEN_REG_WRITE(TEN_PP40G_REG_ADDR(pDev, module_id, misc_tx_FUNCEN), tmp_pp40g_misc_tx_funcen.wrd);

  /* TEN_MDELAY(6); Was used in simulation but probably not needed in a system */

  tmp_pp40g_misc_tx_funcen.bf.fen_mgb = 0;
  TEN_REG_WRITE(TEN_PP40G_REG_ADDR(pDev, module_id, misc_tx_FUNCEN), tmp_pp40g_misc_tx_funcen.wrd);

  /* TEN_MDELAY(6); Was used in simulation but probably not needed in a system */

  tmp_pp40g_misc_tx_funcen.bf.fen_xec = 0;
  TEN_REG_WRITE(TEN_PP40G_REG_ADDR(pDev, module_id, misc_tx_FUNCEN), tmp_pp40g_misc_tx_funcen.wrd);

  /* TEN_MDELAY(6); Was used in simulation but probably not needed in a system */

  tmp_pp40g_misc_tx_funcen.bf.fen_bil = 0;
  TEN_REG_WRITE(TEN_PP40G_REG_ADDR(pDev, module_id, misc_tx_FUNCEN), tmp_pp40g_misc_tx_funcen.wrd);

  /* TEN_MDELAY(6); Was used in simulation but probably not needed in a system */

  tmp_pp40g_misc_tx_funcen.bf.fen_fpg = 1;
  TEN_REG_WRITE(TEN_PP40G_REG_ADDR(pDev, module_id, misc_tx_FUNCEN), tmp_pp40g_misc_tx_funcen.wrd);

  /* TEN_MDELAY(6); Was used in simulation but probably not needed in a system */

  tmp_pp40g_misc_tx_funcen.bf.fen_itp = 0;
  TEN_REG_WRITE(TEN_PP40G_REG_ADDR(pDev, module_id, misc_tx_FUNCEN), tmp_pp40g_misc_tx_funcen.wrd);

  /* TEN_MDELAY(6); Was used in simulation but probably not needed in a system */

  tmp_pp40g_pcs_tx_cntrl.wrd = TEN_REG_READ(TEN_PP40G_REG_ADDR(pDev, module_id, pcs_tx_CNTRL));
  tmp_pp40g_pcs_tx_cntrl.bf.scramble = 0;
  tmp_pp40g_pcs_tx_cntrl.bf.bip_regen = 0;
  tmp_pp40g_pcs_tx_cntrl.bf.bip_err_fwd = 1;
  tmp_pp40g_pcs_tx_cntrl.bf.mrk_regen = 0;
  TEN_REG_WRITE(TEN_PP40G_REG_ADDR(pDev, module_id, pcs_tx_CNTRL), tmp_pp40g_pcs_tx_cntrl.wrd);

  /* Bugzilla #30220, pp40g semaphore fix */ 
  TEN_MOD_UNLOCK(module_id, TEN_ID_PP40G);
  ten_pp40g_tx_disable_markers_t41(module_id);
  
  TEN_MOD_LOCK(module_id, TEN_ID_PP40G);
  tmp_pp40g_pcs_tx_cntrl.wrd = TEN_REG_READ(TEN_PP40G_REG_ADDR(pDev, module_id, pcs_tx_CNTRL));
  tmp_pp40g_pcs_tx_cntrl.bf.insert_am_lock = 1;
  TEN_REG_WRITE(TEN_PP40G_REG_ADDR(pDev, module_id, pcs_tx_CNTRL), tmp_pp40g_pcs_tx_cntrl.wrd);

  TEN_MOD_UNLOCK(module_id, TEN_ID_PP40G);
  return (CS_OK);
}


/******************************************************************************/
/* $rtn_hdr_start   PP40G_TX_XCON_40GEP_RA                                    */
/* CATEGORY   : API                                                           */
/* ACCESS     : Public                                                        */
/* BLOCK      : PP40G                                                         */
/* CHIP       : Tenabo                                                        */
cs_status ten_pp40g_tx_xcon_40gep_ra_t41(cs_uint16 module_id)
/* INPUTS     : o Module_id                                                   */
/* OUTPUTS    : ----                                                          */
/* RETURNS    : CS_OK or CS_ERROR                                             */
/* DESCRIPTION:                                                               */
/*   Configure PP40G                                                          */
/* $rtn_hdr_end                                                               */
/******************************************************************************/
{
  TEN_PP40G_PCS_TX_CNTRL_t tmp_pp40g_pcs_tx_cntrl;
  TEN_PP40G_MISC_CLKEN_t tmp_pp40g_misc_clken;
  TEN_PP40G_MISC_BYPASS_t tmp_pp40g_misc_bypass;
  TEN_PP40G_PCS_TX_FAULT_CNTRL_t tmp_pp40g_pcs_tx_fault_cntrl;
  TEN_PP40G_MISC_TX_CLKEN_t tmp_pp40g_misc_tx_clken;
  TEN_PP40G_MISC_TX_FUNCEN_t tmp_pp40g_misc_tx_funcen;
  T41_t *pDev = NULL;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, FALSE);
  TEN_MOD_LOCK(module_id, TEN_ID_PP40G);
  
  tmp_pp40g_misc_clken.wrd = TEN_REG_READ(TEN_PP40G_REG_ADDR(pDev, module_id, misc_CLKEN));
  tmp_pp40g_misc_clken.bf.clken_tx = 1;
  TEN_REG_WRITE(TEN_PP40G_REG_ADDR(pDev, module_id, misc_CLKEN), tmp_pp40g_misc_clken.wrd);

  /* TEN_MDELAY(6); Was used in simulation but probably not needed in a system */

  tmp_pp40g_misc_clken.bf.clken_pm = 1;
  TEN_REG_WRITE(TEN_PP40G_REG_ADDR(pDev, module_id, misc_CLKEN), tmp_pp40g_misc_clken.wrd);

  /* TEN_MDELAY(6); Was used in simulation but probably not needed in a system */

  tmp_pp40g_misc_tx_clken.wrd = TEN_REG_READ(TEN_PP40G_REG_ADDR(pDev, module_id, misc_tx_CLKEN));
  tmp_pp40g_misc_tx_clken.bf.clken_fpg = 0;
  TEN_REG_WRITE(TEN_PP40G_REG_ADDR(pDev, module_id, misc_tx_CLKEN), tmp_pp40g_misc_tx_clken.wrd);

  /* TEN_MDELAY(6); Was used in simulation but probably not needed in a system */

  tmp_pp40g_misc_tx_clken.bf.clken_xec = 0;
  TEN_REG_WRITE(TEN_PP40G_REG_ADDR(pDev, module_id, misc_tx_CLKEN), tmp_pp40g_misc_tx_clken.wrd);

  /* TEN_MDELAY(6); Was used in simulation but probably not needed in a system */

  tmp_pp40g_misc_tx_clken.bf.clken_mgb = 0;
  TEN_REG_WRITE(TEN_PP40G_REG_ADDR(pDev, module_id, misc_tx_CLKEN), tmp_pp40g_misc_tx_clken.wrd);

  /* TEN_MDELAY(6); Was used in simulation but probably not needed in a system */

  tmp_pp40g_misc_tx_clken.bf.clken_bdb = 1;
  TEN_REG_WRITE(TEN_PP40G_REG_ADDR(pDev, module_id, misc_tx_CLKEN), tmp_pp40g_misc_tx_clken.wrd);

  /* TEN_MDELAY(6); Was used in simulation but probably not needed in a system */

  tmp_pp40g_misc_tx_clken.bf.clken_pra = 1;
  TEN_REG_WRITE(TEN_PP40G_REG_ADDR(pDev, module_id, misc_tx_CLKEN), tmp_pp40g_misc_tx_clken.wrd);

  /* TEN_MDELAY(6); Was used in simulation but probably not needed in a system */

  tmp_pp40g_misc_tx_clken.bf.clken_pbt = 0;
  TEN_REG_WRITE(TEN_PP40G_REG_ADDR(pDev, module_id, misc_tx_CLKEN), tmp_pp40g_misc_tx_clken.wrd);

  /* TEN_MDELAY(6); Was used in simulation but probably not needed in a system */

  tmp_pp40g_misc_bypass.wrd = TEN_REG_READ(TEN_PP40G_REG_ADDR(pDev, module_id, BYPASS));
  tmp_pp40g_misc_bypass.bf.tx_bypass = 0;
  TEN_REG_WRITE(TEN_PP40G_REG_ADDR(pDev, module_id, BYPASS), tmp_pp40g_misc_bypass.wrd);

  tmp_pp40g_pcs_tx_fault_cntrl.wrd = TEN_REG_READ(TEN_PP40G_REG_ADDR(pDev, module_id, FAULT_CNTRL));
  tmp_pp40g_pcs_tx_fault_cntrl.bf.idle_auto = 0;
  tmp_pp40g_pcs_tx_fault_cntrl.bf.rf_auto = 0;
  TEN_REG_WRITE(TEN_PP40G_REG_ADDR(pDev, module_id, FAULT_CNTRL), tmp_pp40g_pcs_tx_fault_cntrl.wrd);

  tmp_pp40g_misc_tx_funcen.wrd = TEN_REG_READ(TEN_PP40G_REG_ADDR(pDev, module_id, misc_tx_FUNCEN));
  tmp_pp40g_misc_tx_funcen.bf.fen_pra = 1;
  TEN_REG_WRITE(TEN_PP40G_REG_ADDR(pDev, module_id, misc_tx_FUNCEN), tmp_pp40g_misc_tx_funcen.wrd);

  /* TEN_MDELAY(6); Was used in simulation but probably not needed in a system */

  tmp_pp40g_misc_tx_funcen.bf.fen_pbt = 0;
  TEN_REG_WRITE(TEN_PP40G_REG_ADDR(pDev, module_id, misc_tx_FUNCEN), tmp_pp40g_misc_tx_funcen.wrd);

  /* TEN_MDELAY(6); Was used in simulation but probably not needed in a system */

  tmp_pp40g_misc_tx_funcen.bf.fen_bdb = 1;
  TEN_REG_WRITE(TEN_PP40G_REG_ADDR(pDev, module_id, misc_tx_FUNCEN), tmp_pp40g_misc_tx_funcen.wrd);

  /* TEN_MDELAY(6); Was used in simulation but probably not needed in a system */

  tmp_pp40g_misc_tx_funcen.bf.fen_mgb = 0;
  TEN_REG_WRITE(TEN_PP40G_REG_ADDR(pDev, module_id, misc_tx_FUNCEN), tmp_pp40g_misc_tx_funcen.wrd);

  /* TEN_MDELAY(6); Was used in simulation but probably not needed in a system */

  tmp_pp40g_misc_tx_funcen.bf.fen_xec = 0;
  TEN_REG_WRITE(TEN_PP40G_REG_ADDR(pDev, module_id, misc_tx_FUNCEN), tmp_pp40g_misc_tx_funcen.wrd);

  /* TEN_MDELAY(6); Was used in simulation but probably not needed in a system */

  tmp_pp40g_misc_tx_funcen.bf.fen_bil = 0;
  TEN_REG_WRITE(TEN_PP40G_REG_ADDR(pDev, module_id, misc_tx_FUNCEN), tmp_pp40g_misc_tx_funcen.wrd);

  /* TEN_MDELAY(6); Was used in simulation but probably not needed in a system */

  tmp_pp40g_misc_tx_funcen.bf.fen_fpg = 1;
  TEN_REG_WRITE(TEN_PP40G_REG_ADDR(pDev, module_id, misc_tx_FUNCEN), tmp_pp40g_misc_tx_funcen.wrd);

  /* TEN_MDELAY(6); Was used in simulation but probably not needed in a system */

  tmp_pp40g_misc_tx_funcen.bf.fen_itp = 0;
  TEN_REG_WRITE(TEN_PP40G_REG_ADDR(pDev, module_id, misc_tx_FUNCEN), tmp_pp40g_misc_tx_funcen.wrd);

  /* TEN_MDELAY(6); Was used in simulation but probably not needed in a system */

  tmp_pp40g_pcs_tx_cntrl.wrd = TEN_REG_READ(TEN_PP40G_REG_ADDR(pDev, module_id, pcs_tx_CNTRL));
  tmp_pp40g_pcs_tx_cntrl.bf.scramble = 1;
  tmp_pp40g_pcs_tx_cntrl.bf.bip_regen = 0;
  tmp_pp40g_pcs_tx_cntrl.bf.bip_err_fwd = 1;
  tmp_pp40g_pcs_tx_cntrl.bf.mrk_regen = 0;
  TEN_REG_WRITE(TEN_PP40G_REG_ADDR(pDev, module_id, pcs_tx_CNTRL), tmp_pp40g_pcs_tx_cntrl.wrd);
  
  /* Bugzilla #30220, pp40g semaphore fix */ 
  TEN_MOD_UNLOCK(module_id, TEN_ID_PP40G);
  ten_pp40g_tx_disable_markers_t41(module_id);

  TEN_MOD_LOCK(module_id, TEN_ID_PP40G);
  tmp_pp40g_pcs_tx_cntrl.wrd = TEN_REG_READ(TEN_PP40G_REG_ADDR(pDev, module_id, pcs_tx_CNTRL));
  tmp_pp40g_pcs_tx_cntrl.bf.insert_am_lock = 1;
  TEN_REG_WRITE(TEN_PP40G_REG_ADDR(pDev, module_id, pcs_tx_CNTRL), tmp_pp40g_pcs_tx_cntrl.wrd);

  TEN_MOD_UNLOCK(module_id, TEN_ID_PP40G);
  return (CS_OK);
}


/******************************************************************************/
/* $rtn_hdr_start   PP40G_TX_XCON_40GESBI_CLOCKS                              */
/* CATEGORY   : API                                                           */
/* ACCESS     : Public                                                        */
/* BLOCK      : PP40G                                                         */
/* CHIP       : Tenabo                                                        */
cs_status ten_pp40g_tx_xcon_40gesbi_clocks_t41(cs_uint16 module_id)
/* INPUTS     : o Module_id                                                   */
/* OUTPUTS    : ----                                                          */
/* RETURNS    : CS_OK or CS_ERROR                                             */
/* DESCRIPTION:                                                               */
/*   Configure PP40G                                                          */
/* $rtn_hdr_end                                                               */
/******************************************************************************/
{
  TEN_PP40G_MISC_CLKEN_t tmp_pp40g_misc_clken;
  TEN_PP40G_MISC_TX_CLKEN_t tmp_pp40g_misc_tx_clken;
  T41_t *pDev = NULL;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, FALSE);
  TEN_MOD_LOCK(module_id, TEN_ID_PP40G);
  
  tmp_pp40g_misc_clken.wrd = TEN_REG_READ(TEN_PP40G_REG_ADDR(pDev, module_id, misc_CLKEN));
  tmp_pp40g_misc_clken.bf.clken_tx = 1;
  TEN_REG_WRITE(TEN_PP40G_REG_ADDR(pDev, module_id, misc_CLKEN), tmp_pp40g_misc_clken.wrd);

  /* TEN_MDELAY(6); Was used in simulation but probably not needed in a system */

  tmp_pp40g_misc_clken.bf.clken_pm = 1;
  TEN_REG_WRITE(TEN_PP40G_REG_ADDR(pDev, module_id, misc_CLKEN), tmp_pp40g_misc_clken.wrd);

  /* TEN_MDELAY(6); Was used in simulation but probably not needed in a system */

  tmp_pp40g_misc_tx_clken.wrd = TEN_REG_READ(TEN_PP40G_REG_ADDR(pDev, module_id, misc_tx_CLKEN));
  tmp_pp40g_misc_tx_clken.bf.clken_fpg = 1;
  TEN_REG_WRITE(TEN_PP40G_REG_ADDR(pDev, module_id, misc_tx_CLKEN), tmp_pp40g_misc_tx_clken.wrd);

  /* TEN_MDELAY(6); Was used in simulation but probably not needed in a system */

  tmp_pp40g_misc_tx_clken.bf.clken_xec = 0;
  TEN_REG_WRITE(TEN_PP40G_REG_ADDR(pDev, module_id, misc_tx_CLKEN), tmp_pp40g_misc_tx_clken.wrd);

  /* TEN_MDELAY(6); Was used in simulation but probably not needed in a system */

  tmp_pp40g_misc_tx_clken.bf.clken_mgb = 0;
  TEN_REG_WRITE(TEN_PP40G_REG_ADDR(pDev, module_id, misc_tx_CLKEN), tmp_pp40g_misc_tx_clken.wrd);

  /* TEN_MDELAY(6); Was used in simulation but probably not needed in a system */

  tmp_pp40g_misc_tx_clken.bf.clken_bdb = 1;
  TEN_REG_WRITE(TEN_PP40G_REG_ADDR(pDev, module_id, misc_tx_CLKEN), tmp_pp40g_misc_tx_clken.wrd);

  /* TEN_MDELAY(6); Was used in simulation but probably not needed in a system */

  tmp_pp40g_misc_tx_clken.bf.clken_pra = 0;
  TEN_REG_WRITE(TEN_PP40G_REG_ADDR(pDev, module_id, misc_tx_CLKEN), tmp_pp40g_misc_tx_clken.wrd);

  /* TEN_MDELAY(6); Was used in simulation but probably not needed in a system */

  tmp_pp40g_misc_tx_clken.bf.clken_pbt = 0;
  TEN_REG_WRITE(TEN_PP40G_REG_ADDR(pDev, module_id, misc_tx_CLKEN), tmp_pp40g_misc_tx_clken.wrd);

  /* TEN_MDELAY(6); Was used in simulation but probably not needed in a system */
  TEN_MOD_UNLOCK(module_id, TEN_ID_PP40G);
  return (CS_OK);
}


/******************************************************************************/
/* $rtn_hdr_start   PP40G_TX_XCON_40GESBI                                     */
/* CATEGORY   : API                                                           */
/* ACCESS     : Public                                                        */
/* BLOCK      : PP40G                                                         */
/* CHIP       : Tenabo                                                        */
cs_status ten_pp40g_tx_xcon_40gesbi_t41(cs_uint16 module_id)
/* INPUTS     : o Module_id                                                   */
/* OUTPUTS    : ----                                                          */
/* RETURNS    : CS_OK or CS_ERROR                                             */
/* DESCRIPTION:                                                               */
/*   Configure PP40G                                                          */
/* $rtn_hdr_end                                                               */
/******************************************************************************/
{
  TEN_PP40G_PCS_TX_CNTRL_t tmp_pp40g_pcs_tx_cntrl;
  TEN_PP40G_MISC_BYPASS_t tmp_pp40g_misc_bypass;
  TEN_PP40G_PCS_TX_FAULT_CNTRL_t tmp_pp40g_pcs_tx_fault_cntrl;
  TEN_PP40G_MISC_TX_FUNCEN_t tmp_pp40g_misc_tx_funcen;
  T41_t *pDev = NULL;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, FALSE);
  TEN_MOD_LOCK(module_id, TEN_ID_PP40G);
  
  tmp_pp40g_misc_bypass.wrd = TEN_REG_READ(TEN_PP40G_REG_ADDR(pDev, module_id, BYPASS));
  tmp_pp40g_misc_bypass.bf.tx_bypass = 0;
  TEN_REG_WRITE(TEN_PP40G_REG_ADDR(pDev, module_id, BYPASS), tmp_pp40g_misc_bypass.wrd);

  tmp_pp40g_pcs_tx_fault_cntrl.wrd = TEN_REG_READ(TEN_PP40G_REG_ADDR(pDev, module_id, FAULT_CNTRL));
  tmp_pp40g_pcs_tx_fault_cntrl.bf.idle_auto = 0;
  tmp_pp40g_pcs_tx_fault_cntrl.bf.rf_auto = 0;
  TEN_REG_WRITE(TEN_PP40G_REG_ADDR(pDev, module_id, FAULT_CNTRL), tmp_pp40g_pcs_tx_fault_cntrl.wrd);

  tmp_pp40g_misc_tx_funcen.wrd = TEN_REG_READ(TEN_PP40G_REG_ADDR(pDev, module_id, misc_tx_FUNCEN));
  tmp_pp40g_misc_tx_funcen.bf.fen_pra = 0;
  TEN_REG_WRITE(TEN_PP40G_REG_ADDR(pDev, module_id, misc_tx_FUNCEN), tmp_pp40g_misc_tx_funcen.wrd);

  /* TEN_MDELAY(6); Was used in simulation but probably not needed in a system */

  tmp_pp40g_misc_tx_funcen.bf.fen_pbt = 0;
  TEN_REG_WRITE(TEN_PP40G_REG_ADDR(pDev, module_id, misc_tx_FUNCEN), tmp_pp40g_misc_tx_funcen.wrd);

  /* TEN_MDELAY(6); Was used in simulation but probably not needed in a system */

  tmp_pp40g_misc_tx_funcen.bf.fen_bdb = 1;
  TEN_REG_WRITE(TEN_PP40G_REG_ADDR(pDev, module_id, misc_tx_FUNCEN), tmp_pp40g_misc_tx_funcen.wrd);

  /* TEN_MDELAY(6); Was used in simulation but probably not needed in a system */

  tmp_pp40g_misc_tx_funcen.bf.fen_mgb = 0;
  TEN_REG_WRITE(TEN_PP40G_REG_ADDR(pDev, module_id, misc_tx_FUNCEN), tmp_pp40g_misc_tx_funcen.wrd);

  /* TEN_MDELAY(6); Was used in simulation but probably not needed in a system */

  tmp_pp40g_misc_tx_funcen.bf.fen_xec = 0;
  TEN_REG_WRITE(TEN_PP40G_REG_ADDR(pDev, module_id, misc_tx_FUNCEN), tmp_pp40g_misc_tx_funcen.wrd);

  /* TEN_MDELAY(6); Was used in simulation but probably not needed in a system */

  tmp_pp40g_misc_tx_funcen.bf.fen_bil = 1;
  TEN_REG_WRITE(TEN_PP40G_REG_ADDR(pDev, module_id, misc_tx_FUNCEN), tmp_pp40g_misc_tx_funcen.wrd);

  /* TEN_MDELAY(6); Was used in simulation but probably not needed in a system */

  tmp_pp40g_misc_tx_funcen.bf.fen_fpg = 1;
  TEN_REG_WRITE(TEN_PP40G_REG_ADDR(pDev, module_id, misc_tx_FUNCEN), tmp_pp40g_misc_tx_funcen.wrd);

  /* TEN_MDELAY(6); Was used in simulation but probably not needed in a system */

  tmp_pp40g_misc_tx_funcen.bf.fen_itp = 0;
  TEN_REG_WRITE(TEN_PP40G_REG_ADDR(pDev, module_id, misc_tx_FUNCEN), tmp_pp40g_misc_tx_funcen.wrd);

  /* TEN_MDELAY(6); Was used in simulation but probably not needed in a system */

  tmp_pp40g_pcs_tx_cntrl.wrd = TEN_REG_READ(TEN_PP40G_REG_ADDR(pDev, module_id, pcs_tx_CNTRL));
  tmp_pp40g_pcs_tx_cntrl.bf.scramble = 0;
  tmp_pp40g_pcs_tx_cntrl.bf.bip_regen = 0;
  tmp_pp40g_pcs_tx_cntrl.bf.bip_err_fwd = 1;
  tmp_pp40g_pcs_tx_cntrl.bf.mrk_regen = 0;
  TEN_REG_WRITE(TEN_PP40G_REG_ADDR(pDev, module_id, pcs_tx_CNTRL), tmp_pp40g_pcs_tx_cntrl.wrd);
  /* Bugzilla #30220, pp40g semaphore fix */ 
  TEN_MOD_UNLOCK(module_id, TEN_ID_PP40G);
  ten_pp40g_tx_disable_markers_t41(module_id);

  TEN_MOD_LOCK(module_id, TEN_ID_PP40G);
  tmp_pp40g_pcs_tx_cntrl.wrd = TEN_REG_READ(TEN_PP40G_REG_ADDR(pDev, module_id, pcs_tx_CNTRL));
  tmp_pp40g_pcs_tx_cntrl.bf.insert_am_lock = 1;
  TEN_REG_WRITE(TEN_PP40G_REG_ADDR(pDev, module_id, pcs_tx_CNTRL), tmp_pp40g_pcs_tx_cntrl.wrd);

  TEN_MOD_UNLOCK(module_id, TEN_ID_PP40G);
  return (CS_OK);
}


/******************************************************************************/
/* $rtn_hdr_start   PP40G_TX_XCON_40GESBI_RA_CLOCKS                           */
/* CATEGORY   : API                                                           */
/* ACCESS     : Public                                                        */
/* BLOCK      : PP40G                                                         */
/* CHIP       : Tenabo                                                        */
cs_status ten_pp40g_tx_xcon_40gesbi_ra_clocks_t41(cs_uint16 module_id)
/* INPUTS     : o Module_id                                                   */
/* OUTPUTS    : ----                                                          */
/* RETURNS    : CS_OK or CS_ERROR                                             */
/* DESCRIPTION:                                                               */
/*   Configure PP40G                                                          */
/* $rtn_hdr_end                                                               */
/******************************************************************************/
{
  TEN_PP40G_MISC_CLKEN_t tmp_pp40g_misc_clken;
  TEN_PP40G_MISC_TX_CLKEN_t tmp_pp40g_misc_tx_clken;
  T41_t *pDev = NULL;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, FALSE);
  TEN_MOD_LOCK(module_id, TEN_ID_PP40G);
  
  tmp_pp40g_misc_clken.wrd = TEN_REG_READ(TEN_PP40G_REG_ADDR(pDev, module_id, misc_CLKEN));
  tmp_pp40g_misc_clken.bf.clken_tx = 1;
  TEN_REG_WRITE(TEN_PP40G_REG_ADDR(pDev, module_id, misc_CLKEN), tmp_pp40g_misc_clken.wrd);

  /* TEN_MDELAY(6); Was used in simulation but probably not needed in a system */

  tmp_pp40g_misc_clken.bf.clken_pm = 1;
  TEN_REG_WRITE(TEN_PP40G_REG_ADDR(pDev, module_id, misc_CLKEN), tmp_pp40g_misc_clken.wrd);

  /* TEN_MDELAY(6); Was used in simulation but probably not needed in a system */

  tmp_pp40g_misc_tx_clken.wrd = TEN_REG_READ(TEN_PP40G_REG_ADDR(pDev, module_id, misc_tx_CLKEN));
  tmp_pp40g_misc_tx_clken.bf.clken_fpg = 1;
  TEN_REG_WRITE(TEN_PP40G_REG_ADDR(pDev, module_id, misc_tx_CLKEN), tmp_pp40g_misc_tx_clken.wrd);

  /* TEN_MDELAY(6); Was used in simulation but probably not needed in a system */

  tmp_pp40g_misc_tx_clken.bf.clken_xec = 0;
  TEN_REG_WRITE(TEN_PP40G_REG_ADDR(pDev, module_id, misc_tx_CLKEN), tmp_pp40g_misc_tx_clken.wrd);

  /* TEN_MDELAY(6); Was used in simulation but probably not needed in a system */

  tmp_pp40g_misc_tx_clken.bf.clken_mgb = 0;
  TEN_REG_WRITE(TEN_PP40G_REG_ADDR(pDev, module_id, misc_tx_CLKEN), tmp_pp40g_misc_tx_clken.wrd);

  /* TEN_MDELAY(6); Was used in simulation but probably not needed in a system */

  tmp_pp40g_misc_tx_clken.bf.clken_bdb = 1;
  TEN_REG_WRITE(TEN_PP40G_REG_ADDR(pDev, module_id, misc_tx_CLKEN), tmp_pp40g_misc_tx_clken.wrd);

  /* TEN_MDELAY(6); Was used in simulation but probably not needed in a system */

  tmp_pp40g_misc_tx_clken.bf.clken_pra = 1;
  TEN_REG_WRITE(TEN_PP40G_REG_ADDR(pDev, module_id, misc_tx_CLKEN), tmp_pp40g_misc_tx_clken.wrd);

  /* TEN_MDELAY(6); Was used in simulation but probably not needed in a system */

  tmp_pp40g_misc_tx_clken.bf.clken_pbt = 0;
  TEN_REG_WRITE(TEN_PP40G_REG_ADDR(pDev, module_id, misc_tx_CLKEN), tmp_pp40g_misc_tx_clken.wrd);

  /* TEN_MDELAY(6); Was used in simulation but probably not needed in a system */
  TEN_MOD_UNLOCK(module_id, TEN_ID_PP40G);
  return (CS_OK);
}


/******************************************************************************/
/* $rtn_hdr_start   PP40G_TX_XCON_40GESBI_RA                                  */
/* CATEGORY   : API                                                           */
/* ACCESS     : Public                                                        */
/* BLOCK      : PP40G                                                         */
/* CHIP       : Tenabo                                                        */
cs_status ten_pp40g_tx_xcon_40gesbi_ra_t41(cs_uint16 module_id)
/* INPUTS     : o Module_id                                                   */
/* OUTPUTS    : ----                                                          */
/* RETURNS    : CS_OK or CS_ERROR                                             */
/* DESCRIPTION:                                                               */
/*   Configure PP40G                                                          */
/* $rtn_hdr_end                                                               */
/******************************************************************************/
{
  TEN_PP40G_PCS_TX_CNTRL_t tmp_pp40g_pcs_tx_cntrl;
  TEN_PP40G_MISC_BYPASS_t tmp_pp40g_misc_bypass;
  TEN_PP40G_PCS_TX_FAULT_CNTRL_t tmp_pp40g_pcs_tx_fault_cntrl;
  TEN_PP40G_MISC_TX_FUNCEN_t tmp_pp40g_misc_tx_funcen;
  T41_t *pDev = NULL;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, FALSE);
  TEN_MOD_LOCK(module_id, TEN_ID_PP40G);
  
  tmp_pp40g_misc_bypass.wrd = TEN_REG_READ(TEN_PP40G_REG_ADDR(pDev, module_id, BYPASS));
  tmp_pp40g_misc_bypass.bf.tx_bypass = 0;
  TEN_REG_WRITE(TEN_PP40G_REG_ADDR(pDev, module_id, BYPASS), tmp_pp40g_misc_bypass.wrd);

  tmp_pp40g_pcs_tx_fault_cntrl.wrd = TEN_REG_READ(TEN_PP40G_REG_ADDR(pDev, module_id, FAULT_CNTRL));
  tmp_pp40g_pcs_tx_fault_cntrl.bf.idle_auto = 0;
  tmp_pp40g_pcs_tx_fault_cntrl.bf.rf_auto = 0;
  TEN_REG_WRITE(TEN_PP40G_REG_ADDR(pDev, module_id, FAULT_CNTRL), tmp_pp40g_pcs_tx_fault_cntrl.wrd);

  tmp_pp40g_misc_tx_funcen.wrd = TEN_REG_READ(TEN_PP40G_REG_ADDR(pDev, module_id, misc_tx_FUNCEN));
  tmp_pp40g_misc_tx_funcen.bf.fen_pra = 1;
  TEN_REG_WRITE(TEN_PP40G_REG_ADDR(pDev, module_id, misc_tx_FUNCEN), tmp_pp40g_misc_tx_funcen.wrd);

  /* TEN_MDELAY(6); Was used in simulation but probably not needed in a system */

  tmp_pp40g_misc_tx_funcen.bf.fen_pbt = 0;
  TEN_REG_WRITE(TEN_PP40G_REG_ADDR(pDev, module_id, misc_tx_FUNCEN), tmp_pp40g_misc_tx_funcen.wrd);

  /* TEN_MDELAY(6); Was used in simulation but probably not needed in a system */

  tmp_pp40g_misc_tx_funcen.bf.fen_bdb = 0;
  TEN_REG_WRITE(TEN_PP40G_REG_ADDR(pDev, module_id, misc_tx_FUNCEN), tmp_pp40g_misc_tx_funcen.wrd);

  /* TEN_MDELAY(6); Was used in simulation but probably not needed in a system */

  tmp_pp40g_misc_tx_funcen.bf.fen_mgb = 1;
  TEN_REG_WRITE(TEN_PP40G_REG_ADDR(pDev, module_id, misc_tx_FUNCEN), tmp_pp40g_misc_tx_funcen.wrd);

  /* TEN_MDELAY(6); Was used in simulation but probably not needed in a system */

  tmp_pp40g_misc_tx_funcen.bf.fen_xec = 0;
  TEN_REG_WRITE(TEN_PP40G_REG_ADDR(pDev, module_id, misc_tx_FUNCEN), tmp_pp40g_misc_tx_funcen.wrd);

  /* TEN_MDELAY(6); Was used in simulation but probably not needed in a system */

  tmp_pp40g_misc_tx_funcen.bf.fen_bil = 1;
  TEN_REG_WRITE(TEN_PP40G_REG_ADDR(pDev, module_id, misc_tx_FUNCEN), tmp_pp40g_misc_tx_funcen.wrd);

  /* TEN_MDELAY(6); Was used in simulation but probably not needed in a system */

  tmp_pp40g_misc_tx_funcen.bf.fen_fpg = 1;
  TEN_REG_WRITE(TEN_PP40G_REG_ADDR(pDev, module_id, misc_tx_FUNCEN), tmp_pp40g_misc_tx_funcen.wrd);

  /* TEN_MDELAY(6); Was used in simulation but probably not needed in a system */

  tmp_pp40g_misc_tx_funcen.bf.fen_itp = 0;
  TEN_REG_WRITE(TEN_PP40G_REG_ADDR(pDev, module_id, misc_tx_FUNCEN), tmp_pp40g_misc_tx_funcen.wrd);

  /* TEN_MDELAY(6); Was used in simulation but probably not needed in a system */

  tmp_pp40g_pcs_tx_cntrl.wrd = TEN_REG_READ(TEN_PP40G_REG_ADDR(pDev, module_id, pcs_tx_CNTRL));
  tmp_pp40g_pcs_tx_cntrl.bf.scramble = 1;
  tmp_pp40g_pcs_tx_cntrl.bf.bip_regen = 0;
  tmp_pp40g_pcs_tx_cntrl.bf.bip_err_fwd = 1;
  tmp_pp40g_pcs_tx_cntrl.bf.mrk_regen = 0;
  TEN_REG_WRITE(TEN_PP40G_REG_ADDR(pDev, module_id, pcs_tx_CNTRL), tmp_pp40g_pcs_tx_cntrl.wrd);
  
  /* Bugzilla #30220, pp40g semaphore fix */ 
  TEN_MOD_UNLOCK(module_id, TEN_ID_PP40G);
  ten_pp40g_tx_disable_markers_t41(module_id);
  
  TEN_MOD_LOCK(module_id, TEN_ID_PP40G);
  tmp_pp40g_pcs_tx_cntrl.wrd = TEN_REG_READ(TEN_PP40G_REG_ADDR(pDev, module_id, pcs_tx_CNTRL));
  tmp_pp40g_pcs_tx_cntrl.bf.insert_am_lock = 1;
  TEN_REG_WRITE(TEN_PP40G_REG_ADDR(pDev, module_id, pcs_tx_CNTRL), tmp_pp40g_pcs_tx_cntrl.wrd);

  TEN_MOD_UNLOCK(module_id, TEN_ID_PP40G);
  return (CS_OK);
}


/******************************************************************************/
/* $rtn_hdr_start   PP40G_TX_XCON_40GES6466_CLOCKS                            */
/* CATEGORY   : API                                                           */
/* ACCESS     : Public                                                        */
/* BLOCK      : PP40G                                                         */
/* CHIP       : Tenabo                                                        */
cs_status ten_pp40g_tx_xcon_40ges6466_clocks_t41(cs_uint16 module_id)
/* INPUTS     : o Module_id                                                   */
/* OUTPUTS    : ----                                                          */
/* RETURNS    : CS_OK or CS_ERROR                                             */
/* DESCRIPTION:                                                               */
/*   Configure PP40G                                                          */
/* $rtn_hdr_end                                                               */
/******************************************************************************/
{
  TEN_PP40G_MISC_CLKEN_t tmp_pp40g_misc_clken;
  TEN_PP40G_MISC_TX_CLKEN_t tmp_pp40g_misc_tx_clken;
  T41_t *pDev = NULL;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, FALSE);
  TEN_MOD_LOCK(module_id, TEN_ID_PP40G);
  
  tmp_pp40g_misc_clken.wrd = TEN_REG_READ(TEN_PP40G_REG_ADDR(pDev, module_id, misc_CLKEN));
  tmp_pp40g_misc_clken.bf.clken_tx = 1;
  TEN_REG_WRITE(TEN_PP40G_REG_ADDR(pDev, module_id, misc_CLKEN), tmp_pp40g_misc_clken.wrd);

  /* TEN_MDELAY(6); Was used in simulation but probably not needed in a system */

  tmp_pp40g_misc_clken.bf.clken_pm = 1;
  TEN_REG_WRITE(TEN_PP40G_REG_ADDR(pDev, module_id, misc_CLKEN), tmp_pp40g_misc_clken.wrd);

  /* TEN_MDELAY(6); Was used in simulation but probably not needed in a system */

  tmp_pp40g_misc_tx_clken.wrd = TEN_REG_READ(TEN_PP40G_REG_ADDR(pDev, module_id, misc_tx_CLKEN));
  tmp_pp40g_misc_tx_clken.bf.clken_fpg = 1;
  TEN_REG_WRITE(TEN_PP40G_REG_ADDR(pDev, module_id, misc_tx_CLKEN), tmp_pp40g_misc_tx_clken.wrd);

  /* TEN_MDELAY(6); Was used in simulation but probably not needed in a system */

  tmp_pp40g_misc_tx_clken.bf.clken_xec = 0;
  TEN_REG_WRITE(TEN_PP40G_REG_ADDR(pDev, module_id, misc_tx_CLKEN), tmp_pp40g_misc_tx_clken.wrd);

  /* TEN_MDELAY(6); Was used in simulation but probably not needed in a system */

  tmp_pp40g_misc_tx_clken.bf.clken_mgb = 1;
  TEN_REG_WRITE(TEN_PP40G_REG_ADDR(pDev, module_id, misc_tx_CLKEN), tmp_pp40g_misc_tx_clken.wrd);

  /* TEN_MDELAY(6); Was used in simulation but probably not needed in a system */

  tmp_pp40g_misc_tx_clken.bf.clken_bdb = 0;
  TEN_REG_WRITE(TEN_PP40G_REG_ADDR(pDev, module_id, misc_tx_CLKEN), tmp_pp40g_misc_tx_clken.wrd);

  /* TEN_MDELAY(6); Was used in simulation but probably not needed in a system */

  tmp_pp40g_misc_tx_clken.bf.clken_pra = 0;
  TEN_REG_WRITE(TEN_PP40G_REG_ADDR(pDev, module_id, misc_tx_CLKEN), tmp_pp40g_misc_tx_clken.wrd);

  /* TEN_MDELAY(6); Was used in simulation but probably not needed in a system */

  tmp_pp40g_misc_tx_clken.bf.clken_pbt = 0;
  TEN_REG_WRITE(TEN_PP40G_REG_ADDR(pDev, module_id, misc_tx_CLKEN), tmp_pp40g_misc_tx_clken.wrd);

  /* TEN_MDELAY(6); Was used in simulation but probably not needed in a system */
  TEN_MOD_UNLOCK(module_id, TEN_ID_PP40G);
  return (CS_OK);
}


/******************************************************************************/
/* $rtn_hdr_start   PP40G_TX_XCON_40GES6466                                   */
/* CATEGORY   : API                                                           */
/* ACCESS     : Public                                                        */
/* BLOCK      : PP40G                                                         */
/* CHIP       : Tenabo                                                        */
cs_status ten_pp40g_tx_xcon_40ges6466_t41(cs_uint16 module_id)
/* INPUTS     : o Module_id                                                   */
/* OUTPUTS    : ----                                                          */
/* RETURNS    : CS_OK or CS_ERROR                                             */
/* DESCRIPTION:                                                               */
/*   Configure PP40G                                                          */
/* $rtn_hdr_end                                                               */
/******************************************************************************/
{
  TEN_PP40G_PCS_TX_CNTRL_t tmp_pp40g_pcs_tx_cntrl;
  TEN_PP40G_MISC_BYPASS_t tmp_pp40g_misc_bypass;
  TEN_PP40G_PCS_TX_FAULT_CNTRL_t tmp_pp40g_pcs_tx_fault_cntrl;
  TEN_PP40G_MISC_TX_FUNCEN_t tmp_pp40g_misc_tx_funcen;
  T41_t *pDev = NULL;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, FALSE);
  TEN_MOD_LOCK(module_id, TEN_ID_PP40G);
  
  tmp_pp40g_misc_bypass.wrd = TEN_REG_READ(TEN_PP40G_REG_ADDR(pDev, module_id, BYPASS));
  tmp_pp40g_misc_bypass.bf.tx_bypass = 0;
  TEN_REG_WRITE(TEN_PP40G_REG_ADDR(pDev, module_id, BYPASS), tmp_pp40g_misc_bypass.wrd);

  tmp_pp40g_pcs_tx_fault_cntrl.wrd = TEN_REG_READ(TEN_PP40G_REG_ADDR(pDev, module_id, FAULT_CNTRL));
  tmp_pp40g_pcs_tx_fault_cntrl.bf.idle_auto = 0;
  tmp_pp40g_pcs_tx_fault_cntrl.bf.rf_auto = 0;
  TEN_REG_WRITE(TEN_PP40G_REG_ADDR(pDev, module_id, FAULT_CNTRL), tmp_pp40g_pcs_tx_fault_cntrl.wrd);

  tmp_pp40g_misc_tx_funcen.wrd = TEN_REG_READ(TEN_PP40G_REG_ADDR(pDev, module_id, misc_tx_FUNCEN));
  tmp_pp40g_misc_tx_funcen.bf.fen_pra = 0;
  TEN_REG_WRITE(TEN_PP40G_REG_ADDR(pDev, module_id, misc_tx_FUNCEN), tmp_pp40g_misc_tx_funcen.wrd);

  /* TEN_MDELAY(6); Was used in simulation but probably not needed in a system */

  tmp_pp40g_misc_tx_funcen.bf.fen_pbt = 0;
  TEN_REG_WRITE(TEN_PP40G_REG_ADDR(pDev, module_id, misc_tx_FUNCEN), tmp_pp40g_misc_tx_funcen.wrd);

  /* TEN_MDELAY(6); Was used in simulation but probably not needed in a system */

  tmp_pp40g_misc_tx_funcen.bf.fen_bdb = 0;
  TEN_REG_WRITE(TEN_PP40G_REG_ADDR(pDev, module_id, misc_tx_FUNCEN), tmp_pp40g_misc_tx_funcen.wrd);

  /* TEN_MDELAY(6); Was used in simulation but probably not needed in a system */

  tmp_pp40g_misc_tx_funcen.bf.fen_mgb = 1;
  TEN_REG_WRITE(TEN_PP40G_REG_ADDR(pDev, module_id, misc_tx_FUNCEN), tmp_pp40g_misc_tx_funcen.wrd);

  /* TEN_MDELAY(6); Was used in simulation but probably not needed in a system */

  tmp_pp40g_misc_tx_funcen.bf.fen_xec = 0;
  TEN_REG_WRITE(TEN_PP40G_REG_ADDR(pDev, module_id, misc_tx_FUNCEN), tmp_pp40g_misc_tx_funcen.wrd);

  /* TEN_MDELAY(6); Was used in simulation but probably not needed in a system */

  tmp_pp40g_misc_tx_funcen.bf.fen_bil = 0;
  TEN_REG_WRITE(TEN_PP40G_REG_ADDR(pDev, module_id, misc_tx_FUNCEN), tmp_pp40g_misc_tx_funcen.wrd);

  /* TEN_MDELAY(6); Was used in simulation but probably not needed in a system */

  tmp_pp40g_misc_tx_funcen.bf.fen_fpg = 1;
  TEN_REG_WRITE(TEN_PP40G_REG_ADDR(pDev, module_id, misc_tx_FUNCEN), tmp_pp40g_misc_tx_funcen.wrd);

  /* TEN_MDELAY(6); Was used in simulation but probably not needed in a system */

  tmp_pp40g_misc_tx_funcen.bf.fen_itp = 0;
  TEN_REG_WRITE(TEN_PP40G_REG_ADDR(pDev, module_id, misc_tx_FUNCEN), tmp_pp40g_misc_tx_funcen.wrd);

  /* TEN_MDELAY(6); Was used in simulation but probably not needed in a system */

  tmp_pp40g_pcs_tx_cntrl.wrd = TEN_REG_READ(TEN_PP40G_REG_ADDR(pDev, module_id, pcs_tx_CNTRL));
  tmp_pp40g_pcs_tx_cntrl.bf.scramble = 0;
  tmp_pp40g_pcs_tx_cntrl.bf.bip_regen = 0;
  tmp_pp40g_pcs_tx_cntrl.bf.bip_err_fwd = 1;
  tmp_pp40g_pcs_tx_cntrl.bf.mrk_regen = 0;
  TEN_REG_WRITE(TEN_PP40G_REG_ADDR(pDev, module_id, pcs_tx_CNTRL), tmp_pp40g_pcs_tx_cntrl.wrd);

  /* Bugzilla #30220, pp40g semaphore fix */ 
  TEN_MOD_UNLOCK(module_id, TEN_ID_PP40G);
  ten_pp40g_tx_disable_markers_t41(module_id);

  TEN_MOD_LOCK(module_id, TEN_ID_PP40G);
  tmp_pp40g_pcs_tx_cntrl.wrd = TEN_REG_READ(TEN_PP40G_REG_ADDR(pDev, module_id, pcs_tx_CNTRL));
  tmp_pp40g_pcs_tx_cntrl.bf.insert_am_lock = 1;
  TEN_REG_WRITE(TEN_PP40G_REG_ADDR(pDev, module_id, pcs_tx_CNTRL), tmp_pp40g_pcs_tx_cntrl.wrd);

  TEN_MOD_UNLOCK(module_id, TEN_ID_PP40G);
  return (CS_OK);
}


/******************************************************************************/
/* $rtn_hdr_start   PP40G_TX_XCON_40GES6466_RA                                */
/* CATEGORY   : API                                                           */
/* ACCESS     : Public                                                        */
/* BLOCK      : PP40G                                                         */
/* CHIP       : Tenabo                                                        */
cs_status ten_pp40g_tx_xcon_40ges6466_ra_t41(cs_uint16 module_id)
/* INPUTS     : o Module_id                                                   */
/* OUTPUTS    : ----                                                          */
/* RETURNS    : CS_OK or CS_ERROR                                             */
/* DESCRIPTION:                                                               */
/*   Configure PP40G                                                          */
/* $rtn_hdr_end                                                               */
/******************************************************************************/
{
  TEN_PP40G_PCS_TX_CNTRL_t tmp_pp40g_pcs_tx_cntrl;
  TEN_PP40G_MISC_CLKEN_t tmp_pp40g_misc_clken;
  TEN_PP40G_MISC_BYPASS_t tmp_pp40g_misc_bypass;
  TEN_PP40G_PCS_TX_FAULT_CNTRL_t tmp_pp40g_pcs_tx_fault_cntrl;
  TEN_PP40G_MISC_TX_CLKEN_t tmp_pp40g_misc_tx_clken;
  TEN_PP40G_MISC_TX_FUNCEN_t tmp_pp40g_misc_tx_funcen;
  T41_t *pDev = NULL;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, FALSE);
  TEN_MOD_LOCK(module_id, TEN_ID_PP40G);
  
  tmp_pp40g_misc_clken.wrd = TEN_REG_READ(TEN_PP40G_REG_ADDR(pDev, module_id, misc_CLKEN));
  tmp_pp40g_misc_clken.bf.clken_tx = 1;
  TEN_REG_WRITE(TEN_PP40G_REG_ADDR(pDev, module_id, misc_CLKEN), tmp_pp40g_misc_clken.wrd);

  /* TEN_MDELAY(6); Was used in simulation but probably not needed in a system */

  tmp_pp40g_misc_clken.bf.clken_pm = 1;
  TEN_REG_WRITE(TEN_PP40G_REG_ADDR(pDev, module_id, misc_CLKEN), tmp_pp40g_misc_clken.wrd);

  /* TEN_MDELAY(6); Was used in simulation but probably not needed in a system */

  tmp_pp40g_misc_tx_clken.wrd = TEN_REG_READ(TEN_PP40G_REG_ADDR(pDev, module_id, misc_tx_CLKEN));
  tmp_pp40g_misc_tx_clken.bf.clken_fpg = 1;
  TEN_REG_WRITE(TEN_PP40G_REG_ADDR(pDev, module_id, misc_tx_CLKEN), tmp_pp40g_misc_tx_clken.wrd);

  /* TEN_MDELAY(6); Was used in simulation but probably not needed in a system */

  tmp_pp40g_misc_tx_clken.bf.clken_xec = 0;
  TEN_REG_WRITE(TEN_PP40G_REG_ADDR(pDev, module_id, misc_tx_CLKEN), tmp_pp40g_misc_tx_clken.wrd);

  /* TEN_MDELAY(6); Was used in simulation but probably not needed in a system */

  tmp_pp40g_misc_tx_clken.bf.clken_mgb = 1;
  TEN_REG_WRITE(TEN_PP40G_REG_ADDR(pDev, module_id, misc_tx_CLKEN), tmp_pp40g_misc_tx_clken.wrd);

  /* TEN_MDELAY(6); Was used in simulation but probably not needed in a system */

  tmp_pp40g_misc_tx_clken.bf.clken_bdb = 0;
  TEN_REG_WRITE(TEN_PP40G_REG_ADDR(pDev, module_id, misc_tx_CLKEN), tmp_pp40g_misc_tx_clken.wrd);

  /* TEN_MDELAY(6); Was used in simulation but probably not needed in a system */

  tmp_pp40g_misc_tx_clken.bf.clken_pra = 1;
  TEN_REG_WRITE(TEN_PP40G_REG_ADDR(pDev, module_id, misc_tx_CLKEN), tmp_pp40g_misc_tx_clken.wrd);

  /* TEN_MDELAY(6); Was used in simulation but probably not needed in a system */

  tmp_pp40g_misc_tx_clken.bf.clken_pbt = 0;
  TEN_REG_WRITE(TEN_PP40G_REG_ADDR(pDev, module_id, misc_tx_CLKEN), tmp_pp40g_misc_tx_clken.wrd);

  /* TEN_MDELAY(6); Was used in simulation but probably not needed in a system */

  tmp_pp40g_misc_bypass.wrd = TEN_REG_READ(TEN_PP40G_REG_ADDR(pDev, module_id, BYPASS));
  tmp_pp40g_misc_bypass.bf.tx_bypass = 0;
  TEN_REG_WRITE(TEN_PP40G_REG_ADDR(pDev, module_id, BYPASS), tmp_pp40g_misc_bypass.wrd);

  tmp_pp40g_pcs_tx_fault_cntrl.wrd = TEN_REG_READ(TEN_PP40G_REG_ADDR(pDev, module_id, FAULT_CNTRL));
  tmp_pp40g_pcs_tx_fault_cntrl.bf.idle_auto = 0;
  tmp_pp40g_pcs_tx_fault_cntrl.bf.rf_auto = 0;
  TEN_REG_WRITE(TEN_PP40G_REG_ADDR(pDev, module_id, FAULT_CNTRL), tmp_pp40g_pcs_tx_fault_cntrl.wrd);

  tmp_pp40g_misc_tx_funcen.wrd = TEN_REG_READ(TEN_PP40G_REG_ADDR(pDev, module_id, misc_tx_FUNCEN));
  tmp_pp40g_misc_tx_funcen.bf.fen_pra = 1;
  TEN_REG_WRITE(TEN_PP40G_REG_ADDR(pDev, module_id, misc_tx_FUNCEN), tmp_pp40g_misc_tx_funcen.wrd);

  /* TEN_MDELAY(6); Was used in simulation but probably not needed in a system */

  tmp_pp40g_misc_tx_funcen.bf.fen_pbt = 0;
  TEN_REG_WRITE(TEN_PP40G_REG_ADDR(pDev, module_id, misc_tx_FUNCEN), tmp_pp40g_misc_tx_funcen.wrd);

  /* TEN_MDELAY(6); Was used in simulation but probably not needed in a system */

  tmp_pp40g_misc_tx_funcen.bf.fen_bdb = 0;
  TEN_REG_WRITE(TEN_PP40G_REG_ADDR(pDev, module_id, misc_tx_FUNCEN), tmp_pp40g_misc_tx_funcen.wrd);

  /* TEN_MDELAY(6); Was used in simulation but probably not needed in a system */

  tmp_pp40g_misc_tx_funcen.bf.fen_mgb = 1;
  TEN_REG_WRITE(TEN_PP40G_REG_ADDR(pDev, module_id, misc_tx_FUNCEN), tmp_pp40g_misc_tx_funcen.wrd);

  /* TEN_MDELAY(6); Was used in simulation but probably not needed in a system */

  tmp_pp40g_misc_tx_funcen.bf.fen_xec = 0;
  TEN_REG_WRITE(TEN_PP40G_REG_ADDR(pDev, module_id, misc_tx_FUNCEN), tmp_pp40g_misc_tx_funcen.wrd);

  /* TEN_MDELAY(6); Was used in simulation but probably not needed in a system */

  tmp_pp40g_misc_tx_funcen.bf.fen_bil = 0;
  TEN_REG_WRITE(TEN_PP40G_REG_ADDR(pDev, module_id, misc_tx_FUNCEN), tmp_pp40g_misc_tx_funcen.wrd);

  /* TEN_MDELAY(6); Was used in simulation but probably not needed in a system */

  tmp_pp40g_misc_tx_funcen.bf.fen_fpg = 1;
  TEN_REG_WRITE(TEN_PP40G_REG_ADDR(pDev, module_id, misc_tx_FUNCEN), tmp_pp40g_misc_tx_funcen.wrd);

  /* TEN_MDELAY(6); Was used in simulation but probably not needed in a system */

  tmp_pp40g_misc_tx_funcen.bf.fen_itp = 0;
  TEN_REG_WRITE(TEN_PP40G_REG_ADDR(pDev, module_id, misc_tx_FUNCEN), tmp_pp40g_misc_tx_funcen.wrd);

  /* TEN_MDELAY(6); Was used in simulation but probably not needed in a system */

  tmp_pp40g_pcs_tx_cntrl.wrd = TEN_REG_READ(TEN_PP40G_REG_ADDR(pDev, module_id, pcs_tx_CNTRL));
  tmp_pp40g_pcs_tx_cntrl.bf.scramble = 1;
  tmp_pp40g_pcs_tx_cntrl.bf.bip_regen = 0;
  tmp_pp40g_pcs_tx_cntrl.bf.bip_err_fwd = 1;
  tmp_pp40g_pcs_tx_cntrl.bf.mrk_regen = 0;
  TEN_REG_WRITE(TEN_PP40G_REG_ADDR(pDev, module_id, pcs_tx_CNTRL), tmp_pp40g_pcs_tx_cntrl.wrd);

  /* Bugzilla #30220, pp40g semaphore fix */ 
  TEN_MOD_UNLOCK(module_id, TEN_ID_PP40G);
  ten_pp40g_tx_disable_markers_t41(module_id);
  
  TEN_MOD_LOCK(module_id, TEN_ID_PP40G);
  tmp_pp40g_pcs_tx_cntrl.wrd = TEN_REG_READ(TEN_PP40G_REG_ADDR(pDev, module_id, pcs_tx_CNTRL));
  tmp_pp40g_pcs_tx_cntrl.bf.insert_am_lock = 1;
  TEN_REG_WRITE(TEN_PP40G_REG_ADDR(pDev, module_id, pcs_tx_CNTRL), tmp_pp40g_pcs_tx_cntrl.wrd);

  TEN_MOD_UNLOCK(module_id, TEN_ID_PP40G);
  return (CS_OK);
}


/******************************************************************************/
/* $rtn_hdr_start   PP40G_TX_XCON_40GEX_CLOCKS                                */
/* CATEGORY   : API                                                           */
/* ACCESS     : Public                                                        */
/* BLOCK      : PP40G                                                         */
/* CHIP       : Tenabo                                                        */
cs_status ten_pp40g_tx_xcon_40gex_clocks_t41(cs_uint16 module_id)
/* INPUTS     : o Module_id                                                   */
/* OUTPUTS    : ----                                                          */
/* RETURNS    : CS_OK or CS_ERROR                                             */
/* DESCRIPTION:                                                               */
/*   Configure PP40G                                                          */
/* $rtn_hdr_end                                                               */
/******************************************************************************/
{
  TEN_PP40G_MISC_CLKEN_t tmp_pp40g_misc_clken;
  TEN_PP40G_MISC_TX_CLKEN_t tmp_pp40g_misc_tx_clken;
  T41_t *pDev = NULL;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, FALSE);
  TEN_MOD_LOCK(module_id, TEN_ID_PP40G);
  
  tmp_pp40g_misc_clken.wrd = TEN_REG_READ(TEN_PP40G_REG_ADDR(pDev, module_id, misc_CLKEN));
  tmp_pp40g_misc_clken.bf.clken_tx = 1;
  TEN_REG_WRITE(TEN_PP40G_REG_ADDR(pDev, module_id, misc_CLKEN), tmp_pp40g_misc_clken.wrd);

  /* TEN_MDELAY(6); Was used in simulation but probably not needed in a system */

  tmp_pp40g_misc_clken.bf.clken_pm = 1;
  TEN_REG_WRITE(TEN_PP40G_REG_ADDR(pDev, module_id, misc_CLKEN), tmp_pp40g_misc_clken.wrd);

  /* TEN_MDELAY(6); Was used in simulation but probably not needed in a system */

  tmp_pp40g_misc_tx_clken.wrd = TEN_REG_READ(TEN_PP40G_REG_ADDR(pDev, module_id, misc_tx_CLKEN));
  tmp_pp40g_misc_tx_clken.bf.clken_fpg = 1;
  TEN_REG_WRITE(TEN_PP40G_REG_ADDR(pDev, module_id, misc_tx_CLKEN), tmp_pp40g_misc_tx_clken.wrd);

  /* TEN_MDELAY(6); Was used in simulation but probably not needed in a system */

  tmp_pp40g_misc_tx_clken.bf.clken_xec = 1;
  TEN_REG_WRITE(TEN_PP40G_REG_ADDR(pDev, module_id, misc_tx_CLKEN), tmp_pp40g_misc_tx_clken.wrd);

  /* TEN_MDELAY(6); Was used in simulation but probably not needed in a system */

  tmp_pp40g_misc_tx_clken.bf.clken_mgb = 0;
  TEN_REG_WRITE(TEN_PP40G_REG_ADDR(pDev, module_id, misc_tx_CLKEN), tmp_pp40g_misc_tx_clken.wrd);

  /* TEN_MDELAY(6); Was used in simulation but probably not needed in a system */

  tmp_pp40g_misc_tx_clken.bf.clken_bdb = 0;
  TEN_REG_WRITE(TEN_PP40G_REG_ADDR(pDev, module_id, misc_tx_CLKEN), tmp_pp40g_misc_tx_clken.wrd);

  /* TEN_MDELAY(6); Was used in simulation but probably not needed in a system */

  tmp_pp40g_misc_tx_clken.bf.clken_pra = 0;
  TEN_REG_WRITE(TEN_PP40G_REG_ADDR(pDev, module_id, misc_tx_CLKEN), tmp_pp40g_misc_tx_clken.wrd);

  /* TEN_MDELAY(6); Was used in simulation but probably not needed in a system */

  tmp_pp40g_misc_tx_clken.bf.clken_pbt = 0;
  TEN_REG_WRITE(TEN_PP40G_REG_ADDR(pDev, module_id, misc_tx_CLKEN), tmp_pp40g_misc_tx_clken.wrd);

  /* TEN_MDELAY(6); Was used in simulation but probably not needed in a system */
  TEN_MOD_UNLOCK(module_id, TEN_ID_PP40G);
  return (CS_OK);
}


/******************************************************************************/
/* $rtn_hdr_start   PP40G_TX_XCON_40GEX                                       */
/* CATEGORY   : API                                                           */
/* ACCESS     : Public                                                        */
/* BLOCK      : PP40G                                                         */
/* CHIP       : Tenabo                                                        */
cs_status ten_pp40g_tx_xcon_40gex_t41(cs_uint16 module_id)
/* INPUTS     : o Module_id                                                   */
/* OUTPUTS    : ----                                                          */
/* RETURNS    : CS_OK or CS_ERROR                                             */
/* DESCRIPTION:                                                               */
/*   Configure PP40G                                                          */
/* $rtn_hdr_end                                                               */
/******************************************************************************/
{
  TEN_PP40G_PCS_TX_CNTRL_t tmp_pp40g_pcs_tx_cntrl;
  TEN_PP40G_MISC_BYPASS_t tmp_pp40g_misc_bypass;
  TEN_PP40G_PCS_TX_FAULT_CNTRL_t tmp_pp40g_pcs_tx_fault_cntrl;
  TEN_PP40G_MISC_TX_FUNCEN_t tmp_pp40g_misc_tx_funcen;
  T41_t *pDev = NULL;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, FALSE);
  TEN_MOD_LOCK(module_id, TEN_ID_PP40G);
  
  tmp_pp40g_misc_bypass.wrd = TEN_REG_READ(TEN_PP40G_REG_ADDR(pDev, module_id, BYPASS));
  tmp_pp40g_misc_bypass.bf.tx_bypass = 0;
  TEN_REG_WRITE(TEN_PP40G_REG_ADDR(pDev, module_id, BYPASS), tmp_pp40g_misc_bypass.wrd);

  tmp_pp40g_pcs_tx_fault_cntrl.wrd = TEN_REG_READ(TEN_PP40G_REG_ADDR(pDev, module_id, FAULT_CNTRL));
  tmp_pp40g_pcs_tx_fault_cntrl.bf.idle_auto = 0;
  tmp_pp40g_pcs_tx_fault_cntrl.bf.rf_auto = 0;
  TEN_REG_WRITE(TEN_PP40G_REG_ADDR(pDev, module_id, FAULT_CNTRL), tmp_pp40g_pcs_tx_fault_cntrl.wrd);

  tmp_pp40g_misc_tx_funcen.wrd = TEN_REG_READ(TEN_PP40G_REG_ADDR(pDev, module_id, misc_tx_FUNCEN));
  tmp_pp40g_misc_tx_funcen.bf.fen_pra = 0;
  TEN_REG_WRITE(TEN_PP40G_REG_ADDR(pDev, module_id, misc_tx_FUNCEN), tmp_pp40g_misc_tx_funcen.wrd);

  /* TEN_MDELAY(6); Was used in simulation but probably not needed in a system */

  tmp_pp40g_misc_tx_funcen.bf.fen_pbt = 0;
  TEN_REG_WRITE(TEN_PP40G_REG_ADDR(pDev, module_id, misc_tx_FUNCEN), tmp_pp40g_misc_tx_funcen.wrd);

  /* TEN_MDELAY(6); Was used in simulation but probably not needed in a system */

  tmp_pp40g_misc_tx_funcen.bf.fen_bdb = 0;
  TEN_REG_WRITE(TEN_PP40G_REG_ADDR(pDev, module_id, misc_tx_FUNCEN), tmp_pp40g_misc_tx_funcen.wrd);

  /* TEN_MDELAY(6); Was used in simulation but probably not needed in a system */

  tmp_pp40g_misc_tx_funcen.bf.fen_mgb = 0;
  TEN_REG_WRITE(TEN_PP40G_REG_ADDR(pDev, module_id, misc_tx_FUNCEN), tmp_pp40g_misc_tx_funcen.wrd);

  /* TEN_MDELAY(6); Was used in simulation but probably not needed in a system */

  tmp_pp40g_misc_tx_funcen.bf.fen_xec = 1;
  TEN_REG_WRITE(TEN_PP40G_REG_ADDR(pDev, module_id, misc_tx_FUNCEN), tmp_pp40g_misc_tx_funcen.wrd);

  /* TEN_MDELAY(6); Was used in simulation but probably not needed in a system */

  tmp_pp40g_misc_tx_funcen.bf.fen_bil = 0;
  TEN_REG_WRITE(TEN_PP40G_REG_ADDR(pDev, module_id, misc_tx_FUNCEN), tmp_pp40g_misc_tx_funcen.wrd);

  /* TEN_MDELAY(6); Was used in simulation but probably not needed in a system */

  tmp_pp40g_misc_tx_funcen.bf.fen_fpg = 1;
  TEN_REG_WRITE(TEN_PP40G_REG_ADDR(pDev, module_id, misc_tx_FUNCEN), tmp_pp40g_misc_tx_funcen.wrd);

  /* TEN_MDELAY(6); Was used in simulation but probably not needed in a system */

  tmp_pp40g_misc_tx_funcen.bf.fen_itp = 0;
  TEN_REG_WRITE(TEN_PP40G_REG_ADDR(pDev, module_id, misc_tx_FUNCEN), tmp_pp40g_misc_tx_funcen.wrd);

  /* TEN_MDELAY(6); Was used in simulation but probably not needed in a system */

  tmp_pp40g_pcs_tx_cntrl.wrd = TEN_REG_READ(TEN_PP40G_REG_ADDR(pDev, module_id, pcs_tx_CNTRL));
  tmp_pp40g_pcs_tx_cntrl.bf.scramble = 0;
  tmp_pp40g_pcs_tx_cntrl.bf.bip_regen = 0;
  tmp_pp40g_pcs_tx_cntrl.bf.bip_err_fwd = 1;
  tmp_pp40g_pcs_tx_cntrl.bf.mrk_regen = 0;
  TEN_REG_WRITE(TEN_PP40G_REG_ADDR(pDev, module_id, pcs_tx_CNTRL), tmp_pp40g_pcs_tx_cntrl.wrd);

  /* Bugzilla #30220, pp40g semaphore fix */ 
  TEN_MOD_UNLOCK(module_id, TEN_ID_PP40G);
  ten_pp40g_tx_disable_markers_t41(module_id);
  
  TEN_MOD_LOCK(module_id, TEN_ID_PP40G);
  tmp_pp40g_pcs_tx_cntrl.wrd = TEN_REG_READ(TEN_PP40G_REG_ADDR(pDev, module_id, pcs_tx_CNTRL));
  tmp_pp40g_pcs_tx_cntrl.bf.insert_am_lock = 1;
  TEN_REG_WRITE(TEN_PP40G_REG_ADDR(pDev, module_id, pcs_tx_CNTRL), tmp_pp40g_pcs_tx_cntrl.wrd);

  TEN_MOD_UNLOCK(module_id, TEN_ID_PP40G);
  return (CS_OK);
}


/******************************************************************************/
/* $rtn_hdr_start   PP40G_TX_XCON_40GEX_RA                                    */
/* CATEGORY   : API                                                           */
/* ACCESS     : Public                                                        */
/* BLOCK      : PP40G                                                         */
/* CHIP       : Tenabo                                                        */
cs_status ten_pp40g_tx_xcon_40gex_ra_t41(cs_uint16 module_id)
/* INPUTS     : o Module_id                                                   */
/* OUTPUTS    : ----                                                          */
/* RETURNS    : CS_OK or CS_ERROR                                             */
/* DESCRIPTION:                                                               */
/*   Configure PP40G                                                          */
/* $rtn_hdr_end                                                               */
/******************************************************************************/
{
  TEN_PP40G_PCS_TX_CNTRL_t tmp_pp40g_pcs_tx_cntrl;
  TEN_PP40G_MISC_CLKEN_t tmp_pp40g_misc_clken;
  TEN_PP40G_MISC_BYPASS_t tmp_pp40g_misc_bypass;
  TEN_PP40G_PCS_TX_FAULT_CNTRL_t tmp_pp40g_pcs_tx_fault_cntrl;
  TEN_PP40G_MISC_TX_CLKEN_t tmp_pp40g_misc_tx_clken;
  TEN_PP40G_MISC_TX_FUNCEN_t tmp_pp40g_misc_tx_funcen;
  T41_t *pDev = NULL;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, FALSE);
  TEN_MOD_LOCK(module_id, TEN_ID_PP40G);
  
  tmp_pp40g_misc_clken.wrd = TEN_REG_READ(TEN_PP40G_REG_ADDR(pDev, module_id, misc_CLKEN));
  tmp_pp40g_misc_clken.bf.clken_tx = 1;
  TEN_REG_WRITE(TEN_PP40G_REG_ADDR(pDev, module_id, misc_CLKEN), tmp_pp40g_misc_clken.wrd);

  /* TEN_MDELAY(6); Was used in simulation but probably not needed in a system */

  tmp_pp40g_misc_clken.bf.clken_pm = 1;
  TEN_REG_WRITE(TEN_PP40G_REG_ADDR(pDev, module_id, misc_CLKEN), tmp_pp40g_misc_clken.wrd);

  /* TEN_MDELAY(6); Was used in simulation but probably not needed in a system */

  tmp_pp40g_misc_tx_clken.wrd = TEN_REG_READ(TEN_PP40G_REG_ADDR(pDev, module_id, misc_tx_CLKEN));
  tmp_pp40g_misc_tx_clken.bf.clken_fpg = 1;
  TEN_REG_WRITE(TEN_PP40G_REG_ADDR(pDev, module_id, misc_tx_CLKEN), tmp_pp40g_misc_tx_clken.wrd);

  /* TEN_MDELAY(6); Was used in simulation but probably not needed in a system */

  tmp_pp40g_misc_tx_clken.bf.clken_xec = 1;
  TEN_REG_WRITE(TEN_PP40G_REG_ADDR(pDev, module_id, misc_tx_CLKEN), tmp_pp40g_misc_tx_clken.wrd);

  /* TEN_MDELAY(6); Was used in simulation but probably not needed in a system */

  tmp_pp40g_misc_tx_clken.bf.clken_mgb = 0;
  TEN_REG_WRITE(TEN_PP40G_REG_ADDR(pDev, module_id, misc_tx_CLKEN), tmp_pp40g_misc_tx_clken.wrd);

  /* TEN_MDELAY(6); Was used in simulation but probably not needed in a system */

  tmp_pp40g_misc_tx_clken.bf.clken_bdb = 0;
  TEN_REG_WRITE(TEN_PP40G_REG_ADDR(pDev, module_id, misc_tx_CLKEN), tmp_pp40g_misc_tx_clken.wrd);

  /* TEN_MDELAY(6); Was used in simulation but probably not needed in a system */

  tmp_pp40g_misc_tx_clken.bf.clken_pra = 1;
  TEN_REG_WRITE(TEN_PP40G_REG_ADDR(pDev, module_id, misc_tx_CLKEN), tmp_pp40g_misc_tx_clken.wrd);

  /* TEN_MDELAY(6); Was used in simulation but probably not needed in a system */

  tmp_pp40g_misc_tx_clken.bf.clken_pbt = 0;
  TEN_REG_WRITE(TEN_PP40G_REG_ADDR(pDev, module_id, misc_tx_CLKEN), tmp_pp40g_misc_tx_clken.wrd);

  /* TEN_MDELAY(6); Was used in simulation but probably not needed in a system */

  tmp_pp40g_misc_bypass.wrd = TEN_REG_READ(TEN_PP40G_REG_ADDR(pDev, module_id, BYPASS));
  tmp_pp40g_misc_bypass.bf.tx_bypass = 0;
  TEN_REG_WRITE(TEN_PP40G_REG_ADDR(pDev, module_id, BYPASS), tmp_pp40g_misc_bypass.wrd);

  tmp_pp40g_pcs_tx_fault_cntrl.wrd = TEN_REG_READ(TEN_PP40G_REG_ADDR(pDev, module_id, FAULT_CNTRL));
  tmp_pp40g_pcs_tx_fault_cntrl.bf.idle_auto = 0;
  tmp_pp40g_pcs_tx_fault_cntrl.bf.rf_auto = 0;
  TEN_REG_WRITE(TEN_PP40G_REG_ADDR(pDev, module_id, FAULT_CNTRL), tmp_pp40g_pcs_tx_fault_cntrl.wrd);

  tmp_pp40g_misc_tx_funcen.wrd = TEN_REG_READ(TEN_PP40G_REG_ADDR(pDev, module_id, misc_tx_FUNCEN));
  tmp_pp40g_misc_tx_funcen.bf.fen_pra = 1;
  TEN_REG_WRITE(TEN_PP40G_REG_ADDR(pDev, module_id, misc_tx_FUNCEN), tmp_pp40g_misc_tx_funcen.wrd);

  /* TEN_MDELAY(6); Was used in simulation but probably not needed in a system */

  tmp_pp40g_misc_tx_funcen.bf.fen_pbt = 0;
  TEN_REG_WRITE(TEN_PP40G_REG_ADDR(pDev, module_id, misc_tx_FUNCEN), tmp_pp40g_misc_tx_funcen.wrd);

  /* TEN_MDELAY(6); Was used in simulation but probably not needed in a system */

  tmp_pp40g_misc_tx_funcen.bf.fen_bdb = 0;
  TEN_REG_WRITE(TEN_PP40G_REG_ADDR(pDev, module_id, misc_tx_FUNCEN), tmp_pp40g_misc_tx_funcen.wrd);

  /* TEN_MDELAY(6); Was used in simulation but probably not needed in a system */

  tmp_pp40g_misc_tx_funcen.bf.fen_mgb = 0;
  TEN_REG_WRITE(TEN_PP40G_REG_ADDR(pDev, module_id, misc_tx_FUNCEN), tmp_pp40g_misc_tx_funcen.wrd);

  /* TEN_MDELAY(6); Was used in simulation but probably not needed in a system */

  tmp_pp40g_misc_tx_funcen.bf.fen_xec = 1;
  TEN_REG_WRITE(TEN_PP40G_REG_ADDR(pDev, module_id, misc_tx_FUNCEN), tmp_pp40g_misc_tx_funcen.wrd);

  /* TEN_MDELAY(6); Was used in simulation but probably not needed in a system */

  tmp_pp40g_misc_tx_funcen.bf.fen_bil = 0;
  TEN_REG_WRITE(TEN_PP40G_REG_ADDR(pDev, module_id, misc_tx_FUNCEN), tmp_pp40g_misc_tx_funcen.wrd);

  /* TEN_MDELAY(6); Was used in simulation but probably not needed in a system */

  tmp_pp40g_misc_tx_funcen.bf.fen_fpg = 1;
  TEN_REG_WRITE(TEN_PP40G_REG_ADDR(pDev, module_id, misc_tx_FUNCEN), tmp_pp40g_misc_tx_funcen.wrd);

  /* TEN_MDELAY(6); Was used in simulation but probably not needed in a system */

  tmp_pp40g_misc_tx_funcen.bf.fen_itp = 0;
  TEN_REG_WRITE(TEN_PP40G_REG_ADDR(pDev, module_id, misc_tx_FUNCEN), tmp_pp40g_misc_tx_funcen.wrd);

  /* TEN_MDELAY(6); Was used in simulation but probably not needed in a system */

  tmp_pp40g_pcs_tx_cntrl.wrd = TEN_REG_READ(TEN_PP40G_REG_ADDR(pDev, module_id, pcs_tx_CNTRL));
  tmp_pp40g_pcs_tx_cntrl.bf.scramble = 1;
  tmp_pp40g_pcs_tx_cntrl.bf.bip_regen = 0;
  tmp_pp40g_pcs_tx_cntrl.bf.bip_err_fwd = 1;
  tmp_pp40g_pcs_tx_cntrl.bf.mrk_regen = 0;
  TEN_REG_WRITE(TEN_PP40G_REG_ADDR(pDev, module_id, pcs_tx_CNTRL), tmp_pp40g_pcs_tx_cntrl.wrd);

  /* Bugzilla #30220, pp40g semaphore fix */ 
  TEN_MOD_UNLOCK(module_id, TEN_ID_PP40G);
  ten_pp40g_tx_disable_markers_t41(module_id);

  TEN_MOD_LOCK(module_id, TEN_ID_PP40G);
  tmp_pp40g_pcs_tx_cntrl.wrd = TEN_REG_READ(TEN_PP40G_REG_ADDR(pDev, module_id, pcs_tx_CNTRL));
  tmp_pp40g_pcs_tx_cntrl.bf.insert_am_lock = 1;
  TEN_REG_WRITE(TEN_PP40G_REG_ADDR(pDev, module_id, pcs_tx_CNTRL), tmp_pp40g_pcs_tx_cntrl.wrd);

  TEN_MOD_UNLOCK(module_id, TEN_ID_PP40G);
  return (CS_OK);
}


/******************************************************************************/
/* $rtn_hdr_start   PP40G_TX_PBERT_CLOCKS                                     */
/* CATEGORY   : API                                                           */
/* ACCESS     : Public                                                        */
/* BLOCK      : PP40G                                                         */
/* CHIP       : Tenabo                                                        */
cs_status ten_pp40g_tx_pbert_clocks_t41(cs_uint16 module_id)
/* INPUTS     : o Module_id                                                   */
/* OUTPUTS    : ----                                                          */
/* RETURNS    : CS_OK or CS_ERROR                                             */
/* DESCRIPTION:                                                               */
/*   Configure PP40G                                                          */
/* $rtn_hdr_end                                                               */
/******************************************************************************/
{
  TEN_PP40G_MISC_CLKEN_t tmp_pp40g_misc_clken;
  TEN_PP40G_MISC_TX_CLKEN_t tmp_pp40g_misc_tx_clken;
  T41_t *pDev = NULL;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, FALSE);
  TEN_MOD_LOCK(module_id, TEN_ID_PP40G);
  
  tmp_pp40g_misc_clken.wrd = TEN_REG_READ(TEN_PP40G_REG_ADDR(pDev, module_id, misc_CLKEN));
  tmp_pp40g_misc_clken.bf.clken_tx = 1;
  TEN_REG_WRITE(TEN_PP40G_REG_ADDR(pDev, module_id, misc_CLKEN), tmp_pp40g_misc_clken.wrd);

  /* TEN_MDELAY(6); Was used in simulation but probably not needed in a system */

  tmp_pp40g_misc_tx_clken.wrd = TEN_REG_READ(TEN_PP40G_REG_ADDR(pDev, module_id, misc_tx_CLKEN));
  tmp_pp40g_misc_tx_clken.bf.clken_pbt = 1;
  TEN_REG_WRITE(TEN_PP40G_REG_ADDR(pDev, module_id, misc_tx_CLKEN), tmp_pp40g_misc_tx_clken.wrd);

  /* TEN_MDELAY(6); Was used in simulation but probably not needed in a system */
  TEN_MOD_UNLOCK(module_id, TEN_ID_PP40G);
  return (CS_OK);
}


/******************************************************************************/
/* $rtn_hdr_start   PP40G_TX_PBERT_IFG                                        */
/* CATEGORY   : API                                                           */
/* ACCESS     : Public                                                        */
/* BLOCK      : PP40G                                                         */
/* CHIP       : Tenabo                                                        */
cs_status ten_pp40g_tx_pbert_ifg_t41(cs_uint16 module_id,
                                     cs_uint16 ifg)
/* INPUTS     : o Module_id                                                   */
/*              o Ifg                                                         */
/* OUTPUTS    : ----                                                          */
/* RETURNS    : CS_OK or CS_ERROR                                             */
/* DESCRIPTION:                                                               */
/*   Configure PP40G                                                          */
/* $rtn_hdr_end                                                               */
/******************************************************************************/
{
  TEN_PP40G_PBERT40G_TX_TX_IFG_t tmp_pp40g_pbert40g_tx_tx_ifg;
  T41_t *pDev = NULL;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, FALSE);
  TEN_MOD_LOCK(module_id, TEN_ID_PP40G);
  
  tmp_pp40g_pbert40g_tx_tx_ifg.wrd = TEN_REG_READ(TEN_PP40G_REG_ADDR(pDev, module_id, TX_IFG));
  tmp_pp40g_pbert40g_tx_tx_ifg.bf.cnt = ifg;
  TEN_REG_WRITE(TEN_PP40G_REG_ADDR(pDev, module_id, TX_IFG), tmp_pp40g_pbert40g_tx_tx_ifg.wrd);

  TEN_MOD_UNLOCK(module_id, TEN_ID_PP40G);
  return (CS_OK);
}


/******************************************************************************/
/* $rtn_hdr_start   PP40G_TX_PBERT                                            */
/* CATEGORY   : API                                                           */
/* ACCESS     : Public                                                        */
/* BLOCK      : PP40G                                                         */
/* CHIP       : Tenabo                                                        */
cs_status ten_pp40g_tx_pbert_t41(cs_uint16 module_id)
/* INPUTS     : o Module_id                                                   */
/* OUTPUTS    : ----                                                          */
/* RETURNS    : CS_OK or CS_ERROR                                             */
/* DESCRIPTION:                                                               */
/*   Configure PP40G                                                          */
/* $rtn_hdr_end                                                               */
/******************************************************************************/
{
  TEN_PP40G_PBERT40G_TX_FRMLENMIN_t tmp_pp40g_pbert40g_tx_frmlenmin;
  TEN_PP40G_PBERT40G_TX_FRMLEN_t tmp_pp40g_pbert40g_tx_frmlen;
  TEN_PP40G_PBERT40G_TX_TYPELEN_t tmp_pp40g_pbert40g_tx_typelen;
  TEN_PP40G_PBERT40G_TX_FRMCNTRL_t tmp_pp40g_pbert40g_tx_frmcntrl;
  TEN_PP40G_PBERT40G_TX_FRMLENMAX_t tmp_pp40g_pbert40g_tx_frmlenmax;
  TEN_PP40G_PBERT40G_TX_CNTRL_t tmp_pp40g_pbert40g_tx_cntrl;
  TEN_PP40G_PBERT40G_TX_TX_IFG_t tmp_pp40g_pbert40g_tx_tx_ifg;
  TEN_PP40G_MISC_TX_FUNCEN_t tmp_pp40g_misc_tx_funcen;
  T41_t *pDev = NULL;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, FALSE);
  
  ten_pp40g_tx_pbert_clocks_t41(module_id);
  /* Bugzilla #30220, pp40g semaphore fix */ 
  TEN_MOD_LOCK(module_id, TEN_ID_PP40G);

  tmp_pp40g_misc_tx_funcen.wrd = TEN_REG_READ(TEN_PP40G_REG_ADDR(pDev, module_id, misc_tx_FUNCEN));
  tmp_pp40g_misc_tx_funcen.bf.fen_pbt = 1;
  TEN_REG_WRITE(TEN_PP40G_REG_ADDR(pDev, module_id, misc_tx_FUNCEN), tmp_pp40g_misc_tx_funcen.wrd);

  /* TEN_MDELAY(6); Was used in simulation but probably not needed in a system */

  tmp_pp40g_pbert40g_tx_typelen.wrd = 0x0106;
  TEN_REG_WRITE(TEN_PP40G_REG_ADDR(pDev, module_id, TYPELEN), tmp_pp40g_pbert40g_tx_typelen.wrd);

  tmp_pp40g_pbert40g_tx_frmlen.wrd = TEN_REG_READ(TEN_PP40G_REG_ADDR(pDev, module_id, FRMLEN));
  tmp_pp40g_pbert40g_tx_frmlen.bf.mode = 0;
  TEN_REG_WRITE(TEN_PP40G_REG_ADDR(pDev, module_id, FRMLEN), tmp_pp40g_pbert40g_tx_frmlen.wrd);

  tmp_pp40g_pbert40g_tx_frmlenmin.wrd = 64;
  TEN_REG_WRITE(TEN_PP40G_REG_ADDR(pDev, module_id, FRMLENMIN), tmp_pp40g_pbert40g_tx_frmlenmin.wrd);

  tmp_pp40g_pbert40g_tx_frmlenmax.wrd = 10000;
  TEN_REG_WRITE(TEN_PP40G_REG_ADDR(pDev, module_id, FRMLENMAX), tmp_pp40g_pbert40g_tx_frmlenmax.wrd);

  tmp_pp40g_pbert40g_tx_tx_ifg.wrd = 0;
  TEN_REG_WRITE(TEN_PP40G_REG_ADDR(pDev, module_id, TX_IFG), tmp_pp40g_pbert40g_tx_tx_ifg.wrd);

  tmp_pp40g_pbert40g_tx_frmcntrl.wrd = 0;
  TEN_REG_WRITE(TEN_PP40G_REG_ADDR(pDev, module_id, FRMCNTRL), tmp_pp40g_pbert40g_tx_frmcntrl.wrd);

  tmp_pp40g_pbert40g_tx_cntrl.wrd = TEN_REG_READ(TEN_PP40G_REG_ADDR(pDev, module_id, pbert40g_tx_CNTRL));
  tmp_pp40g_pbert40g_tx_cntrl.bf.seq_num = 1;
  TEN_REG_WRITE(TEN_PP40G_REG_ADDR(pDev, module_id, pbert40g_tx_CNTRL), tmp_pp40g_pbert40g_tx_cntrl.wrd);

  /* Bugzilla #30220, pp40g semaphore fix */ 
  TEN_MOD_UNLOCK(module_id, TEN_ID_PP40G);
  ten_pp40g_tx_insert_markers_t41(module_id);
  return (CS_OK);
}

/******************************************************************************/
/* $rtn_hdr_start   PP40G_TX_PBERT_40GEP                                      */
/* CATEGORY   : API                                                           */
/* ACCESS     : Public                                                        */
/* BLOCK      : PP40G                                                         */
/* CHIP       : Tenabo                                                        */
cs_status ten_pp40g_tx_pbert_40gep_t41(cs_uint16 module_id)
/* INPUTS     : o Module_id                                                   */
/* OUTPUTS    : ----                                                          */
/* RETURNS    : CS_OK or CS_ERROR                                             */
/* DESCRIPTION:                                                               */
/*   Configure PP40G                                                          */
/* $rtn_hdr_end                                                               */
/******************************************************************************/
{
  T41_t *pDev = NULL;
  TEN_MOD_COMMON_VALIDATE(module_id, pDev, FALSE);

  /* Bugzilla #30220, pp40g semaphore fix */ 
  ten_pp40g_tx_xcon_40gep_t41(module_id);
  ten_pp40g_tx_pbert_t41(module_id);
  return (CS_OK);
}

/******************************************************************************/
/* $rtn_hdr_start   PP40G_TX_PBERT_40GESBI                                    */
/* CATEGORY   : API                                                           */
/* ACCESS     : Public                                                        */
/* BLOCK      : PP40G                                                         */
/* CHIP       : Tenabo                                                        */
cs_status ten_pp40g_tx_pbert_40gesbi_t41(cs_uint16 module_id)
/* INPUTS     : o Module_id                                                   */
/* OUTPUTS    : ----                                                          */
/* RETURNS    : CS_OK or CS_ERROR                                             */
/* DESCRIPTION:                                                               */
/*   Configure PP40G                                                          */
/* $rtn_hdr_end                                                               */
/******************************************************************************/
{
  T41_t *pDev = NULL;
  TEN_MOD_COMMON_VALIDATE(module_id, pDev, FALSE);
  /* Bugzilla #30220, pp40g semaphore fix */ 
  ten_pp40g_tx_xcon_40gesbi_t41(module_id);
  ten_pp40g_tx_pbert_t41(module_id);
  ten_pp40g_tx_pbert_ifg_t41(module_id, 5);
  return (CS_OK);
}

/******************************************************************************/
/* $rtn_hdr_start   PP40G_TX_PBERT_40GES6466                                  */
/* CATEGORY   : API                                                           */
/* ACCESS     : Public                                                        */
/* BLOCK      : PP40G                                                         */
/* CHIP       : Tenabo                                                        */
cs_status ten_pp40g_tx_pbert_40ges6466_t41(cs_uint16 module_id)
/* INPUTS     : o Module_id                                                   */
/* OUTPUTS    : ----                                                          */
/* RETURNS    : CS_OK or CS_ERROR                                             */
/* DESCRIPTION:                                                               */
/*   Configure PP40G                                                          */
/* $rtn_hdr_end                                                               */
/******************************************************************************/
{
  T41_t *pDev = NULL;
  TEN_MOD_COMMON_VALIDATE(module_id, pDev, FALSE);
  /* Bugzilla #30220, pp40g semaphore fix */ 
  ten_pp40g_tx_xcon_40ges6466_t41(module_id);
  ten_pp40g_tx_pbert_t41(module_id);
  return (CS_OK);
}


/******************************************************************************/
/* $rtn_hdr_start   PP40G_TX_PBERT_40GEX                                      */
/* CATEGORY   : API                                                           */
/* ACCESS     : Public                                                        */
/* BLOCK      : PP40G                                                         */
/* CHIP       : Tenabo                                                        */
cs_status ten_pp40g_tx_pbert_40gex_t41(cs_uint16 module_id)
/* INPUTS     : o Module_id                                                   */
/* OUTPUTS    : ----                                                          */
/* RETURNS    : CS_OK or CS_ERROR                                             */
/* DESCRIPTION:                                                               */
/*   Configure PP40G                                                          */
/* $rtn_hdr_end                                                               */
/******************************************************************************/
{
  T41_t *pDev = NULL;
  TEN_MOD_COMMON_VALIDATE(module_id, pDev, FALSE);
  /* Bugzilla #30220, pp40g semaphore fix */ 
  ten_pp40g_tx_xcon_40gex_t41(module_id);
  ten_pp40g_tx_pbert_t41(module_id);
  return (CS_OK);
}

/******************************************************************************/
/* $rtn_hdr_start   PP40G_TX_PBERT_40GEP_RA                                   */
/* CATEGORY   : API                                                           */
/* ACCESS     : Public                                                        */
/* BLOCK      : PP40G                                                         */
/* CHIP       : Tenabo                                                        */
cs_status ten_pp40g_tx_pbert_40gep_ra_t41(cs_uint16 module_id)
/* INPUTS     : o Module_id                                                   */
/* OUTPUTS    : ----                                                          */
/* RETURNS    : CS_OK or CS_ERROR                                             */
/* DESCRIPTION:                                                               */
/*   Configure PP40G                                                          */
/* $rtn_hdr_end                                                               */
/******************************************************************************/
{
  T41_t *pDev = NULL;
  TEN_MOD_COMMON_VALIDATE(module_id, pDev, FALSE);
  /* Bugzilla #30220, pp40g semaphore fix */ 
  ten_pp40g_tx_xcon_40gep_ra_t41(module_id);
  ten_pp40g_tx_pbert_t41(module_id);
  return (CS_OK);
}

/******************************************************************************/
/* $rtn_hdr_start   PP40G_TX_PBERT_40GESBI_RA                                 */
/* CATEGORY   : API                                                           */
/* ACCESS     : Public                                                        */
/* BLOCK      : PP40G                                                         */
/* CHIP       : Tenabo                                                        */
cs_status ten_pp40g_tx_pbert_40gesbi_ra_t41(cs_uint16 module_id)
/* INPUTS     : o Module_id                                                   */
/* OUTPUTS    : ----                                                          */
/* RETURNS    : CS_OK or CS_ERROR                                             */
/* DESCRIPTION:                                                               */
/*   Configure PP40G                                                          */
/* $rtn_hdr_end                                                               */
/******************************************************************************/
{
  T41_t *pDev = NULL;
  TEN_MOD_COMMON_VALIDATE(module_id, pDev, FALSE);
  /* Bugzilla #30220, pp40g semaphore fix */ 
  ten_pp40g_tx_xcon_40gesbi_ra_t41(module_id);
  ten_pp40g_tx_pbert_t41(module_id);
  ten_pp40g_tx_pbert_ifg_t41(module_id, 5);
  return (CS_OK);
}

/******************************************************************************/
/* $rtn_hdr_start   PP40G_TX_PBERT_40GES6466_RA                               */
/* CATEGORY   : API                                                           */
/* ACCESS     : Public                                                        */
/* BLOCK      : PP40G                                                         */
/* CHIP       : Tenabo                                                        */
cs_status ten_pp40g_tx_pbert_40ges6466_ra_t41(cs_uint16 module_id)
/* INPUTS     : o Module_id                                                   */
/* OUTPUTS    : ----                                                          */
/* RETURNS    : CS_OK or CS_ERROR                                             */
/* DESCRIPTION:                                                               */
/*   Configure PP40G                                                          */
/* $rtn_hdr_end                                                               */
/******************************************************************************/
{
  T41_t *pDev = NULL;
  TEN_MOD_COMMON_VALIDATE(module_id, pDev, FALSE);
  /* Bugzilla #30220, pp40g semaphore fix */ 
  ten_pp40g_tx_xcon_40ges6466_ra_t41(module_id);
  ten_pp40g_tx_pbert_t41(module_id);
  ten_pp40g_tx_pbert_ifg_t41(module_id, 5);
  return (CS_OK);
}

/******************************************************************************/
/* $rtn_hdr_start   PP40G_TX_PBERT_40GEX_RA                                   */
/* CATEGORY   : API                                                           */
/* ACCESS     : Public                                                        */
/* BLOCK      : PP40G                                                         */
/* CHIP       : Tenabo                                                        */
cs_status ten_pp40g_tx_pbert_40gex_ra_t41(cs_uint16 module_id)
/* INPUTS     : o Module_id                                                   */
/* OUTPUTS    : ----                                                          */
/* RETURNS    : CS_OK or CS_ERROR                                             */
/* DESCRIPTION:                                                               */
/*   Configure PP40G                                                          */
/* $rtn_hdr_end                                                               */
/******************************************************************************/
{
  T41_t *pDev = NULL;
  TEN_MOD_COMMON_VALIDATE(module_id, pDev, FALSE);
  /* Bugzilla #30220, pp40g semaphore fix */ 
  ten_pp40g_tx_xcon_40gex_ra_t41(module_id);
  ten_pp40g_tx_pbert_t41(module_id);
  ten_pp40g_tx_pbert_ifg_t41(module_id, 5);
  return (CS_OK);
}

/******************************************************************************/
/* $rtn_hdr_start   PP40G_TX_DISABLE_FPG                                      */
/* CATEGORY   : API                                                           */
/* ACCESS     : Public                                                        */
/* BLOCK      : PP40G                                                         */
/* CHIP       : Tenabo                                                        */
cs_status ten_pp40g_tx_disable_fpg_t41(cs_uint16 module_id)
/* INPUTS     : o Module_id                                                   */
/* OUTPUTS    : ----                                                          */
/* RETURNS    : CS_OK or CS_ERROR                                             */
/* DESCRIPTION:                                                               */
/*   Configure PP40G                                                          */
/* $rtn_hdr_end                                                               */
/******************************************************************************/
{
  TEN_PP40G_MISC_TX_CLKEN_t tmp_pp40g_misc_tx_clken;
  T41_t *pDev = NULL;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, FALSE);
  TEN_MOD_LOCK(module_id, TEN_ID_PP40G);
  
  tmp_pp40g_misc_tx_clken.wrd = TEN_REG_READ(TEN_PP40G_REG_ADDR(pDev, module_id, misc_tx_CLKEN));
  tmp_pp40g_misc_tx_clken.bf.clken_fpg = 0;
  TEN_REG_WRITE(TEN_PP40G_REG_ADDR(pDev, module_id, misc_tx_CLKEN), tmp_pp40g_misc_tx_clken.wrd);

  /* TEN_MDELAY(6); Was used in simulation but probably not needed in a system */
  TEN_MOD_UNLOCK(module_id, TEN_ID_PP40G);
  return (CS_OK);
}


/******************************************************************************/
/* $rtn_hdr_start   PP40G_TX_PBERT_GO                                         */
/* CATEGORY   : API                                                           */
/* ACCESS     : Public                                                        */
/* BLOCK      : PP40G                                                         */
/* CHIP       : Tenabo                                                        */
cs_status ten_pp40g_tx_pbert_go_t41(cs_uint16 module_id)
/* INPUTS     : o Module_id                                                   */
/* OUTPUTS    : ----                                                          */
/* RETURNS    : CS_OK or CS_ERROR                                             */
/* DESCRIPTION:                                                               */
/*   Configure PP40G                                                          */
/* $rtn_hdr_end                                                               */
/******************************************************************************/
{
  TEN_PP40G_PBERT40G_TX_GO_t tmp_pp40g_pbert40g_tx_go;
  T41_t *pDev = NULL;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, FALSE);
  TEN_MOD_LOCK(module_id, TEN_ID_PP40G);
  
  tmp_pp40g_pbert40g_tx_go.wrd = TEN_REG_READ(TEN_PP40G_REG_ADDR(pDev, module_id, GO));
  tmp_pp40g_pbert40g_tx_go.bf.go = 1;
  TEN_REG_WRITE(TEN_PP40G_REG_ADDR(pDev, module_id, GO), tmp_pp40g_pbert40g_tx_go.wrd);

  TEN_MOD_UNLOCK(module_id, TEN_ID_PP40G);
  return (CS_OK);
}


/******************************************************************************/
/* $rtn_hdr_start   PP40G_TX_PBERT_STOP                                       */
/* CATEGORY   : API                                                           */
/* ACCESS     : Public                                                        */
/* BLOCK      : PP40G                                                         */
/* CHIP       : Tenabo                                                        */
cs_status ten_pp40g_tx_pbert_stop_t41(cs_uint16 module_id)
/* INPUTS     : o Module_id                                                   */
/* OUTPUTS    : ----                                                          */
/* RETURNS    : CS_OK or CS_ERROR                                             */
/* DESCRIPTION:                                                               */
/*   Configure PP40G                                                          */
/* $rtn_hdr_end                                                               */
/******************************************************************************/
{
  TEN_PP40G_PBERT40G_TX_GO_t tmp_pp40g_pbert40g_tx_go;
  T41_t *pDev = NULL;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, FALSE);
  TEN_MOD_LOCK(module_id, TEN_ID_PP40G);
  
  tmp_pp40g_pbert40g_tx_go.wrd = TEN_REG_READ(TEN_PP40G_REG_ADDR(pDev, module_id, GO));
  tmp_pp40g_pbert40g_tx_go.bf.go = 0;
  TEN_REG_WRITE(TEN_PP40G_REG_ADDR(pDev, module_id, GO), tmp_pp40g_pbert40g_tx_go.wrd);

  TEN_MOD_UNLOCK(module_id, TEN_ID_PP40G);
  return (CS_OK);
}


/******************************************************************************/
/* $rtn_hdr_start   PP40G_COMMON_RST_REMOVAL                                  */
/* CATEGORY   : API                                                           */
/* ACCESS     : Public                                                        */
/* BLOCK      : PP40G                                                         */
/* CHIP       : Tenabo                                                        */
cs_status ten_pp40g_common_rst_removal_t41(cs_uint16 module_id)
/* INPUTS     : o Module_id                                                   */
/* OUTPUTS    : ----                                                          */
/* RETURNS    : CS_OK or CS_ERROR                                             */
/* DESCRIPTION:                                                               */
/*   Remove PP40G MPIF and PM reset                                           */
/* $rtn_hdr_end                                                               */
/******************************************************************************/
{
  TEN_PP40G_MISC_RESET_t tmp_pp40g_misc_reset;
  TEN_PP40G_PM_CTRL_t tmp_pp40g_pm_ctrl;
  T41_t *pDev = NULL;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, FALSE);
  TEN_MOD_LOCK(module_id, TEN_ID_PP40G);
  
  tmp_pp40g_misc_reset.wrd = TEN_REG_READ(TEN_PP40G_REG_ADDR(pDev, module_id, RESET));
  tmp_pp40g_misc_reset.bf.mpif_rst = 0;
  TEN_REG_WRITE(TEN_PP40G_REG_ADDR(pDev, module_id, RESET), tmp_pp40g_misc_reset.wrd);

  /* TEN_MDELAY(6); Was used in simulation but probably not needed in a system */

  tmp_pp40g_pm_ctrl.wrd = TEN_REG_READ(TEN_PP40G_REG_ADDR(pDev, module_id, CTRL));
  tmp_pp40g_pm_ctrl.bf.rst = 0;
  TEN_REG_WRITE(TEN_PP40G_REG_ADDR(pDev, module_id, CTRL), tmp_pp40g_pm_ctrl.wrd);

  /* TEN_MDELAY(6); Was used in simulation but probably not needed in a system */
  TEN_MOD_UNLOCK(module_id, TEN_ID_PP40G);
  return (CS_OK);
}


/******************************************************************************/
/* $rtn_hdr_start   PP40G_RELEASE_PP40G_MPIF_RESET                            */
/* CATEGORY   : API                                                           */
/* ACCESS     : Public                                                        */
/* BLOCK      : PP40G                                                         */
/* CHIP       : Tenabo                                                        */
cs_status ten_pp40g_release_pp40g_mpif_reset_t41(cs_uint16 module_id)
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
  tmp_pp40g_misc_reset.bf.mpif_rst = 0;
  TEN_REG_WRITE(TEN_PP40G_REG_ADDR(pDev, module_id, RESET), tmp_pp40g_misc_reset.wrd);

  /* TEN_MDELAY(6); Was used in simulation but probably not needed in a system */
  TEN_MOD_UNLOCK(module_id, TEN_ID_PP40G);
  return (CS_OK);
}


/******************************************************************************/
/* $rtn_hdr_start   PP40G_MISC_PBERT_TX_SOFT_RESET_REMOVAL                    */
/* CATEGORY   : API                                                           */
/* ACCESS     : Public                                                        */
/* BLOCK      : PP40G                                                         */
/* CHIP       : Tenabo                                                        */
cs_status ten_pp40g_misc_pbert_tx_soft_reset_removal_t41(cs_uint16 module_id)
/* INPUTS     : o Module_id                                                   */
/* OUTPUTS    : ----                                                          */
/* RETURNS    : CS_OK or CS_ERROR                                             */
/* DESCRIPTION:                                                               */
/*   Remove PP40G PBERT TX reset                                              */
/* $rtn_hdr_end                                                               */
/******************************************************************************/
{
  TEN_PP40G_PBERT40G_TX_CNTRL_t tmp_pp40g_pbert40g_tx_cntrl;
  T41_t *pDev = NULL;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, FALSE);
  TEN_MOD_LOCK(module_id, TEN_ID_PP40G);
  
  tmp_pp40g_pbert40g_tx_cntrl.wrd = TEN_REG_READ(TEN_PP40G_REG_ADDR(pDev, module_id, pbert40g_tx_CNTRL));
  tmp_pp40g_pbert40g_tx_cntrl.bf.tx_rst = 0;
  TEN_REG_WRITE(TEN_PP40G_REG_ADDR(pDev, module_id, pbert40g_tx_CNTRL), tmp_pp40g_pbert40g_tx_cntrl.wrd);

  /* TEN_MDELAY(6); Was used in simulation but probably not needed in a system */
  TEN_MOD_UNLOCK(module_id, TEN_ID_PP40G);
  return (CS_OK);
}


/******************************************************************************/
/* $rtn_hdr_start   PP40G_MISC_TX_SOFT_RESET_REMOVAL                          */
/* CATEGORY   : API                                                           */
/* ACCESS     : Public                                                        */
/* BLOCK      : PP40G                                                         */
/* CHIP       : Tenabo                                                        */
cs_status ten_pp40g_misc_tx_soft_reset_removal_t41(cs_uint16 module_id)
/* INPUTS     : o Module_id                                                   */
/* OUTPUTS    : ----                                                          */
/* RETURNS    : CS_OK or CS_ERROR                                             */
/* DESCRIPTION:                                                               */
/*   Remove PP40G PCS TX reset                                                */
/* $rtn_hdr_end                                                               */
/******************************************************************************/
{
  TEN_PP40G_PCS_TX_CNTRL_t tmp_pp40g_pcs_tx_cntrl;
  T41_t *pDev = NULL;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, FALSE);
  TEN_MOD_LOCK(module_id, TEN_ID_PP40G);
  
  tmp_pp40g_pcs_tx_cntrl.wrd = TEN_REG_READ(TEN_PP40G_REG_ADDR(pDev, module_id, pcs_tx_CNTRL));
  tmp_pp40g_pcs_tx_cntrl.bf.tx_rst = 0;
  TEN_REG_WRITE(TEN_PP40G_REG_ADDR(pDev, module_id, pcs_tx_CNTRL), tmp_pp40g_pcs_tx_cntrl.wrd);

  /* TEN_MDELAY(6); Was used in simulation but probably not needed in a system */
  TEN_MOD_UNLOCK(module_id, TEN_ID_PP40G);
  return (CS_OK);
}


/******************************************************************************/
/* $rtn_hdr_start   PP40G_MISC_RX_SOFT_RESET_REMOVAL                          */
/* CATEGORY   : API                                                           */
/* ACCESS     : Public                                                        */
/* BLOCK      : PP40G                                                         */
/* CHIP       : Tenabo                                                        */
cs_status ten_pp40g_misc_rx_soft_reset_removal_t41(cs_uint16 module_id)
/* INPUTS     : o Module_id                                                   */
/* OUTPUTS    : ----                                                          */
/* RETURNS    : CS_OK or CS_ERROR                                             */
/* DESCRIPTION:                                                               */
/*   Remove PP40G MAC RX reset, RS RX reset, PCS RX reset and LIF RX reset    */
/* $rtn_hdr_end                                                               */
/******************************************************************************/
{
  TEN_PP40G_PCS_RX_CNTRL_t tmp_pp40g_pcs_rx_cntrl;
  TEN_PP40G_LIF_RX_CNTRL_t tmp_pp40g_lif_rx_cntrl;
  TEN_PP40G_MAC_RX_CNTRL_t tmp_pp40g_mac_rx_cntrl;
  TEN_PP40G_RS_RX_CNTRL_t tmp_pp40g_rs_rx_cntrl;
  T41_t *pDev = NULL;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, FALSE);
  TEN_MOD_LOCK(module_id, TEN_ID_PP40G);
  
  tmp_pp40g_mac_rx_cntrl.wrd = TEN_REG_READ(TEN_PP40G_REG_ADDR(pDev, module_id, mac_rx_CNTRL));
  tmp_pp40g_mac_rx_cntrl.bf.rxrst = 0;
  TEN_REG_WRITE(TEN_PP40G_REG_ADDR(pDev, module_id, mac_rx_CNTRL), tmp_pp40g_mac_rx_cntrl.wrd);

  /* TEN_MDELAY(6); Was used in simulation but probably not needed in a system */

  tmp_pp40g_rs_rx_cntrl.wrd = TEN_REG_READ(TEN_PP40G_REG_ADDR(pDev, module_id, rs_rx_CNTRL));
  tmp_pp40g_rs_rx_cntrl.bf.rxrst = 0;
  TEN_REG_WRITE(TEN_PP40G_REG_ADDR(pDev, module_id, rs_rx_CNTRL), tmp_pp40g_rs_rx_cntrl.wrd);

  /* TEN_MDELAY(6); Was used in simulation but probably not needed in a system */

  tmp_pp40g_pcs_rx_cntrl.wrd = TEN_REG_READ(TEN_PP40G_REG_ADDR(pDev, module_id, pcs_rx_CNTRL));
  tmp_pp40g_pcs_rx_cntrl.bf.rxrst = 0;
  TEN_REG_WRITE(TEN_PP40G_REG_ADDR(pDev, module_id, pcs_rx_CNTRL), tmp_pp40g_pcs_rx_cntrl.wrd);

  /* TEN_MDELAY(6); Was used in simulation but probably not needed in a system */

  tmp_pp40g_lif_rx_cntrl.wrd = TEN_REG_READ(TEN_PP40G_REG_ADDR(pDev, module_id, lif_rx_CNTRL));
  tmp_pp40g_lif_rx_cntrl.bf.rxrst = 0;
  TEN_REG_WRITE(TEN_PP40G_REG_ADDR(pDev, module_id, lif_rx_CNTRL), tmp_pp40g_lif_rx_cntrl.wrd);

  /* TEN_MDELAY(6); Was used in simulation but probably not needed in a system */
  TEN_MOD_UNLOCK(module_id, TEN_ID_PP40G);
  return (CS_OK);
}


/******************************************************************************/
/* $rtn_hdr_start   PP40G_MISC_ALL_CLOCK_TX                                   */
/* CATEGORY   : API                                                           */
/* ACCESS     : Public                                                        */
/* BLOCK      : PP40G                                                         */
/* CHIP       : Tenabo                                                        */
cs_status ten_pp40g_misc_all_clock_tx_t41(cs_uint16 module_id)
/* INPUTS     : o Module_id                                                   */
/* OUTPUTS    : ----                                                          */
/* RETURNS    : CS_OK or CS_ERROR                                             */
/* DESCRIPTION:                                                               */
/*   Assert PP40G TX clock enables                                            */
/* $rtn_hdr_end                                                               */
/******************************************************************************/
{
  TEN_PP40G_MISC_CLKEN_t tmp_pp40g_misc_clken;
  TEN_PP40G_MISC_TX_CLKEN_t tmp_pp40g_misc_tx_clken;
  T41_t *pDev = NULL;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, FALSE);
  TEN_MOD_LOCK(module_id, TEN_ID_PP40G);
  
  tmp_pp40g_misc_clken.wrd = TEN_REG_READ(TEN_PP40G_REG_ADDR(pDev, module_id, misc_CLKEN));
  tmp_pp40g_misc_clken.bf.clken_tx = 1;
  TEN_REG_WRITE(TEN_PP40G_REG_ADDR(pDev, module_id, misc_CLKEN), tmp_pp40g_misc_clken.wrd);

  /* TEN_MDELAY(6); Was used in simulation but probably not needed in a system */

  tmp_pp40g_misc_clken.bf.clken_pm = 1;
  TEN_REG_WRITE(TEN_PP40G_REG_ADDR(pDev, module_id, misc_CLKEN), tmp_pp40g_misc_clken.wrd);

  /* TEN_MDELAY(6); Was used in simulation but probably not needed in a system */

  tmp_pp40g_misc_tx_clken.wrd = 0x003f;
  TEN_REG_WRITE(TEN_PP40G_REG_ADDR(pDev, module_id, misc_tx_CLKEN), tmp_pp40g_misc_tx_clken.wrd);

  /* TEN_MDELAY(6); Was used in simulation but probably not needed in a system */
  TEN_MOD_UNLOCK(module_id, TEN_ID_PP40G);
  return (CS_OK);
}


/******************************************************************************/
/* $rtn_hdr_start   PP40G_MISC_ALL_CLOCK_RX                                   */
/* CATEGORY   : API                                                           */
/* ACCESS     : Public                                                        */
/* BLOCK      : PP40G                                                         */
/* CHIP       : Tenabo                                                        */
cs_status ten_pp40g_misc_all_clock_rx_t41(cs_uint16 module_id)
/* INPUTS     : o Module_id                                                   */
/* OUTPUTS    : ----                                                          */
/* RETURNS    : CS_OK or CS_ERROR                                             */
/* DESCRIPTION:                                                               */
/*   Assert PP40G RX clock enables                                            */
/* $rtn_hdr_end                                                               */
/******************************************************************************/
{
  TEN_PP40G_MISC_RX_CLKEN_t tmp_pp40g_misc_rx_clken;
  TEN_PP40G_MISC_CLKEN_t tmp_pp40g_misc_clken;
  T41_t *pDev = NULL;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, FALSE);
  TEN_MOD_LOCK(module_id, TEN_ID_PP40G);
  
  tmp_pp40g_misc_clken.wrd = TEN_REG_READ(TEN_PP40G_REG_ADDR(pDev, module_id, misc_CLKEN));
  tmp_pp40g_misc_clken.bf.clken_rx = 1;
  TEN_REG_WRITE(TEN_PP40G_REG_ADDR(pDev, module_id, misc_CLKEN), tmp_pp40g_misc_clken.wrd);

  /* TEN_MDELAY(6); Was used in simulation but probably not needed in a system */

  tmp_pp40g_misc_clken.bf.clken_pm = 1;
  TEN_REG_WRITE(TEN_PP40G_REG_ADDR(pDev, module_id, misc_CLKEN), tmp_pp40g_misc_clken.wrd);

  /* TEN_MDELAY(6); Was used in simulation but probably not needed in a system */

  tmp_pp40g_misc_rx_clken.wrd = 0x3eff;
  TEN_REG_WRITE(TEN_PP40G_REG_ADDR(pDev, module_id, misc_rx_CLKEN), tmp_pp40g_misc_rx_clken.wrd);

  /* TEN_MDELAY(6); Was used in simulation but probably not needed in a system */
  TEN_MOD_UNLOCK(module_id, TEN_ID_PP40G);
  return (CS_OK);
}



/******************************************************************************/
/* $rtn_hdr_start   PP40G_MISC_PP40G_DESKEW_EN                                */
/* CATEGORY   : API                                                           */
/* ACCESS     : Public                                                        */
/* BLOCK      : PP40G                                                         */
/* CHIP       : Tenabo                                                        */
cs_status ten_pp40g_misc_pp40g_deskew_en_t41(cs_uint16 module_id)
/* INPUTS     : o Module_id                                                   */
/* OUTPUTS    : ----                                                          */
/* RETURNS    : CS_OK or CS_ERROR                                             */
/* DESCRIPTION:                                                               */
/*   Enable PP40G deskew logic for monolitic 40G dewrapping                   */
/* $rtn_hdr_end                                                               */
/******************************************************************************/
{
  TEN_PP40G_MISC_CLKEN_t tmp_pp40g_misc_clken;
  TEN_PP40G_MISC_BYPASS_t tmp_pp40g_misc_bypass;
  T41_t *pDev = NULL;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, FALSE);
  TEN_MOD_LOCK(module_id, TEN_ID_PP40G);
  
  tmp_pp40g_misc_clken.wrd = TEN_REG_READ(TEN_PP40G_REG_ADDR(pDev, module_id, misc_CLKEN));
  tmp_pp40g_misc_clken.bf.clken_dsk = 1;
  TEN_REG_WRITE(TEN_PP40G_REG_ADDR(pDev, module_id, misc_CLKEN), tmp_pp40g_misc_clken.wrd);

  /* TEN_MDELAY(6); Was used in simulation but probably not needed in a system */

  tmp_pp40g_misc_bypass.wrd = TEN_REG_READ(TEN_PP40G_REG_ADDR(pDev, module_id, BYPASS));
  tmp_pp40g_misc_bypass.bf.rx_dsk_en = 1;
  TEN_REG_WRITE(TEN_PP40G_REG_ADDR(pDev, module_id, BYPASS), tmp_pp40g_misc_bypass.wrd);

  /* TEN_MDELAY(6); Was used in simulation but probably not needed in a system */
  TEN_MOD_UNLOCK(module_id, TEN_ID_PP40G);
  return (CS_OK);
}


