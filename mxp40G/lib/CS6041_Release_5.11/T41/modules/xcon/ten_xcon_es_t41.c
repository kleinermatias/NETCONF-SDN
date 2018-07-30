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
 * ten_xcon_es_t41.c
 *
 * API's for T41 XCON ES block.
 *
 * $Id: ten_xcon_es_t41.c,v 1.24 2013/02/22 20:48:11 jccarlis Exp $
 *
 */
 
#include "tenabo40.h"

/****************************************************************/
/* PROTOTYPES of private functions                              */
/****************************************************************/
cs_status ten_xcon_es_set_config_mfp_mode(cs_uint16         dev_id,
                                          ten_xcon_es_num_t es_num,
                                          cs_uint8          mode);
cs_status ten_xcon_es_setup_amplitude_recenter_common(cs_uint16 dev_id,
                                          ten_xcon_es_num_t es_num);
cs_status ten_xcon_es_recenter_measure_duration_in_clock_cycles(
                                          cs_uint16         dev_id, 
                                          ten_xcon_es_num_t es_num,
                                          cs_uint16         duration);
cs_status ten_xcon_es_setup_amplitude_recenter_no_fpa_common(
                                          cs_uint16 dev_id,
                                          ten_xcon_es_num_t es_num,
                                          cs_uint16 margin_lower,
                                          cs_uint16 margin_upper,
                                          cs_uint16 correct_lower,
                                          cs_uint16 correct_upper,
                                          cs_uint8  duration,
                                          cs_uint32 sysclk_freq);
cs_status ten_xcon_es_setup_amplitude_recenter_with_fpa_common(
                                          cs_uint16 dev_id,
                                          ten_xcon_es_num_t es_num,
                                          cs_uint16 static_depth,
                                          cs_uint16 circuit_th_lower,
                                          cs_uint16 circuit_th_upper);
cs_status ten_xcon_es_get_recenter_type(  ten_dev_cb_t     *pdevcb, 
                                          ten_xcon_es_num_t es_num,
                                          cs_uint8         *mod_num, 
                                          cs_uint8         *rcntr_type,
                                          cs_uint8         *is40g);
cs_uint16 ten_xcon_es_get_pkt_mode(       cs_uint16 dev_id,
                                          ten_xcon_es_num_t es_num);
cs_status ten_xcon_es_datapath_reset_quick(cs_uint16 dev_id, 
                                          ten_xcon_es_num_t es_num,
                                          cs_reset_action_t act);
cs_status ten_xcon_datapath_reset_quick(  cs_uint16 dev_id,
                                          cs_reset_action_t act);
cs_status ten_xcon_es_check_amplitude_recenter_40g_map(cs_uint16 dev_id,
                                                   cs_uint8  module_num,
                                                   cs_uint8 *map);
cs_status ten_xcon_es_amplitude_recenter_with_fpa_10g_cb(cs_uint16 dev_id,
                                           ten_xcon_es_num_t es_num_ovl,
                                           cs_uint16 static_depth,
                                           cs_uint16 circuit_th_lower,
                                           cs_uint16 circuit_th_upper,
                                           cs_uint16 cb_rw);
cs_status ten_xcon_es_amplitude_recenter_with_fpa_40g_cb(cs_uint16 dev_id,
                                           ten_xcon_es_num_t es_num_ovl,
                                           cs_uint16 static_depth,
                                           cs_uint16 circuit_th_lower,
                                           cs_uint16 circuit_th_upper,
                                           cs_uint16 cb_rw);
cs_status ten_xcon_es_amplitude_recenter_10g_cb( cs_uint16 dev_id,
                                           ten_xcon_es_num_t es_num_ovl,
                                           cs_uint16 margin_lower,
                                           cs_uint16 margin_upper,
                                           cs_uint16 correct_lower,
                                           cs_uint16 correct_upper,
                                           cs_uint8  duration,
                                           cs_uint32 sysclk_freq,
                                           cs_uint16 cb_rw);
cs_status ten_xcon_es_amplitude_recenter_40g_cb(cs_uint16 dev_id,
                                           cs_uint8  module_num_ov,
                                           cs_uint16 margin_lower,
                                           cs_uint16 margin_upper,
                                           cs_uint16 correct_lower,
                                           cs_uint16 correct_upper,
                                           cs_uint8  duration,
                                           cs_uint32 sysclk_freq,
                                           cs_uint16 cb_rw);
cs_status ten_xcon_es_setup_amplitude_recenter_40g_cb( cs_uint16 dev_id,
                                           cs_uint8  module_num,
                                           cs_uint16 margin_lower,
                                           cs_uint16 margin_upper,
                                           cs_uint16 correct_lower,
                                           cs_uint16 correct_upper,
                                           cs_uint8  duration,
                                           cs_uint32 sysclk_freq,
                                           cs_uint16 cb_rw);
cs_status ten_xcon_es_setup_amplitude_recenter_10g_cb(cs_uint16 dev_id,
                                           ten_xcon_es_num_t es_num,
                                           cs_uint16 margin_lower,
                                           cs_uint16 margin_upper,
                                           cs_uint16 correct_lower,
                                           cs_uint16 correct_upper,
                                           cs_uint8  duration,
                                           cs_uint32 sysclk_freq,
                                           cs_uint16 cb_rw);
cs_status ten_xcon_es_setup_amplitude_recenter_with_fpa_40g_cb(cs_uint16 dev_id,
                                           cs_uint8  module_num,
                                           cs_uint16 static_depth,
                                           cs_uint16 circuit_th_lower,
                                           cs_uint16 circuit_th_upper,
                                           cs_uint16 cb_rw);
cs_status ten_xcon_es_setup_amplitude_recenter_with_fpa_10g_cb(cs_uint16 dev_id,
                                           ten_xcon_es_num_t es_num,
                                           cs_uint16 static_depth,
                                           cs_uint16 circuit_th_lower,
                                           cs_uint16 circuit_th_upper,
                                           cs_uint16 cb_rw);
cs_status ten_xcon_es_sadeco_fifo_reset_quick(cs_uint16 dev_id, 
                                           cs_uint8  module_num,
                                           cs_uint16 action);


#if (0)
#endif
/****************************************************************/

/* Bugzilla 27270 Amplitude Recentering, T41 release 5.4 */
cs_char8 * xcon_es_recntr_str[] = {
  "default",     /* TEN_XCON_ES_RECENTER_DEFAULT    */
  "iml",         /* TEN_XCON_ES_RECENTER_IML,       */
  "amp 10g",     /* TEN_XCON_ES_RECENTER_AMP_10G,   */
  "amp 40g",     /* TEN_XCON_ES_RECENTER_AMP_40G,   */
  "amp fpa 10g", /* TEN_XCON_ES_RECENTER_FPA_10G,   */
  "amp fpa 40g"  /* TEN_XCON_ES_RECENTER_FPA_40G,   */
};
/* Bugzilla 27270 Amplitude Recentering, T41 release 5.5 */
cs_char8 * xcon_es_recntr_recov_str[] = {
  "default",     /* TEN_XCON_ES_RECENTER_RECOVERY_DFLT */
  "auto",        /* TEN_XCON_ES_RECENTER_RECOVERY_AUTO */
  "interrupt",   /* TEN_XCON_ES_RECENTER_RECOVERY_INTP */
  "none",        /* TEN_XCON_ES_RECENTER_RECOVERY_NONE */
};

char *str_ar_setup_failed_  = "Amplitude Recenter Setup failed";
char *str_amprecent_failed_ = "Amplitude Recenter failed";


/****************************************************************/
/* $rtn_hdr_start  SET ES RECENTER MEASUREMENT PERIOD           */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : XCON                                            */
/* CHIP       : Tenabo                                          */
cs_status ten_xcon_es_recenter_measure_period_t41(cs_uint16         dev_id, 
                                                  ten_xcon_es_num_t es_num,
                                                  cs_uint8          duration,
                                                  cs_uint32         sysclk_freq)
/* INPUTS     : o Device Id                                     */
/*              o Elastic Store Id                              */
/*              o Period                                        */
/*              o System Clock Frequency                        */
/*                                                              */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* This API calculates the value needed, based on sysclk_freq,  */
/* to program an amplitude recenter measurment period of        */
/* <period> ms and writes it to the XCON_ES_MEASUREMENT_PERIOD  */
/* register.                                                    */
/*                                                              */
/* The [es_num] parameter is specified as:                      */
/*   0 = XCON_ELASTIC_STORE_0                                   */
/*   1 = XCON_ELASTIC_STORE_1                                   */
/*   2 = XCON_ELASTIC_STORE_2                                   */
/*   3 = XCON_ELASTIC_STORE_3                                   */
/*   4 = XCON_ELASTIC_STORE_4                                   */
/*   5 = XCON_ELASTIC_STORE_5                                   */
/*   6 = XCON_ELASTIC_STORE_6                                   */
/*   7 = XCON_ELASTIC_STORE_7                                   */
/*   0xFF = XCON_ELASTIC_STORE_ALL                              */
/*                                                              */
/* The [duration] parameter is specified as:                    */
/*   0..157~168 milliseconds, depending on sysclk_freq          */
/*                                                              */
/* The [sysclk_freq] parameter is specified as:                 */
/*   the sysclk frequency in hertz, i.e., 425000000             */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  cs_uint32 dur_;        /* local copy of duration, expanded for math */
  cs_char8 *func = "ten_xcon_es_recenter_measure_period_t41";

  /* Parameter Checking */
  if((es_num > XCON_ELASTIC_STORE_7) && (es_num != XCON_ELASTIC_STORE_ALL)) { 
    CS_HNDL_ERROR(dev_id, ETEN_DEV_INVALID_USER_ARG, 
      ": %s(),  es_num %d", func, es_num); 
    return CS_ERROR; 
  }

  CS_PRINT("%s(dev_id=%d, es_num=%d, duration=%d, sysclk_freq=%d)\n",
           func, dev_id, es_num, duration, sysclk_freq);

  /* The min/max depth measurement period is defined by DURATION in   */
  /* increments of 1024 system clock cycles. DURATION must be greater */
  /*  than 0.                                                         */
  /* Clunky math to make this fit in integers...                      */
  /* First, divide frequency in Hz by 1024 (size of duration chunks   */
  /*  in clock cycles).                                               */
  dur_  = sysclk_freq / 1024;
  /* Second, adjust for fact that period though period is supplied as */
  /* an integer, it is really a millisecond (10e-3) value.            */
  
  /* Bugzilla  #26726, fix ES measurement period calculation rounding error  */
  /* Multiply for requested number of millseconds.                           */
  dur_ *= duration;
  dur_ /= 1000;
  
  /*   period * sysclk_freq / 1024 < 0xFFFF   */
  if (dur_ > 0x0000FFFF) { 
    CS_HNDL_ERROR(dev_id, ETEN_DEV_INVALID_USER_ARG, 
                             ": Warning, %s(duration=%d, sysclk_freq=%d) Calculated measurement duration %d too large, using %d",
                             func, duration, sysclk_freq, dur_, 0x0FFFF); 
    dur_ = 0x0FFFF; 
  }
  else if (dur_ == 0) { 
    CS_HNDL_ERROR(dev_id, ETEN_DEV_INVALID_USER_ARG, 
                             ": Warning, %s(duration=%d, sysclk_freq=%d) Calculated measurement duration 0 is invalid, using 1",
                             func, duration, sysclk_freq); 
    dur_ = 1; 
  }

  return (ten_xcon_es_recenter_measure_duration_in_clock_cycles(dev_id, es_num, (cs_uint16) dur_) );
}

/****************************************************************/
/* helper function                                              */
/* ten_xcon_es_recenter_measure_duration_in_clock_cycles()      */
/****************************************************************/
/* INPUTS     : o Device Id                                     */
/*              o Elastic Store Id                              */
/*              o Duration                                      */
/*                                                              */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* This API calculates the value needed, based on sysclk_freq,  */
/* to program an amplitude recenter measurment period of        */
/* <period> ms and writes it to the XCON_ES_MEASUREMENT_PERIOD  */
/* register.                                                    */
/*                                                              */
/* The [es_num] parameter is specified as:                      */
/*   0 = XCON_ELASTIC_STORE_0                                   */
/*   1 = XCON_ELASTIC_STORE_1                                   */
/*   2 = XCON_ELASTIC_STORE_2                                   */
/*   3 = XCON_ELASTIC_STORE_3                                   */
/*   4 = XCON_ELASTIC_STORE_4                                   */
/*   5 = XCON_ELASTIC_STORE_5                                   */
/*   6 = XCON_ELASTIC_STORE_6                                   */
/*   7 = XCON_ELASTIC_STORE_7                                   */
/*   0xFF = XCON_ELASTIC_STORE_ALL                              */
/*                                                              */
/* The [duration] parameter is specified as:                    */
/*   DURATION in increments of 1024 system clock cycles,        */
/*   1..0xffff                                                  */
/****************************************************************/
cs_status ten_xcon_es_recenter_measure_duration_in_clock_cycles(cs_uint16 dev_id, 
                                                        ten_xcon_es_num_t es_num,
                                                        cs_uint16         duration)
{
  TEN_XCON_ES_MEASUREMENT_PERIOD_t tmp_xcon_es_measurement_period;
  T41_t *pDev = NULL;
  cs_int16 ret_val = CS_OK;
  cs_uint16 ii;
  volatile cs_reg *tmp_addr;

  /* Parameter Checking */
  if((es_num > XCON_ELASTIC_STORE_7) && (es_num != XCON_ELASTIC_STORE_ALL)) { 
    CS_HNDL_ERROR(dev_id, ETEN_DEV_INVALID_USER_ARG, 
                  ": ten_xcon_es_recenter_measure_duration_in_clock_cycles es_num"); 
    return CS_ERROR; 
  }

  if(duration ==0) { 
    CS_HNDL_ERROR(dev_id, ETEN_DEV_INVALID_USER_ARG, 
                  ": ten_xcon_es_recenter_measure_duration_in_clock_cycles duration"); 
    return CS_ERROR; 
  }

  /* Register setting */
  TEN_DEV_COMMON_VALIDATE(dev_id, pDev, CS_ERROR);
  TEN_DEV_LOCK(dev_id, TEN_ID_XCON);

  for (ii=0; ii<TEN_XCON_ES_COUNT; ii++) {
    if ((es_num == ii) || (es_num == XCON_ELASTIC_STORE_ALL)) {
      tmp_addr =  TEN_XCON_ES_INST_REG_ADDR(pDev, MEASUREMENT_PERIOD, ii);
      tmp_xcon_es_measurement_period.wrd = (cs_uint16) duration;
      TEN_REG_WRITE(tmp_addr, tmp_xcon_es_measurement_period.wrd);
    }
  }

  TEN_DEV_UNLOCK(dev_id, TEN_ID_XCON);

  return (ret_val);
}






/* Bugzilla 27270 Start, Amplitude Recentering, T41 release 5.3  */
/* Local macros to pretty-up error checking */
cs_char8 * ES_OOR_MSG = ": es number out of range.  s/b 0..7";
cs_char8 * ES_INV_MSG = ": es number out of range.  s/b 0..7 or XCON_ELASTIC_STORE_ALL";
#define TEN_XCON_VALIDATE_ES_RANGE if(es_num > XCON_ELASTIC_STORE_7){CS_HNDL_ERROR(dev_id, ETEN_DEV_INVALID_USER_ARG, ES_OOR_MSG); return CS_ERROR;}
#define TEN_XCON_VALIDATE_ES_ALL(M_msg)  if((es_num > XCON_ELASTIC_STORE_7) && (es_num != XCON_ELASTIC_STORE_ALL)) {CS_HNDL_ERROR(dev_id, ETEN_DEV_INVALID_USER_ARG, ES_INV_MSG); return CS_ERROR;}

/********************************************************************/
/* $rtn_hdr_start  XCON ES SETUP AMPL RECENTER 40G T41              */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : XCON                                                */
/* CHIP       : Tenabo                                              */
cs_status ten_xcon_es_setup_amplitude_recenter_40g_t41(cs_uint16 dev_id,
                                                       cs_uint8  module_num,
                                                       cs_uint16 margin_lower,
                                                       cs_uint16 margin_upper,
                                                       cs_uint16 correct_lower,
                                                       cs_uint16 correct_upper,
                                                       cs_uint8  duration,
                                                       cs_uint32 sysclk_freq)
/* INPUTS     : o Device Id                                         */
/*              o Module Number                                     */
/*              o Margin Lower                                      */
/*              o Margin Upper                                      */
/*              o Correction Lower                                  */
/*              o Correction Upper                                  */
/*              o Duration                                          */
/*              o System Clock Frequency                            */
/*                                                                  */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Sets up the specified module's ES registers for recentering      */
/* based on ES amplitude measurements over a specied duration. The  */
/* ES depth is a function of measured amplitude and specified       */
/* margins.                                                         */
/*                                                                  */
/* Disables threshold interrupts and autorecentering in prep for    */
/* forced recentering and measurement phase.                        */
/*                                                                  */
/* The [module_num] parameter is specified as:                      */
/* Module number bit-OR'd with recovery mode, where elastic         */
/* store ID can be                                                  */
/*   0 = TEN_MODULE_A (ES # 0-3)                                    */
/*   1 = TEN_MODULE_B (ES # 4-7)                                    */
/* and (new for 5.5) recovery mode is                               */
/*   0x00 = TEN_XCON_ES_RECENTER_RECOVERY_DFLT (Default):           */
/*     Default is 'none' for backward compatibility.                */
/*   0x40 = TEN_XCON_ES_RECENTER_RECOVERY_AUTO (Recommended):       */
/*     Framer and upper/lower ES violation event handlers kick off  */
/*     recenter, which completes using recenter status polling and  */
/*     system timers.                                               */
/*                                                                  */
/* The [margin_lower] parameter is specified as:                    */
/*   0..0x1fff, the amount of lower margin to reserve for an        */
/*   amplitude recenter                                             */
/*                                                                  */
/* The [margin_upper] parameter is specified as:                    */
/*   0..0x1fff, the amount of upper margin to reserve for an        */
/*   amplitude recenter                                             */
/*                                                                  */
/* The [correct_lower] parameter is specified as:                   */
/*   0..0x01ff, the amount to increase XCON_ES_CIRCUIT_THRESHOLD_   */
/*   LOWER by after computing the new threshold following an        */
/*   amplitude recenter.                                            */
/*                                                                  */
/* The [correct_upper] parameter is specified as:                   */
/*   0..0x01ff, the amount to decrease XCON_ES_CIRCUIT_THRESHOLD_   */
/*   UPPER by after computing the new threshold following an        */
/*   amplitude recenter.                                            */
/*                                                                  */
/* The [duration] parameter is specified as:                        */
/*    1..157~168 milliseconds, depending on sysclk_freq             */
/*    Number of milliseconds to measure depth for Amplitude         */
/*     Recentering.                                                 */
/*                                                                  */
/* The [sysclk_freq] parameter is specified as:                     */
/*   the sysclk frequency in hertz, i.e., 425000000                 */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  return ten_xcon_es_setup_amplitude_recenter_40g_cb(  dev_id, module_num,
                                                       margin_lower,  margin_upper,
                                                       correct_lower, correct_upper,
                                                       duration, sysclk_freq, XCON_ES_UPDATE_CB_TRUE);
}


/********************************************************************/
/* FUNCTION: ten_xcon_es_setup_amplitude_recenter_40g_cb            */
/********************************************************************/
/* This helper function allows control of CB updates.               */
/*   cb_rw = XCON_ES_UPDATE_CB_FALSE: Setup is using data from the  */
/*      control block, so the control block is not updated.         */
/*   cb_rw = XCON_ES_UPDATE_CB_TRUE:  Setup is using data from an   */
/*           API so the control block is updated.                   */
/********************************************************************/
cs_status ten_xcon_es_setup_amplitude_recenter_40g_cb( cs_uint16 dev_id,
                                                       cs_uint8  module_num,
                                                       cs_uint16 margin_lower,
                                                       cs_uint16 margin_upper,
                                                       cs_uint16 correct_lower,
                                                       cs_uint16 correct_upper,
                                                       cs_uint8  duration,
                                                       cs_uint32 sysclk_freq,
                                                       cs_uint16 cb_rw)
{
  cs_uint16 recovery;                /* Release 5.5, Bugzilla 27270 */
  cs_uint8 es_first = 0;
  cs_uint8 es_last  = 7;
  cs_uint8 es_idx   = 0;
  cs_char8 *func    = "ten_xcon_es_setup_amplitude_recenter_40g_t41";
  cs_status stat    = CS_OK;
 
  /* Separate recovery and module_num args from overloaded module_num */
  recovery    = module_num & TEN_XCON_ES_RECENTER_RECOVERY_MASK;
  if (recovery == TEN_XCON_ES_RECENTER_RECOVERY_DFLT) recovery = TEN_XCON_ES_RECENTER_RECOVERY_NONE;
  module_num &= ~TEN_XCON_ES_RECENTER_RECOVERY_MASK;

  /* Get range of affected es. */ 
  if (module_num == TEN_MODULE_A) {
    es_last  = 3;
  }
  else if (module_num == TEN_MODULE_B) {
    es_first = 4;
  }
  else {
    CS_HNDL_ERROR(dev_id, ETEN_MOD_ID_OUT_OF_RANGE, ": %s(es or mod %d), %s", func, module_num, "Invalid module number");
    return CS_ERROR;
  }
  if ( (recovery != TEN_XCON_ES_RECENTER_RECOVERY_NONE) && 
       (recovery != TEN_XCON_ES_RECENTER_RECOVERY_AUTO) ) {
    CS_HNDL_ERROR(dev_id, ETEN_DEV_INVALID_USER_ARG, ": %s(module_num %d), %s 0x%X\n", 
                  func, module_num, "Invalid recovery mode", recovery);
    return CS_ERROR;
  }

  CS_PRINT("%s(%d (recovery=0x%0X)%d %d %d %d %d %d %d cb_rw=%s)\n", func, dev_id,  ((cb_rw) ? recovery : 0xFF), module_num,
                                                   margin_lower,  margin_upper, 
                                                   correct_lower, correct_upper, 
                                                   duration,      sysclk_freq, ((cb_rw) ? "WO" : "RO"));

  /* record values in control block. */
  if (cb_rw == XCON_ES_UPDATE_CB_TRUE) stat |= ten_xcon_es_write_cb_t41(dev_id, module_num*4,
                                   TEN_XCON_ES_RECENTER_AMP_40G | (recovery << 8), /* Rls 5.5 Bugzilla 27270 */
                                   margin_lower,  margin_upper,
                                   correct_lower, correct_upper,
                                   duration,      sysclk_freq);
  if (stat != CS_OK) return stat;       /* <<<<<<< EARLY EXIT, arg validation failure <<<<<<< */

  /* Bugzilla 30990, Datapath reset during reg config to support Amplitude Recenter at marginal sysclock frequencies */
  /* Global ES datapath resets. This reset must be removed bfore exit.   */
  stat |= ten_xcon_glb_pp40g_config_t41(dev_id, module_num,
                                        XCON_GLB_PP40G_CFG_RESET, CS_ENABLE);
  if (stat != CS_OK) return stat;       /* <<<<<<< EARLY EXIT, arg validation failure <<<<<<< */

  for (es_idx = es_first; es_idx <= es_last; es_idx++) {
    stat |= ten_xcon_es_setup_amplitude_recenter_no_fpa_common(dev_id, es_idx,
                                                       margin_lower,  margin_upper,
                                                       correct_lower, correct_upper,
                                                       duration,      sysclk_freq);
  }

  /* Disable 40g autorecenter triggers and 40G tx align. Works for ckt and pkt.  */
  stat |= ten_xcon_glb_pp40g_config_t41(dev_id, module_num,
                                        XCON_GLB_PP40G_CFG_TX_ALGN_EN,
                                        CS_DISABLE);
  stat |= ten_xcon_glb_pp40g_config_t41(dev_id, module_num,
                                        XCON_GLB_PP40G_CFG_LF_DIS,
                                        CS_ENABLE);
  stat |= ten_xcon_glb_pp40g_config_t41(dev_id, module_num,
                                        XCON_GLB_PP40G_CFG_RF_DIS,
                                        CS_ENABLE);
  stat |= ten_xcon_glb_pp40g_config_t41(dev_id, module_num,
                                        XCON_GLB_PP40G_CFG_IDLE_DIS,
                                        CS_ENABLE);

  /* Bugzilla 30990, Datapath reset during reg config to support Amplitude Recenter at  */
  /* marginal sysclock frequencies. Release ES datapath resets.                         */
  ten_xcon_datapath_reset_quick(dev_id, CS_RESET_DEASSERT);
  for (es_idx = es_first; es_idx <= es_last; es_idx++) {
    /* Note, this was done at end of es config by ...es_setup_..._no_fpa_common for     */
    /* 10G datapaths. For 40g configs, it should be done after XCON_GLB_RESET, so here  */
    /* it is again.                                                                     */
    ten_xcon_es_datapath_reset_quick(dev_id, es_idx, CS_RESET_DEASSERT);
  }
  ten_xcon_glb_pp40g_config_t41(dev_id, module_num, XCON_GLB_PP40G_CFG_RESET, CS_DISABLE);

  return (stat);
}

/********************************************************************/
/* $rtn_hdr_start  XCON ES SETUP AMPL RECENTER T41                  */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : XCON                                                */
/* CHIP       : Tenabo                                              */
cs_status ten_xcon_es_setup_amplitude_recenter_t41(cs_uint16 dev_id,
                                                   ten_xcon_es_num_t es_num,
                                                   cs_uint16 margin_lower,
                                                   cs_uint16 margin_upper,
                                                   cs_uint16 correct_lower,
                                                   cs_uint16 correct_upper,
                                                   cs_uint8  duration,
                                                   cs_uint32 sysclk_freq)
/* INPUTS     : o Device Id                                         */
/*              o Elastic Store Id                                  */
/*              o Margin Lower                                      */
/*              o Margin Upper                                      */
/*              o Correction Lower                                  */
/*              o Correction Upper                                  */
/*              o Duration                                          */
/*              o System Clock Frequency                            */
/*                                                                  */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Sets up the specified module's ES registers for recentering      */
/* based on ES amplitude measurements over a specied duration. The  */
/* ES depth is a function of measured amplitude and specified       */
/* margins.                                                         */
/*                                                                  */
/* Disables threshold interrupts and autorecentering in prep for    */
/* forced recentering and measurement phase.                        */
/*                                                                  */
/* The [es_num] parameter is specified as:                          */
/* Elastic store ID bit-OR'd with recovery mode, where elastic      */
/* store ID can be                                                  */
/*   0 = XCON_ELASTIC_STORE_0                                       */
/*   1 = XCON_ELASTIC_STORE_1                                       */
/*   2 = XCON_ELASTIC_STORE_2                                       */
/*   3 = XCON_ELASTIC_STORE_3                                       */
/*   4 = XCON_ELASTIC_STORE_4                                       */
/*   5 = XCON_ELASTIC_STORE_5                                       */
/*   6 = XCON_ELASTIC_STORE_6                                       */
/*   7 = XCON_ELASTIC_STORE_7                                       */
/* and (new for 5.5) recovery mode is                               */
/*   0x00 = TEN_XCON_ES_RECENTER_RECOVERY_DFLT (Default):           */
/*     Default is 'none' for backward compatibility.                */
/*   0x40 = TEN_XCON_ES_RECENTER_RECOVERY_AUTO (Recommended):       */
/*     Framer and upper/lower ES violation event handlers kick off  */
/*     recenter, which completes using recenter status polling and  */
/*     system timers.                                               */
/*                                                                  */
/* The [margin_lower] parameter is specified as:                    */
/*   0..0x1fff, the amount of lower margin to reserve for an        */
/*   amplitude recenter                                             */
/*                                                                  */
/* The [margin_upper] parameter is specified as:                    */
/*   0..0x1fff, the amount of upper margin to reserve for an        */
/*   amplitude recenter                                             */
/*                                                                  */
/* The [correct_lower] parameter is specified as:                   */
/*   0..0x01ff, the amount to increase XCON_ES_CIRCUIT_THRESHOLD_   */
/*   LOWER by after computing the new threshold following an        */
/*   amplitude recenter.                                            */
/*                                                                  */
/* The [correct_upper] parameter is specified as:                   */
/*   0..0x01ff, the amount to decrease XCON_ES_CIRCUIT_THRESHOLD_   */
/*   UPPER by after computing the new threshold following an        */
/*   amplitude recenter.                                            */
/*                                                                  */
/* The [duration] parameter is specified as:                        */
/*    1..157~168 milliseconds, depending on sysclk_freq             */
/*    Number of milliseconds to measure depth for Amplitude         */
/*     Recentering.                                                 */
/*                                                                  */
/* The [sysclk_freq] parameter is specified as:                     */
/*   the sysclk frequency in hertz, i.e., 425000000                 */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  return ten_xcon_es_setup_amplitude_recenter_10g_cb(dev_id, es_num,
                                                   margin_lower,  margin_upper,
                                                   correct_lower, correct_upper,
                                                   duration, sysclk_freq, XCON_ES_UPDATE_CB_TRUE);
}
/********************************************************************/
/* FUNCTION: ten_xcon_es_setup_amplitude_recenter_10g_cb            */
/********************************************************************/
/* This helper function allows control of CB updates.               */
/*   cb_rw = XCON_ES_UPDATE_CB_FALSE: Setup is using data from the  */
/*      control block, so the control block is not updated.         */
/*   cb_rw = XCON_ES_UPDATE_CB_TRUE:  Setup is using data from an   */
/*           API so the control block is updated.                   */
/********************************************************************/
cs_status ten_xcon_es_setup_amplitude_recenter_10g_cb(cs_uint16 dev_id,
                                                   ten_xcon_es_num_t es_num,
                                                   cs_uint16 margin_lower,
                                                   cs_uint16 margin_upper,
                                                   cs_uint16 correct_lower,
                                                   cs_uint16 correct_upper,
                                                   cs_uint8  duration,
                                                   cs_uint32 sysclk_freq,
                                                   cs_uint16 cb_rw)
{
  cs_uint16 recovery;
  cs_status stat = CS_OK;
  cs_char8 *func = "ten_xcon_es_setup_amplitude_recenter_10g_cb";

  /* Separate recovery and es_num args from overloaded es_num */
  recovery = es_num & TEN_XCON_ES_RECENTER_RECOVERY_MASK;
  if (recovery == TEN_XCON_ES_RECENTER_RECOVERY_DFLT) recovery = TEN_XCON_ES_RECENTER_RECOVERY_NONE;
  es_num &= ~TEN_XCON_ES_RECENTER_RECOVERY_MASK;

  TEN_XCON_VALIDATE_ES_RANGE;
  if ( (recovery != TEN_XCON_ES_RECENTER_RECOVERY_NONE) && 
       (recovery != TEN_XCON_ES_RECENTER_RECOVERY_AUTO) ) {
    CS_HNDL_ERROR(dev_id, ETEN_DEV_INVALID_USER_ARG, ": %s(es %d), %s 0x%X\n", 
                  func, es_num, "Invalid recovery mode", recovery);
    return CS_ERROR;
  }

  CS_PRINT("%s(%d (recovery=0x%0X)%d %d %d %d %d %d %d cb_rw=%s)\n", func, dev_id,
                                                   ((cb_rw) ? recovery : 0xFF), es_num,
                                                   margin_lower, margin_upper, 
                                                   correct_lower, correct_upper, 
                                                   duration, sysclk_freq, ((cb_rw) ? "WO" : "RO"));
  /* record values in control block. */
  if (cb_rw == XCON_ES_UPDATE_CB_TRUE) stat |= ten_xcon_es_write_cb_t41(dev_id, es_num, 
                                   TEN_XCON_ES_RECENTER_AMP_10G | (recovery << 8), /* Rls 5.5 Bugzilla 27270 */
                                   margin_lower,  margin_upper,
                                   correct_lower, correct_upper,
                                   duration,      sysclk_freq);
  if (stat != CS_OK) return stat;       /* <<<<<<< EARLY EXIT, arg validation failure <<<<<<< */
  return ten_xcon_es_setup_amplitude_recenter_no_fpa_common(dev_id, es_num,
                                                     margin_lower, margin_upper,
                                                     correct_lower, correct_upper,
                                                     duration, sysclk_freq);
}

/********************************************************************/
/* Internal helper function:                                        */
/*         ten_xcon_es_setup_amplitude_recenter_no_fpa_common()     */
/********************************************************************/
/* INPUTS     : o Device Id                                         */
/*              o Elastic Store Id                                  */
/*              o Margin Lower                                      */
/*              o Margin Upper                                      */
/*              o Correction Lower                                  */
/*              o Correction Upper                                  */
/*              o Duration                                          */
/*              o System Clock Frequency                            */
/*                                                                  */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/*                                                                  */
/* DESCRIPTION:                                                     */
/* See ten_xcon_es_setup_amplitude_recenter_t41()                   */
/********************************************************************/
cs_status ten_xcon_es_setup_amplitude_recenter_no_fpa_common(cs_uint16 dev_id,
                                                      ten_xcon_es_num_t es_num,
                                                      cs_uint16 margin_lower,
                                                      cs_uint16 margin_upper,
                                                      cs_uint16 correct_lower,
                                                      cs_uint16 correct_upper,
                                                      cs_uint8  duration,
                                                      cs_uint32 sysclk_freq)
{
  cs_status stat = CS_OK;
  const cs_char8 *func = "ten_xcon_es_setup_amplitude_recenter_no_fpa_common";

  if (!ten_dev_is_t41(dev_id) ) {
    CS_HNDL_ERROR(dev_id, ETEN_MOD_INVALID_OP, ": %s(es %d), %s", func, 
                  es_num, "This device does not support this function\n");
    return CS_ERROR;
  }

  /* assert reset.  Always release before exiting this function */
  /* Bugzilla 30990, Datapath reset during reg config to support Amplitude Recenter at marginal */
  /* sysclock frequencies                                                                       */
  if (ten_xcon_es_datapath_reset_quick(dev_id, es_num, CS_RESET_ASSERT) == CS_ERROR) {
    CS_HNDL_ERROR(dev_id, ETEN_DRVR_UNEXPECTED_RESULT, ": %s(es %d), %s", func, 
                  es_num, "coudn't reset elastic store datapath\n");
    return CS_ERROR;
  }

  stat |= ten_xcon_es_setup_amplitude_recenter_common(dev_id, es_num);

  stat |= ten_xcon_set_circuit_threshold_level_t41(dev_id, es_num, XCON_ES_RECENTER_AMPLITUDE,
                                                   XCON_ES_MARGIN_LOWER, -1, margin_lower); 
  stat |= ten_xcon_set_circuit_threshold_level_t41(dev_id, es_num, XCON_ES_RECENTER_AMPLITUDE,
                                                   XCON_ES_MARGIN_UPPER, -1, margin_upper); 

  stat |= ten_xcon_es_correction_lower(dev_id, es_num, correct_lower); 
  stat |= ten_xcon_es_correction_upper(dev_id, es_num, correct_upper);

  stat |= ten_xcon_es_recenter_measure_period_t41(dev_id, es_num, duration, sysclk_freq); 

  /* mfp mode should already be set correctly                          */
  /* stat |= ten_xcon_es_set_config_mfp_mode(dev_id, es_num, XCON_FP); */

  /* turn off fpa features */
  stat |= ten_xcon_enable_tx_algn_t41(dev_id, es_num, CS_DISABLE);
  stat |= ten_xcon_es_recenter_enables_t41(dev_id, es_num, XCON_ES_RECENTER_FP_ALIGN_EN,     CS_DISABLE);
  stat |= ten_xcon_es_recenter_enables_t41(dev_id, es_num, XCON_ES_RECENTER_STATIC_DEPTH_EN, CS_DISABLE); 
  stat |= ten_xcon_es_recenter_enables_t41(dev_id, es_num, XCON_ES_RECENTER_TX_DRAIN_EN,     CS_DISABLE); 
  /* Bugzilla 30990, Datapath reset during reg config to support Amplitude Recenter at marginal */
  /* sysclock frequencies                                                                       */
  ten_xcon_es_datapath_reset_quick(dev_id, es_num, CS_RESET_DEASSERT);

  return (stat);
}

/********************************************************************/
/* $rtn_hdr_start  XCON ES SETUP AMPL RECENTER WITH FPA 40G T41     */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : XCON                                                */
/* CHIP       : Tenabo                                              */
cs_status ten_xcon_es_setup_amplitude_recenter_with_fpa_40g_t41(cs_uint16 dev_id,
                                                                cs_uint8  module_num,
                                                                cs_uint16 static_depth,
                                                                cs_uint16 circuit_th_lower,
                                                                cs_uint16 circuit_th_upper)
/* INPUTS     : o Device Id                                         */
/*              o Module Number                                     */
/*              o Static Depth                                      */
/*              o Circuit Threshold Lower                           */
/*              o Circuit Threshold Upper                           */
/*                                                                  */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Sets up ES registers for amplitude recentering with frame pulse  */
/* alignment. The specified depth and circuit thresholds are used   */
/* instead of their calculated counterparts.                        */
/*                                                                  */
/* Disables threshold interrupts and autorecentering in prep for    */
/* forced recentering and alignment phase.                          */
/*                                                                  */
/* The [module_num] parameter is specified as:                      */
/* Module number bit-OR'd with recovery mode, where elastic         */
/* store ID can be                                                  */
/*   0 = TEN_MODULE_A (ES # 0-3)                                    */
/*   1 = TEN_MODULE_B (ES # 4-7)                                    */
/* and (new for 5.5) recovery mode is                               */
/*   0x00 = TEN_XCON_ES_RECENTER_RECOVERY_DFLT (Default):           */
/*     Default is 'none' for backward compatibility.                */
/*   0x40 = TEN_XCON_ES_RECENTER_RECOVERY_AUTO (Recommended):       */
/*     Framer and upper/lower ES violation event handlers kick off  */
/*     recenter, which completes using recenter status polling and  */
/*     system timers.                                               */
/*                                                                  */
/* The [static_depth] parameter is specified as:                    */
/*    0..0x1fff, static_depth is used for an amplitude recenter     */
/*    instead of a calculated depth.                                */
/*                                                                  */
/* The [circuit_th_lower] parameter is specified as:                */
/*   1..0x1fff, Minimum desired amount of data (in units of 4       */
/*   bytes) in the FIFO. Note: LEVEL must be smaller than           */
/*   IML_THRESH but no less than 1.                                 */
/*                                                                  */
/* The [circuit_th_upper] parameter is specified as:                */
/*   1..0x1ffe, Maximum desired amount of data (in units of 4       */
/*   bytes) in the FIFO. Note: LEVEL must be larger than            */
/*   IML_THRESH but no larger than 8190.                            */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  return ten_xcon_es_setup_amplitude_recenter_with_fpa_40g_cb(dev_id, module_num,
                                                              static_depth, circuit_th_lower,
                                                              circuit_th_upper, XCON_ES_UPDATE_CB_TRUE);
}

/********************************************************************/
/* FUNCTION: ten_xcon_es_setup_amplitude_recenter_with_fpa_40g_cb   */
/********************************************************************/
/* This helper function allows control of CB updates.               */
/*   cb_rw = XCON_ES_UPDATE_CB_FALSE: Setup is using data from the  */
/*      control block, so the control block is not updated.         */
/*   cb_rw = XCON_ES_UPDATE_CB_TRUE:  Setup is using data from an   */
/*           API so the control block is updated.                   */
/********************************************************************/
cs_status ten_xcon_es_setup_amplitude_recenter_with_fpa_40g_cb(cs_uint16 dev_id,
                                                                cs_uint8  module_num,
                                                                cs_uint16 static_depth,
                                                                cs_uint16 circuit_th_lower,
                                                                cs_uint16 circuit_th_upper,
                                                                cs_uint16 cb_rw)
{
  cs_uint16 recovery;                /* Release 5.5, Bugzilla 27270 */
  cs_uint8 es_first = 0;
  cs_uint8 es_last  = 7;
  cs_uint8 es_idx   = 0;
  cs_char8 *func    = "ten_xcon_es_setup_amplitude_recenter_with_fpa_40g_cb";
  cs_status stat    = CS_OK;
 
  /* Separate recovery and module_num args from overloaded module_num */
  recovery    = module_num & TEN_XCON_ES_RECENTER_RECOVERY_MASK;
  if (recovery == TEN_XCON_ES_RECENTER_RECOVERY_DFLT) recovery = TEN_XCON_ES_RECENTER_RECOVERY_NONE;
  module_num &= ~TEN_XCON_ES_RECENTER_RECOVERY_MASK;

  /* Get range of affected es. */ 
  if (module_num == TEN_MODULE_A) {
    es_last  = 3;
  }
  else if (module_num == TEN_MODULE_B) {
    es_first = 4;
  }
  else {
    CS_HNDL_ERROR(dev_id, ETEN_MOD_ID_OUT_OF_RANGE, ": %s(es or mod %d), %s", func, module_num, "Invalid module number");
    return CS_ERROR;
  }
  if ( (recovery != TEN_XCON_ES_RECENTER_RECOVERY_NONE) && 
       (recovery != TEN_XCON_ES_RECENTER_RECOVERY_AUTO) ) {
    CS_HNDL_ERROR(dev_id, ETEN_DEV_INVALID_USER_ARG, ": %s(module_num %d), %s 0x%X\n", 
                  func, module_num, "Invalid recovery mode", recovery);
    return CS_ERROR;
  }

  CS_PRINT("%s(%d (recovery=0x%0X)%d %d %d %d cb_rw=%s)\n", func, dev_id, ((cb_rw) ? recovery : 0xFF), module_num, static_depth,
                                                            circuit_th_lower, circuit_th_upper, ((cb_rw) ? "WO" : "RO"));

  /* record values in control block. */
  if (cb_rw == XCON_ES_UPDATE_CB_TRUE) stat |= ten_xcon_es_write_cb_t41(dev_id, module_num*4,
                                   TEN_XCON_ES_RECENTER_FPA_40G | (recovery << 8), /* Rls 5.5 Bugzilla 27270 */
                                   static_depth, circuit_th_lower, circuit_th_upper, 0,0,0);
  if (stat != CS_OK) return stat;       /* <<<<<<< EARLY EXIT, arg validation failure <<<<<<< */

  /* Bugzilla 30990, Datapath reset during reg config to support Amplitude Recenter at marginal sysclock frequencies */
  /* Global ES datapath resets. These resets must be removed bfore exit.   */
  stat |= ten_xcon_glb_pp40g_config_t41(dev_id, module_num,
                                        XCON_GLB_PP40G_CFG_RESET,
                                        CS_ENABLE);
  if (stat != CS_OK) return stat;       /* <<<<<<< EARLY EXIT, arg validation failure <<<<<<< */

  for (es_idx = es_first; es_idx <= es_last; es_idx++) {
    /* Set common registers */
    stat |= ten_xcon_es_setup_amplitude_recenter_with_fpa_common(dev_id,   es_idx, static_depth,
                                                                 circuit_th_lower, circuit_th_upper);
    /* turn off 10g stream tx_algn, it's handled monolithically for 40G) */
    stat |= ten_xcon_enable_tx_algn_t41(dev_id, es_idx, CS_DISABLE);
  }

  /* Enable 40G tx align. Works for ckt and pkt. */
  stat |= ten_xcon_glb_pp40g_config_t41(dev_id, module_num,
                                        XCON_GLB_PP40G_CFG_TX_ALGN_EN,
                                        CS_ENABLE);

  /* Disable 40g autorecenter triggers. Works for ckt and pkt. */
  stat |= ten_xcon_glb_pp40g_config_t41(dev_id, module_num,
                                        XCON_GLB_PP40G_CFG_LF_DIS,
                                        CS_ENABLE);
  stat |= ten_xcon_glb_pp40g_config_t41(dev_id, module_num,
                                        XCON_GLB_PP40G_CFG_RF_DIS,
                                        CS_ENABLE);
  stat |= ten_xcon_glb_pp40g_config_t41(dev_id, module_num,
                                        XCON_GLB_PP40G_CFG_IDLE_DIS,
                                        CS_ENABLE);

  /* Bugzilla 30990, Datapath reset during reg config to support Amplitude Recenter at  */
  /* marginal sysclock frequencies. Release ES datapath resets.                         */
  ten_xcon_datapath_reset_quick(dev_id, CS_RESET_DEASSERT);
  for (es_idx = es_first; es_idx <= es_last; es_idx++) {
    /* Note, this was done at end of es config by ...es_setup_..._with_fpa_common for   */
    /* 10G datapaths. For 40g configs, it should be done after XCON_GLB_RESET, so here  */
    /* it is again.                                                                     */
    ten_xcon_es_datapath_reset_quick(dev_id, es_idx, CS_RESET_DEASSERT);
  }
  ten_xcon_glb_pp40g_config_t41(dev_id, module_num, XCON_GLB_PP40G_CFG_RESET, CS_DISABLE);

  return (stat);
}

/********************************************************************/
/* $rtn_hdr_start  XCON ES SETUP AMPL RECENTER WITH FPA T41         */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : XCON                                                */
/* CHIP       : Tenabo                                              */
cs_status ten_xcon_es_setup_amplitude_recenter_with_fpa_t41(cs_uint16 dev_id,
                                                            ten_xcon_es_num_t es_num,
                                                            cs_uint16 static_depth,
                                                            cs_uint16 circuit_th_lower,
                                                            cs_uint16 circuit_th_upper)
/* INPUTS     : o Device Id                                         */
/*              o Elastic Store Id                                  */
/*              o Static Depth                                      */
/*              o Circuit Threshold Lower                           */
/*              o Circuit Threshold Upper                           */
/*                                                                  */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Sets up ES registers for amplitude recentering with frame pulse  */
/* alignment. The specified depth and circuit thresholds are used   */
/* instead of their calculated counterparts.                        */
/*                                                                  */
/* Disables threshold interrupts and autorecentering in prep for    */
/* forced recentering and alignment phase.                          */
/*                                                                  */
/* The [es_num] parameter is specified as:                          */
/* Elastic store ID bit-OR'd with recovery mode, where elastic      */
/* store ID can be                                                  */
/*   0 = XCON_ELASTIC_STORE_0                                       */
/*   1 = XCON_ELASTIC_STORE_1                                       */
/*   2 = XCON_ELASTIC_STORE_2                                       */
/*   3 = XCON_ELASTIC_STORE_3                                       */
/*   4 = XCON_ELASTIC_STORE_4                                       */
/*   5 = XCON_ELASTIC_STORE_5                                       */
/*   6 = XCON_ELASTIC_STORE_6                                       */
/*   7 = XCON_ELASTIC_STORE_7                                       */
/* and (new for 5.5) recovery mode is                               */
/*   0x00 = TEN_XCON_ES_RECENTER_RECOVERY_DFLT (Default):           */
/*     Default is 'none' for backward compatibility.                */
/*   0x40 = TEN_XCON_ES_RECENTER_RECOVERY_AUTO (Recommended):       */
/*     Framer and upper/lower ES violation event handlers kick off  */
/*     recenter, which completes using recenter status polling and  */
/*     system timers.                                               */
/*                                                                  */
/* The [static_depth] parameter is specified as:                    */
/*    0..0x1fff, static_depth is used for an amplitude recenter     */
/*    instead of a calculated depth.                                */
/*                                                                  */
/* The [circuit_th_lower] parameter is specified as:                */
/*   1..0x1fff, Minimum desired amount of data (in units of 4       */
/*   bytes) in the FIFO. Note: LEVEL must be smaller than           */
/*   IML_THRESH but no less than 1.                                 */
/*                                                                  */
/* The [circuit_th_upper] parameter is specified as:                */
/*   1..0x1ffe, Maximum desired amount of data (in units of 4       */
/*   bytes) in the FIFO. Note: LEVEL must be larger than            */
/*   IML_THRESH but no larger than 8190.                            */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  return ten_xcon_es_setup_amplitude_recenter_with_fpa_10g_cb(dev_id, es_num,
                                                              static_depth, circuit_th_lower,
                                                              circuit_th_upper, XCON_ES_UPDATE_CB_TRUE);
}

/********************************************************************/
/* FUNCTION: ten_xcon_es_setup_amplitude_recenter_with_fpa_10g_cb   */
/********************************************************************/
/* This helper function allows control of CB updates.               */
/*   cb_rw = XCON_ES_UPDATE_CB_FALSE: Setup is using data from the  */
/*      control block, so the control block is not updated.         */
/*   cb_rw = XCON_ES_UPDATE_CB_TRUE:  Setup is using data from an   */
/*           API so the control block is updated.                   */
/********************************************************************/
cs_status ten_xcon_es_setup_amplitude_recenter_with_fpa_10g_cb(cs_uint16 dev_id,
                                                            ten_xcon_es_num_t es_num,
                                                            cs_uint16 static_depth,
                                                            cs_uint16 circuit_th_lower,
                                                            cs_uint16 circuit_th_upper,
                                                            cs_uint16 cb_rw)
{
  cs_uint16 recovery;                /* Release 5.5, Bugzilla 27270 */
  cs_status  stat = CS_OK;
  cs_char8  *func = "ten_xcon_es_setup_amplitude_recenter_with_fpa_10g_cb";

  /* Separate recovery and es_num args from overloaded es_num */
  recovery = es_num & TEN_XCON_ES_RECENTER_RECOVERY_MASK;
  if (recovery == TEN_XCON_ES_RECENTER_RECOVERY_DFLT) recovery = TEN_XCON_ES_RECENTER_RECOVERY_NONE;
  es_num &= ~TEN_XCON_ES_RECENTER_RECOVERY_MASK;

  TEN_XCON_VALIDATE_ES_RANGE;
  if ( (recovery != TEN_XCON_ES_RECENTER_RECOVERY_NONE) && 
       (recovery != TEN_XCON_ES_RECENTER_RECOVERY_AUTO) ) {
    CS_HNDL_ERROR(dev_id, ETEN_DEV_INVALID_USER_ARG, ": %s(es %d), %s 0x%X\n", 
                  func, es_num, "Invalid recovery mode", recovery);
    return CS_ERROR;
  }

  CS_PRINT("%s(%d (recovery=0x%0X)%d %d %d %d cb_rw=%s)\n", func, dev_id, ((cb_rw) ? recovery : 0xFF), es_num, static_depth,
                                                        circuit_th_lower, circuit_th_upper, ((cb_rw) ? "WO" : "RO"));

  /* record values in control block. */
  if (cb_rw == XCON_ES_UPDATE_CB_TRUE) stat |= ten_xcon_es_write_cb_t41(dev_id, es_num, 
                                   TEN_XCON_ES_RECENTER_FPA_10G | (recovery << 8), /* Rls 5.5 Bugzilla 27270 */
                                   static_depth, circuit_th_lower, circuit_th_upper, 0,0,0);
  if (stat != CS_OK) return stat;       /* <<<<<<< EARLY EXIT, arg validation failure <<<<<<< */
  
  return ten_xcon_es_setup_amplitude_recenter_with_fpa_common(dev_id, es_num, static_depth,
                                                              circuit_th_lower, circuit_th_upper);
}


/********************************************************************/
/* Internal helper function:                                        */
/*         ten_xcon_es_setup_amplitude_recenter_with_fpa_common()   */
/********************************************************************/
/* INPUTS     : o Device Id                                         */
/*              o Elastic Store Id                                  */
/*              o Static Depth                                      */
/*              o Circuit Threshold Lower                           */
/*              o Circuit Threshold Upper                           */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/*                                                                  */
/* DESCRIPTION:                                                     */
/* See ten_xcon_es_setup_amplitude_recenter_with_fpa_t41()          */
/********************************************************************/
cs_status ten_xcon_es_setup_amplitude_recenter_with_fpa_common(cs_uint16 dev_id,
                                                            ten_xcon_es_num_t es_num,
                                                            cs_uint16 static_depth,
                                                            cs_uint16 circuit_th_lower,
                                                            cs_uint16 circuit_th_upper)
{
  cs_status stat = CS_OK;
  const cs_char8 *func = "ten_xcon_es_setup_amplitude_recenter_with_fpa_common";

  if (!ten_dev_is_t41(dev_id) ) {
    CS_HNDL_ERROR(dev_id, ETEN_MOD_INVALID_OP, ": %s(es %d), %s",  func, 
                  es_num, "This device does not support this function\n");
    return CS_ERROR;
  }

  /* Bugzilla 30990, Datapath reset during reg config to support Amplitude Recenter at marginal sysclock frequencies */
  /* assert reset.  Always release before exiting this function */
  if (ten_xcon_es_datapath_reset_quick(dev_id, es_num, CS_RESET_ASSERT) == CS_ERROR) {
    CS_HNDL_ERROR(dev_id, ETEN_DRVR_UNEXPECTED_RESULT, ": %s(es %d), %s", func,
                  es_num, "coudn't reset elastic store datapath\n");
    return CS_ERROR;
  }
  stat |= ten_xcon_es_recenter_measure_duration_in_clock_cycles(dev_id, es_num, 2);
  stat |= ten_xcon_es_setup_amplitude_recenter_common(dev_id, es_num);
  stat |= ten_xcon_es_set_config_mfp_mode(dev_id, es_num, XCON_FP);
  stat |= ten_xcon_enable_tx_algn_t41(dev_id, es_num, CS_ENABLE);
  stat |= ten_xcon_es_recenter_enables_t41(dev_id, es_num, XCON_ES_RECENTER_FP_ALIGN_EN, CS_ENABLE); 
  stat |= ten_xcon_es_static_depth(dev_id, es_num, static_depth); 
  stat |= ten_xcon_es_recenter_enables_t41(dev_id, es_num, XCON_ES_RECENTER_STATIC_DEPTH_EN, CS_ENABLE);

  /* for 10g only. When called by 40G function, XCON_ES_RECENTER_TX_DRAIN_EN must be disabled */
  stat |= ten_xcon_es_recenter_enables_t41(dev_id, es_num, XCON_ES_RECENTER_TX_DRAIN_EN, CS_ENABLE); 

  /* Bugzilla 30990, Datapath reset during reg config to support Amplitude Recenter at marginal sysclock frequencies */
  ten_xcon_es_datapath_reset_quick(dev_id, es_num, CS_RESET_DEASSERT);
  return (stat);
}


/********************************************************************/
/* Internal helper function:                                        */
/*         ten_xcon_es_setup_amplitude_recenter_common()            */
/********************************************************************/
/* INPUTS     : o Device Id                                         */
/*              o Elastic Store Id                                  */
/*                                                                  */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Sets up common ES registers for amplitude recentering using      */
/* measured amplitude or frame pulse alignment.                     */
/*                                                                  */
/* Note: Circuit thresholds set here are starting points which are  */
/* autonomously overwritten during the amplitude measurement phase. */
/* For FPA only, the circuit thresholds must be set to the desired  */
/* levels AFTER recentering is complete.                            */
/********************************************************************/
cs_status ten_xcon_es_setup_amplitude_recenter_common(cs_uint16 dev_id,
                                              ten_xcon_es_num_t es_num)
{
  TEN_XCON_ES_CONFIG_t config;
  cs_status stat = CS_OK;

  config.wrd = 0xFFFF;

  /* Bugzilla 30990, New validation. Amplitude recenter and ES Packet Mode are not compatible */
  if (ten_xcon_es_get_pkt_mode(dev_id, es_num) ) {
    CS_HNDL_ERROR(dev_id, ETEN_DEV_INVALID_USER_ARG, ": %s(es_num %d), %s", 
         "ten_xcon_es_setup_amplitude_recenter_common", es_num, "ES is in Packet Mode");
    return CS_ERROR;
  }

  /* disable interrupts and autorecenter. Violation interrupts must be enabled after recentering */
  config.bf.PKT_MODE            = CS_DISABLE;
  config.bf.AUTO_RECENTER_LOWER = CS_DISABLE;
  config.bf.AUTO_RECENTER_UPPER = CS_DISABLE;
  config.bf.AUTO_CENTER         = CS_DISABLE;
  stat |= ten_xcon_es_config_multi_t41(dev_id, es_num, ~config.wrd, config.wrd);
  stat |= ten_xcon_es_recenter_enables_t41(dev_id, es_num, XCON_ES_RECENTER_UPPER_VIOLATION_EN, CS_DISABLE); 
  stat |= ten_xcon_es_recenter_enables_t41(dev_id, es_num, XCON_ES_RECENTER_LOWER_VIOLATION_EN, CS_DISABLE); 

  /* IML threshold, used during setup */
  stat |= ten_xcon_set_circuit_threshold_level_t41(dev_id, es_num, XCON_ES_RECENTER_AMPLITUDE,
                                                   XCON_ES_IML_THRESH, -1, 4000 );

  /* these are starting points which will be autonomously overwritten during recenter  */
  stat |= ten_xcon_set_circuit_threshold_level_t41(dev_id, es_num, XCON_ES_RECENTER_AMPLITUDE,
                                                   XCON_ES_CIRCUIT_THRESHOLD_LOWER, -1,
                                                   TEN_XCON_ES_CIRCUIT_THRESHOLD_LOWER_dft);
  stat |= ten_xcon_set_circuit_threshold_level_t41(dev_id, es_num, XCON_ES_RECENTER_AMPLITUDE,
                                                   XCON_ES_CIRCUIT_THRESHOLD_UPPER, -1,
                                                   TEN_XCON_ES_CIRCUIT_THRESHOLD_UPPER_dft); 
  stat |= ten_xcon_es_recenter_enables_t41(dev_id, es_num, XCON_ES_RECENTER_AMPLITUDE_RECENTER_EN, CS_ENABLE); 
  stat |= ten_xcon_es_recenter_enables_t41(dev_id, es_num, XCON_ES_RECENTER_ACCUMULATE_EN,         CS_DISABLE); 

  return (stat);
}


/********************************************************************/
/* $rtn_hdr_start  XCON ES CHECK AMPL RECENTER 40G T41              */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : XCON                                                */
/* CHIP       : Tenabo                                              */
cs_status ten_xcon_es_check_amplitude_recenter_40g_t41(cs_uint16 dev_id,
                                                   cs_uint8  module_num)
/* INPUTS     : o Device Id                                         */
/*              o Module Number                                     */
/*                                                                  */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK if ready, 1 - 0xFF if not, or CS_ERROR        */
/* DESCRIPTION:                                                     */
/* For each channel, reads XCON ES registers for recentering to     */
/* determine if the measurement period has ended and recentering    */
/* config is complete. In the returned value, the bit corresponding */
/* to each specified channel is set for channels that are not       */
/* complete.                                                        */
/*                                                                  */
/* The [module_num] parameter is specified as:                      */
/*   0 = TEN_MODULE_A (ES # 0-3)                                    */
/*   1 = TEN_MODULE_B (ES # 4-7)                                    */
/*   2 = TEN_MODULE_A_AND_B (ES # 0-7)                              */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  cs_uint8 es_first = 0;
  cs_uint8 es_last  = 7;
  cs_uint8 es_idx   = 0;
  cs_uint32 ret_val = (cs_uint32) CS_OK;
  cs_status esrv    = 0;
  cs_char8 *func    = "ten_xcon_es_check_amplitude_recenter_40g_t41";
 
  /* Get range of affected es. */ 
  if (module_num == TEN_MODULE_A) {
    es_last  = 3;
  }
  else if (module_num == TEN_MODULE_B) {
    es_first = 4;
  }
  else if (module_num == TEN_MODULE_A_AND_B) {
  }
  else {
    CS_HNDL_ERROR(dev_id, ETEN_MOD_ID_OUT_OF_RANGE, ": %s(es or mod %d), %s", func, module_num, "Invalid module number");
    return CS_ERROR;
  }

  for (es_idx = es_first; es_idx <= es_last; es_idx++) {
    esrv = ten_xcon_es_check_amplitude_recenter_t41( dev_id, es_idx);
    if ( esrv == CS_ERROR ) {
      CS_HNDL_ERROR(dev_id, ETEN_DRVR_UNEXPECTED_RESULT, ": %s(es or mod %d), %s", func, module_num, "ten_xcon_es_check_amplitude_recenter_t41");
      return CS_ERROR;
    }
    else if ( esrv != CS_OK) {  /* this channel is not finished */
      ret_val |= (esrv << es_idx); 
    }
  }
  return ( (cs_status) ret_val);
}

/********************************************************************/
/* $rtn_hdr_start  XCON ES CHECK AMPL RECENTER T41                  */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : XCON                                                */
/* CHIP       : Tenabo                                              */
cs_status ten_xcon_es_check_amplitude_recenter_t41(cs_uint16 dev_id,
                                                   ten_xcon_es_num_t es_num)
/* INPUTS     : o Device Id                                         */
/*              o Elastic Store Id                                  */
/*                                                                  */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK if ready, 1 if not ready, or CS_ERROR         */
/* DESCRIPTION:                                                     */
/* Reads ES registers for recentering to determine if the           */
/* measurement period has ended and recentering config is complete. */
/*                                                                  */
/* The [es_num] parameter is specified as:                          */
/*   0 = XCON_ELASTIC_STORE_0                                       */
/*   1 = XCON_ELASTIC_STORE_1                                       */
/*   2 = XCON_ELASTIC_STORE_2                                       */
/*   3 = XCON_ELASTIC_STORE_3                                       */
/*   4 = XCON_ELASTIC_STORE_4                                       */
/*   5 = XCON_ELASTIC_STORE_5                                       */
/*   6 = XCON_ELASTIC_STORE_6                                       */
/*   7 = XCON_ELASTIC_STORE_7                                       */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  TEN_XCON_ES_INTSTATUS_t data;
  T41_t *pDev = NULL;

  TEN_XCON_VALIDATE_ES_RANGE;
  TEN_DEV_COMMON_VALIDATE(dev_id, pDev, CS_ERROR);
  data.wrd = TEN_REG_READ(TEN_XCON_ES_INST_REG_ADDR(pDev, INTSTATUS, es_num));
  return ((cs_status) data.bf.AMPLITUDE_RECENTERs);
}


/********************************************************************/
/* Internal helper function:  ten_xcon_es_set_config_mfp_mode()     */
/********************************************************************/
/* Error checking must be done by the caller.                       */
/* Sets mfp_mode bit, leaves others as is.                          */
/*                                                                  */
/* Inputs : device id                                               */
/*          elastic store number                                    */
/*          mfp mode (XCON_FP or XCON_MFP)                          */
/* Output : TEN_XCON_ES_CONFIG_t.wrd                                */
/********************************************************************/
cs_status ten_xcon_es_set_config_mfp_mode(cs_uint16         dev_id,
                                          ten_xcon_es_num_t es_num,
                                          cs_uint8          mode)
{
  TEN_XCON_ES_CONFIG_t data;
  /* Bugzilla 30990, cleaner faster reg set */
  TEN_XCON_ES_CONFIG_t mask;
  mask.wrd         = 0;
  mask.bf.PKT_MODE = 1;
  mask.bf.MFP_MODE = 1;
  data.wrd         = 0;
  data.bf.MFP_MODE = mode;
  data.bf.PKT_MODE = ten_xcon_es_get_pkt_mode(dev_id, es_num);
  return (ten_xcon_es_config_multi_t41(dev_id, es_num, mask.wrd, data.wrd));
}

/* Bugzilla 27270 End, Amplitude Recentering, T41 release 5.3   */


/* Bugzilla 27270 Start, Amplitude Recentering, T41 release 5.4 */


/****************************************************************/
/* CATEGORY   : Device                                          */
/* ACCESS     : Public                                          */
/* BLOCK      : GENERAL                                         */
/* CHIP       : Tenabo                                          */
cs_status ten_dev_init_xcon_es_cb (cs_uint16 dev_id)
/* INPUTS     : o Device Id                                     */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* Initializes the device control block for the xcon elastic    */
/* store.  Default sets recenering type to IML                  */
/*                                                              */
/* This API should be called only after the device corresponding*/
/* to this module has been registered.                          */
/****************************************************************/
{
  ten_dev_cb_t *pdevcb;
  cs_uint8 es_num = 0;

  pdevcb = TEN_DEV_ID_TO_DEVCB_PTR(dev_id);

  for (; es_num < TEN_XCON_ES_COUNT; es_num++) {
    pdevcb->es_cb[es_num].recenter.type = TEN_XCON_ES_RECENTER_DEFAULT;
  }

  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  XCON ES WRITE CB T41                             */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : XCON                                                */
/* CHIP       : Tenabo                                              */
cs_status ten_xcon_es_write_cb_t41(cs_uint16 dev_id,
                                   ten_xcon_es_num_t es_num,
                                   cs_uint16 type,  
                                   cs_uint16 arg1,  
                                   cs_uint16 arg2,  
                                   cs_uint16 arg3,  
                                   cs_uint16 arg4,  
                                   cs_uint8  duration,
                                   cs_uint32 sysclk_freq)
/* INPUTS     : o Device Id                                         */
/*              o Elastic Store Id                                  */
/*              o Type                                              */
/*              o Multi-purpose args 1-6                            */
/*              o Circuit Threshold Upper                           */
/*                                                                  */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Writes arguments to the ES control block.                        */
/*                                                                  */
/* The [es_num] parameter is specified as:                          */
/*   0 = XCON_ELASTIC_STORE_0                                       */
/*   1 = XCON_ELASTIC_STORE_1                                       */
/*   2 = XCON_ELASTIC_STORE_2                                       */
/*   3 = XCON_ELASTIC_STORE_3                                       */
/*   4 = XCON_ELASTIC_STORE_4                                       */
/*   5 = XCON_ELASTIC_STORE_5                                       */
/*   6 = XCON_ELASTIC_STORE_6                                       */
/*   7 = XCON_ELASTIC_STORE_7                                       */
/*                                                                  */
/* The [type] parameter is overloaded beginning with release 5.5:   */
/*   LS Byte, recenter type:                                        */
/*      0 = TEN_XCON_ES_RECENTER_DEFAULT                            */
/*      1 = TEN_XCON_ES_RECENTER_IML                                */
/*      2 = TEN_XCON_ES_RECENTER_AMP_10G                            */
/*      3 = TEN_XCON_ES_RECENTER_AMP_40G                            */
/*      4 = TEN_XCON_ES_RECENTER_FPA_10G                            */
/*      5 = TEN_XCON_ES_RECENTER_FPA_40G                            */
/*   MS Byte, recovery mode (new for 5.5):                          */
/*     0x00 = TEN_XCON_ES_RECENTER_RECOVERY_DFLT (Default):         */
/*       Default is INTP for backward compatibility.                */
/*     0x40 = TEN_XCON_ES_RECENTER_RECOVERY_AUTO (Recommended):     */
/*       Framer and upper/lower ES violation event handlers kick    */
/*       off recenter, which completes using recenter status        */
/*       polling and system timers.                                 */
/*     0x80 = TEN_XCON_ES_RECENTER_RECOVERY_INTP (Interrupt         */
/*       driven):                                                   */
/*       The Framer event handlers kick off recenter. The           */
/*       recenter-complete event handler completes it. Application  */
/*       code is responsible for enabling the required interrupts   */
/*       and registering their handlers as needed.                  */
/*                                                                  */
/* The [argn] parameters are dependant on the value of [type].      */
/* These are shown in the following table,and explained below that. */
/*                                                                  */
/*           type=AMP_10/40G  type=FPA_10/40G                       */
/*           ---------------  ----------------                      */
/*   arg1:   margin_lower     static_depth                          */
/*   arg2:   margin_upper     circuit_th_lower                      */
/*   arg3:   correct_lower    circuit_th_upper                      */
/*   arg4:   correct_upper    -not used-                            */
/*           duration         -not used-                            */
/*           sysclk_freq      -not used-                            */
/*                                                                  */
/* Each of these is as defined below:                               */
/*                                                                  */
/*   The [margin_lower] parameter is specified as:                  */
/*     0..0x1fff, the amount of lower margin to reserve for an      */
/*     amplitude recenter                                           */
/*                                                                  */
/*   The [margin_upper] parameter is specified as:                  */
/*     0..0x1fff, the amount of upper margin to reserve for an      */
/*     amplitude recenter                                           */
/*                                                                  */
/*   The [correct_lower] parameter is specified as:                 */
/*     0..0x01ff, the amount to increase XCON_ES_CIRCUIT_THRESHOLD_ */
/*     LOWER by after computing the new threshold following an      */
/*     amplitude recenter.                                          */
/*                                                                  */
/*   The [correct_upper] parameter is specified as:                 */
/*     0..0x01ff, the amount to decrease XCON_ES_CIRCUIT_THRESHOLD_ */
/*     UPPER by after computing the new threshold following an      */
/*     amplitude recenter.                                          */
/*                                                                  */
/*   The [duration] parameter is specified as:                      */
/*      1..157~168 milliseconds, depending on sysclk_freq           */
/*      Number of milliseconds to measure depth for Amplitude       */
/*       Recentering.                                               */
/*                                                                  */
/*   The [sysclk_freq] parameter is specified as:                   */
/*     the sysclk frequency in hertz, i.e., 425000000               */
/*                                                                  */
/*   The [static_depth] parameter is specified as:                  */
/*      0..0x1fff, static_depth is used for an amplitude recenter   */
/*      instead of a calculated depth.                              */
/*                                                                  */
/*   The [circuit_th_lower] parameter is specified as:              */
/*     1..0x1fff, Minimum desired amount of data (in units of 4     */
/*     bytes) in the FIFO. Note: LEVEL must be smaller than         */
/*     IML_THRESH but no less than 1.                               */
/*                                                                  */
/*   The [circuit_th_upper] parameter is specified as:              */
/*     1..0x1ffe, Maximum desired amount of data (in units of 4     */
/*     bytes) in the FIFO. Note: LEVEL must be larger than          */
/*     IML_THRESH but no larger than 8190.                          */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  cs_uint8  tmp_side;
  cs_uint8  ii;
  cs_uint16 recovery;                /* Release 5.5, Bugzilla 27270 */
  cs_uint32 err_code = 0;
  ten_dev_cb_t *pdevcb = NULL;
  cs_status     stat   = CS_OK;
  cs_char8     *func   = "ten_xcon_es_write_cb_t41";

  /* validate args */
  TEN_XCON_VALIDATE_ES_RANGE

  if (!(TEN_IS_DEVICE_VALID(dev_id, &err_code))) {
    CS_HNDL_ERROR(dev_id, err_code, "%s\n", func);
    return (CS_ERROR);
  }

  pdevcb = TEN_DEV_ID_TO_DEVCB_PTR(dev_id);
  if (pdevcb == NULL) {
    CS_HNDL_ERROR(dev_id, err_code, "%s\n", func);
    return (CS_ERROR);
  }

  recovery  = (type & (TEN_XCON_ES_RECENTER_RECOVERY_MASK << 8) ) >> 8;
  if (recovery == TEN_XCON_ES_RECENTER_RECOVERY_DFLT) recovery = TEN_XCON_ES_RECENTER_RECOVERY_INTP;
  if ( (recovery != TEN_XCON_ES_RECENTER_RECOVERY_NONE) && 
       (recovery != TEN_XCON_ES_RECENTER_RECOVERY_AUTO) && 
       (recovery != TEN_XCON_ES_RECENTER_RECOVERY_INTP) ) {
    CS_HNDL_ERROR(dev_id, ETEN_DEV_INVALID_USER_ARG, ": %s(es_num %d), %s 0x%X\n", 
                  func, es_num, "Invalid recovery mode", recovery);
    return CS_ERROR;
  }

  /* Validate the type arg */
  type &= ~(TEN_XCON_ES_RECENTER_RECOVERY_MASK << 8);
  switch (type) {
    case TEN_XCON_ES_RECENTER_AMP_40G :
    case TEN_XCON_ES_RECENTER_FPA_40G :
      if (es_num % 4 != 0) {    /* 40g recentering uses es 0 for side A es, and es 4 for side A es */
        CS_HNDL_ERROR(dev_id, ETEN_DEV_INVALID_USER_ARG, "%s(es=%d) does not accept 40G recenter type '%s'", 
                      func, es_num, xcon_es_recntr_str[type]);
        stat = CS_ERROR;
      }
      break;

    case TEN_XCON_ES_RECENTER_AMP_10G :
    case TEN_XCON_ES_RECENTER_FPA_10G :
      if (es_num % 4 != 0) {    /* If ES 1,2,3,5,6 or 7, make sure ES 0 or 4 are not set up for 40G */
        tmp_side = es_num / 4;  /* 0 or 1 */
        if (   (pdevcb->es_cb[tmp_side * 4].recenter.type == TEN_XCON_ES_RECENTER_AMP_40G) 
            || (pdevcb->es_cb[tmp_side * 4].recenter.type == TEN_XCON_ES_RECENTER_FPA_40G) ) {
          CS_HNDL_ERROR(dev_id, ETEN_DEV_INVALID_USER_ARG, 
                      "%s(es=%d), recenter cannot be set for recenter type '%s' because side %d is configured for %s", 
                      func, es_num, xcon_es_recntr_str[type], tmp_side, xcon_es_recntr_str[pdevcb->es_cb[tmp_side].recenter.type]);
          stat = CS_ERROR;
        }
      }
      break;
      
    case TEN_XCON_ES_RECENTER_IML :
    case TEN_XCON_ES_RECENTER_DEFAULT :
      break;

    default :
        CS_HNDL_ERROR(dev_id, ETEN_DEV_INVALID_USER_ARG, 
                      "%s(es=%d), invalid recenter type %d", func, es_num, type);
        stat = CS_ERROR;
      break;
  }
  if (stat != CS_OK ) {
    pdevcb->es_cb[es_num].recenter.type = TEN_XCON_ES_RECENTER_IML;   /* try to provide service */
    return (stat);              /* <<<< <<<<< <<<<< <<<<<  EXIT ON ERROR <<<<< <<<<< <<<<< <<<< */
  }

  CS_PRINT("%s(%d %d (0x%0X)%d %d %d %d %d %d %d)\n",  func, dev_id, es_num, 
                                                       recovery, type,  
                                                       arg1, arg2, arg3, arg4,  
                                                       duration, sysclk_freq);

  pdevcb->es_cb[es_num].recenter.recovery = recovery;
  /* The [argn] parameters are dependant on the value of [type].      */
  /* These are shown in the following table,and explained below that. */
  /*                                                                  */
  /*   type=AMP_10/40G:                                               */
  /*   arg1: margin_lower   arg2: margin_upper  arg3: correct_lower   */
  /*   arg4: correct_upper  arg5: duration      arg6: sysclk_freq     */
  pdevcb->es_cb[es_num].recenter.type = type;
  switch (type) {
    case TEN_XCON_ES_RECENTER_AMP_10G :
    case TEN_XCON_ES_RECENTER_AMP_40G :
      pdevcb->es_cb[es_num].recenter.parms.amp.margin_lower = arg1;
      pdevcb->es_cb[es_num].recenter.parms.amp.margin_upper  = arg2;
      pdevcb->es_cb[es_num].recenter.parms.amp.correct_lower = arg3;
      pdevcb->es_cb[es_num].recenter.parms.amp.correct_upper = arg4;
      pdevcb->es_cb[es_num].recenter.parms.amp.duration     = duration;
      pdevcb->es_cb[es_num].recenter.parms.amp.sysclk_freq = sysclk_freq;
      break;
            
    /*   type=FPA_10/40G:                                             */
    /*   arg1: static_depth           arg2: circuit_th_lower          */
    /*   arg3: circuit_th_upper   arg4,5,6: -not used-                */
    case TEN_XCON_ES_RECENTER_FPA_10G :
    case TEN_XCON_ES_RECENTER_FPA_40G :
      pdevcb->es_cb[es_num].recenter.parms.fpa.static_depth            = arg1;
      pdevcb->es_cb[es_num].recenter.parms.fpa.circuit_threshold_lower = arg2;
      pdevcb->es_cb[es_num].recenter.parms.fpa.circuit_threshold_upper = arg3;
      break;
      
    default :
      break;
  }

  /* Clean up ES CB entries 1-3 or 5-7, if this ES is 0 or 4 and its CB specifies a 40g recenter type */
  if ( ((type==TEN_XCON_ES_RECENTER_AMP_40G) || (type==TEN_XCON_ES_RECENTER_FPA_40G)) && 
       ((es_num==0                         ) || (es_num==4                         ))    ) { /* this line for klocwork */
    for (ii=es_num+1; ii < es_num+4; ii++) {
      pdevcb->es_cb[ii].recenter.type = TEN_XCON_ES_RECENTER_DEFAULT;
    }
  }

  return (stat);
}

/****************************************************************/
/* CATEGORY   : Device                                          */
/* ACCESS     : Public                                          */
/* BLOCK      : GENERAL                                         */
/* CHIP       : Tenabo                                          */
void ten_xcon_es_dump_cb (ten_xcon_es_cb_t *aESCB)
/* INPUTS     : o Pointer to the dev CB's ES CB array           */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* Dumps the XCON Elastic Store control block.                  */
/*                                                              */
/****************************************************************/
{
  cs_uint8 recov_idx;
  cs_uint8 es_num = 0;

  if (aESCB == NULL) { return; }

  for (es_num=0; es_num < TEN_XCON_ES_COUNT; es_num++) {

    /* Print recenter type */
    switch (aESCB[es_num].recenter.type) {
      case TEN_XCON_ES_RECENTER_IML :
        CS_PRINT_OUTPUT("xcon es[%d] recntr = %s\n", es_num, xcon_es_recntr_str[TEN_XCON_ES_RECENTER_IML]);
        break;

      case TEN_XCON_ES_RECENTER_DEFAULT :
        /* Not interesting, don't print (Release 5.5, no bugzilla)
        CS_PRINT_OUTPUT("xcon es[%d] recntr = %s\n", es_num, xcon_es_recntr_str[TEN_XCON_ES_RECENTER_DEFAULT]);
        */
        break;

      case TEN_XCON_ES_RECENTER_AMP_40G :
        CS_PRINT_OUTPUT("xcon es[%d] recntr = %s\n", es_num, xcon_es_recntr_str[TEN_XCON_ES_RECENTER_AMP_40G]);
        break;

      case TEN_XCON_ES_RECENTER_FPA_40G :
        CS_PRINT_OUTPUT("xcon es[%d] recntr = %s\n", es_num, xcon_es_recntr_str[TEN_XCON_ES_RECENTER_FPA_40G]);
        break;

      case TEN_XCON_ES_RECENTER_AMP_10G :
        CS_PRINT_OUTPUT("xcon es[%d] recntr = %s\n", es_num, xcon_es_recntr_str[TEN_XCON_ES_RECENTER_AMP_10G]);
        break;

      case TEN_XCON_ES_RECENTER_FPA_10G :
        CS_PRINT_OUTPUT("xcon es[%d] recntr = %s\n", es_num, xcon_es_recntr_str[TEN_XCON_ES_RECENTER_FPA_10G]);
        break;

      default :
        CS_PRINT_OUTPUT("xcon es[%d] recntr : invalid type %d\n", es_num, aESCB[es_num].recenter.type);
        break;
    }
    recov_idx = aESCB[es_num].recenter.recovery >> 6;
    if (recov_idx > 3) recov_idx = 3;

    /* Print recenter parameters */
    switch (aESCB[es_num].recenter.type) {
      case TEN_XCON_ES_RECENTER_AMP_10G :
      case TEN_XCON_ES_RECENTER_AMP_40G :
        CS_PRINT_OUTPUT(" recovery         = %s\n", xcon_es_recntr_recov_str[recov_idx]);
        CS_PRINT_OUTPUT(" margin lower     = %d\n", aESCB[es_num].recenter.parms.amp.margin_lower  );
        CS_PRINT_OUTPUT(" margin upper     = %d\n", aESCB[es_num].recenter.parms.amp.margin_upper  );
        CS_PRINT_OUTPUT(" correction lower = %d\n", aESCB[es_num].recenter.parms.amp.correct_lower );
        CS_PRINT_OUTPUT(" correction upper = %d\n", aESCB[es_num].recenter.parms.amp.correct_upper );
        CS_PRINT_OUTPUT(" duration         = %d\n", aESCB[es_num].recenter.parms.amp.duration      );
        CS_PRINT_OUTPUT(" sysclk frequency = %d\n", aESCB[es_num].recenter.parms.amp.sysclk_freq   );
        break;
        
      case TEN_XCON_ES_RECENTER_FPA_10G :
      case TEN_XCON_ES_RECENTER_FPA_40G :
        CS_PRINT_OUTPUT(" recovery         = %s\n", xcon_es_recntr_recov_str[recov_idx]);
        CS_PRINT_OUTPUT(" static depth     = %d\n", aESCB[es_num].recenter.parms.fpa.static_depth     );
        CS_PRINT_OUTPUT(" ckt threshld lwr = %d\n", aESCB[es_num].recenter.parms.fpa.circuit_threshold_lower );
        CS_PRINT_OUTPUT(" ckt threshld upr = %d\n", aESCB[es_num].recenter.parms.fpa.circuit_threshold_upper );
        break;
        
      default :
        break;
    }
  }
}


/********************************************************************/
/* $rtn_hdr_start  XCON ES HANDLE TRAFFIC STABLE EVENT 10G T41      */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : XCON                                                */
/* CHIP       : Tenabo                                              */
cs_status ten_xcon_es_handle_traffic_stable_event_10g_t41(cs_uint16 dev_id,
                                                          cs_uint16 source_slice)
/* INPUTS     : o Device Id                                         */
/*              o Source Slice                                      */
/*                                                                  */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_ERROR, CS_OK or downstream (sourced) ES ID+1.    */
/* DESCRIPTION:                                                     */
/* When a  traffic-stable event is detected, this function is       */
/* called to condition the elastic store, e.g., initiate amplitude  */
/* recentering.                                                     */
/*                                                                  */
/* THIS FUNCTION MUST BE RUN ON AN OS THREAD as it requires mutex.  */
/*                                                                  */
/* Returns ID + 1 of the downstream ES if there was no error and    */
/* this is not an ES for amplitude recentering                      */
/*                                                                  */
/* The [source_slice] parameter is specified as:                    */
/*   0, corresponds to stream from module 0 port 0                  */
/*   1, corresponds to stream from module 0 port 1                  */
/*   2, corresponds to stream from module 0 port 2                  */
/*   3, corresponds to stream from module 0 port 3                  */
/*   4, corresponds to stream from module 1 port 0                  */
/*   5, corresponds to stream from module 1 port 1                  */
/*   6, corresponds to stream from module 1 port 2                  */
/*   7, corresponds to stream from module 1 port 3                  */
/*                                                                  */
/*   ** NOTE **                                                     */
/*   The source stream is the stream on which stable traffic has    */
/*   been detected. This function will determine which elastic      */
/*   store is relevant.                                             */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  cs_uint16           downstream_es;
  TEN_XCON_ES_RESET_t tmp_es_reset;
  TEN_XCON_GLB_ES_SOURCE_SELECT_0_t tmp_glb_es_source_select;
  cs_uint32           err_code       = 0;
  cs_uint8            downstream_mod = 0;       /* The opposite module                                */
  cs_uint8            downstream_rcntrType = 0; /* Downstream recenter type (for module if isQuartet) */
  cs_uint8            downstream_isQuartet = 0; /* Downstream uses 4 ESs, e.g, 40G traffic type       */
  T41_t              *pDev   = NULL;
  ten_dev_cb_t       *pdevcb = NULL;
  cs_status           stat   = CS_OK;
  cs_char8           *func   = "ten_xcon_es_handle_traffic_stable_event_10g_t41";  

  TEN_DEV_COMMON_VALIDATE_INTERNAL(dev_id, &pDev);

  if (!(TEN_IS_DEVICE_VALID(dev_id, &err_code))) {
    CS_HNDL_ERROR(dev_id, err_code, "%s()", func);
    return (CS_ERROR);
  }
  pdevcb = TEN_DEV_ID_TO_DEVCB_PTR(dev_id);
  if (pdevcb == NULL) {
    CS_PRINT("%s(), Device %d ERROR: pdevcb is NULL.\n", func, dev_id);
    return (CS_ERROR);
  }

  CS_PRINT("%s() %s\n", func, ten_xcon_es_mod_slice_strings[source_slice]);

  /* a) Find which xcon this slice is sourcing.                     */
  /* b) Get its recentering type from the ES control block.         */
  /* c) If amplitude recenering or frame pulse alignment centering, */
  /*    - Enable amplitude recentering interrupts.                  */
  /*    - Kick off the appropriate recenter.                        */

  /* Find which xcon this slice is sourcing                         */
  for (downstream_es=0; downstream_es<TEN_XCON_ES_COUNT; downstream_es++) {
    tmp_glb_es_source_select.wrd = TEN_REG_READ(TEN_XCON_ES_SOURCE_SEL_REG_ADDR(pDev, downstream_es));
    if (tmp_glb_es_source_select.bf.SOURCE == source_slice) {
      /* Transmitter downstream_es which is using this source */
      tmp_es_reset.wrd = TEN_REG_READ(TEN_XCON_ES_INST_REG_ADDR(pDev, RESET, downstream_es));
      if (!tmp_es_reset.bf.RESET) {
        /* Transmitter downstream_es is out of reset, so matching source has been found */
        break;
      }
    }
  }

  if (downstream_es == TEN_XCON_ES_COUNT) {
    /* Transmitter using this source was not found */
    CS_PRINT("%s() Could not find an ES sourced from %s.\n", func, ten_xcon_es_mod_slice_strings[source_slice]);
    return CS_ERROR;
  }

  /* Find what needs recentering */
  stat = ten_xcon_es_get_recenter_type(pdevcb, downstream_es, 
                                       &downstream_mod, &downstream_rcntrType, &downstream_isQuartet);
  if (stat != CS_OK) return (stat); /* <<<<<<<<< EARLY EXIT ON ERROR <<<<<<<<<<< */

  if (downstream_rcntrType >= TEN_XCON_ES_RECENTER_OOR) {  /* Explicit range check to avoid klocwork complaint */
    CS_HNDL_ERROR(dev_id, ETEN_DEV_INVALID_USER_ARG, "%s(), Downstream ES d, invalid recenter type %d", func, downstream_es, downstream_rcntrType);
    return (CS_ERROR);              /* <<<<<<<<< EARLY EXIT ON ERROR <<<<<<<<<<< */
  }

  CS_PRINT("%s() %s recenter type \'%s\'.\n",
           func, ten_xcon_es_mod_slice_strings[downstream_es], xcon_es_recntr_str[pdevcb->es_cb[downstream_es].recenter.type]);
  
  if (  !(downstream_isQuartet) 
       &&(  (downstream_rcntrType==TEN_XCON_ES_RECENTER_DEFAULT)
          ||(downstream_rcntrType==TEN_XCON_ES_RECENTER_IML    ) ) )
  {
    /* This is a normal (legacy) recenter type. Bug 27270, take no action as part of 5.5 simplification.  
    ten_xcon_select_es_packet_centering (dev_id, downstream_es, XCON_FORCE_CENTER, CS_ENABLE);
    ten_xcon_select_es_packet_centering (dev_id, downstream_es, XCON_FORCE_CENTER, CS_DISABLE);*/
    CS_PRINT("%s(), Downstream ES %d is not configured for amplitude recentering. No action taken.\n",
      func, downstream_es);
  }
  else if (downstream_isQuartet) {
    CS_PRINT("%s(%s) sourced ES %s is in a 40g config, this event will not cause it to be recentered.\n",
              func, ten_xcon_es_mod_slice_strings[source_slice], ten_xcon_es_mod_slice_strings[downstream_es]);
  }
  else
  {
    /* This is an amplitude recenter */
    /* if (downstream_es > 0) ten_udelay_hi_res( (downstream_es%3) * 2000); Orthogonal delay reduces chance of simultaneous recenters in a loopback stream */
    if (pdevcb->es_cb[downstream_es].recenter.recovery == TEN_XCON_ES_RECENTER_RECOVERY_AUTO) {
      stat |= ten_hl_xcon_es_amplitude_recenter_from_cb_t41(dev_id, downstream_es);
    }
    else if (pdevcb->es_cb[downstream_es].recenter.recovery == TEN_XCON_ES_RECENTER_RECOVERY_INTP) {
      /*    - Enable amplitude recentering interrupts.                  */
      stat |= ten_xcon_es_intr_handler_enable (dev_id, TEN_XCON_ES_INTR_AMPLITUDE_RECENTER);

      /*    - Kick off the appropriate recenter.                        */
      if (downstream_isQuartet) {
        stat |= ten_xcon_es_setup_amp_recntr_from_cb_40g_t41(dev_id, downstream_mod);
        stat |= ten_xcon_glb_pp40g_config_t41(dev_id, downstream_mod, XCON_GLB_PP40G_CFG_RECENTER, CS_ENABLE );
        stat |= ten_xcon_glb_pp40g_config_t41(dev_id, downstream_mod, XCON_GLB_PP40G_CFG_RECENTER, CS_DISABLE);
      }
      else {
        stat |= ten_xcon_es_setup_amp_recntr_from_cb_10g_t41(dev_id, downstream_es);
        stat |= ten_xcon_select_es_packet_centering(dev_id, downstream_es, XCON_FORCE_CENTER, CS_ENABLE );
        stat |= ten_xcon_select_es_packet_centering(dev_id, downstream_es, XCON_FORCE_CENTER, CS_DISABLE);
      }
    }
    else {
      CS_PRINT("%s(%s): Auto amplitude recenter disabled for sourced ES %s.\n",
                func, ten_xcon_es_mod_slice_strings[source_slice], ten_xcon_es_mod_slice_strings[downstream_es]);
    }
  }


  CS_PRINT_OUTPUT("\n%s() has finished.\n", func);
  return (downstream_es);
}



/********************************************************************/
/* $rtn_hdr_start  XCON ES HANDLE TRAFFIC STABLE EVENT 40G T41      */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : XCON                                                */
/* CHIP       : Tenabo                                              */
cs_status ten_xcon_es_handle_traffic_stable_event_40g_t41(
                                                   cs_uint16 dev_id,
                                                   cs_uint16 source_module)
/* INPUTS     : o Device Id                                         */
/*              o Module Number of event source                     */
/*                                                                  */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* When a  traffic-stable event is detected, this function is       */
/* called to condition the elastic store, e.g., initiate amplitude  */
/* recentering.                                                     */
/*                                                                  */
/* THIS FUNCTION MUST BE RUN ON AN OS THREAD as it requires mutex.  */
/*                                                                  */
/* The [source_module] parameter is specified as:                   */
/*   0 = TEN_MODULE_A (ES # 0-3)                                    */
/*   1 = TEN_MODULE_B (ES # 4-7)                                    */
/*                                                                  */
/*   ** NOTE **                                                     */
/*   The source module is the module on which stable traffic has    */
/*   been detected. This function will determine which elastic      */
/*   store(s) are relevant.                                         */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  cs_uint16           downstream_es;
  cs_uint32           err_code = 0;
  T41_t              *pDev = NULL;

  cs_uint16           downstream_mod = (source_module+1)&1;  /* The opposite module */
  ten_dev_cb_t       *pdevcb = NULL;
  cs_status           stat   = CS_OK;
  cs_char8           *func   = "ten_xcon_es_handle_traffic_stable_event_40g_t41";  
  cs_uint8            count  = 0;
  TEN_DEV_COMMON_VALIDATE_INTERNAL(dev_id, &pDev);

  if (!(TEN_IS_DEVICE_VALID(dev_id, &err_code))) {
    CS_HNDL_ERROR(dev_id, err_code, "%s()", func);
    return (CS_ERROR);
  }
  pdevcb = TEN_DEV_ID_TO_DEVCB_PTR(dev_id);
  if (pdevcb == NULL) {
    CS_PRINT("%s(), Device %d ERROR: pdevcb is NULL.\n", func, dev_id);
    return (CS_ERROR);
  }

  CS_PRINT("%s() Module %d\n", func, source_module);

  /* a) Get the ES number representing the side to be recentered.   */
  /* b) Get its recentering type from the ES control block.         */
  /* c) If amplitude recenering or frame pulse alignment centering, */
  /*    - Enable amplitude recentering interrupts.                  */
  /*    - Kick off the appropriate recenter.                        */

  /* Get the ES number representing the side to be recentered       */
  /* Note: The side which needs recentering is opposite the side    */
  /* which reported stable traffic. So downstream_es is as below, and the  */
  /* recenter module is opposite the source module, which is        */
  /* downstream_mod                                            */
  if      (source_module == TEN_MODULE_A) downstream_es = XCON_ELASTIC_STORE_4;
  else if (source_module == TEN_MODULE_B) downstream_es = XCON_ELASTIC_STORE_0;
  else    {
    CS_PRINT("%s(), Invalid source_module %d.\n", func, source_module);
    return (CS_ERROR);
  }

  /* ten_udelay_hi_res(downstream_es*2000); Add delay with orthogonality to prevent two simultaneous recenters on loopbacks */
  /*    - Enable amplitude recentering interrupts.                  */

  /*    - Kick off the appropriate recenter.                        */
  /* Get the ES recentering type from the ES control block.         */
  if ( (pdevcb->es_cb[downstream_es].recenter.type == TEN_XCON_ES_RECENTER_AMP_40G) ||
       (pdevcb->es_cb[downstream_es].recenter.type == TEN_XCON_ES_RECENTER_FPA_40G) ) {
    /* Downstream data uses the quartet of ESs on the downstream module */
    count = 4;
    if (pdevcb->es_cb[downstream_es].recenter.recovery == TEN_XCON_ES_RECENTER_RECOVERY_AUTO) {
      stat |= ten_hl_xcon_es_amplitude_recenter_from_cb_t41(dev_id, downstream_es);
    }
    else if (pdevcb->es_cb[downstream_es].recenter.recovery == TEN_XCON_ES_RECENTER_RECOVERY_INTP) {
      stat |= ten_xcon_es_intr_handler_enable (dev_id, TEN_XCON_ES_INTR_AMPLITUDE_RECENTER);
      stat |= ten_xcon_es_setup_amp_recntr_from_cb_40g_t41(dev_id, downstream_mod);
      stat |= ten_xcon_glb_pp40g_config_t41(dev_id, downstream_mod, XCON_GLB_PP40G_CFG_RECENTER, CS_ENABLE );
      stat |= ten_xcon_glb_pp40g_config_t41(dev_id, downstream_mod, XCON_GLB_PP40G_CFG_RECENTER, CS_DISABLE);
    }
    else {
      CS_PRINT("%s(mod=%d):  Auto amplitude recenter disabled for sourced module %d.\n",
                func, source_module, downstream_mod);
      count = 0;
    }
  } /* end if downstream 40g recenter */
  else {
    /* Might be a muxponder. Check each ES individually for those which need amplitude recentering */
    for (downstream_es=downstream_mod*4; downstream_es<downstream_mod*4+4; downstream_es++) {
      if ( (pdevcb->es_cb[downstream_es].recenter.type == TEN_XCON_ES_RECENTER_AMP_10G) ||
           (pdevcb->es_cb[downstream_es].recenter.type == TEN_XCON_ES_RECENTER_FPA_10G) ) {
        count += 1;        
        if (pdevcb->es_cb[downstream_es].recenter.recovery == TEN_XCON_ES_RECENTER_RECOVERY_AUTO) {
          stat |= ten_hl_xcon_es_amplitude_recenter_from_cb_t41(dev_id, downstream_es);
        }
        else if (pdevcb->es_cb[downstream_es].recenter.recovery == TEN_XCON_ES_RECENTER_RECOVERY_INTP) {
          stat |= ten_xcon_es_intr_handler_enable (dev_id, TEN_XCON_ES_INTR_AMPLITUDE_RECENTER);
          stat |= ten_xcon_es_setup_amp_recntr_from_cb_10g_t41(dev_id, downstream_es);
          stat |= ten_xcon_select_es_packet_centering(dev_id, downstream_es, XCON_FORCE_CENTER, CS_ENABLE );
          stat |= ten_xcon_select_es_packet_centering(dev_id, downstream_es, XCON_FORCE_CENTER, CS_DISABLE);
        }
        else {
          CS_PRINT("%s(mod=%d): Auto amplitude recenter disabled for sourced ES %s.\n",
                    func, source_module, ten_xcon_es_mod_slice_strings[downstream_es]);
        }
      }
    }
  } /* end if downstream is not configured for monolithic amplitude recentering       */

  /* If none of the ESs are config'd for amplitude recenter, take no action.          */
  if (!count) {
    CS_PRINT("%s(), Downstream module %d has no ES configured for amplitude recentering. No action taken.\n",
      func, downstream_mod);
    /* stat |= ten_xcon_es_pp40g_reset_t41(downstream_mod); Bug 27270, commented out for 5.5 simplification */
  }

  CS_PRINT_OUTPUT("\n%s() has finished.\n", func);
  return (stat);
}


/********************************************************************/
/* $rtn_hdr_start  XCON ES AMP RECENTER INTERRUPT HANDLER           */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : XCON                                                */
/* CHIP       : Tenabo                                              */
cs_status ten_xcon_es_amp_recntr_intr_handler(cs_uint16 dev_id,
                                              ten_xcon_es_num_t es_num)
/* INPUTS     : o Device Id                                         */
/*              o Module Number                                     */
/*                                                                  */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* When a recenter event is detected, this function determins it's  */
/* status and calls the appropriate event handler.                  */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  TEN_XCON_ES_INTSTATUS_t stat_reg;
  T41_t *pDev = NULL;
  cs_char8     *func          = "ten_xcon_es_amp_recntr_intr_handler";  
  cs_status     stat = CS_OK;

  TEN_DEV_COMMON_VALIDATE_INTERNAL(dev_id, &pDev);
  TEN_XCON_VALIDATE_ES_RANGE;

  CS_PRINT("%s(dev_id=%d, es_num=%d)\n", func, dev_id, es_num);

  /* Get amp recenter interrupt status */
  stat_reg.wrd = TEN_REG_READ(TEN_XCON_ES_INST_REG_ADDR(pDev, INTSTATUS, es_num));

  if (stat_reg.bf.AMPLITUDE_RECENTERs == 1) {
    /* still recentering */
  }
  else {
    stat = ten_xcon_es_handle_recenter_complete_event_t41( dev_id, es_num);
  }

  /* Renable the amp recenter interrupt */
  ten_xcon_es_intr_enable(dev_id, TEN_XCON_ES_INTR_AMPLITUDE_RECENTER);

  return (stat);
}

/********************************************************************/
/* $rtn_hdr_start  XCON ES HANDLE RECENTER COMPLETE EVENT 10G T41   */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : XCON                                                */
/* CHIP       : Tenabo                                              */
cs_status ten_xcon_es_handle_recenter_complete_event_t41(cs_uint16 dev_id,
            	                                   ten_xcon_es_num_t es_num)
/* INPUTS     : o Device Id                                         */
/*              o Elastic Store Id                                  */
/*                                                                  */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* When a recenter complete event is detected, this function is     */
/* called to perform cleanup actions such as logging the success,   */
/* and for amplitude recentering with frame pulse alignment, to     */
/* refresh the circuit threshold registers.                         */
/*                                                                  */
/* THIS FUNCTION MUST BE RUN ON AN OS THREAD as it requires mutex.  */
/*                                                                  */
/* The [es_num] parameter is specified as:                          */
/*   0 = XCON_ELASTIC_STORE_0                                       */
/*   1 = XCON_ELASTIC_STORE_1                                       */
/*   2 = XCON_ELASTIC_STORE_2                                       */
/*   3 = XCON_ELASTIC_STORE_3                                       */
/*   4 = XCON_ELASTIC_STORE_4                                       */
/*   5 = XCON_ELASTIC_STORE_5                                       */
/*   6 = XCON_ELASTIC_STORE_6                                       */
/*   7 = XCON_ELASTIC_STORE_7                                       */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  cs_uint8   es_idx;
  cs_status  stat      = CS_OK;
  T41_t     *pDev      = NULL;
  cs_uint8   rcntrType = 0;     /* Downstream recenter type (for module if isQuartet) */
  cs_uint8   isQuartet = 0;
  cs_char8  *func      = "ten_xcon_es_handle_recenter_complete_event_t41";  
  cs_uint8   mod_num_  = TEN_MODULE_NULL;
  cs_uint8   recenter_cmpl = FALSE;
  ten_dev_cb_t     *pdevcb = NULL;
  ten_xcon_es_cb_t *pescb  = NULL;

  TEN_DEV_COMMON_VALIDATE_INTERNAL(dev_id, &pDev);
  TEN_XCON_VALIDATE_ES_RANGE;

  CS_PRINT("%s(dev_id=%d, es_num=%d)\n", func, dev_id, es_num);

  pdevcb = TEN_DEV_ID_TO_DEVCB_PTR(dev_id);
  pescb  = &(pdevcb->es_cb[es_num]);

  /* Amplitude recentering is complete for this slice. First, determine if this */
  /* is a 40g or 10g recenter. If the latter, we're done. If 40g, we need to    */
  /* wait until no ES's on this module are recentering.                         */
  /*                                                                            */
  /* If this is a 40g recenter type, use ten_xcon_es_check_amplitude_recenter_  */
  /* t41() to see if the recenter is really complete. If recenter is complete,  */
  /* log the success.                                                           */
  /*                                                                            */
  /* If this es or the module recenter config is FPA, refresh its upper and     */
  /* lower threshold configs.                                                   */
    
    
  /* Is this a single ES recenter or an ES quartet? */
  stat = ten_xcon_es_get_recenter_type(pdevcb, es_num, &mod_num_, &rcntrType, &isQuartet);
  if (stat != CS_OK) return (stat); /* <<<<<<<<< EARLY EXIT ON ERROR <<<<<<<<<<< */

  if (isQuartet) {
    if (ten_xcon_es_check_amplitude_recenter_40g_t41(dev_id, mod_num_) == CS_OK) {
      recenter_cmpl = TRUE;
    }
  }
  else {
    mod_num_ = TEN_MODULE_NULL;
    recenter_cmpl = TRUE;
  }
  
  /* Refresh each ES as its recenter completes. Doesn't need to be done as a quartet */
  if (pescb->recenter.type == TEN_XCON_ES_RECENTER_FPA_10G) {
    /* refresh upper and lower ckt thresholds */
    stat |= ten_xcon_set_circuit_threshold_level_t41(dev_id, es_num, XCON_ES_RECENTER_AMPLITUDE,
                                                     XCON_ES_CIRCUIT_THRESHOLD_LOWER, -1, pescb->recenter.parms.fpa.circuit_threshold_lower); 
    stat |= ten_xcon_set_circuit_threshold_level_t41(dev_id, es_num, XCON_ES_RECENTER_AMPLITUDE,
                                                     XCON_ES_CIRCUIT_THRESHOLD_UPPER, -1, pescb->recenter.parms.fpa.circuit_threshold_upper); 
  }
  else if (pescb->recenter.type == TEN_XCON_ES_RECENTER_FPA_40G) {
    /* refresh all thresholds for es that are not recentering. */
    for (es_idx=mod_num_*4; es_idx < mod_num_*4+4; es_idx++) {
      if (ten_xcon_es_check_amplitude_recenter_t41(dev_id, es_idx) == CS_OK) {
        stat |= ten_xcon_set_circuit_threshold_level_t41(dev_id, es_idx, XCON_ES_RECENTER_AMPLITUDE,
                                                         XCON_ES_CIRCUIT_THRESHOLD_LOWER, -1, pescb->recenter.parms.fpa.circuit_threshold_lower); 
        stat |= ten_xcon_set_circuit_threshold_level_t41(dev_id, es_idx, XCON_ES_RECENTER_AMPLITUDE,
                                                         XCON_ES_CIRCUIT_THRESHOLD_UPPER, -1, pescb->recenter.parms.fpa.circuit_threshold_upper); 
      }
    }
  }

  if (recenter_cmpl) {
    ten_udelay_hi_res(1000);             /* Make sure es depth is stable before looking for min/max */
    ten_xcon_es_reset_level_min_max( dev_id, mod_num_, es_num ); /* reset affected ES level min/max */
    TEN_MDELAY(10);                      /* 10 ms ought to be enough to get reasonable min/max      */
    ten_xcon_es_dump_level_min_max(dev_id);
  }

  CS_PRINT_OUTPUT("\n%s() ES %d has finished.\n", func, es_num);
  return (stat);
}

/********************************************************************/
/* Internal helper function:                                        */
/*   ten_xcon_es_get_recenter_type()                                */
/********************************************************************/
/*                                                                  */
/* INPUTS     : o Pointer to device control block                   */
/*              o Elastic Store Id                                  */
/*              o Pointer to module number                          */
/*              o Pointer to recenter type indicator                */
/*              o Pointer to 10/40G indicator                       */
/*                                                                  */
/* OUTPUTS    : o Module number, if CS_OK is returned               */
/*              o Recenter type, if CS_OK is returned               */
/*              o 10/40G indicator, if CS_OK is returned            */
/*                                                                  */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/*                                                                  */
/* DESCRIPTION:                                                     */
/*                                                                  */
/* Given an XCON ES number, this function uses configration         */
/* information in the XCON ES control block to determine if this    */
/* ES or the module it is part of or subject to amplitude           */
/* recentering.                                                     */
/*                                                                  */
/* How it works:                                                    */
/*   If this is es 0 or es 4, check for 40g recenter type.          */
/*   Otherwise, if this is es 1,2,3,5,6, or 7, the recenter type is */
/*   either default or a 10g recenter type. If the latter, this is  */
/*   a 10g recenter type.                                           */
/*                                                                  */
/*   If this recenter is for an es with default recenter type,      */
/*   check the module recenter type (es 0 or 4) to see if this is a */
/*   40g recenter type.                                             */
/********************************************************************/
cs_status ten_xcon_es_get_recenter_type(ten_dev_cb_t *pdevcb, ten_xcon_es_num_t es_num,
                                        cs_uint8 *mod_num, cs_uint8 *rcntr_type, cs_uint8 *is40g)
{
  cs_uint8          es_admin;         /* the 'admin' es for a quartet; ES 0 for module 0, ES 4 for module 1. */
  cs_char8          strMsg[256] = "";
  cs_char8         *strRcType   = "ES %d recenter type is '%s'.";
  cs_status         stat  = CS_OK;
  ten_xcon_es_cb_t *pescb = &(pdevcb->es_cb[es_num]);

  *is40g  = FALSE;
  *rcntr_type = pescb->recenter.type;

  switch (pescb->recenter.type) {
    case TEN_XCON_ES_RECENTER_FPA_40G :
    case TEN_XCON_ES_RECENTER_AMP_40G :
      *mod_num = es_num/4;                /* 0 or 1 */
      *is40g = TRUE;
      sprintf(strMsg, strRcType, es_num, xcon_es_recntr_str[pescb->recenter.type]);
      break;

    case TEN_XCON_ES_RECENTER_DEFAULT :   /* might be a 40g recenter type. check */

      if (es_num %4 != 0) {
        /* ES es_num is 1, 2, 3, 5, 6, or 7 */
        /* This might be a 'quartet' of ES for a 40g traffic type */
        es_admin = (es_num/4)*4;
        if ( (pdevcb->es_cb[es_admin].recenter.type == TEN_XCON_ES_RECENTER_FPA_40G) ||
             (pdevcb->es_cb[es_admin].recenter.type == TEN_XCON_ES_RECENTER_AMP_40G) ) 
        {
          *mod_num = es_num/4;            /* 0 or 1 */
          *is40g = TRUE;
          *rcntr_type = pdevcb->es_cb[es_admin].recenter.type;
          sprintf(strMsg, 
                 "ES %d recenter type is '%s'. Module %d is configured for '%s' recentering.",
                 es_num,   xcon_es_recntr_str[pescb->recenter.type],
                 es_num/4, xcon_es_recntr_str[pdevcb->es_cb[es_admin].recenter.type]);
        }
        else 
        {
          sprintf(strMsg, 
                 "ES %d recenter type is '%s'. Module %d is not configured for 40g amp recentering.",
                 es_num, xcon_es_recntr_str[pescb->recenter.type], es_num/4 );
        }
      } 
      else {      
        /* this is es 0 or 4, the admin es's for 40g recentering so not config'd for amp recenter */
        sprintf(strMsg, strRcType, es_num, xcon_es_recntr_str[pescb->recenter.type]);
      }
      break;

    case TEN_XCON_ES_RECENTER_FPA_10G :
    case TEN_XCON_ES_RECENTER_AMP_10G :
        sprintf(strMsg, strRcType, es_num, xcon_es_recntr_str[pescb->recenter.type]);
      break;

    case TEN_XCON_ES_RECENTER_IML :
        sprintf(strMsg, strRcType, es_num, xcon_es_recntr_str[pescb->recenter.type]);
      break;

    default :
      stat = CS_ERROR;
      sprintf(strMsg, 
             "Amplitude Recenter action for es %d is invalid because recntr type '%d' is not a valid recenter type",
              es_num, pescb->recenter.type);
      break;
  } /* end switch on recenter type */
  
  if (stat==CS_ERROR) {
    CS_HNDL_ERROR(pdevcb->dev_id, ETEN_DRVR_UNEXPECTED_RESULT, ": XCON ES Action, dev_id %d, %s\n", pdevcb->dev_id, strMsg);
  }
  else  {
    CS_PRINT_OUTPUT("dev_id %d, %s\n", pdevcb->dev_id, strMsg);
  }

  return stat;
}


/********************************************************************/
/* $rtn_hdr_start  XCON ES SETUP AMPL RECENTER FROM CB 40G T41      */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : XCON                                                */
/* CHIP       : Tenabo                                              */
cs_status ten_xcon_es_setup_amp_recntr_from_cb_40g_t41(cs_uint16 dev_id,
                                                       cs_uint8  module_num)
/* INPUTS     : o Device Id                                         */
/*              o Module Number                                     */
/*                                                                  */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Configures the specified module's ES registers for recentering   */
/* using parameters written beforehand using                        */
/* ten_xcon_es_write_cb_t41()                                       */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  cs_uint32     err_code = 0;
  ten_dev_cb_t *pdevcb = NULL;
  cs_char8     *func   = "ten_xcon_es_setup_amp_recent_from_cb_40g_t41";
  cs_status     stat   = CS_OK;

  if (!(TEN_IS_DEVICE_VALID(dev_id, &err_code))) {
    CS_HNDL_ERROR(dev_id, err_code, NULL);
    return (CS_ERROR);
  }

  pdevcb = TEN_DEV_ID_TO_DEVCB_PTR(dev_id);
  if (pdevcb == NULL) {
    CS_PRINT("Writing xcon ES CB, T41 dev-%d, ERROR: pdevcb is NULL\n", dev_id);
    return (CS_ERROR);
  }
 
  /* Retrieve the recenter type and parameters for this recenter and call its setup function. */ 
  if ( (module_num == TEN_MODULE_A) || (module_num == TEN_MODULE_B)) {
    if (pdevcb->es_cb[module_num*4].recenter.type == TEN_XCON_ES_RECENTER_AMP_40G) {
      stat = ten_xcon_es_setup_amplitude_recenter_40g_cb( dev_id, module_num,
                               pdevcb->es_cb[module_num*4].recenter.parms.amp.margin_lower ,
                               pdevcb->es_cb[module_num*4].recenter.parms.amp.margin_upper ,
                               pdevcb->es_cb[module_num*4].recenter.parms.amp.correct_lower,
                               pdevcb->es_cb[module_num*4].recenter.parms.amp.correct_upper,
                               pdevcb->es_cb[module_num*4].recenter.parms.amp.duration     ,
                               pdevcb->es_cb[module_num*4].recenter.parms.amp.sysclk_freq, 
                               XCON_ES_UPDATE_CB_FALSE  );
    }
    else if (pdevcb->es_cb[module_num*4].recenter.type == TEN_XCON_ES_RECENTER_FPA_40G) {
      stat = ten_xcon_es_setup_amplitude_recenter_with_fpa_40g_cb( dev_id, module_num,
                               pdevcb->es_cb[module_num*4].recenter.parms.fpa.static_depth           ,
                               pdevcb->es_cb[module_num*4].recenter.parms.fpa.circuit_threshold_lower,
                               pdevcb->es_cb[module_num*4].recenter.parms.fpa.circuit_threshold_upper, 
                               XCON_ES_UPDATE_CB_FALSE  );
    }
    else {
      CS_HNDL_ERROR(dev_id, ETEN_DRVR_UNEXPECTED_RESULT, ": %s(mod %d), %s", func, module_num, "ES CB recenter type is 10g or not amp");
      return CS_ERROR;
    }
  }
  else {
    CS_HNDL_ERROR(dev_id, ETEN_MOD_ID_OUT_OF_RANGE, ": %s(es or mod %d), %s", func, module_num, "Invalid module number");
    return CS_ERROR;
  }

  return (stat);
}

/********************************************************************/
/* $rtn_hdr_start  XCON ES SETUP AMPL RECENTER FROM CB 10G T41      */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : XCON                                                */
/* CHIP       : Tenabo                                              */
cs_status ten_xcon_es_setup_amp_recntr_from_cb_10g_t41(cs_uint16 dev_id,
                                               ten_xcon_es_num_t es_num)
/* INPUTS     : o Device Id                                         */
/*              o Elastic Store Id                                  */
/*                                                                  */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Sets up the specified XCON ES registers for recentering          */
/* using parameters written beforehand using                        */
/* ten_xcon_es_write_cb_t41()                                       */
/*                                                                  */
/* Disables threshold interrupts and autorecentering in prep for    */
/* forced recentering and measurement phase.                        */
/*                                                                  */
/* The [es_num] parameter is specified as:                          */
/*   0 = XCON_ELASTIC_STORE_0                                       */
/*   1 = XCON_ELASTIC_STORE_1                                       */
/*   2 = XCON_ELASTIC_STORE_2                                       */
/*   3 = XCON_ELASTIC_STORE_3                                       */
/*   4 = XCON_ELASTIC_STORE_4                                       */
/*   5 = XCON_ELASTIC_STORE_5                                       */
/*   6 = XCON_ELASTIC_STORE_6                                       */
/*   7 = XCON_ELASTIC_STORE_7                                       */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{

  cs_uint32     err_code = 0;
  ten_dev_cb_t *pdevcb = NULL;
  cs_char8     *func   = "ten_xcon_es_setup_amp_recent_from_cb_10g_t41";
  cs_status     stat   = CS_OK;

  if (!(TEN_IS_DEVICE_VALID(dev_id, &err_code))) {
    CS_HNDL_ERROR(dev_id, err_code, NULL);
    return (CS_ERROR);
  }

  pdevcb = TEN_DEV_ID_TO_DEVCB_PTR(dev_id);
  if (pdevcb == NULL) {
    CS_PRINT("Writing xcon ES CB, T41 dev-%d, ERROR: pdevcb is NULL\n", dev_id);
    return (CS_ERROR);
  }

  TEN_XCON_VALIDATE_ES_RANGE;
 
  /* Retrieve the recenter type and parameters for this recenter and call its setup function. */ 
  if (pdevcb->es_cb[es_num].recenter.type == TEN_XCON_ES_RECENTER_AMP_10G) {
    stat = ten_xcon_es_setup_amplitude_recenter_10g_cb( dev_id, es_num,
                               pdevcb->es_cb[es_num].recenter.parms.amp.margin_lower ,
                               pdevcb->es_cb[es_num].recenter.parms.amp.margin_upper ,
                               pdevcb->es_cb[es_num].recenter.parms.amp.correct_lower,
                               pdevcb->es_cb[es_num].recenter.parms.amp.correct_upper,
                               pdevcb->es_cb[es_num].recenter.parms.amp.duration     ,
                               pdevcb->es_cb[es_num].recenter.parms.amp.sysclk_freq, 
                               XCON_ES_UPDATE_CB_FALSE  );
  }
  else if (pdevcb->es_cb[es_num].recenter.type == TEN_XCON_ES_RECENTER_FPA_10G) {
    stat = ten_xcon_es_setup_amplitude_recenter_with_fpa_10g_cb( dev_id, es_num,
                               pdevcb->es_cb[es_num].recenter.parms.fpa.static_depth           ,
                               pdevcb->es_cb[es_num].recenter.parms.fpa.circuit_threshold_lower,
                               pdevcb->es_cb[es_num].recenter.parms.fpa.circuit_threshold_upper, 
                               XCON_ES_UPDATE_CB_FALSE  );
  }
  else {
    CS_HNDL_ERROR(dev_id, ETEN_DRVR_UNEXPECTED_RESULT, ": %s(ES %d), %s", func, es_num, "ES CB recenter type is 40g or not amp");
    return CS_ERROR;
  }

  return (stat);
}

/* Bugzilla 27270 Release 5.5 Amplitude Recentering */
/********************************************************************/
/* $rtn_hdr_start  XCON ES DUMP LEVEL MIN MAX                       */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : XCON                                                */
/* CHIP       : Tenabo                                              */
cs_status ten_xcon_es_dump_level_min_max (cs_uint16         dev_id)
/* INPUTS     : o Device Id                                         */
/*              o Elastic Store Id                                  */
/*                                                                  */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Dumps the min and max recorded ES levels in 4-byte words         */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  TEN_XCON_ES_DEPTH_MIN_t dMin;
  TEN_XCON_ES_DEPTH_MAX_t dMax;
  cs_uint16               log_suspend_flag;
  T41_t                  *pDev = NULL;

  cs_uint8  es_f = XCON_ELASTIC_STORE_0;  /* id of first es affected */
  cs_uint8  es_l = XCON_ELASTIC_STORE_7;  /* id of last  es affected */
  cs_uint8  es_i = 0;                     /* es index                */

  TEN_DEV_COMMON_VALIDATE (dev_id, pDev, CS_ERROR);
 
  /* Suspend reg r/w logs for clean output */
  log_suspend_flag = g_pTEN->drvr_flag & TEN_DRVR_LOG_SUSPEND;
  g_pTEN->drvr_flag |= TEN_DRVR_LOG_SUSPEND;

  /* Dump the ES store min and max levels */
  CS_PRINT_OUTPUT("Xcon ES Depth: %5s %5s  (in 4-byte words)\n", "Min", "Max");
  for (es_i = es_f; es_i <= es_l; es_i++) {
    dMin.wrd = TEN_REG_READ(TEN_XCON_ES_INST_REG_ADDR(pDev, DEPTH_MIN, es_i));
    dMax.wrd = TEN_REG_READ(TEN_XCON_ES_INST_REG_ADDR(pDev, DEPTH_MAX, es_i));
    CS_PRINT_OUTPUT("%11s %d  %5d %5d\n", "es", es_i, dMin.bf.DEPTH, dMax.bf.DEPTH);
  }
  /* Bugzilla 30990, Fix logs turned off by bad logic */
  g_pTEN->drvr_flag &= (~TEN_DRVR_LOG_SUSPEND | log_suspend_flag);   /* restore log suspend flag */
  CS_PRINT_OUTPUT("\n");

  return CS_OK;
}

/********************************************************************/
/* $rtn_hdr_start  XCON ES SETUP AMPL RECENTER FROM CB 10G T41      */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : XCON                                                */
/* CHIP       : Tenabo                                              */
cs_status ten_xcon_es_reset_level_min_max(cs_uint16         dev_id,
                                          cs_uint16         module_num,
                                          ten_xcon_es_num_t es_num)
/* INPUTS     : o Device Id                                         */
/*              o Module Id   ** Note special usage **              */
/*              o Elastic Store Id                                  */
/*                                                                  */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Resets the elastic store min and max level registers, which      */
/* restarts min/max measurement.                                    */
/*                                                                  */
/* Does not reset ES min/max if amplitude recenter is in progress.  */
/*                                                                  */
/* [module_num] parameter specifies line's module ID                */
/*   0    = TEN_MODULE_A        (resets ES # 0-3 min/max)           */
/*   1    = TEN_MODULE_B        (resets ES # 4-7 min/max)           */
/*   2    = TEN_MODULE_A_AND_B  (resets ES # 0-7 min/max)           */
/*   0xFF = TEN_MODULE_NULL.    (use this to reset one ES min/max,  */
/*                               specified by 'es_num'  )           */
/*                                                                  */
/* The [es_num] parameter is ignored unless module_num is           */
/* TEN_MODULE_NULL. The [es_num] parameter is specified as:         */
/*   0 = XCON_ELASTIC_STORE_0                                       */
/*   1 = XCON_ELASTIC_STORE_1                                       */
/*   2 = XCON_ELASTIC_STORE_2                                       */
/*   3 = XCON_ELASTIC_STORE_3                                       */
/*   4 = XCON_ELASTIC_STORE_4                                       */
/*   5 = XCON_ELASTIC_STORE_5                                       */
/*   6 = XCON_ELASTIC_STORE_6                                       */
/*   7 = XCON_ELASTIC_STORE_7                                       */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  T41_t                         *pDev = NULL;
  volatile cs_reg               *pReg;    /* pointer to recenter config register */
  TEN_XCON_ES_RECENTER_CONFIG_t  dReg;    /* recenter config register data       */
  TEN_XCON_ES_INTSTATUS_t        dInt;    /* es interrupt register data          */

  cs_status rtn  = CS_OK;
  cs_char8 *func = "ten_xcon_es_reset_level_min_max";  
  cs_uint8  es_f = 0;  /* id of first es affected */
  cs_uint8  es_l = 0;  /* id of last  es affected */
  cs_uint8  es_i = 0;  /* es index */

  TEN_DEV_COMMON_VALIDATE (dev_id, pDev, CS_ERROR);
 
  switch (module_num) {
    case TEN_MODULE_A :           /* es_f is 0 or 4, es_l is 3 or 7 */
    case TEN_MODULE_B :
      es_f = XCON_ELASTIC_STORE_0 + (module_num * XCON_ELASTIC_STORE_4);
      es_l = XCON_ELASTIC_STORE_3 + (module_num * XCON_ELASTIC_STORE_4);
      break;

    case TEN_MODULE_A_AND_B :
      es_f = XCON_ELASTIC_STORE_0;
      es_l = XCON_ELASTIC_STORE_7;
      break;

    case TEN_MODULE_NULL :
      TEN_XCON_VALIDATE_ES_RANGE      /* <<<<<<  EARLY EXIT ON ERROR <<<<<<< */
      es_f = es_num;
      es_l = es_num;
      break;

    default :
      CS_HNDL_ERROR(dev_id, ETEN_MOD_INVALID_USER_ARG, "%s(): Invalid module num %d", func, module_num);
      return CS_ERROR;                /* <<<<<<  EARLY EXIT ON ERROR <<<<<<< */
      break;
  }

  /* reset and restart recenter min/max collection */
  TEN_DEV_LOCK(dev_id, TEN_ID_XCON);
  for (es_i = es_f ; es_i <= es_l; es_i++) {
    dInt.wrd = TEN_REG_READ(TEN_XCON_ES_INST_REG_ADDR(pDev, INTSTATUS, es_i));
    if (dInt.bf.AMPLITUDE_RECENTERs == 0) {
      pReg     = TEN_XCON_ES_INST_REG_ADDR(pDev, RECENTER_CONFIG, es_i);
      dReg.wrd = TEN_REG_READ(pReg);
      if (dReg.bf.MEASURE_EN != 0) {
        dReg.bf.MEASURE_EN = 0;
        TEN_REG_WRITE(pReg, dReg.wrd);
      }
      dReg.bf.MEASURE_EN = 1;
      TEN_REG_WRITE(pReg, dReg.wrd);
    }
    else {
      CS_HNDL_ERROR(dev_id, ETEN_DRVR_UNEXPECTED_RESULT, "%s(): Can't reset es %d min/max, amp recenter in progress", func, es_i);
    }
  }
  TEN_DEV_UNLOCK(dev_id, TEN_ID_XCON);

  return (rtn);
}

/* Bugzilla 27270 End, Amplitude Recentering, T41 release 5.4       */

/* Bugzilla 29751 Start */
/********************************************************************/
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : XCON                                                */
/* CHIP       : Tenabo                                              */
cs_status ten_xcon_es_pp40g_reset_t41(cs_uint16 module_id)
/* INPUTS     : o Module Id                                         */
/*                                                                  */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK if ready, 1 if not ready, or CS_ERROR         */
/* DESCRIPTION:                                                     */
/* Reads ES registers for recentering to determine if the           */
/* measurement period has ended and recentering config is complete. */
/*                                                                  */
/* [module_id] parameter specifies line's module ID                 */
/* 16 devices can be registered and module bit indicates line       */
/* or client side of the registered device. The registered device    */
/* is identified by the dev_id bits specified below                 */
/*   Bits 11:8 – dev_id, Bits 7:1 – don’t care, Bit 0 – module      */
/*                                                                  */
/********************************************************************/
{
  cs_uint16 dev_id;
  T41_t *pDev = NULL;
  cs_status rtn = CS_OK;
  cs_char8 *func = "ten_xcon_es_pp40g_reset_t41";  

  TEN_MOD_COMMON_VALIDATE (module_id, pDev, CS_ERROR);
 
  dev_id = TEN_MOD_ID_TO_DEV_ID (module_id);
  CS_PRINT("%s()  %s\n", func, ten_module_strings[module_id&1]);

  /* Reset the 4 XCON Elastic Stores */
  rtn |= ten_xcon_glb_pp40g_config_t41 (dev_id, module_id, XCON_GLB_PP40G_CFG_RESET, CS_ENABLE);
  rtn |= ten_xcon_glb_pp40g_config_t41 (dev_id, module_id, XCON_GLB_PP40G_CFG_RESET, CS_DISABLE);

  /* Recenter the 4 XCON Elastic Stores */
  rtn |= ten_xcon_glb_pp40g_config_t41 (dev_id, module_id, XCON_GLB_PP40G_CFG_RECENTER, CS_ENABLE);
  rtn |= ten_xcon_glb_pp40g_config_t41 (dev_id, module_id, XCON_GLB_PP40G_CFG_RECENTER, CS_DISABLE);

 #if 0
  /* Clear bit from initial setup */
  rtn |= ten_n40g_gbl4x_gblint (module_id, TEN_INT_CLEAR, TEN_N40G_GBL4X_GBLINT_TXDSKERR);
  TEN_MDELAY(6); /* 0.000125 seconds wait for a Sonet frame */

  if (ten_n40g_gbl4x_gblint (module_id, TEN_INT_READ, TEN_N40G_GBL4X_GBLINT_TXDSKERR)) {
    /* N40G has detected deskew error is persistent, so force recync frame alignment in sadeco */
    CS_PRINT("%s() TXDSKERR is persistent for %s, so resync PP40G deskew!\n", func, ten_module_strings[module_id & 1]);
  }
 #endif 
  
  return (rtn);
}

/********************************************************************/
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : XCON                                                */
/* CHIP       : Tenabo                                              */
cs_uint16 ten_get_xcon_es_source_t41(cs_uint16 dev_id, cs_uint16 es_num)
/* INPUTS     : o ES ID                                             */
/*                                                                  */
/* OUTPUTS    : ----                                                */
/* RETURNS    : Elastic Store source  chnl_num                      */
/* DESCRIPTION:                                                     */
/* Reads selected XCON ES Source registers                          */
/*                                                                  */
/* The [es_num] parameter is specified as:                          */
/*   0 = XCON_ELASTIC_STORE_0                                       */
/*   1 = XCON_ELASTIC_STORE_1                                       */
/*   2 = XCON_ELASTIC_STORE_2                                       */
/*   3 = XCON_ELASTIC_STORE_3                                       */
/*   4 = XCON_ELASTIC_STORE_4                                       */
/*   5 = XCON_ELASTIC_STORE_5                                       */
/*   6 = XCON_ELASTIC_STORE_6                                       */
/*   7 = XCON_ELASTIC_STORE_7                                       */
/*                                                                  */
/* The [chnl_num] parameter is specified as:                        */
/*   0 = XCON_MODULE_A_CHANNEL_1                                    */
/*   1 = XCON_MODULE_A_CHANNEL_2                                    */
/*   2 = XCON_MODULE_A_CHANNEL_3                                    */
/*   3 = XCON_MODULE_A_CHANNEL_4                                    */
/*   4 = XCON_MODULE_B_CHANNEL_1                                    */
/*   5 = XCON_MODULE_B_CHANNEL_2                                    */
/*   6 = XCON_MODULE_B_CHANNEL_3                                    */
/*   7 = XCON_MODULE_B_CHANNEL_4                                    */
/*                                                                  */
/********************************************************************/
{
  TEN_XCON_GLB_ES_SOURCE_SELECT_0_t tmp_glb_es_source_select;
  T41_t *pDev = NULL;
  cs_char8 *func = "ten_get_xcon_es_source_t41";  

  TEN_DEV_COMMON_VALIDATE(dev_id, pDev, CS_ERROR);

  CS_PRINT("%s()  %s\n", func, ten_xcon_es_num_strings[es_num]);

  tmp_glb_es_source_select.wrd = TEN_REG_READ(TEN_XCON_ES_SOURCE_SEL_REG_ADDR(pDev, es_num));

  return (tmp_glb_es_source_select.bf.SOURCE);
}
/* Bugzilla 29751 End */


/* Bugzilla 30990, amp recenter ehancement, additional validation.  */
/********************************************************************/
/* Internal helper function:                                        */
/*   ten_xcon_es_get_pkt_mode()                                     */
/********************************************************************/
/*                                                                  */
/* INPUTS     : o Device                                            */
/*              o Elastic Store Id                                  */
/*                                                                  */
/* RETURNS    : TRUE (1) for packet mode, FALSE otherwise           */
/*                                                                  */
/* DESCRIPTION:                                                     */
/*                                                                  */
/* Can be used to validate configuration compatibility with ES      */
/* packet mode.                                                     */
/********************************************************************/
cs_uint16 ten_xcon_es_get_pkt_mode(cs_uint16 dev_id, ten_xcon_es_num_t es_num)
#ifndef TEN_SUSPECT_LAB_READ_ISSUE
{
  TEN_XCON_ES_CONFIG_t tmp_xcon_es_config;
  T41_t    *pDev = NULL;
  cs_char8 *func = "ten_xcon_es_get_pkt_mode";  

  /* Parameter Checking */
  if(es_num > XCON_ELASTIC_STORE_7) { 
    CS_HNDL_ERROR(dev_id, ETEN_DEV_INVALID_USER_ARG, "%s() es_num %d invalid", func, es_num); 
    return CS_ERROR; 
  }

  TEN_DEV_COMMON_VALIDATE(dev_id, pDev, CS_ERROR);
  tmp_xcon_es_config.wrd  = TEN_REG_READ(TEN_XCON_ES_INST_REG_ADDR(pDev, CONFIG, es_num));

  return ( (cs_uint16) tmp_xcon_es_config.bf.PKT_MODE);
}
#else
{
  TEN_XCON_ES_CONFIG_t tmp_xcon_es_config;
  volatile cs_reg *tmp_addr;
  cs_uint16      ii;
  cs_uint16     jj;
  cs_int16     pktm = 0;
  T41_t      *pDev = NULL;
  cs_char8  *func = "ten_xcon_es_get_pkt_mode";  

  /* Parameter Checking */
  if(es_num > XCON_ELASTIC_STORE_7) { 
    CS_HNDL_ERROR(dev_id, ETEN_DEV_INVALID_USER_ARG, "%s() es_num %d invalid", func, es_num); 
    return CS_ERROR; 
  }

  TEN_DEV_COMMON_VALIDATE(dev_id, pDev, CS_ERROR);
  tmp_addr =  TEN_XCON_ES_INST_REG_ADDR(pDev, CONFIG, es_num);

  TEN_DEV_LOCK(dev_id, TEN_ID_XCON);

  /* Todo: loop validates reg read for lab */
  for (ii=0; ii<3; ii++) {
    for (jj=50; jj; jj--) {}
    tmp_xcon_es_config.wrd  = TEN_REG_READ(tmp_addr);
    pktm +=tmp_xcon_es_config.bf.PKT_MODE;
  }
  TEN_DEV_UNLOCK(dev_id, TEN_ID_XCON);

  return ( (pktm < 2) ? 0 : 1);
}
#endif

/* Bugzilla 30990, amp recenter ehancement, reduced reg ops.        */
/********************************************************************/
/* $rtn_hdr_start  ENABLE/DISABLE ES CONFIG, MULTI                  */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : XCON                                                */
/* CHIP       : Tenabo                                              */
cs_status ten_xcon_es_config_multi_t41(cs_uint16         dev_id, 
                                       ten_xcon_es_num_t es_num,
                                       cs_reg            mask,
                                       cs_reg            ctl)
/* INPUTS     : o Device Id                                         */
/*              o Elastic Store Id                                  */
/*              o Enable Number                                     */
/*              o Control                                           */
/*                                                                  */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Enables or disables ES configuration options.                    */
/*                                                                  */
/* The [es_num] parameter is specified as:                          */
/*   0 = XCON_ELASTIC_STORE_0                                       */
/*   1 = XCON_ELASTIC_STORE_1                                       */
/*   2 = XCON_ELASTIC_STORE_2                                       */
/*   3 = XCON_ELASTIC_STORE_3                                       */
/*   4 = XCON_ELASTIC_STORE_4                                       */
/*   5 = XCON_ELASTIC_STORE_5                                       */
/*   6 = XCON_ELASTIC_STORE_6                                       */
/*   7 = XCON_ELASTIC_STORE_7                                       */
/*   0xFF = XCON_ELASTIC_STORE_ALL                                  */
/*                                                                  */
/* The [mask] parameter is specified as:                            */
/* This is a mask of type TEN_XCON_ES_CONFIG_t, where each bit      */
/* field to be modified is set, and each to be left alone is        */
/* clear.                                                           */
/*                                                                  */
/* The [ctl] parameter is specified as:                             */
/* This is a word of type TEN_XCON_ES_CONFIG_t, where each          */
/* bit-field to be modified is of the desired value. Bit-fields     */
/* are only modified if their corresponding field in 'mask' is      */
/* non-zero.                                                        */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  TEN_XCON_ES_CONFIG_t tmp_xcon_es_config;
  volatile cs_reg *tmp_addr;
  cs_uint16      ii;
  cs_int16     ret_val = CS_OK;
  T41_t      *pDev    = NULL;
  cs_char8  *func    = "ten_xcon_es_config_multi_t41";  

  /* Parameter Checking */
  if((es_num > XCON_ELASTIC_STORE_7) && (es_num != XCON_ELASTIC_STORE_ALL)) { 
    CS_HNDL_ERROR(dev_id, ETEN_DEV_INVALID_USER_ARG, "%s() es_num %d invalid", func, es_num); 
    return CS_ERROR; 
  }
  
  /* Note: Mask can be used as a true bit mask because no         */
  /* bitfields in TEN_XCON_ES_CONFIG_t are wider than one bit.    */

  /* Register setting */
  TEN_DEV_COMMON_VALIDATE(dev_id, pDev, CS_ERROR);
  TEN_DEV_LOCK(dev_id, TEN_ID_XCON);

  for (ii=0; ii<TEN_XCON_ES_COUNT; ii++) {
    if ((es_num == ii) || (es_num == XCON_ELASTIC_STORE_ALL)) {
      tmp_addr =  TEN_XCON_ES_INST_REG_ADDR(pDev, CONFIG, ii);

      tmp_xcon_es_config.wrd  = TEN_REG_READ(tmp_addr);
      tmp_xcon_es_config.wrd &= ~mask;
      tmp_xcon_es_config.wrd |= (mask & ctl);
      TEN_REG_WRITE(tmp_addr, tmp_xcon_es_config.wrd);
    }
  }

  TEN_DEV_UNLOCK(dev_id, TEN_ID_XCON);

  return (ret_val);
}


/* Bugzilla 30990, Datapath reset during reg config to support  */
/* Amplitude Recenter at marginal sysclock frequencies. These   */
/* new functions don't use delays after reset release, which    */
/* aren't necessary for these resets. This keeps up to 100ms    */
/* off recenter time as compared to using the block reset       */
/* facility.                                                    */
/****************************************************************/
/* XCON ELASTIC STORE DATAPATH RESET WITH NO DELAY              */
/* CATEGORY   : Helper function                                 */
/* ACCESS     : Local                                           */
/* INPUTS     : o Device Id                                     */
/*              o Elastic Store Id                              */
/*              o Reset Control                                 */
/*                                                              */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* Control XCON sub-block logic reset for the specified         */
/* datapath direction.                                          */
/*                                                              */
/* The [es_num] parameter is specified as:                      */
/*   0 = XCON_ELASTIC_STORE_0                                   */
/*   1 = XCON_ELASTIC_STORE_1                                   */
/*   2 = XCON_ELASTIC_STORE_2                                   */
/*   3 = XCON_ELASTIC_STORE_3                                   */
/*   4 = XCON_ELASTIC_STORE_4                                   */
/*   5 = XCON_ELASTIC_STORE_5                                   */
/*   6 = XCON_ELASTIC_STORE_6                                   */
/*   7 = XCON_ELASTIC_STORE_7                                   */
/*   0xFF = XCON_ELASTIC_STORE_ALL                              */
/*                                                              */
/* The [act] parameter specifies the reset option and is one    */
/* of the following:                                            */
/*   0 = CS_RESET_DEASSERT                                      */
/*   1 = CS_RESET_ASSERT                                        */
/*                                                              */
/****************************************************************/
cs_status ten_xcon_es_datapath_reset_quick(cs_uint16 dev_id, 
                                           ten_xcon_es_num_t es_num,
                                           cs_reset_action_t act)
{
  cs_uint16 ii;
  TEN_XCON_ES_RESET_t tmp_es_reset;
  T41_t  *pDev = NULL;

  /* Parameter Checking */
  if((es_num > XCON_ELASTIC_STORE_7) && (es_num != XCON_ELASTIC_STORE_ALL)) { 
    CS_HNDL_ERROR(dev_id, ETEN_DEV_INVALID_USER_ARG, 
                             ": ten_xcon_es_datapath_reset_quick Param2"); 
    return CS_ERROR; 
  }
  if(act > CS_RESET_ASSERT) { 
    CS_HNDL_ERROR(dev_id, ETEN_DEV_INVALID_USER_ARG, 
                             ": ten_xcon_es_datapath_reset_quick Param3"); 
    return CS_ERROR; 
  }

  /* Register setting */
  TEN_DEV_COMMON_VALIDATE(dev_id, pDev, CS_ERROR);
  TEN_DEV_LOCK(dev_id, TEN_ID_XCON);

  for (ii=0; ii<TEN_XCON_ES_COUNT; ii++) {
    if ((es_num == ii) || (es_num == XCON_ELASTIC_STORE_ALL)) {
      tmp_es_reset.wrd = 0;
      tmp_es_reset.bf.RESET = (act==CS_RESET_ASSERT) ? 1 : 0;
      
      TEN_REG_WRITE(TEN_XCON_ES_INST_REG_ADDR(pDev, RESET, ii), tmp_es_reset.wrd);
    }
  }

  TEN_DEV_UNLOCK(dev_id, TEN_ID_XCON);

  /* Allow time for datapath restoration */
  ten_udelay_hi_res((act==CS_RESET_DEASSERT) ? 50 : 5 );

  return (CS_OK);
}


/* Bugzilla 30990, Datapath reset during reg config to support  */
/* Amplitude Recenter at marginal sysclock frequencies. These   */
/* new functions don't use delays after reset release, which    */
/* aren't necessary for these resets. This keeps up to 100ms    */
/* off recenter time as compared to using the block reset       */
/* facility.                                                    */
/****************************************************************/
/* XCON CONTROL DATAPATH RESET with no delay                    */
/* CATEGORY   : helper function                                 */
/* ACCESS     : Private                                         */
/* INPUTS     : o Device Id                                     */
/*              o Reset Control                                 */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* Control reset on the cross connect's (XCON) datapath.        */
/*                                                              */
/* The [act] parameter specifies the reset option and is one    */
/* of the following:                                            */
/*   0 = CS_RESET_DEASSERT                                      */
/*   1 = CS_RESET_ASSERT                                        */
/****************************************************************/
cs_status ten_xcon_datapath_reset_quick(cs_uint16 dev_id, cs_reset_action_t act)
{
  TEN_XCON_GLB_RESET_t tmp_glb_reset;
  T41_t *pDev = NULL;

  /* Parameter Checking */
  if(act > CS_RESET_ASSERT) { 
    CS_HNDL_ERROR(dev_id, ETEN_DEV_INVALID_USER_ARG, 
                             ": ten_xcon_datapath_reset_quick Param2"); 
    return CS_ERROR; 
  }

  /* Register setting */
  TEN_DEV_COMMON_VALIDATE(dev_id, pDev, CS_ERROR);
  TEN_DEV_LOCK(dev_id, TEN_ID_XCON);

  tmp_glb_reset.wrd = 0;
  tmp_glb_reset.bf.ACTIVE_RESET = (act==CS_RESET_ASSERT) ? 1 : 0;
  TEN_REG_WRITE(TEN_XCON_REG_ADDR(pDev, RESET), tmp_glb_reset.wrd);

  TEN_DEV_UNLOCK(dev_id, TEN_ID_XCON);

  return (CS_OK);
}


/********************************************************************/
/* XCON ES AMPLITUDE RECENTER 40G CB                                */
/* CATEGORY   : Function                                            */
/* ACCESS     : Private                                             */
/* BLOCK      : XCON                                                */
/* CHIP       : Tenabo                                              */
/* INPUTS     : o Device Id                                         */
/*              o Module Number (overloaded in release 5.5)         */
/*              o Margin Lower                                      */
/*              o Margin Upper                                      */
/*              o Correction Lower                                  */
/*              o Correction Upper                                  */
/*              o Duration                                          */
/*              o System Clock Frequency                            */
/*                                                                  */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Sets up the specified module's ES registers for recentering      */
/* based on ES amplitude measurements over a specied duration. The  */
/* ES depth is a function of measured amplitude and specified       */
/* margins. Then recenters and enables circuit thresholds.          */
/*                                                                  */
/* DOES NOT start a recenter if setup fails.                        */
/* DOES NOT enable circuit thresholds if recenter fails             */
/*                                                                  */
/* The [module_num_ov] parameter is overloaded:                     */
/*   Module number bit-OR'd with recovery mode, where elastic       */
/*   store ID can be                                                */
/*     0 = TEN_MODULE_A (ES # 0-3)                                  */
/*     1 = TEN_MODULE_B (ES # 4-7)                                  */
/*   and (new for 5.5) recovery mode is                             */
/*     0x00 = TEN_XCON_ES_RECENTER_RECOVERY_DFLT (Default):         */
/*       Default is 'none' for backward compatibility.              */
/*     0x40 = TEN_XCON_ES_RECENTER_RECOVERY_AUTO (Recommended):     */
/*       Framer and upper/lower ES violation event handlers kick    */
/*       off recenter, which completes using recenter status        */
/*       polling and system timers.                                 */
/*                                                                  */
/* The [margin_lower] parameter is specified as:                    */
/*   0..0x1fff, the amount of lwoer margin to reserve for an        */
/*   amplitude recenter                                             */
/*                                                                  */
/* The [margin_upper] parameter is specified as:                    */
/*   0..0x1fff, the amount of upper margin to reserve for an        */
/*   amplitude recenter                                             */
/*                                                                  */
/* The [correct_lower] parameter is specified as:                   */
/*   0..0x01ff, the amount to increase XCON_ES_CIRCUIT_THRESHOLD_   */
/*   LOWER by after computing the new threshold following an        */
/*   amplitude recenter.                                            */
/*                                                                  */
/* The [correct_upper] parameter is specified as:                   */
/*   0..0x01ff, the amount to decrease XCON_ES_CIRCUIT_THRESHOLD_   */
/*   UPPER by after computing the new threshold following an        */
/*   amplitude recenter.                                            */
/*                                                                  */
/* The [duration] parameter is specified as:                        */
/*    1..157~168 milliseconds, depending on sysclk_freq             */
/*    Number of milliseconds to measure depth for Amplitude         */
/*     Recentering.                                                 */
/*                                                                  */
/* The [sysclk_freq] parameter is specified as:                     */
/*   the sysclk frequency in hertz, i.e., 425000000                 */
/*                                                                  */
/* The [cb_rw] parameter is specified as:                           */
/*   XCON_ES_UPDATE_CB_FALSE to not update the control block        */
/*   XCON_ES_UPDATE_CB_TRUE  to update the control block            */
/*                                                                  */
/********************************************************************/
cs_status ten_xcon_es_amplitude_recenter_40g_cb(cs_uint16 dev_id,
                                                cs_uint8  module_num_ov,
                                                cs_uint16 margin_lower,
                                                cs_uint16 margin_upper,
                                                cs_uint16 correct_lower,
                                                cs_uint16 correct_upper,
                                                cs_uint8  duration,
                                                cs_uint32 sysclk_freq,
                                                cs_uint16 cb_rw)
{
  /* cs_uint16 recovery;                Release 5.5, Bugzilla 27270 */
  cs_status stat = CS_OK;
  char     *func = "ten_hl_xcon_es_amplitude_recenter_40g_t41";
  cs_uint8  es_first = 0;
  cs_uint8  es_last  = 7;
  cs_uint8  ex_idx   = 0;
  cs_uint8  module_num = module_num_ov & ~TEN_XCON_ES_RECENTER_RECOVERY_MASK;

  if (CS_ERROR == ten_xcon_es_setup_amplitude_recenter_40g_cb(dev_id, module_num_ov,
                                                         margin_lower, margin_upper,
                                                        correct_lower, correct_upper,
                                                             duration, sysclk_freq, cb_rw) ) {
    CS_HNDL_ERROR(dev_id, ETEN_DRVR_UNEXPECTED_RESULT, ": %s( mod_ov 0x%X), %s", func, module_num_ov, str_ar_setup_failed_);
    return CS_ERROR;
  }

  ten_xcon_es_sadeco_fifo_reset_quick(dev_id, module_num, CS_RESET_TOGGLE);
  stat |= ten_xcon_40g_recenter_t41( dev_id, module_num);

  if (CS_OK == ten_xcon_es_check_amplitude_recenter_40g_t41(dev_id, module_num)) {
 
    /* Get range of affected es. Mod ID error checking done by setup above */ 
    if (module_num == TEN_MODULE_A) {
      es_last  = 3;
    }
    else if (module_num == TEN_MODULE_B) {
      es_first = 4;
    }
    
    for (ex_idx = es_first; ex_idx <= es_last; ex_idx++) {
      stat |= ten_xcon_es_recenter_enables_t41(dev_id, ex_idx, XCON_ES_RECENTER_UPPER_VIOLATION_EN, CS_ENABLE); 
      stat |= ten_xcon_es_recenter_enables_t41(dev_id, ex_idx, XCON_ES_RECENTER_LOWER_VIOLATION_EN, CS_ENABLE); 
    }
  }
  else {
    CS_HNDL_ERROR(dev_id, ETEN_DRVR_UNEXPECTED_RESULT, ": %s( mod %d), %s", func, module_num, str_amprecent_failed_);
    stat = CS_ERROR;
  }
 
  return (stat);
}


/********************************************************************/
/* XCON ES AMPLITUDE RECENTER T41                                   */
/* CATEGORY   : Function                                            */
/* ACCESS     : Private                                             */
/* BLOCK      : XCON                                                */
/* CHIP       : Tenabo                                              */
/* INPUTS     : o Device Id                                         */
/*              o Elastic Store Id  (overloaded in Release 5.5)     */
/*              o Margin Lower                                      */
/*              o Margin Upper                                      */
/*              o Correction Lower                                  */
/*              o Correction Upper                                  */
/*              o Duration                                          */
/*              o System Clock Frequency                            */
/*                                                                  */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Sets up the specified module's ES registers for recentering      */
/* based on ES amplitude measurements over a specied duration. The  */
/* ES depth is a function of measured amplitude and specified       */
/* margins. Then recenters and enables circuit thresholds.          */
/*                                                                  */
/* DOES NOT start a recenter if setup fails.                        */
/* DOES NOT enable circuit thresholds if recenter fails             */
/*                                                                  */
/* The [es_num_ovl] parameter is overloaded:                        */
/*   Elastic store ID bit-OR'd with recovery mode, where elastic    */
/*   store ID can be                                                */
/*     0 = XCON_ELASTIC_STORE_0                                     */
/*     1 = XCON_ELASTIC_STORE_1                                     */
/*     2 = XCON_ELASTIC_STORE_2                                     */
/*     3 = XCON_ELASTIC_STORE_3                                     */
/*     4 = XCON_ELASTIC_STORE_4                                     */
/*     5 = XCON_ELASTIC_STORE_5                                     */
/*     6 = XCON_ELASTIC_STORE_6                                     */
/*     7 = XCON_ELASTIC_STORE_7                                     */
/*   and (new for 5.5) recovery mode is                             */
/*     0x00 = TEN_XCON_ES_RECENTER_RECOVERY_DFLT (Default):         */
/*       Default is 'none' for backward compatibility.              */
/*     0x40 = TEN_XCON_ES_RECENTER_RECOVERY_AUTO (Recommended):     */
/*       Framer and upper/lower ES violation event handlers kick    */
/*       off recenter, which completes using recenter status        */
/*       polling and system timers.                                 */
/*                                                                  */
/* The [margin_lower] parameter is specified as:                    */
/*   0..0x1fff, the amount of lwoer margin to reserve for an        */
/*   amplitude recenter                                             */
/*                                                                  */
/* The [margin_upper] parameter is specified as:                    */
/*   0..0x1fff, the amount of upper margin to reserve for an        */
/*   amplitude recenter                                             */
/*                                                                  */
/* The [correct_lower] parameter is specified as:                   */
/*   0..0x01ff, the amount to increase XCON_ES_CIRCUIT_THRESHOLD_   */
/*   LOWER by after computing the new threshold following an        */
/*   amplitude recenter.                                            */
/*                                                                  */
/* The [correct_upper] parameter is specified as:                   */
/*   0..0x01ff, the amount to decrease XCON_ES_CIRCUIT_THRESHOLD_   */
/*   UPPER by after computing the new threshold following an        */
/*   amplitude recenter.                                            */
/*                                                                  */
/* The [duration] parameter is specified as:                        */
/*    1..157~168 milliseconds, depending on sysclk_freq             */
/*    Number of milliseconds to measure depth for Amplitude         */
/*     Recentering.                                                 */
/*                                                                  */
/* The [sysclk_freq] parameter is specified as:                     */
/*   the sysclk frequency in hertz, i.e., 425000000                 */
/*                                                                  */
/* The [cb_rw] parameter is specified as:                           */
/*   XCON_ES_UPDATE_CB_FALSE to not update the control block        */
/*   XCON_ES_UPDATE_CB_TRUE  to update the control block            */
/*                                                                  */
/********************************************************************/
cs_status ten_xcon_es_amplitude_recenter_10g_cb( cs_uint16 dev_id,
                                                    ten_xcon_es_num_t es_num_ovl,
                                                    cs_uint16 margin_lower,
                                                    cs_uint16 margin_upper,
                                                    cs_uint16 correct_lower,
                                                    cs_uint16 correct_upper,
                                                    cs_uint8  duration,
                                                    cs_uint32 sysclk_freq,
                                                    cs_uint16 cb_rw)
{
  /* cs_uint16 recovery;                Release 5.5, Bugzilla 27270 */
  cs_status stat = CS_OK;
  char     *func = "ten_hl_xcon_es_amplitude_recenter_t41";
  ten_xcon_es_num_t es_num = es_num_ovl & ~TEN_XCON_ES_RECENTER_RECOVERY_MASK;

  if (CS_ERROR == ten_xcon_es_setup_amplitude_recenter_10g_cb(dev_id, es_num_ovl,
                                                     margin_lower, margin_upper,
                                                    correct_lower, correct_upper,
                                                    duration, sysclk_freq, cb_rw) ) {
    CS_HNDL_ERROR(dev_id, ETEN_DRVR_UNEXPECTED_RESULT, ": %s( es_ovl 0x%X), %s", func, es_num_ovl, str_ar_setup_failed_);
    return CS_ERROR;
  }

  stat |= ten_xcon_es_recenter_t41( dev_id, es_num);

  if (CS_OK == ten_xcon_es_check_amplitude_recenter_t41(dev_id, es_num)) {
 
    stat |= ten_xcon_es_recenter_enables_t41(dev_id, es_num, XCON_ES_RECENTER_UPPER_VIOLATION_EN, CS_ENABLE); 
    stat |= ten_xcon_es_recenter_enables_t41(dev_id, es_num, XCON_ES_RECENTER_LOWER_VIOLATION_EN, CS_ENABLE); 
  }
  else {
    CS_HNDL_ERROR(dev_id, ETEN_DRVR_UNEXPECTED_RESULT, ": %s( es %d), %s", func, es_num, str_amprecent_failed_);
    stat = CS_ERROR;
  }
 
  return (stat);
}


/********************************************************************/
/* XCON ES AMPLITUDE RECENTER WITH FPA 40G T41                      */
/* CATEGORY   : Function                                            */
/* ACCESS     : Private                                             */
/* BLOCK      : XCON                                                */
/* CHIP       : Tenabo                                              */
/* INPUTS     : o Device Id                                         */
/*              o Module Number (overloaded in release 5.5)         */
/*              o Static Depth                                      */
/*              o Circuit Threshold Lower                           */
/*              o Circuit Threshold Upper                           */
/*                                                                  */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Sets up ES registers for amplitude recentering with frame pulse  */
/* alignment. The specified depth and circuit thresholds are used   */
/* instead of their calculated counterparts.                        */
/*                                                                  */
/* Then recenters and enables circuit thresholds.                   */
/*                                                                  */
/* DOES NOT start a recenter if setup fails.                        */
/* DOES NOT enable circuit thresholds if recenter fails             */
/*                                                                  */
/* The [module_num_ov] parameter is overloaded:                     */
/*   Module number bit-OR'd with recovery mode, where elastic       */
/*   store ID can be                                                */
/*     0 = TEN_MODULE_A (ES # 0-3)                                  */
/*     1 = TEN_MODULE_B (ES # 4-7)                                  */
/*   and (new for 5.5) recovery mode is                             */
/*     0x00 = TEN_XCON_ES_RECENTER_RECOVERY_DFLT (Default):         */
/*       Default is 'none' for backward compatibility.              */
/*     0x40 = TEN_XCON_ES_RECENTER_RECOVERY_AUTO (Recommended):     */
/*       Framer and upper/lower ES violation event handlers kick    */
/*       off recenter, which completes using recenter status        */
/*       polling and system timers.                                 */
/*                                                                  */
/* The [static_depth] parameter is specified as:                    */
/*    0..0x1fff, static_depth is used for an amplitude recenter     */
/*    instead of a calculated depth.                                */
/*                                                                  */
/* The [circuit_th_lower] parameter is specified as:                */
/*   1..0x1fff, Minimum desired amount of data (in units of 4       */
/*   bytes) in the FIFO. Note: LEVEL must be smaller than           */
/*   IML_THRESH but no less than 1.                                 */
/*                                                                  */
/* The [circuit_th_upper] parameter is specified as:                */
/*   1..0x1ffe, Maximum desired amount of data (in units of 4       */
/*   bytes) in the FIFO. Note: LEVEL must be larger than            */
/*   IML_THRESH but no larger than 8190.                            */
/*                                                                  */
/* The [cb_rw] parameter is specified as:                           */
/*   XCON_ES_UPDATE_CB_FALSE to not update the control block        */
/*   XCON_ES_UPDATE_CB_TRUE  to update the control block            */
/*                                                                  */
/********************************************************************/
cs_status ten_xcon_es_amplitude_recenter_with_fpa_40g_cb(cs_uint16 dev_id,
                                           ten_xcon_es_num_t module_num_ov,
                                           cs_uint16 static_depth,
                                           cs_uint16 circuit_th_lower,
                                           cs_uint16 circuit_th_upper,
                                           cs_uint16 cb_rw)
{
  /* cs_uint16 recovery;                Release 5.5, Bugzilla 27270 */
  cs_status stat = CS_OK;
  char     *func = "ten_hl_xcon_es_amplitude_recenter_with_fpa_40g_t41";
  cs_uint8  es_first = 0;
  cs_uint8  es_last  = 7;
  cs_uint8  ex_idx   = 0;
  cs_uint8  module_num = module_num_ov & ~TEN_XCON_ES_RECENTER_RECOVERY_MASK;

  if (CS_ERROR == ten_xcon_es_setup_amplitude_recenter_with_fpa_40g_cb(dev_id, module_num_ov,
                                                                       static_depth, circuit_th_lower, 
                                                                       circuit_th_upper, cb_rw) ) {
    CS_HNDL_ERROR(dev_id, ETEN_DRVR_UNEXPECTED_RESULT, ": %s( mod 0x%X), %s", func, module_num_ov, str_ar_setup_failed_);
    return CS_ERROR;
  }

  /* kick off the recenter. Returns when complete or times out */
  stat |= ten_xcon_40g_recenter_t41( dev_id, module_num);

  /* Get range of affected es. Module_num range check handled by ten_xcon_40g_recenter_t41 */ 
  if (module_num == TEN_MODULE_A) {
    es_last  = 3;
  }
  else if (module_num == TEN_MODULE_B) {
    es_first = 4;
  }

  /* validate threshold args */
  if ( (circuit_th_lower == 0) || (circuit_th_lower > 0x1fff) ) {
    stat |= CS_ERROR;
    CS_HNDL_ERROR(dev_id, ETEN_MOD_INVALID_USER_ARG, ": 40g_recenter_with_fpa_t41(mod %d), using circuit_th_lower default %x instead of %d",
                                                      module_num, TEN_XCON_ES_CIRCUIT_THRESHOLD_LOWER_dft, circuit_th_lower);
    circuit_th_lower = TEN_XCON_ES_CIRCUIT_THRESHOLD_LOWER_dft;
  }
  if ( (circuit_th_upper == 0) || (circuit_th_upper > 0x1ffe) ) {
    stat |= CS_ERROR;
    CS_HNDL_ERROR(dev_id, ETEN_MOD_INVALID_USER_ARG, ": 40g_recenter_with_fpa_t41(mod %d), using circuit_th_upper default %x instead of %d",
                                                      module_num, TEN_XCON_ES_CIRCUIT_THRESHOLD_UPPER_dft, circuit_th_upper);
    circuit_th_upper = TEN_XCON_ES_CIRCUIT_THRESHOLD_UPPER_dft;
  }

  /* refresh and enable thresholds */
  if (CS_OK == ten_xcon_es_check_amplitude_recenter_40g_t41(dev_id, module_num)) {
 
    for (ex_idx = es_first; ex_idx <= es_last; ex_idx++) {
      stat |= ten_xcon_set_circuit_threshold_level_t41(dev_id, ex_idx, XCON_ES_RECENTER_AMPLITUDE,
                                                       XCON_ES_CIRCUIT_THRESHOLD_LOWER, -1, circuit_th_lower); 
      stat |= ten_xcon_set_circuit_threshold_level_t41(dev_id, ex_idx, XCON_ES_RECENTER_AMPLITUDE,
                                                       XCON_ES_CIRCUIT_THRESHOLD_UPPER, -1, circuit_th_upper); 
      stat |= ten_xcon_es_recenter_enables_t41(dev_id, ex_idx, XCON_ES_RECENTER_UPPER_VIOLATION_EN, CS_ENABLE); 
      stat |= ten_xcon_es_recenter_enables_t41(dev_id, ex_idx, XCON_ES_RECENTER_LOWER_VIOLATION_EN, CS_ENABLE); 
    }
  }
  else {
    CS_HNDL_ERROR(dev_id, ETEN_DRVR_UNEXPECTED_RESULT, ": %s( mod %d), %s", func, module_num, str_amprecent_failed_);
    stat = CS_ERROR;
  }
 
  return (stat);
}


/********************************************************************/
/* XCON ES AMPLITUDE RECENTER WITH FPA T41                          */
/* CATEGORY   : Helper                                              */
/* ACCESS     : Private                                             */
/* BLOCK      : XCON                                                */
/* CHIP       : Tenabo                                              */
/* INPUTS     : o Device Id                                         */
/*              o Elastic Store Id  (overloaded in Release 5.5)     */
/*              o Static Depth                                      */
/*              o Circuit Threshold Lower                           */
/*              o Circuit Threshold Upper                           */
/*                                                                  */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Sets up ES registers for amplitude recentering with frame pulse  */
/* alignment. The specified depth and circuit thresholds are used   */
/* instead of their calculated counterparts.                        */
/*                                                                  */
/* Then recenters and enables circuit thresholds.                   */
/*                                                                  */
/* DOES NOT start a recenter if setup fails.                        */
/* DOES NOT enable circuit thresholds if recenter fails             */
/*                                                                  */
/* The [es_num_ovl] parameter is overloaded:                        */
/*   Elastic store ID bit-OR'd with recovery mode, where elastic    */
/*   store ID can be                                                */
/*     0 = XCON_ELASTIC_STORE_0                                     */
/*     1 = XCON_ELASTIC_STORE_1                                     */
/*     2 = XCON_ELASTIC_STORE_2                                     */
/*     3 = XCON_ELASTIC_STORE_3                                     */
/*     4 = XCON_ELASTIC_STORE_4                                     */
/*     5 = XCON_ELASTIC_STORE_5                                     */
/*     6 = XCON_ELASTIC_STORE_6                                     */
/*     7 = XCON_ELASTIC_STORE_7                                     */
/*   and (new for 5.5) recovery mode is                             */
/*     0x00 = TEN_XCON_ES_RECENTER_RECOVERY_DFLT (Default):         */
/*       Default is 'none' for backward compatibility.              */
/*     0x40 = TEN_XCON_ES_RECENTER_RECOVERY_AUTO (Recommended):     */
/*       Framer and upper/lower ES violation event handlers kick    */
/*       off recenter, which completes using recenter status        */
/*       polling and system timers.                                 */
/*                                                                  */
/* The [static_depth] parameter is specified as:                    */
/*    0..0x1fff, static_depth is used for an amplitude recenter     */
/*    instead of a calculated depth.                                */
/*                                                                  */
/* The [circuit_th_lower] parameter is specified as:                */
/*   1..0x1fff, Minimum desired amount of data (in units of 4       */
/*   bytes) in the FIFO. Note: LEVEL must be smaller than           */
/*   IML_THRESH but no less than 1.                                 */
/*                                                                  */
/* The [circuit_th_upper] parameter is specified as:                */
/*   1..0x1ffe, Maximum desired amount of data (in units of 4       */
/*   bytes) in the FIFO. Note: LEVEL must be larger than            */
/*   IML_THRESH but no larger than 8190.                            */
/*                                                                  */
/* The [cb_rw] parameter is specified as:                           */
/*   XCON_ES_UPDATE_CB_FALSE to not update the control block        */
/*   XCON_ES_UPDATE_CB_TRUE  to update the control block            */
/*                                                                  */
/********************************************************************/
cs_status ten_xcon_es_amplitude_recenter_with_fpa_10g_cb(cs_uint16 dev_id,
                                                         ten_xcon_es_num_t es_num_ovl,
                                                         cs_uint16 static_depth,
                                                         cs_uint16 circuit_th_lower,
                                                         cs_uint16 circuit_th_upper,
                                                         cs_uint16 cb_rw)
{
  /* cs_uint16 recovery;                Release 5.5, Bugzilla 27270 */
  cs_status stat = CS_OK;
  char     *func = "ten_hl_xcon_es_amplitude_recenter_with_fpa_t41";
  ten_xcon_es_num_t es_num = es_num_ovl & ~TEN_XCON_ES_RECENTER_RECOVERY_MASK;

  if (CS_ERROR == ten_xcon_es_setup_amplitude_recenter_with_fpa_10g_cb(dev_id, es_num_ovl,
                                                              static_depth, circuit_th_lower,
                                                              circuit_th_upper, cb_rw) ) {
    CS_HNDL_ERROR(dev_id, ETEN_DRVR_UNEXPECTED_RESULT, ": %s( es 0x%X), %s", func, es_num_ovl, str_ar_setup_failed_);
    return CS_ERROR;
  }

  stat |= ten_xcon_es_recenter_t41( dev_id, es_num);

  /* validate threshold args */
  if ( (circuit_th_lower == 0) || (circuit_th_lower > 0x1fff) ) {
    stat |= CS_ERROR;
    CS_HNDL_ERROR(dev_id, ETEN_MOD_INVALID_USER_ARG, ": %s(es %d), using circuit_th_lower default %x instead of %d",
                                                      func, es_num, TEN_XCON_ES_CIRCUIT_THRESHOLD_LOWER_dft, circuit_th_lower);
    circuit_th_lower = TEN_XCON_ES_CIRCUIT_THRESHOLD_LOWER_dft;
  }
  if ( (circuit_th_upper == 0) || (circuit_th_upper > 0x1ffe) ) {
    stat |= CS_ERROR;
    CS_HNDL_ERROR(dev_id, ETEN_MOD_INVALID_USER_ARG, ": %s(es %d), using circuit_th_upper default %x instead of %d",
                                                      func, es_num, TEN_XCON_ES_CIRCUIT_THRESHOLD_UPPER_dft, circuit_th_upper);
    circuit_th_upper = TEN_XCON_ES_CIRCUIT_THRESHOLD_UPPER_dft;
  }

  /* refresh and enable thresholds */
  if (CS_OK == ten_xcon_es_check_amplitude_recenter_t41(dev_id, es_num)) {
 
    stat |= ten_xcon_set_circuit_threshold_level_t41(dev_id, es_num, XCON_ES_RECENTER_AMPLITUDE,
                                                     XCON_ES_CIRCUIT_THRESHOLD_LOWER, -1, circuit_th_lower); 
    stat |= ten_xcon_set_circuit_threshold_level_t41(dev_id, es_num, XCON_ES_RECENTER_AMPLITUDE,
                                                     XCON_ES_CIRCUIT_THRESHOLD_UPPER, -1, circuit_th_upper); 
    stat |= ten_xcon_es_recenter_enables_t41(dev_id, es_num, XCON_ES_RECENTER_UPPER_VIOLATION_EN, CS_ENABLE); 
    stat |= ten_xcon_es_recenter_enables_t41(dev_id, es_num, XCON_ES_RECENTER_LOWER_VIOLATION_EN, CS_ENABLE); 
  }
  else {
    CS_HNDL_ERROR(dev_id, ETEN_DRVR_UNEXPECTED_RESULT, ": %s( es %d), %s", func, es_num, str_amprecent_failed_);
    stat = CS_ERROR;
  }
 
  return (stat);
}


/********************************************************************/
/* XCON ELASTIC STORE SOFT (LOGIC) RESET QUICK (NO DELAY)           */
/* CATEGORY   : FUNCTION                                            */
/* ACCESS     : Protected                                           */
/* BLOCK      : XCON                                                */
/* CHIP       : Tenabo                                              */
cs_status ten_xcon_es_sadeco_fifo_reset_quick(cs_uint16 dev_id, 
                                              cs_uint8  module_num,
                                              cs_uint16 action)
/* INPUTS     : o Device Id                                         */
/*              o Module Number                                     */
/*              o Action                                            */
/*                                                                  */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Control XCON sadeco fifo soft reset for the specified  datapath  */
/* direction. There is no delay on reset deassert, which is         */
/* unecessary for sadeco fifo reset. This function serves to align  */
/* the four ES A FIFOs.                                             */
/*                                                                  */
/* The [module_num] parameter is specified as:                      */
/*   0 = TEN_MODULE_A (ES # 0-3)                                    */
/*   1 = TEN_MODULE_B (ES # 4-7)                                    */
/*                                                                  */
/* The [action] parameter is specified as:                          */
/*   CS_RESET_DEASSERT    = 0                                       */
/*   CS_RESET_ASSERT      = 1                                       */
/*   CS_RESET_TOGGLE      = 2                                       */
/*   The CS_RESET_TOGGLE option asserts and immediately deasserts   */
/*   reset.                                                         */
/*                                                                  */
/********************************************************************/
{
  TEN_XCON_SADECO_SADCFG3_t SADCFG3;                /* addr: 0x0402 */
  T41_t *pDev = NULL;
  cs_char8 * func = "ten_xcon_es_sadeco_fifo_reset_quick";

  /* Parameter Checking */
  if(module_num > 1) { 
    CS_HNDL_ERROR(dev_id, ETEN_DEV_INVALID_USER_ARG, ": %s(mod=%d), invalid module number",
                                                     func, module_num);
    return CS_ERROR; 
  }
  if(action > CS_RESET_TOGGLE) { 
    CS_HNDL_ERROR(dev_id, ETEN_DEV_INVALID_USER_ARG, ": %s(mod=), invalid action %d",
                                                     func, module_num, action);
    return CS_ERROR; 
  }

  /* Assert, deassert, or toggle fifo reset bit */
  TEN_DEV_COMMON_VALIDATE(dev_id, pDev, CS_ERROR);
  TEN_DEV_LOCK(dev_id, TEN_ID_XCON);

  SADCFG3.wrd = TEN_REG_READ(TEN_XCON_SADECO_INST_REG_ADDR(pDev, SADCFG3, module_num));
  if( (action == CS_RESET_TOGGLE) || (action == CS_RESET_ASSERT) ){ 
    SADCFG3.bf.FIFORST = 1;
    TEN_REG_WRITE(TEN_XCON_SADECO_INST_REG_ADDR(pDev, SADCFG3, module_num), SADCFG3.wrd);
  }

  if( (action == CS_RESET_TOGGLE) || (action == CS_RESET_DEASSERT) ){ 
    SADCFG3.bf.FIFORST = 0;
    TEN_REG_WRITE(TEN_XCON_SADECO_INST_REG_ADDR(pDev, SADCFG3, module_num), SADCFG3.wrd);
  }
  TEN_DEV_UNLOCK(dev_id, TEN_ID_XCON);

  return (CS_OK);
}

