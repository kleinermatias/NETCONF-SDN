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
 * ten_error.c
 *
 * Error table for various errors called out from the driver.
 *
 * $Id: ten_error.c,v 1.4 2013/02/22 20:48:25 jccarlis Exp $
 *
 */

#include "tenabo40.h"

const cs_char8 *eten_err_tbl[ETEN_MAX_ERR_CODE] = {

  /*
   * Driver related errors
   */
  
  "Driver is already loaded",
  "Driver not loaded yet",
  "Incorrect endian option defined",
  "Driver output file already opened",
  "Error opening driver output file",
  "No driver output file opened",

  /*
   * Device (dev_id) related errors
   */
  "dev_id out of range",
  "Device not registered yet",
  "Device not initialized yet",
  "Chip JTAG Id Mismatch",
  "Invalid dev hard reset selection",
  "BIST not completed yet",
  "Error from BIST",
  "Invalid device Mode",
  "Semaphore init failed",
  "Semaphore take failed",
  "pTEN is NULL",
  "Invalid user arg specified",
  "Cannot allocate memory",
  "NULL pointer",
  "Table Pointer is NULL",
  "Table/Memory starting entry num is invalid",
  "Table/Memory number of entries is invalid",
  "Argument out of Range",
  "Invalid user data size",
  "Invalid Operation",
  "Failed on Dev Init",
  "Reg Access Timeout",

  /*
   * Module (module id) related errors
   */
  "mod_id out of range",
  "Module not opened yet",
  "Cannot allocate memory",
  "Failed to Init Semaphore",
  "Semaphore take failed",
  "Module not initialized",
  "Invalid Debug Mode",
  "CS_SEM pointer NULL",
  "Invalid Tx/Rx option",
  "Nul user pointer",
  "Table Pointer is NULL",
  "Table/Memory starting entry num is invalid",
  "Table/Memory number of entries is invalid",
  "Invalid Module ID",
  "Argument out of Range",
  "Invalid block selection for Hard Reset",
  "Timed out waiting for Reset to clear",
  "Invalid user arg",
  "Invalid user data size",
  "Invalid Operation",
  "Reg Access Timeout",

  /*
   * New errors
   */
  "Unexpected result"
};

/*
 *  ten_error_handler:
 *  This function is the error handler. It prints the error information
 *  along with the function and line where the error occurred.
 *  This can be customized by the user to suite requirements.
 */
void ten_error_handler(cs_uint32 id, cs_uint32 errCode, cs_char8 *fmt, ...)
{
  cs_boolean found = TRUE;
  #ifndef CS_DONT_USE_VAR_ARGS
  va_list VarArg;
  cs_char8 log_str[CS_PRINT_BUFFER_SIZE];
  #endif

  #ifndef CS_DONT_USE_STDLIB
  CS_SET_ERRNO(errCode);
  #endif

  CS_PRINT_ERRORS("ten_error_handler: %d %d\n", errCode + 0x7000, errCode);

  if ( (errCode < ETEN_DEV_CODE_BASE) || (errCode == ETEN_DRVR_UNEXPECTED_RESULT) ) {
    CS_PRINT_ERRORS("Driver (%s) ", eten_err_tbl[errCode]);
  }
  else if ((errCode >= ETEN_DEV_CODE_BASE)
           && (errCode < ETEN_MOD_CODE_BASE)) {
    CS_PRINT_ERRORS("Dev-%d (%s) ", id, eten_err_tbl[errCode]);
  }
  else if ((errCode >= ETEN_MOD_CODE_BASE) && (errCode < ETEN_MAX_ERR_CODE)) {
    CS_PRINT_ERRORS("Module-0x%04x (%s) ", id, eten_err_tbl[errCode]);
  }
  else {
    CS_PRINT_ERRORS("ten_error_handler : Not found.\n");
    found = FALSE;
  }

  /* print additional error text, if any */
  if (found && fmt) {
    #ifndef CS_DONT_USE_VAR_ARGS
    va_start(VarArg, fmt);
    #ifdef CS_DONT_HAVE_VSNPRINTF
    vsprintf(log_str, fmt, VarArg);
    #else
    vsnprintf(log_str, sizeof(log_str), fmt, VarArg);
    #endif
    log_str[CS_PRINT_BUFFER_SIZE - 1] = 0;
    CS_PRINT_ERRORS(log_str);
    va_end(VarArg);
    #endif
  }
  CS_PRINT_ERRORS("\n");
  ten_swerr_cb(id, errCode, fmt);
}
