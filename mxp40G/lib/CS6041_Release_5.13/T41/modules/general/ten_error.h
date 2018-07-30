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
 * ten_error.h
 *
 * Error codes for various error callouts from the driver.
 *
 * $Id: ten_error.h,v 1.4 2013/02/22 20:48:25 jccarlis Exp $
 *
 */

#ifndef __TEN_ERROR_H__
#define __TEN_ERROR_H__

#ifdef __cplusplus
extern "C" {
#endif                          /* __cplusplus */

enum ten_error_codes_e {
  /* Driver related error code enums start here */
  ETEN_DRVR_CODE_BASE,
  ETEN_DRVR_ALREADY_LOADED = ETEN_DRVR_CODE_BASE,
  ETEN_DRVR_NOT_LOADED,
  ETEN_DRVR_INCORRECT_ENDIANESS,
  ETEN_DRVR_ALRDY_OUT_FILE_OPENED,
  ETEN_DRVR_OUT_FILE_OPEN_ERROR,
  ETEN_DRVR_NO_OUT_FILE_OPENED,

  /* Device(dev_id) related error code enums start here */
  ETEN_DEV_CODE_BASE,
  ETEN_DEV_ID_OUT_OF_RANGE = ETEN_DEV_CODE_BASE,
  ETEN_DEV_NOT_REGD,
  ETEN_DEV_NOT_INITED,
  ETEN_DEV_CHIP_JTAG_ID_MISMATCH,
  ETEN_DEV_INVALID_HRESET_SEL,
  ETEN_DEV_BIST_NOT_DONE,
  ETEN_DEV_BIST_BAD_STATUS,
  ETEN_DEV_INVALID_MODE,
  ETEN_DEV_SEM_INIT_FAILED,
  ETEN_DEV_SEM_TAKE_FAILED,
  ETEN_DEV_PTEN_NULL,
  ETEN_DEV_INVALID_USER_ARG,
  ETEN_DEV_MALLOC_FAILED,
  ETEN_DEV_NULL_PTR,
  ETEN_DEV_TBL_NULL,
  ETEN_DEV_TBL_START_INVALID,
  ETEN_DEV_TBL_NUM_INVALID,
  ETEN_DEV_RANGE_ERR,
  ETEN_DEV_INVALID_SIZE,
  ETEN_DEV_INVALID_OP,
  ETEN_DEV_INIT_FAILED,
  ETEN_DEV_REG_ACCESS_TIMEOUT,

  /* Module (mod_id) related error code enums start here */
  ETEN_MOD_CODE_BASE,
  ETEN_MOD_ID_OUT_OF_RANGE = ETEN_MOD_CODE_BASE,
  ETEN_MOD_NOT_OPEN,
  ETEN_MOD_MALLOC_FAILED,
  ETEN_MOD_SEM_INIT_FAILED,
  ETEN_MOD_SEM_TAKE_FAILED,
  ETEN_MOD_NOT_INITED,
  ETEN_MOD_DEBUG_MODE_INVALID,
  ETEN_MOD_LOCK_NULL,
  ETEN_MOD_INVALID_DIR,
  ETEN_MOD_NULL_PTR,
  ETEN_MOD_TBL_NULL,
  ETEN_MOD_TBL_START_INVALID,
  ETEN_MOD_TBL_NUM_INVALID,
  ETEN_MOD_INVALID_MOD_ID,
  ETEN_MOD_RANGE_ERR,
  ETEN_MOD_INVALID_HRESET_SEL,
  ETEN_MOD_RESET_TIMEOUT,
  ETEN_MOD_INVALID_USER_ARG,
  ETEN_MOD_INVALID_SIZE,
  ETEN_MOD_INVALID_OP,
  ETEN_MOD_REG_ACCESS_TIMEOUT,

  /* New error code enums start here */
  ETEN_DRVR_UNEXPECTED_RESULT,
  /* DO NOT ADD ERROR CODES BELOW MAX_ERR_CODE */
  ETEN_MAX_ERR_CODE
};

#ifdef __cplusplus
}                               /* extern C */
#endif                          /* __cplusplus */
#endif                          /* __TEN_ERROR_H__ */
