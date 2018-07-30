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
 * ten_hl_n40g.c
 *
 * API's for N40G high level configuration.
 *
 * $Id: ten_hl_n40g.c,v 1.108 2014/04/02 18:57:55 pptawade Exp $
 *
 */
 
#include "tenabo40.h"

#ifndef TEN_NO_N40G

const cs_uint16 ten_n40g_rx_table[TEN_N40G_RX_MAX_PARM][TEN_N40G_RX_MAX_MODE] = {
/*                                                       DISABLE                     BYPASS                      BYPASS_SNT_MON              OTU3_ODTU23_10U_6j          OTU3_ODTU23_10U             OTU3_ODTU23_7U              OTU3_ODU3_ORX               OTU3_ODTU23                 OC768_ODU3                  ODU3_ODU3                   OTU3_ODU3                   OTU3_ODTU23p_t21            OTU3_ODTU23p                OTU3_ODTU23p14              OTU3_ODU3_LS                OTU3_ODTU23P3               OTU3_ODTU23P7               ODU3_ODTU23                 OTU2_GENRM_ODU3             ODU3_GENRM_OTU2             OTU3E_ODTU23P                */
/*                                                       ============                ============                ============                ============                ============                ============                ============                ============                ============                ============                ============                ============                ============                ============                ============                ============                ============                ============                ============                ============                ============                 */
/*                        DPCFG0_BYSEL */  {                          0,                          0,                          0,                          0,                          0,                          0,                          0,                          0,                          0,                          0,                          1,                          0,                          0,                          0,                          0,                          0,                          0,                          0,                          0,                          1,                          0 },
/*                       DPCFG0_BYPCFG */  {                          0,                          0,                          0,                          0,                          0,                          0,                          0,                          0,                          0,                          1,                          1,                          0,                          0,                          0,                          1,                          0,                          0,                          0,                          0,                          1,                          0 },
/*                          DPCFG0_OBY */  {                          0,                          0,                          0,                          0,                          0,                          0,                          0,                          0,                          1,                          0,                          0,                          0,                          0,                          0,                          0,                          0,                          0,                          0,                          1,                          1,                          0 },
/*                          DPCFG0_SBY */  {                          0,                          0,                          1,                          1,                          1,                          1,                          1,                          1,                          0,                          1,                          1,                          1,                          1,                          1,                          1,                          1,                          1,                          1,                          1,                          0,                          1 },
/*                       DPCFG0_MDPCFG */  {                        0x0,                        0x0,                        0x0,                        0x0,                        0x0,                        0x0,                        0x0,                        0x0,                        0x2,                        0x0,                        0x0,                        0x0,                        0x0,                        0x0,                        0x0,                        0x0,                        0x0,                        0x0,                        0x2,                        0x0,                        0x0 },
/*                       DPCFG0_KPASEL */  {                          0,                          0,                          0,                          0,                          0,                          0,                          0,                          0,                          0,                          0,                          0,                          0,                          0,                          0,                          0,                          0,                          0,                          0,                          0,                          0,                          0 },
/*                   FRMLENGTH_NOFCOLS */  {                        0x0,                      0x10d,                      0x10d,                      0x10d,                      0x10d,                      0x10d,                      0x10d,                      0x10d,                      0x10d,                      0x10d,                      0x10d,                      0x10d,                      0x10d,                      0x10d,                      0x10d,                      0x10d,                      0x10d,                      0x10d,                      0x10d,                      0x10d,                      0x10d },
/*                        SDFCFG_SCREN */  {                          0,                          1,                          1,                          1,                          1,                          1,                          1,                          1,                          1,                          1,                          1,                          1,                          1,                          1,                          1,                          1,                          1,                          1,                          0,                          1,                          1 },
/*                       SDFCFG_FAWWUP */  {                        0x0,                        0x2,                        0x2,                        0x2,                        0x2,                        0x2,                        0x2,                        0x2,                        0x2,                        0x2,                        0x2,                        0x2,                        0x2,                        0x2,                        0x2,                        0x2,                        0x2,                        0x2,                        0x2,                        0x0,                        0x2 },
/*                       SDFCFG_FAWWDW */  {                        0x0,                        0x2,                        0x2,                        0x2,                        0x2,                        0x2,                        0x2,                        0x2,                        0x2,                        0x2,                        0x2,                        0x2,                        0x2,                        0x2,                        0x2,                        0x2,                        0x2,                        0x2,                        0x2,                        0x0,                        0x2 },
/*                        SDFCFG_OOFHY */  {                        0x0,                        0x4,                        0x4,                        0x4,                        0x4,                        0x4,                        0x4,                        0x4,                        0x4,                        0x4,                        0x4,                        0x4,                        0x4,                        0x4,                        0x4,                        0x4,                        0x4,                        0x4,                        0x4,                        0x4,                        0x4 },
/*                      SDFCFG1_ALTSCR */  {                          0,                          0,                          0,                          0,                          0,                          0,                          0,                          0,                          0,                          0,                          0,                          0,                          0,                          0,                          0,                          0,                          0,                          0,                          0,                          0,                          0 },
/*                      OACFG0_PREDSCR */  {                          0,                          1,                          1,                          1,                          1,                          1,                          1,                          1,                          1,                          1,                          1,                          1,                          1,                          1,                          1,                          1,                          1,                          1,                          0,                          1,                          1 },
/*                     OACFG0_POSTDSCR */  {                          0,                          0,                          0,                          0,                          0,                          0,                          0,                          0,                          0,                          0,                          0,                          0,                          0,                          0,                          0,                          0,                          0,                          0,                          0,                          0,                          0 },
/*                         OACFG0_ALEN */  {                          0,                          1,                          1,                          1,                          1,                          1,                          1,                          1,                          1,                          1,                          1,                          1,                          1,                          1,                          1,                          1,                          1,                          1,                          1,                          0,                          1 },
/*                     ODWCFG_STM256MD */  {                          0,                          0,                          0,                          0,                          0,                          0,                          0,                          0,                          1,                          0,                          0,                          0,                          0,                          0,                          0,                          0,                          0,                          0,                          0,                          0,                          0 },
/*                        ODWCFG_FSOMD */  {                          0,                          0,                          0,                          0,                          0,                          0,                          1,                          0,                          0,                          0,                          0,                          0,                          0,                          0,                          1,                          0,                          0,                          0,                          0,                          0,                          0 },
/*                    ODWCFG_DW_ENABLE */  {                          0,                          0,                          0,                          1,                          1,                          1,                          0,                          1,                          0,                          0,                          1,                          1,                          1,                          1,                          0,                          1,                          1,                          1,                          0,                          1,                          1 },
/*                      ODWCFG_AGGRMOD */  {                          0,                          0,                          0,                          1,                          1,                          1,                          0,                          1,                          0,                          0,                          0,                          1,                          1,                          1,                          0,                          1,                          1,                          1,                          0,                          0,                          1 },
/*                      ODWCFG_STM64MD */  {                          0,                          0,                          0,                          0,                          0,                          0,                          0,                          0,                          0,                          0,                          0,                          0,                          0,                          0,                          0,                          0,                          0,                          0,                          0,                          0,                          0 },
/*                   ODWCFG1_JC_ENABLE */  {                        0x0,                        0x0,                        0x0,                        0xf,                        0xf,                        0xf,                        0x0,                        0xf,                        0x0,                        0x0,                        0x0,                        0xf,                        0xf,                        0xf,                        0x0,                        0xF,                        0xF,                        0xf,                        0xF,                        0xF,                        0xF },
/*                     ODWCFG1_JC_PLUS */  {                        0x0,                        0x0,                        0x0,                        0xf,                        0x0,                        0x0,                        0x0,                        0x0,                        0x0,                        0x0,                        0xf,                        0x0,                        0xf,                        0xf,                        0xf,                          1,                          1,                        0x0,                          1,                          1,                        0xF },
/*                        OFCFG1_NPARB */  {                        0x0,                        0x0,                        0x0,                        0x0,                        0x0,                        0x0,                        0x0,                        0x0,                        0x0,                        0x0,                        0x0,                        0x0,                        0x0,                        0x0,                        0x0,                        0x0,                        0x0,                        0x0,                        0x0,                        0x0,                        0x0 },
/*                         OFCFG1_NPAR */  {                        0x0,                      0x010,                      0x010,                      0x017,                      0x017,                      0x010,                      0x010,                      0x010,                      0x010,                        0x0,                      0x010,                      0x010,                      0x010,                      0x010,                      0x010,                      0x010,                      0x010,                      0x000,                       0x10,                        0x0,                      0x010 },
/*                        OFCFG0_NCOLS */  {                        0x0,                      0x0fe,                      0x0fe,                      0x105,                      0x105,                      0x0fe,                      0x0fe,                      0x0fe,                      0x0fe,                      0x0ee,                      0x0fe,                      0x0fe,                      0x0fe,                      0x0fe,                      0x0fe,                      0x0fe,                      0x0fe,                      0x0ee,                      0x0fe,                      0x0ed,                      0x0fe } };

const cs_uint16 ten_n40g_tx_table[TEN_N40G_TX_MAX_PARM][TEN_N40G_TX_MAX_MODE] = {
/*                                                       DISABLE                    BYPASS                     BYPASS_SNT_MON             ODTU2_OTU3_10U_6j          ODTU2_OTU3_10U             ODTU2_OTU3_7U              ODU3_OTU3_ORV              ODTU2_OTU_t21a             ODTU2_OTU3                 ODTU2_OTU3p_t21            ODTU2_OTU3p                ODTU2_OTU3p14              OC192_OTU3                 ODU3_ODU3                  ODU3_OTU3                  ODU3_OTU3_SL               ODTU2_OTU3P3               ODTU2_OTU3P7               ODTU2_ODU3                 OTU2_GENRM_ODU3            ODU3_GENRM_OTU2            OTU3E_ODTU23P               */
/*                                                       ============               ============               ============               ============               ============               ============               ============               ============               ============               ============               ============               ============               ============               ============               ============               ============               ============               ============               ============               ============               ============               ============                */
/*                          CFG_MDPCFG */  {                       0x0,                       0x0,                       0x0,                       0x0,                       0x0,                       0x0,                         1,                       0x0,                       0x0,                       0x0,                       0x0,                       0x0,                       0x0,                       0x0,                       0x0,                       0x0,                       0x0,                       0x0,                       0x0,                        10,                        00,                       0x0 },
/*                             CFG_SBY */  {                         0,                         0,                         0,                         1,                         1,                         1,                         1,                         1,                         1,                         1,                         1,                         1,                         1,                         1,                         1,                         1,                         1,                         1,                         1,                         1,                         1,                         1 },
/*                             CFG_OBY */  {                         0,                         1,                         1,                         0,                         0,                         0,                         0,                         0,                         0,                         0,                         0,                         0,                         1,                         1,                         0,                         0,                         0,                         0,                         0,                         1,                         1,                         0 },
/*                           CFG_KPGBY */  {                         0,                         1,                         1,                         1,                         1,                         1,                         1,                         1,                         1,                         1,                         1,                         1,                         1,                         1,                         1,                         1,                         1,                         1,                         1,                         1,                         1,                         1 },
/*                          OHIE_B1INV */  {                         0,                         0,                         0,                         0,                         0,                         0,                         0,                         0,                         0,                         0,                         0,                         0,                         0,                         0,                         0,                         0,                         0,                         0,                         0,                         0,                         0,                         0 },
/*                          OHIE_SCREN */  {                         0,                         1,                         1,                         1,                         1,                         1,                         1,                         1,                         1,                         1,                         1,                         1,                         0,                         1,                         1,                         1,                         1,                         1,                         1,                         0,                         1,                         1 },
/*                        OHIE_A1A2RSH */  {                         0,                         0,                         0,                         0,                         0,                         0,                         0,                         0,                         0,                         0,                         0,                         0,                         0,                         0,                         0,                         0,                         0,                         0,                         0,                         0,                         0,                         0 },
/*                           OHIE_B1IE */  {                         0,                         0,                         0,                         0,                         0,                         0,                         0,                         0,                         0,                         0,                         0,                         0,                         1,                         0,                         0,                         0,                         0,                         0,                         0,                         0,                         0,                         0 },
/*                        OHIE_B1TRANS */  {                         0,                         0,                         0,                         0,                         0,                         0,                         0,                         0,                         0,                         0,                         0,                         0,                         0,                         0,                         0,                         0,                         0,                         0,                         0,                         0,                         0,                         0 },
/*                   B1ERRINS_B1ERRMSK */  {                         0,                         0,                         0,                         0,                         0,                         0,                         0,                         0,                         0,                         0,                         0,                         0,                         0,                         0,                         0,                         0,                         0,                         0,                         0,                       0x0,                       0x0,                         0 },
/*                       FRMLEN_FRMLEN */  {                       0x0,                    0x10d8,                    0x10d8,                    0x10d8,                    0x10d8,                    0x10d8,                    0x10d8,                    0x10d8,                    0x10d8,                    0x10d8,                    0x10d8,                    0x10d8,                    0x10d8,                    0x10d8,                    0x10d8,                    0x10d8,                    0x10d8,                    0x10d8,                    0x10d8,                    0x10d8,                    0x10d8,                    0x10d8 },
/*                         OCFG_PRESCR */  {                         0,                         1,                         1,                         1,                         1,                         1,                         1,                         1,                         1,                         1,                         1,                         1,                         1,                         1,                         1,                         1,                         1,                         1,                         1,                         0,                         1,                         1 },
/*                        OCFG_POSTSCR */  {                         0,                         0,                         0,                         0,                         0,                         0,                         0,                         0,                         0,                         0,                         0,                         0,                         0,                         0,                         0,                         0,                         0,                         0,                         0,                         0,                         0,                         0 },
/*                        WRPCFG3_WRMD */  {                       0x0,                       0x0,                       0x0,                       0x1,                       0x1,                       0x1,                       0x3,                       0x1,                       0x1,                       0x1,                       0x1,                       0x1,                       0x1,                       0x0,                       0x1,                       0x3,                       0x1,                       0x1,                       0x1,                       0x0,                       0x3,                       0x1 },
/*                    WRPCFG3_STM256MD */  {                         0,                         0,                         0,                         0,                         0,                         0,                         0,                         0,                         0,                         0,                         0,                         0,                         0,                         0,                         0,                         0,                         0,                         0,                         0,                         0,                         0,                         0 },
/*                     WRPCFG3_STM64MD */  {                         0,                         0,                         0,                         0,                         0,                         0,                         0,                         0,                         0,                         0,                         0,                         0,                         0,                         0,                         0,                         0,                         0,                         0,                         0,                         0,                         0,                         0 },
/*                     WRPCFG3_AGGRMOD */  {                         0,                         0,                         0,                         1,                         1,                         1,                         0,                         1,                         1,                         1,                         1,                         1,                         1,                         0,                         0,                         0,                         1,                         1,                         1,                         0,                         0,                         1 },
/*                        WRPCFG4_JCEN */  {                       0x0,                       0x0,                       0x0,                       0x3,                       0x3,                       0x3,                       0x0,                       0xf,                       0x3,                       0xF,                       0xF,                       0xF,                       0x0,                       0x0,                       0x0,                       0x0,                       0xF,                       0xF,                       0x3,                       0xF,                       0xF,                       0xF },
/*                     WRPCFG4_JC_PLUS */  {                         0,                         0,                         0,                         1,                         0,                         0,                         0,                         0,                         0,                         0,                         1,                         1,                         0,                         0,                         0,                         0,                         1,                         1,                         0,                         1,                         1,                         1 },
/*                       WRPCFG0_NCOLS */  {                       0x0,                     0x0fe,                     0x0fe,                     0x105,                     0x105,                     0x0fe,                     0x0fe,                     0x0fe,                     0x0fe,                     0x0fe,                     0x0fe,                     0x0fe,                     0x0fe,                     0x0ee,                     0x0fe,                     0x0fe,                     0x0fe,                     0x0fe,                     0x0ee,                     0x0fe,                     0x0ed,                     0x0fe },
/*                        WRPCFG2_NPAR */  {                       0x0,                      0x10,                      0x10,                     0x017,                     0x017,                     0x010,                     0x010,                     0x010,                     0x010,                     0x010,                     0x010,                     0x010,                     0x010,                       0x0,                     0x010,                     0x010,                     0x010,                     0x010,                     0x000,                      0x10,                      0x00,                     0x010 },
/*                       WRPCFG2_NPARB */  {                       0x0,                       0x0,                       0x0,                       0x0,                       0x0,                       0x0,                       0x0,                       0x0,                       0x0,                       0x0,                       0x0,                       0x0,                       0x0,                       0x0,                       0x0,                       0x0,                       0x0,                       0x0,                       0x0,                       0x0,                       0x0,                       0x0 },
/*                    WRP0DH1_DTHYST01 */  {                       0x0,                       0x0,                       0x0,                       0x0,                       0x0,                       0x0,                       0x0,                       0x0,                       0x0,                       0x0,                       0x0,                       0x0,                       0x0,                       0x0,                       0x0,                       0x0,                       0x0,                       0x0,                       0x0,                       0x0,                       0x0,                       0x0 },
/*                    WRP0DH0_DTHYST00 */  {                       0x0,                       0x0,                       0x0,                    0x1d83,                    0x1d83,                     0xA52,                       0x0,                       0x0,                    0x1d83,                       0x0,                       0x0,                    0x4120,                       0x0,                       0x0,                       0x0,                       0x0,                       0x0,                       0x0,                    0x1d83,                       0x0,                       0x0,                       0x0 },
/*                    WRP1DH1_DTHYST11 */  {                       0x0,                       0x0,                       0x0,                       0x0,                       0x0,                       0x0,                       0x0,                       0x0,                       0x0,                       0x0,                       0x0,                       0x0,                       0x0,                       0x0,                       0x0,                       0x0,                       0x0,                       0x0,                       0x0,                       0x0,                       0x0,                       0x0 },
/*                    WRP1DH0_DTHYST10 */  {                       0x0,                       0x0,                       0x0,                    0x1d83,                    0x1d83,                     0xA53,                       0x0,                       0x0,                    0x1d83,                       0x0,                       0x0,                       0x0,                       0x0,                       0x0,                       0x0,                       0x0,                       0x0,                       0x0,                    0x1d83,                       0x0,                       0x0,                       0x0 },
/*                    WRP2DH1_DTHYST21 */  {                       0x0,                       0x0,                       0x0,                       0x0,                       0x0,                       0x0,                       0x0,                       0x0,                       0x0,                       0x0,                       0x0,                       0x0,                       0x0,                       0x0,                       0x0,                       0x0,                       0x0,                       0x0,                       0x0,                       0x0,                       0x0,                       0x0 },
/*                    WRP2DH0_DTHYST20 */  {                       0x0,                       0x0,                       0x0,                       0x0,                       0x0,                    0x48F5,                       0x0,                       0x0,                       0x0,                       0x0,                       0x0,                       0x0,                       0x0,                       0x0,                       0x0,                       0x0,                       0x0,                    0x1d83,                       0x0,                       0x0,                    0x1d83,                    0x1d83 },
/*                    WRP3DH1_DTHYST31 */  {                       0x0,                       0x0,                       0x0,                       0x0,                       0x0,                       0x0,                       0x0,                       0x0,                       0x0,                       0x0,                       0x0,                       0x0,                       0x0,                       0x0,                       0x0,                       0x0,                       0x0,                       0x0,                       0x0,                       0x0,                       0x0,                       0x0 },
/*                    WRP3DH0_DTHYST30 */  {                       0x0,                       0x0,                       0x0,                       0x0,                       0x0,                    0x48A6,                       0x0,                       0x0,                       0x0,                       0x0,                       0x0,                       0x0,                       0x0,                       0x0,                       0x0,                       0x0,                    0x1d83,                       0x0,                       0x0,                    0x1d83,                       0x0,                       0x0 },
/*                           CFG0_PTIE */  {                         0,                         0,                         0,                         1,                         1,                         1,                         1,                         1,                         1,                         1,                         1,                         1,                         1,                         0,                         1,                         1,                         1,                         1,                         1,                         0,                         1,                         1 },
/*                             CFG2_PT */  {                       0x0,                       0x0,                       0x0,                      0x20,                      0x20,                      0x20,                       0x3,                      0x20,                      0x20,                      0x20,                      0x20,                       0x2,                      0x20,                       0x0,                      0x03,                      0x03,                      0x20,                      0x20,                      0x20,                       0x0,                      0x03,                      0x20 },
/*                         EXPTI_EXPTI */  {                       0x0,                       0x0,                       0x0,                      0x20,                      0x20,                      0x20,                       0x3,                      0x20,                      0x20,                      0x20,                      0x20,                      0x20,                      0x20,                       0x0,                      0x03,                      0x03,                      0x20,                      0x20,                      0x20,                       0x0,                      0x03,                      0x20 } };

const cs_char8 *ten_n40g_rx_debug_str[TEN_N40G_RX_MAX_MODE] = {
  "TEN_N40G_RX_DISABLE",
  "TEN_N40G_RX_BYPASS",
  "TEN_N40G_RX_BYPASS_SNT_MON",
  "TEN_N40G_RX_OTU3_ODTU23_10U_6J",
  "TEN_N40G_RX_OTU3_ODTU23_10U",
  "TEN_N40G_RX_OTU3_ODTU23_7U",
  "TEN_N40G_RX_OTU3_ODU3_ORX",
  "TEN_N40G_RX_OTU3_ODTU23",
  "TEN_N40G_RX_OC768_ODU3",
  "TEN_N40G_RX_ODU3_ODU3",
  "TEN_N40G_RX_OTU3_ODU3",
  "TEN_N40G_RX_OTU3_ODTU23P_T21",
  "TEN_N40G_RX_OTU3_ODTU23P",
  "TEN_N40G_RX_OTU3_ODTU23P14",
  "TEN_N40G_RX_OTU3_ODU3_LS",
  "TEN_N40G_RX_OTU3_ODTU23P3",
  "TEN_N40G_RX_OTU3_ODTU23P7",
  "TEN_N40G_RX_ODU3_ODTU23",
  "TEN_N40G_RX_OTU2_GENRM_ODU3",
  "TEN_N40G_RX_ODU3_GENRM_OTU2",
  "TEN_N40G_RX_OTU3E_ODTU23P" 
};

const cs_char8 *ten_n40g_tx_debug_str[TEN_N40G_TX_MAX_MODE] = {
  "TEN_N40G_TX_DISABLE",
  "TEN_N40G_TX_BYPASS",
  "TEN_N40G_TX_BYPASS_SNT_MON",
  "TEN_N40G_TX_ODTU2_OTU3_10U_6J",
  "TEN_N40G_TX_ODTU2_OTU3_10U",
  "TEN_N40G_TX_ODTU2_OTU3_7U",
  "TEN_N40G_TX_ODU3_OTU3_ORV",
  "TEN_N40G_TX_ODTU2_OTU_T21A",
  "TEN_N40G_TX_ODTU2_OTU3",
  "TEN_N40G_TX_ODTU2_OTU3P_T21",
  "TEN_N40G_TX_ODTU2_OTU3P",
  "TEN_N40G_TX_ODTU2_OTU3P14",
  "TEN_N40G_TX_OC192_OTU3",
  "TEN_N40G_TX_ODU3_ODU3",
  "TEN_N40G_TX_ODU3_OTU3",
  "TEN_N40G_TX_ODU3_OTU3_SL",
  "TEN_N40G_TX_ODTU2_OTU3P3",
  "TEN_N40G_TX_ODTU2_OTU3P7",
  "TEN_N40G_TX_ODTU2_ODU3",
  "TEN_N40G_TX_OTU2_GENRM_ODU3",
  "TEN_N40G_TX_ODU3_GENRM_OTU2",
  "TEN_N40G_TX_OTU3E_ODTU23P" 
};

/****************************************************************/
/* $rtn_hdr_start  N40G CONFIG                                  */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : HIGH LEVEL                                      */
/* CHIP       : Tenabo                                          */
cs_status ten_hl_n40g_config(cs_uint16 module_id,
                              cs_uint8 mode_rx,
                              cs_uint8 mode_tx)
/* INPUTS     : o Module Id                                     */
/*              o Mode RX                                       */
/*              o Mode TX                                       */
/*                                                              */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* Configures an N40G transmit/receive path.                    */
/*                                                              */
/* The [mode_rx] parameter is specified as:                     */
/*   the 'mode' parameter for ten_hl_n40g_rx_init               */
/*   e.g.                                                       */
/*     TEN_N40G_RX_OTU3_ODTU23                                  */
/*     TEN_N40G_RX_BYPASS_SNT_MON                               */
/*                                                              */
/* The [mode_tx] parameter is specified as:                     */
/*   the 'mode' parameter for ten_hl_n40g_tx_init               */
/*   e.g.                                                       */
/*     TEN_N40G_TX_ODTU2_OTU3                                   */
/*     TEN_N40G_TX_DISABLE.                                     */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  cs_status rtn = CS_OK;
  cs_uint16 dev_id;
  cs_uint16 module;

  CS_PRINT("ten_hl_n40g_config: %d, %d, %d\n", module_id, mode_rx, mode_tx);

  if (mode_rx >= TEN_N40G_RX_MAX_MODE) {
     CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": Invalid RX Mode!");
     rtn = CS_ERROR;
     goto RTN_EXIT;
  }
  
  if (mode_tx >= TEN_N40G_TX_MAX_MODE) {
     CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": Invalid TX Mode!");
     rtn = CS_ERROR;
     goto RTN_EXIT;
  }

  dev_id = TEN_MOD_ID_TO_DEV_ID(module_id);
  module = TEN_MOD_ID_TO_MOD_NUM(module_id);
  
  rtn |= ten_mpif_global_clock_disable_n40g(dev_id, module, CS_RX, CS_ENABLE);
  rtn |= ten_mpif_global_reset_n40g(dev_id, module, CS_RX, CS_RESET_DEASSERT);
  rtn |= ten_hl_n40g_rx_init(module_id, mode_rx);
  if (mode_tx != TEN_N40G_TX_DISABLE) {
    rtn |= ten_mpif_global_clock_disable_n40g(dev_id, module, CS_TX, CS_ENABLE);
    rtn |= ten_mpif_global_reset_n40g(dev_id, module, CS_TX, CS_RESET_DEASSERT);
    rtn |= ten_hl_n40g_tx_init(module_id, mode_tx);
    /* bugzilla #19353, fix bus errors */
    rtn |= ten_n40g_otnt4x_bipmsk(module_id, 0xff);
    
    /* Bugzilla 21279 */
    rtn |= ten_n40g_otnt4x_set_wrpcfg4(module_id, 0, 0);
  }

  rtn |= ten_n40g_otnr4x_set_jc_plus(module_id, 0);  /* Bugzilla 21279 */
  rtn |= ten_n40g_otnr4x_set_jc_enable(module_id, 0);

RTN_EXIT:
  return (rtn);
}

/* Bugzilla 24750 Start */
/********************************************************************/
/* N40G OTN ALIGNER SETTINGS                                        */
cs_status ten_hl_n40g_otn_aligner_settings(cs_uint16 module_id) 
/* INPUTS     : o Module Id                                         */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Internal routine to sets the recommended OTN aligner settings    */
/*                                                                  */
/********************************************************************/
{
  TEN_N40G_OTNR4X_OACFG0_t tmp_otnr4x_oacfg0;
  TEN_N40G_OTNR4X_OACFG1_t tmp_otnr4x_oacfg1;
  TEN_N40G_OTNR4X_OACFG2_t tmp_otnr4x_oacfg2;
  T41_t *pDev = NULL;
  
  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_N40G);
  
  tmp_otnr4x_oacfg0.wrd = TEN_REG_READ(TEN_N40G_REG_ADDR(pDev, module_id, OACFG0));
  /* tmp_otnr4x_oacfg0.bf.DSYHYST = 11 or 6, set in ten_hl_fec_config */
  tmp_otnr4x_oacfg0.bf.DSYHYST = 11;
  tmp_otnr4x_oacfg0.bf.SYHYST = 0;
  TEN_REG_WRITE(TEN_N40G_REG_ADDR(pDev, module_id, OACFG0), tmp_otnr4x_oacfg0.wrd);
  
  tmp_otnr4x_oacfg1.wrd = TEN_REG_READ(TEN_N40G_REG_ADDR(pDev, module_id, OACFG1));
  tmp_otnr4x_oacfg1.bf.FSIZES = 32;
  tmp_otnr4x_oacfg1.bf.FSIZEP = 32;
  TEN_REG_WRITE(TEN_N40G_REG_ADDR(pDev, module_id, OACFG1), tmp_otnr4x_oacfg1.wrd);
  
  tmp_otnr4x_oacfg2.wrd = TEN_REG_READ(TEN_N40G_REG_ADDR(pDev, module_id, OACFG2));
  
  /* Bugzilla #33380, MLDR_LMCFG and FTOLD Settings Should be changed for OTL3.4 */
  tmp_otnr4x_oacfg2.bf.FTOLD = 2;
  tmp_otnr4x_oacfg2.bf.FTOLS = 0;
  tmp_otnr4x_oacfg2.bf.FSIZED = 24;
  TEN_REG_WRITE(TEN_N40G_REG_ADDR(pDev, module_id, OACFG2), tmp_otnr4x_oacfg2.wrd);
  TEN_MOD_UNLOCK(module_id, TEN_ID_N40G);

  return (CS_OK);
}
/* Bugzilla 24750 End */

/****************************************************************/
/* $rtn_hdr_start  MAP N10G CHANNEL TO TIMESLOT IN ODTU23       */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : HIGH LEVEL                                      */
/* CHIP       : Tenabo                                          */
cs_status ten_hl_n40g_map_chnl_ts(cs_uint16 module_id,
                                  cs_uint8 slice,
                                  cs_dir_t dir,
                                  cs_uint8 timeslot1,
                                  cs_uint8 timeslot2,
                                  cs_uint8 timeslot3,
                                  cs_uint8 timeslot4)
/* INPUTS     : o Module Id                                     */
/*              o Slice                                         */
/*              o Direction                                     */
/*              o Timeslot 1                                    */
/*              o Timeslot 2                                    */
/*              o Timeslot 3                                    */
/*              o Timeslot 4                                    */
/*                                                              */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* Map the ODTU23 triburatries to the slice                     */
/* The [slice] parameter is specified as follows                */
/*   0-3                                                        */
/* NOTE: The channel index corresponds to ones complement of    */
/*       the port index                                         */
/*                                                              */
/* The [dir] parameter is specified as:                         */
/*   0 = CS_TX                                                  */
/*   1 = CS_RX                                                  */
/*   2 = CS_TX_AND_RX                                           */
/*                                                              */
/* The [timeslot1] parameter specifies the first timeslot to    */
/* assign to the associated tributary channel                   */
/*   0 - 15                                                     */
/*                                                              */
/* The [timeslot2] parameter specifies the second timeslot to   */
/* assign to the associated tributary channel                   */
/*   0 - 15                                                     */
/*                                                              */
/* The [timeslot3] parameter specifies the third timeslot to    */
/* assign to the associated tributary channel                   */
/*   0 - 15                                                     */
/*                                                              */
/* The [timeslot4] parameter specifies the fourth timeslot to   */
/* assign to the associated tributary channel                   */
/*   0 - 15                                                     */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  TEN_N40G_OTNR4X_ODWTSCFG0_t tmp_otnr4x_odwtscfg0;
  TEN_N40G_OTNR4X_ODWTSCFG1_t tmp_otnr4x_odwtscfg1;
  TEN_N40G_OTNT4X_WRPTSCFG0_t tmp_otnt4x_wrptscfg0;
  TEN_N40G_OTNT4X_WRPTSCFG1_t tmp_otnt4x_wrptscfg1;
  T41_t *pDev = NULL;
  cs_uint16 mask = 0x3;
  
  if ((slice>=TEN_MAX_SLICES) && (slice != TEN_SLICE_ALL)) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": slice out of range.  s/b 0..3.");
    return(CS_ERROR);
  }

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_N40G);

  if((dir == CS_RX) || (dir == CS_TX_AND_RX)) {
    if(timeslot1 < 8) {
      tmp_otnr4x_odwtscfg0.wrd = TEN_REG_READ(TEN_N40G_REG_ADDR(pDev, module_id, ODWTSCFG0));
      /* Bugzilla 18742 */
      /* Add the line below to all cases to clear the timeslot to tributary default values
         Otherwise, it could result in more than four tributaries being allocated to a given
         channel, which causes a segfault in ten_hl_n40g_cfg_async_odtu23() as the array
         index overfolws */
      tmp_otnr4x_odwtscfg0.wrd &= ~(mask << (timeslot1*2));
      tmp_otnr4x_odwtscfg0.wrd |= (~slice & 0x3) << (timeslot1*2);
      TEN_REG_WRITE(TEN_N40G_REG_ADDR(pDev, module_id, ODWTSCFG0), tmp_otnr4x_odwtscfg0.wrd);
    }
    else {
      tmp_otnr4x_odwtscfg1.wrd = TEN_REG_READ(TEN_N40G_REG_ADDR(pDev, module_id, ODWTSCFG1));
      tmp_otnr4x_odwtscfg1.wrd &= ~(mask << ((timeslot1-8)*2));
      tmp_otnr4x_odwtscfg1.wrd |= (~slice & 0x3) << ((timeslot1-8)*2);
      TEN_REG_WRITE(TEN_N40G_REG_ADDR(pDev, module_id, ODWTSCFG1), tmp_otnr4x_odwtscfg1.wrd);
    }

    if(timeslot2 < 8) {
      tmp_otnr4x_odwtscfg0.wrd = TEN_REG_READ(TEN_N40G_REG_ADDR(pDev, module_id, ODWTSCFG0));
      tmp_otnr4x_odwtscfg0.wrd &= ~(mask << (timeslot2*2));
      tmp_otnr4x_odwtscfg0.wrd |= (~slice & 0x3) << (timeslot2*2);
      TEN_REG_WRITE(TEN_N40G_REG_ADDR(pDev, module_id, ODWTSCFG0), tmp_otnr4x_odwtscfg0.wrd);
    }
    else {
      tmp_otnr4x_odwtscfg1.wrd = TEN_REG_READ(TEN_N40G_REG_ADDR(pDev, module_id, ODWTSCFG1));
      tmp_otnr4x_odwtscfg1.wrd &= ~(mask << ((timeslot2-8)*2));
      tmp_otnr4x_odwtscfg1.wrd |= (~slice & 0x3) << ((timeslot2-8)*2);
      TEN_REG_WRITE(TEN_N40G_REG_ADDR(pDev, module_id, ODWTSCFG1), tmp_otnr4x_odwtscfg1.wrd);
    }

    if(timeslot3 < 8) {
      tmp_otnr4x_odwtscfg0.wrd = TEN_REG_READ(TEN_N40G_REG_ADDR(pDev, module_id, ODWTSCFG0));
      tmp_otnr4x_odwtscfg0.wrd &= ~(mask << (timeslot3*2));
      tmp_otnr4x_odwtscfg0.wrd |= (~slice & 0x3) << (timeslot3*2);
      TEN_REG_WRITE(TEN_N40G_REG_ADDR(pDev, module_id, ODWTSCFG0), tmp_otnr4x_odwtscfg0.wrd);
    }
    else {
      tmp_otnr4x_odwtscfg1.wrd = TEN_REG_READ(TEN_N40G_REG_ADDR(pDev, module_id, ODWTSCFG1));
      tmp_otnr4x_odwtscfg1.wrd &= ~(mask << ((timeslot3-8)*2));
      tmp_otnr4x_odwtscfg1.wrd |= (~slice & 0x3) << ((timeslot3-8)*2);
      TEN_REG_WRITE(TEN_N40G_REG_ADDR(pDev, module_id, ODWTSCFG1), tmp_otnr4x_odwtscfg1.wrd);
    }

    if(timeslot4 < 8) {
      tmp_otnr4x_odwtscfg0.wrd = TEN_REG_READ(TEN_N40G_REG_ADDR(pDev, module_id, ODWTSCFG0));
      tmp_otnr4x_odwtscfg0.wrd &= ~(mask << (timeslot4*2));
      tmp_otnr4x_odwtscfg0.wrd |= (~slice & 0x3) << (timeslot4*2);
      TEN_REG_WRITE(TEN_N40G_REG_ADDR(pDev, module_id, ODWTSCFG0), tmp_otnr4x_odwtscfg0.wrd);
    }
    else {
      tmp_otnr4x_odwtscfg1.wrd = TEN_REG_READ(TEN_N40G_REG_ADDR(pDev, module_id, ODWTSCFG1));
      tmp_otnr4x_odwtscfg1.wrd &= ~(mask << ((timeslot4-8)*2));
      tmp_otnr4x_odwtscfg1.wrd |= (~slice & 0x3) << ((timeslot4-8)*2);
      TEN_REG_WRITE(TEN_N40G_REG_ADDR(pDev, module_id, ODWTSCFG1), tmp_otnr4x_odwtscfg1.wrd);
    }
  }

  if((dir == CS_TX) || (dir == CS_TX_AND_RX)) {
    if(timeslot1 < 8) {
      tmp_otnt4x_wrptscfg0.wrd = TEN_REG_READ(TEN_N40G_REG_ADDR(pDev, module_id, WRPTSCFG0));
      tmp_otnt4x_wrptscfg0.wrd &= ~(mask << (timeslot1*2));
      tmp_otnt4x_wrptscfg0.wrd |= (~slice & 0x3) << (timeslot1*2);
      TEN_REG_WRITE(TEN_N40G_REG_ADDR(pDev, module_id, WRPTSCFG0), tmp_otnt4x_wrptscfg0.wrd);
    }
    else {
      tmp_otnt4x_wrptscfg1.wrd = TEN_REG_READ(TEN_N40G_REG_ADDR(pDev, module_id, WRPTSCFG1));
      tmp_otnt4x_wrptscfg1.wrd &= ~(mask << ((timeslot1-8)*2));
      tmp_otnt4x_wrptscfg1.wrd |= (~slice & 0x3) << ((timeslot1-8)*2);
      TEN_REG_WRITE(TEN_N40G_REG_ADDR(pDev, module_id, WRPTSCFG1), tmp_otnt4x_wrptscfg1.wrd);
    }

    if(timeslot2 < 8) {
      tmp_otnt4x_wrptscfg0.wrd = TEN_REG_READ(TEN_N40G_REG_ADDR(pDev, module_id, WRPTSCFG0));
      tmp_otnt4x_wrptscfg0.wrd &= ~(mask << (timeslot2*2));
      tmp_otnt4x_wrptscfg0.wrd |= (~slice & 0x3) << (timeslot2*2);
      TEN_REG_WRITE(TEN_N40G_REG_ADDR(pDev, module_id, WRPTSCFG0), tmp_otnt4x_wrptscfg0.wrd);
    }
    else {
      tmp_otnt4x_wrptscfg1.wrd = TEN_REG_READ(TEN_N40G_REG_ADDR(pDev, module_id, WRPTSCFG1));
      tmp_otnt4x_wrptscfg1.wrd &= ~(mask << ((timeslot2-8)*2));
      tmp_otnt4x_wrptscfg1.wrd |= (~slice & 0x3) << ((timeslot2-8)*2);
      TEN_REG_WRITE(TEN_N40G_REG_ADDR(pDev, module_id, WRPTSCFG1), tmp_otnt4x_wrptscfg1.wrd);
    }

    if(timeslot3 < 8) {
      tmp_otnt4x_wrptscfg0.wrd = TEN_REG_READ(TEN_N40G_REG_ADDR(pDev, module_id, WRPTSCFG0));
      tmp_otnt4x_wrptscfg0.wrd &= ~(mask << (timeslot3*2));
      tmp_otnt4x_wrptscfg0.wrd |= (~slice & 0x3) << (timeslot3*2);
      TEN_REG_WRITE(TEN_N40G_REG_ADDR(pDev, module_id, WRPTSCFG0), tmp_otnt4x_wrptscfg0.wrd);
    }
    else {
      tmp_otnt4x_wrptscfg1.wrd = TEN_REG_READ(TEN_N40G_REG_ADDR(pDev, module_id, WRPTSCFG1));
      tmp_otnt4x_wrptscfg1.wrd &= ~(mask << ((timeslot3-8)*2));
      tmp_otnt4x_wrptscfg1.wrd |= (~slice & 0x3) << ((timeslot3-8)*2);
      TEN_REG_WRITE(TEN_N40G_REG_ADDR(pDev, module_id, WRPTSCFG1), tmp_otnt4x_wrptscfg1.wrd);
    }

    if(timeslot4 < 8) {
      tmp_otnt4x_wrptscfg0.wrd = TEN_REG_READ(TEN_N40G_REG_ADDR(pDev, module_id, WRPTSCFG0));
      tmp_otnt4x_wrptscfg0.wrd &= ~(mask << (timeslot4*2));
      tmp_otnt4x_wrptscfg0.wrd |= (~slice & 0x3) << (timeslot4*2);
      TEN_REG_WRITE(TEN_N40G_REG_ADDR(pDev, module_id, WRPTSCFG0), tmp_otnt4x_wrptscfg0.wrd);
    }
    else {
      tmp_otnt4x_wrptscfg1.wrd = TEN_REG_READ(TEN_N40G_REG_ADDR(pDev, module_id, WRPTSCFG1));
      tmp_otnt4x_wrptscfg1.wrd &= ~(mask << ((timeslot4-8)*2));
      tmp_otnt4x_wrptscfg1.wrd |= (~slice & 0x3) << ((timeslot4-8)*2);
      TEN_REG_WRITE(TEN_N40G_REG_ADDR(pDev, module_id, WRPTSCFG1), tmp_otnt4x_wrptscfg1.wrd);
    }
  }

  TEN_MOD_UNLOCK(module_id, TEN_ID_N40G);

  return (CS_OK);
}

/****************************************************************/
/* $rtn_hdr_start  N40G CONFIGURE ODTU23 PER PORT               */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : HIGH LEVEL                                      */
/* CHIP       : Tenabo                                          */
cs_status ten_hl_n40g_cfg_async_odtu23(cs_uint16 module_id,
                                       cs_uint8 slice,
                                       cs_dir_t dir,
                                       cs_uint16 fs_bytes,
                                       cs_uint8 c15_bytes)

/* INPUTS     : o Module Id                                     */
/*              o Slice                                         */
/*              o Direction                                     */
/*              o Justification Control                         */
/*              o Fixed Stuff Bytes                             */
/*              o Column 15 Bytes (Enhanced Justification)      */
/*                                                              */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* Configure ODTU23 parameters for N40G                         */
/*                                                              */
/* The [slice] parameter is specified as                        */
/*   0-3                                                        */
/* NOTE: The channel index corresponds to ones complement of    */
/*       the port index                                         */
/*                                                              */
/* The [dir] parameter is specified as:                         */
/*   0 = CS_TX                                                  */
/*   1 = CS_RX                                                  */
/*   2 = CS_TX_AND_RX                                           */
/*                                                              */
/* The [fs_bytes] parameter specifies the number of additional  */
/*  stuff bytes needed when using Cortina Enhanced CBR mapping  */
/*   0 - 15232                                                  */
/*                                                              */
/* The [c15_bytes] parameter specifies the number of column     */
/* 15 bytes to be used as extra payload bytes for async mapping */
/* using justification (NJOs) when using Cortina Enhanced CBR   */
/* mapping                                                      */
/*   0 - 12                                                     */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  T41_t *pDev = NULL;
  cs_uint8 tribnum[4];
  cs_uint8 i, j=0;
  cs_uint8 fs_done=0, c15_done=0;
  cs_uint8 shift_index;
  cs_uint16 fs_per_ch[4]={0}, c15_per_ch[4]={0};
  cs_uint16 total_fs=fs_bytes, total_c15=c15_bytes;
  cs_uint16 c15_clear_value;
  cs_reg *regaddr ;
  cs_uint16 kk;

  TEN_N40G_OTNR4X_ODWTSCFG0_t tmp_otnr4x_odwtscfg0;
  TEN_N40G_OTNR4X_ODWTSCFG1_t tmp_otnr4x_odwtscfg1;
  TEN_N40G_OTNT4X_WRPTSCFG0_t tmp_otnt4x_wrptscfg0;
  TEN_N40G_OTNT4X_WRPTSCFG1_t tmp_otnt4x_wrptscfg1;

  TEN_N40G_OTNR4X_ODWC15EN0_t tmp_otnr4x_odwc15en0;
  TEN_N40G_OTNR4X_ODWC15EN1_t tmp_otnr4x_odwc15en1;
  TEN_N40G_OTNR4X_ODWC15EN2_t tmp_otnr4x_odwc15en2;
  TEN_N40G_OTNR4X_ODWC15EN3_t tmp_otnr4x_odwc15en3;

  TEN_N40G_OTNT4X_WRPC15EN0_t tmp_otnt4x_wrpc15en0;
  TEN_N40G_OTNT4X_WRPC15EN1_t tmp_otnt4x_wrpc15en1;
  TEN_N40G_OTNT4X_WRPC15EN2_t tmp_otnt4x_wrpc15en2;
  TEN_N40G_OTNT4X_WRPC15EN3_t tmp_otnt4x_wrpc15en3;
  cs_char8 *func = "ten_hl_n40g_cfg_async_odtu23";  


  if ((slice>=TEN_MAX_SLICES) && (slice != TEN_SLICE_ALL)) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": slice out of range.  s/b 0..3.");
    return(CS_ERROR);
  }

  CS_PRINT("%s() %s, %s, %s, fs_bytes=%d, c15_bytes=%d\n",
           func,
           ten_module_strings[module_id&1],
           ten_slice_strings[slice],
           ten_dir_strings[dir],
           fs_bytes,
           c15_bytes);

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_N40G);

  /* bugzilla #24439, klocwork */
  for (kk=0; kk<4; kk++) {
    tribnum[kk] = 0;
  }
  
  /***** RX Setting *****/
  j=0;
  if((dir == CS_RX) || (dir == CS_TX_AND_RX)) {
    /* Find the slice to timeslot mapping */
    tmp_otnr4x_odwtscfg0.wrd = TEN_REG_READ(TEN_N40G_REG_ADDR(pDev, module_id, ODWTSCFG0));
    tmp_otnr4x_odwtscfg1.wrd = TEN_REG_READ(TEN_N40G_REG_ADDR(pDev, module_id, ODWTSCFG1));
    for(i=0; i<8; i++) {
      if(((tmp_otnr4x_odwtscfg0.wrd & (0x03 << i*2)) >> i*2) == (~slice & 0x03)) {
        if(j > 3) {
          CS_PRINT("Invalid channel to port mapping!\n");
          /* bugzilla #25683, fix semaphore leak on ERROR */
          TEN_MOD_UNLOCK(module_id, TEN_ID_N40G);
          return CS_ERROR;     
        }
        tribnum[j++] = i;
      }
    }
    for(i=0; i<8; i++) {
      if(((tmp_otnr4x_odwtscfg1.wrd & (0x03 << i*2)) >> i*2) == (~slice & 0x03)) {
        if(j > 3) {
          CS_PRINT("Invalid channel to port mapping!\n");
          TEN_MOD_UNLOCK(module_id, TEN_ID_N40G);
          return CS_ERROR;     
        }
        tribnum[j++] = i+8;
      }
    }

    /* Program FS bytes */
    regaddr = (cs_reg *)TEN_N40G_REG_ADDR(pDev, module_id, ODWFS0);
    while(!fs_done) {
      for(i=0; i<4; i++) {
        if(fs_bytes <= 64) {
          fs_per_ch[i] += fs_bytes;
          fs_done = 1;
          break;        
        }
        else {
          fs_per_ch[i] += 64;
          fs_bytes = fs_bytes - 64;
        }
      }
    }
    for(i=0; i<4; i++)
      TEN_REG_WRITE((regaddr + tribnum[i]), fs_per_ch[3-i]);

    /* Program C15 bytes */
    j=0;
    while(!c15_done) {
      for(i=0; i<4; i++) {
        if(c15_bytes != 0) {
          c15_per_ch[i] += 1<<j;
          c15_bytes--;
        }
        else {
          c15_done = 1;
          break;
        }
      }
      j++;
    }

    for(i=0; i<4; i++) {
      if(tribnum[i] < 4) {
        shift_index = tribnum[i]*4;
        c15_clear_value = ~(7 << shift_index);
        tmp_otnr4x_odwc15en0.wrd = TEN_REG_READ(TEN_N40G_REG_ADDR(pDev, module_id, ODWC15EN0));
        tmp_otnr4x_odwc15en0.wrd &= c15_clear_value;
        TEN_REG_WRITE(TEN_N40G_REG_ADDR(pDev, module_id, ODWC15EN0), 
                    tmp_otnr4x_odwc15en0.wrd |(c15_per_ch[i] << shift_index));
      }
      else if (tribnum[i] > 3 && tribnum[i] < 8) {
        shift_index = (tribnum[i]-4)*4;
        c15_clear_value = ~(7 << shift_index);
        tmp_otnr4x_odwc15en1.wrd = TEN_REG_READ(TEN_N40G_REG_ADDR(pDev, module_id, ODWC15EN1));
        tmp_otnr4x_odwc15en1.wrd &= c15_clear_value;
        TEN_REG_WRITE(TEN_N40G_REG_ADDR(pDev, module_id, ODWC15EN1), 
                    tmp_otnr4x_odwc15en1.wrd |(c15_per_ch[i] << shift_index));
      }
      else if (tribnum[i] > 7 && tribnum[i] < 12) {
        shift_index = (tribnum[i]-8)*4;
        c15_clear_value = ~(7 << shift_index);
        tmp_otnr4x_odwc15en2.wrd = TEN_REG_READ(TEN_N40G_REG_ADDR(pDev, module_id, ODWC15EN2));
        tmp_otnr4x_odwc15en2.wrd &= c15_clear_value;
        TEN_REG_WRITE(TEN_N40G_REG_ADDR(pDev, module_id, ODWC15EN2), 
                    tmp_otnr4x_odwc15en2.wrd |(c15_per_ch[i] << shift_index));
      }
      else if (tribnum[i] > 11 && tribnum[i] < 16) {
        shift_index = (tribnum[i]-12)*4;
        c15_clear_value = ~(7 << shift_index);
        tmp_otnr4x_odwc15en3.wrd = TEN_REG_READ(TEN_N40G_REG_ADDR(pDev, module_id, ODWC15EN3));
        tmp_otnr4x_odwc15en3.wrd &= c15_clear_value;
        TEN_REG_WRITE(TEN_N40G_REG_ADDR(pDev, module_id, ODWC15EN3), 
                    tmp_otnr4x_odwc15en3.wrd |(c15_per_ch[i] << shift_index));
      }
    }
  }

  /***** TX Setting *****/
  j=0;
  fs_bytes=total_fs;
  c15_bytes=total_c15;
  fs_done=0;
  c15_done=0;
  for(i=0; i<4; i++) {
    fs_per_ch[i]=0;
    c15_per_ch[i]=0;
  }

  if((dir == CS_TX) || (dir == CS_TX_AND_RX)) {
    /* Find the slice to timeslot mapping */
    tmp_otnt4x_wrptscfg0.wrd = TEN_REG_READ(TEN_N40G_REG_ADDR(pDev, module_id, WRPTSCFG0));
    tmp_otnt4x_wrptscfg1.wrd = TEN_REG_READ(TEN_N40G_REG_ADDR(pDev, module_id, WRPTSCFG1));
    for(i=0; i<8; i++) {
      if(((tmp_otnt4x_wrptscfg0.wrd & (0x03 << i*2)) >> i*2) == (~slice & 0x03)) {
        if(j > 3) {
          CS_PRINT("Invalid channel to port mapping!\n");
          TEN_MOD_UNLOCK(module_id, TEN_ID_N40G);
          return CS_ERROR;     
        }
        tribnum[j++] = i;
      }
    }
    for(i=0; i<8; i++) {
      if(((tmp_otnt4x_wrptscfg1.wrd & (0x03 << i*2)) >> i*2) == (~slice & 0x03)) {
        if(j > 3) {
          CS_PRINT("Invalid channel to port mapping!\n");
          TEN_MOD_UNLOCK(module_id, TEN_ID_N40G);
          return CS_ERROR;     
        }
        tribnum[j++] = i+8;
      }
    }

    /* Program FS bytes */
    regaddr = (cs_reg *)TEN_N40G_REG_ADDR(pDev, module_id, WRPFS0);
    while(!fs_done) {
      for(i=0; i<4; i++) {
        if(fs_bytes <= 64) {
          fs_per_ch[i] += fs_bytes;
          fs_done = 1;
          break;        
        }
        else {
          fs_per_ch[i] += 64;
          fs_bytes = fs_bytes - 64;
        }
      }
    }
    for(i=0; i<4; i++)
      TEN_REG_WRITE((regaddr + tribnum[i]), fs_per_ch[3-i]);

    /* Program C15 bytes */
    j=0;
    while(!c15_done) {
      for(i=0; i<4; i++) {
        if(c15_bytes != 0) {
          c15_per_ch[i] += 1<<j;
          c15_bytes--;
        }
        else {
          c15_done = 1;
          break;
        }
      }
      j++;
    }

    for(i=0; i<4; i++) {
      if(tribnum[i] < 4) {
        shift_index = tribnum[i]*4;
        c15_clear_value = ~(7 << shift_index);
        tmp_otnt4x_wrpc15en0.wrd = TEN_REG_READ(TEN_N40G_REG_ADDR(pDev, module_id, WRPC15EN0));
        tmp_otnt4x_wrpc15en0.wrd &= c15_clear_value;
        TEN_REG_WRITE(TEN_N40G_REG_ADDR(pDev, module_id, WRPC15EN0), 
                    tmp_otnt4x_wrpc15en0.wrd |(c15_per_ch[i] << shift_index));
      }
      else if (tribnum[i] > 3 && tribnum[i] < 8) {
        shift_index = (tribnum[i]-4)*4;
        c15_clear_value = ~(7 << shift_index);
        tmp_otnt4x_wrpc15en1.wrd = TEN_REG_READ(TEN_N40G_REG_ADDR(pDev, module_id, WRPC15EN1));
        tmp_otnt4x_wrpc15en1.wrd &= c15_clear_value;
        TEN_REG_WRITE(TEN_N40G_REG_ADDR(pDev, module_id, WRPC15EN1), 
                    tmp_otnt4x_wrpc15en1.wrd |(c15_per_ch[i] << shift_index));
      }
      else if (tribnum[i] > 7 && tribnum[i] < 12) {
        shift_index = (tribnum[i]-8)*4;
        c15_clear_value = ~(7 << shift_index);
        tmp_otnt4x_wrpc15en2.wrd = TEN_REG_READ(TEN_N40G_REG_ADDR(pDev, module_id, WRPC15EN2));
        tmp_otnt4x_wrpc15en2.wrd &= c15_clear_value;
        TEN_REG_WRITE(TEN_N40G_REG_ADDR(pDev, module_id, WRPC15EN2), 
                    tmp_otnt4x_wrpc15en2.wrd |(c15_per_ch[i] << shift_index));
      }
      else if (tribnum[i] > 11 && tribnum[i] < 16) {
        shift_index = (tribnum[i]-12)*4;
        c15_clear_value = ~(7 << shift_index);
        tmp_otnt4x_wrpc15en3.wrd = TEN_REG_READ(TEN_N40G_REG_ADDR(pDev, module_id, WRPC15EN3));
        tmp_otnt4x_wrpc15en3.wrd &= c15_clear_value;
        TEN_REG_WRITE(TEN_N40G_REG_ADDR(pDev, module_id, WRPC15EN3), 
                    tmp_otnt4x_wrpc15en3.wrd |(c15_per_ch[i] << shift_index));
      }
    }
  }
  
  TEN_MOD_UNLOCK(module_id, TEN_ID_N40G);

  return (CS_OK);
}

/****************************************************************/
/* $rtn_hdr_start  N40G RX INITIALIZATION                       */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : HIGH LEVEL                                      */
/* CHIP       : Tenabo                                          */
cs_status ten_hl_n40g_rx_init(cs_uint16 module_id,
                              cs_uint8 mode)
/* INPUTS     : o Module Id                                     */
/*              o Mode                                          */
/*                                                              */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* Configure N40G for traffic.                                  */
/*                                                              */
/* The [mode] parameter is specified as:                        */
/*   TEN_N40G_RX_DISABLE                           = 0,         */
/*   TEN_N40G_RX_BYPASS                            = 1,         */
/*   TEN_N40G_RX_BYPASS_SNT_MON                    = 2,         */
/*   TEN_N40G_RX_OTU3_ODTU23_10U_6J                = 3,         */
/*   TEN_N40G_RX_OTU3_ODTU23_10U                   = 4,         */
/*   TEN_N40G_RX_OTU3_ODTU23_7U                    = 5,         */
/*   TEN_N40G_RX_OTU3_ODU3_ORX                     = 6,         */
/*   TEN_N40G_RX_OTU3_ODTU23                       = 7,         */
/*   TEN_N40G_RX_OC768_ODU3                        = 8,         */
/*   TEN_N40G_RX_ODU3_ODU3                         = 9,         */
/*   TEN_N40G_RX_OTU3_ODU3                         = 10,        */
/*   TEN_N40G_RX_OTU3_ODTU23P_T21                  = 11,        */
/*   TEN_N40G_RX_OTU3_ODTU23P                      = 12,        */
/*   TEN_N40G_RX_OTU3_ODTU23P14                    = 13,        */
/*   TEN_N40G_RX_OTU3_ODU3_LS                      = 14,        */
/*   TEN_N40G_RX_OTU3_ODTU23P3                     = 15,        */
/*   TEN_N40G_RX_OTU3_ODTU23P7                     = 16,        */
/*   TEN_N40G_RX_ODU3_ODTU23                       = 17,        */
/*   TEN_N40G_RX_OTU2_GENRM_ODU3                   = 18,        */
/*   TEN_N40G_RX_ODU3_GENRM_OTU2                   = 19,        */
/*   TEN_N40G_RX_OTU3E_ODTU23P                     = 20.        */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  cs_status ret_val = CS_OK;
  cs_uint16 temp_dev_id;
  cs_uint16 temp_mod_num;

  CS_PRINT("ten_hl_n40g_rx_init.\n");
  
  if (mode >= TEN_N40G_RX_MAX_MODE) {
     CS_PRINT("Invalid Mode!\n");
     ret_val = CS_ERROR;
     goto RTN_EXIT;
  };

  CS_PRINT("mode = (Column #%d) %s\n", mode, ten_n40g_rx_debug_str[mode]);
  
  CS_PRINT("DPCFG0_BYSEL                   = 0x%04X\n", ten_n40g_rx_table[TEN_N40G_RX_DPCFG0_BYSEL][mode]);
  CS_PRINT("DPCFG0_BYPCFG                  = 0x%04X\n", ten_n40g_rx_table[TEN_N40G_RX_DPCFG0_BYPCFG][mode]);
  CS_PRINT("DPCFG0_OBY                     = 0x%04X\n", ten_n40g_rx_table[TEN_N40G_RX_DPCFG0_OBY][mode]);
  CS_PRINT("DPCFG0_SBY                     = 0x%04X\n", ten_n40g_rx_table[TEN_N40G_RX_DPCFG0_SBY][mode]);
  CS_PRINT("DPCFG0_MDPCFG                  = 0x%04X\n", ten_n40g_rx_table[TEN_N40G_RX_DPCFG0_MDPCFG][mode]);
  CS_PRINT("DPCFG0_KPASEL                  = 0x%04X\n", ten_n40g_rx_table[TEN_N40G_RX_DPCFG0_KPASEL][mode]);
  CS_PRINT("FRMLENGTH_NOFCOLS              = 0x%04X\n", ten_n40g_rx_table[TEN_N40G_RX_FRMLENGTH_NOFCOLS][mode]);
  CS_PRINT("SDFCFG_SCREN                   = 0x%04X\n", ten_n40g_rx_table[TEN_N40G_RX_SDFCFG_SCREN][mode]);
  CS_PRINT("SDFCFG_FAWWUP                  = 0x%04X\n", ten_n40g_rx_table[TEN_N40G_RX_SDFCFG_FAWWUP][mode]);
  CS_PRINT("SDFCFG_FAWWDW                  = 0x%04X\n", ten_n40g_rx_table[TEN_N40G_RX_SDFCFG_FAWWDW][mode]);
  CS_PRINT("SDFCFG_OOFHY                   = 0x%04X\n", ten_n40g_rx_table[TEN_N40G_RX_SDFCFG_OOFHY][mode]);
  CS_PRINT("SDFCFG1_ALTSCR                 = 0x%04X\n", ten_n40g_rx_table[TEN_N40G_RX_SDFCFG1_ALTSCR][mode]);
  CS_PRINT("OACFG0_PREDSCR                 = 0x%04X\n", ten_n40g_rx_table[TEN_N40G_RX_OACFG0_PREDSCR][mode]);
  CS_PRINT("OACFG0_POSTDSCR                = 0x%04X\n", ten_n40g_rx_table[TEN_N40G_RX_OACFG0_POSTDSCR][mode]);
  CS_PRINT("OACFG0_ALEN                    = 0x%04X\n", ten_n40g_rx_table[TEN_N40G_RX_OACFG0_ALEN][mode]);
  CS_PRINT("ODWCFG_STM256MD                = 0x%04X\n", ten_n40g_rx_table[TEN_N40G_RX_ODWCFG_STM256MD][mode]);
  CS_PRINT("ODWCFG_FSOMD                   = 0x%04X\n", ten_n40g_rx_table[TEN_N40G_RX_ODWCFG_FSOMD][mode]);
  CS_PRINT("ODWCFG_DW_ENABLE               = 0x%04X\n", ten_n40g_rx_table[TEN_N40G_RX_ODWCFG_DW_ENABLE][mode]);
  CS_PRINT("ODWCFG_AGGRMOD                 = 0x%04X\n", ten_n40g_rx_table[TEN_N40G_RX_ODWCFG_AGGRMOD][mode]);
  CS_PRINT("ODWCFG_STM64MD                 = 0x%04X\n", ten_n40g_rx_table[TEN_N40G_RX_ODWCFG_STM64MD][mode]);
  CS_PRINT("ODWCFG1_JC_ENABLE              = 0x%04X\n", ten_n40g_rx_table[TEN_N40G_RX_ODWCFG1_JC_ENABLE][mode]);
  CS_PRINT("ODWCFG1_JC_PLUS                = 0x%04X\n", ten_n40g_rx_table[TEN_N40G_RX_ODWCFG1_JC_PLUS][mode]);
  CS_PRINT("OFCFG1_NPARB                   = 0x%04X\n", ten_n40g_rx_table[TEN_N40G_RX_OFCFG1_NPARB][mode]);
  CS_PRINT("OFCFG1_NPAR                    = 0x%04X\n", ten_n40g_rx_table[TEN_N40G_RX_OFCFG1_NPAR][mode]);
  CS_PRINT("OFCFG0_NCOLS                   = 0x%04X\n", ten_n40g_rx_table[TEN_N40G_RX_OFCFG0_NCOLS][mode]);

  CS_PRINT("Provision High-Level N40G RX...\n");

  temp_dev_id = TEN_MOD_ID_TO_DEV_ID(module_id);
  temp_mod_num = TEN_MOD_ID_TO_MOD_NUM(module_id);
  if (mode == TEN_N40G_RX_DISABLE) {
    /* Disable clock */
    ten_mpif_global_clock_disable_n40g(temp_dev_id, temp_mod_num, CS_RX, CS_DISABLE);    
    /* Assert hard reset */
    ten_mpif_global_reset_n40g(temp_dev_id, temp_mod_num, CS_RX, CS_RESET_ASSERT);
    goto RTN_EXIT;
  }
  else if (mode == TEN_N40G_RX_BYPASS) {
  
    if ((ten_mpif_get_chip_jtag_id(TEN_MOD_ID_TO_DEV_ID(module_id)) == TEN_CHIP_ID_CS6004) ||
        (ten_mpif_get_chip_jtag_id(TEN_MOD_ID_TO_DEV_ID(module_id)) == TEN_CHIP_ID_CS6044)) {
      CS_PRINT("Skip N40G bypass setting for CS6004.\n");
    }
    else {
      ten_n40g_bypass_framer(module_id, CS_ENABLE );
    }  
    goto RTN_EXIT;
  }
    
  /* Enable clock */
  ten_mpif_global_clock_disable_n40g(temp_dev_id, temp_mod_num, CS_RX, CS_ENABLE);      
  /* Remove hard reset  */
  ten_mpif_global_reset_n40g(temp_dev_id, temp_mod_num, CS_RX, CS_RESET_DEASSERT);

  /* Assert block-level resets */
  ten_n40g_set_global_resets(module_id, CS_RESET_ASSERT,
                             TEN_N40G_GLOBAL_RESETS_ALL);
                             
  ten_n40g_gblr4x_set_dpcfg0(module_id, 
                             ten_n40g_rx_table[TEN_N40G_RX_DPCFG0_KPASEL][mode],
                             ten_n40g_rx_table[TEN_N40G_RX_DPCFG0_BYPCFG][mode],
                             ten_n40g_rx_table[TEN_N40G_RX_DPCFG0_MDPCFG][mode], 
                             ten_n40g_rx_table[TEN_N40G_RX_DPCFG0_BYSEL][mode],
                             ten_n40g_rx_table[TEN_N40G_RX_DPCFG0_OBY][mode],
                             ten_n40g_rx_table[TEN_N40G_RX_DPCFG0_SBY][mode]);
                                     
  ten_n40g_sdfr_set_sdfcfg(module_id, 
                           ten_n40g_rx_table[TEN_N40G_RX_SDFCFG_SCREN][mode], 
                           ten_n40g_rx_table[TEN_N40G_RX_SDFCFG_OOFHY][mode], 
                           ten_n40g_rx_table[TEN_N40G_RX_SDFCFG_FAWWUP][mode], 
                           ten_n40g_rx_table[TEN_N40G_RX_SDFCFG_FAWWDW][mode]);
                                   
  ten_n40g_sdfr_set_sdfcfg1(module_id, 
                            ten_n40g_rx_table[TEN_N40G_RX_SDFCFG1_ALTSCR][mode]);
                                    
  ten_n40g_otnr4x_descrambling(module_id, 
                              ten_n40g_rx_table[TEN_N40G_RX_OACFG0_POSTDSCR][mode], 
                              ten_n40g_rx_table[TEN_N40G_RX_OACFG0_PREDSCR][mode], 
                              ten_n40g_rx_table[TEN_N40G_RX_OACFG0_ALEN][mode]);
                                   
  ten_n40g_otnr4x_set_odwcfg(module_id, 
                             ten_n40g_rx_table[TEN_N40G_RX_ODWCFG_FSOMD][mode], 
                             ten_n40g_rx_table[TEN_N40G_RX_ODWCFG_STM64MD][mode], 
                             ten_n40g_rx_table[TEN_N40G_RX_ODWCFG_STM256MD][mode], 
                             ten_n40g_rx_table[TEN_N40G_RX_ODWCFG_AGGRMOD][mode], 
                             ten_n40g_rx_table[TEN_N40G_RX_ODWCFG_DW_ENABLE][mode]);
                             
                             
                                     
  ten_n40g_otnr4x_set_jc_enable(module_id,  
                                ten_n40g_rx_table[TEN_N40G_RX_ODWCFG1_JC_ENABLE][mode]);
                                        
  ten_n40g_otnr4x_set_jc_plus(module_id, 
                              ten_n40g_rx_table[TEN_N40G_RX_ODWCFG1_JC_PLUS][mode]);

  ten_n40g_otnr4x_set_nparb_npar(module_id, 
                                 ten_n40g_rx_table[TEN_N40G_RX_OFCFG1_NPARB][mode], 
                                 ten_n40g_rx_table[TEN_N40G_RX_OFCFG1_NPAR][mode]);
                                     
  ten_n40g_otnr4x_set_ncols(module_id, 
                            ten_n40g_rx_table[TEN_N40G_RX_OFCFG0_NCOLS][mode]);

  ten_hl_n40g_otn_aligner_settings(module_id);
  
  /* For a standard rate OTU3, a 3ms time corresponds to TDELON/TDELOFF=495 */
  ten_n40g_otnr4x_lofcfg_tdelon_tdeloff(module_id, 495, 495);
  
  ten_n40g_sdfr_lofcfg2_m0byte(module_id, 1);
  
  CS_PRINT("High-Level N40G RX Provisioning Complete.\n");
         
RTN_EXIT:         
  return(ret_val);
}

/****************************************************************/
/* $rtn_hdr_start  N40G TX INITIALIZATION                       */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : HIGH LEVEL                                      */
/* CHIP       : Tenabo                                          */
cs_status ten_hl_n40g_tx_init(cs_uint16 module_id,
                              cs_uint8 mode)
/* INPUTS     : o Module Id                                     */
/*              o Mode                                          */
/*                                                              */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* Configure N40G for traffic.                                  */
/*                                                              */
/* The [mode] parameter is specified as:                        */
/*   TEN_N40G_TX_DISABLE                           = 0,         */
/*   TEN_N40G_TX_BYPASS                            = 1,         */
/*   TEN_N40G_TX_BYPASS_SNT_MON                    = 2,         */
/*   TEN_N40G_TX_ODTU2_OTU3_10U_6J                 = 3,         */
/*   TEN_N40G_TX_ODTU2_OTU3_10U                    = 4,         */
/*   TEN_N40G_TX_ODTU2_OTU3_7U                     = 5,         */
/*   TEN_N40G_TX_ODU3_OTU3_ORV                     = 6,         */
/*   TEN_N40G_TX_ODTU2_OTU_T21A                    = 7,         */
/*   TEN_N40G_TX_ODTU2_OTU3                        = 8,         */
/*   TEN_N40G_TX_ODTU2_OTU3P_T21                   = 9,         */
/*   TEN_N40G_TX_ODTU2_OTU3P                       = 10,        */
/*   TEN_N40G_TX_ODTU2_OTU3P14                     = 11,        */
/*   TEN_N40G_TX_OC192_OTU3                        = 12,        */
/*   TEN_N40G_TX_ODU3_ODU3                         = 13,        */
/*   TEN_N40G_TX_ODU3_OTU3                         = 14,        */
/*   TEN_N40G_TX_ODU3_OTU3_SL                      = 15,        */
/*   TEN_N40G_TX_ODTU2_OTU3P3                      = 16,        */
/*   TEN_N40G_TX_ODTU2_OTU3P7                      = 17,        */
/*   TEN_N40G_TX_ODTU2_ODU3                        = 18,        */
/*   TEN_N40G_TX_OTU2_GENRM_ODU3                   = 19,        */
/*   TEN_N40G_TX_ODU3_GENRM_OTU2                   = 20,        */
/*   TEN_N40G_TX_OTU3E_ODTU23P                     = 21.        */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  cs_status ret_val = CS_OK;
  cs_uint16 temp_dev_id;
  cs_uint16 temp_mod_num;

  CS_PRINT("ten_hl_n40g_tx_init.\n");

  if (mode >= TEN_N40G_TX_MAX_MODE) {
     CS_PRINT("Invalid Mode!\n");
     ret_val = CS_ERROR;
     goto RTN_EXIT;
  };

  CS_PRINT("mode = (Column #%d) %s\n", mode, ten_n40g_tx_debug_str[mode]);
  
  CS_PRINT("CFG_MDPCFG                     = 0x%04X\n", ten_n40g_tx_table[TEN_N40G_TX_CFG_MDPCFG][mode]);
  CS_PRINT("CFG_SBY                        = 0x%04X\n", ten_n40g_tx_table[TEN_N40G_TX_CFG_SBY][mode]);
  CS_PRINT("CFG_OBY                        = 0x%04X\n", ten_n40g_tx_table[TEN_N40G_TX_CFG_OBY][mode]);
  CS_PRINT("CFG_KPGBY                      = 0x%04X\n", ten_n40g_tx_table[TEN_N40G_TX_CFG_KPGBY][mode]);
  CS_PRINT("OHIE_B1INV                     = 0x%04X\n", ten_n40g_tx_table[TEN_N40G_TX_OHIE_B1INV][mode]);
  CS_PRINT("OHIE_SCREN                     = 0x%04X\n", ten_n40g_tx_table[TEN_N40G_TX_OHIE_SCREN][mode]);
  CS_PRINT("OHIE_A1A2RSH                   = 0x%04X\n", ten_n40g_tx_table[TEN_N40G_TX_OHIE_A1A2RSH][mode]);
  CS_PRINT("OHIE_B1IE                      = 0x%04X\n", ten_n40g_tx_table[TEN_N40G_TX_OHIE_B1IE][mode]);
  CS_PRINT("OHIE_B1TRANS                   = 0x%04X\n", ten_n40g_tx_table[TEN_N40G_TX_OHIE_B1TRANS][mode]);
  CS_PRINT("B1ERRINS_B1ERRMSK              = 0x%04X\n", ten_n40g_tx_table[TEN_N40G_TX_B1ERRINS_B1ERRMSK][mode]);
  CS_PRINT("FRMLEN_FRMLEN                  = 0x%04X\n", ten_n40g_tx_table[TEN_N40G_TX_FRMLEN_FRMLEN][mode]);
  CS_PRINT("OCFG_PRESCR                    = 0x%04X\n", ten_n40g_tx_table[TEN_N40G_TX_OCFG_PRESCR][mode]);
  CS_PRINT("OCFG_POSTSCR                   = 0x%04X\n", ten_n40g_tx_table[TEN_N40G_TX_OCFG_POSTSCR][mode]);
  CS_PRINT("WRPCFG3_WRMD                   = 0x%04X\n", ten_n40g_tx_table[TEN_N40G_TX_WRPCFG3_WRMD][mode]);
  CS_PRINT("WRPCFG3_STM256MD               = 0x%04X\n", ten_n40g_tx_table[TEN_N40G_TX_WRPCFG3_STM256MD][mode]);
  CS_PRINT("WRPCFG3_STM64MD                = 0x%04X\n", ten_n40g_tx_table[TEN_N40G_TX_WRPCFG3_STM64MD][mode]);
  CS_PRINT("WRPCFG3_AGGRMOD                = 0x%04X\n", ten_n40g_tx_table[TEN_N40G_TX_WRPCFG3_AGGRMOD][mode]);
  CS_PRINT("WRPCFG4_JCEN                   = 0x%04X\n", ten_n40g_tx_table[TEN_N40G_TX_WRPCFG4_JCEN][mode]);
  CS_PRINT("WRPCFG4_JC_PLUS                = 0x%04X\n", ten_n40g_tx_table[TEN_N40G_TX_WRPCFG4_JC_PLUS][mode]);
  CS_PRINT("WRPCFG0_NCOLS                  = 0x%04X\n", ten_n40g_tx_table[TEN_N40G_TX_WRPCFG0_NCOLS][mode]);
  CS_PRINT("WRPCFG2_NPAR                   = 0x%04X\n", ten_n40g_tx_table[TEN_N40G_TX_WRPCFG2_NPAR][mode]);
  CS_PRINT("WRPCFG2_NPARB                  = 0x%04X\n", ten_n40g_tx_table[TEN_N40G_TX_WRPCFG2_NPARB][mode]);
  CS_PRINT("WRP0DH1_DTHYST01               = 0x%04X\n", ten_n40g_tx_table[TEN_N40G_TX_WRP0DH1_DTHYST01][mode]);
  CS_PRINT("WRP0DH0_DTHYST00               = 0x%04X\n", ten_n40g_tx_table[TEN_N40G_TX_WRP0DH0_DTHYST00][mode]);
  CS_PRINT("WRP1DH1_DTHYST11               = 0x%04X\n", ten_n40g_tx_table[TEN_N40G_TX_WRP1DH1_DTHYST11][mode]);
  CS_PRINT("WRP1DH0_DTHYST10               = 0x%04X\n", ten_n40g_tx_table[TEN_N40G_TX_WRP1DH0_DTHYST10][mode]);
  CS_PRINT("WRP2DH1_DTHYST21               = 0x%04X\n", ten_n40g_tx_table[TEN_N40G_TX_WRP2DH1_DTHYST21][mode]);
  CS_PRINT("WRP2DH0_DTHYST20               = 0x%04X\n", ten_n40g_tx_table[TEN_N40G_TX_WRP2DH0_DTHYST20][mode]);
  CS_PRINT("WRP3DH1_DTHYST31               = 0x%04X\n", ten_n40g_tx_table[TEN_N40G_TX_WRP3DH1_DTHYST31][mode]);
  CS_PRINT("WRP3DH0_DTHYST30               = 0x%04X\n", ten_n40g_tx_table[TEN_N40G_TX_WRP3DH0_DTHYST30][mode]);
  CS_PRINT("CFG0_PTIE                      = 0x%04X\n", ten_n40g_tx_table[TEN_N40G_TX_CFG0_PTIE][mode]);
  CS_PRINT("CFG2_PT                        = 0x%04X\n", ten_n40g_tx_table[TEN_N40G_TX_CFG2_PT][mode]);
  CS_PRINT("EXPTI_EXPTI                    = 0x%04X\n", ten_n40g_tx_table[TEN_N40G_TX_EXPTI_EXPTI][mode]);

  CS_PRINT("Provision High-Level N40G TX...\n");

  temp_dev_id = TEN_MOD_ID_TO_DEV_ID(module_id);
  temp_mod_num = TEN_MOD_ID_TO_MOD_NUM(module_id);
  if (mode == TEN_N40G_TX_DISABLE) {
    /* Disable clock */
    ten_mpif_global_clock_disable_n40g(temp_dev_id, temp_mod_num, CS_TX, CS_DISABLE);    
    /* Assert hard reset */
    ten_mpif_global_reset_n40g(temp_dev_id, temp_mod_num, CS_TX, CS_RESET_ASSERT);
    goto RTN_EXIT;
  }
  else if (mode == TEN_N40G_TX_BYPASS) {
    ten_n40g_bypass_framer(module_id, CS_ENABLE );
    goto RTN_EXIT;
  }
    
  /* Enable clock */
  ten_mpif_global_clock_disable_n40g(temp_dev_id, temp_mod_num, CS_TX, CS_ENABLE);      
  /* Remove hard reset  */
  ten_mpif_global_reset_n40g(temp_dev_id, temp_mod_num, CS_TX, CS_RESET_DEASSERT);

  /* Assert block-level resets*/
  ten_n40g_set_global_resets(module_id, CS_RESET_ASSERT,
                             TEN_N40G_GLOBAL_RESETS_ALL);
                             
  ten_n40g_gblt4x_set_cfg(module_id, 
                          ten_n40g_tx_table[TEN_N40G_TX_CFG_KPGBY][mode], 
                          ten_n40g_tx_table[TEN_N40G_TX_CFG_SBY][mode], 
                          ten_n40g_tx_table[TEN_N40G_TX_CFG_OBY][mode], 
                          ten_n40g_tx_table[TEN_N40G_TX_CFG_MDPCFG][mode]);
                                  
  ten_n40g_st4x_set_ohie(module_id, 
                         ten_n40g_tx_table[TEN_N40G_TX_OHIE_B1INV][mode], 
                         ten_n40g_tx_table[TEN_N40G_TX_OHIE_B1TRANS][mode], 
                         ten_n40g_tx_table[TEN_N40G_TX_OHIE_B1IE][mode], 
                         ten_n40g_tx_table[TEN_N40G_TX_OHIE_SCREN][mode],  
                         ten_n40g_tx_table[TEN_N40G_TX_OHIE_A1A2RSH][mode]);
                         
  ten_n40g_st4x_set_b1errins(module_id, 
                             ten_n40g_tx_table[TEN_N40G_TX_B1ERRINS_B1ERRMSK][mode]);

                           
  ten_n40g_otnt4x_scrambling(module_id, 
                             ten_n40g_tx_table[TEN_N40G_TX_OCFG_POSTSCR][mode], 
                             ten_n40g_tx_table[TEN_N40G_TX_OCFG_PRESCR][mode]);
                                     
  ten_n40g_otnt4x_set_wrpcfg3(module_id, 
                              ten_n40g_tx_table[TEN_N40G_TX_WRPCFG3_STM256MD][mode], 
                              ten_n40g_tx_table[TEN_N40G_TX_WRPCFG3_STM64MD][mode], 
                              ten_n40g_tx_table[TEN_N40G_TX_WRPCFG3_AGGRMOD][mode], 
                              ten_n40g_tx_table[TEN_N40G_TX_WRPCFG3_WRMD][mode]);
    
  ten_n40g_set_dsbldskw(module_id, ten_n40g_tx_table[TEN_N40G_TX_WRPCFG3_AGGRMOD][mode]);
                              
  ten_n40g_otnt4x_set_wrpcfg4(module_id, 
                              ten_n40g_tx_table[TEN_N40G_TX_WRPCFG4_JC_PLUS][mode], 
                              ten_n40g_tx_table[TEN_N40G_TX_WRPCFG4_JCEN][mode]);
                                      
  ten_n40g_otnt4x_set_ncols(module_id, 
                            ten_n40g_tx_table[TEN_N40G_TX_WRPCFG0_NCOLS][mode]);

  ten_n40g_otnt4x_set_nparb_npar(module_id, 
                              ten_n40g_tx_table[TEN_N40G_TX_WRPCFG2_NPARB][mode], 
                              ten_n40g_tx_table[TEN_N40G_TX_WRPCFG2_NPAR][mode]);
                              
  ten_n40g_otnt4x_set_wrp0dh1(module_id, 
                              ten_n40g_tx_table[TEN_N40G_TX_WRP0DH1_DTHYST01][mode]);
  ten_n40g_otnt4x_set_wrp0dh0(module_id, 
                              ten_n40g_tx_table[TEN_N40G_TX_WRP0DH0_DTHYST00][mode]);
  ten_n40g_otnt4x_set_wrp1dh1(module_id, 
                              ten_n40g_tx_table[TEN_N40G_TX_WRP1DH1_DTHYST11][mode]);
  ten_n40g_otnt4x_set_wrp1dh0(module_id, 
                              ten_n40g_tx_table[TEN_N40G_TX_WRP1DH0_DTHYST10][mode]);
  ten_n40g_otnt4x_set_wrp2dh1(module_id, 
                              ten_n40g_tx_table[TEN_N40G_TX_WRP2DH1_DTHYST21][mode]);
  ten_n40g_otnt4x_set_wrp2dh0(module_id, 
                              ten_n40g_tx_table[TEN_N40G_TX_WRP2DH0_DTHYST20][mode]);
  ten_n40g_otnt4x_set_wrp3dh1(module_id, 
                              ten_n40g_tx_table[TEN_N40G_TX_WRP3DH1_DTHYST31][mode]);
  ten_n40g_otnt4x_set_wrp3dh0(module_id, 
                              ten_n40g_tx_table[TEN_N40G_TX_WRP3DH0_DTHYST30][mode]);
     
  ten_n40g_otnt4x_set_ptie(module_id, ten_n40g_tx_table[TEN_N40G_TX_CFG0_PTIE][mode]);
    
  ten_n40g_set_pti_byte(module_id, ten_n40g_tx_table[TEN_N40G_TX_CFG2_PT][mode]);

  ten_n40g_set_expected_pti_byte(module_id, ten_n40g_tx_table[TEN_N40G_TX_EXPTI_EXPTI][mode]);
                                         
  CS_PRINT("High-Level N40G TX Provisioning Complete.\n");
                
RTN_EXIT:                
  return(ret_val);
}

/****************************************************************/
/* $rtn_hdr_start  N40G ASYNC DEWRAP GENERIC 40G CLIENT SW WORKAROUND */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : HIGH LEVEL                                      */
/* CHIP       : Tenabo                                          */
cs_status ten_hl_n40g_async_dewrap_generic_40g_client_sw_workaround(cs_uint16 module_id,
                                                      cs_uint8 block_id)
/* INPUTS     : o Module Id                                     */
/*              o SADECO Block Id                               */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* ISR for implementing the software workaround for             */
/* asynchronous dewrapping of generic 40g class clients.        */
/* The interrupt: N40G_OTNR4X_INTR (0x07183, 0x08183) IOOF      */
/* is the source for this ISR.                                  */
/*                                                              */
/* [block_id] parameter selects the SADECO instance:            */
/*   0 = Sadeco 0 (ES 0 - 3 TX)                                 */
/*   1 = Sadeco 1 (ES 4 - 7 TX).                                */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  /* cs_uint16 timeout = 0; */
  cs_uint16 tmp_dev_id = TEN_MOD_ID_TO_DEV_ID(module_id);
 
  CS_PRINT("ten_hl_n40g_async_dewrap_generic_40g_client_sw_workaround\n");
  
  if (block_id >= TEN_XCON_SADECO_COUNT) {
    CS_HNDL_ERROR(tmp_dev_id, ETEN_DEV_INVALID_USER_ARG, ": block_id out of range.  s/b 0..1.");
    return(CS_ERROR);
  }
  
  if (ten_n40g_otnr4x_get_ofstat(module_id, TEN_N40G_OTNR4X_STATUS_SOOF)) {
    CS_PRINT("SOOF=1 detected!\n");
    ten_xcon_sadeco_sadcfg3_rsymsk(tmp_dev_id, block_id, 0x1F);
  }
  else {
     CS_PRINT("SOOF=0 detected!\n");
     for (;;) {
       /* check for recovery indefinitely, could be days until  */
       /* cut cable is restored.                                */
       if (ten_xcon_sadeco_sadstat(tmp_dev_id, block_id)) {
         CS_PRINT("Recovered:  SOOF=0 and SADSTAT=1.\n");
         break;
       }
       CS_PRINT("Wait for recovery...\n");
       TEN_MDELAY(100);
       #if 0
       timeout++;
       if (timeout == 20) {
         CS_PRINT("Timed out waiting for recovery...\n");
         break;
       }  
       #endif
     } 
     ten_xcon_sadeco_sadcfg3_rsymsk(tmp_dev_id, block_id, 0x10);
  }
  return (CS_OK);
}
#endif

/****************************************************************/
/* $rtn_hdr_start  N40G CONFIG JC                               */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : HIGH LEVEL                                      */
/* CHIP       : Tenabo                                          */
cs_status ten_hl_n40g_config_jc(cs_uint16 module_id,
                                cs_uint8 slice)
/* INPUTS     : o Module Id                                     */
/*              o Slice                                         */
/*                                                              */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* Set N40G determistic justification.                          */
/*                                                              */
/* The [slice] parameter is specified as:                       */
/*   0x00 = TEN_SLICE0                                          */
/*   0x01 = TEN_SLICE1                                          */
/*   0x02 = TEN_SLICE2                                          */
/*   0x03 = TEN_SLICE3                                          */
/*   0xFF = TEN_SLICE_ALL.                                      */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  cs_status rtn = CS_OK;
  cs_uint16 n40g_jc_en = 0;

  /* Set N40G determistic justification    */
  /* Turn off jc enable in ODTU23 and ODU2 */
  rtn |= ten_n40g_otnt4x_set_wrp0dh1(module_id, 0xFF);
  rtn |= ten_n40g_otnt4x_set_wrp0dh0(module_id, 0x03);

   switch (slice) {
   case (TEN_SLICE0):
     n40g_jc_en = 0xe;
     break;
   case (TEN_SLICE1): 
     n40g_jc_en = 0xd;
     break;
   case (TEN_SLICE2):
     n40g_jc_en = 0xb;
     break;
   case (TEN_SLICE3):
   default:
     n40g_jc_en = 0x7;
     break;
   }
   rtn |= ten_n40g_otnt4x_set_wrpcfg4(module_id, 1, n40g_jc_en);
   rtn |= ten_n10g_set_otnt_wrpcfg4(module_id, slice, 0, 0, 1, 0, 0);
   return (rtn);
}

/****************************************************************/
/* $rtn_hdr_start  N40G CONFIG PTI                              */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : HIGH LEVEL                                      */
/* CHIP       : Tenabo                                          */
cs_status ten_hl_n40g_config_pti(cs_uint16 module_id,
                                 cs_uint16 client)
/* INPUTS     : o Module Id                                     */
/*              o Client                                        */
/*                                                              */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* Provision the PTI overhead for OTU3.                         */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  cs_status rtn = CS_OK;
  cs_uint16 pti = 0xFFFF;
  cs_uint16 pti_applicable = TRUE;
  
  switch (client) {
  case (TEN_TRAFFIC_TYPE_ODTU23):
    pti = 0x20;
    break;
    
  default:
    pti_applicable = FALSE;
    break;
  }
  
  if (pti_applicable) {
    rtn |= ten_n40g_otnt4x_set_ptie(module_id, 1);
    rtn |= ten_n40g_set_pti_byte(module_id, pti);
    rtn |= ten_n40g_set_expected_pti_byte(module_id, pti);
  }
  return (rtn);
}

/* Bugzilla 24360 Start */
/****************************************************************/
/* $rtn_hdr_start  N40G CONFIG PTI T41                          */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : HIGH LEVEL                                      */
/* CHIP       : Tenabo                                          */
cs_status ten_hl_n40g_config_pti_t41 (cs_uint16 module_id,
                                      cs_uint16 client,
                                      cs_uint16 map_proc,
                                      cs_uint16 timeslots,
                                      cs_uint16 kpga)
/* INPUTS     : o Module Id                                     */
/*              o Client                                        */
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
/* The [client] parameter is specified as:                      */
/*  TEN_TRAFFIC_TYPE_ODTU23               = 4                   */
/*  TEN_TRAFFIC_TYPE_40GELAN              = 21,                 */
/*  TEN_TRAFFIC_TYPE_OC768                = 22,                 */
/*  TEN_TRAFFIC_TYPE_CBR40G_50188149150   = 24,                 */
/*  TEN_TRAFFIC_TYPE_OC768_OTU3           = 32,                 */
/*  TEN_TRAFFIC_TYPE_ODTU                 = 38,                 */
/*  TEN_TRAFFIC_TYPE_TC_40GE              = 43,                 */
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
  cs_char8 *func = "ten_hl_n40g_config_pti_t41";  
  
  CS_PRINT("%s() %s, %s",
           func,
           ten_module_strings[module_id & 1],
           ten_hl_config_traffic_types_strings[client]);
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
      case (TEN_TRAFFIC_TYPE_OC768):
      case (TEN_TRAFFIC_TYPE_OC768_OTU3):
        if (map_proc == TEN_MAP_BMP) {
          pti = TEN_PAYLOAD_TYPE_SYNC_CBR;
        }
        else {
          pti = TEN_PAYLOAD_TYPE_ASYNC_CBR;
        }
        break;

      case (TEN_TRAFFIC_TYPE_CBR40G_50188149150):
        pti = TEN_PAYLOAD_TYPE_ASYNC_CBR;  /* ??????????????? */
        break;
      
      /* Bugzilla 28006 Start */
      case (TEN_TRAFFIC_TYPE_40GELAN):
      case (TEN_TRAFFIC_TYPE_SERIAL_40GE):
      case (TEN_TRAFFIC_TYPE_PARALLEL_40GE):
      case (TEN_TRAFFIC_TYPE_TC_40GE):
      case (TEN_TRAFFIC_TYPE_S64_66_40GE):
        if ((map_proc == TEN_MAP_AMP_PROP) || (map_proc == TEN_MAP_AMP_PROP_DT)) {
          pti = TEN_PAYLOAD_TYPE_CORTINA_MAPPING; /* ??????????????? */
        } else {  
          pti = TEN_PAYLOAD_TYPE_40GBASE_R;
        }  
        break;
      
     #if 0
      case (TEN_TRAFFIC_TYPE_TC_40GE):
        if ((map_proc == TEN_MAP_AMP_PROP) || (map_proc == TEN_MAP_AMP_PROP_DT)) {
          pti = TEN_PAYLOAD_TYPE_CORTINA_MAPPING;
        } else {  
          pti = TEN_PAYLOAD_TYPE_GFP;    /* ??????????????? */
        }  
        break;
     #endif   
      /* Bugzilla 28006 End */
      
      case (TEN_TRAFFIC_TYPE_ODTU):
      case (TEN_TRAFFIC_TYPE_ODTU23):
        /* Line side is a muxponder */
        if ((map_proc == TEN_MAP_GMP_HO) || (map_proc == TEN_MAP_GMP_HO_DT) || (timeslots == 8)) {
          pti = TEN_PAYLOAD_TYPE_ODU_ODTUK_MUX;
        } else {
          pti = TEN_PAYLOAD_TYPE_ODU_MUX;
        }
        break;
      
      default:
        break;
    }
  }

  
  if (pti != 0xFFFF) {
    rtn |= ten_n40g_otnt4x_set_ptie (module_id, 1);          /* Enable payload type identifier insertion */
    rtn |= ten_n40g_set_pti_byte (module_id, pti);           /* Set payload type identifier to be sent */
    rtn |= ten_n40g_set_expected_pti_byte (module_id, pti);  /* Set expected payload type identifier to be received */
  } else {
    rtn |= ten_n40g_otnt4x_set_ptie (module_id, 0);          /* Disable payload type identifier insertion */
  }
  
  return (rtn);
}
/* Bugzilla 24360 End */

/******************************************************************************/
/* CATEGORY   : API                                                           */
/* ACCESS     : Public                                                        */
/* BLOCK      : HIGH LEVEL                                                    */
/* CHIP       : Tenabo                                                        */
cs_status ten_n40g_gmp_ho_tsen_t41 (cs_uint16 module_id,
                                    cs_uint16 slice,
                                    cs_uint16 gmp_timeslot_mask)
/* INPUTS     : o Module_id                                                   */
/*              o                                                             */
/* OUTPUTS    : ----                                                          */
/* RETURNS    : CS_OK or CS_ERROR                                             */
/* DESCRIPTION:                                                               */
/*   Enable time slots in the tributary for the given port                    */
/* Assume the following:                                                      */
/*    Tributary 3 uses time slices 31, 27, 23 ... 3                           */
/*    Tributary 2 uses time slices 30, 26, 22 ... 2                           */
/*    Tributary 1 uses time slices 29, 25, 21 ... 1                           */
/*    Tributary 0 uses time slices 28, 24, 20 ... 0                           */
/*                                                                            */
/******************************************************************************/
{
  cs_uint16 numTimeSlot;
  cs_uint16 tributary;
  cs_uint32 tributary_set;
  cs_uint16 tributary_mask;
  cs_uint16 timeSlotBit;
  TEN_N40G_OGMPR4X_ODWTSENABLE0_t tmp_n40g_ogmpr4x_odwtsenable0;
  TEN_N40G_OGMPR4X_ODWTSENABLE1_t tmp_n40g_ogmpr4x_odwtsenable1;
  TEN_N40G_OTNT4X_WRPTSENABLE0_t tmp_n40g_otnt4x_wrptsenable0;
  TEN_N40G_OTNT4X_WRPTSENABLE1_t tmp_n40g_otnt4x_wrptsenable1;
  T41_t *pDev = NULL;
  cs_char8 *func = "ten_n40g_gmp_ho_tsen_t41";  

  CS_PRINT("%s() %s, %s, gmp_timeslot_mask=0x%X\n",
           func,
           ten_module_strings[module_id&1],
           ten_slice_strings[slice],
           gmp_timeslot_mask);

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, FALSE);
  TEN_MOD_LOCK(module_id, TEN_ID_N40G);

  /* Read RX timeslot enable bits */
  tmp_n40g_ogmpr4x_odwtsenable0.wrd = TEN_REG_READ(TEN_N40G_REG_ADDR(pDev, module_id, ODWTSENABLE0));
  tmp_n40g_ogmpr4x_odwtsenable1.wrd = TEN_REG_READ(TEN_N40G_REG_ADDR(pDev, module_id, ODWTSENABLE1));
  
  /* Read TX timeslot enable bits */
  tmp_n40g_otnt4x_wrptsenable0.wrd = TEN_REG_READ(TEN_N40G_REG_ADDR(pDev, module_id, WRPTSENABLE0));
  tmp_n40g_otnt4x_wrptsenable1.wrd = TEN_REG_READ(TEN_N40G_REG_ADDR(pDev, module_id, WRPTSENABLE1));

  switch (slice) {
    case 0 :
      /* Tributary 3 */
      tributary = 3;
      tributary_mask = (cs_uint16)~0x8888;
      break;
      
    case 1 :
      /* Tributary 2 */
      tributary = 2;
      tributary_mask = ~0x4444;
      break;
      
    case 2 :
      /* Tributary 1 */
      tributary = 1;
      tributary_mask = ~0x2222;
      break;
      
    case 3 :
      /* Tributary 0 */
      tributary = 0;
      tributary_mask = ~0x1111;
      break;
      
    default:
      CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, "invalid slice.");
      tributary = 0;
      tributary_mask = 0;
      break;
  }
      
  /* Build Time Slot enable bit word for this tributary */
  tributary_set = 0;
  for (numTimeSlot = 0; numTimeSlot < 8; numTimeSlot++) {
    timeSlotBit = (gmp_timeslot_mask >> numTimeSlot) & 1;  /* Get bit */
    tributary_set |= timeSlotBit << (tributary + (numTimeSlot*4));
  }    
      
  /* Zero the timeslot bits for this tributary */    
  tmp_n40g_ogmpr4x_odwtsenable0.wrd &= tributary_mask;    
  tmp_n40g_ogmpr4x_odwtsenable1.wrd &= tributary_mask;    

  tmp_n40g_otnt4x_wrptsenable0.wrd &= tributary_mask;
  tmp_n40g_otnt4x_wrptsenable1.wrd &= tributary_mask;
      
  /* Enable the timeslot bits for this tributary */
  tmp_n40g_ogmpr4x_odwtsenable0.wrd |= tributary_set%65536; /* 0x10000 */
  tmp_n40g_ogmpr4x_odwtsenable1.wrd |= tributary_set>>16;    

  tmp_n40g_otnt4x_wrptsenable0.wrd |= tributary_set%65536;
  tmp_n40g_otnt4x_wrptsenable1.wrd |= tributary_set>>16;

  /* Write RX timeslot enable bits */
  TEN_REG_WRITE(TEN_N40G_REG_ADDR(pDev, module_id, ODWTSENABLE0), tmp_n40g_ogmpr4x_odwtsenable0.wrd);
  TEN_REG_WRITE(TEN_N40G_REG_ADDR(pDev, module_id, ODWTSENABLE1), tmp_n40g_ogmpr4x_odwtsenable1.wrd);
      
  /* Write RX timeslot enable bits */
  TEN_REG_WRITE(TEN_N40G_REG_ADDR(pDev, module_id, WRPTSENABLE0), tmp_n40g_otnt4x_wrptsenable0.wrd);
  TEN_REG_WRITE(TEN_N40G_REG_ADDR(pDev, module_id, WRPTSENABLE1), tmp_n40g_otnt4x_wrptsenable1.wrd);
  TEN_MOD_UNLOCK(module_id, TEN_ID_N40G);
      
  CS_PRINT("%s() tributary_mask = 0x%X\n", func, tributary_mask);
  CS_PRINT("%s() tributary_set = 0x%X\n", func, tributary_set);

  return (CS_OK);
}

/* Bugzilla 26275, Bugzilla 26308 Start */
/******************************************************************************/
/* CATEGORY   : API                                                           */
/* ACCESS     : Public                                                        */
/* BLOCK      : HIGH LEVEL                                                    */
/* CHIP       : Tenabo                                                        */
cs_status ten_n40g_tx_gmp_ho_client_data_entity_t41 (cs_uint16 module_id,
                                                     cs_uint16 slice,
                                                     cs_uint32 Cn,
                                                     cs_uint16 timeslots)
/* INPUTS     : o Module_id                                                   */
/*              o Slice                                                       */
/*              o Cn                                                          */
/*              o Time Slots                                                  */
/* OUTPUTS    : ----                                                          */
/* RETURNS    : CS_OK or CS_ERROR                                             */
/* DESCRIPTION:                                                               */
/*   Provision Client Data Entity for GMP                                     */
/*                                                                            */
/******************************************************************************/
{
  T41_t *pDev = NULL;
  cs_uint16 Cm = 0;
  TEN_N40G_OTNT4X_WRPCFG1_3_t tmp_n40g_otnt4x_wrpcfg1_3;
  TEN_N40G_OTNT4X_CMCFG3_t tmp_n40g_otnt4x_cmcfg3;
  TEN_N40G_OTNT4X_CNCFG31_t tmp_n40g_otnt4x_cncfg31;
  TEN_N40G_OTNT4X_GMPCFG1_t tmp_n40g_otnt4x_gmpcfg1;
  TEN_N40G_OTNT4X_CNCFG30_t tmp_n40g_otnt4x_cncfg30;

  TEN_N40G_OTNT4X_CMCFG2_t tmp_n40g_otnt4x_cmcfg2;
  TEN_N40G_OTNT4X_CNCFG21_t tmp_n40g_otnt4x_cncfg21;
  TEN_N40G_OTNT4X_WRPCFG1_2_t tmp_n40g_otnt4x_wrpcfg1_2;
  TEN_N40G_OTNT4X_CNCFG20_t tmp_n40g_otnt4x_cncfg20;

  TEN_N40G_OTNT4X_CMCFG1_t tmp_n40g_otnt4x_cmcfg1;
  TEN_N40G_OTNT4X_CNCFG11_t tmp_n40g_otnt4x_cncfg11;
  TEN_N40G_OTNT4X_CNCFG10_t tmp_n40g_otnt4x_cncfg10;
  TEN_N40G_OTNT4X_WRPCFG1_1_t tmp_n40g_otnt4x_wrpcfg1_1;

  TEN_N40G_OTNT4X_CNCFG00_t tmp_n40g_otnt4x_cncfg00;
  TEN_N40G_OTNT4X_WRPCFG1_t tmp_n40g_otnt4x_wrpcfg1;
  TEN_N40G_OTNT4X_CMCFG0_t tmp_n40g_otnt4x_cmcfg0;
  TEN_N40G_OTNT4X_CNCFG01_t tmp_n40g_otnt4x_cncfg01;
  
  TEN_N40G_OGMPR4X_GMPODWCFG0_t tmp_n40g_ogmpr4x_gmpodwcfg0;
  TEN_N40G_OGMPR4X_CNCFG00_t tmp_n40g_ogmpr4x_cncfg00;
  TEN_N40G_OGMPR4X_CNCFG01_t tmp_n40g_ogmpr4x_cncfg01;
  TEN_N40G_OGMPR4X_GMPODW0CFG1_t tmp_n40g_ogmpr4x_gmpodw0cfg1;

  TEN_N40G_OGMPR4X_CNCFG10_t tmp_n40g_ogmpr4x_cncfg10;
  TEN_N40G_OGMPR4X_CNCFG11_t tmp_n40g_ogmpr4x_cncfg11;
  TEN_N40G_OGMPR4X_GMPODW1CFG1_t tmp_n40g_ogmpr4x_gmpodw1cfg1;

  TEN_N40G_OGMPR4X_CNCFG20_t tmp_n40g_ogmpr4x_cncfg20;
  TEN_N40G_OGMPR4X_CNCFG21_t tmp_n40g_ogmpr4x_cncfg21;
  TEN_N40G_OGMPR4X_GMPODW2CFG1_t tmp_n40g_ogmpr4x_gmpodw2cfg1;

  TEN_N40G_OGMPR4X_CNCFG30_t tmp_n40g_ogmpr4x_cncfg30;
  TEN_N40G_OGMPR4X_CNCFG31_t tmp_n40g_ogmpr4x_cncfg31;
  TEN_N40G_OGMPR4X_GMPODW3CFG1_t tmp_n40g_ogmpr4x_gmpodw3cfg1;

  
  cs_char8 *func = "ten_n40g_tx_gmp_ho_client_data_entity_t41";  

  
  TEN_MOD_COMMON_VALIDATE(module_id, pDev, FALSE);

  /* Klocwork changes */
  if (!timeslots) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, "Cannot divide by timeslots = 0.");
    return (CS_ERROR);
  }
  
  Cm = (cs_uint16)(Cn / timeslots);
  
  CS_PRINT("%s() %s, %s, Cm=%d, timeslots=%d\n",
           func,
           ten_module_strings[module_id&1],
           ten_slice_strings[slice],
           Cm,
           timeslots);

  /*Cn0 = (cs_uint16)(Cn%65536);*/
  /*Cn1 = (cs_uint16)(Cn>>16);  */
  /*CS_PRINT("%s() Cn=%d\n", func, Cn);                    */
  /*CS_PRINT("%s() Cn=%d:%d\n", func, Cn0, Cn1);           */
  /*CS_PRINT("%s() Cn=%d, Cn=%d:%d\n", func, Cn, Cn0, Cn1);*/
  CS_PRINT("%s() Cn=%d, Cn=%d:%d\n", func, Cn, Cn>>16, Cn%65536);
  CS_PRINT("%s() Cn=%d, Cn=0x%04X:%04X\n", func, Cn, Cn>>16, Cn%65536);
  
  TEN_MOD_LOCK(module_id, TEN_ID_N40G);
  switch (slice) {
    case 0 :
      /* Tributary 3 */
      /* Provision TX side */
      tmp_n40g_otnt4x_gmpcfg1.wrd = TEN_REG_READ(TEN_N40G_REG_ADDR(pDev, module_id, GMPCFG1));
      tmp_n40g_otnt4x_gmpcfg1.bf.GMPMD3 = 1;
      TEN_REG_WRITE(TEN_N40G_REG_ADDR(pDev, module_id, GMPCFG1), tmp_n40g_otnt4x_gmpcfg1.wrd);

      tmp_n40g_otnt4x_cncfg31.wrd = TEN_REG_READ(TEN_N40G_REG_ADDR(pDev, module_id, otnt4x_CNCFG31));
      tmp_n40g_otnt4x_cncfg31.bf.Cn31 = Cn>>16;
      TEN_REG_WRITE(TEN_N40G_REG_ADDR(pDev, module_id, otnt4x_CNCFG31), tmp_n40g_otnt4x_cncfg31.wrd);

      tmp_n40g_otnt4x_cncfg30.wrd = TEN_REG_READ(TEN_N40G_REG_ADDR(pDev, module_id, otnt4x_CNCFG30));
      tmp_n40g_otnt4x_cncfg30.bf.Cn30 = Cn%65536;
      TEN_REG_WRITE(TEN_N40G_REG_ADDR(pDev, module_id, otnt4x_CNCFG30), tmp_n40g_otnt4x_cncfg30.wrd);

      tmp_n40g_otnt4x_cmcfg3.wrd = TEN_REG_READ(TEN_N40G_REG_ADDR(pDev, module_id, CMCFG3));
      tmp_n40g_otnt4x_cmcfg3.bf.CmInit = Cm;
      TEN_REG_WRITE(TEN_N40G_REG_ADDR(pDev, module_id, CMCFG3), tmp_n40g_otnt4x_cmcfg3.wrd);

      tmp_n40g_otnt4x_wrpcfg1_3.wrd = TEN_REG_READ(TEN_N40G_REG_ADDR(pDev, module_id, WRPCFG1_3));
      tmp_n40g_otnt4x_wrpcfg1_3.bf.JCHYST = 0;
      TEN_REG_WRITE(TEN_N40G_REG_ADDR(pDev, module_id, WRPCFG1_3), tmp_n40g_otnt4x_wrpcfg1_3.wrd);

      /* Provision RX side */
      tmp_n40g_ogmpr4x_gmpodwcfg0.wrd = TEN_REG_READ(TEN_N40G_REG_ADDR(pDev, module_id, GMPODWCFG0));
      tmp_n40g_ogmpr4x_gmpodwcfg0.bf.GMPMD3 = 1;
      TEN_REG_WRITE(TEN_N40G_REG_ADDR(pDev, module_id, GMPODWCFG0), tmp_n40g_ogmpr4x_gmpodwcfg0.wrd);

      tmp_n40g_ogmpr4x_cncfg31.wrd = TEN_REG_READ(TEN_N40G_REG_ADDR(pDev, module_id, ogmpr4x_CNCFG31));
      tmp_n40g_ogmpr4x_cncfg31.bf.Cn31 = Cn>>16;
      TEN_REG_WRITE(TEN_N40G_REG_ADDR(pDev, module_id, ogmpr4x_CNCFG31), tmp_n40g_ogmpr4x_cncfg31.wrd);

      tmp_n40g_ogmpr4x_cncfg30.wrd = TEN_REG_READ(TEN_N40G_REG_ADDR(pDev, module_id, ogmpr4x_CNCFG30));
      tmp_n40g_ogmpr4x_cncfg30.bf.Cn30 = Cn%65536;
      TEN_REG_WRITE(TEN_N40G_REG_ADDR(pDev, module_id, ogmpr4x_CNCFG30), tmp_n40g_ogmpr4x_cncfg30.wrd);

      tmp_n40g_ogmpr4x_gmpodw3cfg1.wrd = TEN_REG_READ(TEN_N40G_REG_ADDR(pDev, module_id, GMPODW3CFG1));
      tmp_n40g_ogmpr4x_gmpodw3cfg1.bf.ADJMAX = 0x40;
      TEN_REG_WRITE(TEN_N40G_REG_ADDR(pDev, module_id, GMPODW3CFG1), tmp_n40g_ogmpr4x_gmpodw3cfg1.wrd);
      break;
      
    case 1 :
      /* Tributary 2 */
      tmp_n40g_otnt4x_gmpcfg1.wrd = TEN_REG_READ(TEN_N40G_REG_ADDR(pDev, module_id, GMPCFG1));
      tmp_n40g_otnt4x_gmpcfg1.bf.GMPMD2 = 1;
      TEN_REG_WRITE(TEN_N40G_REG_ADDR(pDev, module_id, GMPCFG1), tmp_n40g_otnt4x_gmpcfg1.wrd);

      tmp_n40g_otnt4x_cncfg21.wrd = TEN_REG_READ(TEN_N40G_REG_ADDR(pDev, module_id, otnt4x_CNCFG21));
      tmp_n40g_otnt4x_cncfg21.bf.Cn21 = Cn>>16;
      TEN_REG_WRITE(TEN_N40G_REG_ADDR(pDev, module_id, otnt4x_CNCFG21), tmp_n40g_otnt4x_cncfg21.wrd);

      tmp_n40g_otnt4x_cncfg20.wrd = TEN_REG_READ(TEN_N40G_REG_ADDR(pDev, module_id, otnt4x_CNCFG20));
      tmp_n40g_otnt4x_cncfg20.bf.Cn20 = Cn%65536;
      TEN_REG_WRITE(TEN_N40G_REG_ADDR(pDev, module_id, otnt4x_CNCFG20), tmp_n40g_otnt4x_cncfg20.wrd);

      tmp_n40g_otnt4x_cmcfg2.wrd = TEN_REG_READ(TEN_N40G_REG_ADDR(pDev, module_id, CMCFG2));
      tmp_n40g_otnt4x_cmcfg2.bf.CmInit = Cm;
      TEN_REG_WRITE(TEN_N40G_REG_ADDR(pDev, module_id, CMCFG2), tmp_n40g_otnt4x_cmcfg2.wrd);

      tmp_n40g_otnt4x_wrpcfg1_2.wrd = TEN_REG_READ(TEN_N40G_REG_ADDR(pDev, module_id, WRPCFG1_2));
      tmp_n40g_otnt4x_wrpcfg1_2.bf.JCHYST = 0;
      TEN_REG_WRITE(TEN_N40G_REG_ADDR(pDev, module_id, WRPCFG1_2), tmp_n40g_otnt4x_wrpcfg1_2.wrd);

      /* Provision RX side */
      tmp_n40g_ogmpr4x_gmpodwcfg0.wrd = TEN_REG_READ(TEN_N40G_REG_ADDR(pDev, module_id, GMPODWCFG0));
      tmp_n40g_ogmpr4x_gmpodwcfg0.bf.GMPMD2 = 1;
      TEN_REG_WRITE(TEN_N40G_REG_ADDR(pDev, module_id, GMPODWCFG0), tmp_n40g_ogmpr4x_gmpodwcfg0.wrd);

      tmp_n40g_ogmpr4x_cncfg21.wrd = TEN_REG_READ(TEN_N40G_REG_ADDR(pDev, module_id, ogmpr4x_CNCFG21));
      tmp_n40g_ogmpr4x_cncfg21.bf.Cn21 = Cn>>16;
      TEN_REG_WRITE(TEN_N40G_REG_ADDR(pDev, module_id, ogmpr4x_CNCFG21), tmp_n40g_ogmpr4x_cncfg21.wrd);

      tmp_n40g_ogmpr4x_cncfg20.wrd = TEN_REG_READ(TEN_N40G_REG_ADDR(pDev, module_id, ogmpr4x_CNCFG20));
      tmp_n40g_ogmpr4x_cncfg20.bf.Cn20 = Cn%65536;
      TEN_REG_WRITE(TEN_N40G_REG_ADDR(pDev, module_id, ogmpr4x_CNCFG20), tmp_n40g_ogmpr4x_cncfg20.wrd);

      tmp_n40g_ogmpr4x_gmpodw2cfg1.wrd = TEN_REG_READ(TEN_N40G_REG_ADDR(pDev, module_id, GMPODW2CFG1));
      tmp_n40g_ogmpr4x_gmpodw2cfg1.bf.ADJMAX = 0x40;
      TEN_REG_WRITE(TEN_N40G_REG_ADDR(pDev, module_id, GMPODW2CFG1), tmp_n40g_ogmpr4x_gmpodw2cfg1.wrd);
      break;

    case 2 :
      /* Tributary 1 */
      tmp_n40g_otnt4x_gmpcfg1.wrd = TEN_REG_READ(TEN_N40G_REG_ADDR(pDev, module_id, GMPCFG1));
      tmp_n40g_otnt4x_gmpcfg1.bf.GMPMD1 = 1;
      TEN_REG_WRITE(TEN_N40G_REG_ADDR(pDev, module_id, GMPCFG1), tmp_n40g_otnt4x_gmpcfg1.wrd);

      tmp_n40g_otnt4x_cncfg11.wrd = TEN_REG_READ(TEN_N40G_REG_ADDR(pDev, module_id, otnt4x_CNCFG11));
      tmp_n40g_otnt4x_cncfg11.bf.Cn11 = Cn>>16;
      TEN_REG_WRITE(TEN_N40G_REG_ADDR(pDev, module_id, otnt4x_CNCFG11), tmp_n40g_otnt4x_cncfg11.wrd);

      tmp_n40g_otnt4x_cncfg10.wrd = TEN_REG_READ(TEN_N40G_REG_ADDR(pDev, module_id, otnt4x_CNCFG10));
      tmp_n40g_otnt4x_cncfg10.bf.Cn10 = Cn%65536;
      TEN_REG_WRITE(TEN_N40G_REG_ADDR(pDev, module_id, otnt4x_CNCFG10), tmp_n40g_otnt4x_cncfg10.wrd);

      tmp_n40g_otnt4x_cmcfg1.wrd = TEN_REG_READ(TEN_N40G_REG_ADDR(pDev, module_id, CMCFG1));
      tmp_n40g_otnt4x_cmcfg1.bf.CmInit = Cm;
      TEN_REG_WRITE(TEN_N40G_REG_ADDR(pDev, module_id, CMCFG1), tmp_n40g_otnt4x_cmcfg1.wrd);

      tmp_n40g_otnt4x_wrpcfg1_1.wrd = TEN_REG_READ(TEN_N40G_REG_ADDR(pDev, module_id, WRPCFG1_1));
      tmp_n40g_otnt4x_wrpcfg1_1.bf.JCHYST = 0;
      TEN_REG_WRITE(TEN_N40G_REG_ADDR(pDev, module_id, WRPCFG1_1), tmp_n40g_otnt4x_wrpcfg1_1.wrd);

      /* Provision RX side */
      tmp_n40g_ogmpr4x_gmpodwcfg0.wrd = TEN_REG_READ(TEN_N40G_REG_ADDR(pDev, module_id, GMPODWCFG0));
      tmp_n40g_ogmpr4x_gmpodwcfg0.bf.GMPMD1 = 1;
      TEN_REG_WRITE(TEN_N40G_REG_ADDR(pDev, module_id, GMPODWCFG0), tmp_n40g_ogmpr4x_gmpodwcfg0.wrd);

      tmp_n40g_ogmpr4x_cncfg11.wrd = TEN_REG_READ(TEN_N40G_REG_ADDR(pDev, module_id, ogmpr4x_CNCFG11));
      tmp_n40g_ogmpr4x_cncfg11.bf.Cn11 = Cn>>16;
      TEN_REG_WRITE(TEN_N40G_REG_ADDR(pDev, module_id, ogmpr4x_CNCFG11), tmp_n40g_ogmpr4x_cncfg11.wrd);

      tmp_n40g_ogmpr4x_cncfg10.wrd = TEN_REG_READ(TEN_N40G_REG_ADDR(pDev, module_id, ogmpr4x_CNCFG10));
      tmp_n40g_ogmpr4x_cncfg10.bf.Cn10 = Cn%65536;
      TEN_REG_WRITE(TEN_N40G_REG_ADDR(pDev, module_id, ogmpr4x_CNCFG10), tmp_n40g_ogmpr4x_cncfg10.wrd);

      tmp_n40g_ogmpr4x_gmpodw1cfg1.wrd = TEN_REG_READ(TEN_N40G_REG_ADDR(pDev, module_id, GMPODW1CFG1));
      tmp_n40g_ogmpr4x_gmpodw1cfg1.bf.ADJMAX = 0x40;
      TEN_REG_WRITE(TEN_N40G_REG_ADDR(pDev, module_id, GMPODW1CFG1), tmp_n40g_ogmpr4x_gmpodw1cfg1.wrd);
      break;
      
    case 3 :
      /* Tributary 0 */
      tmp_n40g_otnt4x_gmpcfg1.wrd = TEN_REG_READ(TEN_N40G_REG_ADDR(pDev, module_id, GMPCFG1));
      tmp_n40g_otnt4x_gmpcfg1.bf.GMPMD0 = 1;
      TEN_REG_WRITE(TEN_N40G_REG_ADDR(pDev, module_id, GMPCFG1), tmp_n40g_otnt4x_gmpcfg1.wrd);

      tmp_n40g_otnt4x_cncfg01.wrd = TEN_REG_READ(TEN_N40G_REG_ADDR(pDev, module_id, otnt4x_CNCFG01));
      tmp_n40g_otnt4x_cncfg01.bf.Cn01 = Cn>>16;
      TEN_REG_WRITE(TEN_N40G_REG_ADDR(pDev, module_id, otnt4x_CNCFG01), tmp_n40g_otnt4x_cncfg01.wrd);

      tmp_n40g_otnt4x_cncfg00.wrd = TEN_REG_READ(TEN_N40G_REG_ADDR(pDev, module_id, otnt4x_CNCFG00));
      tmp_n40g_otnt4x_cncfg00.bf.Cn00 = Cn%65536;
      TEN_REG_WRITE(TEN_N40G_REG_ADDR(pDev, module_id, otnt4x_CNCFG00), tmp_n40g_otnt4x_cncfg00.wrd);

      tmp_n40g_otnt4x_cmcfg0.wrd = TEN_REG_READ(TEN_N40G_REG_ADDR(pDev, module_id, CMCFG0));
      tmp_n40g_otnt4x_cmcfg0.bf.CmInit = Cm;
      TEN_REG_WRITE(TEN_N40G_REG_ADDR(pDev, module_id, CMCFG0), tmp_n40g_otnt4x_cmcfg0.wrd);

      tmp_n40g_otnt4x_wrpcfg1.wrd = TEN_REG_READ(TEN_N40G_REG_ADDR(pDev, module_id, WRPCFG1));
      tmp_n40g_otnt4x_wrpcfg1.bf.JCHYST = 0;
      TEN_REG_WRITE(TEN_N40G_REG_ADDR(pDev, module_id, WRPCFG1), tmp_n40g_otnt4x_wrpcfg1.wrd);

      /* Provision RX side */
      tmp_n40g_ogmpr4x_gmpodwcfg0.wrd = TEN_REG_READ(TEN_N40G_REG_ADDR(pDev, module_id, GMPODWCFG0));
      tmp_n40g_ogmpr4x_gmpodwcfg0.bf.GMPMD0 = 1;
      TEN_REG_WRITE(TEN_N40G_REG_ADDR(pDev, module_id, GMPODWCFG0), tmp_n40g_ogmpr4x_gmpodwcfg0.wrd);
      
      tmp_n40g_ogmpr4x_cncfg01.wrd = TEN_REG_READ(TEN_N40G_REG_ADDR(pDev, module_id, ogmpr4x_CNCFG01));
      tmp_n40g_ogmpr4x_cncfg01.bf.Cn01 = Cn>>16;
      TEN_REG_WRITE(TEN_N40G_REG_ADDR(pDev, module_id, ogmpr4x_CNCFG01), tmp_n40g_ogmpr4x_cncfg01.wrd);

      tmp_n40g_ogmpr4x_cncfg00.wrd = TEN_REG_READ(TEN_N40G_REG_ADDR(pDev, module_id, ogmpr4x_CNCFG00));
      tmp_n40g_ogmpr4x_cncfg00.bf.Cn00 = Cn%65536;
      TEN_REG_WRITE(TEN_N40G_REG_ADDR(pDev, module_id, ogmpr4x_CNCFG00), tmp_n40g_ogmpr4x_cncfg00.wrd);
      
      tmp_n40g_ogmpr4x_gmpodw0cfg1.wrd = TEN_REG_READ(TEN_N40G_REG_ADDR(pDev, module_id, GMPODW0CFG1));
      tmp_n40g_ogmpr4x_gmpodw0cfg1.bf.ADJMAX = 0x40;
      TEN_REG_WRITE(TEN_N40G_REG_ADDR(pDev, module_id, GMPODW0CFG1), tmp_n40g_ogmpr4x_gmpodw0cfg1.wrd);
      break;
      
    default:
        CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, "Slice out of range.  s/b 0..3.");
        break;
  }
  
  TEN_MOD_UNLOCK(module_id, TEN_ID_N40G);
  return (CS_OK);
}
/* Bugzilla 26275, Bugzilla 26308 End */


/******************************************************************************/
/* CATEGORY   : API                                                           */
/* ACCESS     : Public                                                        */
/* BLOCK      : HIGH LEVEL                                                    */
/* CHIP       : Tenabo                                                        */
cs_status ten_n40g_clear_gmp_ho_client_data_entity_t41(cs_uint16 module_id,
                                                       cs_uint16 slice)
/* INPUTS     : o Module_id                                                   */
/*              o Slice                                                       */
/* OUTPUTS    : ----                                                          */
/* RETURNS    : CS_OK or CS_ERROR                                             */
/* DESCRIPTION:                                                               */
/* Clear settings from Client Data Entity for GMP.                            */
/*                                                                            */
/******************************************************************************/
{
  T41_t *pDev = NULL;
  TEN_N40G_OTNT4X_CMCFG3_t tmp_n40g_otnt4x_cmcfg3;
  TEN_N40G_OTNT4X_CNCFG31_t tmp_n40g_otnt4x_cncfg31;
  TEN_N40G_OTNT4X_GMPCFG1_t tmp_n40g_otnt4x_gmpcfg1;
  TEN_N40G_OTNT4X_CNCFG30_t tmp_n40g_otnt4x_cncfg30;

  TEN_N40G_OTNT4X_CMCFG2_t tmp_n40g_otnt4x_cmcfg2;
  TEN_N40G_OTNT4X_CNCFG21_t tmp_n40g_otnt4x_cncfg21;
  TEN_N40G_OTNT4X_CNCFG20_t tmp_n40g_otnt4x_cncfg20;

  TEN_N40G_OTNT4X_CMCFG1_t tmp_n40g_otnt4x_cmcfg1;
  TEN_N40G_OTNT4X_CNCFG11_t tmp_n40g_otnt4x_cncfg11;
  TEN_N40G_OTNT4X_CNCFG10_t tmp_n40g_otnt4x_cncfg10;

  TEN_N40G_OTNT4X_CNCFG00_t tmp_n40g_otnt4x_cncfg00;
  TEN_N40G_OTNT4X_CMCFG0_t tmp_n40g_otnt4x_cmcfg0;
  TEN_N40G_OTNT4X_CNCFG01_t tmp_n40g_otnt4x_cncfg01;
  
  TEN_N40G_OGMPR4X_GMPODWCFG0_t tmp_n40g_ogmpr4x_gmpodwcfg0;
  TEN_N40G_OGMPR4X_CNCFG00_t tmp_n40g_ogmpr4x_cncfg00;
  TEN_N40G_OGMPR4X_CNCFG01_t tmp_n40g_ogmpr4x_cncfg01;

  TEN_N40G_OGMPR4X_CNCFG10_t tmp_n40g_ogmpr4x_cncfg10;
  TEN_N40G_OGMPR4X_CNCFG11_t tmp_n40g_ogmpr4x_cncfg11;

  TEN_N40G_OGMPR4X_CNCFG20_t tmp_n40g_ogmpr4x_cncfg20;
  TEN_N40G_OGMPR4X_CNCFG21_t tmp_n40g_ogmpr4x_cncfg21;

  TEN_N40G_OGMPR4X_CNCFG30_t tmp_n40g_ogmpr4x_cncfg30;
  TEN_N40G_OGMPR4X_CNCFG31_t tmp_n40g_ogmpr4x_cncfg31;
  
  cs_char8 *func = "ten_n40g_clear_gmp_ho_client_data_entity_t41";
  
  TEN_MOD_COMMON_VALIDATE(module_id, pDev, FALSE);

  CS_PRINT("%s() %s, %s\n",
           func,
           ten_module_strings[module_id&1],
           ten_slice_strings[slice]);

  /* Bug #38850: API ten_n40g_clear_gmp_ho_client_data_entity_t41 needs fix for bus errors on T40 */
  if (!ten_dev_is_t41(TEN_MOD_ID_TO_DEV_ID(module_id))) {       
    CS_PRINT("T41 feature only, exit now for T40\n");
    return (CS_OK);
  }
           
  TEN_MOD_LOCK(module_id, TEN_ID_N40G);
  
  switch (slice) {
    case 0 :
      /* Tributary 3 */
      /* Provision TX side */
      tmp_n40g_otnt4x_gmpcfg1.wrd = TEN_REG_READ(TEN_N40G_REG_ADDR(pDev, module_id, GMPCFG1));
      tmp_n40g_otnt4x_gmpcfg1.bf.GMPMD3 = 0;
      TEN_REG_WRITE(TEN_N40G_REG_ADDR(pDev, module_id, GMPCFG1), tmp_n40g_otnt4x_gmpcfg1.wrd);

      tmp_n40g_otnt4x_cncfg31.wrd = TEN_REG_READ(TEN_N40G_REG_ADDR(pDev, module_id, otnt4x_CNCFG31));
      tmp_n40g_otnt4x_cncfg31.bf.Cn31 = 0;
      TEN_REG_WRITE(TEN_N40G_REG_ADDR(pDev, module_id, otnt4x_CNCFG31), tmp_n40g_otnt4x_cncfg31.wrd);

      tmp_n40g_otnt4x_cncfg30.wrd = TEN_REG_READ(TEN_N40G_REG_ADDR(pDev, module_id, otnt4x_CNCFG30));
      tmp_n40g_otnt4x_cncfg30.bf.Cn30 = 0;
      TEN_REG_WRITE(TEN_N40G_REG_ADDR(pDev, module_id, otnt4x_CNCFG30), tmp_n40g_otnt4x_cncfg30.wrd);

      tmp_n40g_otnt4x_cmcfg3.wrd = TEN_REG_READ(TEN_N40G_REG_ADDR(pDev, module_id, CMCFG3));
      tmp_n40g_otnt4x_cmcfg3.bf.CmInit = 0;
      TEN_REG_WRITE(TEN_N40G_REG_ADDR(pDev, module_id, CMCFG3), tmp_n40g_otnt4x_cmcfg3.wrd);

      /* Provision RX side */
      tmp_n40g_ogmpr4x_gmpodwcfg0.wrd = TEN_REG_READ(TEN_N40G_REG_ADDR(pDev, module_id, GMPODWCFG0));
      tmp_n40g_ogmpr4x_gmpodwcfg0.bf.GMPMD3 = 0;
      TEN_REG_WRITE(TEN_N40G_REG_ADDR(pDev, module_id, GMPODWCFG0), tmp_n40g_ogmpr4x_gmpodwcfg0.wrd);

      tmp_n40g_ogmpr4x_cncfg31.wrd = TEN_REG_READ(TEN_N40G_REG_ADDR(pDev, module_id, ogmpr4x_CNCFG31));
      tmp_n40g_ogmpr4x_cncfg31.bf.Cn31 = 0;
      TEN_REG_WRITE(TEN_N40G_REG_ADDR(pDev, module_id, ogmpr4x_CNCFG31), tmp_n40g_ogmpr4x_cncfg31.wrd);

      tmp_n40g_ogmpr4x_cncfg30.wrd = TEN_REG_READ(TEN_N40G_REG_ADDR(pDev, module_id, ogmpr4x_CNCFG30));
      tmp_n40g_ogmpr4x_cncfg30.bf.Cn30 = 0;
      TEN_REG_WRITE(TEN_N40G_REG_ADDR(pDev, module_id, ogmpr4x_CNCFG30), tmp_n40g_ogmpr4x_cncfg30.wrd);

      break;
      
    case 1 :
      /* Tributary 2 */
      tmp_n40g_otnt4x_gmpcfg1.wrd = TEN_REG_READ(TEN_N40G_REG_ADDR(pDev, module_id, GMPCFG1));
      tmp_n40g_otnt4x_gmpcfg1.bf.GMPMD2 = 0;
      TEN_REG_WRITE(TEN_N40G_REG_ADDR(pDev, module_id, GMPCFG1), tmp_n40g_otnt4x_gmpcfg1.wrd);

      tmp_n40g_otnt4x_cncfg21.wrd = TEN_REG_READ(TEN_N40G_REG_ADDR(pDev, module_id, otnt4x_CNCFG21));
      tmp_n40g_otnt4x_cncfg21.bf.Cn21 = 0;
      TEN_REG_WRITE(TEN_N40G_REG_ADDR(pDev, module_id, otnt4x_CNCFG21), tmp_n40g_otnt4x_cncfg21.wrd);

      tmp_n40g_otnt4x_cncfg20.wrd = TEN_REG_READ(TEN_N40G_REG_ADDR(pDev, module_id, otnt4x_CNCFG20));
      tmp_n40g_otnt4x_cncfg20.bf.Cn20 = 0;
      TEN_REG_WRITE(TEN_N40G_REG_ADDR(pDev, module_id, otnt4x_CNCFG20), tmp_n40g_otnt4x_cncfg20.wrd);

      tmp_n40g_otnt4x_cmcfg2.wrd = TEN_REG_READ(TEN_N40G_REG_ADDR(pDev, module_id, CMCFG2));
      tmp_n40g_otnt4x_cmcfg2.bf.CmInit = 0;
      TEN_REG_WRITE(TEN_N40G_REG_ADDR(pDev, module_id, CMCFG2), tmp_n40g_otnt4x_cmcfg2.wrd);

      /* Provision RX side */
      tmp_n40g_ogmpr4x_gmpodwcfg0.wrd = TEN_REG_READ(TEN_N40G_REG_ADDR(pDev, module_id, GMPODWCFG0));
      tmp_n40g_ogmpr4x_gmpodwcfg0.bf.GMPMD2 = 0;
      TEN_REG_WRITE(TEN_N40G_REG_ADDR(pDev, module_id, GMPODWCFG0), tmp_n40g_ogmpr4x_gmpodwcfg0.wrd);

      tmp_n40g_ogmpr4x_cncfg21.wrd = TEN_REG_READ(TEN_N40G_REG_ADDR(pDev, module_id, ogmpr4x_CNCFG21));
      tmp_n40g_ogmpr4x_cncfg21.bf.Cn21 = 0;
      TEN_REG_WRITE(TEN_N40G_REG_ADDR(pDev, module_id, ogmpr4x_CNCFG21), tmp_n40g_ogmpr4x_cncfg21.wrd);

      tmp_n40g_ogmpr4x_cncfg20.wrd = TEN_REG_READ(TEN_N40G_REG_ADDR(pDev, module_id, ogmpr4x_CNCFG20));
      tmp_n40g_ogmpr4x_cncfg20.bf.Cn20 = 0;
      TEN_REG_WRITE(TEN_N40G_REG_ADDR(pDev, module_id, ogmpr4x_CNCFG20), tmp_n40g_ogmpr4x_cncfg20.wrd);

      break;

    case 2 :
      /* Tributary 1 */
      tmp_n40g_otnt4x_gmpcfg1.wrd = TEN_REG_READ(TEN_N40G_REG_ADDR(pDev, module_id, GMPCFG1));
      tmp_n40g_otnt4x_gmpcfg1.bf.GMPMD1 = 0;
      TEN_REG_WRITE(TEN_N40G_REG_ADDR(pDev, module_id, GMPCFG1), tmp_n40g_otnt4x_gmpcfg1.wrd);

      tmp_n40g_otnt4x_cncfg11.wrd = TEN_REG_READ(TEN_N40G_REG_ADDR(pDev, module_id, otnt4x_CNCFG11));
      tmp_n40g_otnt4x_cncfg11.bf.Cn11 = 0;
      TEN_REG_WRITE(TEN_N40G_REG_ADDR(pDev, module_id, otnt4x_CNCFG11), tmp_n40g_otnt4x_cncfg11.wrd);

      tmp_n40g_otnt4x_cncfg10.wrd = TEN_REG_READ(TEN_N40G_REG_ADDR(pDev, module_id, otnt4x_CNCFG10));
      tmp_n40g_otnt4x_cncfg10.bf.Cn10 = 0;
      TEN_REG_WRITE(TEN_N40G_REG_ADDR(pDev, module_id, otnt4x_CNCFG10), tmp_n40g_otnt4x_cncfg10.wrd);

      tmp_n40g_otnt4x_cmcfg1.wrd = TEN_REG_READ(TEN_N40G_REG_ADDR(pDev, module_id, CMCFG1));
      tmp_n40g_otnt4x_cmcfg1.bf.CmInit = 0;
      TEN_REG_WRITE(TEN_N40G_REG_ADDR(pDev, module_id, CMCFG1), tmp_n40g_otnt4x_cmcfg1.wrd);

      /* Provision RX side */
      tmp_n40g_ogmpr4x_gmpodwcfg0.wrd = TEN_REG_READ(TEN_N40G_REG_ADDR(pDev, module_id, GMPODWCFG0));
      tmp_n40g_ogmpr4x_gmpodwcfg0.bf.GMPMD1 = 0;
      TEN_REG_WRITE(TEN_N40G_REG_ADDR(pDev, module_id, GMPODWCFG0), tmp_n40g_ogmpr4x_gmpodwcfg0.wrd);

      tmp_n40g_ogmpr4x_cncfg11.wrd = TEN_REG_READ(TEN_N40G_REG_ADDR(pDev, module_id, ogmpr4x_CNCFG11));
      tmp_n40g_ogmpr4x_cncfg11.bf.Cn11 = 0;
      TEN_REG_WRITE(TEN_N40G_REG_ADDR(pDev, module_id, ogmpr4x_CNCFG11), tmp_n40g_ogmpr4x_cncfg11.wrd);

      tmp_n40g_ogmpr4x_cncfg10.wrd = TEN_REG_READ(TEN_N40G_REG_ADDR(pDev, module_id, ogmpr4x_CNCFG10));
      tmp_n40g_ogmpr4x_cncfg10.bf.Cn10 = 0;
      TEN_REG_WRITE(TEN_N40G_REG_ADDR(pDev, module_id, ogmpr4x_CNCFG10), tmp_n40g_ogmpr4x_cncfg10.wrd);

      break;
      
    case 3 :
      /* Tributary 0 */
      tmp_n40g_otnt4x_gmpcfg1.wrd = TEN_REG_READ(TEN_N40G_REG_ADDR(pDev, module_id, GMPCFG1));
      tmp_n40g_otnt4x_gmpcfg1.bf.GMPMD0 = 0;
      TEN_REG_WRITE(TEN_N40G_REG_ADDR(pDev, module_id, GMPCFG1), tmp_n40g_otnt4x_gmpcfg1.wrd);

      tmp_n40g_otnt4x_cncfg01.wrd = TEN_REG_READ(TEN_N40G_REG_ADDR(pDev, module_id, otnt4x_CNCFG01));
      tmp_n40g_otnt4x_cncfg01.bf.Cn01 = 0;
      TEN_REG_WRITE(TEN_N40G_REG_ADDR(pDev, module_id, otnt4x_CNCFG01), tmp_n40g_otnt4x_cncfg01.wrd);

      tmp_n40g_otnt4x_cncfg00.wrd = TEN_REG_READ(TEN_N40G_REG_ADDR(pDev, module_id, otnt4x_CNCFG00));
      tmp_n40g_otnt4x_cncfg00.bf.Cn00 = 0;
      TEN_REG_WRITE(TEN_N40G_REG_ADDR(pDev, module_id, otnt4x_CNCFG00), tmp_n40g_otnt4x_cncfg00.wrd);

      tmp_n40g_otnt4x_cmcfg0.wrd = TEN_REG_READ(TEN_N40G_REG_ADDR(pDev, module_id, CMCFG0));
      tmp_n40g_otnt4x_cmcfg0.bf.CmInit = 0;
      TEN_REG_WRITE(TEN_N40G_REG_ADDR(pDev, module_id, CMCFG0), tmp_n40g_otnt4x_cmcfg0.wrd);

      /* Provision RX side */
      tmp_n40g_ogmpr4x_gmpodwcfg0.wrd = TEN_REG_READ(TEN_N40G_REG_ADDR(pDev, module_id, GMPODWCFG0));
      tmp_n40g_ogmpr4x_gmpodwcfg0.bf.GMPMD0 = 0;
      TEN_REG_WRITE(TEN_N40G_REG_ADDR(pDev, module_id, GMPODWCFG0), tmp_n40g_ogmpr4x_gmpodwcfg0.wrd);
      
      tmp_n40g_ogmpr4x_cncfg01.wrd = TEN_REG_READ(TEN_N40G_REG_ADDR(pDev, module_id, ogmpr4x_CNCFG01));
      tmp_n40g_ogmpr4x_cncfg01.bf.Cn01 = 0;
      TEN_REG_WRITE(TEN_N40G_REG_ADDR(pDev, module_id, ogmpr4x_CNCFG01), tmp_n40g_ogmpr4x_cncfg01.wrd);

      tmp_n40g_ogmpr4x_cncfg00.wrd = TEN_REG_READ(TEN_N40G_REG_ADDR(pDev, module_id, ogmpr4x_CNCFG00));
      tmp_n40g_ogmpr4x_cncfg00.bf.Cn00 = 0;
      TEN_REG_WRITE(TEN_N40G_REG_ADDR(pDev, module_id, ogmpr4x_CNCFG00), tmp_n40g_ogmpr4x_cncfg00.wrd);
      
      break;
      
    default:
        CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, "Slice out of range.  s/b 0..3.");
        break;
  }
  
  TEN_MOD_UNLOCK(module_id, TEN_ID_N40G);
  return (CS_OK);
}


/* Bugzilla 28237 Start */
/****************************************************************/
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : HIGH LEVEL                                      */
/* CHIP       : Tenabo                                          */
cs_status ten_n40g_mux_mapper_t41 (cs_uint16 module_id, 
                               cs_uint16 client_traffic_type,
                               cs_uint16 slice_line,
                               cs_uint16 mapper,
                               cs_uint16 map_proc,
                               cs_uint16 timeslots,
                               cs_uint16 gmp_timeslot_mask,
                               cs_int16  num_just)
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
/*   TEN_TRAFFIC_TYPE_10GFC_STD            = 57                 */
/*                                                              */
/* [slice_line] parameter specifies line's slice:               */
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
/*   TEN_TRAFFIC_TYPE_OTU3E3               = 23                 */
/*   TEN_TRAFFIC_TYPE_OTU3P2               = 25                 */
/*   TEN_TRAFFIC_TYPE_OTU3E2               = 34                 */
/*   TEN_TRAFFIC_TYPE_OTU3E4               = 55                 */
/*                                                              */
/* The [map_proc] parameter specifies the mapping method        */
/*  TEN_MAP_AMP,           = 0                                  */
/*  TEN_MAP_AMP_DT,        = 2                                  */
/*  TEN_MAP_AMP_PROP,      = 3                                  */
/*  TEN_MAP_AMP_PROP_DT,   = 4                                  */
/*  TEN_MAP_GMP_HO,        = 6                                  */
/*  TEN_MAP_GMP_HO_DT,     = 7                                  */
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
/* The [num_just] parameter specifies the number of             */
/* justification bytes for this slice.  If the number is        */
/* negative, it specifies the nuber of C15s bytes for this      */
/* slice.                                                       */
/*                                                              */
/****************************************************************/ 
{
  cs_uint16 dev_id;
  ten_dev_cb_t *pdevcb;
  ten_syncdsync_cb_t *psyncdsync_cb;
  T41_t *pDev = NULL;
  /*cs_uint16 tributary;*/
  cs_uint16 jc_plus = 0;
  cs_uint16 jc_enabled = 0;
  cs_status rtn = CS_OK;
  cs_char8 *func = "ten_n40g_mux_mapper_t41";  

  TEN_MOD_COMMON_VALIDATE (module_id, pDev, CS_ERROR);
  dev_id = TEN_MOD_ID_TO_DEV_ID (module_id);
  pdevcb = TEN_DEV_ID_TO_DEVCB_PTR(dev_id);
  psyncdsync_cb = &pdevcb->syncdsync_thread_cb[slice_line];

  CS_PRINT("%s()\n", func);
  CS_PRINT("    line (%s, %s, %s)\n", ten_module_strings[module_id&1], ten_slice_strings[slice_line], ten_hl_config_traffic_types_strings[mapper]);
  CS_PRINT("    client %s\n", ten_hl_config_traffic_types_strings[client_traffic_type]);
  if (map_proc <= TEN_MAP_GMP_HO_DT) {           
    CS_PRINT("    %s\n", ten_sync_type_strings[map_proc]);
  }
  else {
    CS_PRINT("    map_proc = %d\n", map_proc);
  }
  CS_PRINT("    timeslots = %x\n", timeslots);
  CS_PRINT("    gmp_timeslot_mask = %x\n", gmp_timeslot_mask);
  CS_PRINT("    num_just = %d\n", num_just);

  if (!pdevcb) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, "pDev is null.");
    return (CS_ERROR);
  }
  
  CS_PRINT("    num_pjo_oxu3=%d, num_just_oxu3=%d, hysteresis=%d\n",  
              psyncdsync_cb->num_pjo_oxu3,
              psyncdsync_cb->num_just_oxu3,
              psyncdsync_cb->hysteresis);

 
  /*tributary = 3 - slice_line;*/  /* Map from slice to tributary */

  /* Shut off syncdsync to mapper association from N10G and enable justification in N40G */
  if ((map_proc == TEN_MAP_AMP_DT) || (map_proc == TEN_MAP_AMP_PROP_DT) ||
      (map_proc == TEN_MAP_GMP_HO_DT)) {
    jc_enabled = 1;     /* Bugzilla 41198 */
  }
  ten_n40g_otnt4x_set_wrpcfg4_jcen_per_slice (module_id, slice_line, jc_enabled); /* Provision Deterministic Justification */

  /* JC_Plus in the TX direction is handled by the N10G block for Muxponder, so it is disabled in the N40G block */
  ten_n40g_otnt4x_set_jc_plus(module_id, 0);

  /* Provision JC for RX */
  if ((map_proc == TEN_MAP_AMP) || (map_proc == TEN_MAP_AMP_DT) ||
      (map_proc == TEN_MAP_AMP_PROP) || (map_proc == TEN_MAP_AMP_PROP_DT) ||
      (map_proc == TEN_MAP_GMP_HO) || (map_proc == TEN_MAP_GMP_HO_DT)) {    /* Bugzilla 26275, 28237 29100 */
    jc_enabled = 1;
  } else {
    jc_enabled = 0;
  }   
  ten_n40g_otnr4x_set_jc_enable_per_slice (module_id, slice_line, jc_enabled);
  
  /* Provision JC Plus for RX */
  if ((map_proc == TEN_MAP_AMP_PROP)       /* Bugzilla 41198 */
  ) {
    jc_plus = 1;
  } else {
    jc_plus = 0;
  }   
  ten_n40g_otnr4x_set_jc_plus_per_slice (module_id, slice_line, jc_plus);


  /* Provision Fixed Stuff and C15 */
  if ((map_proc == TEN_MAP_AMP) || (map_proc == TEN_MAP_AMP_DT) ||
      (map_proc == TEN_MAP_AMP_PROP)  || (map_proc == TEN_MAP_AMP_PROP_DT)) {
   #if 0
    if (psyncdsync_cb->num_just_oxu3 < 0) {
      /* Provision C15s */
      ten_hl_n40g_cfg_async_odtu23 (module_id, slice_line, CS_TX_AND_RX, 0, -psyncdsync_cb->num_just_oxu3);
    } else {
      ten_hl_n40g_cfg_async_odtu23 (module_id, slice_line, CS_TX_AND_RX, psyncdsync_cb->num_just_oxu3, 0);
    }
   #endif   
    /* Bugzilla 29100 Start */
    if (num_just < 0) {
      /* Provision C15s */
      ten_hl_n40g_cfg_async_odtu23 (module_id, slice_line, CS_TX_AND_RX, 0, -num_just);
    } 
    else {
      ten_hl_n40g_cfg_async_odtu23 (module_id, slice_line, CS_TX_AND_RX, num_just, 0);
    }  
    /* Bugzilla 29100 End */
  }

  /* Provision GMP */
  if ((map_proc == TEN_MAP_GMP_LO) || (map_proc == TEN_MAP_GMP_HO) || (map_proc == TEN_MAP_GMP_HO_DT)) { /* Bugzilla 32380 GMP_HO_DT */
    /* No Justifications */
    ten_n40g_tx_gmp_ho_client_data_entity_t41 (module_id, slice_line, pdevcb->syncdsync_thread_cb[slice_line].cn_bytes_n40g, timeslots); /* Bugzilla 26275, Bugzilla 26308 */
  } 
  else {
    /* Bugzilla #32280, #32068 and #32028 allow dynamic reprovisioning between GMP and AMP */
    ten_n40g_clear_gmp_ho_client_data_entity_t41(module_id, slice_line);
    ten_n40g_tx_25g_ts_t41(module_id);
    ten_n40g_rx_25g_ts_t41(module_id);
  }

  /* Provision Aggregation Timeslot Mode */
  if ((map_proc == TEN_MAP_GMP_HO) || (map_proc == TEN_MAP_GMP_HO_DT) || (timeslots == 8)) {
    /* 1.25G Timeslots */
    ten_n40g_tx_125g_ts_t41 (module_id);  /* TSMODE = 1 */
    ten_n40g_rx_125g_ts_t41 (module_id);  /* TSMODE = 1 */
  }

  /* Provison Timeslots Enable */
  if ((map_proc == TEN_MAP_GMP_HO) || (map_proc == TEN_MAP_GMP_HO_DT)) { /* Bugzilla 32380 GMP_HO_DT */
    ten_n40g_gmp_ho_tsen_t41 (module_id, slice_line, gmp_timeslot_mask);
  } 


  /* Provision Deterministic Hysteresis */
  if ((map_proc == TEN_MAP_AMP_DT) || (map_proc == TEN_MAP_AMP_PROP_DT) ||  
      (map_proc == TEN_MAP_GMP_HO_DT)) {
    if (pdevcb) {
      /* Hysteresis value for DT Just */
      ten_n40g_otnt4x_set_dthyst (module_id, slice_line, psyncdsync_cb->hysteresis);
    }
  }
  else {
    /* Bugzilla #32068, allow dynamic reconfigs between GMP/AMP/GMP_DT/AMP_DT modes */
    ten_n40g_otnt4x_set_dthyst (module_id, slice_line, 0);
  }

  if (rtn != CS_OK) {
    CS_PRINT("%s()  FAILED!\n", func);
  }
  return (rtn);
}
/* Bugzilla 28237 End */

/* Bugzilla 24360 Start */
/****************************************************************/
/* $rtn_hdr_start  N40G MUXPONDER CONFIG                        */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : HIGH LEVEL                                      */
/* CHIP       : Tenabo                                          */
cs_status ten_hl_n40g_config_mux_t41(cs_uint16 module_id, 
                                     cs_uint16 client,
                                     cs_uint16 mapper,
                                     cs_uint16 fec_line,
                                     cs_uint16 slice_line,
                                     cs_uint16 dyn_repro,
                                     cs_uint16 map_proc,
                                     cs_uint16 timeslots,
                                     cs_uint16 gmp_timeslot_mask,
                                     cs_uint16 term_type,
                                     cs_uint16 tcm_bits,
                                     cs_uint16 mld_enabled)
/* INPUTS     : o Module Id                                     */
/*              o Client Type                                   */
/*              o Mapper Type                                   */
/*              o FEC Type                                      */
/*              o Line Slice                                    */
/*              o Dynamic Reprovision Type                      */
/*              o Mapping Procedure                             */
/*              o Timeslots                                     */
/*              o GMP Timeslot Mask                             */
/*              o Termination Type                              */
/*              o TCM bits                                      */
/*              o MLD Line                                      */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* Configures an N40G muxponder transmit/receive path.          */
/*                                                              */
/* [module_id] parameter specifies line's module ID             */
/* 16 devices can be registered and module bit indicates line   */
/* or client side of the registered device. The registered      */ 
/* device is identified by the dev_id bits specified below      */
/*   Bits 11:8 – dev_id, Bits 7:1 – don’t care, Bit 0 – module  */ 
/*                                                              */
/* [client] parameter specifies the traffic type of the client: */
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
/*   TEN_TRAFFIC_TYPE_8GFC_RA              = 47                 */
/*   TEN_TRAFFIC_TYPE_4GFC_RA              = 48                 */
/*   TEN_TRAFFIC_TYPE_2GFC_RA              = 49                 */
/*   TEN_TRAFFIC_TYPE_1GFC_RA              = 50                 */
/*   TEN_TRAFFIC_TYPE_10GFC_STD            = 57                 */
/*   TEN_TRAFFIC_TYPE_CBR_10G              = 67                 */
/*                                                              */
/* [mapper] parameter specifies the traffic type of the line:   */
/*   TEN_TRAFFIC_TYPE_NONE                 = 0                  */
/*   TEN_TRAFFIC_TYPE_OTU3                 = 1                  */
/*   TEN_TRAFFIC_TYPE_OTU3E                = 2                  */
/*   TEN_TRAFFIC_TYPE_OTU3P                = 3                  */
/*   TEN_TRAFFIC_TYPE_OTU3E3               = 23                 */
/*   TEN_TRAFFIC_TYPE_OTU3P2               = 25                 */
/*   TEN_TRAFFIC_TYPE_OTU3E2               = 34                 */
/*   TEN_TRAFFIC_TYPE_OTU3E4               = 55                 */
/*                                                              */
/* The [map_proc] parameter specifies the mapping method        */
/*  TEN_MAP_AMP,           = 0                                  */
/*  TEN_MAP_AMP_DT,        = 2                                  */
/*  TEN_MAP_AMP_PROP,      = 3                                  */
/*  TEN_MAP_AMP_PROP_DT,   = 4                                  */
/*  TEN_MAP_GMP_HO,        = 6                                  */
/*  TEN_MAP_GMP_HO_DT,     = 7                                  */
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
/* The [mld_enbl] parameter enables distributing data across    */
/* multiple lanes on line side i.e. OTL3.4                      */
/*   disable = 0                                                */
/*   enable  = 1                                                */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  ten_dev_cb_t *pdevcb;
  T41_t *pDev = NULL;
  ten_syncdsync_cb_t *psyncdsync_cb;  /* Bugzilla 29100 */
  cs_uint16 dev_id;
  cs_uint16 module;
  cs_uint16 tributary;
  cs_status rtn = CS_OK;
  cs_char8 *func = "ten_hl_n40g_config_mux_t41";  
#if 0
  cs_uint16 dthyst;
  cs_uint16 cn;
  TEN_N40G_OTNT4X_WRPC15EN0_t tmp_n40g_otnt4x_wrpc15en0;
  TEN_N40G_OTNT4X_WRPC15EN1_t tmp_n40g_otnt4x_wrpc15en1;
  TEN_N40G_GBL4X_SYNCCFG_t tmp_n40g_gbl4x_synccfg;
  TEN_N40G_GBL4X_SYNCPER_t tmp_n40g_gbl4x_syncper;
  TEN_N40G_OTNR4X_ODWC15EN0_t tmp_n40g_otnr4x_odwc15en0;
  TEN_N40G_OTNR4X_ODWC15EN1_t tmp_n40g_otnr4x_odwc15en1;
  TEN_N40G_OTNT4X_WRP0DH0_t tmp_n40g_otnt4x_wrp0dh0;
  TEN_N40G_OTNT4X_WRP1DH0_t tmp_n40g_otnt4x_wrp1dh0;
  TEN_N40G_OTNT4X_WRP2DH0_t tmp_n40g_otnt4x_wrp2dh0;
  TEN_N40G_OTNT4X_WRP3DH0_t tmp_n40g_otnt4x_wrp3dh0;
#endif

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);

  dev_id = TEN_MOD_ID_TO_DEV_ID (module_id);
  module = TEN_MOD_ID_TO_MOD_NUM (module_id);
  pdevcb = TEN_DEV_ID_TO_DEVCB_PTR(dev_id);
  psyncdsync_cb = &pdevcb->syncdsync_thread_cb[slice_line];  /* Bugzilla 29100 */

  if ((client != TEN_TRAFFIC_TYPE_OTU2) && (client != TEN_TRAFFIC_TYPE_OTU2E) &&
      (client != TEN_TRAFFIC_TYPE_OTU1F) && (client != TEN_TRAFFIC_TYPE_OC192) &&
      (client != TEN_TRAFFIC_TYPE_10GE_6_2) && (client != TEN_TRAFFIC_TYPE_10GE_7_1) &&
      (client != TEN_TRAFFIC_TYPE_10GFC) && (client != TEN_TRAFFIC_TYPE_8GFC) &&
      (client != TEN_TRAFFIC_TYPE_8GFC_ENH) && (client != TEN_TRAFFIC_TYPE_4GFC_ENH) &&
      (client != TEN_TRAFFIC_TYPE_2GFC_ENH) && (client != TEN_TRAFFIC_TYPE_1GFC_ENH) &&
      (client != TEN_TRAFFIC_TYPE_10GFC_TC) &&  (client != TEN_TRAFFIC_TYPE_OTU1E) &&
      (client != TEN_TRAFFIC_TYPE_10GE) && (client != TEN_TRAFFIC_TYPE_10GE_6_1) &&
      (client != TEN_TRAFFIC_TYPE_10GE_7_2) && (client != TEN_TRAFFIC_TYPE_10GE_RA) &&
      (client != TEN_TRAFFIC_TYPE_10GE_TC) && (client != TEN_TRAFFIC_TYPE_OTU2F) &&
      (client != TEN_TRAFFIC_TYPE_10GE_GFPF_OC192_ODU2) && (client != TEN_TRAFFIC_TYPE_10GE_RA) &&
      (client != TEN_TRAFFIC_TYPE_OTU2P) && (client != TEN_TRAFFIC_TYPE_10GE_7_3) &&
      (client != TEN_TRAFFIC_TYPE_8GFC_RA) && (client != TEN_TRAFFIC_TYPE_4GFC_RA) &&
      (client != TEN_TRAFFIC_TYPE_2GFC_RA) && (client != TEN_TRAFFIC_TYPE_1GFC_RA) &&
      (client != TEN_TRAFFIC_TYPE_10GFC_TC_G709) && /* Bug 31054 */
      (client != TEN_TRAFFIC_TYPE_10G_IB) && /* Bugzilla 38565 */
      (client != TEN_TRAFFIC_TYPE_4GFC) && (client != TEN_TRAFFIC_TYPE_2GFC) && /* Bugzilla 38779 */
      (client != TEN_TRAFFIC_TYPE_2GISC) && /* Bugzilla 38779 */
      (client != TEN_TRAFFIC_TYPE_1GFC) && (client != TEN_TRAFFIC_TYPE_1GE) &&  /* Bugzilla 38871 */
      (client != TEN_TRAFFIC_TYPE_FDR10_IB) && /* Bugzilla 39242 */
      (client != TEN_TRAFFIC_TYPE_CPRI_4) &&  /* Bugzilla 39690 */
      (client != TEN_TRAFFIC_TYPE_CBR_10G)) { /* Bugzilla 43573 */
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, "%s() client %d out of range.  s/b 5, 6, 7, 8, 10, 11, 12, 13, 14, 20, 26, 27, 29, 30, 33, 34, 36, 46, 47, 48, 49, 50, 63, 64.", func, client);
    return (CS_ERROR);
  }

  if ((mapper != TEN_TRAFFIC_TYPE_OTU3) && (mapper != TEN_TRAFFIC_TYPE_OTU3E) &&
      (mapper != TEN_TRAFFIC_TYPE_OTU3E2) && (mapper != TEN_TRAFFIC_TYPE_OTU3E4) && /* Bugzilla 28237 */
      (mapper != TEN_TRAFFIC_TYPE_OTU3P) && (mapper != TEN_TRAFFIC_TYPE_OTU3P2) && 
      (mapper != TEN_TRAFFIC_TYPE_OTU3E3) ) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, "%s() mapper %d out of range.  s/b 1, 2, 3, 23, 25, 37.", func, mapper);
    return (CS_ERROR);
  }

  if (slice_line >= TEN_MAX_SLICES) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, "%s() slice_line %d out of range.  s/b 0..3.", func, slice_line);
    return (CS_ERROR);
  }

  if (dyn_repro > TEN_REPRO_LINE_AND_CLIENT) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, "%s() dyn_repro %d out of range.  s/b 0..2.", func, dyn_repro);
    return (CS_ERROR);
  }

  if ((map_proc != TEN_MAP_AMP) && (map_proc != TEN_MAP_AMP_DT) && (map_proc != TEN_MAP_AMP_PROP) &&
      (map_proc != TEN_MAP_AMP_PROP_DT) && (map_proc != TEN_MAP_GMP_HO) && (map_proc != TEN_MAP_GMP_HO_DT)) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, "%s() map_proc %d out of range.  s/b 0, 2, 3, 4, 6, 7", func, map_proc);
    return (CS_ERROR);
  }

  if ((map_proc == TEN_MAP_GMP_HO) || (map_proc == TEN_MAP_GMP_HO_DT)) {
    if ((timeslots > 8) || (timeslots < 1)) {
      CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, "%s() timeslots %d out of range.  s/b 1..8.", func, timeslots);
      return (CS_ERROR);
    }
  }
  else if ((map_proc == TEN_MAP_AMP) || (map_proc == TEN_MAP_AMP_PROP) || (map_proc == TEN_MAP_AMP_DT)) {   /* Bugzilla 28237 */
    if ((timeslots != 4) && (timeslots != 8)) {
      CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, "%s() timeslots %d out of range.  s/b 4 or 8.", func, timeslots);
      return (CS_ERROR);
    }
  } else {
    /*if (timeslots != 4){                                                                                                          */
    /*  CS_HNDL_ERROR(module_id_line, ETEN_MOD_INVALID_USER_ARG, "%s() timeslots %d out of range.  s/b 16 or 32.", func, timeslots);*/
    /*  return (CS_ERROR);                                                                                                          */
    /*}                                                                                                                             */
    /* All other mapping procedures have 2.5G time slots */
    timeslots = 4;
  }  

  if (term_type > TEN_OC192_TERM_MS_LAYER_REGENERATOR) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, "%s() term_type %d out of range.  s/b 0..4.", func, term_type);
    return (CS_ERROR);
  }

  if (tcm_bits & ~0x7E) {
    CS_HNDL_ERROR (module_id, ETEN_MOD_INVALID_USER_ARG, "%s() tcm_bits 0x%X out of range.  s/b 0, 0x2..0x7E.", func, tcm_bits);
    return(CS_ERROR);
  }

  if (mld_enabled > 1) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, "%s() mld_enabled %d out of range.  s/b 0..1.", func, mld_enabled);
    return (CS_ERROR);
  }

  CS_PRINT("%s()\n", func);
           
  CS_PRINT("     line (%s, %s, %s)\n", ten_module_strings[module], ten_hl_config_traffic_types_strings[mapper], ten_fec_ovhd_strings[fec_line]);
  CS_PRINT("     line %s\n", ten_slice_strings[slice_line]);
  CS_PRINT("     client %s, \n", ten_hl_config_traffic_types_strings[client]);
  CS_PRINT("     %s\n", ten_hl_config_dyn_repro_strings[dyn_repro]);
  if (map_proc <= TEN_MAP_GMP_HO_DT) {           
    CS_PRINT("     map_proc=%s\n", ten_sync_type_strings[map_proc]);
  }
  else {
    CS_PRINT("     map_proc=%d\n", map_proc);
  }
  CS_PRINT("     timeslots=0x%X\n", timeslots);
  CS_PRINT("     gmp_timeslot_mask=0x%X\n", gmp_timeslot_mask);
  CS_PRINT("     %s\n", ten_hl_config_otu_overhead_term_strings[term_type]);
  CS_PRINT("     tcm_bits=0x%x\n",  tcm_bits);
  CS_PRINT("     mld_enabled=%d\n", mld_enabled);

  tributary = 3 - slice_line;  /* Map from slice to tributary */

  if ((dyn_repro == TEN_INITIAL_CONFIG) || (dyn_repro == TEN_REPRO_LINE_AND_CLIENT)) {
    /* Provision Line N40G */

    /* Start clocking and take out of reset the N40G RX block */
    rtn |= ten_mpif_global_clock_disable_n40g (dev_id, module, CS_RX, CS_ENABLE);
    rtn |= ten_mpif_global_reset_n40g (dev_id, module, CS_RX, CS_RESET_DEASSERT);
  
    /* Start clocking and take out of reset the N40G TX block */
    rtn |= ten_mpif_global_clock_disable_n40g (dev_id, module, CS_TX, CS_ENABLE);
    rtn |= ten_mpif_global_reset_n40g (dev_id, module, CS_TX, CS_RESET_DEASSERT);

    /*if (ten_dev_is_t41(TEN_MOD_ID_TO_DEV_ID(dpid)))*/
    if (mld_enabled) {
      CS_PRINT("MLD is enabled\n");
      /* Bugzilla #33380, MLDR_LMCFG and FTOLD Settings Should be changed for OTL3.4 */
      ten_n40g_mldrx_mldr_set_lmforlen_t41(module_id, 0xF);
      /* Use Multi-Lane Descew */
      ten_hl_n40g_otl3_4_mld_t41 (module_id, mapper, fec_line);     /* Bugzilla 29419 */
    }

    ten_n40g_tx_otu3_t41(module_id);  /* WRMD=3, STM256MD=0, STM64MD=0, AGGRMOD=0, OBY=0, ncols=254, npar=16, KPGBY=1, BIPMSK = */
    ten_n40g_tx_aggr_t41(module_id);  /* AGGRMOD=1, SBY=1, DSBLDSKW=1 */

    /* Bugzilla 26734 Start */
    ten_n40g_otnt4x_set_wrapper_onoff (module_id, 1); /* Turn wrapper on */
    /* Enable BIP */
    ten_n40g_otnt4x_bipmsk (module_id, 0x81|tcm_bits);  /* Enable Path, Section Monitoring and TCM BIP-8 insertion  */
    /* Bugzilla 26734 End */

    ten_n40g_rx_otu3_t41(module_id);  /* OBY=0, ncols=254, npar=16, ALEN=1, BYSEL=0, BYSEL1=0, FSOMD=1, AGGRMOD=0, BYPCFG=1, BIPMSK=0xff */
    ten_n40g_rx_aggr_t41(module_id);  /* AGGRMOD=1, SBY=1 */
    ten_n40g_rx_opu3_t41(module_id);  /* OPU3 layer dewrapper is enabled   DW_ENABLE=1, BYSEL=1, BYSEL1=0, KPASEL=1 */

    /* Disable the N40G deskew function (which aligns four incoming streams by frame pulse)*/
    /* since all four channels may not be provisioned */
    rtn |= ten_n40g_set_dsbldskw (module_id, 1);  /* DSBLDSKW = 1 */

    rtn |= ten_hl_n40g_config_lom_from_traffic (module_id, mapper, fec_line);
    
    /* Bugzilla #31390, set obfa2 lom */
    rtn |= ten_hl_n40g_config_lom_obfa2_from_traffic(module_id, mapper, fec_line);
    rtn |= ten_hl_n40g_config_lof_from_traffic(module_id, mapper, fec_line);
    rtn |= ten_hl_n40g_config_lof_obfa2_from_traffic(module_id, mapper, fec_line);
    
    rtn |= ten_hl_n40g_otn_aligner_settings (module_id);
    rtn |= ten_n40g_sdfr_lofcfg2_m0byte(module_id, 1);
  }  
  
  /* Bugzilla #32068, allow dynamic reprovisioning between GMP/AMP, PTI=0x21 for GMP, 0x20 for AMP */
  /* Set an appropriate value for PTI 10G PTI was set when the N10G clients were initialized */
  rtn |= ten_hl_n40g_config_pti_t41 (module_id, TEN_TRAFFIC_TYPE_ODTU, map_proc, timeslots, TEN_KPG_DISABLED);
  
  /* Provision all the mapping related registers */
  /*rtn |= ten_n40g_mux_mapper_t41 (module_id, client, slice_line, mapper, map_proc, timeslots, gmp_timeslot_mask);*/
  rtn |= ten_n40g_mux_mapper_t41 (module_id, client, slice_line, mapper, map_proc, timeslots, gmp_timeslot_mask, psyncdsync_cb->num_just_oxu3); /* Bugzilla 29100 */

  if (rtn != CS_OK) {
    CS_PRINT("%s()  FAILED!\n", func);
  }
  return (rtn);
}
/* Bugzilla 24360 End */

/* Bugzilla 28006 Start */
/****************************************************************/
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : HIGH LEVEL                                      */
/* CHIP       : Tenabo                                          */
cs_status ten_n40g_trans_mapper_t41 (cs_uint16 module_id, 
                                     cs_uint16 client_traffic_type,
                                     cs_uint16 mapper,
                                     cs_uint16 map_proc,
                                     cs_uint16 timeslots,
                                     cs_uint16 gmp_timeslot_mask)
/* DESCRIPTION:                                                 */
/* Configures the N40G for the given transponder mapper.        */
/* INPUTS     : o Module Id                                     */
/*              o Client Type                                   */
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
/* of the client: */
/*   TEN_TRAFFIC_TYPE_NONE                 = 0                  */
/*   TEN_TRAFFIC_TYPE_OTU3                 = 1                  */
/*   TEN_TRAFFIC_TYPE_OTU3E                = 2                  */
/*   TEN_TRAFFIC_TYPE_OTU3P                = 3                  */
/*   TEN_TRAFFIC_TYPE_OC768                = 22                 */
/*   TEN_TRAFFIC_TYPE_OTU3E3               = 23                 */
/*   TEN_TRAFFIC_TYPE_CBR40G_50188149150   = 24                 */
/*   TEN_TRAFFIC_TYPE_OTU3E2               = 34                 */
/*   TEN_TRAFFIC_TYPE_OTU3E4               = 55                 */
/*                                                              */
/* [mapper] parameter specifies the traffic type of the line:   */
/*   TEN_TRAFFIC_TYPE_NONE                 = 0                  */
/*   TEN_TRAFFIC_TYPE_OTU3                 = 1                  */
/*   TEN_TRAFFIC_TYPE_OTU3E                = 2                  */
/*   TEN_TRAFFIC_TYPE_OTU3P                = 3                  */
/*   TEN_TRAFFIC_TYPE_40GELAN              = 21                 */
/*   TEN_TRAFFIC_TYPE_OC768                = 22                 */
/*   TEN_TRAFFIC_TYPE_OTU3E3               = 23                 */
/*   TEN_TRAFFIC_TYPE_CBR40G_50188149150   = 24                 */
/*   TEN_TRAFFIC_TYPE_OTU3P2               = 25                 */
/*   TEN_TRAFFIC_TYPE_OTU3E2               = 34                 */
/*   TEN_TRAFFIC_TYPE_OTU3E4               = 55                 */
/*                                                              */
/* The [map_proc] parameter specifies the mapping method        */
/*  TEN_MAP_AMP,           = 0                                  */
/*  TEN_MAP_BMP,           = 1                                  */
/*  TEN_MAP_AMP_PROP,      = 3                                  */
/*  TEN_MAP_GMP_LO,        = 5                                  */
/*  TEN_MAP_GMP_HO,        = 6                                  */
/*                                                              */
/* The [timeslots] parameter specifies number of timeslots.     */
/* Bandwidth is always 1.25G per timeslot for GMP_HO. Whereas   */
/* for AMP it is as follows:                                    */
/* 16 timeslots  - 2.5G per timeslot                            */
/* 32 timeslots  - 1.25G per timeslot                           */
/*   timeslots = 1 – 8      for [map_proc] - GMP_HO             */
/*   timeslots = 16/32      for [map_proc] – Any AMP            */
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
  T41_t *pDev = NULL;
  /*cs_uint16 i;*/
  /*  TEN_N40G_OTNT4X_GMPCFG1_t tmp_n40g_otnt4x_gmpcfg1; */
  TEN_N40G_OTNT4X_WRPCFG3_t tmp_otnt4x_wrpcfg3;
  TEN_N40G_OTNR4X_ODWCFG_t tmp_n40g_otnr4x_odwcfg;
  cs_uint16 jc_plus = 0;
  /* Bugzilla 26275 Start */
  cs_uint16 jc_enabled_rx = 0;
  cs_uint16 jc_enabled_tx = 0;
  cs_char8 *func = "ten_n40g_trans_mapper_t41";  
#if 0
  cs_uint32 Cn;
  TEN_N40G_OTNT4X_CMCFG0_t tmp_n40g_otnt4x_cmcfg0;
  TEN_N40G_OTNT4X_CNCFG00_t tmp_n40g_otnt4x_cncfg00;
  TEN_N40G_OTNT4X_CNCFG01_t tmp_n40g_otnt4x_cncfg01;
  cs_uint16 gmpmd = 0;
  cs_uint16 payload_type = TEN_PAYLOAD_TYPE_SYNC_CBR;
#endif

  TEN_MOD_COMMON_VALIDATE (module_id, pDev, CS_ERROR);
  dev_id = TEN_MOD_ID_TO_DEV_ID (module_id);
  pdevcb = TEN_DEV_ID_TO_DEVCB_PTR(dev_id);
  psyncdsync_cb = &pdevcb->syncdsync_thread_cb[0];

  CS_PRINT("%s() %s, %s, %s",
           func,
           ten_module_strings[module_id&1],
           ten_hl_config_traffic_types_strings[client_traffic_type],
           ten_hl_config_traffic_types_strings[mapper]);
  if (map_proc <= TEN_MAP_GMP_HO_DT) {           
    CS_PRINT(", %s", ten_sync_type_strings[map_proc]);
  }
  else {
    CS_PRINT(", map_proc = %d", map_proc);
  }
  CS_PRINT(", timeslots = 0x%X, gmp_timeslot_mask = 0x%X\n",
           timeslots,
           gmp_timeslot_mask);

  CS_PRINT("%s()  num_pjo_oxu3=%d, num_just_oxu3=%d\n",  
              func,
              psyncdsync_cb->num_pjo_oxu3,
              psyncdsync_cb->num_just_oxu3);   /* Bugzilla 28006 */


 
  /* Determine PJO justification for JC provisioning */
  if ((map_proc == TEN_MAP_AMP) || (map_proc == TEN_MAP_AMP_PROP) || 
      (map_proc == TEN_MAP_AMP_DT) || (map_proc == TEN_MAP_AMP_PROP_DT)) {
    if (psyncdsync_cb->num_pjo_oxu3 < 3) {
      jc_plus = 0;
      jc_enabled_rx = 1;
      jc_enabled_tx = 1;
    }
    else {
      jc_enabled_rx = 1;
      jc_enabled_tx = 1;
      jc_plus = 1;
    }
  }
  else if (map_proc == TEN_MAP_GMP_HO) {
    /* Turn on async justification */
    jc_plus = 0;
    jc_enabled_rx = 1;
    jc_enabled_tx = 1;    /* Bugzilla 29481 */
  } else {
    /* PJO Justification will not be used but justification will */
    jc_plus = 0;
    jc_enabled_rx = 1;
    jc_enabled_tx = 1;
  }
  ten_n40g_otnt4x_set_wrpcfg4 (module_id, jc_plus, jc_enabled_tx);  /* Enable wrapper to generate justification and enhanced justification  */
  ten_n40g_otnr4x_set_jc_enable (module_id, jc_enabled_rx);   /* Enable justification commands to be evaluated in de-wrapping. JC_ENABLE*/
  ten_n40g_otnr4x_set_jc_plus (module_id, jc_plus);     /* Provision enhanced justification. JC_PLUS */
  /* Bugzilla 26275 End */
 
  /* Provision Aggregation Timeslot Mode */
  if (timeslots == 32) {
    ten_n40g_tx_125g_ts_t41 (module_id);  /* TSMODE = 1 */
    ten_n40g_rx_125g_ts_t41 (module_id);  /* TSMODE = 1 */
  }
 
  /* Bugzilla 27397 Start */
  if ((map_proc == TEN_MAP_AMP) || (map_proc == TEN_MAP_BMP)) {
    if (((client_traffic_type == TEN_TRAFFIC_TYPE_OC768) && (mapper == TEN_TRAFFIC_TYPE_OTU3)) || 
        ((client_traffic_type == TEN_TRAFFIC_TYPE_OTU3) && (mapper == TEN_TRAFFIC_TYPE_OTU3))) {
      /* Use Standard fixed stuff */
      TEN_MOD_LOCK(module_id, TEN_ID_N40G);
      tmp_otnt4x_wrpcfg3.wrd = TEN_REG_READ(TEN_N40G_REG_ADDR(pDev, module_id, WRPCFG3));
      tmp_otnt4x_wrpcfg3.bf.STM256MD = 1; /* Enable STM256MD fixed stuff */
      TEN_REG_WRITE(TEN_N40G_REG_ADDR(pDev, module_id, WRPCFG3), tmp_otnt4x_wrpcfg3.wrd);

      tmp_n40g_otnr4x_odwcfg.wrd = TEN_REG_READ(TEN_N40G_REG_ADDR(pDev, module_id, ODWCFG));
      tmp_n40g_otnr4x_odwcfg.bf.STM256MD = 1; /* Enable STM256MD fixed stuff */
      TEN_REG_WRITE(TEN_N40G_REG_ADDR(pDev, module_id, ODWCFG), tmp_n40g_otnr4x_odwcfg.wrd);
      TEN_MOD_UNLOCK(module_id, TEN_ID_N40G);
    }
    /* Bugzilla 31435 Start */
    else if (map_proc == TEN_MAP_BMP) {
      /* Use Cortina Fixed Stuff */
      if (psyncdsync_cb->num_just_oxu3 < 0) {
        /* Provision C15s */
        ten_n40g_otnt4x_set_c15res_en0 (module_id, -psyncdsync_cb->num_just_oxu3);  /* C15RES_EN0 (40G Transponder) */
        ten_n40g_otnr4x_set_c15res_en0 (module_id, -psyncdsync_cb->num_just_oxu3);  /* C15RES_EN0 (40G Transponder) */
      } else {
        /* Configure fixed stuff bytes on TX for Cortina enhances mapping (Time slot 0 used for Monolithic) */
        ten_n40g_otnt4x_set_wrpfs0 (module_id, psyncdsync_cb->num_just_oxu3);    /* FS0 */ 
        /* Configure fixed stuff bytes on RX for Cortina enhances mapping  (Time slot 0 used for Monolithic) */
        ten_n40g_otnr4x_set_odwfs (module_id, psyncdsync_cb->num_just_oxu3, 0);   /* FS0...FS15 */
      }
    }
    /* Bugzilla 31435 End */
  }
  else if ((map_proc == TEN_MAP_AMP_PROP) || (map_proc == TEN_MAP_AMP_PROP_DT)) { 
    /* Use Standard or Cortina fixed stuff */
    if (psyncdsync_cb->num_just_oxu3 < 0) {
      /* Provision C15s */
      ten_n40g_otnt4x_set_c15res_en0 (module_id, -psyncdsync_cb->num_just_oxu3);  /* C15RES_EN0 (40G Transponder) */
      ten_n40g_otnr4x_set_c15res_en0 (module_id, -psyncdsync_cb->num_just_oxu3);  /* C15RES_EN0 (40G Transponder) */
    } else {
      /* Configure fixed stuff bytes on TX for Cortina enhances mapping (Time slot 0 used for Monolithic) */
      ten_n40g_otnt4x_set_wrpfs0 (module_id, psyncdsync_cb->num_just_oxu3);    /* FS0 */ 
      /* Configure fixed stuff bytes on RX for Cortina enhances mapping  (Time slot 0 used for Monolithic) */
      ten_n40g_otnr4x_set_odwfs (module_id, psyncdsync_cb->num_just_oxu3, 0);   /* FS0...FS15 */
    }
  }
  else {
    /* Must be GMP, so do not use Standard or Cortian fixed stuff */
    ten_n40g_otnt4x_set_wrpfs0 (module_id, 0);    /* FS0 */ 
    ten_n40g_otnr4x_set_odwfs (module_id, 0, 0);   /* FS0...FS15 */

    /* Provison Timeslots Enable */
    if (map_proc == TEN_MAP_GMP_HO) {
      /*ten_n40g_rx_gmp_ho_tsen_t41 (module_id, gmp_timeslot_mask, gmp_timeslot_mask);*/   /* odwtsenable0, odwtsenable1 ?????????*/
      /*ten_n40g_gmp_ho_tsen_t41 (module_id, slice_line, gmp_timeslot_mask);*/
      ten_n40g_rx_gmp_ho_tsen_t41 (module_id, 0xFFFF, 0xFFFF);   /* odwtsenable0, odwtsenable1 */
      /* What about TX? */
    } 
 
    /* No Justifications */
    /*CS_PRINT("%s() cn_bytes_n40g=%d\n", func, pdevcb->syncdsync_thread_cb[0].cn_bytes_n40g); */ /*Bugzilla 26308*/
    ten_n40g_tx_gmp_ho_client_data_entity_t41 (module_id, 3, psyncdsync_cb->cn_bytes_n40g, timeslots);  /* Bugzilla 26275, Bugzilla 26308*/
  }
  /* Bugzilla 27397 End */
 
  return (CS_OK);
}
/* Bugzilla 28006 End */

/* Bugzilla 27668 Start */
/****************************************************************/
/* CATEGORY   : ROUTINE                                         */
/* ACCESS     : Public                                          */
/* BLOCK      : HIGH LEVEL                                      */
/* CHIP       : Tenabo                                          */
cs_status ten_hl_n40g_otl3_4_mld_t41 (cs_uint16 module_id, 
                                      cs_uint16 client_traffic_type,
                                      cs_uint16 fec)
/* INPUTS     : o Module Id                                     */
/*              o Client Type                                   */
/*              o FEC                                           */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* Configures an N40G transponder transmit/receive path.        */
/*                                                              */
/* [module_id] parameter specifies line's module ID             */
/* 16 devices can be registered and module bit indicates line   */
/* or client side of the registered device. The registered      */ 
/* device is identified by the dev_id bits specified below      */
/*   Bits 11:8 – dev_id, Bits 7:1 – don’t care, Bit 0 – module  */ 
/*                                                              */
/* [client_traffic_type] parameter specifies the traffic type   */
/* of the client: */
/*   TEN_TRAFFIC_TYPE_OTU3                 = 1                  */
/*   TEN_TRAFFIC_TYPE_OTU3E                = 2                  */
/*   TEN_TRAFFIC_TYPE_OTU3P                = 3                  */
/*   TEN_TRAFFIC_TYPE_OTU3E3               = 23                 */
/*   TEN_TRAFFIC_TYPE_OTU3E2               = 34                 */
/*   TEN_TRAFFIC_TYPE_OTU3E4               = 55                 */
/*                                                              */
/* The [fec] parameter is specified as:                         */
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
/*   TEN_FEC_MODE_ZEROFEC           = 14,  (FEC all zeroes)     */
/*   TEN_FEC_MODE_NOFEC             = 15   (FEC not present).   */
/*   TEN_FEC_MODE_OTUkV_263         = 17,  (UFEC 7%)            */
/*   TEN_FEC_MODE_OTUkV_280         = 18,  (UFEC 18%)           */
/*   TEN_FEC_MODE_OTUkV_295         = 19,  (UFEC 25%)           */
/*                                                              */
/****************************************************************/ 
{
  cs_status rtn = CS_OK;
  cs_char8 *func = "ten_hl_n40g_otl3_4_mld_t41";  
      
  CS_PRINT("%s() %s, %s, %s\n",
           func,
           ten_module_strings[module_id & 1],
           ten_hl_config_traffic_types_strings[client_traffic_type],
           ten_fec_ovhd_strings[fec]);
      
  /* Use Multi-Lane Descew */
  rtn |= ten_n40g_tx_otl34_t41 (module_id);  /* MLDEN=1, TX_MODE=0 */
  rtn |= ten_n40g_rx_otl34_t41 (module_id);  /* MLDEN=1, RX_MODE=0, DSCRL_EN=1 */

  switch (fec) {
    case TEN_FEC_MODE_OTUkV:
    case TEN_FEC_MODE_OTUkV_SDH_A:
    case TEN_FEC_MODE_OTUkV_SDH_B:
    case TEN_FEC_MODE_GFEC:
    case TEN_FEC_MODE_ZEROFEC:
    case TEN_FEC_MODE_OTUkV_4080_3929:
    case TEN_FEC_MODE_OTUkV_68_65:
      rtn |= ten_n40g_sadeco_sdclen (module_id, 0x0FF0);  /* (255 columns * 4 rows * chanels) */
      break;

    case TEN_FEC_MODE_OTUkV_262:
      rtn |= ten_n40g_sadeco_sdclen (module_id, 0x1060);  /* (262 columns * 4 rows * chanels) */
      break;

    case TEN_FEC_MODE_OTUkV_273:
      rtn |= ten_n40g_sadeco_sdclen (module_id, 0x1110);  /* (273 columns * 4 rows * chanels) */
      break;

    case TEN_FEC_MODE_OTUkV_285:
      rtn |= ten_n40g_sadeco_sdclen (module_id, 0x11D0);  /* (285 columns * 4 rows * chanels) */
      break;

    case TEN_FEC_MODE_OTUkV_297:
    case TEN_FEC_MODE_OTUkV_5_4:
      rtn |= ten_n40g_sadeco_sdclen (module_id, 0x1290);  /* (297 columns * 4 rows * chanels) */
      break;

    case TEN_FEC_MODE_OTUkV_301:
      rtn |= ten_n40g_sadeco_sdclen (module_id, 0x12D0);  /* (301 columns * 4 rows * chanels) */
      break;

    case TEN_FEC_MODE_OTUkV_267:
      rtn |= ten_n40g_sadeco_sdclen (module_id, 0x10B0);  /* (267 columns * 4 rows * chanels) */
      break;

    case TEN_FEC_MODE_OTUkV_270:
      rtn |= ten_n40g_sadeco_sdclen (module_id, 0x10E0);  /* (270 columns * 4 rows * chanels) */
      break;

    case TEN_FEC_MODE_NOFEC:
      rtn |= ten_n40g_sadeco_sdclen (module_id, 0x0EF0);  /* (239 columns * 4 rows * chanels) */
      break;
      
    default:
        CS_PRINT("ERROR, unhandled case\n");
        break;
  }

  rtn |= ten_n40g_mldrx_mld_es_set_sreset_t41 (module_id, TEN_SLICE_ALL, 0);
  rtn |= ten_n40g_mldrx_sadeco_set_sreset_t41 (module_id, 0);
  rtn |= ten_n40g_sadeco_enable_fp (module_id, 1);
  
  if (fec <= TEN_FEC_MODE_OTUkV_270) {
     /* Enables the MFAS translation table for generating compliant MFAS sequence after UFEC modification */ 
    rtn |= ten_n40g_mfas_translation_en (module_id, CS_TX_AND_RX, CS_ENABLE);
  }                                    
  
  return (rtn);
}                                        
/* Bugzilla 27668 End */
                                        
/* Bugzilla 24360 Start */
/****************************************************************/
/* $rtn_hdr_start  N40G TRANSPONDER CONFIG                      */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : HIGH LEVEL                                      */
/* CHIP       : Tenabo                                          */
cs_status ten_hl_n40g_config_trans_t41 (cs_uint16 module_id, 
                                        cs_uint16 client_traffic_type,
                                        cs_uint16 mapper,
                                        cs_uint16 fec,
                                        cs_uint16 map_proc,
                                        cs_uint16 timeslots,
                                        cs_uint16 gmp_timeslot_mask,
                                        cs_uint16 term_type,
                                        cs_uint16 tcm_bits,
                                        cs_uint16 mld_enabled,
                                        cs_uint16 kpga)
/* INPUTS     : o Module Id                                     */
/*              o Client Type                                   */
/*              o Mapper Type                                   */
/*              o FEC                                           */
/*              o Mapping Procedure                             */
/*              o Time Slots                                    */
/*              o GMP Timeslot Mask                             */
/*              o Termination Type                              */
/*              o TCM bits                                      */
/*              o MLD                                           */
/*              o KPGA enable                                   */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* Configures an N40G transponder transmit/receive path.        */
/*                                                              */
/* [module_id] parameter specifies line's module ID             */
/* 16 devices can be registered and module bit indicates line   */
/* or client side of the registered device. The registered      */ 
/* device is identified by the dev_id bits specified below      */
/*   Bits 11:8 – dev_id, Bits 7:1 – don’t care, Bit 0 – module  */ 
/*                                                              */
/* [client_traffic_type] parameter specifies the traffic type   */
/* of the client:                                               */
/*   TEN_TRAFFIC_TYPE_NONE                 = 0                  */
/*   TEN_TRAFFIC_TYPE_OTU3                 = 1                  */
/*   TEN_TRAFFIC_TYPE_OTU3E                = 2                  */
/*   TEN_TRAFFIC_TYPE_OTU3P                = 3                  */
/*   TEN_TRAFFIC_TYPE_OC768                = 22                 */
/*   TEN_TRAFFIC_TYPE_OTU3E3               = 23                 */
/*   TEN_TRAFFIC_TYPE_CBR40G_50188149150   = 24                 */
/*   TEN_TRAFFIC_TYPE_OTU3E2               = 34                 */
/*   TEN_TRAFFIC_TYPE_SERIAL_40GE          = 41,                */
/*   TEN_TRAFFIC_TYPE_PARALLEL_40GE        = 42,                */
/*   TEN_TRAFFIC_TYPE_TC_40GE              = 43,                */
/*   TEN_TRAFFIC_TYPE_S64_66_40GE          = 44,                */
/*   TEN_TRAFFIC_TYPE_OTU3E4               = 55                 */
/*                                                              */
/* [mapper] parameter specifies the traffic type of the line:   */
/*   TEN_TRAFFIC_TYPE_NONE                 = 0                  */
/*   TEN_TRAFFIC_TYPE_OTU3                 = 1                  */
/*   TEN_TRAFFIC_TYPE_OTU3E                = 2                  */
/*   TEN_TRAFFIC_TYPE_OTU3P                = 3                  */
/*   TEN_TRAFFIC_TYPE_40GELAN              = 21                 */
/*   TEN_TRAFFIC_TYPE_OC768                = 22                 */
/*   TEN_TRAFFIC_TYPE_OTU3E3               = 23                 */
/*   TEN_TRAFFIC_TYPE_CBR40G_50188149150   = 24                 */
/*   TEN_TRAFFIC_TYPE_OTU3P2               = 25                 */
/*   TEN_TRAFFIC_TYPE_OTU3E2               = 34                 */
/*   TEN_TRAFFIC_TYPE_OTU3E4               = 55                 */
/*                                                              */
/* The [fec] parameter is specified as:                         */
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
/*   TEN_FEC_MODE_NOFEC             = 15   (FEC not present).   */
/*   TEN_FEC_MODE_OTUkV_263         = 17,  (UFEC 7%)            */
/*   TEN_FEC_MODE_OTUkV_280         = 18,  (UFEC 18%)           */
/*   TEN_FEC_MODE_OTUkV_295         = 19,  (UFEC 25%)           */
/*                                                              */
/* The [map_proc] parameter specifies the mapping method        */
/*  TEN_MAP_AMP,           = 0                                  */
/*  TEN_MAP_BMP,           = 1                                  */
/*  TEN_MAP_AMP_PROP,      = 3                                  */
/*  TEN_MAP_GMP_LO,        = 5                                  */
/*  TEN_MAP_GMP_HO,        = 6                                  */
/*                                                              */
/* The [timeslots] parameter specifies number of timeslots.     */
/* Bandwidth is always 1.25G per timeslot for GMP_HO. Whereas   */
/* for AMP it is as follows:                                    */
/* 16 timeslots  - 2.5G per timeslot                            */
/* 32 timeslots  - 1.25G per timeslot                           */
/*   timeslots = 1 – 8      for [map_proc] - GMP_HO             */
/*   timeslots = 16/32      for [map_proc] – Any AMP            */
/*                                                              */
/* The [gmp_timeslot_mask] parameter specifies the timeslots to */
/* use for GMP mapping. Applicable to GMP_HO only.              */
/*   Bit 0- Timeslot 1 through Bit 7 – Timeslot 8               */
/*                                                              */
/* The [term_type] parameter specifies the termination type     */
/*   TEN_OC768_TERM_TRANSPARENT_CBR10       = 1                 */
/*   TEN_OC768_TERM_TRANSPARENT_REGENERATOR = 2                 */
/*   TEN_OC768_TERM_RS_LAYER_REGENERATOR    = 3                 */
/*   TEN_OC768_TERM_MS_LAYER_REGENERATOR    = 4                 */
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
/* The [mld_enbl] parameter enables distributing data across    */
/* multiple lanes on line side i.e. OTL3.4                      */
/*   disable = 0                                                */
/*   enable  = 1                                                */
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
  ten_dev_cb_t *pdevcb;
  cs_uint16 dev_id;
  cs_uint16 module;
  TEN_N40G_GBLT4X_KPGCFG_t tmp_n40g_gblt4x_kpgcfg;
  TEN_N40G_GBLR4X_DPCFG0_t tmp_n40g_gblr4x_dpcfg0;
  TEN_N40G_OTNT4X_WRPCFG3_t tmp_n40g_otnt4x_wrpcfg3;
  T41_t *pDev = NULL;
  /* Bugzilla #26779, compile warnings */
  /* TEN_N40G_OTNT4X_CFG4_t tmp_n40g_otnt4x_cfg4; */
  TEN_N40G_OTNR4X_ODWCFG_t tmp_otnr4x_odwcfg;
  TEN_N40G_GBLT4X_CFG_t tmp_n40g_gblt4x_cfg;
  TEN_N40G_OTNR4X_OBFA2_OFCFG0_t tmp_n40g_otnr4x_obfa2_ofcfg0;  /* Bugzilla 26730 */
  /*cs_uint16 payload_type = TEN_PAYLOAD_TYPE_SYNC_CBR;*/
  cs_status rtn = CS_OK;
  cs_char8 *func = "ten_hl_n40g_config_trans_t41";  
#if 0
  //TEN_N40G_ST4X_OHIE_t tmp_n40g_st4x_ohie;
  //TEN_N40G_GBLT4X_CFG_t tmp_n40g_gblt4x_cfg;
  //TEN_N40G_OTNT4X_CNCFG00_t tmp_n40g_otnt4x_cncfg00;
  //TEN_N40G_OTNT4X_CNCFG01_t tmp_n40g_otnt4x_cncfg01;
  //TEN_N40G_OGMPR4X_CNCFG00_t tmp_n40g_ogmpr4x_cncfg00;
  //TEN_N40G_OGMPR4X_CNCFG01_t tmp_n40g_ogmpr4x_cncfg01;
  //TEN_N40G_OTNR4X_ODWFS0_t tmp_n40g_otnr4x_odwfs0;
  //TEN_N40G_OTNR4X_ODWFS1_t tmp_n40g_otnr4x_odwfs1;
  //TEN_N40G_OTNT4X_GMPCFG1_t tmp_n40g_otnt4x_gmpcfg1;
#endif

  TEN_MOD_COMMON_VALIDATE (module_id, pDev, CS_ERROR);
  module = TEN_MOD_ID_TO_MOD_NUM (module_id);

  dev_id = TEN_MOD_ID_TO_DEV_ID (module_id);
  pdevcb = TEN_DEV_ID_TO_DEVCB_PTR(dev_id);

  CS_PRINT("%s()\n", func);
  CS_PRINT("    %s\n", ten_module_strings[module_id & 1]);
  CS_PRINT("    client_traffic_type = %s\n", ten_hl_config_traffic_types_strings[client_traffic_type]);
  CS_PRINT("    mapper = %s\n", ten_hl_config_traffic_types_strings[mapper]);
  if (map_proc <= TEN_MAP_GMP_HO_DT) {           
    CS_PRINT("    map_proc=%s\n", ten_sync_type_strings[map_proc]);
  }
  else {
    CS_PRINT("    map_proc=%d\n", map_proc);
  }
  CS_PRINT("    timeslots=0x%X\n", timeslots);
  CS_PRINT("    gmp_timeslot_mask=0x%X\n", gmp_timeslot_mask); 
  if (client_traffic_type == TEN_TRAFFIC_TYPE_OC768) {
    CS_PRINT("    term_type=%s\n", ten_hl_config_oc192_overhead_term_strings[term_type]);
  } 
  else if ((client_traffic_type == TEN_TRAFFIC_TYPE_OTU3) || (client_traffic_type == TEN_TRAFFIC_TYPE_OTU3E) ||
           (client_traffic_type == TEN_TRAFFIC_TYPE_OTU3P) || (client_traffic_type == TEN_TRAFFIC_TYPE_OTU3E3) || 
           (client_traffic_type == TEN_TRAFFIC_TYPE_OTU3E2) || (client_traffic_type == TEN_TRAFFIC_TYPE_OTU3E4) ||
           (client_traffic_type == TEN_TRAFFIC_TYPE_OTU3P2) ) {
    CS_PRINT("    term_type=%s\n", ten_hl_config_otu_overhead_term_strings[term_type]);       
  } 
  else {
    CS_PRINT("    term_type=%d\n", term_type);       
  }        
  CS_PRINT("    tcm_bits=0x%X\n", tcm_bits);
  CS_PRINT("    mld_enabled=%d\n", mld_enabled);
  CS_PRINT("    kpga=%s\n", ten_kpg_strings[kpga]); 

  /* Bugzilla 27397 code removed */ 

  if (mld_enabled) {
    CS_PRINT("MLD is enabled\n");
    /* Bugzilla #33380, MLDR_LMCFG and FTOLD Settings Should be changed for OTL3.4 */
    ten_n40g_mldrx_mldr_set_lmforlen_t41(module_id, 0xF);
    
    /* Use Multi-Lane Descew */
    if (mapper == TEN_TRAFFIC_TYPE_OC768) {
      /* Provision Client side of OC768 to OTU3v */
      ten_n40g_tx_stl256_t41 (module_id);  /* MLDEN=1, TX_MODE=1, SKEW_EN=1   Enable SONET MLD, STL256 */
      ten_n40g_rx_stl256_t41 (module_id);  /* MLDEN=1, RX_MODE=1, DSCRL_EN=1  Enable SONET MLD, STL256 */

      /* Configure mld elastic store and sadeco in N40G */
      ten_n40g_sadeco_config (module_id, 4, 505, XCON_SONET_SDH_16, 0x1F);  /* ESDEPTH, HIGHLIM, SDH16MD, RSYMSK */
      ten_n40g_sadeco_enable_fp (module_id, CS_ENABLE);  /* SDCOFF */
      ten_n40g_set_circuit_thresholds (module_id, TEN_SLICE_ALL, XCON_ES_IML_THRESH, 510);
      ten_n40g_set_circuit_thresholds (module_id, TEN_SLICE_ALL, XCON_ES_CIRCUIT_THRESHOLD_UPPER, 511);
      ten_n40g_sadeco_sdclen (module_id, 0x97E0);  /* (90 columns * 9 rows * 768 STS1) / 16 bytes per word */
      /*ten_n40g_mldr_set_lmfirlen (module_id, 2);*/
      
      ten_n40g_mldrx_mld_es_set_sreset_t41 (module_id, TEN_SLICE_ALL, 0);
      ten_n40g_mldrx_sadeco_set_sreset_t41 (module_id, 0);
      ten_n40g_sadeco_enable_fp (module_id, 1);
    } 
    else if ((mapper == TEN_TRAFFIC_TYPE_TC_40GE) || (mapper == TEN_TRAFFIC_TYPE_SERIAL_40GE) ||
             (mapper == TEN_TRAFFIC_TYPE_PARALLEL_40GE) || (mapper == TEN_TRAFFIC_TYPE_S64_66_40GE)) {
      /* MLD handled in PP40G block */
    } 
    else {
      /* Provision OTNv */
      ten_hl_n40g_otl3_4_mld_t41 (module_id, mapper, fec);
    }
  }

  if (client_traffic_type == TEN_TRAFFIC_TYPE_OC768) {
    if (mapper == TEN_TRAFFIC_TYPE_OC768) {
      /* Provision Client side of OC768 to OTU3v */
      /* Route Data path through OC768 block  */
      ten_n40g_tx_oc768_out_t41 (module_id);   /* Bypass OTU3   OBY=1 */
      ten_n40g_rx_oc768_in_t41 (module_id);    /* Bypass OTU3   BYPCFG=1, OBY=1 */

   /* Set NCOLS and NPAR in case we do a CBR */
      ten_n40g_otnr4x_set_ncols (module_id, 238);  /* NCOLS=238 */
      ten_n40g_otnr4x_set_nparb_npar (module_id, 0, 0); /* NPARB=0, NPAR=0 */
      
      /* Program the 40G SONET Transmit block: (b1inv, b1trans, b1ie, scren, a1a2rsh ) */
      ten_n40g_st4x_set_ohie (module_id, 0, 0, 0, 1, 0);

      
      if (term_type == TEN_OC192_TERM_TRANSPARENT_CBR10) {
        ten_n40g_gblr4x_set_dpcfg0 (module_id, 1, 1, 0, 1, 1, 1); /* kpasel, bypcfg, mdpcfg, bysel, oby, sby */
        ten_n40g_gblt4x_set_cfg (module_id, 1, 1, 1, 0); /* kpgby, sby, oby, mdpcfg */

        /* Bugzilla #24460, move this call to correct 40G SONET/SDH Aligner Settings */
        /* ten_n40g_sdfr_set_sdfcfg_fawwup_fawwdw (module_id, 4, 1);  */ /* FAWWUP, FAWWDW */
      }
      else {
        /* Configure 40g RX data path for OTU framing of data straight to the OC768 */
        ten_n40g_gblr4x_set_dpcfg0 (module_id, 0, 0, 3, 0, 1, 0);  /* KPASEL, BYPCFG, MDPCFG, BYSEL, OBY, SBY */
  
        /* Disabel OTU3 dewrapper  DW_ENABLE */
        ten_n40g_otnr4x_set_dw_enable (module_id, 0);  /* DW_ENABLE */
        /* Enable 40G SONET descrambler */
        ten_n40g_sdfr_enable_descrambler (module_id, 1 ); /* SCREN */
        /* Configure 40g TX data */
        ten_n40g_gblt4x_set_cfg (module_id, 1, 0, 1, 3); /* KPGBY, SBY, OBY, MDPCFG */
        /* Disable OTU3 scrablers */
        ten_n40g_otnt4x_scrambling (module_id, 0, 0); /* POSTSCR, PRESCR */
        /* Turn N40G Wrapper off */
        ten_n40g_otnt4x_set_wrapper_onoff (module_id, 0); /* WRMD */
        /* Program the 40G SONET Transmit block */
        ten_n40g_st4x_set_ohie (module_id, 0, 0, 0, 1, 0); /* b1inv, b1trans, b1ie, scren, a1a2rsh */
        /* Bugzilla #24460, move this call to correct 40G SONET/SDH Aligner Settings */
        /* ten_n40g_sdfr_set_sdfcfg_fawwup_fawwdw (module_id, 4, 1); */   /* FAWWUP, FAWWDW */
      }

     #if 0
      //if (term_type == TEN_OC192_TERM_TRANSPARENT_CBR10) {
      //else if (term_type == TEN_OC192_TERM_TRANSPARENT_REGENERATOR) {
      //  ten_n40g_set_oh_insertion_enables(module_id, TEN_N40G_ST4X_OHIE_B1TRANS, 0);  /* Enable insert of Calculated B1 */              
      //  ten_n40g_set_oh_insertion_enables(module_id, TEN_N40G_ST4X_OHIE_B1IE, 0);    /* Disable Calculated B1 insertion */                   
      //  ten_n40g_set_oh_insertion_enables(module_id, TEN_N40G_ST4X_OHIE_SCREN, 1);   /* Enable SONET/SDH scrabling */                        
      //  ten_n40g_set_oh_insertion_enables(module_id, TEN_N40G_ST4X_OHIE_A1A2RSH, 1); /* Enable A1 A2 insertion to refresh FAS */               
      //  ten_n40g_set_oh_insertion_enables(module_id, TEN_N40G_ST4X_OHIE_A1A2IE, 0);  /* Framing timing comes from receiver*/                  
      //}
      //else if (term_type == TEN_OC192_TERM_RS_LAYER_REGENERATOR) {
      //  ten_n40g_set_oh_insertion_enables(module_id, TEN_N40G_ST4X_OHIE_B1TRANS, 1);  /* Enable insert of Calculated B1 */              
      //  ten_n40g_set_oh_insertion_enables(module_id, TEN_N40G_ST4X_OHIE_B1IE, 1);    /* Enable Calculated B1 insertion */                   
      //  ten_n40g_set_oh_insertion_enables(module_id, TEN_N40G_ST4X_OHIE_SCREN, 1);   /* Enable SONET/SDH scrabling */                        
      //  ten_n40g_set_oh_insertion_enables(module_id, TEN_N40G_ST4X_OHIE_A1A2RSH, 1); /* Enable A1 A2 insertion to refresh FAS */               
      //  ten_n40g_set_oh_insertion_enables(module_id, TEN_N40G_ST4X_OHIE_A1A2IE, 0);  /* Framing timing comes from receiver*/                  
      //}
      //else if (term_type == TEN_OC192_TERM_MS_LAYER_REGENERATOR) {
      //  ten_n40g_set_oh_insertion_enables(module_id, TEN_N40G_ST4X_OHIE_B1TRANS, 1); /* Enable insert of Calculated B1 */               
      //  ten_n40g_set_oh_insertion_enables(module_id, TEN_N40G_ST4X_OHIE_B1IE, 1);    /* Enable Calculated B1 insertion */                   
      //  ten_n40g_set_oh_insertion_enables(module_id, TEN_N40G_ST4X_OHIE_SCREN, 1);   /* Enable SONET/SDH scrabling */                        
      //  ten_n40g_set_oh_insertion_enables(module_id, TEN_N40G_ST4X_OHIE_A1A2RSH, 1); /* Enable A1 A2 insertion to refresh FAS */               
      //  ten_n40g_set_oh_insertion_enables(module_id, TEN_N40G_ST4X_OHIE_A1A2IE, 0);  /* Framing timing comes from receiver*/                  
      //}
     #endif  
    
      /* Enable ISR for Sonet Out Of Frame */
      /*ten_n40g_sdfr_sdfist_handler_enable (module_id, TEN_N40G_SDFR_SDFIST_OOF);*/ /* Bugzilla 28977 */
    }

    else if ((mapper == TEN_TRAFFIC_TYPE_OTU3) || (mapper == TEN_TRAFFIC_TYPE_OTU3P) || 
             (mapper == TEN_TRAFFIC_TYPE_OTU3E2) || (mapper == TEN_TRAFFIC_TYPE_OTU3E3) || 
             (mapper == TEN_TRAFFIC_TYPE_OTU3E) || (mapper == TEN_TRAFFIC_TYPE_OTU3E4) ||
             (mapper == TEN_TRAFFIC_TYPE_OTU3P2) ) {  /* Bugzilla 31435 */
      /* Provision Line side of OC768 to OTU3v */
      ten_n40g_tx_otu3_t41 (module_id);  /* WRMD=3, STM256MD=0, STM64MD=0, AGGRMOD=0, OBY=0, ncols=254, npar=16, KPGBY=1, BIPMSK = */

      ten_n40g_otnt4x_set_wrapper_onoff (module_id, 1); /* Turn wrapper on */
    #if 0 
      //TEN_MOD_LOCK(module_id, TEN_ID_N40G);
      //tmp_n40g_otnt4x_wrpcfg3.wrd = TEN_REG_READ(TEN_N40G_REG_ADDR(pDev, module_id, WRPCFG3));
      //tmp_n40g_otnt4x_wrpcfg3.bf.WRMD = 1;  /* Turn wrapper on */
      //TEN_REG_WRITE(TEN_N40G_REG_ADDR(pDev, module_id, WRPCFG3), tmp_n40g_otnt4x_wrpcfg3.wrd);
      //TEN_MOD_UNLOCK(module_id, TEN_ID_N40G);
    #endif  
      
      /* Configure 40g TX data path for OTU framing of data from the OC768 mapper  (KPGBY, SBY, OBY, MDPCFG) */
      /*ten_n40g_gblt4x_set_cfg(mod_line, 1, 0, 0, 3);*/
      /*ten_n40g_otnt4x_scrambling(mod_line, 0, 1);*/ /* GFEC scrambling   POSTSCR, PRESCR */
      /* Configure STM256, STM64, Aggregation mode Monolithic and Wrapper mode ON  (WRPCFG3: STM256MD, STM64MD, AGGRMOD, WRMD) */
      /*ten_n40g_otnt4x_set_wrpcfg3 (mod_line, stm256md, stm64md, 0, 1);*/

   /* Program the 40G SONET Transmit block */
      ten_n40g_st4x_set_ohie (module_id, 0, 0, 0, 1, 0); /* b1inv, b1trans, b1ie, scren, a1a2rsh */
      /* Disable 10G Sonet scrambler */
      ten_n10g_soht_set_scren (module_id, TEN_SLICE_ALL, 0);
      /* Insert FAS pattern of 0xF6F6F6282828 hex row 1, columns 1 through 6 */
      ten_n40g_otnt4x_set_fasie (module_id, 1);  /* FASIE  */
      /* Bugzilla 26734 Start */
      /* Enable BIP */
      ten_n40g_otnt4x_bipmsk (module_id, 0x81|tcm_bits);  /* Enable Path, Section Monitoring and TCM BIP-8 insertion  */
      /* Bugzilla 26734 End */
    
     #if 0 
      ///* Set Payload Type Insertion (PTI) value to what the tester expects - 03 sync, 02 - async */
      //ten_n40g_set_pti_byte (module_id, payload_type);
      ///* Enable Payload Type Insertion (PTIE) */
      //ten_n40g_otnt4x_set_ptie (module_id, 1);
     #endif 
      /*ten_n40g_otnt4x_set_wrpcfg4(mod_line, jc_plus, jc_enabled);*/  /* Enable wrapper to generate justification commands.   Enable enhanced justification */

      /* Configure 40g RX data path for OTU Dewrapper and then through the OC768  (KPASEL, BYPCFG, MDPCFG, BYSEL, OBY, SBY) */
      /*ten_n40g_gblr4x_set_dpcfg0(module_id, 0, 0, 3, 0, 0, 0);*/
      /* Configure STM256, STM64, Aggregation mode Monolithic and Dewrapper mode ON (DW_CONFIG: FSOMD, STM64MD, STM256MD, AGGRMOD, DW_ENABLE) */
      /*ten_n40g_otnr4x_set_odwcfg (module_id, 0, stm64md, stm256md, 0, 1); */
    
      /* Enable 40G SONET descrambler */
      ten_n40g_sdfr_enable_descrambler(module_id, 1 );
      /* Set expected Payload Type (PT) to match tester - 03 - sync , 02 - async */
      /*ten_n40g_set_expected_pti_byte(module_id, payload_type);*/

      /*ten_hl_n40g_otn_aligner_settings (module_id);*/
   
      ten_n40g_rx_otu3_t41 (module_id);  /* OBY=0, ncols=254, npar=16, ALEN=1, BYSEL=0, BYSEL1=0, FSOMD=1, AGGRMOD=0, BYPCFG=1, BIPMSK=0xff */
      ten_n40g_rx_opu3_t41 (module_id);  /* OPU3 layer dewrapper is enabled   DW_ENABLE=1, BYSEL=1, BYSEL1=0, KPASEL=1 */

      if (kpga != TEN_KPG_DISABLED) {
        /*payload_type = TEN_PAYLOAD_TYPE_SYNC_CBR;*/
        /*tmp_n40g_otnt4x_cfg2.wrd = TEN_REG_READ(TEN_N40G_REG_ADDR(pDev, module_id, CFG2));*/
        /*tmp_n40g_otnt4x_cfg2.bf.PTI = 0x3;                                                */
        /*TEN_REG_WRITE(TEN_N40G_REG_ADDR(pDev, module_id, CFG2), tmp_n40g_otnt4x_cfg2.wrd);*/

        /*tmp_n40g_oohr_expti.wrd = TEN_REG_READ(TEN_N40G_OOHR_REG_ADDR(pDev, module_id, EXPTI));*/
        /*tmp_n40g_oohr_expti.bf.EXPTI = 0x3;                                                    */
        /*TEN_REG_WRITE(TEN_N40G_OOHR_REG_ADDR(pDev, module_id, EXPTI), tmp_n40g_oohr_expti.wrd);*/
      }

      rtn |= ten_hl_n40g_otn_aligner_settings (module_id);
      rtn |= ten_hl_n40g_config_lom_from_traffic (module_id, mapper, fec);
      
      /* Bugzilla #31390, set obfa2 lom */
      rtn |= ten_hl_n40g_config_lom_obfa2_from_traffic(module_id, mapper, fec);
      rtn |= ten_hl_n40g_config_lof_from_traffic(module_id, mapper, fec);
      rtn |= ten_hl_n40g_config_lof_obfa2_from_traffic(module_id, mapper, fec);
    
      rtn |= ten_n40g_sdfr_lofcfg2_m0byte(module_id, 1);
      
      /* Bugzilla 27397 Start */  
      /* Configure 40g RX data path for OTU Dewrapper and then through the OC768 */
      ten_n40g_gblr4x_set_dpcfg0 (module_id, 0, 0, 3, 0, 0, 0); /* KPASEL, BYPCFG, MDPCFG, BYSEL, OBY, SBY */
      /* Configure 40g TX data path for OTU framing of data from the OC768 mapper */
      ten_n40g_gblt4x_set_cfg(module_id, 1, 0, 0, 3); /* KPGBY, SBY, OBY, MDPCFG */
      /* Bugzilla 27397 End */  
    
      /* Enable ISR for OTN Out Of Frame */
      /*ten_n40g_otnr4x_intr_handler_enable (module_id, TEN_N40G_OTNR4X_INTR_IIF);*/   /* Bugzilla 28977*/
    }
      
    if (kpga != TEN_KPG_DISABLED) {
      /* The tester will see B3 errors because of a problem with the T40 chip */
      /* Configure for KPGA into OC768 */
     #if 0
      //tmp_n40g_st4x_ohie.wrd = TEN_REG_READ(TEN_N40G_REG_ADDR(pDev, module_id, OHIE));
      //tmp_n40g_st4x_ohie.bf.A1A2RSH = 0;
      //tmp_n40g_st4x_ohie.bf.A1A2IE = 1;
      //tmp_n40g_st4x_ohie.bf.PRBSIE = 1;
      ///*tmp_n40g_st4x_ohie.bf.B1IE = 1;*/
      //tmp_n40g_st4x_ohie.bf.POHIE = 1;
      //TEN_REG_WRITE(TEN_N40G_REG_ADDR(pDev, module_id, OHIE), tmp_n40g_st4x_ohie.wrd);
      //
      ///* Select POH C2BYTE */
      //ten_n40g_set_poh_byte (module_id, TEN_POH_C2, 0xFE);
      //
      //tmp_n40g_gblt4x_kpgcfg.wrd = TEN_REG_READ(TEN_N40G_REG_ADDR(pDev, module_id, KPGCFG));
      //tmp_n40g_gblt4x_kpgcfg.bf.PATSEL = kpga;
      //TEN_REG_WRITE(TEN_N40G_REG_ADDR(pDev, module_id, KPGCFG), tmp_n40g_gblt4x_kpgcfg.wrd);
      //
      ///*ten_n40g_gblr4x_set_kpasel (module_id, module_id);*/
      //tmp_n40g_gblr4x_dpcfg0.wrd = TEN_REG_READ(TEN_N40G_REG_ADDR(pDev, module_id, DPCFG0));
      //tmp_n40g_gblr4x_dpcfg0.bf.KPASEL = 0;  /* Signal to the KPA is VC-4-256 payload */
      //TEN_REG_WRITE(TEN_N40G_REG_ADDR(pDev, module_id, DPCFG0), tmp_n40g_gblr4x_dpcfg0.wrd);
      //
      ///* DW_CONFIG: FSOMD, STM64MD, STM256MD, AGGRMOD, DW_ENABLE */
      ///*  ten_n40g_otnr4x_set_odwcfg (module_id, 0, 0, 0, 0, 0); */
      //
      ///* PDHY0/1 */
      //ten_n40g_set_gblr4x_pdhy (module_id, 1, 0);
     //#if 0 
      //if (mapper == TEN_TRAFFIC_TYPE_OTU3) {
      //  /* FASIE */
      //  ten_n40g_otnt4x_set_fasie (module_id, 1);
      //
      //  /* Enable BIP */
      //  ten_n40g_otnt4x_bipmsk (module_id, 0xFF);
      //}
     //#endif 
     #endif 
      /* Configure 40g TX data */
      if (mapper == TEN_TRAFFIC_TYPE_OC768) {
        ten_n40g_gblt4x_set_cfg (module_id, 1, 0, 1, 3);  /* KPGBY, SBY, OBY, MDPCFG */
        /* Disable OTU3 scrablers */
        ten_n40g_otnt4x_scrambling (module_id, 0, 0); /* POSTSCR, PRESCR */
        /* Turn N40G Wrapper off */
        ten_n40g_otnt4x_set_wrapper_onoff (module_id, 0); /* WRMD */
      } else {
        ten_n40g_gblt4x_set_cfg (module_id, 1, 0, 0, 3);  /* KPGBY, SBY, OBY, MDPCFG */
        ten_n40g_otnt4x_set_wrpcfg3 (module_id, 1, 0, 0, 1); /* STM256MD, STM64MD, AGGRMOD, WRMD */
      }
      
      /* Program the SONET Transmit block */
      ten_n40g_st4x_set_ohie (module_id, 0, 0, 1, 1, 0); /* b1inv, b1trans, b1ie, scren, a1a2rsh */
      /* Select PRBS data from KPG as payload PRBSIE */
      ten_n40g_set_oh_insertion_enables (module_id, TEN_N40G_ST4X_OHIE_PRBSIE, 1);
      /* Select PRBS data from KPG as payload B1IE */
      ten_n40g_set_oh_insertion_enables (module_id, TEN_N40G_ST4X_OHIE_B1IE, 1);
      /* Select PRBS data from KPG as payload POHIE */
      ten_n40g_set_poh_byte (module_id, TEN_POH_C2, 0xFE);
      ten_n40g_set_oh_insertion_enables (module_id, TEN_N40G_ST4X_OHIE_POHIE, 1);
      /* A1A2 insertion needs to be set A1A2IE */
      ten_n40g_set_oh_insertion_enables (module_id, TEN_N40G_ST4X_OHIE_A1A2IE, 1);
      /* Config KPG - PATSEL */
      ten_n40g_config_kpg (module_id, 1, 0, kpga, 0, 0, 0, 0, 0, 0, 0, 0); /* KPGBY, KPGAUTO, PATSEL, FPAT7..FPAT0,   */
      
     #if 0 
      ///* Configure the N10G SONET block so that it produces the OH byptes needed by the N40G for framing */
      //ten_n10g_set_gblt_cfgtx0 (module_id, TEN_SLICE_ALL, 0, 0, 0, 1, 1, 0, 1, 0); /* pplf_en, cbrstmaisins, pn11auto, otnoff, oby, sby, kpgby, pktie */
      //ten_n10g_soht_set_a1a2ie (module_id, TEN_SLICE_ALL, 1); /* A1A2IE */
      //ten_n10g_soht_pohben0 (module_id, TEN_SLICE_ALL, 1, 1); /* PRBSIE, POHIE */
      //ten_n10g_otnt_set_wrmd (module_id, TEN_SLICE_ALL, 0); /* WRMD */
     #endif 
      if (mapper == TEN_TRAFFIC_TYPE_OC768) {
        /* Configure 40g RX data path for OTU framing of data straight to the OC768 */
        ten_n40g_gblr4x_set_dpcfg0 (module_id, 0, 0, 3, 0, 1, 0); /* KPASEL, BYPCFG, MDPCFG, BYSEL, OBY, SBY */
        /* Disabel OTU3 dewrapper  DW_ENABLE */
        ten_n40g_otnr4x_set_dw_enable (module_id, 0); /* DW_ENABLE */
        /* Configure STM256, STM64, Aggregation mode Monolithic and Dewrapper mode off */
        ten_n40g_otnr4x_set_odwcfg (module_id, 0, 0, 0, 0, 0); /* FSOMD, STM64MD, STM256MD, AGGRMOD, DW_ENABLE */
      }
      else {
        ten_n40g_gblr4x_set_dpcfg0 (module_id, 0, 0, 3, 0, 0, 0); /* KPASEL, BYPCFG, MDPCFG, BYSEL, OBY, SBY */
        ten_n40g_otnr4x_set_odwcfg (module_id, 0, 0, 1, 0, 1); /* FSOMD, STM64MD, STM256MD, AGGRMOD, DW_ENABLE */
      }
      
      /* Bug #40056:  OTU2 KPGA configuration sets PDHY = 0, PHYS also left at 0 */
      /* ten_n40g_set_gblr4x_pdhy (module_id, 0x5F5, 0xE100); */ /* PDHY1, PDHY0 */ 
  
      /* Enable 40G SONET descrambler */
      ten_n40g_sdfr_enable_descrambler (module_id, 1 ); /* SCREN */
      
     #if 0 
     //ten_n10g_set_gblr_dpcfg (module_id, TEN_SLICE_ALL, 2, 0, 0, 0, 1, 0, 1); /* XSEL, KPASEL, SBYPLD, SBYFRM, OBY, SDHOFF, OTNOFF */
     #endif 
    }
  }

  /* Bugzilla #31577, support OTU3E4 */
  /*else if ((client_traffic_type == TEN_TRAFFIC_TYPE_OTU3) && (mapper == TEN_TRAFFIC_TYPE_OTU3)) {*/
  else if ((client_traffic_type == TEN_TRAFFIC_TYPE_OTU3) || (client_traffic_type == TEN_TRAFFIC_TYPE_OTU3E) ||
           (client_traffic_type == TEN_TRAFFIC_TYPE_OTU3E2) || (client_traffic_type == TEN_TRAFFIC_TYPE_OTU3P) ||
           (client_traffic_type == TEN_TRAFFIC_TYPE_OTU3E3) || (client_traffic_type == TEN_TRAFFIC_TYPE_OTU3E4) ||
           (client_traffic_type == TEN_TRAFFIC_TYPE_OTU3P2) ) {
    /* Line and client are OTU3v */
    /* OTU3 layer generation only, FEC overhead bytes are added and ODU3 layer is untouched Sonet bypassed */
    ten_n40g_tx_odu3_otu3_t41 (module_id);    /* SBY=1 WRMD=3, STM256MD=0, STM64MD=0, AGGRMOD=0, OBY=0, ncols=254, npar=16, KPGBY=1, BIPMSK = */
    ten_n40g_rx_otu3_odu3_t41 (module_id);    /* SBY=1, KPASEL=1, OBY=0, ncols=254, npar=16, ALEN=1, BYSEL=0, BYSEL1=0, FSOMD=1, AGGRMOD=0, BYPCFG=1, BIPMSK=0xff */

    if (kpga == TEN_KPG_DISABLED) {
      ten_hl_40g_otu3_tx_termination (module_id, term_type, tcm_bits);
      ten_hl_40g_otu3_rx_termination (module_id, term_type);
    }
    /*if (kpga != TEN_KPG_DISABLED) {*/
    else {
#if 0
      ///* Configure for KPGA into ODU3 */
      //payload_type = TEN_PAYLOAD_TYPE_PRBS;
      //
      //ten_n40g_tx_opu3_t41(module_id); /* OPU3 layer wrapper is enabled. WRMD=1 BIPMSK |= 0x01 */
      //
      ///* Place pattern in fixed stuff */
      //tmp_n40g_otnt4x_wrpcfg3.wrd = TEN_REG_READ(TEN_N40G_REG_ADDR(pDev, module_id, WRPCFG3));
      //tmp_n40g_otnt4x_wrpcfg3.bf.STM256MD = 0;
      //TEN_REG_WRITE(TEN_N40G_REG_ADDR(pDev, module_id, WRPCFG3), tmp_n40g_otnt4x_wrpcfg3.wrd);
      //tmp_otnr4x_odwcfg.wrd = TEN_REG_READ(TEN_N40G_REG_ADDR(pDev, module_id, ODWCFG));
      //tmp_otnr4x_odwcfg.bf.STM256MD = 0;
      //TEN_REG_WRITE(TEN_N40G_REG_ADDR(pDev, module_id, ODWCFG), tmp_otnr4x_odwcfg.wrd);
      //
      ///*tmp_n40g_otnt4x_cfg0.wrd = TEN_REG_READ (TEN_N40G_REG_ADDR(pDev, module_id, CFG0));*/
      ///*tmp_n40g_otnt4x_cfg0.bf.PTIE = 1;                                                  */
      ///*TEN_REG_WRITE (TEN_N40G_REG_ADDR(pDev, module_id, CFG0), tmp_n40g_otnt4x_cfg0.wrd);*/
      //
      ///*tmp_n40g_otnt4x_cfg2.wrd = TEN_REG_READ(TEN_N40G_REG_ADDR (pDev, module_id, CFG2));*/
      ///*tmp_n40g_otnt4x_cfg2.bf.PTI = 0xFE;                                                */
      ///*TEN_REG_WRITE (TEN_N40G_REG_ADDR(pDev, module_id, CFG2), tmp_n40g_otnt4x_cfg2.wrd);*/
      //
      //tmp_n40g_gblt4x_cfg.wrd = TEN_REG_READ (TEN_N40G_REG_ADDR(pDev, module_id, CFG));
      //tmp_n40g_gblt4x_cfg.bf.KPGBY = 0;
      //TEN_REG_WRITE (TEN_N40G_REG_ADDR(pDev, module_id, CFG), tmp_n40g_gblt4x_cfg.wrd);
      //
      //tmp_n40g_gblt4x_kpgcfg.wrd = TEN_REG_READ (TEN_N40G_REG_ADDR(pDev, module_id, KPGCFG));
      ///*tmp_n40g_gblt4x_kpgcfg.bf.PATSEL = pattern;*/
      //tmp_n40g_gblt4x_kpgcfg.bf.PATSEL = kpga;
      //TEN_REG_WRITE (TEN_N40G_REG_ADDR(pDev, module_id, KPGCFG), tmp_n40g_gblt4x_kpgcfg.wrd);
      //
      //
      //ten_n40g_rx_opu3_t41 (module_id);   /* OPU3 layer dewrapper is enabled   DW_ENABLE=1, BYSEL=1, BYSEL1=0, KPASEL=1 */
      //
      //tmp_n40g_gblr4x_dpcfg0.wrd = TEN_REG_READ (TEN_N40G_REG_ADDR(pDev, module_id, DPCFG0));
      //tmp_n40g_gblr4x_dpcfg0.bf.SBY = 1;
      //tmp_n40g_gblr4x_dpcfg0.bf.KPASEL = 1;   /* Signal to the KPA is the OPU-3 payload or the unaligned line interface input */
      //TEN_REG_WRITE (TEN_N40G_REG_ADDR(pDev, module_id, DPCFG0), tmp_n40g_gblr4x_dpcfg0.wrd);
      //
      ///*payload_type = TEN_PAYLOAD_TYPE_PRBS;                                                   */
      ///*tmp_n40g_oohr_expti.wrd = TEN_REG_READ (TEN_N40G_OOHR_REG_ADDR(pDev, module_id, EXPTI));*/
      ///*tmp_n40g_oohr_expti.bf.EXPTI = 0xFE;                                                    */
      ///*TEN_REG_WRITE (TEN_N40G_OOHR_REG_ADDR(pDev, module_id, EXPTI), tmp_n40g_oohr_expti.wrd);*/
#endif    
      /*payload_type = TEN_PAYLOAD_TYPE_PRBS;*/

      rtn |= ten_n40g_gblt4x_set_cfg (module_id, 0, 1, 0, 3); /* KPGBY, SBY, OBY, MDPCFG */
      rtn |= ten_n40g_otnt4x_scrambling (module_id, 0, 1);  /* POSTSCR, PRESCR */
      rtn |= ten_n40g_otnt4x_set_wrpcfg3 (module_id, 0, 0, 0, 1);  /* STM256MD, STM64MD, AGGRMOD, WRMD */
      rtn |= ten_n40g_config_kpg (module_id, 0,0, kpga, 0, 0, 0, 0, 0, 0, 0, 0); /* KPGBY, KPGAUTO, PATSEL, FPAT7..FPAT0,   */
      rtn |= ten_n40g_otnt4x_set_fasie (module_id, 1); /* FASIE */
      /*rtn |= ten_n40g_otnt4x_bipmsk (module_id, 0xFF);*/
      rtn |= ten_n40g_otnt4x_bipmsk (module_id, 0x81|tcm_bits);  /* Enable Path, Section Monitoring and TCM BIP-8 insertion  */
      /*rtn |= ten_n40g_set_pti_byte (module_id, TEN_PAYLOAD_TYPE_PRBS);*/
      /*rtn |= ten_n40g_otnt4x_set_ptie (module_id, 1);                 */

      rtn |= ten_n40g_gblr4x_set_dpcfg0 (module_id, 1, 0, 3, 0, 0, 1); /* KPASEL, BYPCFG, MDPCFG, BYSEL, OBY, SBY */
      rtn |= ten_n40g_otnr4x_set_odwcfg (module_id, 0, 0, 0, 0, 1); /*( FSOMD, STM64MD, STM256MD, AGGRMOD, DW_ENABLE) */
      /* Bug #40056:  OTU2 KPGA configuration sets PDHY = 0, PHYS also left at 0 */
      rtn |= ten_n40g_set_gblr4x_pdhy (module_id, 0x5F5, 0xE100);  /* PDHY1, PDHY0 */
      /*rtn |= ten_n40g_set_expected_pti_byte (module_id, TEN_PAYLOAD_TYPE_PRBS); */
    }

#if 0   
    ///* Set Payload Type Insertion (PTI) value  - 03 sync, 02 - async */
    //ten_n40g_set_pti_byte(module_id, payload_type);
    ///* Set expected Payload Type (PT) value  - 03 - sync , 02 - async */
    //ten_n40g_set_expected_pti_byte(module_id, payload_type);
    ///* Enable PTIE Payload Type Insertion Enable */
    ///*ten_n40g_otnt4x_set_ptie (module_id, 1);*/  /* Handled in ten_hl_40g_otu3_tx_termination() */
#endif    

    if (((client_traffic_type == TEN_TRAFFIC_TYPE_OTU3) && (mapper == TEN_TRAFFIC_TYPE_OTU3P)) ||
        ((client_traffic_type == TEN_TRAFFIC_TYPE_OTU3) && (mapper == TEN_TRAFFIC_TYPE_OTU3E)) ||
        ((client_traffic_type == TEN_TRAFFIC_TYPE_OTU3) && (mapper == TEN_TRAFFIC_TYPE_OTU3E1)) ||
        ((client_traffic_type == TEN_TRAFFIC_TYPE_OTU3) && (mapper == TEN_TRAFFIC_TYPE_OTU3E2))) {  /* Bugzilla 29481 */
      /* Route Line signal through second (client) ODU3 aligner  (Outputof 2nd Level OTN Aligner) */
      TEN_MOD_LOCK(module_id, TEN_ID_N40G);
      tmp_n40g_gblr4x_dpcfg0.wrd = TEN_REG_READ (TEN_N40G_REG_ADDR (pDev, module_id, DPCFG0));
      tmp_n40g_gblr4x_dpcfg0.bf.BYSEL = 0;
      tmp_n40g_gblr4x_dpcfg0.bf.BYSEL1 = 1;
      TEN_REG_WRITE (TEN_N40G_REG_ADDR (pDev, module_id, DPCFG0), tmp_n40g_gblr4x_dpcfg0.wrd);

      /* Bugzilla 26730 Start */
      tmp_n40g_otnr4x_obfa2_ofcfg0.wrd = TEN_REG_READ(TEN_N40G_REG_ADDR(pDev, module_id, OBFA2_OFCFG0));
      tmp_n40g_otnr4x_obfa2_ofcfg0.bf.NCOLS = 238;
      TEN_REG_WRITE(TEN_N40G_REG_ADDR(pDev, module_id, OBFA2_OFCFG0), tmp_n40g_otnr4x_obfa2_ofcfg0.wrd);
      /* Bugzilla 26730 End */

      /* Bugzilla 26734 Start */
      /* Place pattern in fixed stuff */
      tmp_n40g_otnt4x_wrpcfg3.wrd = TEN_REG_READ(TEN_N40G_REG_ADDR(pDev, module_id, WRPCFG3));
      tmp_n40g_otnt4x_wrpcfg3.bf.STM256MD = 0;
      TEN_REG_WRITE(TEN_N40G_REG_ADDR(pDev, module_id, WRPCFG3), tmp_n40g_otnt4x_wrpcfg3.wrd);
      tmp_otnr4x_odwcfg.wrd = TEN_REG_READ(TEN_N40G_REG_ADDR(pDev, module_id, ODWCFG));
      tmp_otnr4x_odwcfg.bf.STM256MD = 0;
      TEN_REG_WRITE(TEN_N40G_REG_ADDR(pDev, module_id, ODWCFG), tmp_otnr4x_odwcfg.wrd);
      /* Bugzilla 26734 End */
      TEN_MOD_UNLOCK(module_id, TEN_ID_N40G);

      ten_n40g_otnr4x_set_dw_enable (module_id, 1);  /*  DW_ENABLE  Enable the dewrapper ???????????????? Is ODU3 inside of ODU3p?????????  */

      ten_n40g_otnt4x_set_wrapper_onoff (module_id, 1); /* WRMD   Enable full wrapping OPU3->OTU3 */
    }

    rtn |= ten_hl_n40g_otn_aligner_settings (module_id);
    rtn |= ten_hl_n40g_config_lom_from_traffic (module_id, client_traffic_type, fec);
    
    /* Bugzilla #31390, set obfa2 lom */
    rtn |= ten_hl_n40g_config_lom_obfa2_from_traffic(module_id, client_traffic_type, fec);
    rtn |= ten_hl_n40g_config_lof_from_traffic(module_id, client_traffic_type, fec);
    rtn |= ten_hl_n40g_config_lof_obfa2_from_traffic(module_id, client_traffic_type, fec);
    
    rtn |= ten_n40g_sdfr_lofcfg2_m0byte(module_id, 1);
  
    /* Enable ISR for OTN Out Of Frame */
    /*ten_n40g_otnr4x_intr_handler_enable (module_id, TEN_N40G_OTNR4X_INTR_IIF);*/   /* Bugzilla 28977*/
  }

  /* Bugzilla 26200 Start */
  else if ((client_traffic_type == TEN_TRAFFIC_TYPE_TC_40GE) || (client_traffic_type == TEN_TRAFFIC_TYPE_SERIAL_40GE) ||
           (client_traffic_type == TEN_TRAFFIC_TYPE_PARALLEL_40GE) || (client_traffic_type == TEN_TRAFFIC_TYPE_S64_66_40GE)) {
    if (client_traffic_type == mapper) {
      /* Provision Client side of 40GE to OTU3v */
      /*ten_n40g_rx_n40g_bypass_t41 (module_id);*/ /* Bypass OTU3 and OC768 Blocks  BYPCFG=1, BYSEL=1, BYSEL1=0, OBY=1 */
      ten_n40g_rx_pkt_bypass_t41 (module_id);  /* OBY=1, SBY=1 */
      ten_n40g_tx_pkt_bypass_t41 (module_id);  /* OBY=1, SBY=1, KPGBY=1 */

      /* Turn the OTN aligner off */
      ten_n40g_otnr4x_alen (module_id, 0); 
    }
    else {
      /* Provision Line side of 40GE to OTU3v */
      ten_n40g_tx_otu3_t41 (module_id);  /* WRMD=3, STM256MD=0, STM64MD=0, AGGRMOD=0, OBY=0, ncols=254, npar=16, KPGBY=1, BIPMSK = */
      #if 0
      //ten_n40g_tx_opu3_t41 (module_id);  /* OPU3 layer wrapper is enabled. BIPMSK|=0x01, WRMD=1, BIPMSK|=0x7E */
      #else
      TEN_MOD_LOCK(module_id, TEN_ID_N40G);
      tmp_n40g_otnt4x_wrpcfg3.wrd = TEN_REG_READ(TEN_N40G_REG_ADDR(pDev, module_id, WRPCFG3));
      tmp_n40g_otnt4x_wrpcfg3.bf.WRMD = 1;      /* Turn wrapper on */
      TEN_REG_WRITE(TEN_N40G_REG_ADDR(pDev, module_id, WRPCFG3), tmp_n40g_otnt4x_wrpcfg3.wrd);
      /* Bugzilla 26734 Start */
      /*tmp_n40g_otnt4x_cfg4.wrd = TEN_REG_READ(TEN_N40G_REG_ADDR(pDev, module_id, CFG4));*/
      /*tmp_n40g_otnt4x_cfg4.bf.BIPMSK |= 0x01;*/ /* Turn on BIP-8 Path Monitoring frame field insertion */
      /*TEN_REG_WRITE(TEN_N40G_REG_ADDR(pDev, module_id, CFG4), tmp_n40g_otnt4x_cfg4.wrd);*/
      TEN_MOD_UNLOCK(module_id, TEN_ID_N40G);
      /* Enable BIP */
      ten_n40g_otnt4x_bipmsk (module_id, 0x81|tcm_bits);  /* Enable Path, Section Monitoring and TCM BIP-8 insertion  */
      /* Bugzilla 26734 End */
      #endif

      TEN_MOD_LOCK(module_id, TEN_ID_N40G);
      tmp_n40g_gblt4x_cfg.wrd = TEN_REG_READ(TEN_N40G_REG_ADDR(pDev, module_id, CFG));
      tmp_n40g_gblt4x_cfg.bf.SBY = 1;   /* Bypass all SONET/SDH transmit functions */
      tmp_n40g_gblt4x_cfg.bf.MDPCFG = 0;  /* Generic Splitting */ /* Bugzilla 29609 */
      TEN_REG_WRITE(TEN_N40G_REG_ADDR(pDev, module_id, CFG), tmp_n40g_gblt4x_cfg.wrd);
      TEN_MOD_UNLOCK(module_id, TEN_ID_N40G);

      ten_n40g_rx_otu3_t41(module_id); /* OBY=0, ncols=254, npar=16, ALEN=1, BYSEL=0, BYSEL1=0, FSOMD=1, AGGRMOD=0, BYPCFG=1, BIPMSK=0xff */
      ten_n40g_rx_opu3_t41(module_id); /* OPU3 layer dewrapper is enabled   DW_ENABLE=1, BYSEL=1, BYSEL1=0, KPASEL=1 */

      TEN_MOD_LOCK(module_id, TEN_ID_N40G);
      tmp_n40g_gblr4x_dpcfg0.wrd = TEN_REG_READ(TEN_N40G_REG_ADDR(pDev, module_id, DPCFG0));
      tmp_n40g_gblr4x_dpcfg0.bf.SBY = 1;   /* The SONET/SDH framer is bypassed */
      tmp_n40g_gblr4x_dpcfg0.bf.MDPCFG = 0;   /* Generic Split */
      TEN_REG_WRITE(TEN_N40G_REG_ADDR(pDev, module_id, DPCFG0), tmp_n40g_gblr4x_dpcfg0.wrd);
      TEN_MOD_UNLOCK(module_id, TEN_ID_N40G);

      /* Bugzilla 26734 Start */
      /* Enable BIP */
      ten_n40g_otnt4x_bipmsk (module_id, 0x81|tcm_bits);  /* Enable Path, Section Monitoring and TCM BIP-8 insertion  */
      /* Bugzilla 26734 End */

      #if 0
      //if (gmp)
      //    if (otu3) {
      //      ten_n40g_tx_gmp_lo_t41(module_id, 15232);
      //      tmp_n40g_otnt4x_cncfg01.bf.Cn01 = 0;
      //      tmp_n40g_otnt4x_cncfg00.bf.Cn00 = 15219;
      //      ten_n40g_rx_gmp_lo_t41(module_id, 15232);
      //      tmp_n40g_ogmpr4x_cncfg01.bf.Cn01 = 0;
      //      tmp_n40g_ogmpr4x_cncfg00.bf.Cn00 = 15219;
      //    }
      //    else if (otu3e) {
      //      ten_n40g_tx_gmp_lo_t41(module_id, 15232);
      //      tmp_n40g_otnt4x_cncfg01.bf.Cn01 = 0;
      //      tmp_n40g_otnt4x_cncfg00.bf.Cn00 = 14817;
      //      ten_n40g_rx_gmp_lo_t41(module_id, 15232);
      //      tmp_n40g_ogmpr4x_cncfg01.bf.Cn01 = 0;
      //      tmp_n40g_ogmpr4x_cncfg00.bf.Cn00 = 14817;
      //    }
      //    else if (otu3e2) {
      //      ten_n40g_tx_gmp_lo_t41(module_id, 15232);
      //      tmp_n40g_otnt4x_cncfg01.bf.Cn01 = 0;
      //      tmp_n40g_otnt4x_cncfg00.bf.Cn00 = 15100;
      //      ten_n40g_rx_gmp_lo_t41(module_id, 15232);
      //      tmp_n40g_ogmpr4x_cncfg01.bf.Cn01 = 0;
      //      tmp_n40g_ogmpr4x_cncfg00.bf.Cn00 = 15100;
      //    }
      //}
      //else if (proomap) {
      //    else if (otu3e) {
      //      tmp_n40g_otnt4x_wrpfs0.bf.FS0 = 127;
      //      tmp_n40g_otnr4x_odwfs0.bf.FS0 = 127;
      //    }
      //}
      #endif
      /* Enable ISR for OTN Out Of Frame */
      /*ten_n40g_otnr4x_intr_handler_enable (module_id, TEN_N40G_OTNR4X_INTR_IIF);*/   /* Bugzilla 28977 */
    }

   #if 0  
    ///*if (mapper == TEN_TRAFFIC_TYPE_OTU3) {*/
    //else if (mapper == TEN_TRAFFIC_TYPE_OTU3) {
    //  ten_n40g_tx_40ge_gmp_lo_otu3_t41 (module_id);
    //  ten_n40g_tx_40ge_gmp_lo_otu3_25u_t41 (module_id);
    //  ten_n40g_tx_40ge_gmp_lo_otu3_otl34_t41 (module_id);
    //
    //  ten_n40g_rx_otu3_gmp_lo_40ge_t41 (module_id);
    //  ten_n40g_rx_odu3_gmp_lo_40ge_t41 (module_id); 
    //
    //  ten_n40g_rx_otu3_25u_gmp_lo_40ge_t41 (module_id);
    //  ten_n40g_rx_otl34_otu3_gmp_lo_40ge_t41 (module_id);
    //}
    //else if (mapper == TEN_TRAFFIC_TYPE_OTU3E) {
    //  ten_n40g_tx_40ge_gmp_lo_otu3e1_t41 (module_id);
    //  ten_n40g_tx_40ge_propmap_lo_otu3e1_t41 (module_id);
    //
    //  ten_n40g_rx_otu3e1_gmp_lo_40ge_t41 (module_id);
    //  ten_n40g_rx_otu3e1_propmap_lo_40ge_t41 (module_id);
    //}
    //else if (mapper == TEN_TRAFFIC_TYPE_OTU3E2) {
    //  ten_n40g_tx_40ge_gmp_lo_otu3e2_t41 (module_id);
    //
    //  ten_n40g_rx_otu3e2_gmp_lo_40ge_t41 (module_id);
    //}
   #endif 
    /* Bugzilla 26200 End */
   
    /* Bugzilla #31390, set obfa2 lom */
    
    if ((mapper == TEN_TRAFFIC_TYPE_OTU3) || (mapper == TEN_TRAFFIC_TYPE_OTU3E) ||
      (mapper == TEN_TRAFFIC_TYPE_OTU3P) || (mapper == TEN_TRAFFIC_TYPE_OTU3P2) ||
      (mapper == TEN_TRAFFIC_TYPE_OTU3E2) || (mapper == TEN_TRAFFIC_TYPE_OTU3E4) ||
      (mapper == TEN_TRAFFIC_TYPE_OTU3E3) ) {
    
      rtn |= ten_hl_n40g_config_lom_from_traffic (module_id, mapper, fec);
      rtn |= ten_hl_n40g_config_lom_obfa2_from_traffic(module_id, mapper, fec);
      rtn |= ten_hl_n40g_config_lof_from_traffic(module_id, mapper, fec);
      rtn |= ten_hl_n40g_config_lof_obfa2_from_traffic(module_id, mapper, fec);
    }
  }
 
  else if ((client_traffic_type == TEN_TRAFFIC_TYPE_BYPASS) || (mapper == TEN_TRAFFIC_TYPE_BYPASS)) {
    ten_n40g_rx_n40g_bypass_t41 (module_id); /* Bypass OTU3 and OC768 Blocks  BYPCFG=1, BYSEL=1, BYSEL1=0, OBY=1 */
    /*ten_n40g_rx_pkt_bypass_t41 (module_id)*/  /* Bypass OTU3 and OC768 Blocks OBY=1, SBY=1*/
    ten_n40g_tx_pkt_bypass_t41 (module_id);  /* OBY=1, SBY=1, KPGBY=1 */

    /* Turn the OTN aligner off */
    ten_n40g_otnr4x_alen (module_id, 0); 

    if (kpga != TEN_KPG_DISABLED) {
      tmp_n40g_gblt4x_kpgcfg.wrd = TEN_REG_READ(TEN_N40G_REG_ADDR(pDev, module_id, KPGCFG));
      tmp_n40g_gblt4x_kpgcfg.bf.PATSEL = kpga;
      TEN_REG_WRITE(TEN_N40G_REG_ADDR(pDev, module_id, KPGCFG), tmp_n40g_gblt4x_kpgcfg.wrd);
    
      tmp_n40g_gblr4x_dpcfg0.wrd = TEN_REG_READ(TEN_N40G_REG_ADDR(pDev, module_id, DPCFG0));
      tmp_n40g_gblr4x_dpcfg0.bf.KPASEL = 0;
      TEN_REG_WRITE(TEN_N40G_REG_ADDR(pDev, module_id, DPCFG0), tmp_n40g_gblr4x_dpcfg0.wrd);
    }
  }
  
  /* Bugzilla 27397 Start */
  if ((mapper == TEN_TRAFFIC_TYPE_OTU3) || (mapper == TEN_TRAFFIC_TYPE_OTU3E) ||
      (mapper == TEN_TRAFFIC_TYPE_OTU3P) || (mapper == TEN_TRAFFIC_TYPE_OTU3P2) ||
      (mapper == TEN_TRAFFIC_TYPE_OTU3E2) || (mapper == TEN_TRAFFIC_TYPE_OTU3E4) ||
      (mapper == TEN_TRAFFIC_TYPE_OTU3E3) ) {
    /* This side will have a mapper/demapper */
    /* Bugzilla 27106 Start */
    if (kpga == TEN_KPG_DISABLED) {
      /* Only provision a mapping if KPGA is disabled  (KPGA uses BMP with no fixed stuff */
      rtn |= ten_n40g_trans_mapper_t41 (module_id, client_traffic_type, mapper, map_proc, timeslots, gmp_timeslot_mask);
    }
    /* Bugzilla 27106 End */
    rtn |= ten_hl_n40g_config_pti_t41 (module_id, client_traffic_type, map_proc, timeslots, kpga);

    /* Remove Open Connection Indication (OCI) siganl from the OTN frame in case it had been added */
    rtn |= ten_hl_ohpp_force_odu3_maintenance_signal (module_id, TEN_OHPP_INSERT_OCI, TEN_OHPP_WIDTH_FRAME, CS_DISABLE); /* Bugzilla 29609 */
  }
  /* Bugzilla 27397 End */
  
  if (mapper == TEN_TRAFFIC_TYPE_BYPASS) {
    /* Start clocking and take out of reset the N40G RX block */
    /*rtn |= ten_mpif_global_clock_disable_n40g (dev_id, module, CS_RX, CS_ENABLE);*/
    /*rtn |= ten_mpif_global_reset_n40g (dev_id, module, CS_RX, CS_RESET_DEASSERT);*/
    
    /* N40G block is bypassed.  This is used for client side of Muxponder */
    /*rtn |= ten_hl_n40g_rx_init (module_id, TEN_N40G_RX_BYPASS_SNT_MON);*/ /* Prabably not needed */

    /* N40G TX block is not clocked and left in reset */
  }
  else {
    /* Start clocking and take out of reset the N40G RX block */
    /* Bugzilla #30081 - using the wrong module ID in ten_hl_n40g_config_trans_t41 */ 
    rtn |= ten_mpif_global_clock_disable_n40g (dev_id, module, CS_RX, CS_ENABLE);
    rtn |= ten_mpif_global_reset_n40g (dev_id, module, CS_RX, CS_RESET_DEASSERT);
    
    /* Start clocking and take out of reset the N40G TX block */
    rtn |= ten_mpif_global_clock_disable_n40g (dev_id, module, CS_TX, CS_ENABLE);
    rtn |= ten_mpif_global_reset_n40g (dev_id, module, CS_TX, CS_RESET_DEASSERT);
  }
  
  return (CS_OK);
}
/* Bugzilla 24360 End */

/* Bugzilla 24956 Start */
/****************************************************************/
/* $rtn_hdr_start  HIGH LEVEL N40G CONFIG LOS OF MULTIFRAME     */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : HIGH LEVEL CONFIG                               */
/* CHIP       : Tenabo                                          */
cs_status ten_hl_n40g_config_lom_from_traffic (cs_uint16 module_id, 
                                               cs_uint16 traffic_type,
                                               cs_uint16 fec)
/* INPUTS     : o Module Id                                     */
/*              o Traffic Type                                  */
/*              o Fec                                           */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* Provision Loss Of Multiframe for N40G block for 3ms given    */
/* the traffic type and fec                                     */
/*                                                              */
/* [module_id] parameter specifies line's module ID             */
/* 16 devices can be registered and module bit indicates line   */
/* or client side of the registered device. The registered      */
/* device is identified by the dev_id bits specified below      */
/*   Bits 11:8 – dev_id, Bits 7:1 – don’t care, Bit 0 – module  */
/*                                                              */
/* [traffic_type] parameter specifies the traffic type          */
/*   TEN_TRAFFIC_TYPE_OTU3  = 1                                 */
/*   TEN_TRAFFIC_TYPE_OTU3E = 2                                 */
/*   TEN_TRAFFIC_TYPE_OTU3P = 3                                 */
/*   TEN_TRAFFIC_TYPE_OTU3_NOFEC = 19                           */
/*   TEN_TRAFFIC_TYPE_OTU3E3 = 23                               */
/*   TEN_TRAFFIC_TYPE_OTU3P2 = 25                               */
/*   TEN_TRAFFIC_TYPE_OC768_OTU3 = 32                           */
/*   TEN_TRAFFIC_TYPE_OTU3E2 = 35                               */
/*   TEN_TRAFFIC_TYPE_OTU3E4 = 55                               */
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
/*   TEN_FEC_MODE_NOFEC             = 15   (FEC not present).   */
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
  cs_char8 *func = "ten_hl_n40g_config_lom_from_traffic";  

  TEN_MOD_COMMON_VALIDATE (module_id, pDev, CS_ERROR);

  if ((traffic_type != TEN_TRAFFIC_TYPE_OTU3) && (traffic_type != TEN_TRAFFIC_TYPE_OTU3E) && 
      (traffic_type != TEN_TRAFFIC_TYPE_OTU3P) && (traffic_type != TEN_TRAFFIC_TYPE_OTU3_NOFEC) &&
      (traffic_type != TEN_TRAFFIC_TYPE_OTU3E3) && (traffic_type != TEN_TRAFFIC_TYPE_OTU3P2) &&
      (traffic_type != TEN_TRAFFIC_TYPE_OC768_OTU3) && (traffic_type != TEN_TRAFFIC_TYPE_OTU3E2) &&
      (traffic_type != TEN_TRAFFIC_TYPE_OTU3E4)) {     /* Bugzilla 28237 */
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, "%s() traffic_type %d out of range.", func, traffic_type);
    return (CS_ERROR);
  }    

  if (fec >= (TEN_FEC_MODE_MAX_NUM)) { 
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, "%s() fec %d out of range.  s/b 0..%d.", func, fec, (TEN_FEC_MODE_MAX_NUM-2));
    return (CS_ERROR);
  }

  CS_PRINT("%s() %s, %s, %s\n",
           func,
           ten_module_strings[module_id & 1],
           ten_hl_config_traffic_types_strings[traffic_type],
           ten_fec_ovhd_strings[fec]);

  /* Get signal rate on line */
  signal_rate = ten_calculate_signal_rate (traffic_type, fec);
  CS_PRINT("%s() signal_rate = %f\n", func, signal_rate);

  if (signal_rate == 0) {
    /* Line signal rate could not be found */
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, "%s() Traffic %s with fec %s not supported", 
                  func, ten_hl_config_traffic_types_strings[traffic_type], ten_fec_ovhd_strings[fec]);
    return (CS_ERROR);
  }

  rtn |= ten_hl_n40g_config_lom_from_bps (module_id, signal_rate);

  return (rtn);
}

/* Bugzilla 31127 Start */
/****************************************************************/
/* $rtn_hdr_start  HIGH LEVEL N40G CONFIG LOS OF FRAME FROM BPS */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : HIGH LEVEL CONFIG                               */
/* CHIP       : Tenabo                                          */
cs_status ten_hl_n40g_config_lof_from_bps (cs_uint16 module_id, 
                                           double signal_rate)
/* INPUTS     : o Module Id                                     */
/*              o Signal Rate                                   */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* Provision Loss Of frame for N40G block for 3ms given Bits    */
/* Per Second                                                   */
/*                                                              */
/* [module_id] parameter specifies line's module ID             */
/* 16 devices can be registered and module bit indicates line   */
/* or client side of the registered device. The registered      */
/* device is identified by the dev_id bits specified below      */
/*   Bits 11:8 – dev_id, Bits 7:1 – don’t care, Bit 0 – module  */
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
  cs_char8 *func = "ten_hl_n40g_config_lof_from_bps";  

  TEN_MOD_COMMON_VALIDATE (module_id, pDev, CS_ERROR);

  CS_PRINT("%s(), %s, %f\n",
           func,
           ten_module_strings[module_id & 1],
           signal_rate);

  /* Compute Time Delay: tdel = (signal rate/261120) * 0.003s */
  /* Half of a tdel unit is added to signal rate before the devide to round 0.5 up to 1. Half = (261120/(2*0.003))*/
  temp_tdel_on_off = ((signal_rate + (261120/(2*0.003))) / (261120/0.003));
  CS_PRINT("%s() temp_tdel_on_off = %d\n", func, temp_tdel_on_off);
  tdel_on_off = (cs_uint16)temp_tdel_on_off;
  CS_PRINT("%s() tdel_on_off = %d\n", func, tdel_on_off);

  rtn |= ten_n40g_otnr4x_lofcfg_tdelon_tdeloff (module_id, tdel_on_off, tdel_on_off);

  /*rtn |= ten_n40g_otnr4x_oacfg0_dsyhyst(module_id, 5);*/
  /*rtn |= ten_n40g_otnr4x_oacfg0_syhyst( module_id, 2);*/

  return (rtn);
}

/****************************************************************/
/* $rtn_hdr_start  HIGH LEVEL N40G CONFIG LOS OF FRAME          */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : HIGH LEVEL CONFIG                               */
/* CHIP       : Tenabo                                          */
cs_status ten_hl_n40g_config_lof_from_traffic (cs_uint16 module_id, 
                                               cs_uint16 traffic_type,
                                               cs_uint16 fec)
/* INPUTS     : o Module Id                                     */
/*              o Traffic Type                                  */
/*              o Fec                                           */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* Provision Loss Of Frame for N40G block for 3ms given         */
/* the traffic type and fec                                     */
/*                                                              */
/* [module_id] parameter specifies line's module ID             */
/* 16 devices can be registered and module bit indicates line   */
/* or client side of the registered device. The registered      */
/* device is identified by the dev_id bits specified below      */
/*   Bits 11:8 – dev_id, Bits 7:1 – don’t care, Bit 0 – module  */
/*                                                              */
/* [traffic_type] parameter specifies the traffic type          */
/*   TEN_TRAFFIC_TYPE_OTU3  = 1                                 */
/*   TEN_TRAFFIC_TYPE_OTU3E = 2                                 */
/*   TEN_TRAFFIC_TYPE_OTU3P = 3                                 */
/*   TEN_TRAFFIC_TYPE_OTU3_NOFEC = 19                           */
/*   TEN_TRAFFIC_TYPE_OTU3E3 = 23                               */
/*   TEN_TRAFFIC_TYPE_OTU3P2 = 25                               */
/*   TEN_TRAFFIC_TYPE_OC768_OTU3 = 32                           */
/*   TEN_TRAFFIC_TYPE_OTU3E2 = 35                               */
/*   TEN_TRAFFIC_TYPE_OTU3E4 = 55                               */
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
/*   TEN_FEC_MODE_NOFEC             = 15   (FEC not present).   */
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
  cs_char8 *func = "ten_hl_n40g_config_lof_from_traffic";  

  TEN_MOD_COMMON_VALIDATE (module_id, pDev, CS_ERROR);

  if ((traffic_type != TEN_TRAFFIC_TYPE_OTU3) && (traffic_type != TEN_TRAFFIC_TYPE_OTU3E) && 
      (traffic_type != TEN_TRAFFIC_TYPE_OTU3P) && (traffic_type != TEN_TRAFFIC_TYPE_OTU3_NOFEC) &&
      (traffic_type != TEN_TRAFFIC_TYPE_OTU3E3) && (traffic_type != TEN_TRAFFIC_TYPE_OTU3P2) &&
      (traffic_type != TEN_TRAFFIC_TYPE_OC768_OTU3) && (traffic_type != TEN_TRAFFIC_TYPE_OTU3E2) &&
      (traffic_type != TEN_TRAFFIC_TYPE_OTU3E4)) {     /* Bugzilla 28237 */
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, "%s() traffic_type %d out of range.", func, traffic_type);
    return (CS_ERROR);
  }    

  if (fec >= (TEN_FEC_MODE_MAX_NUM)) { 
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, "%s() fec %d out of range.  s/b 0..%d.", func, fec, (TEN_FEC_MODE_MAX_NUM-2));
    return (CS_ERROR);
  }

  CS_PRINT("%s() %s, %s, %s\n",
           func,
           ten_module_strings[module_id & 1],
           ten_hl_config_traffic_types_strings[traffic_type],
           ten_fec_ovhd_strings[fec]);

  /* Get signal rate on line */
  signal_rate = ten_calculate_signal_rate (traffic_type, fec);
  CS_PRINT("%s() signal_rate = %f\n", func, signal_rate);

  if (signal_rate == 0) {
    /* Line signal rate could not be found */
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, "%s() Traffic %s with fec %s not supported", 
                  func, ten_hl_config_traffic_types_strings[traffic_type], ten_fec_ovhd_strings[fec]);
    return (CS_ERROR);
  }

  rtn |= ten_hl_n40g_config_lof_from_bps (module_id, signal_rate);

  return (rtn);
}

/* Bugzilla 31127 End */

/****************************************************************/
/* $rtn_hdr_start  HIGH LEVEL N40G CONFIG LOM FROM BPS          */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : HIGH LEVEL CONFIG                               */
/* CHIP       : Tenabo                                          */
cs_status ten_hl_n40g_config_lom_from_bps(cs_uint16 module_id, 
                                          double signal_rate)
/* INPUTS     : o Module Id                                     */
/*              o Signal Rate                                   */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* Provision Loss Of Multiframe for N40G block for 3ms given    */
/* Bits Per Second.                                             */
/*                                                              */
/* NOTE:  N40G_OOHR_LOMCFG0::TDELON is actually calculated      */
/*   from sys clock, not signal rate.  This API automatically   */
/*   performs the calculation based on sys clock instead of     */
/*   signal_rate.                                               */
/*   N40G_OOHR_LOMCFG1.bf.TDELOFF is set to 1.                  */
/*                                                              */
/* [module_id] parameter specifies line's module ID             */
/* 16 devices can be registered and module bit indicates line   */
/* or client side of the registered device. The registered      */
/* device is identified by the dev_id bits specified below:     */
/*   Bits 11:8 – dev_id, Bits 7:1 – don’t care, Bit 0 – module  */
/*                                                              */
/* [signal_rate] parameter specifies line Bits Per Second       */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  cs_uint16 tdel_on;
  T41_t *pDev = NULL;
  cs_status rtn = CS_OK;
  cs_char8 *func = "ten_hl_n40g_config_lom_from_bps";  
  ten_dev_cb_t *pdevcb;
  double temp_tdel_on_double;
  
  TEN_MOD_COMMON_VALIDATE (module_id, pDev, CS_ERROR);

  CS_PRINT("%s(), %s, %f\n",
           func,
           ten_module_strings[module_id & 1],
           signal_rate);

  /* Bugzilla #31390, calculate N40G_OOHR_LOMCFG0 from sysclk instead of signal rate */
  pdevcb = TEN_DEV_ID_TO_DEVCB_PTR(TEN_MOD_ID_TO_DEV_ID(module_id));
  CS_PRINT("sysclk = %d\n", pdevcb->sysclock);
  
  /* Compute 3ms = OOHR_LOMCFG0:TDELON * 2040 x T_system_clock from DS 2.6.9.5 Multiframe Alignment Signal (MFAS) */
  temp_tdel_on_double = (0.003 * pdevcb->sysclock)/2040.0;
  temp_tdel_on_double += 0.5;  /* to round 0.5 up to 1.0 */
  CS_PRINT("temp_tdel_on_double = %f\n", temp_tdel_on_double);
  tdel_on = (cs_uint16)temp_tdel_on_double;
  
  CS_PRINT("tdel_on = %d\n", tdel_on);

  /* Bugzilla #30251, fix bus errors on T40 */
  if (ten_dev_is_t41(TEN_MOD_ID_TO_DEV_ID(module_id))) {
    rtn |= ten_n40g_oohr_lomcfg_tdelon_tdeloff(module_id, tdel_on, 1);  /* Bugzilla 31127 */

    /* the consequent actions based on LOM will be driven from the filtered FLOM instead of the unfiltered one. */
    rtn |= ten_n40g_oohr_cfg11_flomen(module_id, 1);
  }
  
  /* Provision MFAS De-Synchronization and Synchronization hysteresis */
  rtn |= ten_n40g_oohr_cfg0 (module_id, 5, 2); /* mfdsyh, mfsyhy */
  return (rtn);
}
/* Bugzilla 24956 End */

/* Bugzilla 31209 Start */
/****************************************************************/
/* $rtn_hdr_start  HIGH LEVEL N40G CONFIG LOS OF FRAME OBFA2 FROM BPS */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : HIGH LEVEL CONFIG                               */
/* CHIP       : Tenabo                                          */
cs_status ten_hl_n40g_config_lof_obfa2_from_bps (cs_uint16 module_id, 
                                                 double signal_rate)
/* INPUTS     : o Module Id                                     */
/*              o Signal Rate                                   */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* Provision Loss Of frame for N40G block OBFA2 for 3ms given   */
/* Bits Per Second                                              */
/*                                                              */
/* [module_id] parameter specifies line's module ID             */
/* 16 devices can be registered and module bit indicates line   */
/* or client side of the registered device. The registered      */
/* device is identified by the dev_id bits specified below      */
/*   Bits 11:8 – dev_id, Bits 7:1 – don’t care, Bit 0 – module  */
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
  cs_char8 *func = "ten_hl_n40g_config_lof_obfa2_from_bps";  

  TEN_MOD_COMMON_VALIDATE (module_id, pDev, CS_ERROR);

  CS_PRINT("%s(), %s, %f\n",
           func,
           ten_module_strings[module_id & 1],
           signal_rate);

  /* Compute Time Delay: tdel = (signal rate/261120) * 0.003s */
  /* Half of a tdel unit is added to signal rate before the devide to round 0.5 up to 1. Half = (261120/(2*0.003))*/
  temp_tdel_on_off = ((signal_rate + (261120/(2*0.003))) / (261120/0.003));
  CS_PRINT("%s() temp_tdel_on_off = %d\n", func, temp_tdel_on_off);
  tdel_on_off = (cs_uint16)temp_tdel_on_off;
  CS_PRINT("%s() tdel_on_off = %d\n", func, tdel_on_off);

  rtn |= ten_n40g_otnr4x_obfa2_lofcfg_tdelon_tdeloff (module_id, tdel_on_off, tdel_on_off);

  return (rtn);
}

/****************************************************************/
/* $rtn_hdr_start  HIGH LEVEL N40G CONFIG LOS OF FRAME FOR OBFA2 */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : HIGH LEVEL CONFIG                               */
/* CHIP       : Tenabo                                          */
cs_status ten_hl_n40g_config_lof_obfa2_from_traffic (cs_uint16 module_id, 
                                               cs_uint16 traffic_type,
                                               cs_uint16 fec)
/* INPUTS     : o Module Id                                     */
/*              o Traffic Type                                  */
/*              o Fec                                           */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* Provision Loss Of Frame for N40G OBFA2 block for 3ms         */
/* given the traffic type and fec                               */
/*                                                              */
/* [module_id] parameter specifies line's module ID             */
/* 16 devices can be registered and module bit indicates line   */
/* or client side of the registered device. The registered      */
/* device is identified by the dev_id bits specified below      */
/*   Bits 11:8 – dev_id, Bits 7:1 – don’t care, Bit 0 – module  */
/*                                                              */
/* [traffic_type] parameter specifies the traffic type          */
/*   TEN_TRAFFIC_TYPE_OTU3  = 1                                 */
/*   TEN_TRAFFIC_TYPE_OTU3E = 2                                 */
/*   TEN_TRAFFIC_TYPE_OTU3P = 3                                 */
/*   TEN_TRAFFIC_TYPE_OTU3_NOFEC = 19                           */
/*   TEN_TRAFFIC_TYPE_OTU3E3 = 23                               */
/*   TEN_TRAFFIC_TYPE_OTU3P2 = 25                               */
/*   TEN_TRAFFIC_TYPE_OC768_OTU3 = 32                           */
/*   TEN_TRAFFIC_TYPE_OTU3E2 = 35                               */
/*   TEN_TRAFFIC_TYPE_OTU3E4 = 55                               */
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
/*   TEN_FEC_MODE_NOFEC             = 15,  (FEC not present).   */
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
  cs_char8 *func = "ten_hl_n40g_config_lof_obfa2_from_traffic";  

  TEN_MOD_COMMON_VALIDATE (module_id, pDev, CS_ERROR);

  if ((traffic_type != TEN_TRAFFIC_TYPE_OTU3) && (traffic_type != TEN_TRAFFIC_TYPE_OTU3E) && 
      (traffic_type != TEN_TRAFFIC_TYPE_OTU3P) && (traffic_type != TEN_TRAFFIC_TYPE_OTU3_NOFEC) &&
      (traffic_type != TEN_TRAFFIC_TYPE_OTU3E3) && (traffic_type != TEN_TRAFFIC_TYPE_OTU3P2) &&
      (traffic_type != TEN_TRAFFIC_TYPE_OC768_OTU3) && (traffic_type != TEN_TRAFFIC_TYPE_OTU3E2) &&
      (traffic_type != TEN_TRAFFIC_TYPE_OTU3E4)) {     /* Bugzilla 28237 */
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, "%s() traffic_type %d out of range.", func, traffic_type);
    return (CS_ERROR);
  }    

  if (fec >= (TEN_FEC_MODE_MAX_NUM)) { 
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, "%s() fec %d out of range.  s/b 0..%d.", func, fec, (TEN_FEC_MODE_MAX_NUM-1));
    return (CS_ERROR);
  }

  CS_PRINT("%s() %s, %s, %s\n",
           func,
           ten_module_strings[module_id & 1],
           ten_hl_config_traffic_types_strings[traffic_type],
           ten_fec_ovhd_strings[fec]);

  /* Get signal rate on line */
  signal_rate = ten_calculate_signal_rate (traffic_type, fec);
  CS_PRINT("%s() signal_rate = %f\n", func, signal_rate);

  if (signal_rate == 0) {
    /* Line signal rate could not be found */
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, "%s() Traffic %s with fec %s not supported", 
                  func, ten_hl_config_traffic_types_strings[traffic_type], ten_fec_ovhd_strings[fec]);
    return (CS_ERROR);
  }

  rtn |= ten_hl_n40g_config_lof_obfa2_from_bps (module_id, signal_rate);

  return (rtn);
}

/****************************************************************/
/* $rtn_hdr_start  HIGH LEVEL N40G CONFIG LOS OF MULTIFRAME OBFA2 FROM BPS */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : HIGH LEVEL CONFIG                               */
/* CHIP       : Tenabo                                          */
cs_status ten_hl_n40g_config_lom_obfa2_from_bps (cs_uint16 module_id, 
                                                 double signal_rate)
/* INPUTS     : o Module Id                                     */
/*              o Signal Rate                                   */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* Provision Loss Of Multiframe for N40G block OBFA2 for 3ms    */
/* given Bits Per Second                                        */
/* N40G_OTNRX4X_OBFA2_LOMCFG1.bf.TDELOFF is set to 1.           */
/*                                                              */
/* [module_id] parameter specifies line's module ID             */
/* 16 devices can be registered and module bit indicates line   */
/* or client side of the registered device. The registered      */
/* device is identified by the dev_id bits specified below      */
/*   Bits 11:8 – dev_id, Bits 7:1 – don’t care, Bit 0 – module  */
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
  cs_char8 *func = "ten_hl_n40g_config_lom_obfa2_from_bps";  

  TEN_MOD_COMMON_VALIDATE (module_id, pDev, CS_ERROR);

  CS_PRINT("%s(), %s, %f\n",
           func,
           ten_module_strings[module_id & 1],
           signal_rate);

  /* Compute Time Delay: tdel = (signal rate/261120) * 0.003s */
  /* Half of a tdel unit is added to signal rate before the devide to round 0.5 up to 1. Half = (261120/(2*0.003))*/
  temp_tdel_on_off = ((signal_rate + (261120/(2*0.003))) / (261120/0.003));
  CS_PRINT("temp_tdel_on_off = %d\n", temp_tdel_on_off);
  tdel_on_off = (cs_uint16)temp_tdel_on_off;
  CS_PRINT("tdel_on_off = %d\n", tdel_on_off);

  /* Bugzilla #31390, set tdeloff to 1 */
  rtn |= ten_n40g_otnr4x_obfa2_lomcfg_tdelon_tdeloff (module_id, tdel_on_off, 1);

  return (rtn);
}

/****************************************************************/
/* $rtn_hdr_start  HIGH LEVEL N40G CONFIG LOS OF MULTIFRAME FOR OBFA2 */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : HIGH LEVEL CONFIG                               */
/* CHIP       : Tenabo                                          */
cs_status ten_hl_n40g_config_lom_obfa2_from_traffic (cs_uint16 module_id, 
                                               cs_uint16 traffic_type,
                                               cs_uint16 fec)
/* INPUTS     : o Module Id                                     */
/*              o Traffic Type                                  */
/*              o Fec                                           */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* Provision Loss Of Multiframe for N40G OBFA2 block for 3ms    */
/* given the traffic type and fec                               */
/*                                                              */
/* [module_id] parameter specifies line's module ID             */
/* 16 devices can be registered and module bit indicates line   */
/* or client side of the registered device. The registered      */
/* device is identified by the dev_id bits specified below      */
/*   Bits 11:8 – dev_id, Bits 7:1 – don’t care, Bit 0 – module  */
/*                                                              */
/* [traffic_type] parameter specifies the traffic type          */
/*   TEN_TRAFFIC_TYPE_OTU3  = 1                                 */
/*   TEN_TRAFFIC_TYPE_OTU3E = 2                                 */
/*   TEN_TRAFFIC_TYPE_OTU3P = 3                                 */
/*   TEN_TRAFFIC_TYPE_OTU3_NOFEC = 19                           */
/*   TEN_TRAFFIC_TYPE_OTU3E3 = 23                               */
/*   TEN_TRAFFIC_TYPE_OTU3P2 = 25                               */
/*   TEN_TRAFFIC_TYPE_OC768_OTU3 = 32                           */
/*   TEN_TRAFFIC_TYPE_OTU3E2 = 35                               */
/*   TEN_TRAFFIC_TYPE_OTU3E4 = 55                               */
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
/*   TEN_FEC_MODE_NOFEC             = 15   (FEC not present).   */
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
  cs_char8 *func = "ten_hl_n40g_config_lom_obfa2_from_traffic";  

  TEN_MOD_COMMON_VALIDATE (module_id, pDev, CS_ERROR);

  if ((traffic_type != TEN_TRAFFIC_TYPE_OTU3) && (traffic_type != TEN_TRAFFIC_TYPE_OTU3E) && 
      (traffic_type != TEN_TRAFFIC_TYPE_OTU3P) && (traffic_type != TEN_TRAFFIC_TYPE_OTU3_NOFEC) &&
      (traffic_type != TEN_TRAFFIC_TYPE_OTU3E3) && (traffic_type != TEN_TRAFFIC_TYPE_OTU3P2) &&
      (traffic_type != TEN_TRAFFIC_TYPE_OC768_OTU3) && (traffic_type != TEN_TRAFFIC_TYPE_OTU3E2) &&
      (traffic_type != TEN_TRAFFIC_TYPE_OTU3E4)) {     /* Bugzilla 28237 */
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, "%s() traffic_type %d out of range.", func, traffic_type);
    return (CS_ERROR);
  }    

  if (fec >= (TEN_FEC_MODE_MAX_NUM)) { 
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, "%s() fec %d out of range.  s/b 0..%d.", func, fec, (TEN_FEC_MODE_MAX_NUM-1));
    return (CS_ERROR);
  }

  CS_PRINT("%s() %s, %s, %s\n",
           func,
           ten_module_strings[module_id & 1],
           ten_hl_config_traffic_types_strings[traffic_type],
           ten_fec_ovhd_strings[fec]);

  /* Get signal rate on line */
  signal_rate = ten_calculate_signal_rate (traffic_type, fec);
  CS_PRINT("%s() signal_rate = %f\n", func, signal_rate);

  if (signal_rate == 0) {
    /* Line signal rate could not be found */
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, "%s() Traffic %s with fec %s not supported", 
                  func, ten_hl_config_traffic_types_strings[traffic_type], ten_fec_ovhd_strings[fec]);
    return (CS_ERROR);
  }

  rtn |= ten_hl_n40g_config_lom_obfa2_from_bps (module_id, signal_rate);

  return (rtn);
}
/* Bugzilla 31209 End */

/* Bugzilla 26565 start */
/****************************************************************/
/* $rtn_hdr_start  N40G 10G JUSTIFICATION CONTROL FOR MUXPONDER */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : HIGH LEVEL CONFIG                               */
/* CHIP       : Tenabo                                          */
cs_status ten_hl_n40g_mux_just_control (cs_uint16 module_id,
                                        cs_uint8 slice,
                                        cs_uint8 jcen,
                                        cs_uint8 jc_plus)
/* INPUTS     : o Module Id                                     */
/*              o Slice                                         */
/*              o Justification Enable                          */
/*              o Justification Plus Enable                     */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* For Muxponders, sets up 10G slice justification              */
/* configuration on the N40G. Sets up RX and TX.                */
/*                                                              */
/* [module_id] parameter specifies line's module ID             */
/*                                                              */
/* The [slice] parameter is specified as:                       */
/*   0x00 = TEN_SLICE0                                          */
/*   0x01 = TEN_SLICE1                                          */
/*   0x02 = TEN_SLICE2                                          */
/*   0x03 = TEN_SLICE3                                          */
/*   0xFF = TEN_SLICE_ALL                                       */
/*                                                              */
/* The [jcen] parameter is specified as:                        */
/*   TRUE  (1)  Enables justification                           */
/*   FALSE (0)  Disables justification                           */
/*                                                              */
/* The [jc_plus] parameter is specified as:                     */
/*   TRUE  (1)  Enables cortina-enhanced justification          */
/*   FALSE (0)  Disables cortina-enhanced justification         */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  TEN_N40G_OTNR4X_ODWCFG1_t tmp_otnr4x_odwcfg1;
  TEN_N40G_OTNT4X_WRPCFG4_t tmp_otnt4x_wrpcfg4;
  T41_t *pDev = NULL;
  cs_uint8 jcen_slice_map   = 0x0F;   /* default value 0x0F used only if TEN_SLICE_ALL */
  cs_uint8 jcplus_slice_map = 0x0F;   /* default value 0x0F used only if TEN_SLICE_ALL */

  cs_char8 *func = "ten_hl_n40g_mux_just_control";  

  TEN_MOD_COMMON_VALIDATE (module_id, pDev, CS_ERROR);

  CS_PRINT("%s(), Mod %d, Slice %d, jcen %s, jcplus%s\n",
           func, module_id, slice,
           ( (jcen==0)    ? "disabled" : "enabled"), 
           ( (jc_plus==0) ? "disabled" : "enabled") );

  /* set up bit masking */
  if (slice!=TEN_SLICE_ALL) {
    jcen_slice_map   = 1 << slice;
    jcplus_slice_map = jcen_slice_map;
  }

  /* negate if disabling, to clear reg bit(s) */
  if (jcen == 0)    jcen_slice_map   = ~jcen_slice_map;   
  if (jc_plus == 0) jcplus_slice_map = ~jcplus_slice_map;

  TEN_MOD_LOCK(module_id, TEN_ID_N40G);

  /* RX */
  tmp_otnr4x_odwcfg1.wrd = TEN_REG_READ(TEN_N40G_REG_ADDR(pDev, module_id, ODWCFG1));
  tmp_otnr4x_odwcfg1.bf.JC_ENABLE =    (jcen) ? (jcen_slice_map   | tmp_otnr4x_odwcfg1.bf.JC_ENABLE) : (jcen_slice_map & tmp_otnr4x_odwcfg1.bf.JC_ENABLE);
  tmp_otnr4x_odwcfg1.bf.JC_PLUS   = (jc_plus) ? (jcplus_slice_map | tmp_otnr4x_odwcfg1.bf.JC_PLUS)   : (jcplus_slice_map & tmp_otnr4x_odwcfg1.bf.JC_PLUS);
  TEN_REG_WRITE(TEN_N40G_REG_ADDR(pDev, module_id, ODWCFG1), tmp_otnr4x_odwcfg1.wrd);

  /* TX */
  tmp_otnt4x_wrpcfg4.wrd = TEN_REG_READ(TEN_N40G_REG_ADDR(pDev, module_id, WRPCFG4));
  tmp_otnt4x_wrpcfg4.bf.JCEN    =    (jcen) ? (jcen_slice_map | tmp_otnt4x_wrpcfg4.bf.JCEN) : (jcen_slice_map & tmp_otnt4x_wrpcfg4.bf.JCEN);
  tmp_otnt4x_wrpcfg4.bf.JC_PLUS = (jc_plus) ?  1 : 0;
  TEN_REG_WRITE(TEN_N40G_REG_ADDR(pDev, module_id, WRPCFG4), tmp_otnt4x_wrpcfg4.wrd);

  TEN_MOD_UNLOCK(module_id, TEN_ID_N40G);

  return (CS_OK);
}

/********************************************************************/
/* Function: ten_get_n40g_reg_addr()                                */
/********************************************************************/
/* For Bugzilla 28734:                                              */
/* Gets the address of an n40g register.                            */
/*                                                                  */
/* Used by macro TEN_N40G_REG_ADDR. Given the base address of a     */
/* non-common n40g register as defined in t41_registers.h, and      */
/* its instance number (0..TEN_N40G_COUNT-1), calculates the        */
/* offset and adds it to the base register's address.               */
/********************************************************************/
volatile cs_reg *ten_get_n40g_reg_addr( cs_reg   *pReg,
                                                  cs_uint16 instance )
{
  if (instance >= TEN_N40G_COUNT) {
    CS_HNDL_ERROR(0, ETEN_DEV_INVALID_USER_ARG,
                  "n40g instance %d out of range. S/b < TEN_N40G_COUNT.",
                  instance);
    instance = 0;
  }
  return (pReg + instance * TEN_N40G_STRIDE);
}

