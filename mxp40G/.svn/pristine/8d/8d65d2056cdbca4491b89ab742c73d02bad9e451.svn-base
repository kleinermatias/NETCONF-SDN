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
 * ten_ohpp_api.h 
 *
 * $Id: ten_ohpp_api.h,v 1.10 2013/03/19 14:04:05 jccarlis Exp $
 *
 * API prototypes for OHPP 
 *
 */
 
#ifndef __TEN_OHPP_API_H__
#define __TEN_OHPP_API_H__

#ifdef __cplusplus
extern "C" {
#endif

cs_status ten_ohpp_sfu_sreset(cs_uint16 module_id, 
                              cs_reset_action_t act);
                              
cs_status ten_ohpp_sfu_insert_otn_maintenance_signal(cs_uint16, cs_uint8, cs_uint8, cs_uint8);
cs_status ten_ohpp_sfu_insert_otn_maintenance_signal_t41(cs_uint16, cs_uint8, cs_uint8, cs_uint8, cs_uint8);

cs_status ten_ohpp_sfu_set_iaesel(cs_uint16 module_id, 
                                  cs_uint16 iaesel, 
                                  cs_uint8 stream);

cs_status ten_ohpp_sfu_set_mssel(cs_uint16 module_id, 
                                 cs_uint16 mssel, 
                                 cs_uint8 stream);

cs_status ten_ohpp_sfu_select_global_timing_source(cs_uint16 module_id, 
                                                   cs_uint16 select4, 
                                                   cs_uint16 select3, 
                                                   cs_uint16 select2, 
                                                   cs_uint16 select1);

cs_status ten_ohpp_set_doe_ram(cs_uint16 module_id,
                               cs_uint8 instance, 
                               cs_char8 *str);
                               
cs_status ten_ohpp_clear_doi_ram(cs_uint16 module_id,
                                cs_uint8  string);
                                
cs_status ten_ohpp_set_doe_ram_byte(cs_uint16 module_id,
                                    cs_uint8  string,
                                    cs_uint8  byte,
                                    cs_uint16 value);

cs_status ten_ohpp_get_doe_ram(cs_uint16 module_id,
                               cs_uint8 instance, 
                               cs_char8 *str);

cs_int16 ten_ohpp_get_doe_ram_byte(cs_uint16 module_id,
                                  cs_uint8  string,
                                  cs_uint8  byte);

cs_status ten_ohpp_set_doi_ram(cs_uint16 module_id,
                               cs_uint8 instance, 
                               cs_uint16 *str);

cs_int16 ten_ohpp_get_doi_ram_byte(cs_uint16 module_id,
                                  cs_uint8  string,
                                  cs_uint8  byte);

cs_status ten_ohpp_set_doi_ram_byte(cs_uint16 module_id,
                                    cs_uint8  string,
                                    cs_uint8  byte,
                                    cs_uint16 value);

cs_status ten_ohpp_get_doi_ram(cs_uint16 module_id,
                               cs_uint8 instance, 
                               cs_char8 *str);
                                                   
cs_status ten_ohpp_sfu_ccr1cfg0(cs_uint16 module_id, 
                            cs_uint16 ccr1fpl, 
                            cs_uint16 ccr1fpp, 
                            cs_uint16 ccr1col, 
                            cs_uint16 ccr1dol, 
                            cs_uint16 ccr1ln, 
                            cs_uint16 ccr1cmp);
                            
cs_status ten_ohpp_sfu_ccr1cfg1(cs_uint16 module_id, 
                            cs_uint16 ccr1ss, 
                            cs_uint16 ccr1frq);
                            
cs_status ten_ohpp_sfu_ccr1cfg2(cs_uint16 module_id, 
                            cs_uint16 ccr1md, 
                            cs_uint16 ccr1bs);
                            
cs_status ten_ohpp_sfu_ccr2cfg0(cs_uint16 module_id, 
                            cs_uint16 ccr2fpl, 
                            cs_uint16 ccr2fpp, 
                            cs_uint16 ccr2col, 
                            cs_uint16 ccr2dol, 
                            cs_uint16 ccr2ln, 
                            cs_uint16 ccr2cmp);
                            
cs_status ten_ohpp_sfu_ccr2cfg1(cs_uint16 module_id, 
                            cs_uint16 ccr2ss, 
                            cs_uint16 ccr2frq);
                            
cs_status ten_ohpp_sfu_ccr2cfg2(cs_uint16 module_id, 
                            cs_uint16 ccr2md, 
                            cs_uint16 ccr2bs);
                            
cs_status ten_ohpp_sfu_ccr3cfg0(cs_uint16 module_id, 
                            cs_uint16 ccr3fpl, 
                            cs_uint16 ccr3fpp, 
                            cs_uint16 ccr3col, 
                            cs_uint16 ccr3dol, 
                            cs_uint16 ccr3ln, 
                            cs_uint16 ccr3cmp);
                            
cs_status ten_ohpp_sfu_ccr3cfg1(cs_uint16 module_id, 
                            cs_uint16 ccr3ss, 
                            cs_uint16 ccr3frq);
                            
cs_status ten_ohpp_sfu_ccr3cfg2(cs_uint16 module_id, 
                            cs_uint16 ccr3md, 
                            cs_uint16 ccr3bs);
                            
cs_status ten_ohpp_sfu_ccr4cfg0(cs_uint16 module_id, 
                            cs_uint16 ccr4fpl, 
                            cs_uint16 ccr4fpp, 
                            cs_uint16 ccr4col, 
                            cs_uint16 ccr4dol, 
                            cs_uint16 ccr4ln, 
                            cs_uint16 ccr4cmp);
                            
cs_status ten_ohpp_sfu_ccr4cfg1(cs_uint16 module_id, 
                            cs_uint16 ccr4ss, 
                            cs_uint16 ccr4frq);
                            
cs_status ten_ohpp_sfu_ccr4cfg2(cs_uint16 module_id, 
                            cs_uint16 ccr4md, 
                            cs_uint16 ccr4bs);
                            
cs_status ten_ohpp_sfu_ccr5cfg0(cs_uint16 module_id, 
                            cs_uint16 ccr5fpl, 
                            cs_uint16 ccr5fpp, 
                            cs_uint16 ccr5col, 
                            cs_uint16 ccr5dol, 
                            cs_uint16 ccr5ln, 
                            cs_uint16 ccr5cmp);
                            
cs_status ten_ohpp_sfu_ccr5cfg1(cs_uint16 module_id, 
                            cs_uint16 ccr5ss, 
                            cs_uint16 ccr5frq);
                            
cs_status ten_ohpp_sfu_ccr5cfg2(cs_uint16 module_id, 
                            cs_uint16 ccr5md, 
                            cs_uint16 ccr5bs);
                            
cs_status ten_ohpp_sfu_cct1cfg0(cs_uint16 module_id, 
                            cs_uint16 cct1fpl, 
                            cs_uint16 cct1fpp, 
                            cs_uint16 cct1col, 
                            cs_uint16 cct1dol, 
                            cs_uint16 cct1ln, 
                            cs_uint16 cct1cmp);
                            
cs_status ten_ohpp_sfu_cct1cfg1(cs_uint16 module_id, 
                            cs_uint16 cct1ss, 
                            cs_uint16 cct1frq);
                            
cs_status ten_ohpp_sfu_cct1cfg2(cs_uint16 module_id, 
                            cs_uint16 cct1md, 
                            cs_uint16 cct1bs);
                            
cs_status ten_ohpp_sfu_cct2cfg0(cs_uint16 module_id, 
                            cs_uint16 cct2fpl, 
                            cs_uint16 cct2fpp, 
                            cs_uint16 cct2col, 
                            cs_uint16 cct2dol, 
                            cs_uint16 cct2ln, 
                            cs_uint16 cct2cmp);
                            
cs_status ten_ohpp_sfu_cct2cfg1(cs_uint16 module_id, 
                            cs_uint16 cct2ss, 
                            cs_uint16 cct2frq);
                            
cs_status ten_ohpp_sfu_cct2cfg2(cs_uint16 module_id, 
                            cs_uint16 cct2md, 
                            cs_uint16 cct2bs);
                            
cs_status ten_ohpp_sfu_cct3cfg0(cs_uint16 module_id, 
                            cs_uint16 cct3fpl, 
                            cs_uint16 cct3fpp, 
                            cs_uint16 cct3col, 
                            cs_uint16 cct3dol, 
                            cs_uint16 cct3ln, 
                            cs_uint16 cct3cmp);
                            
cs_status ten_ohpp_sfu_cct3cfg1(cs_uint16 module_id, 
                            cs_uint16 cct3ss, 
                            cs_uint16 cct3frq);
                            
cs_status ten_ohpp_sfu_cct3cfg2(cs_uint16 module_id, 
                            cs_uint16 cct3md, 
                            cs_uint16 cct3bs);
                            
cs_status ten_ohpp_sfu_cct4cfg0(cs_uint16 module_id, 
                            cs_uint16 cct4fpl, 
                            cs_uint16 cct4fpp, 
                            cs_uint16 cct4col, 
                            cs_uint16 cct4dol, 
                            cs_uint16 cct4ln, 
                            cs_uint16 cct4cmp);
                            
cs_status ten_ohpp_sfu_cct4cfg1(cs_uint16 module_id, 
                            cs_uint16 cct4ss, 
                            cs_uint16 cct4frq);
                            
cs_status ten_ohpp_sfu_cct4cfg2(cs_uint16 module_id, 
                            cs_uint16 cct4md, 
                            cs_uint16 cct4bs);
                            
cs_status ten_ohpp_sfu_cct5cfg0(cs_uint16 module_id, 
                            cs_uint16 cct5fpl, 
                            cs_uint16 cct5fpp, 
                            cs_uint16 cct5col, 
                            cs_uint16 cct5dol, 
                            cs_uint16 cct5ln, 
                            cs_uint16 cct5cmp);
                            
cs_status ten_ohpp_sfu_cct5cfg1(cs_uint16 module_id, 
                            cs_uint16 cct5ss, 
                            cs_uint16 cct5frq);
                            
cs_status ten_ohpp_sfu_cct5cfg2(cs_uint16 module_id, 
                            cs_uint16 cct5md, 
                            cs_uint16 cct5bs);

cs_status ten_ohpp_sfu_set_cctval(cs_uint16 module_id, 
                                  cs_uint16 cctval, 
                                  cs_uint8 channel);

cs_uint16 ten_ohpp_sfu_get_cctstate(cs_uint16 module_id);

cs_status ten_ohpp_sfu_set_oclkcfg(cs_uint16 module_id, 
                                   cs_uint16 tclkoinv, 
                                   cs_uint16 rclkoinv);

cs_status ten_ohpp_sfu_set_msignal(cs_uint16 module_id,
                                   cs_uint16 row,
                                   cs_uint16 value);
                                   
cs_int16 ten_ohpp_sfu_get_msignal(cs_uint16 module_id,
                                  cs_uint16 row);
                                  
cs_int16 ten_ohpp_sfu_get_osignal(cs_uint16 module_id,
                                  cs_uint16 row);

cs_status ten_ohpp_sfu_set_gpbcfg(cs_uint16 module_id, 
                                  cs_uint16 instance,
                                  cs_uint16 config,
                                  cs_uint16 g0bval, 
                                  cs_uint16 g0sink);
                                  
cs_status ten_ohpp_sfu_set_gpbsel(cs_uint16 module_id, 
                                  cs_uint16 instance,
                                  cs_uint16 config,
                                  cs_uint16 g0bsel1);
                                  
cs_status ten_ohpp_sfu_set_m3bcfg(cs_uint16 module_id, 
                                  cs_uint16 stream, 
                                  cs_uint16 m3bmsk);
                                  
cs_status ten_ohpp_sfu_set_nstcfg(cs_uint16 module_id, 
                                  cs_uint16 stream, 
                                  cs_uint16 nstc);
                                  
cs_status ten_ohpp_sfu_set_phdtcten(cs_uint16 module_id, 
                                    cs_uint16 phdtcten);

cs_status ten_ohpp_sfu_set_sfcmsel(cs_uint16 module_id, 
                                   cs_uint16 sfcmsel);

cs_status ten_ohpp_sfu_set_nulothr(cs_uint16 module_id, 
                                   cs_uint16 nulothr);

cs_status ten_ohpp_sfu_set_nulthis(cs_uint16 module_id,  
                                   cs_uint16 nulthis);

cs_status ten_ohpp_sfu_set_doaien(cs_uint16 module_id, 
                                  cs_uint16 doaien);

cs_status ten_ohpp_sfu_set_siggene(cs_uint16 module_id,  
                                   cs_uint16 siggene);
                               
cs_status ten_ohpp_sfu_set_admohen(cs_uint16 module_id, 
                                   cs_uint16 admohen);

cs_status ten_ohpp_sfu_set_stsohen(cs_uint16 module_id, 
                                   cs_uint16 stsohen);

cs_status ten_ohpp_sfu_set_otnohen(cs_uint16 module_id, 
                                   cs_uint16 otnohen);
                               
cs_int16 ten_ohpp_sfu_get_state(cs_uint16 module_id, 
                                cs_uint16 select);
                            
cs_status ten_ohpp_sfu_set_doaum(cs_uint16 module_id, 
                                 cs_uint16 stream, 
                                 cs_uint16 doaum);
                                 
cs_status ten_ohpp_sfu_set_doasel(cs_uint16 module_id, 
                                  cs_uint16 stream, 
                                  cs_uint16 doasel);
                                  
cs_status ten_ohpp_sfu_set_doaup(cs_uint16 module_id, 
                                 cs_uint16 stream, 
                                 cs_uint16 doaup);
                                 
cs_status ten_ohpp_set_sfc_ram(cs_uint16 module_id,
                               cs_uint8 row, 
                               cs_uint16 *str);

cs_status ten_ohpp_set_sfc_ram_bit(cs_uint16 module_id,
                                   cs_uint16 row, 
                                   cs_uint16 bit,
                                   cs_uint8  value);

cs_status ten_ohpp_get_sfc_ram(cs_uint16 module_id,
                               cs_uint8 row, 
                               cs_uint16 *str);

cs_int16 ten_ohpp_get_sfc_ram_bit(cs_uint16 module_id,
                                  cs_uint16 row, 
                                  cs_uint16 bit);

cs_status ten_ohpp_set_shadow_sfc_ram(cs_uint16 module_id,
                                      cs_uint16 bank,
                                      cs_uint8 row, 
                                      cs_uint16 *str);

cs_status ten_ohpp_set_shadow_sfc_ram_bit(cs_uint16 module_id,
                                          cs_uint16 bank,
                                          cs_uint16 row, 
                                          cs_uint16 bit,
                                          cs_uint8  value);

cs_status ten_ohpp_get_shadow_sfc_ram(cs_uint16 module_id,
                                      cs_uint16 bank,
                                      cs_uint8 row, 
                                      cs_uint16 *str);

cs_int16 ten_ohpp_get_shadow_sfc_ram_bit(cs_uint16 module_id,
                                         cs_uint16 bank,
                                         cs_uint16 row, 
                                         cs_uint16 bit);

cs_status ten_ohpp_copy_shadow_sfc_ram(cs_uint16 module_id,
                                       cs_uint16 bank);

cs_status ten_ohpp_clear_shadow_sfc_ram(cs_uint16 module_id,
                                        cs_uint16 bank);

cs_status ten_ohpp_set_sfu_beicfg(cs_uint16 module_id, 
                                  cs_uint16 beisrc, 
                                  cs_uint8  stream);
                                  
cs_status ten_ohpp_sfu_beicfg1_bipsel(cs_uint16 module_id, 
                                      cs_uint16 bipsel);
                                      
cs_status ten_ohpp_sfu_beiovrd(cs_uint16 module_id, 
                               cs_uint16 stream, 
                               cs_uint16 beiovrden);
                               
cs_status ten_ohpp_sfu_switch_bank(cs_uint16 module_id);

cs_status ten_ohpp_sfu_gsfu_cfg(cs_uint16 module_id, 
                                cs_uint16 unit, 
                                cs_uint16 gs_dst, 
                                cs_uint16 gs_path, 
                                cs_uint16 gs_src);

cs_status ten_ohpp_sfu_gsfu_sbs(cs_uint16 module_id, 
                                cs_uint16 unit, 
                                cs_uint16 gs_sbs);

cs_status ten_ohpp_sfu_gsfu_dbs(cs_uint16 module_id, 
                                cs_uint16 unit, 
                                cs_uint16 gs_dbs);

/* Bugzilla 21101: SFU Config dump enhancements */
cs_int16 ten_ohpp_compare_shadow_sfc_ram(cs_uint16 module_id,
                                         cs_uint16 bank);

/* T41 additions */
cs_status ten_ohpp_sfu_set_direct_io_mode(cs_uint16 module_id, 
                                    cs_uint16 direct_io_mode);
                                    
cs_status ten_ohpp_sfu_set_lsoh_mode(cs_uint16 module_id, 
                                     cs_uint16 lsoh_mode);
                                     
cs_status ten_ohpp_sfu_cct1cfg1_cct1mux_t41(cs_uint16 module_id, 
                                            cs_uint16 cct1mux);
                                            
cs_status ten_ohpp_sfu_cct2cfg1_cct2mux_t41(cs_uint16 module_id, 
                                            cs_uint16 cct2mux);
                                            
cs_status ten_ohpp_sfu_cct3cfg1_cct3mux_t41(cs_uint16 module_id, 
                                            cs_uint16 cct3mux);
                                            
cs_status ten_ohpp_sfu_cct4cfg1_cct4mux_t41(cs_uint16 module_id, 
                                            cs_uint16 cct4mux);
                                            
cs_status ten_ohpp_sfu_cct5cfg1_cct5mux_t41(cs_uint16 module_id, 
                                            cs_uint16 cct5mux);
                                            
cs_status ten_ohpp_sfu_ccr1cfg1_ccr1mux_t41(cs_uint16 module_id, 
                                            cs_uint16 ccr1mux);
                                            
cs_status ten_ohpp_sfu_ccr2cfg1_ccr2mux_t41(cs_uint16 module_id, 
                                            cs_uint16 ccr2mux);
                                            
cs_status ten_ohpp_sfu_ccr3cfg1_ccr3mux_t41(cs_uint16 module_id, 
                                            cs_uint16 ccr3mux);
                                            
cs_status ten_ohpp_sfu_ccr4cfg1_ccr4mux_t41(cs_uint16 module_id, 
                                            cs_uint16 ccr4mux);
                                            
cs_status ten_ohpp_sfu_ccr5cfg1_ccr5mux_t41(cs_uint16 module_id, 
                                            cs_uint16 ccr5mux);
                                              
#ifdef __cplusplus
}
#endif
#endif

