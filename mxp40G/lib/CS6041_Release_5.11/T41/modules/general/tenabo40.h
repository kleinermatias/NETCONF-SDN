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
 * tenabo40.h
 *
 * Includes all the necessary header files in the correct order.
 *
 * $Id: tenabo40.h,v 1.8 2013/02/22 20:48:25 jccarlis Exp $
 *
 */

#ifndef __TEN_TENABO40_H__
#define __TEN_TENABO40_H__

#include "ten_bld_flags.h"

#ifndef CS_DONT_USE_STDLIB
#include <stdio.h> 
#endif 

#ifndef CS_DONT_USE_VAR_ARGS
#include <stdarg.h>
#endif

#include "cs_rtos.h"

#ifdef RELEASE_PLATFORM

#endif

#include "cs_utils.h"
#include "ten_error.h"
#include "t41_registers.h"

#include "ten_stats.h"
#include "ten_stats_data.h"

#include "ten_gen_data.h"

#include "ten_gen_api.h"
#include "ten_callback.h"

#include "ten_mpif_data.h"
#include "ten_mpif_api.h"
#include "ten_irq_priv.h"

#include "ten_fec_data.h"
#include "ten_fec_api.h"

#include "ten_glb_misc_api.h"

#include "ten_gpllx1_data.h"
#include "ten_gpllx1_api.h"

#include "ten_fracdiv_data.h"
#include "ten_fracdiv_api.h"

#include "ten_hsif_data.h"
#include "ten_hsif_api.h"

#include "ten_pp10g_data.h"
#include "ten_pp10g_api.h"

#include "ten_n40g_data.h"
#ifndef TEN_NO_N40G
#include "ten_n40g_api.h"
#endif

#include "ten_n10g_data.h"
#include "ten_n10g_api.h"

#include "ten_xcon_data.h"
#include "ten_xcon_api.h"

#include "ten_pp40g_data.h"
#include "ten_pp40g_api.h"

#include "ten_ohpp_data.h"
#include "ten_ohpp_api.h"

#include "ten_stats_priv.h"
#include "ten_stats_api.h"

#include "ten_syncdsync_data.h"
#include "ten_syncdsync_api.h"

#include "ten_hl_data.h"
#include "ten_hl_api.h"

#include "ten_hl_config_data.h"
#include "ten_hl_config_api.h"

#include "ten_callback.h"

#include "ten_debug_api.h"
#include "ten_debug_strings.h"

#include "ten_dm_api.h"
#include "ten_dm_data.h"

/* Needs TEN_IRQ_THREAD_ENABLE from ten_bld_flags.h */
#ifdef POSIX_PTHREAD
#  if TEN_IRQ_THREAD_ENABLE
#    include <pthread.h>
#  endif
#endif



#endif



