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
/* Copyright (C) 2006-2011 Cortina Systems, Inc. All rights reserved.  */
/***********************************************************************/
/*
 * ten_bld_flags.h
 *
 * Contains the build flags.
 *
 * $Id: ten_bld_flags.h,v 1.28 2013/05/06 19:14:38 jccarlis Exp $
 *
 */

#ifndef __TEN_BUILD_FLAGS_H__
#define __TEN_BUILD_FLAGS_H__

  #define CS_FUNCTION_NAME __func__  
  
/* uncomment this to include debugging APIs.                  */
 #define INCLUDE_TEN_DEBUG_APIS 1                           

/* uncomment this define to check for bus errors              */
 #define TEN_CHECK_FOR_BUS_ERRORS 1                          

 /* controls whether CS_INLINE is defined as '__inline__' or nothing */
 /* #define CS_DONT_USE_INLINE  */

 /* uncomment this define to use vsprintf instead of vnsprintf */
 /* #define CS_DONT_HAVE_VSNPRINTF  */

/* define 'CS_DONT_USE_STDLIB' to compile the driver without requiring <stdio.h> */
 /* #define CS_DONT_USE_STDLIB */
 
 /* define 'CS_DONT_USE_VAR_ARGS' to compile the driver without requiring <stdarg.h> */
 /* #define CS_DONT_USE_VAR_ARGS */
 
 /* uncomment this define to disable all PRINTing */
 /* #define __CS_DONT_PRINT__ */

/* uncomment this define to suppress logging of xfi ucode     */
 #define TEN_LOG_XFI_UCODE        1                         


#define TEN_IRQ_THREAD_ENABLE 0

/*  Configurations automatically disable OCI by default.         */
/*  To separate datapath provisioning from line conditioning,    */
/*  set this value to '0'.  Then separately, call:               */
/*  ten_hl_ohpp_control_oduk_oci (module_id, slice, CS_DISABLE); */
/*  For Bug #39241 - Signal conditioning should not be done      */
/*  by T41 datapath configuration APIs                           */
/* #define TEN_HL_OHPP_DISABLE_ODUK_OCI 0 */
#define TEN_HL_OHPP_DISABLE_ODUK_OCI 1
 
#endif



