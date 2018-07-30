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
 * ten_drvr.c
 * "Driver" related code is implemented here.
 *
 * $Id: ten_drvr.c,v 1.50 2014/03/27 20:47:00 jccarlis Exp $
 *
 */

#include "tenabo40.h"
/* Bugzilla 24021 Start */
#include "ten_irq.h"
/* Bugzilla 24021 End */

#define TEN_DRIVER_VERSION "T41 Driver Lab Release:  5.13"

/* Global pointer to the Driver's memory (Control Block) */
ten_drvr_cb_t *g_pTEN = NULL;

/* Public non-API function prototype.                           */
extern cs_status ten_dev_udelay_hi_res(cs_uint32 usecs);

/* Bugzilla 24021 test_thread_function removed */

/****************************************************************/
/* $rtn_hdr_start  LOAD DEVICE DRIVER                           */
/* CATEGORY   : Driver                                          */
/* ACCESS     : Public                                          */
/* BLOCK      : GENERAL                                         */
/* CHIP       : Tenabo                                          */
cs_status ten_drvr_load(void)
/* INPUTS     : ----                                            */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* This loads the driver, initializes the driver data-structures*/
/* and allocates resource for the device control block table    */
/* and initializes it.                                          */
/*                                                              */
/* This API should be called BEFORE invoking any of the other   */
/* APIs.                                                        */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  #if TEN_IRQ_THREAD_ENABLE
  /* Bugzilla 24021 Start */
  pthread_t thread_id;  /* ID returned by pthread_create() */
  /* Bugzilla 24021 End */
  int res;
  #endif
  cs_uint16 ii;

  if (CS_VERIFY_ENDIANESS() != CS_OK) {
    CS_HNDL_ERROR(0, ETEN_DRVR_INCORRECT_ENDIANESS, NULL);
    return (CS_ERROR);
  }

  if (TEN_DRVR_IS_LOADED()) {
    /* Driver is already loaded */
    CS_HNDL_ERROR(0, ETEN_DRVR_ALREADY_LOADED, NULL);
    return (CS_ERROR);
  }

  /* Allocate memory for the Driver's Control Block  */
  g_pTEN = (ten_drvr_cb_t *) CS_MALLOC(sizeof(ten_drvr_cb_t));
  if (g_pTEN == NULL) {
    CS_PRINT("ERROR: Fail to allocate memory when loading driver\n");
    return (CS_ERROR);
  }

  CS_MEMSET((void *)g_pTEN, 0, sizeof(ten_drvr_cb_t));
  g_pTEN->drvr_loaded = FALSE;
  g_pTEN->drvr_flag = TEN_DRVR_DEFAULT_FLAG;
  g_pTEN->ucode_flag = 1;  /* bugzilla #19410 */
  g_pTEN->ucode_running_flag = 1;  /* bugzilla #21921 */
  g_pTEN->esc_code_print = FALSE;
  g_pTEN->debug_base_address = 0;

  /* Bugilla #26434, bus error checking control */
  /* Bug #40123 - Fix bus error logging APIs to work on per device basis */
  for (ii=0;ii<TEN_MAX_NUM_DEVICES;ii++) {
    g_pTEN->ten_bus_error_count[ii] = 0;
    #ifdef TEN_CHECK_FOR_BUS_ERRORS
    g_pTEN->ten_bus_error_ctl[ii] = CS_ENABLE;
    #else
    g_pTEN->ten_bus_error_ctl[ii] = CS_DISABLE;
    #endif
  }

  #ifndef CS_DONT_USE_STDLIB
  g_pTEN->drvr_out_fp = NULL;
  strcpy(g_pTEN->drvr_out_filename, " ");
  #endif

  g_pTEN->drvr_loaded = TRUE;
  CS_PRINT("T41 Driver Loaded.\n");
  ten_drvr_print_ver();

  #ifndef RELEASE_PLATFORM
  cs_lab_load_driver(CS_CHIP_T41);
  #endif

  /* bugzilla #26154, manage thread activity with compile switch  */
  #if TEN_IRQ_THREAD_ENABLE
  /* Bugzilla 24021 Start */
  res = pthread_create (&thread_id, NULL, irq_polling_thread, NULL);
  if (res != 0) {
    CS_PRINT("IRQ Polling Thread create failed.\n");
  }
  /* Bugzilla 24021 End */
  #endif

  /* Bugzilla 30990, Register callback to use the device driver for ten_udelay_high_res.   */
  if (!ten_is_registered_udelay_hi_res() ) ten_register_udelay_hi_res(ten_drvr_udelay_hi_res);

  return (CS_OK);
}

/****************************************************************/
/* $rtn_hdr_start  UNLOAD DEVICE DRIVER                         */
/* CATEGORY   : Driver                                          */
/* ACCESS     : Public                                          */
/* BLOCK      : GENERAL                                         */
/* CHIP       : Tenabo                                          */
cs_status ten_drvr_unload(void)
/* INPUTS     : ----                                            */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* This unloads the driver and releases any related system      */
/* resources held by the driver.                                */
/*                                                              */
/* The APIs in the driver should not called after this, until   */
/* after ten_load_driver() is loaded again.                     */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  cs_uint32 ii;
  ten_dev_cb_t **dev_cb_tbl;
  ten_dev_cb_t *pdevcb;

  CS_PRINT("ten_drvr_unload\n");

  if (!(TEN_DRVR_IS_LOADED())) {
    CS_HNDL_ERROR(0, ETEN_DRVR_NOT_LOADED, NULL);
    return (CS_ERROR);
  }

  dev_cb_tbl = g_pTEN->p_dev_cb_tbl;

  for (ii = 0; ii < TEN_MAX_NUM_DEVICES; ii++) {
    pdevcb = dev_cb_tbl[ii];

    if (pdevcb) {
      if (ten_dev_unregister(pdevcb->dev_id) != CS_OK) {
        return (CS_ERROR);
      }
    }
  }

  CS_PRINT("T41 Driver Unloaded.\n");
  CS_FREE(g_pTEN);
  g_pTEN = NULL;

  #ifndef RELEASE_PLATFORM
  cs_lab_unload_driver(CS_CHIP_T41);
  #endif

  return (CS_OK);
}

/****************************************************************/
/* $rtn_hdr_start   START DRIVER OUTPUT TO FILE                 */
/* CATEGORY   : Driver                                          */
/* ACCESS     : Public                                          */
/* BLOCK      : GENERAL                                         */
/* CHIP       : Tenabo                                          */
cs_status ten_drvr_start_output_to_file(const cs_char8 *fname)
/* INPUTS     : o Filename for driver output                    */
/* OUTPUTS    : o Driver print messages to the file [fname]     */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* All program output going to stdout will also be written to   */
/* specified file.                                              */
/*                                                              */
/* The output to the specified file can be stopped by calling   */
/* ten_stop_driver_output_to_file().                            */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  CS_PRINT("ten_drvr_start_output_to_file\n");

  /* Bugzilla #28788, support compiler option CS_DONT_USE_STDLIB */
  #ifndef CS_DONT_USE_STDLIB

  if (!(TEN_DRVR_IS_LOADED())) {
    CS_HNDL_ERROR(0, ETEN_DRVR_NOT_LOADED, NULL);
    return (CS_ERROR);
  }

  if (g_pTEN->drvr_out_fp != NULL) {
    CS_HNDL_ERROR(0, ETEN_DRVR_ALRDY_OUT_FILE_OPENED, ":%s\n", g_pTEN->drvr_out_filename);
    return (CS_ERROR);
  }

  if (fname == NULL) {
    CS_HNDL_ERROR(0, ETEN_DRVR_OUT_FILE_OPEN_ERROR, ": fname = ???\n");
    return (CS_ERROR);
  }

  g_pTEN->drvr_out_fp = fopen(fname, "w");
  if (g_pTEN->drvr_out_fp == NULL) {
    CS_HNDL_ERROR(0, ETEN_DRVR_OUT_FILE_OPEN_ERROR, "%s\n", fname);
    return (CS_ERROR);
  }

  strcpy(g_pTEN->drvr_out_filename, fname);

  CS_PRINT("Start driver output to %s.\n", g_pTEN->drvr_out_filename);
  #endif /* CS_DONT_USE_STDLIB */

  return (CS_OK);
}

/****************************************************************/
/* $rtn_hdr_start   STOP DRIVER OUTPUT TO FILE                  */
/* CATEGORY   : Driver                                          */
/* ACCESS     : Public                                          */
/* BLOCK      : GENERAL                                         */
/* CHIP       : Tenabo                                          */
cs_status ten_drvr_stop_output_to_file(void)
/* INPUTS     : ----                                            */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* Stop the writing to the file of the program output and reset */
/* it to stdout.                                                */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  CS_PRINT("ten_drvr_stop_output_to_file\n");

  /* Bugzilla #28788, support compiler option CS_DONT_USE_STDLIB */
  #ifndef CS_DONT_USE_STDLIB

  if (!(TEN_DRVR_IS_LOADED())) {
    CS_HNDL_ERROR(0, ETEN_DRVR_NOT_LOADED, NULL);
    return (CS_ERROR);
  }

  if (g_pTEN->drvr_out_fp == NULL) {
    CS_HNDL_ERROR(0, ETEN_DRVR_NO_OUT_FILE_OPENED, NULL);
    return (CS_ERROR);
  }

  CS_PRINT("Driver output to %s stopped.\n", g_pTEN->drvr_out_filename);

  fclose(g_pTEN->drvr_out_fp);
  g_pTEN->drvr_out_fp = NULL;
  strcpy(g_pTEN->drvr_out_filename, " ");
  #endif /* #ifndef CS_DONT_USE_STDLIB */

  return (CS_OK);
}

/****************************************************************/
/* $rtn_hdr_start   STATISTICS HEX FORMAT DISPLAY CONTROL       */
/* CATEGORY   : Driver                                          */
/* ACCESS     : Public                                          */
/* BLOCK      : GENERAL                                         */
/* CHIP       : Tenabo                                          */
void ten_drvr_ctl_stats_hex_format(cs_ctl_t hex_ctl)
/* INPUTS     : o Hex Control                                   */
/* OUTPUTS    : ----                                            */
/* RETURNS    : ----                                            */
/* DESCRIPTION:                                                 */
/* Enables/disables debug printing of statistics counters in    */
/* hexadecimal format for display.                              */
/* By default, decimal format is used.                          */
/*                                                              */
/* The [hex_ctl] parameter is specified as:                     */
/*   CS_DISABLE (0) or CS_ENABLE (1)                            */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  CS_PRINT("ten_drvr_ctl_stats_hex_format\n");

  if (TEN_DRVR_IS_LOADED()) {
    if (hex_ctl == CS_DISABLE) {
      g_pTEN->drvr_flag &= ((~TEN_DRVR_STATS_IN_HEX) & 0xFFFF);
    }
    else {
      g_pTEN->drvr_flag |= TEN_DRVR_STATS_IN_HEX;
    }
  }
}

/****************************************************************/
/* $rtn_hdr_start   STATISTICS ZERO COUNTER DISPLAY CONTROL     */
/* CATEGORY   : Driver                                          */
/* ACCESS     : Public                                          */
/* BLOCK      : GENERAL                                         */
/* CHIP       : Tenabo                                          */
void ten_drvr_ctl_stats_mask_zero(cs_ctl_t mask_zero_ctl)
/* INPUTS     : o Control                                       */
/* OUTPUTS    : ----                                            */
/* RETURNS    : ----                                            */
/* DESCRIPTION:                                                 */
/* Enables/disables if debug printing the statistics counters   */
/* with zero values.                                            */
/* By default, all ZERO counters are printed out.               */
/*                                                              */
/* The [mask_zero_ctl] parameter is specified as:               */
/*   CS_DISABLE (0) or CS_ENABLE (1)                            */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  CS_PRINT("ten_drvr_ctl_stats_mask_zero\n");

  if (TEN_DRVR_IS_LOADED()) {
    if (mask_zero_ctl == CS_DISABLE) {
      g_pTEN->drvr_flag &= ((~TEN_DRVR_STATS_MASK_ZERO) & 0xFFFF);
    }
    else {
      g_pTEN->drvr_flag |= TEN_DRVR_STATS_MASK_ZERO;
    }
  }
}

/****************************************************************/
/* $rtn_hdr_start   STATISTICS TIMING INTERVAL MODE             */
/* CATEGORY   : Driver                                          */
/* ACCESS     : Public                                          */
/* BLOCK      : GENERAL                                         */
/* CHIP       : Tenabo                                          */
void ten_drvr_ctl_stats_timing_interval(cs_ctl_t mask_zero_ctl)
/* INPUTS     : o Control                                       */
/* OUTPUTS    : ----                                            */
/* RETURNS    : ----                                            */
/* DESCRIPTION:                                                 */
/* Control mode of software accumulation for timing-interval    */
/* based stats.                                                 */
/*                                                              */
/* The [mask_zero_ctl] parameter is specified as:               */
/*   CS_DISABLE = 0                                             */
/*   CS_ENABLE = 1                                              */
/*                                                              */
/* NOTE:                                                        */
/* When enabled, "timing interval" based stats can accumulate   */
/* in software instead of just reporting the current snapshot   */
/* for the last timing interval (ie, the current hardware       */
/* register values).                                            */
/* In this mode, stats should be read only ONCE per timing      */
/* interval, to avoid extra (and invalid) software              */
/* accumulations.                                               */
/* The software counters have a 64 bit resolution.              */
/* By default, stats report the current snapshot only and do    */
/* not accumulate in software.  This default mode is used for   */
/* lab testing and those users who will to handle accumulation  */
/* at another layer.                                            */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  if (TEN_DRVR_IS_LOADED()) {
    if (mask_zero_ctl == CS_DISABLE) {
      g_pTEN->drvr_flag &= ((~TEN_DRVR_STATS_TIMING_INTERVAL) & 0xFFFF);
    }
    else {
      g_pTEN->drvr_flag |= TEN_DRVR_STATS_TIMING_INTERVAL;
    }
  }
}

/****************************************************************/
/* $rtn_hdr_start   ENABLE/DISABLE VT100 ESCAPE CODE PRINTING   */
/* CATEGORY   : Driver                                          */
/* ACCESS     : Public                                          */
/* BLOCK      : GENERAL                                         */
/* CHIP       : Tenabo                                          */
void ten_drvr_ctl_esc_code_print(cs_ctl_t ctl)
/* INPUTS     : o Control                                       */
/* OUTPUTS    : ----                                            */
/* RETURNS    : ----                                            */
/* DESCRIPTION:                                                 */
/* Enables/disables the driver print formatting using VT100     */
/* terminal emulator escape codes.                              */
/* By default, the escape code printing is enabled.             */
/*                                                              */
/* The [ctl] parameter is specified as:                         */
/*   CS_DISABLE (0) or CS_ENABLE (1)                            */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  CS_PRINT("ten_drvr_ctl_esc_code_print\n");

  if (TEN_DRVR_IS_LOADED()) {
    g_pTEN->esc_code_print = (ctl == CS_ENABLE) ? TRUE : FALSE;
  }
}

/****************************************************************/
/* $rtn_hdr_start   CONTROL LOGGING OUTPUT                      */
/* CATEGORY   : Driver                                          */
/* ACCESS     : Public                                          */
/* BLOCK      : GENERAL                                         */
/* CHIP       : Tenabo                                          */
void ten_drvr_ctl_logging(cs_uint16 log_ctl)
/* INPUTS     : o Logging Control                               */
/* OUTPUTS    : ----                                            */
/* RETURNS    : ----                                            */
/* DESCRIPTION:                                                 */
/* Enables/disables debug logging messages to stout.            */
/* By default, only errors are logged (CS_LOG_ERRORS_ONLY).     */
/*                                                              */
/* The [ctl] parameter is specified as:                         */
/*   CS_LOG_DISABLE           = 0, (nothing logged)             */
/*   CS_LOG_ENABLE            = 1, (everything logged)          */
/*   CS_LOG_DELAYS_AND_ERRORS = 2, (only delays/errors logged)  */
/*   CS_LOG_DELAYS_ONLY       = 3, (only delays logged)         */
/*   CS_LOG_ERRORS_ONLY       = 4  (only errors logged).        */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  cs_uint16 all_dbg_flags = TEN_DRVR_LOG_ALL | TEN_DRVR_LOG_DELAYS_AND_ERRORS |
                            TEN_DRVR_LOG_DELAYS_ONLY | TEN_DRVR_LOG_ERRORS_ONLY;

  if (TEN_DRVR_IS_LOADED()) {
    g_pTEN->drvr_flag &= ((~all_dbg_flags) & 0xFFFF);

    /* bugzilla #24439, klockwork */
    switch (log_ctl) {
    case (CS_LOG_DISABLE):
      break;
    case (CS_LOG_ENABLE):
      g_pTEN->drvr_flag |= TEN_DRVR_LOG_ALL;
      break;
    case (CS_LOG_DELAYS_AND_ERRORS):
      g_pTEN->drvr_flag |= TEN_DRVR_LOG_DELAYS_AND_ERRORS;

      break;
    case (CS_LOG_DELAYS_ONLY):
      g_pTEN->drvr_flag |= TEN_DRVR_LOG_DELAYS_ONLY;
      break;

    default:
    case (CS_LOG_ERRORS_ONLY):
      g_pTEN->drvr_flag |= TEN_DRVR_LOG_ERRORS_ONLY;
      break;
    }
  }
}

/****************************************************************/
/* $rtn_hdr_start   PRINT DRIVER VERSION INFORMATION            */
/* CATEGORY   : Driver                                          */
/* ACCESS     : Public                                          */
/* BLOCK      : GENERAL                                         */
/* CHIP       : Tenabo                                          */
void ten_drvr_print_ver(void)
/* INPUTS     : ----                                            */
/* OUTPUTS    : ----                                            */
/* RETURNS    : ----                                            */
/* DESCRIPTION:                                                 */
/* Prints the driver release version information.               */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  CS_PRINT_OUTPUT("%s\n", TEN_DRIVER_VERSION);
  CS_PRINT_OUTPUT("XFI Microcode Release:      %s\n", ten_hsif_gram_table_version);
  CS_PRINT_OUTPUT("Driver built on %s @ %s\n", __DATE__, __TIME__);
}

/****************************************************************/
/* $rtn_hdr_start   PRINT DRIVER SUMMARY INFORMATION            */
/* CATEGORY   : Driver                                          */
/* ACCESS     : Public                                          */
/* BLOCK      : GENERAL                                         */
/* CHIP       : Tenabo                                          */
void ten_drvr_print_summary(void)
/* INPUTS     : ----                                            */
/* OUTPUTS    : ----                                            */
/* RETURNS    : ----                                            */
/* DESCRIPTION:                                                 */
/* Prints the driver summary information. Indicates which       */
/* device(s), module(s) and slices(s) are valid, active, etc.   */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  cs_uint16 num_devices = 0, num_ports = 0;
  ten_dev_cb_t **dev_cb_tbl;
  cs_uint16 ii, jj;

  if (!(TEN_DRVR_IS_LOADED())) {
    CS_HNDL_ERROR(0, ETEN_DRVR_NOT_LOADED, NULL);
    return;;
  }

  dev_cb_tbl = g_pTEN->p_dev_cb_tbl;
  cs_bar();
  CS_PRINT_OUTPUT("T41 Driver Summary\n");
  cs_bar();
  for (ii = 0; ii < TEN_MAX_NUM_DEVICES; ii++) {
    ten_dev_cb_t *pdevcb = dev_cb_tbl[ii];

    if (pdevcb) {
      num_devices++;
      num_ports = 0;
      CS_PRINT_OUTPUT("dev id              = %d\n", pdevcb->dev_id);
      CS_PRINT_OUTPUT("base addr @         = %p\n", pdevcb->base_addr);
      CS_PRINT_OUTPUT("state               = %s\n", (pdevcb->state == TEN_DEV_STATE_REGISTERED) ?
                      "registered" : "initialized");
      if (g_pTEN) {
        CS_PRINT_OUTPUT("drvr_loaded         = %d\n", g_pTEN->drvr_loaded);
        CS_PRINT_OUTPUT("ws_ctl.enbl         = %d\n", g_pTEN->ws_ctl.enbl);
        CS_PRINT_OUTPUT("ws_ctl.method       = %d\n", g_pTEN->ws_ctl.method);
        CS_PRINT_OUTPUT("drvr_flag           = 0x%04X\n", g_pTEN->drvr_flag);
        CS_PRINT_OUTPUT("ucode_flag          = %d\n", g_pTEN->ucode_flag);
        CS_PRINT_OUTPUT("ucode_running_flag  = %d\n", g_pTEN->ucode_running_flag);
        CS_PRINT_OUTPUT("esc_code_print      = %d\n", g_pTEN->esc_code_print);
        CS_PRINT_OUTPUT("ten_bus_error_count = %d\n", g_pTEN->ten_bus_error_count[ii]);
        CS_PRINT_OUTPUT("ten_bus_error_ctl   = %d\n", g_pTEN->ten_bus_error_ctl[ii]);
      }
      if (pdevcb->state == TEN_DEV_STATE_INITIALIZED) {
        for (jj = 0; jj < TEN_MAX_NUM_MODULES; jj++) {
          ten_mod_cb_t *ppcb = pdevcb->ppcb[jj];

          if (ppcb) {
            num_ports++;
            CS_PRINT_OUTPUT("module id           = 0x%04X\n", ppcb->mod_id);
            CS_PRINT_OUTPUT("state               = %s\n", (ppcb->state ==
                             TEN_MOD_STATE_OPENED) ? "opened" : "initialized");
          }
        }
        CS_PRINT_OUTPUT("valid modules in dev id %d = %d\n", ii, num_ports);
      }
    }
  }

  CS_PRINT_OUTPUT("valid devices in driver   = %d\n", num_devices);
  cs_bar();
}

/*****************************************
 ************    DRIVER     **************
 *****************************************/
cs_boolean ten_drvr_is_stats_in_hex_fmt(void)
{
  if (TEN_DRVR_IS_LOADED()) {
    return (((g_pTEN->drvr_flag & TEN_DRVR_STATS_IN_HEX) != 0) ? TRUE : FALSE);
  }
  return (FALSE);
}

cs_boolean ten_drvr_is_mask_zero_cntr(void)
{
  if (TEN_DRVR_IS_LOADED()) {
    return (((g_pTEN->drvr_flag & TEN_DRVR_STATS_MASK_ZERO) != 0) ? TRUE : FALSE);
  }
  else {
    return (FALSE);
  }
}

cs_boolean ten_drvr_is_esc_code_enbld(void)
{
  if (TEN_DRVR_IS_LOADED()) {
    return (((g_pTEN->drvr_flag & TEN_DRVR_ESC_CODE_PRINT) != 0) ? TRUE : FALSE);
  }
  else {
    return (FALSE);
  }
}

/* This delay utility uses a T41's MPIF miscellaneous counter. The first T41 initialzed */
/* should write its device number to static var ten_drvr_udelay_hi_res_dev_id.          */
void ten_drvr_udelay_hi_res(cs_uint32 usecs)
{
  if (ten_dev_udelay_hi_res(usecs) != CS_OK) {
    CS_PRINT("ten_drvr_udelay_hi_res() Warning: hi res timer could not be set, using TEN_UDELAY()\n");
    TEN_UDELAY(usecs);
  }
}

