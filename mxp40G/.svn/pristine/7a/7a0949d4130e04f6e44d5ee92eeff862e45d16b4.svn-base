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
 * ten_hl_ohpp.c
 *
 * API's for OHPP high level configuration.
 *
 * $Id: ten_hl_ohpp.c,v 1.21 2013/07/02 18:44:26 khill Exp $
 *
 */
 
#include "tenabo40.h"

const cs_char8 *ten_consequent_actions_str[TEN_CONSEQUENT_ACTION_ROW_COUNT] = {
  "Maintenance signal insertion for OxU3",
  "Maintenance signal insertion for OxU2 channel 1",
  "Maintenance signal insertion for OxU2 channel 2",
  "Maintenance signal insertion for OxU2 channel 3",
  "Maintenance signal insertion for OxU2 channel 4",
  "OTN PM BDI control for OxU3",
  "OTN TCM1 BDI control for OxU3",
  "OTN TCM2 BDI control for OxU3",
  "OTN TCM3 BDI control for OxU3",
  "OTN TCM4 BDI control for OxU3",
  "OTN TCM5 BDI control for OxU3",
  "OTN TCM6 BDI control for OxU3",
  "OTN SM BDI control for OxU3",
  "OTN PM BDI control for OxU2 channel 1",
  "OTN TCM1 BDI control for OxU2 channel 1",
  "OTN TCM2 BDI control for OxU2 channel 1",
  "OTN TCM3 BDI control for OxU2 channel 1",
  "OTN TCM4 BDI control for OxU2 channel 1",
  "OTN TCM5 BDI control for OxU2 channel 1",
  "OTN TCM6 BDI control for OxU2 channel 1",
  "OTN SM BDI control for OxU2 channel 1",
  "OTN PM BDI control for OxU2 channel 2",
  "OTN TCM1 BDI control for OxU2 channel 2",
  "OTN TCM2 BDI control for OxU2 channel 2",
  "OTN TCM3 BDI control for OxU2 channel 2",
  "OTN TCM4 BDI control for OxU2 channel 2",
  "OTN TCM5 BDI control for OxU2 channel 2",
  "OTN TCM6 BDI control for OxU2 channel 2",
  "OTN SM BDI control for OxU2 channel 2",
  "OTN PM BDI control for OxU2 channel 3",
  "OTN TCM1 BDI control for OxU2 channel 3",
  "OTN TCM2 BDI control for OxU2 channel 3",
  "OTN TCM3 BDI control for OxU2 channel 3",
  "OTN TCM4 BDI control for OxU2 channel 3",
  "OTN TCM5 BDI control for OxU2 channel 3",
  "OTN TCM6 BDI control for OxU2 channel 3",
  "OTN SM BDI control for OxU2 channel 3",
  "OTN PM BDI control for OxU2 channel 4",
  "OTN TCM1 BDI control for OxU2 channel 4",
  "OTN TCM2 BDI control for OxU2 channel 4",
  "OTN TCM3 BDI control for OxU2 channel 4",
  "OTN TCM4 BDI control for OxU2 channel 4",
  "OTN TCM5 BDI control for OxU2 channel 4",
  "OTN TCM6 BDI control for OxU2 channel 4",
  "OTN SM BDI control for OxU2 channel 4",
  "OTN IAE control for OxU3",
  "OTN IAE control for OxU2 channel 1",
  "OTN IAE control for OxU2 channel 2",
  "OTN IAE control for OxU2 channel 3",
  "OTN IAE control for OxU2 channel 4",
  "OxU3-AIS (OxU3-PN11) insertion control",
  "OxU2-AIS (OxU2-PN11) insertion control for channel 1",
  "OxU2-AIS (OxU2-PN11) insertion control for channel 2",
  "OxU2-AIS (OxU2-PN11) insertion control for channel 3",
  "OxU2-AIS (OxU2-PN11) insertion control for channel 4",
  "OxU3 CBRGenk-AIS payload insertion",
  "OxU2 CBRGenk-AIS payload insertion for channel 1",
  "OxU2 CBRGenk-AIS payload insertion for channel 2",
  "OxU2 CBRGenk-AIS payload insertion for channel 3",
  "OxU2 CBRGenk-AIS payload insertion for channel 4",
  "RDI insertion for OC-192 channel 1",
  "RDI insertion for OC-192 channel 2",
  "RDI insertion for OC-192 channel 3",
  "RDI insertion for OC-192 channel 4",
  "Multiplex Section AIS insertion for OC-192 channel 1",
  "Multiplex Section AIS insertion for OC-192 channel 2",
  "Multiplex Section AIS insertion for OC-192 channel 3",
  "Multiplex Section AIS insertion for OC-192 channel 4",
  "General Purpose Signaling Binary Inserter 0",
  "General Purpose Signaling Binary Inserter 1",
  "General Purpose Signaling Binary Inserter 2",
  "General Purpose Signaling Binary Inserter 3",
  "General Purpose Signaling Binary Inserter 4",
  "General Purpose Signaling Binary Inserter 5",
  "General Purpose Signaling Binary Inserter 6",
  "General Purpose Signaling Binary Inserter 7",
  "General Purpose Signaling Binary Inserter 8",
  "General Purpose Signaling Binary Inserter 9"
};

const cs_char8 *ten_consequent_action_events_global_str[TEN_CONSEQUENT_ACTION_EVENT_GLOBAL_COUNT] = {
  "External LOS detection status on receive MultiRate 10G tributary 1",
  "External LOS detection status on receive MultiRate 10G tributary 2",
  "External LOS detection status on receive MultiRate 10G tributary 3",
  "External LOS detection status on receive MultiRate 10G tributary 4",
  "External LOS detection status on receive XFI 10G tributary 1",
  "External LOS detection status on receive XFI 10G tributary 2",
  "External LOS detection status on receive XFI 10G tributary 3",
  "External LOS detection status on receive XFI 10G tributary 4",
  "Clock failure detected on receive 10G tributary 1",
  "Clock failure detected on receive 10G tributary 2",
  "Clock failure detected on receive 10G tributary 3",
  "Clock failure detected on receive 10G tributary 4",
  "Clock failure detected on transmit 10G tributary 1",
  "Clock failure detected on transmit 10G tributary 2",
  "Clock failure detected on transmit 10G tributary 3",
  "Clock failure detected on transmit 10G tributary 4",
  "Filtered lock detect failure on receive Multi-Rate 10G tributary 1",
  "Filtered lock detect failure on receive Multi-Rate 10G tributary 2",
  "Filtered lock detect failure on receive Multi-Rate 10G tributary 3",
  "Filtered lock detect failure on receive Multi-Rate 10G tributary 4",
  "Filtered lock detect failure on transmit Multi-Rate 10G tributary 1",
  "Filtered lock detect failure on transmit Multi-Rate 10G tributary 2",
  "Filtered lock detect failure on transmit Multi-Rate 10G tributary 3",
  "Filtered lock detect failure on transmit Multi-Rate 10G tributary 4",
  "Filtered lock detect failure on receive XFI 10G tributary 1",
  "Filtered lock detect failure on receive XFI 10G tributary 2",
  "Filtered lock detect failure on receive XFI 10G tributary 3",
  "Filtered lock detect failure on receive XFI 10G tributary 4",
  "Filtered lock detect failure on transmit XFI 10G tributary 1",
  "Filtered lock detect failure on transmit XFI 10G tributary 2",
  "Filtered lock detect failure on transmit XFI 10G tributary 3",
  "Filtered lock detect failure on transmit XFI 10G tributary 4",
  "Justification generator out of range for 10G tributary 1",
  "Justification generator out of range for 10G tributary 2",
  "Justification generator out of range for 10G tributary 3",
  "Justification generator out of range for 10G tributary 4",
  "Phase detector out of range for 10G tributary 1",
  "Phase detector out of range for 10G tributary 2",
  "Phase detector out of range for 10G tributary 3",
  "Phase detector out of range for 10G tributary 4"
};

const cs_char8 *ten_consequent_action_events_oxux_str[TEN_CONSEQUENT_ACTION_EVENT_OXUX_COUNT] = {
  "Signal degrade condition detected based on FEC decoder statistics",
  "Excessive error defect (or signal fail) detected based on FEC decoder statistics",
  "Trace Identifier Mismatch condition was detected and reported in dTIM0",
  "Trace Identifier Mismatch condition was detected and reported in dTIM1",
  "Trace Identifier Mismatch condition was detected and reported in dTIM2",
  "Trace Identifier Mismatch condition was detected and reported in dTIM3",
  "Trace Identifier Mismatch condition was detected and reported in dTIM4",
  "Trace Identifier Mismatch condition was detected and reported in dTIM5",
  "Trace Identifier Mismatch condition was detected and reported in dTIM6",
  "Trace Identifier Mismatch condition was detected and reported in dTIM7",
  "PN-11 (OxUk-AIS) pattern detected",
  "Status of internal LOS detector",
  "MFAS aligner in OxU2 terminator is in LOM state",
  "Aligner remains in LOF state",
  "Aligner is in OOF state",
  "Last received FAW was corrupted according to the aligner configuration",
  "Section: Detected Incoming Alignment Error",
  "Section: Detected Backward Defect Indication",
  "Section: Detected Backward Incoming Alignment Error",
  "Path: Detected Lock",
  "Path: Detected Open Connection Indication",
  "Path: Detected Backward Defect Indication",
  "Path: Detected ODU Alarm Indication Signal",
  "Payload: Detected Mulitplex Structure Identifier Mismatch",
  "Payload: Detected PayLoad Mismatch",
  "Payload: Detected CBR Generic Alarm Indication Signal",
  "TCM1: Detected Lock",
  "TCM1: Detected Open Connection Indication",
  "TCM1: Detected Incoming Alignment Error",
  "TCM1: Detected Backward Defect Indication",
  "TCM1: Detected ODU Alarm Indication Signal",
  "TCM1: Detected Backward Incoming Alignment Error",
  "TCM1: Detected Loss of Tandem Connection",
  "TCM2: Detected Lock",
  "TCM2: Detected Open Connection Indication",
  "TCM2: Detected Incoming Alignment Error",
  "TCM2: Detected Backward Defect Indication",
  "TCM2: Detected ODU Alarm Indication Signal",
  "TCM2: Detected Backward Incoming Alignment Error",
  "TCM2: Detected Loss of Tandem Connection",
  "TCM3: Detected Lock",
  "TCM3: Detected Open Connection Indication",
  "TCM3: Detected Incoming Alignment Error",
  "TCM3: Detected Backward Defect Indication",
  "TCM3: Detected ODU Alarm Indication Signal",
  "TCM3: Detected Backward Incoming Alignment Error",
  "TCM3: Detected Loss of Tandem Connection",
  "TCM4: Detected Lock",
  "TCM4: Detected Open Connection Indication",
  "TCM4: Detected Incoming Alignment Error",
  "TCM4: Detected Backward Defect Indication",
  "TCM4: Detected ODU Alarm Indication Signal",
  "TCM4: Detected Backward Incoming Alignment Error",
  "TCM4: Detected Loss of Tandem Connection",
  "TCM5: Detected Lock",
  "TCM5: Detected Open Connection Indication",
  "TCM5: Detected Incoming Alignment Error",
  "TCM5: Detected Backward Defect Indication",
  "TCM5: Detected ODU Alarm Indication Signal",
  "TCM5: Detected Backward Incoming Alignment Error",
  "TCM5: Detected Loss of Tandem Connection",
  "TCM6: Detected Lock",
  "TCM6: Detected Open Connection Indication",
  "TCM6: Detected Incoming Alignment Error",
  "TCM6: Detected Backward Defect Indication",
  "TCM6: Detected ODU Alarm Indication Signal",
  "TCM6: Detected Backward Incoming Alignment Error",
  "TCM6: Detected Loss of Tandem Connection",
  "Signal degrade status from BIP-8 processor 0",
  "Signal degrade status from BIP-8 processor 1",
  "Signal degrade status from BIP-8 processor 2",
  "Signal degrade status from BIP-8 processor 3",
  "Signal degrade status from BIP-8 processor 4",
  "Signal degrade status from BIP-8 processor 5",
  "Signal degrade status from BIP-8 processor 6",
  "Signal degrade status from BIP-8 processor 7",
  "Result of the match against CMP1, as selected in OOHR_GAFCMP1:GC1MSK",
  "Result of the match against CMP2, as selected in OOHR_GAFCMP2:GC2MSK",
  "Result of the match against CMP3, as selected in OOHR_GAFCMP3:GC3MSK",
  "Result of the match against CMP4, as selected in OOHR_GAFCMP4:GC4MSK",
  "Result of the match against CMP5, as selected in OOHR_GAFCMP5:GC5MSK",
  "Result of the match against CMP6, as selected in OOHR_GAFCMP6:GC6MSK",
  "Result of the match against CMP7, as selected in OOHR_GAFCMP7:GC7MSK",
  "Result of the match against CMP8, as selected in OOHR_GAFCMP8:GC8MSK"
};

const cs_char8 *ten_consequent_action_events_oc192_str[TEN_CONSEQUENT_ACTION_EVENT_OC192_COUNT] = {
  "Line AIS was detected",
  "Signal Degrade was detected",
  "Signal Fail was detected",
  "J0-based Trace Identifier Mismatch was detected",
  "Loss Of Signal was detected",
  "Out Of Frame was detected",
  "Loss Of Frame was detected",
  "STM-AIS was detected"
};

/* Bugzilla #38149 - update ten_hl_ohpp_dump_sfu API for T41 events  */
const cs_char8 *ten_consequent_action_events_cs604x_oxu3_str[3] = {
  "Low Order Fixed Stuff Mismatch / Cn Out-of-range Status",
  "Detected Loss of Lane Alignment (MLD)",
  "Reserved",
};

const cs_char8 *ten_consequent_action_events_cs604x_oxu2_terminator_channel_actions_str[] = {
  "Low Order Fixed Stuff Mismatch / Cn Out-of-range Status",
  "High Order Fixed Stuff Mismatch for ODTU23 / Cn Out-of-range Status for ODTU2.ts or ODTU3.ts tributary", 
  "High Order MSI Mismatch for ODTU23, ODTU2.ts, or ODTU3.ts tributary"
};

#ifndef TEN_NO_N40G
/****************************************************************/
/* $rtn_hdr_start  FORCE OTU3 AIS                               */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : HIGH LEVEL                                      */
/* CHIP       : Tenabo                                          */
cs_status ten_hl_ohpp_force_otu3_ais(cs_uint16 module_id,
                                     cs_uint16 state)
/* INPUTS     : o Module Id                                     */
/*              o State                                         */
/*                                                              */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* Force an OTU3 AIS (PN-11) on the 40G port via the SFU        */
/* MSignal.                                                     */
/*                                                              */
/* The [state] parameter is specified as:                       */
/*   0 = 40G port behaves normally                              */
/*   1 = 40G port transmits an OTU3 AIS                         */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  cs_status ret_val;

  ret_val = ten_ohpp_sfu_set_msignal(module_id, TEN_CA_OXU3_AIS_PN11_INSERT_CTRL, state);

  return(ret_val);
}
#endif

/****************************************************************/
/* $rtn_hdr_start  FORCE OTU2 AIS                               */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : HIGH LEVEL                                      */
/* CHIP       : Tenabo                                          */
cs_status ten_hl_ohpp_force_otu2_ais(cs_uint16 module_id,
                                     cs_uint8 slice,
                                     cs_uint16 state)
/* INPUTS     : o Module Id                                     */
/*              o Slice                                         */
/*              o State                                         */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* Force an OTU2 AIS (PN-11) on the 10G ports via the SFU       */
/* MSignal.                                                     */
/*                                                              */
/* The [slice] parameter is specified as:                       */
/*   0x00 = TEN_SLICE0                                          */
/*   0x01 = TEN_SLICE1                                          */
/*   0x02 = TEN_SLICE2                                          */
/*   0x03 = TEN_SLICE3                                          */
/*   0xFF = TEN_SLICE_ALL                                       */
/*                                                              */
/* The [state] parameter is specified as:                       */
/*   0 = 10G port behaves normally                              */
/*   1 = 10G port transmits an OTU2 AIS                         */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  cs_status ret_val = CS_OK;
  
  if ((slice>=TEN_MAX_SLICES) && (slice != TEN_SLICE_ALL)) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": slice out of range.  s/b 0..3.");
    return(CS_ERROR);
  }

  if ((slice == TEN_SLICE0) || (slice == TEN_SLICE_ALL)) {
    ret_val = ten_ohpp_sfu_set_msignal(module_id, TEN_CA_OXU2_AIS_PN11_INSERT_CTRL_1, state);
  }

  if (ret_val == CS_ERROR) {
    goto RTN_EXIT;
  }
  else if ((slice == TEN_SLICE1) || (slice == TEN_SLICE_ALL)) {
    ret_val = ten_ohpp_sfu_set_msignal(module_id, TEN_CA_OXU2_AIS_PN11_INSERT_CTRL_2, state);
  }

  if (ret_val == CS_ERROR) {
    goto RTN_EXIT;
  }
  else if ((slice == TEN_SLICE2) || (slice == TEN_SLICE_ALL)) {
    ret_val = ten_ohpp_sfu_set_msignal(module_id, TEN_CA_OXU2_AIS_PN11_INSERT_CTRL_3, state);
  }

  if (ret_val == CS_ERROR) {
    goto RTN_EXIT;
  }
  else if ((slice == TEN_SLICE3) || (slice == TEN_SLICE_ALL)) {
    ret_val = ten_ohpp_sfu_set_msignal(module_id, TEN_CA_OXU2_AIS_PN11_INSERT_CTRL_4, state);
  }

RTN_EXIT:
  return(ret_val);
}

#ifndef TEN_NO_N40G
/* Bugzilla 29609 Start */
/****************************************************************/
/* $rtn_hdr_start  FORCE ODU3 MAINTENANCE SIGNAL                */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : HIGH LEVEL                                      */
/* CHIP       : Tenabo                                          */
cs_status ten_hl_ohpp_force_odu3_maintenance_signal(cs_uint16 module_id,
                                                    cs_uint8 signal,
                                                    cs_uint8 width,
                                                    cs_uint16 state)
/* INPUTS     : o Module Id                                     */
/*              o Signal                                        */
/*              o Width                                         */
/*              o State                                         */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* Force an ODU3 Maintenance Signal on the 40G port via the SFU */
/* MSignal.                                                     */
/*                                                              */
/* The [signal] parameter specifies the signal:                 */
/*   0 = TEN_OHPP_INSERT_ZERO                                   */
/*       Maintenance signal insertion only allowed if OXU21MS   */
/*       is disabled in SFC. If OXU21MS turns active while      */
/*       OMSA1S is set to 00 binary all bytes will be set to    */
/*       00 hex.                                                */
/*   1 = TEN_OHPP_INSERT_AIS                                    */
/*       Insert AIS (all bytes set to FF hex).                  */
/*   2 = TEN_OHPP_INSERT_OCI                                    */
/*       Insert OCI (all bytes set to 66 hex).                  */
/*   3 = TEN_OHPP_INSERT_LCK                                    */
/*       Insert LCK (all bytes set to 55 hex).                  */
/*                                                              */
/* The [width] parameter specifies the signal:                  */
/*   0 = TEN_OHPP_WIDTH_ONLY_PAYLOAD                            */
/*       Fill OPUk payload section only, leaving OTN overhead   */
/*       columns 1 through 16 unmodified.                       */
/*   1 = TEN_OHPP_WIDTH_OH_PAYLOAD                              */
/*       Fill OPUk payload and overhead section, leaving OTN    */
/*       overhead columns 1 through 14 unmodified.              */
/*   2 = TEN_OHPP_WIDTH_FRAME                                   */
/*       Fill complete OTUk frame except for FTFL and OTUk      */
/*       overhead.                                              */
/*                                                              */
/* The [state] parameter is specified as:                       */
/*   0 = 40G port behaves normally                              */
/*   1 = 40G port transmits an ODU3 Maintenance Signal          */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  cs_status ret_val;
  T41_t *pDev = NULL;
  cs_char8 *func = "ten_hl_ohpp_force_odu3_maintenance_signal";  

  if (signal > TEN_OHPP_INSERT_LCK) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, "%s()  signal %d out of range.", func, signal);
    return(CS_ERROR);
  }
  if (width > TEN_OHPP_WIDTH_FRAME) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, "%s()  width %d out of range.", func, width);
    return(CS_ERROR);
  }
  if (state > 1) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, "%s()  state %d out of range.", func, state);
    return(CS_ERROR);
  }

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);

  CS_PRINT("%s() %s, %s, %s state=%d\n", func, ten_module_strings[module_id & 1], 
            ten_ohpp_signals_strings[signal], ten_ohpp_widths_strings[width], state );

  /* Insert the OTU3 signal */
  ret_val = ten_ohpp_sfu_set_msignal(module_id, TEN_CA_MAINT_SIG_INSERT_OXU3, state);
 
  if (state) {
    /* Provison the signal to be inserted for OTU3 */
    ret_val |= ten_ohpp_sfu_insert_otn_maintenance_signal(module_id, signal, width, 5);
  }

  return(ret_val);
}
/* Bugzilla 29609 End */

/****************************************************************/
/* $rtn_hdr_start  ENABLE ODU3 MAINTENANCE SIGNAL               */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : HIGH LEVEL                                      */
/* CHIP       : Tenabo                                          */
cs_status ten_hl_ohpp_enable_odu3_maintenance_signal(cs_uint16 module_id,
                                                     cs_uint8 signal,
                                                     cs_uint8 width,
                                                     cs_uint16 state)
/* INPUTS     : o Module Id                                     */
/*              o Signal                                        */
/*              o Width                                         */
/*              o State                                         */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* Enable an ODU3 Maintenance Signal on the 40G port.           */
/*                                                              */
/* The [signal] parameter specifies the signal:                 */
/*   0 = TEN_OHPP_INSERT_ZERO                                   */
/*       Maintenance signal insertion only allowed if OXU21MS   */
/*       is disabled in SFC. If OXU21MS turns active while      */
/*       OMSA1S is set to 00 binary all bytes will be set to    */
/*       00 hex.                                                */
/*   1 = TEN_OHPP_INSERT_AIS                                    */
/*       Insert AIS (all bytes set to FF hex).                  */
/*   2 = TEN_OHPP_INSERT_OCI                                    */
/*       Insert OCI (all bytes set to 66 hex).                  */
/*   3 = TEN_OHPP_INSERT_LCK                                    */
/*       Insert LCK (all bytes set to 55 hex).                  */
/*                                                              */
/* The [width] parameter specifies the signal:                  */
/*   0 = TEN_OHPP_WIDTH_ONLY_PAYLOAD                            */
/*       Fill OPUk payload section only, leaving OTN overhead   */
/*       columns 1 through 16 unmodified.                       */
/*   1 = TEN_OHPP_WIDTH_OH_PAYLOAD                              */
/*       Fill OPUk payload and overhead section, leaving OTN    */
/*       overhead columns 1 through 14 unmodified.              */
/*   2 = TEN_OHPP_WIDTH_FRAME                                   */
/*       Fill complete OTUk frame except for FTFL and OTUk      */
/*       overhead.                                              */
/*                                                              */
/* The [state] parameter is specified as:                       */
/*   0 = 40G port behaves normally                              */
/*   1 = 40G port transmits an ODU3 Maintenance Signal          */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  cs_status ret_val;

  ret_val = ten_ohpp_sfu_insert_otn_maintenance_signal(module_id, signal, width, 5);

  return(ret_val);
}
#endif

/****************************************************************/
/* $rtn_hdr_start  FORCE ODU2 MAINTENANCE SIGNAL                */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : HIGH LEVEL                                      */
/* CHIP       : Tenabo                                          */
cs_status ten_hl_ohpp_force_odu2_maintenance_signal(cs_uint16 module_id,
                                                    cs_uint8 slice,
                                                    cs_uint8 signal,
                                                    cs_uint8 width,
                                                    cs_uint16 state)
/* INPUTS     : o Module Id                                     */
/*              o Slice                                         */
/*              o Signal                                        */
/*              o Width                                         */
/*              o State                                         */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* Force an ODU2 Maintenance Signal on the 10G ports via the    */
/* SFU MSignal.                                                 */
/*                                                              */
/* The [slice] parameter is specified as:                       */
/*   0x00 = TEN_SLICE0                                          */
/*   0x01 = TEN_SLICE1                                          */
/*   0x02 = TEN_SLICE2                                          */
/*   0x03 = TEN_SLICE3                                          */
/*   0xFF = TEN_SLICE_ALL                                       */
/*                                                              */
/* The [signal] parameter specifies the signal:                 */
/*   0 = TEN_OHPP_INSERT_ZERO                                   */
/*       Maintenance signal insertion only allowed if OXU21MS   */
/*       is disabled in SFC. If OXU21MS turns active while      */
/*       OMSA1S is set to 00 binary all bytes will be set to    */
/*       00 hex.                                                */
/*   1 = TEN_OHPP_INSERT_AIS                                    */
/*       Insert AIS (all bytes set to FF hex).                  */
/*   2 = TEN_OHPP_INSERT_OCI                                    */
/*       Insert OCI (all bytes set to 66 hex).                  */
/*   3 = TEN_OHPP_INSERT_LCK                                    */
/*       Insert LCK (all bytes set to 55 hex).                  */
/*                                                              */
/* The [width] parameter specifies the signal:                  */
/*   0 = TEN_OHPP_WIDTH_ONLY_PAYLOAD                            */
/*       Fill OPUk payload section only, leaving OTN overhead   */
/*       columns 1 through 16 unmodified.                       */
/*   1 = TEN_OHPP_WIDTH_OH_PAYLOAD                              */
/*       Fill OPUk payload and overhead section, leaving OTN    */
/*       overhead columns 1 through 14 unmodified.              */
/*   2 = TEN_OHPP_WIDTH_FRAME                                   */
/*       Fill complete OTUk frame except for FTFL and OTUk      */
/*       overhead.                                              */
/*                                                              */
/* The [state] parameter is specified as:                       */
/*   0 = 10G port behaves normally                              */
/*   1 = 10G port transmits an ODU2 Maintenance Signal          */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  cs_status ret_val = CS_OK;
  
  if ((slice>=TEN_MAX_SLICES) && (slice != TEN_SLICE_ALL)) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": slice out of range.  s/b 0..3.");
    return(CS_ERROR);
  }

  if ((slice == TEN_SLICE0) || (slice == TEN_SLICE_ALL)) {
    ret_val = ten_ohpp_sfu_insert_otn_maintenance_signal(module_id, signal, width, 1);
    if (ret_val == CS_ERROR) {
      goto RTN_EXIT;
    }
    else {
      ret_val = ten_ohpp_sfu_set_msignal(module_id, TEN_CA_MAINT_SIG_INSERT_OXU2_1, state);
    }
  }

  if (ret_val == CS_ERROR) {
    goto RTN_EXIT;
  }
  else if ((slice == TEN_SLICE1) || (slice == TEN_SLICE_ALL)) {
    ret_val = ten_ohpp_sfu_insert_otn_maintenance_signal(module_id, signal, width, 2);
    if (ret_val == CS_ERROR) {
      goto RTN_EXIT;
    }
    else {
      ret_val = ten_ohpp_sfu_set_msignal(module_id, TEN_CA_MAINT_SIG_INSERT_OXU2_2, state);
    }
  }

  if (ret_val == CS_ERROR) {
    goto RTN_EXIT;
  }
  else if ((slice == TEN_SLICE2) || (slice == TEN_SLICE_ALL)) {
    ret_val = ten_ohpp_sfu_insert_otn_maintenance_signal(module_id, signal, width, 3);
    if (ret_val == CS_ERROR) {
      goto RTN_EXIT;
    }
    else {
      ret_val = ten_ohpp_sfu_set_msignal(module_id, TEN_CA_MAINT_SIG_INSERT_OXU2_3, state);
    }
  }

  if (ret_val == CS_ERROR) {
    goto RTN_EXIT;
  }
  else if ((slice == TEN_SLICE3) || (slice == TEN_SLICE_ALL)) {
    ret_val = ten_ohpp_sfu_insert_otn_maintenance_signal(module_id, signal, width, 4);
    if (ret_val == CS_ERROR) {
      goto RTN_EXIT;
    }
    else {
      ret_val = ten_ohpp_sfu_set_msignal(module_id, TEN_CA_MAINT_SIG_INSERT_OXU2_4, state);
    }
  }

RTN_EXIT:
  return(ret_val);
}

/****************************************************************/
/* $rtn_hdr_start  ENABLE ODU2 MAINTENANCE SIGNAL               */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : HIGH LEVEL                                      */
/* CHIP       : Tenabo                                          */
cs_status ten_hl_ohpp_enable_odu2_maintenance_signal(cs_uint16 module_id,
                                                     cs_uint8 slice,
                                                     cs_uint8 signal,
                                                     cs_uint8 width,
                                                     cs_uint16 state)
/* INPUTS     : o Module Id                                     */
/*              o Slice                                         */
/*              o Signal                                        */
/*              o Width                                         */
/*              o State                                         */
/*                                                              */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* Enable an ODU2 Maintenance Signal on the 10G ports.          */
/*                                                              */
/* The [slice] parameter is specified as:                       */
/*   0x00 = TEN_SLICE0                                          */
/*   0x01 = TEN_SLICE1                                          */
/*   0x02 = TEN_SLICE2                                          */
/*   0x03 = TEN_SLICE3                                          */
/*   0xFF = TEN_SLICE_ALL                                       */
/*                                                              */
/* The [signal] parameter specifies the signal:                 */
/*   0 = TEN_OHPP_INSERT_ZERO                                   */
/*       Maintenance signal insertion only allowed if OXU21MS   */
/*       is disabled in SFC. If OXU21MS turns active while      */
/*       OMSA1S is set to 00 binary all bytes will be set to    */
/*       00 hex.                                                */
/*   1 = TEN_OHPP_INSERT_AIS                                    */
/*       Insert AIS (all bytes set to FF hex).                  */
/*   2 = TEN_OHPP_INSERT_OCI                                    */
/*       Insert OCI (all bytes set to 66 hex).                  */
/*   3 = TEN_OHPP_INSERT_LCK                                    */
/*       Insert LCK (all bytes set to 55 hex).                  */
/*                                                              */
/* The [width] parameter specifies the signal:                  */
/*   0 = TEN_OHPP_WIDTH_ONLY_PAYLOAD                            */
/*       Fill OPUk payload section only, leaving OTN overhead   */
/*       columns 1 through 16 unmodified.                       */
/*   1 = TEN_OHPP_WIDTH_OH_PAYLOAD                              */
/*       Fill OPUk payload and overhead section, leaving OTN    */
/*       overhead columns 1 through 14 unmodified.              */
/*   2 = TEN_OHPP_WIDTH_FRAME                                   */
/*       Fill complete OTUk frame except for FTFL and OTUk      */
/*       overhead.                                              */
/*                                                              */
/* The [state] parameter is specified as:                       */
/*   0 = 10G port behaves normally                              */
/*   1 = 10G port transmits an ODU2 Maintenance Signal          */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  cs_status ret_val = CS_OK;
  
  if ((slice>=TEN_MAX_SLICES) && (slice != TEN_SLICE_ALL)) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": slice out of range.  s/b 0..3.");
    return(CS_ERROR);
  }

  if ((slice == TEN_SLICE0) || (slice == TEN_SLICE_ALL)) {
    ret_val = ten_ohpp_sfu_insert_otn_maintenance_signal(module_id, signal, width, 1);
  }

  if (ret_val == CS_ERROR) {
    goto RTN_EXIT;
  }
  else if ((slice == TEN_SLICE1) || (slice == TEN_SLICE_ALL)) {
    ret_val = ten_ohpp_sfu_insert_otn_maintenance_signal(module_id, signal, width, 2);
  }

  if (ret_val == CS_ERROR) {
    goto RTN_EXIT;
  }
  else if ((slice == TEN_SLICE2) || (slice == TEN_SLICE_ALL)) {
    ret_val = ten_ohpp_sfu_insert_otn_maintenance_signal(module_id, signal, width, 3);
  }

  if (ret_val == CS_ERROR) {
    goto RTN_EXIT;
  }
  else if ((slice == TEN_SLICE3) || (slice == TEN_SLICE_ALL)) {
    ret_val = ten_ohpp_sfu_insert_otn_maintenance_signal(module_id, signal, width, 4);
  }

RTN_EXIT:
  return(ret_val);
}

#ifndef TEN_NO_N40G
/****************************************************************/
/* $rtn_hdr_start  FORCE OPU3 PN11                              */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : HIGH LEVEL                                      */
/* CHIP       : Tenabo                                          */
cs_status ten_hl_ohpp_force_opu3_pn11(cs_uint16 module_id,
                                      cs_uint16 state)
/* INPUTS     : o Module Id                                     */
/*              o State                                         */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* Force a client signal replacement by PN-11 (CBRGenAIS) on    */
/* the 40G port via the SFU MSignal.                            */
/*                                                              */
/* The [state] parameter is specified as:                       */
/*   0 = 40G port behaves normally                              */
/*   1 = 40G port transmits an OPU3 PN11 Signal                 */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  cs_status ret_val;

  /* Set (or clear) the MSignal bits to force the AIS */
  ret_val = ten_ohpp_sfu_set_msignal(module_id, TEN_CA_OXU3_CBR_GEN_PAY_INSERT_AIS, state);

  /* Set (or clear) the framer mask */
  if (ret_val == CS_OK) {
    ret_val = ten_n40g_set_pn11auto(module_id, state);
  }

  return(ret_val);
}

/****************************************************************/
/* $rtn_hdr_start  ENABLE OPU3 PN11                             */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : HIGH LEVEL                                      */
/* CHIP       : Tenabo                                          */
cs_status ten_hl_ohpp_enable_opu3_pn11(cs_uint16 module_id,
                                       cs_uint16 state)
/* INPUTS     : o Module Id                                     */
/*              o State                                         */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* Enable a client signal replacement by PN-11 (CBRGenAIS) on   */
/* the 40G port via an SFU Consequent Action.                   */
/*                                                              */
/* The [state] parameter is specified as:                       */
/*   0 = 40G port behaves normally                              */
/*   1 = 40G port transmits an OPU3 PN11 Signal                 */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  cs_status ret_val;

  ret_val = ten_n40g_set_pn11auto(module_id, state);

  return(ret_val);
}
#endif

/****************************************************************/
/* $rtn_hdr_start  FORCE OPU2 PN11                              */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : HIGH LEVEL                                      */
/* CHIP       : Tenabo                                          */
cs_status ten_hl_ohpp_force_opu2_pn11(cs_uint16 module_id,
                                      cs_uint8 slice,
                                      cs_uint16 state)
/* INPUTS     : o Module Id                                     */
/*              o Slice                                         */
/*              o State                                         */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* Force a client signal replacement by PN-11 (CBRGenAIS) on    */
/* the 10G ports via the SFU MSignal.                           */
/*                                                              */
/* The [slice] parameter is specified as:                       */
/*   0x00 = TEN_SLICE0                                          */
/*   0x01 = TEN_SLICE1                                          */
/*   0x02 = TEN_SLICE2                                          */
/*   0x03 = TEN_SLICE3                                          */
/*   0xFF = TEN_SLICE_ALL                                       */
/*                                                              */
/* The [state] parameter is specified as:                       */
/*   0 = 10G port behaves normally                              */
/*   1 = 10G port transmits an OPU2 PN11 Signal                 */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  cs_status ret_val = CS_OK;
  
  if ((slice>=TEN_MAX_SLICES) && (slice != TEN_SLICE_ALL)) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": slice out of range.  s/b 0..3.");
    return(CS_ERROR);
  }

  /* Set (or clear) the MSignal bits to force the AIS, then set (or clear) the framer mask */
  if ((slice == TEN_SLICE0) || (slice == TEN_SLICE_ALL)) {
    ret_val = ten_ohpp_sfu_set_msignal(module_id, TEN_CA_OXU2_CBR_GEN_PAY_INSERT_AIS_1, state);
    if (ret_val == CS_ERROR) {
      goto RTN_EXIT;
    }
    else {
      ret_val = ten_n10g_set_pn11auto(module_id, TEN_SLICE0, state);
    }
  }

  if (ret_val == CS_ERROR) {
    goto RTN_EXIT;
  }
  else if ((slice == TEN_SLICE1) || (slice == TEN_SLICE_ALL)) {
    ret_val = ten_ohpp_sfu_set_msignal(module_id, TEN_CA_OXU2_CBR_GEN_PAY_INSERT_AIS_2, state);
    if (ret_val == CS_ERROR) {
      goto RTN_EXIT;
    }
    else {
      ret_val = ten_n10g_set_pn11auto(module_id, TEN_SLICE1, state);
    }
  }

  if (ret_val == CS_ERROR) {
    goto RTN_EXIT;
  }
  else if ((slice == TEN_SLICE2) || (slice == TEN_SLICE_ALL)) {
    ret_val = ten_ohpp_sfu_set_msignal(module_id, TEN_CA_OXU2_CBR_GEN_PAY_INSERT_AIS_3, state);
    if (ret_val == CS_ERROR) {
      goto RTN_EXIT;
    }
    else {
      ret_val = ten_n10g_set_pn11auto(module_id, TEN_SLICE2, state);
    }
  }

  if (ret_val == CS_ERROR) {
    goto RTN_EXIT;
  }
  else if ((slice == TEN_SLICE3) || (slice == TEN_SLICE_ALL)) {
    ret_val = ten_ohpp_sfu_set_msignal(module_id, TEN_CA_OXU2_CBR_GEN_PAY_INSERT_AIS_4, state);
    if (ret_val == CS_ERROR) {
      goto RTN_EXIT;
    }
    else {
      ret_val = ten_n10g_set_pn11auto(module_id, TEN_SLICE3, state);
    }
  }

RTN_EXIT:
  return(ret_val);
}

/****************************************************************/
/* $rtn_hdr_start  ENABLE OPU2 PN11                             */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : HIGH LEVEL                                      */
/* CHIP       : Tenabo                                          */
cs_status ten_hl_ohpp_enable_opu2_pn11(cs_uint16 module_id,
                                       cs_uint8 slice,
                                       cs_uint16 state)
/* INPUTS     : o Module Id                                     */
/*              o Slice                                         */
/*              o State                                         */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* Enable a client signal replacement by PN-11 (CBRGenAIS) on   */
/* the 10G ports via an SFU Consequent Action.                  */
/*                                                              */
/* The [slice] parameter is specified as:                       */
/*   0x00 = TEN_SLICE0                                          */
/*   0x01 = TEN_SLICE1                                          */
/*   0x02 = TEN_SLICE2                                          */
/*   0x03 = TEN_SLICE3                                          */
/*   0xFF = TEN_SLICE_ALL                                       */
/*                                                              */
/* The [state] parameter is specified as:                       */
/*   0 = 10G port behaves normally                              */
/*   1 = 10G port transmits an OPU2 PN11 Signal.                */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  cs_status ret_val = CS_OK;
  
  if ((slice>=TEN_MAX_SLICES) && (slice != TEN_SLICE_ALL)) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": slice out of range.  s/b 0..3.");
    return(CS_ERROR);
  }

  /* Set (or clear) the MSignal bits to force the AIS, then set (or clear) the framer mask */
  if ((slice == TEN_SLICE0) || (slice == TEN_SLICE_ALL)) {
    ret_val = ten_n10g_set_pn11auto(module_id, TEN_SLICE0, state);
  }

  if (ret_val == CS_ERROR) {
    goto RTN_EXIT;
  }
  else if ((slice == TEN_SLICE1) || (slice == TEN_SLICE_ALL)) {
    ret_val = ten_n10g_set_pn11auto(module_id, TEN_SLICE1, state);
  }

  if (ret_val == CS_ERROR) {
    goto RTN_EXIT;
  }
  else if ((slice == TEN_SLICE2) || (slice == TEN_SLICE_ALL)) {
    ret_val = ten_n10g_set_pn11auto(module_id, TEN_SLICE2, state);
  }

  if (ret_val == CS_ERROR) {
    goto RTN_EXIT;
  }
  else if ((slice == TEN_SLICE3) || (slice == TEN_SLICE_ALL)) {
    ret_val = ten_n10g_set_pn11auto(module_id, TEN_SLICE3, state);
  }


RTN_EXIT:
  return(ret_val);
}

/****************************************************************/
/* $rtn_hdr_start  FORCE AIS-L                                  */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : HIGH LEVEL                                      */
/* CHIP       : Tenabo                                          */
cs_status ten_hl_ohpp_force_aisl(cs_uint16 module_id,
                                 cs_uint8 slice,
                                 cs_uint16 state)
/* INPUTS     : o Module Id                                     */
/*              o Slice                                         */
/*              o State                                         */
/*                                                              */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* Force an AIS-L on the 10G ports via the SFU MSignal.         */
/*                                                              */
/* The [slice] parameter is specified as:                       */
/*   0x00 = TEN_SLICE0                                          */
/*   0x01 = TEN_SLICE1                                          */
/*   0x02 = TEN_SLICE2                                          */
/*   0x03 = TEN_SLICE3                                          */
/*   0xFF = TEN_SLICE_ALL                                       */
/*                                                              */
/* The [state] parameter is specified as:                       */
/*   0 = 10G port behaves normally                              */
/*   1 = 10G port transmits an AIS-L.                           */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  cs_status ret_val = CS_OK;
  
  if ((slice>=TEN_MAX_SLICES) && (slice != TEN_SLICE_ALL)) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": slice out of range.  s/b 0..3.");
    return(CS_ERROR);
  }

  /* Set (or clear) the MSignal bits to force the AIS, then set (or clear) the framer mask */
  if ((slice == TEN_SLICE0) || (slice == TEN_SLICE_ALL)) {
    ret_val = ten_ohpp_sfu_set_msignal(module_id, TEN_CA_MUX_AIS_INSERT_OC_192_1, state);
    if (ret_val == CS_ERROR) {
      goto RTN_EXIT;
    }
    else {
      ret_val = ten_n10g_set_maismsk(module_id, TEN_SLICE0, state);
    }
  }

  if (ret_val == CS_ERROR) {
    goto RTN_EXIT;
  }
  else if ((slice == TEN_SLICE1) || (slice == TEN_SLICE_ALL)) {
    ret_val = ten_ohpp_sfu_set_msignal(module_id, TEN_CA_MUX_AIS_INSERT_OC_192_2, state);
    if (ret_val == CS_ERROR) {
      goto RTN_EXIT;
    }
    else {
      ret_val = ten_n10g_set_maismsk(module_id, TEN_SLICE1, state);
    }
  }

  if (ret_val == CS_ERROR) {
    goto RTN_EXIT;
  }
  else if ((slice == TEN_SLICE2) || (slice == TEN_SLICE_ALL)) {
    ret_val = ten_ohpp_sfu_set_msignal(module_id, TEN_CA_MUX_AIS_INSERT_OC_192_3, state);
    if (ret_val == CS_ERROR) {
      goto RTN_EXIT;
    }
    else {
      ret_val = ten_n10g_set_maismsk(module_id, TEN_SLICE2, state);
    }
  }

  if (ret_val == CS_ERROR) {
    goto RTN_EXIT;
  }
  else if ((slice == TEN_SLICE3) || (slice == TEN_SLICE_ALL)) {
    ret_val = ten_ohpp_sfu_set_msignal(module_id, TEN_CA_MUX_AIS_INSERT_OC_192_4, state);
    if (ret_val == CS_ERROR) {
      goto RTN_EXIT;
    }
    else {
      ret_val = ten_n10g_set_maismsk(module_id, TEN_SLICE3, state);
    }
  }

RTN_EXIT:
  return(ret_val);
}

/****************************************************************/
/* $rtn_hdr_start  ENABLE AIS-L                                 */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : HIGH LEVEL                                      */
/* CHIP       : Tenabo                                          */
cs_status ten_hl_ohpp_enable_aisl(cs_uint16 module_id,
                                  cs_uint8 slice,
                                  cs_uint16 state)
/* INPUTS     : o Module Id                                     */
/*              o Slice                                         */
/*              o State                                         */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* Enable an AIS-L on the 10G ports via an SFU Consequent       */
/* Action.                                                      */
/*                                                              */
/* The [slice] parameter is specified as:                       */
/*   0x00 = TEN_SLICE0                                          */
/*   0x01 = TEN_SLICE1                                          */
/*   0x02 = TEN_SLICE2                                          */
/*   0x03 = TEN_SLICE3                                          */
/*   0xFF = TEN_SLICE_ALL                                       */
/*                                                              */
/* The [state] parameter is specified as:                       */
/*   0 = 10G port behaves normally                              */
/*   1 = 10G port transmits an AIS-L.                           */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  cs_status ret_val = CS_OK;
  
  if ((slice>=TEN_MAX_SLICES) && (slice != TEN_SLICE_ALL)) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": slice out of range.  s/b 0..3.");
    return(CS_ERROR);
  }

  /* Set (or clear) the MSignal bits to force the AIS, then set (or clear) the framer mask */
  if ((slice == TEN_SLICE0) || (slice == TEN_SLICE_ALL)) {
    ret_val = ten_n10g_set_maismsk(module_id, TEN_SLICE0, state);
  }

  if (ret_val == CS_ERROR) {
    goto RTN_EXIT;
  }
  else if ((slice == TEN_SLICE1) || (slice == TEN_SLICE_ALL)) {
    ret_val = ten_n10g_set_maismsk(module_id, TEN_SLICE1, state);
  }

  if (ret_val == CS_ERROR) {
    goto RTN_EXIT;
  }
  else if ((slice == TEN_SLICE2) || (slice == TEN_SLICE_ALL)) {
    ret_val = ten_n10g_set_maismsk(module_id, TEN_SLICE2, state);
  }

  if (ret_val == CS_ERROR) {
    goto RTN_EXIT;
  }
  else if ((slice == TEN_SLICE3) || (slice == TEN_SLICE_ALL)) {
    ret_val = ten_n10g_set_maismsk(module_id, TEN_SLICE3, state);
  }

RTN_EXIT:
  return(ret_val);
}

/****************************************************************/
/* $rtn_hdr_start  FORCE CIRCUIT PP10G INSERTION                */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : HIGH LEVEL                                      */
/* CHIP       : Tenabo                                          */
cs_status ten_hl_ohpp_force_circuit_pp10g_insert(cs_uint16 module_id,
                                                 cs_uint8  slice,
                                                 cs_uint16 state)
/* INPUTS     : o Module Id                                     */
/*              o Slice                                         */
/*              o State                                         */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* Force insertion of PP10G output into the outgoing 10G        */
/* stream when in circuit mode. Used for injecting PP10G        */
/* ordered sets into circuit mode data streams.                 */
/*                                                              */
/* The [slice] parameter is specified as:                       */
/*   0x00 = TEN_SLICE0                                          */
/*   0x01 = TEN_SLICE1                                          */
/*   0x02 = TEN_SLICE2                                          */
/*   0x03 = TEN_SLICE3                                          */
/*   0xFF = TEN_SLICE_ALL                                       */
/*                                                              */
/* The [state] parameter is specified as:                       */
/*   0 = 10G port behaves normally                              */
/*   1 = 10G port transmits PP10G output.                       */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  cs_status ret_val = CS_OK;
  
  if ((slice>=TEN_MAX_SLICES) && (slice != TEN_SLICE_ALL)) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": slice out of range.  s/b 0..3.");
    return(CS_ERROR);
  }

  /* Set (or clear) the MSignal bits to force the AIS, then set (or clear) the framer mask */
  /* To insert 10GE LF PN11AUTO=0 and PPLF_EN=1 */
  if ((slice == TEN_SLICE0) || (slice == TEN_SLICE_ALL)) {
    ret_val = ten_ohpp_sfu_set_msignal(module_id, TEN_CA_OXU2_CBR_GEN_PAY_INSERT_AIS_1, state);
    if (ret_val == CS_ERROR) {
      goto RTN_EXIT;
    }
    else {
      ret_val = ten_n10g_set_pn11auto(module_id, TEN_SLICE0, 0);
    }
    if (ret_val == CS_ERROR) {
      goto RTN_EXIT;
    }
    else {
      ret_val = ten_n10g_set_pplf_en(module_id, TEN_SLICE0, state);
    }
  }

  if (ret_val == CS_ERROR) {
    goto RTN_EXIT;
  }
  else if ((slice == TEN_SLICE1) || (slice == TEN_SLICE_ALL)) {
    ret_val = ten_ohpp_sfu_set_msignal(module_id, TEN_CA_OXU2_CBR_GEN_PAY_INSERT_AIS_2, state);
    if (ret_val == CS_ERROR) {
      goto RTN_EXIT;
    }
    else {
      ret_val = ten_n10g_set_pn11auto(module_id, TEN_SLICE1, 0);
    }
    if (ret_val == CS_ERROR) {
      goto RTN_EXIT;
    }
    else {
      ret_val = ten_n10g_set_pplf_en(module_id, TEN_SLICE1, state);
    }
  }

  if (ret_val == CS_ERROR) {
    goto RTN_EXIT;
  }
  else if ((slice == TEN_SLICE2) || (slice == TEN_SLICE_ALL)) {
    ret_val = ten_ohpp_sfu_set_msignal(module_id, TEN_CA_OXU2_CBR_GEN_PAY_INSERT_AIS_3, state);
    if (ret_val == CS_ERROR) {
      goto RTN_EXIT;
    }
    else {
      ret_val = ten_n10g_set_pn11auto(module_id, TEN_SLICE2, 0);
    }
    if (ret_val == CS_ERROR) {
      goto RTN_EXIT;
    }
    else {
      ret_val = ten_n10g_set_pplf_en(module_id, TEN_SLICE2, state);
    }
  }

  if (ret_val == CS_ERROR) {
    goto RTN_EXIT;
  }
  else if ((slice == TEN_SLICE3) || (slice == TEN_SLICE_ALL)) {
    ret_val = ten_ohpp_sfu_set_msignal(module_id, TEN_CA_OXU2_CBR_GEN_PAY_INSERT_AIS_4, state);
    if (ret_val == CS_ERROR) {
      goto RTN_EXIT;
    }
    else {
      ret_val = ten_n10g_set_pn11auto(module_id, TEN_SLICE3, 0);
    }
    if (ret_val == CS_ERROR) {
      goto RTN_EXIT;
    }
    else {
      ret_val = ten_n10g_set_pplf_en(module_id, TEN_SLICE3, state);
    }
  }

RTN_EXIT:
  return(ret_val);
}

/****************************************************************/
/* $rtn_hdr_start  ENABLE CIRCUIT PP10G INSERTION               */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : HIGH LEVEL                                      */
/* CHIP       : Tenabo                                          */
cs_status ten_hl_ohpp_enable_circuit_pp10g_insert(cs_uint16 module_id,
                                                  cs_uint8  slice,
                                                  cs_uint16 state)
/* INPUTS     : o Module Id                                     */
/*              o Slice                                         */
/*              o State                                         */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* Enable insertion of PP10G output into the outgoing 10G       */
/* stream when in circuit mode. Used for injecting PP10G        */
/* ordered sets into circuit mode data streams. Triggered by    */
/* CBRGenAIS Consequent Action.                                 */
/*                                                              */
/* The [slice] parameter is specified as:                       */
/*   0x00 = TEN_SLICE0                                          */
/*   0x01 = TEN_SLICE1                                          */
/*   0x02 = TEN_SLICE2                                          */
/*   0x03 = TEN_SLICE3                                          */
/*   0xFF = TEN_SLICE_ALL                                       */
/*                                                              */
/* The [state] parameter is specified as:                       */
/*   0 = 10G port behaves normally                              */
/*   1 = 10G port transmits PP10G output.                       */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  cs_status ret_val = CS_OK;
  
  if ((slice>=TEN_MAX_SLICES) && (slice != TEN_SLICE_ALL)) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": slice out of range.  s/b 0..3.");
    return(CS_ERROR);
  }

  /* Set (or clear) the MSignal bits to force the AIS, then set (or clear) the framer mask */
  /* To insert 10GE LF PN11AUTO=0 and PPLF_EN=1 */
  if ((slice == TEN_SLICE0) || (slice == TEN_SLICE_ALL)) {
    ret_val = ten_n10g_set_pn11auto(module_id, TEN_SLICE0, 0);
    if (ret_val == CS_ERROR) {
      goto RTN_EXIT;
    }
    else {
      ret_val = ten_n10g_set_pplf_en(module_id, TEN_SLICE0, state);
    }
  }

  if (ret_val == CS_ERROR) {
    goto RTN_EXIT;
  }
  else if ((slice == TEN_SLICE1) || (slice == TEN_SLICE_ALL)) {
    ret_val = ten_n10g_set_pn11auto(module_id, TEN_SLICE1, 0);
    if (ret_val == CS_ERROR) {
      goto RTN_EXIT;
    }
    else {
      ret_val = ten_n10g_set_pplf_en(module_id, TEN_SLICE1, state);
    }
  }

  if (ret_val == CS_ERROR) {
    goto RTN_EXIT;
  }
  else if ((slice == TEN_SLICE2) || (slice == TEN_SLICE_ALL)) {
    ret_val = ten_n10g_set_pn11auto(module_id, TEN_SLICE2, 0);
    if (ret_val == CS_ERROR) {
      goto RTN_EXIT;
    }
    else {
      ret_val = ten_n10g_set_pplf_en(module_id, TEN_SLICE2, state);
    }
  }

  if (ret_val == CS_ERROR) {
    goto RTN_EXIT;
  }
  else if ((slice == TEN_SLICE3) || (slice == TEN_SLICE_ALL)) {
    ret_val = ten_n10g_set_pn11auto(module_id, TEN_SLICE3, 0);
    if (ret_val == CS_ERROR) {
      goto RTN_EXIT;
    }
    else {
      ret_val = ten_n10g_set_pplf_en(module_id, TEN_SLICE3, state);
    }
  }

RTN_EXIT:
  return(ret_val);
}

/****************************************************************/
/* $rtn_hdr_start  OHPP DUMP MSIGNAL SETTINGS                   */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : HIGH LEVEL                                      */
/* CHIP       : Tenabo                                          */
cs_status ten_hl_ohpp_dump_msignal(cs_uint16 module_id)
/* INPUTS     : o Module Id                                     */
/*                                                              */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* A text dump of the settings of the MSignal bits.             */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  cs_uint16 ii;
  
  /* Bugzilla #20180, display output even when logging is DISABLED */
  CS_PRINT_OUTPUT("\n\n\nThe following MSignal bits are set:\n");
  for (ii=0; ii<TEN_CONSEQUENT_ACTION_ROW_COUNT; ii++) {
    if (ten_ohpp_sfu_get_msignal(module_id, ii) == 1) {
      CS_PRINT_OUTPUT("  %s\n", ten_consequent_actions_str[ii]);
    }
  }
  CS_PRINT_OUTPUT("End of MSignal dump.\n");

  return(CS_OK);
}

/****************************************************************/
/* $rtn_hdr_start  OHPP DUMP OSIGNAL SETTINGS                   */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : HIGH LEVEL                                      */
/* CHIP       : Tenabo                                          */
cs_status ten_hl_ohpp_dump_osignal(cs_uint16 module_id)
/* INPUTS     : o Module Id                                     */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* A text dump of the settings of the OSignal bits.             */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  cs_uint16 ii;
  
  /* Bugzilla #20180, display output even when logging is DISABLED */
  CS_PRINT_OUTPUT("\n\n\nThe following OSignal bits are set:\n");
  for (ii=0; ii<TEN_CONSEQUENT_ACTION_ROW_COUNT; ii++) {
    if (ten_ohpp_sfu_get_osignal(module_id, ii) == 1) {
      CS_PRINT_OUTPUT("  %s\n", ten_consequent_actions_str[ii]);
    }
  }
  /* Fixed MSignal->Osignal typo without a bugzilla number */
  CS_PRINT_OUTPUT("End of OSignal dump.\n");

  return(CS_OK);
}

/* Bugzilla 21101: SFU Config dump enhancements */
/****************************************************************/
/* $rtn_hdr_start  OHPP DUMP OSIGNAL SETTINGS LOOPED            */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : HIGH LEVEL                                      */
/* CHIP       : Tenabo                                          */
cs_status ten_hl_ohpp_dump_osignal_loop(cs_uint16 module_id,
                                        cs_uint16 loop,
                                        cs_uint32 wait)
/* INPUTS     : o Module Id                                     */
/*            : o Loop                                          */
/*            : o Wait                                          */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* A text dump of the settings of the OSignal bits. This API    */
/* polls each osignal bit [loop] number of times and displays   */
/* how many of the reads were positive. If 0 is passed in as    */
/* the loop argument then the code defaults to a value of       */
/* loop = 10.                                                   */
/*                                                              */
/* The [loop] parameter is specified as:                        */
/*   0..65,535                                                  */
/*                                                              */
/* The [wait] parameter is specified as:                        */
/*   0..4,294,967,295 (32 bit value)                            */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  cs_uint16 ii;
  cs_uint16 jj;
  cs_uint16 count;
  
  CS_PRINT_OUTPUT("\n\n\nThe following OSignal bits are set:\n");

  /* Default value (0 passed in) of loop = 10 */
  if (loop==0) { loop = 10; }

  for (ii=0; ii<TEN_CONSEQUENT_ACTION_ROW_COUNT; ii++) {
    count = 0;
    for (jj=0; jj<loop; jj++) {
      if (wait > 0) { TEN_MDELAY(wait); }
      if (ten_ohpp_sfu_get_osignal(module_id, ii) == 1) { count++; }
    }
    if (count > 0) {
      CS_PRINT_OUTPUT("  %5d/%5d samples set for %s\n", count, loop, ten_consequent_actions_str[ii]);
    }
  }
  CS_PRINT_OUTPUT("End of OSignal dump.\n");

  return(CS_OK);
}

/****************************************************************/
/* $rtn_hdr_start  OHPP SWITCH SFC RAM BANK                     */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : HIGH LEVEL                                      */
/* CHIP       : Tenabo                                          */
cs_status ten_hl_ohpp_switch_sfc_ram(cs_uint16 module_id)
/* INPUTS     : o Module Id                                     */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* Switches the inactive SFC RAM bank to active and vice versa. */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  cs_int16 temp_initially_active;
  cs_uint32 err_code = 0;
  volatile cs_int16 temp_new_active;
  cs_uint16 temp_new_bank;
  cs_boolean waiting_for_high;
  cs_status rtn = CS_OK;
  cs_uint32 msec_elapsed = 0;

  if (!(TEN_IS_MOD_VALID(module_id, &err_code))) {
      CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, "ERROR: API   -Id (0x%x) is invalid!\n", module_id);
      rtn = CS_ERROR;
      goto RTN_EXIT;
  }
  
  /* Bug #38443 - warm start: include ten_hl_ohpp_switch_sfc_ram inside of ten_dev_is_ws_in_progress */
  if (ten_dev_is_ws_in_progress(TEN_MOD_ID_TO_DEV_ID(module_id))) {
    CS_PRINT("Device is in warm start mode.\n");
    return (CS_OK);
  }
  
  temp_initially_active = ten_ohpp_sfu_get_state(module_id, TEN_OHPP_SFU_STATE_SFCBANK);
  if (temp_initially_active == 0) {
    temp_new_bank = 1;
  }
  else {
    temp_new_bank = 0;
  }

  ten_ohpp_sfu_set_sfcmsel(module_id, temp_new_bank);

  waiting_for_high = TRUE;
  while (waiting_for_high) {
    temp_new_active = ten_ohpp_sfu_get_state(module_id, TEN_OHPP_SFU_STATE_SFCBANK);
    if (temp_new_active != temp_initially_active) {
       break;
    }   
    TEN_MDELAY(TEN_PP10G_MSEC_DELAY);
    msec_elapsed += TEN_PP10G_MSEC_DELAY;
    if (msec_elapsed >= TEN_PP10G_MSEC_TIMEOUT) {
      CS_HNDL_ERROR(module_id, ETEN_MOD_REG_ACCESS_TIMEOUT, ": timeout waiting for bank switch.");
      rtn = CS_ERROR;
      goto RTN_EXIT;
      break;
    }
  }

RTN_EXIT:
  return (rtn);
} 

/****************************************************************/
/* $rtn_hdr_start  OHPP COMMIT SHADOW SFC RAM CHANGES           */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : HIGH LEVEL                                      */
/* CHIP       : Tenabo                                          */
cs_status ten_hl_ohpp_commit_shadow_sfc_ram(cs_uint16 module_id,
                                            cs_uint16 bank)
/* INPUTS     : o Module Id                                     */
/*              o Bank                                          */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* Changes to the Shadow data structures are not propagated     */
/* through to the SFC RAM until this API is called. If this API */
/* is called for the inactive bank, the entire data structure   */
/* for the inactive bank is simply copied to the inactive bank  */
/* of physical SFC RAM. However, if this API is called for the  */
/* active bank, the physical banks are first switched, then     */
/* the data structure for the formerly active bank will be      */
/* copied to the newly inactive physical RAM, then the banks    */
/* are switched again. If undersirable consequences will result */
/* from this temporary switch to the inactive bank, then signal */
/* conditioning should be temporarily switched off by calling   */
/* the ten_ohpp_sfu_set_siggene API.                            */
/*                                                              */
/* The [bank] parameter is specified as:                        */
/*   0..1                                                       */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{

  cs_int16 temp_initially_active;
  cs_uint32 err_code = 0;

  if (bank > 1) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": bank out of range.  s/b 0..1.");
    return(CS_ERROR);
  } 
  if (!(TEN_IS_MOD_VALID(module_id, &err_code))) {
    CS_PRINT("ERROR: API   -Id (0x%x) is invalid!\n", module_id);
    return(CS_ERROR);
  }

  temp_initially_active = ten_ohpp_sfu_get_state(module_id, TEN_OHPP_SFU_STATE_SFCBANK);
  if (temp_initially_active != bank) {
    ten_ohpp_copy_shadow_sfc_ram(module_id, bank);
  }
  else {
    ten_hl_ohpp_switch_sfc_ram(module_id);
    ten_ohpp_copy_shadow_sfc_ram(module_id, bank);
    ten_hl_ohpp_switch_sfc_ram(module_id);
  }

  return (CS_OK);
}

/****************************************************************/
/* $rtn_hdr_start  OHPP DUMP CONSEQUENT ACTION EVENT SETTINGS   */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : HIGH LEVEL                                      */
/* CHIP       : Tenabo                                          */
cs_status ten_hl_ohpp_dump_consequent_action_events (cs_uint16 module_id,
                                                     cs_uint8 row)
/* INPUTS     : o Module Id                                     */
/*              o Row                                           */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* A text dump of the of the Consequent Action Events set in    */
/* the Inactive Bank of the physical SFC RAM to trigger the     */
/* specified row action.                                        */
/*                                                              */
/* The [row] parameter is specified as:                         */
/*   0..77                                                      */
/*   See ten_ohpp_data.h for the 78 enumeration values.         */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  cs_uint16 ii;
  cs_boolean temp_none;
  cs_uint32 err_code = 0;

  /* Turn off reg read/write dumps because API is so print intensive */
  g_pTEN->drvr_flag |= TEN_DRVR_LOG_SUSPEND;

  if (row >= TEN_CONSEQUENT_ACTION_ROW_COUNT) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": row out of range.  s/b 0..77.");
    return(CS_ERROR);
  } 
  if (!(TEN_IS_MOD_VALID(module_id, &err_code))) {
    CS_PRINT_OUTPUT("ERROR: API   -Id (0x%x) is invalid!\n", module_id);
    return(CS_ERROR);
  }
 
  CS_PRINT_OUTPUT("\nConsequent Action Events set for Own Module\n");

  temp_none = TRUE;
  CS_PRINT_OUTPUT(" Global Input Events\n");
  for (ii=TEN_CONSEQUENT_ACTION_EVENT_FIRST_GLOBAL;
       ii<=TEN_CONSEQUENT_ACTION_EVENT_LAST_GLOBAL; ii++) {
    if (ten_ohpp_get_sfc_ram_bit(module_id, row, ii) == 1) {
      temp_none = FALSE;
      CS_PRINT_OUTPUT("  * %s\n",
        ten_consequent_action_events_global_str[ii-TEN_CONSEQUENT_ACTION_EVENT_FIRST_GLOBAL]);
    }
  }
  if (temp_none) {
      CS_PRINT_OUTPUT("  None\n");
  }

  temp_none = TRUE;
  CS_PRINT_OUTPUT(" OxU3 Terminator Events\n");
  for (ii=TEN_CONSEQUENT_ACTION_EVENT_FIRST_OXU3;
       ii<=TEN_CONSEQUENT_ACTION_EVENT_LAST_OXU3; ii++) {
    if (ten_ohpp_get_sfc_ram_bit(module_id, row, ii) == 1) {
      temp_none = FALSE;
      CS_PRINT_OUTPUT("  * %s\n",
        ten_consequent_action_events_oxux_str[ii-TEN_CONSEQUENT_ACTION_EVENT_FIRST_OXU3]);
    }
  }
  if (temp_none) {
      CS_PRINT_OUTPUT("  None\n");
  }

  temp_none = TRUE;
  CS_PRINT_OUTPUT(" OxU2  #1 Terminator Events\n");
  for (ii=TEN_CONSEQUENT_ACTION_EVENT_FIRST_OXU2_1;
       ii<=TEN_CONSEQUENT_ACTION_EVENT_LAST_OXU2_1; ii++) {
    if (ten_ohpp_get_sfc_ram_bit(module_id, row, ii) == 1) {
      temp_none = FALSE;
      CS_PRINT_OUTPUT("  * %s\n",
        ten_consequent_action_events_oxux_str[ii-TEN_CONSEQUENT_ACTION_EVENT_FIRST_OXU2_1]);
    }
  }
  if (temp_none) {
      CS_PRINT_OUTPUT("  None\n");
  }

  temp_none = TRUE;
  CS_PRINT_OUTPUT(" OxU2  #2 Terminator Events\n");
  for (ii=TEN_CONSEQUENT_ACTION_EVENT_FIRST_OXU2_2;
       ii<=TEN_CONSEQUENT_ACTION_EVENT_LAST_OXU2_2; ii++) {
    if (ten_ohpp_get_sfc_ram_bit(module_id, row, ii) == 1) {
      temp_none = FALSE;
      CS_PRINT_OUTPUT("  * %s\n",
        ten_consequent_action_events_oxux_str[ii-TEN_CONSEQUENT_ACTION_EVENT_FIRST_OXU2_2]);
    }
  }
  if (temp_none) {
      CS_PRINT_OUTPUT("  None\n");
  }

  temp_none = TRUE;
  CS_PRINT_OUTPUT(" OxU2  #3 Terminator Events\n");
  for (ii=TEN_CONSEQUENT_ACTION_EVENT_FIRST_OXU2_3;
       ii<=TEN_CONSEQUENT_ACTION_EVENT_LAST_OXU2_3; ii++) {
    if (ten_ohpp_get_sfc_ram_bit(module_id, row, ii) == 1) {
      temp_none = FALSE;
      CS_PRINT_OUTPUT("  * %s\n",
        ten_consequent_action_events_oxux_str[ii-TEN_CONSEQUENT_ACTION_EVENT_FIRST_OXU2_3]);
    }
  }
  if (temp_none) {
      CS_PRINT_OUTPUT("  None\n");
  }

  temp_none = TRUE;
  CS_PRINT_OUTPUT(" OxU2  #4 Terminator Events\n");
  for (ii=TEN_CONSEQUENT_ACTION_EVENT_FIRST_OXU2_4;
       ii<=TEN_CONSEQUENT_ACTION_EVENT_LAST_OXU2_4; ii++) {
    if (ten_ohpp_get_sfc_ram_bit(module_id, row, ii) == 1) {
      temp_none = FALSE;
      CS_PRINT_OUTPUT("  * %s\n",
        ten_consequent_action_events_oxux_str[ii-TEN_CONSEQUENT_ACTION_EVENT_FIRST_OXU2_4]);
    }
  }
  if (temp_none) {
      CS_PRINT_OUTPUT("  None\n");
  }

  temp_none = TRUE;
  CS_PRINT_OUTPUT(" OC192 #1 Terminator Events\n");
  for (ii=TEN_CONSEQUENT_ACTION_EVENT_FIRST_OC192_1;
       ii<=TEN_CONSEQUENT_ACTION_EVENT_LAST_OC192_1; ii++) {
    if (ten_ohpp_get_sfc_ram_bit(module_id, row, ii) == 1) {
      temp_none = FALSE;
      CS_PRINT_OUTPUT("  * %s\n",
        ten_consequent_action_events_oc192_str[ii-TEN_CONSEQUENT_ACTION_EVENT_FIRST_OC192_1]);
    }
  }
  if (temp_none) {
      CS_PRINT_OUTPUT("  None\n");
  }

  temp_none = TRUE;
  CS_PRINT_OUTPUT(" OC192 #2 Terminator Events\n");
  for (ii=TEN_CONSEQUENT_ACTION_EVENT_FIRST_OC192_2;
       ii<=TEN_CONSEQUENT_ACTION_EVENT_LAST_OC192_2; ii++) {
    if (ten_ohpp_get_sfc_ram_bit(module_id, row, ii) == 1) {
      temp_none = FALSE;
      CS_PRINT_OUTPUT("  * %s\n",
        ten_consequent_action_events_oc192_str[ii-TEN_CONSEQUENT_ACTION_EVENT_FIRST_OC192_2]);
    }
  }
  if (temp_none) {
      CS_PRINT_OUTPUT("  None\n");
  }

  temp_none = TRUE;
  CS_PRINT_OUTPUT(" OC192 #3 Terminator Events\n");
  for (ii=TEN_CONSEQUENT_ACTION_EVENT_FIRST_OC192_3;
       ii<=TEN_CONSEQUENT_ACTION_EVENT_LAST_OC192_3; ii++) {
    if (ten_ohpp_get_sfc_ram_bit(module_id, row, ii) == 1) {
      temp_none = FALSE;
      CS_PRINT_OUTPUT("  * %s\n",
        ten_consequent_action_events_oc192_str[ii-TEN_CONSEQUENT_ACTION_EVENT_FIRST_OC192_3]);
    }
  }
  if (temp_none) {
      CS_PRINT_OUTPUT("  None\n");
  }

  temp_none = TRUE;
  CS_PRINT_OUTPUT(" OC192 #4 Terminator Events\n");
  for (ii=TEN_CONSEQUENT_ACTION_EVENT_FIRST_OC192_4;
       ii<=TEN_CONSEQUENT_ACTION_EVENT_LAST_OC192_4; ii++) {
    if (ten_ohpp_get_sfc_ram_bit(module_id, row, ii) == 1) {
      temp_none = FALSE;
      CS_PRINT_OUTPUT("  * %s\n",
        ten_consequent_action_events_oc192_str[ii-TEN_CONSEQUENT_ACTION_EVENT_FIRST_OC192_4]);
    }
  }
  if (temp_none) {
      CS_PRINT_OUTPUT("  None\n");
  }
  
  /* Bugzilla #38149 - update ten_hl_ohpp_dump_sfu API for T41 events  */
  if (ten_dev_is_t41(TEN_MOD_ID_TO_DEV_ID(module_id))) {
    temp_none = TRUE;
    CS_PRINT_OUTPUT(" CS604X OxU3 Terminator Events\n");
    for (ii=TEN_CONSEQUENT_ACTION_EVENT_FIRST_OXU3_TERM; ii<=TEN_CONSEQUENT_ACTION_EVENT_LAST_OXU3_TERM; ii++) {
      if (ten_ohpp_get_sfc_ram_bit(module_id, row, ii) == 1) {
        temp_none = FALSE;
        CS_PRINT_OUTPUT("  * %s\n", ten_consequent_action_events_cs604x_oxu3_str[ii-TEN_CONSEQUENT_ACTION_EVENT_FIRST_OXU3_TERM]);
      }
    }
    if (temp_none) {
      CS_PRINT_OUTPUT("  None\n");
    }
  
    temp_none = TRUE;
    CS_PRINT_OUTPUT(" CS604X OxU2 #1 Terminator Events\n");
    for (ii=TEN_CONSEQUENT_ACTION_EVENT_FIRST_OXU2_TERM_1; ii<=TEN_CONSEQUENT_ACTION_EVENT_LAST_OXU2_TERM_1; ii++) {
      if (ten_ohpp_get_sfc_ram_bit(module_id, row, ii) == 1) {
        temp_none = FALSE;
        CS_PRINT_OUTPUT("  * %s\n", ten_consequent_action_events_cs604x_oxu2_terminator_channel_actions_str[ii-TEN_CONSEQUENT_ACTION_EVENT_FIRST_OXU2_TERM_1]);
      }
    }
    if (temp_none) {
      CS_PRINT_OUTPUT("  None\n");
    }
    
    temp_none = TRUE;
    CS_PRINT_OUTPUT(" CS604X OxU2 #2 Terminator Events\n");
    for (ii=TEN_CONSEQUENT_ACTION_EVENT_FIRST_OXU2_TERM_2; ii<=TEN_CONSEQUENT_ACTION_EVENT_LAST_OXU2_TERM_2; ii++) {
      if (ten_ohpp_get_sfc_ram_bit(module_id, row, ii) == 1) {
        temp_none = FALSE;
        CS_PRINT_OUTPUT("  * %s\n", ten_consequent_action_events_cs604x_oxu2_terminator_channel_actions_str[ii-TEN_CONSEQUENT_ACTION_EVENT_FIRST_OXU2_TERM_2]);
      }
    }
    if (temp_none) {
      CS_PRINT_OUTPUT("  None\n");
    }
    
    temp_none = TRUE;
    CS_PRINT_OUTPUT(" CS604X OxU2 #3 Terminator Events\n");
    for (ii=TEN_CONSEQUENT_ACTION_EVENT_FIRST_OXU2_TERM_3; ii<=TEN_CONSEQUENT_ACTION_EVENT_LAST_OXU2_TERM_3; ii++) {
      if (ten_ohpp_get_sfc_ram_bit(module_id, row, ii) == 1) {
        temp_none = FALSE;
        CS_PRINT_OUTPUT("  * %s\n", ten_consequent_action_events_cs604x_oxu2_terminator_channel_actions_str[ii-TEN_CONSEQUENT_ACTION_EVENT_FIRST_OXU2_TERM_3]);
      }
    }
    if (temp_none) {
      CS_PRINT_OUTPUT("  None\n");
    }
    
    temp_none = TRUE;
    CS_PRINT_OUTPUT(" CS604X OxU2 #4 Terminator Events\n");
    for (ii=TEN_CONSEQUENT_ACTION_EVENT_FIRST_OXU2_TERM_4; ii<=TEN_CONSEQUENT_ACTION_EVENT_LAST_OXU2_TERM_4; ii++) {
      if (ten_ohpp_get_sfc_ram_bit(module_id, row, ii) == 1) {
        temp_none = FALSE;
        CS_PRINT_OUTPUT("  * %s\n", ten_consequent_action_events_cs604x_oxu2_terminator_channel_actions_str[ii-TEN_CONSEQUENT_ACTION_EVENT_FIRST_OXU2_TERM_4]);
      }
    }
    if (temp_none) {
      CS_PRINT_OUTPUT("  None\n");
    }
    
    temp_none = TRUE;
    CS_PRINT_OUTPUT(" CS604X 40G Packet Processor Events\n");
    if (ten_ohpp_get_sfc_ram_bit(module_id, row, TEN_CONSEQUENT_ACTION_EVENT_40G_PP) == 1) {
      temp_none = FALSE;
      CS_PRINT_OUTPUT("  * %s\n", "Rx Failure Alarm from 40G Packet Processor");
    }
    if (temp_none) {
      CS_PRINT_OUTPUT("  None\n");
    }
    
    for (ii=TEN_CONSEQUENT_ACTION_EVENT_10G_PP_CHAN1; ii<=TEN_CONSEQUENT_ACTION_EVENT_10G_PP_CHAN4; ii++) {
      temp_none = TRUE;
      CS_PRINT_OUTPUT(" CS604X 10G #%d Packet Processor Events\n", ii-(TEN_CONSEQUENT_ACTION_EVENT_10G_PP_CHAN1-1));
      if (ten_ohpp_get_sfc_ram_bit(module_id, row, ii) == 1) {
        temp_none = FALSE;
        CS_PRINT_OUTPUT("  * %s %d\n", "Rx Failure Alarm from 10G Packet Processor Channel ", ii-(TEN_CONSEQUENT_ACTION_EVENT_10G_PP_CHAN1-1));
      }
      if (temp_none) {
       CS_PRINT_OUTPUT("  None\n");
      }
    }
  }

  CS_PRINT_OUTPUT("\nConsequent Action Events set for Other Module\n");

  temp_none = TRUE;
  CS_PRINT_OUTPUT(" Global Input Events\n");
  for (ii=TEN_CONSEQUENT_ACTION_EVENT_FIRST_GLOBAL;
       ii<=TEN_CONSEQUENT_ACTION_EVENT_LAST_GLOBAL; ii++) {
    if (ten_ohpp_get_sfc_ram_bit(module_id, row, ii+TEN_CONSEQUENT_ACTION_EVENT_OTHER_OFFSET) == 1) {
      temp_none = FALSE;
      CS_PRINT_OUTPUT("  * %s\n",
        ten_consequent_action_events_global_str[ii-TEN_CONSEQUENT_ACTION_EVENT_FIRST_GLOBAL]);
    }
  }
  if (temp_none) {
      CS_PRINT_OUTPUT("  None\n");
  }

  temp_none = TRUE;
  CS_PRINT_OUTPUT(" OxU3 Terminator Events\n");
  for (ii=TEN_CONSEQUENT_ACTION_EVENT_FIRST_OXU3;
       ii<=TEN_CONSEQUENT_ACTION_EVENT_LAST_OXU3; ii++) {
    if (ten_ohpp_get_sfc_ram_bit(module_id, row, ii+TEN_CONSEQUENT_ACTION_EVENT_OTHER_OFFSET) == 1) {
      temp_none = FALSE;
      CS_PRINT_OUTPUT("  * %s\n",
        ten_consequent_action_events_oxux_str[ii-TEN_CONSEQUENT_ACTION_EVENT_FIRST_OXU3]);
    }
  }
  if (temp_none) {
      CS_PRINT_OUTPUT("  None\n");
  }

  temp_none = TRUE;
  CS_PRINT_OUTPUT(" OxU2  #1 Terminator Events\n");
  for (ii=TEN_CONSEQUENT_ACTION_EVENT_FIRST_OXU2_1;
       ii<=TEN_CONSEQUENT_ACTION_EVENT_LAST_OXU2_1; ii++) {
    if (ten_ohpp_get_sfc_ram_bit(module_id, row, ii+TEN_CONSEQUENT_ACTION_EVENT_OTHER_OFFSET) == 1) {
      temp_none = FALSE;
      CS_PRINT_OUTPUT("  * %s\n",
        ten_consequent_action_events_oxux_str[ii-TEN_CONSEQUENT_ACTION_EVENT_FIRST_OXU2_1]);
    }
  }
  if (temp_none) {
      CS_PRINT_OUTPUT("  None\n");
  }

  temp_none = TRUE;
  CS_PRINT_OUTPUT(" OxU2  #2 Terminator Events\n");
  for (ii=TEN_CONSEQUENT_ACTION_EVENT_FIRST_OXU2_2;
       ii<=TEN_CONSEQUENT_ACTION_EVENT_LAST_OXU2_2; ii++) {
    if (ten_ohpp_get_sfc_ram_bit(module_id, row, ii+TEN_CONSEQUENT_ACTION_EVENT_OTHER_OFFSET) == 1) {
      temp_none = FALSE;
      CS_PRINT_OUTPUT("  * %s\n",
        ten_consequent_action_events_oxux_str[ii-TEN_CONSEQUENT_ACTION_EVENT_FIRST_OXU2_2]);
    }
  }
  if (temp_none) {
      CS_PRINT_OUTPUT("  None\n");
  }

  temp_none = TRUE;
  CS_PRINT_OUTPUT(" OxU2  #3 Terminator Events\n");
  for (ii=TEN_CONSEQUENT_ACTION_EVENT_FIRST_OXU2_3;
       ii<=TEN_CONSEQUENT_ACTION_EVENT_LAST_OXU2_3; ii++) {
    if (ten_ohpp_get_sfc_ram_bit(module_id, row, ii+TEN_CONSEQUENT_ACTION_EVENT_OTHER_OFFSET) == 1) {
      temp_none = FALSE;
      CS_PRINT_OUTPUT("  * %s\n",
        ten_consequent_action_events_oxux_str[ii-TEN_CONSEQUENT_ACTION_EVENT_FIRST_OXU2_3]);
    }
  }
  if (temp_none) {
      CS_PRINT_OUTPUT("  None\n");
  }

  temp_none = TRUE;
  CS_PRINT_OUTPUT(" OxU2  #4 Terminator Events\n");
  for (ii=TEN_CONSEQUENT_ACTION_EVENT_FIRST_OXU2_4;
       ii<=TEN_CONSEQUENT_ACTION_EVENT_LAST_OXU2_4; ii++) {
    if (ten_ohpp_get_sfc_ram_bit(module_id, row, ii+TEN_CONSEQUENT_ACTION_EVENT_OTHER_OFFSET) == 1) {
      temp_none = FALSE;
      CS_PRINT_OUTPUT("  * %s\n",
        ten_consequent_action_events_oxux_str[ii-TEN_CONSEQUENT_ACTION_EVENT_FIRST_OXU2_4]);
    }
  }
  if (temp_none) {
      CS_PRINT_OUTPUT("  None\n");
  }

  temp_none = TRUE;
  CS_PRINT_OUTPUT(" OC192 #1 Terminator Events\n");
  for (ii=TEN_CONSEQUENT_ACTION_EVENT_FIRST_OC192_1;
       ii<=TEN_CONSEQUENT_ACTION_EVENT_LAST_OC192_1; ii++) {
    if (ten_ohpp_get_sfc_ram_bit(module_id, row, ii+TEN_CONSEQUENT_ACTION_EVENT_OTHER_OFFSET) == 1) {
      temp_none = FALSE;
      CS_PRINT_OUTPUT("  * %s\n",
        ten_consequent_action_events_oc192_str[ii-TEN_CONSEQUENT_ACTION_EVENT_FIRST_OC192_1]);
    }
  }
  if (temp_none) {
      CS_PRINT_OUTPUT("  None\n");
  }

  temp_none = TRUE;
  CS_PRINT_OUTPUT(" OC192 #2 Terminator Events\n");
  for (ii=TEN_CONSEQUENT_ACTION_EVENT_FIRST_OC192_2;
       ii<=TEN_CONSEQUENT_ACTION_EVENT_LAST_OC192_2; ii++) {
    if (ten_ohpp_get_sfc_ram_bit(module_id, row, ii+TEN_CONSEQUENT_ACTION_EVENT_OTHER_OFFSET) == 1) {
      temp_none = FALSE;
      CS_PRINT_OUTPUT("  * %s\n",
        ten_consequent_action_events_oc192_str[ii-TEN_CONSEQUENT_ACTION_EVENT_FIRST_OC192_2]);
    }
  }
  if (temp_none) {
      CS_PRINT_OUTPUT("  None\n");
  }

  temp_none = TRUE;
  CS_PRINT_OUTPUT(" OC192 #3 Terminator Events\n");
  for (ii=TEN_CONSEQUENT_ACTION_EVENT_FIRST_OC192_3;
       ii<=TEN_CONSEQUENT_ACTION_EVENT_LAST_OC192_3; ii++) {
    if (ten_ohpp_get_sfc_ram_bit(module_id, row, ii+TEN_CONSEQUENT_ACTION_EVENT_OTHER_OFFSET) == 1) {
      temp_none = FALSE;
      CS_PRINT_OUTPUT("  * %s\n",
        ten_consequent_action_events_oc192_str[ii-TEN_CONSEQUENT_ACTION_EVENT_FIRST_OC192_3]);
    }
  }
  if (temp_none) {
      CS_PRINT_OUTPUT("  None\n");
  }

  temp_none = TRUE;
  CS_PRINT_OUTPUT(" OC192 #4 Terminator Events\n");
  for (ii=TEN_CONSEQUENT_ACTION_EVENT_FIRST_OC192_4;
       ii<=TEN_CONSEQUENT_ACTION_EVENT_LAST_OC192_4; ii++) {
    if (ten_ohpp_get_sfc_ram_bit(module_id, row, ii+TEN_CONSEQUENT_ACTION_EVENT_OTHER_OFFSET) == 1) {
      temp_none = FALSE;
      CS_PRINT_OUTPUT("  * %s\n",
        ten_consequent_action_events_oc192_str[ii-TEN_CONSEQUENT_ACTION_EVENT_FIRST_OC192_4]);
    }
  }
  if (temp_none) {
      CS_PRINT_OUTPUT("  None\n");
  }

  /* Bugzilla #38149 - update ten_hl_ohpp_dump_sfu API for T41 events  */
  if (ten_dev_is_t41(TEN_MOD_ID_TO_DEV_ID(module_id))) {
    temp_none = TRUE;
    CS_PRINT_OUTPUT(" CS604X OxU3 Terminator Events\n");
    for (ii=TEN_CONSEQUENT_ACTION_EVENT_FIRST_OXU3_TERM; ii<=TEN_CONSEQUENT_ACTION_EVENT_LAST_OXU3_TERM; ii++) {
      if (ten_ohpp_get_sfc_ram_bit(module_id, row, ii+TEN_CONSEQUENT_ACTION_EVENT_OTHER_OFFSET_T41) == 1) {
        temp_none = FALSE;
        CS_PRINT_OUTPUT("  * %s\n", ten_consequent_action_events_cs604x_oxu3_str[ii-TEN_CONSEQUENT_ACTION_EVENT_FIRST_OXU3_TERM]);
      }
    }
    if (temp_none) {
      CS_PRINT_OUTPUT("  None\n");
    }
  
    temp_none = TRUE;
    CS_PRINT_OUTPUT(" CS604X OxU2 #1 Terminator Events\n");
    for (ii=TEN_CONSEQUENT_ACTION_EVENT_FIRST_OXU2_TERM_1; ii<=TEN_CONSEQUENT_ACTION_EVENT_LAST_OXU2_TERM_1; ii++) {
      if (ten_ohpp_get_sfc_ram_bit(module_id, row, ii+TEN_CONSEQUENT_ACTION_EVENT_OTHER_OFFSET_T41) == 1) {
        temp_none = FALSE;
        CS_PRINT_OUTPUT("  * %s\n", ten_consequent_action_events_cs604x_oxu2_terminator_channel_actions_str[ii-TEN_CONSEQUENT_ACTION_EVENT_FIRST_OXU2_TERM_1]);
      }
    }
    if (temp_none) {
      CS_PRINT_OUTPUT("  None\n");
    }
    
    temp_none = TRUE;
    CS_PRINT_OUTPUT(" CS604X OxU2 #2 Terminator Events\n");
    for (ii=TEN_CONSEQUENT_ACTION_EVENT_FIRST_OXU2_TERM_2; ii<=TEN_CONSEQUENT_ACTION_EVENT_LAST_OXU2_TERM_2; ii++) {
      if (ten_ohpp_get_sfc_ram_bit(module_id, row, ii+TEN_CONSEQUENT_ACTION_EVENT_OTHER_OFFSET_T41) == 1) {
        temp_none = FALSE;
        CS_PRINT_OUTPUT("  * %s\n", ten_consequent_action_events_cs604x_oxu2_terminator_channel_actions_str[ii-TEN_CONSEQUENT_ACTION_EVENT_FIRST_OXU2_TERM_2]);
      }
    }
    if (temp_none) {
      CS_PRINT_OUTPUT("  None\n");
    }
    
    temp_none = TRUE;
    CS_PRINT_OUTPUT(" CS604X OxU2 #3 Terminator Events\n");
    for (ii=TEN_CONSEQUENT_ACTION_EVENT_FIRST_OXU2_TERM_3; ii<=TEN_CONSEQUENT_ACTION_EVENT_LAST_OXU2_TERM_3; ii++) {
      if (ten_ohpp_get_sfc_ram_bit(module_id, row, ii+TEN_CONSEQUENT_ACTION_EVENT_OTHER_OFFSET_T41) == 1) {
        temp_none = FALSE;
        CS_PRINT_OUTPUT("  * %s\n", ten_consequent_action_events_cs604x_oxu2_terminator_channel_actions_str[ii-TEN_CONSEQUENT_ACTION_EVENT_FIRST_OXU2_TERM_3]);
      }
    }
    if (temp_none) {
      CS_PRINT_OUTPUT("  None\n");
    }
    
    temp_none = TRUE;
    CS_PRINT_OUTPUT(" CS604X OxU2 #4 Terminator Events\n");
    for (ii=TEN_CONSEQUENT_ACTION_EVENT_FIRST_OXU2_TERM_4; ii<=TEN_CONSEQUENT_ACTION_EVENT_LAST_OXU2_TERM_4; ii++) {
      if (ten_ohpp_get_sfc_ram_bit(module_id, row, ii+TEN_CONSEQUENT_ACTION_EVENT_OTHER_OFFSET_T41) == 1) {
        temp_none = FALSE;
        CS_PRINT_OUTPUT("  * %s\n", ten_consequent_action_events_cs604x_oxu2_terminator_channel_actions_str[ii-TEN_CONSEQUENT_ACTION_EVENT_FIRST_OXU2_TERM_4]);
      }
    }
    if (temp_none) {
      CS_PRINT_OUTPUT("  None\n");
    }
    
    temp_none = TRUE;
    CS_PRINT_OUTPUT(" CS604X 40G Packet Processor Events\n");
    if (ten_ohpp_get_sfc_ram_bit(module_id, row, TEN_CONSEQUENT_ACTION_EVENT_40G_PP+TEN_CONSEQUENT_ACTION_EVENT_OTHER_OFFSET_T41) == 1) {
      temp_none = FALSE;
      CS_PRINT_OUTPUT("  * %s\n", "Rx Failure Alarm from 40G Packet Processor");
    }
    if (temp_none) {
      CS_PRINT_OUTPUT("  None\n");
    }

    for (ii=TEN_CONSEQUENT_ACTION_EVENT_10G_PP_CHAN1; ii<=TEN_CONSEQUENT_ACTION_EVENT_10G_PP_CHAN4; ii++) {
      temp_none = TRUE;
      CS_PRINT_OUTPUT(" CS604X 10G #%d Packet Processor Events\n", ii-(TEN_CONSEQUENT_ACTION_EVENT_10G_PP_CHAN1-1));
      if (ten_ohpp_get_sfc_ram_bit(module_id, row, ii+TEN_CONSEQUENT_ACTION_EVENT_OTHER_OFFSET_T41) == 1) {
        temp_none = FALSE;
        CS_PRINT_OUTPUT("  * %s %d\n", "Rx Failure Alarm from 10G Packet Processor Channel ", ii-(TEN_CONSEQUENT_ACTION_EVENT_10G_PP_CHAN1-1));
      }
      if (temp_none) {
       CS_PRINT_OUTPUT("  None\n");
      }
    }
  }
  
  CS_PRINT_OUTPUT("\nEnd of Consequent Action Event dump.\n");

  /* Turn on reg read/write dumps */
  g_pTEN->drvr_flag &= ~TEN_DRVR_LOG_SUSPEND;

  return(CS_OK);
}

/* Bugzilla 21101: SFU Config dump enhancements */
/****************************************************************/
/* $rtn_hdr_start  OHPP DUMP CONSEQUENT ACTIONS ALL ROWS        */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : HIGH LEVEL                                      */
/* CHIP       : Tenabo                                          */
cs_status ten_hl_ohpp_dump_consequent_actions_all (cs_uint16 module_id)
/* INPUTS     : o Module Id                                     */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* A text dump of the of the Consequent Action Events set in    */
/* the Inactive Bank of the physical SFC RAM to trigger all     */
/* row actions.                                                 */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  cs_uint16 ii;
  cs_uint16 row;
  cs_boolean temp_event_none;
  cs_boolean temp_row_none;
  cs_uint32 err_code = 0;

  /* Turn off reg read/write dumps because API is so print intensive */
  g_pTEN->drvr_flag |= TEN_DRVR_LOG_SUSPEND;

  if (!(TEN_IS_MOD_VALID(module_id, &err_code))) {
    CS_PRINT_OUTPUT("ERROR: API   -Id (0x%x) is invalid!\n", module_id);
    return(CS_ERROR);
  }
 
  CS_PRINT_OUTPUT("\n  Consequent Action Events set for Own Module\n");

  for (row=0; row<TEN_CONSEQUENT_ACTION_ROW_COUNT; row++) {
    temp_row_none   = TRUE;
    temp_event_none = TRUE;
    for (ii=TEN_CONSEQUENT_ACTION_EVENT_FIRST_GLOBAL;
         ii<=TEN_CONSEQUENT_ACTION_EVENT_LAST_GLOBAL; ii++) {
      if (ten_ohpp_get_sfc_ram_bit(module_id, row, ii) == 1) {
        if (temp_row_none) {
          CS_PRINT_OUTPUT("    ROW %d: %s\n", row, ten_consequent_actions_str[row]);
          temp_row_none = FALSE;
        }
        if (temp_event_none) {
          CS_PRINT_OUTPUT("      Global Input Events\n");
          temp_event_none = FALSE;
        }
        CS_PRINT_OUTPUT("        * %s\n",
          ten_consequent_action_events_global_str[ii-TEN_CONSEQUENT_ACTION_EVENT_FIRST_GLOBAL]);
      }
    }

    temp_event_none = TRUE;
    for (ii=TEN_CONSEQUENT_ACTION_EVENT_FIRST_OXU3;
         ii<=TEN_CONSEQUENT_ACTION_EVENT_LAST_OXU3; ii++) {
      if (ten_ohpp_get_sfc_ram_bit(module_id, row, ii) == 1) {
        if (temp_row_none) {
          CS_PRINT_OUTPUT("    ROW %d: %s\n", row, ten_consequent_actions_str[row]);
          temp_row_none = FALSE;
        }
        if (temp_event_none) {
          CS_PRINT_OUTPUT("       OxU3 Terminator Events\n");
          temp_event_none = FALSE;
        }
        CS_PRINT_OUTPUT("        * %s\n",
          ten_consequent_action_events_oxux_str[ii-TEN_CONSEQUENT_ACTION_EVENT_FIRST_OXU3]);
      }
    }

    temp_event_none = TRUE;
    for (ii=TEN_CONSEQUENT_ACTION_EVENT_FIRST_OXU2_1;
         ii<=TEN_CONSEQUENT_ACTION_EVENT_LAST_OXU2_1; ii++) {
      if (ten_ohpp_get_sfc_ram_bit(module_id, row, ii) == 1) {
        if (temp_row_none) {
          CS_PRINT_OUTPUT("    ROW %d: %s\n", row, ten_consequent_actions_str[row]);
          temp_row_none = FALSE;
        }
        if (temp_event_none) {
          CS_PRINT_OUTPUT("       OxU2  #1 Terminator Events\n");
          temp_event_none = FALSE;
        }
        CS_PRINT_OUTPUT("        * %s\n",
          ten_consequent_action_events_oxux_str[ii-TEN_CONSEQUENT_ACTION_EVENT_FIRST_OXU2_1]);
      }
    }

    temp_event_none = TRUE;
    for (ii=TEN_CONSEQUENT_ACTION_EVENT_FIRST_OXU2_2;
         ii<=TEN_CONSEQUENT_ACTION_EVENT_LAST_OXU2_2; ii++) {
      if (ten_ohpp_get_sfc_ram_bit(module_id, row, ii) == 1) {
        if (temp_row_none) {
          CS_PRINT_OUTPUT("    ROW %d: %s\n", row, ten_consequent_actions_str[row]);
          temp_row_none = FALSE;
        }
        if (temp_event_none) {
          CS_PRINT_OUTPUT("       OxU2  #2 Terminator Events\n");
          temp_event_none = FALSE;
        }
        CS_PRINT_OUTPUT("        * %s\n",
          ten_consequent_action_events_oxux_str[ii-TEN_CONSEQUENT_ACTION_EVENT_FIRST_OXU2_2]);
      }
    }

    temp_event_none = TRUE;
    for (ii=TEN_CONSEQUENT_ACTION_EVENT_FIRST_OXU2_3;
         ii<=TEN_CONSEQUENT_ACTION_EVENT_LAST_OXU2_3; ii++) {
      if (ten_ohpp_get_sfc_ram_bit(module_id, row, ii) == 1) {
        if (temp_row_none) {
          CS_PRINT_OUTPUT("    ROW %d: %s\n", row, ten_consequent_actions_str[row]);
          temp_row_none = FALSE;
        }
        if (temp_event_none) {
          CS_PRINT_OUTPUT("       OxU2  #3 Terminator Events\n");
          temp_event_none = FALSE;
        }
        CS_PRINT_OUTPUT("        * %s\n",
          ten_consequent_action_events_oxux_str[ii-TEN_CONSEQUENT_ACTION_EVENT_FIRST_OXU2_3]);
      }
    }

    temp_event_none = TRUE;
    for (ii=TEN_CONSEQUENT_ACTION_EVENT_FIRST_OXU2_4;
         ii<=TEN_CONSEQUENT_ACTION_EVENT_LAST_OXU2_4; ii++) {
      if (ten_ohpp_get_sfc_ram_bit(module_id, row, ii) == 1) {
        if (temp_row_none) {
          CS_PRINT_OUTPUT("    ROW %d: %s\n", row, ten_consequent_actions_str[row]);
          temp_row_none = FALSE;
        }
        if (temp_event_none) {
          CS_PRINT_OUTPUT("       OxU2  #4 Terminator Events\n");
          temp_event_none = FALSE;
        }
        CS_PRINT_OUTPUT("        * %s\n",
          ten_consequent_action_events_oxux_str[ii-TEN_CONSEQUENT_ACTION_EVENT_FIRST_OXU2_4]);
      }
    }

    temp_event_none = TRUE;
    for (ii=TEN_CONSEQUENT_ACTION_EVENT_FIRST_OC192_1;
         ii<=TEN_CONSEQUENT_ACTION_EVENT_LAST_OC192_1; ii++) {
      if (ten_ohpp_get_sfc_ram_bit(module_id, row, ii) == 1) {
        if (temp_row_none) {
          CS_PRINT_OUTPUT("    ROW %d: %s\n", row, ten_consequent_actions_str[row]);
          temp_row_none = FALSE;
        }
        if (temp_event_none) {
          CS_PRINT_OUTPUT("       OC192 #1 Terminator Events\n");
          temp_event_none = FALSE;
        }
        CS_PRINT_OUTPUT("        * %s\n",
          ten_consequent_action_events_oc192_str[ii-TEN_CONSEQUENT_ACTION_EVENT_FIRST_OC192_1]);
      }
    }

    temp_event_none = TRUE;
    for (ii=TEN_CONSEQUENT_ACTION_EVENT_FIRST_OC192_2;
         ii<=TEN_CONSEQUENT_ACTION_EVENT_LAST_OC192_2; ii++) {
      if (ten_ohpp_get_sfc_ram_bit(module_id, row, ii) == 1) {
        if (temp_row_none) {
          CS_PRINT_OUTPUT("    ROW %d: %s\n", row, ten_consequent_actions_str[row]);
          temp_row_none = FALSE;
        }
        if (temp_event_none) {
          CS_PRINT_OUTPUT("       OC192 #2 Terminator Events\n");
          temp_event_none = FALSE;
        }
        CS_PRINT_OUTPUT("        * %s\n",
          ten_consequent_action_events_oc192_str[ii-TEN_CONSEQUENT_ACTION_EVENT_FIRST_OC192_2]);
      }
    }

    temp_event_none = TRUE;
    for (ii=TEN_CONSEQUENT_ACTION_EVENT_FIRST_OC192_3;
         ii<=TEN_CONSEQUENT_ACTION_EVENT_LAST_OC192_3; ii++) {
      if (ten_ohpp_get_sfc_ram_bit(module_id, row, ii) == 1) {
        if (temp_row_none) {
          CS_PRINT_OUTPUT("    ROW %d: %s\n", row, ten_consequent_actions_str[row]);
          temp_row_none = FALSE;
        }
        if (temp_event_none) {
          CS_PRINT_OUTPUT("       OC192 #3 Terminator Events\n");
          temp_event_none = FALSE;
        }
        CS_PRINT_OUTPUT("        * %s\n",
          ten_consequent_action_events_oc192_str[ii-TEN_CONSEQUENT_ACTION_EVENT_FIRST_OC192_3]);
      }
    }

    temp_event_none = TRUE;
    for (ii=TEN_CONSEQUENT_ACTION_EVENT_FIRST_OC192_4;
         ii<=TEN_CONSEQUENT_ACTION_EVENT_LAST_OC192_4; ii++) {
      if (ten_ohpp_get_sfc_ram_bit(module_id, row, ii) == 1) {
        if (temp_row_none) {
          CS_PRINT_OUTPUT("    ROW %d: %s\n", row, ten_consequent_actions_str[row]);
          temp_row_none = FALSE;
        }
        if (temp_event_none) {
          CS_PRINT_OUTPUT("       OC192 #4 Terminator Events\n");
          temp_event_none = FALSE;
        }
        CS_PRINT_OUTPUT("        * %s\n",
          ten_consequent_action_events_oc192_str[ii-TEN_CONSEQUENT_ACTION_EVENT_FIRST_OC192_4]);
      }
    }
    
    /* Bugzilla #38149 - update ten_hl_ohpp_dump_sfu API for T41 events  */
    if (ten_dev_is_t41(TEN_MOD_ID_TO_DEV_ID(module_id))) {
      temp_event_none = TRUE;
      for (ii=TEN_CONSEQUENT_ACTION_EVENT_FIRST_OXU3_TERM; ii<=TEN_CONSEQUENT_ACTION_EVENT_LAST_OXU3_TERM; ii++) {
        if (ten_ohpp_get_sfc_ram_bit(module_id, row, ii) == 1) {
          if (temp_row_none) {
            CS_PRINT_OUTPUT("    ROW %d: %s\n", row, ten_consequent_actions_str[row]);
            temp_row_none = FALSE;
          }
          if (temp_event_none) {
            CS_PRINT_OUTPUT("       CS604X OxU3 Terminator Events\n");
            temp_event_none = FALSE;
          }
          CS_PRINT_OUTPUT("        * %s\n",
            ten_consequent_action_events_cs604x_oxu3_str[ii-TEN_CONSEQUENT_ACTION_EVENT_FIRST_OXU3_TERM]);
        }
      }
      
      temp_event_none = TRUE;
      for (ii=TEN_CONSEQUENT_ACTION_EVENT_FIRST_OXU2_TERM_1; ii<=TEN_CONSEQUENT_ACTION_EVENT_LAST_OXU2_TERM_1; ii++) {
        if (ten_ohpp_get_sfc_ram_bit(module_id, row, ii) == 1) {
          if (temp_row_none) {
            CS_PRINT_OUTPUT("    ROW %d: %s\n", row, ten_consequent_actions_str[row]);
            temp_row_none = FALSE;
          }
          if (temp_event_none) {
            CS_PRINT_OUTPUT("       CS604X OxU2 #1 Terminator Events\n");
            temp_event_none = FALSE;
          }
          CS_PRINT_OUTPUT("        * %s\n",
            ten_consequent_action_events_cs604x_oxu2_terminator_channel_actions_str[ii-TEN_CONSEQUENT_ACTION_EVENT_FIRST_OXU2_TERM_1]);
        }
      }
      
      temp_event_none = TRUE;
      for (ii=TEN_CONSEQUENT_ACTION_EVENT_FIRST_OXU2_TERM_2; ii<=TEN_CONSEQUENT_ACTION_EVENT_LAST_OXU2_TERM_2; ii++) {
        if (ten_ohpp_get_sfc_ram_bit(module_id, row, ii) == 1) {
          if (temp_row_none) {
            CS_PRINT_OUTPUT("    ROW %d: %s\n", row, ten_consequent_actions_str[row]);
            temp_row_none = FALSE;
          }
          if (temp_event_none) {
            CS_PRINT_OUTPUT("       CS604X OxU2 #2 Terminator Events\n");
            temp_event_none = FALSE;
          }
          CS_PRINT_OUTPUT("        * %s\n",
            ten_consequent_action_events_cs604x_oxu2_terminator_channel_actions_str[ii-TEN_CONSEQUENT_ACTION_EVENT_FIRST_OXU2_TERM_2]);
        }
      }
      
      temp_event_none = TRUE;
      for (ii=TEN_CONSEQUENT_ACTION_EVENT_FIRST_OXU2_TERM_3; ii<=TEN_CONSEQUENT_ACTION_EVENT_LAST_OXU2_TERM_3; ii++) {
        if (ten_ohpp_get_sfc_ram_bit(module_id, row, ii) == 1) {
          if (temp_row_none) {
            CS_PRINT_OUTPUT("    ROW %d: %s\n", row, ten_consequent_actions_str[row]);
            temp_row_none = FALSE;
          }
          if (temp_event_none) {
            CS_PRINT_OUTPUT("       CS604X OxU2 #3 Terminator Events\n");
            temp_event_none = FALSE;
          }
          CS_PRINT_OUTPUT("        * %s\n",
            ten_consequent_action_events_cs604x_oxu2_terminator_channel_actions_str[ii-TEN_CONSEQUENT_ACTION_EVENT_FIRST_OXU2_TERM_3]);
        }
      }
      
      temp_event_none = TRUE;
      for (ii=TEN_CONSEQUENT_ACTION_EVENT_FIRST_OXU2_TERM_4; ii<=TEN_CONSEQUENT_ACTION_EVENT_LAST_OXU2_TERM_4; ii++) {
        if (ten_ohpp_get_sfc_ram_bit(module_id, row, ii) == 1) {
          if (temp_row_none) {
            CS_PRINT_OUTPUT("    ROW %d: %s\n", row, ten_consequent_actions_str[row]);
            temp_row_none = FALSE;
          }
          if (temp_event_none) {
            CS_PRINT_OUTPUT("       CS604X OxU2 #4 Terminator Events\n");
            temp_event_none = FALSE;
          }
          CS_PRINT_OUTPUT("        * %s\n",
            ten_consequent_action_events_cs604x_oxu2_terminator_channel_actions_str[ii-TEN_CONSEQUENT_ACTION_EVENT_FIRST_OXU2_TERM_4]);
        }
      }

      temp_event_none = TRUE;
      if (ten_ohpp_get_sfc_ram_bit(module_id, row, TEN_CONSEQUENT_ACTION_EVENT_40G_PP) == 1) {
        if (temp_row_none) {
          CS_PRINT_OUTPUT("    ROW %d: %s\n", row, ten_consequent_actions_str[row]);
          temp_row_none = FALSE;
        }
        if (temp_event_none) {
          CS_PRINT_OUTPUT("       CS604X 40G Packet Processor Events\n");
          temp_event_none = FALSE;
        }
        CS_PRINT_OUTPUT("        * %s\n", "Rx Failure Alarm from 40G Packet Processor");
      }

      for (ii=TEN_CONSEQUENT_ACTION_EVENT_10G_PP_CHAN1; ii<=TEN_CONSEQUENT_ACTION_EVENT_10G_PP_CHAN4; ii++) {
        temp_event_none = TRUE;
        if (ten_ohpp_get_sfc_ram_bit(module_id, row, ii) == 1) {
          if (temp_row_none) {
            CS_PRINT_OUTPUT("    ROW %d: %s\n", row, ten_consequent_actions_str[row]);
            temp_row_none = FALSE;
          }
          if (temp_event_none) {
            CS_PRINT_OUTPUT("       CS604X 10G #%d Packet Processor Events\n", ii-(TEN_CONSEQUENT_ACTION_EVENT_10G_PP_CHAN1-1));
            temp_event_none = FALSE;
          }
          CS_PRINT_OUTPUT("        * %s %d\n", "Rx Failure Alarm from 10G Packet Processor Channel ", ii-(TEN_CONSEQUENT_ACTION_EVENT_10G_PP_CHAN1-1));
        }
      }
    }
  }

  CS_PRINT_OUTPUT("\n  Consequent Action Events set for Other Module\n");

  for (row=0; row<TEN_CONSEQUENT_ACTION_ROW_COUNT; row++) {

    temp_row_none   = TRUE;

    temp_event_none = TRUE;
    for (ii=TEN_CONSEQUENT_ACTION_EVENT_FIRST_GLOBAL;
         ii<=TEN_CONSEQUENT_ACTION_EVENT_LAST_GLOBAL; ii++) {
      if (ten_ohpp_get_sfc_ram_bit(module_id, row, ii+TEN_CONSEQUENT_ACTION_EVENT_OTHER_OFFSET) == 1) {
        if (temp_row_none) {
          CS_PRINT_OUTPUT("    ROW %d: %s\n", row, ten_consequent_actions_str[row]);
          temp_row_none = FALSE;
        }
        if (temp_event_none) {
          CS_PRINT_OUTPUT("      Global Input Events\n");
          temp_event_none = FALSE;
        }
        CS_PRINT_OUTPUT("        * %s\n",
          ten_consequent_action_events_global_str[ii-TEN_CONSEQUENT_ACTION_EVENT_FIRST_GLOBAL]);
      }
    }

    temp_event_none = TRUE;
    for (ii=TEN_CONSEQUENT_ACTION_EVENT_FIRST_OXU3;
         ii<=TEN_CONSEQUENT_ACTION_EVENT_LAST_OXU3; ii++) {
      if (ten_ohpp_get_sfc_ram_bit(module_id, row, ii+TEN_CONSEQUENT_ACTION_EVENT_OTHER_OFFSET) == 1) {
        if (temp_row_none) {
          CS_PRINT_OUTPUT("    ROW %d: %s\n", row, ten_consequent_actions_str[row]);
          temp_row_none = FALSE;
        }
        if (temp_event_none) {
          CS_PRINT_OUTPUT("       OxU3 Terminator Events\n");
          temp_event_none = FALSE;
        }
        CS_PRINT_OUTPUT("        * %s\n",
          ten_consequent_action_events_oxux_str[ii-TEN_CONSEQUENT_ACTION_EVENT_FIRST_OXU3]);
      }
    }

    temp_event_none = TRUE;
    for (ii=TEN_CONSEQUENT_ACTION_EVENT_FIRST_OXU2_1;
         ii<=TEN_CONSEQUENT_ACTION_EVENT_LAST_OXU2_1; ii++) {
      if (ten_ohpp_get_sfc_ram_bit(module_id, row, ii+TEN_CONSEQUENT_ACTION_EVENT_OTHER_OFFSET) == 1) {
        if (temp_row_none) {
          CS_PRINT_OUTPUT("    ROW %d: %s\n", row, ten_consequent_actions_str[row]);
          temp_row_none = FALSE;
        }
        if (temp_event_none) {
          CS_PRINT_OUTPUT("       OxU2  #1 Terminator Events\n");
          temp_event_none = FALSE;
        }
        CS_PRINT_OUTPUT("        * %s\n",
          ten_consequent_action_events_oxux_str[ii-TEN_CONSEQUENT_ACTION_EVENT_FIRST_OXU2_1]);
      }
    }

    temp_event_none = TRUE;
    for (ii=TEN_CONSEQUENT_ACTION_EVENT_FIRST_OXU2_2;
         ii<=TEN_CONSEQUENT_ACTION_EVENT_LAST_OXU2_2; ii++) {
      if (ten_ohpp_get_sfc_ram_bit(module_id, row, ii+TEN_CONSEQUENT_ACTION_EVENT_OTHER_OFFSET) == 1) {
        if (temp_row_none) {
          CS_PRINT_OUTPUT("    ROW %d: %s\n", row, ten_consequent_actions_str[row]);
          temp_row_none = FALSE;
        }
        if (temp_event_none) {
          CS_PRINT_OUTPUT("       OxU2  #2 Terminator Events\n");
          temp_event_none = FALSE;
        }
        CS_PRINT_OUTPUT("        * %s\n",
          ten_consequent_action_events_oxux_str[ii-TEN_CONSEQUENT_ACTION_EVENT_FIRST_OXU2_2]);
      }
    }

    temp_event_none = TRUE;
    for (ii=TEN_CONSEQUENT_ACTION_EVENT_FIRST_OXU2_3;
         ii<=TEN_CONSEQUENT_ACTION_EVENT_LAST_OXU2_3; ii++) {
      if (ten_ohpp_get_sfc_ram_bit(module_id, row, ii+TEN_CONSEQUENT_ACTION_EVENT_OTHER_OFFSET) == 1) {
        if (temp_row_none) {
          CS_PRINT_OUTPUT("    ROW %d: %s\n", row, ten_consequent_actions_str[row]);
          temp_row_none = FALSE;
        }
        if (temp_event_none) {
          CS_PRINT_OUTPUT("       OxU2  #3 Terminator Events\n");
          temp_event_none = FALSE;
        }
        CS_PRINT_OUTPUT("        * %s\n",
          ten_consequent_action_events_oxux_str[ii-TEN_CONSEQUENT_ACTION_EVENT_FIRST_OXU2_3]);
      }
    }

    temp_event_none = TRUE;
    for (ii=TEN_CONSEQUENT_ACTION_EVENT_FIRST_OXU2_4;
         ii<=TEN_CONSEQUENT_ACTION_EVENT_LAST_OXU2_4; ii++) {
      if (ten_ohpp_get_sfc_ram_bit(module_id, row, ii+TEN_CONSEQUENT_ACTION_EVENT_OTHER_OFFSET) == 1) {
        if (temp_row_none) {
          CS_PRINT_OUTPUT("    ROW %d: %s\n", row, ten_consequent_actions_str[row]);
          temp_row_none = FALSE;
        }
        if (temp_event_none) {
          CS_PRINT_OUTPUT("       OxU2  #4 Terminator Events\n");
          temp_event_none = FALSE;
        }
        CS_PRINT_OUTPUT("        * %s\n",
          ten_consequent_action_events_oxux_str[ii-TEN_CONSEQUENT_ACTION_EVENT_FIRST_OXU2_4]);
      }
    }

    temp_event_none = TRUE;
    for (ii=TEN_CONSEQUENT_ACTION_EVENT_FIRST_OC192_1;
         ii<=TEN_CONSEQUENT_ACTION_EVENT_LAST_OC192_1; ii++) {
      if (ten_ohpp_get_sfc_ram_bit(module_id, row, ii+TEN_CONSEQUENT_ACTION_EVENT_OTHER_OFFSET) == 1) {
        if (temp_row_none) {
          CS_PRINT_OUTPUT("    ROW %d: %s\n", row, ten_consequent_actions_str[row]);
          temp_row_none = FALSE;
        }
        if (temp_event_none) {
          CS_PRINT_OUTPUT("       OC192 #1 Terminator Events\n");
          temp_event_none = FALSE;
        }
        CS_PRINT_OUTPUT("        * %s\n",
          ten_consequent_action_events_oc192_str[ii-TEN_CONSEQUENT_ACTION_EVENT_FIRST_OC192_1]);
      }
    }

    temp_event_none = TRUE;
    for (ii=TEN_CONSEQUENT_ACTION_EVENT_FIRST_OC192_2;
         ii<=TEN_CONSEQUENT_ACTION_EVENT_LAST_OC192_2; ii++) {
      if (ten_ohpp_get_sfc_ram_bit(module_id, row, ii+TEN_CONSEQUENT_ACTION_EVENT_OTHER_OFFSET) == 1) {
        if (temp_row_none) {
          CS_PRINT_OUTPUT("    ROW %d: %s\n", row, ten_consequent_actions_str[row]);
          temp_row_none = FALSE;
        }
        if (temp_event_none) {
          CS_PRINT_OUTPUT("       OC192 #2 Terminator Events\n");
          temp_event_none = FALSE;
        }
        CS_PRINT_OUTPUT("        * %s\n",
          ten_consequent_action_events_oc192_str[ii-TEN_CONSEQUENT_ACTION_EVENT_FIRST_OC192_2]);
      }
    }

    temp_event_none = TRUE;
    for (ii=TEN_CONSEQUENT_ACTION_EVENT_FIRST_OC192_3;
         ii<=TEN_CONSEQUENT_ACTION_EVENT_LAST_OC192_3; ii++) {
      if (ten_ohpp_get_sfc_ram_bit(module_id, row, ii+TEN_CONSEQUENT_ACTION_EVENT_OTHER_OFFSET) == 1) {
        if (temp_row_none) {
          CS_PRINT_OUTPUT("    ROW %d: %s\n", row, ten_consequent_actions_str[row]);
          temp_row_none = FALSE;
        }
        if (temp_event_none) {
          CS_PRINT_OUTPUT("       OC192 #3 Terminator Events\n");
          temp_event_none = FALSE;
        }
        CS_PRINT_OUTPUT("        * %s\n",
          ten_consequent_action_events_oc192_str[ii-TEN_CONSEQUENT_ACTION_EVENT_FIRST_OC192_3]);
      }
    }

    temp_event_none = TRUE;
    for (ii=TEN_CONSEQUENT_ACTION_EVENT_FIRST_OC192_4;
         ii<=TEN_CONSEQUENT_ACTION_EVENT_LAST_OC192_4; ii++) {
      if (ten_ohpp_get_sfc_ram_bit(module_id, row, ii+TEN_CONSEQUENT_ACTION_EVENT_OTHER_OFFSET) == 1) {
        if (temp_row_none) {
          CS_PRINT_OUTPUT("    ROW %d: %s\n", row, ten_consequent_actions_str[row]);
          temp_row_none = FALSE;
        }
        if (temp_event_none) {
          CS_PRINT_OUTPUT("       OC192 #4 Terminator Events\n");
          temp_event_none = FALSE;
        }
        CS_PRINT_OUTPUT("        * %s\n",
          ten_consequent_action_events_oc192_str[ii-TEN_CONSEQUENT_ACTION_EVENT_FIRST_OC192_4]);
      }
    }
    
    /* Bugzilla #38149 - update ten_hl_ohpp_dump_sfu API for T41 events  */
    if (ten_dev_is_t41(TEN_MOD_ID_TO_DEV_ID(module_id))) {
      temp_event_none = TRUE;
      for (ii=TEN_CONSEQUENT_ACTION_EVENT_FIRST_OXU3_TERM; ii<=TEN_CONSEQUENT_ACTION_EVENT_LAST_OXU3_TERM; ii++) {
        if (ten_ohpp_get_sfc_ram_bit(module_id, row, ii+TEN_CONSEQUENT_ACTION_EVENT_OTHER_OFFSET_T41) == 1) {
          if (temp_row_none) {
            CS_PRINT_OUTPUT("    ROW %d: %s\n", row, ten_consequent_actions_str[row]);
            temp_row_none = FALSE;
          }
          if (temp_event_none) {
            CS_PRINT_OUTPUT("       CS604X OxU3 Terminator Events\n");
            temp_event_none = FALSE;
          }
          CS_PRINT_OUTPUT("        * %s\n",
            ten_consequent_action_events_cs604x_oxu3_str[ii-TEN_CONSEQUENT_ACTION_EVENT_FIRST_OXU3_TERM]);
        }
      }
      
      temp_event_none = TRUE;
      for (ii=TEN_CONSEQUENT_ACTION_EVENT_FIRST_OXU2_TERM_1; ii<=TEN_CONSEQUENT_ACTION_EVENT_LAST_OXU2_TERM_1; ii++) {
        if (ten_ohpp_get_sfc_ram_bit(module_id, row, ii+TEN_CONSEQUENT_ACTION_EVENT_OTHER_OFFSET_T41) == 1) {
          if (temp_row_none) {
            CS_PRINT_OUTPUT("    ROW %d: %s\n", row, ten_consequent_actions_str[row]);
            temp_row_none = FALSE;
          }
          if (temp_event_none) {
            CS_PRINT_OUTPUT("       CS604X OxU2 #1 Terminator Events\n");
            temp_event_none = FALSE;
          }
          CS_PRINT_OUTPUT("        * %s\n",
            ten_consequent_action_events_cs604x_oxu2_terminator_channel_actions_str[ii-TEN_CONSEQUENT_ACTION_EVENT_FIRST_OXU2_TERM_1]);
        }
      }
      
      temp_event_none = TRUE;
      for (ii=TEN_CONSEQUENT_ACTION_EVENT_FIRST_OXU2_TERM_2; ii<=TEN_CONSEQUENT_ACTION_EVENT_LAST_OXU2_TERM_2; ii++) {
        if (ten_ohpp_get_sfc_ram_bit(module_id, row, ii+TEN_CONSEQUENT_ACTION_EVENT_OTHER_OFFSET_T41) == 1) {
          if (temp_row_none) {
            CS_PRINT_OUTPUT("    ROW %d: %s\n", row, ten_consequent_actions_str[row]);
            temp_row_none = FALSE;
          }
          if (temp_event_none) {
            CS_PRINT_OUTPUT("       CS604X OxU2 #2 Terminator Events\n");
            temp_event_none = FALSE;
          }
          CS_PRINT_OUTPUT("        * %s\n",
            ten_consequent_action_events_cs604x_oxu2_terminator_channel_actions_str[ii-TEN_CONSEQUENT_ACTION_EVENT_FIRST_OXU2_TERM_2]);
        }
      }
      
      temp_event_none = TRUE;
      for (ii=TEN_CONSEQUENT_ACTION_EVENT_FIRST_OXU2_TERM_3; ii<=TEN_CONSEQUENT_ACTION_EVENT_LAST_OXU2_TERM_3; ii++) {
        if (ten_ohpp_get_sfc_ram_bit(module_id, row, ii+TEN_CONSEQUENT_ACTION_EVENT_OTHER_OFFSET_T41) == 1) {
          if (temp_row_none) {
            CS_PRINT_OUTPUT("    ROW %d: %s\n", row, ten_consequent_actions_str[row]);
            temp_row_none = FALSE;
          }
          if (temp_event_none) {
            CS_PRINT_OUTPUT("       CS604X OxU2 #3 Terminator Events\n");
            temp_event_none = FALSE;
          }
          CS_PRINT_OUTPUT("        * %s\n",
            ten_consequent_action_events_cs604x_oxu2_terminator_channel_actions_str[ii-TEN_CONSEQUENT_ACTION_EVENT_FIRST_OXU2_TERM_3]);
        }
      }
      
      temp_event_none = TRUE;
      for (ii=TEN_CONSEQUENT_ACTION_EVENT_FIRST_OXU2_TERM_4; ii<=TEN_CONSEQUENT_ACTION_EVENT_LAST_OXU2_TERM_4; ii++) {
        if (ten_ohpp_get_sfc_ram_bit(module_id, row, ii+TEN_CONSEQUENT_ACTION_EVENT_OTHER_OFFSET_T41) == 1) {
          if (temp_row_none) {
            CS_PRINT_OUTPUT("    ROW %d: %s\n", row, ten_consequent_actions_str[row]);
            temp_row_none = FALSE;
          }
          if (temp_event_none) {
            CS_PRINT_OUTPUT("       CS604X OxU2 #4 Terminator Events\n");
            temp_event_none = FALSE;
          }
          CS_PRINT_OUTPUT("        * %s\n",
            ten_consequent_action_events_cs604x_oxu2_terminator_channel_actions_str[ii-TEN_CONSEQUENT_ACTION_EVENT_FIRST_OXU2_TERM_4]);
        }
      }

      temp_event_none = TRUE;
      if (ten_ohpp_get_sfc_ram_bit(module_id, row, TEN_CONSEQUENT_ACTION_EVENT_40G_PP+TEN_CONSEQUENT_ACTION_EVENT_OTHER_OFFSET_T41) == 1) {
        if (temp_row_none) {
          CS_PRINT_OUTPUT("    ROW %d: %s\n", row, ten_consequent_actions_str[row]);
          temp_row_none = FALSE;
        }
        if (temp_event_none) {
          CS_PRINT_OUTPUT("       CS604X 40G Packet Processor Events\n");
          temp_event_none = FALSE;
        }
        CS_PRINT_OUTPUT("        * %s\n", "Rx Failure Alarm from 40G Packet Processor");
      }

      for (ii=TEN_CONSEQUENT_ACTION_EVENT_10G_PP_CHAN1; ii<=TEN_CONSEQUENT_ACTION_EVENT_10G_PP_CHAN4; ii++) {
        temp_event_none = TRUE;
        if (ten_ohpp_get_sfc_ram_bit(module_id, row, ii+TEN_CONSEQUENT_ACTION_EVENT_OTHER_OFFSET_T41) == 1) {
          if (temp_row_none) {
            CS_PRINT_OUTPUT("    ROW %d: %s\n", row, ten_consequent_actions_str[row]);
            temp_row_none = FALSE;
          }
          if (temp_event_none) {
            CS_PRINT_OUTPUT("       CS604X 10G #%d Packet Processor Events\n", ii-(TEN_CONSEQUENT_ACTION_EVENT_10G_PP_CHAN1-1));
            temp_event_none = FALSE;
          }
          CS_PRINT_OUTPUT("        * %s %d\n", "Rx Failure Alarm from 10G Packet Processor Channel ", ii-(TEN_CONSEQUENT_ACTION_EVENT_10G_PP_CHAN1-1));
        }
      }
    }
  }

  CS_PRINT_OUTPUT("\n  End of Consequent Action Event dump.\n");

  /* Turn on reg read/write dumps */
  g_pTEN->drvr_flag &= ~TEN_DRVR_LOG_SUSPEND;

  return(CS_OK);
}

/* Bugzilla 21101: SFU Config dump enhancements */
/****************************************************************/
/* $rtn_hdr_start  OHPP DUMP SHADOW CONSEQUENT ACTIONS ALL ROWS */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : HIGH LEVEL                                      */
/* CHIP       : Tenabo                                          */
cs_status ten_hl_ohpp_dump_shadow_consequent_actions_all (cs_uint16 module_id,
                                                          cs_uint16 bank)
/* INPUTS     : o Module Id                                     */
/*              o Bank                                          */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* A text dump of the of the Consequent Action Events set in    */
/* the Shadow SFC RAM to trigger all row actions.               */
/*                                                              */
/* The [bank] parameter is specified as:                        */
/*   0..1                                                       */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  cs_uint16 ii;
  cs_uint16 row;
  cs_boolean temp_event_none;
  cs_boolean temp_row_none;
  cs_uint32 err_code = 0;

  /* Turn off reg read/write dumps because API is so print intensive */
  g_pTEN->drvr_flag |= TEN_DRVR_LOG_SUSPEND;

  if (bank > 1) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": bank out of range.  s/b 0..1.");
    return(CS_ERROR);
  } 
  if (!(TEN_IS_MOD_VALID(module_id, &err_code))) {
    CS_PRINT_OUTPUT("ERROR: API   -Id (0x%x) is invalid!\n", module_id);
    return(CS_ERROR);
  }
 
  CS_PRINT_OUTPUT("\n  Shadow Consequent Action Events set for Own Module\n");

  for (row=0; row<TEN_CONSEQUENT_ACTION_ROW_COUNT; row++) {

    temp_row_none   = TRUE;

    temp_event_none = TRUE;
    for (ii=TEN_CONSEQUENT_ACTION_EVENT_FIRST_GLOBAL;
         ii<=TEN_CONSEQUENT_ACTION_EVENT_LAST_GLOBAL; ii++) {
      if (ten_ohpp_get_shadow_sfc_ram_bit(module_id, bank, row, ii) == 1) {
        if (temp_row_none) {
          CS_PRINT_OUTPUT("    ROW %d: %s\n", row, ten_consequent_actions_str[row]);
          temp_row_none = FALSE;
        }
        if (temp_event_none) {
          CS_PRINT_OUTPUT("      Global Input Events\n");
          temp_event_none = FALSE;
        }
        CS_PRINT_OUTPUT("        * %s\n",
          ten_consequent_action_events_global_str[ii-TEN_CONSEQUENT_ACTION_EVENT_FIRST_GLOBAL]);
      }
    }

    temp_event_none = TRUE;
    for (ii=TEN_CONSEQUENT_ACTION_EVENT_FIRST_OXU3;
         ii<=TEN_CONSEQUENT_ACTION_EVENT_LAST_OXU3; ii++) {
      if (ten_ohpp_get_shadow_sfc_ram_bit(module_id, bank, row, ii) == 1) {
        if (temp_row_none) {
          CS_PRINT_OUTPUT("    ROW %d: %s\n", row, ten_consequent_actions_str[row]);
          temp_row_none = FALSE;
        }
        if (temp_event_none) {
          CS_PRINT_OUTPUT("       OxU3 Terminator Events\n");
          temp_event_none = FALSE;
        }
        CS_PRINT_OUTPUT("        * %s\n",
          ten_consequent_action_events_oxux_str[ii-TEN_CONSEQUENT_ACTION_EVENT_FIRST_OXU3]);
      }
    }

    temp_event_none = TRUE;
    for (ii=TEN_CONSEQUENT_ACTION_EVENT_FIRST_OXU2_1;
         ii<=TEN_CONSEQUENT_ACTION_EVENT_LAST_OXU2_1; ii++) {
      if (ten_ohpp_get_shadow_sfc_ram_bit(module_id, bank, row, ii) == 1) {
        if (temp_row_none) {
          CS_PRINT_OUTPUT("    ROW %d: %s\n", row, ten_consequent_actions_str[row]);
          temp_row_none = FALSE;
        }
        if (temp_event_none) {
          CS_PRINT_OUTPUT("       OxU2  #1 Terminator Events\n");
          temp_event_none = FALSE;
        }
        CS_PRINT_OUTPUT("        * %s\n",
          ten_consequent_action_events_oxux_str[ii-TEN_CONSEQUENT_ACTION_EVENT_FIRST_OXU2_1]);
      }
    }

    temp_event_none = TRUE;
    for (ii=TEN_CONSEQUENT_ACTION_EVENT_FIRST_OXU2_2;
         ii<=TEN_CONSEQUENT_ACTION_EVENT_LAST_OXU2_2; ii++) {
      if (ten_ohpp_get_shadow_sfc_ram_bit(module_id, bank, row, ii) == 1) {
        if (temp_row_none) {
          CS_PRINT_OUTPUT("    ROW %d: %s\n", row, ten_consequent_actions_str[row]);
          temp_row_none = FALSE;
        }
        if (temp_event_none) {
          CS_PRINT_OUTPUT("       OxU2  #2 Terminator Events\n");
          temp_event_none = FALSE;
        }
        CS_PRINT_OUTPUT("        * %s\n",
          ten_consequent_action_events_oxux_str[ii-TEN_CONSEQUENT_ACTION_EVENT_FIRST_OXU2_2]);
      }
    }

    temp_event_none = TRUE;
    for (ii=TEN_CONSEQUENT_ACTION_EVENT_FIRST_OXU2_3;
         ii<=TEN_CONSEQUENT_ACTION_EVENT_LAST_OXU2_3; ii++) {
      if (ten_ohpp_get_shadow_sfc_ram_bit(module_id, bank, row, ii) == 1) {
        if (temp_row_none) {
          CS_PRINT_OUTPUT("    ROW %d: %s\n", row, ten_consequent_actions_str[row]);
          temp_row_none = FALSE;
        }
        if (temp_event_none) {
          CS_PRINT_OUTPUT("       OxU2  #3 Terminator Events\n");
          temp_event_none = FALSE;
        }
        CS_PRINT_OUTPUT("        * %s\n",
          ten_consequent_action_events_oxux_str[ii-TEN_CONSEQUENT_ACTION_EVENT_FIRST_OXU2_3]);
      }
    }

    temp_event_none = TRUE;
    for (ii=TEN_CONSEQUENT_ACTION_EVENT_FIRST_OXU2_4;
         ii<=TEN_CONSEQUENT_ACTION_EVENT_LAST_OXU2_4; ii++) {
      if (ten_ohpp_get_shadow_sfc_ram_bit(module_id, bank, row, ii) == 1) {
        if (temp_row_none) {
          CS_PRINT_OUTPUT("    ROW %d: %s\n", row, ten_consequent_actions_str[row]);
          temp_row_none = FALSE;
        }
        if (temp_event_none) {
          CS_PRINT_OUTPUT("       OxU2  #4 Terminator Events\n");
          temp_event_none = FALSE;
        }
        CS_PRINT_OUTPUT("        * %s\n",
          ten_consequent_action_events_oxux_str[ii-TEN_CONSEQUENT_ACTION_EVENT_FIRST_OXU2_4]);
      }
    }

    temp_event_none = TRUE;
    for (ii=TEN_CONSEQUENT_ACTION_EVENT_FIRST_OC192_1;
         ii<=TEN_CONSEQUENT_ACTION_EVENT_LAST_OC192_1; ii++) {
      if (ten_ohpp_get_shadow_sfc_ram_bit(module_id, bank, row, ii) == 1) {
        if (temp_row_none) {
          CS_PRINT_OUTPUT("    ROW %d: %s\n", row, ten_consequent_actions_str[row]);
          temp_row_none = FALSE;
        }
        if (temp_event_none) {
          CS_PRINT_OUTPUT("       OC192 #1 Terminator Events\n");
          temp_event_none = FALSE;
        }
        CS_PRINT_OUTPUT("        * %s\n",
          ten_consequent_action_events_oc192_str[ii-TEN_CONSEQUENT_ACTION_EVENT_FIRST_OC192_1]);
      }
    }

    temp_event_none = TRUE;
    for (ii=TEN_CONSEQUENT_ACTION_EVENT_FIRST_OC192_2;
         ii<=TEN_CONSEQUENT_ACTION_EVENT_LAST_OC192_2; ii++) {
      if (ten_ohpp_get_shadow_sfc_ram_bit(module_id, bank, row, ii) == 1) {
        if (temp_row_none) {
          CS_PRINT_OUTPUT("    ROW %d: %s\n", row, ten_consequent_actions_str[row]);
          temp_row_none = FALSE;
        }
        if (temp_event_none) {
          CS_PRINT_OUTPUT("       OC192 #2 Terminator Events\n");
          temp_event_none = FALSE;
        }
        CS_PRINT_OUTPUT("        * %s\n",
          ten_consequent_action_events_oc192_str[ii-TEN_CONSEQUENT_ACTION_EVENT_FIRST_OC192_2]);
      }
    }

    temp_event_none = TRUE;
    for (ii=TEN_CONSEQUENT_ACTION_EVENT_FIRST_OC192_3;
         ii<=TEN_CONSEQUENT_ACTION_EVENT_LAST_OC192_3; ii++) {
      if (ten_ohpp_get_shadow_sfc_ram_bit(module_id, bank, row, ii) == 1) {
        if (temp_row_none) {
          CS_PRINT_OUTPUT("    ROW %d: %s\n", row, ten_consequent_actions_str[row]);
          temp_row_none = FALSE;
        }
        if (temp_event_none) {
          CS_PRINT_OUTPUT("       OC192 #3 Terminator Events\n");
          temp_event_none = FALSE;
        }
        CS_PRINT_OUTPUT("        * %s\n",
          ten_consequent_action_events_oc192_str[ii-TEN_CONSEQUENT_ACTION_EVENT_FIRST_OC192_3]);
      }
    }

    temp_event_none = TRUE;
    for (ii=TEN_CONSEQUENT_ACTION_EVENT_FIRST_OC192_4;
         ii<=TEN_CONSEQUENT_ACTION_EVENT_LAST_OC192_4; ii++) {
      if (ten_ohpp_get_shadow_sfc_ram_bit(module_id, bank, row, ii) == 1) {
        if (temp_row_none) {
          CS_PRINT_OUTPUT("    ROW %d: %s\n", row, ten_consequent_actions_str[row]);
          temp_row_none = FALSE;
        }
        if (temp_event_none) {
          CS_PRINT_OUTPUT("       OC192 #4 Terminator Events\n");
          temp_event_none = FALSE;
        }
        CS_PRINT_OUTPUT("        * %s\n",
          ten_consequent_action_events_oc192_str[ii-TEN_CONSEQUENT_ACTION_EVENT_FIRST_OC192_4]);
      }
    }
    
    /* Bugzilla #38149 - update ten_hl_ohpp_dump_sfu API for T41 events  */
    if (ten_dev_is_t41(TEN_MOD_ID_TO_DEV_ID(module_id))) {
      temp_event_none = TRUE;
      for (ii=TEN_CONSEQUENT_ACTION_EVENT_FIRST_OXU3_TERM; ii<=TEN_CONSEQUENT_ACTION_EVENT_LAST_OXU3_TERM; ii++) {
        if (ten_ohpp_get_shadow_sfc_ram_bit(module_id, bank, row, ii) == 1) {
          if (temp_row_none) {
            CS_PRINT_OUTPUT("    ROW %d: %s\n", row, ten_consequent_actions_str[row]);
            temp_row_none = FALSE;
          }
          if (temp_event_none) {
            CS_PRINT_OUTPUT("       CS604X OxU3 Terminator Events\n");
            temp_event_none = FALSE;
          }
          CS_PRINT_OUTPUT("        * %s\n",
            ten_consequent_action_events_cs604x_oxu3_str[ii-TEN_CONSEQUENT_ACTION_EVENT_FIRST_OXU3_TERM]);
        }
      }
      
      temp_event_none = TRUE;
      for (ii=TEN_CONSEQUENT_ACTION_EVENT_FIRST_OXU2_TERM_1; ii<=TEN_CONSEQUENT_ACTION_EVENT_LAST_OXU2_TERM_1; ii++) {
        if (ten_ohpp_get_shadow_sfc_ram_bit(module_id, bank, row, ii) == 1) {
          if (temp_row_none) {
            CS_PRINT_OUTPUT("    ROW %d: %s\n", row, ten_consequent_actions_str[row]);
            temp_row_none = FALSE;
          }
          if (temp_event_none) {
            CS_PRINT_OUTPUT("       CS604X OxU2 #1 Terminator Events\n");
            temp_event_none = FALSE;
          }
          CS_PRINT_OUTPUT("        * %s\n",
            ten_consequent_action_events_cs604x_oxu2_terminator_channel_actions_str[ii-TEN_CONSEQUENT_ACTION_EVENT_FIRST_OXU2_TERM_1]);
        }
      }
      
      temp_event_none = TRUE;
      for (ii=TEN_CONSEQUENT_ACTION_EVENT_FIRST_OXU2_TERM_2; ii<=TEN_CONSEQUENT_ACTION_EVENT_LAST_OXU2_TERM_2; ii++) {
        if (ten_ohpp_get_shadow_sfc_ram_bit(module_id, bank, row, ii) == 1) {
          if (temp_row_none) {
            CS_PRINT_OUTPUT("    ROW %d: %s\n", row, ten_consequent_actions_str[row]);
            temp_row_none = FALSE;
          }
          if (temp_event_none) {
            CS_PRINT_OUTPUT("       CS604X OxU2 #2 Terminator Events\n");
            temp_event_none = FALSE;
          }
          CS_PRINT_OUTPUT("        * %s\n",
            ten_consequent_action_events_cs604x_oxu2_terminator_channel_actions_str[ii-TEN_CONSEQUENT_ACTION_EVENT_FIRST_OXU2_TERM_2]);
        }
      }
      
      temp_event_none = TRUE;
      for (ii=TEN_CONSEQUENT_ACTION_EVENT_FIRST_OXU2_TERM_3; ii<=TEN_CONSEQUENT_ACTION_EVENT_LAST_OXU2_TERM_3; ii++) {
        if (ten_ohpp_get_shadow_sfc_ram_bit(module_id, bank, row, ii) == 1) {
          if (temp_row_none) {
            CS_PRINT_OUTPUT("    ROW %d: %s\n", row, ten_consequent_actions_str[row]);
            temp_row_none = FALSE;
          }
          if (temp_event_none) {
            CS_PRINT_OUTPUT("       CS604X OxU2 #3 Terminator Events\n");
            temp_event_none = FALSE;
          }
          CS_PRINT_OUTPUT("        * %s\n",
            ten_consequent_action_events_cs604x_oxu2_terminator_channel_actions_str[ii-TEN_CONSEQUENT_ACTION_EVENT_FIRST_OXU2_TERM_3]);
        }
      }
      
      temp_event_none = TRUE;
      for (ii=TEN_CONSEQUENT_ACTION_EVENT_FIRST_OXU2_TERM_4; ii<=TEN_CONSEQUENT_ACTION_EVENT_LAST_OXU2_TERM_4; ii++) {
        if (ten_ohpp_get_shadow_sfc_ram_bit(module_id, bank, row, ii) == 1) {
          if (temp_row_none) {
            CS_PRINT_OUTPUT("    ROW %d: %s\n", row, ten_consequent_actions_str[row]);
            temp_row_none = FALSE;
          }
          if (temp_event_none) {
            CS_PRINT_OUTPUT("       CS604X OxU2 #4 Terminator Events\n");
            temp_event_none = FALSE;
          }
          CS_PRINT_OUTPUT("        * %s\n",
            ten_consequent_action_events_cs604x_oxu2_terminator_channel_actions_str[ii-TEN_CONSEQUENT_ACTION_EVENT_FIRST_OXU2_TERM_4]);
        }
      }

      temp_event_none = TRUE;
      if (ten_ohpp_get_shadow_sfc_ram_bit(module_id, bank, row, TEN_CONSEQUENT_ACTION_EVENT_40G_PP) == 1) {
        if (temp_row_none) {
          CS_PRINT_OUTPUT("    ROW %d: %s\n", row, ten_consequent_actions_str[row]);
          temp_row_none = FALSE;
        }
        if (temp_event_none) {
          CS_PRINT_OUTPUT("       CS604X 40G Packet Processor Events\n");
          temp_event_none = FALSE;
        }
        CS_PRINT_OUTPUT("        * %s\n", "Rx Failure Alarm from 40G Packet Processor");
      }

      for (ii=TEN_CONSEQUENT_ACTION_EVENT_10G_PP_CHAN1; ii<=TEN_CONSEQUENT_ACTION_EVENT_10G_PP_CHAN4; ii++) {
        temp_event_none = TRUE;
        if (ten_ohpp_get_shadow_sfc_ram_bit(module_id, bank, row, ii) == 1) {
          if (temp_row_none) {
            CS_PRINT_OUTPUT("    ROW %d: %s\n", row, ten_consequent_actions_str[row]);
            temp_row_none = FALSE;
          }
          if (temp_event_none) {
            CS_PRINT_OUTPUT("       CS604X 10G #%d Packet Processor Events\n", ii-(TEN_CONSEQUENT_ACTION_EVENT_10G_PP_CHAN1-1));
            temp_event_none = FALSE;
          }
          CS_PRINT_OUTPUT("        * %s %d\n", "Rx Failure Alarm from 10G Packet Processor Channel ", ii-(TEN_CONSEQUENT_ACTION_EVENT_10G_PP_CHAN1-1));
        }
      }
    }
  }

  CS_PRINT_OUTPUT("\n  Shadow Consequent Action Events set for Other Module\n");

  for (row=0; row<TEN_CONSEQUENT_ACTION_ROW_COUNT; row++) {

    temp_row_none   = TRUE;

    temp_event_none = TRUE;
    for (ii=TEN_CONSEQUENT_ACTION_EVENT_FIRST_GLOBAL;
         ii<=TEN_CONSEQUENT_ACTION_EVENT_LAST_GLOBAL; ii++) {
      if (ten_ohpp_get_shadow_sfc_ram_bit(module_id, bank, row, ii+TEN_CONSEQUENT_ACTION_EVENT_OTHER_OFFSET) == 1) {
        if (temp_row_none) {
          CS_PRINT_OUTPUT("    ROW %d: %s\n", row, ten_consequent_actions_str[row]);
          temp_row_none = FALSE;
        }
        if (temp_event_none) {
          CS_PRINT_OUTPUT("      Global Input Events\n");
          temp_event_none = FALSE;
        }
        CS_PRINT_OUTPUT("        * %s\n",
          ten_consequent_action_events_global_str[ii-TEN_CONSEQUENT_ACTION_EVENT_FIRST_GLOBAL]);
      }
    }

    temp_event_none = TRUE;
    for (ii=TEN_CONSEQUENT_ACTION_EVENT_FIRST_OXU3;
         ii<=TEN_CONSEQUENT_ACTION_EVENT_LAST_OXU3; ii++) {
      if (ten_ohpp_get_shadow_sfc_ram_bit(module_id, bank, row, ii+TEN_CONSEQUENT_ACTION_EVENT_OTHER_OFFSET) == 1) {
        if (temp_row_none) {
          CS_PRINT_OUTPUT("    ROW %d: %s\n", row, ten_consequent_actions_str[row]);
          temp_row_none = FALSE;
        }
        if (temp_event_none) {
          CS_PRINT_OUTPUT("       OxU3 Terminator Events\n");
          temp_event_none = FALSE;
        }
        CS_PRINT_OUTPUT("        * %s\n",
          ten_consequent_action_events_oxux_str[ii-TEN_CONSEQUENT_ACTION_EVENT_FIRST_OXU3]);
      }
    }

    temp_event_none = TRUE;
    for (ii=TEN_CONSEQUENT_ACTION_EVENT_FIRST_OXU2_1;
         ii<=TEN_CONSEQUENT_ACTION_EVENT_LAST_OXU2_1; ii++) {
      if (ten_ohpp_get_shadow_sfc_ram_bit(module_id, bank, row, ii+TEN_CONSEQUENT_ACTION_EVENT_OTHER_OFFSET) == 1) {
        if (temp_row_none) {
          CS_PRINT_OUTPUT("    ROW %d: %s\n", row, ten_consequent_actions_str[row]);
          temp_row_none = FALSE;
        }
        if (temp_event_none) {
          CS_PRINT_OUTPUT("       OxU2  #1 Terminator Events\n");
          temp_event_none = FALSE;
        }
        CS_PRINT_OUTPUT("        * %s\n",
          ten_consequent_action_events_oxux_str[ii-TEN_CONSEQUENT_ACTION_EVENT_FIRST_OXU2_1]);
      }
    }

    temp_event_none = TRUE;
    for (ii=TEN_CONSEQUENT_ACTION_EVENT_FIRST_OXU2_2;
         ii<=TEN_CONSEQUENT_ACTION_EVENT_LAST_OXU2_2; ii++) {
      if (ten_ohpp_get_shadow_sfc_ram_bit(module_id, bank, row, ii+TEN_CONSEQUENT_ACTION_EVENT_OTHER_OFFSET) == 1) {
        if (temp_row_none) {
          CS_PRINT_OUTPUT("    ROW %d: %s\n", row, ten_consequent_actions_str[row]);
          temp_row_none = FALSE;
        }
        if (temp_event_none) {
          CS_PRINT_OUTPUT("       OxU2  #2 Terminator Events\n");
          temp_event_none = FALSE;
        }
        CS_PRINT_OUTPUT("        * %s\n",
          ten_consequent_action_events_oxux_str[ii-TEN_CONSEQUENT_ACTION_EVENT_FIRST_OXU2_2]);
      }
    }

    temp_event_none = TRUE;
    for (ii=TEN_CONSEQUENT_ACTION_EVENT_FIRST_OXU2_3;
         ii<=TEN_CONSEQUENT_ACTION_EVENT_LAST_OXU2_3; ii++) {
      if (ten_ohpp_get_shadow_sfc_ram_bit(module_id, bank, row, ii+TEN_CONSEQUENT_ACTION_EVENT_OTHER_OFFSET) == 1) {
        if (temp_row_none) {
          CS_PRINT_OUTPUT("    ROW %d: %s\n", row, ten_consequent_actions_str[row]);
          temp_row_none = FALSE;
        }
        if (temp_event_none) {
          CS_PRINT_OUTPUT("       OxU2  #3 Terminator Events\n");
          temp_event_none = FALSE;
        }
        CS_PRINT_OUTPUT("        * %s\n",
          ten_consequent_action_events_oxux_str[ii-TEN_CONSEQUENT_ACTION_EVENT_FIRST_OXU2_3]);
      }
    }

    temp_event_none = TRUE;
    for (ii=TEN_CONSEQUENT_ACTION_EVENT_FIRST_OXU2_4;
         ii<=TEN_CONSEQUENT_ACTION_EVENT_LAST_OXU2_4; ii++) {
      if (ten_ohpp_get_shadow_sfc_ram_bit(module_id, bank, row, ii+TEN_CONSEQUENT_ACTION_EVENT_OTHER_OFFSET) == 1) {
        if (temp_row_none) {
          CS_PRINT_OUTPUT("    ROW %d: %s\n", row, ten_consequent_actions_str[row]);
          temp_row_none = FALSE;
        }
        if (temp_event_none) {
          CS_PRINT_OUTPUT("       OxU2  #4 Terminator Events\n");
          temp_event_none = FALSE;
        }
        CS_PRINT_OUTPUT("        * %s\n",
          ten_consequent_action_events_oxux_str[ii-TEN_CONSEQUENT_ACTION_EVENT_FIRST_OXU2_4]);
      }
    }

    temp_event_none = TRUE;
    for (ii=TEN_CONSEQUENT_ACTION_EVENT_FIRST_OC192_1;
         ii<=TEN_CONSEQUENT_ACTION_EVENT_LAST_OC192_1; ii++) {
      if (ten_ohpp_get_shadow_sfc_ram_bit(module_id, bank, row, ii+TEN_CONSEQUENT_ACTION_EVENT_OTHER_OFFSET) == 1) {
        if (temp_row_none) {
          CS_PRINT_OUTPUT("    ROW %d: %s\n", row, ten_consequent_actions_str[row]);
          temp_row_none = FALSE;
        }
        if (temp_event_none) {
          CS_PRINT_OUTPUT("       OC192 #1 Terminator Events\n");
          temp_event_none = FALSE;
        }
        CS_PRINT_OUTPUT("        * %s\n",
          ten_consequent_action_events_oc192_str[ii-TEN_CONSEQUENT_ACTION_EVENT_FIRST_OC192_1]);
      }
    }

    temp_event_none = TRUE;
    for (ii=TEN_CONSEQUENT_ACTION_EVENT_FIRST_OC192_2;
         ii<=TEN_CONSEQUENT_ACTION_EVENT_LAST_OC192_2; ii++) {
      if (ten_ohpp_get_shadow_sfc_ram_bit(module_id, bank, row, ii+TEN_CONSEQUENT_ACTION_EVENT_OTHER_OFFSET) == 1) {
        if (temp_row_none) {
          CS_PRINT_OUTPUT("    ROW %d: %s\n", row, ten_consequent_actions_str[row]);
          temp_row_none = FALSE;
        }
        if (temp_event_none) {
          CS_PRINT_OUTPUT("       OC192 #2 Terminator Events\n");
          temp_event_none = FALSE;
        }
        CS_PRINT_OUTPUT("        * %s\n",
          ten_consequent_action_events_oc192_str[ii-TEN_CONSEQUENT_ACTION_EVENT_FIRST_OC192_2]);
      }
    }

    temp_event_none = TRUE;
    for (ii=TEN_CONSEQUENT_ACTION_EVENT_FIRST_OC192_3;
         ii<=TEN_CONSEQUENT_ACTION_EVENT_LAST_OC192_3; ii++) {
      if (ten_ohpp_get_shadow_sfc_ram_bit(module_id, bank, row, ii+TEN_CONSEQUENT_ACTION_EVENT_OTHER_OFFSET) == 1) {
        if (temp_row_none) {
          CS_PRINT_OUTPUT("    ROW %d: %s\n", row, ten_consequent_actions_str[row]);
          temp_row_none = FALSE;
        }
        if (temp_event_none) {
          CS_PRINT_OUTPUT("       OC192 #3 Terminator Events\n");
          temp_event_none = FALSE;
        }
        CS_PRINT_OUTPUT("        * %s\n",
          ten_consequent_action_events_oc192_str[ii-TEN_CONSEQUENT_ACTION_EVENT_FIRST_OC192_3]);
      }
    }

    temp_event_none = TRUE;
    for (ii=TEN_CONSEQUENT_ACTION_EVENT_FIRST_OC192_4;
         ii<=TEN_CONSEQUENT_ACTION_EVENT_LAST_OC192_4; ii++) {
      if (ten_ohpp_get_shadow_sfc_ram_bit(module_id, bank, row, ii+TEN_CONSEQUENT_ACTION_EVENT_OTHER_OFFSET) == 1) {
        if (temp_row_none) {
          CS_PRINT_OUTPUT("    ROW %d: %s\n", row, ten_consequent_actions_str[row]);
          temp_row_none = FALSE;
        }
        if (temp_event_none) {
          CS_PRINT_OUTPUT("       OC192 #4 Terminator Events\n");
          temp_event_none = FALSE;
        }
        CS_PRINT_OUTPUT("        * %s\n",
          ten_consequent_action_events_oc192_str[ii-TEN_CONSEQUENT_ACTION_EVENT_FIRST_OC192_4]);
      }
    }

    /* Bugzilla #38149 - update ten_hl_ohpp_dump_sfu API for T41 events  */
    if (ten_dev_is_t41(TEN_MOD_ID_TO_DEV_ID(module_id))) {
      temp_event_none = TRUE;
      for (ii=TEN_CONSEQUENT_ACTION_EVENT_FIRST_OXU3_TERM; ii<=TEN_CONSEQUENT_ACTION_EVENT_LAST_OXU3_TERM; ii++) {
        if (ten_ohpp_get_shadow_sfc_ram_bit(module_id, bank, row, ii+TEN_CONSEQUENT_ACTION_EVENT_OTHER_OFFSET_T41) == 1) {
          if (temp_row_none) {
            CS_PRINT_OUTPUT("    ROW %d: %s\n", row, ten_consequent_actions_str[row]);
            temp_row_none = FALSE;
          }
          if (temp_event_none) {
            CS_PRINT_OUTPUT("       CS604X OxU3 Terminator Events\n");
            temp_event_none = FALSE;
          }
          CS_PRINT_OUTPUT("        * %s\n",
            ten_consequent_action_events_cs604x_oxu3_str[ii-TEN_CONSEQUENT_ACTION_EVENT_FIRST_OXU3_TERM]);
        }
      }
      
      temp_event_none = TRUE;
      for (ii=TEN_CONSEQUENT_ACTION_EVENT_FIRST_OXU2_TERM_1; ii<=TEN_CONSEQUENT_ACTION_EVENT_LAST_OXU2_TERM_1; ii++) {
        if (ten_ohpp_get_shadow_sfc_ram_bit(module_id, bank, row, ii+TEN_CONSEQUENT_ACTION_EVENT_OTHER_OFFSET_T41) == 1) {
          if (temp_row_none) {
            CS_PRINT_OUTPUT("    ROW %d: %s\n", row, ten_consequent_actions_str[row]);
            temp_row_none = FALSE;
          }
          if (temp_event_none) {
            CS_PRINT_OUTPUT("       CS604X OxU2 #1 Terminator Events\n");
            temp_event_none = FALSE;
          }
          CS_PRINT_OUTPUT("        * %s\n",
            ten_consequent_action_events_cs604x_oxu2_terminator_channel_actions_str[ii-TEN_CONSEQUENT_ACTION_EVENT_FIRST_OXU2_TERM_1]);
        }
      }
      
      temp_event_none = TRUE;
      for (ii=TEN_CONSEQUENT_ACTION_EVENT_FIRST_OXU2_TERM_2; ii<=TEN_CONSEQUENT_ACTION_EVENT_LAST_OXU2_TERM_2; ii++) {
        if (ten_ohpp_get_shadow_sfc_ram_bit(module_id, bank, row, ii+TEN_CONSEQUENT_ACTION_EVENT_OTHER_OFFSET_T41) == 1) {
          if (temp_row_none) {
            CS_PRINT_OUTPUT("    ROW %d: %s\n", row, ten_consequent_actions_str[row]);
            temp_row_none = FALSE;
          }
          if (temp_event_none) {
            CS_PRINT_OUTPUT("       CS604X OxU2 #2 Terminator Events\n");
            temp_event_none = FALSE;
          }
          CS_PRINT_OUTPUT("        * %s\n",
            ten_consequent_action_events_cs604x_oxu2_terminator_channel_actions_str[ii-TEN_CONSEQUENT_ACTION_EVENT_FIRST_OXU2_TERM_2]);
        }
      }
      
      temp_event_none = TRUE;
      for (ii=TEN_CONSEQUENT_ACTION_EVENT_FIRST_OXU2_TERM_3; ii<=TEN_CONSEQUENT_ACTION_EVENT_LAST_OXU2_TERM_3; ii++) {
        if (ten_ohpp_get_shadow_sfc_ram_bit(module_id, bank, row, ii+TEN_CONSEQUENT_ACTION_EVENT_OTHER_OFFSET_T41) == 1) {
          if (temp_row_none) {
            CS_PRINT_OUTPUT("    ROW %d: %s\n", row, ten_consequent_actions_str[row]);
            temp_row_none = FALSE;
          }
          if (temp_event_none) {
            CS_PRINT_OUTPUT("       CS604X OxU2 #3 Terminator Events\n");
            temp_event_none = FALSE;
          }
          CS_PRINT_OUTPUT("        * %s\n",
            ten_consequent_action_events_cs604x_oxu2_terminator_channel_actions_str[ii-TEN_CONSEQUENT_ACTION_EVENT_FIRST_OXU2_TERM_3]);
        }
      }
      
      temp_event_none = TRUE;
      for (ii=TEN_CONSEQUENT_ACTION_EVENT_FIRST_OXU2_TERM_4; ii<=TEN_CONSEQUENT_ACTION_EVENT_LAST_OXU2_TERM_4; ii++) {
        if (ten_ohpp_get_shadow_sfc_ram_bit(module_id, bank, row, ii+TEN_CONSEQUENT_ACTION_EVENT_OTHER_OFFSET_T41) == 1) {
          if (temp_row_none) {
            CS_PRINT_OUTPUT("    ROW %d: %s\n", row, ten_consequent_actions_str[row]);
            temp_row_none = FALSE;
          }
          if (temp_event_none) {
            CS_PRINT_OUTPUT("       CS604X OxU2 #4 Terminator Events\n");
            temp_event_none = FALSE;
          }
          CS_PRINT_OUTPUT("        * %s\n",
            ten_consequent_action_events_cs604x_oxu2_terminator_channel_actions_str[ii-TEN_CONSEQUENT_ACTION_EVENT_FIRST_OXU2_TERM_4]);
        }
      }

      temp_event_none = TRUE;
      if (ten_ohpp_get_shadow_sfc_ram_bit(module_id, bank, row, TEN_CONSEQUENT_ACTION_EVENT_40G_PP+TEN_CONSEQUENT_ACTION_EVENT_OTHER_OFFSET_T41) == 1) {
        if (temp_row_none) {
          CS_PRINT_OUTPUT("    ROW %d: %s\n", row, ten_consequent_actions_str[row]);
          temp_row_none = FALSE;
        }
        if (temp_event_none) {
          CS_PRINT_OUTPUT("       CS604X 40G Packet Processor Events\n");
          temp_event_none = FALSE;
        }
        CS_PRINT_OUTPUT("        * %s\n", "Rx Failure Alarm from 40G Packet Processor");
      }

      for (ii=TEN_CONSEQUENT_ACTION_EVENT_10G_PP_CHAN1; ii<=TEN_CONSEQUENT_ACTION_EVENT_10G_PP_CHAN4; ii++) {
        temp_event_none = TRUE;
        if (ten_ohpp_get_shadow_sfc_ram_bit(module_id, bank, row, ii+TEN_CONSEQUENT_ACTION_EVENT_OTHER_OFFSET_T41) == 1) {
          if (temp_row_none) {
            CS_PRINT_OUTPUT("    ROW %d: %s\n", row, ten_consequent_actions_str[row]);
            temp_row_none = FALSE;
          }
          if (temp_event_none) {
            CS_PRINT_OUTPUT("       CS604X 10G #%d Packet Processor Events\n", ii-(TEN_CONSEQUENT_ACTION_EVENT_10G_PP_CHAN1-1));
            temp_event_none = FALSE;
          }
          CS_PRINT_OUTPUT("        * %s %d\n", "Rx Failure Alarm from 10G Packet Processor Channel ", ii-(TEN_CONSEQUENT_ACTION_EVENT_10G_PP_CHAN1-1));
        }
      }
    }
  }
  CS_PRINT_OUTPUT("\n  End of Shadow Consequent Action Event dump.\n");

  /* Turn on reg read/write dumps */
  g_pTEN->drvr_flag &= ~TEN_DRVR_LOG_SUSPEND;

  return(CS_OK);
}

/* Bugzilla 21101: SFU Config dump enhancements */
/****************************************************************/
/* $rtn_hdr_start  OHPP DUMP SFU CONFIGURATION AND STATE        */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : HIGH LEVEL                                      */
/* CHIP       : Tenabo                                          */
cs_status ten_hl_ohpp_dump_sfu (cs_uint16 module_id)
/* INPUTS     : o Module Id                                     */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* A text dump of SFU configured consequent actions, clock      */
/* enables, resets, enables, and the active bank number.        */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  TEN_MPIF_GLOBAL_CLOCK_DISABLE_COMMON_t tmp_global_clock_disable_common;
  TEN_MPIF_GLOBAL_RESET_COMMON_t tmp_global_reset_common;
  TEN_OHPP_SFU_SRESET_t tmp_sfu_sreset;
  TEN_OHPP_SFU_FRMROHEN_t tmp_sfu_frmrohen;
  TEN_OHPP_SFU_CFG_t tmp_sfu_cfg;
  T41_t *pDev = NULL;
  cs_uint16 dev_id = TEN_MOD_ID_TO_DEV_ID(module_id);
  cs_boolean sfc_is_readable = FALSE;
  cs_uint16 temp_initially_active = 0;
  cs_uint16 temp_initially_inactive = 1;
  cs_uint16 shadow_compare_bank_0 = 0;
  cs_uint16 shadow_compare_bank_1 = 0;
  cs_uint16 local_reset;
  cs_uint16 clock_disabled;
  cs_uint16 global_reset;
  
  g_pTEN->drvr_flag |= TEN_DRVR_LOG_SUSPEND;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_DEV_COMMON_VALIDATE(dev_id, pDev, CS_ERROR);

  /* Read register values into temp variables */
  tmp_global_clock_disable_common.wrd = TEN_REG_READ(TEN_MPIF_REG_ADDR(pDev, GLOBAL_CLOCK_DISABLE_COMMON));
  tmp_global_reset_common.wrd = TEN_REG_READ(TEN_MPIF_REG_ADDR(pDev, GLOBAL_RESET_COMMON));
  tmp_sfu_sreset.wrd = TEN_REG_READ(TEN_OHPP_SFU_REG_ADDR(pDev, module_id, SRESET));
  tmp_sfu_frmrohen.wrd = TEN_REG_READ(TEN_OHPP_SFU_REG_ADDR(pDev, module_id, FRMROHEN));
  tmp_sfu_cfg.wrd = TEN_REG_READ(TEN_OHPP_SFU_REG_ADDR(pDev, module_id, CFG));

  /* Get clocks and reset states */
  local_reset       = tmp_sfu_sreset.bf.SRESET;
  /*  Bug #37669:  ten_hl_ohpp_dump_sfu bug  */
  if (TEN_MOD_ID_TO_MOD_NUM(module_id) == TEN_MODULE_B) {
    clock_disabled = tmp_global_clock_disable_common.bf.ohpp_b;
    global_reset    = tmp_global_reset_common.bf.ohpp_b;
    CS_PRINT_OUTPUT("\nSTATUS OF SFU SIDE B\n");
  }
  else {
    clock_disabled = tmp_global_clock_disable_common.bf.ohpp_a;
    global_reset    = tmp_global_reset_common.bf.ohpp_a;
    CS_PRINT_OUTPUT("\nSTATUS OF SFU SIDE A\n");
  }

  sfc_is_readable = ((clock_disabled == 0) &&
                     (global_reset == 0) &&
                     (local_reset == 0));

  if (sfc_is_readable) {
    /* Get initially active and inactive states */
    temp_initially_active = ten_ohpp_sfu_get_state(module_id, TEN_OHPP_SFU_STATE_SFCBANK);
    if (temp_initially_active == 1) {
      temp_initially_inactive = 0;
    }
    else {
      temp_initially_inactive = 1;
    }
     /* Dump initially inactive bank */
    CS_PRINT_OUTPUT("\nCONSEQUENT ACTIONS FOR INACTIVE BANK %d\n", temp_initially_inactive);
    ten_hl_ohpp_dump_consequent_actions_all (module_id);
    g_pTEN->drvr_flag |= TEN_DRVR_LOG_SUSPEND;

    /* Switch physical banks */
    ten_hl_ohpp_switch_sfc_ram(module_id);
    /* Dump initially active bank */
    CS_PRINT_OUTPUT("\nCONSEQUENT ACTIONS FOR   ACTIVE BANK %d\n", temp_initially_active);
    ten_hl_ohpp_dump_consequent_actions_all (module_id);
    g_pTEN->drvr_flag |= TEN_DRVR_LOG_SUSPEND;

    /* Switch physical banks - back to initial state */
    ten_hl_ohpp_switch_sfc_ram(module_id);
  }
  else {
    CS_PRINT_OUTPUT("No Consequent Action dump because SFC RAM is not readable\n");
  }

  CS_PRINT_OUTPUT("\n");

  CS_PRINT_OUTPUT("OHPP Clock:        ");
  if (clock_disabled == 1) {
    CS_PRINT_OUTPUT("Disabled\n");
  }
  else {
    CS_PRINT_OUTPUT("Enabled\n");
  }

  CS_PRINT_OUTPUT("OHPP Global Reset: ");
  if (global_reset == 1) {
    CS_PRINT_OUTPUT("Asserted\n");
  }
  else {
    CS_PRINT_OUTPUT("Deasserted\n");
  }

  CS_PRINT_OUTPUT("SFU Soft Reset:    ");
  if (local_reset == 1) {
    CS_PRINT_OUTPUT("Asserted\n");
  }
  else {
    CS_PRINT_OUTPUT("Deasserted\n");
  }

  CS_PRINT_OUTPUT("\n");


  if (sfc_is_readable) {
    CS_PRINT_OUTPUT("Admin Overhead Information SFU inputs (ADM OH Enables):\n");
    if (tmp_sfu_frmrohen.bf.ADMOHEN & 0x0001) {
      CS_PRINT_OUTPUT("  Interface 1 Enabled (Includes 40GKPA)\n");
    }
    else {
      CS_PRINT_OUTPUT("  Interface 1 Disabled (Includes 40GKPA)\n");
    }
    if (tmp_sfu_frmrohen.bf.ADMOHEN & 0x0002) {
      CS_PRINT_OUTPUT("  Interface 2 Enabled\n");
    }
    else {
      CS_PRINT_OUTPUT("  Interface 2 Disabled\n");
    }
    if (tmp_sfu_frmrohen.bf.ADMOHEN & 0x0004) {
      CS_PRINT_OUTPUT("  Interface 3 Enabled\n");
    }
    else {
      CS_PRINT_OUTPUT("  Interface 3 Disabled\n");
    }
    if (tmp_sfu_frmrohen.bf.ADMOHEN & 0x0008) {
      CS_PRINT_OUTPUT("  Interface 4 Enabled\n");
    }
    else {
      CS_PRINT_OUTPUT("  Interface 4 Disabled\n");
    }

    CS_PRINT_OUTPUT("SONET/STS Framer SFU inputs (STS OH Enables):\n");
    if (tmp_sfu_frmrohen.bf.STSOHEN & 0x0001) {
      CS_PRINT_OUTPUT("  Framer 1    Enabled\n");
    }
    else {
      CS_PRINT_OUTPUT("  Framer 1    Disabled\n");
    }
    if (tmp_sfu_frmrohen.bf.STSOHEN & 0x0002) {
      CS_PRINT_OUTPUT("  Framer 2    Enabled\n");
    }
    else {
      CS_PRINT_OUTPUT("  Framer 2    Disabled\n");
    }
    if (tmp_sfu_frmrohen.bf.STSOHEN & 0x0004) {
      CS_PRINT_OUTPUT("  Framer 3    Enabled\n");
    }
    else {
      CS_PRINT_OUTPUT("  Framer 3    Disabled\n");
    }
    if (tmp_sfu_frmrohen.bf.STSOHEN & 0x0008) {
      CS_PRINT_OUTPUT("  Framer 4    Enabled\n");
    }
    else {
      CS_PRINT_OUTPUT("  Framer 4    Disabled\n");
    }

    CS_PRINT_OUTPUT("OTN Framer SFU inputs (OTN OH Enables):\n");
    if (tmp_sfu_frmrohen.bf.OTNOHEN & 0x0001) {
      CS_PRINT_OUTPUT("  Framer 1    Enabled\n");
    }
    else {
      CS_PRINT_OUTPUT("  Framer 1    Disabled\n");
    }
    if (tmp_sfu_frmrohen.bf.OTNOHEN & 0x0002) {
      CS_PRINT_OUTPUT("  Framer 2    Enabled\n");
    }
    else {
      CS_PRINT_OUTPUT("  Framer 2    Disabled\n");
    }
    if (tmp_sfu_frmrohen.bf.OTNOHEN & 0x0004) {
      CS_PRINT_OUTPUT("  Framer 3    Enabled\n");
    }
    else {
      CS_PRINT_OUTPUT("  Framer 3    Disabled\n");
    }
    if (tmp_sfu_frmrohen.bf.OTNOHEN & 0x0008) {
      CS_PRINT_OUTPUT("  Framer 4    Enabled\n");
    }
    else {
      CS_PRINT_OUTPUT("  Framer 4    Disabled\n");
    }
    if (tmp_sfu_frmrohen.bf.OTNOHEN & 0x0010) {
      CS_PRINT_OUTPUT("  40G Framer  Enabled\n");
    }
    else {
      CS_PRINT_OUTPUT("  40G Framer  Disabled\n");
    }

    CS_PRINT_OUTPUT("\n");

    CS_PRINT_OUTPUT("SFU Consequent Action Insertion (SigGenE): ");
    if (tmp_sfu_cfg.bf.SIGGENE == 1) {
      CS_PRINT_OUTPUT("Enabled\n");
    }
    else {
      CS_PRINT_OUTPUT("Disabled\n");
    }

    CS_PRINT_OUTPUT("\n");

    CS_PRINT_OUTPUT("Active Bank:       %d\n", temp_initially_active);

    CS_PRINT_OUTPUT("\n");

    /* Compare initially inactive physical bank to corresponding shadow RAM */
    if (temp_initially_inactive == 1) {
      shadow_compare_bank_1 = ten_ohpp_compare_shadow_sfc_ram(module_id, 1);
    }
    else {
      shadow_compare_bank_0 = ten_ohpp_compare_shadow_sfc_ram(module_id, 0);
    }
    /* Switch physical banks */
    ten_hl_ohpp_switch_sfc_ram(module_id);
    /* Compare initially active physical bank to corresponding shadow RAM */
    if (temp_initially_active == 1) {
      shadow_compare_bank_1 = ten_ohpp_compare_shadow_sfc_ram(module_id, 1);
    }
    else {
      shadow_compare_bank_0 = ten_ohpp_compare_shadow_sfc_ram(module_id, 0);
    }
    /* Switch physical banks - back to initial state */
    ten_hl_ohpp_switch_sfc_ram(module_id);
    /* Print results */
    if (shadow_compare_bank_0 == 1) {
      CS_PRINT_OUTPUT("Shadow RAM Bank 0 matches Physical SFC RAM\n");
    }
    else {
      CS_PRINT_OUTPUT("Shadow RAM Bank 0 does not match Physical SFC RAM\n");
    }
    if (shadow_compare_bank_1 == 1) {
      CS_PRINT_OUTPUT("Shadow RAM Bank 1 matches Physical SFC RAM\n");
    }
    else {
      CS_PRINT_OUTPUT("Shadow RAM Bank 1 does not match Physical SFC RAM\n");
    }
  }
  else {
    CS_PRINT_OUTPUT("No enables dumped because SFC RAM is not readable\n");
  }

  CS_PRINT_OUTPUT("\n");
  g_pTEN->drvr_flag &= ~TEN_DRVR_LOG_SUSPEND;

  return(CS_OK);
}

/****************************************************************/
/* $rtn_hdr_start  OHPP DUMP SHADOW CA EVENT SETTINGS           */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : HIGH LEVEL                                      */
/* CHIP       : Tenabo                                          */
cs_status ten_hl_ohpp_dump_shadow_consequent_action_events (cs_uint16 module_id,
                                                            cs_uint16 bank,
                                                            cs_uint8 row)
/* INPUTS     : o Module Id                                     */
/*              o Bank                                          */
/*              o Row                                           */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* A text dump of the of the Consequent Action Events set in    */
/* the Shadow SFC RAM to trigger the specified row action.      */
/*                                                              */
/* The [row] parameter is specified as:                         */
/*   0..77                                                      */
/*   See ten_ohpp_data.h for the 78 enumeration values.         */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  cs_uint16 ii;
  cs_boolean temp_none;
  cs_uint32 err_code = 0;

  if (bank > 1) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": bank out of range.  s/b 0..1.");
    return(CS_ERROR);
  } 
  if (row >= TEN_CONSEQUENT_ACTION_ROW_COUNT) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": row out of range.  s/b 0..77.");
    return(CS_ERROR);
  } 
  if (!(TEN_IS_MOD_VALID(module_id, &err_code))) {
    CS_PRINT_OUTPUT("ERROR: API   -Id (0x%x) is invalid!\n", module_id);
    return(CS_ERROR);
  }
 
  CS_PRINT_OUTPUT("\nConsequent Action Events set for Own Module\n");

  temp_none = TRUE;
  CS_PRINT_OUTPUT(" Global Input Events\n");
  for (ii=TEN_CONSEQUENT_ACTION_EVENT_FIRST_GLOBAL;
       ii<=TEN_CONSEQUENT_ACTION_EVENT_LAST_GLOBAL; ii++) {
    if (ten_ohpp_get_shadow_sfc_ram_bit(module_id, bank, row, ii) == 1) {
      temp_none = FALSE;
      CS_PRINT_OUTPUT("  * %s\n",
        ten_consequent_action_events_global_str[ii-TEN_CONSEQUENT_ACTION_EVENT_FIRST_GLOBAL]);
    }
  }
  if (temp_none) {
      CS_PRINT_OUTPUT("  None\n");
  }

  temp_none = TRUE;
  CS_PRINT_OUTPUT(" OxU3 Terminator Events\n");
  for (ii=TEN_CONSEQUENT_ACTION_EVENT_FIRST_OXU3;
       ii<=TEN_CONSEQUENT_ACTION_EVENT_LAST_OXU3; ii++) {
    if (ten_ohpp_get_shadow_sfc_ram_bit(module_id, bank, row, ii) == 1) {
      temp_none = FALSE;
      CS_PRINT_OUTPUT("  * %s\n",
        ten_consequent_action_events_oxux_str[ii-TEN_CONSEQUENT_ACTION_EVENT_FIRST_OXU3]);
    }
  }
  if (temp_none) {
      CS_PRINT_OUTPUT("  None\n");
  }

  temp_none = TRUE;
  CS_PRINT_OUTPUT(" OxU2  #1 Terminator Events\n");
  for (ii=TEN_CONSEQUENT_ACTION_EVENT_FIRST_OXU2_1;
       ii<=TEN_CONSEQUENT_ACTION_EVENT_LAST_OXU2_1; ii++) {
    if (ten_ohpp_get_shadow_sfc_ram_bit(module_id, bank, row, ii) == 1) {
      temp_none = FALSE;
      CS_PRINT_OUTPUT("  * %s\n",
        ten_consequent_action_events_oxux_str[ii-TEN_CONSEQUENT_ACTION_EVENT_FIRST_OXU2_1]);
    }
  }
  if (temp_none) {
      CS_PRINT_OUTPUT("  None\n");
  }

  temp_none = TRUE;
  CS_PRINT_OUTPUT(" OxU2  #2 Terminator Events\n");
  for (ii=TEN_CONSEQUENT_ACTION_EVENT_FIRST_OXU2_2;
       ii<=TEN_CONSEQUENT_ACTION_EVENT_LAST_OXU2_2; ii++) {
    if (ten_ohpp_get_shadow_sfc_ram_bit(module_id, bank, row, ii) == 1) {
      temp_none = FALSE;
      CS_PRINT_OUTPUT("  * %s\n",
        ten_consequent_action_events_oxux_str[ii-TEN_CONSEQUENT_ACTION_EVENT_FIRST_OXU2_2]);
    }
  }
  if (temp_none) {
      CS_PRINT_OUTPUT("  None\n");
  }

  temp_none = TRUE;
  CS_PRINT_OUTPUT(" OxU2  #3 Terminator Events\n");
  for (ii=TEN_CONSEQUENT_ACTION_EVENT_FIRST_OXU2_3;
       ii<=TEN_CONSEQUENT_ACTION_EVENT_LAST_OXU2_3; ii++) {
    if (ten_ohpp_get_shadow_sfc_ram_bit(module_id, bank, row, ii) == 1) {
      temp_none = FALSE;
      CS_PRINT_OUTPUT("  * %s\n",
        ten_consequent_action_events_oxux_str[ii-TEN_CONSEQUENT_ACTION_EVENT_FIRST_OXU2_3]);
    }
  }
  if (temp_none) {
      CS_PRINT_OUTPUT("  None\n");
  }

  temp_none = TRUE;
  CS_PRINT_OUTPUT(" OxU2  #4 Terminator Events\n");
  for (ii=TEN_CONSEQUENT_ACTION_EVENT_FIRST_OXU2_4;
       ii<=TEN_CONSEQUENT_ACTION_EVENT_LAST_OXU2_4; ii++) {
    if (ten_ohpp_get_shadow_sfc_ram_bit(module_id, bank, row, ii) == 1) {
      temp_none = FALSE;
      CS_PRINT_OUTPUT("  * %s\n",
        ten_consequent_action_events_oxux_str[ii-TEN_CONSEQUENT_ACTION_EVENT_FIRST_OXU2_4]);
    }
  }
  if (temp_none) {
      CS_PRINT_OUTPUT("  None\n");
  }

  temp_none = TRUE;
  CS_PRINT_OUTPUT(" OC192 #1 Terminator Events\n");
  for (ii=TEN_CONSEQUENT_ACTION_EVENT_FIRST_OC192_1;
       ii<=TEN_CONSEQUENT_ACTION_EVENT_LAST_OC192_1; ii++) {
    if (ten_ohpp_get_shadow_sfc_ram_bit(module_id, bank, row, ii) == 1) {
      temp_none = FALSE;
      CS_PRINT_OUTPUT("  * %s\n",
        ten_consequent_action_events_oc192_str[ii-TEN_CONSEQUENT_ACTION_EVENT_FIRST_OC192_1]);
    }
  }
  if (temp_none) {
      CS_PRINT_OUTPUT("  None\n");
  }

  temp_none = TRUE;
  CS_PRINT_OUTPUT(" OC192 #2 Terminator Events\n");
  for (ii=TEN_CONSEQUENT_ACTION_EVENT_FIRST_OC192_2;
       ii<=TEN_CONSEQUENT_ACTION_EVENT_LAST_OC192_2; ii++) {
    if (ten_ohpp_get_shadow_sfc_ram_bit(module_id, bank, row, ii) == 1) {
      temp_none = FALSE;
      CS_PRINT_OUTPUT("  * %s\n",
        ten_consequent_action_events_oc192_str[ii-TEN_CONSEQUENT_ACTION_EVENT_FIRST_OC192_2]);
    }
  }
  if (temp_none) {
      CS_PRINT_OUTPUT("  None\n");
  }

  temp_none = TRUE;
  CS_PRINT_OUTPUT(" OC192 #3 Terminator Events\n");
  for (ii=TEN_CONSEQUENT_ACTION_EVENT_FIRST_OC192_3;
       ii<=TEN_CONSEQUENT_ACTION_EVENT_LAST_OC192_3; ii++) {
    if (ten_ohpp_get_shadow_sfc_ram_bit(module_id, bank, row, ii) == 1) {
      temp_none = FALSE;
      CS_PRINT_OUTPUT("  * %s\n",
        ten_consequent_action_events_oc192_str[ii-TEN_CONSEQUENT_ACTION_EVENT_FIRST_OC192_3]);
    }
  }
  if (temp_none) {
      CS_PRINT_OUTPUT("  None\n");
  }

  temp_none = TRUE;
  CS_PRINT_OUTPUT(" OC192 #4 Terminator Events\n");
  for (ii=TEN_CONSEQUENT_ACTION_EVENT_FIRST_OC192_4;
       ii<=TEN_CONSEQUENT_ACTION_EVENT_LAST_OC192_4; ii++) {
    if (ten_ohpp_get_shadow_sfc_ram_bit(module_id, bank, row, ii) == 1) {
      temp_none = FALSE;
      CS_PRINT_OUTPUT("  * %s\n",
        ten_consequent_action_events_oc192_str[ii-TEN_CONSEQUENT_ACTION_EVENT_FIRST_OC192_4]);
    }
  }
  if (temp_none) {
      CS_PRINT_OUTPUT("  None\n");
  }

  /* Bugzilla #38149 - update ten_hl_ohpp_dump_sfu API for T41 events  */
  if (ten_dev_is_t41(TEN_MOD_ID_TO_DEV_ID(module_id))) {
    temp_none = TRUE;
    CS_PRINT_OUTPUT(" CS604X OxU3 Terminator Events\n");
    for (ii=TEN_CONSEQUENT_ACTION_EVENT_FIRST_OXU3_TERM; ii<=TEN_CONSEQUENT_ACTION_EVENT_LAST_OXU3_TERM; ii++) {
      if (ten_ohpp_get_shadow_sfc_ram_bit(module_id, bank, row, ii) == 1) {
        temp_none = FALSE;
        CS_PRINT_OUTPUT("  * %s\n", ten_consequent_action_events_cs604x_oxu3_str[ii-TEN_CONSEQUENT_ACTION_EVENT_FIRST_OXU3_TERM]);
      }
    }
    if (temp_none) {
      CS_PRINT_OUTPUT("  None\n");
    }
  
    temp_none = TRUE;
    CS_PRINT_OUTPUT(" CS604X OxU2 #1 Terminator Events\n");
    for (ii=TEN_CONSEQUENT_ACTION_EVENT_FIRST_OXU2_TERM_1; ii<=TEN_CONSEQUENT_ACTION_EVENT_LAST_OXU2_TERM_1; ii++) {
      if (ten_ohpp_get_shadow_sfc_ram_bit(module_id, bank, row, ii) == 1) {
        temp_none = FALSE;
        CS_PRINT_OUTPUT("  * %s\n", ten_consequent_action_events_cs604x_oxu2_terminator_channel_actions_str[ii-TEN_CONSEQUENT_ACTION_EVENT_FIRST_OXU2_TERM_1]);
      }
    }
    if (temp_none) {
      CS_PRINT_OUTPUT("  None\n");
    }
    
    temp_none = TRUE;
    CS_PRINT_OUTPUT(" CS604X OxU2 #2 Terminator Events\n");
    for (ii=TEN_CONSEQUENT_ACTION_EVENT_FIRST_OXU2_TERM_2; ii<=TEN_CONSEQUENT_ACTION_EVENT_LAST_OXU2_TERM_2; ii++) {
      if (ten_ohpp_get_shadow_sfc_ram_bit(module_id, bank, row, ii) == 1) {
        temp_none = FALSE;
        CS_PRINT_OUTPUT("  * %s\n", ten_consequent_action_events_cs604x_oxu2_terminator_channel_actions_str[ii-TEN_CONSEQUENT_ACTION_EVENT_FIRST_OXU2_TERM_2]);
      }
    }
    if (temp_none) {
      CS_PRINT_OUTPUT("  None\n");
    }
    
    temp_none = TRUE;
    CS_PRINT_OUTPUT(" CS604X OxU2 #3 Terminator Events\n");
    for (ii=TEN_CONSEQUENT_ACTION_EVENT_FIRST_OXU2_TERM_3; ii<=TEN_CONSEQUENT_ACTION_EVENT_LAST_OXU2_TERM_3; ii++) {
      if (ten_ohpp_get_shadow_sfc_ram_bit(module_id, bank, row, ii) == 1) {
        temp_none = FALSE;
        CS_PRINT_OUTPUT("  * %s\n", ten_consequent_action_events_cs604x_oxu2_terminator_channel_actions_str[ii-TEN_CONSEQUENT_ACTION_EVENT_FIRST_OXU2_TERM_3]);
      }
    }
    if (temp_none) {
      CS_PRINT_OUTPUT("  None\n");
    }
    
    temp_none = TRUE;
    CS_PRINT_OUTPUT(" CS604X OxU2 #4 Terminator Events\n");
    for (ii=TEN_CONSEQUENT_ACTION_EVENT_FIRST_OXU2_TERM_4; ii<=TEN_CONSEQUENT_ACTION_EVENT_LAST_OXU2_TERM_4; ii++) {
      if (ten_ohpp_get_shadow_sfc_ram_bit(module_id, bank, row, ii) == 1) {
        temp_none = FALSE;
        CS_PRINT_OUTPUT("  * %s\n", ten_consequent_action_events_cs604x_oxu2_terminator_channel_actions_str[ii-TEN_CONSEQUENT_ACTION_EVENT_FIRST_OXU2_TERM_4]);
      }
    }
    if (temp_none) {
      CS_PRINT_OUTPUT("  None\n");
    }
    
    temp_none = TRUE;
    CS_PRINT_OUTPUT(" CS604X 40G Packet Processor Events\n");
    if (ten_ohpp_get_shadow_sfc_ram_bit(module_id, bank, row, TEN_CONSEQUENT_ACTION_EVENT_40G_PP) == 1) {
      temp_none = FALSE;
      CS_PRINT_OUTPUT("  * %s\n", "Rx Failure Alarm from 40G Packet Processor");
    }
    if (temp_none) {
      CS_PRINT_OUTPUT("  None\n");
    }
    
    for (ii=TEN_CONSEQUENT_ACTION_EVENT_10G_PP_CHAN1; ii<=TEN_CONSEQUENT_ACTION_EVENT_10G_PP_CHAN4; ii++) {
      temp_none = TRUE;
      CS_PRINT_OUTPUT(" CS604X 10G #%d Packet Processor Events\n", ii-(TEN_CONSEQUENT_ACTION_EVENT_10G_PP_CHAN1-1));
      if (ten_ohpp_get_shadow_sfc_ram_bit(module_id, bank, row, ii) == 1) {
        temp_none = FALSE;
        CS_PRINT_OUTPUT("  * %s %d\n", "Rx Failure Alarm from 10G Packet Processor Channel ", ii-(TEN_CONSEQUENT_ACTION_EVENT_10G_PP_CHAN1-1));
      }
      if (temp_none) {
       CS_PRINT_OUTPUT("  None\n");
      }
    }
  }
  
  CS_PRINT_OUTPUT("\nConsequent Action Events set for Other Module\n");

  temp_none = TRUE;
  CS_PRINT_OUTPUT(" Global Input Events\n");
  for (ii=TEN_CONSEQUENT_ACTION_EVENT_FIRST_GLOBAL;
       ii<=TEN_CONSEQUENT_ACTION_EVENT_LAST_GLOBAL; ii++) {
    if (ten_ohpp_get_shadow_sfc_ram_bit(module_id, bank, row, ii+TEN_CONSEQUENT_ACTION_EVENT_OTHER_OFFSET) == 1) {
      temp_none = FALSE;
      CS_PRINT_OUTPUT("  * %s\n",
        ten_consequent_action_events_global_str[ii-TEN_CONSEQUENT_ACTION_EVENT_FIRST_GLOBAL]);
    }
  }
  if (temp_none) {
      CS_PRINT_OUTPUT("  None\n");
  }

  temp_none = TRUE;
  CS_PRINT_OUTPUT(" OxU3 Terminator Events\n");
  for (ii=TEN_CONSEQUENT_ACTION_EVENT_FIRST_OXU3;
       ii<=TEN_CONSEQUENT_ACTION_EVENT_LAST_OXU3; ii++) {
    if (ten_ohpp_get_shadow_sfc_ram_bit(module_id, bank, row, ii+TEN_CONSEQUENT_ACTION_EVENT_OTHER_OFFSET) == 1) {
      temp_none = FALSE;
      CS_PRINT_OUTPUT("  * %s\n",
        ten_consequent_action_events_oxux_str[ii-TEN_CONSEQUENT_ACTION_EVENT_FIRST_OXU3]);
    }
  }
  if (temp_none) {
      CS_PRINT_OUTPUT("  None\n");
  }

  temp_none = TRUE;
  CS_PRINT_OUTPUT(" OxU2  #1 Terminator Events\n");
  for (ii=TEN_CONSEQUENT_ACTION_EVENT_FIRST_OXU2_1;
       ii<=TEN_CONSEQUENT_ACTION_EVENT_LAST_OXU2_1; ii++) {
    if (ten_ohpp_get_shadow_sfc_ram_bit(module_id, bank, row, ii+TEN_CONSEQUENT_ACTION_EVENT_OTHER_OFFSET) == 1) {
      temp_none = FALSE;
      CS_PRINT_OUTPUT("  * %s\n",
        ten_consequent_action_events_oxux_str[ii-TEN_CONSEQUENT_ACTION_EVENT_FIRST_OXU2_1]);
    }
  }
  if (temp_none) {
      CS_PRINT_OUTPUT("  None\n");
  }

  temp_none = TRUE;
  CS_PRINT_OUTPUT(" OxU2  #2 Terminator Events\n");
  for (ii=TEN_CONSEQUENT_ACTION_EVENT_FIRST_OXU2_2;
       ii<=TEN_CONSEQUENT_ACTION_EVENT_LAST_OXU2_2; ii++) {
    if (ten_ohpp_get_shadow_sfc_ram_bit(module_id, bank, row, ii+TEN_CONSEQUENT_ACTION_EVENT_OTHER_OFFSET) == 1) {
      temp_none = FALSE;
      CS_PRINT_OUTPUT("  * %s\n",
        ten_consequent_action_events_oxux_str[ii-TEN_CONSEQUENT_ACTION_EVENT_FIRST_OXU2_2]);
    }
  }
  if (temp_none) {
      CS_PRINT_OUTPUT("  None\n");
  }

  temp_none = TRUE;
  CS_PRINT_OUTPUT(" OxU2  #3 Terminator Events\n");
  for (ii=TEN_CONSEQUENT_ACTION_EVENT_FIRST_OXU2_3;
       ii<=TEN_CONSEQUENT_ACTION_EVENT_LAST_OXU2_3; ii++) {
    if (ten_ohpp_get_shadow_sfc_ram_bit(module_id, bank, row, ii+TEN_CONSEQUENT_ACTION_EVENT_OTHER_OFFSET) == 1) {
      temp_none = FALSE;
      CS_PRINT_OUTPUT("  * %s\n",
        ten_consequent_action_events_oxux_str[ii-TEN_CONSEQUENT_ACTION_EVENT_FIRST_OXU2_3]);
    }
  }
  if (temp_none) {
      CS_PRINT_OUTPUT("  None\n");
  }

  temp_none = TRUE;
  CS_PRINT_OUTPUT(" OxU2  #4 Terminator Events\n");
  for (ii=TEN_CONSEQUENT_ACTION_EVENT_FIRST_OXU2_4;
       ii<=TEN_CONSEQUENT_ACTION_EVENT_LAST_OXU2_4; ii++) {
    if (ten_ohpp_get_shadow_sfc_ram_bit(module_id, bank, row, ii+TEN_CONSEQUENT_ACTION_EVENT_OTHER_OFFSET) == 1) {
      temp_none = FALSE;
      CS_PRINT_OUTPUT("  * %s\n",
        ten_consequent_action_events_oxux_str[ii-TEN_CONSEQUENT_ACTION_EVENT_FIRST_OXU2_4]);
    }
  }
  if (temp_none) {
      CS_PRINT_OUTPUT("  None\n");
  }

  temp_none = TRUE;
  CS_PRINT_OUTPUT(" OC192 #1 Terminator Events\n");
  for (ii=TEN_CONSEQUENT_ACTION_EVENT_FIRST_OC192_1;
       ii<=TEN_CONSEQUENT_ACTION_EVENT_LAST_OC192_1; ii++) {
    if (ten_ohpp_get_shadow_sfc_ram_bit(module_id, bank, row, ii+TEN_CONSEQUENT_ACTION_EVENT_OTHER_OFFSET) == 1) {
      temp_none = FALSE;
      CS_PRINT_OUTPUT("  * %s\n",
        ten_consequent_action_events_oc192_str[ii-TEN_CONSEQUENT_ACTION_EVENT_FIRST_OC192_1]);
    }
  }
  if (temp_none) {
      CS_PRINT_OUTPUT("  None\n");
  }

  temp_none = TRUE;
  CS_PRINT_OUTPUT(" OC192 #2 Terminator Events\n");
  for (ii=TEN_CONSEQUENT_ACTION_EVENT_FIRST_OC192_2;
       ii<=TEN_CONSEQUENT_ACTION_EVENT_LAST_OC192_2; ii++) {
    if (ten_ohpp_get_shadow_sfc_ram_bit(module_id, bank, row, ii+TEN_CONSEQUENT_ACTION_EVENT_OTHER_OFFSET) == 1) {
      temp_none = FALSE;
      CS_PRINT_OUTPUT("  * %s\n",
        ten_consequent_action_events_oc192_str[ii-TEN_CONSEQUENT_ACTION_EVENT_FIRST_OC192_2]);
    }
  }
  if (temp_none) {
      CS_PRINT_OUTPUT("  None\n");
  }

  temp_none = TRUE;
  CS_PRINT_OUTPUT(" OC192 #3 Terminator Events\n");
  for (ii=TEN_CONSEQUENT_ACTION_EVENT_FIRST_OC192_3;
       ii<=TEN_CONSEQUENT_ACTION_EVENT_LAST_OC192_3; ii++) {
    if (ten_ohpp_get_shadow_sfc_ram_bit(module_id, bank, row, ii+TEN_CONSEQUENT_ACTION_EVENT_OTHER_OFFSET) == 1) {
      temp_none = FALSE;
      CS_PRINT_OUTPUT("  * %s\n",
        ten_consequent_action_events_oc192_str[ii-TEN_CONSEQUENT_ACTION_EVENT_FIRST_OC192_3]);
    }
  }
  if (temp_none) {
      CS_PRINT_OUTPUT("  None\n");
  }

  temp_none = TRUE;
  CS_PRINT_OUTPUT(" OC192 #4 Terminator Events\n");
  for (ii=TEN_CONSEQUENT_ACTION_EVENT_FIRST_OC192_4;
       ii<=TEN_CONSEQUENT_ACTION_EVENT_LAST_OC192_4; ii++) {
    if (ten_ohpp_get_shadow_sfc_ram_bit(module_id, bank, row, ii+TEN_CONSEQUENT_ACTION_EVENT_OTHER_OFFSET) == 1) {
      temp_none = FALSE;
      CS_PRINT_OUTPUT("  * %s\n",
        ten_consequent_action_events_oc192_str[ii-TEN_CONSEQUENT_ACTION_EVENT_FIRST_OC192_4]);
    }
  }
  if (temp_none) {
      CS_PRINT_OUTPUT("  None\n");
  }
  
  /* Bugzilla #38149 - update ten_hl_ohpp_dump_sfu API for T41 events  */
  if (ten_dev_is_t41(TEN_MOD_ID_TO_DEV_ID(module_id))) {
    temp_none = TRUE;
    CS_PRINT_OUTPUT(" CS604X OxU3 Terminator Events\n");
    for (ii=TEN_CONSEQUENT_ACTION_EVENT_FIRST_OXU3_TERM; ii<=TEN_CONSEQUENT_ACTION_EVENT_LAST_OXU3_TERM; ii++) {
      if (ten_ohpp_get_shadow_sfc_ram_bit(module_id, bank, row, ii+TEN_CONSEQUENT_ACTION_EVENT_OTHER_OFFSET_T41) == 1) {
        temp_none = FALSE;
        CS_PRINT_OUTPUT("  * %s\n", ten_consequent_action_events_cs604x_oxu3_str[ii-TEN_CONSEQUENT_ACTION_EVENT_FIRST_OXU3_TERM]);
      }
    }
    if (temp_none) {
      CS_PRINT_OUTPUT("  None\n");
    }
  
    temp_none = TRUE;
    CS_PRINT_OUTPUT(" CS604X OxU2 #1 Terminator Events\n");
    for (ii=TEN_CONSEQUENT_ACTION_EVENT_FIRST_OXU2_TERM_1; ii<=TEN_CONSEQUENT_ACTION_EVENT_LAST_OXU2_TERM_1; ii++) {
      if (ten_ohpp_get_shadow_sfc_ram_bit(module_id, bank, row, ii+TEN_CONSEQUENT_ACTION_EVENT_OTHER_OFFSET_T41) == 1) {
        temp_none = FALSE;
        CS_PRINT_OUTPUT("  * %s\n", ten_consequent_action_events_cs604x_oxu2_terminator_channel_actions_str[ii-TEN_CONSEQUENT_ACTION_EVENT_FIRST_OXU2_TERM_1]);
      }
    }
    if (temp_none) {
      CS_PRINT_OUTPUT("  None\n");
    }
    
    temp_none = TRUE;
    CS_PRINT_OUTPUT(" CS604X OxU2 #2 Terminator Events\n");
    for (ii=TEN_CONSEQUENT_ACTION_EVENT_FIRST_OXU2_TERM_2; ii<=TEN_CONSEQUENT_ACTION_EVENT_LAST_OXU2_TERM_2; ii++) {
      if (ten_ohpp_get_shadow_sfc_ram_bit(module_id, bank, row, ii+TEN_CONSEQUENT_ACTION_EVENT_OTHER_OFFSET_T41) == 1) {
        temp_none = FALSE;
        CS_PRINT_OUTPUT("  * %s\n", ten_consequent_action_events_cs604x_oxu2_terminator_channel_actions_str[ii-TEN_CONSEQUENT_ACTION_EVENT_FIRST_OXU2_TERM_2]);
      }
    }
    if (temp_none) {
      CS_PRINT_OUTPUT("  None\n");
    }
    
    temp_none = TRUE;
    CS_PRINT_OUTPUT(" CS604X OxU2 #3 Terminator Events\n");
    for (ii=TEN_CONSEQUENT_ACTION_EVENT_FIRST_OXU2_TERM_3; ii<=TEN_CONSEQUENT_ACTION_EVENT_LAST_OXU2_TERM_3; ii++) {
      if (ten_ohpp_get_shadow_sfc_ram_bit(module_id, bank, row, ii+TEN_CONSEQUENT_ACTION_EVENT_OTHER_OFFSET_T41) == 1) {
        temp_none = FALSE;
        CS_PRINT_OUTPUT("  * %s\n", ten_consequent_action_events_cs604x_oxu2_terminator_channel_actions_str[ii-TEN_CONSEQUENT_ACTION_EVENT_FIRST_OXU2_TERM_3]);
      }
    }
    if (temp_none) {
      CS_PRINT_OUTPUT("  None\n");
    }
    
    temp_none = TRUE;
    CS_PRINT_OUTPUT(" CS604X OxU2 #4 Terminator Events\n");
    for (ii=TEN_CONSEQUENT_ACTION_EVENT_FIRST_OXU2_TERM_4; ii<=TEN_CONSEQUENT_ACTION_EVENT_LAST_OXU2_TERM_4; ii++) {
      if (ten_ohpp_get_shadow_sfc_ram_bit(module_id, bank, row, ii+TEN_CONSEQUENT_ACTION_EVENT_OTHER_OFFSET_T41) == 1) {
        temp_none = FALSE;
        CS_PRINT_OUTPUT("  * %s\n", ten_consequent_action_events_cs604x_oxu2_terminator_channel_actions_str[ii-TEN_CONSEQUENT_ACTION_EVENT_FIRST_OXU2_TERM_4]);
      }
    }
    if (temp_none) {
      CS_PRINT_OUTPUT("  None\n");
    }
    
    temp_none = TRUE;
    CS_PRINT_OUTPUT(" CS604X 40G Packet Processor Events\n");
    if (ten_ohpp_get_shadow_sfc_ram_bit(module_id, bank, row, TEN_CONSEQUENT_ACTION_EVENT_40G_PP) == 1) {
      temp_none = FALSE;
      CS_PRINT_OUTPUT("  * %s\n", "Rx Failure Alarm from 40G Packet Processor");
    }
    if (temp_none) {
      CS_PRINT_OUTPUT("  None\n");
    }
    
    for (ii=TEN_CONSEQUENT_ACTION_EVENT_10G_PP_CHAN1; ii<=TEN_CONSEQUENT_ACTION_EVENT_10G_PP_CHAN4; ii++) {
      temp_none = TRUE;
      CS_PRINT_OUTPUT(" CS604X 10G #%d Packet Processor Events\n", ii-(TEN_CONSEQUENT_ACTION_EVENT_10G_PP_CHAN1-1));
      if (ten_ohpp_get_shadow_sfc_ram_bit(module_id, bank, row, ii+TEN_CONSEQUENT_ACTION_EVENT_OTHER_OFFSET_T41) == 1) {
        temp_none = FALSE;
        CS_PRINT_OUTPUT("  * %s %d\n", "Rx Failure Alarm from 10G Packet Processor Channel ", ii-(TEN_CONSEQUENT_ACTION_EVENT_10G_PP_CHAN1-1));
      }
      if (temp_none) {
       CS_PRINT_OUTPUT("  None\n");
      }
    }
  }

  CS_PRINT_OUTPUT("\nEnd of Consequent Action Event dump.\n");

  return(CS_OK);
}

/****************************************************************/
/* $rtn_hdr_start  OHPP DUMP DOE RAM                            */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : HIGH LEVEL                                      */
/* CHIP       : Tenabo                                          */
cs_status ten_hl_ohpp_dump_doe_ram(cs_uint16 module_id,
                                   cs_uint8  string)
/* INPUTS     : o Module Id                                     */
/*              o String                                        */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* Provides a text dump of the contents of the DOE RAM.         */
/* The DOE RAM stores 5 instances of a 512-bit string. The      */
/* first string begins at address zero, the next at address     */
/* 0x20, etc. DOE RAM address space above the 5 strings is      */
/* reserved.                                                    */
/* The RAM is a 192-entry table. Each entry is 16 bits wide and */
/* occupies 1 16-bit register.                                  */
/*                                                              */
/* The [string] parameter is specified as:                      */
/*   0 = Extracted OxU3 management overhead                     */
/*   1 = Extracted management overhead from OxU2 stream 1       */
/*   2 = Extracted management overhead from OxU2 stream 2       */
/*   3 = Extracted management overhead from OxU2 stream 3       */
/*   4 = Extracted management overhead from OxU2 stream 4.      */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  cs_uint32 err_code = 0;

  if (!(TEN_IS_MOD_VALID(module_id, &err_code))) {
    CS_PRINT_OUTPUT("ERROR: API   -Id (0x%x) is invalid!\n", module_id);
    return(CS_ERROR);
  }
  if (string > 4) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": string out of range.  s/b 0..4.");
    return(CS_ERROR);
  }

  /* Turn off reg read/write dumps */
  g_pTEN->drvr_flag |= TEN_DRVR_LOG_SUSPEND;

  CS_PRINT_OUTPUT("\nDOE RAM for Module %d, String %d", module_id, string);

  CS_PRINT_OUTPUT("\n Frame Alignment OH: ");
  CS_PRINT_OUTPUT("%02X ", ten_ohpp_get_doe_ram_byte(module_id,  string, TEN_OTNOH_FAOH_BYTE1));
  CS_PRINT_OUTPUT("%02X ", ten_ohpp_get_doe_ram_byte(module_id,  string, TEN_OTNOH_FAOH_BYTE2));
  CS_PRINT_OUTPUT("%02X ", ten_ohpp_get_doe_ram_byte(module_id,  string, TEN_OTNOH_FAOH_BYTE3));
  CS_PRINT_OUTPUT("%02X ", ten_ohpp_get_doe_ram_byte(module_id,  string, TEN_OTNOH_FAOH_BYTE4));
  CS_PRINT_OUTPUT("%02X ", ten_ohpp_get_doe_ram_byte(module_id,  string, TEN_OTNOH_FAOH_BYTE5));
  CS_PRINT_OUTPUT("%02X ", ten_ohpp_get_doe_ram_byte(module_id,  string, TEN_OTNOH_FAOH_BYTE6));
  CS_PRINT_OUTPUT("%02X ", ten_ohpp_get_doe_ram_byte(module_id,  string, TEN_OTNOH_FAOH_BYTE7));

  CS_PRINT_OUTPUT("\n OTUk OH:            ");
  CS_PRINT_OUTPUT("%02X ", ten_ohpp_get_doe_ram_byte(module_id,  string, TEN_OTNOH_OTUKOH_BYTE1));
  CS_PRINT_OUTPUT("%02X ", ten_ohpp_get_doe_ram_byte(module_id,  string, TEN_OTNOH_OTUKOH_BYTE2));
  CS_PRINT_OUTPUT("%02X ", ten_ohpp_get_doe_ram_byte(module_id,  string, TEN_OTNOH_OTUKOH_BYTE3));
  CS_PRINT_OUTPUT("%02X ", ten_ohpp_get_doe_ram_byte(module_id,  string, TEN_OTNOH_OTUKOH_BYTE4));
  CS_PRINT_OUTPUT("%02X ", ten_ohpp_get_doe_ram_byte(module_id,  string, TEN_OTNOH_OTUKOH_BYTE5));
  CS_PRINT_OUTPUT("%02X ", ten_ohpp_get_doe_ram_byte(module_id,  string, TEN_OTNOH_OTUKOH_BYTE6));
  CS_PRINT_OUTPUT("%02X ", ten_ohpp_get_doe_ram_byte(module_id,  string, TEN_OTNOH_OTUKOH_BYTE7));

  CS_PRINT_OUTPUT("\n TCM Activation:     ");
  CS_PRINT_OUTPUT("%02X ", ten_ohpp_get_doe_ram_byte(module_id,  string, TEN_OTNOH_TCMACT));

  CS_PRINT_OUTPUT("\n TCM 6:              ");
  CS_PRINT_OUTPUT("%02X ", ten_ohpp_get_doe_ram_byte(module_id,  string, TEN_OTNOH_TCM6_BYTE1));
  CS_PRINT_OUTPUT("%02X ", ten_ohpp_get_doe_ram_byte(module_id,  string, TEN_OTNOH_TCM6_BYTE2));
  CS_PRINT_OUTPUT("%02X ", ten_ohpp_get_doe_ram_byte(module_id,  string, TEN_OTNOH_TCM6_BYTE3));

  CS_PRINT_OUTPUT("\n TCM 5:              ");
  CS_PRINT_OUTPUT("%02X ", ten_ohpp_get_doe_ram_byte(module_id,  string, TEN_OTNOH_TCM5_BYTE1));
  CS_PRINT_OUTPUT("%02X ", ten_ohpp_get_doe_ram_byte(module_id,  string, TEN_OTNOH_TCM5_BYTE2));
  CS_PRINT_OUTPUT("%02X ", ten_ohpp_get_doe_ram_byte(module_id,  string, TEN_OTNOH_TCM5_BYTE3));

  CS_PRINT_OUTPUT("\n TCM 4:              ");
  CS_PRINT_OUTPUT("%02X ", ten_ohpp_get_doe_ram_byte(module_id,  string, TEN_OTNOH_TCM4_BYTE1));
  CS_PRINT_OUTPUT("%02X ", ten_ohpp_get_doe_ram_byte(module_id,  string, TEN_OTNOH_TCM4_BYTE2));
  CS_PRINT_OUTPUT("%02X ", ten_ohpp_get_doe_ram_byte(module_id,  string, TEN_OTNOH_TCM4_BYTE3));

  CS_PRINT_OUTPUT("\n Fault Type/Loc:     ");
  CS_PRINT_OUTPUT("%02X ", ten_ohpp_get_doe_ram_byte(module_id,  string, TEN_OTNOH_FTFL));

  CS_PRINT_OUTPUT("\n TCM 3:              ");
  CS_PRINT_OUTPUT("%02X ", ten_ohpp_get_doe_ram_byte(module_id,  string, TEN_OTNOH_TCM3_BYTE1));
  CS_PRINT_OUTPUT("%02X ", ten_ohpp_get_doe_ram_byte(module_id,  string, TEN_OTNOH_TCM3_BYTE2));
  CS_PRINT_OUTPUT("%02X ", ten_ohpp_get_doe_ram_byte(module_id,  string, TEN_OTNOH_TCM3_BYTE3));

  CS_PRINT_OUTPUT("\n TCM 2:              ");
  CS_PRINT_OUTPUT("%02X ", ten_ohpp_get_doe_ram_byte(module_id,  string, TEN_OTNOH_TCM2_BYTE1));
  CS_PRINT_OUTPUT("%02X ", ten_ohpp_get_doe_ram_byte(module_id,  string, TEN_OTNOH_TCM2_BYTE2));
  CS_PRINT_OUTPUT("%02X ", ten_ohpp_get_doe_ram_byte(module_id,  string, TEN_OTNOH_TCM2_BYTE3));

  CS_PRINT_OUTPUT("\n TCM 1:              ");
  CS_PRINT_OUTPUT("%02X ", ten_ohpp_get_doe_ram_byte(module_id,  string, TEN_OTNOH_TCM1_BYTE1));
  CS_PRINT_OUTPUT("%02X ", ten_ohpp_get_doe_ram_byte(module_id,  string, TEN_OTNOH_TCM1_BYTE2));
  CS_PRINT_OUTPUT("%02X ", ten_ohpp_get_doe_ram_byte(module_id,  string, TEN_OTNOH_TCM1_BYTE3));

  CS_PRINT_OUTPUT("\n Path Monitoring:    ");
  CS_PRINT_OUTPUT("%02X ", ten_ohpp_get_doe_ram_byte(module_id,  string, TEN_OTNOH_PM_BYTE1));
  CS_PRINT_OUTPUT("%02X ", ten_ohpp_get_doe_ram_byte(module_id,  string, TEN_OTNOH_PM_BYTE2));
  CS_PRINT_OUTPUT("%02X ", ten_ohpp_get_doe_ram_byte(module_id,  string, TEN_OTNOH_PM_BYTE3));

  CS_PRINT_OUTPUT("\n Experimental:       ");
  CS_PRINT_OUTPUT("%02X ", ten_ohpp_get_doe_ram_byte(module_id,  string, TEN_OTNOH_EXP_BYTE1));
  CS_PRINT_OUTPUT("%02X ", ten_ohpp_get_doe_ram_byte(module_id,  string, TEN_OTNOH_EXP_BYTE2));

  CS_PRINT_OUTPUT("\n GCC1:               ");
  CS_PRINT_OUTPUT("%02X ", ten_ohpp_get_doe_ram_byte(module_id,  string, TEN_OTNOH_GCC1_BYTE1));
  CS_PRINT_OUTPUT("%02X ", ten_ohpp_get_doe_ram_byte(module_id,  string, TEN_OTNOH_GCC1_BYTE2));

  CS_PRINT_OUTPUT("\n GCC2:               ");
  CS_PRINT_OUTPUT("%02X ", ten_ohpp_get_doe_ram_byte(module_id,  string, TEN_OTNOH_GCC2_BYTE1));
  CS_PRINT_OUTPUT("%02X ", ten_ohpp_get_doe_ram_byte(module_id,  string, TEN_OTNOH_GCC2_BYTE2));

  CS_PRINT_OUTPUT("\n APS/PCC:            ");
  CS_PRINT_OUTPUT("%02X ", ten_ohpp_get_doe_ram_byte(module_id,  string, TEN_OTNOH_APSPCC_BYTE1));
  CS_PRINT_OUTPUT("%02X ", ten_ohpp_get_doe_ram_byte(module_id,  string, TEN_OTNOH_APSPCC_BYTE2));
  CS_PRINT_OUTPUT("%02X ", ten_ohpp_get_doe_ram_byte(module_id,  string, TEN_OTNOH_APSPCC_BYTE3));
  CS_PRINT_OUTPUT("%02X ", ten_ohpp_get_doe_ram_byte(module_id,  string, TEN_OTNOH_APSPCC_BYTE4));

  CS_PRINT_OUTPUT("\n OPUk OH:            ");
  CS_PRINT_OUTPUT("%02X ", ten_ohpp_get_doe_ram_byte(module_id,  string, TEN_OTNOH_OPUKOH_BYTE1));
  CS_PRINT_OUTPUT("%02X ", ten_ohpp_get_doe_ram_byte(module_id,  string, TEN_OTNOH_OPUKOH_BYTE2));
  CS_PRINT_OUTPUT("%02X ", ten_ohpp_get_doe_ram_byte(module_id,  string, TEN_OTNOH_OPUKOH_BYTE3));
  CS_PRINT_OUTPUT("%02X ", ten_ohpp_get_doe_ram_byte(module_id,  string, TEN_OTNOH_OPUKOH_BYTE4));
  CS_PRINT_OUTPUT("%02X ", ten_ohpp_get_doe_ram_byte(module_id,  string, TEN_OTNOH_OPUKOH_BYTE5));
  CS_PRINT_OUTPUT("%02X ", ten_ohpp_get_doe_ram_byte(module_id,  string, TEN_OTNOH_OPUKOH_BYTE6));
  CS_PRINT_OUTPUT("%02X ", ten_ohpp_get_doe_ram_byte(module_id,  string, TEN_OTNOH_OPUKOH_BYTE7));
  CS_PRINT_OUTPUT("%02X ", ten_ohpp_get_doe_ram_byte(module_id,  string, TEN_OTNOH_OPUKOH_BYTE8));

  CS_PRINT_OUTPUT("\nEnd DOE RAM for Module %d, String %d\n\n", module_id, string);

  /* Turn on reg read/write dumps */
  g_pTEN->drvr_flag &= ~TEN_DRVR_LOG_SUSPEND;

  return (CS_OK);
}

/****************************************************************/
/* $rtn_hdr_start  OHPP DUMP DOI RAM                            */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : HIGH LEVEL                                      */
/* CHIP       : Tenabo                                          */
cs_status ten_hl_ohpp_dump_doi_ram(cs_uint16 module_id,
                                   cs_uint8  string)
/* INPUTS     : o Module Id                                     */
/*              o String                                        */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* Provides a text dump of the contents of the DOI RAM.         */
/* The DOI RAM stores 5 instances of a 512-bit string. The      */
/* first string begins at address zero, the next at address     */
/* 0x20, etc. DOI RAM address space above the 5 strings is      */
/* reserved.                                                    */
/* The RAM is a 192-entry table. Each entry is 16 bits wide and */
/* occupies 1 16-bit register.                                  */
/*                                                              */
/* The [string] parameter is specified as:                      */
/*   0 = Extracted OxU3 management overhead                     */
/*   1 = Extracted management overhead from OxU2 stream 1       */
/*   2 = Extracted management overhead from OxU2 stream 2       */
/*   3 = Extracted management overhead from OxU2 stream 3       */
/*   4 = Extracted management overhead from OxU2 stream 4.      */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  cs_uint32 err_code = 0;

  if (!(TEN_IS_MOD_VALID(module_id, &err_code))) {
    CS_PRINT_OUTPUT("ERROR: API   -Id (0x%x) is invalid!\n", module_id);
    return(CS_ERROR);
  }
  if (string > 4) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": string out of range.  s/b 0..4.");
    return(CS_ERROR);
  }

  /* Turn off reg read/write dumps */
  g_pTEN->drvr_flag |= TEN_DRVR_LOG_SUSPEND;

  CS_PRINT_OUTPUT("\nDOI RAM for Module %d, String %d", module_id, string);

  CS_PRINT_OUTPUT("\n Frame Alignment OH: ");
  CS_PRINT_OUTPUT("%02X ", ten_ohpp_get_doi_ram_byte(module_id,  string, TEN_OTNOH_FAOH_BYTE1));
  CS_PRINT_OUTPUT("%02X ", ten_ohpp_get_doi_ram_byte(module_id,  string, TEN_OTNOH_FAOH_BYTE2));
  CS_PRINT_OUTPUT("%02X ", ten_ohpp_get_doi_ram_byte(module_id,  string, TEN_OTNOH_FAOH_BYTE3));
  CS_PRINT_OUTPUT("%02X ", ten_ohpp_get_doi_ram_byte(module_id,  string, TEN_OTNOH_FAOH_BYTE4));
  CS_PRINT_OUTPUT("%02X ", ten_ohpp_get_doi_ram_byte(module_id,  string, TEN_OTNOH_FAOH_BYTE5));
  CS_PRINT_OUTPUT("%02X ", ten_ohpp_get_doi_ram_byte(module_id,  string, TEN_OTNOH_FAOH_BYTE6));
  CS_PRINT_OUTPUT("%02X ", ten_ohpp_get_doi_ram_byte(module_id,  string, TEN_OTNOH_FAOH_BYTE7));

  CS_PRINT_OUTPUT("\n OTUk OH:            ");
  CS_PRINT_OUTPUT("%02X ", ten_ohpp_get_doi_ram_byte(module_id,  string, TEN_OTNOH_OTUKOH_BYTE1));
  CS_PRINT_OUTPUT("%02X ", ten_ohpp_get_doi_ram_byte(module_id,  string, TEN_OTNOH_OTUKOH_BYTE2));
  CS_PRINT_OUTPUT("%02X ", ten_ohpp_get_doi_ram_byte(module_id,  string, TEN_OTNOH_OTUKOH_BYTE3));
  CS_PRINT_OUTPUT("%02X ", ten_ohpp_get_doi_ram_byte(module_id,  string, TEN_OTNOH_OTUKOH_BYTE4));
  CS_PRINT_OUTPUT("%02X ", ten_ohpp_get_doi_ram_byte(module_id,  string, TEN_OTNOH_OTUKOH_BYTE5));
  CS_PRINT_OUTPUT("%02X ", ten_ohpp_get_doi_ram_byte(module_id,  string, TEN_OTNOH_OTUKOH_BYTE6));
  CS_PRINT_OUTPUT("%02X ", ten_ohpp_get_doi_ram_byte(module_id,  string, TEN_OTNOH_OTUKOH_BYTE7));

  CS_PRINT_OUTPUT("\n TCM Activation:     ");
  CS_PRINT_OUTPUT("%02X ", ten_ohpp_get_doi_ram_byte(module_id,  string, TEN_OTNOH_TCMACT));

  CS_PRINT_OUTPUT("\n TCM 6:              ");
  CS_PRINT_OUTPUT("%02X ", ten_ohpp_get_doi_ram_byte(module_id,  string, TEN_OTNOH_TCM6_BYTE1));
  CS_PRINT_OUTPUT("%02X ", ten_ohpp_get_doi_ram_byte(module_id,  string, TEN_OTNOH_TCM6_BYTE2));
  CS_PRINT_OUTPUT("%02X ", ten_ohpp_get_doi_ram_byte(module_id,  string, TEN_OTNOH_TCM6_BYTE3));

  CS_PRINT_OUTPUT("\n TCM 5:              ");
  CS_PRINT_OUTPUT("%02X ", ten_ohpp_get_doi_ram_byte(module_id,  string, TEN_OTNOH_TCM5_BYTE1));
  CS_PRINT_OUTPUT("%02X ", ten_ohpp_get_doi_ram_byte(module_id,  string, TEN_OTNOH_TCM5_BYTE2));
  CS_PRINT_OUTPUT("%02X ", ten_ohpp_get_doi_ram_byte(module_id,  string, TEN_OTNOH_TCM5_BYTE3));

  CS_PRINT_OUTPUT("\n TCM 4:              ");
  CS_PRINT_OUTPUT("%02X ", ten_ohpp_get_doi_ram_byte(module_id,  string, TEN_OTNOH_TCM4_BYTE1));
  CS_PRINT_OUTPUT("%02X ", ten_ohpp_get_doi_ram_byte(module_id,  string, TEN_OTNOH_TCM4_BYTE2));
  CS_PRINT_OUTPUT("%02X ", ten_ohpp_get_doi_ram_byte(module_id,  string, TEN_OTNOH_TCM4_BYTE3));

  CS_PRINT_OUTPUT("\n Fault Type/Loc:     ");
  CS_PRINT_OUTPUT("%02X ", ten_ohpp_get_doi_ram_byte(module_id,  string, TEN_OTNOH_FTFL));

  CS_PRINT_OUTPUT("\n TCM 3:              ");
  CS_PRINT_OUTPUT("%02X ", ten_ohpp_get_doi_ram_byte(module_id,  string, TEN_OTNOH_TCM3_BYTE1));
  CS_PRINT_OUTPUT("%02X ", ten_ohpp_get_doi_ram_byte(module_id,  string, TEN_OTNOH_TCM3_BYTE2));
  CS_PRINT_OUTPUT("%02X ", ten_ohpp_get_doi_ram_byte(module_id,  string, TEN_OTNOH_TCM3_BYTE3));

  CS_PRINT_OUTPUT("\n TCM 2:              ");
  CS_PRINT_OUTPUT("%02X ", ten_ohpp_get_doi_ram_byte(module_id,  string, TEN_OTNOH_TCM2_BYTE1));
  CS_PRINT_OUTPUT("%02X ", ten_ohpp_get_doi_ram_byte(module_id,  string, TEN_OTNOH_TCM2_BYTE2));
  CS_PRINT_OUTPUT("%02X ", ten_ohpp_get_doi_ram_byte(module_id,  string, TEN_OTNOH_TCM2_BYTE3));

  CS_PRINT_OUTPUT("\n TCM 1:              ");
  CS_PRINT_OUTPUT("%02X ", ten_ohpp_get_doi_ram_byte(module_id,  string, TEN_OTNOH_TCM1_BYTE1));
  CS_PRINT_OUTPUT("%02X ", ten_ohpp_get_doi_ram_byte(module_id,  string, TEN_OTNOH_TCM1_BYTE2));
  CS_PRINT_OUTPUT("%02X ", ten_ohpp_get_doi_ram_byte(module_id,  string, TEN_OTNOH_TCM1_BYTE3));

  CS_PRINT_OUTPUT("\n Path Monitoring:    ");
  CS_PRINT_OUTPUT("%02X ", ten_ohpp_get_doi_ram_byte(module_id,  string, TEN_OTNOH_PM_BYTE1));
  CS_PRINT_OUTPUT("%02X ", ten_ohpp_get_doi_ram_byte(module_id,  string, TEN_OTNOH_PM_BYTE2));
  CS_PRINT_OUTPUT("%02X ", ten_ohpp_get_doi_ram_byte(module_id,  string, TEN_OTNOH_PM_BYTE3));

  CS_PRINT_OUTPUT("\n Experimental:       ");
  CS_PRINT_OUTPUT("%02X ", ten_ohpp_get_doi_ram_byte(module_id,  string, TEN_OTNOH_EXP_BYTE1));
  CS_PRINT_OUTPUT("%02X ", ten_ohpp_get_doi_ram_byte(module_id,  string, TEN_OTNOH_EXP_BYTE2));

  CS_PRINT_OUTPUT("\n GCC1:               ");
  CS_PRINT_OUTPUT("%02X ", ten_ohpp_get_doi_ram_byte(module_id,  string, TEN_OTNOH_GCC1_BYTE1));
  CS_PRINT_OUTPUT("%02X ", ten_ohpp_get_doi_ram_byte(module_id,  string, TEN_OTNOH_GCC1_BYTE2));

  CS_PRINT_OUTPUT("\n GCC2:               ");
  CS_PRINT_OUTPUT("%02X ", ten_ohpp_get_doi_ram_byte(module_id,  string, TEN_OTNOH_GCC2_BYTE1));
  CS_PRINT_OUTPUT("%02X ", ten_ohpp_get_doi_ram_byte(module_id,  string, TEN_OTNOH_GCC2_BYTE2));

  CS_PRINT_OUTPUT("\n APS/PCC:            ");
  CS_PRINT_OUTPUT("%02X ", ten_ohpp_get_doi_ram_byte(module_id,  string, TEN_OTNOH_APSPCC_BYTE1));
  CS_PRINT_OUTPUT("%02X ", ten_ohpp_get_doi_ram_byte(module_id,  string, TEN_OTNOH_APSPCC_BYTE2));
  CS_PRINT_OUTPUT("%02X ", ten_ohpp_get_doi_ram_byte(module_id,  string, TEN_OTNOH_APSPCC_BYTE3));
  CS_PRINT_OUTPUT("%02X ", ten_ohpp_get_doi_ram_byte(module_id,  string, TEN_OTNOH_APSPCC_BYTE4));

  CS_PRINT_OUTPUT("\n OPUk OH:            ");
  CS_PRINT_OUTPUT("%02X ", ten_ohpp_get_doi_ram_byte(module_id,  string, TEN_OTNOH_OPUKOH_BYTE1));
  CS_PRINT_OUTPUT("%02X ", ten_ohpp_get_doi_ram_byte(module_id,  string, TEN_OTNOH_OPUKOH_BYTE2));
  CS_PRINT_OUTPUT("%02X ", ten_ohpp_get_doi_ram_byte(module_id,  string, TEN_OTNOH_OPUKOH_BYTE3));
  CS_PRINT_OUTPUT("%02X ", ten_ohpp_get_doi_ram_byte(module_id,  string, TEN_OTNOH_OPUKOH_BYTE4));
  CS_PRINT_OUTPUT("%02X ", ten_ohpp_get_doi_ram_byte(module_id,  string, TEN_OTNOH_OPUKOH_BYTE5));
  CS_PRINT_OUTPUT("%02X ", ten_ohpp_get_doi_ram_byte(module_id,  string, TEN_OTNOH_OPUKOH_BYTE6));
  CS_PRINT_OUTPUT("%02X ", ten_ohpp_get_doi_ram_byte(module_id,  string, TEN_OTNOH_OPUKOH_BYTE7));
  CS_PRINT_OUTPUT("%02X ", ten_ohpp_get_doi_ram_byte(module_id,  string, TEN_OTNOH_OPUKOH_BYTE8));

  CS_PRINT_OUTPUT("\nEnd DOI RAM for Module %d, String %d\n\n", module_id, string);

  /* Turn on reg read/write dumps */
  g_pTEN->drvr_flag &= ~TEN_DRVR_LOG_SUSPEND;

  return (CS_OK);
}

/****************************************************************/
/* $rtn_hdr_start  OHPP AND SHADOW RAM INIT                     */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : HIGH LEVEL                                      */
/* CHIP       : Tenabo                                          */
cs_status ten_hl_ohpp_and_shadow_ram_init(cs_uint16 dev_id)
/* INPUTS     : o Device Id                                     */
/*              o String                                        */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* Initializes the both sides (module A and B) of OHPP for use, */
/* and additionally clears the shadow RAM.                      */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  cs_status rtn = CS_OK;
  cs_uint16 tmp_mod_id;
  cs_uint16 ii;
  T41_t *pDev = NULL;
  
  for (ii=0; ii<2; ii++) {
    if (ii == 0) {
      tmp_mod_id = (cs_uint16)((dev_id << 8) | TEN_MODULE_A);
    } 
    else {
      tmp_mod_id = (cs_uint16)((dev_id << 8) | TEN_MODULE_B);
    }
    rtn |= ten_hl_ohpp_init(tmp_mod_id);
    rtn |= ten_ohpp_clear_shadow_sfc_ram(tmp_mod_id, 0);
    rtn |= ten_ohpp_clear_shadow_sfc_ram(tmp_mod_id, 1);

    /* Bugzilla 24048 */
    /* The default value of 759 in SFCCYCLMT causes a delay while going
       through RAM address 623 through 759 during which time the RAM 
       address is forceed to 0. If a consequent action occurred during this 
       time, it would incorrectly apply to address 0 i.e.0xU3 maintainace 
       signal. Writing a value of 624 skips this delay and forces the RAM
       address to 0 after reaching address 623 */ 

    TEN_MOD_COMMON_VALIDATE(tmp_mod_id, pDev, CS_ERROR);

    TEN_MOD_LOCK(tmp_mod_id, TEN_ID_OHPP);
    
    /* bugzilla #24439, klocwork */
    if (ii == 0) {
      TEN_REG_WRITE(TEN_OHPP_SFU_REG_ADDR(pDev, TEN_MODULE_A, SFCCYCLMT), 624);
    } 
    else {
      TEN_REG_WRITE(TEN_OHPP_SFU_REG_ADDR(pDev, TEN_MODULE_B, SFCCYCLMT), 624);
    }
    TEN_MOD_UNLOCK(tmp_mod_id, TEN_ID_OHPP);
  }
  return (rtn);
}

/****************************************************************/
/* $rtn_hdr_start  OHPP INIT                                    */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : HIGH LEVEL                                      */
/* CHIP       : Tenabo                                          */
cs_status ten_hl_ohpp_init(cs_uint16 module_id)
/* INPUTS     : o Module Id                                     */
/*              o String                                        */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* Initializes the OHPP for use.                                */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  cs_status rtn = CS_OK; 
  cs_uint16 mod_num1, mod_num2;
  
  CS_PRINT("ten_hl_ohpp_init\n");
 
  /* remove global reset for ohpp_a/ohpp_b */
  if (TEN_MOD_ID_TO_MOD_NUM(module_id) == TEN_MODULE_A) {
    mod_num1 = TEN_MPIF_GLOBAL_RESET_COMMON_OHPP_A;
    mod_num2 = TEN_MPIF_GLOBAL_CLOCK_DISABLE_COMMON_OHPP_A;
  }
  else {
    mod_num1 = TEN_MPIF_GLOBAL_RESET_COMMON_OHPP_B;
    mod_num2 = TEN_MPIF_GLOBAL_CLOCK_DISABLE_COMMON_OHPP_B;
  }
  
  /* deassert ohpp_a/ohpp_b, spoh resets */
  mod_num1 |= TEN_MPIF_GLOBAL_RESET_COMMON_SPOH;

  /* enable ohpp_a/ohpp_b, spoh, xcon clock */
  mod_num2 |= (TEN_MPIF_GLOBAL_CLOCK_DISABLE_COMMON_XCON | 
               TEN_MPIF_GLOBAL_CLOCK_DISABLE_COMMON_SPOH);

  rtn |= ten_mpif_global_clock_disable_common(TEN_MOD_ID_TO_DEV_ID(module_id), 
                                              CS_ENABLE, 
                                              mod_num2);
  
  rtn = ten_mpif_global_reset_common(TEN_MOD_ID_TO_DEV_ID(module_id), 
                                     CS_RESET_DEASSERT,
                                     mod_num1);

  /* enable overhead insertion from the framer(s)                     */
  /* STS OH: 11~8                                                     */
  /* OTNOH: 0~4, (0: OxU2_1, 1: OxU2_2, 2:OxU2_3, 3:OxU2_4, 4:OxU3)   */
  /* OHPP_SFU_FRMROHEN => 0x1f                                        */
  rtn |= ten_ohpp_sfu_set_admohen(module_id, 0xF);
  rtn |= ten_ohpp_sfu_set_stsohen(module_id, 0xF);
  rtn |= ten_ohpp_sfu_set_otnohen(module_id, 0x1F);
  
  /* release soft reset */
  rtn |= ten_ohpp_sfu_sreset(module_id, CS_RESET_DEASSERT);

  return (rtn);
}

/****************************************************************/
/* $rtn_hdr_start  OHPP CONTROL ODUK OCI                        */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : HIGH LEVEL                                      */
/* CHIP       : Tenabo                                          */
cs_status ten_hl_ohpp_control_oduk_oci(cs_uint16 module_id,
                                       cs_uint8 slice,
                                       cs_ctl_t ctl)
/* INPUTS     : o Module Id                                     */
/*              o Slice                                         */
/*              o Control                                       */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* Control (Insert/clear) downstream ODUk-OCI to 10G channel    */
/* slice.                                                       */
/*                                                              */
/* The [slice] parameter is specified as:                       */
/*   0x00 = TEN_SLICE0                                          */
/*   0x01 = TEN_SLICE1                                          */
/*   0x02 = TEN_SLICE2                                          */
/*   0x03 = TEN_SLICE3                                          */
/*   0xFF = TEN_SLICE_ALL                                       */
/*                                                              */
/* [ctl]  Controls ODUk OCI                                     */
/*   0 = CS_DISABLE                                             */
/*   1 = CS_ENABLE, insert downstream ODUk-OCI to 10G slice.    */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  cs_status rtn = CS_OK; 
  /* Bug 26471 Start: Code did not originally support TEN_SLICE_ALL        */
  cs_uint8  i;
  /* Bug 26471 End                                                         */

  CS_PRINT("ten_hl_ohpp_control_oduk_oci\n");

  if ((slice>=TEN_MAX_SLICES) && (slice != TEN_SLICE_ALL)) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": slice out of range.  s/b 0..3 or 0xFF.");
    return (CS_ERROR);
  }
  
  if (ctl > CS_ENABLE) { 
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": ctl out of range."); 
    return (CS_ERROR);
  }

  if (ctl == CS_ENABLE) {
    /* Insert downstream ODUk-OCI to 10G channel slice */
    /* Clear resets and enable clocks */
    rtn |= ten_hl_resets_global(TEN_MOD_ID_TO_DEV_ID(module_id), TEN_MODULE_A_AND_B, TEN_SLICE_ALL, CS_TX_AND_RX, CS_RESET_DEASSERT, TEN_HL_RESETS_GLOBAL_COMMON);
    rtn |= ten_mpif_global_clock_disable_common(TEN_MOD_ID_TO_DEV_ID(module_id), CS_ENABLE, TEN_MPIF_GLOBAL_CLOCK_DISABLE_COMMON_ALL);
    /* Enable OTN<->OHPP communications for all four 10G streams and the 40G stream */
    rtn |= ten_ohpp_sfu_set_otnohen(module_id, 0x1f);
    rtn |= ten_ohpp_sfu_sreset(module_id, CS_RESET_DEASSERT);
    /* Bug 26471 Start: Code did not originally support TEN_SLICE_ALL        */
    /* Note: 1 is added to the slice number (i+1) because slice numbers 0..3 */
    /* correspond to "stream" numbers 1..4. Refer to ohpp_consequent_actions */
    /* enum.                                                                 */
    for (i=0; i<TEN_MAX_SLICES; i++) {
      if ((slice == i) || (slice == TEN_SLICE_ALL)) {
        rtn |= ten_ohpp_sfu_insert_otn_maintenance_signal(module_id, TEN_OHPP_INSERT_OCI, TEN_OHPP_WIDTH_FRAME, i+1);
        rtn |= ten_ohpp_sfu_set_msignal(module_id, i+1, ctl);
      }
    }
    /* Bug 26471 End                                                         */
    /* bipxor=0xff, bipmsk=0xff */
    rtn |= ten_n10g_otnt_cfg4(module_id, slice, 0xff, 0xff);
  }
  else {
    /* Clear downstream ODUk-OCI */
    /* Clear resets and enable clocks */
    rtn |= ten_hl_resets_global(TEN_MOD_ID_TO_DEV_ID(module_id), TEN_MODULE_A_AND_B, TEN_SLICE_ALL, CS_TX_AND_RX, CS_RESET_DEASSERT, TEN_HL_RESETS_GLOBAL_COMMON);
    rtn |= ten_mpif_global_clock_disable_common(TEN_MOD_ID_TO_DEV_ID(module_id), CS_ENABLE, TEN_MPIF_GLOBAL_CLOCK_DISABLE_COMMON_ALL);
    /* Enable OTN<->OHPP communications for all four 10G streams and the 40G stream */
    rtn |= ten_ohpp_sfu_set_otnohen(module_id, 0x1f);
    rtn |= ten_ohpp_sfu_sreset(module_id, CS_RESET_DEASSERT);
    /* Bug 26471 Start: Code did not originally support TEN_SLICE_ALL        */
    /* Note: 1 is added to the slice number (i+1) because slice numbers 0..3 */
    /* correspond to "stream" numbers 1..4. Refer to ohpp_consequent_actions */
    /* enum.                                                                 */
    for (i=0; i<TEN_MAX_SLICES; i++) {
      if ((slice == i) || (slice == TEN_SLICE_ALL)) {
        rtn |= ten_ohpp_sfu_insert_otn_maintenance_signal(module_id, TEN_OHPP_INSERT_OCI, TEN_OHPP_WIDTH_FRAME, i+1);
        rtn |= ten_ohpp_sfu_set_msignal(module_id, i+1, ctl);
      }
    }
    /* Bug 26471 End                                                         */
    /* bipxor=0x00, bipmsk=0xff */
    rtn |= ten_n10g_otnt_cfg4(module_id, slice, 0x00, 0xff);
  }
  return (rtn);
}

/****************************************************************/
/* $rtn_hdr_start  SET DOI RAM CONFIG                           */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : HIGH LEVEL                                      */
/* CHIP       : Tenabo                                          */
cs_status ten_hl_ohpp_doi_ram_config(cs_uint16 module_id,
                                     cs_uint8 doa_insert_enbl,
                                     cs_uint8 mgt_ovhd_stream,
                                     cs_uint8 ram_byte_start_idx,
                                     cs_uint8 ram_byte_stop_idx,
                                     cs_uint8 ram_byte_value,
                                     cs_uint8 insert_oh_ctrl,
                                     cs_uint8 mfas_match_unit,
                                     cs_uint8 mfas_match_cmp,
                                     cs_uint8 mfas_match_mask)
/* INPUTS     : o Module Id                                     */
/*              o Direct Overhead Insertion Enable              */
/*              o Managament Overhead Stream                    */
/*              o RAM Overhead Byte Start Index                 */
/*              o RAM Overhead Byte Stop Index                  */
/*              o RAM Byte Value                                */
/*              o Insert Overhead control                       */
/*              o MFAS Match Unit Index                         */
/*              o Comparison reference for MFAS Match Unit      */
/*              o Mask for MFAS Match Unit                      */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* The overhead generator is equipped with a 64-byte wide RAM   */
/* register array accessed through registers. This API allows   */
/* changing the byte values to be inserted in the TX overhead   */
/* space.                                                       */
/*                                                              */
/* The [doa_insert_enbl] parameter enables the Direct Overhead  */
/* Access Insertion Unit from the SFU.                          */
/*                                                              */
/* The [mgt_ovhd_stream] parameter is specified as:             */
/*   0 = OxU3 management overhead                               */
/*   1 = Management overhead for OxU2 stream 1                  */
/*   2 = Management overhead for OxU2 stream 2                  */
/*   3 = Management overhead for OxU2 stream 3                  */
/*   4 = Management overhead for OxU2 stream 4                  */
/*                                                              */
/* The [ram_byte_start_idx] parameter is specified as :         */
/* The [ram_byte_stop_idx] parameter is specified as :          */
/*   TEN_OTNOH_FAOH_BYTE1           = 0                         */
/*   TEN_OTNOH_FAOH_BYTE2           = 1                         */
/*   TEN_OTNOH_FAOH_BYTE3           = 2                         */
/*   TEN_OTNOH_FAOH_BYTE4           = 3                         */
/*   TEN_OTNOH_FAOH_BYTE5           = 4                         */
/*   TEN_OTNOH_FAOH_BYTE6           = 5                         */
/*   TEN_OTNOH_FAOH_BYTE7           = 6                         */
/*   TEN_OTNOH_OTUKOH_BYTE1         = 7                         */
/*   TEN_OTNOH_OTUKOH_BYTE2         = 8                         */
/*   TEN_OTNOH_OTUKOH_BYTE3         = 9                         */
/*   TEN_OTNOH_OTUKOH_BYTE4         = 10                        */
/*   TEN_OTNOH_OTUKOH_BYTE5         = 11                        */
/*   TEN_OTNOH_OTUKOH_BYTE6         = 12                        */
/*   TEN_OTNOH_OTUKOH_BYTE7         = 13                        */
/*   TEN_OTNOH_OPUKOH_BYTE1         = 14                        */
/*   TEN_OTNOH_OPUKOH_BYTE2         = 15                        */
/*                                                              */
/*   TEN_OTNOH_RES_BYTE1            = 16                        */
/*   TEN_OTNOH_RES_BYTE2            = 17                        */
/*   TEN_OTNOH_RES_BYTE3            = 18                        */
/*   TEN_OTNOH_TCMACT               = 19                        */
/*   TEN_OTNOH_TCM6_BYTE1           = 20                        */
/*   TEN_OTNOH_TCM6_BYTE2           = 21                        */
/*   TEN_OTNOH_TCM6_BYTE3           = 22                        */
/*   TEN_OTNOH_TCM5_BYTE1           = 23                        */
/*   TEN_OTNOH_TCM5_BYTE2           = 24                        */
/*   TEN_OTNOH_TCM5_BYTE3           = 25                        */
/*   TEN_OTNOH_TCM4_BYTE1           = 26                        */
/*   TEN_OTNOH_TCM4_BYTE2           = 27                        */
/*   TEN_OTNOH_TCM4_BYTE3           = 28                        */
/*   TEN_OTNOH_FTFL                 = 29                        */
/*   TEN_OTNOH_OPUKOH_BYTE3         = 30                        */
/*   TEN_OTNOH_OPUKOH_BYTE4         = 31                        */
/*                                                              */
/*   TEN_OTNOH_TCM3_BYTE1           = 32                        */
/*   TEN_OTNOH_TCM3_BYTE2           = 33                        */
/*   TEN_OTNOH_TCM3_BYTE3           = 34                        */
/*   TEN_OTNOH_TCM2_BYTE1           = 35                        */
/*   TEN_OTNOH_TCM2_BYTE2           = 36                        */
/*   TEN_OTNOH_TCM2_BYTE3           = 37                        */
/*   TEN_OTNOH_TCM1_BYTE1           = 38                        */
/*   TEN_OTNOH_TCM1_BYTE2           = 39                        */
/*   TEN_OTNOH_TCM1_BYTE3           = 40                        */
/*   TEN_OTNOH_PM_BYTE1             = 41                        */
/*   TEN_OTNOH_PM_BYTE2             = 42                        */
/*   TEN_OTNOH_PM_BYTE3             = 43                        */
/*   TEN_OTNOH_EXP_BYTE1            = 44                        */
/*   TEN_OTNOH_EXP_BYTE2            = 45                        */
/*   TEN_OTNOH_OPUKOH_BYTE5         = 46                        */
/*   TEN_OTNOH_OPUKOH_BYTE6         = 47                        */
/*                                                              */
/*   TEN_OTNOH_GCC1_BYTE1           = 48                        */
/*   TEN_OTNOH_GCC1_BYTE2           = 49                        */
/*   TEN_OTNOH_GCC2_BYTE1           = 50                        */
/*   TEN_OTNOH_GCC2_BYTE2           = 51                        */
/*   TEN_OTNOH_APSPCC_BYTE1         = 52                        */
/*   TEN_OTNOH_APSPCC_BYTE2         = 53                        */
/*   TEN_OTNOH_APSPCC_BYTE3         = 54                        */
/*   TEN_OTNOH_APSPCC_BYTE4         = 55                        */
/*   TEN_OTNOH_RES_BYTE4            = 56                        */
/*   TEN_OTNOH_RES_BYTE5            = 57                        */
/*   TEN_OTNOH_RES_BYTE6            = 58                        */
/*   TEN_OTNOH_RES_BYTE7            = 59                        */
/*   TEN_OTNOH_RES_BYTE8            = 60                        */
/*   TEN_OTNOH_RES_BYTE9            = 61                        */
/*   TEN_OTNOH_OPUKOH_BYTE7         = 62                        */
/*   TEN_OTNOH_OPUKOH_BYTE8         = 63                        */
/*                                                              */
/* The [ram_byte_value] parameter specifies the value to write  */
/* to the specified RAM location                                */
/*   0x00 - 0xFF                                                */
/*                                                              */
/* The [insert_oh_ctrl] parameter is the Overhead Data Insertion*/
/* Control from the framer                                      */
/*   0 = Never insert overhead byte                             */
/*   1 = Insert overhead byte when MFM1 is active               */
/*   2 = Insert overhead byte when MFM2 is active               */
/*   3 = Insert overhead byte when MFM3 is active.              */
/*                                                              */
/* The [mfas_match_unit] parameter indicates an event when the  */
/* match occurs. For example, an event could be when 0 and 64th */
/* frames occur, insert the ram_byte_value specified.           */
/* Based on the MFAS sequence generated by the internal MFAS    */
/* counter, up to 3 DOI MFAS match events may be generated for  */
/* each transmitted frame. The internal MFAS counter is compared*/
/* compared with 3 user-defined values specified in the         */
/* mfas_match_unit parameter.                                   */
/* This comparison is only performed when the corresponding bits*/
/* of [mfas_match_mask] are set to 1. Setting the complete mask */
/* register to zero leads to a permanent match per frame.       */
/*   MFAS Match unit = 1-3  (DOI)                               */
/*                                                              */
/* The [mfas_match_cmp] parameter is the comparison reference   */
/* for MFAS Match Unit specified by [mfas_match_unit]. If this  */
/* value matches with the accepted MFAS across all bits selected*/
/* in [mfas_match_mask] an MFM1 Event will be generated.        */
/*   0 - 0xFF                                                   */
/*                                                              */
/* The [mfas_match_mask] parameter is the mask for MFAS Match   */
/* Unit specified by [mfas_match_unit]. If the bits selected in */
/* [mfas_match_mask] match between [mfas_match_cmp] and the     */
/* accepted MFAS, an MFM1 Event will be generated.              */
/*   0 - 0xFF                                                   */
/*                                                              */
/* MFAS & [mfas_match_mask] = [mfas_match_cmp]                  */
/* USAGE EXAMPLE:                                               */
/* [a] Change an OH byte in the first multiframe out of 255     */
/*     mfas_match_cmp  = 0x01                                   */
/*     mfas_match_mask = 0xFF                                   */
/* [b] Change an OH byte every 64th frame                       */
/*     mfas_match_cmp  = 0xBF                                   */
/*     mfas_match_mask = 0x00                                   */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{ /* Bugzilla 22547 */
  TEN_OHPP_SFU_CFG_t tmp_sfu_cfg;
  TEN_OHPP_SFU_STATE_t tmp_sfu_state;
  cs_uint8 i;
  T41_t *pDev = NULL;
  cs_uint8 slice = 0;
  cs_char8 *func = "ten_hl_ohpp_doi_ram_config";  

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);

  if (doa_insert_enbl > 1) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": doa_insert_enbl out of range 0..1");
    return(CS_ERROR);
  }

  if ( mgt_ovhd_stream > 4) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": mgt_ovhd_stream out of range 0..4");
    return(CS_ERROR);
  }

  if (ram_byte_start_idx > 63) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": ram_byte_start_idx out of range 0..63");
    return(CS_ERROR);
  }

  if (ram_byte_stop_idx > 63) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": ram_byte_stop_idx out of range 0..63");
    return(CS_ERROR);
  }

  if (insert_oh_ctrl > 3) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": insert_oh_ctrl out of range 0..3");
    return(CS_ERROR);
  }

  if ((mfas_match_unit < 1) || (mfas_match_unit > 3)) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": mfas_match_unit out of range 1..11");
    return(CS_ERROR);
  }

  CS_PRINT("%s()\n", func);
  CS_PRINT("    %s\n", ten_module_strings[module_id & 1]);
  CS_PRINT("    doa_insert_enbl = %d\n", doa_insert_enbl);
  CS_PRINT("    mgt_ovhd_stream = %d\n", mgt_ovhd_stream);
  CS_PRINT("    ram_byte_start_idx = %d\n", ram_byte_start_idx);
  CS_PRINT("    ram_byte_stop_idx = %d\n", ram_byte_stop_idx);
  CS_PRINT("    ram_byte_value = 0x%X\n", ram_byte_value);
  CS_PRINT("    insert_oh_ctrl = %d\n", insert_oh_ctrl);
  CS_PRINT("    mfas_match_unit = 0x%X\n", mfas_match_unit);
  CS_PRINT("    mfas_match_cmp = 0x%X\n", mfas_match_cmp);
  CS_PRINT("    mfas_match_mask = 0x%X\n", mfas_match_mask);

  /*  Use management overhead stream index to determine the n10g slice */
  if (mgt_ovhd_stream > 0) {
    slice = mgt_ovhd_stream-1;
  }

  tmp_sfu_cfg.wrd = TEN_REG_READ(TEN_OHPP_SFU_REG_ADDR(pDev, module_id, CFG));
  CS_PRINT("sfu_cfg.bf.DOAIEN=%d\n", tmp_sfu_cfg.bf.DOAIEN);
  
  tmp_sfu_state.wrd = TEN_REG_READ(TEN_OHPP_SFU_REG_ADDR(pDev, module_id, STATE));

  CS_PRINT("SFCINIT=%d\n", tmp_sfu_state.bf.SFCINIT);
  CS_PRINT("SFCBANK=%d\n", tmp_sfu_state.bf.SFCBANK);
  CS_PRINT("DOAIRF=%d\n", tmp_sfu_state.bf.DOAIRF);
  CS_PRINT("DOAIBFF=%d\n", tmp_sfu_state.bf.DOAIBFF);
  CS_PRINT("PHLOST=%d\n", tmp_sfu_state.bf.PHLOST);

  /***** Enabling the insertion into a particular Tx OH byte #i from the Direct Overhead
         Inserter after the DOI inserter has been enabled *****/
  if ((doa_insert_enbl == 1)&&(tmp_sfu_cfg.bf.DOAIEN == 1)) {
    CS_PRINT("CASE #1:  doa_insert_enbl==1 and sfu_cfg.bf.DOAIEN==1\n");

    if (!tmp_sfu_state.bf.DOAIBFF) {
      /* Microprocessor writes the desired Tx OxUk overhead values into the DOI RAM through
         register bank OHPP_DOI_RAM(n) */
      for (i=ram_byte_start_idx; i<ram_byte_stop_idx+1;i++) {
        if (ten_ohpp_set_doi_ram_byte(module_id, mgt_ovhd_stream, i, ram_byte_value) != CS_OK) {
          return (CS_ERROR);
        }
      }
      
      /* Bugzilla #34016 */
      /* Configure the desired multiframe(s) (MFM) events triggering the Tx OxUk OH bytes 
         insertion the Direct Overhead Inserter (DOI)*/
      if (mgt_ovhd_stream == 0) {
        if(ten_n40g_otnt4x_mfmcfg(module_id, mfas_match_unit, mfas_match_cmp, mfas_match_mask) != CS_OK) {
          return (CS_ERROR);
        }
      }
      else {
        if(ten_n10g_otnt_mfmcfg(module_id, slice, mfas_match_unit, mfas_match_cmp, mfas_match_mask) != CS_OK) {
          return (CS_ERROR);
        }
      }
      
      /* Configure the 2-bit direct insertion control field of each individual Tx OH byte to 
         either insert the value programmed in the DOI RAM when triggered by the selected
         MFM event or disable insertion from the DOI memory for that particular OH byte.*/
      for (i=ram_byte_start_idx; i<ram_byte_stop_idx+1;i++) {
        if (mgt_ovhd_stream == 0) {
          if (ten_n40g_otnt4x_doaie(module_id, i, insert_oh_ctrl) != CS_OK) {
            return (CS_ERROR);
          }
        }
        else {
          if (ten_n10g_otnt_doaie(module_id, slice, i, insert_oh_ctrl) != CS_OK) {
            return (CS_ERROR);
          }
        }
      }
    }
    else {
      /* When set, the FIFO of the Direct Overhead Access Insert Buffer is full. */
      /* Any write attempts to DOAIB will be ignored. */
      CS_PRINT("WARNING:  tmp_sfu_state.bf.DOAIBFF=1\n");
      return (CS_ERROR);
    }
  }
  /***** Enabling the Direct Overhead Inserter *****/
  else if ((doa_insert_enbl == 1)&&(tmp_sfu_cfg.bf.DOAIEN == 0)) {
    CS_PRINT("CASE #2:  doa_insert_enbl==1 and sfu_cfg.bf.DOAIEN==0\n");

    /* Bugzilla #34016, must enable DOI before reading DOI RAM */
    /* Enable the Direct Overhead Inserter */
    ten_ohpp_sfu_set_doaien(module_id, 1);

    if (!tmp_sfu_state.bf.DOAIBFF) {

      /* Microprocessor writes the desired Tx OxUk overhead values into the DOI RAM through
         register bank OHPP_DOI_RAM(n) */
      for (i=ram_byte_start_idx; i<ram_byte_stop_idx+1;i++) {
        CS_PRINT("ten_ohpp_set_doi_ram_byte #2\n");
        if (ten_ohpp_set_doi_ram_byte(module_id, mgt_ovhd_stream, i, ram_byte_value) != CS_OK) {
          return (CS_ERROR);
        }
      }

      /* Configure the desired multiframe(s) (MFM) events triggering the Tx OxUk OH bytes 
         insertion the Direct Overhead Inserter (DOI)*/
      if (mgt_ovhd_stream == 0) {
        if(ten_n40g_otnt4x_mfmcfg(module_id, mfas_match_unit, mfas_match_cmp, mfas_match_mask) != CS_OK) {
          return (CS_ERROR);
        }
      }
      else {
        if(ten_n10g_otnt_mfmcfg(module_id, slice, mfas_match_unit, mfas_match_cmp, mfas_match_mask) != CS_OK) {
          return (CS_ERROR);
        }
      }

      /* Configure the 2-bit direct insertion control field of each individual Tx OH byte to 
         either insert the value programmed in the DOI RAM when triggered by the selected
         MFM event or disable insertion from the DOI memory for that particular OH byte.*/
      for (i=ram_byte_start_idx; i<ram_byte_stop_idx+1;i++) {
        if (mgt_ovhd_stream == 0) {
          if (ten_n40g_otnt4x_doaie(module_id, i, insert_oh_ctrl) != CS_OK) {
            return (CS_ERROR);
          }
        }
        else {
          if(ten_n10g_otnt_doaie(module_id, slice, i, insert_oh_ctrl) != CS_OK) {
            return (CS_ERROR);
          }
        }
      }
    }
    else {
      /* When set, the FIFO of the Direct Overhead Access Insert Buffer is full. */
      /* Any write attempts to DOAIB will be ignored. */
      CS_PRINT("WARNING:  tmp_sfu_state.bf.DOAIBFF=1\n");
      return (CS_ERROR);
    }
  }
  /***** Disabling the insertion into a particular Tx OH byte #i from the Direct Overhead
         Inserter after the DOI inserter has been enabled *****/
  else if ((doa_insert_enbl == 0)&&(tmp_sfu_cfg.bf.DOAIEN == 1)) {
    CS_PRINT("CASE #3:  doa_insert_enbl==0 and sfu_cfg.bf.DOAIEN==1\n");
  
    /* Configure the 2-bit direct insertion control field of each individual Tx OH byte to 
       a value 0 to disable insertion from the DOI memory for that particular OH byte.*/
    for (i=ram_byte_start_idx; i<ram_byte_stop_idx+1;i++) {
      if (mgt_ovhd_stream == 0) {
        if (ten_n40g_otnt4x_doaie(module_id, i, 0) != CS_OK) {
          return (CS_ERROR);
        }
      }
      else {
        if (ten_n10g_otnt_doaie(module_id, slice, i, 0) != CS_OK) {
          return (CS_ERROR);
        }
      }
    }
  }
  /***** Disabling the Direct Overhead Inserter all together (if unused) *****/
  else if ((doa_insert_enbl == 0)&&(tmp_sfu_cfg.bf.DOAIEN == 0)) {
    CS_PRINT("CASE #4:  doa_insert_enbl==0 and sfu_cfg.bf.DOAIEN==0\n");
    /* Configure the 2-bit direct insertion control field for all the Tx OH byte to 
       a value of 0 */
    for (i=0; i<64; i++) {
      if (mgt_ovhd_stream == 0) {
        if (ten_n40g_otnt4x_doaie(module_id, i, 0) != CS_OK) {
          return (CS_ERROR);
        }
      }
      else {
        if (ten_n10g_otnt_doaie(module_id, slice, i, 0) != CS_OK) {
          return (CS_ERROR);
        }
      } 
    }

    /* Microprocessor writes DOAIEN to a value of 0 to disable the Direct Overhead Inserter */
    ten_ohpp_sfu_set_doaien(module_id, 0);
  }

  return (CS_OK);
}



