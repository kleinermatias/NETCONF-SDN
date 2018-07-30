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
 * ten_hl_pp40g.c
 *
 * API's for PP40G high level configuration.
 *
 * $Id: ten_hl_pp40g.c,v 1.40 2013/02/22 20:44:11 jccarlis Exp $
 *
 */
 
#include "tenabo40.h"

/****************************************************************/
/* $rtn_hdr_start  PP40G CONFIG T41                             */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : HIGH LEVEL                                      */
/* CHIP       : Tenabo                                          */
cs_status ten_hl_pp40g_config_t41(cs_uint16 module_id,
                                  cs_uint16 mode_rx,
                                  cs_uint16 mode_tx,
                                  cs_uint16 deskew_at_pp40g,
                                  cs_uint16 sysclk)
/* INPUTS     : o Module Id                                     */
/*              o Mode RX                                       */
/*              o Mode TX                                       */
/*              o Deskew at PP40G                               */
/*              o System Clock                                  */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* Configures an PP40G transmit/receive path.                   */
/*                                                              */
/* [module_id] parameter specifies line's module ID             */
/*                                                              */
/* The [mode_rx] parameter is specified as:                     */
/*   the 'mode' parameter for ten_hl_pp40g_rx_init              */
/*                                                              */
/* The [mode_tx] parameter is specified as:                     */
/*   the 'mode' parameter for ten_hl_pp40g_tx_init.             */
/*                                                              */
/* The [deskew_at_pp40g] parameter is specified as:             */
/*   deskew at PP40G  = 1                                       */
/*   deskew at SADECO = 0                                       */
/*                                                              */
/* [sysclk] parameter specifies the sysclk frequency in MHz.    */
/*   For example, 400.                                          */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  cs_status rtn = CS_OK;
  cs_char8 *func = "ten_hl_pp40g_config_t41";  
  cs_uint16 dev_id = TEN_MOD_ID_TO_DEV_ID(module_id);
  cs_uint16 mod_num = TEN_MOD_ID_TO_MOD_NUM(module_id);

  if (mode_rx >= TEN_PP40G_RX_MAX_MODE) {
     CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": Invalid rx mode.");
     return (CS_ERROR);
  }
  
  if (mode_tx >= TEN_PP40G_TX_MAX_MODE) {
     CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": Invalid tx mode.");
     rtn = CS_ERROR;
     return (CS_ERROR);
  }

  CS_PRINT("%s() %s, mode_rx=%s, mode_tx=%s, deskew_at_pp40g=%d, sysclk=%d\n", 
           func,
           ten_module_strings[module_id&1],
           ten_pp40g_rx_parm_strings[mode_rx],
           ten_pp40g_tx_parm_strings[mode_tx],
           deskew_at_pp40g,
           sysclk);

  /* When set, the processor interface of all PP40G sub-modules is in reset.  */
  /* The initialization sequence of PP40G is as follows:                      */
  
  /* 1) Assert all hard reset inputs.  */
  rtn |= ten_mpif_global_reset_pp40g_sys_t41(dev_id, mod_num, CS_RESET_ASSERT);  /* MPIF_GLOBAL_RESET_PP40G:  sys_a or sys_b = 1*/
  rtn |= ten_mpif_global_reset_pp40g_t41(dev_id, mod_num, CS_TX_AND_RX, CS_RESET_ASSERT);  /* MPIF_GLOBAL_RESET_PP40G:  tx_a and rx_a or tx_b and rx_b = 1*/
  
  /* Bugzilla #29609 - Implement 40G transponder dynamic reprovisioning  */
  /* This reset is '1' by default, but for dynamic reconfig, it could be '0' from the previous config */
  /* Set to '1' here so that code works the same for initial and dynamic, specifically step #6, where this */
  /* reset is released (otherwise it would already have been removed too soon in the procedure) */
  rtn |= ten_pp40g_misc_control_sreset_t41(module_id, CS_RESET_ASSERT);
  
  /* Bugzilla 27126 Start */
  /* 2) Deassert mpif_reset hard reset input.  */
  rtn |= ten_mpif_global_reset_common(dev_id, CS_RESET_DEASSERT, TEN_MPIF_GLOBAL_RESET_COMMON_MPIF);  /* MPIF_GLOBAL_RESET_COMMON: mpif = 0 */

  /* enable mpif global clocks */
  rtn |= ten_mpif_global_clock_disable_pp40g_sys_t41(dev_id, mod_num, CS_ENABLE);
  rtn |= ten_mpif_global_clock_disable_pp40g_rx_t41(dev_id, mod_num, CS_ENABLE);
  
  /* Bugzilla #27275, byp not needed */
  rtn |= ten_mpif_global_clock_disable_pp40g_byp_t41(dev_id, mod_num, CS_DISABLE); 

  /* 3) Enable all clocks via PP40G_MISC_CLKEN, PP40G_MISC_RX_CLKEN and  */
  rtn |= ten_pp40g_reset_all_subblocks_t41( module_id, CS_RESET_TOGGLE);

  /* 4) Short wait for reset to take effect (e.g. verify register contents of  */
  /*    registers written in step 3).  */
  TEN_MDELAY(10);
  /* Bugzilla 27126 End */

  /* Turn on PP40G Misc clocks */
  /* 5) Enable application specific required clocks via configuration registers  */
  /*    listed in step 3. Disable all other PP40G clocks.  */
  /* PP40G_MISC_TX_CLKEN registers.  */
  switch (mode_tx) {
  case (TEN_PP40G_TX_PBERT_40GEP):
  case (TEN_PP40G_TX_XCON_40GEP_RA):
  case (TEN_PP40G_TX_XCON_40GEP):
    rtn |= ten_pp40g_tx_xcon_40gep_clocks_t41(module_id);
    break;

  case (TEN_PP40G_TX_PBERT_40GESBI):
  case (TEN_PP40G_TX_XCON_40GESBI_RA):
  case (TEN_PP40G_TX_XCON_40GESBI):
    rtn |= ten_pp40g_tx_xcon_40gesbi_clocks_t41(module_id);
    break;
    
  case (TEN_PP40G_TX_PBERT_40GES6466):
  case (TEN_PP40G_TX_XCON_40GES6466_RA):
  case (TEN_PP40G_TX_XCON_40GES6466):
    rtn |= ten_pp40g_tx_xcon_40ges6466_clocks_t41(module_id);
    break;
  
  case (TEN_PP40G_TX_PBERT_40GEX):
  case (TEN_PP40G_TX_XCON_40GEX_RA):
  case (TEN_PP40G_TX_XCON_40GEX):
    rtn |= ten_pp40g_tx_xcon_40gex_clocks_t41(module_id);
    break;
  
  default:
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": Invalid tx mode.");
    rtn = CS_ERROR;
    break;
  }
  
  switch (mode_rx) {
  case (TEN_PP40G_RX_40GEP_XCON_RA):
  case (TEN_PP40G_RX_40GEP_XCON):
    rtn |= ten_pp40g_rx_40gep_xcon_clocks_t41(module_id);
    break;
    
  case (TEN_PP40G_RX_40GESBI_XCON_RA):
  case (TEN_PP40G_RX_40GESBI_XCON):
    rtn |= ten_pp40g_rx_40gesbi_xcon_clocks_t41(module_id);
    break;
    
  case (TEN_PP40G_RX_40GES6466_XCON_RA):
  case (TEN_PP40G_RX_40GES6466_XCON):
    rtn |= ten_pp40g_rx_40ges6466_xcon_clocks_t41(module_id);
    break;
    
  case (TEN_PP40G_RX_40GEX_XCON_RA):
  case (TEN_PP40G_RX_40GEX_XCON):
    rtn |= ten_pp40g_rx_40gex_xcon_clocks_t41(module_id);
    break;
    
  default:
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": Invalid rx mode.");
    rtn = CS_ERROR;
    break;
  }
  
  /* 6) Release this soft reset (mpif_rst).  */
  rtn |= ten_pp40g_misc_control_sreset_t41(module_id, CS_RESET_DEASSERT);
  
  /* Bugzilla 27126 Start */
  /* 7) Deassert all remaining hard reset inputs.  */
  /* enable mpif global clocks */
  rtn |= ten_mpif_global_reset_pp40g_sys_t41(dev_id, mod_num, CS_RESET_DEASSERT);
  rtn |= ten_mpif_global_reset_pp40g_t41(dev_id, mod_num, CS_TX_AND_RX, CS_RESET_DEASSERT);
  /* Bugzilla 27126 End */
  
  rtn |= ten_pp40g_pm_control_sreset_t41(module_id, CS_RESET_ASSERT);
                                          
  /* 8) Configure PP40G for the required application.  */
  rtn |= ten_hl_pp40g_rx_init_t41(module_id, mode_rx);
  rtn |= ten_hl_pp40g_tx_init_t41(module_id, mode_tx);

  if ( (ten_pp40g_is_bypassed_t41(module_id)) &&
       (deskew_at_pp40g == TEN_PP40G_BYPASS_DESKEW) &&     /* Bugzilla 28977 */
       (mode_rx != TEN_PP40G_RX_40GEP_XCON_RA) &&
       (mode_rx != TEN_PP40G_RX_40GEP_XCON) ) {
    /*  Use PP40G Bypass Deskew */
    rtn |= ten_pp40g_rx_bypass_dsk_en_t41(module_id, CS_ENABLE);
  }
  else  {
    rtn |= ten_pp40g_rx_bypass_dsk_en_t41(module_id, CS_DISABLE);
  }
   
  /* Bugzilla #29248, update fix BER timer calculation */
  if ((mode_rx == TEN_PP40G_RX_40GEX_XCON_RA) || (mode_rx == TEN_PP40G_RX_40GEX_XCON)) {
    /* Set period to 250us */
    rtn |= ten_pp40g_pcs_rx_bertimer_calculate_period(module_id, sysclk, 250, 0);
  } 
  else {
    /* Set period to 1250us */
    rtn |= ten_pp40g_pcs_rx_bertimer_calculate_period(module_id, sysclk, 1250, 0);
  }
  
  /* 9) Release applicable soft resets in the recommended order (against traffic flow). */
  /* This is done in full.pl */
  
  return (rtn);
}

/****************************************************************/
/* $rtn_hdr_start  PP40G RX INITIALIZATION T41                  */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : HIGH LEVEL                                      */
/* CHIP       : Tenabo                                          */
cs_status ten_hl_pp40g_rx_init_t41(cs_uint16 module_id,
                                   cs_uint8 mode)
/* INPUTS     : o Module Id                                     */
/*              o Mode                                          */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* Configure PP40G RX.                                          */
/*                                                              */
/* The [mode] parameter is specified as:                        */
/*   TEN_PP40G_RX_DISABLE            = 0,  Disable              */
/*   TEN_PP40G_RX_BYPASS             = 1,  Bypass               */
/*   TEN_PP40G_RX_40GEP_XCON         = 2,  40GE parallel RX     */
/*   TEN_PP40G_RX_40GESBI_XCON       = 3,  40GE Serial RX       */
/*   TEN_PP40G_RX_40GES6466_XCON     = 4,  Monolithic RX        */
/*   TEN_PP40G_RX_40GEX_XCON         = 5,  Transcoding for RX   */
/*   TEN_PP40G_RX_40GEP_XCON_RA      = 6,  40GE parallel RX RA  */
/*   TEN_PP40G_RX_40GESBI_XCON_RA    = 7,  40GE Serial RX RA    */
/*   TEN_PP40G_RX_40GES6466_XCON_RA  = 8,  Monolithic RX RA     */
/*   TEN_PP40G_RX_40GEX_XCON_RA      = 9,  Transcoding RX RA.   */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  cs_status rtn = CS_OK;
  cs_uint16 dev_id;
  cs_uint16 mod_num;

  CS_PRINT("ten_hl_pp40g_rx_init_t41, mod_id=0x%04X, mode=%s (%d)\n", 
            module_id, ten_pp40g_rx_debug_str[mode], mode);
 
  if (mode >= TEN_PP40G_RX_MAX_MODE) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": Invalid mode.");
    return (CS_ERROR);
  }
  
  dev_id = TEN_MOD_ID_TO_DEV_ID(module_id);
  mod_num = TEN_MOD_ID_TO_MOD_NUM(module_id);
  
  if (mode == TEN_PP40G_RX_DISABLE) {
    /* Disable clock */
    rtn |= ten_mpif_global_clock_disable_pp40g_sys_t41(dev_id, mod_num, CS_DISABLE);
    rtn |= ten_mpif_global_clock_disable_pp40g_rx_t41(dev_id, mod_num, CS_DISABLE);
    rtn |= ten_mpif_global_clock_disable_pp40g_byp_t41(dev_id, mod_num, CS_DISABLE);
    
    /* Assert hard reset */
    rtn |= ten_mpif_global_reset_pp40g_sys_t41(dev_id, mod_num, CS_RESET_ASSERT);
    rtn |= ten_mpif_global_reset_pp40g_t41(dev_id, mod_num, CS_RX, CS_RESET_ASSERT);
  }
  else if (mode == TEN_PP40G_RX_BYPASS) {
    rtn |= ten_pp40g_rx_pp40g_rx_bypass_t41(module_id);
  }
  else {
    /* Assert block-level resets */
    rtn |= ten_pp40g_lif_rx_control_sreset_t41(module_id, CS_RESET_ASSERT);
    rtn |= ten_pp40g_pcs_rx_control_sreset_t41(module_id, CS_RESET_ASSERT);
    rtn |= ten_pp40g_rs_rx_control_sreset_t41(module_id, CS_RESET_ASSERT);
    rtn |= ten_pp40g_mac_rx_control_sreset_t41(module_id, CS_RESET_ASSERT);
  
    switch (mode) {
    case (TEN_PP40G_RX_40GEP_XCON):
      rtn |= ten_pp40g_rx_40gep_xcon_t41(module_id);
      break;
      
    case (TEN_PP40G_RX_40GESBI_XCON):
      rtn |= ten_pp40g_rx_40gesbi_xcon_t41(module_id);
      break;
      
    case (TEN_PP40G_RX_40GES6466_XCON):
      rtn |= ten_pp40g_rx_40ges6466_xcon_t41(module_id);
      break;
      
    case (TEN_PP40G_RX_40GEX_XCON):
      rtn |= ten_pp40g_rx_40gex_xcon_t41(module_id);
      break;
      
    case (TEN_PP40G_RX_40GEP_XCON_RA):
      rtn |= ten_pp40g_rx_40gep_xcon_ra_t41(module_id);
      break;
      
    case (TEN_PP40G_RX_40GESBI_XCON_RA):
      rtn |= ten_pp40g_rx_40gesbi_xcon_ra_t41(module_id);
      break;
      
    case (TEN_PP40G_RX_40GES6466_XCON_RA):
      rtn |= ten_pp40g_rx_40ges6466_xcon_ra_t41(module_id);
      break;
      
    case (TEN_PP40G_RX_40GEX_XCON_RA):
      rtn |= ten_pp40g_rx_40gex_xcon_ra_t41(module_id);
      break;
      
    default:
      CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": Invalid mode.");
      rtn = CS_ERROR;
      break;
    }
  }
  
  CS_PRINT("ten_hl_pp40g_rx_init_t41 complete:  ");
  if (rtn == CS_OK) {
    CS_PRINT("CS_OK\n");
  }
  else {
    CS_PRINT("CS_ERROR\n");
  }
  return(rtn);
}

/****************************************************************/
/* $rtn_hdr_start  PP40G TX INITIALIZATION  T41                 */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : HIGH LEVEL                                      */
/* CHIP       : Tenabo                                          */
cs_status ten_hl_pp40g_tx_init_t41(cs_uint16 module_id,
                                  cs_uint8 mode)
/* INPUTS     : o Module Id                                     */
/*              o Mode                                          */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* Configure PP40G TX.                                          */
/*                                                              */
/* The [mode] parameter is specified as:                        */
/*   TEN_PP40G_TX_XCON_40GEP        = 0, 40GE parallel TX       */
/*   TEN_PP40G_TX_XCON_40GESBI      = 1, 40GE Serial TX         */
/*   TEN_PP40G_TX_XCON_40GES6466    = 2, Monolithic TX          */
/*   TEN_PP40G_TX_XCON_40GEX        = 3, Transcoding TX         */
/*   TEN_PP40G_TX_XCON_40GEP_RA     = 4, 40GE parallel TX RA    */
/*   TEN_PP40G_TX_XCON_40GESBI_RA   = 5, 40GE Serial TX RA      */
/*   TEN_PP40G_TX_XCON_40GES6466_RA = 6, Monolithic TX RA       */
/*   TEN_PP40G_TX_XCON_40GEX_RA     = 7, Transcoding TX RA      */
/*   TEN_PP40G_TX_PBERT_40GEP       = 8, 40GE parallel TX       */
/*   TEN_PP40G_TX_PBERT_40GESBI     = 9, 40GE Serial TX         */
/*   TEN_PP40G_TX_PBERT_40GES6466   = 10, Monolithic TX         */
/*   TEN_PP40G_TX_PBERT_40GEX       = 11, Transcoding TX.       */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  cs_status rtn = CS_OK;
  cs_uint16 dev_id;
  cs_uint16 mod_num;

  CS_PRINT("ten_hl_pp40g_tx_init_t41, mod_id=0x%04X, mode=%s (%d)\n", 
            module_id, ten_pp40g_tx_debug_str[mode], mode);
 
  if (mode >= TEN_PP40G_TX_MAX_MODE) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": Invalid mode.");
    return (CS_ERROR);
  }
  
  dev_id = TEN_MOD_ID_TO_DEV_ID(module_id);
  mod_num = TEN_MOD_ID_TO_MOD_NUM(module_id);
  
  if (mode == TEN_PP40G_TX_DISABLE) {
    /* Disable clock */
    rtn |= ten_mpif_global_clock_disable_pp40g_sys_t41(dev_id, mod_num, CS_DISABLE);
    rtn |= ten_mpif_global_clock_disable_pp40g_byp_t41(dev_id, mod_num, CS_DISABLE);
    
    /* Assert hard reset */
    rtn |= ten_mpif_global_reset_pp40g_sys_t41(dev_id, mod_num, CS_RESET_ASSERT);
    rtn |= ten_mpif_global_reset_pp40g_t41(dev_id, mod_num, CS_TX, CS_RESET_ASSERT);
  }
  else if (mode == TEN_PP40G_TX_BYPASS) {
    rtn |= ten_pp40g_tx_pp40g_tx_bypass_t41(module_id);
  }
  else {
    /* Assert block-level resets */
    rtn |= ten_pp40g_pcs_tx_control_sreset_t41(module_id, CS_RESET_ASSERT);

    switch (mode) {
      
    case (TEN_PP40G_TX_XCON_40GEP):
      rtn |= ten_pp40g_tx_xcon_40gep_t41(module_id);
      break;
    
    case (TEN_PP40G_TX_XCON_40GESBI):
      rtn |= ten_pp40g_tx_xcon_40gesbi_t41(module_id);
      break;
      
    case (TEN_PP40G_TX_XCON_40GES6466):
      rtn |= ten_pp40g_tx_xcon_40ges6466_t41(module_id);
      break;
    
    case (TEN_PP40G_TX_XCON_40GEX):
      rtn |= ten_pp40g_tx_xcon_40gex_t41(module_id);
      break;
    
    case (TEN_PP40G_TX_XCON_40GEP_RA):
      rtn |= ten_pp40g_tx_xcon_40gep_ra_t41(module_id);
      break;
      
    case (TEN_PP40G_TX_XCON_40GESBI_RA):
      rtn |= ten_pp40g_tx_xcon_40gesbi_ra_t41(module_id);
      break;
      
    case (TEN_PP40G_TX_XCON_40GES6466_RA):
      rtn |= ten_pp40g_tx_xcon_40ges6466_ra_t41(module_id);
      break;
      
    case (TEN_PP40G_TX_XCON_40GEX_RA):
      rtn |= ten_pp40g_tx_xcon_40gex_ra_t41(module_id);
      break;
      
    case (TEN_PP40G_TX_PBERT_40GEP):
      rtn |= ten_pp40g_tx_pbert_40gep_t41(module_id);
      break;
    
    case (TEN_PP40G_TX_PBERT_40GESBI):
      rtn |= ten_pp40g_tx_pbert_40gesbi_t41(module_id);
      break;
    
    case (TEN_PP40G_TX_PBERT_40GES6466):
      rtn |= ten_pp40g_tx_pbert_40ges6466_t41(module_id);
      break;
    
    case (TEN_PP40G_TX_PBERT_40GEX):
      rtn |= ten_pp40g_tx_pbert_40gex_t41(module_id);
      break;
      
    default:
      CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": Invalid mode.");
      rtn = CS_ERROR;
      break;
    }
  }
  
  CS_PRINT("ten_hl_pp40g_tx_init_t41 complete:  ");
  if (rtn == CS_OK) {
    CS_PRINT("CS_OK\n");
  }
  else {
    CS_PRINT("CS_ERROR\n");
  }
  return(rtn);
}







