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
 * ten_hl_gpllx1.c
 *
 * API's for high level configuration of the GPLLX1 block.
 *
 * $Id: ten_hl_gpllx1.c,v 1.28 2013/04/17 18:36:22 jccarlis Exp $
 *
 */
 
#include "tenabo40.h"

/* API ten_hl_gpllx1_analog_config                     */
/* obsolete and should not be used     */

/********************************************************************/
/* $rtn_hdr_start  TENABO GPLL CHECK LOCK                           */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : HIGH LEVEL                                          */
/* CHIP       : Tenabo                                              */
cs_uint16 ten_hl_gpllx1_check_lock (cs_uint16 dev_id, 
                                     cs_uint16 inst) 
/* INPUTS     : o Device Id                                         */
/*            : o Instance                                          */
/* OUTPUTS    : ----                                                */
/* RETURNS    : 1: locked 0: NOT locked                             */
/* DESCRIPTION:                                                     */
/*  Wait for SerDes GPLL lock status                                */
/* Indicates if the SerDes is locked.                               */
/*                                                                  */
/*   [instance]                                                     */
/*     Specified as 0..16 or TEN_INSTANCE_ALL (0xFF)                */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
    /*cs_uint16 locked = 0;*/
    cs_uint16 i;
    T41_t *pDev = NULL;

    TEN_DEV_COMMON_VALIDATE(dev_id, pDev, FALSE);

  /* bugzilla #24260 start, check for valid instance */
  if ((inst >= TEN_GPLLX1_SDS_COUNT) && (inst != TEN_INSTANCE_ALL)) {
    CS_HNDL_ERROR(dev_id, ETEN_DEV_INVALID_USER_ARG, ": instance out of range.  s/b 0..16 or 0xFF.");
    return (FALSE);
  }
  /* bugzilla #24260 end, check for valid instance */

    for (i=0; i<100; i++)
    {
        if (TRUE == ten_gpllx1_txlockd0_lock(dev_id, inst))
            return TRUE;
        
        /* Delay 50ms ??*/
        /*misc::misc_delay(50);*/
        /*for (j=0; j<50; j++)                                    */
        /*    TEN_REG_READ(TEN_MPIF_REG_ADDR(pDev, CHIP_ID_LSB)); */
        TEN_MDELAY(50);
    }
    return FALSE;
}

/********************************************************************/
/* $rtn_hdr_start  HIGH LEVE GPLLX1 CONFIG SYSGPLL                  */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : HIGH LEVEL                                          */
/* CHIP       : Tenabo                                              */
cs_status ten_hl_gpllx1_config_SYSGPLL (cs_uint16 dev_id, 
                                        cs_uint16 mbclksel) 
/* INPUTS     : o Device Id                                         */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Config System GPLL Blocks                                        */
/*                                                                  */
/* The [mbclksel] parameter is specified as:                        */
/*   0 = sys_ref_freq <= 200000000Hz                                */
/*   1 = sys_ref_freq > 200000000Hz.                                */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
    CS_PRINT("ten_hl_gpllx1_config_SYSGPLL, dev_id=%d, mbclksel=%d\n", dev_id, mbclksel);
    
    if (0 != ten_mpif_clock_select_sys(dev_id, 0))
    {
        /* MPIF select failed */
        return (CS_ERROR);
    }

    if (0 != ten_mpif_global_reset_syspll(dev_id, CS_RESET_DEASSERT))
    {
        /* MPIF global reset failed */
        return (CS_ERROR);
    }

    if (mbclksel)
    {
        if (0 != ten_gpllx1_set_stxp0_tx_clkdiv_ctrl(dev_id, 0, 4, 0, 2, 0, 6))
        {
            /* stxp0 tx clkdiv failed */
            return (CS_ERROR);
        } 
        ten_gpllx1_stxp0_tx_cp(dev_id, 0, 3, 3);
    }
    else
    {
        if (0 != ten_gpllx1_set_stxp0_tx_clkdiv_ctrl(dev_id, 0, 4, 0, 0, 0, 8))
        {
            /* stxp0 tx clkdiv failed */
            return (CS_ERROR);
        }   
        ten_gpllx1_stxp0_tx_cp(dev_id, 0, 7, 7);
    }
    
    if (0 != ten_gpllx1_set_stxp0_tx_config(dev_id, 0, 0, 0))
    {
        /* stxp0 tx config failed */
        return (CS_ERROR);
    }
    
    /* apply ring_oscillator fix */
    ten_set_vco_coarse_tuning (dev_id, 0); /* Bugzilla #24261 */

    ten_gpllx1_set_txvco0_init(dev_id, 0, 1);
    
    ten_gpllx1_set_txvco0_init(dev_id, 0, 0);

    return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  HIGH LEVEL GPLLX1 INIT                           */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : HIGH LEVEL                                          */
/* CHIP       : Tenabo                                              */
cs_status ten_hl_gpllx1_init (cs_uint16 dev_id, 
                              cs_uint8  instance, 
                              cs_uint8  mode, 
                              cs_uint16 stxp_pd)
/* INPUTS     : o Device Id                                         */
/*            : o Instance                                          */
/*            : o Mode                                              */
/*              o STXP PD                                           */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Initializes GPLLs as specified.                                  */
/*                                                                  */
/* The [instance] parameter is specified as:                        */
/*   0..16 or TEN_INSTANCE_ALL (0xFF)                               */
/*                                                                  */
/* The [mode] parameter is specified as:                            */
/*   TEN_HL_GPLL_MODE_SFI42_40G     = 0                             */
/*   TEN_HL_GPLL_MODE_SFI42_10G     = 1                             */
/*   TEN_HL_GPLL_MODE_SFI41         = 2                             */
/*   TEN_HL_GPLL_MODE_XFI_4GFC      = 3                             */
/*   TEN_HL_GPLL_MODE_XFI_2GFC      = 4                             */
/*   TEN_HL_GPLL_MODE_XFI_1GFC      = 5                             */
/*   TEN_HL_GPLL_MODE_DEFAULT       = 6                             */
/*   Note: This argument is ignored when stxp_pd = 1.               */
/*                                                                  */
/* The [stxp_pd] parameter is specified as:                         */
/*   0 = entire transmit section is powered up                      */
/*   1 = entire transmit section is powered down                    */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  cs_status ret_val = CS_OK;
  cs_char8 *func = "ten_hl_gpllx1_init";  

  if (mode > TEN_HL_GPLL_MODE_DEFAULT) {
    CS_HNDL_ERROR(dev_id, ETEN_DEV_INVALID_USER_ARG, "%s() mode %d out of range.  s/b 0..6.", func, mode);
    return(CS_ERROR);
  }
  
  if (instance < TEN_GPLLX1_SDS_COUNT) {
    CS_PRINT("%s() %s, %s, stxp_pd=%d\n", func, ten_gpll_instance_strings[instance], ten_gpllx1_mode_strings[mode], stxp_pd);
  }
  else if (instance == TEN_INSTANCE_ALL) {
    CS_PRINT("%s() INSTANCE_ALL, %s, stxp_pd=%d\n", func, ten_gpllx1_mode_strings[mode], stxp_pd);
  } else {
    CS_HNDL_ERROR(dev_id, ETEN_DEV_INVALID_USER_ARG, "%s() instance %d out of range.  s/b 0..16 or 0xFF.", func, instance);
    return(CS_ERROR);
  }
 
 

  ret_val |= ten_gpllx1_stxp0_tx_pwrdn_all(dev_id, instance, stxp_pd);
  /* set charge pump control register */
  ret_val |= ten_gpllx1_stxp0_tx_cp(dev_id, instance, 0x3, 0x3);

  if (stxp_pd == 1) {
    goto RTN_EXIT;
  }

  /* apply ring_oscillator fix */
  ten_set_vco_coarse_tuning (dev_id, instance);  /* Bugzilla #24261 */
  
  switch (mode) {
    case TEN_HL_GPLL_MODE_SFI42_40G:
      /* Clock output control: tclkien=0 (RingVCO), clkouten=1 (test clock disabled), tclko_sel=x36 (div8) */
      ret_val |= ten_gpllx1_set_stxp0_tx_clkout_ctrl(dev_id, instance,0,1,0x36);
      /* Clock Div Control:  */
      /* fastdiv_sel=4 (div2), strdiv_sel=0 (div1), ctvdiv_sel=0 (div1), ddiv_sel_sel=0 (div1), rdiv_sel=div64 */
      ret_val |= ten_gpllx1_set_stxp0_tx_clkdiv_ctrl(dev_id, instance,4,0,0,0,0x9); 
      /* Config: buswidth=0 (8bit), pilot_sel=4 (AUXREFIN) */
      ret_val |= ten_gpllx1_set_stxp0_tx_config(dev_id, instance,0, 4);
      /* Config: lptime_sel=2 (AUXREFIN) */
      ret_val |= ten_gpllx1_stxp0_tx_config_lptime_sel(dev_id, instance,2); 
      break;
    case TEN_HL_GPLL_MODE_SFI42_10G:
      /* Clock output control */
      /* Clock output control: tclkien=0 (RingVCO), clkouten=1 (test clock disabled), tclko_sel=x36 (div8) */
      ret_val |= ten_gpllx1_set_stxp0_tx_clkout_ctrl(dev_id, instance,0,1,0x36);
      /* Clock Div Control */
      /* fastdiv_sel=4 (div2), strdiv_sel=0 (div1), ctvdiv_sel=0 (div1), ddiv_sel_sel=0 (div1), rdiv_sel=div8 */
      ret_val |= ten_gpllx1_set_stxp0_tx_clkdiv_ctrl(dev_id, instance,4,0,0,0,0x9); 
      /* Config: buswidth=0 (8bit), pilot_sel=4 (AUXREFIN) */
      ret_val |= ten_gpllx1_set_stxp0_tx_config(dev_id, instance, 0, 4);
      /* Config: lptime_sel=2 (AUXREFIN) */
      ret_val |= ten_gpllx1_stxp0_tx_config_lptime_sel(dev_id, instance,2); 
      break;
    case TEN_HL_GPLL_MODE_SFI41:
      /* Clock output control */
      /* Clock output control: tclkien=0 (RingVCO), clkouten=1 (test clock disabled), tclko_sel=x36 (div8) */
      ret_val |= ten_gpllx1_set_stxp0_tx_clkout_ctrl(dev_id, instance,0,1,0x36);
      /* Clock Div Control */
      /* fastdiv_sel=4 (div2), strdiv_sel=0 (div1), ctvdiv_sel=0 (div1), ddiv_sel_sel=0 (div1), rdiv_sel=div8 */
      ret_val |= ten_gpllx1_set_stxp0_tx_clkdiv_ctrl(dev_id, instance,4,0,0,0,6); 
      /* Config: buswidth=0 (8bit), pilot_sel=4 (AUXREFIN) */
      ret_val |= ten_gpllx1_set_stxp0_tx_config(dev_id, instance, 0, 4);
      /* Config: lptime_sel=2 (AUXREFIN) */
      ret_val |= ten_gpllx1_stxp0_tx_config_lptime_sel(dev_id, instance,2); 
      break;
    case TEN_HL_GPLL_MODE_XFI_4GFC:
      /* Clock output control */
      /* Clock output control: tclkien=0 (RingVCO), clkouten=1 (test clock disabled), tclko_sel=x36 (div8) */
      ret_val |= ten_gpllx1_set_stxp0_tx_clkout_ctrl(dev_id, instance,0,0,0x36);
      /* Clock Div Control */
      /* fastdiv_sel=4 (div2), ctrdiv_sel=0 (div1), ctvdiv_sel=0 (div1), ddiv_sel_sel=1 (div2), rdiv_sel=7 (div16) */
      ret_val |= ten_gpllx1_set_stxp0_tx_clkdiv_ctrl(dev_id, instance,4,0,0,1,7); 
      /* Config: buswidth=0 (8bit), pilot_sel=4 (AUXREFIN) */
      ret_val |= ten_gpllx1_set_stxp0_tx_config(dev_id, instance, 0, 1);
      /* Config: lptime_sel=2 (AUXREFIN) */
      ret_val |= ten_gpllx1_stxp0_tx_config_lptime_sel(dev_id, instance,2); 
      break;
    case TEN_HL_GPLL_MODE_XFI_2GFC:
      /* Clock output control */
      /* Clock output control: tclkien=0 (RingVCO), clkouten=1 (test clock disabled), tclko_sel=x36 (div8) */
      ret_val |= ten_gpllx1_set_stxp0_tx_clkout_ctrl(dev_id, instance,0,0,0x36);
      /* Clock Div Control */
      /* fastdiv_sel=4 (div2), ctrdiv_sel=0 (div1), ctvdiv_sel=0 (div1), ddiv_sel_sel=2 (div4), rdiv_sel=8 (div32) */
      ret_val |= ten_gpllx1_set_stxp0_tx_clkdiv_ctrl(dev_id, instance,4,0,0,2,8); 
      /* Config: buswidth=0 (8bit), pilot_sel=4 (AUXREFIN) */
      ret_val |= ten_gpllx1_set_stxp0_tx_config(dev_id, instance, 0, 1);
      /* Config: lptime_sel=2 (AUXREFIN) */
      ret_val |= ten_gpllx1_stxp0_tx_config_lptime_sel(dev_id, instance,2); 
      break;
    case TEN_HL_GPLL_MODE_XFI_1GFC:
      /* Clock output control */
      /* Clock output control: tclkien=0 (RingVCO), clkouten=1 (test clock disabled), tclko_sel=x36 (div8) */
      ret_val |= ten_gpllx1_set_stxp0_tx_clkout_ctrl(dev_id, instance,0,0,0x36);
      /* Clock Div Control */
      /* fastdiv_sel=4 (div2), ctrdiv_sel=0 (div1), ctvdiv_sel=0 (div1), ddiv_sel_sel=3 (div8), rdiv_sel=9 (div64) */
      ret_val |= ten_gpllx1_set_stxp0_tx_clkdiv_ctrl(dev_id, instance,4,0,0,3,9); 
      /* Config: buswidth=0 (8bit), pilot_sel=4 (AUXREFIN) */
      ret_val |= ten_gpllx1_set_stxp0_tx_config(dev_id, instance, 0, 1);
      /* Config: lptime_sel=2 (AUXREFIN) */
      ret_val |= ten_gpllx1_stxp0_tx_config_lptime_sel(dev_id, instance,2); 
      break;
    default:
      /* Clock output control */
      /* Clock output control: tclkien=0 (RingVCO), clkouten=1 (test clock disabled), tclko_sel=x36 (div8) */
      ret_val |= ten_gpllx1_set_stxp0_tx_clkout_ctrl(dev_id, instance,0,0,0x36);
      /* Clock Div Control */
      /* fastdiv_sel=4 (div2), ctrdiv_sel=0 (div1), ctvdiv_sel=0 (div1), ddiv_sel_sel=0 (div1), rdiv_sel=6 (div8) */
      ret_val |= ten_gpllx1_set_stxp0_tx_clkdiv_ctrl(dev_id, instance,4,0,0,0,6); 
      /* Config: buswidth=0 (8bit), pilot_sel=4 (AUXREFIN) */
      ret_val |= ten_gpllx1_set_stxp0_tx_config(dev_id, instance, 0, 1);
      /* Config: lptime_sel=2 (AUXREFIN) */
      ret_val |= ten_gpllx1_stxp0_tx_config_lptime_sel(dev_id, instance,2); 
  }

  ret_val |= ten_gpllx1_set_txvco0_init(dev_id, instance, 1);
  ret_val |= ten_gpllx1_set_txvco0_init(dev_id, instance, 0);
 
RTN_EXIT:
  return (ret_val);
}

/********************************************************************/
/* $rtn_hdr_start  HIGH LEVEL GPLLX1 WAIT FOR VCOTUNE               */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : HIGH LEVEL                                          */
/* CHIP       : Tenabo                                              */
cs_int16 ten_hl_gpllx1_waitfor_vcotune (cs_uint16 dev_id, 
                                        cs_uint8  instance)
/* INPUTS     : o Device Id                                         */
/*            : o Instance                                          */
/* OUTPUTS    : ----                                                */
/* RETURNS    : 1=locked, 0=NOT locked or CS_ERROR                  */
/* DESCRIPTION:                                                     */
/* Wait for GPLL VCO Tune to lock.                                  */
/*                                                                  */
/* The [instance] parameter is specified as:                        */
/*   0..16 or TEN_INSTANCE_ALL (0xFF)                               */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  cs_uint16 ii; 
  cs_uint16 tuned = 0;
  cs_boolean check_tune = 0;
  cs_boolean check_lock = 0;

  /* bugzilla #24260 start, check for valid instance */
  if ((instance >= TEN_GPLLX1_SDS_COUNT) && (instance != TEN_INSTANCE_ALL)) {
    CS_HNDL_ERROR(dev_id, ETEN_DEV_INVALID_USER_ARG, ": instance out of range.  s/b 0..16.");
    return(0);
  }
  /* bugzilla #24260 end, check for valid instance */

  for (ii=0; ii<60; ii++) {
    check_tune = ten_gpllx1_get_txvco_tune_intstatus(dev_id, instance);
    CS_PRINT("%d:, GPLL instance=%d VCO Tune status = %d\n", ii, instance, tuned);
      
    if (check_tune == FALSE) {
      break; 
    }
    /* Bugzilla #28471, minimum delay */
    TEN_MDELAY(20);
  }

  if (check_tune == TRUE) {
    goto RTN_EXIT;
  }

  for (ii=0; ii<100; ii++) {
    check_lock = ten_gpllx1_txlockd0_filt_lock(dev_id, instance);
    CS_PRINT("%d:, GPLL instance=%d Filt lock status = %d\n", ii, instance, tuned);
      
    if (check_lock == TRUE) {
        /* Bug #39428: Regression failures due to dynamic reconfig of XFI to SFI4.2 with BMP config */
        /* Make sure FILT_LOCKs is truly stable */
        tuned++;
        if (tuned >= 10) {
          CS_PRINT("GPLL instance=%d FILT_LOCKs=TUNED\n", instance);
          break; 
        }
    }
    else {
      tuned = 0;
    }
    /* Bugzilla #28471, minimum delay */
    TEN_MDELAY(20);
  }

RTN_EXIT:
  return (tuned > 0);
}

/* Bugzilla 31529 Start */
/********************************************************************/
/* $rtn_hdr_start  HIGH LEVEL GPLLX1 WAIT FOR LOCK 40G              */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : HIGH LEVEL                                          */
/* CHIP       : Tenabo                                              */
cs_status ten_hl_gpllx1_waitfor_gpll_lock_40g(cs_uint16 dev_id, 
                                              cs_uint8  instance)
/* INPUTS     : o Device Id                                         */
/*            : o Instance                                          */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK if locked or CS_ERROR                         */
/* DESCRIPTION:                                                     */
/* Wait for GPLL lock on a 40G interface.                           */
/* Returns:  CS_ERROR if GPLL is not locked or                      */
/*           CS_OK if GPLL is locked.                               */
/*                                                                  */
/* The [instance] parameter is specified as:                        */
/*   1, 9 or TEN_INSTANCE_ALL (0xFF)                                */
/* Typically, use '1' for Module A or '9' for Module B.             */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  cs_uint16 ii;
  cs_status rtn = CS_OK;
  cs_uint16 inst;
  cs_uint16 gpll_inst;
  cs_uint16 module;
  /* bugzilla # 23069, do not use all 8 GPLLs for 40G transponder */
  TEN_GPLLX1_SDS_COMMON_STXP0_TX_PWRDN_t tmp_stxp0_tx_pwrdn;
  volatile cs_reg *tmp_addr;
  T41_t *pDev = NULL;
  cs_char8 *func = "ten_hl_gpllx1_waitfor_gpll_lock_40g";  

  TEN_DEV_COMMON_VALIDATE(dev_id, pDev, CS_ERROR);

  if ((instance == 1) || (instance == 9)) {
    CS_PRINT("%s() %s\n", func, ten_gpll_instance_strings[instance]);
  }
  else if (instance == TEN_INSTANCE_ALL) {
    CS_PRINT("%s() INSTANCE_ALL\n", func);
  } 
  else {
    CS_HNDL_ERROR(dev_id, ETEN_DEV_INVALID_USER_ARG, "%s() instance %d out of range.  s/b 1, 9 or 0xFF.", func, instance);
    return(CS_ERROR);
  }

  /* Bugzilla #36753: In Warm Start mode, disable API FAILURE */
  if (ten_dev_is_ws_in_progress(dev_id)) {
    CS_PRINT("Device is in warm start mode, report CS_OK\n");
    return (CS_OK);
  }

  for (module=0; module<2; module++) {
    if ((instance == (module * 8) + 1) || (instance == TEN_INSTANCE_ALL)) {
      gpll_inst = (module * 8) + 1;
      for (ii=0; ii<8; ii++) {
        inst = gpll_inst + ii;
        tmp_addr = TEN_GPLLX1_INST_REG_ADDR(pDev, STXP0_TX_PWRDN, inst);
        tmp_stxp0_tx_pwrdn.wrd = TEN_REG_READ(tmp_addr);
        if (tmp_stxp0_tx_pwrdn.bf.STXP_PD) {
          /* Don't check for lock on this GPLL because it is powered down */
          continue;
        }
      
        if (ten_gpllx1_txlockd0_lock(dev_id, inst) == FALSE) {
          rtn = CS_ERROR;
          CS_PRINT("%s() GPLLX1 TX Lock failed for %s\n", func, ten_gpll_instance_strings[inst]);
        }
      }
    }
  }

  return (rtn);
}

/********************************************************************/
/* $rtn_hdr_start  HIGH LEVEL GPLLX1 WAIT FOR LOCK 40G T41           */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : HIGH LEVEL                                          */
/* CHIP       : Tenabo                                              */
cs_status ten_hl_gpllx1_waitfor_gpll_lock_40g_t41(cs_uint16 dev_id, 
                                                  cs_uint8  module_num)
/* INPUTS     : o Device Id                                         */
/*            : o Module Num                                        */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK if locked or CS_ERROR                         */
/* DESCRIPTION:                                                     */
/* Wait for GPLL lock on a 40G module.                              */
/* Returns:  CS_ERROR if GPLL is not locked or                      */
/*           CS_OK if GPLL is locked.                               */
/*                                                                  */
/* The [module_num] parameter is specified as:                      */
/*   0 = TEN_MODULE_A                                               */
/*   1 = TEN_MODULE_B                                               */
/*   2 = TEN_MODULE_A_AND_B                                         */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  cs_uint16 ii;
  cs_status rtn = CS_OK;
  cs_uint16 inst;
  cs_uint16 gpll_inst;
  cs_uint16 module;
  TEN_GPLLX1_SDS_COMMON_STXP0_TX_PWRDN_t tmp_stxp0_tx_pwrdn;
  volatile cs_reg *tmp_addr;
  T41_t *pDev = NULL;
  cs_char8 *func = "ten_hl_gpllx1_waitfor_gpll_lock_40g_t41";  

  TEN_DEV_COMMON_VALIDATE(dev_id, pDev, CS_ERROR);

  if (module_num <= TEN_MODULE_A_AND_B) {
    CS_PRINT("%s() %s\n", func, ten_module_strings[module_num]);
  } else {
    CS_HNDL_ERROR(dev_id, ETEN_DEV_INVALID_USER_ARG, "%s() module_num %d out of range.  s/b 0, 1 or 2.", func, module_num);
    return(CS_ERROR);
  }

  for (module=0; module<2; module++) {
    if ((module_num == module) || (module_num == TEN_MODULE_A_AND_B)) {
      gpll_inst = (module * 8) + 1;
      for (ii=0; ii<8; ii++) {
        inst = gpll_inst + ii;
        tmp_addr = TEN_GPLLX1_INST_REG_ADDR(pDev, STXP0_TX_PWRDN, inst);
        tmp_stxp0_tx_pwrdn.wrd = TEN_REG_READ(tmp_addr);
        if (tmp_stxp0_tx_pwrdn.bf.STXP_PD) {
          /* Don't check for lock on this GPLL because it is powered down */
          continue;
        }
      
        if (ten_gpllx1_txlockd0_lock(dev_id, inst) == FALSE) {
          rtn = CS_ERROR;
          CS_PRINT("%s() GPLLX1 TX Lock failed for %s\n", func, ten_gpll_instance_strings[inst]);
        }
      }
    }
  }

  return (rtn);
}
/* Bugzilla 31529 End */

/* Bugzilla 31529 Start */
/********************************************************************/
/* $rtn_hdr_start  HIGH LEVEL GPLLX1 WAIT FOR LOCK                  */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : HIGH LEVEL                                          */
/* CHIP       : Tenabo                                              */
cs_status ten_hl_gpllx1_waitfor_gpll_lock(cs_uint16 dev_id, 
                                          cs_uint8  instance)
/* INPUTS     : o Device Id                                         */
/*            : o Instance                                          */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK if locked or CS_ERROR                         */
/* DESCRIPTION:                                                     */
/* Wait for GPLL lock on a 40G interface, ie 4-lane SFI-4.2,        */
/* SFI-4.1, XAUI, XFI.                                              */
/* Returns:  CS_ERROR if GPLL is not locked or                      */
/*           CS_OK if GPLL is locked.                               */
/*                                                                  */
/* The [instance] parameter is specified as:                        */
/*   1..12                                                          */
/* Typically, '1 + slice' for Module A or '9 + slice' for Module B. */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  cs_uint16 inst;
  cs_status rtn = CS_OK;
  cs_char8 *func = "ten_hl_gpllx1_waitfor_gpll_lock";  
  
  
  if ((instance >= TEN_GPLLX1_SDS_COUNT-4) || (instance < 1)) {
    CS_HNDL_ERROR(dev_id, ETEN_DEV_INVALID_USER_ARG, "%s instance %d out of range.  s/b 1..12", func, instance);
    return (CS_ERROR);
  }
  
  CS_PRINT("%s() %s\n", func, ten_gpll_instance_strings[instance]);
  
  
  /* Get RX GPLL lock status */
  if (ten_gpllx1_txlockd0_lock(dev_id, instance) == FALSE) {
    CS_PRINT("%s() Failed to lock for %s\n", func, ten_gpll_instance_strings[instance]);
    rtn = CS_ERROR;
  }

  /* Get TX GPLL lock status */
  inst = instance + 4;
  if (ten_gpllx1_txlockd0_lock(dev_id, inst) == FALSE) {
      CS_PRINT("%s() Failed to lock for %s\n", func, ten_gpll_instance_strings[inst]);
    rtn = CS_ERROR;
  }
  
  return (rtn);
}

/* Bugzilla 31529 End */
/********************************************************************/
/* $rtn_hdr_start  HIGH LEVEL GPLLX1 WAIT FOR LOCK T41              */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : HIGH LEVEL                                          */
/* CHIP       : Tenabo                                              */
cs_status ten_hl_gpllx1_waitfor_gpll_lock_t41(cs_uint16 dev_id, 
                                              cs_uint8  module_num,
                                              cs_uint8  slice)
/* INPUTS     : o Device Id                                         */
/*            : o Module Num                                        */
/*            : o Slice                                             */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK if locked or CS_ERROR                         */
/* DESCRIPTION:                                                     */
/* Wait for GPLL lock on a 10G interface TX and RX                  */
/* Returns:  CS_ERROR if GPLL is not locked or                      */
/*           CS_OK if GPLL is locked.                               */
/*                                                                  */
/* The [module_num] parameter is specified as:                      */
/*   0 = TEN_MODULE_A                                               */
/*   1 = TEN_MODULE_B                                               */
/*                                                                  */
/* The [slice] parameters specify the slice and is one of the       */
/* following:                                                       */
/*   TEN_SLICE0 = 0                                                 */
/*   TEN_SLICE1 = 1                                                 */
/*   TEN_SLICE2 = 2                                                 */
/*   TEN_SLICE3 = 3                                                 */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  cs_uint16 instance;
  cs_status rtn = CS_OK;
  cs_char8 *func = "ten_hl_gpllx1_waitfor_gpll_lock_t41";  
  
 
  if (module_num < TEN_MODULE_A_AND_B) {
    CS_PRINT("%s() %s\n", func, ten_module_strings[module_num]);
  } else {
    CS_HNDL_ERROR(dev_id, ETEN_DEV_INVALID_USER_ARG, "%s() module_num %d out of range.  s/b 0, 1.", func, module_num);
    return(CS_ERROR);
  }

  if (slice >= TEN_MAX_SLICES) {
    CS_HNDL_ERROR(dev_id, ETEN_MOD_INVALID_USER_ARG, "%s() slice %d out of range.  s/b 0..3.", func, slice);
    return (CS_ERROR);
  }

  CS_PRINT("%s() %s, %s\n", func, ten_module_strings[module_num], ten_slice_strings[slice]);


  /* Get RX GPLL lock status */
  instance = 1 + module_num * 8 + slice;
  if (ten_gpllx1_txlockd0_lock(dev_id, instance) == FALSE) {
    CS_PRINT("%s() Failed to lock for %s\n", func, ten_gpll_instance_strings[instance]);
    rtn = CS_ERROR;
  }

  /* Get TX GPLL lock status */
  instance = instance + 4;
  if (ten_gpllx1_txlockd0_lock(dev_id, instance) == FALSE) {
      CS_PRINT("%s() Failed to lock for %s\n", func, ten_gpll_instance_strings[instance]);
    rtn = CS_ERROR;
  }
  
  return (rtn);
}




