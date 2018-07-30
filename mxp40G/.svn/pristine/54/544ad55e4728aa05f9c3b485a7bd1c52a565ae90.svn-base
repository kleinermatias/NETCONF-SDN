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
 * ten_hl_fracdiv.c
 *
 * API's for High Level Configuration of the Fractional Divider Block
 *
 * $Id: ten_hl_fracdiv.c,v 1.12 2013/02/22 20:44:11 jccarlis Exp $
 *
 */
 
#include "tenabo40.h"

#define TEN_CONSTANT_2_24 ((double)(0x1000000))

/****************************************************************/
/* $rtn_hdr_start  FRACTIONAL DIVIDER CONFIG                    */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : HIGH LEVEL                                      */
/* CHIP       : Tenabo                                          */
cs_status ten_hl_fracdiv_config(cs_uint16 dev_id, 
                              cs_uint16 instance,
                              cs_uint32 sysclk_freq, 
                              cs_uint32 desired_freq)
/* INPUTS     : o Dev Id                                        */
/*              o Instance                                      */
/*              o Sysclk Frequency                              */
/*              o Desired Frequency                             */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* Configures the Fractional Divider Block based on the         */
/* sysclk frequency and the desired frequency.                  */
/* This function is the same as ten_hl_fracdiv_init,            */
/* except that it also sets s2_en.                              */
/*                                                              */
/*  [instance] parameter is specified as:                       */
/*   0..15                                                      */
/*                                                              */
/*  [sysclk_freq] Sysclk Frequency in Hz                        */
/*                                                              */
/*  [desired_freq] Desired Frequency in Hz                      */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  cs_status rtn = CS_OK;
  cs_char8 *func = "ten_hl_fracdiv_config";  
  
  CS_PRINT("%s() %s, sysclk_freq=%d, desired_freq=%d\n", func, ten_fracdiv_instance_strings[instance], sysclk_freq, desired_freq);
  
  rtn |= ten_hl_fracdiv_init(dev_id, instance, sysclk_freq, desired_freq);
  
  if (desired_freq > 100000000) {
    rtn |= ten_frac_div_cfg_frac_div_s2en(dev_id, instance, 0);
  }

  /* Bugzilla 30990, high resolution usec delay timer.                         */
  /* Update system clock and its dependencies when we learn what it is */
  ten_dev_update_sysclock(dev_id, sysclk_freq);

  return (rtn);
}

/****************************************************************/
/* $rtn_hdr_start  FRACTIONAL DIVIDER INIT                      */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : HIGH LEVEL                                      */
/* CHIP       : Tenabo                                          */
cs_status ten_hl_fracdiv_init(cs_uint16 dev_id, 
                              cs_uint16 instance,
                              cs_uint32 sysclk_freq, 
                              cs_uint32 desired_freq)
/* INPUTS     : o Dev Id                                        */
/*              o Instance                                      */
/*              o Sysclk Frequency                              */
/*              o Desired Frequency                             */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* Configures the Fractional Divider (frac_div) Block based     */
/* on the sysclk frequency and the desired frequency.           */
/*                                                              */
/*  [instance] parameter is specified as:                       */
/*   0..15                                                      */
/*                                                              */
/*  [sysclk_freq] Sysclk Frequency in Hz                        */
/*                                                              */
/*  [desired_freq] Desired Frequency in Hz                      */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  cs_uint16 floor_i;
  cs_uint32 round_n;
  double i, n;
  cs_status rtn = CS_OK;
  cs_char8 *func = "ten_hl_fracdiv_init";  
  
  CS_PRINT("%s() %s, sysclk_freq=%d, desired_freq=%d\n", func, ten_fracdiv_instance_strings[instance], sysclk_freq, desired_freq);
  
  /* calculate I, N values */
  i = ((double)sysclk_freq * 4.0)/(double)desired_freq;
  floor_i = (cs_uint16)i;
  
  n = (i - (double)floor_i) * TEN_CONSTANT_2_24;
  round_n = (int)(n + 0.5);

  /*CS_PRINT("    sysclk_freq = %d, desired clk_freq = %d\n", sysclk_freq, desired_freq);*/
  CS_PRINT("    i=%lf, floor_i=%d (0x%08X)\n", i, floor_i, floor_i);
  CS_PRINT("    n=%lf, round_n=%d (0x%08X)\n", n, round_n, round_n);

  
  if (floor_i > 0xFF) {
    CS_HNDL_ERROR(dev_id, ETEN_DEV_INVALID_USER_ARG,"%s() FRAC_DIV_CFG_FRAC_DIV_INT out of range.", func);
    return (CS_ERROR);
  }
  CS_PRINT("Provision Fractional Divider...\n");
  
  rtn |= ten_frac_div_cfg_frac_div_reset(dev_id, instance, CS_RESET_DEASSERT);
  rtn |= ten_frac_div_cfg_frac_div_enable(dev_id, instance, CS_RESET_DEASSERT);

  rtn |= ten_frac_div_cfg_frac_div_width(dev_id, instance, 3);
  
  rtn |= ten_frac_div_cfg_frac_div_int(dev_id, instance, floor_i);
   
  rtn |= ten_frac_div_cfg_frac_div_n(dev_id, instance, (cs_uint16)(round_n >> 16), 
                             (cs_uint16)(round_n & 0xFFFF));
                               
  rtn |= ten_frac_div_cfg_frac_div_enable(dev_id, instance, 1);
                               
  rtn |= ten_frac_div_cfg_frac_div_s1en(dev_id, instance, 1);
     
  rtn |= ten_frac_div_cfg_frac_div_s2en(dev_id, instance, 1);
   
  /* toggle the reset */
  rtn |= ten_frac_div_cfg_frac_div_reset(dev_id, instance, CS_RESET_TOGGLE);

  CS_PRINT("Fractional Divider Provisioning Complete.\n");
  
  return (rtn);
}

