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
 * ten_hl_n10g.c
 *
 * API's for N10G high level configuration.
 *
 * $Id: ten_hl_n10g.c,v 1.127 2013/05/01 14:34:06 jccarlis Exp $
 *
 */

#include "tenabo40.h"

const cs_uint16 ten_n10g_rx_table[TEN_N10G_RX_MAX_PARM][TEN_N10G_RX_MAX_MODE] = {
/*                                                       DISABLE                      BYPASS                       OTU2_ODU2_fs                 OTU2_U15_10GFC               OTU2_OPU2                    ODU2j_8GFC                   OTU2_8GFC                    ODU2_ODU2                    OC192_OC192                  OxU3j_ODU2e_10GE             OTU2e_ODU2                   OxU3_OC192                   OxU3_OC192p                  OxU3_ODU2                    OxU3_ODU2p                   OxU3_10GEp                   OxU3_10GE                    OxU3_10GFC                   OxU3_OC192_10GE              OTU2e_ODU2e                  OTU1e_ODU1e                  OTU2_ODU2                    OTU2e_10GE                   OxU3_ODU2e_10GE              OTU2fc_10GFC                 OxU3_ODU2fc_10GFC            OTU1e_10GE                   OxU3_ODU1e_10GE              OTU2ej_10GE                  OTU2ej_10GFC                 OTU2xj_10GE                  OTU2ej_8GFC                  ODU2_OC192                   OTU2ej_OC192                 OTU2_10GE                    OTU2_10U_ODU2                OTU2_OC192_10GE              OC192_10GE                   OTU2_OC192                   BYPASS_P                     OTU2_OC192pt                 OxU3_ODU2_10GE               OxU3_192_10GE                OTU2_34_10GE                 OTU2_OC192_10GE_20U          OTU2_GENRM_ODU3              ODU3_GENRM_OTU2               */
/*                                                       ============                 ============                 ============                 ============                 ============                 ============                 ============                 ============                 ============                 ============                 ============                 ============                 ============                 ============                 ============                 ============                 ============                 ============                 ============                 ============                 ============                 ============                 ============                 ============                 ============                 ============                 ============                 ============                 ============                 ============                 ============                 ============                 ============                 ============                 ============                 ============                 ============                 ============                 ============                 ============                 ============                 ============                 ============                 ============                 ============                 ============                 ============                  */
/*                        DPCFG_OTNOFF */  {                           0,                           1,                           0,                           0,                           0,                           0,                           0,                           0,                           1,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           1,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           1,                           0,                           1,                           0,                           0,                           0,                        0   ,                           0,                           0,                           1 },
/*                        DPCFG_SDHOFF */  {                           0,                           1,                           1,                           1,                           1,                           1,                           1,                           1,                           0,                           1,                           1,                           0,                           0,                           1,                           1,                           1,                           1,                           1,                           1,                           1,                           1,                           1,                           1,                           1,                           1,                           1,                           1,                           1,                           1,                           1,                           1,                           1,                           0,                           0,                           1,                           1,                           0,                           0,                           0,                           1,                           0,                           1,                           0,                        1   ,                           0,                           0,                           1 },
/*                           DPCFG_OBY */  {                           0,                           1,                           0,                           0,                           0,                           0,                           0,                           0,                           1,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           1,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           1,                           0,                           1,                           0,                           0,                           0,                        0   ,                           0,                           0,                           1 },
/*                        DPCFG_SBYFRM */  {                           0,                           1,                           1,                           0,                           1,                           0,                           0,                           1,                           0,                           1,                           1,                           0,                           0,                           1,                           1,                           1,                           1,                           1,                           1,                           1,                           1,                           1,                           0,                           0,                           0,                           0,                           0,                           0,                           1,                           1,                           1,                           1,                           0,                           0,                           0,                           1,                           0,                           0,                           0,                           1,                           0,                           1,                           0,                        0   ,                           0,                           1,                           1 },
/*                        DPCFG_SBYPLD */  {                           0,                           1,                           1,                           1,                           1,                           1,                           1,                           0,                           1,                           1,                           1,                           1,                           1,                           1,                           1,                           1,                           1,                           1,                           1,                           1,                           1,                           1,                           1,                           1,                           1,                           1,                           1,                           1,                           1,                           1,                           1,                           1,                           1,                           1,                           1,                           1,                           0,                           0,                           1,                           1,                           0,                           1,                           0,                        1   ,                           0,                           1,                           1 },
/*                        DPCFG_KPASEL */  {                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                       0x0  ,                         0x0,                         0x0,                         0x0 },
/*                          DPCFG_XSEL */  {                          00,                         0x2,                         0x1,                         0x1,                         0x2,                         0x2,                         0x1,                         0x1,                         0x1,                         0x2,                         0x2,                         0x1,                         0x1,                         0x1,                         0x1,                         0x1,                         0x1,                         0x1,                         0x2,                         0x1,                         0x1,                         0x1,                         0x2,                         0x2,                         0x2,                         0x2,                         0x2,                         0x2,                         0x2,                         0x2,                         0x2,                         0x2,                         0x1,                         0x1,                         0x1,                         0x1,                         0x1,                         0x1,                         0x1,                         0x0,                         0x2,                         0x1,                         0x1,                       0x2  ,                         0x1,                         0x2,                          00 },
/*                   FRMLENGTH_NOFCOLS */  {                         0x0,                       0x10d,                       0x10d,                       0x10d,                       0x10d,                       0x10d,                       0x10d,                       0x10d,                       0x10d,                       0x10d,                       0x10d,                       0x10d,                       0x10d,                       0x10d,                       0x10d,                       0x10d,                       0x10d,                       0x10d,                       0x10d,                       0x10d,                       0x10d,                       0x10d,                       0x10d,                       0x10d,                       0x10d,                       0x10d,                       0x10d,                       0x10d,                       0x10d,                       0x10d,                       0x10d,                       0x10d,                       0x10d,                       0x10d,                       0x10d,                       0x10d,                       0x10d,                       0x10d,                       0x10d,                       0x10d,                       0x10d,                       0x10d,                       0x10d,                      0x10d ,                       0x10d,                       0x10d,                       0x10d },
/*                        SDFCFG_SCREN */  {                           0,                           1,                           1,                           1,                           1,                           1,                           1,                           1,                           1,                           1,                           1,                           1,                           1,                           1,                           1,                           1,                           1,                           1,                           1,                           1,                           1,                           1,                           1,                           1,                           1,                           1,                           1,                           1,                           1,                           1,                           1,                           1,                           1,                           1,                           1,                           1,                           1,                           1,                           1,                           1,                           1,                           1,                           1,                           1,                           1,                           0,                           1 },
/*                       SDFCFG_FAWWUP */  {                         0x0,                         0x2,                         0x2,                         0x2,                         0x2,                         0x2,                         0x2,                         0x2,                         0x2,                         0x2,                         0x2,                         0x2,                         0x2,                         0x2,                         0x2,                         0x2,                         0x2,                         0x2,                         0x2,                         0x2,                         0x2,                         0x2,                         0x2,                         0x2,                         0x2,                         0x2,                         0x2,                         0x2,                         0x2,                         0x2,                         0x2,                         0x2,                         0x2,                         0x2,                         0x2,                         0x2,                         0x2,                         0x2,                         0x2,                         0x2,                         0x2,                         0x2,                         0x2,                      0x2   ,                         0x2,                         0x2,                         0x0 },
/*                       SDFCFG_FAWWDW */  {                         0x0,                         0x2,                         0x2,                         0x2,                         0x2,                         0x2,                         0x2,                         0x2,                         0x2,                         0x2,                         0x2,                         0x2,                         0x2,                         0x2,                         0x2,                         0x2,                         0x2,                         0x2,                         0x2,                         0x2,                         0x2,                         0x2,                         0x2,                         0x2,                         0x2,                         0x2,                         0x2,                         0x2,                         0x2,                         0x2,                         0x2,                         0x2,                         0x2,                         0x2,                         0x2,                         0x2,                         0x2,                         0x2,                         0x2,                         0x2,                         0x2,                         0x2,                         0x2,                      0x2   ,                         0x2,                         0x2,                         0x0 },
/*                        SDFCFG_OOFHY */  {                         0x0,                         0x4,                         0x4,                         0x4,                         0x4,                         0x4,                         0x4,                         0x4,                         0x4,                         0x4,                         0x4,                         0x4,                         0x4,                         0x4,                         0x4,                         0x4,                         0x4,                         0x4,                         0x4,                         0x4,                         0x4,                         0x4,                         0x4,                         0x4,                         0x4,                         0x4,                         0x4,                         0x4,                         0x4,                         0x4,                         0x4,                         0x4,                         0x4,                         0x4,                         0x4,                         0x4,                         0x4,                         0x4,                         0x4,                         0x4,                         0x4,                         0x4,                         0x4,                      0x4   ,                         0x4,                         0x4,                         0x4 },
/*                        SDFCFG_BFAEN */  {                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           1,                           0,                           0,                           1,                           1,                           0,                           0,                           0,                           1,                           0,                           1,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           1,                           1,                           0,                           0,                           1,                           1,                           1,                           0,                           1,                           1,                           1,                        0   ,                           1,                           1,                           1 },
/*                      SDFCFG1_ALTSCR */  {                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                        0   ,                           0,                           0,                           0 },
/*                        OACFG0_FECEN */  {                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                        0   ,                           0,                           0,                           0 },
/*                      OACFG0_PREDSCR */  {                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                        0   ,                           0,                           0,                           0 },
/*                     OACFG0_POSTDSCR */  {                           0,                           1,                           1,                           1,                           1,                           1,                           1,                           1,                           1,                           0,                           1,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           1,                           1,                           1,                           1,                           0,                           1,                           0,                           1,                           0,                           1,                           1,                           1,                           1,                           1,                           1,                           1,                           1,                           1,                           1,                           1,                           1,                           1,                           0,                           0,                           1,                           1,                           1,                           0 },
/*                      ODWCFG_JC_PLUS */  {                           0,                           0,                           0,                           0,                           0,                           1,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           1,                           0,                           0,                           0,                           1,                           1,                           1,                           1,                           1,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                        0   ,                           0,                           0,                           0 },
/*                        ODWCFG_FSOMD */  {                           0,                           0,                           1,                           1,                           1,                           1,                           1,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           1,                           1,                           1,                           1,                           1,                           1,                           1,                           1,                           1,                           0,                           0,                           0,                           0,                           0,                           1,                           1,                           1,                           1,                           1,                           1,                           0,                           0,                           0,                           1,                        1   ,                           1,                           0,                           0 },
/*                        ODWCFG_G43MD */  {                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           1,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           1,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                        0   ,                           0,                           0,                           0 },
/*                    ODWCFG_C15RES_EN */  {                        0   ,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           1,                           1,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                        0   ,                           0,                        0   ,                        0    },
/*                      ODWCFG_STM64MD */  {                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           1,                           0,                           1,                           1,                           0,                           0,                           1,                           0,                           0,                           0,                           1,                           0,                           0,                           1,                           1,                           1,                           1,                           0,                           0,                           1,                           1,                           0,                           1,                           1,                           0,                           0,                           0,                           1,                           1,                           1,                           0,                           0,                           0,                           0,                        0   ,                           1,                           0,                           0 },
/*                        ODWCFG_DWMOD */  {                         0x0,                         0x0,                         0x5,                         0x1,                         0x1,                         0x3,                         0x1,                         0x0,                         0x0,                         0x1,                         0x0,                         0x1,                         0x1,                         0x0,                         0x0,                         0x1,                         0x1,                         0x0,                         0x0,                         0x1,                         0x1,                         0x1,                         0x1,                         0x3,                         0x1,                         0x3,                         0x1,                         0x3,                         0x3,                         0x3,                         0x3,                         0x3,                         0x1,                         0x3,                         0x1,                         0x1,                         0x1,                         0x1,                         0x3,                         0x0,                         0x1,                         0x1,                         0x1,                         0x1,                         0x1,                         0x1,                         0x1 },
/*                        OFCFG1_NPARB */  {                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                      0x7   ,                         0x0,                         0x0,                         0x0 },
/*                         OFCFG1_NPAR */  {                         0x0,                        0x10,                        0x10,                        0x22,                        0x10,                        0x00,                        0x10,                        0x00,                        0x10,                         0x0,                        0x10,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                        0x10,                        0x10,                        0x10,                        0x10,                        0x00,                        0x22,                        0x00,                        0x10,                        0x00,                        0x10,                        0x10,                        0x17,                        0x10,                         0x0,                        0x10,                        0x10,                        0x17,                        0x10,                        0x10,                        0x10,                         0x0,                        0x10,                         0x0,                         0x0,                      0x8   ,                        0x2E,                        0x10,                        0x10 },
/*                        OFCFG0_NCOLS */  {                        0x00,                       0x0fe,                       0x0fe,                       0x110,                       0x0fe,                       0x0ee,                       0x0fe,                       0x0ee,                       0x0fe,                       0x0ee,                       0x0fe,                       0x0ee,                       0x0ee,                       0x0ee,                       0x0ee,                       0x0ee,                       0x0ee,                       0x0ee,                       0x0fe,                       0x0fe,                       0x0fe,                       0x0fe,                       0x0fe,                       0x0ee,                       0x110,                        0xee,                       0x0fe,                       0x0ee,                       0x0fe,                       0x0fe,                       0x105,                       0x0fe,                       0x0ee,                       0x0fe,                       0x0fe,                       0x105,                        0xfe,                        0xfe,                       0x0fe,                       0x0ee,                       0x0fe,                       0x0ee,                       0x0ee,                       0x0fe,                       0x11C,                       0x0fe,                       0x0fe },
/*                            ODWFS_FS */  {                        0x00,                        0x00,                        0x00,                        0x00,                        0x00,                       0x8E6,                        0x00,                        0x00,                        0x00,                        0x00,                        0x00,                         0x0,                         0x0,                        0x00,                         0x0,                        0x00,                        0x00,                        0x00,                        0x00,                        0x00,                        0x00,                        0x00,                        0x00,                        0x00,                        0x00,                        0x00,                        0x00,                        0x00,                        0x00,                        0x00,                        0x3a,                       0xA69,                        0x00,                       0x250,                        0x00,                        0x00,                        0x00,                        0x00,                        0x00,                        0x00,                        0x00,                        0x00,                        0x00,                       0x00 ,                        0x00,                        0x00,                        0x00 },
/*                       S1CFG_B1TRANS */  {                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                        0   ,                           0,                           0,                           0 },
/*                       S1CFG_B2TRANS */  {                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                        0   ,                           0,                           0,                           0 },
/*                     NOFCOLS_NOFCOLS */  {                        0x00,                      0x010d,                      0x010d,                      0x010d,                      0x010d,                      0x010d,                      0x010d,                      0x010d,                      0x010d,                      0x010d,                      0x010d,                      0x010d,                      0x010d,                      0x010d,                      0x010d,                      0x010d,                      0x010d,                      0x010d,                      0x010d,                      0x010d,                      0x010d,                      0x010d,                      0x010d,                      0x010d,                      0x010d,                      0x010d,                      0x010d,                      0x010d,                      0x010d,                      0x010d,                      0x010d,                      0x010d,                      0x010d,                      0x010d,                      0x010d,                      0x010d,                      0x010d,                       0x10d,                      0x010d,                      0x010d,                      0x010d,                      0x010d,                      0x010d,                      0x010d,                      0x010d,                       0x10d,                       0x10d },
/*                       K12CFG_KAFLEN */  {                         0x0,                         0x3,                         0x3,                         0x3,                         0x3,                         0x3,                         0x3,                         0x3,                         0x3,                         0x3,                         0x3,                         0x3,                         0x3,                         0x3,                         0x3,                         0x3,                         0x3,                         0x3,                         0x3,                         0x3,                         0x3,                         0x3,                         0x3,                         0x3,                         0x3,                         0x3,                         0x3,                         0x3,                         0x3,                         0x3,                         0x3,                         0x3,                         0x3,                         0x3,                         0x3,                         0x3,                         0x3,                         0x3,                         0x3,                         0x3,                         0x3,                         0x3,                         0x3,                      0x3   ,                         0x3,                         0x3,                         0x3 } };

const cs_uint16 ten_n10g_tx_table[TEN_N10G_TX_MAX_PARM][TEN_N10G_TX_MAX_MODE] = {
/*                                                       DISABLE                      BYPASS                       10GFC_OTU2_U15               OPU2_OTU2                    ODU2_ODU2                    8GFC_OTU2                    8GFC_ODU2j                   10GE_ODU2e_OxU3j             10GE_OTU2e                   10GE_ODU2e_OxU3              10GE_OTU1e                   10GE_ODU1e_OxU3              10GFC_OTU2fc                 10GFC_ODU2fc_OxU3            OC192_OxU3                   OC192_OxU3p                  ODU2_OxU3                    10GFC_OxU3                   10GE_OxU3p                   10GE_OxU3                    ODU2_OxU3p                   OC192_ODU2                   OC192_OTU2ej                 10GE_OTU2                    10GE_OTU2xj                  10GE_OTU2ej                  10GFC_OTU2ej                 8GFC_OTU2ej                  ODU1e_OTU1e                  ODU2_OTU2                    ODU2e_OTU2e                  ODU2_OTU2_10U                10GE_OC192_OTU2              10GE_OC192                   OC192_OTU2                   OC192_OC192pt                10GE_192_OxU3                10GE_ODU2_OxU3               10GE_ODU2e_OxU3_dt           10GE_OTU2_34                 OTU2_OxU3_NT                 FC_TRANS_OxU3_NT             OTU2e_OxU3_NT                OC192_OTU2_10U               10GE_OC192_OTU2_20U          OTU2_GENRM_ODU3              ODU3_GENRM_OTU2               */
/*                                                       ============                 ============                 ============                 ============                 ============                 ============                 ============                 ============                 ============                 ============                 ============                 ============                 ============                 ============                 ============                 ============                 ============                 ============                 ============                 ============                 ============                 ============                 ============                 ============                 ============                 ============                 ============                 ============                 ============                 ============                 ============                 ============                 ============                 ============                 ============                 ============                 ============                 ============                 ============                 ============                 ============                 ============                 ============                 ============                 ============                 ============                 ============                  */
/*                          CFGTX0_SBY */  {                           0,                           1,                           1,                           1,                           1,                           1,                           1,                           1,                           1,                           1,                           1,                           1,                           1,                           1,                           0,                           0,                           1,                           1,                           1,                           1,                           1,                           1,                           1,                           1,                           1,                           1,                           1,                           1,                           1,                           1,                           1,                           1,                           0,                           0,                           1,                           0,                           0,                           1,                           1,                           1,                           1,                           1,                           1,                           1,                           0,                           1,                           1 },
/*                          CFGTX0_OBY */  {                           0,                           1,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           1,                           1,                           0,                           0,                           1,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           1,                           0,                           1,                           0,                           0,                           0,                           0,                           1,                           0,                           0,                           0,                           0,                           0,                           1 },
/*                        CFGTX0_KPGBY */  {                           0,                           1,                           1,                           1,                           1,                           1,                           1,                           1,                           1,                           1,                           1,                           1,                           1,                           1,                           1,                           1,                           1,                           1,                           1,                           1,                           1,                           1,                           1,                           1,                           1,                           1,                           1,                           1,                           1,                           1,                           1,                           1,                           1,                           1,                           1,                           1,                           1,                           1,                           1,                           1,                           1,                           1,                           1,                           1,                           1,                           1,                           1 },
/*                       CFGTX0_OTNOFF */  {                           0,                           1,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           1,                           0,                           1,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0 },
/*                       FRMLEN_FRMLEN */  {                         0x0,                      0x10d8,                      0x10d8,                      0x10d8,                      0x10d8,                      0x10d8,                      0x10d8,                      0x10d8,                      0x10d8,                      0x10d8,                      0x10d8,                      0x10d8,                      0x10d8,                      0x10d8,                      0x10d8,                      0x10d8,                      0x10d8,                      0x10d8,                      0x10d8,                      0x10d8,                      0x10d8,                      0x10d8,                      0x10d8,                      0x10d8,                      0x10d8,                      0x10d8,                      0x10d8,                      0x10d8,                      0x10d8,                      0x10d8,                      0x10d8,                      0x10d8,                      0x10d8,                      0x10d8,                      0x10d8,                      0x10d8,                      0x10d8,                      0x10d8,                      0x10d8,                      0x10d8,                      0x10d8,                      0x10d8,                      0x10d8,                      0x10d8,                      0x10d8,                      0x10d8,                      0x10d8 },
/*                        OHBEN0_SCREN */  {                           0,                           1,                           1,                           1,                           1,                           1,                           1,                           1,                           1,                           1,                           1,                           1,                           1,                           1,                           1,                           1,                           1,                           1,                           1,                           1,                           1,                           1,                           1,                           1,                           1,                           1,                           1,                           1,                           1,                           1,                           1,                           1,                           1,                           1,                           1,                           1,                           1,                           1,                           1,                           1,                           1,                           1,                           1,                           1,                           1,                           0,                           1 },
/*                      OHBEN0_A1A2RSH */  {                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           1,                           1,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           1,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0 },
/*                         OHBEN0_B1IE */  {                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           1,                           1,                           0,                           1,                           1,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           1,                           0,                           0 },
/*                       OHBEN0_A1A2IE */  {                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           1,                           1,                           0,                           0,                           1,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           1,                           0,                           0 },
/*                         OHBEN0_J0IE */  {                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           1,                           1,                           0,                           0,                           1,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           1,                           0,                           0 },
/*                        OHBEN0_DEFIE */  {                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           1,                           1,                           0,                           0,                           1,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           1,                           0,                           0 },
/*                        OHBEN0_NU1IE */  {                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x1,                         0x1,                         0x0,                         0x0,                         0x1,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x1,                         0x0,                         0x0 },
/*                        OHBEN1_B2INV */  {                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0 },
/*                        OHBEN1_B1INV */  {                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0 },
/*                      OHBEN1_B1TRANS */  {                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0 },
/*                      OHBEN1_B2TRANS */  {                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0 },
/*                         OHBEN1_K1IE */  {                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           1,                           1,                           0,                           0,                           1,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           1,                           0,                           0 },
/*                         OHBEN1_K2IE */  {                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           1,                           1,                           0,                           0,                           1,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           1,                           0,                           0 },
/*                         OHBEN2_M0IE */  {                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           1,                           1,                           0,                           0,                           1,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           1,                           0,                           0 },
/*                         OHBEN2_M1IE */  {                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           1,                           1,                           0,                           0,                           1,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           1,                           0,                           0 },
/*                       SOHBYTES5_NU1 */  {                        0x00,                        0x00,                        0x00,                        0x00,                        0x00,                        0x00,                        0x00,                        0x00,                        0x00,                        0x00,                        0x00,                        0x00,                        0x00,                        0x00,                        0x00,                        0x00,                        0x00,                        0x00,                        0x00,                        0x00,                        0x00,                        0x00,                        0x00,                        0x00,                        0x00,                        0x00,                        0x00,                        0x00,                        0x00,                        0x00,                        0x00,                        0x00,                        0xCC,                        0xCC,                        0x00,                        0x00,                        0xCC,                        0x00,                        0x00,                        0x00,                        0x00,                        0x00,                        0x00,                        0x00,                        0xCC,                        0x00,                        0x00 },
/*                    OHBEN3_ALT_SCREN */  {                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0 },
/*                   B1ERRINS_B1ERRMSK */  {                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                           0,                           0,                           0,                           0,                         0x0,                           0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0 },
/*                   B2ERRINS_B2ERRMSK */  {                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                           0,                           0,                           0,                           0,                         0x0,                           0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0 },
/*                    SOHBYTES2_K2BYTE */  {                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                           0,                           0,                           0,                           0,                         0x0,                           0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0 },
/*                    SOHBYTES2_K1BYTE */  {                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                           0,                           0,                           0,                           0,                         0x0,                           0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0 },
/*                     SOHBYTES3_OHDEF */  {                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                           0,                           0,                           0,                           0,                         0x0,                           0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0 },
/*                      POHBEN0_PRBSIE */  {                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0 },
/*                       POHBEN0_POHIE */  {                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           1,                           1,                           0,                           0,                           1,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           1,                           0,                           0 },
/*                        POHBEN0_B3IE */  {                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           1,                           1,                           0,                           0,                           1,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           1,                           0,                           0 },
/*                        POHBEN0_C2IE */  {                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           1,                           1,                           0,                           0,                           1,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           1,                           0,                           0 },
/*                        POHBEN0_J1IE */  {                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           1,                           1,                           0,                           0,                           1,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           1,                           0,                           0 },
/*                    POHBYTES0_C2BYTE */  {                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x1,                         0x1,                         0x0,                         0x0,                         0x1,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x1,                         0x0,                         0x0 },
/*                     J0STRG0_J0STRG0 */  {                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x2,                         0x2,                         0x0,                         0x0,                         0x2,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x2,                         0x0,                         0x0 },
/*                         B2IE0_B2IE0 */  {                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                      0xFFFF,                      0xFFFF,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                      0xFFFF,                      0xFFFF,                         0x0,                      0xFFFF,                      0xFFFF,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                      0xFFFF,                         0x0,                         0x0 },
/*                         B2IE1_B2IE1 */  {                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                      0xFFFF,                      0xFFFF,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                      0xFFFF,                      0xFFFF,                         0x0,                      0xFFFF,                      0xFFFF,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                      0xFFFF,                         0x0,                         0x0 },
/*                         B2IE2_B2IE2 */  {                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                      0xFFFF,                      0xFFFF,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                      0xFFFF,                      0xFFFF,                         0x0,                      0xFFFF,                      0xFFFF,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                      0xFFFF,                         0x0,                         0x0 },
/*                         B2IE3_B2IE3 */  {                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                      0xFFFF,                      0xFFFF,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                      0xFFFF,                      0xFFFF,                         0x0,                      0xFFFF,                      0xFFFF,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                      0xFFFF,                         0x0,                         0x0 },
/*                         B2IE4_B2IE4 */  {                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                      0xFFFF,                      0xFFFF,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                      0xFFFF,                      0xFFFF,                         0x0,                      0xFFFF,                      0xFFFF,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                      0xFFFF,                         0x0,                         0x0 },
/*                         B2IE5_B2IE5 */  {                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                      0xFFFF,                      0xFFFF,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                      0xFFFF,                      0xFFFF,                         0x0,                      0xFFFF,                      0xFFFF,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                      0xFFFF,                         0x0,                         0x0 },
/*                         B2IE6_B2IE6 */  {                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                      0xFFFF,                      0xFFFF,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                      0xFFFF,                      0xFFFF,                         0x0,                      0xFFFF,                      0xFFFF,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                      0xFFFF,                         0x0,                         0x0 },
/*                         B2IE7_B2IE7 */  {                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                      0xFFFF,                      0xFFFF,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                      0xFFFF,                      0xFFFF,                         0x0,                      0xFFFF,                      0xFFFF,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                      0xFFFF,                         0x0,                         0x0 },
/*                         B2IE8_B2IE8 */  {                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                      0xFFFF,                      0xFFFF,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                      0xFFFF,                      0xFFFF,                         0x0,                      0xFFFF,                      0xFFFF,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                      0xFFFF,                         0x0,                         0x0 },
/*                         B2IE9_B2IE9 */  {                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                      0xFFFF,                      0xFFFF,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                      0xFFFF,                      0xFFFF,                         0x0,                      0xFFFF,                      0xFFFF,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                      0xFFFF,                         0x0,                         0x0 },
/*                       B2IE10_B2IE10 */  {                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                      0xFFFF,                      0xFFFF,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                      0xFFFF,                      0xFFFF,                         0x0,                      0xFFFF,                      0xFFFF,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                      0xFFFF,                         0x0,                         0x0 },
/*                       B2IE11_B2IE11 */  {                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                      0xFFFF,                      0xFFFF,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                      0xFFFF,                      0xFFFF,                         0x0,                      0xFFFF,                      0xFFFF,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                      0xFFFF,                         0x0,                         0x0 },
/*                       B2IE12_B2IE12 */  {                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                      0xFFFF,                      0xFFFF,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                      0xFFFF,                      0xFFFF,                         0x0,                      0xFFFF,                      0xFFFF,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                      0xFFFF,                         0x0,                         0x0 },
/*                         OCFG_PRESCR */  {                           0,                           1,                           1,                           1,                           1,                           1,                           1,                           0,                           1,                           0,                           1,                           0,                           1,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           1,                           1,                           1,                           1,                           1,                           1,                           1,                           1,                           1,                           1,                           1,                           1,                           1,                           1,                           1,                           0,                           0,                           0,                           1,                           0,                           0,                           0,                           1,                           1,                           0,                           0 },
/*                        OCFG_POSTSCR */  {                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0 },
/*                        WRPCFG3_WRMD */  {                         0x0,                         0x0,                         0x1,                         0x1,                         0x0,                         0x1,                         0x1,                         0x1,                         0x1,                         0x1,                         0x1,                         0x1,                         0x1,                         0x1,                         0x1,                         0x1,                         0x0,                         0x0,                         0x1,                         0x1,                         0x0,                         0x1,                         0x1,                         0x1,                         0x1,                         0x1,                         0x1,                         0x1,                         0x3,                         0x3,                         0x3,                         0x3,                         0x1,                         0x0,/*Bugzilla 17309 29758*/ 0x1,                         0x0,                         0x1,                         0x1,                         0x1,                         0x1,                         0x0,                         0x1,                         0x1,                         0x1,                         0x1,                         0x1,                         0x0 },
/*                   WRPCFG3_C15RES_EN */  {                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x1,                         0x1,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0 },
/*                     WRPCFG3_STM64MD */  {                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x1,                         0x1,                         0x1,                         0x0,                         0x0,                         0x1,                         0x1,                         0x1,                         0x1,                         0x0,                         0x0,                         0x1,                         0x0,                         0x0,                         0x1,                         0x0,                         0x0,                         0x0,                         0x1,                         0x1,                         0x1,                         0x0,                         0x0,                         0x1,                         0x0,                           1,                           1,                           1,                           0,                         0x0,                         0x0,                         0x1,                         0x0,                         0x0,                         0x0,                         0x1,                           1,                           1,                         0x0,                         0x1 },
/*                       WRPCFG3_G43MD */  {                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x1,                         0x0,                         0x0,                         0x0,                         0x1,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                           0,                           0,                           0,                           0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                           0,                           0,                         0x0,                         0x0 },
/*                       WRPCFG0_NCOLS */  {                         0x0,                       0x0fe,                       0x110,                       0x0fe,                       0x0ee,                       0x0fe,                       0x0ee,                       0x0ee,                       0x0fe,                       0x0ee,                       0x0fe,                       0x0ee,                       0x110,                        0xee,                       0x0ee,                       0x0ee,                       0x0ee,                       0x0ee,                       0x0ee,                       0x0ee,                       0x0ee,                       0x0ee,                       0x0fe,                       0x0fe,                       0x105,                       0x0fe,                       0x0fe,                       0x0fe,                       0x0fe,                       0x0fe,                       0x0fe,                       0x105,                       0x0fe,                       0x0fe,                       0x0fe,                       0x0fe,                       0x0ee,                       0x0ee,                       0x0ee,                      0x0fe ,                       0x0ee,                      0x0fe ,                       0x0ee,                       0x105,                       0x11C,                       0x0fe,                       0x0fe },
/*                        WRPCFG2_NPAR */  {                         0x0,                        0x10,                        0x22,                        0x10,                         0x0,                        0x10,                         0x0,                         0x0,                        0x10,                        0x00,                        0x10,                        0x00,                        0x22,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                        0x10,                        0x10,                        0x17,                        0x10,                        0x10,                        0x10,                        0x10,                        0x10,                        0x10,                        0x17,                        0x10,                        0x10,                        0x10,                        0x10,                         0x0,                         0x0,                         0x0,                         0x8,                         0x0,                         0x8,                        0x00,                        0x17,                        0x2E,                        0x10,                        0x10 },
/*                       WRPCFG2_NPARB */  {                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                           0,                           0,                         0x0,                         0x0,                         0x0,                         0x7,                         0x0,                         0x7,                         0x0,                           0,                         0x0,                         0x0,                         0x0 },
/*                   WRPCFG4_JCEN_OTU2 */  {                           0,                           0,                           0,                           0,                           0,                           0,                           1,                           0,                           0,                           1,                           0,                           1,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           1,                           1,                           0,                           1,                           1,                           1,                           1,                           0,                           0,                           0,                           0,                           0,                           0,                           1,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           1,                           1,                           0,                           0,                           0 },
/*                 WRPCFG4_JCEN_ODTU23 */  {                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           1,                           1,                           0,                           0,                           0,                           0,                           1,                           1,                           1,                           1,                           1,                           1,                           0,                           1,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           1,                           1,                           1,                           0,                           0,                           0,                           1,                           1 },
/*                     WRPCFG4_JCEN_DT */  {                           0,                           0,                           0,                           0,                           0,                           0,                           1,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           1,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           1,                           1,                           1,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0 },
/*                WRPCFG4_JC_PLUS_OTU2 */  {                           0,                           0,                           0,                           0,                           0,                           0,                           1,                           0,                           0,                           1,                           0,                           1,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           1,                           1,                           1,                           1,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           1,                           0,                           0,                           0,                           0 },
/*              WRPCFG4_JC_PLUS_ODTU23 */  {                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           1,                           1,                           0,                           0,                           0,                           0,                           1,                           1,                           1,                           1,                           1,                           1,                           0,                           1,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           0,                           1,                           1,                           1,                           0,                           0,                           0,                           1,                           1 },
/*                            WRPFS_FS */  {                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                       0x8E6,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                       0x250,                         0x0,                        0x3a,                         0x0,                         0x0,                       0xA69,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0,                         0x0 },
/*                         CFG4_BIPMSK */  {                        0x00,                        0xff,                        0xff,                        0xff,                        0xff,                        0xff,                        0xff,                        0xff,                        0xff,                        0xff,                        0xff,                        0xff,                        0xff,                        0xff,                        0xff,                        0xff,                        0xff,                        0xff,                        0xff,                        0xff,                        0xff,                        0xff,                        0xff,                        0xff,                        0xff,                        0xff,                        0xff,                        0xff,                        0xff,                        0xff,                        0xff,                        0xff,                        0xff,                        0xff,                        0xff,                        0xff,                        0xff,                        0xff,                        0xff,                        0xff,                        0xff,                        0xff,                        0xff,                        0xff,                        0xff,                        0xff,                        0xff },
/*                           CFG0_PTIE */  {                           0,                           0,                           1,                           1,                           0,                           1,                           1,                           1,                           1,                           1,                           1,                           1,                           1,                           1,                           1,                           1,                           0,                           0,                           1,                           1,                           0,                           1,                           1,                           1,                           1,                           1,                           1,                           1,                           1,                           1,                           1,                           1,                           1,                           1,                           1,                           1,                           1,                           1,                           1,                           1,                           0,                           1,                           1,                           1,                           1,                           1,                           0 },
/*                             CFG2_PT */  {                        0x00,                        0x00,                        0x03,                        0x03,                        0x00,                        0x03,                        0x02,                        0x03,                        0x03,                        0x02,                        0x03,                        0x02,                        0x03,                        0x03,                        0x03,                        0x03,                        0x00,                        0x00,                        0x08,                        0x09,                        0x00,                        0x02,                        0x02,                        0x09,                        0x02,                        0x02,                        0x02,                        0x02,                        0x03,                        0x03,                        0x03,                        0x03,                        0x03,                        0x03,                        0x02,                        0x03,                        0x03,                        0x03,                        0x03,                        0x03,                        0x00,                        0x08,                        0x02,                        0x02,                        0x03,                        0x03,                        0x00 },
/*                         EXPTI_EXPTI */  {                        0x00,                        0x00,                        0x03,                        0x03,                        0x00,                        0x03,                        0x02,                        0x03,                        0x03,                        0x02,                        0x03,                        0x02,                        0x03,                        0x03,                        0x03,                        0x03,                        0x00,                        0x00,                        0x08,                        0x09,                        0x00,                        0x02,                        0x02,                        0x09,                        0x02,                        0x02,                        0x02,                        0x02,                        0x03,                        0x03,                        0x03,                        0x03,                        0x03,                        0x03,                        0x02,                        0x03,                        0x03,                        0x03,                        0x03,                        0x03,                        0x00,                        0x08,                        0x02,                        0x02,                        0x03,                        0x03,                        0x00 } };

const cs_char8 *ten_n10g_rx_debug_str[TEN_N10G_RX_MAX_MODE] = {
  "TEN_N10G_RX_DISABLE",
  "TEN_N10G_RX_BYPASS",
  "TEN_N10G_RX_OTU2_ODU2_FS",
  "TEN_N10G_RX_OTU2_U15_10GFC",
  "TEN_N10G_RX_OTU2_OPU2",
  "TEN_N10G_RX_ODU2J_8GFC",
  "TEN_N10G_RX_OTU2_8GFC",
  "TEN_N10G_RX_ODU2_ODU2",
  "TEN_N10G_RX_OC192_OC192",
  "TEN_N10G_RX_OXU3J_ODU2E_10GE",
  "TEN_N10G_RX_OTU2E_ODU2",
  "TEN_N10G_RX_OXU3_OC192",
  "TEN_N10G_RX_OXU3_OC192P",
  "TEN_N10G_RX_OXU3_ODU2",
  "TEN_N10G_RX_OXU3_ODU2P",
  "TEN_N10G_RX_OXU3_10GEP",
  "TEN_N10G_RX_OXU3_10GE",
  "TEN_N10G_RX_OXU3_10GFC",
  "TEN_N10G_RX_OXU3_OC192_10GE",
  "TEN_N10G_RX_OTU2E_ODU2E",
  "TEN_N10G_RX_OTU1E_ODU1E",
  "TEN_N10G_RX_OTU2_ODU2",
  "TEN_N10G_RX_OTU2E_10GE",
  "TEN_N10G_RX_OXU3_ODU2E_10GE",
  "TEN_N10G_RX_OTU2FC_10GFC",
  "TEN_N10G_RX_OXU3_ODU2FC_10GFC",
  "TEN_N10G_RX_OTU1E_10GE",
  "TEN_N10G_RX_OXU3_ODU1E_10GE",
  "TEN_N10G_RX_OTU2EJ_10GE",
  "TEN_N10G_RX_OTU2EJ_10GFC",
  "TEN_N10G_RX_OTU2XJ_10GE",
  "TEN_N10G_RX_OTU2EJ_8GFC",
  "TEN_N10G_RX_ODU2_OC192",
  "TEN_N10G_RX_OTU2EJ_OC192",
  "TEN_N10G_RX_OTU2_10GE",
  "TEN_N10G_RX_OTU2_10U_ODU2",
  "TEN_N10G_RX_OTU2_OC192_10GE",
  "TEN_N10G_RX_OC192_10GE",
  "TEN_N10G_RX_OTU2_OC192",
  "TEN_N10G_RX_BYPASS_P",
  "TEN_N10G_RX_OTU2_OC192PT",
  "TEN_N10G_RX_OXU3_ODU2_10GE",
  "TEN_N10G_RX_OXU3_192_10GE",
  "TEN_N10G_RX_OTU2_34_10GE",
  "TEN_N10G_RX_OTU2_OC192_10GE_20U",
  "TEN_N10G_RX_OTU2_GENRM_ODU3",
  "TEN_N10G_RX_ODU3_GENRM_OTU2"
};

const cs_char8 *ten_n10g_tx_debug_str[TEN_N10G_TX_MAX_MODE] = {
  "TEN_N10G_TX_DISABLE",
  "TEN_N10G_TX_BYPASS",
  "TEN_N10G_TX_10GFC_OTU2_U15",
  "TEN_N10G_TX_OPU2_OTU2",
  "TEN_N10G_TX_ODU2_ODU2",
  "TEN_N10G_TX_8GFC_OTU2",
  "TEN_N10G_TX_8GFC_ODU2J",
  "TEN_N10G_TX_10GE_ODU2E_OXU3J",
  "TEN_N10G_TX_10GE_OTU2E",
  "TEN_N10G_TX_10GE_ODU2E_OXU3",
  "TEN_N10G_TX_10GE_OTU1E",
  "TEN_N10G_TX_10GE_ODU1E_OXU3",
  "TEN_N10G_TX_10GFC_OTU2FC",
  "TEN_N10G_TX_10GFC_ODU2FC_OXU3",
  "TEN_N10G_TX_OC192_OXU3",
  "TEN_N10G_TX_OC192_OXU3P",
  "TEN_N10G_TX_ODU2_OXU3",
  "TEN_N10G_TX_10GFC_OXU3",
  "TEN_N10G_TX_10GE_OXU3P",
  "TEN_N10G_TX_10GE_OXU3",
  "TEN_N10G_TX_ODU2_OXU3P",
  "TEN_N10G_TX_OC192_ODU2",
  "TEN_N10G_TX_OC192_OTU2EJ",
  "TEN_N10G_TX_10GE_OTU2",
  "TEN_N10G_TX_10GE_OTU2XJ",
  "TEN_N10G_TX_10GE_OTU2EJ",
  "TEN_N10G_TX_10GFC_OTU2EJ",
  "TEN_N10G_TX_8GFC_OTU2EJ",
  "TEN_N10G_TX_ODU1E_OTU1E",
  "TEN_N10G_TX_ODU2_OTU2",
  "TEN_N10G_TX_ODU2E_OTU2E",
  "TEN_N10G_TX_ODU2_OTU2_10U",
  "TEN_N10G_TX_10GE_OC192_OTU2",
  "TEN_N10G_TX_10GE_OC192",
  "TEN_N10G_TX_OC192_OTU2",
  "TEN_N10G_TX_OC192_OC192PT",
  "TEN_N10G_TX_10GE_192_OXU3",
  "TEN_N10G_TX_10GE_ODU2_OXU3",
  "TEN_N10G_TX_10GE_ODU2E_OXU3_DT",
  "TEN_N10G_TX_10GE_OTU2_34",
  "TEN_N10G_TX_OTU2_OXU3_NT",
  "TEN_N10G_TX_FC_TRANS_OXU3_NT",
  "TEN_N10G_TX_OTU2E_OXU3_NT",
  "TEN_N10G_TX_OC192_OTU2_10U",
  "TEN_N10G_TX_10GE_OC192_OTU2_20U",
  "TEN_N10G_TX_OTU2_GENRM_ODU3",
  "TEN_N10G_TX_ODU3_GENRM_OTU2"
};

/****************************************************************/
/* $rtn_hdr_start  N10G CONFIG                                  */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : HIGH LEVEL                                      */
/* CHIP       : Tenabo                                          */
cs_status ten_hl_n10g_config(cs_uint16 module_id,
                             cs_uint8 slice,
                             cs_uint8 mode_rx,
                             cs_uint8 mode_tx,
                             cs_uint16 dyn_repro)
/* INPUTS     : o Module Id                                     */
/*              o Slice                                         */
/*              o Mode RX                                       */
/*              o Mode TX                                       */
/*              o Dynamic Reprovision                           */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* Configures an N10G transmit/receive path.                    */
/*                                                              */
/* The [slice] parameter is specified as:                       */
/*   0x00 = TEN_SLICE0                                          */
/*   0x01 = TEN_SLICE1                                          */
/*   0x02 = TEN_SLICE2                                          */
/*   0x03 = TEN_SLICE3                                          */
/*   0xFF = TEN_SLICE_ALL                                       */
/*                                                              */
/* The [mode_rx] parameter is specified as:                     */
/*   the 'mode' parameter for ten_hl_n10g_rx_init, e.g.         */
/*     TEN_N10G_RX_OXU3_OC192                                   */
/*     TEN_N10G_RX_OC192_OC192                                  */
/*     TEN_N10G_RX_OXU3_10GE                                    */
/*     TEN_N10G_RX_BYPASS                                       */
/*                                                              */
/* The [mode_tx] parameter is specified as:                     */
/*   the 'mode' parameter for ten_hl_n10g_tx_init, e.g.         */
/*     TEN_N10G_TX_OC192_OXU3                                   */
/*     TEN_N10G_TX_OC192_OC192PT                                */
/*     TEN_N10G_TX_10GE_OXU3                                    */
/*     TEN_N10G_TX_BYPASS                                       */
/*                                                              */
/* The [dyn_repo] parameter is specified as:                    */
/*    0 - full provision                                        */
/*    1 - dynamic reprovision.                                  */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  cs_uint16 dev_id;
  cs_uint16 module;
  cs_char8 *func = "ten_hl_n10g_config";  
  cs_status rtn = CS_OK;

  CS_PRINT("ten_hl_n10g_config, module_id=%d, slice=%d, mode_rx=%d, mode_tx=%d, dyn_repro=%d\n", module_id, slice, mode_rx, mode_tx, dyn_repro);

  TEN_N10G_VALIDATE(module_id, slice);

  if (mode_rx >= TEN_N10G_RX_MAX_MODE) {
     CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": Invalid RX Mode!");
     rtn = CS_ERROR;
     goto RTN_EXIT;
  }

  if (mode_tx >= TEN_N10G_TX_MAX_MODE) {
     CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": Invalid TX Mode!");
     rtn = CS_ERROR;
     goto RTN_EXIT;
  }

  dev_id = TEN_MOD_ID_TO_DEV_ID(module_id);
  module = TEN_MOD_ID_TO_MOD_NUM(module_id);

  /* Provide clock for this slice's RX and TX for the N10G and N40G blocks */
  rtn |= ten_mpif_global_clock_disable_n10g(dev_id, module, slice, CS_TX_AND_RX, CS_ENABLE);
  /* Remove reset for this slice's RX and TX for the N10G block */
  rtn |= ten_mpif_global_reset_n10g(dev_id, module, slice, CS_TX_AND_RX, CS_RESET_DEASSERT);
  
  if (dyn_repro) {
    /* Bugzilla #36979, Fix dynamic reconfiguration issues */
    if ((mode_tx != TEN_N10G_TX_BYPASS) && (mode_tx != TEN_N10G_TX_DISABLE)) { 
      rtn |= ten_hl_n10g_reconfig_set_defaults(module_id, slice);
    } 
  
    rtn |= ten_hl_n10g_reconfig_rx_init(module_id, slice, mode_rx);
    rtn |= ten_hl_n10g_reconfig_tx_init(module_id, slice, mode_tx);
  }
  else {
    rtn |= ten_hl_n10g_rx_init(module_id, slice, mode_rx);
    rtn |= ten_hl_n10g_tx_init(module_id, slice, mode_tx);
  }
  
  /* Bugzilla 32145 Start */
  /* Turn off GMP wrapping for non-GMP configs so drl from gmp -> amp/bmp will work */
  if (ten_dev_is_t41(TEN_MOD_ID_TO_DEV_ID(module_id))) {
    rtn |= ten_n10g_gmp_off_t41 (module_id, slice);
  }
  /* Bugzilla 32145 End */
  
RTN_EXIT:
  if (rtn != CS_OK) {
    CS_PRINT("%s() FAILED!\n", func);
  }

  return (rtn);
}

/* Bugzilla 24750 Start */
/********************************************************************/
/* N10G OTN ALIGNER SETTINGS                                        */
cs_status ten_hl_n10g_otn_aligner_settings(cs_uint16 module_id, cs_uint8 slice)
/* INPUTS     : o Module Id                                         */
/*              o Slice                                             */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Internal routine that sets the recommended OTN aligner settings  */
/*                                                                  */
/********************************************************************/
{
  cs_uint8 sl;
  TEN_N10G_OTNR_OACFG0_t tmp_otnr_oacfg0;
  TEN_N10G_OTNR_OACFG1_t tmp_otnr_oacfg1;
  TEN_N10G_OTNR_OACFG2_t tmp_otnr_oacfg2;
  T41_t *pDev = NULL;

  if ((slice >= TEN_MAX_SLICES) && (slice != TEN_SLICE_ALL)) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": slice out of range.  s/b 0..3.");
    return(CS_ERROR);
  }

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_N10G);

  for (sl=0; sl<TEN_MAX_SLICES; sl++) {
    if ((slice == sl) || (slice == TEN_SLICE_ALL)) {
      tmp_otnr_oacfg0.wrd = TEN_REG_READ(TEN_N10G_REG_ADDR(pDev, module_id, sl, OACFG0));
      /* tmp_otnr_oacfg0.bf.DSYHYST = 11 or 6, set in ten_hl_fec_config */
      tmp_otnr_oacfg0.bf.DSYHYST = 11;
      tmp_otnr_oacfg0.bf.SYHYST = 0;
      TEN_REG_WRITE(TEN_N10G_REG_ADDR(pDev, module_id, sl, OACFG0), tmp_otnr_oacfg0.wrd);

      tmp_otnr_oacfg1.wrd = TEN_REG_READ(TEN_N10G_REG_ADDR(pDev, module_id, sl, OACFG1));
      tmp_otnr_oacfg1.bf.FSIZES = 32;
      tmp_otnr_oacfg1.bf.FSIZEP = 32;
      TEN_REG_WRITE(TEN_N10G_REG_ADDR(pDev, module_id, sl, OACFG1), tmp_otnr_oacfg1.wrd);

      tmp_otnr_oacfg2.wrd = TEN_REG_READ(TEN_N10G_REG_ADDR(pDev, module_id, sl, OACFG2));
      tmp_otnr_oacfg2.bf.FTOLD = 1;
      tmp_otnr_oacfg2.bf.FTOLS = 0;
      tmp_otnr_oacfg2.bf.FSIZED = 24;
      TEN_REG_WRITE(TEN_N10G_REG_ADDR(pDev, module_id, sl, OACFG2), tmp_otnr_oacfg2.wrd);
    }
  }
  TEN_MOD_UNLOCK(module_id, TEN_ID_N10G);

  return (CS_OK);
}
/* Bugzilla 24750 End */

/****************************************************************/
/* $rtn_hdr_start  N10G RX INITIALIZATION                       */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : HIGH LEVEL                                      */
/* CHIP       : Tenabo                                          */
cs_status ten_hl_n10g_rx_init(cs_uint16 module_id,
                              cs_uint8 slice,
                              cs_uint8 mode)
/* INPUTS     : o Module Id                                     */
/*              o Slice                                         */
/*              o Mode                                          */
/*                                                              */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* Configure N10G for traffic.                                  */
/*                                                              */
/* The [slice] parameter is specified as:                       */
/*   0x00 = TEN_SLICE0                                          */
/*   0x01 = TEN_SLICE1                                          */
/*   0x02 = TEN_SLICE2                                          */
/*   0x03 = TEN_SLICE3                                          */
/*   0xFF = TEN_SLICE_ALL                                       */
/*                                                              */
/* The [mode] parameter is specified as:                        */
/*   TEN_N10G_RX_DISABLE                           = 0,         */
/*   TEN_N10G_RX_BYPASS                            = 1,         */
/*   TEN_N10G_RX_OTU2_ODU2_FS                      = 2,         */
/*   TEN_N10G_RX_OTU2_U15_10GFC                    = 3,         */
/*   TEN_N10G_RX_OTU2_OPU2                         = 4,         */
/*   TEN_N10G_RX_ODU2J_8GFC                        = 5,         */
/*   TEN_N10G_RX_OTU2_8GFC                         = 6,         */
/*   TEN_N10G_RX_ODU2_ODU2                         = 7,         */
/*   TEN_N10G_RX_OC192_OC192                       = 8,         */
/*   TEN_N10G_RX_OXU3J_ODU2E_10GE                  = 9,         */
/*   TEN_N10G_RX_OTU2E_ODU2                        = 10,        */
/*   TEN_N10G_RX_OXU3_OC192                        = 11,        */
/*   TEN_N10G_RX_OXU3_OC192P                       = 12,        */
/*   TEN_N10G_RX_OXU3_ODU2                         = 13,        */
/*   TEN_N10G_RX_OXU3_ODU2P                        = 14,        */
/*   TEN_N10G_RX_OXU3_10GEP                        = 15,        */
/*   TEN_N10G_RX_OXU3_10GE                         = 16,        */
/*   TEN_N10G_RX_OXU3_10GFC                        = 17,        */
/*   TEN_N10G_RX_OXU3_OC192_10GE                   = 18,        */
/*   TEN_N10G_RX_OTU2E_ODU2E                       = 19,        */
/*   TEN_N10G_RX_OTU1E_ODU1E                       = 20,        */
/*   TEN_N10G_RX_OTU2_ODU2                         = 21,        */
/*   TEN_N10G_RX_OTU2E_10GE                        = 22,        */
/*   TEN_N10G_RX_OXU3_ODU2E_10GE                   = 23,        */
/*   TEN_N10G_RX_OTU2FC_10GFC                      = 24,        */
/*   TEN_N10G_RX_OXU3_ODU2FC_10GFC                 = 25,        */
/*   TEN_N10G_RX_OTU1E_10GE                        = 26,        */
/*   TEN_N10G_RX_OXU3_ODU1E_10GE                   = 27,        */
/*   TEN_N10G_RX_OTU2EJ_10GE                       = 28,        */
/*   TEN_N10G_RX_OTU2EJ_10GFC                      = 29,        */
/*   TEN_N10G_RX_OTU2XJ_10GE                       = 30,        */
/*   TEN_N10G_RX_OTU2EJ_8GFC                       = 31,        */
/*   TEN_N10G_RX_ODU2_OC192                        = 32,        */
/*   TEN_N10G_RX_OTU2EJ_OC192                      = 33,        */
/*   TEN_N10G_RX_OTU2_10GE                         = 34,        */
/*   TEN_N10G_RX_OTU2_10U_ODU2                     = 35,        */
/*   TEN_N10G_RX_OTU2_OC192_10GE                   = 36,        */
/*   TEN_N10G_RX_OC192_10GE                        = 37,        */
/*   TEN_N10G_RX_OTU2_OC192                        = 38,        */
/*   TEN_N10G_RX_BYPASS_P                          = 39,        */
/*   TEN_N10G_RX_OTU2_OC192PT                      = 40,        */
/*   TEN_N10G_RX_OXU3_ODU2_10GE                    = 41,        */
/*   TEN_N10G_RX_OXU3_192_10GE                     = 42,        */
/*   TEN_N10G_RX_OTU2_34_10GE                      = 43,        */
/*   TEN_N10G_RX_OTU2_OC192_10GE_20U               = 44,        */
/*   TEN_N10G_RX_OTU2_GENRM_ODU3                   = 45,        */
/*   TEN_N10G_RX_ODU3_GENRM_OTU2                   = 46.        */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  cs_uint16 temp_dev_id;
  cs_uint16 temp_mod_num;
  cs_status ret_val = CS_OK;
  cs_char8 *func = "ten_hl_n10g_rx_init";  


  TEN_N10G_VALIDATE(module_id, slice);

  if (mode >= TEN_N10G_RX_MAX_MODE) {
     CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, "%s() Invalid RX Mode %d!", func, mode);
     return (CS_ERROR);
  }

  if (slice < TEN_MAX_SLICES) {
    CS_PRINT("%s() %s, %s, %s \n", func, ten_module_strings[module_id&1], ten_slice_strings[slice], ten_n10g_rx_debug_str[mode]);
  }
  else if (slice == TEN_SLICE_ALL) {
    CS_PRINT("%s() %s, SLICE_ALL, %s \n", func, ten_module_strings[module_id&1], ten_n10g_rx_debug_str[mode]);
  } else {
     CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, "%s() slice %d is invalid!", func, slice);
     return (CS_ERROR);
  }

  temp_dev_id = TEN_MOD_ID_TO_DEV_ID(module_id);
  temp_mod_num = TEN_MOD_ID_TO_MOD_NUM(module_id);

  /* Assert hard reset */
  ten_mpif_global_reset_n10g(temp_dev_id, temp_mod_num, slice, CS_RX, CS_RESET_ASSERT);

  if (mode == TEN_N10G_RX_DISABLE) {
    /* Disable clock */
    ret_val |= ten_mpif_global_clock_disable_n10g(temp_dev_id, temp_mod_num, slice, CS_RX, CS_DISABLE);
  } else {
    /* Enable clock */
    ret_val |= ten_mpif_global_clock_disable_n10g(temp_dev_id, temp_mod_num, slice, CS_RX, CS_ENABLE);

    /* Remove hard reset */
    ret_val |= ten_mpif_global_reset_n10g(temp_dev_id, temp_mod_num, slice, CS_RX, CS_RESET_DEASSERT);

    /* Assert Block-level resets */
    /* Bugzilla #20965, reset TX/RX independently */
    ret_val |= ten_n10g_set_global_resets(module_id, slice, CS_RESET_ASSERT,
                               TEN_N10G_GLOBAL_RESETS_RSTRX |
                               TEN_N10G_GLOBAL_RESETS_RSTOR |
                               TEN_N10G_GLOBAL_RESETS_RSTCR |
                               TEN_N10G_GLOBAL_RESETS_RSTSYS);

    /* bugzilla #20650, use common code instead of duplicate code */
    ret_val |= ten_hl_n10g_reconfig_rx_init(module_id, slice, mode);
  }

  if (ret_val == CS_OK) {
    CS_PRINT("%s() complete.\n", func);
  } else {
    CS_PRINT("%s() had an error!\n", func);
  }
  return(ret_val);
}

/****************************************************************/
/* $rtn_hdr_start  N10G RX RECONFIG INITIALIZATION              */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : HIGH LEVEL                                      */
/* CHIP       : Tenabo                                          */
cs_status ten_hl_n10g_reconfig_rx_init(cs_uint16 module_id,
                                       cs_uint8 slice,
                                       cs_uint8 mode)
/* INPUTS     : o Module Id                                     */
/*              o Slice                                         */
/*              o Mode                                          */
/*                                                              */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* Configure N10G for traffic during dynamic reconfiguration.   */
/* This API does not hold the N10G in reset which would have    */
/* affected the datapath.                                       */
/*                                                              */
/* The [slice] parameter is specified as:                       */
/*   0x00 = TEN_SLICE0                                          */
/*   0x01 = TEN_SLICE1                                          */
/*   0x02 = TEN_SLICE2                                          */
/*   0x03 = TEN_SLICE3                                          */
/*   0xFF = TEN_SLICE_ALL                                       */
/*                                                              */
/* The [mode] parameter is specified as:                        */
/*   TEN_N10G_RX_DISABLE                           = 0,         */
/*   TEN_N10G_RX_BYPASS                            = 1,         */
/*   TEN_N10G_RX_OTU2_ODU2_FS                      = 2,         */
/*   TEN_N10G_RX_OTU2_U15_10GFC                    = 3,         */
/*   TEN_N10G_RX_OTU2_OPU2                         = 4,         */
/*   TEN_N10G_RX_ODU2J_8GFC                        = 5,         */
/*   TEN_N10G_RX_OTU2_8GFC                         = 6,         */
/*   TEN_N10G_RX_ODU2_ODU2                         = 7,         */
/*   TEN_N10G_RX_OC192_OC192                       = 8,         */
/*   TEN_N10G_RX_OXU3J_ODU2E_10GE                  = 9,         */
/*   TEN_N10G_RX_OTU2E_ODU2                        = 10,        */
/*   TEN_N10G_RX_OXU3_OC192                        = 11,        */
/*   TEN_N10G_RX_OXU3_OC192P                       = 12,        */
/*   TEN_N10G_RX_OXU3_ODU2                         = 13,        */
/*   TEN_N10G_RX_OXU3_ODU2P                        = 14,        */
/*   TEN_N10G_RX_OXU3_10GEP                        = 15,        */
/*   TEN_N10G_RX_OXU3_10GE                         = 16,        */
/*   TEN_N10G_RX_OXU3_10GFC                        = 17,        */
/*   TEN_N10G_RX_OXU3_OC192_10GE                   = 18,        */
/*   TEN_N10G_RX_OTU2E_ODU2E                       = 19,        */
/*   TEN_N10G_RX_OTU1E_ODU1E                       = 20,        */
/*   TEN_N10G_RX_OTU2_ODU2                         = 21,        */
/*   TEN_N10G_RX_OTU2E_10GE                        = 22,        */
/*   TEN_N10G_RX_OXU3_ODU2E_10GE                   = 23,        */
/*   TEN_N10G_RX_OTU2FC_10GFC                      = 24,        */
/*   TEN_N10G_RX_OXU3_ODU2FC_10GFC                 = 25,        */
/*   TEN_N10G_RX_OTU1E_10GE                        = 26,        */
/*   TEN_N10G_RX_OXU3_ODU1E_10GE                   = 27,        */
/*   TEN_N10G_RX_OTU2EJ_10GE                       = 28,        */
/*   TEN_N10G_RX_OTU2EJ_10GFC                      = 29,        */
/*   TEN_N10G_RX_OTU2XJ_10GE                       = 30,        */
/*   TEN_N10G_RX_OTU2EJ_8GFC                       = 31,        */
/*   TEN_N10G_RX_ODU2_OC192                        = 32,        */
/*   TEN_N10G_RX_OTU2EJ_OC192                      = 33,        */
/*   TEN_N10G_RX_OTU2_10GE                         = 34,        */
/*   TEN_N10G_RX_OTU2_10U_ODU2                     = 35,        */
/*   TEN_N10G_RX_OTU2_OC192_10GE                   = 36,        */
/*   TEN_N10G_RX_OC192_10GE                        = 37,        */
/*   TEN_N10G_RX_OTU2_OC192                        = 38,        */
/*   TEN_N10G_RX_BYPASS_P                          = 39,        */
/*   TEN_N10G_RX_OTU2_OC192PT                      = 40,        */
/*   TEN_N10G_RX_OXU3_ODU2_10GE                    = 41,        */
/*   TEN_N10G_RX_OXU3_192_10GE                     = 42,        */
/*   TEN_N10G_RX_OTU2_34_10GE                      = 43,        */
/*   TEN_N10G_RX_OTU2_OC192_10GE_20U               = 44,        */
/*   TEN_N10G_RX_OTU2_GENRM_ODU3                   = 45,        */
/*   TEN_N10G_RX_ODU3_GENRM_OTU2                   = 46.        */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  cs_status ret_val = CS_OK;

  CS_PRINT("ten_hl_n10g_reconfig_rx_init, slice = %d\n", slice);

  TEN_N10G_VALIDATE(module_id, slice);

  if (mode >= TEN_N10G_RX_MAX_MODE) {
     CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": Invalid RX Mode!");
     ret_val = CS_ERROR;
     goto RTN_EXIT;
  }

  CS_PRINT("mode = (Column #%d) %s\n", mode, ten_n10g_rx_debug_str[mode]);

  CS_PRINT("DPCFG_OTNOFF                   = 0x%04X\n", ten_n10g_rx_table[TEN_N10G_RX_DPCFG_OTNOFF][mode]);
  CS_PRINT("DPCFG_SDHOFF                   = 0x%04X\n", ten_n10g_rx_table[TEN_N10G_RX_DPCFG_SDHOFF][mode]);
  CS_PRINT("DPCFG_OBY                      = 0x%04X\n", ten_n10g_rx_table[TEN_N10G_RX_DPCFG_OBY][mode]);
  CS_PRINT("DPCFG_SBYFRM                   = 0x%04X\n", ten_n10g_rx_table[TEN_N10G_RX_DPCFG_SBYFRM][mode]);
  CS_PRINT("DPCFG_SBYPLD                   = 0x%04X\n", ten_n10g_rx_table[TEN_N10G_RX_DPCFG_SBYPLD][mode]);
  CS_PRINT("DPCFG_KPASEL                   = 0x%04X\n", ten_n10g_rx_table[TEN_N10G_RX_DPCFG_KPASEL][mode]);
  CS_PRINT("DPCFG_XSEL                     = 0x%04X\n", ten_n10g_rx_table[TEN_N10G_RX_DPCFG_XSEL][mode]);
  CS_PRINT("FRMLENGTH_NOFCOLS              = 0x%04X\n", ten_n10g_rx_table[TEN_N10G_RX_FRMLENGTH_NOFCOLS][mode]);
  CS_PRINT("SDFCFG_SCREN                   = 0x%04X\n", ten_n10g_rx_table[TEN_N10G_RX_SDFCFG_SCREN][mode]);
  CS_PRINT("SDFCFG_FAWWUP                  = 0x%04X\n", ten_n10g_rx_table[TEN_N10G_RX_SDFCFG_FAWWUP][mode]);
  CS_PRINT("SDFCFG_FAWWDW                  = 0x%04X\n", ten_n10g_rx_table[TEN_N10G_RX_SDFCFG_FAWWDW][mode]);
  CS_PRINT("SDFCFG_OOFHY                   = 0x%04X\n", ten_n10g_rx_table[TEN_N10G_RX_SDFCFG_OOFHY][mode]);
  CS_PRINT("SDFCFG_BFAEN                   = 0x%04X\n", ten_n10g_rx_table[TEN_N10G_RX_SDFCFG_BFAEN][mode]);
  CS_PRINT("SDFCFG1_ALTSCR                 = 0x%04X\n", ten_n10g_rx_table[TEN_N10G_RX_SDFCFG1_ALTSCR][mode]);
  CS_PRINT("OACFG0_FECEN                   = 0x%04X\n", ten_n10g_rx_table[TEN_N10G_RX_OACFG0_FECEN][mode]);
  CS_PRINT("OACFG0_PREDSCR                 = 0x%04X\n", ten_n10g_rx_table[TEN_N10G_RX_OACFG0_PREDSCR][mode]);
  CS_PRINT("OACFG0_POSTDSCR                = 0x%04X\n", ten_n10g_rx_table[TEN_N10G_RX_OACFG0_POSTDSCR][mode]);
  CS_PRINT("ODWCFG_JC_PLUS                 = 0x%04X\n", ten_n10g_rx_table[TEN_N10G_RX_ODWCFG_JC_PLUS][mode]);
  CS_PRINT("ODWCFG_FSOMD                   = 0x%04X\n", ten_n10g_rx_table[TEN_N10G_RX_ODWCFG_FSOMD][mode]);
  CS_PRINT("ODWCFG_G43MD                   = 0x%04X\n", ten_n10g_rx_table[TEN_N10G_RX_ODWCFG_G43MD][mode]);
  CS_PRINT("ODWCFG_C15RES_EN               = 0x%04X\n", ten_n10g_rx_table[TEN_N10G_RX_ODWCFG_C15RES_EN][mode]);
  CS_PRINT("ODWCFG_STM64MD                 = 0x%04X\n", ten_n10g_rx_table[TEN_N10G_RX_ODWCFG_STM64MD][mode]);
  CS_PRINT("ODWCFG_DWMOD                   = 0x%04X\n", ten_n10g_rx_table[TEN_N10G_RX_ODWCFG_DWMOD][mode]);
  CS_PRINT("OFCFG1_NPARB                   = 0x%04X\n", ten_n10g_rx_table[TEN_N10G_RX_OFCFG1_NPARB][mode]);
  CS_PRINT("OFCFG1_NPAR                    = 0x%04X\n", ten_n10g_rx_table[TEN_N10G_RX_OFCFG1_NPAR][mode]);
  CS_PRINT("OFCFG0_NCOLS                   = 0x%04X\n", ten_n10g_rx_table[TEN_N10G_RX_OFCFG0_NCOLS][mode]);
  CS_PRINT("ODWFS_FS                       = 0x%04X\n", ten_n10g_rx_table[TEN_N10G_RX_ODWFS_FS][mode]);
  CS_PRINT("S1CFG_B1TRANS                  = 0x%04X\n", ten_n10g_rx_table[TEN_N10G_RX_S1CFG_B1TRANS][mode]);
  CS_PRINT("S1CFG_B2TRANS                  = 0x%04X\n", ten_n10g_rx_table[TEN_N10G_RX_S1CFG_B2TRANS][mode]);
  CS_PRINT("NOFCOLS_NOFCOLS                = 0x%04X\n", ten_n10g_rx_table[TEN_N10G_RX_NOFCOLS_NOFCOLS][mode]);
  CS_PRINT("K12CFG_KAFLEN                  = 0x%04X\n", ten_n10g_rx_table[TEN_N10G_RX_K12CFG_KAFLEN][mode]);

  CS_PRINT("Provision High-Level N10G RX...\n");

  ret_val |= ten_n10g_set_gblr_dpcfg(module_id, slice,
                          ten_n10g_rx_table[TEN_N10G_RX_DPCFG_XSEL][mode],
                          ten_n10g_rx_table[TEN_N10G_RX_DPCFG_KPASEL][mode],
                          ten_n10g_rx_table[TEN_N10G_RX_DPCFG_SBYPLD][mode],
                          ten_n10g_rx_table[TEN_N10G_RX_DPCFG_SBYFRM][mode],
                          ten_n10g_rx_table[TEN_N10G_RX_DPCFG_OBY][mode],
                          ten_n10g_rx_table[TEN_N10G_RX_DPCFG_SDHOFF][mode],
                          ten_n10g_rx_table[TEN_N10G_RX_DPCFG_OTNOFF][mode]);


  ret_val |= ten_n10g_sdfr_set_sdfcfg(module_id, slice,
                           ten_n10g_rx_table[TEN_N10G_RX_SDFCFG_SCREN][mode],
                           ten_n10g_rx_table[TEN_N10G_RX_SDFCFG_OOFHY][mode],
                           ten_n10g_rx_table[TEN_N10G_RX_SDFCFG_FAWWUP][mode],
                           ten_n10g_rx_table[TEN_N10G_RX_SDFCFG_FAWWDW][mode]);


  ret_val |= ten_n10g_sdfr_set_sdfcfg1(module_id, slice,
                            ten_n10g_rx_table[TEN_N10G_RX_SDFCFG1_ALTSCR][mode]);

  ret_val |= ten_n10g_otnr_descrambling(module_id, slice,
                           ten_n10g_rx_table[TEN_N10G_RX_OACFG0_POSTDSCR][mode],
                           ten_n10g_rx_table[TEN_N10G_RX_OACFG0_PREDSCR][mode]);

  ret_val |= ten_n10g_otnr_set_jc_plus(module_id, slice,
                            ten_n10g_rx_table[TEN_N10G_RX_ODWCFG_JC_PLUS][mode]);

  ret_val |= ten_n10g_otnr_set_linkalm_jcnom(module_id, slice,
                              ten_n10g_rx_table[TEN_N10G_RX_ODWCFG_JC_PLUS][mode]);
  if (ten_n10g_rx_table[TEN_N10G_RX_ODWCFG_JC_PLUS][mode]) {
    ret_val |= ten_n10g_oohr_gendwnlfsf(module_id, slice, 1, 0, 0, 0, 1, 0, 0);
                        /* SQGCC, SF_XLOS, SF_LOS, SF_OTUAIS, SF_LOF,SF_FECEED, SF_LOM */
  }

  ret_val |= ten_n10g_otnr_set_fsomd(module_id, slice,
                          ten_n10g_rx_table[TEN_N10G_RX_ODWCFG_FSOMD][mode]);

  ret_val |= ten_n10g_otnr_set_g43md(module_id, slice,
                          ten_n10g_rx_table[TEN_N10G_RX_ODWCFG_G43MD][mode]);

  ret_val |= ten_n10g_otnr_set_c15res_en(module_id, slice,
                              ten_n10g_rx_table[TEN_N10G_RX_ODWCFG_C15RES_EN][mode]);

  ret_val |= ten_n10g_otnr_set_stm64md(module_id, slice,
                            ten_n10g_rx_table[TEN_N10G_RX_ODWCFG_STM64MD][mode]);

  ret_val |= ten_n10g_otnr_set_dwmod(module_id, slice,
                          ten_n10g_rx_table[TEN_N10G_RX_ODWCFG_DWMOD][mode]);

  ret_val |= ten_n10g_otnr_set_frame_format(module_id, slice,
                                 ten_n10g_rx_table[TEN_N10G_RX_OFCFG0_NCOLS][mode],
                                 3, /* NROWS */
                                 ten_n10g_rx_table[TEN_N10G_RX_OFCFG1_NPARB][mode],
                                 ten_n10g_rx_table[TEN_N10G_RX_OFCFG1_NPAR][mode]);

  ret_val |= ten_n10g_set_otnr_odwfs(module_id, slice,
                          ten_n10g_rx_table[TEN_N10G_RX_ODWFS_FS][mode]);

  ret_val |= ten_n10g_sohr_set_byte_err_trans_mode(module_id, slice,
                                        ten_n10g_rx_table[TEN_N10G_RX_S1CFG_B1TRANS][mode],
                                        ten_n10g_rx_table[TEN_N10G_RX_S1CFG_B2TRANS][mode]);
  ret_val |= ten_n10g_sohr_set_kaflen(module_id, slice,
                           ten_n10g_rx_table[TEN_N10G_RX_K12CFG_KAFLEN][mode]);

  if (mode == TEN_N10G_RX_OXU3_192_10GE) {
    ret_val |= ten_n10g_otnr_set_stm64md(module_id, slice, 1);
  }

  ret_val |= ten_hl_n10g_otn_aligner_settings(module_id, slice);

  /* For a standard rate OTU2, a 3ms time corresponds to TDELON/TDELOFF=492 */
  ret_val |= ten_n10g_otnr_lofcfg_tdelon_tdeloff(module_id, slice, 492, 492);

  CS_PRINT("High Level N10G RX Provisioning Complete.\n");

RTN_EXIT:
  return(ret_val);
}

/****************************************************************/
/* $rtn_hdr_start  N10G TX INITIALIZATION                       */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : HIGH LEVEL                                      */
/* CHIP       : Tenabo                                          */
cs_status ten_hl_n10g_tx_init(cs_uint16 module_id,
                              cs_uint8 slice,
                              cs_uint8 mode)
/* INPUTS     : o Module Id                                     */
/*              o Slice                                         */
/*              o Mode                                          */
/*                                                              */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* Configure N10G for traffic.                                  */
/*                                                              */
/* The [slice] parameter is specified as:                       */
/*   0x00 = TEN_SLICE0                                          */
/*   0x01 = TEN_SLICE1                                          */
/*   0x02 = TEN_SLICE2                                          */
/*   0x03 = TEN_SLICE3                                          */
/*   0xFF = TEN_SLICE_ALL                                       */
/*                                                              */
/* The [mode] parameter is specified as:                        */
/*   TEN_N10G_TX_DISABLE                           = 0,         */
/*   TEN_N10G_TX_BYPASS                            = 1,         */
/*   TEN_N10G_TX_10GFC_OTU2_U15                    = 2,         */
/*   TEN_N10G_TX_OPU2_OTU2                         = 3,         */
/*   TEN_N10G_TX_ODU2_ODU2                         = 4,         */
/*   TEN_N10G_TX_8GFC_OTU2                         = 5,         */
/*   TEN_N10G_TX_8GFC_ODU2J                        = 6,         */
/*   TEN_N10G_TX_10GE_ODU2E_OXU3J                  = 7,         */
/*   TEN_N10G_TX_10GE_OTU2E                        = 8,         */
/*   TEN_N10G_TX_10GE_ODU2E_OXU3                   = 9,         */
/*   TEN_N10G_TX_10GE_OTU1E                        = 10,        */
/*   TEN_N10G_TX_10GE_ODU1E_OXU3                   = 11,        */
/*   TEN_N10G_TX_10GFC_OTU2FC                      = 12,        */
/*   TEN_N10G_TX_10GFC_ODU2FC_OXU3                 = 13,        */
/*   TEN_N10G_TX_OC192_OXU3                        = 14,        */
/*   TEN_N10G_TX_OC192_OXU3P                       = 15,        */
/*   TEN_N10G_TX_ODU2_OXU3                         = 16,        */
/*   TEN_N10G_TX_10GFC_OXU3                        = 17,        */
/*   TEN_N10G_TX_10GE_OXU3P                        = 18,        */
/*   TEN_N10G_TX_10GE_OXU3                         = 19,        */
/*   TEN_N10G_TX_ODU2_OXU3P                        = 20,        */
/*   TEN_N10G_TX_OC192_ODU2                        = 21,        */
/*   TEN_N10G_TX_OC192_OTU2EJ                      = 22,        */
/*   TEN_N10G_TX_10GE_OTU2                         = 23,        */
/*   TEN_N10G_TX_10GE_OTU2XJ                       = 24,        */
/*   TEN_N10G_TX_10GE_OTU2EJ                       = 25,        */
/*   TEN_N10G_TX_10GFC_OTU2EJ                      = 26,        */
/*   TEN_N10G_TX_8GFC_OTU2EJ                       = 27,        */
/*   TEN_N10G_TX_ODU1E_OTU1E                       = 28,        */
/*   TEN_N10G_TX_ODU2_OTU2                         = 29,        */
/*   TEN_N10G_TX_ODU2E_OTU2E                       = 30,        */
/*   TEN_N10G_TX_ODU2_OTU2_10U                     = 31,        */
/*   TEN_N10G_TX_10GE_OC192_OTU2                   = 32,        */
/*   TEN_N10G_TX_10GE_OC192                        = 33,        */
/*   TEN_N10G_TX_OC192_OTU2                        = 34,        */
/*   TEN_N10G_TX_OC192_OC192PT                     = 35,        */
/*   TEN_N10G_TX_10GE_192_OXU3                     = 36,        */
/*   TEN_N10G_TX_10GE_ODU2_OXU3                    = 37,        */
/*   TEN_N10G_TX_10GE_ODU2E_OXU3_DT                = 38,        */
/*   TEN_N10G_TX_10GE_OTU2_34                      = 39,        */
/*   TEN_N10G_TX_OTU2_OXU3_NT                      = 40,        */
/*   TEN_N10G_TX_FC_TRANS_OXU3_NT                  = 41,        */
/*   TEN_N10G_TX_OTU2E_OXU3_NT                     = 42,        */
/*   TEN_N10G_TX_OC192_OTU2_10U                    = 43,        */
/*   TEN_N10G_TX_10GE_OC192_OTU2_20U               = 44,        */
/*   TEN_N10G_TX_OTU2_GENRM_ODU3                   = 45,        */
/*   TEN_N10G_TX_ODU3_GENRM_OTU2                   = 46.        */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  cs_uint16 temp_dev_id;
  cs_uint16 temp_mod_num;
  cs_status ret_val = CS_OK;
  cs_char8 *func = "ten_hl_n10g_tx_init";  

  TEN_N10G_VALIDATE(module_id, slice);

   if (mode >= TEN_N10G_TX_MAX_MODE) {
     CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, "%s %d is an Invalid TX Mode!", func, mode);
     ret_val = CS_ERROR;
     goto RTN_EXIT;
  }

  if (slice < TEN_MAX_SLICES) {
    CS_PRINT("%s() %s, %s, %s, mode = (Column #%d)\n", func, ten_module_strings[module_id&1], ten_slice_strings[slice], ten_n10g_tx_debug_str[mode], mode);
  }
  else if (slice == TEN_SLICE_ALL) {
    CS_PRINT("%s() %s, TEN_SLICE_ALL, %s, mode = (Column #%d)\n", func, ten_module_strings[module_id&1], ten_n10g_tx_debug_str[mode], mode);
  } else {
     CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, "%s %d is an Invalid slice!", func, slice);
     ret_val = CS_ERROR;
     goto RTN_EXIT;
  }

  /* Assert hard reset */
  temp_dev_id = TEN_MOD_ID_TO_DEV_ID(module_id);
  temp_mod_num = TEN_MOD_ID_TO_MOD_NUM(module_id);
  ten_mpif_global_reset_n10g(temp_dev_id, temp_mod_num, slice, CS_TX, CS_RESET_ASSERT);

  if (mode == TEN_N10G_TX_DISABLE) {
    /* Disable clock */
    ret_val |= ten_mpif_global_clock_disable_n10g(temp_dev_id, temp_mod_num, slice, CS_TX, CS_DISABLE);
    goto RTN_EXIT;
  }

  /* Enable clock */
  ret_val |= ten_mpif_global_clock_disable_n10g(temp_dev_id, temp_mod_num, slice, CS_TX, CS_ENABLE);

  /* Remove hard reset */
  ret_val |= ten_mpif_global_reset_n10g(temp_dev_id, temp_mod_num, slice, CS_TX, CS_RESET_DEASSERT);

  /* Assert Block-level resets */
  /* Bugzilla #20965, reset TX/RX independently */
  ret_val |= ten_n10g_set_global_resets(module_id, slice, CS_RESET_ASSERT,
                             TEN_N10G_GLOBAL_RESETS_RSTSYS  |
                             TEN_N10G_GLOBAL_RESETS_RSTTX   |
                             TEN_N10G_GLOBAL_RESETS_RSTTXNG |
                             TEN_N10G_GLOBAL_RESETS_RSTOT   |
                             TEN_N10G_GLOBAL_RESETS_RSTCT);

  /* bugzilla #20650, use common code instead of duplicate code */
  ret_val |= ten_hl_n10g_reconfig_tx_init(module_id, slice, mode);

  CS_PRINT("%s() is complete.\n", func);

RTN_EXIT:
  return(ret_val);
}

/****************************************************************/
/* $rtn_hdr_start  N10G TX RECONFIG INITIALIZATION              */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : HIGH LEVEL                                      */
/* CHIP       : Tenabo                                          */
cs_status ten_hl_n10g_reconfig_tx_init(cs_uint16 module_id,
                                       cs_uint8 slice,
                                       cs_uint8 mode)
/* INPUTS     : o Module Id                                     */
/*              o Slice                                         */
/*              o Mode                                          */
/*                                                              */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* Configure N10G for traffic during dynamic reconfiguration    */
/* Does not hold the N10G in reset which would have affected    */
/* the datapath                                                 */
/*                                                              */
/* The [slice] parameter is specified as:                       */
/*   0x00 = TEN_SLICE0                                          */
/*   0x01 = TEN_SLICE1                                          */
/*   0x02 = TEN_SLICE2                                          */
/*   0x03 = TEN_SLICE3                                          */
/*   0xFF = TEN_SLICE_ALL                                       */
/*                                                              */
/* The [mode] parameter is specified as:                        */
/*   TEN_N10G_TX_DISABLE                           = 0,         */
/*   TEN_N10G_TX_BYPASS                            = 1,         */
/*   TEN_N10G_TX_10GFC_OTU2_U15                    = 2,         */
/*   TEN_N10G_TX_OPU2_OTU2                         = 3,         */
/*   TEN_N10G_TX_ODU2_ODU2                         = 4,         */
/*   TEN_N10G_TX_8GFC_OTU2                         = 5,         */
/*   TEN_N10G_TX_8GFC_ODU2J                        = 6,         */
/*   TEN_N10G_TX_10GE_ODU2E_OXU3J                  = 7,         */
/*   TEN_N10G_TX_10GE_OTU2E                        = 8,         */
/*   TEN_N10G_TX_10GE_ODU2E_OXU3                   = 9,         */
/*   TEN_N10G_TX_10GE_OTU1E                        = 10,        */
/*   TEN_N10G_TX_10GE_ODU1E_OXU3                   = 11,        */
/*   TEN_N10G_TX_10GFC_OTU2FC                      = 12,        */
/*   TEN_N10G_TX_10GFC_ODU2FC_OXU3                 = 13,        */
/*   TEN_N10G_TX_OC192_OXU3                        = 14,        */
/*   TEN_N10G_TX_OC192_OXU3P                       = 15,        */
/*   TEN_N10G_TX_ODU2_OXU3                         = 16,        */
/*   TEN_N10G_TX_10GFC_OXU3                        = 17,        */
/*   TEN_N10G_TX_10GE_OXU3P                        = 18,        */
/*   TEN_N10G_TX_10GE_OXU3                         = 19,        */
/*   TEN_N10G_TX_ODU2_OXU3P                        = 20,        */
/*   TEN_N10G_TX_OC192_ODU2                        = 21,        */
/*   TEN_N10G_TX_OC192_OTU2EJ                      = 22,        */
/*   TEN_N10G_TX_10GE_OTU2                         = 23,        */
/*   TEN_N10G_TX_10GE_OTU2XJ                       = 24,        */
/*   TEN_N10G_TX_10GE_OTU2EJ                       = 25,        */
/*   TEN_N10G_TX_10GFC_OTU2EJ                      = 26,        */
/*   TEN_N10G_TX_8GFC_OTU2EJ                       = 27,        */
/*   TEN_N10G_TX_ODU1E_OTU1E                       = 28,        */
/*   TEN_N10G_TX_ODU2_OTU2                         = 29,        */
/*   TEN_N10G_TX_ODU2E_OTU2E                       = 30,        */
/*   TEN_N10G_TX_ODU2_OTU2_10U                     = 31,        */
/*   TEN_N10G_TX_10GE_OC192_OTU2                   = 32,        */
/*   TEN_N10G_TX_10GE_OC192                        = 33,        */
/*   TEN_N10G_TX_OC192_OTU2                        = 34,        */
/*   TEN_N10G_TX_OC192_OC192PT                     = 35,        */
/*   TEN_N10G_TX_10GE_192_OXU3                     = 36,        */
/*   TEN_N10G_TX_10GE_ODU2_OXU3                    = 37,        */
/*   TEN_N10G_TX_10GE_ODU2E_OXU3_DT                = 38,        */
/*   TEN_N10G_TX_10GE_OTU2_34                      = 39,        */
/*   TEN_N10G_TX_OTU2_OXU3_NT                      = 40,        */
/*   TEN_N10G_TX_FC_TRANS_OXU3_NT                  = 41,        */
/*   TEN_N10G_TX_OTU2E_OXU3_NT                     = 42,        */
/*   TEN_N10G_TX_OC192_OTU2_10U                    = 43,        */
/*   TEN_N10G_TX_10GE_OC192_OTU2_20U               = 44,        */
/*   TEN_N10G_TX_OTU2_GENRM_ODU3                   = 45,        */
/*   TEN_N10G_TX_ODU3_GENRM_OTU2                   = 46.        */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  cs_uint16 dev_id;  /* Bugzilla 29758 */
  cs_status ret_val = CS_OK;
  cs_char8 *func = "ten_hl_n10g_reconfig_tx_init";  


  dev_id = TEN_MOD_ID_TO_DEV_ID(module_id); /* Bugzilla 29758 */

  TEN_N10G_VALIDATE(module_id, slice);


   if (mode >= TEN_N10G_TX_MAX_MODE) {
     CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, "%s() Invalid TX Mode %d!", func, mode);
     ret_val = CS_ERROR;
     goto RTN_EXIT;
  }

  CS_PRINT("%s() %s slice = %d, mode = (Column #%d) %s\n", func, ten_module_strings[module_id&1],  slice, mode, ten_n10g_tx_debug_str[mode]);

  CS_PRINT("    CFGTX0_SBY                     = 0x%04X\n", ten_n10g_tx_table[TEN_N10G_TX_CFGTX0_SBY][mode]);
  CS_PRINT("    CFGTX0_OBY                     = 0x%04X\n", ten_n10g_tx_table[TEN_N10G_TX_CFGTX0_OBY][mode]);
  CS_PRINT("    CFGTX0_KPGBY                   = 0x%04X\n", ten_n10g_tx_table[TEN_N10G_TX_CFGTX0_KPGBY][mode]);
  /* Bugzilla 29758 Start */
  if (ten_dev_is_t41(dev_id)) {
    CS_PRINT("    CFGTX0_OTNOFF                  = 0x%04X\n", ten_n10g_tx_table[TEN_N10G_TX_CFGTX0_OTNOFF][mode]);
  } else {
    /* T40 had a problem with inserting STM-AIS when the OTN block was not clocked */
    CS_PRINT("    CFGTX0_OTNOFF                  = 0x%04X\n", 0 /*ten_n10g_tx_table[TEN_N10G_TX_CFGTX0_OTNOFF][mode] */);
  }
  /* Bugzilla 29758 End */
  CS_PRINT("    FRMLEN_FRMLEN                  = 0x%04X\n", ten_n10g_tx_table[TEN_N10G_TX_FRMLEN_FRMLEN][mode]);
  CS_PRINT("    OHBEN0_SCREN                   = 0x%04X\n", ten_n10g_tx_table[TEN_N10G_TX_OHBEN0_SCREN][mode]);
  CS_PRINT("    OHBEN0_A1A2RSH                 = 0x%04X\n", ten_n10g_tx_table[TEN_N10G_TX_OHBEN0_A1A2RSH][mode]);
  CS_PRINT("    OHBEN0_B1IE                    = 0x%04X\n", ten_n10g_tx_table[TEN_N10G_TX_OHBEN0_B1IE][mode]);
  CS_PRINT("    OHBEN0_A1A2IE                  = 0x%04X\n", ten_n10g_tx_table[TEN_N10G_TX_OHBEN0_A1A2IE][mode]);
  CS_PRINT("    OHBEN0_J0IE                    = 0x%04X\n", ten_n10g_tx_table[TEN_N10G_TX_OHBEN0_J0IE][mode]);
  CS_PRINT("    OHBEN0_DEFIE                   = 0x%04X\n", ten_n10g_tx_table[TEN_N10G_TX_OHBEN0_DEFIE][mode]);
  CS_PRINT("    OHBEN0_NU1IE                   = 0x%04X\n", ten_n10g_tx_table[TEN_N10G_TX_OHBEN0_NU1IE][mode]);
  CS_PRINT("    OHBEN1_B2INV                   = 0x%04X\n", ten_n10g_tx_table[TEN_N10G_TX_OHBEN1_B2INV][mode]);
  CS_PRINT("    OHBEN1_B1INV                   = 0x%04X\n", ten_n10g_tx_table[TEN_N10G_TX_OHBEN1_B1INV][mode]);
  CS_PRINT("    OHBEN1_B1TRANS                 = 0x%04X\n", ten_n10g_tx_table[TEN_N10G_TX_OHBEN1_B1TRANS][mode]);
  CS_PRINT("    OHBEN1_B2TRANS                 = 0x%04X\n", ten_n10g_tx_table[TEN_N10G_TX_OHBEN1_B2TRANS][mode]);
  CS_PRINT("    OHBEN1_K1IE                    = 0x%04X\n", ten_n10g_tx_table[TEN_N10G_TX_OHBEN1_K1IE][mode]);
  CS_PRINT("    OHBEN1_K2IE                    = 0x%04X\n", ten_n10g_tx_table[TEN_N10G_TX_OHBEN1_K2IE][mode]);
  CS_PRINT("    OHBEN2_M0IE                    = 0x%04X\n", ten_n10g_tx_table[TEN_N10G_TX_OHBEN2_M0IE][mode]);
  CS_PRINT("    OHBEN2_M1IE                    = 0x%04X\n", ten_n10g_tx_table[TEN_N10G_TX_OHBEN2_M1IE][mode]);
  CS_PRINT("    SOHBYTES5_NU1                  = 0x%04X\n", ten_n10g_tx_table[TEN_N10G_TX_SOHBYTES5_NU1][mode]);
  CS_PRINT("    OHBEN3_ALT_SCREN               = 0x%04X\n", ten_n10g_tx_table[TEN_N10G_TX_OHBEN3_ALT_SCREN][mode]);
  CS_PRINT("    B1ERRINS_B1ERRMSK              = 0x%04X\n", ten_n10g_tx_table[TEN_N10G_TX_B1ERRINS_B1ERRMSK][mode]);
  CS_PRINT("    B2ERRINS_B2ERRMSK              = 0x%04X\n", ten_n10g_tx_table[TEN_N10G_TX_B2ERRINS_B2ERRMSK][mode]);
  CS_PRINT("    SOHBYTES2_K2BYTE               = 0x%04X\n", ten_n10g_tx_table[TEN_N10G_TX_SOHBYTES2_K2BYTE][mode]);
  CS_PRINT("    SOHBYTES2_K1BYTE               = 0x%04X\n", ten_n10g_tx_table[TEN_N10G_TX_SOHBYTES2_K1BYTE][mode]);
  CS_PRINT("    SOHBYTES3_OHDEF                = 0x%04X\n", ten_n10g_tx_table[TEN_N10G_TX_SOHBYTES3_OHDEF][mode]);
  CS_PRINT("    POHBEN0_PRBSIE                 = 0x%04X\n", ten_n10g_tx_table[TEN_N10G_TX_POHBEN0_PRBSIE][mode]);
  CS_PRINT("    POHBEN0_POHIE                  = 0x%04X\n", ten_n10g_tx_table[TEN_N10G_TX_POHBEN0_POHIE][mode]);
  CS_PRINT("    POHBEN0_B3IE                   = 0x%04X\n", ten_n10g_tx_table[TEN_N10G_TX_POHBEN0_B3IE][mode]);
  CS_PRINT("    POHBEN0_C2IE                   = 0x%04X\n", ten_n10g_tx_table[TEN_N10G_TX_POHBEN0_C2IE][mode]);
  CS_PRINT("    POHBEN0_J1IE                   = 0x%04X\n", ten_n10g_tx_table[TEN_N10G_TX_POHBEN0_J1IE][mode]);
  CS_PRINT("    POHBYTES0_C2BYTE               = 0x%04X\n", ten_n10g_tx_table[TEN_N10G_TX_POHBYTES0_C2BYTE][mode]);
  CS_PRINT("    J0STRG0_J0STRG0                = 0x%04X\n", ten_n10g_tx_table[TEN_N10G_TX_J0STRG0_J0STRG0][mode]);
  CS_PRINT("    B2IE0_B2IE0                    = 0x%04X\n", ten_n10g_tx_table[TEN_N10G_TX_B2IE0_B2IE0][mode]);
  CS_PRINT("    B2IE1_B2IE1                    = 0x%04X\n", ten_n10g_tx_table[TEN_N10G_TX_B2IE1_B2IE1][mode]);
  CS_PRINT("    B2IE2_B2IE2                    = 0x%04X\n", ten_n10g_tx_table[TEN_N10G_TX_B2IE2_B2IE2][mode]);
  CS_PRINT("    B2IE3_B2IE3                    = 0x%04X\n", ten_n10g_tx_table[TEN_N10G_TX_B2IE3_B2IE3][mode]);
  CS_PRINT("    B2IE4_B2IE4                    = 0x%04X\n", ten_n10g_tx_table[TEN_N10G_TX_B2IE4_B2IE4][mode]);
  CS_PRINT("    B2IE5_B2IE5                    = 0x%04X\n", ten_n10g_tx_table[TEN_N10G_TX_B2IE5_B2IE5][mode]);
  CS_PRINT("    B2IE6_B2IE6                    = 0x%04X\n", ten_n10g_tx_table[TEN_N10G_TX_B2IE6_B2IE6][mode]);
  CS_PRINT("    B2IE7_B2IE7                    = 0x%04X\n", ten_n10g_tx_table[TEN_N10G_TX_B2IE7_B2IE7][mode]);
  CS_PRINT("    B2IE8_B2IE8                    = 0x%04X\n", ten_n10g_tx_table[TEN_N10G_TX_B2IE8_B2IE8][mode]);
  CS_PRINT("    B2IE9_B2IE9                    = 0x%04X\n", ten_n10g_tx_table[TEN_N10G_TX_B2IE9_B2IE9][mode]);
  CS_PRINT("    B2IE10_B2IE10                  = 0x%04X\n", ten_n10g_tx_table[TEN_N10G_TX_B2IE10_B2IE10][mode]);
  CS_PRINT("    B2IE11_B2IE11                  = 0x%04X\n", ten_n10g_tx_table[TEN_N10G_TX_B2IE11_B2IE11][mode]);
  CS_PRINT("    B2IE12_B2IE12                  = 0x%04X\n", ten_n10g_tx_table[TEN_N10G_TX_B2IE12_B2IE12][mode]);
  CS_PRINT("    OCFG_PRESCR                    = 0x%04X\n", ten_n10g_tx_table[TEN_N10G_TX_OCFG_PRESCR][mode]);
  CS_PRINT("    OCFG_POSTSCR                   = 0x%04X\n", ten_n10g_tx_table[TEN_N10G_TX_OCFG_POSTSCR][mode]);
  CS_PRINT("    WRPCFG3_WRMD                   = 0x%04X\n", ten_n10g_tx_table[TEN_N10G_TX_WRPCFG3_WRMD][mode]);
  CS_PRINT("    WRPCFG3_C15RES_EN              = 0x%04X\n", ten_n10g_tx_table[TEN_N10G_TX_WRPCFG3_C15RES_EN][mode]);
  CS_PRINT("    WRPCFG3_STM64MD                = 0x%04X\n", ten_n10g_tx_table[TEN_N10G_TX_WRPCFG3_STM64MD][mode]);
  CS_PRINT("    WRPCFG3_G43MD                  = 0x%04X\n", ten_n10g_tx_table[TEN_N10G_TX_WRPCFG3_G43MD][mode]);
  CS_PRINT("    WRPCFG0_NCOLS                  = 0x%04X\n", ten_n10g_tx_table[TEN_N10G_TX_WRPCFG0_NCOLS][mode]);
  CS_PRINT("    WRPCFG2_NPAR                   = 0x%04X\n", ten_n10g_tx_table[TEN_N10G_TX_WRPCFG2_NPAR][mode]);
  CS_PRINT("    WRPCFG2_NPARB                  = 0x%04X\n", ten_n10g_tx_table[TEN_N10G_TX_WRPCFG2_NPARB][mode]);
  CS_PRINT("    WRPCFG4_JCEN_OTU2              = 0x%04X\n", ten_n10g_tx_table[TEN_N10G_TX_WRPCFG4_JCEN_OTU2][mode]);
  CS_PRINT("    WRPCFG4_JCEN_ODTU23            = 0x%04X\n", ten_n10g_tx_table[TEN_N10G_TX_WRPCFG4_JCEN_ODTU23][mode]);
  CS_PRINT("    WRPCFG4_JCEN_DT                = 0x%04X\n", ten_n10g_tx_table[TEN_N10G_TX_WRPCFG4_JCEN_DT][mode]);
  CS_PRINT("    WRPCFG4_JC_PLUS_OTU2           = 0x%04X\n", ten_n10g_tx_table[TEN_N10G_TX_WRPCFG4_JC_PLUS_OTU2][mode]);
  CS_PRINT("    WRPCFG4_JC_PLUS_ODTU23         = 0x%04X\n", ten_n10g_tx_table[TEN_N10G_TX_WRPCFG4_JC_PLUS_ODTU23][mode]);
  CS_PRINT("    WRPFS_FS                       = 0x%04X\n", ten_n10g_tx_table[TEN_N10G_TX_WRPFS_FS][mode]);
  CS_PRINT("    CFG4_BIPMSK                    = 0x%04X\n", ten_n10g_tx_table[TEN_N10G_TX_CFG4_BIPMSK][mode]);
  CS_PRINT("    CFG0_PTIE                      = 0x%04X\n", ten_n10g_tx_table[TEN_N10G_TX_CFG0_PTIE][mode]);
  CS_PRINT("    CFG2_PT                        = 0x%04X\n", ten_n10g_tx_table[TEN_N10G_TX_CFG2_PT][mode]);
  CS_PRINT("    EXPTI_EXPTI                    = 0x%04X\n", ten_n10g_tx_table[TEN_N10G_TX_EXPTI_EXPTI][mode]);

  CS_PRINT("    Provision High-Level N10G TX...\n");

 #if 1
  /* Bugzilla 29609 Start */
  if (ten_dev_is_t41_ptr(TEN_MOD_ID_TO_DEVCB_PTR(module_id))) {
    /* Enable internal TX clock */
    ten_n10g_tx_bypass_t41 (module_id, slice, CS_RESET_DEASSERT);  /* gbl_bypcfg.TX_BYPASS=0, CLKTX_DIS=0 */
  }
  /* Bugzilla 29609 End */
 #endif
 
  /* Bugzilla 29758 Start */
  if (ten_dev_is_t41(dev_id)) {
    ret_val |= ten_n10g_set_gblt_bypasses(module_id, slice,
                               ten_n10g_tx_table[TEN_N10G_TX_CFGTX0_OTNOFF][mode],
                               ten_n10g_tx_table[TEN_N10G_TX_CFGTX0_OBY][mode],
                               ten_n10g_tx_table[TEN_N10G_TX_CFGTX0_SBY][mode],
                               ten_n10g_tx_table[TEN_N10G_TX_CFGTX0_KPGBY][mode]);
  } else {
    /* T40 had a problem with inserting STM-AIS when the OTN block was not clocked */
    ret_val |= ten_n10g_set_gblt_bypasses(module_id, slice,
                               0, /*ten_n10g_tx_table[TEN_N10G_TX_CFGTX0_OTNOFF][mode],  */  /* Bugzilla 17309 */
                               ten_n10g_tx_table[TEN_N10G_TX_CFGTX0_OBY][mode],
                               ten_n10g_tx_table[TEN_N10G_TX_CFGTX0_SBY][mode],
                               ten_n10g_tx_table[TEN_N10G_TX_CFGTX0_KPGBY][mode]);
  }
  /* Bugzilla 29758 End */

  ret_val |= ten_n10g_soht_set_ohben0(module_id, slice,
                           ten_n10g_tx_table[TEN_N10G_TX_OHBEN0_B1IE][mode],
                           ten_n10g_tx_table[TEN_N10G_TX_OHBEN0_SCREN][mode],
                           ten_n10g_tx_table[TEN_N10G_TX_OHBEN0_A1A2RSH][mode],
                           ten_n10g_tx_table[TEN_N10G_TX_OHBEN0_A1A2IE][mode]);

  ret_val |= ten_n10g_soht_set_ohben0_j0ie(module_id, slice,
                           ten_n10g_tx_table[TEN_N10G_TX_OHBEN0_J0IE][mode]);

  ret_val |= ten_n10g_soht_set_ohben0_defie(module_id, slice,
                           ten_n10g_tx_table[TEN_N10G_TX_OHBEN0_DEFIE][mode]);

  ret_val |= ten_n10g_soht_set_ohben0_nu1ie(module_id, slice,
                           ten_n10g_tx_table[TEN_N10G_TX_OHBEN0_NU1IE][mode]);

  ret_val |= ten_n10g_soht_set_ohben1(module_id, slice,
                           ten_n10g_tx_table[TEN_N10G_TX_OHBEN1_B2INV][mode],
                           ten_n10g_tx_table[TEN_N10G_TX_OHBEN1_B1INV][mode],
                           ten_n10g_tx_table[TEN_N10G_TX_OHBEN1_B2TRANS][mode],
                           ten_n10g_tx_table[TEN_N10G_TX_OHBEN1_B1TRANS][mode]);

  ret_val |= ten_n10g_soht_set_ohben1_k1ie(module_id, slice,
                           ten_n10g_tx_table[TEN_N10G_TX_OHBEN1_K1IE][mode]);

  ret_val |= ten_n10g_soht_set_ohben1_k2ie(module_id, slice,
                           ten_n10g_tx_table[TEN_N10G_TX_OHBEN1_K2IE][mode]);

  ret_val |= ten_n10g_soht_set_ohben2(module_id, slice,
                           ten_n10g_tx_table[TEN_N10G_TX_OHBEN2_M0IE][mode],
                           ten_n10g_tx_table[TEN_N10G_TX_OHBEN2_M1IE][mode]);

  ret_val |= ten_n10g_set_soh_byte(module_id, slice,
                                TEN_SOH_NU1,
                                ten_n10g_tx_table[TEN_N10G_TX_SOHBYTES5_NU1][mode]);

  ret_val |= ten_n10g_soht_set_ohben3(module_id, slice,
                           ten_n10g_tx_table[TEN_N10G_TX_OHBEN3_ALT_SCREN][mode]);

  ret_val |= ten_n10g_soht_set_b1errmsk(module_id, slice,
                             ten_n10g_tx_table[TEN_N10G_TX_B1ERRINS_B1ERRMSK][mode]);

  ret_val |= ten_n10g_soht_set_b2errmsk(module_id, slice,
                             ten_n10g_tx_table[TEN_N10G_TX_B2ERRINS_B2ERRMSK][mode]);

  ret_val |= ten_n10g_set_soh_byte(module_id, slice,
                        TEN_SOH_K2,
                        (cs_uint8)(ten_n10g_tx_table[TEN_N10G_TX_SOHBYTES2_K2BYTE][mode] & 0xFF));

  ret_val |= ten_n10g_set_soh_byte(module_id, slice,
                        TEN_SOH_K1,
                        (cs_uint8)(ten_n10g_tx_table[TEN_N10G_TX_SOHBYTES2_K1BYTE][mode] & 0xFF));

  ret_val |= ten_n10g_set_soh_byte(module_id, slice,
                        TEN_SOH_OHDEF,
                        (cs_uint8)(ten_n10g_tx_table[TEN_N10G_TX_SOHBYTES3_OHDEF][mode] & 0xFF));

  ret_val |= ten_n10g_soht_pohben0(module_id, slice,
                        ten_n10g_tx_table[TEN_N10G_TX_POHBEN0_PRBSIE][mode],
                        ten_n10g_tx_table[TEN_N10G_TX_POHBEN0_POHIE][mode]);

  ret_val |= ten_n10g_soht_set_pohben0_b3ie(module_id, slice,
                        ten_n10g_tx_table[TEN_N10G_TX_POHBEN0_B3IE][mode]);

  ret_val |= ten_n10g_soht_set_pohben0_c2ie(module_id, slice,
                        ten_n10g_tx_table[TEN_N10G_TX_POHBEN0_C2IE][mode]);

  ret_val |= ten_n10g_soht_set_pohben0_j1ie(module_id, slice,
                        ten_n10g_tx_table[TEN_N10G_TX_POHBEN0_J1IE][mode]);

  ret_val |= ten_n10g_set_poh_byte(module_id, slice, TEN_SET_POH_C2,
                        ten_n10g_tx_table[TEN_N10G_TX_POHBYTES0_C2BYTE][mode]);

  ret_val |= ten_n10g_soht_j0strg0(module_id, slice, 0,
                        ten_n10g_tx_table[TEN_N10G_TX_J0STRG0_J0STRG0][mode]);

  ret_val |= ten_n10g_soht_b2ie(module_id, slice, 0,
                     ten_n10g_tx_table[TEN_N10G_TX_B2IE0_B2IE0][mode]);

  ret_val |= ten_n10g_soht_b2ie(module_id, slice, 1,
                   ten_n10g_tx_table[TEN_N10G_TX_B2IE1_B2IE1][mode]);

  ret_val |= ten_n10g_soht_b2ie(module_id, slice, 2,
                          ten_n10g_tx_table[TEN_N10G_TX_B2IE2_B2IE2][mode]);

  ret_val |= ten_n10g_soht_b2ie(module_id, slice, 3,
                          ten_n10g_tx_table[TEN_N10G_TX_B2IE3_B2IE3][mode]);

  ret_val |= ten_n10g_soht_b2ie(module_id, slice, 4,
                          ten_n10g_tx_table[TEN_N10G_TX_B2IE4_B2IE4][mode]);

  ret_val |= ten_n10g_soht_b2ie(module_id, slice, 5,
                          ten_n10g_tx_table[TEN_N10G_TX_B2IE5_B2IE5][mode]);

  ret_val |= ten_n10g_soht_b2ie(module_id, slice, 6,
                          ten_n10g_tx_table[TEN_N10G_TX_B2IE6_B2IE6][mode]);

  ret_val |= ten_n10g_soht_b2ie(module_id, slice, 7,
                          ten_n10g_tx_table[TEN_N10G_TX_B2IE7_B2IE7][mode]);

  ret_val |= ten_n10g_soht_b2ie(module_id, slice, 8,
                          ten_n10g_tx_table[TEN_N10G_TX_B2IE8_B2IE8][mode]);

  ret_val |= ten_n10g_soht_b2ie(module_id, slice, 9,
                          ten_n10g_tx_table[TEN_N10G_TX_B2IE9_B2IE9][mode]);

  ret_val |= ten_n10g_soht_b2ie(module_id, slice, 10,
                          ten_n10g_tx_table[TEN_N10G_TX_B2IE10_B2IE10][mode]);

  ret_val |= ten_n10g_soht_b2ie(module_id, slice, 11,
                          ten_n10g_tx_table[TEN_N10G_TX_B2IE11_B2IE11][mode]);

  ret_val |= ten_n10g_soht_b2ie(module_id, slice, 12,
                          ten_n10g_tx_table[TEN_N10G_TX_B2IE12_B2IE12][mode]);

  ret_val |= ten_n10g_otnt_scrambling(module_id, slice,
                           ten_n10g_tx_table[TEN_N10G_TX_OCFG_POSTSCR][mode],
                           ten_n10g_tx_table[TEN_N10G_TX_OCFG_PRESCR][mode]);

  ret_val |= ten_n10g_otnt_set_wrmd(module_id, slice,
                         ten_n10g_tx_table[TEN_N10G_TX_WRPCFG3_WRMD][mode]);

  ret_val |= ten_n10g_otnt_set_c15res_en(module_id, slice,
                              ten_n10g_tx_table[TEN_N10G_TX_WRPCFG3_C15RES_EN][mode]);

  ret_val |= ten_n10g_otnt_set_stm64md(module_id, slice,
                            ten_n10g_tx_table[TEN_N10G_TX_WRPCFG3_STM64MD][mode]);

  ret_val |= ten_n10g_otnt_set_g43md(module_id, slice,
                          ten_n10g_tx_table[TEN_N10G_TX_WRPCFG3_G43MD][mode]);

  ret_val |= ten_n10g_otnt_set_frame_format(module_id, slice,
                                 ten_n10g_tx_table[TEN_N10G_TX_WRPCFG0_NCOLS][mode],
                                 3, /* NROWS */
                                 ten_n10g_tx_table[TEN_N10G_TX_WRPCFG2_NPARB][mode],
                                 ten_n10g_tx_table[TEN_N10G_TX_WRPCFG2_NPAR][mode]);

  ret_val |= ten_n10g_set_otnt_wrpcfg4(module_id, slice,
                            ten_n10g_tx_table[TEN_N10G_TX_WRPCFG4_JC_PLUS_ODTU23][mode],
                            ten_n10g_tx_table[TEN_N10G_TX_WRPCFG4_JC_PLUS_OTU2][mode],
                            ten_n10g_tx_table[TEN_N10G_TX_WRPCFG4_JCEN_DT][mode],
                            ten_n10g_tx_table[TEN_N10G_TX_WRPCFG4_JCEN_ODTU23][mode],
                            ten_n10g_tx_table[TEN_N10G_TX_WRPCFG4_JCEN_OTU2][mode]);

  ret_val |= ten_n10g_otnt_set_wrpfs(module_id, slice,
                          ten_n10g_tx_table[TEN_N10G_TX_WRPFS_FS][mode]);

  ret_val |= ten_n10g_otnt_set_ptie(module_id, slice,
                         ten_n10g_tx_table[TEN_N10G_TX_CFG0_PTIE][mode]);

  ret_val |= ten_n10g_otnt_set_pti_byte(module_id, slice,
                             ten_n10g_tx_table[TEN_N10G_TX_CFG2_PT][mode]);

  ret_val |= ten_n10g_set_expected_pti_byte(module_id, slice,
                                 ten_n10g_tx_table[TEN_N10G_TX_EXPTI_EXPTI][mode]);

  if (mode == TEN_N10G_TX_10GE_192_OXU3) {
     ret_val |= ten_n10g_otnt_set_stm64md(module_id, slice, 1);
  }

  CS_PRINT("High-Level N10G TX Provisioning Complete.\n");

RTN_EXIT:
  return(ret_val);
}

/****************************************************************/
/* $rtn_hdr_start  N10G RX TRANS REGEN                          */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : HIGH LEVEL                                      */
/* CHIP       : Tenabo                                          */
cs_status ten_hl_n10g_rx_trans_regen(cs_uint16 module_id,
                                     cs_uint8 slice)
/* INPUTS     : o Module Id                                     */
/*              o Slice                                         */
/*              o Mode                                          */
/*                                                              */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* Configure N10G RX for transparent regenerator mode.          */
/*                                                              */
/* The [slice] parameter is specified as:                       */
/*   0x00 = TEN_SLICE0                                          */
/*   0x01 = TEN_SLICE1                                          */
/*   0x02 = TEN_SLICE2                                          */
/*   0x03 = TEN_SLICE3                                          */
/*   0xFF = TEN_SLICE_ALL                                       */
/*                                                              */
/* LOS , LOF, and OTUk-AIS reported to OHPP                     */
/* TCM and PM layers may optionally be used for non-intrusive   */
/* monitoring                                                   */
/* SDH Processor and PP10G may optionally be used for           */
/* non-intrusive monitoring                                     */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  cs_uint16 sl;
  TEN_N10G_GBLR_DPCFG_t tmp_gblr_dpcfg;
  TEN_N10G_OTNR_ODWCFG_t tmp_otnr_odwcfg;
  T41_t *pDev = NULL;

  CS_PRINT("ten_hl_n10g_rx_trans_regen, slice = %d\n", slice);

  TEN_N10G_VALIDATE(module_id, slice);

  if ((slice >= TEN_MAX_SLICES) && (slice != TEN_SLICE_ALL)) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": slice out of range.  s/b 0..3.");
    return(CS_ERROR);
  }

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_N10G);

  for (sl=0; sl<TEN_MAX_SLICES; sl++) {
    if ((slice == sl) || (slice == TEN_SLICE_ALL)) {
      tmp_gblr_dpcfg.wrd = TEN_REG_READ(TEN_N10G_REG_ADDR(pDev, module_id, sl, DPCFG));
      tmp_gblr_dpcfg.bf.XSEL   = 1;     /* Align OxU2 */
      tmp_gblr_dpcfg.bf.SBYFRM = 1;     /* OTN Bypass Disabled */
      tmp_gblr_dpcfg.bf.OBY    = 0;     /* SDH Frame Bypass Enable (Framed OTN through the XCON) */
      TEN_REG_WRITE(TEN_N10G_REG_ADDR(pDev, module_id, sl, DPCFG), tmp_gblr_dpcfg.wrd);

      tmp_otnr_odwcfg.wrd = TEN_REG_READ(TEN_N10G_REG_ADDR(pDev, module_id, sl, ODWCFG));
      tmp_otnr_odwcfg.bf.FSOMD = 1;     /* Remove FEC OTU->ODU */
      TEN_REG_WRITE(TEN_N10G_REG_ADDR(pDev, module_id, sl, ODWCFG), tmp_otnr_odwcfg.wrd);
    }
  }

  TEN_MOD_UNLOCK(module_id, TEN_ID_N10G);

  return (CS_OK);
}

/****************************************************************/
/* $rtn_hdr_start  N10G TX TRANS REGEN                          */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : HIGH LEVEL                                      */
/* CHIP       : Tenabo                                          */
cs_status ten_hl_n10g_tx_trans_regen(cs_uint16 module_id,
                                     cs_uint8 slice)
/* INPUTS     : o Module Id                                     */
/*              o Slice                                         */
/*              o Mode                                          */
/*                                                              */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* Configure N10G TX for transparent regenerator mode.          */
/*                                                              */
/* The [slice] parameter is specified as:                       */
/*   0x00 = TEN_SLICE0                                          */
/*   0x01 = TEN_SLICE1                                          */
/*   0x02 = TEN_SLICE2                                          */
/*   0x03 = TEN_SLICE3                                          */
/*   0xFF = TEN_SLICE_ALL                                       */
/*                                                              */
/* SFU inserts ODUk-AIS as consequent action if LOS/LOF/OTUk-AIS*/
/* detected on opposite RX (this must include setting           */
/* OTNT_CFG0.FASIE=1, OTNT_CFG0.MFASINS=0x3)                    */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  cs_uint16 sl;
  TEN_N10G_GBLT_CFGTX0_t tmp_gblt_cfgtx0;
  TEN_N10G_OTNT_CFG0_t tmp_otnt_cfg0;
  TEN_N10G_OTNT_WRPCFG3_t tmp_otnt_wrpcfg3;
  TEN_N10G_OTNT_CFG4_t tmp_otnt_cfg4;
  T41_t *pDev = NULL;

  CS_PRINT("ten_hl_n10g_tx_trans_regen, slice = %d\n", slice);

  TEN_N10G_VALIDATE(module_id, slice);

  if ((slice >= TEN_MAX_SLICES) && (slice != TEN_SLICE_ALL)) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": slice out of range.  s/b 0..3.");
    return(CS_ERROR);
  }

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_N10G);

  for (sl=0; sl<TEN_MAX_SLICES; sl++) {
    if ((slice == sl) || (slice == TEN_SLICE_ALL)) {
      tmp_gblt_cfgtx0.wrd = TEN_REG_READ(TEN_N10G_REG_ADDR(pDev, module_id, sl, CFGTX0));
      tmp_gblt_cfgtx0.bf.OBY   = 0;     /* OTN Bypass Disabled */
      tmp_gblt_cfgtx0.bf.SBY   = 1;     /* SDH Bypass Enabled */
      tmp_gblt_cfgtx0.bf.KPGBY = 1;     /* KPG Bypass Enabled */
      TEN_REG_WRITE(TEN_N10G_REG_ADDR(pDev, module_id, sl, CFGTX0), tmp_gblt_cfgtx0.wrd);

      tmp_otnt_cfg0.wrd = TEN_REG_READ(TEN_N10G_REG_ADDR(pDev, module_id, sl, CFG0));
      tmp_otnt_cfg0.bf.PTIE    = 0;     /* Disable Payload Type Indicator */
      tmp_otnt_cfg0.bf.FASIE   = 0;     /* Do Not Insert FAS Pattern */
      tmp_otnt_cfg0.bf.MFASINS = 0;     /* Never Insert MFAS Counter */
      TEN_REG_WRITE(TEN_N10G_REG_ADDR(pDev, module_id, sl, CFG0), tmp_otnt_cfg0.wrd);

      tmp_otnt_wrpcfg3.wrd = TEN_REG_READ(TEN_N10G_REG_ADDR(pDev, module_id, sl, WRPCFG3));
      tmp_otnt_wrpcfg3.bf.WRMD = 3;     /* Map ODU->OTU */
      TEN_REG_WRITE(TEN_N10G_REG_ADDR(pDev, module_id, sl, WRPCFG3), tmp_otnt_wrpcfg3.wrd);

      tmp_otnt_cfg4.wrd = TEN_REG_READ(TEN_N10G_REG_ADDR(pDev, module_id, sl, CFG4));
      tmp_otnt_cfg4.bf.BIPMSK = 0;      /* Pass Through Section BIP */
      TEN_REG_WRITE(TEN_N10G_REG_ADDR(pDev, module_id, sl, CFG4), tmp_otnt_cfg4.wrd);
    }
  }

  TEN_MOD_UNLOCK(module_id, TEN_ID_N10G);

  return (CS_OK);
}

/****************************************************************/
/* $rtn_hdr_start  N10G RX SECTION TERM                         */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : HIGH LEVEL                                      */
/* CHIP       : Tenabo                                          */
cs_status ten_hl_n10g_rx_section_term(cs_uint16 module_id,
                                      cs_uint8  slice,
                                      cs_uint8  term_otu)
/* INPUTS     : o Module Id                                     */
/*              o Slice                                         */
/*              o OTU Overhead Termination Type                 */
/*                                                              */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* Configure N10G RX for section terminatior mode.              */
/*                                                              */
/* The [slice] parameter is specified as:                       */
/*   0x00 = TEN_SLICE0                                          */
/*   0x01 = TEN_SLICE1                                          */
/*   0x02 = TEN_SLICE2                                          */
/*   0x03 = TEN_SLICE3                                          */
/*   0xFF = TEN_SLICE_ALL                                       */
/*                                                              */
/* The [term_otu] parameter specifies the OTU overhead          */
/* termination and is one of the following:                     */
/*   0x00 = TEN_OTU_TERM_TRANSPARENT                            */
/*   0x01 = TEN_OTU_TERM_SECTION                                */
/*                                                              */
/* LOS , LOF, and OTUk-AIS reported to OHPP                     */
/* SM-dTIM, SM-dDEG, SM-dIAE, SM-dBDI, SM-dBIAE  defects        */
/* reported to OHPP                                             */
/* TCM and PM layers may optionally be used for non-intrusive   */
/* monitoring                                                   */
/* SDH Processor and PP10G may optionally be used for           */
/* non-intrusive monitoring                                     */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  cs_uint16 sl;
  TEN_N10G_GBLR_DPCFG_t tmp_gblr_dpcfg;
  TEN_N10G_OTNR_ODWCFG_t tmp_otnr_odwcfg;
  TEN_N10G_OOHR_CFG5_t tmp_oohr_cfg5;
  T41_t *pDev = NULL;

  CS_PRINT("ten_hl_n10g_rx_section_term, slice = %d\n", slice);

  TEN_N10G_VALIDATE(module_id, slice);

  if ((slice >= TEN_MAX_SLICES) && (slice != TEN_SLICE_ALL)) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": slice out of range.  s/b 0..3.");
    return(CS_ERROR);
  }

  if (term_otu > TEN_OTU_TERM_FULL) {
    CS_HNDL_ERROR (module_id, ETEN_MOD_INVALID_USER_ARG, ": term_otu out of range.  s/b 0..2.");
    return(CS_ERROR);
  }

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_N10G);

  for (sl=0; sl<TEN_MAX_SLICES; sl++) {
    if ((slice == sl) || (slice == TEN_SLICE_ALL)) {
      tmp_gblr_dpcfg.wrd = TEN_REG_READ(TEN_N10G_REG_ADDR(pDev, module_id, sl, DPCFG));
      if (term_otu == TEN_OTU_TERM_SECTION) {
        tmp_gblr_dpcfg.bf.XSEL   = 1;     /* Align OxU2 */
      } else {
        tmp_gblr_dpcfg.bf.XSEL   = 2;     /* Align payload */
      }
      tmp_gblr_dpcfg.bf.SBYFRM = 1;     /* OTN Bypass Disabled */
      tmp_gblr_dpcfg.bf.OBY    = 0;     /* SDH Frame Bypass Enable (Framed OTN through the XCON) */
      TEN_REG_WRITE(TEN_N10G_REG_ADDR(pDev, module_id, sl, DPCFG), tmp_gblr_dpcfg.wrd);

      tmp_otnr_odwcfg.wrd = TEN_REG_READ(TEN_N10G_REG_ADDR(pDev, module_id, sl, ODWCFG));
      tmp_otnr_odwcfg.bf.FSOMD = 1;     /* Remove FEC OTU->ODU */
      TEN_REG_WRITE(TEN_N10G_REG_ADDR(pDev, module_id, sl, ODWCFG), tmp_otnr_odwcfg.wrd);

      tmp_oohr_cfg5.wrd = TEN_REG_READ(TEN_N10G_OOHR_REG_ADDR(pDev, module_id, sl, CFG5));
      tmp_oohr_cfg5.bf.BIPMSK  = 0xFF;
      tmp_oohr_cfg5.bf.MFALGNE = 1;     /* MFAS Alignment Enabled */
      TEN_REG_WRITE(TEN_N10G_OOHR_REG_ADDR(pDev, module_id, sl, CFG5), tmp_oohr_cfg5.wrd);
    }
  }

  TEN_MOD_UNLOCK(module_id, TEN_ID_N10G);

  return (CS_OK);
}

/****************************************************************/
/* $rtn_hdr_start  N10G TX SECTION TERM                         */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : HIGH LEVEL                                      */
/* CHIP       : Tenabo                                          */
cs_status ten_hl_n10g_tx_section_term(cs_uint16 module_id,
                                      cs_uint8  slice,
                                      cs_uint8  term_otu,
                                      cs_uint8  bipmsk)
/* INPUTS     : o Module Id                                     */
/*              o Slice                                         */
/*              o OTU Overhead Termination Type                 */
/*              o bip mask                                      */
/*                                                              */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* Configure N10G TX for section terminatior mode.              */
/*                                                              */
/* The [slice] parameter is specified as:                       */
/*   0x00 = TEN_SLICE0                                          */
/*   0x01 = TEN_SLICE1                                          */
/*   0x02 = TEN_SLICE2                                          */
/*   0x03 = TEN_SLICE3                                          */
/*   0xFF = TEN_SLICE_ALL                                       */
/*                                                              */
/* The [term_otu] parameter specifies the OTU overhead          */
/* termination and is one of the following:                     */
/*   0x00 = TEN_OTU_TERM_TRANSPARENT                            */
/*   0x01 = TEN_OTU_TERM_SECTION                                */
/*                                                              */
/* The [tcm] parameter specifies tandem pair <1-6>              */
/*                                                              */
/* SFU inserts ODUk-AIS as consequent action if LOS/LOF/OTUk-AIS*/
/* or optionally SM-dTIM  detected on opposite RX               */
/* SFU inserts SM-IAE as consequent action if LOS/LOF/OTUk-AIS  */
/* detected on opposite RX, else set SM-IAE = 0                 */
/* SFU inserts SM-BEI based on SM-BIP errors detected on same   */
/* side RX                                                      */
/* SFU inserts SM-BIAE as consequent action when SM-dIAE        */
/* detected on same side RX                                     */
/* SFU inserts SM-BDI as consequent action when LOS/LOF/OTUk-AIS*/
/* or optionally SM-dTIM  detected on same side RX, else set    */
/* SM-BDI=0                                                     */
/* SM-TTI,  GCC0, and RES overhead may optionally be inserted.  */
/* ODU-layer GCC1/GCC2, FTFL, APS/PCC, EXP, and RES overhead    */
/* may optionally be inserted.                                  */
/* SFU inserts TCMi-BEI based on TCMi-BIP errors detected on    */
/* TCM-Terminating side RX                                      */
/* SFU inserts TCMi-BIAE as consequent action when TCMi-dIAE    */
/* detected on TCM-Terminating side RX                          */
/* SFU inserts TCMi-BDI as consequent action when LOS/LOF/      */
/* OTUk-AIS or optionally SM-dTIM or TCMi-ODUkAIS/dOCI/dLCK/dLTC*/
/* or optionally TCMi-dTIM detected on TCM-Terminating side RX, */
/* else set TCMi-BDI=0                                          */
/* SFU inserts TCMi-aIAE (TCMi -STAT = 010) as consequent action*/
/* if LOS/LOF/OTUk-AIS on opposite RX, else set TCMi- STAT = 001*/
/* TCMi-TTI inserted                                            */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  cs_uint16 sl;
  TEN_N10G_GBLT_CFGTX0_t tmp_gblt_cfgtx0;
  TEN_N10G_OTNT_CFG0_t tmp_otnt_cfg0;
  TEN_N10G_OTNT_WRPCFG3_t tmp_otnt_wrpcfg3;
  TEN_N10G_OTNT_CFG4_t tmp_otnt_cfg4;
  T41_t *pDev = NULL;
  /*cs_uint8 bipmsk;*/

  CS_PRINT("ten_hl_n10g_tx_section_term, slice = %d\n", slice);

  TEN_N10G_VALIDATE(module_id, slice);

  if ((slice >= TEN_MAX_SLICES) && (slice != TEN_SLICE_ALL)) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": slice out of range.  s/b 0..3.");
    return(CS_ERROR);
  }

  if (term_otu > TEN_OTU_TERM_FULL) {
    CS_HNDL_ERROR (module_id, ETEN_MOD_INVALID_USER_ARG, ": term_otu out of range.  s/b 0..2.");
    return(CS_ERROR);
  }

  /*if (tcm > 6) {                                                                          */
  /*  CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": tcm out of range.  s/b 1..6.");*/
  /*  return(CS_ERROR); }                                                                   */
  /* bipmsk = 0x80 + (1 << tcm) ;*/

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_N10G);

  for (sl=0; sl<TEN_MAX_SLICES; sl++) {
    if ((slice == sl) || (slice == TEN_SLICE_ALL)) {
      tmp_gblt_cfgtx0.wrd = TEN_REG_READ(TEN_N10G_REG_ADDR(pDev, module_id, sl, CFGTX0));
      tmp_gblt_cfgtx0.bf.OBY   = 0;     /* OTN Bypass Disabled */
      tmp_gblt_cfgtx0.bf.SBY   = 1;     /* SDH Bypass Enabled */
      tmp_gblt_cfgtx0.bf.KPGBY = 1;     /* KPG Bypass Enabled */
      TEN_REG_WRITE(TEN_N10G_REG_ADDR(pDev, module_id, sl, CFGTX0), tmp_gblt_cfgtx0.wrd);

      tmp_otnt_cfg0.wrd = TEN_REG_READ(TEN_N10G_REG_ADDR(pDev, module_id, sl, CFG0));
      tmp_otnt_cfg0.bf.PTIE    = 0;     /* Disable Payload Type Indicator */
      tmp_otnt_cfg0.bf.FASIE   = 1;     /* Insert FAS Pattern */
      tmp_otnt_cfg0.bf.MFASINS = 3;     /* Always Insert MFAS Counter */
      tmp_otnt_cfg0.bf.MFALGNE = 1;     /* Enable MFAS Alignment */
      TEN_REG_WRITE(TEN_N10G_REG_ADDR(pDev, module_id, sl, CFG0), tmp_otnt_cfg0.wrd);

      tmp_otnt_wrpcfg3.wrd = TEN_REG_READ(TEN_N10G_REG_ADDR(pDev, module_id, sl, WRPCFG3));
      if (term_otu == TEN_OTU_TERM_SECTION) {
        tmp_otnt_wrpcfg3.bf.WRMD = 3;     /* Map ODU->OTU */
      } else {
        tmp_otnt_wrpcfg3.bf.WRMD = 1;     /* Map OTU->OTU */
      }
      TEN_REG_WRITE(TEN_N10G_REG_ADDR(pDev, module_id, sl, WRPCFG3), tmp_otnt_wrpcfg3.wrd);

      tmp_otnt_cfg4.wrd = TEN_REG_READ(TEN_N10G_REG_ADDR(pDev, module_id, sl, CFG4));
      tmp_otnt_cfg4.bf.BIPMSK = bipmsk;   /* Generate Section BIP */
      TEN_REG_WRITE(TEN_N10G_REG_ADDR(pDev, module_id, sl, CFG4), tmp_otnt_cfg4.wrd);
    }
  }

  TEN_MOD_UNLOCK(module_id, TEN_ID_N10G);

  return (CS_OK);
}

/****************************************************************/
/* $rtn_hdr_start  N10G CONFIG TERMINATION                      */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : HIGH LEVEL                                      */
/* CHIP       : Tenabo                                          */
cs_status ten_hl_n10g_config_termination(cs_uint16 module_id,
                                         cs_uint8  slice,
                                         cs_uint8  term_otu,
                                         cs_uint8  tcm)
/* INPUTS     : o Module Id                                     */
/*              o Slice                                         */
/*              o OTU Overhead Termination Type                 */
/*              o TCM termination                               */
/*                                                              */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* Configure N10G TX for section terminatior mode.              */
/*                                                              */
/* The [slice] parameter is specified as:                       */
/*   0x00 = TEN_SLICE0                                          */
/*   0x01 = TEN_SLICE1                                          */
/*   0x02 = TEN_SLICE2                                          */
/*   0x03 = TEN_SLICE3                                          */
/*   0xFF = TEN_SLICE_ALL                                       */
/*                                                              */
/* The [term_otu] parameter specifies the OTU overhead          */
/* termination and is one of the following:                     */
/*   0x00 = TEN_OTU_TERM_TRANSPARENT                            */
/*   0x01 = TEN_OTU_TERM_SECTION                                */
/*                                                              */
/* The [tcm] parameter specifies the termination for TCM 1      */
/* through 6.  This is a bit encoded paramerts with bits 1      */
/* through 6 specifying TCM 1 thourgh 6 respecivly.  These bits */
/* are defined as follows:                                      */
/*   0 = disable                                                */
/*   1 = enable                                                 */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  cs_uint8 bipmsk;

  CS_PRINT("ten_hl_n10g_config_termination, slice = %d, term_otu = %d, tcm = 0x%X\n",
           slice, term_otu, tcm);

  TEN_N10G_VALIDATE(module_id, slice);

  if ((slice >= TEN_MAX_SLICES) && (slice != TEN_SLICE_ALL)) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": slice out of range.  s/b 0..3.");
    return(CS_ERROR);
  }

  /* Setup Termination Mode */
  if (term_otu == TEN_OTU_TERM_TRANSPARENT) {
    /* Transparent Regenerator */
    /* RX Side */
    ten_hl_n10g_rx_trans_regen (module_id, slice);

    /* TX Side */
    ten_hl_n10g_tx_trans_regen (module_id, slice);
  } else {
    /* Section Terminator */
    /* RX Side */
    ten_hl_n10g_rx_section_term (module_id, slice, term_otu);

    /* TX Side */
    /* Take into account any TCM (Tandem Connection Monitoring) */
    if (term_otu == TEN_OTU_TERM_SECTION) {
        /* Set Section Monitoring BIP-8 update */
        bipmsk = 0x80 | tcm;
    } else {
        /* Set Section Monitoring and Path Monitoring BIP-8 update */
        bipmsk = 0x81 | tcm;
    }

    CS_PRINT ("bipmsk = 0x%X\n", bipmsk);

    ten_hl_n10g_tx_section_term (module_id, slice, term_otu, bipmsk);
  }

  return (CS_OK);
}

/****************************************************************/
/* $rtn_hdr_start  N10G CONFIG PTI                              */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : HIGH LEVEL                                      */
/* CHIP       : Tenabo                                          */
cs_status ten_hl_n10g_config_pti(cs_uint16 module_id,
                                 cs_uint8  slice,
                                 cs_uint16 client,
                                 cs_uint16 sync)
/* INPUTS     : o Module Id                                     */
/*              o Slice                                         */
/*              o Client                                        */
/*              o Sync                                          */
/*                                                              */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* Provision the PTI overhead for OTU2.                         */
/*                                                              */
/* The [slice] parameter is specified as:                       */
/*   0x00 = TEN_SLICE0                                          */
/*   0x01 = TEN_SLICE1                                          */
/*   0x02 = TEN_SLICE2                                          */
/*   0x03 = TEN_SLICE3                                          */
/*   0xFF = TEN_SLICE_ALL                                       */
/*                                                              */
/* The [client] parameter is specified as:                      */
/*   TEN_TRAFFIC_TYPE_OC192 = 8,                                */
/*   TEN_TRAFFIC_TYPE_10GE_WAN = 9,                             */
/*   TEN_TRAFFIC_TYPE_10GE_6_2 = 10,                            */
/*   TEN_TRAFFIC_TYPE_10GE_7_1 = 11,                            */
/*   TEN_TRAFFIC_TYPE_10GE_7_3 = 12,                            */
/*   TEN_TRAFFIC_TYPE_10GFC = 13,                               */
/*   TEN_TRAFFIC_TYPE_10GE = 20                                 */
/*   TEN_TRAFFIC_TYPE_10GE_6_1 = 26                             */
/*   TEN_TRAFFIC_TYPE_10GE_TC = 33                              */
/*                                                              */
/* The [sync] parameter is specified as:                        */
/*    0 = Async, 1 = Sync.                                      */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  cs_status rtn = CS_OK;
  cs_uint16 pti = 0xFFFF;
  cs_uint16 pti_applicable = TRUE;
  cs_char8 *func = "ten_hl_n10g_config_pti";  

  CS_PRINT("%s() %s, %s, %s, sync=%d",
           func,
           ten_module_strings[module_id & 1],
           ten_slice_strings[slice],
           ten_hl_config_traffic_types_strings[client],
           sync);

  switch (client) {
  case (TEN_TRAFFIC_TYPE_OC192):
    if (sync == 1) {
      pti = TEN_PAYLOAD_TYPE_SYNC_CBR; /* 3 */
    }
    else {
      pti = TEN_PAYLOAD_TYPE_ASYNC_CBR; /* 2 */
    }
    break;

  case (TEN_TRAFFIC_TYPE_10GE_6_2):
/* Bugzilla 20308 Start */
  case (TEN_TRAFFIC_TYPE_10GE_GFPF_OC192_ODU2):
/* Bugzilla 20308 End */
  case (TEN_TRAFFIC_TYPE_10GE_TC):
    pti = TEN_PAYLOAD_TYPE_GFP; /* 5 */
    break;

  case (TEN_TRAFFIC_TYPE_10GE):
  case (TEN_TRAFFIC_TYPE_10GE_WAN):
  case (TEN_TRAFFIC_TYPE_10GE_7_1):
  case (TEN_TRAFFIC_TYPE_10GE_6_1):
  case (TEN_TRAFFIC_TYPE_10GFC):
  case  TEN_TRAFFIC_TYPE_10GFC_TC:  /* Bugzilla 24360 */
  case  TEN_TRAFFIC_TYPE_10GFC_TC_G709: /* Bug 31054 */
    pti = TEN_PAYLOAD_TYPE_SYNC_CBR; /* 3 */
    break;

  case (TEN_TRAFFIC_TYPE_10GE_7_3):
  /* Bugzilla 22237 Start */
  case (TEN_TRAFFIC_TYPE_10GE_RA):
  /* Bugzilla 22237 End */
    pti = 9;
    break;

  default:
    pti_applicable = FALSE;
    break;
  }

  if (pti_applicable) {
    rtn |= ten_n10g_otnt_set_ptie(module_id, slice, 1);
    rtn |= ten_n10g_otnt_set_pti_byte(module_id, slice, pti);
    rtn |= ten_n10g_set_expected_pti_byte(module_id, slice, pti);
  }

  return (rtn);
}

/* Bugzilla 24360 Start */
/****************************************************************/
/* $rtn_hdr_start  N10G CONFIG PTI T41                          */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : HIGH LEVEL                                      */
/* CHIP       : Tenabo                                          */
cs_status ten_hl_n10g_config_pti_t41 (cs_uint16 module_id,
                                      cs_uint8  slice,
                                      cs_uint16 client,
                                      cs_uint16 mapper,
                                      cs_uint16 map_proc,
                                      cs_uint16 timeslots,
                                      cs_uint16 kpga)
/* INPUTS     : o Module Id                                     */
/*              o Slice                                         */
/*              o Client                                        */
/*              o Mapper                                        */
/*              o Map Procedure                                 */
/*              o Time Slots                                    */
/*              o KPGA                                          */
/*                                                              */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* Provision the PTI overhead for OTU3v.                        */
/*                                                              */
/* [module_id] parameter specifies line's module ID             */
/* 16 devices can be registered and module bit indicates line   */
/* or client side of the registered device. The registered      */
/* device is identified by the dev_id bits specified below      */
/*   Bits 11:8 – dev_id, Bits 7:1 – don’t care, Bit 0 – module  */
/*                                                              */
/* The [slice] parameter is specified as:                       */
/*   0x00 = TEN_SLICE0                                          */
/*   0x01 = TEN_SLICE1                                          */
/*   0x02 = TEN_SLICE2                                          */
/*   0x03 = TEN_SLICE3                                          */
/*   0xFF = TEN_SLICE_ALL                                       */
/*                                                              */
/* The [client] parameter is specified as:                      */
/*   TEN_TRAFFIC_TYPE_OC192 = 8,                                */
/*   TEN_TRAFFIC_TYPE_10GE_WAN = 9,                             */
/*   TEN_TRAFFIC_TYPE_10GE_6_2 = 10,                            */
/*   TEN_TRAFFIC_TYPE_10GE_7_1 = 11,                            */
/*   TEN_TRAFFIC_TYPE_10GE_7_3 = 12,                            */
/*   TEN_TRAFFIC_TYPE_10GFC = 13,                               */
/*   TEN_TRAFFIC_TYPE_10GE = 20                                 */
/*   TEN_TRAFFIC_TYPE_10GE_6_1 = 26                             */
/*   TEN_TRAFFIC_TYPE_10GE_TC = 33                              */
/*                                                              */
/* [mapper] parameter specifies the traffic type of the line:   */
/*   TEN_TRAFFIC_TYPE_NONE                 = 0                  */
/*   TEN_TRAFFIC_TYPE_OTU2                 = 5                  */
/*   TEN_TRAFFIC_TYPE_OTU2E                = 6                  */
/*   TEN_TRAFFIC_TYPE_OTU1F                = 7                  */
/*   TEN_TRAFFIC_TYPE_OTU1E                = 29                 */
/*                                                              */
/* The [map_proc] parameter specifies the mapping method        */
/*   TEN_MAP_AMP,           = 0                                 */
/*   TEN_MAP_BMP,           = 1                                 */
/*   TEN_MAP_AMP_DT,        = 2                                 */
/*   TEN_MAP_AMP_PROP,      = 3                                 */
/*   TEN_MAP_AMP_PROP_DT,   = 4                                 */
/*   TEN_MAP_GMP_HO,        = 6                                 */
/*   TEN_MAP_GMP_HO_DT,     = 7                                 */
/*                                                              */
/* The [timeslots] parameter specifies number of timeslots.     */
/* Bandwidth for map_proc = GMP_HO is always 1.25G per timeslot.*/
/*   timeslots = 1 - 8                                          */
/* Bandwidth for map_proc = AMP or AMP_DT is as follows:        */
/*   timeslots = 4 for 2.5G per timeslot                        */
/*   timeslots = 8 for 1.25G per timeslot                       */
/* Bandwidth for all other map_proc is 2.5G so timeslots = 4    */
/*                                                              */
/* The [kpga] parameter is specified as:                        */
/*   0x00 = TEN_KPG_FIXED_PATTERN                               */
/*   0x01 = TEN_KPG_PN11                                        */
/*   0x02 = TEN_KPG_PN23                                        */
/*   0x03 = TEN_KPG_PN31                                        */
/*   0x04 = TEN_KPG_DISABLED                                    */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  cs_uint16 pti = 0xFFFF;  /* Payload Type Identifier */
  cs_status rtn = CS_OK;
  cs_char8 *func = "ten_hl_n10g_config_pti_t41";  

  CS_PRINT("%s() %s, %s, %s, %s",
           func,
           ten_module_strings[module_id & 1],
           ten_slice_strings[slice],
           ten_hl_config_traffic_types_strings[client],
           ten_hl_config_traffic_types_strings[mapper]);
  if (map_proc <= TEN_MAP_GMP_HO_DT) {
    CS_PRINT(", map_proc=%s", ten_sync_type_strings[map_proc]);
  }
  else {
    CS_PRINT(", map_proc=%d", map_proc);
  }
  CS_PRINT(", timeslots=0x%X, %s\n", timeslots, ten_kpg_strings[kpga]);


  if (kpga != TEN_KPG_DISABLED) {
    pti = TEN_PAYLOAD_TYPE_PRBS;
  }
  else {
    switch (client) {
      case (TEN_TRAFFIC_TYPE_OC192):
      case (TEN_TRAFFIC_TYPE_OC192_OTU2):
      case (TEN_TRAFFIC_TYPE_10GE_WAN):
      case (TEN_TRAFFIC_TYPE_10GE):
      case (TEN_TRAFFIC_TYPE_10GE_GFPF_OC192_ODU2):
        /* All of these go into the OTU2 with the standard fixed stuff */
        if (map_proc == TEN_MAP_BMP) {
          pti = TEN_PAYLOAD_TYPE_SYNC_CBR;
        }
        else {
          pti = TEN_PAYLOAD_TYPE_ASYNC_CBR;
        }
        break;

      case (TEN_TRAFFIC_TYPE_10GE_TC):
        pti = TEN_PAYLOAD_TYPE_GFP;
        break;

      case (TEN_TRAFFIC_TYPE_10GE_6_1):
        pti = TEN_PAYLOAD_TYPE_SYNC_CBR;    /* SyncDsync does not do any justification */
        break;

      case (TEN_TRAFFIC_TYPE_10GE_6_2):
        pti = TEN_PAYLOAD_TYPE_GFP;
        break;

      case (TEN_TRAFFIC_TYPE_10GE_7_1):
        pti = TEN_PAYLOAD_TYPE_SYNC_CBR;   /* SyncDsync does not do any justification */
        break;

      case (TEN_TRAFFIC_TYPE_10GE_7_2):
        pti = TEN_PAYLOAD_TYPE_GFP;
        break;

      case (TEN_TRAFFIC_TYPE_10GFC):
        pti = 0; /* ????? */
        break;

      case (TEN_TRAFFIC_TYPE_10GFC_TC):
      case (TEN_TRAFFIC_TYPE_10GFC_TC_G709): /* Bug 31054 */
      case (TEN_TRAFFIC_TYPE_10GFC_TC_RA): /* Bug 36432 */
        pti = TEN_PAYLOAD_TYPE_FC_1200_OTU2E;
        break;

      case (TEN_TRAFFIC_TYPE_10GE_7_3):
      case (TEN_TRAFFIC_TYPE_10GE_RA):
        pti = TEN_PAYLOAD_TYPE_10G_GFP_EXT_OTU2;
        break;

      case (TEN_TRAFFIC_TYPE_1GE):   /* Bugzilla 38871 */
      case (TEN_TRAFFIC_TYPE_1GFC):  /* Bugzilla 38871 */
      case (TEN_TRAFFIC_TYPE_2GISC): /* Bug 38779 */
      case (TEN_TRAFFIC_TYPE_2GFC):  /* Bug 38779 */
      case (TEN_TRAFFIC_TYPE_4GFC):
        if (map_proc == TEN_MAP_BMP) {
          pti = TEN_PAYLOAD_TYPE_FC_400_ODUFEX;
        }
        /* Bugzilla 36501 start */
        else if (map_proc == TEN_MAP_GMP_LO) {
          pti = TEN_PAYLOAD_TYPE_ODU_ODTUK_MUX;
        }
        /* Bugzilla 36501 end */
        break;

      case (TEN_TRAFFIC_TYPE_8GFC):
        if (map_proc == TEN_MAP_BMP) {
          pti = TEN_PAYLOAD_TYPE_FC_800_ODUFEX;
        }
        /* Bugzilla 36501 start */
        else if (map_proc == TEN_MAP_GMP_LO) {
          pti = TEN_PAYLOAD_TYPE_ODU_ODTUK_MUX;
        }
        /* Bugzilla 36501 end */
        break;

      /* Bugzilla 38565 Start */
      case (TEN_TRAFFIC_TYPE_10G_IB):
      case (TEN_TRAFFIC_TYPE_FDR10_IB): /* Bugzilla 39242 */
          pti = TEN_PAYLOAD_TYPE_ASYNC_CBR;
        break;
      /* Bugzilla 38565 End */

      case (TEN_TRAFFIC_TYPE_8GFC_RA):
      case (TEN_TRAFFIC_TYPE_4GFC_RA):
      case (TEN_TRAFFIC_TYPE_2GFC_RA):
      case (TEN_TRAFFIC_TYPE_1GFC_RA):
      case (TEN_TRAFFIC_TYPE_8GFC_ENH):
      case (TEN_TRAFFIC_TYPE_4GFC_ENH):
      case (TEN_TRAFFIC_TYPE_2GFC_ENH):
      case (TEN_TRAFFIC_TYPE_1GFC_ENH):
        pti = TEN_PAYLOAD_TYPE_ASYNC_CBR;
        break;


      default:
        break;
    }
  }


  if (pti != 0xFFFF) {
    rtn |= ten_n10g_otnt_set_ptie(module_id, slice, 1);           /* Enable payload type identifier insertion */
    rtn |= ten_n10g_otnt_set_pti_byte(module_id, slice, pti);     /* Set payload type identifier to be sent */
    rtn |= ten_n10g_set_expected_pti_byte(module_id, slice, pti); /* Set expected payload type identifier to be received */
  } else {
    rtn |= ten_n10g_otnt_set_ptie(module_id, slice, 0);          /* Disable payload type identifier insertion */
  }

  return (rtn);
}
/* Bugzilla 24360 End */

/* Bugzilla 28237 Start */
/****************************************************************/
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : HIGH LEVEL                                      */
/* CHIP       : Tenabo                                          */
cs_status ten_n10g_mux_mapper_t41 (cs_uint16 module_id, 
                                   cs_uint16 client_traffic_type,
                                   cs_uint16 slice,
                                   cs_uint16 mapper,
                                   cs_uint16 map_oxuv,
                                   cs_uint16 map_odtu,
                                   cs_uint16 timeslots,
                                   cs_uint16 gmp_timeslot_mask)
/* DESCRIPTION:                                                 */
/* Configures the N40G for the given muxponder mapper.          */
/* INPUTS     : o Module Id                                     */
/*              o Client Type                                   */
/*              o Line Slice                                    */
/*              o Mapper Type                                   */
/*              o Mapping Procedure                             */
/*              o Tributary Slot Bandwidth                      */
/*              o GMP Timeslot Mask                             */
/*                                                              */
/* [module_id] parameter specifies line's module ID             */
/* 16 devices can be registered and module bit indicates line   */
/* or client side of the registered device. The registered      */ 
/* device is identified by the dev_id bits specified below      */
/*   Bits 11:8 – dev_id, Bits 7:1 – don’t care, Bit 0 – module  */ 
/*                                                              */
/* [client_traffic_type] parameter specifies the traffic type   */
/* of the client:                                               */
/*   TEN_TRAFFIC_TYPE_OTU2                 = 5                  */
/*   TEN_TRAFFIC_TYPE_OTU2E                = 6                  */
/*   TEN_TRAFFIC_TYPE_OTU1F                = 7                  */
/*   TEN_TRAFFIC_TYPE_OC192                = 8                  */
/*   TEN_TRAFFIC_TYPE_10GE_WAN             = 9                  */
/*   TEN_TRAFFIC_TYPE_10GE_6_2             = 10                 */
/*   TEN_TRAFFIC_TYPE_10GE_7_1             = 11                 */
/*   TEN_TRAFFIC_TYPE_10GE_7_3             = 12                 */
/*   TEN_TRAFFIC_TYPE_10GFC                = 13                 */
/*   TEN_TRAFFIC_TYPE_8GFC                 = 14                 */
/*   TEN_TRAFFIC_TYPE_10GE                 = 20                 */
/*   TEN_TRAFFIC_TYPE_10GE_6_1             = 26                 */
/*   TEN_TRAFFIC_TYPE_10GE_7_2             = 27                 */
/*   TEN_TRAFFIC_TYPE_10GE_GFPF_OC192_ODU2 = 28                 */
/*   TEN_TRAFFIC_TYPE_OTU1E                = 29                 */
/*   TEN_TRAFFIC_TYPE_10GE_RA              = 30                 */
/*   TEN_TRAFFIC_TYPE_10GE_TC              = 33                 */
/*   TEN_TRAFFIC_TYPE_OTU2F                = 34                 */
/*   TEN_TRAFFIC_TYPE_OTU2P                = 36                 */
/*   TEN_TRAFFIC_TYPE_10GFC_TC             = 46                 */
/*   TEN_TRAFFIC_TYPE_10GFC_TC_G709        = 57                 */
/*                                                              */
/* [slice] parameter specifies line's slice:                    */
/*   TEN_SLICE0 = 0                                             */
/*   TEN_SLICE1 = 1                                             */
/*   TEN_SLICE2 = 2                                             */
/*   TEN_SLICE3 = 3                                             */
/*                                                              */
/* [mapper] parameter specifies the traffic type of the line:   */
/*   TEN_TRAFFIC_TYPE_NONE                 = 0                  */
/*   TEN_TRAFFIC_TYPE_OTU3                 = 1                  */
/*   TEN_TRAFFIC_TYPE_OTU3E                = 2                  */
/*   TEN_TRAFFIC_TYPE_OTU3P                = 3                  */
/*   TEN_TRAFFIC_TYPE_OTU3P2               = 25                 */
/*   TEN_TRAFFIC_TYPE_OTU3E2               = 34                 */
/*   TEN_TRAFFIC_TYPE_OTU3E4               = 55                 */
/*                                                              */
/* The [map_oxuv] parameter specifies the first level mapping   */
/*   onto otu2v (for n10g)                                      */
/* See customer docs for valid mapping combinations.            */
/*   TEN_MAP_BMP          = 1                                   */
/*   TEN_MAP_AMP          = 0                                   */
/*   TEN_MAP_AMP_PROP     = 3                                   */
/*   TEN_MAP_GMP_LO       = 5                                   */
/*   TEN_MAP_GMP_HO       = 6                                   */
/*   TEN_MAP_DONT_CARE    = 0xFF                                */
/*                                                              */
/* The [map_odtu] parameter specifies the second level mapping  */
/*    onto odtu.                                                */
/* See customer docs for valid mapping combinations.            */
/*   TEN_MAP_AMP          = 0                                   */
/*   TEN_MAP_AMP_PROP     = 3                                   */
/*   TEN_MAP_AMP_DT       = 2                                   */
/*   TEN_MAP_GMP_HO       = 6                                   */
/*   TEN_MAP_GMP_HO_DT    = 7                                   */
/*   TEN_MAP_DONT_CARE    = 0xFF                                */
/*                                                              */
/* The [timeslots] parameter specifies number of timeslots.     */
/* Bandwidth for map_proc = GMP_HO is always 1.25G per timeslot.*/
/*   timeslots = 1 - 8                                          */
/* Bandwidth for map_proc = AMP or AMP_DT is as follows:        */
/*   timeslots = 4 for 2.5G per timeslot                        */
/*   timeslots = 8 for 1.25G per timeslot                       */
/* Bandwidth for all other map_proc is 2.5G so timeslots = 4    */
/*                                                              */
/* The [gmp_timeslot_mask] parameter specifies the timeslots to */
/* use for GMP mapping. Applicable to GMP_HO only.              */
/*   Bit 0- Timeslot 1 through Bit 7 – Timeslot 8               */
/*                                                              */
/****************************************************************/ 
{
  cs_uint16 dev_id;
  ten_dev_cb_t *pdevcb;
  ten_syncdsync_cb_t *psyncdsync_cb;
  TEN_N10G_OTNT_WRPCFG4_t tmp_n10g_otnt_wrpcfg4;
  TEN_N10G_OTNR_ODWCFG_t tmp_otnr_odwcfg;
  TEN_N10G_OTNT_GMPCFG1_t tmp_n10g_otnt_gmpcfg1;
  TEN_N10G_OGMPR_GMPODWCFG_t tmp_n10g_ogmpr_gmpodwcfg;
  TEN_N10G_OOHR_GENDWNLFSF_t tmp_n10g_oohr_gendwnlfsf;
  T41_t *pDev = NULL;

  cs_uint16 Cm;
  cs_uint16 jcen_dt = 0;
  cs_uint16 jcen_otu2 = 0;
  cs_uint16 jc_plus_otu2 = 0;
  cs_uint16 jcen_odtu23 = 0;
  cs_uint16 jc_plus_odtu23 = 0;
  cs_uint16 dwmod = 3;  /* Dewrapper enabled Justification commands are evaluated */
  cs_uint16 wrmd2 = 0;   /* Mode of operation for OxU2 Wrapper Defaulted to WRMD */
  cs_uint16 dwmod2 = 0;  /* Mode of operation for OxU2 DeWrapper Defaulted to DWMOD */
  cs_uint16 linkalm_jcnom = 1;  /* Dewrapper will disable justifications and interpret all frames as having nominal JC when a signal fail alarm is detected in the OTN Link/Frame layer. */
  cs_uint16 gensf_lof = 0;
  cs_status rtn = CS_OK;
  cs_char8 *func = "ten_n10g_mux_mapper_t41";  

  TEN_MOD_COMMON_VALIDATE (module_id, pDev, CS_ERROR);
  dev_id = TEN_MOD_ID_TO_DEV_ID (module_id);
  pdevcb = TEN_DEV_ID_TO_DEVCB_PTR(dev_id);
  psyncdsync_cb = &pdevcb->syncdsync_thread_cb[slice];

  CS_PRINT("%s()\n", func);
  CS_PRINT("    line (%s, %s, %s)\n", ten_module_strings[module_id&1], ten_slice_strings[slice], ten_hl_config_traffic_types_strings[mapper]);
  CS_PRINT("    client %s\n", ten_hl_config_traffic_types_strings[client_traffic_type]);
  if (map_oxuv <= TEN_MAP_GMP_HO_DT) {           
    CS_PRINT("    %s\n", ten_sync_type_strings[map_oxuv]);
  }
  else {
    CS_PRINT("    map_oxuv = %d\n", map_oxuv);
  }
  if (map_odtu <= TEN_MAP_GMP_HO_DT) {           
    CS_PRINT("    %s\n", ten_sync_type_strings[map_odtu]);
  }
  else {
    CS_PRINT("    map_odtu = %d\n", map_odtu);
  }
  CS_PRINT("    timeslots = %x\n", timeslots);
  CS_PRINT("    gmp_timeslot_mask = %x\n", gmp_timeslot_mask);

  if (!pdevcb) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, "pDev is null.");
    return (CS_ERROR);
  }

  /* Take care of first level (Low Order)of mapping  (client into ODU2v) */
  if (map_oxuv == TEN_MAP_BMP) {
    dwmod = 1;   /* Dewrapper enabled Justification commands are ignored */

  }
  else if (map_oxuv == TEN_MAP_AMP) {
    jcen_otu2 = 1;
  }
  else if (map_oxuv == TEN_MAP_AMP_PROP) {
    jcen_otu2 = 1;
    jc_plus_otu2 = 1;
  }
  else if (map_oxuv == TEN_MAP_GMP_LO) {
    wrmd2 = 2;  /* Mode of operation for OxU2 Wrapper is LO OXU on */
	dwmod2 = 2;  /* Mode of operation for OxU2 DeWrapper is LO OXU on */
	jcen_otu2 = 1;
    /*jc_plus_otu2 = 1;*/
	
    Cm = (cs_uint16) (pdevcb->syncdsync_thread_cb[slice].cn_bytes_n10g / timeslots);  /*Bugzilla 26308*/
    rtn |= ten_n10g_tx_gmp_cm_cn_t41( module_id, slice, Cm, /* cm, cn bit 16, cn 0-15 */ 
                                      (cs_uint16)(pdevcb->syncdsync_thread_cb[slice].cn_bytes_n10g) & 0xffff,
                                      (cs_uint16)(pdevcb->syncdsync_thread_cb[slice].cn_bytes_n10g)>>16);      /*Bugzilla 36501*/
    rtn |= ten_n10g_rx_gmp_cn_t41( module_id, slice, 
                                  (cs_uint16) (pdevcb->syncdsync_thread_cb[slice].cn_bytes_n10g) & 0xffff,
                                  (cs_uint16) (pdevcb->syncdsync_thread_cb[slice].cn_bytes_n10g)>>16);  /* cn bit 16, cn 0-15, Bugzilla
				  36501 */
  }
  else if (map_oxuv == TEN_MAP_GMP_HO) {   /* Bugzilla 29100 */
    jcen_otu2 = 1;
    wrmd2 = 3;  /* Mode of operation for OxU2 Wrapper is HO OXU on */
	dwmod2 = 3;  /* Mode of operation for OxU2 DeWrapper is HO OXU on */  /* Bugzilla 29100 */
  }

  /* Take care of second level (High Order) of mapping  (ODU2v into ODTU23 or ODTU3e.st) */
  if ((map_odtu == TEN_MAP_AMP_DT) || (map_odtu == TEN_MAP_AMP_PROP_DT) ||
      (map_odtu == TEN_MAP_GMP_HO_DT)) {
    /* Enable Deterministic Justification */
    jcen_dt = 1;
  } 
  else if (map_odtu == TEN_MAP_GMP_HO) {
    jcen_odtu23 = 1;
  }
  
  else if (map_odtu == TEN_MAP_AMP) {
    jcen_odtu23 = 1;
  }
  else if (map_odtu == TEN_MAP_AMP_PROP) {
    jcen_odtu23 = 1;
    jc_plus_odtu23 = 1;
  } else {
    dwmod = 1;   /* Dewrapper enabled Justification commands are ignored */
  }

  TEN_MOD_LOCK(module_id, TEN_ID_N10G);

  tmp_n10g_otnt_wrpcfg4.wrd = TEN_REG_READ(TEN_N10G_REG_ADDR(pDev, module_id, slice, WRPCFG4));
  tmp_n10g_otnt_wrpcfg4.bf.JCEN_OTU2 = jcen_otu2;
  tmp_n10g_otnt_wrpcfg4.bf.JC_PLUS_OTU2 = jc_plus_otu2;
  tmp_n10g_otnt_wrpcfg4.bf.JCEN_DT = jcen_dt;
  tmp_n10g_otnt_wrpcfg4.bf.JCEN_ODTU23 = jcen_odtu23;
  tmp_n10g_otnt_wrpcfg4.bf.JC_PLUS_ODTU23 = jc_plus_odtu23;
  TEN_REG_WRITE(TEN_N10G_REG_ADDR(pDev, module_id, slice, WRPCFG4), tmp_n10g_otnt_wrpcfg4.wrd);

  tmp_otnr_odwcfg.wrd = TEN_REG_READ(TEN_N10G_REG_ADDR(pDev, module_id, slice, ODWCFG));
  tmp_otnr_odwcfg.bf.DWMOD = dwmod;
  tmp_otnr_odwcfg.bf.LINKALM_JCNOM = linkalm_jcnom;
  TEN_REG_WRITE(TEN_N10G_REG_ADDR(pDev, module_id, slice, ODWCFG), tmp_otnr_odwcfg.wrd);

  tmp_n10g_otnt_gmpcfg1.wrd = TEN_REG_READ(TEN_N10G_REG_ADDR(pDev, module_id, slice, GMPCFG1));
  tmp_n10g_otnt_gmpcfg1.bf.WRMD2 = wrmd2;
  TEN_REG_WRITE(TEN_N10G_REG_ADDR(pDev, module_id, slice, GMPCFG1), tmp_n10g_otnt_gmpcfg1.wrd);

  tmp_n10g_ogmpr_gmpodwcfg.wrd = TEN_REG_READ(TEN_N10G_REG_ADDR(pDev, module_id, slice, GMPODWCFG));
  tmp_n10g_ogmpr_gmpodwcfg.bf.DWMOD2 = dwmod2;
  TEN_REG_WRITE(TEN_N10G_REG_ADDR(pDev, module_id, slice, GMPODWCFG), tmp_n10g_ogmpr_gmpodwcfg.wrd);

  tmp_n10g_oohr_gendwnlfsf.wrd = TEN_REG_READ(TEN_XML_N10G_OOHR_REG_ADDR(pDev, module_id, slice, oohr_GENDWNLFSF));
  tmp_n10g_oohr_gendwnlfsf.bf.GENSF_LOF = gensf_lof;
  TEN_REG_WRITE(TEN_XML_N10G_OOHR_REG_ADDR(pDev, module_id, slice, oohr_GENDWNLFSF), tmp_n10g_oohr_gendwnlfsf.wrd);

  TEN_MOD_UNLOCK(module_id, TEN_ID_N10G);

  return (rtn);
}
/* Bugzilla 28237 End */


/* Bugzilla 32145 Start */
/****************************************************************/
/* $rtn_hdr_start  N10G CONFIG                                  */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : HIGH LEVEL                                      */
/* CHIP       : Tenabo                                          */
cs_status ten_n10g_gmp_off_t41 (cs_uint16 module_id, 
                                   cs_uint16 slice)
/* DESCRIPTION:                                                 */
/* Configures the N40G for the given muxponder mapper.          */
/* INPUTS     : o Module Id                                     */
/*              o Line Slice                                    */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* Set N10G_OGMPR_GMPODWCFG.DWMOD2 and N10G_OTNT_GMPCFG1.WRMD2  */
/* to default settings of zero.                                 */
/*                                                              */
/* [module_id] parameter specifies line's module ID             */
/* 16 devices can be registered and module bit indicates line   */
/* or client side of the registered device. The registered      */ 
/* device is identified by the dev_id bits specified below      */
/*   Bits 11:8 – dev_id, Bits 7:1 – don’t care, Bit 0 – module  */ 
/*                                                              */
/* [slice] parameter specifies line's slice:                    */
/*   0x00 = TEN_SLICE0                                          */
/*   0x01 = TEN_SLICE1                                          */
/*   0x02 = TEN_SLICE2                                          */
/*   0x03 = TEN_SLICE3                                          */
/*   0xFF = TEN_SLICE_ALL                                       */
/*                                                              */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/ 
{
  cs_uint8 sl;
  TEN_N10G_OTNT_GMPCFG1_t tmp_n10g_otnt_gmpcfg1;
  TEN_N10G_OGMPR_GMPODWCFG_t tmp_n10g_ogmpr_gmpodwcfg;
  T41_t *pDev = NULL;

  cs_uint16 dwmod2 = 0;
  cs_uint16 wrmd2 = 0;
  cs_status rtn = CS_OK;
  cs_char8 *func = "ten_n10g_gmp_off_t41";  

  TEN_MOD_COMMON_VALIDATE (module_id, pDev, CS_ERROR);

  CS_PRINT("%s()\n", func);
  CS_PRINT("    line (%s, %s)\n", ten_module_strings[module_id&1], ten_slice_strings[slice]);

  if ((slice >= TEN_MAX_SLICES) && (slice != TEN_SLICE_ALL)) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, "%s() slice out of range.  s/b 0..3.", func);
    return(CS_ERROR);
  }
  TEN_MOD_LOCK(module_id, TEN_ID_N10G);

  for (sl=0; sl<TEN_MAX_SLICES; sl++) {
    if ((slice == sl) || (slice == TEN_SLICE_ALL)) {
      tmp_n10g_otnt_gmpcfg1.wrd = TEN_REG_READ(TEN_N10G_REG_ADDR(pDev, module_id, sl, GMPCFG1));
      tmp_n10g_otnt_gmpcfg1.bf.WRMD2 = wrmd2;
      TEN_REG_WRITE(TEN_N10G_REG_ADDR(pDev, module_id, sl, GMPCFG1), tmp_n10g_otnt_gmpcfg1.wrd);

      tmp_n10g_ogmpr_gmpodwcfg.wrd = TEN_REG_READ(TEN_N10G_REG_ADDR(pDev, module_id, sl, GMPODWCFG));
      tmp_n10g_ogmpr_gmpodwcfg.bf.DWMOD2 = dwmod2;
      TEN_REG_WRITE(TEN_N10G_REG_ADDR(pDev, module_id, sl, GMPODWCFG), tmp_n10g_ogmpr_gmpodwcfg.wrd);
    }
  }
  TEN_MOD_UNLOCK(module_id, TEN_ID_N10G);

  return (rtn);
}
/* Bugzilla 32145 End */


/* Bugzilla 24360 Start */
/****************************************************************/
/* $rtn_hdr_start  N10G CONFIG                                  */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : HIGH LEVEL                                      */
/* CHIP       : Tenabo                                          */
cs_status ten_hl_n10g_config_t41(cs_uint16 module_id,
                                 cs_uint16 slice,
                                 cs_uint16 dyn_repro,
                                 cs_uint16 client,
                                 cs_uint16 mapper,
                                 cs_uint16 fec,
                                 cs_uint16 map_oxuv,
                                 cs_uint16 map_odtu,
                                 cs_uint16 timeslots,
                                 cs_uint16 gmp_timeslot_mask,
                                 cs_uint16 term_type,
                                 cs_uint16 tcm_bits)
/* INPUTS     : o Module Id                                     */
/*              o Slice                                         */
/*              o Client Type                                   */
/*              o Mapper Type                                   */
/*              o Mapping Method OxU2v                          */
/*              o Mapping Method ODTv                           */
/*              o Timeslots                                     */
/*              o GMP Timeslot Mask                             */
/*              o Termination Type                              */
/*              o TCM bits                                      */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* Configures an N10G transmit/receive path.                    */
/*                                                              */
/* [module_id] parameter specifies line's module ID             */
/* 16 devices can be registered and module bit indicates line   */
/* or client side of the registered device. The registered      */
/* device is identified by the dev_id bits specified below      */
/*   Bits 11:8 - dev_id, Bits 7:1 - don't care, Bit 0 - module  */
/*                                                              */
/* [slice] parameter specifies the slice:                       */
/*   TEN_SLICE0 = 0                                             */
/*   TEN_SLICE1 = 1                                             */
/*   TEN_SLICE2 = 2                                             */
/*   TEN_SLICE3 = 3                                             */
/*                                                              */
/* [client] parameter specifies the traffic type of the client: */
/*   TEN_TRAFFIC_TYPE_NONE                 = 0                  */
/*   TEN_TRAFFIC_TYPE_OTU2                 = 5                  */
/*   TEN_TRAFFIC_TYPE_OTU2E                = 6                  */
/*   TEN_TRAFFIC_TYPE_OTU1F                = 7                  */
/*   TEN_TRAFFIC_TYPE_OC192                = 8                  */
/*   TEN_TRAFFIC_TYPE_10GE_WAN             = 9                  */
/*   TEN_TRAFFIC_TYPE_10GE_6_2             = 10                 */
/*   TEN_TRAFFIC_TYPE_10GE_7_1             = 11                 */
/*   TEN_TRAFFIC_TYPE_10GE_7_3             = 12                 */
/*   TEN_TRAFFIC_TYPE_10GFC                = 13                 */
/*   TEN_TRAFFIC_TYPE_8GFC                 = 14                 */
/*   TEN_TRAFFIC_TYPE_4GFC                 = 15                 */
/*   TEN_TRAFFIC_TYPE_2GFC                 = 16                 */
/*   TEN_TRAFFIC_TYPE_1GFC                 = 17                 */
/*   TEN_TRAFFIC_TYPE_5GB_IB               = 18                 */
/*   TEN_TRAFFIC_TYPE_10GE                 = 20                 */
/*   TEN_TRAFFIC_TYPE_10GE_6_1             = 26                 */
/*   TEN_TRAFFIC_TYPE_10GE_7_2             = 27                 */
/*   TEN_TRAFFIC_TYPE_10GE_GFPF_OC192_ODU2 = 28                 */
/*   TEN_TRAFFIC_TYPE_OTU1E                = 29                 */
/*   TEN_TRAFFIC_TYPE_10GE_RA              = 30                 */
/*   TEN_TRAFFIC_TYPE_OTU2F                = 33                 */
/*   TEN_TRAFFIC_TYPE_OTU2P                = 35                 */
/*   TEN_TRAFFIC_TYPE_ODUFLEX              = 36                 */
/*   TEN_TRAFFIC_TYPE_10G_IB               = 38                 */
/*   TEN_TRAFFIC_TYPE_12_5G_IB             = 39                 */
/*   TEN_TRAFFIC_TYPE_10GFC_TC             = 46                 */
/*   TEN_TRAFFIC_TYPE_8GFC_RA              = 47                 */
/*   TEN_TRAFFIC_TYPE_4GFC_RA              = 48                 */
/*   TEN_TRAFFIC_TYPE_2GFC_RA              = 49                 */
/*   TEN_TRAFFIC_TYPE_1GFC_RA              = 50                 */
/*   TEN_TRAFFIC_TYPE_8GFC_ENH             = 51                 */
/*   TEN_TRAFFIC_TYPE_4GFC_ENH             = 52                 */
/*   TEN_TRAFFIC_TYPE_2GFC_ENH             = 53                 */
/*   TEN_TRAFFIC_TYPE_1GFC_ENH             = 54                 */
/*   TEN_TRAFFIC_TYPE_10GE_GFPF            = 56                 */
/*   TEN_TRAFFIC_TYPE_10GFC_STD            = 57                 */
/*   TEN_TRAFFIC_TYPE_10GFC_TC_RA          = 58                 */
/*   TEN_TRAFFIC_TYPE_2GISC                = 59                 */
/*   TEN_TRAFFIC_TYPE_1GE                  = 63                 */
/*   TEN_TRAFFIC_TYPE_FDR10_IB             = 64                 */
/*                                                              */
/* [mapper] parameter specifies the traffic type of the line:   */
/*   TEN_TRAFFIC_TYPE_NONE                 = 0                  */
/*   TEN_TRAFFIC_TYPE_OTU2                 = 5                  */
/*   TEN_TRAFFIC_TYPE_OTU2E                = 6                  */
/*   TEN_TRAFFIC_TYPE_OC192                = 8                  */
/*   TEN_TRAFFIC_TYPE_10GE_WAN             = 9                  */
/*   TEN_TRAFFIC_TYPE_10GE_6_2             = 10                 */
/*   TEN_TRAFFIC_TYPE_10GE_7_1             = 11                 */
/*   TEN_TRAFFIC_TYPE_10GE_7_3             = 12                 */
/*   TEN_TRAFFIC_TYPE_10GFC                = 13                 */
/*   TEN_TRAFFIC_TYPE_8GFC                 = 14                 */
/*   TEN_TRAFFIC_TYPE_4GFC                 = 15                 */
/*   TEN_TRAFFIC_TYPE_2GFC                 = 16                 */
/*   TEN_TRAFFIC_TYPE_1GFC                 = 17                 */
/*   TEN_TRAFFIC_TYPE_10GE                 = 20                 */
/*   TEN_TRAFFIC_TYPE_10GE_6_1             = 26                 */
/*   TEN_TRAFFIC_TYPE_10GE_7_2             = 27                 */
/*   TEN_TRAFFIC_TYPE_10GE_GFPF_OC192_ODU2 = 28                 */
/*   TEN_TRAFFIC_TYPE_OTU1E                = 29                 */
/*   TEN_TRAFFIC_TYPE_10GE_RA              = 30                 */
/*   TEN_TRAFFIC_TYPE_OTU2F                = 34                 */
/*   TEN_TRAFFIC_TYPE_OTU2P                = 36                 */
/*   TEN_TRAFFIC_TYPE_ODUFLEX              = 37                 */
/*   TEN_TRAFFIC_TYPE_ODTU                 = 38                 */
/*   TEN_TRAFFIC_TYPE_10G_IB               = 39                 */
/*   TEN_TRAFFIC_TYPE_12_5G_IB             = 40                 */
/*   TEN_TRAFFIC_TYPE_10GFC_TC             = 46                 */
/*   TEN_TRAFFIC_TYPE_8GFC_RA              = 47                 */
/*   TEN_TRAFFIC_TYPE_4GFC_RA              = 48                 */
/*   TEN_TRAFFIC_TYPE_2GFC_RA              = 49                 */
/*   TEN_TRAFFIC_TYPE_1GFC_RA              = 50                 */
/*   TEN_TRAFFIC_TYPE_8GFC_ENH             = 51                 */
/*   TEN_TRAFFIC_TYPE_4GFC_ENH             = 52                 */
/*   TEN_TRAFFIC_TYPE_2GFC_ENH             = 53                 */
/*   TEN_TRAFFIC_TYPE_1GFC_ENH             = 54                 */
/*   TEN_TRAFFIC_TYPE_10GE_GFPF            = 56                 */
/*   TEN_TRAFFIC_TYPE_10GFC_STD            = 57                 */
/*                                                              */
/* The [map_oxuv] parameter specifies the client mapping method */
/*   onto otu2v (for n10g)                                      */
/* See customer docs for valid mapping combinations.            */
/*   TEN_MAP_BMP          = 1                                   */
/*   TEN_MAP_AMP          = 0                                   */
/*   TEN_MAP_AMP_PROP     = 3 (See also syncdsync CB!)          */
/*   TEN_MAP_GMP_LO       = 5 (See also syncdsync CB!)(T41)     */
/*   TEN_MAP_GMP_HO       = 6 (Infiniband, see CB!)   (T41)     */
/*   TEN_MAP_DONT_CARE    = 0xFF                                */
/*                                                              */
/* The [map_odtu] parameter specifies the line mapping method   */
/*    onto odtu.                                                */
/* See customer docs for valid mapping combinations.            */
/*   TEN_MAP_AMP          = 0                                   */
/*   TEN_MAP_AMP_PROP     = 3 (See also syncdsync CB!)          */
/*   TEN_MAP_AMP_DT       = 2                                   */
/*   TEN_MAP_GMP_HO       = 6     (T41)                         */
/*   TEN_MAP_GMP_HO_DT    = 7     (T41)                         */
/*   TEN_MAP_DONT_CARE    = 0xFF                                */
/*                                                              */
/* The [timeslots] parameter specifies number of timeslots.     */
/* Bandwidth for map_proc = GMP_HO is always 1.25G per timeslot.*/
/*   timeslots = 1 - 8                                          */
/* Bandwidth for map_proc = AMP or AMP_DT is as follows:        */
/*   timeslots = 4 for 2.5G per timeslot                        */
/*   timeslots = 8 for 1.25G per timeslot                       */
/* Bandwidth for all other map_proc is 2.5G so timeslots = 4    */
/*                                                              */
/* The [gmp_timeslot_mask] parameter specifies the timeslots to */
/* use for GMP mapping. Applicable to GMP_HO only.              */
/*   Bit 0- Timeslot 1 through Bit 7 - Timeslot 8               */
/*                                                              */
/* The [term_type] parameter specifies the termination type     */
/*   TEN_OC192_TERM_TRANSPARENT_CBR10       = 1                 */
/*   TEN_OC192_TERM_TRANSPARENT_REGENERATOR = 2                 */
/*   TEN_OC192_TERM_RS_LAYER_REGENERATOR    = 3                 */
/*   TEN_OC192_TERM_MS_LAYER_REGENERATOR    = 4                 */
/*   TEN_OTU_TERM_TRANSPARENT = 0                               */
/*   TEN_OTU_TERM_SECTION     = 1                               */
/*                                                              */
/* The [tcm_bits] parameter specifies the termination for TCM 1 */
/* through 6.  This is a bit encoded parameter with bits 1      */
/* through 6 specifying TCM 1 through 6 respectively.           */
/* These bits are defined as follows:                           */
/*   disable = 0                                                */
/*   enable  = 1                                                */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  ten_dev_cb_t *pdevcb;
  cs_uint16 Cm;   /*Bugzilla 26308*/
  cs_uint16 Cn_hi;
  cs_uint16 Cn_lo;
  ten_syncdsync_cb_t *psyncdsync_cb;
  cs_status rtn = CS_OK;
  cs_uint16 dev_id = TEN_MOD_ID_TO_DEV_ID (module_id);
  cs_char8 *func = "ten_hl_n10g_config_t41";
  cs_boolean isT41 = ten_dev_is_t41(dev_id);
  TEN_N10G_VALIDATE(module_id, slice);
  pdevcb = TEN_DEV_ID_TO_DEVCB_PTR(dev_id);

  CS_PRINT("%s()\n", func);
  CS_PRINT("    %s\n", ten_module_strings[module_id & 1]);
  CS_PRINT("    %s\n", ten_slice_strings[slice]);
  CS_PRINT("    %s\n", ten_hl_config_dyn_repro_strings[dyn_repro]);
  CS_PRINT("    %s\n", ten_hl_config_traffic_types_strings[client]);
  CS_PRINT("    %s\n", ten_hl_config_traffic_types_strings[mapper]);
  CS_PRINT("    %s\n", ten_fec_ovhd_strings[fec]);
  if (map_odtu <= TEN_MAP_GMP_HO_DT) {           
    CS_PRINT("    map_odtu = %s\n", ten_sync_type_strings[map_odtu]);
  }
  else {
    CS_PRINT("    map_odtu = %d\n", map_odtu);
  }
  if (map_oxuv <= TEN_MAP_GMP_HO_DT) {           
    CS_PRINT("    map_oxuv = %s\n", ten_sync_type_strings[map_oxuv]);
  }
  else {
    CS_PRINT("    map_oxuv = %d\n", map_oxuv);
  }
  CS_PRINT("    timeslots=%d\n", timeslots);
  CS_PRINT("    gmp_timeslot_mask=0x%04X\n", gmp_timeslot_mask);
  CS_PRINT("    %s\n", ten_hl_config_otu_overhead_term_strings[term_type]);
  CS_PRINT("    tcm_bits=0x%X\n", tcm_bits);
  

  /* Range-check map_oxuv mapping arguments according to chip type*/
  if ( ( map_oxuv == TEN_MAP_BMP)       || ( map_oxuv == TEN_MAP_AMP)        || ( map_oxuv == TEN_MAP_AMP_PROP)
     ||( map_oxuv == TEN_MAP_DONT_CARE) ) {
  }
  else if ( (isT41) &&( ( map_oxuv == TEN_MAP_GMP_LO) || ( map_oxuv == TEN_MAP_GMP_HO) ) ) {
  }
  else {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, "%s: %s, Client %d->Line %d, map_oxuv=%d not supported\n", func, (isT41)?"T41":"T40", client, mapper, map_oxuv);
    return (CS_ERROR);                            /* <<<<<<<<<<<<<<<<<<<<<<< EARLY EXIT <<<<<<<<<<<<<<<<<<*/
  }

  /* Range-check map_odtu mapping arguments according to chip type*/
  if ( ( map_odtu == TEN_MAP_AMP) || ( map_odtu == TEN_MAP_AMP_PROP)    || ( map_odtu == TEN_MAP_AMP_DT) || ( map_odtu == TEN_MAP_AMP_PROP_DT)
     ||( map_odtu == TEN_MAP_BMP) || ( map_odtu == TEN_MAP_DONT_CARE) ) {
  }
  else if ( (isT41) && ( ( map_odtu == TEN_MAP_GMP_HO) || ( map_odtu == TEN_MAP_GMP_HO_DT) ) ) {
  }
  else {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, "%s: %s, Client %d->Line %d, map_odtu=%d not supported\n", func, ((isT41)?"T41":"T40"), client, mapper, map_odtu);
    return (CS_ERROR);                            /* <<<<<<<<<<<<<<<<<<<<<<< EARLY EXIT <<<<<<<<<<<<<<<<<<*/
  }


  /* Begin n10g configuration */

  /* Check for easy client-side configs first, exit early for these */
  if ( ((client == TEN_TRAFFIC_TYPE_10GE_7_3) && (mapper == TEN_TRAFFIC_TYPE_10GE_7_3)) ||
       ((client == TEN_TRAFFIC_TYPE_10GE_7_1) && (mapper == TEN_TRAFFIC_TYPE_10GE_7_1)) ||
       ((client == TEN_TRAFFIC_TYPE_10GE_7_2) && (mapper == TEN_TRAFFIC_TYPE_10GE_7_2)) ||
       ((client == TEN_TRAFFIC_TYPE_10GE_6_2) && (mapper == TEN_TRAFFIC_TYPE_10GE_6_2)) ||
       ((client == TEN_TRAFFIC_TYPE_10GE_RA)  && (mapper == TEN_TRAFFIC_TYPE_10GE_RA)) ||
       ((client == TEN_TRAFFIC_TYPE_10GE_GFPF_OC192_ODU2) && (mapper == TEN_TRAFFIC_TYPE_10GE_GFPF_OC192_ODU2)) ||
       ((client == TEN_TRAFFIC_TYPE_10GE_TC)  && (mapper == TEN_TRAFFIC_TYPE_10GE_TC)) ||
       ((client == TEN_TRAFFIC_TYPE_10GFC)    && (mapper == TEN_TRAFFIC_TYPE_10GFC)) ||
       ((client == TEN_TRAFFIC_TYPE_10GFC_TC) && (mapper == TEN_TRAFFIC_TYPE_10GFC_TC)) ||
       ((client == TEN_TRAFFIC_TYPE_10GFC_TC_G709) && (mapper == TEN_TRAFFIC_TYPE_10GFC_TC_G709)) || /* Bug 31054 */
       ((client == TEN_TRAFFIC_TYPE_10GFC_TC_RA)   && (mapper == TEN_TRAFFIC_TYPE_10GFC_TC_RA)) ||
       ((client == TEN_TRAFFIC_TYPE_8GFC)     && (mapper == TEN_TRAFFIC_TYPE_8GFC)) ||
       ((client == TEN_TRAFFIC_TYPE_4GFC)     && (mapper == TEN_TRAFFIC_TYPE_4GFC)) ||
       ((client == TEN_TRAFFIC_TYPE_2GFC)     && (mapper == TEN_TRAFFIC_TYPE_2GFC)) ||
       ((client == TEN_TRAFFIC_TYPE_1GFC)     && (mapper == TEN_TRAFFIC_TYPE_1GFC)) || /* Bugzilla 38871 */
       ((client == TEN_TRAFFIC_TYPE_1GE)      && (mapper == TEN_TRAFFIC_TYPE_1GE)) ||  /* Bugzilla 38871 */
       ((client == TEN_TRAFFIC_TYPE_2GISC)    && (mapper == TEN_TRAFFIC_TYPE_2GISC)) ||
       ((client == TEN_TRAFFIC_TYPE_8GFC_ENH) && (mapper == TEN_TRAFFIC_TYPE_8GFC_ENH)) ||
       ((client == TEN_TRAFFIC_TYPE_4GFC_ENH) && (mapper == TEN_TRAFFIC_TYPE_4GFC_ENH)) ||
       ((client == TEN_TRAFFIC_TYPE_2GFC_ENH) && (mapper == TEN_TRAFFIC_TYPE_2GFC_ENH)) ||
       ((client == TEN_TRAFFIC_TYPE_1GFC_ENH) && (mapper == TEN_TRAFFIC_TYPE_1GFC_ENH)) ||
       ((client == TEN_TRAFFIC_TYPE_10GE_6_1) && (mapper == TEN_TRAFFIC_TYPE_10GE_6_1)) ||
       ((client == TEN_TRAFFIC_TYPE_10GE_GFPF) && (mapper == TEN_TRAFFIC_TYPE_10GE_GFPF)) ||     /* Bugzilla 29991 */
       ((client == TEN_TRAFFIC_TYPE_ODUFLEX)  && (mapper == TEN_TRAFFIC_TYPE_ODUFLEX)) ||  /* No bugzilla. Adds framework for ODUFLEX support */
       ((client == TEN_TRAFFIC_TYPE_5GB_IB)   && (mapper == TEN_TRAFFIC_TYPE_5GB_IB)) ||
       ((client == TEN_TRAFFIC_TYPE_10G_IB)   && (mapper == TEN_TRAFFIC_TYPE_10G_IB)) ||
       ((client == TEN_TRAFFIC_TYPE_FDR10_IB) && (mapper == TEN_TRAFFIC_TYPE_FDR10_IB)) ) { /* Bugzilla 39242 */
    /* Client side 10G Transponder or 10GE Muxponder */
    rtn |= ten_hl_n10g_config (module_id, slice, TEN_N10G_RX_BYPASS, TEN_N10G_TX_BYPASS, dyn_repro);
 
    if (rtn != CS_OK) {
      CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, "%s()  FAILED!\n", func);
    }
    return (rtn);     /* Early but normal exit */
  }

  switch (client) {
    case TEN_TRAFFIC_TYPE_OC192 :  /* client */
      switch (mapper) {

        /* OC192->OTU2 */
        /* Bug #38686:  Add support for OC192 (10GE WAN) into OTU2E and OTU21E */
        case TEN_TRAFFIC_TYPE_OTU1E:
        case TEN_TRAFFIC_TYPE_OTU2E:
        case TEN_TRAFFIC_TYPE_OTU2:
          /* Line side 10G Transponder */
          if ((mapper == TEN_TRAFFIC_TYPE_OTU2E) || (mapper == TEN_TRAFFIC_TYPE_OTU1E)) {
            rtn |= ten_hl_n10g_config(module_id, slice, TEN_N10G_RX_OTU2EJ_OC192, TEN_N10G_TX_OC192_OTU2EJ, dyn_repro);
            if (mapper == TEN_TRAFFIC_TYPE_OTU1E) {
              /* fixed stuff is different for OTU1E than from table OTU2EJ_OC192/Oc192_OTU2EJ column, so override it */
              rtn |= ten_n10g_set_otnr_odwfs(module_id, slice, 531);
              rtn |= ten_n10g_otnt_set_wrpfs(module_id, slice, 531);
            }
          }
          else {
            rtn |= ten_hl_n10g_config(module_id, slice, TEN_N10G_RX_OTU2_OC192, TEN_N10G_TX_OC192_OTU2, dyn_repro);
          }
          
          if (rtn != CS_OK) {
            return (rtn); /* EARLY EXIT ON FAILURE up to calling function to report error */
          }

          /* Should be done by FEC code */
          /*ten_n10g_otnt_scrambling (module_id_line, slice_line, 0, 1);*/
          /*ten_n10g_otnr_descrambling (module_id_line, slice_line, 1, 0);*/

          /* Clear the ODU2 OCI that the null config set up */
          /* Bug #39241 - Signal conditioning should not be done by T41 datapath configuration APIs */
          #if (TEN_HL_OHPP_DISABLE_ODUK_OCI == 1) 
          rtn |= ten_hl_ohpp_control_oduk_oci (module_id, slice, CS_DISABLE);
          #endif

          rtn |= ten_hl_n10g_config_lom_from_traffic (module_id, slice, mapper, fec);

          /* Set up the OC192 Termination */
          rtn |= ten_hl_oc192_termination_path_line_side(module_id, slice, term_type);
          ten_n10g_tx_trans_term_line_bypass(module_id, slice, term_type);
          rtn |= ten_n10g_gblr_set_kpasel(module_id, slice, 0);  /* KPA input from SDH Payload*/
          /*rtn |= ten_n10g_gblr_set_kpasel(module_id, slice, 1);*/  /* KPA input from OxU2 Payload*/

          switch (map_oxuv) {
            case TEN_MAP_BMP :
            case TEN_MAP_DONT_CARE :
              rtn |= ten_n10g_set_otnt_wrpcfg4 (module_id, slice, 0, 0, 0, 0, 0); /* jc_plus_odtu23, jc_plus_otu2, jcen_dt, jcen_odtu23 and jcen_otu2 */
              rtn |= ten_n10g_otnr_set_dwmod (module_id, slice, 1);               /* Dewrapper enabled Justification commands are ignored */
              break;
            case TEN_MAP_AMP :
                rtn |= ten_n10g_set_otnt_wrpcfg4 (module_id, slice, 0, 0, 0, 0, 1); /* jc_plus_odtu23, jc_plus_otu2, jcen_dt, jcen_odtu23 and jcen_otu2 */
                rtn |= ten_n10g_otnr_set_dwmod (module_id, slice, 3);               /* Dewrapper enabled Justification commands are evaluated */
              break;
            case TEN_MAP_AMP_PROP :
              rtn |= ten_n10g_set_otnt_wrpcfg4 (module_id, slice, 0, 1, 0, 0, 1); /* jc_plus_odtu23, jc_plus_otu2, jcen_dt, jcen_odtu23 and jcen_otu2 */
              rtn |= ten_n10g_tx_amp_prop_t41( module_id, slice, 0); /* hardcode to 0 since 0c192 client fits. For FC use pdevcb->syncdsync_thread_cb[slice].num_just_oxu2); */
              rtn |= ten_n10g_otnr_set_dwmod ( module_id, slice, 3);              /* Dewrapper enabled Justification commands are evaluated */
              rtn |= ten_n10g_rx_amp_prop_t41( module_id, slice, 0); /* hardcode to 0 since 0c192 client fits. For FC use pdevcb->syncdsync_thread_cb[slice].num_just_oxu2); */
              break;
            default :
              CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, "%s: OC192->OTU2, map_oxuv=%d not supported\n", func, map_oxuv);
              rtn |= CS_ERROR;
              break;
          }
          if (rtn != CS_OK) return (rtn); /* <<<<<<<<<<<<<<<  EARLY EXIT ON FAILURE <<<<<<<up to calling function to report error */
          break;

        /* OC192->OC192 */
        case TEN_TRAFFIC_TYPE_OC192 :
          /* Client side 10G Transponder or OC192 Muxponder */
          rtn |= ten_hl_n10g_config (module_id, slice, TEN_N10G_RX_OC192_OC192, TEN_N10G_TX_OC192_OC192PT, dyn_repro);

          /* Set up the OC192 Termination */
          rtn |= ten_hl_oc192_termination_path_client_side(module_id, slice, term_type);
          
          /* Bugzilla 37671 */
          /* SONET in transparent mode needs to keep OTN clock on to generate CBRGenAIS */
          ten_n10g_set_gblt_otnoff( module_id, slice, 0);
          ten_n10g_set_pn11auto(module_id, slice, 1);
          break;

        /* OC192->ODTU */
        case TEN_TRAFFIC_TYPE_ODTU :
          /* Muxponder Line side */
          rtn |= ten_hl_n10g_config (module_id, slice, TEN_N10G_RX_OXU3_OC192, TEN_N10G_TX_OC192_OXU3, dyn_repro);

          /* Line side OTU scrambling done in N40G block */
          rtn |= ten_n10g_otnt_scrambling (module_id, slice, 0, 0);   /* Turn off scramblers */
          rtn |= ten_n10g_otnr_descrambling (module_id, slice, 0, 0); /* Turn off descramblers */

          /* Clear the ODU2 OCI that the null config set up */
          /* Bug #39241 - Signal conditioning should not be done by T41 datapath configuration APIs */
          #if (TEN_HL_OHPP_DISABLE_ODUK_OCI == 1) 
          rtn |= ten_hl_ohpp_control_oduk_oci (module_id, slice, CS_DISABLE);
          #endif

          /* Bugzilla 37928 - Need to disable dLOS generation since ODU2 is unscrambled */
          rtn |= ten_n10g_gblr_loscfg0 (module_id, slice, 3);

          /*ten_hl_xcon_config(dev_id, (module_id_line & 1) * 4 + slice_line, (module_id_client & 1) * 4 + slice_client, TEN_TRAFFIC_TYPE_OC192); */

          rtn |= ten_hl_n10g_config_lom_from_traffic (module_id, slice, TEN_TRAFFIC_TYPE_OTU2, TEN_FEC_MODE_NOFEC);
          rtn |= ten_n10g_gblr_set_kpasel(module_id, slice, 0);  /* KPA input from SDH Payload*/
      
          rtn |= ten_hl_oc192_termination_path_line_side(module_id, slice, term_type);
          if (rtn != CS_OK) return (rtn); /* <<<<<<<<<<<<<<<  EARLY EXIT ON FAILURE <<<<<<<up to calling function to report error */

          /* process 1st-level mappings */
          switch (map_oxuv) {
            case TEN_MAP_AMP :
              /* Bugzilla # , Fix regression failures */
              rtn |= ten_n10g_set_otnt_wrpcfg4(module_id, slice, 0, 0, 0, 1, 1); /* jc_plus_odtu23, jc_plus_otu2, jcen_dt, jcen_odtu23 and jcen_otu2 */
              rtn |= ten_n10g_otnr_set_dwmod(module_id, slice, 3);               /* Dewrapper enabled Justification commands are evaluated */
              break;
            case TEN_MAP_BMP :
              /* Bugzilla 27969 part 1 start ( OC192 muxponder configs for GMP)                          */
              /* Have a first look at 2nd-level mappings. These are set somewhere else for map_odtu==AMP */
              if (map_odtu == TEN_MAP_GMP_HO) {
                rtn |= ten_n10g_otnr_set_dwmod(module_id, slice, 3);             /* Dewrapper enabled Justification commands are evaluated */
                /* The following belongs here but it's overwritten by 2nd-level mapping code             */
                /* ten_n10g_otnt_set_wrmd(module_id, slice, 1);                     Wrapper enabled      */
              }
              /* Bugzilla 27969 end */
              break;
            case TEN_MAP_GMP_LO:                                                                   /*Bugzilla 36905*/
              rtn |= ten_n10g_otnr_set_stm64md(module_id, slice, 0);
              rtn |= ten_n10g_otnt_set_stm64md(module_id, slice, 0);

              Cm    = (cs_uint16) (pdevcb->syncdsync_thread_cb[slice].cn_bytes_n10g / timeslots);  /*Bugzilla 26308*/
              Cn_hi = (cs_uint16) (pdevcb->syncdsync_thread_cb[slice].cn_bytes_n10g >> 16);
              Cn_lo = (cs_uint16) (pdevcb->syncdsync_thread_cb[slice].cn_bytes_n10g & 0x0000ffff);

              rtn |= ten_n10g_tx_gmp_lo_t41( module_id, slice );
              rtn |= ten_n10g_rx_gmp_lo_t41( module_id, slice );
              rtn |= ten_n10g_tx_gmp_cm_cn_t41( module_id, slice, Cm, Cn_lo, Cn_hi);
              rtn |= ten_n10g_rx_gmp_cn_t41( module_id, slice, Cn_lo, Cn_hi);
              break;
            case TEN_MAP_DONT_CARE :

              rtn |= ten_n10g_set_otnt_wrpcfg4 (module_id, slice, 0, 0, 0, 0, 0); /* jc_plus_odtu23, jc_plus_otu2, jcen_dt, jcen_odtu23 and jcen_otu2 */
              rtn |= ten_n10g_otnr_set_dwmod (module_id, slice, 1);               /* Dewrapper enabled Justification commands are ignored */
              break;
            default:
              CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, "%s() Unexpected map_oxuv %d for OC192->ODTU", func, map_oxuv);
              break;
          }
          if (rtn != CS_OK) return (rtn); /* <<<<<<<<<<<<<<<  EARLY EXIT ON FAILURE <<<<<<<up to calling function to report error */
          break;

        default :
          CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, "%s() Unexpected line type %d for OC192 client", func, mapper);
          return (CS_ERROR);              /* <<<<<<<<<<<<<<<  EARLY EXIT ON FAILURE <<<<<<<up to calling function to report error */
          break;
      }
      break;

    case TEN_TRAFFIC_TYPE_OTU1F :  /* client */
      switch (mapper) {

        /* OTU1F->OTU1F */
        case TEN_TRAFFIC_TYPE_OTU1F :
          /* Client or Line side 10G Transponder Client side OTU2 Muxponder */
          rtn |= ten_hl_n10g_config (module_id, slice, TEN_N10G_RX_OTU2E_ODU2E, TEN_N10G_TX_ODU2E_OTU2E, dyn_repro);
          /* Bug #39241 - Signal conditioning should not be done by T41 datapath configuration APIs */
          #if (TEN_HL_OHPP_DISABLE_ODUK_OCI == 1) 
          rtn |= ten_hl_ohpp_control_oduk_oci (module_id, slice, CS_DISABLE);
          #endif

          rtn |= ten_hl_n10g_config_lom_from_traffic (module_id, slice, client, fec);
          rtn |= ten_n10g_gblr_set_kpasel(module_id, slice, 1);  /* KPA input from OxU2 Payload*/
          break;
        default:
          CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, "%s() Unexpected line type %d for OTU1F client", func, mapper);
          return (CS_ERROR);              /* <<<<<<<<<<<<<<<  EARLY EXIT ON FAILURE <<<<<<<up to calling function to report error */
          break;
      }
      break;

      
    case TEN_TRAFFIC_TYPE_OTU2F :  /* client */
      switch (mapper) {

        /* OTU1F->OTU1F */
        case TEN_TRAFFIC_TYPE_OTU2F :
          /* Client or Line side 10G Transponder Client side OTU2 Muxponder */
          break;
        default:
          CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, "%s() Unexpected line type %d for OTU2F client", func, mapper);
          return (CS_ERROR);              /* <<<<<<<<<<<<<<<  EARLY EXIT ON FAILURE <<<<<<<up to calling function to report error */
          break;
      }
      break;

      
    case TEN_TRAFFIC_TYPE_OTU1E :  /* client */
      switch (mapper) {

        /* OTU1E->OTU1E */
        case TEN_TRAFFIC_TYPE_OTU1E :
          /* Client or Line side 10G Transponder Client side OTU2 Muxponder */
          /* Use same table entry as OTU2e */
          rtn |= ten_hl_n10g_config (module_id, slice, TEN_N10G_RX_OTU2E_ODU2E, TEN_N10G_TX_ODU2E_OTU2E, dyn_repro);

          /* Bug #39241 - Signal conditioning should not be done by T41 datapath configuration APIs */
          #if (TEN_HL_OHPP_DISABLE_ODUK_OCI == 1) 
          rtn |= ten_hl_ohpp_control_oduk_oci (module_id, slice, CS_DISABLE);
          #endif

          rtn |= ten_n10g_otnr_set_stm64md (module_id, slice, 0);
          rtn |= ten_n10g_otnt_set_stm64md (module_id, slice, 0);

          rtn |= ten_hl_n10g_config_lom_from_traffic (module_id, slice, client, fec);
          rtn |= ten_n10g_gblr_set_kpasel(module_id, slice, 1);  /* KPA input from OxU2 Payload*/

          /* Setup Termination Mode */
          rtn |= ten_hl_n10g_config_termination (module_id, slice, term_type, tcm_bits);
          break;


        /* OTU1E->ODTU */
        case TEN_TRAFFIC_TYPE_ODTU :
          /* Line side Muxponder */

          /* Use same table entery as OTU2e */
          rtn |= ten_hl_n10g_tx_init (module_id, slice, TEN_N10G_TX_ODU2_OXU3P);
          rtn |= ten_hl_n10g_rx_init (module_id, slice, TEN_N10G_RX_OXU3_ODU2P);

          rtn |= ten_n10g_otnt_scrambling (module_id, slice, 0, 0);   /* Turn off scramblers */
          rtn |= ten_n10g_otnr_descrambling (module_id, slice, 0, 0); /* Turn off scramblers */

          /* Bugzilla 37928 - Need to disable dLOS generation since ODU2 is unscrambled */
          rtn |= ten_n10g_gblr_loscfg0 (module_id, slice, 3);

          /* OTU1e has no fixed stuff */
          rtn |= ten_n10g_otnr_set_stm64md (module_id, slice, 0);
          rtn |= ten_n10g_otnt_set_stm64md (module_id, slice, 0);

          /* Bug #39241 - Signal conditioning should not be done by T41 datapath configuration APIs */
          #if (TEN_HL_OHPP_DISABLE_ODUK_OCI == 1) 
          rtn |= ten_hl_ohpp_control_oduk_oci (module_id, slice, CS_DISABLE);
          #endif

          /* Bug 37598 - ODU2 PM Bip-8 byte unexpectly terminated in OTU2e client mapped to ODTU */
          /* Clear the ODU2 OCI that the null config set up */
          rtn |= ten_hl_n10g_config_termination (module_id, slice, term_type, tcm_bits);

          rtn |= ten_hl_n10g_config_lom_from_traffic (module_id, slice, TEN_TRAFFIC_TYPE_OTU2E, TEN_FEC_MODE_NOFEC);
          rtn |= ten_n10g_gblr_set_kpasel(module_id, slice, 1);  /* KPA input from OxU2 Payload*/
          break;
      }
      break;

    case TEN_TRAFFIC_TYPE_OTU2E :  /* client */
      switch (mapper) {

        /* OTU2E->OTU2E */
        case TEN_TRAFFIC_TYPE_OTU2E :
          /* Client or Line side 10G Transponder Client side OTU2 Muxponder */
          rtn |= ten_hl_n10g_config (module_id, slice, TEN_N10G_RX_OTU2E_ODU2E, TEN_N10G_TX_ODU2E_OTU2E, dyn_repro);

          /* Bug #39241 - Signal conditioning should not be done by T41 datapath configuration APIs */
          #if (TEN_HL_OHPP_DISABLE_ODUK_OCI == 1) 
          rtn |= ten_hl_ohpp_control_oduk_oci (module_id, slice, CS_DISABLE);
          #endif

          rtn |= ten_hl_n10g_config_lom_from_traffic (module_id, slice, client, fec);
          rtn |= ten_n10g_gblr_set_kpasel(module_id, slice, 1);  /* KPA input from OxU2 Payload*/

          /* Setup Termination Mode */
          rtn |= ten_hl_n10g_config_termination (module_id, slice, term_type, tcm_bits);
          break;

        /* OTU2E->ODTU */
        case TEN_TRAFFIC_TYPE_ODTU :
          /* Line side Muxponder */
          rtn |= ten_hl_n10g_tx_init (module_id, slice, TEN_N10G_TX_ODU2_OXU3P);
          rtn |= ten_hl_n10g_rx_init (module_id, slice, TEN_N10G_RX_OXU3_ODU2P);

          rtn |= ten_n10g_otnt_scrambling (module_id, slice, 0, 0);   /* Turn off scramblers */
          rtn |= ten_n10g_otnr_descrambling (module_id, slice, 0, 0); /* Turn off scramblers */

          /* Bug 37598 - ODU2 PM Bip-8 byte unexpectly terminated in OTU2e client mapped to ODTU */
          /* Clear the ODU2 OCI that the null config set up */
          /* Bug #39241 - Signal conditioning should not be done by T41 datapath configuration APIs */
          #if (TEN_HL_OHPP_DISABLE_ODUK_OCI == 1) 
          rtn |= ten_hl_ohpp_control_oduk_oci (module_id, slice, CS_DISABLE);
          #endif

          /* Bugzilla 37928 - Need to disable dLOS generation since ODU2 is unscrambled */
          rtn |= ten_n10g_gblr_loscfg0 (module_id, slice, 3);

          rtn |= ten_hl_n10g_config_termination (module_id, slice, term_type, tcm_bits);

          rtn |= ten_hl_n10g_config_lom_from_traffic (module_id, slice, TEN_TRAFFIC_TYPE_OTU2E, TEN_FEC_MODE_NOFEC);
          rtn |= ten_n10g_gblr_set_kpasel(module_id, slice, 1);  /* KPA input from OxU2 Payload*/

          /* process 1st-level mappings */
          switch (map_oxuv) {
            case TEN_MAP_BMP :
            case TEN_MAP_DONT_CARE :
              rtn |= ten_n10g_set_otnt_wrpcfg4 (module_id, slice, 0, 0, 0, 0, 0); /* jc_plus_odtu23, jc_plus_otu2, jcen_dt, jcen_odtu23 and jcen_otu2 */
              rtn |= ten_n10g_otnr_set_dwmod (module_id, slice, 1);               /* Dewrapper enabled Justification commands are ignored */
            break;

          default:
              CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, "%s() Unexpected map_oxuv %d for OTU2E->ODTU", func, map_oxuv);
              break;
          }
          break;
        default :
          CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, "%s()  Unexpected line type %d for OTU2E client", func, mapper);
          return (CS_ERROR);              /* <<<<<<<<<<<<<<<  EARLY EXIT ON FAILURE <<<<<<<up to calling function to report error */
          break;
      }
      break;

      
    case TEN_TRAFFIC_TYPE_OTU2 :  /* client */
      switch (mapper) {

        /* OTU2->OTU2 */
        case TEN_TRAFFIC_TYPE_OTU2 :
          /* Client or Line side 10G Transponder Client side OTU2 Muxponder */

          if ((map_oxuv == TEN_MAP_BMP) ||(map_oxuv == TEN_MAP_DONT_CARE)) {
            /*rtn |= ten_hl_n10g_config (module_id, slice, TEN_N10G_RX_OTU2_ODU2, TEN_N10G_TX_ODU2_OTU2, 0);*/
            rtn |= ten_hl_n10g_config (module_id, slice, TEN_N10G_RX_OTU2_ODU2, TEN_N10G_TX_ODU2_OTU2, dyn_repro);
          } else {
            /* Force termination mode to full */
            term_type = TEN_OTU_TERM_FULL;

            rtn |= ten_hl_n10g_config (module_id, slice, TEN_N10G_RX_OTU2_OPU2, TEN_N10G_TX_OPU2_OTU2, dyn_repro);
            rtn |= ten_n10g_otnr_set_stm64md (module_id, slice, 1);
            rtn |= ten_n10g_otnr_set_dwmod (module_id, slice, 3);
            rtn |= ten_n10g_otnt_set_stm64md (module_id, slice, 1);
            rtn |= ten_n10g_otnt_set_wrmd (module_id, slice, 1);
            rtn |= ten_n10g_set_otnt_wrpcfg4 (module_id, slice, 0, 0, 0, 0, 1);
          }
          
          /* Bug #39241 - Signal conditioning should not be done by T41 datapath configuration APIs */
          #if (TEN_HL_OHPP_DISABLE_ODUK_OCI == 1) 
          rtn |= ten_hl_ohpp_control_oduk_oci (module_id, slice, CS_DISABLE);
          #endif
          
          /* Bug 37598 - ODU2 PM Bip-8 byte unexpectly terminated in OTU2e client mapped to ODTU */

          rtn |= ten_hl_n10g_config_lom_from_traffic (module_id, slice, client, fec);
          rtn |= ten_n10g_gblr_set_kpasel(module_id, slice, 1);  /* KPA input from OxU2 Payload*/

          /* Setup Termination Mode */
          rtn |= ten_hl_n10g_config_termination (module_id, slice, term_type, tcm_bits);
          break;

        /* OTU2->ODTU */
        case TEN_TRAFFIC_TYPE_ODTU :
          /* Line side Muxponder */
          rtn |= ten_hl_n10g_config (module_id, slice, TEN_N10G_RX_OXU3_ODU2, TEN_N10G_TX_ODU2_OXU3, dyn_repro);

          /* Line side OTU scrambling done in N40G block */
          rtn |= ten_n10g_otnt_scrambling (module_id, slice, 0, 0);   /* Turn off scramblers */
          rtn |= ten_n10g_otnr_descrambling (module_id, slice, 0, 0); /* Turn off descramblers */

          /* Bugzilla 37928 - Need to disable dLOS generation since ODU2 is unscrambled */
          rtn |= ten_n10g_gblr_loscfg0 (module_id, slice, 3);

          /* Bug 37598 - ODU2 PM Bip-8 byte unexpectly terminated in OTU2e client mapped to ODTU */
          rtn |= ten_hl_n10g_config_lom_from_traffic (module_id, slice, TEN_TRAFFIC_TYPE_OTU2, TEN_FEC_MODE_NOFEC);
          rtn |= ten_n10g_gblr_set_kpasel(module_id, slice, 1);  /* KPA input from OxU2 Payload*/

          /* Bug #39241 - Signal conditioning should not be done by T41 datapath configuration APIs */
          #if (TEN_HL_OHPP_DISABLE_ODUK_OCI == 1) 
          rtn |= ten_hl_ohpp_control_oduk_oci (module_id, slice, CS_DISABLE);
          #endif

          /* Setup Termination Mode */
          rtn |= ten_hl_n10g_config_termination (module_id, slice, term_type, tcm_bits);

          /* process 1st-level mappings */
          switch (map_oxuv) {
            case TEN_MAP_AMP :
              /* Bugzilla # , Fix regression failures */
              rtn |= ten_n10g_set_otnt_wrpcfg4(module_id, slice, 0, 0, 0, 1, 1); /* jc_plus_odtu23, jc_plus_otu2, jcen_dt, jcen_odtu23 and jcen_otu2 */
              rtn |= ten_n10g_otnr_set_dwmod(module_id, slice, 3);               /* Dewrapper enabled Justification commands are evaluated */
              break;
            case TEN_MAP_AMP_PROP :
              /* Bugzilla # , Fix regression failures */
              rtn |= ten_n10g_set_otnt_wrpcfg4(module_id, slice, 0, 1, 0, 1, 1); /* jc_plus_odtu23, jc_plus_otu2, jcen_dt, jcen_odtu23 and jcen_otu2 */
              rtn |= ten_n10g_tx_amp_prop_t41( module_id, slice, 0); /* hardcode to 0 since otu2 client fits. For FC use pdevcb->syncdsync_thread_cb[slice].num_just_oxu2); */
              rtn |= ten_n10g_otnr_set_dwmod(module_id, slice, 3);               /* Dewrapper enabled Justification commands are evaluated */
              rtn |= ten_n10g_rx_amp_prop_t41( module_id, slice, 0); /* hardcode to 0 since otu2 client fits. For FC use pdevcb->syncdsync_thread_cb[slice].num_just_oxu2); */
              break;
            case TEN_MAP_BMP :
            case TEN_MAP_DONT_CARE :
              /* T40 code sets this up right */
              break;
            default:
              CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, "%s() Unexpected map_oxuv %d for OTU2->ODTU", func, map_oxuv);
              break;
          }
          if (rtn != CS_OK) return (rtn); /* <<<<<<<<<<<<<<<  EARLY EXIT ON FAILURE <<<<<<<up to calling function to report error */
          break;
        default :
          CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, "%s()  Unexpected line type %d for OTU2 client", func, mapper);
          return (CS_ERROR);              /* <<<<<<<<<<<<<<<  EARLY EXIT ON FAILURE <<<<<<<up to calling function to report error */
          break;
      }
      break;

      
    case TEN_TRAFFIC_TYPE_10GE_6_1 :  /* client */
      switch (mapper) {

        /* 10GE6.1->ODTU */
        case TEN_TRAFFIC_TYPE_ODTU :

          /* Line side Muxponder */
          rtn |= ten_hl_n10g_config (module_id, slice, TEN_N10G_RX_OXU3_192_10GE, TEN_N10G_TX_10GE_192_OXU3, dyn_repro);

          /* Bug #39241 - Signal conditioning should not be done by T41 datapath configuration APIs */
          #if (TEN_HL_OHPP_DISABLE_ODUK_OCI == 1) 
          rtn |= ten_hl_ohpp_control_oduk_oci (module_id, slice, CS_DISABLE);
          #endif

          /* Line side OTU scrambling done in N40G block */
          rtn |= ten_n10g_otnt_scrambling (module_id, slice, 0, 0);    /* Turn off scramblers */
          rtn |= ten_n10g_otnr_descrambling (module_id, slice, 0, 0);  /* Turn off scramblers */

          /* Bugzilla 37928 - Need to disable dLOS generation since ODU2 is unscrambled */
          rtn |= ten_n10g_gblr_loscfg0 (module_id, slice, 3);

          /* Bug #37028 - OTN BIP8 mask not enabled properly for different mapping modes */
          rtn |= ten_n10g_oohr_cfg5_bipmsk(module_id, slice, 0xFF);
          if (tcm_bits != 0) {
            rtn |= ten_n10g_otnt_bipmsk (module_id, slice, 0x81 | tcm_bits);
          }
          else {
            rtn |= ten_n10g_otnt_bipmsk (module_id, slice, 0xFF); /* Enable BIP calculation at Tx OTU2 SM, PM and TCM */
          }

          /* Set STM 64 */
          rtn |= ten_n10g_otnr_set_stm64md (module_id, slice, 1);
          rtn |= ten_n10g_otnt_set_stm64md (module_id, slice, 1);

          rtn |= ten_hl_n10g_config_lom_from_traffic (module_id, slice, TEN_TRAFFIC_TYPE_OTU2, TEN_FEC_MODE_NOFEC);

          /* process 1st-level mappings */
          if (map_oxuv == TEN_MAP_BMP) {
            rtn |= ten_n10g_set_otnt_wrpcfg4 (module_id, slice, 0, 0, 0, 0, 0); /* jc_plus_odtu23, jc_plus_otu2, jcen_dt, jcen_odtu23 and jcen_otu2 */
            rtn |= ten_n10g_otnr_set_dwmod (module_id, slice, 1);               /* Dewrapper enabled Justification commands are ignored */
          }
          /*rtn |= ten_hl_oc192_termination (module_id, slice, term_sonet);*/
          break;

        /* 10GE6.1->OTU2 */
        case TEN_TRAFFIC_TYPE_OTU2 :
          /* Line side 10G Transponder */
          rtn |= ten_hl_n10g_config (module_id, slice, TEN_N10G_RX_OTU2_OC192_10GE, TEN_N10G_TX_10GE_OC192_OTU2, dyn_repro);
          /* Bug #39241 - Signal conditioning should not be done by T41 datapath configuration APIs */
          #if (TEN_HL_OHPP_DISABLE_ODUK_OCI == 1) 
          rtn |= ten_hl_ohpp_control_oduk_oci (module_id, slice, CS_DISABLE);
          #endif

          /* Bug #37028 - OTN BIP8 mask not enabled properly for different mapping modes */
          rtn |= ten_n10g_oohr_cfg5_bipmsk(module_id, slice, 0xFF);
          if (tcm_bits != 0) {
            rtn |= ten_n10g_otnt_bipmsk (module_id, slice, 0x81 | tcm_bits);
          }
          else {
            rtn |= ten_n10g_otnt_bipmsk (module_id, slice, 0xFF); /* Enable BIP calculation at Tx OTU2 SM, PM and TCM */
          }
          
          /* Set TDELON/TDELOFF for 3ms */
          /*rtn |= ten_n10g_otnr_lofcfg_tdelon_tdeloff(module_id, slice, 492, 492);*/
          rtn |= ten_hl_n10g_config_lom_from_traffic (module_id, slice, mapper, fec);
          break;

        /* Bugzilla #37204: 10ge6.1 (LAN) to WAN config */          
        /* 10GE6.1->OC192 */
        case TEN_TRAFFIC_TYPE_OC192:
          /* Line side 10G Transponder */
          rtn |= ten_hl_n10g_config (module_id, slice, TEN_N10G_RX_OC192_10GE, TEN_N10G_TX_10GE_OC192, dyn_repro);
          /* Bug #39241 - Signal conditioning should not be done by T41 datapath configuration APIs */
          #if (TEN_HL_OHPP_DISABLE_ODUK_OCI == 1) 
          rtn |= ten_hl_ohpp_control_oduk_oci (module_id, slice, CS_DISABLE);
          #endif
          break;
          
        default :
          CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, "%s()  Unexpected line type %d for client 10GE_6_1", func, mapper);
          return (CS_ERROR);              /* <<<<<<<<<<<<<<<  EARLY EXIT ON FAILURE <<<<<<<up to calling function to report error */
          break;
      }
      break;


    case TEN_TRAFFIC_TYPE_10GE_6_2 :  /* client */
      switch (mapper) {
        /* 10GE6.2->ODTU */
        case TEN_TRAFFIC_TYPE_ODTU :
          /* Line side Muxponder */

          rtn |= ten_hl_n10g_config (module_id, slice, TEN_N10G_RX_OXU3_10GE, TEN_N10G_TX_10GE_OXU3, dyn_repro);

          rtn |= ten_n10g_otnt_scrambling (module_id, slice, 0, 0);   /* Turn off scramblers */
          rtn |= ten_n10g_otnr_descrambling (module_id, slice, 0, 0); /* Turn off scramblers */

           /* Bug #39241 - Signal conditioning should not be done by T41 datapath configuration APIs */
          #if (TEN_HL_OHPP_DISABLE_ODUK_OCI == 1) 
          rtn |= ten_hl_ohpp_control_oduk_oci (module_id, slice, CS_DISABLE);
          #endif


          /* Bugzilla 37928 - Need to disable dLOS generation since ODU2 is unscrambled */
          rtn |= ten_n10g_gblr_loscfg0 (module_id, slice, 3);

          rtn |= ten_n10g_otnr_set_g43md (module_id, slice, 0);
          rtn |= ten_n10g_otnt_set_g43md (module_id, slice, 0);

          /* Set MFASINS to insert multi-frame alignment counter (MFAS) count in data stream Always */
          rtn |= ten_n10g_otnt_cfg0_mfasins (module_id, slice, 3);

          /* MFALGNE = 0x0    Disables the MFAS alignment process */
          rtn |= ten_n10g_otnt_cfg0_mfalgne (module_id, slice, 0);

          rtn |= ten_hl_n10g_config_lom_from_traffic (module_id, slice, TEN_TRAFFIC_TYPE_OTU2, TEN_FEC_MODE_NOFEC);

          /* process 1st-level mappings (none due to rate adjust) */
          break;

        /* 10GE6.2->OTU2 */
        case TEN_TRAFFIC_TYPE_OTU2 :
          /* Line side 10G Transponder */
          rtn |= ten_hl_n10g_config (module_id, slice, TEN_N10G_RX_OTU2_10GE, TEN_N10G_TX_10GE_OTU2, dyn_repro);
          
          /* Bug #39241 - Signal conditioning should not be done by T41 datapath configuration APIs */
          #if (TEN_HL_OHPP_DISABLE_ODUK_OCI == 1) 
          rtn |= ten_hl_ohpp_control_oduk_oci (module_id, slice, CS_DISABLE);
          #endif

          /* Bug #37028 - OTN BIP8 mask not enabled properly for different mapping modes */
          rtn |= ten_n10g_oohr_cfg5_bipmsk(module_id, slice, 0xFF);
          if (tcm_bits != 0) {
            rtn |= ten_n10g_otnt_bipmsk (module_id, slice, 0x81 | tcm_bits);
          }
          else {
            rtn |= ten_n10g_otnt_bipmsk (module_id, slice, 0xFF); /* Enable BIP calculation at Tx OTU2 SM, PM and TCM */
          }
          
          rtn |= ten_n10g_otnr_set_g43md (module_id, slice, 0);
          rtn |= ten_n10g_otnt_set_g43md (module_id, slice, 0);

          /* Set MFASINS to insert multi-frame alignment counter (MFAS) count in data stream Always */
          rtn |= ten_n10g_otnt_cfg0_mfasins (module_id, slice, 3);

          /* MFALGNE = 0x0    Disables the MFAS alignment process */
          rtn |= ten_n10g_otnt_cfg0_mfalgne (module_id, slice, 0);

          /* Set TDELON/TDELOFF for 3ms */
          rtn |= ten_hl_n10g_config_lom_from_traffic (module_id, slice, mapper, fec);
          break;
        default :
          CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, "%s()  Unexpected line type %d for client 10GE_6_2", func, mapper);
          return (CS_ERROR);              /* <<<<<<<<<<<<<<<  EARLY EXIT ON FAILURE <<<<<<<up to calling function to report error */
          break;
      }
      break;


    case TEN_TRAFFIC_TYPE_10GE_7_1 :  /* client */
      switch (mapper) {

        /* 10GE7.1->ODTU */
        case TEN_TRAFFIC_TYPE_ODTU :

          /* Line side Muxponder */
          rtn |= ten_hl_n10g_config (module_id, slice, TEN_N10G_RX_OXU3_ODU2E_10GE, TEN_N10G_TX_10GE_ODU2E_OXU3J, dyn_repro);

          /* Line side OTU scrambling done in N40G block */
          rtn |= ten_n10g_otnt_scrambling (module_id, slice, 0, 0);     /* Turn off scramblers */
          rtn |= ten_n10g_otnr_descrambling (module_id, slice, 0, 0);   /* Turn off scramblers */

          /* Enable JC Plus for this slice */
          rtn |= ten_n10g_otnt_set_jc_odtu23 (module_id, slice, 1, 0, 1);  /* jc_plus_odtu23, jcen_dt, jcen_odtu23 */

          /* Clear the ODU2 OCI that the null config set up */
           /* Bug #39241 - Signal conditioning should not be done by T41 datapath configuration APIs */
          #if (TEN_HL_OHPP_DISABLE_ODUK_OCI == 1) 
          rtn |= ten_hl_ohpp_control_oduk_oci (module_id, slice, CS_DISABLE);
          #endif


          rtn |= ten_hl_n10g_config_lom_from_traffic (module_id, slice, TEN_TRAFFIC_TYPE_OTU2E, TEN_FEC_MODE_NOFEC);
          break;

        /* 10GE7.1->OTU2E */
        case TEN_TRAFFIC_TYPE_OTU2E :
          /* Line side 10G Transponder */
          rtn |= ten_hl_n10g_config (module_id, slice, TEN_N10G_RX_OTU2E_10GE, TEN_N10G_TX_10GE_OTU2E, dyn_repro);

           /* Bug #39241 - Signal conditioning should not be done by T41 datapath configuration APIs */
          #if (TEN_HL_OHPP_DISABLE_ODUK_OCI == 1) 
          rtn |= ten_hl_ohpp_control_oduk_oci (module_id, slice, CS_DISABLE);
          #endif


          /* Bug #37028 - OTN BIP8 mask not enabled properly for different mapping modes */
          rtn |= ten_n10g_oohr_cfg5_bipmsk(module_id, slice, 0xFF);
          if (tcm_bits != 0) {
            rtn |= ten_n10g_otnt_bipmsk (module_id, slice, 0x81 | tcm_bits);
          }
          else {
            rtn |= ten_n10g_otnt_bipmsk (module_id, slice, 0xFF); /* Enable BIP calculation at Tx OTU2 SM, PM and TCM */
          }
          
          /* Set MFASINS to insert multi-frame alignment counter (MFAS) count in data stream Always */
          rtn |= ten_n10g_otnt_cfg0_mfasins (module_id, slice, 3);

          /* MFALGNE = 0x0    Disables the MFAS alignment process */
          rtn |= ten_n10g_otnt_cfg0_mfalgne (module_id, slice, 0);

          rtn |= ten_hl_n10g_config_lom_from_traffic (module_id, slice, mapper, fec);
          break;
        default :
          CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, "%s()  Unexpected line type %d for client 10GE_7_1", func, mapper);
          return (CS_ERROR);              /* <<<<<<<<<<<<<<<  EARLY EXIT ON FAILURE <<<<<<<up to calling function to report error */
          break;
      }
      break;


    case TEN_TRAFFIC_TYPE_10GE_7_2 :  /* client */
      switch (mapper) {

        /* 10GE7.2->ODTU */
        case TEN_TRAFFIC_TYPE_ODTU :
          /* Line side Muxponder */

          rtn |= ten_hl_n10g_config (module_id, slice, TEN_N10G_RX_OXU3_ODU2E_10GE, TEN_N10G_TX_10GE_ODU2E_OXU3J, dyn_repro);

          /* Disable STM64 */
          rtn |= ten_n10g_otnr_set_stm64md (module_id, slice, 0);
          rtn |= ten_n10g_otnt_set_stm64md (module_id, slice, 0);

          /* Line side OTU scrambling done in N40G block */
          rtn |= ten_n10g_otnt_scrambling (module_id, slice, 0, 0);     /* Turn off scramblers */
          rtn |= ten_n10g_otnr_descrambling (module_id, slice, 0, 0);   /* Turn off scramblers */

          /* Clear the ODU2 OCI that the null config set up */
          /* Bug #39241 - Signal conditioning should not be done by T41 datapath configuration APIs */
          #if (TEN_HL_OHPP_DISABLE_ODUK_OCI == 1) 
          rtn |= ten_hl_ohpp_control_oduk_oci (module_id, slice, CS_DISABLE);
          #endif

          rtn |= ten_hl_n10g_config_lom_from_traffic (module_id, slice, TEN_TRAFFIC_TYPE_OTU1E, TEN_FEC_MODE_NOFEC);
          break;

        /* 10GE7.2->OTU1E */
        case TEN_TRAFFIC_TYPE_OTU1E :
          /* Line side 10G Transponder */
          rtn |= ten_hl_n10g_config (module_id, slice, TEN_N10G_RX_OTU2E_10GE, TEN_N10G_TX_10GE_OTU2E, dyn_repro);

          /* OTU1e has no fixed stuff */
          rtn |= ten_n10g_otnr_set_stm64md (module_id, slice, 0);
          rtn |= ten_n10g_otnt_set_stm64md (module_id, slice, 0);

           /* Bug #39241 - Signal conditioning should not be done by T41 datapath configuration APIs */
          #if (TEN_HL_OHPP_DISABLE_ODUK_OCI == 1) 
          rtn |= ten_hl_ohpp_control_oduk_oci (module_id, slice, CS_DISABLE);
          #endif

          
          /* Bug #37028 - OTN BIP8 mask not enabled properly for different mapping modes */
          rtn |= ten_n10g_oohr_cfg5_bipmsk(module_id, slice, 0xFF);
          if (tcm_bits != 0) {
            rtn |= ten_n10g_otnt_bipmsk (module_id, slice, 0x81 | tcm_bits);
          }
          else {
            rtn |= ten_n10g_otnt_bipmsk (module_id, slice, 0xFF); /* Enable BIP calculation at Tx OTU2 SM, PM and TCM */
          }
          
          /* Set MFASINS to insert multi-frame alignment counter (MFAS) count in data stream Always */
          rtn |= ten_n10g_otnt_cfg0_mfasins (module_id, slice, 3);

          /* MFALGNE = 0x0    Disables the MFAS alignment process */
          rtn |= ten_n10g_otnt_cfg0_mfalgne (module_id, slice, 0);

          rtn |= ten_hl_n10g_config_lom_from_traffic (module_id, slice, mapper, fec);
          break;
        default :
          CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, "%s()  Unexpected line type %d for client 10GE_7_2", func, mapper);
          return (CS_ERROR);              /* <<<<<<<<<<<<<<<  EARLY EXIT ON FAILURE <<<<<<<up to calling function to report error */
          break;
      }
      break;


    case TEN_TRAFFIC_TYPE_10GE_7_3 :  /* client */
      switch (mapper) {

        /* 10GE7.3->ODTU */
        case TEN_TRAFFIC_TYPE_ODTU :
          /* Line side Muxponder */

          rtn |= ten_hl_n10g_config (module_id, slice, TEN_N10G_RX_OXU3_10GE, TEN_N10G_TX_10GE_OXU3, dyn_repro);

          /* Line side OTU scrambling done in N40G block */
          rtn |= ten_n10g_otnt_scrambling (module_id, slice, 0, 0);    /* Turn off scramblers */
          rtn |= ten_n10g_otnr_descrambling (module_id, slice, 0, 0);  /* Turn off descramblers */

          rtn |= ten_hl_n10g_config_lom_from_traffic (module_id, slice, TEN_TRAFFIC_TYPE_OTU2, TEN_FEC_MODE_NOFEC);

          /* Bug #39241 - Signal conditioning should not be done by T41 datapath configuration APIs */
          #if (TEN_HL_OHPP_DISABLE_ODUK_OCI == 1) 
          rtn |= ten_hl_ohpp_control_oduk_oci (module_id, slice, CS_DISABLE);
          #endif

          /* process 1st-level mappings (none due to rate adjust) */
          break;

        /* 10GE7.3->OTU2 */
        case TEN_TRAFFIC_TYPE_OTU2 :
          /* Line side 10G Transponder */
          rtn |= ten_hl_n10g_config (module_id, slice, TEN_N10G_RX_OTU2_10GE, TEN_N10G_TX_10GE_OTU2, dyn_repro);
          /* Bug #39241 - Signal conditioning should not be done by T41 datapath configuration APIs */
          #if (TEN_HL_OHPP_DISABLE_ODUK_OCI == 1) 
          rtn |= ten_hl_ohpp_control_oduk_oci (module_id, slice, CS_DISABLE);
          #endif

          /* Bug #37028 - OTN BIP8 mask not enabled properly for different mapping modes */
          rtn |= ten_n10g_oohr_cfg5_bipmsk(module_id, slice, 0xFF);
          if (tcm_bits != 0) {
            rtn |= ten_n10g_otnt_bipmsk (module_id, slice, 0x81 | tcm_bits);
          }
          else {
            rtn |= ten_n10g_otnt_bipmsk (module_id, slice, 0xFF); /* Enable BIP calculation at Tx OTU2 SM, PM and TCM */
          }
          
          rtn |= ten_n10g_otnr_set_g43md (module_id, slice, 1);
          rtn |= ten_n10g_otnt_set_g43md (module_id, slice, 1);

          /* Set MFASINS to insert multi-frame alignment counter (MFAS) count in data stream Always */
          rtn |= ten_n10g_otnt_cfg0_mfasins (module_id, slice, 3);

          /* MFALGNE = 0x0    Disables the MFAS alignment process */
          rtn |= ten_n10g_otnt_cfg0_mfalgne (module_id, slice, 0);

          rtn |= ten_hl_n10g_config_lom_from_traffic (module_id, slice, mapper, fec);
          break;
        default :
          CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, "%s() Unexpected line type %d for client 10GE_7_3", func, mapper);
          return (CS_ERROR);              /* <<<<<<<<<<<<<<<  EARLY EXIT ON FAILURE <<<<<<<up to calling function to report error */
          break;
      }
      break;


      case TEN_TRAFFIC_TYPE_10GE_RA :  /* client */
        switch (mapper) {

        /* 10GE_RA->OTU2 */
          case TEN_TRAFFIC_TYPE_OTU2 :
          case TEN_TRAFFIC_TYPE_OTU2E:
          /* Line side 10G Transponder */
          
          /* Bugzilla #30526, support 10ge_ra into otu2e */
          if (mapper == TEN_TRAFFIC_TYPE_OTU2) {
            rtn |= ten_hl_n10g_config (module_id, slice, TEN_N10G_RX_OTU2_10GE, TEN_N10G_TX_10GE_OTU2, dyn_repro);
          }
          else {
             rtn |= ten_hl_n10g_config (module_id, slice, TEN_N10G_RX_OTU2E_10GE, TEN_N10G_TX_10GE_OTU2E, dyn_repro);
          }

          /* Bug #39241 - Signal conditioning should not be done by T41 datapath configuration APIs */
          #if (TEN_HL_OHPP_DISABLE_ODUK_OCI == 1) 
          rtn |= ten_hl_ohpp_control_oduk_oci (module_id, slice, CS_DISABLE);
          #endif

          /* Bug #37028 - OTN BIP8 mask not enabled properly for different mapping modes */
          rtn |= ten_n10g_oohr_cfg5_bipmsk(module_id, slice, 0xFF);
          if (tcm_bits != 0) {
            rtn |= ten_n10g_otnt_bipmsk (module_id, slice, 0x81 | tcm_bits);
          }
          else {
            rtn |= ten_n10g_otnt_bipmsk (module_id, slice, 0xFF); /* Enable BIP calculation at Tx OTU2 SM, PM and TCM */
          }
          
          rtn |= ten_n10g_otnr_set_g43md (module_id, slice, 0);
          rtn |= ten_n10g_otnt_set_g43md (module_id, slice, 0);

           /* Set MFASINS to insert multi-frame alignment counter (MFAS) count in data stream Always */
          rtn |= ten_n10g_otnt_cfg0_mfasins (module_id, slice, 3);

          /* MFALGNE = 0x0    Disables the MFAS alignment process */
          rtn |= ten_n10g_otnt_cfg0_mfalgne (module_id, slice, 0);

          /* Set TDELON/TDELOFF for 3ms */
          rtn |= ten_hl_n10g_config_lom_from_traffic (module_id, slice, mapper, fec);
          break;

        /* 10GE_RA->ODTU */
        case TEN_TRAFFIC_TYPE_ODTU :
          /* Line side Muxponder */
          /* Bugzilla #39308: Add support for 10GE_RA->OTU2e->OTU3V */
          pdevcb = TEN_DEV_ID_TO_DEVCB_PTR(dev_id);
          if (pdevcb) {  
            psyncdsync_cb = &pdevcb->syncdsync_thread_cb[slice];
            if (psyncdsync_cb) {
              /* check if OTU2E (10399525320.0), if > OTU2 (10037273920.0), using mid point value to avoid rounding problems */
              if (psyncdsync_cb->xcon_client_rate > 10100000000.0) {
                CS_PRINT("mux_odtuv_rate=OTU2E, use 10GE_RA->OTU2e->OTU3V\n");
                rtn |= ten_hl_n10g_config (module_id, slice, TEN_N10G_RX_OXU3_ODU2E_10GE, TEN_N10G_TX_10GE_ODU2E_OXU3J, dyn_repro);
              }
              else {
                rtn |= ten_hl_n10g_config (module_id, slice, TEN_N10G_RX_OXU3_10GE, TEN_N10G_TX_10GE_OXU3, dyn_repro); 
              }
            }
          }

          /* Line side OTU scrambling done in N40G block */
          rtn |= ten_n10g_otnt_scrambling (module_id, slice, 0, 0);     /* Turn off scramblers */
          rtn |= ten_n10g_otnr_descrambling (module_id, slice, 0, 0);   /* Turn off scramblers */

           /* Bug #39241 - Signal conditioning should not be done by T41 datapath configuration APIs */
          #if (TEN_HL_OHPP_DISABLE_ODUK_OCI == 1) 
          rtn |= ten_hl_ohpp_control_oduk_oci (module_id, slice, CS_DISABLE);
          #endif


          rtn |= ten_n10g_otnr_set_g43md (module_id, slice, 0);
          rtn |= ten_n10g_otnt_set_g43md (module_id, slice, 0);
           /* Set MFASINS to insert multi-frame alignment counter (MFAS) count in data stream Always */
          rtn |= ten_n10g_otnt_cfg0_mfasins (module_id, slice, 3);

          /* MFALGNE = 0x0    Disables the MFAS alignment process */
          rtn |= ten_n10g_otnt_cfg0_mfalgne (module_id, slice, 0);
          /* jc_plus_odtu23=1, jc_plus_otu2=0, jcen_dt=0, jcen_odtu23=1, jcen_otu2=0*/
          rtn |= ten_n10g_set_otnt_wrpcfg4 (module_id, slice, 1, 0, 0, 1, 0);           /* @TODO: Mapping should not be set here. */

          /* Set TDELON/TDELOFF for 3ms */
          rtn |= ten_hl_n10g_config_lom_from_traffic (module_id, slice, TEN_TRAFFIC_TYPE_OTU2, TEN_FEC_MODE_NOFEC);
          break;
        default :
          CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, "%s()  Unexpected line type %d for client 10GE_RA", func, mapper);
          return (CS_ERROR);              /* <<<<<<<<<<<<<<<  EARLY EXIT ON FAILURE <<<<<<<up to calling function to report error */
          break;
      }
      break;


    case TEN_TRAFFIC_TYPE_10GE_GFPF_OC192_ODU2 :  /* client */
      switch (mapper) {

        /* 10GE_GFPF_OC192_ODU2->OTU2 */
        case TEN_TRAFFIC_TYPE_OTU2 :
          /* Line side 10G Transponder */
          rtn |= ten_hl_n10g_config (module_id, slice, TEN_N10G_RX_OTU2_OC192_10GE, TEN_N10G_TX_10GE_OC192_OTU2, dyn_repro);
           /* Bug #39241 - Signal conditioning should not be done by T41 datapath configuration APIs */
          #if (TEN_HL_OHPP_DISABLE_ODUK_OCI == 1) 
          rtn |= ten_hl_ohpp_control_oduk_oci (module_id, slice, CS_DISABLE);
          #endif

          rtn |= ten_n10g_otnr_set_g43md (module_id, slice, 0);
          rtn |= ten_n10g_otnt_set_g43md (module_id, slice, 0);

           /* Set MFASINS to insert multi-frame alignment counter (MFAS) count in data stream Always */
          rtn |= ten_n10g_otnt_cfg0_mfasins (module_id, slice, 3);
          /* MFALGNE = 0x0    Disables the MFAS alignment process */
          rtn |= ten_n10g_otnt_cfg0_mfalgne (module_id, slice, 0);

          /* Set TDELON/TDELOFF for 3ms */
          rtn |= ten_hl_n10g_config_lom_from_traffic (module_id, slice, mapper, fec);
          rtn |= ten_n10g_gblr_set_kpasel(module_id, slice, 0);  /* KPA input from SDH Payload */
          break;

        /* 10GE_GFPF_OC192_ODU2->ODTU */
        case TEN_TRAFFIC_TYPE_ODTU :

          /* Line side 10G Transponder */
          rtn |= ten_hl_n10g_config(module_id, slice, TEN_N10G_RX_OXU3_192_10GE,TEN_N10G_TX_10GE_192_OXU3, dyn_repro);
          /* WRPCFG3_STM64MD = 1 */
          rtn |= ten_n10g_otnt_set_stm64md (module_id, slice, 1);
          /* Bug #39241 - Signal conditioning should not be done by T41 datapath configuration APIs */
          #if (TEN_HL_OHPP_DISABLE_ODUK_OCI == 1) 
          rtn |= ten_hl_ohpp_control_oduk_oci (module_id, slice, CS_DISABLE);
          #endif

          rtn |= ten_n10g_otnr_set_g43md (module_id, slice, 0);
          rtn |= ten_n10g_otnt_set_g43md (module_id, slice, 0);

           /* Set MFASINS to insert multi-frame alignment counter (MFAS) count in data stream Always */
          rtn |= ten_n10g_otnt_cfg0_mfasins (module_id, slice, 3);
          /* MFALGNE = 0x0    Disables the MFAS alignment process */
          rtn |= ten_n10g_otnt_cfg0_mfalgne (module_id, slice, 0);

          /* Set TDELON/TDELOFF for 3ms */
          rtn |= ten_hl_n10g_config_lom_from_traffic (module_id, slice, TEN_TRAFFIC_TYPE_OTU2, TEN_FEC_MODE_NOFEC);
          break;
        default :
          CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, "%s()  Unexpected line type %d for client 10GE_GFPF_OC192_ODU2", func, mapper);
          return (CS_ERROR);              /* <<<<<<<<<<<<<<<  EARLY EXIT ON FAILURE <<<<<<<up to calling function to report error */
          break;
      }
      break;

    /* Bugzilla 29991 Start */
    case TEN_TRAFFIC_TYPE_10GE_GFPF:
      switch (mapper) {
        case TEN_TRAFFIC_TYPE_OC192:
          /* 10GE_GFPF->OC192 */
          /* Client side 10G Transponder or OC192 Muxponder */
          rtn |= ten_hl_n10g_config (module_id, slice, TEN_N10G_RX_OC192_10GE, TEN_N10G_TX_10GE_OC192, dyn_repro);  /* Bugzilla 29758 Start */
          break;

        default :
          CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, "%s() Unexpected line type %d for client TEN_TRAFFIC_TYPE_10GE", func, mapper);
          return (CS_ERROR);
          break;
      }
      break;
    /* Bugzilla 29991 End */


    case TEN_TRAFFIC_TYPE_10GE_TC :  /* client */
      switch (mapper) {

        /* 10GE_TC->OTU2E */
        case TEN_TRAFFIC_TYPE_OTU2E :
          /* Line side 10G Transponder */
          rtn |= ten_hl_n10g_config (module_id, slice, TEN_N10G_RX_OTU2EJ_10GE, TEN_N10G_TX_10GE_OTU2EJ, dyn_repro);

          /* Bug #39241 - Signal conditioning should not be done by T41 datapath configuration APIs */
          #if (TEN_HL_OHPP_DISABLE_ODUK_OCI == 1) 
          rtn |= ten_hl_ohpp_control_oduk_oci (module_id, slice, CS_DISABLE);
          #endif

          /* Bug #37028 - OTN BIP8 mask not enabled properly for different mapping modes */
          rtn |= ten_n10g_oohr_cfg5_bipmsk(module_id, slice, 0xFF);
          if (tcm_bits != 0) {
            rtn |= ten_n10g_otnt_bipmsk (module_id, slice, 0x81 | tcm_bits);
          }
          else {
            rtn |= ten_n10g_otnt_bipmsk (module_id, slice, 0xFF); /* Enable BIP calculation at Tx OTU2 SM, PM and TCM */
          }

          rtn |= ten_n10g_otnt_set_wrpfs (module_id, slice, pdevcb->syncdsync_cb.num_just_oxu2);
          rtn |= ten_n10g_set_otnr_odwfs (module_id, slice, pdevcb->syncdsync_cb.num_just_oxu2);

          rtn |= ten_n10g_otnr_set_stm64md (module_id, slice,0);
          rtn |= ten_n10g_otnt_set_stm64md (module_id, slice,0);
          rtn |= ten_n10g_otnt_set_c15res_en (module_id, slice,0);
          rtn |= ten_n10g_otnr_set_c15res_en (module_id, slice,0);

          /* unset the G43MD in N10G */
          rtn |= ten_n10g_otnr_set_g43md (module_id, slice, 0);
          rtn |= ten_n10g_otnt_set_g43md (module_id, slice, 0);

          /* Set TDELON/TDELOFF for 3ms */
          rtn |= ten_hl_n10g_config_lom_from_traffic (module_id, slice, mapper, fec);
          break;
        default :
          CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, "%s()  Unexpected line type %d for client 10GE_TC", func, mapper);
          return (CS_ERROR);              /* <<<<<<<<<<<<<<<  EARLY EXIT ON FAILURE <<<<<<<up to calling function to report error */
          break;
      }
      break;


    case TEN_TRAFFIC_TYPE_10GFC :  /* client */
      switch (mapper) {

        /* 10GFC->OTU1F,  10GFC->OTU2F */
        case TEN_TRAFFIC_TYPE_OTU1F :
        case TEN_TRAFFIC_TYPE_OTU2F :
          /* Line side 10G Transponder */

          rtn |= ten_hl_n10g_config (module_id, slice, TEN_N10G_RX_OTU2E_10GE, TEN_N10G_TX_10GE_OTU2E, dyn_repro);
          /* Bug #39241 - Signal conditioning should not be done by T41 datapath configuration APIs */
          #if (TEN_HL_OHPP_DISABLE_ODUK_OCI == 1) 
          rtn |= ten_hl_ohpp_control_oduk_oci (module_id, slice, CS_DISABLE);
          #endif

          /* Bug #37028 - OTN BIP8 mask not enabled properly for different mapping modes */
          rtn |= ten_n10g_oohr_cfg5_bipmsk(module_id, slice, 0xFF);
          if (tcm_bits != 0) {
            rtn |= ten_n10g_otnt_bipmsk (module_id, slice, 0x81 | tcm_bits);
          }
          else {
            rtn |= ten_n10g_otnt_bipmsk (module_id, slice, 0xFF); /* Enable BIP calculation at Tx OTU2 SM, PM and TCM */
          }

          rtn |= ten_hl_n10g_config_pti (module_id, slice, TEN_TRAFFIC_TYPE_10GFC, 1);
          rtn |= ten_n10g_otnr_set_stm64md (module_id, slice, 0);
          rtn |= ten_n10g_otnt_set_stm64md (module_id, slice, 0);

          /* Set MFASINS to insert multi-frame alignment counter (MFAS) count in data stream Always */
          rtn |= ten_n10g_otnt_cfg0_mfasins (module_id,   slice,   3);
          /* MFALGNE = 0x0    Disables the MFAS alignment process */
          rtn |= ten_n10g_otnt_cfg0_mfalgne (module_id,   slice,   0);

          /* Set TDELON/TDELOFF for 3ms */
          rtn |= ten_hl_n10g_config_lom_from_traffic (module_id, slice, mapper, fec);
          if (map_oxuv == TEN_MAP_BMP) {
          }
          else {
            CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, "%s: 10GFC->ODU1F/2F, map_oxuv=%d with map_odtu=%d not supported\n", func, map_oxuv, map_odtu);
            rtn |= CS_ERROR;
          }
          break;

        /* 10GFC->ODTU */
        case TEN_TRAFFIC_TYPE_ODTU :
          /* Line side 10G Transponder */
            /* validate this block before using it. Need to package 10FGC into ODU1e. */
            rtn |= ten_hl_n10g_config (module_id, slice, TEN_N10G_RX_OXU3_10GEP, TEN_N10G_TX_10GE_OXU3P, dyn_repro);
            /* Line side OTU scrambling done in N40G block */
            rtn |= ten_n10g_otnt_scrambling (module_id, slice, 0, 0);
            rtn |= ten_n10g_otnr_descrambling (module_id, slice, 0, 0);
            /* Bug #39241 - Signal conditioning should not be done by T41 datapath configuration APIs */
            #if (TEN_HL_OHPP_DISABLE_ODUK_OCI == 1) 
            rtn |= ten_hl_ohpp_control_oduk_oci (module_id, slice, CS_DISABLE);
            #endif

            /* Enable JC Plus for this slice */
            rtn |= ten_n10g_otnt_set_jc_odtu23 (module_id, slice, 1, 0, 1);  /* jc_plus_odtu23, jcen_dt, jcen_odtu23 */

            /* Bug #37028 - OTN BIP8 mask not enabled properly for different mapping modes */
            rtn |= ten_n10g_oohr_cfg5_bipmsk(module_id, slice, 0xFF);
            if (tcm_bits != 0) {
              rtn |= ten_n10g_otnt_bipmsk (module_id, slice, 0x81 | tcm_bits);
            }
            else {
              rtn |= ten_n10g_otnt_bipmsk (module_id, slice, 0xFF); /* Enable BIP calculation at Tx OTU2 SM, PM and TCM */
            }

            /* Set MFASINS to insert multi-frame alignment counter (MFAS) count in data stream Always */
            rtn |= ten_n10g_otnt_cfg0_mfasins (module_id, slice, 3);

            /* MFALGNE = 0x0    Disables the MFAS alignment process */
            rtn |= ten_n10g_otnt_cfg0_mfalgne( module_id, slice, 0);
          break;
        default :
          CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, "%s(),  Unexpected line type %d for client 10GFC", func, mapper);
          return (CS_ERROR);              /* <<<<<<<<<<<<<<<  EARLY EXIT ON FAILURE <<<<<<<up to calling function to report error */
          break;
      }
      break;


    case TEN_TRAFFIC_TYPE_10GFC_TC :  /* client */
    case TEN_TRAFFIC_TYPE_10GFC_TC_G709 :  /* Bug 31054 */
      switch (mapper) {
        /* 10GFC(TC)->OTU2E */
        case TEN_TRAFFIC_TYPE_OTU2E :
          /* Line side 10G Transponder */
          rtn |= ten_hl_n10g_config (module_id, slice, TEN_N10G_RX_OTU2E_10GE, TEN_N10G_TX_10GE_OTU2E, dyn_repro);
          /* Bug #39241 - Signal conditioning should not be done by T41 datapath configuration APIs */
          #if (TEN_HL_OHPP_DISABLE_ODUK_OCI == 1) 
          rtn |= ten_hl_ohpp_control_oduk_oci (module_id, slice, CS_DISABLE);
          #endif

          /* Bug #37028 - OTN BIP8 mask not enabled properly for different mapping modes */
          rtn |= ten_n10g_oohr_cfg5_bipmsk(module_id, slice, 0xFF);
          if (tcm_bits != 0) {
            rtn |= ten_n10g_otnt_bipmsk (module_id, slice, 0x81 | tcm_bits);
          }
          else {
            rtn |= ten_n10g_otnt_bipmsk (module_id, slice, 0xFF); /* Enable BIP calculation at Tx OTU2 SM, PM and TCM */
          }
          
          rtn |= ten_hl_n10g_config_pti (module_id, slice, TEN_TRAFFIC_TYPE_10GFC, 1);

          /* Set MFASINS to insert multi-frame alignment counter (MFAS) count in data stream Always */
          rtn |= ten_n10g_otnt_cfg0_mfasins (module_id,   slice,   3);
          /* MFALGNE = 0x0    Disables the MFAS alignment process */
          rtn |= ten_n10g_otnt_cfg0_mfalgne (module_id,   slice,   0);

          /* Set TDELON/TDELOFF for 3ms */
          rtn |= ten_hl_n10g_config_lom_from_traffic (module_id, slice, mapper, fec);
          break;

        /* 10GFC(TC)->ODTU */
        case TEN_TRAFFIC_TYPE_ODTU :
          /* Line side 10G Transponder */
          rtn |= ten_hl_n10g_config (module_id, slice, TEN_N10G_RX_OXU3_10GEP, TEN_N10G_TX_10GE_OXU3P, dyn_repro);
          /* Line side OTU scrambling done in N40G block */
          rtn |= ten_n10g_otnt_scrambling (module_id, slice, 0, 0);
          rtn |= ten_n10g_otnr_descrambling (module_id, slice, 0, 0);
           /* Bug #39241 - Signal conditioning should not be done by T41 datapath configuration APIs */
          #if (TEN_HL_OHPP_DISABLE_ODUK_OCI == 1) 
          rtn |= ten_hl_ohpp_control_oduk_oci (module_id, slice, CS_DISABLE);
          #endif


          /* Enable JC Plus for this slice */
          rtn |= ten_n10g_otnt_set_jc_odtu23 (module_id, slice, 1, 0, 1);

          /* Bug #37028 - OTN BIP8 mask not enabled properly for different mapping modes */
          rtn |= ten_n10g_oohr_cfg5_bipmsk(module_id, slice, 0xFF);
          if (tcm_bits != 0) {
            rtn |= ten_n10g_otnt_bipmsk (module_id, slice, 0x81 | tcm_bits);
          }
          else {
            rtn |= ten_n10g_otnt_bipmsk (module_id, slice, 0xFF); /* Enable BIP calculation at Tx OTU2 SM, PM and TCM */
          }

          /* Set MFASINS to insert multi-frame alignment counter (MFAS) count in data stream Always */
          rtn |= ten_n10g_otnt_cfg0_mfasins (module_id, slice, 3);

          /* MFALGNE = 0x0    Disables the MFAS alignment process */
          rtn |= ten_n10g_otnt_cfg0_mfalgne( module_id, slice, 0);
          break;
        default :
          CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, "%s()  Unexpected line type %d for client 10GFC_TC", func, mapper);
          return (CS_ERROR);              /* <<<<<<<<<<<<<<<  EARLY EXIT ON FAILURE <<<<<<<up to calling function to report error */
          break;
      }
      break;

    case TEN_TRAFFIC_TYPE_10GFC_TC_RA :    /* client */
      switch (mapper) {
        /* 10GFC(TC)->OTU2E */
        case TEN_TRAFFIC_TYPE_OTU2E :
          /* Line side 10G Transponder */
          rtn |= ten_hl_n10g_config (module_id, slice, TEN_N10G_RX_OTU2E_10GE, TEN_N10G_TX_10GE_OTU2E, dyn_repro);
          /* Bug #39241 - Signal conditioning should not be done by T41 datapath configuration APIs */
          #if (TEN_HL_OHPP_DISABLE_ODUK_OCI == 1) 
          rtn |= ten_hl_ohpp_control_oduk_oci (module_id, slice, CS_DISABLE);
          #endif

          /* Bug #37028 - OTN BIP8 mask not enabled properly for different mapping modes */
          rtn |= ten_n10g_oohr_cfg5_bipmsk(module_id, slice, 0xFF);
          if (tcm_bits != 0) {
            rtn |= ten_n10g_otnt_bipmsk (module_id, slice, 0x81 | tcm_bits);
          }
          else {
            rtn |= ten_n10g_otnt_bipmsk (module_id, slice, 0xFF); /* Enable BIP calculation at Tx OTU2 SM, PM and TCM */
          }

          rtn |= ten_hl_n10g_config_pti (module_id, slice, TEN_TRAFFIC_TYPE_10GFC, 1);
          /* Disable ODTU JC Plus for this slice */
          rtn |= ten_n10g_otnt_set_jc_odtu23 (module_id, slice, 0, 0, 0);
          /* STM64MD should be off for all 10GFC */
          /* rtn |= ten_n10g_otnt_set_stm64md(module_id, slice, 0);
          rtn |= ten_n10g_otnr_set_stm64md(module_id, slice, 0); */

          /* Bug 36432 - PTI handled by ten_hl_n10g_config_pti_t41*/
          /* rtn |= ten_hl_n10g_config_pti (module_id, slice, TEN_TRAFFIC_TYPE_10GFC, 1); */

          /* Set MFASINS to insert multi-frame alignment counter (MFAS) count in data stream Always */
          rtn |= ten_n10g_otnt_cfg0_mfasins (module_id,   slice,   3);
          /* MFALGNE = 0x0    Disables the MFAS alignment process */
          rtn |= ten_n10g_otnt_cfg0_mfalgne (module_id,   slice,   0);

          /* Set TDELON/TDELOFF for 3ms */
          rtn |= ten_hl_n10g_config_lom_from_traffic (module_id, slice, mapper, fec);
          break;

        default :
          CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, "%s()  Unexpected line type %d for client 10GFC_RA", func, mapper);
          return (CS_ERROR);              /* <<<<<<<<<<<<<<<  EARLY EXIT ON FAILURE <<<<<<<up to calling function to report error */
          break;
      }
      break;

    case TEN_TRAFFIC_TYPE_8GFC :  /* client */
    case TEN_TRAFFIC_TYPE_4GFC :
    case TEN_TRAFFIC_TYPE_2GFC :
    case TEN_TRAFFIC_TYPE_1GFC :
    case TEN_TRAFFIC_TYPE_2GISC :
      switch (mapper) {
        /* 4/8 GFC->OTU2 */
        case TEN_TRAFFIC_TYPE_OTU2 :
          /* Line side 10G Transponder */
          switch (map_oxuv) {
            case TEN_MAP_GMP_LO :
              /* process 1st-level mappings */
              rtn |= ten_hl_n10g_config(module_id, slice, TEN_N10G_RX_OTU2_8GFC, TEN_N10G_TX_8GFC_OTU2, dyn_repro);
              /* Bug 29757 Start */
              /* Clear the ODU2 OCI that the null config set up */
               /* Bug #39241 - Signal conditioning should not be done by T41 datapath configuration APIs */
          #if (TEN_HL_OHPP_DISABLE_ODUK_OCI == 1) 
          rtn |= ten_hl_ohpp_control_oduk_oci (module_id, slice, CS_DISABLE);
          #endif

              /* Bug 29757 End */
             
              /* Bug #37028 - OTN BIP8 mask not enabled properly for different mapping modes */
              rtn |= ten_n10g_oohr_cfg5_bipmsk(module_id, slice, 0xFF);
              if (tcm_bits != 0) {
                rtn |= ten_n10g_otnt_bipmsk (module_id, slice, 0x81 | tcm_bits);
              }
              else {
                rtn |= ten_n10g_otnt_bipmsk (module_id, slice, 0xFF); /* Enable BIP calculation at Tx OTU2 SM, PM and TCM */
              }
              
              rtn |= ten_n10g_gblr_set_xsel(module_id, slice, 0x2);
              /* Set STM 64 */
              rtn |= ten_n10g_otnr_set_stm64md(module_id, slice, 0);
              rtn |= ten_n10g_otnt_set_stm64md(module_id, slice, 0);
              /* Set MFASINS to insert multi-frame alignment counter (MFAS) count in data stream Always */
              rtn |= ten_n10g_otnt_cfg0_mfasins(module_id,   slice,   3);
              /* MFALGNE = 0x0    Disables the MFAS alignment process */
              rtn |= ten_n10g_otnt_cfg0_mfalgne(module_id,   slice,   0);

              Cm    = (cs_uint16) (pdevcb->syncdsync_thread_cb[slice].cn_bytes_n10g / timeslots);  /*Bugzilla 26308*/
              Cn_hi = (cs_uint16) (pdevcb->syncdsync_thread_cb[slice].cn_bytes_n10g >> 16);
              Cn_lo = (cs_uint16) (pdevcb->syncdsync_thread_cb[slice].cn_bytes_n10g & 0x0000ffff);

              rtn |= ten_n10g_tx_gmp_lo_t41( module_id, slice );
              rtn |= ten_n10g_rx_gmp_lo_t41( module_id, slice );
              rtn |= ten_n10g_tx_gmp_cm_cn_t41( module_id, slice, Cm, Cn_lo, Cn_hi);
              rtn |= ten_n10g_rx_gmp_cn_t41( module_id, slice, Cn_lo, Cn_hi);         /*Bugzilla 36501*/
              break;
            default:
              CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, "%s()  Unexpected line type %d for client 8GFC", func, map_oxuv);
              return (CS_ERROR);              /* <<<<<<<<<<<<<<<  EARLY EXIT ON FAILURE <<<<<<<up to calling function to report error */
              break;
          }
          break;

        /* 1/2/4/8 GFC RA->ODTU 40G Muxponder Line side */
        case TEN_TRAFFIC_TYPE_ODTU :
          /* process 1st-level mappings */
          rtn |= ten_hl_n10g_config(module_id, slice, TEN_N10G_RX_ODU2J_8GFC, TEN_N10G_TX_8GFC_ODU2J, dyn_repro);
          /* Bug 29757 Start */
          /* Clear the ODU2 OCI that the null config set up */
          /* Bug #39241 - Signal conditioning should not be done by T41 datapath configuration APIs */
          #if (TEN_HL_OHPP_DISABLE_ODUK_OCI == 1) 
          rtn |= ten_hl_ohpp_control_oduk_oci (module_id, slice, CS_DISABLE);
          #endif

          /* Bug 29757 End */
          /* Overwrite columns */
          rtn |= ten_n10g_set_otnr_odwfs(module_id, slice, 0);
          rtn |= ten_n10g_otnt_set_wrpfs(module_id, slice, 0);
          /* Line side OTU scrambling done in N40G block */
          rtn |= ten_n10g_otnt_scrambling(module_id, slice, 0, 0);
          rtn |= ten_n10g_otnr_descrambling(module_id, slice, 0, 0);
          
          /* Bug #37028 - OTN BIP8 mask not enabled properly for different mapping modes */
          rtn |= ten_n10g_oohr_cfg5_bipmsk(module_id, slice, 0xFF);
          if (tcm_bits != 0) {
            rtn |= ten_n10g_otnt_bipmsk (module_id, slice, 0x81 | tcm_bits);
          }
          else {
            rtn |= ten_n10g_otnt_bipmsk (module_id, slice, 0xFF); /* Enable BIP calculation at Tx OTU2 SM, PM and TCM */
          }
          
          /* rtn |= ten_n10g_set_pktie(module_id, slice, 0); */
          /* Set TDELON/TDELOFF for 3ms */
          rtn |= ten_n10g_otnr_lofcfg_tdelon_tdeloff(module_id, slice, 492*239/255, 492*239/255);
          rtn |= ten_n10g_gblr_set_xsel(module_id, slice, 0x2);
          /* Set STM 64 */
          rtn |= ten_n10g_otnr_set_stm64md(module_id, slice, 0);
          rtn |= ten_n10g_otnt_set_stm64md(module_id, slice, 0);
          /* Set MFASINS to insert multi-frame alignment counter (MFAS) count in data stream Always */
          rtn |= ten_n10g_otnt_cfg0_mfasins(module_id,   slice,   3);
          /* MFALGNE = 0x0    Disables the MFAS alignment process */
          rtn |= ten_n10g_otnt_cfg0_mfalgne(module_id,   slice,   0);

          /* Bugzilla 36501 start */
          rtn |= ten_n10g_oohr_jcsquelch (module_id, slice, TEN_JCSQLCH_LOS, 0);
          rtn |= ten_n10g_gblr_loscfg0 (module_id, slice, 3);
          /* Bugzilla 36501 end */
          
          /* process 1st-level mappings - Bugzilla 36501*/
          /* Bugzilla 37001 Start: false positive error for map_oxuv!=TEN_MAP_GMP_LO fixed */
          if (map_oxuv == TEN_MAP_GMP_LO) {
              Cm    = (cs_uint16) (pdevcb->syncdsync_thread_cb[slice].cn_bytes_n10g / timeslots);  /*Bugzilla 26308*/
              Cn_hi = (cs_uint16) (pdevcb->syncdsync_thread_cb[slice].cn_bytes_n10g >> 16);
              Cn_lo = (cs_uint16) (pdevcb->syncdsync_thread_cb[slice].cn_bytes_n10g & 0x0000ffff);

              rtn |= ten_n10g_tx_gmp_lo_t41( module_id, slice );
              rtn |= ten_n10g_rx_gmp_lo_t41( module_id, slice );
              rtn |= ten_n10g_tx_gmp_cm_cn_t41( module_id, slice, Cm, Cn_lo, Cn_hi);
              rtn |= ten_n10g_rx_gmp_cn_t41( module_id, slice, Cn_lo, Cn_hi);
          }    
          /* Bugzilla 37001 End */      
          break;

        default :
          CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, "%s()  Unexpected line type %d for this FiberChannel client", func, mapper);
          return (CS_ERROR);              /* <<<<<<<<<<<<<<<  EARLY EXIT ON FAILURE <<<<<<<up to calling function to report error */
          break;
      }
      break;


    case TEN_TRAFFIC_TYPE_1GE :  /* Bugzilla 38871 */
      switch (mapper) {
        case TEN_TRAFFIC_TYPE_OTU2 :
          /* Line side 10G Transponder */
          rtn |= ten_hl_n10g_config (module_id, slice, TEN_N10G_RX_OTU2_10GE, TEN_N10G_TX_10GE_OTU2, dyn_repro);
          
          /* Bug #39241 - Signal conditioning should not be done by T41 datapath configuration APIs */
          #if (TEN_HL_OHPP_DISABLE_ODUK_OCI == 1) 
          rtn |= ten_hl_ohpp_control_oduk_oci (module_id, slice, CS_DISABLE);
          #endif

          rtn |= ten_n10g_oohr_cfg5_bipmsk(module_id, slice, 0xFF);
          if (tcm_bits != 0) {
            rtn |= ten_n10g_otnt_bipmsk (module_id, slice, 0x81 | tcm_bits);
          }
          else {
            rtn |= ten_n10g_otnt_bipmsk (module_id, slice, 0xFF); /* Enable BIP calculation at Tx OTU2 SM, PM and TCM */
          }
          
          rtn |= ten_n10g_otnr_set_g43md (module_id, slice, 0);
          rtn |= ten_n10g_otnt_set_g43md (module_id, slice, 0);

          /* Set MFASINS to insert multi-frame alignment counter (MFAS) count in data stream Always */
          rtn |= ten_n10g_otnt_cfg0_mfasins (module_id, slice, 3);

          /* MFALGNE = 0x0    Disables the MFAS alignment process */
          rtn |= ten_n10g_otnt_cfg0_mfalgne (module_id, slice, 0);

          /* Set TDELON/TDELOFF for 3ms */
          rtn |= ten_hl_n10g_config_lom_from_traffic (module_id, slice, mapper, fec);
             
          rtn |= ten_n10g_gblr_set_xsel(module_id, slice, 0x2);
          /* Set STM 64 */
          rtn |= ten_n10g_otnr_set_stm64md(module_id, slice, 0);
          rtn |= ten_n10g_otnt_set_stm64md(module_id, slice, 0);

          Cm    = (cs_uint16) (pdevcb->syncdsync_thread_cb[slice].cn_bytes_n10g / timeslots);  /*Bugzilla 26308*/
          Cn_hi = (cs_uint16) (pdevcb->syncdsync_thread_cb[slice].cn_bytes_n10g >> 16);
          Cn_lo = (cs_uint16) (pdevcb->syncdsync_thread_cb[slice].cn_bytes_n10g & 0x0000ffff);

          rtn |= ten_n10g_tx_gmp_lo_t41( module_id, slice );
          rtn |= ten_n10g_rx_gmp_lo_t41( module_id, slice );
          rtn |= ten_n10g_tx_gmp_cm_cn_t41( module_id, slice, Cm, Cn_lo, Cn_hi);
          rtn |= ten_n10g_rx_gmp_cn_t41( module_id, slice, Cn_lo, Cn_hi);         /*Bugzilla 36501*/
          break;

        case TEN_TRAFFIC_TYPE_ODTU :
          /* Line side Muxponder */
          rtn |= ten_hl_n10g_config (module_id, slice, TEN_N10G_RX_OXU3J_ODU2E_10GE, TEN_N10G_TX_10GE_OXU3, dyn_repro);

          rtn |= ten_n10g_otnt_scrambling (module_id, slice, 0, 0);   /* Turn off scramblers */
          rtn |= ten_n10g_otnr_descrambling (module_id, slice, 0, 0); /* Turn off scramblers */

          /* Bug #39241 - Signal conditioning should not be done by T41 datapath configuration APIs */
          #if (TEN_HL_OHPP_DISABLE_ODUK_OCI == 1) 
          rtn |= ten_hl_ohpp_control_oduk_oci (module_id, slice, CS_DISABLE);
          #endif

          /* Bugzilla 37928 - Need to disable dLOS generation since ODU2 is unscrambled */
          rtn |= ten_n10g_gblr_loscfg0 (module_id, slice, 3);

          rtn |= ten_n10g_otnr_set_g43md (module_id, slice, 0);
          rtn |= ten_n10g_otnt_set_g43md (module_id, slice, 0);

          /* Set MFASINS to insert multi-frame alignment counter (MFAS) count in data stream Always */
          rtn |= ten_n10g_otnt_cfg0_mfasins (module_id, slice, 3);
          /* MFALGNE = 0x0    Disables the MFAS alignment process */
          rtn |= ten_n10g_otnt_cfg0_mfalgne (module_id, slice, 0);
          /* Set TDELON/TDELOFF for 3ms */
          rtn |= ten_hl_n10g_config_lom_from_traffic (module_id, slice, TEN_TRAFFIC_TYPE_OTU2, TEN_FEC_MODE_NOFEC);

          /* Overwrite columns */
          rtn |= ten_n10g_set_otnr_odwfs(module_id, slice, 0);
          rtn |= ten_n10g_otnt_set_wrpfs(module_id, slice, 0);
        
          /* process 1st-level mappings - Bugzilla 36501*/
          /* Bugzilla 37001 Start: false positive error for map_oxuv!=TEN_MAP_GMP_LO fixed */
          if (map_oxuv == TEN_MAP_GMP_LO) {
              Cm    = (cs_uint16) (pdevcb->syncdsync_thread_cb[slice].cn_bytes_n10g / timeslots);  /*Bugzilla 26308*/
              Cn_hi = (cs_uint16) (pdevcb->syncdsync_thread_cb[slice].cn_bytes_n10g >> 16);
              Cn_lo = (cs_uint16) (pdevcb->syncdsync_thread_cb[slice].cn_bytes_n10g & 0x0000ffff);

              rtn |= ten_n10g_tx_gmp_lo_t41( module_id, slice );
              rtn |= ten_n10g_rx_gmp_lo_t41( module_id, slice );
              rtn |= ten_n10g_tx_gmp_cm_cn_t41( module_id, slice, Cm, Cn_lo, Cn_hi);
              rtn |= ten_n10g_rx_gmp_cn_t41( module_id, slice, Cn_lo, Cn_hi);
          }    
          /* Bugzilla 37001 End */      
          break;

        default :
          CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, "%s()  Unexpected line type %d for this Ethernet client", func, mapper);
          return (CS_ERROR);
          break;
      }
      break;


    case TEN_TRAFFIC_TYPE_8GFC_RA :  /* client */
    case TEN_TRAFFIC_TYPE_4GFC_RA :
    case TEN_TRAFFIC_TYPE_2GFC_RA :
    case TEN_TRAFFIC_TYPE_1GFC_RA :
      switch (mapper) {
        /* 1/2/4/8 GFC RA->1/2/4/8 GFC RA Transponder Client side */
        case TEN_TRAFFIC_TYPE_8GFC_RA :
        case TEN_TRAFFIC_TYPE_4GFC_RA :
        case TEN_TRAFFIC_TYPE_2GFC_RA :
        case TEN_TRAFFIC_TYPE_1GFC_RA :
          /* process 1st-level mappings */
          rtn |= ten_hl_n10g_config(module_id, slice, TEN_N10G_RX_BYPASS, TEN_N10G_TX_BYPASS,dyn_repro);
          /* PTI setting for 8GFC */
          /* rtn |= ten_n10g_set_pktie(module_id, slice, 1); */
          /* Set MFASINS to insert multi-frame alignment counter (MFAS) count in data stream Always */
          rtn |= ten_n10g_otnt_cfg0_mfasins(module_id,   slice,   3);
          /* MFALGNE = 0x0    Disables the MFAS alignment process */
          rtn |= ten_n10g_otnt_cfg0_mfalgne(module_id,   slice,   0);
          break;

        /* 1/2/4/8 GFC RA->OTU2 10G Transponder Line side */
        case TEN_TRAFFIC_TYPE_OTU2 :
          /* process 1st-level mappings */
          rtn |= ten_hl_n10g_config(module_id, slice, TEN_N10G_RX_OTU2_8GFC, TEN_N10G_TX_8GFC_OTU2, dyn_repro);
          /* Bug 29757 Start */
          /* Clear the ODU2 OCI that the null config set up */
          /* Bug #39241 - Signal conditioning should not be done by T41 datapath configuration APIs */
          #if (TEN_HL_OHPP_DISABLE_ODUK_OCI == 1) 
          rtn |= ten_hl_ohpp_control_oduk_oci (module_id, slice, CS_DISABLE);
          #endif

          /* Bug 29757 End */
         
          /* Bug #37028 - OTN BIP8 mask not enabled properly for different mapping modes */
          rtn |= ten_n10g_oohr_cfg5_bipmsk(module_id, slice, 0xFF);
          if (tcm_bits != 0) {
            rtn |= ten_n10g_otnt_bipmsk (module_id, slice, 0x81 | tcm_bits);
          }
          else {
            rtn |= ten_n10g_otnt_bipmsk (module_id, slice, 0xFF); /* Enable BIP calculation at Tx OTU2 SM, PM and TCM */
          }

         /* PTI setting for 8GFC */
          /* rtn |= ten_n10g_set_pktie(module_id, slice, 1); */
          /* Set MFASINS to insert multi-frame alignment counter (MFAS) count in data stream Always */
          rtn |= ten_n10g_otnt_cfg0_mfasins(module_id,   slice,   3);
          /* MFALGNE = 0x0    Disables the MFAS alignment process */
          rtn |= ten_n10g_otnt_cfg0_mfalgne(module_id,   slice,   0);
          break;

        /* 1/2/4/8 GFC RA->ODTU 40G Muxponder Line side */
        case TEN_TRAFFIC_TYPE_ODTU :
          /* process 1st-level mappings */
          rtn |= ten_hl_n10g_config(module_id, slice, TEN_N10G_RX_ODU2J_8GFC, TEN_N10G_TX_8GFC_ODU2J, dyn_repro);
          /* Bug 29757 Start */
          /* Clear the ODU2 OCI that the null config set up */
          /* Bug #39241 - Signal conditioning should not be done by T41 datapath configuration APIs */
          #if (TEN_HL_OHPP_DISABLE_ODUK_OCI == 1) 
          rtn |= ten_hl_ohpp_control_oduk_oci (module_id, slice, CS_DISABLE);
          #endif

          /* Bug 29757 End */
          /* Line side OTU scrambling done in N40G block */
          rtn |= ten_n10g_otnt_scrambling(module_id, slice, 0, 0);
          rtn |= ten_n10g_otnr_descrambling(module_id, slice, 0, 0);
          
          /* Bug #37028 - OTN BIP8 mask not enabled properly for different mapping modes */
          rtn |= ten_n10g_oohr_cfg5_bipmsk(module_id, slice, 0xFF);
          if (tcm_bits != 0) {
            rtn |= ten_n10g_otnt_bipmsk (module_id, slice, 0x81 | tcm_bits);
          }
          else {
            rtn |= ten_n10g_otnt_bipmsk (module_id, slice, 0xFF); /* Enable BIP calculation at Tx OTU2 SM, PM and TCM */
          }

          /* rtn |= ten_n10g_set_pktie(module_id, slice, 1); */
          /* Set TDELON/TDELOFF for 3ms */
          rtn |= ten_n10g_otnr_lofcfg_tdelon_tdeloff(module_id, slice, 492*239/255, 492*239/255);
          rtn |= ten_n10g_gblr_set_xsel(module_id, slice, 0x2);
          /* Set STM 64 */
          rtn |= ten_n10g_otnr_set_stm64md(module_id, slice, 0);
          rtn |= ten_n10g_otnt_set_stm64md(module_id, slice, 0);
          /* Set MFASINS to insert multi-frame alignment counter (MFAS) count in data stream Always */
          rtn |= ten_n10g_otnt_cfg0_mfasins(module_id,   slice,   3);
          /* MFALGNE = 0x0    Disables the MFAS alignment process */
          rtn |= ten_n10g_otnt_cfg0_mfalgne(module_id,   slice,   0);
          break;

        /* 1/2/4/8 GFC RA->OC192 10G Transponder Line side */
        case TEN_TRAFFIC_TYPE_OC192:
          rtn |= ten_hl_n10g_config (module_id, slice, TEN_N10G_RX_OC192_10GE, TEN_N10G_TX_10GE_OC192, dyn_repro);
          break;

        default :
          CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, "%s()  Unhandled default case 1/2/4/8GFC RA ODU2", func);
          break;
      }
      break;

    /* Bugzilla 26608 Start */
    case TEN_TRAFFIC_TYPE_8GFC_ENH :  /* client */
      switch (mapper) {
        /* 8GFC ENH->OTU2 10G Transponder Line side */
        case TEN_TRAFFIC_TYPE_OTU2 :
          /* process 1st-level mappings */
          rtn |= ten_hl_n10g_config(module_id, slice, TEN_N10G_RX_OTU2EJ_8GFC, TEN_N10G_TX_8GFC_OTU2EJ, dyn_repro);
          /* Bug 29757 Start */
          /* Clear the ODU2 OCI that the null config set up */
          /* Bug #39241 - Signal conditioning should not be done by T41 datapath configuration APIs */
          #if (TEN_HL_OHPP_DISABLE_ODUK_OCI == 1) 
          rtn |= ten_hl_ohpp_control_oduk_oci (module_id, slice, CS_DISABLE);
          #endif

          /* Bug 29757 End */
          rtn |= ten_n10g_set_otnr_odwfs(module_id, slice, 2278);
          rtn |= ten_n10g_otnt_set_wrpfs(module_id, slice, 2278);
          /* Line side OTU scrambling done in N40G block */
          rtn |= ten_n10g_otnt_scrambling(module_id, slice, 0, 0);
          rtn |= ten_n10g_otnr_descrambling(module_id, slice, 0, 0);

          /* Bug #37028 - OTN BIP8 mask not enabled properly for different mapping modes */
          rtn |= ten_n10g_oohr_cfg5_bipmsk(module_id, slice, 0xFF);
          if (tcm_bits != 0) {
            rtn |= ten_n10g_otnt_bipmsk (module_id, slice, 0x81 | tcm_bits);
          }
          else {
            rtn |= ten_n10g_otnt_bipmsk (module_id, slice, 0xFF); /* Enable BIP calculation at Tx OTU2 SM, PM and TCM */
          }

          /* Set TDELON/TDELOFF for 3ms */
          rtn |= ten_n10g_otnr_lofcfg_tdelon_tdeloff(module_id, slice, 492*239/255, 492*239/255);
          rtn |= ten_n10g_gblr_set_xsel(module_id, slice, 0x2);
          /* Set STM 64 */
          rtn |= ten_n10g_otnr_set_stm64md(module_id, slice, 0);
          rtn |= ten_n10g_otnt_set_stm64md(module_id, slice, 0);
          break;

        /* 8GFC ENH->OTU2E 10G Transponder Line side */
        case TEN_TRAFFIC_TYPE_OTU2E :
          /* process 1st-level mappings */
          rtn |= ten_hl_n10g_config(module_id, slice, TEN_N10G_RX_OTU2EJ_8GFC, TEN_N10G_TX_8GFC_OTU2EJ, dyn_repro);
          /* Bug 29757 Start */
          /* Clear the ODU2 OCI that the null config set up */
          /* Bug #39241 - Signal conditioning should not be done by T41 datapath configuration APIs */
          #if (TEN_HL_OHPP_DISABLE_ODUK_OCI == 1) 
          rtn |= ten_hl_ohpp_control_oduk_oci (module_id, slice, CS_DISABLE);
          #endif

          /* Bug 29757 End */
          rtn |= ten_n10g_set_otnr_odwfs(module_id, slice, 2729);
          rtn |= ten_n10g_otnt_set_wrpfs(module_id, slice, 2729);
          /* Line side OTU scrambling done in N40G block */
          rtn |= ten_n10g_otnt_scrambling(module_id, slice, 0, 0);
          rtn |= ten_n10g_otnr_descrambling(module_id, slice, 0, 0);
          
          /* Bug #37028 - OTN BIP8 mask not enabled properly for different mapping modes */
          rtn |= ten_n10g_oohr_cfg5_bipmsk(module_id, slice, 0xFF);
          if (tcm_bits != 0) {
            rtn |= ten_n10g_otnt_bipmsk (module_id, slice, 0x81 | tcm_bits);
          }
          else {
            rtn |= ten_n10g_otnt_bipmsk (module_id, slice, 0xFF); /* Enable BIP calculation at Tx OTU2 SM, PM and TCM */
          }

          /* Set TDELON/TDELOFF for 3ms */
          rtn |= ten_n10g_otnr_lofcfg_tdelon_tdeloff(module_id, slice, 492*239/255, 492*239/255);
          rtn |= ten_n10g_gblr_set_xsel(module_id, slice, 0x2);
          /* Set STM 64 */
          rtn |= ten_n10g_otnr_set_stm64md(module_id, slice, 0);
          rtn |= ten_n10g_otnt_set_stm64md(module_id, slice, 0);
          break;

        /* 8GFC ENH->ODTU 40G Muxponder Line side */
        case TEN_TRAFFIC_TYPE_ODTU :
          /* process 1st-level mappings */
          rtn |= ten_hl_n10g_config(module_id, slice, TEN_N10G_RX_ODU2J_8GFC, TEN_N10G_TX_8GFC_ODU2J, dyn_repro);
          /* Bug 29757 Start */
          /* Clear the ODU2 OCI that the null config set up */
          /* Bug #39241 - Signal conditioning should not be done by T41 datapath configuration APIs */
          #if (TEN_HL_OHPP_DISABLE_ODUK_OCI == 1) 
          rtn |= ten_hl_ohpp_control_oduk_oci (module_id, slice, CS_DISABLE);
          #endif

          /* Bug 29757 End */
          rtn |= ten_n10g_set_otnr_odwfs(module_id, slice, 2278);
          rtn |= ten_n10g_otnt_set_wrpfs(module_id, slice, 2278);
          /* Line side OTU scrambling done in N40G block */
          rtn |= ten_n10g_otnt_scrambling(module_id, slice, 0, 0);
          rtn |= ten_n10g_otnr_descrambling(module_id, slice, 0, 0);
          
          /* Bug #37028 - OTN BIP8 mask not enabled properly for different mapping modes */
          rtn |= ten_n10g_oohr_cfg5_bipmsk(module_id, slice, 0xFF);
          if (tcm_bits != 0) {
            rtn |= ten_n10g_otnt_bipmsk (module_id, slice, 0x81 | tcm_bits);
          }
          else {
            rtn |= ten_n10g_otnt_bipmsk (module_id, slice, 0xFF); /* Enable BIP calculation at Tx OTU2 SM, PM and TCM */
          }

          /* Set TDELON/TDELOFF for 3ms */
          rtn |= ten_n10g_otnr_lofcfg_tdelon_tdeloff(module_id, slice, 492*239/255, 492*239/255);
          rtn |= ten_n10g_gblr_set_xsel(module_id, slice, 0x2);
          /* Set STM 64 */
          rtn |= ten_n10g_otnr_set_stm64md(module_id, slice, 0);
          rtn |= ten_n10g_otnt_set_stm64md(module_id, slice, 0);
          break;

        default :
          CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, "%s() Unhandled default case 1/2/4/8GFC ENH", func);
          break;
      }
      break;
  
    case TEN_TRAFFIC_TYPE_4GFC_ENH :  /* client */
      switch (mapper) {
        /* 4GFC ENH->OTU2 10G Transponder Line side */
        case TEN_TRAFFIC_TYPE_OTU2 :
          /* process 1st-level mappings */
          rtn |= ten_hl_n10g_config(module_id, slice, TEN_N10G_RX_OTU2EJ_8GFC, TEN_N10G_TX_8GFC_OTU2EJ, dyn_repro);
          /* Bug 29757 Start */
          /* Clear the ODU2 OCI that the null config set up */
           /* Bug #39241 - Signal conditioning should not be done by T41 datapath configuration APIs */
          #if (TEN_HL_OHPP_DISABLE_ODUK_OCI == 1) 
          rtn |= ten_hl_ohpp_control_oduk_oci (module_id, slice, CS_DISABLE);
          #endif

          /* Bug 29757 End */
          rtn |= ten_n10g_set_otnr_odwfs(module_id, slice, 8755);
          rtn |= ten_n10g_otnt_set_wrpfs(module_id, slice, 8755);
          /* Line side OTU scrambling done in N40G block */
          rtn |= ten_n10g_otnt_scrambling(module_id, slice, 0, 0);
          rtn |= ten_n10g_otnr_descrambling(module_id, slice, 0, 0);

          /* Bug #37028 - OTN BIP8 mask not enabled properly for different mapping modes */
          rtn |= ten_n10g_oohr_cfg5_bipmsk(module_id, slice, 0xFF);
          if (tcm_bits != 0) {
            rtn |= ten_n10g_otnt_bipmsk (module_id, slice, 0x81 | tcm_bits);
          }
          else {
            rtn |= ten_n10g_otnt_bipmsk (module_id, slice, 0xFF); /* Enable BIP calculation at Tx OTU2 SM, PM and TCM */
          }

          /* Set TDELON/TDELOFF for 3ms */
          rtn |= ten_n10g_otnr_lofcfg_tdelon_tdeloff(module_id, slice, 492*239/255, 492*239/255);
          rtn |= ten_n10g_gblr_set_xsel(module_id, slice, 0x2);
          /* Set STM 64 */
          rtn |= ten_n10g_otnr_set_stm64md(module_id, slice, 0);
          rtn |= ten_n10g_otnt_set_stm64md(module_id, slice, 0);
          break;

        /* 4GFC ENH->OTU2E 10G Transponder Line side */
        case TEN_TRAFFIC_TYPE_OTU2E :
          /* process 1st-level mappings */
          rtn |= ten_hl_n10g_config(module_id, slice, TEN_N10G_RX_OTU2EJ_8GFC, TEN_N10G_TX_8GFC_OTU2EJ, dyn_repro);
          /* Bug 29757 Start */
          /* Clear the ODU2 OCI that the null config set up */
          /* Bug #39241 - Signal conditioning should not be done by T41 datapath configuration APIs */
          #if (TEN_HL_OHPP_DISABLE_ODUK_OCI == 1) 
          rtn |= ten_hl_ohpp_control_oduk_oci (module_id, slice, CS_DISABLE);
          #endif

          /* Bug 29757 End */
          rtn |= ten_n10g_set_otnr_odwfs(module_id, slice, 8981);
          rtn |= ten_n10g_otnt_set_wrpfs(module_id, slice, 8981);
          /* Line side OTU scrambling done in N40G block */
          rtn |= ten_n10g_otnt_scrambling(module_id, slice, 0, 0);
          rtn |= ten_n10g_otnr_descrambling(module_id, slice, 0, 0);

          /* Bug #37028 - OTN BIP8 mask not enabled properly for different mapping modes */
          rtn |= ten_n10g_oohr_cfg5_bipmsk(module_id, slice, 0xFF);
          if (tcm_bits != 0) {
            rtn |= ten_n10g_otnt_bipmsk (module_id, slice, 0x81 | tcm_bits);
          }
          else {
            rtn |= ten_n10g_otnt_bipmsk (module_id, slice, 0xFF); /* Enable BIP calculation at Tx OTU2 SM, PM and TCM */
          }

          /* Set TDELON/TDELOFF for 3ms */
          rtn |= ten_n10g_otnr_lofcfg_tdelon_tdeloff(module_id, slice, 492*239/255, 492*239/255);
          rtn |= ten_n10g_gblr_set_xsel(module_id, slice, 0x2);
          /* Set STM 64 */
          rtn |= ten_n10g_otnr_set_stm64md(module_id, slice, 0);
          rtn |= ten_n10g_otnt_set_stm64md(module_id, slice, 0);
          break;


        /* 4GFC ENH->ODTU 40G Muxponder Line side */
        case TEN_TRAFFIC_TYPE_ODTU :
          /* process 1st-level mappings */
          rtn |= ten_hl_n10g_config(module_id, slice, TEN_N10G_RX_ODU2J_8GFC, TEN_N10G_TX_8GFC_ODU2J, dyn_repro);
          /* Bug 29757 Start */
          /* Clear the ODU2 OCI that the null config set up */
          /* Bug #39241 - Signal conditioning should not be done by T41 datapath configuration APIs */
          #if (TEN_HL_OHPP_DISABLE_ODUK_OCI == 1) 
          rtn |= ten_hl_ohpp_control_oduk_oci (module_id, slice, CS_DISABLE);
          #endif

          /* Bug 29757 End */
          rtn |= ten_n10g_set_otnr_odwfs(module_id, slice, 8755);
          rtn |= ten_n10g_otnt_set_wrpfs(module_id, slice, 8755);
          /* Line side OTU scrambling done in N40G block */
          rtn |= ten_n10g_otnt_scrambling(module_id, slice, 0, 0);
          rtn |= ten_n10g_otnr_descrambling(module_id, slice, 0, 0);

          /* Bug #37028 - OTN BIP8 mask not enabled properly for different mapping modes */
          rtn |= ten_n10g_oohr_cfg5_bipmsk(module_id, slice, 0xFF);
          if (tcm_bits != 0) {
            rtn |= ten_n10g_otnt_bipmsk (module_id, slice, 0x81 | tcm_bits);
          }
          else {
            rtn |= ten_n10g_otnt_bipmsk (module_id, slice, 0xFF); /* Enable BIP calculation at Tx OTU2 SM, PM and TCM */
          }
 
          /* Set TDELON/TDELOFF for 3ms */
          rtn |= ten_n10g_otnr_lofcfg_tdelon_tdeloff(module_id, slice, 492*239/255, 492*239/255);
          rtn |= ten_n10g_gblr_set_xsel(module_id, slice, 0x2);
          /* Set STM 64 */
          rtn |= ten_n10g_otnr_set_stm64md(module_id, slice, 0);
          rtn |= ten_n10g_otnt_set_stm64md(module_id, slice, 0);
          break;

        default :
          CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, "%s() Unhandled default case 1/2/4/8GFC ENH", func);
          break;
      }
      break;

    case TEN_TRAFFIC_TYPE_2GFC_ENH :  /* client */
      switch (mapper) {
        /* 2GFC ENH->OTU2 10G Transponder Line side */
        case TEN_TRAFFIC_TYPE_OTU2 :
          /* process 1st-level mappings */
          rtn |= ten_hl_n10g_config(module_id, slice, TEN_N10G_RX_OTU2EJ_8GFC, TEN_N10G_TX_8GFC_OTU2EJ, dyn_repro);
          /* Bug 29757 Start */
          /* Clear the ODU2 OCI that the null config set up */
          /* Bug #39241 - Signal conditioning should not be done by T41 datapath configuration APIs */
          #if (TEN_HL_OHPP_DISABLE_ODUK_OCI == 1) 
          rtn |= ten_hl_ohpp_control_oduk_oci (module_id, slice, CS_DISABLE);
          #endif

          /* Bug 29757 End */
          rtn |= ten_n10g_set_otnr_odwfs(module_id, slice, 11994);
          rtn |= ten_n10g_otnt_set_wrpfs(module_id, slice, 11994);
          /* Line side OTU scrambling done in N40G block */
          rtn |= ten_n10g_otnt_scrambling(module_id, slice, 0, 0);
          rtn |= ten_n10g_otnr_descrambling(module_id, slice, 0, 0);

          /* Bug #37028 - OTN BIP8 mask not enabled properly for different mapping modes */
          rtn |= ten_n10g_oohr_cfg5_bipmsk(module_id, slice, 0xFF);
          if (tcm_bits != 0) {
            rtn |= ten_n10g_otnt_bipmsk (module_id, slice, 0x81 | tcm_bits);
          }
          else {
            rtn |= ten_n10g_otnt_bipmsk (module_id, slice, 0xFF); /* Enable BIP calculation at Tx OTU2 SM, PM and TCM */
          }

          /* Set TDELON/TDELOFF for 3ms */
          rtn |= ten_n10g_otnr_lofcfg_tdelon_tdeloff(module_id, slice, 492*239/255, 492*239/255);
          rtn |= ten_n10g_gblr_set_xsel(module_id, slice, 0x2);
          /* Set STM 64 */
          rtn |= ten_n10g_otnr_set_stm64md(module_id, slice, 0);
          rtn |= ten_n10g_otnt_set_stm64md(module_id, slice, 0);
          break;

        /* 2GFC ENH->OTU2E 10G Transponder Line side */
        case TEN_TRAFFIC_TYPE_OTU2E :
          /* process 1st-level mappings */
          rtn |= ten_hl_n10g_config(module_id, slice, TEN_N10G_RX_OTU2EJ_8GFC, TEN_N10G_TX_8GFC_OTU2EJ, dyn_repro);
          /* Bug 29757 Start */
          /* Clear the ODU2 OCI that the null config set up */
          /* Bug #39241 - Signal conditioning should not be done by T41 datapath configuration APIs */
          #if (TEN_HL_OHPP_DISABLE_ODUK_OCI == 1) 
          rtn |= ten_hl_ohpp_control_oduk_oci (module_id, slice, CS_DISABLE);
          #endif

          /* Bug 29757 End */
          rtn |= ten_n10g_set_otnr_odwfs(module_id, slice, 12106);
          rtn |= ten_n10g_otnt_set_wrpfs(module_id, slice, 12106);
          /* Line side OTU scrambling done in N40G block */
          rtn |= ten_n10g_otnt_scrambling(module_id, slice, 0, 0);
          rtn |= ten_n10g_otnr_descrambling(module_id, slice, 0, 0);

          /* Bug #37028 - OTN BIP8 mask not enabled properly for different mapping modes */
          rtn |= ten_n10g_oohr_cfg5_bipmsk(module_id, slice, 0xFF);
          if (tcm_bits != 0) {
            rtn |= ten_n10g_otnt_bipmsk (module_id, slice, 0x81 | tcm_bits);
          }
          else {
            rtn |= ten_n10g_otnt_bipmsk (module_id, slice, 0xFF); /* Enable BIP calculation at Tx OTU2 SM, PM and TCM */
          }
          /* Set TDELON/TDELOFF for 3ms */
          rtn |= ten_n10g_otnr_lofcfg_tdelon_tdeloff(module_id, slice, 492*239/255, 492*239/255);
          rtn |= ten_n10g_gblr_set_xsel(module_id, slice, 0x2);
          /* Set STM 64 */
          rtn |= ten_n10g_otnr_set_stm64md(module_id, slice, 0);
          rtn |= ten_n10g_otnt_set_stm64md(module_id, slice, 0);
          break;


        /* 2GFC ENH->ODTU 40G Muxponder Line side */
        case TEN_TRAFFIC_TYPE_ODTU :
          /* process 1st-level mappings */
          rtn |= ten_hl_n10g_config(module_id, slice, TEN_N10G_RX_ODU2J_8GFC, TEN_N10G_TX_8GFC_ODU2J, dyn_repro);
          /* Bug 29757 Start */
          /* Clear the ODU2 OCI that the null config set up */
          /* Bug #39241 - Signal conditioning should not be done by T41 datapath configuration APIs */
          #if (TEN_HL_OHPP_DISABLE_ODUK_OCI == 1) 
          rtn |= ten_hl_ohpp_control_oduk_oci (module_id, slice, CS_DISABLE);
          #endif

          /* Bug 29757 End */
          rtn |= ten_n10g_set_otnr_odwfs(module_id, slice, 11994);
          rtn |= ten_n10g_otnt_set_wrpfs(module_id, slice, 11994);
          /* Line side OTU scrambling done in N40G block */
          rtn |= ten_n10g_otnt_scrambling(module_id, slice, 0, 0);
          rtn |= ten_n10g_otnr_descrambling(module_id, slice, 0, 0);

          /* Bug #37028 - OTN BIP8 mask not enabled properly for different mapping modes */
          rtn |= ten_n10g_oohr_cfg5_bipmsk(module_id, slice, 0xFF);
          if (tcm_bits != 0) {
            rtn |= ten_n10g_otnt_bipmsk (module_id, slice, 0x81 | tcm_bits);
          }
          else {
            rtn |= ten_n10g_otnt_bipmsk (module_id, slice, 0xFF); /* Enable BIP calculation at Tx OTU2 SM, PM and TCM */
          }

          /* Set TDELON/TDELOFF for 3ms */
          rtn |= ten_n10g_otnr_lofcfg_tdelon_tdeloff(module_id, slice, 492*239/255, 492*239/255);
          rtn |= ten_n10g_gblr_set_xsel(module_id, slice, 0x2);
          /* Set STM 64 */
          rtn |= ten_n10g_otnr_set_stm64md(module_id, slice, 0);
          rtn |= ten_n10g_otnt_set_stm64md(module_id, slice, 0);
          break;

        default :
          CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, "%s() Unhandled default case 1/2/4/8GFC ENH", func);
          break;
      }
      break;
    /* Bugzilla 26608 End */

    /* No bugzilla. Adds framework for ODUFLEX support */
    case TEN_TRAFFIC_TYPE_ODUFLEX :  /* client */
      switch (mapper) {
        /* ODUFLEX->OTU2 */
        case TEN_TRAFFIC_TYPE_OTU2 :
          rtn |= ten_hl_n10g_config(module_id, slice,       /* set basic config */
                                    TEN_N10G_RX_OTU2_ODU2, 
                                    TEN_N10G_TX_OPU2_OTU2,
                                    dyn_repro);
          rtn |=  ten_n10g_tx_oduflex_t41 (module_id, slice);
          rtn |=  ten_n10g_rx_oduflex_t41 (module_id, slice);

         /* ODUFLEX->ODTU */
        case TEN_TRAFFIC_TYPE_ODTU :
          rtn |= ten_hl_n10g_config(module_id, slice,       /* set basic config */
                                    TEN_N10G_RX_OXU3_ODU2, 
                                    TEN_N10G_TX_ODU2_OXU3,
                                    dyn_repro);
          rtn |=  ten_n10g_tx_oduflex_aggr_t41 (module_id, slice);
          rtn |=  ten_n10g_rx_odu2aggr_t41 (module_id, slice);
          break;
        default :
          CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, "%s()  Unexpected line type %d for this FiberChannel client", func,  mapper);
          return (CS_ERROR);              /* <<<<<<<<<<<<<<<  EARLY EXIT ON FAILURE <<<<<<<up to calling function to report error */
      } /* end switch mapper */

      /* process 1st-level mappings */
      switch (map_oxuv) {
        case TEN_MAP_BMP :
        case TEN_MAP_DONT_CARE :
          rtn |= ten_n10g_set_otnt_wrpcfg4 (module_id, slice, 0, 0, 0, 0, 0); /* jc_plus_odtu23, jc_plus_otu2, jcen_dt, jcen_odtu23 and jcen_otu2 */
          rtn |= ten_n10g_otnr_set_dwmod (module_id, slice, 1);               /* Dewrapper enabled Justification commands are ignored */
          break;
        case TEN_MAP_AMP :
          rtn |= ten_n10g_set_otnt_wrpcfg4 (module_id, slice, 0, 0, 0, 0, 1); /* jc_plus_odtu23, jc_plus_otu2, jcen_dt, jcen_odtu23 and jcen_otu2 */
          rtn |= ten_n10g_otnr_set_dwmod (module_id, slice, 3);               /* Dewrapper enabled Justification commands are evaluated */
          break;
        case TEN_MAP_AMP_PROP :
          rtn |= ten_n10g_set_otnt_wrpcfg4 (module_id, slice, 0, 1, 0, 0, 1); /* jc_plus_odtu23, jc_plus_otu2, jcen_dt, jcen_odtu23 and jcen_otu2 */
          rtn |= ten_n10g_tx_amp_prop_t41( module_id, slice, 0); /* hardcode to 0 since 0c192 client fits. For FC use pdevcb->syncdsync_thread_cb[slice].num_just_oxu2); */
          rtn |= ten_n10g_otnr_set_dwmod ( module_id, slice, 3);              /* Dewrapper enabled Justification commands are evaluated */
          rtn |= ten_n10g_rx_amp_prop_t41( module_id, slice, 0); /* hardcode to 0 since 0c192 client fits. For FC use pdevcb->syncdsync_thread_cb[slice].num_just_oxu2); */ 
          break;
        case TEN_MAP_GMP_LO :
          Cm = (cs_uint16) (pdevcb->syncdsync_thread_cb[slice].cn_bytes_n10g / timeslots);  /*Bugzilla 26308, 36501*/

          rtn |= ten_n10g_set_otnt_wrpcfg4(module_id, slice, 0, 0, 0, 1, 0); /* jc_plus_odtu23, jc_plus_otu2, jcen_dt, jcen_odtu23 and jcen_otu2 */

          rtn |= ten_n10g_tx_gmp_lo_t41( module_id, slice );
          rtn |= ten_n10g_rx_gmp_lo_t41( module_id, slice );
          rtn |= ten_n10g_otnr_set_dwmod(module_id, slice, 3);               /* Dewrapper enabled Justification commands are evaluated */

          rtn |= ten_n10g_tx_gmp_cm_cn_t41( module_id, slice, Cm, /* cm, cn bit 16, cn 0-15 */
                                                              (cs_uint16)(pdevcb->syncdsync_thread_cb[slice].cn_bytes_n10g) & 0xffff,
                                                              (cs_uint16)(pdevcb->syncdsync_thread_cb[slice].cn_bytes_n10g)>>16);   /*Bugzilla 36501*/
          rtn |= ten_n10g_rx_gmp_cn_t41( module_id, slice, 
                                         (cs_uint16) (pdevcb->syncdsync_thread_cb[slice].cn_bytes_n10g) & 0xffff,
                                         (cs_uint16) (pdevcb->syncdsync_thread_cb[slice].cn_bytes_n10g)>>16); /*  cn bit 16, cn 0-15 - Bugzilla 36501*/
          break;
    default :
          CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, "%s: ODUflex->OTU2, map_oxuv=%d not supported\n", func, map_oxuv);
      rtn |= CS_ERROR;
      break;
      } /* end switch 1st-level mapping */
      break;
      /* No bugzilla. End framework for ODUFLEX */


    case TEN_TRAFFIC_TYPE_10G_IB :  /* client */
    case TEN_TRAFFIC_TYPE_FDR10_IB :  /* Bugzilla 39242 */
      switch (mapper) {
        /* 5/10 IB->OTU2E */
        case TEN_TRAFFIC_TYPE_OTU2E :
          /* Line side 10G Transponder */
          switch (map_oxuv) {
            case TEN_MAP_GMP_LO :
              /* process 1st-level mappings */
              rtn |= ten_hl_n10g_config (module_id, slice, TEN_N10G_RX_OTU2E_10GE, TEN_N10G_TX_10GE_OTU2E, dyn_repro);
              /* Clear the ODU2 OCI that the null config set up */
              /* Bug #39241 - Signal conditioning should not be done by T41 datapath configuration APIs */
              #if (TEN_HL_OHPP_DISABLE_ODUK_OCI == 1) 
              rtn |= ten_hl_ohpp_control_oduk_oci (module_id, slice, CS_DISABLE);
              #endif

              /* Bug #37028 - OTN BIP8 mask not enabled properly for different mapping modes */
              rtn |= ten_n10g_oohr_cfg5_bipmsk(module_id, slice, 0xFF);
              if (tcm_bits != 0) {
                rtn |= ten_n10g_otnt_bipmsk (module_id, slice, 0x81 | tcm_bits);
              }
              else {
                rtn |= ten_n10g_otnt_bipmsk (module_id, slice, 0xFF); /* Enable BIP calculation at Tx OTU2 SM, PM and TCM */
              }

              rtn |= ten_n10g_gblr_set_xsel(module_id, slice, 0x2);
              /* Set STM 64 */
              rtn |= ten_n10g_otnr_set_stm64md(module_id, slice, 0);
              rtn |= ten_n10g_otnt_set_stm64md(module_id, slice, 0);
              /* Set MFASINS to insert multi-frame alignment counter (MFAS) count in data stream Always */
              rtn |= ten_n10g_otnt_cfg0_mfasins(module_id,   slice,   3);
              /* MFALGNE = 0x0    Disables the MFAS alignment process */
              rtn |= ten_n10g_otnt_cfg0_mfalgne(module_id,   slice,   0);

              Cm    = (cs_uint16) (pdevcb->syncdsync_thread_cb[slice].cn_bytes_n10g / timeslots);  /*Bugzilla 26308, 36501*/
              Cn_hi = (cs_uint16) (pdevcb->syncdsync_thread_cb[slice].cn_bytes_n10g >> 16);        /*Bugzilla 36501*/
              Cn_lo = (cs_uint16) (pdevcb->syncdsync_thread_cb[slice].cn_bytes_n10g & 0x0000ffff); /*Bugzilla 36501*/

              rtn |= ten_n10g_tx_gmp_lo_t41( module_id, slice );
              rtn |= ten_n10g_rx_gmp_lo_t41( module_id, slice );
              rtn |= ten_n10g_tx_gmp_cm_cn_t41( module_id, slice, Cm, Cn_lo, Cn_hi);
              rtn |= ten_n10g_rx_gmp_cn_t41( module_id, slice, Cn_lo, Cn_hi);          /*Bugzilla 36501*/
              break;

            case TEN_MAP_AMP : /* Bugzilla 39393 */
            case TEN_MAP_AMP_PROP :
              /* process 1st-level mappings */
              rtn |= ten_hl_n10g_config (module_id, slice, TEN_N10G_RX_OTU2E_10GE, TEN_N10G_TX_10GE_OTU2E, dyn_repro);
              /* Clear the ODU2 OCI that the null config set up */
              /* Bug #39241 - Signal conditioning should not be done by T41 datapath configuration APIs */
              #if (TEN_HL_OHPP_DISABLE_ODUK_OCI == 1) 
              rtn |= ten_hl_ohpp_control_oduk_oci (module_id, slice, CS_DISABLE);
              #endif

              /* Overwrite FS, JC, JC_PLUS, DWMOD */
              rtn |= ten_n10g_otnt_set_wrpfs(module_id, slice, 522);
              rtn |= ten_n10g_set_otnt_wrpcfg4(module_id, slice, 0, 1, 0, 0, 1); /* jc_plus_odtu23, jc_plus_otu2, jcen_dt, jcen_odtu23 and jcen_otu2 */
              rtn |= ten_n10g_set_otnr_odwfs(module_id, slice, 522);
              rtn |= ten_n10g_otnr_set_jc_plus(module_id, slice, 1);
              rtn |= ten_n10g_otnr_set_dwmod(module_id, slice, 3);               /* Dewrapper enabled Justification commands are evaluated */
              /* Bug #37028 - OTN BIP8 mask not enabled properly for different mapping modes */
              rtn |= ten_n10g_oohr_cfg5_bipmsk(module_id, slice, 0xFF);
              if (tcm_bits != 0) {
                rtn |= ten_n10g_otnt_bipmsk (module_id, slice, 0x81 | tcm_bits);
              }
              else {
                rtn |= ten_n10g_otnt_bipmsk (module_id, slice, 0xFF); /* Enable BIP calculation at Tx OTU2 SM, PM and TCM */
              }

              rtn |= ten_n10g_gblr_set_xsel(module_id, slice, 0x2);
              /* Set STM 64 */
              rtn |= ten_n10g_otnr_set_stm64md(module_id, slice, 0);
              rtn |= ten_n10g_otnt_set_stm64md(module_id, slice, 0);
              /* Set MFASINS to insert multi-frame alignment counter (MFAS) count in data stream Always */
              rtn |= ten_n10g_otnt_cfg0_mfasins(module_id,   slice,   3);
              /* MFALGNE = 0x0    Disables the MFAS alignment process */
              rtn |= ten_n10g_otnt_cfg0_mfalgne(module_id,   slice,   0);
              break;
            default:
              CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, "%s()  Unexpected line type %d for client Infinband", func, map_oxuv);
              return (CS_ERROR);
              break;
          }
          break;

       /* Bugzilla 38565 Start */
       /* 10G_IB->ODTU 40G Muxponder Line side GMP_LO/GMP_HO_DT*/
        case TEN_TRAFFIC_TYPE_ODTU :
          /* process 1st-level mappings */
          rtn |= ten_hl_n10g_config(module_id, slice, TEN_N10G_RX_ODU2J_8GFC, TEN_N10G_TX_8GFC_ODU2J, dyn_repro);
          /* Clear the ODU2 OCI that the null config set up */
          /* Bug #39241 - Signal conditioning should not be done by T41 datapath configuration APIs */
          #if (TEN_HL_OHPP_DISABLE_ODUK_OCI == 1) 
          rtn |= ten_hl_ohpp_control_oduk_oci (module_id, slice, CS_DISABLE);
          #endif

          if (map_oxuv != TEN_MAP_GMP_LO) { /* Bugzilla 39393 */
              /* Overwrite FS, JC, JC_PLUS, DWMOD */
              rtn |= ten_n10g_otnt_set_wrpfs(module_id, slice, 522);
              rtn |= ten_n10g_set_otnt_wrpcfg4(module_id, slice, 1, 1, 0, 1, 1); /* jc_plus_odtu23, jc_plus_otu2, jcen_dt, jcen_odtu23 and jcen_otu2 */
              rtn |= ten_n10g_set_otnr_odwfs(module_id, slice, 522);
              rtn |= ten_n10g_otnr_set_jc_plus(module_id, slice, 1);
              rtn |= ten_n10g_otnr_set_dwmod(module_id, slice, 3);               /* Dewrapper enabled Justification commands are evaluated */
          }
          /* Line side OTU scrambling done in N40G block */
          rtn |= ten_n10g_otnt_scrambling(module_id, slice, 0, 0);
          rtn |= ten_n10g_otnr_descrambling(module_id, slice, 0, 0);
          
          rtn |= ten_n10g_oohr_cfg5_bipmsk(module_id, slice, 0xFF);
          if (tcm_bits != 0) {
            rtn |= ten_n10g_otnt_bipmsk (module_id, slice, 0x81 | tcm_bits);
          }
          else {
            rtn |= ten_n10g_otnt_bipmsk (module_id, slice, 0xFF); /* Enable BIP calculation at Tx OTU2 SM, PM and TCM */
          }
          
          /* Set TDELON/TDELOFF for 3ms */
          rtn |= ten_n10g_otnr_lofcfg_tdelon_tdeloff(module_id, slice, 492*239/255, 492*239/255);
          rtn |= ten_n10g_gblr_set_xsel(module_id, slice, 0x2);
          /* Set STM 64 */
          rtn |= ten_n10g_otnr_set_stm64md(module_id, slice, 0);
          rtn |= ten_n10g_otnt_set_stm64md(module_id, slice, 0);
          /* Set MFASINS to insert multi-frame alignment counter (MFAS) count in data stream Always */
          rtn |= ten_n10g_otnt_cfg0_mfasins(module_id,   slice,   3);
          /* MFALGNE = 0x0    Disables the MFAS alignment process */
          rtn |= ten_n10g_otnt_cfg0_mfalgne(module_id,   slice,   0);

          rtn |= ten_n10g_oohr_jcsquelch (module_id, slice, TEN_JCSQLCH_LOS, 0);
          rtn |= ten_n10g_gblr_loscfg0 (module_id, slice, 3);
          
          if (map_oxuv == TEN_MAP_GMP_LO) { /* Bugzilla 39393 */
            /* Clear FS */
            rtn |= ten_n10g_set_otnr_odwfs(module_id, slice, 0);
            rtn |= ten_n10g_otnt_set_wrpfs(module_id, slice, 0);

            Cm    = (cs_uint16) (pdevcb->syncdsync_thread_cb[slice].cn_bytes_n10g / timeslots);  /*Bugzilla 26308*/
            Cn_hi = (cs_uint16) (pdevcb->syncdsync_thread_cb[slice].cn_bytes_n10g >> 16);
            Cn_lo = (cs_uint16) (pdevcb->syncdsync_thread_cb[slice].cn_bytes_n10g & 0x0000ffff);

            rtn |= ten_n10g_tx_gmp_lo_t41( module_id, slice );
            rtn |= ten_n10g_rx_gmp_lo_t41( module_id, slice );
            rtn |= ten_n10g_tx_gmp_cm_cn_t41( module_id, slice, Cm, Cn_lo, Cn_hi);
            rtn |= ten_n10g_rx_gmp_cn_t41( module_id, slice, Cn_lo, Cn_hi);
          }
          break;
        /* Bugzilla 38565 End */

        default :
          CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, "%s()  Unexpected line type %d for this Infiniband client", func, mapper);
          return (CS_ERROR);
          break;
      }
      break;


    default :
      CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, "%s: Client type %d not supported. Line type %d\n", func, client, mapper);
      return CS_ERROR;
      break;
  } /* end case client=TEN_TRAFFIC_TYPE_ODUFLEX */

  if (mapper != TEN_TRAFFIC_TYPE_OC192) {
    /* A client is being mapped into a OTN */
    rtn |= ten_hl_n10g_config_pti_t41 (module_id, slice, client, mapper, map_oxuv, timeslots, TEN_KPG_DISABLED);
  }

  /* process 2nd-level mappings. These selections must be validated above according to client and line */
  switch (map_odtu) {
    case TEN_MAP_DONT_CARE: /* 10G transponder should break out of this switch */
      break;

    case TEN_MAP_AMP :    /* Some of this rewrites registers written by T40 code. */
      rtn |= ten_n10g_otnt_set_jc_odtu23(module_id, slice, 0, 0, 1);     /* jc_plus_odtu23, jcen_dt, jcen_odtu23                   */
      rtn |= ten_n10g_otnr_set_dwmod(module_id, slice, 3);               /* Dewrapper enabled Justification commands are evaluated */
      break;

    case TEN_MAP_AMP_PROP : /* Not handled by T40 code */
      rtn |= ten_n10g_otnt_set_jc_odtu23(module_id, slice, 1, 0, 1);     /* jc_plus_odtu23, jcen_dt, jcen_odtu23                   */
      rtn |= ten_n10g_otnr_set_dwmod(module_id, slice, 3);               /* Dewrapper enabled Justification commands are evaluated */
      break;

    case TEN_MAP_GMP_HO : /* Not handled by T40 code */
      rtn |= ten_n10g_mux_mapper_t41 (module_id, client, slice, mapper, map_oxuv, map_odtu, timeslots, gmp_timeslot_mask);  /* Bugzilla 28237 */
      break;


    case TEN_MAP_AMP_PROP_DT :
    case TEN_MAP_AMP_DT :
    case TEN_MAP_GMP_HO_DT :
      rtn |= ten_n10g_tx_odtu_detamp_t41 ( module_id, slice );
      rtn |= ten_n10g_otnr_set_dwmod(module_id, slice, 3);               /* Dewrapper enabled Justification commands are evaluated */
      break;

    default :
      CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, "%s()  map_odtu %d invalid for client %d->line %d", func, map_odtu, client, mapper);
      break;
  }

  if (rtn != CS_OK) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, "%s()  FAILED!\n", func);
  }

  return (rtn);
}
/* Bugzilla 24360 End */

/****************************************************************/
/* $rtn_hdr_start  HIGH LEVEL N10G CONFIG LOF OF FRAME          */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : HIGH LEVEL CONFIG                               */
/* CHIP       : Tenabo                                          */
cs_status ten_hl_n10g_config_lof_from_traffic (cs_uint16 module_id,
                                               cs_uint8  slice,
                                               cs_uint16 traffic_type,
                                               cs_uint16 fec)
/* INPUTS     : o Module Id                                     */
/*              o Slice                                         */
/*              o Traffic Type                                  */
/*              o Fec                                           */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* Provision Loss Of frame for N10G block for 3ms given         */
/* the traffic type and fec                                     */
/*                                                              */
/* [module_id] parameter specifies line's module ID             */
/* 16 devices can be registered and module bit indicates line   */
/* or client side of the registered device. The registered      */
/* device is identified by the dev_id bits specified below      */
/*   Bits 11:8 – dev_id, Bits 7:1 – don’t care, Bit 0 – module  */
/*                                                              */
/* [slice] specifies slice:                                     */
/*   0x00 = TEN_SLICE0                                          */
/*   0x01 = TEN_SLICE1                                          */
/*   0x02 = TEN_SLICE2                                          */
/*   0x03 = TEN_SLICE3                                          */
/*                                                              */
/* [traffic_type] parameter specifies the traffic type          */
/*   TEN_TRAFFIC_TYPE_OTU2  = 5                                 */
/*   TEN_TRAFFIC_TYPE_OTU2E = 6                                 */
/*   TEN_TRAFFIC_TYPE_OTU1F = 7                                 */
/*   TEN_TRAFFIC_TYPE_10GE_GFPF_OC192_ODU2 = 28                 */
/*   TEN_TRAFFIC_TYPE_OTU1E = 29                                */
/*   TEN_TRAFFIC_TYPE_OC192_OTU2 = 31                           */
/*                                                              */
/* The [line_fec] parameter is specified as:                    */
/*   TEN_FEC_MODE_OTUkV             = 0,   (UFEC  7%)           */
/*   TEN_FEC_MODE_OTUkV_262         = 1,   (UFEC 10%)           */
/*   TEN_FEC_MODE_OTUkV_273         = 2,   (UFEC 15%)           */
/*   TEN_FEC_MODE_OTUkV_285         = 3,   (UFEC 20%)           */
/*   TEN_FEC_MODE_OTUkV_297         = 4,   (UFEC 25%)           */
/*   TEN_FEC_MODE_OTUkV_5_4         = 5,   (UFEC 25%)           */
/*   TEN_FEC_MODE_OTUkV_301         = 6,   (UFEC 26%)           */
/*   TEN_FEC_MODE_OTUkV_SDH_A       = 7,   (UFEC  7%)           */
/*   TEN_FEC_MODE_OTUkV_SDH_B       = 8,   (UFEC  7%)           */
/*   TEN_FEC_MODE_OTUkV_4080_3929   = 9,   (UFEC 3.4%)          */
/*   TEN_FEC_MODE_OTUkV_68_65       = 10,  (UFEC 4.2%)          */
/*   TEN_FEC_MODE_OTUkV_267         = 11,  (UFEC 12%)           */
/*   TEN_FEC_MODE_OTUkV_270         = 12,  (UFEC 13%)           */
/*   TEN_FEC_MODE_GFEC              = 13,  (GFEC 7%)            */
/*   TEN_FEC_MODE_ZERO_FEC          = 14,  (FEC all zeroes)     */
/*   TEN_FEC_MODE_NOFEC             = 15   (FEC not present)    */
/*   TEN_FEC_MODE_DEALLOCATE        = 16,  (Power down FEC)     */
/*   TEN_FEC_MODE_OTUkV_263         = 17,  (UFEC 7%)            */
/*   TEN_FEC_MODE_OTUkV_280         = 18,  (UFEC 18%)           */
/*   TEN_FEC_MODE_OTUkV_295         = 19,  (UFEC 25%)           */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  double signal_rate;
  T41_t *pDev = NULL;
  cs_status rtn = CS_OK;
  cs_char8 *func = "ten_hl_n10g_config_lof_from_traffic";  

  TEN_MOD_COMMON_VALIDATE (module_id, pDev, CS_ERROR);

  if (slice >= TEN_MAX_SLICES) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, "%s() slice %d out of range.  s/b 0..3.", func, slice);
    return (CS_ERROR);
  }

  if ((traffic_type != TEN_TRAFFIC_TYPE_OTU2) && (traffic_type != TEN_TRAFFIC_TYPE_OTU2E) &&
      (traffic_type != TEN_TRAFFIC_TYPE_OTU1E) && (traffic_type != TEN_TRAFFIC_TYPE_OTU1F) &&
      (traffic_type != TEN_TRAFFIC_TYPE_OC192_OTU2) && (traffic_type != TEN_TRAFFIC_TYPE_10GE_GFPF_OC192_ODU2)) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, "%s() traffic_type %d out of range.", func, traffic_type);
    return (CS_ERROR);
  }

  if (fec >= TEN_FEC_MODE_MAX_NUM) {     /* Bugzilla 29274 */
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, "%s() fec %d out of range.  s/b 0..%d.", func, fec, (TEN_FEC_MODE_MAX_NUM-1));
    return (CS_ERROR);
  }

  CS_PRINT("%s() %s, Slice %d, %s, %s\n",
           func,
           ten_module_strings[module_id & 1],
           slice,
           ten_hl_config_traffic_types_strings[traffic_type],
           ten_fec_ovhd_strings[fec]);

  /* Bugzilla 29274 Start */
  if (fec == TEN_FEC_MODE_DEALLOCATE) {
    fec = TEN_FEC_MODE_NOFEC;
  }
  /* Bugzilla 29274 End */

  /* Get signal rate on line */
  signal_rate = ten_calculate_signal_rate (traffic_type, fec);

  CS_PRINT("%s() signal_rate = %f\n", func, signal_rate);
  if (signal_rate == 0) {
    /* Line signal rate could not be found */
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, "%s() Traffic %s with fec %s not supported\n",
                  func, ten_hl_config_traffic_types_strings[traffic_type], ten_fec_ovhd_strings[fec]);
    return (CS_ERROR);
  }

  rtn |= ten_hl_n10g_config_lof_from_bps(module_id, slice, signal_rate);

  return (rtn);
}

/****************************************************************/
/* $rtn_hdr_start  HIGH LEVEL N10G CONFIG LOF                   */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : HIGH LEVEL CONFIG                               */
/* CHIP       : Tenabo                                          */
cs_status ten_hl_n10g_config_lof_from_bps(cs_uint16 module_id,
                                          cs_uint8  slice,
                                          double signal_rate)
/* INPUTS     : o Module Id                                     */
/*              o Slice                                         */
/*              o Signal Rate                                   */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* Provision Loss Of frame for N10G block for 3ms given         */
/* the Bits Per Second.                                         */
/*                                                              */
/* [module_id] parameter specifies line's module ID             */
/* 16 devices can be registered and module bit indicates line   */
/* or client side of the registered device. The registered      */
/* device is identified by the dev_id bits specified below      */
/* Bits 11:8 – dev_id, Bits 7:1 – don’t care, Bit 0 – module    */
/*                                                              */
/* [slice] specifies slice:                                     */
/*   0x00 = TEN_SLICE0                                          */
/*   0x01 = TEN_SLICE1                                          */
/*   0x02 = TEN_SLICE2                                          */
/*   0x03 = TEN_SLICE3                                          */
/*                                                              */
/* [signal_rate] parameter specifies line Bits Per Second       */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  cs_uint32 temp_tdel_on_off;
  cs_uint16 tdel_on_off;
  T41_t *pDev = NULL;
  cs_status rtn = CS_OK;
  cs_char8 *func = "ten_hl_n10g_config_lof_from_bps";

  TEN_MOD_COMMON_VALIDATE (module_id, pDev, CS_ERROR);

  CS_PRINT("%s() %s, Slice %d, %f\n",
           func,
           ten_module_strings[module_id & 1],
           slice,
           signal_rate);

  /* Compute Time Delay: tdel = (signal rate/65280) * 0.003s */
  /* Half of a tdel unit is added to signal rate before the devide to round 0.5 up to 1. Half =(65280/(2*0.003))*/
  temp_tdel_on_off = ((signal_rate + (65280/(2*0.003))) / (65280/0.003));
  tdel_on_off = (cs_uint16)temp_tdel_on_off;

  rtn |= ten_n10g_otnr_lofcfg_tdelon_tdeloff (module_id, slice, tdel_on_off, tdel_on_off);

  return (rtn);
}

/* Bugzilla 24956 End */

/* Bugzilla 24956 Start */
/****************************************************************/
/* $rtn_hdr_start  HIGH LEVEL N10G CONFIG LOS OF MULTIFRAME     */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : HIGH LEVEL CONFIG                               */
/* CHIP       : Tenabo                                          */
cs_status ten_hl_n10g_config_lom_from_traffic (cs_uint16 module_id,
                                               cs_uint8  slice,
                                               cs_uint16 traffic_type,
                                               cs_uint16 fec)
/* INPUTS     : o Module Id                                     */
/*              o Slice                                         */
/*              o Traffic Type                                  */
/*              o Fec                                           */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* Provision Loss Of Multiframe for N10G block for 3ms given    */
/* the traffic type and fec                                     */
/*                                                              */
/* [module_id] parameter specifies line's module ID             */
/* 16 devices can be registered and module bit indicates line   */
/* or client side of the registered device. The registered      */
/* device is identified by the dev_id bits specified below      */
/*   Bits 11:8 – dev_id, Bits 7:1 – don’t care, Bit 0 – module  */
/*                                                              */
/* [slice] specifies slice:                                     */
/*   0x00 = TEN_SLICE0                                          */
/*   0x01 = TEN_SLICE1                                          */
/*   0x02 = TEN_SLICE2                                          */
/*   0x03 = TEN_SLICE3                                          */
/*                                                              */
/* [traffic_type] parameter specifies the traffic type          */
/*   TEN_TRAFFIC_TYPE_OTU2  = 5                                 */
/*   TEN_TRAFFIC_TYPE_OTU2E = 6                                 */
/*   TEN_TRAFFIC_TYPE_OTU1F = 7                                 */
/*   TEN_TRAFFIC_TYPE_10GE_GFPF_OC192_ODU2 = 28                 */
/*   TEN_TRAFFIC_TYPE_OTU1E = 29                                */
/*   TEN_TRAFFIC_TYPE_OC192_OTU2 = 31                           */
/*                                                              */
/* The [line_fec] parameter is specified as:                    */
/*   TEN_FEC_MODE_OTUkV             = 0,   (UFEC  7%)           */
/*   TEN_FEC_MODE_OTUkV_262         = 1,   (UFEC 10%)           */
/*   TEN_FEC_MODE_OTUkV_273         = 2,   (UFEC 15%)           */
/*   TEN_FEC_MODE_OTUkV_285         = 3,   (UFEC 20%)           */
/*   TEN_FEC_MODE_OTUkV_297         = 4,   (UFEC 25%)           */
/*   TEN_FEC_MODE_OTUkV_5_4         = 5,   (UFEC 25%)           */
/*   TEN_FEC_MODE_OTUkV_301         = 6,   (UFEC 26%)           */
/*   TEN_FEC_MODE_OTUkV_SDH_A       = 7,   (UFEC  7%)           */
/*   TEN_FEC_MODE_OTUkV_SDH_B       = 8,   (UFEC  7%)           */
/*   TEN_FEC_MODE_OTUkV_4080_3929   = 9,   (UFEC 3.4%)          */
/*   TEN_FEC_MODE_OTUkV_68_65       = 10,  (UFEC 4.2%)          */
/*   TEN_FEC_MODE_OTUkV_267         = 11,  (UFEC 12%)           */
/*   TEN_FEC_MODE_OTUkV_270         = 12,  (UFEC 13%)           */
/*   TEN_FEC_MODE_GFEC              = 13,  (GFEC 7%)            */
/*   TEN_FEC_MODE_ZERO_FEC          = 14,  (FEC all zeroes)     */
/*   TEN_FEC_MODE_NOFEC             = 15   (FEC not present)    */
/*   TEN_FEC_MODE_DEALLOCATE        = 16,  (Power down FEC)     */
/*   TEN_FEC_MODE_OTUkV_263         = 17,  (UFEC 7%)            */
/*   TEN_FEC_MODE_OTUkV_280         = 18,  (UFEC 18%)           */
/*   TEN_FEC_MODE_OTUkV_295         = 19,  (UFEC 25%)           */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  double signal_rate;
  T41_t *pDev = NULL;
  cs_status rtn = CS_OK;
  cs_char8 *func = "ten_hl_n10g_config_lom_from_traffic";  

  TEN_MOD_COMMON_VALIDATE (module_id, pDev, CS_ERROR);

  if (slice >= TEN_MAX_SLICES) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, "%s() slice %d out of range.  s/b 0..3.", func, slice);
    return (CS_ERROR);
  }

  if ((traffic_type != TEN_TRAFFIC_TYPE_OTU2) && (traffic_type != TEN_TRAFFIC_TYPE_OTU2E) &&
      (traffic_type != TEN_TRAFFIC_TYPE_OTU1E) && (traffic_type != TEN_TRAFFIC_TYPE_OTU1F) &&
      (traffic_type != TEN_TRAFFIC_TYPE_OC192_OTU2) && (traffic_type != TEN_TRAFFIC_TYPE_10GE_GFPF_OC192_ODU2)) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, "%s() traffic_type %d out of range.", func, traffic_type);
    return (CS_ERROR);
  }

  if (fec >= TEN_FEC_MODE_MAX_NUM) {     /* Bugzilla 29274 */
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, "%s() fec %d out of range.  s/b 0..%d.", func, fec, (TEN_FEC_MODE_MAX_NUM-1));
    return (CS_ERROR);
  }

  CS_PRINT("%s() %s, Slice %d, %s, %s\n",
           func,
           ten_module_strings[module_id & 1],
           slice,
           ten_hl_config_traffic_types_strings[traffic_type],
           ten_fec_ovhd_strings[fec]);

  /* Bugzilla 29274 Start */
  if (fec == TEN_FEC_MODE_DEALLOCATE) {
    fec = TEN_FEC_MODE_NOFEC;
  }
  /* Bugzilla 29274 End */

  /* Get signal rate on line */
  signal_rate = ten_calculate_signal_rate (traffic_type, fec);

  CS_PRINT("%s() signal_rate = %f\n", func, signal_rate);
  if (signal_rate == 0) {
    /* Line signal rate could not be found */
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, "%s() Traffic %s with fec %s not supported\n",
                  func, ten_hl_config_traffic_types_strings[traffic_type], ten_fec_ovhd_strings[fec]);
    return (CS_ERROR);
  }

  rtn |= ten_hl_n10g_config_lom_from_bps (module_id, slice, signal_rate);

  return (rtn);
}

/****************************************************************/
/* $rtn_hdr_start  HIGH LEVEL N10G CONFIG LOM                   */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : HIGH LEVEL CONFIG                               */
/* CHIP       : Tenabo                                          */
cs_status ten_hl_n10g_config_lom_from_bps (cs_uint16 module_id,
                                           cs_uint8  slice,
                                           double signal_rate)
/* INPUTS     : o Module Id                                     */
/*              o Slice                                         */
/*              o Signal Rate                                   */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* Provision Loss Of Multiframe for N10G block for 3ms given    */
/* the Bits Per Second.                                         */
/*                                                              */
/* [module_id] parameter specifies line's module ID             */
/* 16 devices can be registered and module bit indicates line   */
/* or client side of the registered device. The registered      */
/* device is identified by the dev_id bits specified below      */
/* Bits 11:8 – dev_id, Bits 7:1 – don’t care, Bit 0 – module    */
/*                                                              */
/* NOTE:  N10G_OOHR_LOMCFG0::TDELON is actually calculated      */
/*   from sys clock, not signal rate.  This API automatically   */
/*   performs the calculation based on sys clock instead of     */
/*   signal_rate.                                               */
/*   N10G_OOHR_LOMCFG1.bf.TDELOFF is set to 1.                  */
/*                                                              */
/* [slice] specifies slice:                                     */
/*   0x00 = TEN_SLICE0                                          */
/*   0x01 = TEN_SLICE1                                          */
/*   0x02 = TEN_SLICE2                                          */
/*   0x03 = TEN_SLICE3                                          */
/*                                                              */
/* [signal_rate] parameter specifies line Bits Per Second       */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  cs_uint16 tdel_on;
  T41_t *pDev = NULL;
  cs_status rtn = CS_OK;
  cs_char8 *func = "ten_hl_n10g_config_lom_from_bps";  
  double temp_tdel_on_double;
  ten_dev_cb_t *pdevcb;

  TEN_MOD_COMMON_VALIDATE (module_id, pDev, CS_ERROR);

  CS_PRINT("%s() %s, Slice %d, %f\n",
           func,
           ten_module_strings[module_id & 1],
           slice,
           signal_rate);
  
  /* Bugzilla #32196, calculate N10G_OOHR_LOMCFG0 from sysclk instead of signal rate */
  pdevcb = TEN_DEV_ID_TO_DEVCB_PTR(TEN_MOD_ID_TO_DEV_ID(module_id));
  CS_PRINT("sysclk = %d\n", pdevcb->sysclock);
  
  /* Compute 3ms = OOHR_LOMCFG0:TDELON * 2040 x T_system_clock from DS 2.6.9.5 Multiframe Alignment Signal (MFAS) */
  temp_tdel_on_double = (0.003 * pdevcb->sysclock)/2040.0;
  temp_tdel_on_double += 0.5;  /* to round 0.5 up to 1.0 */
  CS_PRINT("temp_tdel_on_double = %f\n", temp_tdel_on_double);
  tdel_on = (cs_uint16)temp_tdel_on_double;
  
  CS_PRINT("tdel_on = %d\n", tdel_on);

  /* Bug #37828:  ten_hl_n10g_config_lom_from_traffic causes bus errors in T40 */
  if (ten_dev_is_t41(TEN_MOD_ID_TO_DEV_ID(module_id))) {
    rtn |= ten_n10g_oohr_lomcfg_tdelon_tdeloff(module_id, slice, tdel_on, 1);
  
    /* the consequent actions based on LOM will be driven from the filtered FLOM instead of the unfiltered one. */
    rtn |= ten_n10g_oohr_cfg11_flomen(module_id, slice, 1);
  }
  
  /* Provision MFAS De-Synchronization and Synchronization hysteresis */
  rtn |= ten_n10g_oohr_cfg0 (module_id, slice, 5, 2); /* mfdsyh, mfsyhy */

  return (rtn);
}
/* Bugzilla 24956 End */


/***********************************************************************/
/* FUNCTION : ten_hl_oc192_termination_path_client_side()              */
/***********************************************************************/
/* This helper function does not need an API appearance. This function */
/* is defined specifically for the client side as indicated by high-   */
/* level callers such as ten_hl_oc192_termination_path()               */
/***********************************************************************/
cs_status ten_hl_oc192_termination_path_client_side (
                                         cs_uint16 module_id_client,
                                         cs_uint16 slice_client,
                                         cs_uint16 term)
{
  cs_char8 *func = "ten_hl_oc192_termination_path_client_side";  

  if (term == TEN_OC192_TERM_TRANSPARENT_CBR10) {
      /* RX Client */
      /* XSEL = 2, SBYPLD = 1 (bypass SONET/SDH processing) */
      /* DPCFG_XSEL needs to change */
      ten_n10g_set_gblr_dpcfg(module_id_client, slice_client,
                      2,  /* xsel */
                      0,  /* kpasel */
                      1,  /* sbypld */
                      0,  /* sbyfrm */
                      1,  /* oby */
                      0,  /* sdhoff */
                      1); /* otnoff */
      /* LOS reported to OHPP */
      /* SDH processor may optionally be used for non-intrusive monitoring */

      /* TX Client */
      /* SBY = 0 (must not bypass SONET/SDH processor for consequent action insertion) */
      /* SOHT_OHBEN0 = 0x00, SOHT_OHBEN1 = 0x00, SOHT_OHBEN2 = 0x00 (disable all SONET/SDH insertion) */
      /* SOHT.OHBEN0_SCREN (1=enable SONET scrambling) need to change */
      /* SOHT.OHBEN0_A1A2RSH (1=regenerate A1A2) need to change */
      ten_n10g_soht_set_ohben0(module_id_client, slice_client,
                      0,  /* b1ie */
                      0,  /* scren */
                      0,  /* a1a2rsh */
                      0); /* a1a2ie */
      /* SFU inserts STM-AIS as consequent action if OTN defect detected on line side */
      /* Optionally do this */

      /* Bugzilla 32383 Start: All trans mappings should have B2IE=0 */
      ten_n10g_soht_b2ie(module_id_client, slice_client, TEN_INSTANCE_ALL, 0);
      /* Bugzilla 32383 End */
  }
  else if (term == TEN_OC192_TERM_TRANSPARENT_REGENERATOR) {
      /* RX Client Side: */
      /* XSEL = 1, SBYFRM = 0  (Framed SONET/SDH through the XCON) */
      /* SDFR_SDFCFG.SCREN = 1 */
      /* LOS , LOF, and STM-AIS reported to OHPP */
      /* SDH Processor and PP10G may optionally be  */
      /* used for non-intrusive monitoring */
      /* Table is OK */

      /* TX Client Side: */
      /* SBY = 0 (Do not bypass SDH Processor) */
      /* SOHT_OHBEN0 = 0x08 (A1A2RSH), SOHT_OHBEN1 = 0x00, SOHT_OHBEN2 = 0x00 (disable all SONET/SDH insertion but turn on scrambling) */
      /* SFU inserts MS-AIS (AIS-L) as consequent action if LOF/STM-AIS or OTN defect detected on line RX (this must include setting SOHT_OHBEN0.B1IE=1) */
      ten_n10g_soht_set_ohben0(module_id_client, slice_client,
                      0,  /* b1ie */
                      1,  /* scren */
                      1,  /* a1a2rsh */
                      0); /* a1a2ie */
      ten_n10g_soht_b2ie(module_id_client, slice_client, TEN_INSTANCE_ALL, 0);
      /* config_b2(module_id_client, slice_client, 0); */
  }
  else if (term == TEN_OC192_TERM_RS_LAYER_REGENERATOR) {
      /* RX Client Side: */
      /* XSEL = 1, SBYFRM = 0  (Framed SONET/SDH through the XCON) */
      /* SDFR_SDFCFG.SCREN = 1 */
      /* LOS , LOF, STM-AIS, RS-TIM, AIS-L defects reported to OHPP */
      /* Set SOHR_S1CFG.B1TRANS=1 */
      /* SDH Processor and PP10G may optionally be used for non-intrusive monitoring */
      /* SOHR_S1CFG.B1TRANS needs to change */
      ten_n10g_sohr_set_byte_err_trans_mode(module_id_client, slice_client,
                      1,  /* b1trans */
                      0); /* b2trans */

      /* TX Client Side: */
      /* SBY = 0 (Do not bypass SDH Processor) */
      /* In SOHT, set SCREN=1, A1A2RSH=1, B1IE =1 */
      /* In SOHT, enable RSOH bytes that are to be sourced  */
      /*(others will be transparently passed through) */
      /* If B1 error transparency is desired, set B1TRANS=1 in SOHT_OHBEN1 */
      /* SFU inserts MS-AIS (AIS-L) as consequent action if */
      /* LOF/STM-AIS/MS-AIS or optionally RS-TIM  */
      /* or OTN defect detected on line RX */
      /* Table is OK */
  }
  else if (term == TEN_OC192_TERM_MS_LAYER_REGENERATOR) {
      /* RX Client Side: */
      /* XSEL = 1, SBYFRM = 0  (Framed SONET/SDH through the XCON) */
      /* SDFR_SDFCFG.SCREN = 1 */
      /* LOS , LOF, STM-AIS, RS-TIM, AIS-L, dEXC, dLOP, AU-AIS  */
      /* defects reported to OHPP */
      /* Set SOHR_S1CFG.B1TRANS=1 */
      /* Set SOHR_S1CFG.B2TRANS=1 */
      /* SDH Processor and PP10G may optionally be used for non-intrusive monitoring */
      /* B1TRANS and B2TRANS need to change */
      ten_n10g_sohr_set_byte_err_trans_mode(module_id_client, slice_client,
                      1,  /* b1trans */
                      1); /* b2trans */

      /* TX Client Side: */
      /* SBY = 0 (Do not bypass SDH Processor) */
      /* In SOHT, set SCREN=1, A1A2RSH=1, B1IE =1, B2IE=1 */
      /* In SOHT, enable RSOH/MSOH bytes that are to be sourced */
      /* (others will be transparently passed through) */
      /* If B1 error transparency is desired, set B1TRANS=1 in SOHT_OHBEN1 */
      /* If B2 error transparency is desired, set B2TRANS=1 in SOHT_OHBEN1 */
      /* SFU inserts MS-RDI (RDI-L) as consequent action */
      /* if LOS/LOF/MS-AIS detected on client RX */
      /* SFU inserts MS-REI (REI-L) based on number of B2  */
      /* errors detected on client RX */
      /* SFU inserts MS-AIS (AIS-L) as consequent action  */
      /* if LOF/STM-AIS/MS-AIS or optionally RS-TIM/dEXC  */
      /* or OTN defect detected on line RX */
      /* Optionally insert AU-AIS as consequent action */
      /* if dLOP/AU-AIS detected on line RX */
      /* B1IE and B2IE need to change */
      ten_n10g_soht_set_ohben0(module_id_client, slice_client,
                      1,  /* b1ie */
                      1,  /* scren */
                      1,  /* a1a2rsh */
                      0); /* a1a2ie */
      ten_n10g_soht_b2ie(module_id_client, slice_client, TEN_INSTANCE_ALL, 0xFFFF);
      /* config_b2(module_id_client, slice_client, 0xffff); */
  }
  else {
    CS_HNDL_ERROR (module_id_client, ETEN_MOD_INVALID_USER_ARG, "%s() term %d is invalid.", func, term);
    return(CS_ERROR);
  }
  return (CS_OK);
}

/***********************************************************************/
/* FUNCTION : ten_hl_oc192_termination_path_line_side()                */
/***********************************************************************/
/* This helper function does not need an API appearance. This function */
/* is defined specifically for the line side as indicated by highlevel */
/* callers such as ten_hl_oc192_termination_path()                     */
/***********************************************************************/
cs_status ten_hl_oc192_termination_path_line_side (
                                         cs_uint16 module_id_line,
                                         cs_uint16 slice_line,
                                         cs_uint16 term)
{
  /* if ($term eq 'trans') { */
  if (term == TEN_OC192_TERM_TRANSPARENT_CBR10) {
      /* TX Line (mapping) */
      /* SBY = 1 (bypass SONET/SDH processing) */
      /* GBLT.CFGTX0_SBY (0=bypass disabled) needs to change */
      ten_n10g_set_gblt_bypasses(module_id_line, slice_line,
                      0,  /* otnoff */
                      0,  /* oby */
                      1,  /* sby */
                      1); /* kpgby */
      if (ten_dev_is_t41_ptr(TEN_MOD_ID_TO_DEVCB_PTR(module_id_line))) {
        ten_n10g_tx_bypass_t41 ( module_id_line, slice_line, 0 );  /* gbl_bypcfg.TX_BYPASS=0, CLKTX_DIS=0 */
      }
      /* SFU inserts CBRGENAIS as consequent action if LOS detected on client RX */
      /* Optionally do this */

      /* RX Line (demapping) */
      /* XSEL = 2, SBYPLD = 1 (bypass SONET/SDH processing) */
      /* DPCFG_XSEL needs to change */
      ten_n10g_set_gblr_dpcfg(module_id_line, slice_line,
                      2,  /* xsel */
                      0,  /* kpasel */
                      1,  /* sbypld */
                      0,  /* sbyfrm */
                      0,  /* oby */
                      0,  /* sdhoff */
                      0); /* otnoff */
      /* OTN layer defects reported to OHPP */
      /* SDH processor may optionally be used for non-intrusive monitoring,  */
      /* otherwise set SDHE = 0 to save power */
      /* SDHE not set by the table */
  }
  /* elsif ($term eq 'transregen') { */
  else if (term == TEN_OC192_TERM_TRANSPARENT_REGENERATOR) {
      /* TX Line Side (Mapping): */
      /* SBY = 0 (Do not bypass SONET/SDH processing) */
      /* SOHT_OHBEN0 = 0x08 (A1A2RSH), SOHT_OHBEN1 = 0x00,  */
      /* SOHT_OHBEN2 = 0x00 (disable all SONET/SDH insertion */
      /* but turn on scrambling) */
      /* SFU inserts MS-AIS (AIS-L) as consequent action if */
      /* LOS/LOF/STM-AIS detected on client RX  */
      /* (this must include setting SOHT_OHBEN0.B1IE=1) */
      ten_n10g_soht_set_ohben0(module_id_line, slice_line,
                      0,  /* b1ie */
                      1,  /* scren */
                      1,  /* a1a2rsh */
                      0); /* a1a2ie */

      ten_n10g_soht_b2ie(module_id_line, slice_line, TEN_INSTANCE_ALL, 0);
      /* config_b2(module_id_line, slice_line, 0); */

      /* RX Line Side (Demapping): */
      /* XSEL = 1, SBYFRM = 0   (Framed SONET/SDH to the XCON) */
      /* SDFR_SDFCFG.SCREN = 1 */
      /* LOF and STM-AIS reported to OHPP */
      /* OTN-layer defects reported to OHPP */
      /* SDH Processor and PP10G may optionally be used */
      /* for non-intrusive monitoring */
      /* Table is OK */

  }
  /* elsif ($term eq 'rsregen') { */
  else if (term == TEN_OC192_TERM_RS_LAYER_REGENERATOR) {
      /* TX Line Side (Mapping): */
      /* SBY = 0 (Do not bypass SONET/SDH processing) */
      /* In SOHT, set SCREN=1, A1A2RSH=1, B1IE =1 */
      /* In SOHT, enable RSOH bytes that are to be sourced  */
      /* (others will be transparently passed through) */
      /* If B1 error transparency is desired, set B1TRANS=1 in SOHT_OHBEN1 */
      /* SFU inserts MS-AIS (AIS-L) as consequent action if */
      /* LOS/LOF/STM-AIS/MS-AIS or optionally RS-TIM  detected on client RX */
      /* B1IE needs to change */
      ten_n10g_soht_set_ohben0(module_id_line, slice_line,
                      1,  /* b1ie */
                      1,  /* scren */
                      1,  /* a1a2rsh */
                      0); /* a1a2ie */
      /* RX Line Side (Demapping): */
      /* XSEL = 1, SBYFRM = 0  (Framed SONET/SDH through the XCON) */
      /* SDFR_SDFCFG.SCREN = 1 */
      /* LOF, STM-AIS, RS-TIM, AIS-L defects reported to OHPP */
      /* OTN-layer defects reported to OHPP */
      /* Set SOHR_S1CFG.B1TRANS=1 */
      /* SDH Processor and PP10G may optionally be used for  */
      /* non-intrusive monitoring */
      /* B1 TRANS needs to change */
      ten_n10g_sohr_set_byte_err_trans_mode(module_id_line, slice_line,
                      1,  /* b1trans */
                      0); /* b2trans */
  }
  /* elsif ($term eq 'msregen') { */
  else if (term == TEN_OC192_TERM_MS_LAYER_REGENERATOR) {
      /* TX Line Side (Mapping): */
      /* SBY = 0 (Do not bypass SONET/SDH processing) */
      /* In SOHT, set SCREN=1, A1A2RSH=1, B1IE =1, B2IE=1 */
      /* In SOHT, enable RSOH/MSOH bytes that are to be sourced  */
      /* (others will be transparently passed through) */
      /* If B1 error transparency is desired, set B1TRANS=1 in SOHT_OHBEN1 */
      /* If B2 error transparency is desired, set B2TRANS=1 in SOHT_OHBEN1 */
      /* SFU inserts MS-RDI (RDI-L) as consequent action if */
      /* LOF/MS-AIS detected on line RX */
      /* SFU inserts MS-REI (REI-L) based on number of B2 errors */
      /* detected on line RX */
      /* SFU inserts MS-AIS (AIS-L) as consequent action  */
      /* if LOS/LOF/STM-AIS/MS-AIS or optionally RS-TIM/dEXC  detected on client RX */
      /* Optionally insert AU-AIS as consequent action  */
      /* if dLOP/AU-AIS detected on client RX */
      /* B1IE and B2IE need to change */
      ten_n10g_soht_set_ohben0(module_id_line, slice_line,
                      1,  /* b1ie */
                      1,  /* scren */
                      1,  /* a1a2rsh */
                      0); /* a1a2ie */
      ten_n10g_soht_b2ie(module_id_line, slice_line, TEN_INSTANCE_ALL, 0xFFFF);
      /* config_b2(module_id_line, slice_line, 0xffff); */
      /* RX Line Side (Demapping): */
      /* XSEL = 1, SBYFRM = 0  (Framed SONET/SDH through the XCON) */
      /* SDFR_SDFCFG.SCREN = 1 */
      /* LOF, STM-AIS, RS-TIM, AIS-L, dEXC, dLOP, AU-AIS defects reported to OHPP */
      /* OTN-layer defects reported to OHPP */
      /* Set SOHR_S1CFG.B1TRANS=1 */
      /* Set SOHR_S1CFG.B2TRANS=1 */
      /* SDH Processor and PP10G may optionally be used for non-intrusive monitoring */
      /* B1TRANS and B2TRANS need to change */
      ten_n10g_sohr_set_byte_err_trans_mode(module_id_line, slice_line,
                      1,  /* b1trans */
                      1); /* b2trans */
  }
  else {
    CS_HNDL_ERROR (module_id_line, ETEN_MOD_INVALID_USER_ARG, ": term invalid.");
    return(CS_ERROR);
  }

  return (CS_OK);
}


/***********************************************************************/
/* FUNCTION : ten_n10g_tx_trans_term_line_bypass()                     */
/***********************************************************************/
/* This helper function does not need an API appearance. This function */
/* is defined specifically for the line side as indicated by highlevel */
/* callers such as ten_hl_oc192_termination_path(), for setting up     */
/* GBLT_CFGTX0 and T41 GBL_BYPCFG as needed for oc192 regen configs.   */
/***********************************************************************/
cs_status ten_n10g_tx_trans_term_line_bypass(cs_uint16 module_id_line,
                                         cs_uint16 slice_line,
                                         cs_uint16 term_oc192)
{
  if (term_oc192 == TEN_OC192_TERM_TRANSPARENT_CBR10) {
  }
  else if ( (term_oc192 == TEN_OC192_TERM_TRANSPARENT_REGENERATOR) ||
            (term_oc192 == TEN_OC192_TERM_RS_LAYER_REGENERATOR)    ||
            (term_oc192 == TEN_OC192_TERM_MS_LAYER_REGENERATOR)       ){

      /* TX Line Side (Mapping): */
      /* SBY = 0 (Do not bypass SONET/SDH processing) */
      ten_n10g_set_gblt_bypasses(module_id_line, slice_line,
                      0,  /* otnoff */
                      0,  /* oby */
                      0,  /* sby */
                      1); /* kpgby */
      if (ten_dev_is_t41_ptr(TEN_MOD_ID_TO_DEVCB_PTR(module_id_line))) {
        ten_n10g_tx_bypass_t41 ( module_id_line, slice_line, 0 ); /* gbl_bypcfg.BYPASS:0, gbl_bypcfg.CLKTX_DIS:0 */
      }
}

  else {
    CS_HNDL_ERROR (module_id_line, ETEN_MOD_INVALID_USER_ARG, ": term invalid.");
    return(CS_ERROR);
  }

  return (CS_OK);
}

/********************************************************************/
/* Function: ten_get_n10g_reg_addr()                                */
/********************************************************************/
/* For Bugzilla 28734:                                              */
/* Gets the address of an n10g register.                            */
/*                                                                  */
/* Used by macro TEN_N10G_REG_ADDR. Given the base address of a     */
/* non-common n10g register as defined in t41_registers.h, and      */
/* its instance number (0..TEN_N10G_COUNT-1), calculates the        */
/* offset and adds it to the base register's address.               */
/********************************************************************/
volatile cs_reg *ten_get_n10g_reg_addr( cs_reg   *pReg,
                                                  cs_uint16 module_id,
                                                  cs_uint8  slice )
{
  cs_uint16 instance = (module_id & 0x0001) * 4 + slice;
  if (instance >= TEN_N10G_COUNT) {
    CS_HNDL_ERROR(0, ETEN_DEV_INVALID_USER_ARG,
                  "n10g instance %d (m %d s %d) out of range. S/b < TEN_N10G_COUNT.",
                  instance, module_id, slice);
    instance = 0;
  }
  return (pReg + instance * TEN_N10G_STRIDE);
}

/****************************************************************/
/* $rtn_hdr_start  N10G RX RECONFIG SET DEFAULTS                */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : HIGH LEVEL                                      */
/* CHIP       : Tenabo                                          */
cs_status ten_hl_n10g_reconfig_set_defaults(cs_uint16 module_id,
                                            cs_uint8 slice)
/* INPUTS     : o Module Id                                     */
/*              o Slice                                         */
/*                                                              */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* Configures N10G defaults before dynamic reconfiguration.     */
/* This will assure consistency between the initial config      */
/* and the dynamic reconfiguration.                             */
/*                                                              */
/* The [slice] parameter is specified as:                       */
/*   0x00 = TEN_SLICE0                                          */
/*   0x01 = TEN_SLICE1                                          */
/*   0x02 = TEN_SLICE2                                          */
/*   0x03 = TEN_SLICE3                                          */
/*   0xFF = TEN_SLICE_ALL                                       */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  cs_status rtn = CS_OK;

  CS_PRINT("ten_hl_n10g_reconfig_set_defaults, mod_id=0x%04X, sl=%d\n", module_id, slice);

  TEN_N10G_VALIDATE(module_id, slice);
  rtn |= ten_n10g_otnt_set_fasie(module_id, slice,  0);
  rtn |= ten_n10g_otnt_cfg0_mfalgne(module_id, slice, 1);
  rtn |= ten_n10g_otnt_cfg0_mfasins (module_id, slice, 0);
                     
  return (rtn);
}



