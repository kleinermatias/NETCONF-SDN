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
 * ten_hl_syncdsync_t41.c
 *
 * API's for SYNCDSYNC T41 high level configuration.
 *
 * $Id: ten_hl_syncdsync_t41.c,v 1.70 2013/09/13 12:12:47 pptawade Exp $
 *
 */

#include "tenabo40.h"

/* Bugzilla #26154, compile issues */
extern cs_uint32 low_word, hi_word;

/****************************************************************/
/* $rtn_hdr_start HIGH LEVEL CONFIG SYNCDSYNC CONFIG            */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : HIGH LEVEL CONFIG                               */
/* CHIP       : Tenabo                                          */
cs_status ten_hl_syncdsync_datapath_config_t41(cs_uint16 module_id_line,
                                               cs_uint8  slice_line, 
                                               cs_uint16 module_id_client,
                                               cs_uint8  slice_client,
                                               cs_uint8 fec_line,
                                               cs_uint8 fec_client,
                                               cs_uint8  mode,
                                               cs_uint16 method,
                                               cs_uint8  k_divider,
                                               cs_uint8  map_odtu,
                                               cs_uint8  map_oxuv,
                                               cs_uint8  gmp_timeslots)
/* INPUTS     : o Line Module Id                                */
/*              o Line Slice                                    */
/*              o Client Module Id                              */
/*              o Client Slice                                  */
/*              o FEC Type Line                                 */
/*              o FEC Type Client                               */
/*              o Mode                                          */
/*              o Method                                        */
/*              o k Divider                                     */
/*              o Mapping Method Line                           */
/*              o Mapping Method Client                         */
/*              o Timeslots                                     */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* Configures line and client syncdsync blocks based on mode and*/
/* method                                                       */
/*                                                              */
/* [module_id_line] parameter specifies line's module ID        */
/* 16 devices can be registered and module bit indicates line   */
/* or client side of the registered device. The registered device*/
/* is identified by the dev_id bits specified below             */
/*   Bits 11:8 - dev_id, Bits 7:1 - don't care, Bit 0 - module  */
/*                                                              */
/* [slice_line] parameter specifies line's slice:               */
/*   TEN_SLICE0 = 0                                             */
/*   TEN_SLICE1 = 1                                             */
/*   TEN_SLICE2 = 2                                             */
/*   TEN_SLICE3 = 3                                             */
/*                                                              */
/* [module_id_client] parameter specifies client's module ID    */
/* 16 devices can be registered and module bit indicates line   */
/* or client side of the registered device. The registered device*/ 
/* is identified by the dev_id bits specified below             */
/*   Bits 11:8 - dev_id, Bits 7:1 - don't care, Bit 0 - module  */
/*                                                              */
/* [slice_client] parameter specifies client's slice:           */
/*   TEN_SLICE0 = 0                                             */
/*   TEN_SLICE1 = 1                                             */
/*   TEN_SLICE2 = 2                                             */
/*   TEN_SLICE3 = 3                                             */
/*                                                              */
/* [fec_line] parameter defines the line fec type:              */
/* [fec_client] parameter defines the line fec type:            */
/*     TEN_FEC_MODE_NOFEC = 15, or                              */
/*     Any other FEC% as per ten_fec_ovhd_t = 0 -14             */
/*                                                              */
/* [mode] specifies one of the three modes                      */
/*   TEN_40G_TRANSPONDER  = 0 (40G to 40G)                      */
/*   TEN_40G_MUXPONDER    = 1 (10G to 40G)                      */
/*   TEN_10G_TRANSPONDER  = 2 (10G to 10G)                      */
/*                                                              */
/* [method] specifies how syncdysnc blocks can be               */
/* configured for 40G applications                              */
/*   TEN_1TO1_ASYNC_2LEVEL = 0                                  */
/*       Client -  1:1                                          */
/*       Line   -  Async 2 level mapping                        */
/*   TEN_SYNC_ASYNC_1LEVEL = 1                                  */
/*       Client -  Sync  1 level mapping                        */
/*       Line   -  Async 1 level mapping                        */
/*   TEN_1TO1_ASYNC_1LEVEL = 2                                  */
/*       Client -  1:1                                          */
/*       Line   -  Async 1 level mapping                        */
/*   TEN_BOTH_1TO1         = 3                                  */
/*       Client -  1:1                                          */
/*       Line   -  1:1                                          */
/*                                                              */
/* [k_divider] specifies the value of constant 'k'              */
/*   Async : 16 - 64                                            */
/*   Sync  : 16 - 255                                           */
/*                                                              */
/* The [map_odtu] parameter specifies the mapping method        */
/* The [map_oxuv] parameter specifies the mapping method        */
/*  TEN_MAP_BMP,           = 0                                  */
/*  TEN_MAP_AMP,           = 1                                  */
/*  TEN_MAP_AMP_DT,        = 2                                  */
/*  TEN_MAP_AMP_PROP,      = 3                                  */
/*  TEN_MAP_AMP_PROP_DT,   = 4                                  */
/*  TEN_MAP_GMP_LO,        = 5                                  */
/*  TEN_MAP_GMP_HO,        = 6                                  */
/*  TEN_MAP_GMP_HO_DT,     = 7                                  */
/*                                                              */
/* The [gmp_timeslots] parameter specifies number of timeslots. */
/* Applicable to GMP_HO only if [map_proc] = TEN_MAP_GMP_HO     */
/* Bandwidth is always 1.25G per timeslot                       */
/*   1 - 8                                                      */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  cs_status rtn = CS_OK;
  cs_uint16 dev_id;
  ten_dev_cb_t *pdevcb;

  cs_uint8 i=0;
  cs_uint32 n1, n2, m1, m2;
  cs_uint32 num_hi, num_lo, denom_hi, denom_lo, ac1_hi=0, ac1_lo=0, ac2_hi=0, ac2_lo=0, ad1=0, ad2=0;
  cs_uint8 cfg=0, cfgpd0=0, jc_thresh=0;
  cs_int16 num_just_odu3, num_just_client;
  cs_uint16 num_pjo_odu3, num_pjo_odu2, num_pjo_client;
  cs_int16 num_just_oxu3_client;          /* Bugzilla 26729 */
  cs_uint16 num_pjo_oxu3_client;          /* Bugzilla 26729 */
  cs_int16 num_just_odtu, num_just_oxuv;
  cs_uint16 num_pjo_odtu, num_pjo_oxuv;
  cs_uint8 max_pjo;
  double Cm=0, Cn=0, hysteresis=0;
  cs_uint8 map_oxuv_simplified=0;
  cs_char8 *func = "ten_hl_syncdsync_datapath_config_t41";  

  CS_PRINT("%s() \n", func);
  CS_PRINT("    line %s\n", ten_module_strings[module_id_line&1]);
  CS_PRINT("    slice_line=%d\n", slice_line);
  CS_PRINT("    client %s\n", ten_module_strings[module_id_client&1]);
  CS_PRINT("    slice_client=%d\n", slice_client);
  CS_PRINT("    line fec=%s\n", ten_fec_ovhd_strings[fec_line]);
  CS_PRINT("    client fec=%s\n", ten_fec_ovhd_strings[fec_client]);
  CS_PRINT("    %s\n", ten_traffic_mode_strings[mode]);
  CS_PRINT("    %s\n", ten_method_strings[method]);
  CS_PRINT("    k_divider=%d\n", k_divider);
            
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
  CS_PRINT("    gmp_timeslots=%d\n", gmp_timeslots);

  dev_id = TEN_MOD_ID_TO_DEV_ID(module_id_line);
  pdevcb = TEN_DEV_ID_TO_DEVCB_PTR(dev_id);
  
  CS_PRINT("    line_rate=%f\n", pdevcb->syncdsync_thread_cb[slice_client].line_rate);
  CS_PRINT("    xcon_client_rate=%f\n", pdevcb->syncdsync_thread_cb[slice_client].xcon_client_rate);
  CS_PRINT("    client_rate=%f\n", pdevcb->syncdsync_thread_cb[slice_client].client_rate);

  CS_PRINT("    num_just_oxu3=%d\n", pdevcb->syncdsync_thread_cb[slice_client].num_just_oxu3);
  CS_PRINT("    num_pjo_odu3=%d\n", pdevcb->syncdsync_thread_cb[slice_client].num_pjo_oxu3);

  CS_PRINT("    num_just_oxu2=%d\n", pdevcb->syncdsync_thread_cb[slice_client].num_just_oxu2);
  CS_PRINT("    num_pjo_oxu2=%d\n", pdevcb->syncdsync_thread_cb[slice_client].num_pjo_oxu2);

  CS_PRINT("    num_just_oxu3_client=%d\n", pdevcb->syncdsync_thread_cb[slice_client].num_just_oxu3_client);
  CS_PRINT("    num_pjo_oxu3_client=%d\n", pdevcb->syncdsync_thread_cb[slice_client].num_pjo_oxu3_client);

  CS_PRINT("    transcode_num=%d\n", pdevcb->syncdsync_thread_cb[slice_client].transcode_num);
  CS_PRINT("    transcode_denom=%d\n", pdevcb->syncdsync_thread_cb[slice_client].transcode_denom);


  switch(mode) {
    case TEN_40G_TRANSPONDER:
    case TEN_40G_WIRE:  /* Bugzilla 24645/28501 */
      num_just_odu3   = pdevcb->syncdsync_thread_cb[slice_client].num_just_oxu3;
      num_pjo_odu3    = pdevcb->syncdsync_thread_cb[slice_client].num_pjo_oxu3;

      num_just_oxu3_client  = pdevcb->syncdsync_thread_cb[slice_client].num_just_oxu3_client;   /* Bugzilla 26729 */
      num_pjo_oxu3_client   = pdevcb->syncdsync_thread_cb[slice_client].num_pjo_oxu3_client;    /* Bugzilla 26729 */

      num_just_client  = pdevcb->syncdsync_thread_cb[slice_client].num_just_oxu2;
      num_pjo_client   = pdevcb->syncdsync_thread_cb[slice_client].num_pjo_oxu2; 

      if(map_oxuv == TEN_MAP_GMP_LO) {
        /* Bugzilla 28006 Start */
        /* Client side */
        if (map_odtu == TEN_MAP_AMP_PROP) {
          /* Async to Async 1 Level */
          /* Client Side is GMP. Line side is AMP Proprietary (Dual Muxponder) */
#if 0
          //Cm = ((2.0*pdevcb->syncdsync_thread_cb[slice_client].P_line * pdevcb->syncdsync_thread_cb[slice_client].client_rate) /
          //  pdevcb->syncdsync_thread_cb[slice_client].line_rate) * ((cs_float)pdevcb->syncdsync_thread_cb[slice_client].transcode_denom /
          //  (cs_float)pdevcb->syncdsync_thread_cb[slice_client].transcode_num);
          
          //Cm = ((2.0*pdevcb->syncdsync_thread_cb[slice_client].P_client * pdevcb->syncdsync_thread_cb[slice_client].client_rate) /
          //  pdevcb->syncdsync_thread_cb[slice_client].xcon_client_rate) * ((cs_float)pdevcb->syncdsync_thread_cb[slice_client].transcode_denom /
          //  (cs_float)pdevcb->syncdsync_thread_cb[slice_client].transcode_num);
#endif
          Cm = ((2.0*pdevcb->syncdsync_thread_cb[slice_client].P_client * pdevcb->syncdsync_thread_cb[slice_client].xcon_client_rate) /
            pdevcb->syncdsync_thread_cb[slice_client].client_rate) * ((cs_float)pdevcb->syncdsync_thread_cb[slice_client].transcode_denom /
            (cs_float)pdevcb->syncdsync_thread_cb[slice_client].transcode_num);

          Cn = _round(Cm*(double)gmp_timeslots);
          pdevcb->syncdsync_thread_cb[slice_client].cn_bytes_n40g = Cn;  
           
          /* Client Side */
          /*n2 = (cs_uint32)(pdevcb->syncdsync_thread_cb[slice_client].P_line*16*4);*/
          n1 = (cs_uint32)(pdevcb->syncdsync_thread_cb[slice_client].P_client*16*4);
          m1 = (cs_uint32)Cn;
           
          /* Line Side */
          n2 = pdevcb->syncdsync_thread_cb[slice_client].P_line*16*4;
          m2 = 238*16*4 - num_just_odu3;
           
          /*for(i=0;i<4;i++) {*/
            ten_syncdsync_trans_async_async_1level_config (module_id_line, slice_line, 
                                                           module_id_client, slice_client,
                                                           k_divider, n1, m1, n2, m2,
                                                           /*mode, num_pjo_oxuv, num_pjo_odtu,*/
                                                           TEN_OXU3_MONO_ONE_LEVEL, num_pjo_oxu3_client, num_pjo_odu3,
                                                           TEN_SLICE_40G);
          /*}*/                                                 
         
          ten_syncdsynctx_gmp_enbl_t41(module_id_client, slice_client, 1);
          ten_syncdsynctx_gmp_enbl_t41(module_id_client, 3, 1);  /* Bugzilla 28200 */
        
        } else {
          /* Bugzilla 28006 End */
          Cm = ((2.0*pdevcb->syncdsync_thread_cb[slice_client].P_line*pdevcb->syncdsync_thread_cb[slice_client].client_rate) /
            pdevcb->syncdsync_thread_cb[slice_client].line_rate) * ((cs_float)pdevcb->syncdsync_thread_cb[slice_client].transcode_denom /
            (cs_float)pdevcb->syncdsync_thread_cb[slice_client].transcode_num);

          Cn = _round(Cm*(double)gmp_timeslots);
          pdevcb->syncdsync_thread_cb[slice_client].cn_bytes_n40g = Cn;  

          if(method == TEN_1TO1_ASYNC_1LEVEL) {
            n1 = (cs_uint32)(pdevcb->syncdsync_thread_cb[slice_client].P_line*16*4);
            m1 = (cs_uint32)Cn;
            n2 = 1;
            m2 = 1;

            ten_syncdsync_trans_1to1_async_config(module_id_line, slice_line, 
                                                  module_id_client, slice_client,
                                                  k_divider, n1, m1, 
                                                  TEN_OXU3_MONO_ONE_LEVEL, num_pjo_odu3, 
                                                  TEN_SLICE_40G);    /* Bugzilla 26729 */
          }
          else if(method == TEN_1TO1_ASYNC_1TO1_1LEVEL) {
            n1 = (cs_uint32)(pdevcb->syncdsync_thread_cb[slice_client].P_line*16*4);
            m1 = (cs_uint32)Cn;
            n2 = 1;
            m2 = 1;

            ten_syncdsync_trans_1to1_async_1to1_config(module_id_line, slice_line, 
                                                       module_id_client, slice_client,
                                                       k_divider, n1, m1, 
                                                       TEN_OXU3_MONO_ONE_LEVEL, num_pjo_odu3,
                                                       TEN_SLICE_40G);    /* Bugzilla 26729 */
          }
          else if(method == TEN_SYNC_ASYNC_1LEVEL) {
            n1 = pdevcb->syncdsync_thread_cb[slice_client].P_client*16*4;
            m1 = 239*16*4;
            n2 = (cs_uint32)(pdevcb->syncdsync_thread_cb[slice_client].P_line*16*4);
            m2 = (cs_uint32)Cn;

            ten_syncdsync_trans_sync_async_config(module_id_line, slice_line, 
                                                  module_id_client, slice_client,
                                                  k_divider, n1, m1, n2, m2,
                                                  TEN_OXU3_MONO_ONE_LEVEL, num_pjo_odu3,
                                                  TEN_SLICE_40G);    /* Bugzilla 26729 */
          }
          else if(method == TEN_BOTH_1TO1) {
              ten_syncdsync_1_to_1_config(module_id_line, slice_line, 
                                          module_id_client, slice_client,
                                          k_divider);
          }
          else {
            CS_PRINT("%s()  Method not supported!\n", func);
            rtn = CS_ERROR;
            goto RTN_EXIT;
          }
          ten_syncdsynctx_gmp_enbl_t41(module_id_line, slice_line, 1);
          ten_syncdsynctx_gmp_enbl_t41(module_id_line, 3, 1);  /* Bugzilla 28200 */
        }
        /*ten_syncdsynctx_gmp_enbl_t41(module_id_line, slice_line, 1); */
        /*ten_syncdsynctx_gmp_enbl_t41(module_id_line, 3, 1);*/  /* Bugzilla 28200 */
      }
      else {
        if(method == TEN_ASYNC_ASYNCX4_1LEVEL) {
          n2 = (cs_uint32)(pdevcb->syncdsync_thread_cb[slice_client].P_line*16*4);
          m2 = (cs_uint32)Cn;
          n1 = pdevcb->syncdsync_thread_cb[slice_client].P_line*16*4;
          m1 = 238*16*4 - num_just_odu3;

          ten_syncdsync_trans_async_asyncx4_config(module_id_line, slice_line, 
                                                   module_id_client, slice_client,
                                                   k_divider,
                                                   n1, m1, n2, m2,
                                                   mode, num_pjo_client, num_pjo_odu3,
                                                   TEN_SLICE_40G);    /* Bugzilla 26729 */

          ten_syncdsynctx_gmp_enbl_t41(module_id_line, slice_line, 1);
          ten_syncdsynctx_gmp_enbl_t41(module_id_line, 3, 1);   /* Bugzilla 28200 */
        }
        /* Bugzilla 29481 Start */
        else if ((map_oxuv == TEN_MAP_BMP) && (map_odtu == TEN_MAP_GMP_LO)) {   /* Bugzilla 34253 */
           if (method == TEN_SYNC_ASYNC_1LEVEL) {
             /* High Order Mapping is GMP */
             Cm = ((2.0*pdevcb->syncdsync_thread_cb[slice_client].P_line*pdevcb->syncdsync_thread_cb[slice_client].xcon_client_rate) /
             /*Cm = ((2.0*pdevcb->syncdsync_thread_cb[slice_client].P_line*pdevcb->syncdsync_thread_cb[slice_client].client_rate) / */
             pdevcb->syncdsync_thread_cb[slice_client].line_rate);

             Cn = _round(Cm*(double)gmp_timeslots);
             pdevcb->syncdsync_thread_cb[slice_client].cn_bytes_n40g = Cn;  


             CS_PRINT("    Cm           = %f\n", Cm);
             CS_PRINT("    Cn           = %f\n", Cn);

             /* Line Side */
             /*n2 = (cs_uint32)(pdevcb->syncdsync_thread_cb[slice_client].P_line*(32.0*16.0*4.0)/4.0);*/
             n2 = (cs_uint32)(pdevcb->syncdsync_thread_cb[slice_client].P_line*16*4);
             m2 = (cs_uint32)Cn;

             /* Client Side */
             n1 = pdevcb->syncdsync_thread_cb[slice_client].P_client*16*4;
             m1 = 239*16*4;     /* m1 = pdevcb->syncdsync_thread_cb[slice_client].Q_client*16*4 */
             /*m1 = 238*16*4;*/     /* m1 = pdevcb->syncdsync_thread_cb[slice_client].Q_client*16*4 */


             ten_syncdsync_trans_sync_async_config(module_id_line, slice_line, 
                                                   module_id_client, slice_client,
                                                   k_divider, n1, m1, n2, m2,
                                                   TEN_OXU3_MONO_ONE_LEVEL, num_pjo_odu3,
                                                   TEN_SLICE_40G);

             ten_syncdsynctx_gmp_enbl_t41(module_id_line, slice_client, 1);
             ten_syncdsynctx_gmp_enbl_t41(module_id_line, 3, 1);
           }
        }
        /* Bugzilla 29481 End */
        else {
          /* ten_hl_syncdsync_threadsafe_datapath_config only understands sync and */
          /* async so we need to translate map_oxuv to either sync or async        */
          /* Bugzilla 27167 Start */
          if (map_odtu == TEN_MAP_DONT_CARE) {
            /* map_odtu is not specified, so can only use map_oxuv */
            if (map_oxuv == TEN_MAP_BMP) {
              map_oxuv_simplified = 1;
            }
            else {
              map_oxuv_simplified = 0;
            }
          } else {
            if ((map_oxuv == TEN_MAP_BMP) && (map_odtu == TEN_MAP_BMP)) {
              map_oxuv_simplified = 1;
            }
            else {
              map_oxuv_simplified = 0;
            }
          }
          /* Bugzilla 27167 End */
          ten_hl_syncdsync_threadsafe_datapath_config(module_id_line, slice_line, 
                                                      module_id_client, slice_client,
                                                      mode, map_oxuv_simplified, method,
                                                      k_divider, fec_line, fec_client);
        }
      }
      break;
  
    case TEN_40G_MUXPONDER:
      num_just_odtu = pdevcb->syncdsync_thread_cb[slice_client].num_just_oxu3;
      num_pjo_odtu  = pdevcb->syncdsync_thread_cb[slice_client].num_pjo_oxu3;
      num_just_oxuv = pdevcb->syncdsync_thread_cb[slice_client].num_just_oxu2;
      num_pjo_oxuv  = pdevcb->syncdsync_thread_cb[slice_client].num_pjo_oxu2;

      pdevcb->syncdsync_thread_cb[slice_client].client_map_proc = map_oxuv;
      pdevcb->syncdsync_thread_cb[slice_client].line_map_proc = map_odtu;
  
      if((map_odtu == TEN_MAP_GMP_HO_DT) || (map_odtu == TEN_MAP_GMP_HO)) {
        /* High Order Mapping into odtu23 or odtu3.ts is GMP */
        pdevcb->syncdsync_thread_cb[slice_client].ad2_constant = 8;  /*Bugzilla 41096*/
        pdevcb->syncdsync_thread_cb[slice_client].multi_frames = 32; /*Bugzilla 41096*/

        Cm = (2048.0*pdevcb->syncdsync_thread_cb[slice_client].P_line*pdevcb->syncdsync_thread_cb[slice_client].xcon_client_rate) /
                   ((double)gmp_timeslots*pdevcb->syncdsync_thread_cb[slice_client].line_rate);
        
        Cn = _round(Cm*(double)gmp_timeslots);
        pdevcb->syncdsync_thread_cb[slice_client].cn_bytes_n40g = Cn;  /*Bugzilla 26308*/
        
        /* Line side  */
        n1 = (cs_uint32)(pdevcb->syncdsync_thread_cb[slice_client].P_line*(32.0*16.0*4.0)/4.0);
        m1 = (cs_uint32)Cn;
        m1 |=  gmp_timeslots << 24;   /* Bugzilla 31322 */

        /* Deterministic Hysteresis */
        if(map_odtu == TEN_MAP_GMP_HO_DT) {
          hysteresis = (pdevcb->syncdsync_thread_cb[slice_client].P_line*128.0)/(_round(((Cm*gmp_timeslots))) - 
                        (4*pdevcb->syncdsync_thread_cb[slice_client].xcon_client_rate*n1/pdevcb->syncdsync_thread_cb[slice_client].line_rate));
          pdevcb->syncdsync_thread_cb[slice_client].hysteresis = (cs_uint32)hysteresis;

          /*ten_calc_hyst(dev_id);*/  /* Bugzilla 28237 */
        }

        if((map_oxuv == TEN_MAP_AMP) || (map_oxuv ==TEN_MAP_AMP_PROP)) {
          /* Low Order Mapping of client into odu2v is AMP or AMP_PROP */
          if (method == TEN_1TO1_ASYNC_2LEVEL) {
            n2 = 239*16*4;
            m2 = (238*16*4-num_just_oxuv);

            ten_syncdsync_mux_1to1_async_2level_config(module_id_line, slice_line, 
                                                       module_id_client, slice_client,
                                                       k_divider, n1, n2, m1, m2, 
                                                       num_pjo_oxuv, num_pjo_odtu);
          }
          else {
            CS_PRINT("%s()  Method not supported!\n", func);
            rtn = CS_ERROR;
            goto RTN_EXIT;
          }
        }
        else if(map_oxuv == TEN_MAP_BMP) {
          /* Low Order Mapping of Client into odu2v is BMP */
          if (method == TEN_1TO1_ASYNC_2LEVEL) {
            /* Cleint sync mapping into Mux ODU2v */
            n2 = 239*16*4;
            m2 = (238*16*4-num_just_oxuv);

            ten_syncdsync_mux_1to1_async_2level_config(module_id_line, slice_line, 
                                                       module_id_client, slice_client,
                                                       k_divider, n1, n2, m1, m2, 
                                                       num_pjo_oxuv, num_pjo_odtu);
          }
          else if (method == TEN_SYNC_ASYNC_1LEVEL) {
            n2 = pdevcb->syncdsync_thread_cb[slice_client].P_client*16*4;
            m2 = 239*16*4;

            ten_syncdsync_mux_sync_async_1level_config(module_id_line, slice_line, 
                                                       module_id_client, slice_client,
                                                       fec_client, k_divider, n1, n2, m1, m2, 
                                                       num_pjo_oxuv, num_pjo_odtu);
          }
          else if (method == TEN_BOTH_1TO1) {
            ten_syncdsync_1_to_1_config(module_id_line, slice_line, 
                                        module_id_client, slice_client,
                                        k_divider);
          }
        }
        else if(map_oxuv == TEN_MAP_GMP_LO) {
          /* Client side mapping is GMP_LO */
          if (method == TEN_1TO1_ASYNC_2LEVEL) {          
            /* Client */
            Cm = (8.0*239.0*pdevcb->syncdsync_thread_cb[slice_client].client_rate) /
                       pdevcb->syncdsync_thread_cb[slice_client].xcon_client_rate;

            Cn = (cs_uint32)(Cm*(double)gmp_timeslots);
            pdevcb->syncdsync_thread_cb[slice_client].cn_bytes_n10g = Cn;  /*Bugzilla 26308*/

            n2 = (cs_uint32)(239.0*16.0*4.0);
            m2 = (cs_uint32)Cn;

            ten_syncdsync_mux_1to1_async_2level_config(module_id_line, slice_line, 
                                                       module_id_client, slice_client,
                                                       k_divider, n1, n2, m1, m2, 
                                                       num_pjo_oxuv, num_pjo_odtu);
          }
          else {
            CS_PRINT("%s()  Method not supported!\n", func);
            rtn = CS_ERROR;
            goto RTN_EXIT;
          }
        }
        else if (pdevcb->oduflex_cb.enbl) {
          if (method == TEN_1TO1_ASYNC_2LEVEL) {
            n2 = 238*16*4;
            m2 = 239*16*4;

            ten_syncdsync_mux_1to1_async_2level_config(module_id_line, slice_line, 
                                                       module_id_client, slice_client,
                                                       k_divider, n1, n2, m1, m2, 
                                                       num_pjo_oxuv, num_pjo_odtu);
          }
          else {
            CS_PRINT("%s()  Method not supported!\n", func);
            rtn = CS_ERROR;
            goto RTN_EXIT;
          }
        }
/* Bugzilla 29100 Debug Start */        
        else if(map_oxuv == TEN_MAP_GMP_HO) {
          if (method == TEN_ASYNC_ASYNC_1LEVEL) {
            for(i=0;i<4;i++) {
              Cm = (2048.0*pdevcb->syncdsync_thread_cb[slice_client].P_line*pdevcb->syncdsync_thread_cb[slice_client].xcon_client_rate) /
                         ((double)gmp_timeslots*pdevcb->syncdsync_thread_cb[slice_client].client_rate);
              
              Cn = _round(Cm*(double)gmp_timeslots);
              pdevcb->syncdsync_thread_cb[i].cn_bytes_n10g = Cn;  /* Bugzilla 29100 */

              /* Line Side */
              n1 = (cs_uint32)(pdevcb->syncdsync_thread_cb[slice_client].P_line*(32.0*16.0*4.0)/4.0);
              m1 = (cs_uint32)Cn;
              m1 |=  gmp_timeslots << 24;   /* Bugzilla 31322 */

              /* Client Side*/
              n2 = (cs_uint32)(pdevcb->syncdsync_thread_cb[slice_client].P_line*(32.0*16.0*4.0)/4.0);
              m2 = (cs_uint32)Cn;

              pdevcb->syncdsync_thread_cb[i].transcode_num = pdevcb->syncdsync_thread_cb[slice_client].transcode_num;
              pdevcb->syncdsync_thread_cb[i].transcode_denom = pdevcb->syncdsync_thread_cb[slice_client].transcode_denom;

              ten_syncdsync_mux_async_async_1level_config(module_id_line, i, 
                                                          module_id_client, i,
                                                          k_divider, n1, n2, m1, m2,
                                                          num_pjo_oxuv, num_pjo_odtu);

              ten_syncdsynctx_gmp_enbl_t41(module_id_client, i, 1);
            }
          }
        }
/* Bugzilla 29100 Debug End */        
        ten_syncdsynctx_gmp_enbl_t41(module_id_line, slice_line, 1);
      }
      else if((map_odtu == TEN_MAP_AMP_PROP) || (map_odtu == TEN_MAP_AMP)) {  /* Bugzilla 26787 */
        /* Mapping into odtu23 or odtu3.ts */
        if (map_oxuv == TEN_MAP_GMP_HO) {
          /* Mapping of client into odu2v */
          if (method == TEN_ASYNC_ASYNC_1LEVEL) {
            /* Dual Muxponder */
            for(i=0;i<4;i++) {
              Cm = (2048.0*pdevcb->syncdsync_thread_cb[slice_client].P_line*pdevcb->syncdsync_thread_cb[slice_client].xcon_client_rate) /
                         ((double)gmp_timeslots*pdevcb->syncdsync_thread_cb[slice_client].client_rate);     /*Bugzilla 26787 */
              
              Cn = _round(Cm*(double)gmp_timeslots);
              pdevcb->syncdsync_thread_cb[i].cn_bytes_n10g = Cn;  /* Bugzilla 29100 */

              /* Bugzilla 26787 Start */
              /* Line Side */
              n1 = pdevcb->syncdsync_thread_cb[slice_client].P_client*16*4*4;
              m1 = 238*16*4*4-num_just_odtu;

              /* Client Side */
              n2 = (cs_uint32)(pdevcb->syncdsync_thread_cb[slice_client].P_line*(32.0*16.0*4.0)/4.0);
              m2 = (cs_uint32)Cn;
              m2 |=  gmp_timeslots << 24;   /* Bugzilla 31322 */
              /* Bugzilla 26787 End */

              pdevcb->syncdsync_thread_cb[i].transcode_num = pdevcb->syncdsync_thread_cb[slice_client].transcode_num;
              pdevcb->syncdsync_thread_cb[i].transcode_denom = pdevcb->syncdsync_thread_cb[slice_client].transcode_denom;

              ten_syncdsync_mux_async_async_1level_config(module_id_line, i, 
                                                          module_id_client, i,
                                                          k_divider, n1, n2, m1, m2,     /* Bugzilla 26785 */
                                                          num_pjo_oxuv, num_pjo_odtu);

              ten_syncdsynctx_gmp_enbl_t41(module_id_client, i, 1);  /* Bugzilla 29100 */
            }
          }
          else {
            CS_PRINT("%s()  Method not supported!\n", func);
            rtn = CS_ERROR;
            goto RTN_EXIT;
          }

          ten_syncdsynctx_gmp_enbl_t41(module_id_client, slice_client, 1);
        }
        /* Bugzilla 26787 Start */
        else if ((map_oxuv == TEN_MAP_AMP_PROP) || (map_oxuv == TEN_MAP_AMP)) {
          if (method == TEN_ASYNC_ASYNC_1LEVEL) {
            for(i=0;i<4;i++) {
              n1 = pdevcb->syncdsync_thread_cb[slice_client].P_line*16*4*4;
              m1 = 238*16*4*4-num_just_odtu;

              n2 = pdevcb->syncdsync_thread_cb[slice_client].P_client*16*4*4;
              m2 = 238*16*4*4-num_just_oxuv;

              pdevcb->syncdsync_thread_cb[i].transcode_num =
                   pdevcb->syncdsync_thread_cb[slice_client].transcode_num;
              pdevcb->syncdsync_thread_cb[i].transcode_denom =
                   pdevcb->syncdsync_thread_cb[slice_client].transcode_denom;

              ten_syncdsync_mux_async_async_1level_config(module_id_line, i, 
                                                          module_id_client, i,
                                                          k_divider, n1, n2, m1, m2,    /* Bugzilla 26785 */
                                                          num_pjo_oxuv, num_pjo_odtu);
            }
          }
        }
        else { /* Rest of the cases are common to T40/T41 */
          ten_hl_syncdsync_threadsafe_datapath_config(module_id_line, slice_line, 
                                                      module_id_client, slice_client,
                                                      mode, map_oxuv, method,
                                                      k_divider, fec_line, fec_client);
        }
        /* Bugzilla 26787 End */
      }
      else if (map_oxuv == TEN_MAP_GMP_LO) {
        /* Non OTN client being mapped into an OTN */
        Cm = (8.0*239.0*pdevcb->syncdsync_thread_cb[slice_client].client_rate) /
                   pdevcb->syncdsync_thread_cb[slice_client].xcon_client_rate;

        Cn = (cs_uint32)(Cm*(double)gmp_timeslots);
        pdevcb->syncdsync_thread_cb[slice_client].cn_bytes_n10g = Cn;  /*Bugzilla 26308*/

        n2 = (cs_uint32)239.0*16.0*4.0;
        m2 = (cs_uint32)Cn;

        if((map_odtu == TEN_MAP_AMP_DT) || (map_odtu ==TEN_MAP_AMP_PROP_DT)) {
          if (method == TEN_1TO1_ASYNC_2LEVEL) {
            n1 = pdevcb->syncdsync_thread_cb[slice_client].P_line*16*4*4;
            m1 = (238*16*4*4-num_just_odtu);
            m1 |=  gmp_timeslots << 24;

            ten_syncdsync_mux_1to1_async_2level_config(module_id_line, slice_line, 
                                                       module_id_client, slice_client,
                                                       k_divider, n1, n2, m1, m2, 
                                                       num_pjo_oxuv, num_pjo_odtu);

            /* Deterministic Hysteresis */
            ten_calc_hyst_t41(dev_id, slice_line, map_odtu); /* Bugzilla 39003 */
          }
          else {
            CS_PRINT("%s()  Method not supported!\n", func);
            rtn = CS_ERROR;
            goto RTN_EXIT;
          }
        }
        ten_syncdsynctx_gmp_enbl_t41(module_id_line, slice_line, 1);
      }
      else { /* Rest of the cases are common to T40/T41 */
        ten_hl_syncdsync_threadsafe_datapath_config(module_id_line, slice_line, 
                                                    module_id_client, slice_client,
                                                    mode, map_oxuv, method,
                                                    k_divider, fec_line, fec_client);
      }
      break;

    case TEN_10G_TRANSPONDER:
    case TEN_10G_WIRE:  /* Bugzilla 24645/28501 */
      if((map_oxuv == TEN_MAP_AMP) || (map_oxuv ==TEN_MAP_AMP_PROP) || (map_oxuv == TEN_MAP_BMP)) {
        ten_hl_syncdsync_threadsafe_datapath_config(module_id_line, slice_line, 
                                                    module_id_client, slice_client,
                                                    mode, map_oxuv, method,
                                                    k_divider, fec_line, fec_client);
      }
      else if(map_oxuv == TEN_MAP_GMP_LO) {
        num_pjo_odu2    = pdevcb->syncdsync_thread_cb[slice_client].num_pjo_oxu2;

        Cm = (8.0*pdevcb->syncdsync_thread_cb[slice_client].P_line*pdevcb->syncdsync_thread_cb[slice_client].client_rate) /
                   pdevcb->syncdsync_thread_cb[slice_client].line_rate;

        Cn = _round(Cm*(double)gmp_timeslots);
        pdevcb->syncdsync_thread_cb[slice_line].cn_bytes_n10g = Cn;  /*Bugzilla 26308*/ /*Bugzilla 36604*/

        n1 = (cs_uint32)(pdevcb->syncdsync_thread_cb[slice_client].P_line*(16.0*4.0));
        m1 = (cs_uint32)Cn;

        ten_syncdsync_trans_1to1_async_config(module_id_line, slice_line, 
                                              module_id_client, slice_client,
                                              k_divider, n1, m1, 0, num_pjo_odu2,
                                              TEN_SLICE_10G);    /* Bugzilla 26729 */


        ten_syncdsynctx_gmp_enbl_t41(module_id_line, slice_line, 1);
      }
      else if(map_oxuv == TEN_MAP_GMP_HO) {
          num_pjo_odu2    = pdevcb->syncdsync_thread_cb[slice_client].num_pjo_oxu2;

          /* Client RX */
          n1 = 238*16*4*pdevcb->syncdsync_thread_cb[slice_client].transcode_num;
          m1 = 239*16*4*pdevcb->syncdsync_thread_cb[slice_client].transcode_denom;
          n2 = 1;
          m2 = 1;

          /*num    = m1 * m2; */
          long_multiply(m1, m2);
          num_hi = hi_word;
          num_lo = low_word;

          /* denom  = n1 * n2 * k_divider; */
          long_multiply(n1*k_divider, n2);
          denom_hi = hi_word;
          denom_lo = low_word;

          ten_syncdsyncrx_cfg(module_id_client,
                              slice_client,
                              num_hi, num_lo, denom_hi, denom_lo,
                              0,0,0,0,0,0,0);

          /* ODUFlex Line TX */
          ten_syncdsync_config_1_to_1(module_id_line,
                                      pdevcb->oduflex_cb.line_slice,
                                      ((module_id_client & 1) * 4) + slice_client,
                                      CS_TX, 
                                      k_divider);

          /* ODUFlex Line RX */
          ten_syncdsync_config_1_to_1(module_id_line,
                                      pdevcb->oduflex_cb.line_slice,
                                      0,
                                      CS_RX, 
                                      k_divider);

          /* Line TX */
          /* xcon_client_rate = ODUflex_rate */
          Cm = (512.0*pdevcb->syncdsync_thread_cb[slice_client].P_line*pdevcb->syncdsync_thread_cb[slice_client].xcon_client_rate) /
                   ((double)gmp_timeslots*pdevcb->syncdsync_thread_cb[slice_client].line_rate);

          Cn = _round(Cm*(double)gmp_timeslots);
          pdevcb->syncdsync_thread_cb[slice_line].cn_bytes_n10g = Cn; /*Bugzilla 26308*/ /*Bugzilla 36604*/

          n1 = (cs_uint32)(pdevcb->syncdsync_thread_cb[slice_client].P_line*(8.0*16.0*4.0));
          m1 = (cs_uint32)Cn;
          n2 = 1;
          m2 = 1;

          /*num    = m1 * m2 * trans_num; */
          long_multiply(m1, m2*pdevcb->syncdsync_thread_cb[slice_client].transcode_num);
          num_hi = hi_word;
          num_lo = low_word;

          /* denom  = n1 * n2 * k_divider * trans_denom; */
          long_multiply(n1*k_divider, n2*pdevcb->syncdsync_thread_cb[slice_client].transcode_denom);
          denom_hi = hi_word;
          denom_lo = low_word;

          /* ac1 = n1 * m2; */
          ac1_hi = 0;
          ac1_lo = 0;

          /* ac2 = n1 * n2 * trans_num; */
          long_multiply(n1, n2*pdevcb->syncdsync_thread_cb[slice_client].transcode_num);
          ac2_hi = hi_word;
          ac2_lo = low_word;

          ad1 = 0;
          ad2 = num_pjo_odu2*pdevcb->syncdsync_thread_cb[slice_client].transcode_num;

          cfg    = 0;
          cfgpd0 = 0x01;

          jc_thresh = (cs_uint32)_ten_floor((cs_float)(2.0 * ((cs_float)k_divider)/((2.0 * (cs_float)num_pjo_odu2) + 1.0)));  /* Bugzilla #26345 */
          max_pjo = (cs_uint8)num_pjo_odu2;

          /* Line TX */
          ten_syncdsynctx_cfg(module_id_client,
                              slice_client,
                              ((module_id_line & 1) * 4) + pdevcb->oduflex_cb.line_slice, 
                              num_hi, num_lo, denom_hi, denom_lo,
                              ac1_hi, ac1_lo, ac2_hi, ac2_lo,
                              ad1, ad2,
                              cfg, cfgpd0,
                              jc_thresh,
                              max_pjo);

          /* Line RX */
          ten_syncdsyncrx_cfg(module_id_client,
                              slice_client,
                              num_hi, num_lo, denom_hi, denom_lo,
                              ac1_hi, ac1_lo, ac2_hi, ac2_lo,
                              ad1, ad2,
                              cfg);

        /* ODUflex Client TX */
        ten_syncdsync_config_1_to_1(module_id_line,
                                    pdevcb->oduflex_cb.client_slice,
                                    ((module_id_client & 1) * 4) + slice_line,
                                    CS_TX, 
                                    k_divider);

        /* ODUflex Client RX */
        n1 = 239*16*4*pdevcb->syncdsync_thread_cb[slice_client].transcode_denom;
        m1 = 238*16*4*pdevcb->syncdsync_thread_cb[slice_client].transcode_num;
        n2 = 1;
        m2 = 1;

        /*num    = m1 * m2; */
        long_multiply(m1, m2);
        num_hi = hi_word;
        num_lo = low_word;

        /* denom  = n1 * n2 * k_divider; */
        long_multiply(n1*k_divider, n2);
        denom_hi = hi_word;
        denom_lo = low_word;

        ten_syncdsyncrx_cfg(module_id_line,
                            pdevcb->oduflex_cb.client_slice,
                            num_hi, num_lo, denom_hi, denom_lo,
                            0,0,0,0,0,0,0);

        /* Client TX */
        ten_syncdsync_config_1_to_1(module_id_client,
                                    slice_client,
                                    ((module_id_line & 1) * 4) + pdevcb->oduflex_cb.client_slice,
                                    CS_TX, 
                                    k_divider);

        ten_syncdsynctx_gmp_enbl_t41(module_id_line, slice_line, 1);
      }
      break;
    
    default:
      CS_PRINT("%s() SyncDsync not provisioned and left in reset\n", func);
      break;
      
  }

RTN_EXIT:
  CS_PRINT("%s() Exit\n", func);
  return (rtn);
}

/****************************************************************/
/* $rtn_hdr_start HIGH LEVEL CONFIG SYNCDSYNC CONFIG V2         */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : HIGH LEVEL CONFIG                               */
/* CHIP       : Tenabo                                          */
cs_status ten_hl_syncdsync_datapath_config_t41_v2(cs_uint16 module_id_line,
                                                  cs_uint8  slice_line, 
                                                  cs_uint16 module_id_client,
                                                  cs_uint8  slice_client,
                                                  cs_uint8 fec_line,
                                                  cs_uint8 fec_client,
                                                  cs_uint8  mode,
                                                  cs_uint16 method,
                                                  cs_uint8  k_divider_line,
                                                  cs_uint8  k_divider_client,
                                                  cs_uint8  map_odtu,
                                                  cs_uint8  map_oxuv,
                                                  cs_uint8  gmp_timeslots)
/* INPUTS     : o Line Module Id                                */
/*              o Line Slice                                    */
/*              o Client Module Id                              */
/*              o Client Slice                                  */
/*              o FEC Type Line                                 */
/*              o FEC Type Client                               */
/*              o Mode                                          */
/*              o Method                                        */
/*              o k Divider Line                                */
/*              o k Divider Client                              */
/*              o Mapping Method Line                           */
/*              o Mapping Method Client                         */
/*              o Timeslots                                     */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* Configures line and client syncdsync blocks based on mode and*/
/* method. _v2 splits k_divider into line and client parameters.*/
/*                                                              */
/* [module_id_line] parameter specifies line's module ID        */
/* 16 devices can be registered and module bit indicates line   */
/* or client side of the registered device. The registered device*/
/* is identified by the dev_id bits specified below             */
/*   Bits 11:8 - dev_id, Bits 7:1 - don't care, Bit 0 - module  */
/*                                                              */
/* [slice_line] parameter specifies line's slice:               */
/*   TEN_SLICE0 = 0                                             */
/*   TEN_SLICE1 = 1                                             */
/*   TEN_SLICE2 = 2                                             */
/*   TEN_SLICE3 = 3                                             */
/*                                                              */
/* [module_id_client] parameter specifies client's module ID    */
/* 16 devices can be registered and module bit indicates line   */
/* or client side of the registered device. The registered device*/ 
/* is identified by the dev_id bits specified below             */
/*   Bits 11:8 - dev_id, Bits 7:1 - don't care, Bit 0 - module  */
/*                                                              */
/* [slice_client] parameter specifies client's slice:           */
/*   TEN_SLICE0 = 0                                             */
/*   TEN_SLICE1 = 1                                             */
/*   TEN_SLICE2 = 2                                             */
/*   TEN_SLICE3 = 3                                             */
/*                                                              */
/* [fec_line] parameter defines the line fec type:              */
/* [fec_client] parameter defines the line fec type:            */
/*     TEN_FEC_MODE_NOFEC = 15, or                              */
/*     Any other FEC% as per ten_fec_ovhd_t = 0 -14             */
/*                                                              */
/* [mode] specifies one of the three modes                      */
/*   TEN_40G_TRANSPONDER  = 0 (40G to 40G)                      */
/*   TEN_40G_MUXPONDER    = 1 (10G to 40G)                      */
/*   TEN_10G_TRANSPONDER  = 2 (10G to 10G)                      */
/*                                                              */
/* [method] specifies how syncdysnc blocks can be               */
/* configured for 40G applications                              */
/*   TEN_1TO1_ASYNC_2LEVEL = 0                                  */
/*       Client -  1:1                                          */
/*       Line   -  Async 2 level mapping                        */
/*   TEN_SYNC_ASYNC_1LEVEL = 1                                  */
/*       Client -  Sync  1 level mapping                        */
/*       Line   -  Async 1 level mapping                        */
/*   TEN_1TO1_ASYNC_1LEVEL = 2                                  */
/*       Client -  1:1                                          */
/*       Line   -  Async 1 level mapping                        */
/*   TEN_BOTH_1TO1         = 3                                  */
/*       Client -  1:1                                          */
/*       Line   -  1:1                                          */
/*                                                              */
/* [k_divider] specifies the value of constant 'k'              */
/*   Async : 16 - 64                                            */
/*   Sync  : 16 - 255                                           */
/*                                                              */
/* The [map_odtu] parameter specifies the mapping method        */
/* The [map_oxuv] parameter specifies the mapping method        */
/*  TEN_MAP_BMP,           = 0                                  */
/*  TEN_MAP_AMP,           = 1                                  */
/*  TEN_MAP_AMP_DT,        = 2                                  */
/*  TEN_MAP_AMP_PROP,      = 3                                  */
/*  TEN_MAP_AMP_PROP_DT,   = 4                                  */
/*  TEN_MAP_GMP_LO,        = 5                                  */
/*  TEN_MAP_GMP_HO,        = 6                                  */
/*  TEN_MAP_GMP_HO_DT,     = 7                                  */
/*                                                              */
/* The [gmp_timeslots] parameter specifies number of timeslots. */
/* Applicable to GMP_HO only if [map_proc] = TEN_MAP_GMP_HO     */
/* Bandwidth is always 1.25G per timeslot                       */
/*   1 - 8                                                      */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  cs_status rtn = CS_OK;
  cs_uint16 dev_id;
  ten_dev_cb_t *pdevcb;

  cs_uint8 i=0;
  cs_uint32 n1, n2, m1, m2;
  cs_uint32 num_hi, num_lo, denom_hi, denom_lo, ac1_hi=0, ac1_lo=0, ac2_hi=0, ac2_lo=0, ad1=0, ad2=0;
  cs_uint8 cfg=0, cfgpd0=0, jc_thresh=0;
  cs_int16 num_just_odu3, num_just_client;
  cs_uint16 num_pjo_odu3, num_pjo_odu2, num_pjo_client;
  cs_int16 num_just_oxu3_client;          /* Bugzilla 26729 */
  cs_uint16 num_pjo_oxu3_client;          /* Bugzilla 26729 */
  cs_int16 num_just_odtu, num_just_oxuv;
  cs_uint16 num_pjo_odtu, num_pjo_oxuv;
  cs_uint8 max_pjo;
  double Cm=0, Cn=0, hysteresis=0;
  cs_uint8 map_oxuv_simplified=0;
  cs_char8 *func = "ten_hl_syncdsync_datapath_config_t41";  
  cs_uint8 k_divider = k_divider_client; /* Default single k for old configs */

  CS_PRINT("%s() \n", func);
  CS_PRINT("    line %s\n", ten_module_strings[module_id_line&1]);
  CS_PRINT("    slice_line=%d\n", slice_line);
  CS_PRINT("    client %s\n", ten_module_strings[module_id_client&1]);
  CS_PRINT("    slice_client=%d\n", slice_client);
  CS_PRINT("    line fec=%s\n", ten_fec_ovhd_strings[fec_line]);
  CS_PRINT("    client fec=%s\n", ten_fec_ovhd_strings[fec_client]);
  CS_PRINT("    %s\n", ten_traffic_mode_strings[mode]);
  CS_PRINT("    %s\n", ten_method_strings[method]);
  CS_PRINT("    k_divider_line=%d\n", k_divider_line);
  CS_PRINT("    k_divider_client=%d\n", k_divider_client);
            
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
  CS_PRINT("    gmp_timeslots=%d\n", gmp_timeslots);

  dev_id = TEN_MOD_ID_TO_DEV_ID(module_id_line);
  pdevcb = TEN_DEV_ID_TO_DEVCB_PTR(dev_id);
  
  CS_PRINT("    line_rate=%f\n", pdevcb->syncdsync_thread_cb[slice_client].line_rate);
  CS_PRINT("    xcon_client_rate=%f\n", pdevcb->syncdsync_thread_cb[slice_client].xcon_client_rate);
  CS_PRINT("    client_rate=%f\n", pdevcb->syncdsync_thread_cb[slice_client].client_rate);

  CS_PRINT("    num_just_oxu3=%d\n", pdevcb->syncdsync_thread_cb[slice_client].num_just_oxu3);
  CS_PRINT("    num_pjo_odu3=%d\n", pdevcb->syncdsync_thread_cb[slice_client].num_pjo_oxu3);

  CS_PRINT("    num_just_oxu2=%d\n", pdevcb->syncdsync_thread_cb[slice_client].num_just_oxu2);
  CS_PRINT("    num_pjo_oxu2=%d\n", pdevcb->syncdsync_thread_cb[slice_client].num_pjo_oxu2);

  CS_PRINT("    num_just_oxu3_client=%d\n", pdevcb->syncdsync_thread_cb[slice_client].num_just_oxu3_client);
  CS_PRINT("    num_pjo_oxu3_client=%d\n", pdevcb->syncdsync_thread_cb[slice_client].num_pjo_oxu3_client);

  CS_PRINT("    transcode_num=%d\n", pdevcb->syncdsync_thread_cb[slice_client].transcode_num);
  CS_PRINT("    transcode_denom=%d\n", pdevcb->syncdsync_thread_cb[slice_client].transcode_denom);


  switch(mode) {
    case TEN_40G_TRANSPONDER:
    case TEN_40G_WIRE:  /* Bugzilla 24645/28501 */
      num_just_odu3   = pdevcb->syncdsync_thread_cb[slice_client].num_just_oxu3;
      num_pjo_odu3    = pdevcb->syncdsync_thread_cb[slice_client].num_pjo_oxu3;

      num_just_oxu3_client  = pdevcb->syncdsync_thread_cb[slice_client].num_just_oxu3_client;   /* Bugzilla 26729 */
      num_pjo_oxu3_client   = pdevcb->syncdsync_thread_cb[slice_client].num_pjo_oxu3_client;    /* Bugzilla 26729 */

      num_just_client  = pdevcb->syncdsync_thread_cb[slice_client].num_just_oxu2;
      num_pjo_client   = pdevcb->syncdsync_thread_cb[slice_client].num_pjo_oxu2; 

      if(map_oxuv == TEN_MAP_GMP_LO) {
        /* Bugzilla 28006 Start */
        /* Client side */
        if (map_odtu == TEN_MAP_AMP_PROP) {
          /* Async to Async 1 Level */
          /* Client Side is GMP. Line side is AMP Proprietary (Dual Muxponder) */
#if 0
          //Cm = ((2.0*pdevcb->syncdsync_thread_cb[slice_client].P_line * pdevcb->syncdsync_thread_cb[slice_client].client_rate) /
          //  pdevcb->syncdsync_thread_cb[slice_client].line_rate) * ((cs_float)pdevcb->syncdsync_thread_cb[slice_client].transcode_denom /
          //  (cs_float)pdevcb->syncdsync_thread_cb[slice_client].transcode_num);
          
          //Cm = ((2.0*pdevcb->syncdsync_thread_cb[slice_client].P_client * pdevcb->syncdsync_thread_cb[slice_client].client_rate) /
          //  pdevcb->syncdsync_thread_cb[slice_client].xcon_client_rate) * ((cs_float)pdevcb->syncdsync_thread_cb[slice_client].transcode_denom /
          //  (cs_float)pdevcb->syncdsync_thread_cb[slice_client].transcode_num);
#endif
          Cm = ((2.0*pdevcb->syncdsync_thread_cb[slice_client].P_client * pdevcb->syncdsync_thread_cb[slice_client].xcon_client_rate) /
            pdevcb->syncdsync_thread_cb[slice_client].client_rate) * ((cs_float)pdevcb->syncdsync_thread_cb[slice_client].transcode_denom /
            (cs_float)pdevcb->syncdsync_thread_cb[slice_client].transcode_num);

          Cn = _round(Cm*(double)gmp_timeslots);
          pdevcb->syncdsync_thread_cb[slice_client].cn_bytes_n40g = Cn;  
           
          /* Client Side */
          /*n2 = (cs_uint32)(pdevcb->syncdsync_thread_cb[slice_client].P_line*16*4);*/
          n1 = (cs_uint32)(pdevcb->syncdsync_thread_cb[slice_client].P_client*16*4);
          m1 = (cs_uint32)Cn;
           
          /* Line Side */
          n2 = pdevcb->syncdsync_thread_cb[slice_client].P_line*16*4;
          m2 = 238*16*4 - num_just_odu3;
           
          /*for(i=0;i<4;i++) {*/
            ten_syncdsync_trans_async_async_1level_config (module_id_line, slice_line, 
                                                           module_id_client, slice_client,
                                                           k_divider, n1, m1, n2, m2,
                                                           /*mode, num_pjo_oxuv, num_pjo_odtu,*/
                                                           TEN_OXU3_MONO_ONE_LEVEL, num_pjo_oxu3_client, num_pjo_odu3,
                                                           TEN_SLICE_40G);
          /*}*/                                                 
         
          ten_syncdsynctx_gmp_enbl_t41(module_id_client, slice_client, 1);
          ten_syncdsynctx_gmp_enbl_t41(module_id_client, 3, 1);  /* Bugzilla 28200 */
        
        } else {
          /* Bugzilla 28006 End */
          Cm = ((2.0*pdevcb->syncdsync_thread_cb[slice_client].P_line*pdevcb->syncdsync_thread_cb[slice_client].client_rate) /
            pdevcb->syncdsync_thread_cb[slice_client].line_rate) * ((cs_float)pdevcb->syncdsync_thread_cb[slice_client].transcode_denom /
            (cs_float)pdevcb->syncdsync_thread_cb[slice_client].transcode_num);

          Cn = _round(Cm*(double)gmp_timeslots);
          pdevcb->syncdsync_thread_cb[slice_client].cn_bytes_n40g = Cn;  

          if(method == TEN_1TO1_ASYNC_1LEVEL) {
            n1 = (cs_uint32)(pdevcb->syncdsync_thread_cb[slice_client].P_line*16*4);
            m1 = (cs_uint32)Cn;
            n2 = 1;
            m2 = 1;

            ten_syncdsync_trans_1to1_async_config(module_id_line, slice_line, 
                                                  module_id_client, slice_client,
                                                  k_divider, n1, m1, 
                                                  TEN_OXU3_MONO_ONE_LEVEL, num_pjo_odu3, 
                                                  TEN_SLICE_40G);    /* Bugzilla 26729 */
          }
          else if(method == TEN_1TO1_ASYNC_1TO1_1LEVEL) {
            n1 = (cs_uint32)(pdevcb->syncdsync_thread_cb[slice_client].P_line*16*4);
            m1 = (cs_uint32)Cn;
            n2 = 1;
            m2 = 1;

            ten_syncdsync_trans_1to1_async_1to1_config(module_id_line, slice_line, 
                                                       module_id_client, slice_client,
                                                       k_divider, n1, m1, 
                                                       TEN_OXU3_MONO_ONE_LEVEL, num_pjo_odu3,
                                                       TEN_SLICE_40G);    /* Bugzilla 26729 */
          }
          else if(method == TEN_SYNC_ASYNC_1LEVEL) {
            n1 = pdevcb->syncdsync_thread_cb[slice_client].P_client*16*4;
            m1 = 239*16*4;
            n2 = (cs_uint32)(pdevcb->syncdsync_thread_cb[slice_client].P_line*16*4);
            m2 = (cs_uint32)Cn;

            ten_syncdsync_trans_sync_async_config(module_id_line, slice_line, 
                                                  module_id_client, slice_client,
                                                  k_divider, n1, m1, n2, m2,
                                                  TEN_OXU3_MONO_ONE_LEVEL, num_pjo_odu3,
                                                  TEN_SLICE_40G);    /* Bugzilla 26729 */
          }
          else if(method == TEN_BOTH_1TO1) {
              ten_syncdsync_1_to_1_config(module_id_line, slice_line, 
                                          module_id_client, slice_client,
                                          k_divider);
          }
          else {
            CS_PRINT("%s()  Method not supported!\n", func);
            rtn = CS_ERROR;
            goto RTN_EXIT;
          }
          ten_syncdsynctx_gmp_enbl_t41(module_id_line, slice_line, 1);
          ten_syncdsynctx_gmp_enbl_t41(module_id_line, 3, 1);  /* Bugzilla 28200 */
        }
        /*ten_syncdsynctx_gmp_enbl_t41(module_id_line, slice_line, 1); */
        /*ten_syncdsynctx_gmp_enbl_t41(module_id_line, 3, 1);*/  /* Bugzilla 28200 */
      }
      else {
        if(method == TEN_ASYNC_ASYNCX4_1LEVEL) {
          n2 = (cs_uint32)(pdevcb->syncdsync_thread_cb[slice_client].P_line*16*4);
          m2 = (cs_uint32)Cn;
          n1 = pdevcb->syncdsync_thread_cb[slice_client].P_line*16*4;
          m1 = 238*16*4 - num_just_odu3;

          ten_syncdsync_trans_async_asyncx4_config(module_id_line, slice_line, 
                                                   module_id_client, slice_client,
                                                   k_divider,
                                                   n1, m1, n2, m2,
                                                   mode, num_pjo_client, num_pjo_odu3,
                                                   TEN_SLICE_40G);    /* Bugzilla 26729 */

          ten_syncdsynctx_gmp_enbl_t41(module_id_line, slice_line, 1);
          ten_syncdsynctx_gmp_enbl_t41(module_id_line, 3, 1);   /* Bugzilla 28200 */
        }
        /* Bugzilla 29481 Start */
        else if ((map_oxuv == TEN_MAP_BMP) && (map_odtu == TEN_MAP_GMP_LO)) {   /* Bugzilla 34253 */
           if (method == TEN_SYNC_ASYNC_1LEVEL) {
             /* High Order Mapping is GMP */
             Cm = ((2.0*pdevcb->syncdsync_thread_cb[slice_client].P_line*pdevcb->syncdsync_thread_cb[slice_client].xcon_client_rate) /
             /*Cm = ((2.0*pdevcb->syncdsync_thread_cb[slice_client].P_line*pdevcb->syncdsync_thread_cb[slice_client].client_rate) / */
             pdevcb->syncdsync_thread_cb[slice_client].line_rate);

             Cn = _round(Cm*(double)gmp_timeslots);
             pdevcb->syncdsync_thread_cb[slice_client].cn_bytes_n40g = Cn;  


             CS_PRINT("    Cm           = %f\n", Cm);
             CS_PRINT("    Cn           = %f\n", Cn);

             /* Line Side */
             /*n2 = (cs_uint32)(pdevcb->syncdsync_thread_cb[slice_client].P_line*(32.0*16.0*4.0)/4.0);*/
             n2 = (cs_uint32)(pdevcb->syncdsync_thread_cb[slice_client].P_line*16*4);
             m2 = (cs_uint32)Cn;

             /* Client Side */
             n1 = pdevcb->syncdsync_thread_cb[slice_client].P_client*16*4;
             m1 = 239*16*4;     /* m1 = pdevcb->syncdsync_thread_cb[slice_client].Q_client*16*4 */
             /*m1 = 238*16*4;*/     /* m1 = pdevcb->syncdsync_thread_cb[slice_client].Q_client*16*4 */


             ten_syncdsync_trans_sync_async_config(module_id_line, slice_line, 
                                                   module_id_client, slice_client,
                                                   k_divider, n1, m1, n2, m2,
                                                   TEN_OXU3_MONO_ONE_LEVEL, num_pjo_odu3,
                                                   TEN_SLICE_40G);

             ten_syncdsynctx_gmp_enbl_t41(module_id_line, slice_client, 1);
             ten_syncdsynctx_gmp_enbl_t41(module_id_line, 3, 1);
           }
        }
        /* Bugzilla 29481 End */
        else {
          /* ten_hl_syncdsync_threadsafe_datapath_config only understands sync and */
          /* async so we need to translate map_oxuv to either sync or async        */
          /* Bugzilla 27167 Start */
          if (map_odtu == TEN_MAP_DONT_CARE) {
            /* map_odtu is not specified, so can only use map_oxuv */
            if (map_oxuv == TEN_MAP_BMP) {
              map_oxuv_simplified = 1;
            }
            else {
              map_oxuv_simplified = 0;
            }
          } else {
            if ((map_oxuv == TEN_MAP_BMP) && (map_odtu == TEN_MAP_BMP)) {
              map_oxuv_simplified = 1;
            }
            else {
              map_oxuv_simplified = 0;
            }
          }
          /* Bugzilla 27167 End */
          ten_hl_syncdsync_threadsafe_datapath_config(module_id_line, slice_line, 
                                                      module_id_client, slice_client,
                                                      mode, map_oxuv_simplified, method,
                                                      k_divider, fec_line, fec_client);
        }
      }
      break;
  
    case TEN_40G_MUXPONDER:
      num_just_odtu = pdevcb->syncdsync_thread_cb[slice_client].num_just_oxu3;
      num_pjo_odtu  = pdevcb->syncdsync_thread_cb[slice_client].num_pjo_oxu3;
      num_just_oxuv = pdevcb->syncdsync_thread_cb[slice_client].num_just_oxu2;
      num_pjo_oxuv  = pdevcb->syncdsync_thread_cb[slice_client].num_pjo_oxu2;

      if((map_odtu == TEN_MAP_GMP_HO_DT) || (map_odtu == TEN_MAP_GMP_HO)) {
        /* High Order Mapping into odtu23 or odtu3.ts is GMP */
        Cm = (2048.0*pdevcb->syncdsync_thread_cb[slice_client].P_line*pdevcb->syncdsync_thread_cb[slice_client].xcon_client_rate) /
                   ((double)gmp_timeslots*pdevcb->syncdsync_thread_cb[slice_client].line_rate);
        
        Cn = _round(Cm*(double)gmp_timeslots);
        pdevcb->syncdsync_thread_cb[slice_client].cn_bytes_n40g = Cn;  /*Bugzilla 26308*/

        /* Line side  */
        n1 = (cs_uint32)(pdevcb->syncdsync_thread_cb[slice_client].P_line*(32.0*16.0*4.0)/4.0);
        m1 = (cs_uint32)Cn;
        m1 |=  gmp_timeslots << 24;   /* Bugzilla 31322 */

        /* Deterministic Hysteresis */
        if(map_odtu == TEN_MAP_GMP_HO_DT) {
          hysteresis = (pdevcb->syncdsync_thread_cb[slice_client].P_line*128.0)/(_round(((Cm*gmp_timeslots))) - 
                        (4*pdevcb->syncdsync_thread_cb[slice_client].xcon_client_rate*n1/pdevcb->syncdsync_thread_cb[slice_client].line_rate));
          pdevcb->syncdsync_thread_cb[slice_client].hysteresis = (cs_uint32)hysteresis;

          /*ten_calc_hyst(dev_id);*/  /* Bugzilla 28237 */
        }

        if((map_oxuv == TEN_MAP_AMP) || (map_oxuv ==TEN_MAP_AMP_PROP)) {
          /* Low Order Mapping of client into odu2v is AMP or AMP_PROP */
          if (method == TEN_1TO1_ASYNC_2LEVEL) {
            n2 = 239*16*4;
            m2 = (238*16*4-num_just_oxuv);

            ten_syncdsync_mux_1to1_async_2level_config(module_id_line, slice_line, 
                                                       module_id_client, slice_client,
                                                       k_divider, n1, n2, m1, m2, 
                                                       num_pjo_oxuv, num_pjo_odtu);
          }
          else {
            CS_PRINT("%s()  Method not supported!\n", func);
            rtn = CS_ERROR;
            goto RTN_EXIT;
          }
        }
        else if(map_oxuv == TEN_MAP_BMP) {
          /* Low Order Mapping of Client into odu2v is BMP */
          if (method == TEN_1TO1_ASYNC_2LEVEL) {
            /* Cleint sync mapping into Mux ODU2v */
            n2 = 239*16*4;
            m2 = (238*16*4-num_just_oxuv);

            ten_syncdsync_mux_1to1_async_2level_config(module_id_line, slice_line, 
                                                       module_id_client, slice_client,
                                                       k_divider, n1, n2, m1, m2, 
                                                       num_pjo_oxuv, num_pjo_odtu);
          }
          else if (method == TEN_SYNC_ASYNC_1LEVEL) {
            n2 = pdevcb->syncdsync_thread_cb[slice_client].P_client*16*4;
            m2 = 239*16*4;

            ten_syncdsync_mux_sync_async_1level_config(module_id_line, slice_line, 
                                                       module_id_client, slice_client,
                                                       fec_client, k_divider, n1, n2, m1, m2, 
                                                       num_pjo_oxuv, num_pjo_odtu);
          }
          else if (method == TEN_BOTH_1TO1) {
            ten_syncdsync_1_to_1_config(module_id_line, slice_line, 
                                        module_id_client, slice_client,
                                        k_divider);
          }
        }
        else if(map_oxuv == TEN_MAP_GMP_LO) {
          /* Client side mapping is GMP_LO */
          if (method == TEN_1TO1_ASYNC_2LEVEL) {          
            /* Client */
            /* Bugzilla 38779 Start - split k_divider for subrate muxponders */
            Cm = (8.0*239.0*pdevcb->syncdsync_thread_cb[slice_client].client_rate*k_divider_line) /
                       (pdevcb->syncdsync_thread_cb[slice_client].xcon_client_rate*k_divider_client);

            Cn = (cs_uint32)(Cm*(double)gmp_timeslots);
            pdevcb->syncdsync_thread_cb[slice_client].cn_bytes_n10g = Cn;  /*Bugzilla 26308*/

            n2 = (cs_uint32)(239.0*16.0*4.0);
            m2 = (cs_uint32)Cn;

            ten_syncdsync_mux_1to1_async_2level_config_v2(module_id_line, slice_line, 
                                                          module_id_client, slice_client,
                                                          k_divider_line, k_divider_client, n1, n2, m1, m2, 
                                                          num_pjo_oxuv, num_pjo_odtu);
            /* Bugzilla 38779 End */
          }
          else {
            CS_PRINT("%s()  Method not supported!\n", func);
            rtn = CS_ERROR;
            goto RTN_EXIT;
          }
        }
        else if (pdevcb->oduflex_cb.enbl) {
          if (method == TEN_1TO1_ASYNC_2LEVEL) {
            n2 = 238*16*4;
            m2 = 239*16*4;

            ten_syncdsync_mux_1to1_async_2level_config(module_id_line, slice_line, 
                                                       module_id_client, slice_client,
                                                       k_divider, n1, n2, m1, m2, 
                                                       num_pjo_oxuv, num_pjo_odtu);
          }
          else {
            CS_PRINT("%s()  Method not supported!\n", func);
            rtn = CS_ERROR;
            goto RTN_EXIT;
          }
        }
/* Bugzilla 29100 Debug Start */        
        else if(map_oxuv == TEN_MAP_GMP_HO) {
          if (method == TEN_ASYNC_ASYNC_1LEVEL) {
            for(i=0;i<4;i++) {
              Cm = (2048.0*pdevcb->syncdsync_thread_cb[slice_client].P_line*pdevcb->syncdsync_thread_cb[slice_client].xcon_client_rate) /
                         ((double)gmp_timeslots*pdevcb->syncdsync_thread_cb[slice_client].client_rate);
              
              Cn = _round(Cm*(double)gmp_timeslots);
              pdevcb->syncdsync_thread_cb[i].cn_bytes_n10g = Cn;  /* Bugzilla 29100 */

              /* Line Side */
              n1 = (cs_uint32)(pdevcb->syncdsync_thread_cb[slice_client].P_line*(32.0*16.0*4.0)/4.0);
              m1 = (cs_uint32)Cn;
              m1 |=  gmp_timeslots << 24;   /* Bugzilla 31322 */

              /* Client Side*/
              n2 = (cs_uint32)(pdevcb->syncdsync_thread_cb[slice_client].P_line*(32.0*16.0*4.0)/4.0);
              m2 = (cs_uint32)Cn;

              pdevcb->syncdsync_thread_cb[i].transcode_num = pdevcb->syncdsync_thread_cb[slice_client].transcode_num;
              pdevcb->syncdsync_thread_cb[i].transcode_denom = pdevcb->syncdsync_thread_cb[slice_client].transcode_denom;

              ten_syncdsync_mux_async_async_1level_config(module_id_line, i, 
                                                          module_id_client, i,
                                                          k_divider, n1, n2, m1, m2,
                                                          num_pjo_oxuv, num_pjo_odtu);

              ten_syncdsynctx_gmp_enbl_t41(module_id_client, i, 1);
            }
          }
        }
/* Bugzilla 29100 Debug End */        
        ten_syncdsynctx_gmp_enbl_t41(module_id_line, slice_line, 1);
      }
      else if((map_odtu == TEN_MAP_AMP_PROP) || (map_odtu == TEN_MAP_AMP)) {  /* Bugzilla 26787 */
        /* Mapping into odtu23 or odtu3.ts */
        if (map_oxuv == TEN_MAP_GMP_HO) {
          /* Mapping of client into odu2v */
          if (method == TEN_ASYNC_ASYNC_1LEVEL) {
            /* Dual Muxponder */
            for(i=0;i<4;i++) {
              Cm = (2048.0*pdevcb->syncdsync_thread_cb[slice_client].P_line*pdevcb->syncdsync_thread_cb[slice_client].xcon_client_rate) /
                         ((double)gmp_timeslots*pdevcb->syncdsync_thread_cb[slice_client].client_rate);     /*Bugzilla 26787 */
              
              Cn = _round(Cm*(double)gmp_timeslots);
              pdevcb->syncdsync_thread_cb[i].cn_bytes_n10g = Cn;  /* Bugzilla 29100 */

              /* Bugzilla 26787 Start */
              /* Line Side */
              n1 = pdevcb->syncdsync_thread_cb[slice_client].P_client*16*4*4;
              m1 = 238*16*4*4-num_just_odtu;

              /* Client Side */
              n2 = (cs_uint32)(pdevcb->syncdsync_thread_cb[slice_client].P_line*(32.0*16.0*4.0)/4.0);
              m2 = (cs_uint32)Cn;
              m2 |=  gmp_timeslots << 24;   /* Bugzilla 31322 */
              /* Bugzilla 26787 End */

              pdevcb->syncdsync_thread_cb[i].transcode_num = pdevcb->syncdsync_thread_cb[slice_client].transcode_num;
              pdevcb->syncdsync_thread_cb[i].transcode_denom = pdevcb->syncdsync_thread_cb[slice_client].transcode_denom;

              ten_syncdsync_mux_async_async_1level_config(module_id_line, i, 
                                                          module_id_client, i,
                                                          k_divider, n1, n2, m1, m2,     /* Bugzilla 26785 */
                                                          num_pjo_oxuv, num_pjo_odtu);

              ten_syncdsynctx_gmp_enbl_t41(module_id_client, i, 1);  /* Bugzilla 29100 */
            }
          }
          else {
            CS_PRINT("%s()  Method not supported!\n", func);
            rtn = CS_ERROR;
            goto RTN_EXIT;
          }

          ten_syncdsynctx_gmp_enbl_t41(module_id_client, slice_client, 1);
        }
        /* Bugzilla 26787 Start */
        else if ((map_oxuv == TEN_MAP_AMP_PROP) || (map_oxuv == TEN_MAP_AMP)) {
          if (method == TEN_ASYNC_ASYNC_1LEVEL) {
            for(i=0;i<4;i++) {
              n1 = pdevcb->syncdsync_thread_cb[slice_client].P_line*16*4*4;
              m1 = 238*16*4*4-num_just_odtu;

              n2 = pdevcb->syncdsync_thread_cb[slice_client].P_client*16*4*4;
              m2 = 238*16*4*4-num_just_oxuv;

              pdevcb->syncdsync_thread_cb[i].transcode_num =
                   pdevcb->syncdsync_thread_cb[slice_client].transcode_num;
              pdevcb->syncdsync_thread_cb[i].transcode_denom =
                   pdevcb->syncdsync_thread_cb[slice_client].transcode_denom;

              ten_syncdsync_mux_async_async_1level_config(module_id_line, i, 
                                                          module_id_client, i,
                                                          k_divider, n1, n2, m1, m2,    /* Bugzilla 26785 */
                                                          num_pjo_oxuv, num_pjo_odtu);
            }
          }
        }
        else { /* Rest of the cases are common to T40/T41 */
          ten_hl_syncdsync_threadsafe_datapath_config(module_id_line, slice_line, 
                                                      module_id_client, slice_client,
                                                      mode, map_oxuv, method,
                                                      k_divider, fec_line, fec_client);
        }
        /* Bugzilla 26787 End */
      }
      else if (map_oxuv == TEN_MAP_GMP_LO) {
        /* Non OTN client being mapped into an OTN */
        Cm = (8.0*239.0*pdevcb->syncdsync_thread_cb[slice_client].client_rate*k_divider_line) /   /* Bugzilla 39003 */
                   (pdevcb->syncdsync_thread_cb[slice_client].xcon_client_rate*k_divider_client); /* Bugzilla 39003 */

        Cn = (cs_uint32)(Cm*(double)gmp_timeslots);
        pdevcb->syncdsync_thread_cb[slice_client].cn_bytes_n10g = Cn;  /*Bugzilla 26308*/

        n2 = (cs_uint32)239.0*16.0*4.0;
        m2 = (cs_uint32)Cn;

        if((map_odtu == TEN_MAP_AMP_DT) || (map_odtu ==TEN_MAP_AMP_PROP_DT)) {
          if (method == TEN_1TO1_ASYNC_2LEVEL) {
            n1 = pdevcb->syncdsync_thread_cb[slice_client].P_line*16*4*4;
            m1 = (238*16*4*4-num_just_odtu);
            m1 |=  gmp_timeslots << 24;

            ten_syncdsync_mux_1to1_async_2level_config_v2(module_id_line, slice_line, 
                                                          module_id_client, slice_client,
                                                          k_divider_line, k_divider_client, n1, n2, m1, m2, /* Bugzilla 39003 */
                                                          num_pjo_oxuv, num_pjo_odtu);

            /* Deterministic Hysteresis */
            ten_calc_hyst_t41(dev_id, slice_line, map_odtu); /* Bugzilla 39003 */
          }
          else {
            CS_PRINT("%s()  Method not supported!\n", func);
            rtn = CS_ERROR;
            goto RTN_EXIT;
          }
        }
        ten_syncdsynctx_gmp_enbl_t41(module_id_line, slice_line, 1);
      }
      else { /* Rest of the cases are common to T40/T41 */
        ten_hl_syncdsync_threadsafe_datapath_config(module_id_line, slice_line, 
                                                    module_id_client, slice_client,
                                                    mode, map_oxuv, method,
                                                    k_divider, fec_line, fec_client);
      }
      break;

    case TEN_10G_TRANSPONDER:
    case TEN_10G_WIRE:  /* Bugzilla 24645/28501 */
      if((map_oxuv == TEN_MAP_AMP) || (map_oxuv ==TEN_MAP_AMP_PROP) || (map_oxuv == TEN_MAP_BMP)) {
        ten_hl_syncdsync_threadsafe_datapath_config_v2(module_id_line, slice_line, 
                                                    module_id_client, slice_client,
                                                    mode, map_oxuv, method,
                                                    /* Bugzilla 26608 Start */
                                                    k_divider_line, k_divider_client, fec_line, fec_client);
                                                    /* Bugzilla 26608 End */
      }
      else if(map_oxuv == TEN_MAP_GMP_LO) {
        num_pjo_odu2    = pdevcb->syncdsync_thread_cb[slice_client].num_pjo_oxu2;

        Cm = (8.0*pdevcb->syncdsync_thread_cb[slice_client].P_line*
              pdevcb->syncdsync_thread_cb[slice_client].client_rate*k_divider_line) /
             (pdevcb->syncdsync_thread_cb[slice_client].line_rate*k_divider_client);

        Cn = _round(Cm*(double)gmp_timeslots);
        pdevcb->syncdsync_thread_cb[slice_line].cn_bytes_n10g = Cn;  /*Bugzilla 26308*/ /*Bugzilla 36604*/

        n1 = (cs_uint32)(pdevcb->syncdsync_thread_cb[slice_client].P_line*(16.0*4.0));
        m1 = (cs_uint32)Cn;

        ten_syncdsync_trans_1to1_async_config_v2(module_id_line, slice_line, 
                                                 module_id_client, slice_client,
                                                 k_divider_line, k_divider_client, n1, m1, 0, num_pjo_odu2,
                                                 TEN_SLICE_10G);    /* Bugzilla 26729 */


        ten_syncdsynctx_gmp_enbl_t41(module_id_line, slice_line, 1);
      }
      else if(map_oxuv == TEN_MAP_GMP_HO) {
          num_pjo_odu2    = pdevcb->syncdsync_thread_cb[slice_client].num_pjo_oxu2;

          /* Client RX */
          n1 = 238*16*4*pdevcb->syncdsync_thread_cb[slice_client].transcode_num;
          m1 = 239*16*4*pdevcb->syncdsync_thread_cb[slice_client].transcode_denom;
          n2 = 1;
          m2 = 1;

          /*num    = m1 * m2; */
          long_multiply(m1, m2);
          num_hi = hi_word;
          num_lo = low_word;

          /* denom  = n1 * n2 * k_divider; */
          long_multiply(n1*k_divider, n2);
          denom_hi = hi_word;
          denom_lo = low_word;

          ten_syncdsyncrx_cfg(module_id_client,
                              slice_client,
                              num_hi, num_lo, denom_hi, denom_lo,
                              0,0,0,0,0,0,0);

          /* ODUFlex Line TX */
          ten_syncdsync_config_1_to_1(module_id_line,
                                      pdevcb->oduflex_cb.line_slice,
                                      ((module_id_client & 1) * 4) + slice_client,
                                      CS_TX, 
                                      k_divider);

          /* ODUFlex Line RX */
          ten_syncdsync_config_1_to_1(module_id_line,
                                      pdevcb->oduflex_cb.line_slice,
                                      0,
                                      CS_RX, 
                                      k_divider);

          /* Line TX */
          /* xcon_client_rate = ODUflex_rate */
          Cm = (512.0*pdevcb->syncdsync_thread_cb[slice_client].P_line*pdevcb->syncdsync_thread_cb[slice_client].xcon_client_rate) /
                   ((double)gmp_timeslots*pdevcb->syncdsync_thread_cb[slice_client].line_rate);

          Cn = _round(Cm*(double)gmp_timeslots);
          pdevcb->syncdsync_thread_cb[slice_line].cn_bytes_n10g = Cn; /*Bugzilla 26308*/ /*Bugzilla 36604*/

          n1 = (cs_uint32)(pdevcb->syncdsync_thread_cb[slice_client].P_line*(8.0*16.0*4.0));
          m1 = (cs_uint32)Cn;
          n2 = 1;
          m2 = 1;

          /*num    = m1 * m2 * trans_num; */
          long_multiply(m1, m2*pdevcb->syncdsync_thread_cb[slice_client].transcode_num);
          num_hi = hi_word;
          num_lo = low_word;

          /* denom  = n1 * n2 * k_divider * trans_denom; */
          long_multiply(n1*k_divider, n2*pdevcb->syncdsync_thread_cb[slice_client].transcode_denom);
          denom_hi = hi_word;
          denom_lo = low_word;

          /* ac1 = n1 * m2; */
          ac1_hi = 0;
          ac1_lo = 0;

          /* ac2 = n1 * n2 * trans_num; */
          long_multiply(n1, n2*pdevcb->syncdsync_thread_cb[slice_client].transcode_num);
          ac2_hi = hi_word;
          ac2_lo = low_word;

          ad1 = 0;
          ad2 = num_pjo_odu2*pdevcb->syncdsync_thread_cb[slice_client].transcode_num;

          cfg    = 0;
          cfgpd0 = 0x01;

          jc_thresh = (cs_uint32)_ten_floor((cs_float)(2.0 * ((cs_float)k_divider)/((2.0 * (cs_float)num_pjo_odu2) + 1.0)));  /* Bugzilla #26345 */
          max_pjo = (cs_uint8)num_pjo_odu2;

          /* Line TX */
          ten_syncdsynctx_cfg(module_id_client,
                              slice_client,
                              ((module_id_line & 1) * 4) + pdevcb->oduflex_cb.line_slice, 
                              num_hi, num_lo, denom_hi, denom_lo,
                              ac1_hi, ac1_lo, ac2_hi, ac2_lo,
                              ad1, ad2,
                              cfg, cfgpd0,
                              jc_thresh,
                              max_pjo);

          /* Line RX */
          ten_syncdsyncrx_cfg(module_id_client,
                              slice_client,
                              num_hi, num_lo, denom_hi, denom_lo,
                              ac1_hi, ac1_lo, ac2_hi, ac2_lo,
                              ad1, ad2,
                              cfg);

        /* ODUflex Client TX */
        ten_syncdsync_config_1_to_1(module_id_line,
                                    pdevcb->oduflex_cb.client_slice,
                                    ((module_id_client & 1) * 4) + slice_line,
                                    CS_TX, 
                                    k_divider);

        /* ODUflex Client RX */
        n1 = 239*16*4*pdevcb->syncdsync_thread_cb[slice_client].transcode_denom;
        m1 = 238*16*4*pdevcb->syncdsync_thread_cb[slice_client].transcode_num;
        n2 = 1;
        m2 = 1;

        /*num    = m1 * m2; */
        long_multiply(m1, m2);
        num_hi = hi_word;
        num_lo = low_word;

        /* denom  = n1 * n2 * k_divider; */
        long_multiply(n1*k_divider, n2);
        denom_hi = hi_word;
        denom_lo = low_word;

        ten_syncdsyncrx_cfg(module_id_line,
                            pdevcb->oduflex_cb.client_slice,
                            num_hi, num_lo, denom_hi, denom_lo,
                            0,0,0,0,0,0,0);

        /* Client TX */
        ten_syncdsync_config_1_to_1(module_id_client,
                                    slice_client,
                                    ((module_id_line & 1) * 4) + pdevcb->oduflex_cb.client_slice,
                                    CS_TX, 
                                    k_divider);

        ten_syncdsynctx_gmp_enbl_t41(module_id_line, slice_line, 1);
      }
      break;
    
    default:
      CS_PRINT("%s() SyncDsync not provisioned and left in reset\n", func);
      break;
      
  }

RTN_EXIT:
  CS_PRINT("%s() Exit\n", func);
  return (rtn);
}

/********************************************************************/
/* $rtn_hdr_start  SYNCDSYNC MUX 1TO1 ASYNC 2 LEVEL MAPPING CONFIG  */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : SYNCDSYNC                                           */
/* CHIP       : Tenabo                                              */
cs_status ten_syncdsync_mux_1to1_async_2level_config(cs_uint16 module_id_line,
                                                     cs_uint8  slice_line, 
                                                     cs_uint16 module_id_client,
                                                     cs_uint8  slice_client,
                                                     cs_uint8  k_divider,
                                                     cs_uint32 n1, 
                                                     cs_uint32 n2, 
                                                     cs_uint32 m1, 
                                                     cs_uint32 m2, 
                                                     cs_uint16 num_pjo_oxuv, 
                                                     cs_uint16 num_pjo_odtu)
/* INPUTS     : o Line Module Id                                    */
/*              o Line Slice                                        */
/*              o Client Module Id                                  */
/*              o Client Slice                                      */
/*              o k divider                                         */
/*              o Bytes of four OxU3 frames                         */
/*              o Client bytes per ODU2 frame                       */
/*              o Payload bytes per ODTU23 structure                */
/*              o Client payload bytes per ODU2 frame               */
/*              o Number of mapper PJOs                             */
/*              o Number of client PJOs                             */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Configures the line to client path as follows:                   */
/*   Client RX and TX  : 1 to 1                                     */
/*   Line RX and TX    : Two level ASYNC mapping                    */
/*                                                                  */
/*   [slice_line]  Specified as TEN_SLICE0 (0), TEN_SLICE1 (1),     */
/*     TEN_SLICE2 (2), TEN_SLICE3 (3) or TEN_SLICE_ALL (0xFF)       */
/*                                                                  */
/*   [slice_client]  Specified as TEN_SLICE0 (0), TEN_SLICE1 (1),   */
/*     TEN_SLICE2 (2), TEN_SLICE3 (3) or TEN_SLICE_ALL (0xFF)       */
/*                                                                  */
/*   [k_divider] specifies the value of constant 'k'                */
/*     Async : 16 - 64                                              */
/*     Sync  : 16 - 255                                             */
/*                                                                  */
/*   [n1] specifies number of bytes of four OxU3 frames             */
/*   [n2] specifies number of client bytes per ODU2 frame           */ 
/*   [m1] specifies number of payload bytes per ODTU23 structure    */
/*   [m2] specifies number of client payload bytes per ODU2 frame   */
/*      Value is application dependent                              */
/*                                                                  */
/*   [num_pjo_oxuv] specifies the number of positive justification  */
/*                  bytes (First Level Mapping)                     */
/*     0 - 6                                                        */
/*                                                                  */
/*   [num_pjo_odtu] specifies the number of positive justification  */
/*                  bytes (Second Level Mapping)                    */
/*     0 - 6                                                        */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  cs_status rtn = CS_OK;
  cs_uint16 dev_id;
  ten_dev_cb_t *pdevcb;
  cs_uint8 max_pjo;
  cs_uint32 ts;
  cs_uint32 num_hi, num_lo, denom_hi, denom_lo, ac1_hi=0, ac1_lo=0, ac2_hi=0, ac2_lo=0, ad1=0, ad2=0;
  cs_uint8 cfg=0, cfgpd0=0, jc_thresh=0;
  cs_char8 *func = "ten_syncdsync_mux_1to1_async_2level_config";  

  CS_PRINT("%s()\n", func);
  CS_PRINT("    line (%s, %s)\n", ten_module_strings[module_id_line&1], ten_slice_strings[slice_line]);
  CS_PRINT("    client (%s, %s)\n", ten_module_strings[module_id_client&1], ten_slice_strings[slice_client]);
  CS_PRINT("    k_divider %d\n", k_divider);
  CS_PRINT("    n1 0x%X\n", n1);
  CS_PRINT("    n2 0x%X\n", n2);
  CS_PRINT("    m1 0x%X\n", m1);
  CS_PRINT("    m2 0x%X\n", m2);
  CS_PRINT("    num_pjo_oxuv %d\n", num_pjo_oxuv);
  CS_PRINT("    num_pjo_odtu %d\n", num_pjo_odtu);

  dev_id = TEN_MOD_ID_TO_DEV_ID(module_id_line);
  pdevcb = TEN_DEV_ID_TO_DEVCB_PTR(dev_id);

  /* Get timeslots */
  ts = (m1 >> 24) == 0 ? 4 : (m1 >> 24);      /* Bugzilla 31322 */
  m1 = m1 & 0x1FFFF;
  
  /*num    = m1 * m2 * trans_num; */
  long_multiply(m1, m2*pdevcb->syncdsync_thread_cb[slice_client].transcode_num);
  num_hi = hi_word;
  num_lo = low_word;

  /* denom  = n1 * n2 * k_divider * trans_denom; */
  long_multiply(n1*64, n2*pdevcb->syncdsync_thread_cb[slice_client].transcode_denom);
  denom_hi = hi_word;
  denom_lo = low_word;

  /* ac1 = n1 * m2 * trans_num; */
  long_multiply(n1, m2*pdevcb->syncdsync_thread_cb[slice_client].transcode_num);
  ac1_hi = hi_word;
  ac1_lo = low_word;

  /* ac2 = n1 * n2 * trans_num; */
  long_multiply(n1, n2*pdevcb->syncdsync_thread_cb[slice_client].transcode_num);
  ac2_hi = hi_word;
  ac2_lo = low_word;

  /* ad1 = 4 * num_pjo_odtu23 * m2 * trans_num; */
  /* ad2 = (m1+4) * num_pjo_odu2 * trans_num; */
  if((pdevcb->syncdsync_thread_cb[slice_client].line_map_proc == TEN_MAP_GMP_HO) ||
     (pdevcb->syncdsync_thread_cb[slice_client].line_map_proc == TEN_MAP_GMP_HO_DT))
    ad1 = num_pjo_odtu * m2 * pdevcb->syncdsync_thread_cb[slice_client].transcode_num * 
          pdevcb->syncdsync_thread_cb[slice_client].ad2_constant * 
          pdevcb->syncdsync_thread_cb[slice_client].multi_frames;                                /*Bugzilla 41096*/
  else
    ad1 = ts * num_pjo_odtu * m2 * pdevcb->syncdsync_thread_cb[slice_client].transcode_num;
  ad2 = (m1+4) * num_pjo_oxuv * pdevcb->syncdsync_thread_cb[slice_client].transcode_num;

  cfg    = 0x03;
  cfgpd0 = 0x01;
  jc_thresh = (cs_uint32)_ten_floor((cs_float)(2.0 * ((cs_float)64)/((2.0 * (cs_float)num_pjo_odtu) + 1.0))); /* Bugzilla #26345 */
  max_pjo = num_pjo_odtu > num_pjo_oxuv ? num_pjo_odtu : num_pjo_oxuv;

  /* Client RX */
  ten_syncdsync_config_1_to_1(module_id_client,
                              slice_client,
                              ((module_id_line & 1) * 4) + slice_line,
                              CS_RX, 
                              64);

  /* Line TX */
  ten_syncdsynctx_cfg(module_id_line,
                      slice_line,
                      ((module_id_client & 1) * 4) + slice_client, 
                      num_hi, num_lo, denom_hi, denom_lo,
                      ac1_hi, ac1_lo, ac2_hi, ac2_lo,
                      ad1, ad2,
                      cfg, cfgpd0,
                      jc_thresh,
                      max_pjo);

  /* denom  = n1 * n2 * k_divider; */
  long_multiply(n1*k_divider, n2*pdevcb->syncdsync_thread_cb[slice_client].transcode_denom);  /* Bugzilla 28237 */
  denom_hi = hi_word;
  denom_lo = low_word;

  /* Line RX */
  ten_syncdsyncrx_cfg(module_id_line,
                      slice_line,
                      num_hi, num_lo, denom_hi, denom_lo,
                      ac1_hi, ac1_lo, ac2_hi, ac2_lo,
                      ad1, ad2,
                      cfg);

  /* Client TX */
  ten_syncdsync_config_1_to_1(module_id_client,
                              slice_client,
                              ((module_id_line & 1) * 4) + slice_line,
                              CS_TX, 
                              k_divider);

  return (rtn);
}

/* Bug 38779 Start */
/********************************************************************/
/* $rtn_hdr_start  SYNCDSYNC MUX 1TO1 ASYNC 2 LEVEL MAP CONFIG V2   */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : SYNCDSYNC                                           */
/* CHIP       : Tenabo                                              */
cs_status ten_syncdsync_mux_1to1_async_2level_config_v2(cs_uint16 module_id_line,
                                                        cs_uint8  slice_line, 
                                                        cs_uint16 module_id_client,
                                                        cs_uint8  slice_client,
                                                        cs_uint8  k_divider_line,
                                                        cs_uint8  k_divider_client,
                                                        cs_uint32 n1, 
                                                        cs_uint32 n2, 
                                                        cs_uint32 m1, 
                                                        cs_uint32 m2, 
                                                        cs_uint16 num_pjo_oxuv, 
                                                        cs_uint16 num_pjo_odtu)
/* INPUTS     : o Line Module Id                                    */
/*              o Line Slice                                        */
/*              o Client Module Id                                  */
/*              o Client Slice                                      */
/*              o k divider line                                    */
/*              o k divider client                                  */
/*              o Bytes of four OxU3 frames                         */
/*              o Client bytes per ODU2 frame                       */
/*              o Payload bytes per ODTU23 structure                */
/*              o Client payload bytes per ODU2 frame               */
/*              o Number of mapper PJOs                             */
/*              o Number of client PJOs                             */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Configures the line to client path as follows:                   */
/*   Client RX and TX  : 1 to 1                                     */
/*   Line RX and TX    : Two level ASYNC mapping                    */
/*   _v2 splits k_divider into line and client parameters           */
/*                                                                  */
/*   [slice_line]  Specified as TEN_SLICE0 (0), TEN_SLICE1 (1),     */
/*     TEN_SLICE2 (2), TEN_SLICE3 (3) or TEN_SLICE_ALL (0xFF)       */
/*                                                                  */
/*   [slice_client]  Specified as TEN_SLICE0 (0), TEN_SLICE1 (1),   */
/*     TEN_SLICE2 (2), TEN_SLICE3 (3) or TEN_SLICE_ALL (0xFF)       */
/*                                                                  */
/*   [k_divider_line/client] specifies the value of constant 'k'    */
/*     Async : 16 - 64                                              */
/*     Sync  : 16 - 255                                             */
/*                                                                  */
/*   [n1] specifies number of bytes of four OxU3 frames             */
/*   [n2] specifies number of client bytes per ODU2 frame           */ 
/*   [m1] specifies number of payload bytes per ODTU23 structure    */
/*   [m2] specifies number of client payload bytes per ODU2 frame   */
/*      Value is application dependent                              */
/*                                                                  */
/*   [num_pjo_oxuv] specifies the number of positive justification  */
/*                  bytes (First Level Mapping)                     */
/*     0 - 6                                                        */
/*                                                                  */
/*   [num_pjo_odtu] specifies the number of positive justification  */
/*                  bytes (Second Level Mapping)                    */
/*     0 - 6                                                        */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  cs_status rtn = CS_OK;
  cs_uint16 dev_id;
  ten_dev_cb_t *pdevcb;
  cs_uint8 max_pjo;
  cs_uint32 ts;
  cs_uint32 num_hi, num_lo, denom_hi, denom_lo, ac1_hi=0, ac1_lo=0, ac2_hi=0, ac2_lo=0, ad1=0, ad2=0;
  cs_uint8 cfg=0, cfgpd0=0, jc_thresh=0;
  cs_char8 *func = "ten_syncdsync_mux_1to1_async_2level_config";  

  CS_PRINT("%s()\n", func);
  CS_PRINT("    line (%s, %s)\n", ten_module_strings[module_id_line&1], ten_slice_strings[slice_line]);
  CS_PRINT("    client (%s, %s)\n", ten_module_strings[module_id_client&1], ten_slice_strings[slice_client]);
  CS_PRINT("    k_divider_line   %d\n", k_divider_line);
  CS_PRINT("    k_divider_client %d\n", k_divider_client);
  CS_PRINT("    n1 0x%X\n", n1);
  CS_PRINT("    n2 0x%X\n", n2);
  CS_PRINT("    m1 0x%X\n", m1);
  CS_PRINT("    m2 0x%X\n", m2);
  CS_PRINT("    num_pjo_oxuv %d\n", num_pjo_oxuv);
  CS_PRINT("    num_pjo_odtu %d\n", num_pjo_odtu);

  dev_id = TEN_MOD_ID_TO_DEV_ID(module_id_line);
  pdevcb = TEN_DEV_ID_TO_DEVCB_PTR(dev_id);

  /* Get timeslots */
  ts = (m1 >> 24) == 0 ? 4 : (m1 >> 24);
  m1 = m1 & 0x1FFFF;
  
  /*num    = m1 * m2 * trans_num; */
  long_multiply(m1, m2*pdevcb->syncdsync_thread_cb[slice_client].transcode_num);
  num_hi = hi_word;
  num_lo = low_word;

  /* denom  = n1 * n2 * k_divider * trans_denom; */
  /* long_multiply(n1*64, n2*pdevcb->syncdsync_thread_cb[slice_client].transcode_denom); */
  long_multiply(n1*k_divider_line, n2*pdevcb->syncdsync_thread_cb[slice_client].transcode_denom);
  denom_hi = hi_word;
  denom_lo = low_word;

  /* ac1 = n1 * m2 * trans_num; */
  long_multiply(n1, m2*pdevcb->syncdsync_thread_cb[slice_client].transcode_num);
  ac1_hi = hi_word;
  ac1_lo = low_word;

  /* ac2 = n1 * n2 * trans_num; */
  long_multiply(n1, n2*pdevcb->syncdsync_thread_cb[slice_client].transcode_num);
  ac2_hi = hi_word;
  ac2_lo = low_word;

  /* ad1 = 4 * num_pjo_odtu23 * m2 * trans_num; */
  /* ad2 = (m1+4) * num_pjo_odu2 * trans_num; */
  ad1 = ts * num_pjo_odtu * m2 * pdevcb->syncdsync_thread_cb[slice_client].transcode_num;       
  ad2 = (m1+4) * num_pjo_oxuv * pdevcb->syncdsync_thread_cb[slice_client].transcode_num;

  cfg    = 0x03;
  cfgpd0 = 0x01;
  /* jc_thresh = (cs_uint32)_ten_floor((cs_float)(2.0 * ((cs_float)64)/((2.0 * (cs_float)num_pjo_odtu) + 1.0))); */
  jc_thresh = (cs_uint32)_ten_floor((cs_float)(2.0 * ((cs_float)k_divider_line)/((2.0 * (cs_float)num_pjo_odtu) + 1.0)));
  if(jc_thresh < 14) /* Bugzilla 39003 */
      jc_thresh = 14;

  max_pjo = num_pjo_odtu > num_pjo_oxuv ? num_pjo_odtu : num_pjo_oxuv;

  /* Client RX */
  ten_syncdsync_config_1_to_1(module_id_client,
                              slice_client,
                              ((module_id_line & 1) * 4) + slice_line,
                              CS_RX, 
                              /* 64); */
                              k_divider_client);

  /* Line TX */
  ten_syncdsynctx_cfg(module_id_line,
                      slice_line,
                      ((module_id_client & 1) * 4) + slice_client, 
                      num_hi, num_lo, denom_hi, denom_lo,
                      ac1_hi, ac1_lo, ac2_hi, ac2_lo,
                      ad1, ad2,
                      cfg, cfgpd0,
                      jc_thresh,
                      max_pjo);

  /* denom  = n1 * n2 * k_divider; */
  long_multiply(n1*k_divider_line, n2*pdevcb->syncdsync_thread_cb[slice_client].transcode_denom);  /* Bugzilla 28237 */
  denom_hi = hi_word;
  denom_lo = low_word;

  /* Line RX */
  ten_syncdsyncrx_cfg(module_id_line,
                      slice_line,
                      num_hi, num_lo, denom_hi, denom_lo,
                      ac1_hi, ac1_lo, ac2_hi, ac2_lo,
                      ad1, ad2,
                      cfg);

  /* Client TX */
  ten_syncdsync_config_1_to_1(module_id_client,
                              slice_client,
                              ((module_id_line & 1) * 4) + slice_line,
                              CS_TX, 
                              k_divider_client);

  return (rtn);
}
/* Bug 38779 End */

/********************************************************************/
/* $rtn_hdr_start  SYNCDSYNC MUX SYNC ASYNC 1 LEVEL MAPPING CONFIG  */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : SYNCDSYNC                                           */
/* CHIP       : Tenabo                                              */
cs_status ten_syncdsync_mux_sync_async_1level_config(cs_uint16 module_id_line,
                                                     cs_uint8  slice_line, 
                                                     cs_uint16 module_id_client,
                                                     cs_uint8  slice_client,
                                                     cs_uint8  fec_client,
                                                     cs_uint8  k_divider,
                                                     cs_uint32 n1, 
                                                     cs_uint32 n2, 
                                                     cs_uint32 m1, 
                                                     cs_uint32 m2, 
                                                     cs_uint16 num_pjo_oxuv, 
                                                     cs_uint16 num_pjo_odtu)
/* INPUTS     : o Line Module Id                                    */
/*              o Line Slice                                        */
/*              o Client Module Id                                  */
/*              o Client Slice                                      */
/*              o FEC Type Client                                   */
/*              o k divider                                         */
/*              o Bytes of four OxU3 frames                         */
/*              o Client bytes per ODU2 frame                       */
/*              o Payload bytes per ODTU23 structure                */
/*              o Client payload bytes per ODU2 frame               */
/*              o Number of mapper PJOs                             */
/*              o Number of client PJOs                             */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Configures the line to client path as follows:                   */
/*   Client RX         : No FEC 1 to 1 ; else SYNC Mapping          */
/*   Line TX and RX    : 1 level ASYNC Mapping                      */
/*   Client TX         : 1 to 1 Mapping                             */
/*                                                                  */
/*   [slice_line]  Specified as TEN_SLICE0 (0), TEN_SLICE1 (1),     */
/*     TEN_SLICE2 (2), TEN_SLICE3 (3) or TEN_SLICE_ALL (0xFF)       */
/*                                                                  */
/*   [slice_client]  Specified as TEN_SLICE0 (0), TEN_SLICE1 (1),   */
/*     TEN_SLICE2 (2), TEN_SLICE3 (3) or TEN_SLICE_ALL (0xFF)       */
/*                                                                  */
/* [fec_client] parameter defines the line fec type:                */
/*     TEN_FEC_MODE_NOFEC = 15, or                                  */
/*     Any other FEC% as per ten_fec_ovhd_t = 0 -14                 */
/*                                                                  */
/*   [k_divider] specifies the value of constant 'k'                */
/*     Async : 16 - 64                                              */
/*     Sync  : 16 - 255                                             */
/*                                                                  */
/*   [n1] specifies number of bytes of four OxU3 frames             */
/*   [n2] specifies number of client bytes per ODU2 frame           */
/*   [m1] specifies number of payload bytes per ODTU23 structure    */
/*   [m2] specifies number of client payload bytes per ODU2 frame   */
/*      Value is application dependent                              */
/*                                                                  */
/*   [num_pjo_oxuv] specifies the number of positive justification  */
/*                  bytes (First Level Mapping)                     */
/*     0 - 6                                                        */
/*                                                                  */
/*   [num_pjo_odtu] specifies the number of positive justification  */
/*                  bytes (Second Level Mapping)                    */
/*     0 - 6                                                        */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  cs_status rtn = CS_OK;
  cs_uint16 dev_id;
  ten_dev_cb_t *pdevcb;
  cs_uint8 max_pjo;
  cs_uint32 int_n1, int_n2, int_m1, int_m2;
  cs_uint32 ts;
  cs_uint32 num_hi, num_lo, denom_hi, denom_lo, ac1_hi=0, ac1_lo=0, ac2_hi=0, ac2_lo=0, ad1=0, ad2=0;
  cs_uint8 cfg=0, cfgpd0=0, jc_thresh=0;
  cs_char8 *func = "ten_syncdsync_mux_sync_async_1level_config";  

  CS_PRINT("%s()\n", func);
  CS_PRINT("    line (%s, %s)\n", ten_module_strings[module_id_line&1], ten_slice_strings[slice_line]);
  CS_PRINT("    client (%s, %s)\n", ten_module_strings[module_id_client&1], ten_slice_strings[slice_client]);
  CS_PRINT("    k_divider %d\n", k_divider);
  CS_PRINT("    fec_client %s\n",     ten_fec_ovhd_strings[fec_client]);
  CS_PRINT("    n1 0x%X\n", n1);
  CS_PRINT("    n2 0x%X\n", n2);
  CS_PRINT("    m1 0x%X\n", m1);
  CS_PRINT("    m2 0x%X\n", m2);
  CS_PRINT("    num_pjo_oxuv %d\n", num_pjo_oxuv);
  CS_PRINT("    num_pjo_odtu %d\n", num_pjo_odtu);


  dev_id = TEN_MOD_ID_TO_DEV_ID(module_id_line);
  pdevcb = TEN_DEV_ID_TO_DEVCB_PTR(dev_id);

  /* Get timeslots */
  ts = (m1 >> 24) == 0 ? 4 : (m1 >> 24);      /* Bugzilla 31322 */
  m1 = m1 & 0x1FFFF;
  
  int_n1 = 1;
  int_m1 = 1;

   /*num    = m1 * m2; */
  long_multiply(int_m1, m2);
  num_hi = hi_word;
  num_lo = low_word;

  /* denom  = n1 * n2 * k_divider; */
  long_multiply(int_n1*64, n2);
  denom_hi = hi_word;
  denom_lo = low_word;

  /*Client RX */
  if(fec_client == TEN_FEC_MODE_NOFEC) {
    ten_syncdsync_config_1_to_1(module_id_client,
                                slice_client,
                                ((module_id_line & 1) * 4) + slice_line,
                                CS_RX,
                                64);
  }
  else {
    ten_syncdsyncrx_cfg(module_id_client,
                        slice_client,
                        num_hi, num_lo, denom_hi, denom_lo,
                        0,0,0,0,0,0,0);
  }

  int_n2 = 1;
  int_m2 = 1;

  /*num    = m1 * m2; */
  long_multiply(m1, int_m2);
  num_hi = hi_word;
  num_lo = low_word;

  /* denom  = n1 * n2 * k_divider; */
  long_multiply(n1*64, int_n2);
  denom_hi = hi_word;
  denom_lo = low_word;

  /* $ac1    = 0; */
  ac1_hi = 0;
  ac1_lo = 0;

  /* $ac2 = $n1 * $n2; */
  long_multiply(n1, int_n2);
  ac2_hi = hi_word;
  ac2_lo = low_word;

  ad1 = 0;
  if((pdevcb->syncdsync_thread_cb[slice_client].line_map_proc == TEN_MAP_GMP_HO) ||
     (pdevcb->syncdsync_thread_cb[slice_client].line_map_proc == TEN_MAP_GMP_HO_DT))
    ad2 = num_pjo_odtu * pdevcb->syncdsync_thread_cb[slice_client].ad2_constant * 
          pdevcb->syncdsync_thread_cb[slice_client].multi_frames;                        /*Bugzilla 41096*/
  else  
    ad2 = ts * num_pjo_odtu;

  cfg    = 0x02;
  cfgpd0 = 0x01;
  jc_thresh = (cs_uint32)_ten_floor((cs_float)(2.0 * ((cs_float)64)/((2.0 * (cs_float)num_pjo_odtu) + 1.0))); /* Bugzilla #26345 */
  max_pjo = num_pjo_odtu > num_pjo_oxuv ? num_pjo_odtu : num_pjo_oxuv;

  /* Line TX */
  ten_syncdsynctx_cfg(module_id_line,
                      slice_line,
                      ((module_id_client & 1) * 4) + slice_client, 
                      num_hi, num_lo, denom_hi, denom_lo,
                      ac1_hi, ac1_lo, ac2_hi, ac2_lo,
                      ad1, ad2,
                      cfg, cfgpd0,
                      jc_thresh,
                      max_pjo);

  /* Line RX */
  long_multiply(m1, int_m2*pdevcb->syncdsync_thread_cb[slice_client].P_client);
  num_hi = hi_word;
  num_lo = low_word;

  /* denom  = n1 * n2 * k_divider; */
  long_multiply(n1*k_divider, int_n2*239);
  denom_hi = hi_word;
  denom_lo = low_word;

  /* $ac1    = 0; */
  ac1_hi = 0;
  ac1_lo = 0;

  /* $ac2 = $n1 * $n2; */
  long_multiply(n1, int_n2*pdevcb->syncdsync_thread_cb[slice_client].P_client);
  ac2_hi = hi_word;
  ac2_lo = low_word;

  ad1 = 0;                               
  ad2 = ts*num_pjo_odtu*pdevcb->syncdsync_thread_cb[slice_client].P_client;

  ten_syncdsyncrx_cfg(module_id_line,
                      slice_line,
                      num_hi, num_lo, denom_hi, denom_lo,
                      ac1_hi, ac1_lo, ac2_hi, ac2_lo,
                      ad1, ad2,
                      cfg);

  /* Client TX */
  ten_syncdsync_config_1_to_1(module_id_client,
                              slice_client,
                              ((module_id_line & 1) * 4) + slice_line,
                              CS_TX,
                              k_divider);

  return (rtn);
}

/********************************************************************/
/* $rtn_hdr_start  SYNCDSYNC MUX ASYNC ASYNC 1 LEVEL MAPPING CONFIG */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : SYNCDSYNC                                           */
/* CHIP       : Tenabo                                              */
cs_status ten_syncdsync_mux_async_async_1level_config(cs_uint16 module_id_line,
                                                      cs_uint8  slice_line, 
                                                      cs_uint16 module_id_client,
                                                      cs_uint8  slice_client,
                                                      cs_uint8  k_divider,
                                                      cs_uint32 n1, 
                                                      cs_uint32 n2, 
                                                      cs_uint32 m1, 
                                                      cs_uint32 m2,
                                                      cs_uint16 num_pjo_oxuv, 
                                                      cs_uint16 num_pjo_odtu)
/* INPUTS     : o Line Module Id                                    */
/*              o Line Slice                                        */
/*              o Client Module Id                                  */
/*              o Client Slice                                      */
/*              o k divider                                         */
/*              o Bytes of four OxU3 frames                         */
/*              o Client bytes per ODU2 frame                       */
/*              o Payload bytes per ODTU23 structure                */
/*              o Client payload bytes per ODU2 frame               */
/*              o Number of mapper PJOs                             */
/*              o Number of client PJOs                             */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Configures the line to client path as follows:                   */
/*   Client RX and TX  : 1 level ASYNC Mapping                      */
/*   Line RX and TX    : 1 level ASYNC mapping                      */
/*                                                                  */
/*   [slice_line]  Specified as TEN_SLICE0 (0), TEN_SLICE1 (1),     */
/*     TEN_SLICE2 (2), TEN_SLICE3 (3) or TEN_SLICE_ALL (0xFF)       */
/*                                                                  */
/*   [slice_client]  Specified as TEN_SLICE0 (0), TEN_SLICE1 (1),   */
/*     TEN_SLICE2 (2), TEN_SLICE3 (3) or TEN_SLICE_ALL (0xFF)       */
/*                                                                  */
/*   [k_divider] specifies the value of constant 'k'                */
/*     Async : 16 - 64                                              */
/*     Sync  : 16 - 255                                             */
/*                                                                  */
/*   [n1] specifies number of bytes of four OxU3 frames             */
/*   [n2] specifies number of client bytes per ODU2 frame           */
/*   [m1] specifies number of payload bytes per ODTU23 structure    */
/*   [m2] specifies number of client payload bytes per ODU2 frame   */
/*      Value is application dependent                              */
/*                                                                  */
/*   [num_pjo_oxuv] specifies the number of positive justification  */
/*                  bytes (First Level Mapping)                     */
/*     0 - 6                                                        */
/*                                                                  */
/*   [num_pjo_odtu] specifies the number of positive justification  */
/*                  bytes (Second Level Mapping)                    */
/*     0 - 6                                                        */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  cs_status rtn = CS_OK;
  cs_uint16 dev_id;
  cs_uint32 ts_line, ts_client;
  ten_dev_cb_t *pdevcb;

  cs_uint32 num_hi, num_lo, denom_hi, denom_lo, ac1_hi=0, ac1_lo=0, ac2_hi=0, ac2_lo=0, ad1=0, ad2=0;
  cs_uint8 cfg=0, cfgpd0=0, jc_thresh=0;
  cs_uint8 max_pjo;
  cs_char8 *func = "ten_syncdsync_mux_async_async_1level_config";  

  CS_PRINT("%s()\n", func);
  CS_PRINT("    line   (%s, %s)\n", ten_module_strings[module_id_line&1], ten_slice_strings[slice_line]);
  CS_PRINT("    client (%s, %s)\n", ten_module_strings[module_id_client&1], ten_slice_strings[slice_client]);
  CS_PRINT("    line   (n1 0x%X, m1 0x%X, num_pjo_odtu %d)\n", n1, m1, num_pjo_odtu);
  CS_PRINT("    client (n2 0x%X, m2 0x%X, num_pjo_oxuv %d)\n", n2, m2, num_pjo_oxuv);
  CS_PRINT("    k_divider %d\n", k_divider);
 #if 0
  CS_PRINT("    n1 0x%X\n", n1);
  CS_PRINT("    n2 0x%X\n", n2);
  CS_PRINT("    m1 0x%X\n", m1);
  CS_PRINT("    m2 0x%X\n", m2);
  CS_PRINT("    num_pjo_oxuv %d\n", num_pjo_oxuv);
  CS_PRINT("    num_pjo_odtu %d\n", num_pjo_odtu);
 #endif 

  dev_id = TEN_MOD_ID_TO_DEV_ID(module_id_line);
  pdevcb = TEN_DEV_ID_TO_DEVCB_PTR(dev_id);

  /* Get timeslots */
  ts_line = (m1 >> 24) == 0 ? 4 : (m1 >> 24);      /* Bugzilla 31322 */
  m1 = m1 & 0x1FFFF;
  ts_client = (m2 >> 24) == 0 ? 4 : (m2 >> 24);      /* Bugzilla 31322 */
  m2 = m2 & 0x1FFFF;

  /**************************/
  /*      Line Side         */
  /**************************/
   /*num    = m1 * m2 * trans_num; */
  /* long_multiply(m1, m2); */
  long_multiply(m1, 1*pdevcb->syncdsync_thread_cb[slice_client].transcode_num);
  num_hi = hi_word;
  num_lo = low_word;

  /* denom  = n1 * n2 * k_divider * trans_denom; */
  /* long_multiply(n1*64, n2); */
  long_multiply(n1*64, 1*pdevcb->syncdsync_thread_cb[slice_client].transcode_denom);
  denom_hi = hi_word;
  denom_lo = low_word;

  /* ac1 = 0; */
  ac1_hi = 0;
  ac1_lo = 0;

  /* ac2 = n1 * n2 * trans_num; */
  /* long_multiply(n1, n2); */

  long_multiply(n1, 1*pdevcb->syncdsync_thread_cb[slice_client].transcode_num);
  ac2_hi = hi_word;
  ac2_lo = low_word;

  /* ad1 = 0*/
  /* ad2 = 4 * num_pjo_odu2 * trans_num; */
  ad1 = 0;       
  ad2 = ts_line * num_pjo_odtu * pdevcb->syncdsync_thread_cb[slice_client].transcode_num;

  cfg    = 2;  /* Bugzilla 26785 */
  cfgpd0 = 0x01;
  jc_thresh = (cs_uint32)_ten_floor((cs_float)(2.0 * ((cs_float)64)/((2.0 * (cs_float)num_pjo_odtu) + 1.0)));  /* Bugzilla #26345 */
  max_pjo = (cs_uint8)num_pjo_odtu;

  /* Line TX */
  ten_syncdsynctx_cfg(module_id_line,
                      slice_line,
                      ((module_id_client & 1) * 4) + slice_client, 
                      num_hi, num_lo, denom_hi, denom_lo,
                      ac1_hi, ac1_lo, ac2_hi, ac2_lo,
                      ad1, ad2,
                      cfg, cfgpd0,
                      jc_thresh,
                      max_pjo);

  /* Line RX */
  ten_syncdsyncrx_cfg(module_id_line,
                      slice_line,
                      num_hi, num_lo, denom_hi, denom_lo,
                      ac1_hi, ac1_lo, ac2_hi, ac2_lo,
                      ad1, ad2,
                      cfg);



  /****************************/
  /*      Client Side         */
  /****************************/
   /*num    = m1 * m2 * trans_num; */
  /* long_multiply(m1, m2); */
  long_multiply(1, m2*pdevcb->syncdsync_thread_cb[slice_client].transcode_num);
  num_hi = hi_word;
  num_lo = low_word;

  /* denom  = n1 * n2 * k_divider * trans_denom; */
  /* long_multiply(n1*64, n2); */
  long_multiply(1*64, n2*pdevcb->syncdsync_thread_cb[slice_client].transcode_denom);
  denom_hi = hi_word;
  denom_lo = low_word;

  /* ac1 = 0; */
  ac1_hi = 0;
  ac1_lo = 0;

  /* ac2 = n1 * n2 * trans_num; */
  long_multiply(n2, 1*pdevcb->syncdsync_thread_cb[slice_client].transcode_num);  /* Bugzilla 26785 */
  ac2_hi = hi_word;
  ac2_lo = low_word;

  /* ad1 = 0*/
  /* ad2 = 4 * num_pjo_odu2 * trans_num; */
  ad1 = 0;       
  ad2 = ts_client * num_pjo_oxuv * pdevcb->syncdsync_thread_cb[slice_client].transcode_num;

  cfg    = 2;  /* Bugzilla 26785 */
  cfgpd0 = 0x01;
  jc_thresh = (cs_uint32)_ten_floor((cs_float)(2.0 * ((cs_float)64)/((2.0 * (cs_float)num_pjo_oxuv) + 1.0))); /* Bugzilla #26345 */
  max_pjo = (cs_uint8)num_pjo_oxuv;

  /* Client RX */
  ten_syncdsyncrx_cfg(module_id_client,
                      slice_client,
                      num_hi, num_lo, denom_hi, denom_lo,
                      ac1_hi, ac1_lo, ac2_hi, ac2_lo,
                      ad1, ad2,
                      cfg);

  /* Client TX */
  ten_syncdsynctx_cfg(module_id_client,
                      slice_client,
                      ((module_id_line & 1) * 4) + slice_line, 
                      num_hi, num_lo, denom_hi, denom_lo,
                      ac1_hi, ac1_lo, ac2_hi, ac2_lo,
                      ad1, ad2,
                      cfg, cfgpd0,
                      jc_thresh,
                      max_pjo);

  return (rtn);
}

/********************************************************************/
/* $rtn_hdr_start  SYNCDSYNC TRANS 1TO1 ASYNC MAPPING CONFIG        */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : SYNCDSYNC                                           */
/* CHIP       : Tenabo                                              */
cs_status ten_syncdsync_trans_1to1_async_config(cs_uint16 module_id_line,
                                                cs_uint8  slice_line, 
                                                cs_uint16 module_id_client,
                                                cs_uint8  slice_client,
                                                cs_uint8  k_divider,
                                                cs_uint32 n1,  
                                                cs_uint32 m1, 
                                                cs_uint8  mode,
                                                cs_uint16 num_pjo_oxuv,
                                                cs_uint16 rate)                 /* Bugzilla 26729 */
/* INPUTS     : o Line Module Id                                    */
/*              o Line Slice                                        */
/*              o Client Module Id                                  */
/*              o Client Slice                                      */
/*              o k divider                                         */
/*              o Bytes per OxUk frame                              */
/*              o Client bytes per OxUk frame                       */
/*              o Mode                                              */
/*              o Number of PJOs used by the ODU3 frame             */
/*              o Rate                                              */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/*   Client RX         : 1 to 1 Mapping                             */
/*   Line RX and TX    : ASYNC Mapping                              */
/*   Client TX         : 1 to 1 Mapping                             */
/*                                                                  */
/*   [slice_line]  Specified as TEN_SLICE0 (0), TEN_SLICE1 (1),     */
/*     TEN_SLICE2 (2), TEN_SLICE3 (3) or TEN_SLICE_ALL (0xFF)       */
/*                                                                  */
/*   [slice_client]  Specified as TEN_SLICE0 (0), TEN_SLICE1 (1),   */
/*     TEN_SLICE2 (2), TEN_SLICE3 (3) or TEN_SLICE_ALL (0xFF)       */
/*                                                                  */
/*   [k_divider] specifies the value of constant 'k'                */
/*     Async : 16 - 64                                              */
/*     Sync  : 16 - 255                                             */
/*                                                                  */
/*   [n1] specifies number of bytes per OxUk frame                  */
/*   [m1] specifies number of client bytes per OxUk frame           */
/*      Value is application dependent                              */
/*                                                                  */
/*   [mode] specifies monolithic de-wrapping level of justification */
/*     TEN_OXU3_MONO_ONE_LEVEL = 0                                  */
/*     TEN_OXU2_MONO_ONE_LEVEL = 1                                  */
/*                                                                  */
/*   [num_pjo] specifies the number of positive justification       */
/*                  bytes (First Level Mapping)                     */
/*     0 - 6                                                        */
/*                                                                  */
/*   [rate] is used to identify 10G vs 40G                          */
/*     TEN_SLICE_10G = 0                                            */
/*     TEN_SLICE_40G = 1                                            */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  cs_status rtn = CS_OK;
  cs_uint16 dev_id;
  ten_dev_cb_t *pdevcb;

  cs_uint32 num_hi, num_lo, denom_hi, denom_lo, ac1_hi=0, ac1_lo=0, ac2_hi=0, ac2_lo=0, ad1=0, ad2=0;
  cs_uint8 cfg=0, cfgpd0=0, jc_thresh=0;
  cs_uint8 max_pjo;
  cs_uint32 n2=1, m2=1;
  cs_char8 *func = "ten_syncdsync_trans_1to1_async_config";  

  CS_PRINT("%s()\n", func);
  CS_PRINT("    line: %s %s\n", ten_module_strings[module_id_line&1], ten_slice_strings[slice_line]);
  CS_PRINT("    client: %s %s\n", ten_module_strings[module_id_client&1], ten_slice_strings[slice_client]);
  CS_PRINT("    k_divider=%d\n", k_divider);
  CS_PRINT("    n1=%d, m1=%d\n", n1, m1); 
  CS_PRINT("    mode=%s\n",ten_hl_syncdsync_mode_strings[mode]);
  CS_PRINT("    num_pjo_oxuv=%d\n", num_pjo_oxuv);

  dev_id = TEN_MOD_ID_TO_DEV_ID(module_id_line);
  pdevcb = TEN_DEV_ID_TO_DEVCB_PTR(dev_id);

  /* Client RX */
  ten_syncdsync_config_1_to_1(module_id_client,
                              slice_client,
                              ((module_id_line & 1) * 4) + slice_line,
                              CS_RX, 
                              k_divider);

  /*num    = m1 * m2 * trans_num; */
  long_multiply(m1, m2*pdevcb->syncdsync_thread_cb[slice_client].transcode_num);
  num_hi = hi_word;
  num_lo = low_word;

  /* denom  = n1 * n2 * k_divider * trans_denom; */
  long_multiply(n1*k_divider, n2*pdevcb->syncdsync_thread_cb[slice_client].transcode_denom);
  denom_hi = hi_word;
  denom_lo = low_word;

  /* ac1 = n1 * m2; */
  ac1_hi = 0;
  ac1_lo = 0;

  /* ac2 = n1 * n2 * trans_num; */
  if(mode == TEN_OXU2_MONO_ONE_LEVEL)
    long_multiply(n1, n2*pdevcb->syncdsync_thread_cb[slice_client].transcode_num);
  else
    long_multiply(n1/4, n2*pdevcb->syncdsync_thread_cb[slice_client].transcode_num);

  ac2_hi = hi_word;
  ac2_lo = low_word;

  ad1 = 0;
  ad2 = num_pjo_oxuv*pdevcb->syncdsync_thread_cb[slice_client].transcode_num;

  cfg    = mode;
  cfgpd0 = 0x01;

  jc_thresh = (cs_uint32)_ten_floor((cs_float)(2.0 * ((cs_float)k_divider)/((2.0 * (cs_float)num_pjo_oxuv) + 1.0)));  /* Bugzilla #26345 */
  max_pjo = (cs_uint8)num_pjo_oxuv;

  /* Line TX */
  ten_syncdsynctx_cfg(module_id_line,
                      slice_line,
                      ((module_id_client & 1) * 4) + slice_client, 
                      num_hi, num_lo, denom_hi, denom_lo,
                      ac1_hi, ac1_lo, ac2_hi, ac2_lo,
                      ad1, ad2,
                      cfg, cfgpd0,
                      jc_thresh,
                      max_pjo);

  /* Bugzilla 26729 Start */
  if(rate == TEN_SLICE_40G) {
    ten_syncdsynctx_cfg(module_id_line,
                        3,
                        ((module_id_client & 1) * 4) + slice_client, 
                        num_hi, num_lo, denom_hi, denom_lo,
                        ac1_hi, ac1_lo, ac2_hi, ac2_lo,
                        ad1, ad2,
                        cfg, cfgpd0,
                        jc_thresh,
                        max_pjo);
  }
  /* Bugzilla 26729 End */

  /* Line RX */
  ten_syncdsyncrx_cfg(module_id_line,
                      slice_line,
                      num_hi, num_lo, denom_hi, denom_lo,
                      ac1_hi, ac1_lo, ac2_hi, ac2_lo,
                      ad1, ad2,
                      cfg);

  /* Bugzilla 26729 Start */
  if(rate == TEN_SLICE_40G) {
    ten_syncdsyncrx_cfg(module_id_line,
                        3,
                        num_hi, num_lo, denom_hi, denom_lo,
                        ac1_hi, ac1_lo, ac2_hi, ac2_lo,
                        ad1, ad2,
                        cfg);
  }
  /* Bugzilla 26729 End */

  /* Client TX */
  ten_syncdsync_config_1_to_1(module_id_client,
                              slice_client,
                              ((module_id_line & 1) * 4) + slice_line,
                              CS_TX, 
                              k_divider);

  return (rtn);
}

/********************************************************************/
/* $rtn_hdr_start  SYNCDSYNC TRANS 1TO1 ASYNC MAPPING CONFIG V2     */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : SYNCDSYNC                                           */
/* CHIP       : Tenabo                                              */
cs_status ten_syncdsync_trans_1to1_async_config_v2(cs_uint16 module_id_line,
                                                   cs_uint8  slice_line, 
                                                   cs_uint16 module_id_client,
                                                   cs_uint8  slice_client,
                                                   cs_uint8  k_divider_line,
                                                   cs_uint8  k_divider_client,
                                                   cs_uint32 n1,  
                                                   cs_uint32 m1, 
                                                   cs_uint8  mode,
                                                   cs_uint16 num_pjo_oxuv,
                                                   cs_uint16 rate)                 /* Bugzilla 26729 */
/* INPUTS     : o Line Module Id                                    */
/*              o Line Slice                                        */
/*              o Client Module Id                                  */
/*              o Client Slice                                      */
/*              o k divider line                                    */
/*              o k divider client                                  */
/*              o Bytes per OxUk frame                              */
/*              o Client bytes per OxUk frame                       */
/*              o Mode                                              */
/*              o Number of PJOs used by the ODU3 frame             */
/*              o Rate                                              */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/*   Client RX         : 1 to 1 Mapping                             */
/*   Line RX and TX    : ASYNC Mapping                              */
/*   Client TX         : 1 to 1 Mapping                             */
/*   _v2 splits k_divider into line and client parameters           */
/*                                                                  */
/*   [slice_line]  Specified as TEN_SLICE0 (0), TEN_SLICE1 (1),     */
/*     TEN_SLICE2 (2), TEN_SLICE3 (3) or TEN_SLICE_ALL (0xFF)       */
/*                                                                  */
/*   [slice_client]  Specified as TEN_SLICE0 (0), TEN_SLICE1 (1),   */
/*     TEN_SLICE2 (2), TEN_SLICE3 (3) or TEN_SLICE_ALL (0xFF)       */
/*                                                                  */
/*   [k_divider_line/client] specifies the value of constant 'k'    */
/*     Async : 16 - 64                                              */
/*     Sync  : 16 - 255                                             */
/*                                                                  */
/*   [n1] specifies number of bytes per OxUk frame                  */
/*   [m1] specifies number of client bytes per OxUk frame           */
/*      Value is application dependent                              */
/*                                                                  */
/*   [mode] specifies monolithic de-wrapping level of justification */
/*     TEN_OXU3_MONO_ONE_LEVEL = 0                                  */
/*     TEN_OXU2_MONO_ONE_LEVEL = 1                                  */
/*                                                                  */
/*   [num_pjo] specifies the number of positive justification       */
/*                  bytes (First Level Mapping)                     */
/*     0 - 6                                                        */
/*                                                                  */
/*   [rate] is used to identify 10G vs 40G                          */
/*     TEN_SLICE_10G = 0                                            */
/*     TEN_SLICE_40G = 1                                            */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  cs_status rtn = CS_OK;
  cs_uint16 dev_id;
  ten_dev_cb_t *pdevcb;

  cs_uint32 num_hi, num_lo, denom_hi, denom_lo, ac1_hi=0, ac1_lo=0, ac2_hi=0, ac2_lo=0, ad1=0, ad2=0;
  cs_uint8 cfg=0, cfgpd0=0, jc_thresh=0;
  cs_uint8 max_pjo;
  cs_uint32 n2=1, m2=1;
  cs_char8 *func = "ten_syncdsync_trans_1to1_async_config_v2";  

  CS_PRINT("%s()\n", func);
  CS_PRINT("    line: %s %s\n", ten_module_strings[module_id_line&1], ten_slice_strings[slice_line]);
  CS_PRINT("    client: %s %s\n", ten_module_strings[module_id_client&1], ten_slice_strings[slice_client]);
  CS_PRINT("    k_divider_line=%d\n", k_divider_line);
  CS_PRINT("    k_divider_client=%d\n", k_divider_client);
  CS_PRINT("    n1=%d, m1=%d\n", n1, m1); 
  CS_PRINT("    mode=%s\n",ten_hl_syncdsync_mode_strings[mode]);
  CS_PRINT("    num_pjo_oxuv=%d\n", num_pjo_oxuv);

  dev_id = TEN_MOD_ID_TO_DEV_ID(module_id_line);
  pdevcb = TEN_DEV_ID_TO_DEVCB_PTR(dev_id);

  /* Client RX */
  ten_syncdsync_config_1_to_1(module_id_client,
                              slice_client,
                              ((module_id_line & 1) * 4) + slice_line,
                              CS_RX, 
                              k_divider_client);

  /*num    = m1 * m2 * trans_num; */
  long_multiply(m1, m2*pdevcb->syncdsync_thread_cb[slice_client].transcode_num);
  num_hi = hi_word;
  num_lo = low_word;

  /* denom  = n1 * n2 * k_divider * trans_denom; */
  long_multiply(n1*k_divider_line, n2*pdevcb->syncdsync_thread_cb[slice_client].transcode_denom);
  denom_hi = hi_word;
  denom_lo = low_word;

  /* ac1 = n1 * m2; */
  ac1_hi = 0;
  ac1_lo = 0;

  /* ac2 = n1 * n2 * trans_num; */
  if(mode == TEN_OXU2_MONO_ONE_LEVEL)
    long_multiply(n1, n2*pdevcb->syncdsync_thread_cb[slice_client].transcode_num);
  else
    long_multiply(n1/4, n2*pdevcb->syncdsync_thread_cb[slice_client].transcode_num);

  ac2_hi = hi_word;
  ac2_lo = low_word;

  ad1 = 0;
  ad2 = num_pjo_oxuv*pdevcb->syncdsync_thread_cb[slice_client].transcode_num;

  cfg    = mode;
  cfgpd0 = 0x01;

  jc_thresh = (cs_uint32)_ten_floor((cs_float)(2.0 * ((cs_float)k_divider_line)/((2.0 * (cs_float)num_pjo_oxuv) + 1.0)));  /* Bugzilla #26345 */
  if(jc_thresh < 14) /* Bugzilla 39003 */
      jc_thresh = 14;

  max_pjo = (cs_uint8)num_pjo_oxuv;

  /* Line TX */
  ten_syncdsynctx_cfg(module_id_line,
                      slice_line,
                      ((module_id_client & 1) * 4) + slice_client, 
                      num_hi, num_lo, denom_hi, denom_lo,
                      ac1_hi, ac1_lo, ac2_hi, ac2_lo,
                      ad1, ad2,
                      cfg, cfgpd0,
                      jc_thresh,
                      max_pjo);

  /* Bugzilla 26729 Start */
  if(rate == TEN_SLICE_40G) {
    ten_syncdsynctx_cfg(module_id_line,
                        3,
                        ((module_id_client & 1) * 4) + slice_client, 
                        num_hi, num_lo, denom_hi, denom_lo,
                        ac1_hi, ac1_lo, ac2_hi, ac2_lo,
                        ad1, ad2,
                        cfg, cfgpd0,
                        jc_thresh,
                        max_pjo);
  }
  /* Bugzilla 26729 End */

  /* Line RX */
  ten_syncdsyncrx_cfg(module_id_line,
                      slice_line,
                      num_hi, num_lo, denom_hi, denom_lo,
                      ac1_hi, ac1_lo, ac2_hi, ac2_lo,
                      ad1, ad2,
                      cfg);

  /* Bugzilla 26729 Start */
  if(rate == TEN_SLICE_40G) {
    ten_syncdsyncrx_cfg(module_id_line,
                        3,
                        num_hi, num_lo, denom_hi, denom_lo,
                        ac1_hi, ac1_lo, ac2_hi, ac2_lo,
                        ad1, ad2,
                        cfg);
  }
  /* Bugzilla 26729 End */

  /* Client TX */
  ten_syncdsync_config_1_to_1(module_id_client,
                              slice_client,
                              ((module_id_line & 1) * 4) + slice_line,
                              CS_TX, 
                              k_divider_client);

  return (rtn);
}

/********************************************************************/
/* $rtn_hdr_start  SYNCDSYNC TRANS 1TO1 ASYNC 1TO1 MAPPING CONFIG   */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : SYNCDSYNC                                           */
/* CHIP       : Tenabo                                              */
cs_status ten_syncdsync_trans_1to1_async_1to1_config(cs_uint16 module_id_line,
                                                     cs_uint8  slice_line, 
                                                     cs_uint16 module_id_client,
                                                     cs_uint8  slice_client,
                                                     cs_uint8  k_divider,
                                                     cs_uint32 n1, 
                                                     cs_uint32 m1,
                                                     cs_uint8  mode,
                                                     cs_uint16 num_pjo_oxuv,
                                                     cs_uint16 rate)              /* Bugzilla 26729 */
/* INPUTS     : o Line Module Id                                    */
/*              o Line Slice                                        */
/*              o Client Module Id                                  */
/*              o Client Slice                                      */
/*              o k divider                                         */
/*              o Bytes per OxU3 frame                              */
/*              o Payload bytes per OxU3 frame                      */
/*              o Mode                                              */
/*              o Number of PJOs used by the OxUk frame             */
/*              o Rate                                              */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/*   Client RX         : 1 to 1 Mapping                             */
/*   Line TX           : ASYNC Mapping                              */
/*   Line RX           : 1 to 1 Mapping                             */
/*   Client TX         : 1 to 1 Mapping                             */
/*                                                                  */
/*                                                                  */
/*   [slice_line]  Specified as TEN_SLICE0 (0), TEN_SLICE1 (1),     */
/*     TEN_SLICE2 (2), TEN_SLICE3 (3) or TEN_SLICE_ALL (0xFF)       */
/*                                                                  */
/*   [slice_client]  Specified as TEN_SLICE0 (0), TEN_SLICE1 (1),   */
/*     TEN_SLICE2 (2), TEN_SLICE3 (3) or TEN_SLICE_ALL (0xFF)       */
/*                                                                  */
/*   [k_divider] specifies the value of constant 'k'                */
/*     Async : 16 - 64                                              */
/*     Sync  : 16 - 255                                             */
/*                                                                  */
/*   [n1] specifies number of bytes per OxUk frame                  */
/*   [m1] specifies number of client bytes per OxUk frame           */
/*      Value is application dependent                              */
/*                                                                  */
/*   [mode] specifies monolithic de-wrapping level of justification */
/*     TEN_OXU3_MONO_ONE_LEVEL = 0                                  */
/*     TEN_OXU2_MONO_ONE_LEVEL = 1                                  */
/*                                                                  */
/*   [num_pjo] specifies the number of positive justification       */
/*                  bytes (First Level Mapping)                     */
/*     0 - 6                                                        */
/*                                                                  */
/*   [rate] is used to identify 10G vs 40G                          */
/*     TEN_SLICE_10G = 0                                            */
/*     TEN_SLICE_40G = 1                                            */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  cs_status rtn = CS_OK;
  cs_uint16 dev_id;
  ten_dev_cb_t *pdevcb;
  cs_uint32 num_hi, num_lo, denom_hi, denom_lo, ac1_hi=0, ac1_lo=0, ac2_hi=0, ac2_lo=0, ad1=0, ad2=0;
  cs_uint8 cfg=0, cfgpd0=0, jc_thresh=0;
  cs_uint8 max_pjo;
  cs_uint32 n2=1, m2=1;
  cs_char8 *func = "ten_syncdsync_trans_1to1_async_1to1_config";  

  CS_PRINT("%s() module_id_line=%s, slice_line=%s, module_id_client=%s, slice_client=%s\n",
           func,
           ten_module_strings[module_id_line&1],
           ten_slice_strings[slice_line],
           ten_module_strings[module_id_client&1],
           ten_slice_strings[slice_client]);

  dev_id = TEN_MOD_ID_TO_DEV_ID(module_id_line);
  pdevcb = TEN_DEV_ID_TO_DEVCB_PTR(dev_id);

  /* Client RX */
  ten_syncdsync_config_1_to_1(module_id_client,
                              slice_client,
                              ((module_id_line & 1) * 4) + slice_line,
                              CS_RX, 
                              k_divider);

  /*num    = m1 * m2 * trans_num; */
  long_multiply(m1, m2*pdevcb->syncdsync_thread_cb[slice_client].transcode_num);
  num_hi = hi_word;
  num_lo = low_word;

  /* denom  = n1 * n2 * k_divider * trans_denom; */
  long_multiply(n1*k_divider, n2*pdevcb->syncdsync_thread_cb[slice_client].transcode_denom);
  denom_hi = hi_word;
  denom_lo = low_word;

  /* ac1 = n1 * m2; */
  ac1_hi = 0;
  ac1_lo = 0;

  /* ac2 = n1 * n2 * trans_num; */
  if(mode == TEN_OXU2_MONO_ONE_LEVEL)
    long_multiply(n1, n2*pdevcb->syncdsync_thread_cb[slice_client].transcode_num);
  else
    long_multiply(n1/4, n2*pdevcb->syncdsync_thread_cb[slice_client].transcode_num);

  ac2_hi = hi_word;
  ac2_lo = low_word;

  ad1 = 0;
  ad2 = num_pjo_oxuv*pdevcb->syncdsync_thread_cb[slice_client].transcode_num;

  cfg    = mode;
  cfgpd0 = 0x01;

  jc_thresh = (cs_uint32)_ten_floor((cs_float)(2.0 * ((cs_float)k_divider)/((2.0 * (cs_float)num_pjo_oxuv) + 1.0)));  /* Bugzilla #26345 */
  max_pjo = (cs_uint8)num_pjo_oxuv;

  /* Line TX */
  ten_syncdsynctx_cfg(module_id_line,
                      slice_line,
                      ((module_id_client & 1) * 4) + slice_client, 
                      num_hi, num_lo, denom_hi, denom_lo,
                      ac1_hi, ac1_lo, ac2_hi, ac2_lo,
                      ad1, ad2,
                      cfg, cfgpd0,
                      jc_thresh,
                      max_pjo);

  /* Bugzilla 26729 Start */
  if(rate == TEN_SLICE_40G) {
    ten_syncdsynctx_cfg(module_id_line,
                        3,
                        ((module_id_client & 1) * 4) + slice_client, 
                        num_hi, num_lo, denom_hi, denom_lo,
                        ac1_hi, ac1_lo, ac2_hi, ac2_lo,
                        ad1, ad2,
                        cfg, cfgpd0,
                        jc_thresh,
                        max_pjo);
  }
  /* Bugzilla 26729 End */

  /* Line RX */
  ten_syncdsync_config_1_to_1(module_id_line,
                              slice_line,
                              ((module_id_client & 1) * 4) + slice_client,
                              CS_RX, 
                              k_divider);

    /* Client TX */
  ten_syncdsync_config_1_to_1(module_id_client,
                              slice_client,
                              ((module_id_line & 1) * 4) + slice_line,
                              CS_TX, 
                              k_divider);

  return (rtn);
}

/********************************************************************/
/* $rtn_hdr_start  SYNCDSYNC SYNC ASYNC MAPPING CONFIG              */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : SYNCDSYNC                                           */
/* CHIP       : Tenabo                                              */
cs_status ten_syncdsync_trans_sync_async_config(cs_uint16 module_id_line,
                                                cs_uint8  slice_line, 
                                                cs_uint16 module_id_client,
                                                cs_uint8  slice_client,
                                                cs_uint8  k_divider,
                                                cs_uint32 n1,
                                                cs_uint32 m1,
                                                cs_uint32 n2, 
                                                cs_uint32 m2,
                                                cs_uint8  mode,
                                                cs_uint16 num_pjo_oxuv,
                                                cs_uint16 rate)           /* Bugzilla 26729 */
/* INPUTS     : o Line Module Id                                    */
/*              o Line Slice                                        */
/*              o Client Module Id                                  */
/*              o Client Slice                                      */
/*              o k divider                                         */
/*              o Bytes per client OxU3 frame                       */
/*              o Payload bytes per client OxU3 frame               */
/*              o Bytes per line OxU3 frame                         */
/*              o Payload bytes per line OxU3 frame                 */
/*              o Mode                                              */
/*              o Number of PJOs used by the OxUk frame             */
/*              o Rate                                              */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/*   Client RX         : SYNC Mapping                               */
/*   Line TX           : ASYNC Mapping                              */
/*   Line RX           : ASYNC Mapping                              */
/*   Client TX         : 1 TO 1 Mapping                             */
/*                                                                  */
/*   [slice_line]  Specified as TEN_SLICE0 (0), TEN_SLICE1 (1),     */
/*     TEN_SLICE2 (2), TEN_SLICE3 (3) or TEN_SLICE_ALL (0xFF)       */
/*                                                                  */
/*   [slice_client]  Specified as TEN_SLICE0 (0), TEN_SLICE1 (1),   */
/*     TEN_SLICE2 (2), TEN_SLICE3 (3) or TEN_SLICE_ALL (0xFF)       */
/*                                                                  */
/*   [k_divider] specifies the value of constant 'k'                */
/*     Async : 16 - 64                                              */
/*     Sync  : 16 - 255                                             */
/*                                                                  */
/*   [n1] specifies number of bytes per client OxUk frame           */
/*   [m1] specifies number of client bytes per client OxUk frame    */
/*   [n2] specifies number of bytes per line OxUk frame             */
/*   [m2] specifies number of client bytes per line OxUk frame      */
/*      Value is application dependent                              */
/*                                                                  */
/*   [mode] specifies monolithic de-wrapping level of justification */
/*     TEN_OXU3_MONO_ONE_LEVEL = 0                                  */
/*     TEN_OXU2_MONO_ONE_LEVEL = 1                                  */
/*                                                                  */
/*   [num_pjo] specifies the number of positive justification       */
/*                  bytes (First Level Mapping)                     */
/*     0 - 6                                                        */
/*                                                                  */
/*   [rate] is used to identify 10G vs 40G                          */
/*     TEN_SLICE_10G = 0                                            */
/*     TEN_SLICE_40G = 1                                            */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  cs_status rtn = CS_OK;
  cs_uint16 dev_id;
  ten_dev_cb_t *pdevcb;
  cs_uint32 num_hi, num_lo, denom_hi, denom_lo, ac1_hi=0, ac1_lo=0, ac2_hi=0, ac2_lo=0, ad1=0, ad2=0;
  cs_uint8 cfg=0, cfgpd0=0, jc_thresh=0;
  cs_uint8 max_pjo;
  cs_char8 *func = "ten_syncdsync_trans_sync_async_config";  

  CS_PRINT("%s()\n", func);
  CS_PRINT("    module_id_line=%s\n", ten_module_strings[module_id_line&1]);
  CS_PRINT("    slice_line=%s\n", ten_slice_strings[slice_line]);
  CS_PRINT("    module_id_client=%s\n", ten_module_strings[module_id_client&1]);
  CS_PRINT("    slice_client=%s\n", ten_slice_strings[slice_client]);
  CS_PRINT("    %s\n", ten_hl_syncdsync_mode_strings[mode]);
  CS_PRINT("    k_divider    = %d\n", k_divider);
  CS_PRINT("    n1           = 0x%04X\n", n1);
  CS_PRINT("    m1           = 0x%04X\n", m1);
  CS_PRINT("    n2           = 0x%04X\n", n2);
  CS_PRINT("    m2           = 0x%04X\n", m2);
  CS_PRINT("    num_pjo_oxuv = %d\n", num_pjo_oxuv);
  CS_PRINT("    rate         = %s\n", ten_slice_mode_strings[rate]);


  dev_id = TEN_MOD_ID_TO_DEV_ID(module_id_line);
  pdevcb = TEN_DEV_ID_TO_DEVCB_PTR(dev_id);

  /*num    = m1 * m2; */
  long_multiply(m1, 1);
  num_hi = hi_word;
  num_lo = low_word;

  /* denom  = n1 * n2 * k_divider; */
  long_multiply(n1*k_divider, 1);
  denom_hi = hi_word;
  denom_lo = low_word;

  /* Client RX */
  ten_syncdsyncrx_cfg(module_id_client,
                      slice_client,
                      num_hi, num_lo, denom_hi, denom_lo,
                      0,0,0,0,0,0,0);

  /* Line TX */
  /*num    = m1 * m2 * trans_num; */
  long_multiply(1, m2*pdevcb->syncdsync_thread_cb[slice_client].transcode_num);
  num_hi = hi_word;
  num_lo = low_word;

  /* denom  = n1 * n2 * k_divider * trans_denom; */
  long_multiply(k_divider, n2*pdevcb->syncdsync_thread_cb[slice_client].transcode_denom);
  denom_hi = hi_word;
  denom_lo = low_word;

  /* ac1 = n1 * m2; */
  ac1_hi = 0;
  ac1_lo = 0;

  /* ac2 = n1 * n2 * trans_num; */
  if(mode == TEN_OXU2_MONO_ONE_LEVEL)
    long_multiply(1, n2*pdevcb->syncdsync_thread_cb[slice_client].transcode_num);
  else
    long_multiply(1, (n2/4)*pdevcb->syncdsync_thread_cb[slice_client].transcode_num);

  ac2_hi = hi_word;
  ac2_lo = low_word;

  ad1 = 0;
  ad2 = num_pjo_oxuv*pdevcb->syncdsync_thread_cb[slice_client].transcode_num;

  cfg    = mode;
  cfgpd0 = 0x01;

  jc_thresh = (cs_uint32)_ten_floor((cs_float)(2.0 * ((cs_float)k_divider)/((2.0 * (cs_float)num_pjo_oxuv) + 1.0))); /* Bugzilla #26345 */
  max_pjo = (cs_uint8)num_pjo_oxuv;

  ten_syncdsynctx_cfg(module_id_line,
                      slice_line,
                      ((module_id_client & 1) * 4) + slice_client, 
                      num_hi, num_lo, denom_hi, denom_lo,
                      ac1_hi, ac1_lo, ac2_hi, ac2_lo,
                      ad1, ad2,
                      cfg, cfgpd0,
                      jc_thresh,
                      max_pjo);

  /* Bugzilla 26729 Start */
  if(rate == TEN_SLICE_40G) {
    ten_syncdsynctx_cfg(module_id_line,
                        3,
                        ((module_id_client & 1) * 4) + slice_client, 
                        num_hi, num_lo, denom_hi, denom_lo,
                        ac1_hi, ac1_lo, ac2_hi, ac2_lo,
                        ad1, ad2,
                        cfg, cfgpd0,
                        jc_thresh,
                        max_pjo);
  }
  /* Bugzilla 26729 End */

  /* Line RX */
  /*num    = m1 * m2 * trans_num; */
  long_multiply(1, m2*pdevcb->syncdsync_thread_cb[slice_client].P_client);
  num_hi = hi_word;
  num_lo = low_word;

  /* denom  = n1 * n2 * k_divider * trans_denom; */
  /*long_multiply(k_divider, n2*239);*/
  long_multiply(k_divider, n2*pdevcb->syncdsync_thread_cb[slice_client].Q_client);  /* Bugzilla 27167 */
  denom_hi = hi_word;
  denom_lo = low_word;

  /* ac1 = n1 * m2; */
  ac1_hi = 0;
  ac1_lo = 0;

  /* ac2 = n1 * n2 * trans_num; */
  if(mode == TEN_OXU2_MONO_ONE_LEVEL)
    long_multiply(1, n2*pdevcb->syncdsync_thread_cb[slice_client].P_client);
  else
    long_multiply(1, (n2/4)*pdevcb->syncdsync_thread_cb[slice_client].P_client);

  ac2_hi = hi_word;
  ac2_lo = low_word;

  ad1 = 0;
  ad2 = num_pjo_oxuv*pdevcb->syncdsync_thread_cb[slice_client].P_client;

  cfg    = mode;
  cfgpd0 = 0x01;

  jc_thresh = (cs_uint32)_ten_floor((cs_float)(2.0 * ((cs_float)k_divider)/((2.0 * (cs_float)num_pjo_oxuv) + 1.0))); /* Bugzilla #26345 */
  max_pjo = (cs_uint8)num_pjo_oxuv;

  /* Bugzilla 26729 Start */
  ten_syncdsyncrx_cfg(module_id_line,
                      slice_line,
                      num_hi, num_lo, denom_hi, denom_lo,
                      ac1_hi, ac1_lo, ac2_hi, ac2_lo,
                      ad1, ad2,
                      cfg);

  if(rate == TEN_SLICE_40G) {
    ten_syncdsyncrx_cfg(module_id_line,
                        3,
                        num_hi, num_lo, denom_hi, denom_lo,
                        ac1_hi, ac1_lo, ac2_hi, ac2_lo,
                        ad1, ad2,
                        cfg);
  }
  /* Bugzilla 26729 End */

  /* Client TX */
  ten_syncdsync_config_1_to_1(module_id_client,
                              slice_client,
                              /*3,  */                                        /* Bugzilla 29841 Must use slice 3 so that clock with RX justifications is used */
                              ((module_id_line & 1) * 4) + slice_line,
                              CS_TX,
                              k_divider);

  return (rtn);
}

/********************************************************************/
/* $rtn_hdr_start  SYNCDSYNC SYNC ASYNC MAPPING CONFIG              */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : SYNCDSYNC                                           */
/* CHIP       : Tenabo                                              */
cs_status ten_syncdsync_trans_async_asyncx4_config(cs_uint16 module_id_line,
                                                cs_uint8  slice_line, 
                                                cs_uint16 module_id_client,
                                                cs_uint8  slice_client,
                                                cs_uint8  k_divider,
                                                cs_uint32 n1,
                                                cs_uint32 m1,
                                                cs_uint32 n2, 
                                                cs_uint32 m2,
                                                cs_uint8  mode,
                                                cs_uint16 num_pjo_oxuv1,
                                                cs_uint16 num_pjo_oxuv2,
                                                cs_uint16 rate)              /* Bugzilla 26729 */
/* INPUTS     : o Line Module Id                                    */
/*              o Line Slice                                        */
/*              o Client Module Id                                  */
/*              o Client Slice                                      */
/*              o k divider                                         */
/*              o Bytes per client OxU3 frame                       */
/*              o Payload bytes per client OxU3 frame               */
/*              o Bytes per line OxU3 frame                         */
/*              o Payload bytes per line OxU3 frame                 */
/*              o Mode                                              */
/*              o Number of PJOs used by the client OxUk frame      */
/*              o Number of PJOs used by the line OxUk frame        */
/*              o Rate                                              */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/*   Client RX         : SYNC Mapping                               */
/*   Line TX           : ASYNC Mapping                              */
/*   Line RX           : ASYNC Mapping                              */
/*   Client TX         : 1 TO 1 Mapping                             */
/*                                                                  */
/*   [slice_line]  Specified as TEN_SLICE0 (0), TEN_SLICE1 (1),     */
/*     TEN_SLICE2 (2), TEN_SLICE3 (3) or TEN_SLICE_ALL (0xFF)       */
/*                                                                  */
/*   [slice_client]  Specified as TEN_SLICE0 (0), TEN_SLICE1 (1),   */
/*     TEN_SLICE2 (2), TEN_SLICE3 (3) or TEN_SLICE_ALL (0xFF)       */
/*                                                                  */
/*   [k_divider] specifies the value of constant 'k'                */
/*     Async : 16 - 64                                              */
/*     Sync  : 16 - 255                                             */
/*                                                                  */
/*   [n1] specifies number of bytes per client OxUk frame           */
/*   [m1] specifies number of client bytes per client OxUk frame    */
/*   [n2] specifies number of bytes per line OxUk frame             */
/*   [m2] specifies number of client bytes per line OxUk frame      */
/*      Value is application dependent                              */
/*                                                                  */
/*   [mode] specifies monolithic de-wrapping level of justification */
/*     TEN_OXU3_MONO_ONE_LEVEL = 0                                  */
/*     TEN_OXU2_MONO_ONE_LEVEL = 1                                  */
/*                                                                  */
/*   [num_pjo] specifies the number of positive justification       */
/*                  bytes (First Level Mapping)                     */
/*     0 - 6                                                        */
/*                                                                  */
/*   [rate] is used to identify 10G vs 40G                          */
/*     TEN_SLICE_10G = 0                                            */
/*     TEN_SLICE_40G = 1                                            */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  cs_status rtn = CS_OK;
  cs_uint16 dev_id;
  ten_dev_cb_t *pdevcb;
  cs_uint32 num_hi, num_lo, denom_hi, denom_lo, ac1_hi=0, ac1_lo=0, ac2_hi=0, ac2_lo=0, ad1=0, ad2=0;
  cs_uint8 cfg=0, cfgpd0=0, jc_thresh=0;
  cs_uint8 max_pjo, slice;
  cs_char8 *func = "ten_syncdsync_trans_async_asyncx4_config";  

  CS_PRINT("%s() module_id_line=%s, slice_line=%s, module_id_client=%s, slice_client=%s\n",
           func,
           ten_module_strings[module_id_line&1],
           ten_slice_strings[slice_line],
           ten_module_strings[module_id_client&1],
           ten_slice_strings[slice_client]);

  dev_id = TEN_MOD_ID_TO_DEV_ID(module_id_line);
  pdevcb = TEN_DEV_ID_TO_DEVCB_PTR(dev_id);

  /*num    = m1 * m2; */
  long_multiply(m1, 1);
  num_hi = hi_word;
  num_lo = low_word;

  /* denom  = n1 * n2 * k_divider; */
  long_multiply(n1*k_divider, 1);
  denom_hi = hi_word;
  denom_lo = low_word;

  /* ac1 = n1 * m2; */
  ac1_hi = 0;
  ac1_lo = 0;

  /* ac2 = n1 * n2 * trans_num; */
  if(mode == TEN_OXU2_MONO_ONE_LEVEL)
    long_multiply(n1, pdevcb->syncdsync_thread_cb[slice_client].transcode_num);
  else
    long_multiply(n1/4, pdevcb->syncdsync_thread_cb[slice_client].transcode_num);

  ac2_hi = hi_word;
  ac2_lo = low_word;

  ad1 = 0;
  ad2 = num_pjo_oxuv1*pdevcb->syncdsync_thread_cb[slice_client].transcode_num;

  cfg    = mode;
  cfgpd0 = 0x01;

  jc_thresh = (cs_uint32)_ten_floor((cs_float)(2.0 * ((cs_float)k_divider)/((2.0 * (cs_float)num_pjo_oxuv1) + 1.0))); /* Bugzilla #26345 */
  max_pjo = (cs_uint8)num_pjo_oxuv1;

  /* Client RX */
  ten_syncdsyncrx_cfg(module_id_client,
                      slice_client,
                      num_hi, num_lo, denom_hi, denom_lo,
                      ac1_hi, ac1_lo, ac2_hi, ac2_lo,
                      ad1, ad2,
                      cfg);

  /* Bugzilla 26729 Start */
  if(rate == TEN_SLICE_40G) {
    ten_syncdsyncrx_cfg(module_id_client,
                        3,
                        num_hi, num_lo, denom_hi, denom_lo,
                        ac1_hi, ac1_lo, ac2_hi, ac2_lo,
                        ad1, ad2,
                        cfg);
  }
  /* Bugzilla 26729 End */

  /* Client TX x 4 */
  for(slice=0;slice<4;slice++) {
    ten_syncdsynctx_cfg(module_id_client,
                        slice,
                        ((module_id_line & 1) * 4) + slice_line, 
                        num_hi, num_lo, denom_hi, denom_lo,
                        ac1_hi, ac1_lo, ac2_hi, ac2_lo,
                        ad1, ad2,
                        cfg, cfgpd0,
                        jc_thresh,
                        max_pjo);
  }

  /*num    = m1 * m2 * trans_num; */
  long_multiply(1, m2*pdevcb->syncdsync_thread_cb[slice_client].transcode_num);
  num_hi = hi_word;
  num_lo = low_word;

  /* denom  = n1 * n2 * k_divider * trans_denom; */
  long_multiply(k_divider, n2*pdevcb->syncdsync_thread_cb[slice_client].transcode_denom);
  denom_hi = hi_word;
  denom_lo = low_word;

  /* ac1 = n1 * m2; */
  ac1_hi = 0;
  ac1_lo = 0;

  /* ac2 = n1 * n2 * trans_num; */
  if(mode == TEN_OXU2_MONO_ONE_LEVEL)
    long_multiply(1, n2*pdevcb->syncdsync_thread_cb[slice_client].transcode_num);
  else
    long_multiply(1, (n2/4)*pdevcb->syncdsync_thread_cb[slice_client].transcode_num);

  ac2_hi = hi_word;
  ac2_lo = low_word;

  ad1 = 0;
  ad2 = num_pjo_oxuv2*pdevcb->syncdsync_thread_cb[slice_client].transcode_num;

  cfg    = mode;
  cfgpd0 = 0x01;

  jc_thresh = (cs_uint32)_ten_floor((cs_float)(2.0 * ((cs_float)k_divider)/((2.0 * (cs_float)num_pjo_oxuv2) + 1.0)));  /* Bugzilla #26345 */
  max_pjo = (cs_uint8)num_pjo_oxuv2;

  /* Line RX */
  ten_syncdsyncrx_cfg(module_id_line,
                      slice_line,
                      num_hi, num_lo, denom_hi, denom_lo,
                      ac1_hi, ac1_lo, ac2_hi, ac2_lo,
                      ad1, ad2,
                      cfg);

  /* Bugzilla 26729 Start */
  if(rate == TEN_SLICE_40G) {
    ten_syncdsyncrx_cfg(module_id_line,
                        3,
                        num_hi, num_lo, denom_hi, denom_lo,
                        ac1_hi, ac1_lo, ac2_hi, ac2_lo,
                        ad1, ad2,
                        cfg);
  }
  /* Bugzilla 26729 End */

  /* Line TX */
  ten_syncdsynctx_cfg(module_id_line,
                      slice_line,
                      ((module_id_client & 1) * 4) + slice_client, 
                      num_hi, num_lo, denom_hi, denom_lo,
                      ac1_hi, ac1_lo, ac2_hi, ac2_lo,
                      ad1, ad2,
                      cfg, cfgpd0,
                      jc_thresh,
                      max_pjo);

  /* Bugzilla 26729 Start */
  if(rate == TEN_SLICE_40G) {
    ten_syncdsynctx_cfg(module_id_line,
                        3,
                        ((module_id_client & 1) * 4) + slice_client, 
                        num_hi, num_lo, denom_hi, denom_lo,
                        ac1_hi, ac1_lo, ac2_hi, ac2_lo,
                        ad1, ad2,
                        cfg, cfgpd0,
                        jc_thresh,
                        max_pjo);
  }
  /* Bugzilla 26729 End */

  return (rtn);
}

/* Bugzilla 28006 Start */
/********************************************************************/
/* $rtn_hdr_start  SYNCDSYNC ASYNC ASYNC MAPPING CONFIG             */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : SYNCDSYNC                                           */
/* CHIP       : Tenabo                                              */
cs_status ten_syncdsync_trans_async_async_1level_config(cs_uint16 module_id_line,
                                                cs_uint8  slice_line, 
                                                cs_uint16 module_id_client,
                                                cs_uint8  slice_client,
                                                cs_uint8  k_divider,
                                                cs_uint32 n1,
                                                cs_uint32 m1,
                                                cs_uint32 n2, 
                                                cs_uint32 m2,
                                                cs_uint8  mode,
                                                cs_uint16 num_pjo_oxuv1,
                                                cs_uint16 num_pjo_oxuv2,
                                                cs_uint16 rate)
/* INPUTS     : o Line Module Id                                    */
/*              o Line Slice                                        */
/*              o Client Module Id                                  */
/*              o Client Slice                                      */
/*              o k divider                                         */
/*              o Bytes per client OxU3 frame                       */
/*              o Payload bytes per client OxU3 frame               */
/*              o Bytes per line OxU3 frame                         */
/*              o Payload bytes per line OxU3 frame                 */
/*              o Mode                                              */
/*              o Number of PJOs used by the Client OxUk frame      */
/*              o Number of PJOs used by the Cine OxUk frame        */
/*              o Rate                                              */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/*   Client RX         : ASYNC Mapping                              */
/*   Line TX           : ASYNC Mapping                              */
/*   Line RX           : ASYNC Mapping                              */
/*   Client TX         : ASYNC Mapping                              */
/*                                                                  */
/*   [slice_line]  Specified as TEN_SLICE0 (0), TEN_SLICE1 (1),     */
/*     TEN_SLICE2 (2), TEN_SLICE3 (3) or TEN_SLICE_ALL (0xFF)       */
/*                                                                  */
/*   [slice_client]  Specified as TEN_SLICE0 (0), TEN_SLICE1 (1),   */
/*     TEN_SLICE2 (2), TEN_SLICE3 (3) or TEN_SLICE_ALL (0xFF)       */
/*                                                                  */
/*   [k_divider] specifies the value of constant 'k'                */
/*     Async : 16 - 64                                              */
/*     Sync  : 16 - 255                                             */
/*                                                                  */
/*   [n1] number of bytes per OxUk frame on Client side             */
/*   [m1] number of client (payload) bytes per OxUk frame on Client side */
/*   [n2] number of bytes per OxUk frame on Line side               */
/*   [m2] number of client (payload) bytes per OxUk frame on Line side */
/*      Value is application dependent                              */
/*                                                                  */
/*   [mode] specifies monolithic de-wrapping level of justification */
/*     TEN_OXU2_MONO_ONE_LEVEL = 0                                  */
/*     TEN_OXU3_MONO_ONE_LEVEL = 1                                  */
/*                                                                  */
/*   [num_pjo_oxuv1] number of positive justification bytes         */ 
/*                   (First Level Mapping) on Client side           */
/*     0 - 6                                                        */
/*                                                                  */
/*   [num_pjo_oxuv2] number of positive justification bytes         */ 
/*                   (First Level Mapping) on Line side             */
/*     0 - 6                                                        */
/*                                                                  */
/*   [rate] is used to identify 10G vs 40G                          */
/*     TEN_SLICE_10G = 0                                            */
/*     TEN_SLICE_40G = 1                                            */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  cs_status rtn = CS_OK;
  cs_uint16 dev_id;
  ten_dev_cb_t *pdevcb;
  cs_uint32 num_hi, num_lo, denom_hi, denom_lo, ac1_hi=0, ac1_lo=0, ac2_hi=0, ac2_lo=0, ad1=0, ad2=0;
  cs_uint8 cfg=0, cfgpd0=0, jc_thresh=0;
  cs_uint8 max_pjo;
  cs_char8 *func = "ten_syncdsync_trans_async_async_1level_config";  

  CS_PRINT("%s()\n", func);
  CS_PRINT("    module_id_line = %s\n", ten_module_strings[module_id_line&1]);
  CS_PRINT("    slice_line = %s\n", ten_slice_strings[slice_line]);
  CS_PRINT("    module_id_client = %s\n", ten_module_strings[module_id_client&1]);
  CS_PRINT("    slice_client = %s\n", ten_slice_strings[slice_client]);
  CS_PRINT("    k_divider = %d\n", k_divider);
  CS_PRINT("    n1 = 0x%X\n", n1);
  CS_PRINT("    m1 = 0x%X\n", m1);
  CS_PRINT("    n2 = 0x%X\n", n2);
  CS_PRINT("    m2 = 0x%X\n", m2);
  CS_PRINT("    mode = %s\n", ten_hl_syncdsync_mode_strings[mode]);
  CS_PRINT("    num_pjo_oxuv1 = %d\n", num_pjo_oxuv1);
  CS_PRINT("    num_pjo_oxuv2 = %d\n", num_pjo_oxuv2);
  CS_PRINT("    rate = %s\n", ten_slice_mode_strings[rate]);

  dev_id = TEN_MOD_ID_TO_DEV_ID(module_id_line);
  pdevcb = TEN_DEV_ID_TO_DEVCB_PTR(dev_id);

  CS_PRINT("    transcode_num = %d\n", pdevcb->syncdsync_thread_cb[slice_client].transcode_num);
  CS_PRINT("    transcode_denom = %d\n", pdevcb->syncdsync_thread_cb[slice_client].transcode_denom);

  /******************************************/
  /************** Client RX *****************/
  /******************************************/
  /*num    = m1 * m2; */
  long_multiply(m1, 1*pdevcb->syncdsync_thread_cb[slice_client].transcode_num);   /* 1 level, so only use client side bytes */
  num_hi = hi_word;
  num_lo = low_word;
  CS_PRINT("    client RX    num_lo = 0x%X, num_hi = 0x%X\n", num_lo, num_hi);

  /* denom  = n1 * n2 * k_divider; */
  long_multiply(n1*k_divider, 1*pdevcb->syncdsync_thread_cb[slice_client].transcode_denom); /* 1 level, so only use client side bytes */
  denom_hi = hi_word;
  denom_lo = low_word;

  /* ac1 = n1 * m2; */
  ac1_hi = 0;           /* Zero for 1 level */
  ac1_lo = 0;
  
  /* ac2 = n1 * n2 * trans_num; */
  if (mode == TEN_OXU2_MONO_ONE_LEVEL)
    long_multiply(n1, pdevcb->syncdsync_thread_cb[slice_client].transcode_num);
  else
    long_multiply(n1/4, pdevcb->syncdsync_thread_cb[slice_client].transcode_num);
  
  ac2_hi = hi_word;
  ac2_lo = low_word;
  
  ad1 = 0;
  ad2 = num_pjo_oxuv1*pdevcb->syncdsync_thread_cb[slice_client].transcode_num;

  cfg    = mode; /* TEN_OXU2_MONO_ONE_LEVEL, TEN_OXU3_MONO_ONE_LEVEL, TEN_ODTU23_MUX_ONE_LEVEL or TEN_ODTU23_ODU2_MUX_TWO_LEVEL*/
  cfgpd0 = 0x01;  /* Three state phase detector enabled */
  
  jc_thresh = (cs_uint32)_ten_floor((cs_float)(2.0 * ((cs_float)k_divider)/((2.0 * (cs_float)num_pjo_oxuv1) + 1.0)));
  max_pjo = (cs_uint8)num_pjo_oxuv1;
  
  ten_syncdsyncrx_cfg(module_id_client,
                      slice_client,
                      num_hi, num_lo, denom_hi, denom_lo,
                      ac1_hi, ac1_lo, ac2_hi, ac2_lo,
                      ad1, ad2,
                      cfg);

  if(rate == TEN_SLICE_40G) {
   #if 0 
    /* ???????????????????????????*/
    ten_syncdsyncrx_cfg(module_id_client,
                        2,
                        num_hi, num_lo, denom_hi, denom_lo,
                        ac1_hi, ac1_lo, ac2_hi, ac2_lo,
                        ad1, ad2,
                        cfg);
    /* ???????????????????????????*/
   #endif
    ten_syncdsyncrx_cfg(module_id_client,
                        3,
                        num_hi, num_lo, denom_hi, denom_lo,
                        ac1_hi, ac1_lo, ac2_hi, ac2_lo,
                        ad1, ad2,
                        cfg);
  }
  
  /******************************************/
  /************** Client TX *****************/
  /******************************************/
  ten_syncdsynctx_cfg(module_id_client,
                      slice_client,
                      ((module_id_line & 1) * 4) + slice_line, 
                      num_hi, num_lo, denom_hi, denom_lo,
                      ac1_hi, ac1_lo, ac2_hi, ac2_lo,
                      ad1, ad2,
                      cfg, cfgpd0,
                      jc_thresh,
                      max_pjo);

  if(rate == TEN_SLICE_40G) {
   #if 0 
    /* ???????????????????????????*/
    ten_syncdsynctx_cfg(module_id_client,
                        2,
                        ((module_id_line & 1) * 4) + slice_line, 
                        num_hi, num_lo, denom_hi, denom_lo,
                        ac1_hi, ac1_lo, ac2_hi, ac2_lo,
                        ad1, ad2,
                        cfg, cfgpd0,
                        jc_thresh,
                        max_pjo);
    /* ???????????????????????????*/
   #endif
    ten_syncdsynctx_cfg(module_id_client,
                        3,
                        ((module_id_line & 1) * 4) + slice_line, 
                        num_hi, num_lo, denom_hi, denom_lo,
                        ac1_hi, ac1_lo, ac2_hi, ac2_lo,
                        ad1, ad2,
                        cfg, cfgpd0,
                        jc_thresh,
                        max_pjo);
  }



  /******************************************/
  /*************** Line RX ******************/
  /******************************************/
  /* num = m1 * m2 * trans_num; */
  long_multiply(1, m2*pdevcb->syncdsync_thread_cb[slice_client].transcode_num);  /* 1 level, so only use client side bytes */
  num_hi = hi_word;
  num_lo = low_word;

  /* denom = n1 * n2 * k_divider * trans_denom; */
  long_multiply(k_divider, n2*pdevcb->syncdsync_thread_cb[slice_client].transcode_denom);
  denom_hi = hi_word;
  denom_lo = low_word;

  /* ac1 = n1 * m2; */
  ac1_hi = 0;
  ac1_lo = 0;
  /*ac1_lo = 1;*/  /* ???? */

  /* ac2 = n1 * n2 * trans_num; */
  if(mode == TEN_OXU2_MONO_ONE_LEVEL)
    long_multiply(1, n2*pdevcb->syncdsync_thread_cb[slice_client].transcode_num);
  else
    long_multiply(1, (n2/4)*pdevcb->syncdsync_thread_cb[slice_client].transcode_num);

  ac2_hi = hi_word;
  ac2_lo = low_word;

  ad1 = 0;
  ad2 = num_pjo_oxuv2*pdevcb->syncdsync_thread_cb[slice_client].transcode_num;

  /*cfg    = mode;*/
  cfg    = 1;
  cfgpd0 = 0x01;  /* Three state phase detector enabled */

  jc_thresh = (cs_uint32)_ten_floor((cs_float)(2.0 * ((cs_float)k_divider)/((2.0 * (cs_float)num_pjo_oxuv2) + 1.0)));
  max_pjo = (cs_uint8)num_pjo_oxuv2;

  ten_syncdsyncrx_cfg(module_id_line,
                      slice_line,
                      num_hi, num_lo, denom_hi, denom_lo,
                      ac1_hi, ac1_lo, ac2_hi, ac2_lo,
                      ad1, ad2,
                      cfg);

  if(rate == TEN_SLICE_40G) {
   #if 0 
    /* ???????????????????????????*/
    ten_syncdsyncrx_cfg(module_id_line,
                        2,
                        num_hi, num_lo, denom_hi, denom_lo,
                        ac1_hi, ac1_lo, ac2_hi, ac2_lo,
                        ad1, ad2,
                        cfg);
    /* ???????????????????????????*/
   #endif
    ten_syncdsyncrx_cfg(module_id_line,
                        3,
                        num_hi, num_lo, denom_hi, denom_lo,
                        ac1_hi, ac1_lo, ac2_hi, ac2_lo,
                        ad1, ad2,
                        cfg);
  }

  /******************************************/
  /*************** Line TX ******************/
  /******************************************/
  ten_syncdsynctx_cfg(module_id_line,
                      slice_line,
                      ((module_id_client & 1) * 4) + slice_client, 
                      num_hi, num_lo, denom_hi, denom_lo,
                      ac1_hi, ac1_lo, ac2_hi, ac2_lo,
                      ad1, ad2,
                      cfg, cfgpd0,
                      jc_thresh,
                      max_pjo);

  if(rate == TEN_SLICE_40G) {
   #if 0 
    /* ???????????????????????????*/
    ten_syncdsynctx_cfg(module_id_line,
                        2,
                        ((module_id_client & 1) * 4) + slice_client, 
                        num_hi, num_lo, denom_hi, denom_lo,
                        ac1_hi, ac1_lo, ac2_hi, ac2_lo,
                        ad1, ad2,
                        cfg, cfgpd0,
                        jc_thresh,
                        max_pjo);
    /* ???????????????????????????*/
   #endif 
    ten_syncdsynctx_cfg(module_id_line,
                        3,
                        ((module_id_client & 1) * 4) + slice_client, 
                        num_hi, num_lo, denom_hi, denom_lo,
                        ac1_hi, ac1_lo, ac2_hi, ac2_lo,
                        ad1, ad2,
                        cfg, cfgpd0,
                        jc_thresh,
                        max_pjo);
  }


  return (rtn);
}
/* Bugzilla 28006 End */

/********************************************************************/
/* $rtn_hdr_start  SYNCDSYNC 1 TO 1 MAPPING CONFIG                  */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : SYNCDSYNC                                           */
/* CHIP       : Tenabo                                              */
cs_status ten_syncdsync_1_to_1_config(cs_uint16 module_id_line,
                                      cs_uint8  slice_line, 
                                      cs_uint16 module_id_client,
                                      cs_uint8  slice_client,
                                      cs_uint8  k_divider)
/* INPUTS     : o Line Module Id                                    */
/*              o Line Slice                                        */
/*              o Client Module Id                                  */
/*              o Client Slice                                      */
/*              o k divider                                         */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Configures the line to client path for 1to1 on client and two    */
/* level mapping on line side                                       */
/*                                                                  */
/*   [slice_line]  Specified as TEN_SLICE0 (0), TEN_SLICE1 (1),     */
/*     TEN_SLICE2 (2), TEN_SLICE3 (3) or TEN_SLICE_ALL (0xFF)       */
/*                                                                  */
/*   [slice_client]  Specified as TEN_SLICE0 (0), TEN_SLICE1 (1),   */
/*     TEN_SLICE2 (2), TEN_SLICE3 (3) or TEN_SLICE_ALL (0xFF)       */
/*                                                                  */
/*   [k_divider] specifies the value of constant 'k'                */
/*     Async : 16 - 64                                              */
/*     Sync  : 16 - 255                                             */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  cs_status rtn = CS_OK;
  cs_char8 *func = "ten_syncdsync_1_to_1_config";  

  CS_PRINT("%s() module_id_line=%s, slice_line=%s, module_id_client=%s, slice_client=%s\n",
           func,
           ten_module_strings[module_id_line&1],
           ten_slice_strings[slice_line],
           ten_module_strings[module_id_client&1],
           ten_slice_strings[slice_client]);

  /* Client RX */
  ten_syncdsync_config_1_to_1(module_id_client,
                              slice_client,
                              ((module_id_line & 1) * 4) + slice_line,
                              CS_RX, 
                              k_divider);
  /* Line TX */
  ten_syncdsync_config_1_to_1(module_id_line,
                              slice_line,
                              ((module_id_client & 1) * 4) + slice_client,
                              CS_TX, 
                              k_divider);
  /* Line RX */
  ten_syncdsync_config_1_to_1(module_id_line,
                              slice_line,
                              ((module_id_client & 1) * 4) + slice_client,
                              CS_RX, 
                              k_divider);
  /* Client TX */
  ten_syncdsync_config_1_to_1(module_id_client,
                              slice_client,
                              ((module_id_line & 1) * 4) + slice_line,
                              CS_TX, 
                              k_divider);

  return (rtn);
}

/********************************************************************/
/* $rtn_hdr_start  SYNCDSYNC SET CONTROL BLOCK 10G TRANS PARAMETERS */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : SYNCDSYNC                                           */
/* CHIP       : Tenabo                                              */
cs_status ten_syncdsync_set_cb_10g_transponder_t41(cs_uint16 dev_id,
                                                   cs_uint8 slice_client,
                                                   cs_int16 num_just_oxu2,
                                                   cs_uint8 num_pjo_oxu2,
                                                   cs_uint16 P_line,
                                                   cs_uint16 Q_line,
                                                   cs_uint16 P_client,
                                                   cs_uint16 Q_client,
                                                   cs_uint8 line_client_same,
                                                   cs_uint8 line_client_rate_equal,
                                                   cs_uint8 oduflex_enbl,
                                                   cs_uint8 oduflex_client_slice,
                                                   cs_uint8 oduflex_line_slice,
                                                   double client_rate, 
                                                   double xcon_client_rate,
                                                   double line_rate)
/* INPUTS     : o Device Id                                         */
/*              o Client Slice                                      */
/*              o 0xU2 Justification Bytes (C15 / FS)               */
/*              o 0xU2 PJO                                          */
/*              o Line Numerator (P)                                */
/*              o Line Denominator (Q)                              */
/*              o Client Numenrator (P)                             */
/*              o Client Denominator (Q)                            */
/*              o Line Client Identical Indicator                   */ 
/*              o Line Client Rate Relation Indicator               */
/*              o ODUflex enable                                    */
/*              o ODUflex Client Slice                              */
/*              o ODUflex Line Slice                                */
/*              o Client Rate                                       */
/*              o Rate of the signal crossing over XCON             */
/*              o Line Rate                                         */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Writes the syncdsync parameters for 10G transponder applications */
/* to the syncdsync control block                                   */
/*                                                                  */
/*   [slice_client] parameter specifies client's slice:             */
/*     TEN_SLICE0 = 0                                               */
/*     TEN_SLICE1 = 1                                               */
/*     TEN_SLICE2 = 2                                               */
/*     TEN_SLICE3 = 3                                               */
/*                                                                  */
/*   [num_just_oxu2] specifies the number of justification bytes -  */
/*                   C15 of FS                                      */
/*                                                                  */
/*   [num_pjo_oxu2] specifies the number of positive justification  */
/*                  bytes                                           */
/*     0 - 6                                                        */
/*                                                                  */
/*   [P_line] specifies the number of columns in the OTN frame on   */
/*            the line side                                         */
/*     236 - 301                                                    */
/*                                                                  */
/*   [Q_line] specifies the number of columns in the payload on the */
/*            line side                                             */
/*     236 - 238                                                    */
/*                                                                  */
/*   [P_client] specifies the number of columns in the OTN frame on */
/*              the client side                                     */
/*     236 - 301                                                    */
/*                                                                  */
/*   [Q_client] specifies the number of columns in the payload on   */
/*              the client side                                     */
/*     236 - 238                                                    */
/*                                                                  */
/*   [line_client_same] is used for 10G/40G transponder applications*/
/*   to indicate line and client type are identical - for syncdsync */
/*   to be programmed 1:1                                           */
/*     0 - line and client type are different                       */
/*     1 - line and client type are identical                       */
/*                                                                  */
/*   [line_client_rate_equal] is used in conjunction with           */
/*   line_client_same parameter to indicate presence of FECs on     */
/*   and clinet side if line and cline ttype are identical          */
/*     0 - line and client data rates are different                 */
/*     1 - line and client data rates are identical                 */
/*                                                                  */
/*   [oduflex_enbl] is used to indicate the mapping involves ODUflex*/
/*     0 - CS_DISABLE                                               */
/*     1 - CS_ENABLE                                                */
/*                                                                  */
/*   [oduflex_client_slice] specifies the slice on which ODUflex    */ 
/*   maps to client                                                 */
/*     TEN_SLICE0 = 0                                               */
/*     TEN_SLICE1 = 1                                               */
/*     TEN_SLICE2 = 2                                               */
/*     TEN_SLICE3 = 3                                               */
/*                                                                  */
/*   [oduflex_line_slice] specifies the channel on which the client */
/*   maps to ODUflex                                                */
/*     TEN_SLICE0 = 0                                               */
/*     TEN_SLICE1 = 1                                               */
/*     TEN_SLICE2 = 2                                               */
/*     TEN_SLICE3 = 3                                               */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  ten_dev_cb_t *pdevcb;
  cs_char8 *func = "ten_syncdsync_set_cb_10g_transponder_t41";  
  CS_PRINT("%s() %s\n", func, ten_slice_strings[slice_client]);
  CS_PRINT("    num_just_oxu2 = %d\n", num_just_oxu2);
  CS_PRINT("    num_pjo_oxu2 = %d\n", num_pjo_oxu2);
  CS_PRINT("    P_line = %d\n", P_line);
  CS_PRINT("    Q_line = %d\n", Q_line);
  CS_PRINT("    P_client = %d\n", P_client);
  CS_PRINT("    Q_client = %d\n", Q_client);
  CS_PRINT("    line_client_same = %d\n", line_client_same);
  CS_PRINT("    line_client_rate_equal = %d\n", line_client_rate_equal);
  CS_PRINT("    oduflex_enbl = %d\n", oduflex_enbl);
  CS_PRINT("    oduflex_client_slice = %d\n", oduflex_client_slice);
  CS_PRINT("    oduflex_line_slice = %d\n", oduflex_line_slice);
  CS_PRINT("    client_rate = %f\n", client_rate);
  CS_PRINT("    xcon_client_rate = %f\n", xcon_client_rate);
  CS_PRINT("    line_rate = %f\n", line_rate);

  pdevcb = TEN_DEV_ID_TO_DEVCB_PTR(dev_id);

  pdevcb->syncdsync_thread_cb[slice_client].num_just_oxu2 = num_just_oxu2;
  pdevcb->syncdsync_thread_cb[slice_client].num_pjo_oxu2  = num_pjo_oxu2;
  pdevcb->syncdsync_thread_cb[slice_client].P_line   = P_line;
  pdevcb->syncdsync_thread_cb[slice_client].Q_line   = Q_line;
  pdevcb->syncdsync_thread_cb[slice_client].P_client = P_client;
  pdevcb->syncdsync_thread_cb[slice_client].Q_client = Q_client;
  pdevcb->syncdsync_thread_cb[slice_client].line_client_same = line_client_same;
  pdevcb->syncdsync_thread_cb[slice_client].line_client_rate_equal = line_client_rate_equal;
  pdevcb->syncdsync_thread_cb[slice_client].client_rate = client_rate;
  pdevcb->syncdsync_thread_cb[slice_client].xcon_client_rate = xcon_client_rate;
  pdevcb->syncdsync_thread_cb[slice_client].line_rate = line_rate;
  pdevcb->oduflex_cb.enbl = oduflex_enbl;
  pdevcb->oduflex_cb.client_slice = oduflex_client_slice;
  pdevcb->oduflex_cb.line_slice = oduflex_line_slice;


  return CS_OK;
}

/********************************************************************/
/* $rtn_hdr_start  SYNCDSYNC SET CONTROL BLOCK 40G MUX PARAMETERS   */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : SYNCDSYNC                                           */
/* CHIP       : Tenabo                                              */
cs_status ten_syncdsync_set_cb_40g_muxponder_t41(cs_uint16 dev_id,
                                                 cs_uint8 slice_client,
                                                 cs_int16 num_just_oxu2,
                                                 cs_uint8 num_pjo_oxu2,
                                                 cs_int16 num_just_oxu3,
                                                 cs_uint8 num_pjo_oxu3,
                                                 cs_uint16 P_line,
                                                 cs_uint16 Q_line,
                                                 cs_uint16 P_client,
                                                 cs_uint16 Q_client,
                                                 double client_rate,
                                                 double xcon_client_rate,
                                                 double line_rate)
/* INPUTS     : o Device Id                                         */
/*              o Client Slice                                      */
/*              o 0xU2 Justification Bytes (C15 / FS)               */
/*              o 0xU2 PJO                                          */
/*              o 0xU3 Justification Bytes (C15 / FS)               */
/*              o 0xU3 PJO                                          */
/*              o Line Numerator (P)                                */
/*              o Line Denominator (Q)                              */
/*              o Client Numenrator (P)                             */
/*              o Client Denominator (Q)                            */
/*              o Client Rate                                       */
/*              o Low Order ODU2 rate                               */
/*              o Line Rate                                         */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Writes the syncdsync parameters for 40G muxponder applications   */
/* to the syncdsync control block                                   */
/*                                                                  */
/*   [slice_client] parameter specifies client's slice:             */
/*     TEN_SLICE0 = 0                                               */
/*     TEN_SLICE1 = 1                                               */
/*     TEN_SLICE2 = 2                                               */
/*     TEN_SLICE3 = 3                                               */
/*                                                                  */
/*   [num_just_oxu2] specifies the number of justification bytes -  */
/*                   C15 of FS (client -> OxU2)                     */
/*                                                                  */
/*   [num_pjo_oxu2] specifies the number of positive justification  */
/*                  bytes (client -> OxU2)                          */
/*     0 - 6                                                        */
/*                                                                  */
/*   [num_just_oxu3] specifies the number of justification bytes -  */
/*                   C15 of FS (OxU2 -> OxU3)                       */
/*                                                                  */
/*   [num_pjo_oxu3] specifies the number of positive justification  */
/*                  bytes (OxU2 -> OxU3)                            */
/*     0 - 6                                                        */
/*                                                                  */
/*   [P_line] specifies the number of columns in the OTN frame on   */
/*            the line side                                         */
/*     239 - 231                                                    */
/*                                                                  */
/*   [Q_line] specifies the number of columns in the payload on the */
/*            line side                                             */
/*     237 - 238                                                    */
/*                                                                  */
/*   [P_client] specifies the number of columns in the OTN frame on */
/*              the client side                                     */
/*     239 - 231                                                    */
/*                                                                  */
/*   [Q_client] specifies the number of columns in the payload on   */
/*              the client side                                     */
/*     237 - 238                                                    */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  ten_dev_cb_t *pdevcb;
  cs_char8 *func = "ten_syncdsync_set_cb_40g_muxponder_t41";  
  CS_PRINT("%s() %s\n", func, ten_slice_strings[slice_client]);
  CS_PRINT("    num_just_oxu2 = %d\n", num_just_oxu2);
  CS_PRINT("    num_pjo_oxu2 = %d\n", num_pjo_oxu2);
  CS_PRINT("    num_just_oxu3 = %d\n", num_just_oxu3);
  CS_PRINT("    num_pjo_oxu3 = %d\n", num_pjo_oxu3);
  CS_PRINT("    P_line = %d\n", P_line);
  CS_PRINT("    Q_line = %d\n", Q_line);
  CS_PRINT("    P_client = %d\n", P_client);
  CS_PRINT("    Q_client = %d\n", Q_client);
  CS_PRINT("    client_rate = %f\n", client_rate);
  CS_PRINT("    xcon_client_rate = %f\n", xcon_client_rate);
  CS_PRINT("    line_rate = %f\n", line_rate);

  pdevcb = TEN_DEV_ID_TO_DEVCB_PTR(dev_id);

  pdevcb->syncdsync_thread_cb[slice_client].num_just_oxu2 = num_just_oxu2;
  pdevcb->syncdsync_thread_cb[slice_client].num_pjo_oxu2  = num_pjo_oxu2;
  pdevcb->syncdsync_thread_cb[slice_client].num_just_oxu3 = num_just_oxu3;
  pdevcb->syncdsync_thread_cb[slice_client].num_pjo_oxu3  = num_pjo_oxu3;
  pdevcb->syncdsync_thread_cb[slice_client].P_line   = P_line;
  pdevcb->syncdsync_thread_cb[slice_client].Q_line   = Q_line;
  pdevcb->syncdsync_thread_cb[slice_client].P_client = P_client;
  pdevcb->syncdsync_thread_cb[slice_client].Q_client = Q_client;
  pdevcb->syncdsync_thread_cb[slice_client].client_rate = client_rate;
  pdevcb->syncdsync_thread_cb[slice_client].xcon_client_rate = xcon_client_rate;
  pdevcb->syncdsync_thread_cb[slice_client].line_rate = line_rate;

  return CS_OK;
}


/********************************************************************/
/* $rtn_hdr_start  SYNCDSYNC SET CONTROL BLOCK 40G TRANS PARAMETERS */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : HIGH LEVEL                                          */
/* CHIP       : Tenabo                                              */
cs_status ten_syncdsync_set_cb_40g_transponder_t41(cs_uint16 dev_id,
                                                   cs_uint8 slice_client,
                                                   cs_int16 num_just_oxu3,
                                                   cs_uint8 num_pjo_oxu3,
                                                   cs_uint16 P_line,
                                                   cs_uint16 Q_line,
                                                   cs_uint16 P_client,
                                                   cs_uint16 Q_client,
                                                   double client_rate, 
                                                   double xcon_client_rate,
                                                   double line_rate,
                                                   cs_uint8 line_client_same,
                                                   cs_uint8 line_client_rate_equal)
/* INPUTS     : o Device Id                                         */
/*              o Client Slice                                      */
/*              o 0xU3 Justification Bytes (C15 / FS)               */
/*              o 0xU3 PJO                                          */
/*              o Line Numerator (P)                                */
/*              o Line Denominator (Q)                              */
/*              o Client Numenrator (P)                             */
/*              o Client Denominator (Q)                            */
/*              o Client Rate                                       */
/*              o Low Order ODU2 rate                               */
/*              o Line Rate                                         */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Writes the syncdsync parameters for 40G muxponder applications   */
/* to the syncdsync control block                                   */
/*                                                                  */
/*   [slice_client] parameter specifies client's slice:             */
/*     TEN_SLICE0 = 0                                               */
/*     TEN_SLICE1 = 1                                               */
/*     TEN_SLICE2 = 2                                               */
/*     TEN_SLICE3 = 3                                               */
/*                                                                  */
/*   [num_just_oxu3] specifies the number of justification bytes -  */
/*                   C15 of FS (OxU2 -> OxU3)                       */
/*                                                                  */
/*   [num_pjo_oxu3] specifies the number of positive justification  */
/*                  bytes (OxU2 -> OxU3)                            */
/*     0 - 6                                                        */
/*                                                                  */
/*   [P_line] specifies the number of columns in the OTN frame on   */
/*            the line side                                         */
/*     239 - 24381                                                  */
/*                                                                  */
/*   [Q_line] specifies the number of columns in the payload on the */
/*            line side                                             */
/*     217 - 18445                                                  */
/*                                                                  */
/*   [P_client] specifies the number of columns in the OTN frame on */
/*              the client side                                     */
/*     239 - 24381                                                  */
/*                                                                  */
/*   [Q_client] specifies the number of columns in the payload on   */
/*              the client side                                     */
/*     217 - 18445                                                  */
/*                                                                  */
/*   [line_client_same] is used for 10G/40G transponder applications*/
/*   to indicate line and client type are identical - for syncdsync */
/*   to be programmed 1:1                                           */
/*     0 - line and client type are different                       */
/*     1 - line and client type are identical                       */
/*                                                                  */
/*   [line_client_rate_equal] is used in conjunction with           */
/*   line_client_same parameter to indicate presence of FECs on     */
/*   and clinet side if line and cline ttype are identical          */
/*     0 - line and client data rates are different                 */
/*     1 - line and client data rates are identical                 */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
  {
  ten_dev_cb_t *pdevcb;
  cs_char8 *func = "ten_syncdsync_set_cb_40g_transponder_t41";  
  CS_PRINT("%s() %s\n", func, ten_slice_strings[slice_client]);
  CS_PRINT("    num_just_oxu3 = %d\n", num_just_oxu3);
  CS_PRINT("    num_pjo_oxu3 = %d\n", num_pjo_oxu3);
  CS_PRINT("    P_line = %d\n", P_line);
  CS_PRINT("    Q_line = %d\n", Q_line);
  CS_PRINT("    P_client = %d\n", P_client);
  CS_PRINT("    Q_client = %d\n", Q_client);

  CS_PRINT("    client_rate = %f\n", client_rate);
  CS_PRINT("    xcon_client_rate = %f\n", xcon_client_rate);
  CS_PRINT("    line_rate = %f\n", line_rate);
  CS_PRINT("    line_client_same = %d\n", line_client_same);
  CS_PRINT("    line_client_rate_equal = %d\n", line_client_rate_equal);

  pdevcb = TEN_DEV_ID_TO_DEVCB_PTR(dev_id);

  pdevcb->syncdsync_thread_cb[slice_client].num_just_oxu3 = num_just_oxu3;
  pdevcb->syncdsync_thread_cb[slice_client].num_pjo_oxu3  = num_pjo_oxu3;
  pdevcb->syncdsync_thread_cb[slice_client].P_line   = P_line;
  pdevcb->syncdsync_thread_cb[slice_client].Q_line   = Q_line;
  pdevcb->syncdsync_thread_cb[slice_client].P_client = P_client;
  pdevcb->syncdsync_thread_cb[slice_client].Q_client = Q_client;
  pdevcb->syncdsync_thread_cb[slice_client].client_rate = client_rate;
  pdevcb->syncdsync_thread_cb[slice_client].xcon_client_rate = xcon_client_rate;
  pdevcb->syncdsync_thread_cb[slice_client].line_rate = line_rate;
  pdevcb->syncdsync_thread_cb[slice_client].line_client_same = line_client_same;
  pdevcb->syncdsync_thread_cb[slice_client].line_client_rate_equal = line_client_rate_equal;


  CS_PRINT("%s() client_rate=%f, xcon_client_rate=%f, line_rate=%f\n", func,   client_rate, xcon_client_rate, line_rate);


  return CS_OK;
}


/* Bugzilla 28006 Start */
/********************************************************************/
/* $rtn_hdr_start  SYNCDSYNC SET CONTROL BLOCK 40G TRANS PARAMETERS */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : HIGH LEVEL                                          */
/* CHIP       : Tenabo                                              */
cs_status ten_syncdsync_set_cb_40g_transponder_dual_async_t41(cs_uint16 dev_id,
                                                        cs_uint8 slice_client,
                                                        cs_int16 num_just_oxu3,
                                                        cs_uint8 num_pjo_oxu3,
                                                        cs_int16 num_just_oxu3_client,
                                                        cs_uint8 num_pjo_oxu3_client,
                                                        cs_uint16 P_line,
                                                        cs_uint16 Q_line,
                                                        cs_uint16 P_client,
                                                        cs_uint16 Q_client,
                                                        double client_rate, 
                                                        double xcon_client_rate,
                                                        double line_rate)
/* INPUTS     : o Device Id                                         */
/*              o Client Slice                                      */
/*              o 0xU3 Justification Bytes (C15 / FS)               */
/*              o 0xU3 PJO                                          */
/*              o Client 0xU3 Justification Bytes (C15 / FS)        */
/*              o Client 0xU3 PJO                                   */
/*              o Line Numerator (P)                                */
/*              o Line Denominator (Q)                              */
/*              o Client Numenrator (P)                             */
/*              o Client Denominator (Q)                            */
/*              o Client Rate                                       */
/*              o Low Order ODU2 rate                               */
/*              o Line Rate                                         */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Writes the syncdsync parameters for 40G muxponder applications   */
/* to the syncdsync control block when both sides are async         */
/*                                                                  */
/*   [slice_client] parameter specifies client's slice:             */
/*     TEN_SLICE0 = 0                                               */
/*     TEN_SLICE1 = 1                                               */
/*     TEN_SLICE2 = 2                                               */
/*     TEN_SLICE3 = 3                                               */
/*                                                                  */
/*   [num_just_oxu3_client]                                         */
/*   [num_just_oxu3] specifies the number of justification bytes -  */
/*                   C15 of FS (OxU2 -> OxU3)                       */
/*                                                                  */
/*   [num_pjo_oxu3_client]                                          */
/*   [num_pjo_oxu3] specifies the number of positive justification  */
/*                  bytes (OxU2 -> OxU3)                            */
/*     0 - 6                                                        */
/*                                                                  */
/*   [P_line] specifies the number of columns in the OTN frame on   */
/*            the line side                                         */
/*     239 - 24381                                                  */
/*                                                                  */
/*   [Q_line] specifies the number of columns in the payload on the */
/*            line side                                             */
/*     217 - 18445                                                  */
/*                                                                  */
/*   [P_client] specifies the number of columns in the OTN frame on */
/*              the client side                                     */
/*     239 - 24381                                                  */
/*                                                                  */
/*   [Q_client] specifies the number of columns in the payload on   */
/*              the client side                                     */
/*     217 - 18445                                                  */
/*                                                                  */
/*   [client_rate]      Client bit rate                             */
/*   [xcon_client_rate] Bit rate at the Cross Connect               */
/*   [line_rate]        Line bit rate                               */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
 {
  ten_dev_cb_t *pdevcb;
  cs_char8 *func = "ten_syncdsync_set_cb_40g_transponder_dual_async_t41";  

  CS_PRINT("%s() %s\n", func, ten_slice_strings[slice_client]);
  CS_PRINT("    num_just_oxu3 = %d\n", num_just_oxu3);
  CS_PRINT("    num_pjo_oxu3 = %d\n", num_pjo_oxu3);
  CS_PRINT("    num_just_oxu3_client = %d\n", num_just_oxu3_client);
  CS_PRINT("    num_pjo_oxu3_client = %d\n", num_pjo_oxu3_client);
  CS_PRINT("    P_line = %d\n", P_line);
  CS_PRINT("    Q_line = %d\n", Q_line);
  CS_PRINT("    P_client = %d\n", P_client);
  CS_PRINT("    Q_client = %d\n", Q_client);
  CS_PRINT("    client_rate = %f\n", client_rate);
  CS_PRINT("    xcon_client_rate = %f\n", xcon_client_rate);
  CS_PRINT("    line_rate = %f\n", line_rate);

  pdevcb = TEN_DEV_ID_TO_DEVCB_PTR(dev_id);

  pdevcb->syncdsync_thread_cb[slice_client].num_just_oxu3 = num_just_oxu3;
  pdevcb->syncdsync_thread_cb[slice_client].num_pjo_oxu3  = num_pjo_oxu3;
  pdevcb->syncdsync_thread_cb[slice_client].num_just_oxu3_client = num_just_oxu3_client;
  pdevcb->syncdsync_thread_cb[slice_client].num_pjo_oxu3_client  = num_pjo_oxu3_client;
  pdevcb->syncdsync_thread_cb[slice_client].P_line   = P_line;
  pdevcb->syncdsync_thread_cb[slice_client].Q_line   = Q_line;
  pdevcb->syncdsync_thread_cb[slice_client].P_client = P_client;
  pdevcb->syncdsync_thread_cb[slice_client].Q_client = Q_client;
  pdevcb->syncdsync_thread_cb[slice_client].client_rate = client_rate;
  pdevcb->syncdsync_thread_cb[slice_client].xcon_client_rate = xcon_client_rate;
  pdevcb->syncdsync_thread_cb[slice_client].line_rate = line_rate;

  return CS_OK;
}
/* Bugzilla 28006 End */

  /*******************************************************************/
/* Miscellaneous functions */
/*******************************************************************/
  cs_uint32 _round(double num) 
{ 
  cs_uint32 integer = (cs_uint32)num; 
  if(num - integer < 0.5) 
    return integer; 
  else 
    return (cs_uint32)((1.0-((num-(double)integer)))+num); 
} 

cs_uint32 _power(cs_uint16 num, cs_uint16 exponent) {
  cs_uint8 i;
  cs_uint32 result=1;

  for(i=0;i<exponent;i++) {
    result = result*num;
  }
  return result;
}



