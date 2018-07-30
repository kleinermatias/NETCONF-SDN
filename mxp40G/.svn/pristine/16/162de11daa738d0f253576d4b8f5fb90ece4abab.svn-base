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
 * ten_hl_config_otu2.c
 *
 * API's for high level OC192 client configuration.
 *
 * $Id: ten_hl_config_oc192.c,v 1.22 2013/11/26 20:08:19 jccarlis Exp $
 *
 */
 
#include "tenabo40.h"

/****************************************************************/
/* $rtn_hdr_start  HIGH LEVEL CONFIG ASYNC OC192 ODTU23         */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : HIGH LEVEL CONFIG                               */
/* CHIP       : Tenabo                                          */
cs_status ten_hl_config_oc192_async_odtu23(cs_uint16 module_id_line,
                                           cs_uint8  slice_line,
                                           cs_uint16 module_id_client,
                                           cs_uint8  slice_client,
                                           cs_uint16 dyn_repro,
                                           cs_uint16 line,
                                           cs_uint16 term)
/* INPUTS     : o Line Module Id                                */
/*              o Line Slice                                    */
/*            : o Client Module Id                              */
/*              o Client Slice                                  */
/*              o Dynamic Reprovision Type                      */
/*              o Line                                          */
/*              o Term                                          */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* Assigns ODTU on the line side and OC192 on the client side   */
/* OC192 is mapped asynchronously to ODU2 which is then mapped  */
/* wit deterministic justifications to OTU3                     */
/* OC192 -> ODU2 -> ODTU23 -> OTU3/3+/3e                        */
/* OC192 will be scrambled within the ODU2                      */
/*                                                              */
/* [module_id_line] specifies line's module ID                  */ 
/*                                                              */
/* [slice_line] specifies line's slice:                         */
/*   0x00 = TEN_SLICE0                                          */
/*   0x01 = TEN_SLICE1                                          */
/*   0x02 = TEN_SLICE2                                          */
/*   0x03 = TEN_SLICE3                                          */
/*                                                              */
/* [module_id_client] specifies the client's module ID          */
/*                                                              */
/* [slice_client] specifies client's slice:                     */
/*   0x00 = TEN_SLICE0                                          */
/*   0x01 = TEN_SLICE1                                          */
/*   0x02 = TEN_SLICE2                                          */
/*   0x03 = TEN_SLICE3                                          */
/*                                                              */
/* [dyn_repro] specifies the type of dynamic reprovisioning:    */
/*   0x00 = TEN_INITIAL_CONFIG                                  */
/*   0x01 = TEN_REPRO_CLIENT                                    */
/*   0x02 = TEN_REPRO_LINE_AND_CLIENT                           */
/*                                                              */
/* [line] specifies the traffic type of the line:               */
/*   TEN_TRAFFIC_TYPE_OTU3  = 1,                                */
/*   TEN_TRAFFIC_TYPE_OTU3E = 2,                                */
/*   TEN_TRAFFIC_TYPE_OTU3P = 3,                                */
/*   TEN_TRAFFIC_TYPE_OTU3_NOFEC = 19.                          */
/*                                                              */
/* [term] defines the way the OC192 will be sinked and sourced  */
/*   TEN_OC192_TERM_TRANSPARENT_CBR10       = 1,                */
/*   TEN_OC192_TERM_TRANSPARENT_REGENERATOR = 2,                */
/*   TEN_OC192_TERM_RS_LAYER_REGENERATOR    = 3,                */
/*   TEN_OC192_TERM_MS_LAYER_REGENERATOR    = 4.                */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  cs_uint16 dev_id = TEN_MOD_ID_TO_DEV_ID(module_id_line);
  cs_status rtn = CS_OK;
  ten_dev_cb_t *pdevcb;
  cs_uint32 hysteresis;
  T41_t *pDev = NULL;

  CS_PRINT("ten_hl_config_oc192_async_odtu23: 0x%X, %d, 0x%X, %d, dyn=%d, %d, %d\n",
            module_id_line, slice_line, module_id_client, slice_client, 
            dyn_repro, line, term);
            
  pdevcb = TEN_DEV_ID_TO_DEVCB_PTR(dev_id);

  TEN_MOD_COMMON_VALIDATE(module_id_line, pDev, CS_ERROR);
  TEN_MOD_COMMON_VALIDATE(module_id_client, pDev, CS_ERROR);

  rtn |= ten_hl_config_oc192_odtu23(module_id_line,
                             slice_line,
                             module_id_client,
                             slice_client,
                             dyn_repro,
                             line,
                             term);

  /* Bugzilla # , Fix regression failures */
  rtn |= ten_n10g_set_otnt_wrpcfg4(module_id_line, slice_line, 0, 0, 1, 0, 1);
  rtn |= ten_n10g_otnr_set_dwmod(module_id_line, slice_line, 3);
  
  rtn |= ten_n40g_otnr4x_set_jc_enable_per_slice(module_id_line, slice_line, 1);
  rtn |= ten_n40g_otnr4x_set_jc_plus_per_slice(module_id_line, slice_line, 0);       /* Bugzilla 21279 */

  rtn |= ten_n40g_otnt4x_set_wrpcfg4_jcen_per_slice(module_id_line, slice_line, 0);  /* Bugzilla 21279 */
  rtn |= ten_n40g_otnt4x_set_jc_plus(module_id_line, 0);

  /* Bug 23864 Start */
  if (pdevcb) {
    hysteresis = pdevcb->syncdsync_cb.hysteresis;
    /* Hysteresis value for DT Just */
    if      ( slice_line == 0 ) {
      rtn |= ten_n40g_otnt4x_set_wrp3dh1(module_id_line, (cs_uint16) (hysteresis >> 16));
      rtn |= ten_n40g_otnt4x_set_wrp3dh0(module_id_line, (cs_uint16) (hysteresis & 0xFFFF));
    }
    else if ( slice_line == 1 ) {
      rtn |= ten_n40g_otnt4x_set_wrp2dh1(module_id_line, (cs_uint16) (hysteresis >> 16));
      rtn |= ten_n40g_otnt4x_set_wrp2dh0(module_id_line, (cs_uint16) (hysteresis & 0xFFFF));
    }
    else if ( slice_line == 2 ) {
      rtn |= ten_n40g_otnt4x_set_wrp1dh1(module_id_line, (cs_uint16) (hysteresis >> 16));
      rtn |= ten_n40g_otnt4x_set_wrp1dh0(module_id_line, (cs_uint16) (hysteresis & 0xFFFF));
    }
    else if ( slice_line == 3 ) {
      rtn |= ten_n40g_otnt4x_set_wrp0dh1(module_id_line, (cs_uint16) (hysteresis >> 16));
      rtn |= ten_n40g_otnt4x_set_wrp0dh0(module_id_line, (cs_uint16) (hysteresis & 0xFFFF));
    }
  }
  else {
    rtn = CS_ERROR;
  }
  /* Bug 23864 End  */

  return (rtn);
}


/****************************************************************/
/* $rtn_hdr_start  HIGH LEVEL CONFIG OC192 ODTU23               */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : HIGH LEVEL CONFIG                               */
/* CHIP       : Tenabo                                          */
cs_status ten_hl_config_oc192_odtu23(cs_uint16   module_id_line,
                                       cs_uint8  slice_line,
                                       cs_uint16 module_id_client,
                                       cs_uint8  slice_client,
                                       cs_uint16 dyn_repro,
                                       cs_uint16 line,
                                       cs_uint16 term)
/* INPUTS     : o Line Module Id                                */
/*              o Line Slice                                    */
/*            : o Client Module Id                              */
/*              o Client Slice                                  */
/*              o Dynamic Reprovision Type                      */
/*              o Line                                          */
/*              o Term                                          */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* Assigns ODTU on the line side and OC192 on the client side   */
/* OC192 -> ODU2 -> ODTU23 -> OTU3/3+/3e                        */
/* OC192 will be scrambled within the ODU2                      */
/*                                                              */
/* [module_id_line] specifies line's module ID                  */ 
/*                                                              */
/* [slice_line] specifies line's slice:                         */
/*   0x00 = TEN_SLICE0                                          */
/*   0x01 = TEN_SLICE1                                          */
/*   0x02 = TEN_SLICE2                                          */
/*   0x03 = TEN_SLICE3                                          */
/*                                                              */
/* [module_id_client] specifies the client's module ID          */
/*                                                              */
/* [slice_client] specifies client's slice:                     */
/*   0x00 = TEN_SLICE0                                          */
/*   0x01 = TEN_SLICE1                                          */
/*   0x02 = TEN_SLICE2                                          */
/*   0x03 = TEN_SLICE3                                          */
/*                                                              */
/* [dyn_repro] specifies the type of dynamic reprovisioning:    */
/*   0x00 = TEN_INITIAL_CONFIG                                  */
/*   0x01 = TEN_REPRO_CLIENT                                    */
/*   0x02 = TEN_REPRO_LINE_AND_CLIENT                           */
/*                                                              */
/* [line] specifies the traffic type of the line:               */
/*   TEN_TRAFFIC_TYPE_OTU3  = 1,                                */
/*   TEN_TRAFFIC_TYPE_OTU3E = 2,                                */
/*   TEN_TRAFFIC_TYPE_OTU3P = 3,                                */
/*   TEN_TRAFFIC_TYPE_OTU3_NOFEC = 19.                          */
/*                                                              */
/* [term] defines the way the OC192 will be sinked and sourced  */
/*   TEN_OC192_TERM_TRANSPARENT_CBR10       = 1,                */
/*   TEN_OC192_TERM_TRANSPARENT_REGENERATOR = 2,                */
/*   TEN_OC192_TERM_RS_LAYER_REGENERATOR    = 3,                */
/*   TEN_OC192_TERM_MS_LAYER_REGENERATOR    = 4.                */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  cs_uint16 dev_id = TEN_MOD_ID_TO_DEV_ID(module_id_line);
  cs_status rtn = CS_OK;
  T41_t *pDev = NULL;

  CS_PRINT("ten_hl_config_oc192_odtu23: 0x%X, %d, 0x%X, %d, dyn=%d, %d, %d\n",
            module_id_line, slice_line, module_id_client, slice_client, 
            dyn_repro, line, term);
            
  TEN_MOD_COMMON_VALIDATE(module_id_line, pDev, CS_ERROR);
  TEN_MOD_COMMON_VALIDATE(module_id_client, pDev, CS_ERROR);
  
    ten_hl_n10g_config(module_id_line, slice_line, TEN_N10G_RX_OXU3_OC192, TEN_N10G_TX_OC192_OXU3, dyn_repro);
    
    ten_hl_n10g_config(module_id_client, slice_client, TEN_N10G_RX_OC192_OC192, TEN_N10G_TX_OC192_OC192PT, 0);
    
    /* Bugzilla #20657, regression fixes */
    /* Line side OTU scrambling done in N40G block */
    ten_n10g_otnt_scrambling (module_id_line, slice_line, 0, 0); 
    ten_n10g_otnr_descrambling (module_id_line, slice_line, 0, 0); 
    
    /* Clear the ODU2 OCI that the null config set up */
    /* Bug #39241 - Signal conditioning should not be done by T41 datapath configuration APIs */
    #if (TEN_HL_OHPP_DISABLE_ODUK_OCI == 1) 
    rtn |= ten_hl_ohpp_control_oduk_oci (module_id_line, slice_line, CS_DISABLE);
    #endif
    
    /* Override HL provisioning */
    /* if ($term eq 'trans') { */
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

        /* TX Line (mapping) */
        /* SBY = 1 (bypass SONET/SDH processing) */
        /* GBLT.CFGTX0_SBY (0=bypass disabled) needs to change */
        ten_n10g_set_gblt_bypasses(module_id_line, slice_line,
                        0,  /* otnoff */
                        0,  /* oby */
                        1,  /* sby */
                        1); /* kpgby */
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
    }
    /* elsif ($term eq 'transregen') { */
    else if (term == TEN_OC192_TERM_TRANSPARENT_REGENERATOR) {
        /* RX Client Side: */
        /* XSEL = 1, SBYFRM = 0  (Framed SONET/SDH through the XCON) */
        /* SDFR_SDFCFG.SCREN = 1 */
        /* LOS , LOF, and STM-AIS reported to OHPP */
        /* SDH Processor and PP10G may optionally be  */
        /* used for non-intrusive monitoring */
        /* Table is OK */

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
    /* elsif ($term eq 'rsregen') { */
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
    /* elsif ($term eq 'msregen') { */
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
      CS_HNDL_ERROR (module_id_line, ETEN_MOD_INVALID_USER_ARG, ": term invalid.");
      return(CS_ERROR);
    }
    
    /* if ($line eq 'otu3') { */
    if (line == TEN_TRAFFIC_TYPE_OTU3) {
        /* config_syncdsync(module_id_line, slice_line, TEN_SYNCDESYNC_DEMAP_OC192_OTU3, TEN_SYNCDESYNC_MAP_OC192_OTU3, ((module_id_client & 1) * 4) + slice_client); */
    }
    /* elsif ($line eq 'otu3nofec') { */
    else if (line == TEN_TRAFFIC_TYPE_OTU3_NOFEC) {
        /* config_syncdsync(module_id_line, slice_line, TEN_SYNCDESYNC_DEMAP_OC192_ODU3, TEN_SYNCDESYNC_MAP_OC192_ODU3, ((module_id_client & 1) * 4) + slice_client); */
    }
    else if (line == TEN_TRAFFIC_TYPE_OTU3P) {
        /*config_syncdsync(module_id_line, slice_line, TEN_SYNCDESYNC_DEMAP_OC192_OTU3P, TEN_SYNCDESYNC_MAP_OC192_OTU3P, ((module_id_client & 1) * 4) + slice_client); */
        ten_hl_n40g_cfg_async_odtu23(module_id_line, slice_line, CS_TX_AND_RX, 2121, 0);
    }
    /* Bugzilla 20308 Start */
    else if (line == TEN_TRAFFIC_TYPE_OTU3P2) {
        /* Bugzilla 24628 Start */ 
        ten_hl_n40g_cfg_async_odtu23(module_id_line, slice_line, CS_TX_AND_RX, 3083, 0);
        /* Bugzilla 24628 End */ 
    }
    /* Bugzilla 20308 End */
    else if (line == TEN_TRAFFIC_TYPE_OTU3E) {
        ten_hl_n40g_cfg_async_odtu23(module_id_line, slice_line, CS_TX_AND_RX, 2122, 0);
    }
  /* Bugzilla 25290 OTU3e2 Not Supported Start */
#if 0  
  else if (line == TEN_TRAFFIC_TYPE_OTU3E2) {
    /* Bugzilla 24628 Start */ 
    ten_hl_n40g_cfg_async_odtu23(module_id_line, slice_line, CS_TX_AND_RX, 1875, 0);
    /* Bugzilla 24628 End */ 
  }
#endif  
  /* Bugzilla 25290 OTU3e2 Not Supported End */


     /* Bugzilla # , Fix regression failures */
    ten_n40g_otnr4x_set_jc_enable_per_slice(module_id_line, slice_line, 1);    /* Bugzilla 21279 */
    ten_n40g_otnr4x_set_jc_plus_per_slice(module_id_line, slice_line, 0);      /* Bugzilla 21279 */
    
    ten_n40g_otnt4x_set_wrpcfg4_jcen_per_slice(module_id_line, slice_line, 0);  /* Bugzilla 21279 */
    ten_n40g_otnt4x_set_jc_plus(module_id_line, 0);                              /* Bugzilla 21279 */
    
    /* CLOCK old method */
    /* config_syncdsync(module_id_client, slice_client, TEN_SYNCDESYNC_DEMAP_1_TO_1, TEN_SYNCDESYNC_MAP_1_TO_1, ((module_id_line & 1) * 4) + slice_line); */

    /* CLOCK new method */
    /* This didn't work because the base rate of OTU3e is different from OC192 */
    /* config_syncdsync_div(module_id_client, slice_client, ((module_id_line & 1) * 4) + slice_line, 'oc192', 'otu2'); */

    /* config_pti_10g(module_id_line, slice_line, 'oc192', 0); */
    ten_hl_n10g_config_pti(module_id_line, slice_line, TEN_TRAFFIC_TYPE_OC192, 0);
    
    /* config_xcon($dev_id, (module_id_line & 1) * 4 + slice_line, (module_id_client & 1) * 4 + slice_client, 'oc192'); */
    ten_hl_xcon_config(dev_id, (module_id_line & 1) * 4 + slice_line, (module_id_client & 1) * 4 + slice_client, TEN_TRAFFIC_TYPE_OC192); 

    return (rtn);
}

/****************************************************************/
/* $rtn_hdr_start  HIGH LEVEL CONFIG OC192 OTU2                 */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : HIGH LEVEL CONFIG                               */
/* CHIP       : Tenabo                                          */
cs_status ten_hl_config_oc192_otu2(cs_uint16 module_id_line,
                                   cs_uint8  slice_line,
                                   cs_uint16 module_id_client,
                                   cs_uint8  slice_client,
                                   cs_uint16 dyn_repro,
                                   cs_uint16 line,
                                   cs_uint16 term,
                                   cs_uint16 fec,
                                   cs_uint16 sync,
                                   cs_uint16 k)
/* INPUTS     : o Line Module Id                                */
/*              o Line Slice                                    */
/*            : o Client Module Id                              */
/*              o Client Slice                                  */
/*              o Dynamic Reprovision Type                      */
/*              o Line                                          */
/*              o Term                                          */
/*              o FEC                                           */
/*              o Sync                                          */
/*              o K                                             */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* Configures OC192 on the client side into OTU2 on line side.  */
/*                                                              */
/* [module_id_line] specifies line's module ID                  */ 
/*                                                              */
/* [slice_line] specifies line's slice:                         */
/*   0x00 = TEN_SLICE0                                          */
/*   0x01 = TEN_SLICE1                                          */
/*   0x02 = TEN_SLICE2                                          */
/*   0x03 = TEN_SLICE3                                          */
/*                                                              */
/* [module_id_client] specifies the client's module ID          */
/*                                                              */
/* [slice_client] specifies client's slice:                     */
/*   0x00 = TEN_SLICE0                                          */
/*   0x01 = TEN_SLICE1                                          */
/*   0x02 = TEN_SLICE2                                          */
/*   0x03 = TEN_SLICE3                                          */
/*                                                              */
/* [dyn_repro] specifies the type of dynamic reprovisioning:    */
/*   0x00 = TEN_INITIAL_CONFIG                                  */
/*   0x01 = TEN_REPRO_CLIENT                                    */
/*   0x02 = TEN_REPRO_LINE_AND_CLIENT                           */
/*                                                              */
/* [line] specifies the traffic type of the line:               */
/*   TEN_TRAFFIC_TYPE_OTU3  = 1,                                */
/*   TEN_TRAFFIC_TYPE_OTU3E = 2,                                */
/*   TEN_TRAFFIC_TYPE_OTU3P = 3,                                */
/*   TEN_TRAFFIC_TYPE_OTU3_NOFEC = 19.                          */
/*                                                              */
/* [term] defines the way the OC192 will be sinked and sourced  */
/*   TEN_OC192_TERM_TRANSPARENT_CBR10       = 1,                */
/*   TEN_OC192_TERM_TRANSPARENT_REGENERATOR = 2,                */
/*   TEN_OC192_TERM_RS_LAYER_REGENERATOR    = 3,                */
/*   TEN_OC192_TERM_MS_LAYER_REGENERATOR    = 4.                */
/*                                                              */
/* [fec] defines fec type:                                      */
/*   TEN_FEC_TYPE_NOFEC = 0,                                    */
/*   TEN_FEC_TYPE_ZEROFEC = 1,                                  */
/*   TEN_FEC_TYPE_GFEC = 2,                                     */
/*   TEN_FEC_TYPE_UFEC = 3                                      */
/*                                                              */
/* The [sync] parameter specifies the clock sync method         */
/*   0 = TEN_MAP_AMP                                            */
/*   1 = TEN_MAP_BMP                                            */
/*                                                              */
/* [k] defines K value.                                         */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  cs_uint16 dev_id = TEN_MOD_ID_TO_DEV_ID(module_id_line);
  cs_status rtn = CS_OK;
  T41_t *pDev = NULL;
    
  CS_PRINT("ten_hl_config_oc192_otu2: 0x%X, %d, 0x%X, %d", 
           "dyn=%d, line=%d, term=%d, sync=%d, fec=%d, k=%d\n",
            module_id_line, slice_line, module_id_client, slice_client, 
            dyn_repro, line, term, fec, sync, k);
            
  TEN_MOD_COMMON_VALIDATE(module_id_line, pDev, CS_ERROR);
  TEN_MOD_COMMON_VALIDATE(module_id_client, pDev, CS_ERROR);

  /* Bugzilla 25070 Start */
  if (fec == TEN_FEC_MODE_NOFEC) {
      ten_hl_n10g_config(module_id_line, slice_line, TEN_N10G_RX_ODU2_OC192, TEN_N10G_TX_OC192_ODU2, dyn_repro);
      ten_hl_n10g_config(module_id_client, slice_client, TEN_N10G_RX_OC192_OC192, TEN_N10G_TX_OC192_OC192PT, 0);
      
      /* Bug #39241 - Signal conditioning should not be done by T41 datapath configuration APIs */
      #if (TEN_HL_OHPP_DISABLE_ODUK_OCI == 1) 
      rtn |= ten_hl_ohpp_control_oduk_oci (module_id_line, slice_line, CS_DISABLE);
      #endif

      /* ten_n10g_otnt_scrambling(module_id_line, slice_line, 1, 0); */
      /* ten_n10g_otnr_descrambling(module_id_line, slice_line, 0, 1); */
      /* ten_n10g_otnr_set_dwmod(module_id_line, slice_line, 3); */
      /* ten_n10g_set_sby(module_id_line, slice_line, 0); */

      if(sync == TEN_MAP_BMP) {
          ten_n10g_set_otnt_wrpcfg4(module_id_line, slice_line, 0, 0, 0, 0, 0);  /* jc_plus_odtu23, jc_plus_otu2, jcen_dt, jcen_odtu23 and jcen_otu2 */
          ten_n10g_otnr_set_dwmod(module_id_line, slice_line, 1);                /* Dewrapper enabled Justification commands are ignored */
      }
      else {
          ten_n10g_set_otnt_wrpcfg4(module_id_line, slice_line, 0, 0, 0, 0, 1);  /* jc_plus_odtu23, jc_plus_otu2, jcen_dt, jcen_odtu23 and jcen_otu2 */
          ten_n10g_otnr_set_dwmod(module_id_line, slice_line, 3);                /* Dewrapper enabled Justification commands are evaluated */
      }
  }
  /* Bugzilla 25070 End */
  else {
      ten_hl_n10g_config(module_id_line, slice_line, TEN_N10G_RX_OTU2_OC192, TEN_N10G_TX_OC192_OTU2, dyn_repro);
      ten_hl_n10g_config(module_id_client, slice_client, TEN_N10G_RX_OC192_OC192, TEN_N10G_TX_OC192_OC192PT, 0);
      ten_n10g_otnt_bipmsk(module_id_line, slice_line, 0xFF);
  
      ten_n10g_otnt_scrambling(module_id_line, slice_line, 0, 1);
      ten_n10g_otnr_descrambling(module_id_line, slice_line, 1, 0);
    
      /* Clear the ODU2 OCI that the null config set up */
      /* Bug #39241 - Signal conditioning should not be done by T41 datapath configuration APIs */
      #if (TEN_HL_OHPP_DISABLE_ODUK_OCI == 1) 
      rtn |= ten_hl_ohpp_control_oduk_oci (module_id_line, slice_line, CS_DISABLE);
      #endif
  }
    
  /* if ($term eq 'trans') { */
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
      /* TX Line (mapping) */
      /* SBY = 1 (bypass SONET/SDH processing) */
      /* GBLT.CFGTX0_SBY (0=bypass disabled) needs to change */
      ten_n10g_set_gblt_bypasses(module_id_line, slice_line,
                      0,  /* otnoff */
                      0,  /* oby */
                      1,  /* sby */
                      1); /* kpgby */
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
      /* SDH processor may optionally be used for non-intrusive monitoring, otherwise set SDHE = 0 to save power */
      /* SDHE not set by the table */

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
  }
  /* elsif ($term eq 'transregen') { */
  else if (term == TEN_OC192_TERM_TRANSPARENT_REGENERATOR) {
      /* RX Client Side: */
      /* XSEL = 1, SBYFRM = 0  (Framed SONET/SDH through the XCON) */
      /* SDFR_SDFCFG.SCREN = 1 */
      /* LOS , LOF, and STM-AIS reported to OHPP */
      /* SDH Processor and PP10G may optionally be used for non-intrusive monitoring */
      /* Table is OK */

      /* TX Line Side (Mapping): */
      /* SBY = 0 (Do not bypass SONET/SDH processing) */
      /* SOHT_OHBEN0 = 0x08 (A1A2RSH), SOHT_OHBEN1 = 0x00, SOHT_OHBEN2 = 0x00 (disable all SONET/SDH insertion but turn on scrambling) */
      /* SFU inserts MS-AIS (AIS-L) as consequent action if LOS/LOF/STM-AIS detected on client RX (this must include setting SOHT_OHBEN0.B1IE=1) */
      ten_n10g_set_gblt_bypasses(module_id_line, slice_line,
                      0,  /* otnoff */
                      0,  /* oby */
                      0,  /* sby */
                      1); /* kpgby */
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
      /* SDH Processor and PP10G may optionally be used for non-intrusive monitoring */
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
  /* elsif ($term eq 'rsregen') { */
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
      /* TX Line Side (Mapping): */
      /* SBY = 0 (Do not bypass SONET/SDH processing) */
      /* In SOHT, set SCREN=1, A1A2RSH=1, B1IE =1 */
      /* In SOHT, enable RSOH bytes that are to be sourced (others will be transparently passed through) */
      /* If B1 error transparency is desired, set B1TRANS=1 in SOHT_OHBEN1 */
      /* SFU inserts MS-AIS (AIS-L) as consequent action if LOS/LOF/STM-AIS/MS-AIS or optionally RS-TIM  detected on client RX */
      /* B1IE needs to change */
      ten_n10g_set_gblt_bypasses(module_id_line, slice_line,
                      0,  /* otnoff */
                      0,  /* oby */
                      0,  /* sby */
                      1); /* kpgby */
                      
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
      /* SDH Processor and PP10G may optionally be used for non-intrusive monitoring */
      /* B1 TRANS needs to change */
      ten_n10g_sohr_set_byte_err_trans_mode(module_id_line, slice_line,
                      1,  /* b1trans */
                      0); /* b2trans */
      /* TX Client Side: */
      /* SBY = 0 (Do not bypass SDH Processor) */
      /* In SOHT, set SCREN=1, A1A2RSH=1, B1IE =1 */
      /* In SOHT, enable RSOH bytes that are to be sourced (others will be transparently passed through) */
      /* If B1 error transparency is desired, set B1TRANS=1 in SOHT_OHBEN1 */
      /* SFU inserts MS-AIS (AIS-L) as consequent action if LOF/STM-AIS/MS-AIS or optionally RS-TIM  or OTN defect detected on line RX */
      /* Table is OK */
  }
  /*  elsif ($term eq 'msregen') { */
  else if (term == TEN_OC192_TERM_MS_LAYER_REGENERATOR) {
      /* RX Client Side: */
      /* XSEL = 1, SBYFRM = 0  (Framed SONET/SDH through the XCON) */
      /* SDFR_SDFCFG.SCREN = 1 */
      /* LOS , LOF, STM-AIS, RS-TIM, AIS-L, dEXC, dLOP, AU-AIS defects reported to OHPP */
      /* Set SOHR_S1CFG.B1TRANS=1 */
      /* Set SOHR_S1CFG.B2TRANS=1 */
      /* SDH Processor and PP10G may optionally be used for non-intrusive monitoring */
      /* B1TRANS and B2TRANS need to change */
      ten_n10g_sohr_set_byte_err_trans_mode(module_id_client, slice_client,
                      1,  /* b1trans */
                      1); /* b2trans */
      /* TX Line Side (Mapping): */
      /* SBY = 0 (Do not bypass SONET/SDH processing) */
      /* In SOHT, set SCREN=1, A1A2RSH=1, B1IE =1, B2IE=1 */
      /* In SOHT, enable RSOH/MSOH bytes that are to be sourced (others will be transparently passed through) */
      /* If B1 error transparency is desired, set B1TRANS=1 in SOHT_OHBEN1 */
      /* If B2 error transparency is desired, set B2TRANS=1 in SOHT_OHBEN1 */
      /* SFU inserts MS-RDI (RDI-L) as consequent action if LOF/MS-AIS detected on line RX */
      /* SFU inserts MS-REI (REI-L) based on number of B2 errors detected on line RX */
      /* SFU inserts MS-AIS (AIS-L) as consequent action if LOS/LOF/STM-AIS/MS-AIS or optionally RS-TIM/dEXC  detected on client RX */
      /* Optionally insert AU-AIS as consequent action if dLOP/AU-AIS detected on client RX */
      /* B1IE and B2IE need to change */
      ten_n10g_set_gblt_bypasses(module_id_line, slice_line,
                      0,  /* otnoff */
                      0,  /* oby */
                      0,  /* sby */
                      1); /* kpgby */
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
      /* TX Client Side: */
      /* SBY = 0 (Do not bypass SDH Processor) */
      /* In SOHT, set SCREN=1, A1A2RSH=1, B1IE =1, B2IE=1 */
      /* In SOHT, enable RSOH/MSOH bytes that are to be sourced (others will be transparently passed through) */
      /* If B1 error transparency is desired, set B1TRANS=1 in SOHT_OHBEN1 */
      /* If B2 error transparency is desired, set B2TRANS=1 in SOHT_OHBEN1 */
      /* SFU inserts MS-RDI (RDI-L) as consequent action if LOS/LOF/MS-AIS detected on client RX */
      /* SFU inserts MS-REI (REI-L) based on number of B2 errors detected on client RX */
      /* SFU inserts MS-AIS (AIS-L) as consequent action if LOF/STM-AIS/MS-AIS or optionally RS-TIM/dEXC  or OTN defect detected on line RX */
      /* Optionally insert AU-AIS as consequent action if dLOP/AU-AIS detected on line RX */
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
    CS_HNDL_ERROR (module_id_line, ETEN_MOD_INVALID_USER_ARG, ": term invalid.");
    return(CS_ERROR);
  }
    
  /* Bugzilla 25070 Start */
    /* Per Prashant's email of 3/26/10 */
    /* Commented-out lines can use the default from the table */
  /*  if (sync) { */
    if (sync == TEN_MAP_BMP) {
        ten_n10g_set_otnt_wrpcfg4(module_id_line, slice_line,
                                    0,  /* jc_plus_odtu23, */
                                    0,  /* jc_plus_otu2, */
                                    0,  /* jcen_dt, */
                                    0,  /* jcen_odtu23, */
                                    0); /* jcen_otu2 - Was 1 */
  /*         ten_n10g_otnt_set_wrmd(module_id_line, slice_line, 1); */
  /*         ten_n10g_otnr_set_jc_plus(module_id_line, slice_line,, 0); */
  /*         ten_n10g_otnr_set_fsomd(module_id_line, slice_line, 1); */
        ten_n10g_otnr_set_dwmod(module_id_line, slice_line, 1); /* Was 3 */     /* Dewrapper enabled Justification commands are ignored */
    }
    else {
           ten_n10g_set_otnt_wrpcfg4(module_id_line, slice_line,
                                       0,  /* jc_plus_odtu23, */
                                       0,  /* jc_plus_otu2, */
                                       0,  /* jcen_dt, */
                                       0,  /* jcen_odtu23, */
                                       1); /* jcen_otu2 */
           ten_n10g_otnt_set_wrmd(module_id_line, slice_line, 1);                /* Wrapper on */
          ten_n10g_otnr_set_dwmod(module_id_line, slice_line, 3);                /* Dewrapper enabled Justification commands are evaluated */
    }
  /* Bugzilla 25070 End */

    /* config_pti_10g(module_id_line, slice_line, 'oc192', $sync); */
    ten_hl_n10g_config_pti(module_id_line, slice_line, TEN_TRAFFIC_TYPE_OC192, sync);

    /* config_xcon($dev_id, (module_id_line & 1) * 4 + slice_line, (module_id_client & 1) * 4 + slice_client, 'oc192'); */
    ten_hl_xcon_config(dev_id, (module_id_line & 1) * 4 + slice_line, (module_id_client & 1) * 4 + slice_client, TEN_TRAFFIC_TYPE_OC192); 
    
    return (rtn);
}

/* Bugzilla 22514 Start */
/****************************************************************/
/* $rtn_hdr_start  HIGH LEVEL CONFIG OC192 Cross Connect Loopback*/
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : HIGH LEVEL CONFIG                               */
/* CHIP       : Tenabo                                          */
cs_status ten_hl_config_oc192_xcon_loopback(cs_uint16 module_id,
                                          cs_uint8  slice,
                                          cs_uint16 traffic_type,
                                          cs_uint16 dyn_repro,
                                          cs_uint16 term_sonet)
/* INPUTS     : o Module Id                                     */
/*              o Slice                                         */
/*              o Dynamic Reprovision Type                      */
/*              o Traffic Type                                  */
/*              o Term Sonet                                    */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* Configures OC192 cross connect loopback.                     */
/*                                                              */
/* [module_id] specifies module ID                              */ 
/*   0xXX00 = Module A                                          */      
/*   0xXX01 = Module B                                          */
/*                                                              */
/* [slice] specifies slice:                                     */
/*   0x00 = TEN_SLICE0                                          */
/*   0x01 = TEN_SLICE1                                          */
/*   0x02 = TEN_SLICE2                                          */
/*   0x03 = TEN_SLICE3                                          */
/*                                                              */
/* [dyn_repro] specifies the type of dynamic reprovisioning:    */
/*   0x00 = TEN_INITIAL_CONFIG                                  */
/*   0x01 = TEN_REPRO_CLIENT                                    */
/*   0x02 = TEN_REPRO_LINE_AND_CLIENT                           */
/*                                                              */
/* [traffic_type] specifies the traffic type of the line:       */
/*   0x08 = TEN_TRAFFIC_TYPE_OC192                              */
/*                                                              */
/* [term_sonet] defines the way the OC192 will be sinked and    */
/*              sourced                                         */
/*   0x01 = TEN_OC192_TERM_TRANSPARENT_CBR10                    */
/*   0x02 = TEN_OC192_TERM_TRANSPARENT_REGENERATOR              */
/*   0x03 = TEN_OC192_TERM_RS_LAYER_REGENERATOR                 */
/*   0x01 = TEN_OC192_TERM_MS_LAYER_REGENERATOR                 */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  cs_uint16 dev_id = TEN_MOD_ID_TO_DEV_ID(module_id);
  cs_status rtn = CS_OK;
  T41_t *pDev = NULL;
  /* Bugzilla 23776 Start */
  cs_char8 *func = "ten_hl_config_oc192_xcon_loopback";  /* __FUNCTION__ or __func__ not available for all compilers */
    
  TEN_MOD_COMMON_VALIDATE (module_id, pDev, CS_ERROR);
    
  if ((slice >= TEN_MAX_SLICES) && (slice != TEN_SLICE_ALL)) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, "%s() slice %d out of range.  s/b 0..3, 255.", func, slice);
    return (CS_ERROR);
  }
    
  if (traffic_type != TEN_TRAFFIC_TYPE_OC192) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, "%s() traffic_type %d out of range.  s/b 8.", func, traffic_type);
    return (CS_ERROR);
  }    
    
  if (dyn_repro > TEN_REPRO_LINE_AND_CLIENT) { 
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, "%s() dyn_repro %d out of range.  s/b 0..2.", func, dyn_repro);
    return (CS_ERROR);
  }
    
  /*if ((term_sonet < TEN_OC192_TERM_TRANSPARENT_REGENERATOR) || (term_sonet > TEN_OC192_TERM_MS_LAYER_REGENERATOR)) {*/
  if ((term_sonet < TEN_OC192_TERM_TRANSPARENT_CBR10) || (term_sonet > TEN_OC192_TERM_MS_LAYER_REGENERATOR)) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, "%s() term_sonet %d out of range.  s/b 1..4.", func, term_sonet);
    return (CS_ERROR);
  }
 
  CS_PRINT("%s() %s, Slice %d, %s, %s, %s\n",
           func,
           ten_module_strings[module_id & 1],
           slice,
           ten_hl_config_traffic_types_strings[traffic_type],
           ten_hl_config_dyn_repro_strings[dyn_repro],
           ten_hl_config_oc192_overhead_term_strings[term_sonet]);
  /* Bugzilla 23776 End */
            
  
  rtn |= ten_hl_n10g_config (module_id, slice, TEN_N10G_RX_OC192_OC192, TEN_N10G_TX_OC192_OC192PT, 0);
  
  rtn |= ten_hl_oc192_termination (module_id, slice, term_sonet);
  
  rtn |= ten_hl_xcon_config(dev_id, (module_id & 1) * 4 + slice, (module_id & 1) * 4 + slice, TEN_TRAFFIC_TYPE_OC192); 
  
  return (rtn);
}

/****************************************************************/
/* $rtn_hdr_start  OC192 TERMINATION FOR OTU2                   */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : HIGH LEVEL                                      */
/* CHIP       : Tenabo                                          */
cs_status ten_hl_oc192_termination_for_otu2(cs_uint16 module_id,
                                            cs_uint8  slice,
                                            cs_uint16 term_sonet)
/* INPUTS     : o Module Id                                     */
/*              o Term Overhead Termination Type                */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* Configure OC768 header termination mode for otu2.            */
/*                                                              */
/* [module_id] specifies module ID                              */ 
/*   0xXX00 = Module A                                          */      
/*   0xXX01 = Module B                                          */
/*                                                              */
/* [slice] specifies slice:                                     */
/*   0x00 = TEN_SLICE0                                          */
/*   0x01 = TEN_SLICE1                                          */
/*   0x02 = TEN_SLICE2                                          */
/*   0x03 = TEN_SLICE3                                          */
/*                                                              */
/* [term_sonet] defines the way the OC768 will be sinked and    */
/* sourced                                                      */
/*   TEN_OC192_TERM_TRANSPARENT_CBR10       = 1,                */
/*   TEN_OC192_TERM_TRANSPARENT_REGENERATOR = 2,                */
/*   TEN_OC192_TERM_RS_LAYER_REGENERATOR    = 3,                */
/*   TEN_OC192_TERM_MS_LAYER_REGENERATOR    = 4.                */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  /* cs_uint16 dev_id = TEN_MOD_ID_TO_DEV_ID(module_id); */
  cs_status rtn = CS_OK;
  /*T41_t *pDev;*/
 
  if (term_sonet == TEN_OC192_TERM_TRANSPARENT_CBR10) {
    /* TX Line (mapping) */
    /* SBY = 1 (bypass SONET/SDH processing) */
    /* GBLT.CFGTX0_SBY (0=bypass disabled) needs to change */
    ten_n10g_set_gblt_bypasses(module_id, slice,
                    0,  /* otnoff */
                    0,  /* oby */
                    1,  /* sby */
                    1); /* kpgby */
    /* SFU inserts CBRGENAIS as consequent action if LOS detected on client RX */
    /* Optionally do this */

    /* RX Line (demapping) */
    /* XSEL = 2, SBYPLD = 1 (bypass SONET/SDH processing) */
    /* DPCFG_XSEL needs to change */
    ten_n10g_set_gblr_dpcfg(module_id, slice,
                    2,  /* xsel */
                    0,  /* kpasel */
                    1,  /* sbypld */
                    0,  /* sbyfrm */
                    0,  /* oby */
                    0,  /* sdhoff */
                    0); /* otnoff */
    /* OTN layer defects reported to OHPP */
    /* SDH processor may optionally be used for non-intrusive monitoring, otherwise set SDHE = 0 to save power */
    /* SDHE not set by the table */

  }

  else if (term_sonet == TEN_OC192_TERM_TRANSPARENT_REGENERATOR) {
    /* TX Line Side (Mapping): */
    /* SBY = 0 (Do not bypass SONET/SDH processing) */
    /* SOHT_OHBEN0 = 0x08 (A1A2RSH), SOHT_OHBEN1 = 0x00, SOHT_OHBEN2 = 0x00 (disable all SONET/SDH insertion but turn on scrambling) */
    /* SFU inserts MS-AIS (AIS-L) as consequent action if LOS/LOF/STM-AIS detected on client RX (this must include setting SOHT_OHBEN0.B1IE=1) */
    ten_n10g_set_gblt_bypasses(module_id, slice,
                    0,  /* otnoff */
                    0,  /* oby */
                    0,  /* sby */
                    1); /* kpgby */
    ten_n10g_soht_set_ohben0(module_id, slice,
                    0,  /* b1ie */
                    1,  /* scren */
                    1,  /* a1a2rsh */
                    0); /* a1a2ie */
    ten_n10g_soht_b2ie(module_id, slice, TEN_INSTANCE_ALL, 0);
    /* config_b2(module_id_line, slice_line, 0); */

    /* RX Line Side (Demapping): */
    /* XSEL = 1, SBYFRM = 0   (Framed SONET/SDH to the XCON) */
    /* SDFR_SDFCFG.SCREN = 1 */
    /* LOF and STM-AIS reported to OHPP */
    /* OTN-layer defects reported to OHPP */
    /* SDH Processor and PP10G may optionally be used for non-intrusive monitoring */
    /* Table is OK */

  }

  else if (term_sonet == TEN_OC192_TERM_RS_LAYER_REGENERATOR) {
    /* TX Line Side (Mapping): */
    /* SBY = 0 (Do not bypass SONET/SDH processing) */
    /* In SOHT, set SCREN=1, A1A2RSH=1, B1IE =1 */
    /* In SOHT, enable RSOH bytes that are to be sourced (others will be transparently passed through) */
    /* If B1 error transparency is desired, set B1TRANS=1 in SOHT_OHBEN1 */
    /* SFU inserts MS-AIS (AIS-L) as consequent action if LOS/LOF/STM-AIS/MS-AIS or optionally RS-TIM  detected on client RX */
    /* B1IE needs to change */
    ten_n10g_set_gblt_bypasses(module_id, slice,
                    0,  /* otnoff */
                    0,  /* oby */
                    0,  /* sby */
                    1); /* kpgby */
                    
    ten_n10g_soht_set_ohben0(module_id, slice,
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
    /* SDH Processor and PP10G may optionally be used for non-intrusive monitoring */
    /* B1 TRANS needs to change */
    ten_n10g_sohr_set_byte_err_trans_mode(module_id, slice,
                    1,  /* b1trans */
                    0); /* b2trans */
  }

  else if (term_sonet == TEN_OC192_TERM_MS_LAYER_REGENERATOR) {
    /* TX Line Side (Mapping): */
    /* SBY = 0 (Do not bypass SONET/SDH processing) */
    /* In SOHT, set SCREN=1, A1A2RSH=1, B1IE =1, B2IE=1 */
    /* In SOHT, enable RSOH/MSOH bytes that are to be sourced (others will be transparently passed through) */
    /* If B1 error transparency is desired, set B1TRANS=1 in SOHT_OHBEN1 */
    /* If B2 error transparency is desired, set B2TRANS=1 in SOHT_OHBEN1 */
    /* SFU inserts MS-RDI (RDI-L) as consequent action if LOF/MS-AIS detected on line RX */
    /* SFU inserts MS-REI (REI-L) based on number of B2 errors detected on line RX */
    /* SFU inserts MS-AIS (AIS-L) as consequent action if LOS/LOF/STM-AIS/MS-AIS or optionally RS-TIM/dEXC  detected on client RX */
    /* Optionally insert AU-AIS as consequent action if dLOP/AU-AIS detected on client RX */
    /* B1IE and B2IE need to change */
    ten_n10g_set_gblt_bypasses(module_id, slice,
                    0,  /* otnoff */
                    0,  /* oby */
                    0,  /* sby */
                    1); /* kpgby */
    ten_n10g_soht_set_ohben0(module_id, slice,
                    1,  /* b1ie */
                    1,  /* scren */
                    1,  /* a1a2rsh */
                    0); /* a1a2ie */
    ten_n10g_soht_b2ie(module_id, slice, TEN_INSTANCE_ALL, 0xFFFF);
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
    ten_n10g_sohr_set_byte_err_trans_mode(module_id, slice,
                    1,  /* b1trans */
                    1); /* b2trans */
  }
  else {
    CS_HNDL_ERROR (module_id, ETEN_MOD_INVALID_USER_ARG, ": term_sonet invalid.");
    return(CS_ERROR);
  }

  return (rtn);
}



/****************************************************************/
/* $rtn_hdr_start  OC192 TERMINATION                            */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : HIGH LEVEL                                      */
/* CHIP       : Tenabo                                          */
cs_status ten_hl_oc192_termination(cs_uint16 module_id,
                                   cs_uint8  slice,
                                   cs_uint16 term_sonet)
/* INPUTS     : o Module Id Line                                */
/*              o Module Id Client                              */
/*              o Term Overhead Termination Type                */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* Configure OC768 header termination mode.                     */
/*                                                              */
/* [module_id] specifies module ID                              */ 
/*   0xXX00 = Module A                                          */      
/*   0xXX01 = Module B                                          */
/*                                                              */
/* [slice] specifies slice:                                     */
/*   0x00 = TEN_SLICE0                                          */
/*   0x01 = TEN_SLICE1                                          */
/*   0x02 = TEN_SLICE2                                          */
/*   0x03 = TEN_SLICE3                                          */
/*                                                              */
/* [term_sonet] defines the way the OC768 will be sinked and    */
/* sourced                                                      */
/*   TEN_OC192_TERM_TRANSPARENT_CBR10       = 1,                */
/*   TEN_OC192_TERM_TRANSPARENT_REGENERATOR = 2,                */
/*   TEN_OC192_TERM_RS_LAYER_REGENERATOR    = 3,                */
/*   TEN_OC192_TERM_MS_LAYER_REGENERATOR    = 4.                */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  /* cs_uint16 dev_id = TEN_MOD_ID_TO_DEV_ID(module_id); */
  cs_status rtn = CS_OK;
  /*T41_t *pDev;*/
 
  if (term_sonet == TEN_OC192_TERM_TRANSPARENT_CBR10) {
    /* RX Client */
    /* XSEL = 2, SBYPLD = 1 (bypass SONET/SDH processing) */
    /* DPCFG_XSEL needs to change */
    ten_n10g_set_gblr_dpcfg(module_id, slice,
                    2,  /* xsel */
                    0,  /* kpasel */
                    1,  /* sbypld */
                    0,  /* sbyfrm */
                    1,  /* oby */
                    0,  /* sdhoff */
                    1); /* otnoff */

    /* TX Client */
    /* SBY = 0 (must not bypass SONET/SDH processor for consequent action insertion) */
    /* SOHT_OHBEN0 = 0x00, SOHT_OHBEN1 = 0x00, SOHT_OHBEN2 = 0x00 (disable all SONET/SDH insertion) */
    /* SOHT.OHBEN0_SCREN (1=enable SONET scrambling) need to change */
    /* SOHT.OHBEN0_A1A2RSH (1=regenerate A1A2) need to change */
    ten_n10g_soht_set_ohben0(module_id, slice,
                    0,  /* b1ie */
                    0,  /* scren */
                    0,  /* a1a2rsh */
                    0); /* a1a2ie */
    /* SFU inserts STM-AIS as consequent action if OTN defect detected on line side */
    /* Optionally do this */
  }

  else if (term_sonet == TEN_OC192_TERM_TRANSPARENT_REGENERATOR) {
    /* RX Client Side: */
    /* XSEL = 1, SBYFRM = 0  (Framed SONET/SDH through the XCON) */
    /* SDFR_SDFCFG.SCREN = 1 */
    /* LOS , LOF, and STM-AIS reported to OHPP */
    /* SDH Processor and PP10G may optionally be used for non-intrusive monitoring */
    /* Table is OK */

    /* TX Client Side: */
    /* SBY = 0 (Do not bypass SDH Processor) */
    /* SOHT_OHBEN0 = 0x08 (A1A2RSH), SOHT_OHBEN1 = 0x00, SOHT_OHBEN2 = 0x00 (disable all SONET/SDH insertion but turn on scrambling) */
    /* SFU inserts MS-AIS (AIS-L) as consequent action if LOF/STM-AIS or OTN defect detected on line RX (this must include setting SOHT_OHBEN0.B1IE=1) */
    ten_n10g_soht_set_ohben0(module_id, slice,
                    0,  /* b1ie */
                    1,  /* scren */
                    1,  /* a1a2rsh */
                    0); /* a1a2ie */

    ten_n10g_soht_b2ie(module_id, slice, TEN_INSTANCE_ALL, 0);
    /* config_b2(module_id_client, slice_client, 0); */
  }

  else if (term_sonet == TEN_OC192_TERM_RS_LAYER_REGENERATOR) {
    /* RX Client Side: */
    /* XSEL = 1, SBYFRM = 0  (Framed SONET/SDH through the XCON) */
    /* SDFR_SDFCFG.SCREN = 1 */
    /* LOS , LOF, STM-AIS, RS-TIM, AIS-L defects reported to OHPP */
    /* Set SOHR_S1CFG.B1TRANS=1 */
    /* SDH Processor and PP10G may optionally be used for non-intrusive monitoring */
    /* SOHR_S1CFG.B1TRANS needs to change */
    ten_n10g_sohr_set_byte_err_trans_mode(module_id, slice,
                    1,  /* b1trans */
                    0); /* b2trans */

    /* TX Client Side: */
    /* SBY = 0 (Do not bypass SDH Processor) */
    /* In SOHT, set SCREN=1, A1A2RSH=1, B1IE =1 */
    /* In SOHT, enable RSOH bytes that are to be sourced (others will be transparently passed through) */
    /* If B1 error transparency is desired, set B1TRANS=1 in SOHT_OHBEN1 */
    /* SFU inserts MS-AIS (AIS-L) as consequent action if LOF/STM-AIS/MS-AIS or optionally RS-TIM  or OTN defect detected on line RX */
    /* Table is OK */
  }

  else if (term_sonet == TEN_OC192_TERM_MS_LAYER_REGENERATOR) {
    /* RX Client Side: */
    /* XSEL = 1, SBYFRM = 0  (Framed SONET/SDH through the XCON) */
    /* SDFR_SDFCFG.SCREN = 1 */
    /* LOS , LOF, STM-AIS, RS-TIM, AIS-L, dEXC, dLOP, AU-AIS defects reported to OHPP */
    /* Set SOHR_S1CFG.B1TRANS=1 */
    /* Set SOHR_S1CFG.B2TRANS=1 */
    /* SDH Processor and PP10G may optionally be used for non-intrusive monitoring */
    /* B1TRANS and B2TRANS need to change */
    ten_n10g_sohr_set_byte_err_trans_mode(module_id, slice,
                    1,  /* b1trans */
                    1); /* b2trans */

    /* TX Client Side: */
    /* SBY = 0 (Do not bypass SDH Processor) */
    /* In SOHT, set SCREN=1, A1A2RSH=1, B1IE =1, B2IE=1 */
    /* In SOHT, enable RSOH/MSOH bytes that are to be sourced (others will be transparently passed through) */
    /* If B1 error transparency is desired, set B1TRANS=1 in SOHT_OHBEN1 */
    /* If B2 error transparency is desired, set B2TRANS=1 in SOHT_OHBEN1 */
    /* SFU inserts MS-RDI (RDI-L) as consequent action if LOS/LOF/MS-AIS detected on client RX */
    /* SFU inserts MS-REI (REI-L) based on number of B2 errors detected on client RX */
    /* SFU inserts MS-AIS (AIS-L) as consequent action if LOF/STM-AIS/MS-AIS or optionally RS-TIM/dEXC  or OTN defect detected on line RX */
    /* Optionally insert AU-AIS as consequent action if dLOP/AU-AIS detected on line RX */
    /* B1IE and B2IE need to change */
    ten_n10g_soht_set_ohben0(module_id, slice,
                    1,  /* b1ie */
                    1,  /* scren */
                    1,  /* a1a2rsh */
                    0); /* a1a2ie */
    ten_n10g_soht_b2ie(module_id, slice, TEN_INSTANCE_ALL, 0xFFFF);
    /* config_b2(module_id_client, slice_client, 0xffff); */
  }
  else {
    CS_HNDL_ERROR (module_id, ETEN_MOD_INVALID_USER_ARG, ": term_sonet invalid.");
    return(CS_ERROR);
  }

  return (rtn);
}
/* Bugzilla 22514 End */

/* Bugzilla 22970 Start */
/****************************************************************/
/* $rtn_hdr_start  HIGH LEVEL CONFIG OC192 KPGA */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : HIGH LEVEL CONFIG                               */
/* CHIP       : Tenabo                                          */
cs_status ten_hl_config_oc192_kpga (cs_uint16 module_id,
                                    cs_uint8  slice,
                                    cs_uint8  dyn_repro,
                                    cs_uint16 pattern)
/* INPUTS     : o Module Id                                     */
/*              o Slice                                         */
/*              o Line                                          */
/*              o Dynamic Reprovision Type                      */
/*              o Pattern Selection                             */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* Provision an OC192 KPGA tester                               */
/*                                                              */
/* [module_id] specifies module ID                              */ 
/*   0xXX00 = Module A                                          */      
/*   0xXX01 = Module B                                          */
/*                                                              */      
/* [slice] specifies slice:                                     */      
/*   0x00 = TEN_SLICE0                                          */      
/*   0x01 = TEN_SLICE1                                          */
/*   0x02 = TEN_SLICE2                                          */
/*   0x03 = TEN_SLICE3                                          */
/*                                                              */
/* [dyn_repro]  specifies the type of dynamic reprovisioning:   */
/*   0x00 = TEN_INITIAL_CONFIG                                  */
/*   0x01 = TEN_REPRO_CLIENT                                    */
/*   0x02 = TEN_REPRO_LINE_AND_CLIENT                           */
/*                                                              */
/* The [pattern] parameter is specified as:                     */
/*   0x00 = TEN_KPG_FIXED_PATTERN                               */
/*   0x01 = TEN_KPG_PN11                                        */
/*   0x02 = TEN_KPG_PN23                                        */
/*   0x03 = TEN_KPG_PN31                                        */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  cs_uint16 module_num = module_id & 1;
  cs_status rtn = CS_OK;
  T41_t *pDev = NULL;
  cs_char8 *func = "ten_hl_config_oc192_kpga";  /* __FUNCTION__ or __func__ not available for all compilers */

  TEN_MOD_COMMON_VALIDATE (module_id, pDev, CS_ERROR);

  if ((slice >= TEN_MAX_SLICES) && (slice != TEN_SLICE_ALL)) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, "%s() slice %d out of range.  s/b 0..3, 255.", func, slice);
    return (CS_ERROR);
  }

  if (dyn_repro > TEN_REPRO_LINE_AND_CLIENT) { 
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, "%s() dyn_repro %d out of range.  s/b 0..2.", func, dyn_repro);
    return (CS_ERROR);
  }

  if (pattern > TEN_KPG_PN31) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, "%s() pattern %d out of range.  s/b 0..3.", func, pattern);
    return (CS_ERROR);
  }

  CS_PRINT("%s() %s, Slice %d, %s, pattern = %s\n",
           func,
           ten_module_strings[module_num],
           slice,
           ten_hl_config_dyn_repro_strings[dyn_repro],
           ten_kpg_strings[pattern]);

 
  rtn |= ten_hl_n10g_config (module_id, slice, TEN_N10G_RX_OC192_OC192, TEN_N10G_TX_10GE_OC192, 0);

  /* The virtual container of the concatenated payload SONET/SDH frames will be replaced with PRBS as configured for the KPA. */
  rtn |= ten_n10g_soht_prbsie(module_id, slice, 1);

  /* Turn OTU2 wrapper off  (WRPCFG3.WRMD) */
  rtn |= ten_n10g_otnt_set_wrmd(module_id, slice, 0);

  /* Config KPG */   /* Bugzilla #33766, fix warnings, use cs_ctl_t enums */
  rtn |= ten_n10g_config_kpg(module_id, slice, CS_ENABLE, CS_DISABLE, pattern, 0, 0);

  rtn |= ten_tx_config_sonet_generation (module_id, slice);

  /* Bug #40056:  OTU2 KPGA configuration sets PDHY = 0, PHYS also left at 0 */
 /* rtn |= ten_n10g_set_gblr_pdhy(module_id, slice, 0xE100,0x5F5); */

  return (rtn);
}



/****************************************************************/
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : HIGH LEVEL CONFIG                               */
/* CHIP       : Tenabo                                          */
cs_status ten_tx_config_sonet_generation (cs_uint16 module_id,
                                          cs_uint8  slice)
/* INPUTS     : o Module Id                                     */
/*              o Slice                                         */
/*              o Line                                          */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* Provision an OC192 KPGA tester                               */
/*                                                              */
/* [module_id] specifies module ID                              */ 
/*   0xXX00 = Module A                                          */      
/*   0xXX01 = Module B                                          */
/*                                                              */      
/* [slice] specifies slice:                                     */      
/*   0x00 = TEN_SLICE0                                          */      
/*   0x01 = TEN_SLICE1                                          */
/*   0x02 = TEN_SLICE2                                          */
/*   0x03 = TEN_SLICE3                                          */
/*                                                              */
/****************************************************************/
{
  cs_uint16 i;
  cs_status rtn = CS_OK;

  rtn |= ten_n10g_soht_set_scren (module_id, slice, 1);
  rtn |= ten_n10g_soht_set_b1ie (module_id, slice, 1);

  for (i=0; i<12; i++) {
     rtn |= ten_n10g_soht_b2ie (module_id, slice, i, 0xffff);
  }
  rtn |= ten_n10g_soht_b2ie (module_id, slice, 12, 0x0fff);

  rtn |= ten_n10g_soht_set_pohben0_b3ie (module_id, slice, 1);
  rtn |= ten_n10g_soht_set_pohben0_c2ie (module_id, slice, 1);
  rtn |= ten_n10g_set_poh_byte (module_id, slice, TEN_SET_POH_C2, 1);

  rtn |= ten_n10g_soht_set_ohben0_defie (module_id, slice, 0);

  rtn |= ten_n10g_soht_set_ohben0_nu1ie (module_id, slice, 1);
  rtn |= ten_n10g_set_soh_byte (module_id, slice, TEN_SOH_NU1, 0xCC);

  rtn |= ten_n10g_soht_set_ohben0_j0ie (module_id, slice, 1);

  rtn |= ten_n10g_soht_j0strg0 (module_id, slice, 0, 0x2);

  rtn |= ten_n10g_soht_set_pohben0_j1ie (module_id, slice, 1);

  rtn |= ten_n10g_soht_set_ohben1_k1ie (module_id, slice, 1);
  rtn |= ten_n10g_soht_set_ohben1_k2ie (module_id, slice, 1);

  rtn |= ten_n10g_soht_set_ohben2 (module_id, slice, 1, 1);


  /* Set input to KPA to output of SDH/SONET block  (KPASEL=0) */
  rtn |= ten_n10g_gblr_set_kpasel (module_id, slice, 0);

  /* Enable SDH/SONET descrambler */
  rtn |= ten_n10g_sdfr_set_scren (module_id, slice, 1);

  return (rtn);
}
/* Bugzilla 22970 End */
