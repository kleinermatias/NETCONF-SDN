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
 * ten_syncdsync_data.h
 *
 * $Id: ten_syncdsync_data.h,v 1.3 2013/02/22 20:50:01 jccarlis Exp $
 *
 */

#ifndef __TEN_SYNCDSYNC_DATA_H__
#define __TEN_SYNCDSYNC_DATA_H__

#ifdef __cplusplus
extern "C" {
#endif  /* __cplusplus */

#define TEN_SYNCDSYNC_UPPER16(s) ((cs_uint16)((s>>16) & 0xFFFF))
#define TEN_SYNCDSYNC_LOWER16(s) ((cs_uint16)((s    ) & 0xFFFF))

enum ten_syncdsync_cfgmontx_status_e {
  TEN_SYNCDSYNCTX_CFGMONTX_STATUS_JC_OUT_RANGE = 1,
  TEN_SYNCDSYNCTX_CFGMONTX_STATUS_OUT_RANGE = 2,
  TEN_SYNCDSYNCTX_CFGMONTX_STATUS_ALL = 0xFFFF
};

#ifdef __cplusplus
}  /* extern C */
#endif
#endif

