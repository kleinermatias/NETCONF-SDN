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
 * ten_n10g_api.h 
 *
 * $Id: ten_n10g_api.h,v 1.39 2013/04/05 20:52:35 jccarlis Exp $
 *
 * API prototypes for N10G 
 *
 */
 
#ifndef __TEN_N10G_API_H__
#define __TEN_N10G_API_H__

#ifdef __cplusplus
extern "C" {
#endif
cs_status ten_hl_oc192_termination_path_client_side (cs_uint16 module_id_client,
                                                     cs_uint16 slice_client,
                                                     cs_uint16 term);
cs_status ten_hl_oc192_termination_path_line_side  ( cs_uint16 module_id_line,
                                                     cs_uint16 slice_line,
                                                     cs_uint16 term);
cs_status ten_n10g_tx_trans_term_line_bypass       ( cs_uint16 module_id_line,
                                                     cs_uint16 slice_line,
                                                     cs_uint16 term_oc192);

cs_status ten_n10g_set_global_resets(cs_uint16 module_id, cs_uint8 slice,
                                     cs_reset_action_t act, cs_uint16 bitfield);

cs_boolean ten_n10g_get_global_losf_status(cs_uint16 module_id, cs_uint8 slice);

cs_int16 ten_n10g_get_global_pstat_status(cs_uint16 module_id, cs_uint8 slice);

cs_boolean ten_n10g_get_global_pf_status(cs_uint16 module_id, cs_uint8 slice);

cs_status ten_n10g_set_gblr_dpcfg(cs_uint16 module_id, cs_uint8 slice, cs_uint16 xsel,
                                  cs_uint16 kpasel, cs_uint16 sbypld, cs_uint16 sbyfrm,
                                  cs_uint16 oby, cs_uint16 sdhoff, cs_uint16 otnoff);
                                  
cs_status ten_n10g_set_gblr_dpcfg_sbypld(cs_uint16 module_id,
                                         cs_uint8 slice, 
                                         cs_uint16 sbypld);                                  

cs_status ten_n10g_set_gblr_phys(cs_uint16 module_id, cs_uint8 slice, cs_uint16 phys);

cs_status ten_n10g_set_gblr_kpacfg0(cs_uint16 module_id, cs_uint8 slice, cs_uint16 fmm,
                                    cs_uint16 pclr, cs_uint16 pafrsti, cs_uint16 pafrst,
                                    cs_uint16 pafseti, cs_uint16 pafset);

cs_status ten_n10g_set_gblr_pdhy(cs_uint16 module_id, cs_uint8 slice, cs_uint16 pdhy0,
                                 cs_uint16 pdhy1);

cs_status ten_n10g_config_kpa(cs_uint16 module_id, cs_uint8 slice, cs_uint16 fmm,
                              cs_uint16 prbs_stats_time_int,
                              cs_uint16 fixed_stats_time_int);

cs_status ten_n10g_config_kpa_fmm(cs_uint16 module_id, cs_uint8 slice, cs_uint16 fmm);

cs_status ten_n10g_config_kpa_prbs_interval(cs_uint16 module_id, cs_uint8 slice,
                                            cs_uint16 prbs_stats_time_int);

cs_status ten_n10g_config_kpa_fixed_interval(cs_uint16 module_id, cs_uint8 slice,
                                             cs_uint16 fixed_stats_time_int);

cs_status ten_n10g_restart_kpa(cs_uint16 module_id, cs_uint8 slice);

cs_status ten_n10g_config_fixed_pattern_match(cs_uint16 module_id, cs_uint8 slice,
                                              cs_uint16 pattern, cs_uint16 parm1,
                                              cs_uint16 parm0);

cs_status ten_n10g_gblr_set_xsel(cs_uint16 module_id, cs_uint8 slice, cs_uint16 xsel);

cs_status ten_n10g_set_gblt_cfgtx0(cs_uint16 module_id, cs_uint8 slice, cs_uint16 pplf_en,
                                   cs_uint16 cbrstmaisins, cs_uint16 pn11auto,
                                   cs_uint16 otnoff, cs_uint16 oby, cs_uint16 sby,
                                   cs_uint16 kpgby, cs_uint16 pktie);

cs_status ten_n10g_config_kpg(cs_uint16 module_id, cs_uint8 slice, cs_ctl_t kpg_bypass,
                              cs_ctl_t kpg_auto, cs_uint16 pattern, cs_uint16 fpat1,
                              cs_uint16 fpat0);

cs_status ten_n10g_set_gblt_bypasses(cs_uint16 module_id, cs_uint8 slice,
                                     cs_uint16 otnoff, cs_uint16 oby, cs_uint16 sby,
                                     cs_uint16 kpgby);

cs_status ten_n10g_set_gblt_otnoff(cs_uint16 module_id,
                                   cs_uint8 slice, 
                                   cs_uint16 otnoff);

cs_status ten_n10g_set_pktie(cs_uint16 module_id, cs_uint8 slice, cs_uint16 pktie);

cs_status ten_n10g_set_pplf_en(cs_uint16 module_id, cs_uint8 slice, cs_uint16 pplf_en);

cs_status ten_n10g_set_cbrstmaisins(cs_uint16 module_id, cs_uint8 slice,
                                    cs_uint16 cbrstmaisins);

cs_status ten_n10g_set_pn11auto(cs_uint16 module_id, cs_uint8 slice, cs_uint16 pn11auto);

cs_status ten_n10g_set_sby(cs_uint16 module_id,
                           cs_uint8 slice, 
                           cs_uint16 sby);

cs_status ten_n10g_oohr_gendwnlfsf(cs_uint16 module_id, cs_uint8 slice, cs_uint16 sqgcc,
                                   cs_uint16 gensf_xlos, cs_uint16 gensf_los,
                                   cs_uint16 gensf_otuais, cs_uint16 gensf_lof,
                                   cs_uint16 gensf_feceed, cs_uint16 gensf_lom);

cs_status ten_n10g_oohr_gendwnlfsf_gensf_lol(cs_uint16 module_id, cs_uint8 slice, 
                                             cs_uint16 gensf_lol);
                                             
cs_status ten_n10g_oohr_gendwnlfsf_sqbiponlf(cs_uint16 module_id, cs_uint8 slice, 
                                             cs_uint16 sqbiponlf);

cs_status ten_n10g_oohr_gendwnlfsf_sqiaeonsmtti(cs_uint16 module_id, cs_uint8 slice, 
                                                cs_uint16 sqiaeonsmtti);
                                                
cs_status ten_n10g_oohr_gendwnlfsf_sqiaeonlf(cs_uint16 module_id, cs_uint8 slice, 
                                             cs_uint16 sqiaeonlf);
                                   
cs_status ten_n10g_oohr_gendwnpmsf(cs_uint16 module_id, cs_uint8 slice,
                                   cs_uint16 gensf_doduaisp, cs_uint16 gensf_dlckp,
                                   cs_uint16 gensf_docip, cs_uint16 gensf_dtimp,
                                   cs_uint16 gensf_dmsim, cs_uint16 gensf_dplm);

cs_status ten_n10g_oohr_gendwntcm1sf(cs_uint16 module_id, cs_uint8 slice,
                                     cs_uint16 gensf_doduaistcm, cs_uint16 gensf_dlcktcm,
                                     cs_uint16 gensf_docitcm, cs_uint16 gensf_dltc,
                                     cs_uint16 gensf_dtimtcm);

cs_status ten_n10g_oohr_gendwntcm2sf(cs_uint16 module_id, cs_uint8 slice,
                                     cs_uint16 gensf_doduaistcm, cs_uint16 gensf_dlcktcm,
                                     cs_uint16 gensf_docitcm, cs_uint16 gensf_dltc,
                                     cs_uint16 gensf_dtimtcm);

cs_status ten_n10g_oohr_gendwntcm3sf(cs_uint16 module_id, cs_uint8 slice,
                                     cs_uint16 gensf_doduaistcm, cs_uint16 gensf_dlcktcm,
                                     cs_uint16 gensf_docitcm, cs_uint16 gensf_dltc,
                                     cs_uint16 gensf_dtimtcm);

cs_status ten_n10g_oohr_gendwntcm4sf(cs_uint16 module_id, cs_uint8 slice,
                                     cs_uint16 gensf_doduaistcm, cs_uint16 gensf_dlcktcm,
                                     cs_uint16 gensf_docitcm, cs_uint16 gensf_dltc,
                                     cs_uint16 gensf_dtimtcm);

cs_status ten_n10g_oohr_gendwntcm5sf(cs_uint16 module_id, cs_uint8 slice,
                                     cs_uint16 gensf_doduaistcm, cs_uint16 gensf_dlcktcm,
                                     cs_uint16 gensf_docitcm, cs_uint16 gensf_dltc,
                                     cs_uint16 gensf_dtimtcm);

cs_status ten_n10g_oohr_gendwntcm6sf(cs_uint16 module_id, cs_uint8 slice,
                                     cs_uint16 gensf_doduaistcm, cs_uint16 gensf_dlcktcm,
                                     cs_uint16 gensf_docitcm, cs_uint16 gensf_dltc,
                                     cs_uint16 gensf_dtimtcm);

cs_status ten_n10g_oohr_gendwnais(cs_uint16 module_id, cs_uint8 slice,
                                  cs_uint16 genais_lf, cs_uint16 genais_sm,
                                  cs_uint16 genais_tcm6, cs_uint16 genais_tcm5,
                                  cs_uint16 genais_tcm4, cs_uint16 genais_tcm3,
                                  cs_uint16 genais_tcm2, cs_uint16 genais_tcm1,
                                  cs_uint16 genais_pm, cs_uint16 genais_py);

cs_status ten_n10g_oohr_gendwnok(cs_uint16 module_id, cs_uint8 slice, cs_uint16 genok_lf,
                                 cs_uint16 genok_sm, cs_uint16 genok_tcm6,
                                 cs_uint16 genok_tcm5, cs_uint16 genok_tcm4,
                                 cs_uint16 genok_tcm3, cs_uint16 genok_tcm2,
                                 cs_uint16 genok_tcm1, cs_uint16 genok_pm,
                                 cs_uint16 genok_py);

cs_status ten_n10g_oohr_cfg0(cs_uint16 module_id, cs_uint8 slice, cs_uint16 mfdsyh,
                             cs_uint16 mfsyhy);

cs_status ten_n10g_set_oohr_cfg1(cs_uint16 module_id, cs_uint8 slice, cs_uint16 beidiv,
                                 cs_uint16 beiniv);

cs_status ten_n10g_set_oohr_cfg2(cs_uint16 module_id, cs_uint8 slice, cs_uint16 beintv,
                                 cs_uint16 beidtv);

cs_status ten_n10g_set_oohr_cfg3(cs_uint16 module_id, cs_uint8 slice, cs_uint16 bipdiv,
                                 cs_uint16 bipniv);

cs_status ten_n10g_set_oohr_cfg4(cs_uint16 module_id, cs_uint8 slice, cs_uint16 bipntv,
                                 cs_uint16 bipdtv);

cs_status ten_n10g_oohr_cfg5_bipmsk(cs_uint16 module_id, cs_uint8 slice,
                                    cs_uint16 bipmsk);

cs_status ten_n10g_oohr_cfg5_bipssel(cs_uint16 module_id, cs_uint8 slice,
                                     cs_uint16 bipssel);

cs_status ten_n10g_oohr_cfg5_beissel(cs_uint16 module_id, cs_uint8 slice,
                                     cs_uint16 beissel);

cs_status ten_n10g_oohr_cfg5_mfalgne(cs_uint16 module_id, cs_uint8 slice,
                                     cs_uint16 mfalgne);

cs_status ten_n10g_set_oohr_cfg6(cs_uint16 module_id, cs_uint8 slice, cs_uint16 sesiv,
                                 cs_uint16 sestv);

cs_status ten_n10g_set_oohr_cfg7(cs_uint16 module_id, cs_uint8 slice, cs_uint16 seuiv,
                                 cs_uint16 seutv);

cs_status ten_n10g_oohr_cfg11_msiext_cfg8_msicnt(cs_uint16 module_id, cs_uint8 slice, 
                                                 cs_uint16 msi_ext__msi_cnt);                               
                                 
cs_status ten_n10g_oohr_cfg8_msicnt(cs_uint16 module_id, cs_uint8 slice, 
                                    cs_uint16 msicnt);
                                    
cs_status ten_n10g_oohr_cfg8(cs_uint16 module_id, cs_uint8 slice, cs_uint16 msicnt,
                             cs_uint16 stbldmsim, cs_uint16 stbldplm, cs_uint16 stbldtm,
                             cs_uint16 iaeflen, cs_uint16 bdiflen, cs_uint16 biaeflen);

cs_status ten_n10g_oohr_cfg9(cs_uint16 module_id, cs_uint8 slice, cs_uint16 apsulen,
                             cs_uint16 apsflen, cs_uint16 statulen, cs_uint16 statflen);

cs_status ten_n10g_oohr_cfg10(cs_uint16 module_id, cs_uint8 slice, cs_uint16 msiulen,
                              cs_uint16 msiflen, cs_uint16 ptiulen, cs_uint16 ptiflen);
                              
cs_status ten_n10g_oohr_cfg11_sps_mfdscr(cs_uint16 module_id, cs_uint8 slice, 
                                         cs_uint16 sps_mfdscr);
                                         
cs_status ten_n10g_oohr_cfg11_oh63sel(cs_uint16 module_id, cs_uint8 slice, 
                                      cs_uint16 oh63sel);
                                      
cs_status ten_n10g_oohr_cfg11_oh62sel(cs_uint16 module_id, cs_uint8 slice, 
                                      cs_uint16 oh62sel);
                                      
cs_status ten_n10g_oohr_cfg11_ohpp_bipsel(cs_uint16 module_id, 
                                          cs_uint8 slice, 
                                          cs_uint16 ohpp_bipsel);
                                          
cs_status ten_n10g_oohr_cfg11_ohpp_eedsel(cs_uint16 module_id, cs_uint8 slice, 
                                          cs_uint16 ohpp_eedsel);
                                          
cs_status ten_n10g_oohr_cfg11_ohpp_msi_trbsel(cs_uint16 module_id, cs_uint8 slice, 
                                              cs_uint16 ohpp_msi_trbsel);
                                              
cs_status ten_n10g_oohr_cfg11_acc_msi_trbsel(cs_uint16 module_id, cs_uint8 slice, 
                                             cs_uint16 acc_msi_trbsel);
                                             
cs_status ten_n10g_oohr_cfg11_flomen(cs_uint16 module_id, cs_uint8 slice, 
                                     cs_uint16 flomen);
                                     
cs_status ten_n10g_oohr_cfg11_msi_ext(cs_uint16 module_id, cs_uint8 slice, 
                                      cs_uint16 msi_ext);
                                      
cs_status ten_n10g_oohr_lomcfg_tdelon_tdeloff(cs_uint16 module_id, cs_uint8 slice,
                                              cs_uint16 tdelon, cs_uint16 tdeloff);

cs_status ten_n10g_oohr_jcsquelch(cs_uint16 module_id, cs_uint8 slice, 
                                  cs_uint16 squelch_on_signal,
                                  cs_ctl_t enable);

cs_status ten_n10g_set_expected_pti_byte(cs_uint16 module_id, cs_uint8 slice,
                                         cs_uint16 expti);

cs_status ten_n10g_set_expected_msi_string(cs_uint16 module_id, cs_uint8 slice,
                                           cs_uint16 msi7, cs_uint16 msi6, cs_uint16 msi5,
                                           cs_uint16 msi4, cs_uint16 msi3, cs_uint16 msi2,
                                           cs_uint16 msi1, cs_uint16 msi0);
                                           
cs_status ten_n10g_set_expected_msi_ext_string(cs_uint16 module_id, 
                                               cs_uint8 slice, 
                                               cs_uint16 msi_ext7,
                                               cs_uint16 msi_ext6,
                                               cs_uint16 msi_ext5,
                                               cs_uint16 msi_ext4,
                                               cs_uint16 msi_ext3,
                                               cs_uint16 msi_ext2,
                                               cs_uint16 msi_ext1,
                                               cs_uint16 msi_ext0);
                                               
cs_int16 ten_n10g_get_accepted_pti_byte(cs_uint16 module_id, cs_uint8 slice);

cs_int16 ten_n10g_get_accepted_msi_string(cs_uint16 module_id, cs_uint8 slice,
                                          cs_uint8 index);

cs_int32 ten_n10g_oohr_get_aps_pcc_bytes(cs_uint16 module_id, cs_uint8 slice,
                                         cs_uint8 channel);

cs_status ten_n10g_set_oohr_bipvala(cs_uint16 module_id, cs_uint8 slice,
                                    cs_uint16 bipvala01, cs_uint16 bipvala00);

cs_status ten_n10g_set_oohr_bipvalb(cs_uint16 module_id, cs_uint8 slice,
                                    cs_uint16 bipvalb01, cs_uint16 bipvalb00);

cs_status ten_n10g_oohr_bipcfg(cs_uint16 module_id, cs_uint8 slice, cs_uint16 bip7exs,
                               cs_uint16 bip7blk, cs_uint16 bip6exs, cs_uint16 bip6blk,
                               cs_uint16 bip5exs, cs_uint16 bip5blk, cs_uint16 bip4exs,
                               cs_uint16 bip4blk, cs_uint16 bip3exs, cs_uint16 bip3blk,
                               cs_uint16 bip2exs, cs_uint16 bip2blk, cs_uint16 bip1exs,
                               cs_uint16 bip1blk, cs_uint16 bip0exs, cs_uint16 bip0blk);

cs_status ten_n10g_set_oohr_beivala(cs_uint16 module_id, cs_uint8 slice,
                                    cs_uint16 beivala1, cs_uint16 beivala0);

cs_status ten_n10g_set_oohr_beivalb(cs_uint16 module_id, cs_uint8 slice,
                                    cs_uint16 beivalb1, cs_uint16 beivalb0);

cs_status ten_n10g_oohr_beicfg(cs_uint16 module_id, cs_uint8 slice, 
                           cs_uint16 layer,  
                           cs_uint16 bei_blk);                                    
                                    
cs_int16 ten_n10g_oohr_get_sm_status(cs_uint16 module_id, cs_uint8 slice,
                                     cs_uint8 select);

cs_int16 ten_n10g_oohr_get_tcm1_status(cs_uint16 module_id, cs_uint8 slice,
                                       cs_uint8 select);

cs_int16 ten_n10g_oohr_get_tcm2_status(cs_uint16 module_id, cs_uint8 slice,
                                       cs_uint8 select);

cs_int16 ten_n10g_oohr_get_tcm3_status(cs_uint16 module_id, cs_uint8 slice,
                                       cs_uint8 select);

cs_int16 ten_n10g_oohr_get_tcm4_status(cs_uint16 module_id, cs_uint8 slice,
                                       cs_uint8 select);

cs_int16 ten_n10g_oohr_get_tcm5_status(cs_uint16 module_id, cs_uint8 slice,
                                       cs_uint8 select);

cs_int16 ten_n10g_oohr_get_tcm6_status(cs_uint16 module_id, cs_uint8 slice,
                                       cs_uint8 select);

cs_int16 ten_n10g_oohr_get_pm_status(cs_uint16 module_id, cs_uint8 slice,
                                     cs_uint8 select);

cs_status ten_n10g_oohr_mfmcfg(cs_uint16 module_id, cs_uint8 slice, cs_uint8 match_unit,
                               cs_uint8 mfmcmp, cs_uint8 mfmmsk);

cs_status ten_n10g_set_oohr_afths1(cs_uint16 module_id, cs_uint8 slice, cs_uint16 af1stv);

cs_status ten_n10g_set_oohr_afthu1(cs_uint16 module_id, cs_uint8 slice, cs_uint16 af1utv);

cs_status ten_n10g_set_oohr_afths2(cs_uint16 module_id, cs_uint8 slice, cs_uint16 af2stv);

cs_status ten_n10g_set_oohr_afthu2(cs_uint16 module_id, cs_uint8 slice, cs_uint16 af2utv);

cs_status ten_n10g_set_oohr_afths3(cs_uint16 module_id, cs_uint8 slice, cs_uint16 af3stv);

cs_status ten_n10g_set_oohr_afthu3(cs_uint16 module_id, cs_uint8 slice, cs_uint16 af3utv);

cs_status ten_n10g_set_oohr_afths4(cs_uint16 module_id, cs_uint8 slice, cs_uint16 af4stv);

cs_status ten_n10g_set_oohr_afthu4(cs_uint16 module_id, cs_uint8 slice, cs_uint16 af4utv);

cs_status ten_n10g_oohr_cmp_unit(cs_uint16 module_id, cs_uint8 slice, cs_uint8 unit,
                                 cs_uint16 cmp);

cs_status ten_n10g_oohr_gaf_cfg(cs_uint16 module_id, cs_uint8 slice, cs_uint8 unit,
                                cs_uint16 afmsk, cs_uint16 afts, cs_uint16 afcol,
                                cs_uint16 afrow, cs_uint16 afi, cs_uint16 afmf);

cs_status ten_n10g_oohr_gaf_cmp(cs_uint16 module_id, cs_uint8 slice, cs_uint8 unit,
                                cs_uint16 gcmsk);

cs_int16 ten_n10g_oohr_get_gaf_status(cs_uint16 module_id, cs_uint8 slice, cs_uint8 unit,
                                      cs_uint8 select);

cs_status ten_n10g_oohr_config_string_extractor(cs_uint16 module_id, cs_uint8 slice,
                                                cs_uint8 unit, cs_uint16 se_mfe,
                                                cs_uint16 se_cnt, cs_uint16 se_col,
                                                cs_uint16 se_row, cs_uint16 se_cmp);

cs_status ten_n10g_oohr_config_string_extractor_cmp(cs_uint16 module_id, 
                             cs_uint8 slice, 
                             cs_uint8 unit, 
                             cs_uint16 se_cmp);
                             
cs_status ten_n10g_oohr_set_string_extractor_dt_dis(cs_uint16 module_id, 
                                                    cs_uint8 slice, 
                                                    cs_uint8 unit,  
                                                    cs_uint16 se_dt_dis);
                         
cs_status ten_n10g_oohr_set_string_extractor_dmm(cs_uint16 module_id, cs_uint8 slice,
                                                 cs_uint8 unit, cs_uint16 se_dmm);

cs_status ten_n10g_oohr_set_string_extractor_off(cs_uint16 module_id, cs_uint8 slice,
                                                 cs_uint8 unit, cs_uint16 se_off);

cs_int16 ten_n10g_oohr_get_string_extractor_unit_status0(cs_uint16 module_id,
                                                         cs_uint8 slice, cs_uint8 select);

cs_int16 ten_n10g_oohr_get_string_extractor_unit_status1(cs_uint16 module_id,
                                                         cs_uint8 slice, cs_uint8 select);

cs_int16 ten_n10g_oohr_get_defect_trace_identifier_status0(cs_uint16 module_id,
                                                           cs_uint8 slice,
                                                           cs_uint8 select);

cs_int16 ten_n10g_oohr_get_defect_trace_identifier_status1(cs_uint16 module_id,
                                                           cs_uint8 slice,
                                                           cs_uint8 select);

cs_status ten_n10g_oohr_config_string_inserter(cs_uint16 module_id, cs_uint8 slice,
                                               cs_uint8 unit, cs_uint16 sicnt,
                                               cs_uint16 simfe, cs_uint16 sicol,
                                               cs_uint16 sirow);

cs_status ten_n10g_oohr_set_string_inserter_ie(cs_uint16 module_id, cs_uint8 slice,
                                               cs_uint8 unit, cs_uint16 siie);

cs_status ten_n10g_oohr_string_insertion_update(cs_uint16 module_id, cs_uint8 slice,
                                                cs_uint8 unit);

cs_int16 ten_n10g_get_otu_framer_status(cs_uint16 module_id, cs_uint8 slice,
                                        cs_uint16 field);

cs_status ten_n10g_set_otnr_odwcfg(cs_uint16 module_id, cs_uint8 slice, cs_uint16 odu2sps,
                                   cs_uint16 mfp_len, cs_uint16 fsomd,
                                   cs_uint16 c15res_en, cs_uint16 g43md,
                                   cs_uint16 jc_plus, cs_uint16 stm64md, cs_uint16 dwmod);
                                   
cs_status ten_n10g_set_otnr_odwcfg_odu2sps(cs_uint16 module_id, cs_uint8 slice, cs_uint16 odu2sps);

cs_status ten_n10g_set_otnr_odwcfg_mfp_len(cs_uint16 module_id, cs_uint8 slice, 
                                           cs_uint16 mfp_len);
                                   
cs_status ten_n10g_set_otnr_odwfs(cs_uint16 module_id, cs_uint8 slice, cs_uint16 fs);

cs_int16 ten_n10g_get_otnr_odwfs(cs_uint16 module_id,
                                 cs_uint8 slice);

cs_status ten_n10g_otnr_descrambling(cs_uint16 module_id, cs_uint8 slice,
                                     cs_uint16 postdscr, cs_uint16 predscr);

cs_status ten_n10g_otnt_mfmcfg(cs_uint16 module_id, cs_uint8 slice, 
                               cs_uint8 match_unit, 
                               cs_uint16 mfmcmp, 
                               cs_uint16 mfmmsk);

cs_status ten_n10g_otnr_ocfg(cs_uint16 module_id, cs_uint8 slice, cs_boolean fecmd,
                             cs_boolean fecen);

cs_status ten_n10g_otnr_set_frame_format(cs_uint16 module_id, cs_uint8 slice,
                                         cs_uint16 ncols, cs_uint16 nrows,
                                         cs_uint16 nparb, cs_uint16 npar);

cs_status ten_n10g_otnr_set_dwmod(cs_uint16 module_id, cs_uint8 slice, cs_uint16 dwmod);

cs_status ten_n10g_otnr_set_jc_plus(cs_uint16 module_id, cs_uint8 slice,
                                    cs_uint16 jc_plus);

cs_status ten_n10g_otnr_set_c15res_en(cs_uint16 module_id, cs_uint8 slice,
                                      cs_uint16 c15res_en);

cs_status ten_n10g_otnr_set_stm64md(cs_uint16 module_id, cs_uint8 slice,
                                    cs_uint16 stm64md);

cs_status ten_n10g_otnr_set_g43md(cs_uint16 module_id, cs_uint8 slice, cs_uint16 g43md);

cs_status ten_n10g_otnr_set_fsomd(cs_uint16 module_id, cs_uint8 slice, cs_uint16 fsomd);

cs_status ten_n10g_otnr_set_linkalm_jcnom(cs_uint16 module_id, cs_uint8 slice, 
                           cs_uint16 linkalm_jcnom);

cs_status ten_n10g_otnr_set_ncols(cs_uint16 module_id, cs_uint8 slice, cs_uint16 ncols);

cs_status ten_n10g_otnr_set_nparb_npar(cs_uint16 module_id, cs_uint8 slice,
                                       cs_uint16 nparb, cs_uint16 npar);

cs_status ten_n10g_otnr_select_global_timing_source(cs_uint16 module_id, cs_uint8 slice,
                                                    cs_uint16 select);

cs_status ten_n10g_otnsm_set_string_inserter(cs_uint16 module_id, cs_uint8 slice,
                                             cs_uint16 instance, cs_char8 *str);

cs_status ten_n10g_otnsm_set_string_extractor(cs_uint16 module_id, cs_uint8 slice,
                                             cs_uint16 instance, cs_char8 *str);

cs_status ten_n10g_otnsm_get_string_extractor(cs_uint16 module_id, cs_uint8 slice,
                                             cs_uint16 instance, cs_char8 *str);

cs_status ten_n10g_otnt_set_frame_format(cs_uint16 module_id, cs_uint8 slice,
                                        cs_uint16 ncols, cs_uint16 nrows,
                                        cs_uint16 nparb, cs_uint16 npar);

cs_status ten_n10g_set_otnt_wrpcfg3(cs_uint16 module_id, cs_uint8 slice,
                                   cs_uint16 stm64md, cs_uint16 fpsynce,
                                   cs_uint16 c15res_en, cs_uint16 g43md,
                                   cs_uint16 wrmd);

cs_status ten_n10g_set_otnt_wrpcfg4(cs_uint16 module_id, cs_uint8 slice,
                                   cs_uint16 jc_plus_odtu23, cs_uint16 jc_plus_otu2,
                                   cs_uint16 jcen_dt, cs_uint16 jcen_odtu23,
                                   cs_uint16 jcen_otu2);

cs_status ten_n10g_otnt_set_wrpfs(cs_uint16 module_id, cs_uint8 slice, cs_uint16 fs);

cs_status ten_n10g_otnt_scrambling(cs_uint16 module_id, cs_uint8 slice,
                                  cs_uint16 postscr, cs_uint16 prescr);

cs_status ten_n10g_otnt_ocfg(cs_uint16 module_id, cs_uint8 slice, cs_boolean fecmd,
                            cs_boolean fecen);

cs_status ten_n10g_otnt_set_pti_byte(cs_uint16 module_id, cs_uint8 slice,
                                    cs_uint16 pti);

cs_status ten_n10g_otnt_cfg4(cs_uint16 module_id, cs_uint8 slice, cs_uint16 bipxor,
                            cs_uint16 bipmsk);

cs_status ten_n10g_otnt_bipmsk(cs_uint16 module_id, cs_uint8 slice, 
                               cs_uint16 bipmsk);

cs_status ten_n10g_otnt_set_apspcc(cs_uint16 module_id, cs_uint8 slice,
                                  cs_uint8 channel, cs_uint16 apspcc1,
                                  cs_uint16 apspcc0);

cs_boolean ten_n10g_otnt_get_lom_status(cs_uint16 module_id, cs_uint8 slice);

cs_status ten_n10g_otnt_set_jc_odtu23(cs_uint16 module_id, cs_uint8 slice,
                                     cs_uint16 jc_plus_odtu23, cs_uint16 jcen_dt,
                                     cs_uint16 jcen_odtu23);

cs_status ten_n10g_otnt_set_jcen_dt(cs_uint16 module_id,
                                    cs_uint8 slice, 
                                    cs_uint16 jcen_dt);

cs_status ten_n10g_otnt_set_wrmd(cs_uint16 module_id, cs_uint8 slice,
                                cs_uint16 wrmd);

cs_status ten_n10g_otnt_set_g43md(cs_uint16 module_id, cs_uint8 slice,
                                 cs_uint16 g43md);
                                 
cs_status ten_n10g_otnt_doaie(cs_uint16 module_id, cs_uint8 slice, 
                                cs_uint8  byte,
                                cs_uint16 insertion);
                                
cs_status ten_n10g_otnt_set_c15res_en(cs_uint16 module_id, cs_uint8 slice,
                                     cs_uint16 c15res_en);

cs_status ten_n10g_otnt_set_stm64md(cs_uint16 module_id, cs_uint8 slice,
                                   cs_uint16 stm64md);

cs_status ten_n10g_otnt_set_wrpcfg5(cs_uint16 module_id, cs_uint8 slice,
                                   cs_uint16 stuffbt);

cs_status ten_n10g_otnt_set_ncols(cs_uint16 module_id, cs_uint8 slice,
                                 cs_uint16 ncols);

cs_status ten_n10g_otnt_set_nparb_npar(cs_uint16 module_id, cs_uint8 slice,
                                      cs_uint16 nparb, cs_uint16 npar);

cs_status ten_n10g_otnt_set_fasie(cs_uint16 module_id, cs_uint8 slice,
                                 cs_uint16 fasie);
                                 
cs_status ten_n10g_otnt_cfg0_mfasins(cs_uint16 module_id, cs_uint8 slice, 
                         cs_uint16 mfasins);
                         
cs_status ten_n10g_otnt_cfg0_mfalgne(cs_uint16 module_id, cs_uint8 slice, 
                         cs_uint16 mfalgne);
                         
cs_int16 ten_n10g_get_accepted_poh_byte(cs_uint16 module_id, cs_uint8 slice,
                                      cs_uint16 ovrhd);

cs_int16 ten_n10g_get_poh_status(cs_uint16 module_id, cs_uint8 slice,
                                cs_uint16 field);

cs_status ten_n10g_set_pohr_b3btber(cs_uint16 module_id, cs_uint8 slice,
                                   cs_uint16 b3btber);

cs_status ten_n10g_set_pohr_b3blber(cs_uint16 module_id, cs_uint8 slice,
                                   cs_uint16 b3blber);

cs_status ten_n10g_set_pohr_j1cfg(cs_uint16 module_id,
                                  cs_uint8 slice, 
                                  cs_uint16 select, 
                                  cs_uint16 value);

cs_status ten_n10g_get_pohr_j1extr(cs_uint16 module_id,
                                   cs_uint8  slice,
                                   cs_char8 *str);
                                   
cs_status ten_n10g_print_pohr_j1extr(cs_uint16 module_id,
                                     cs_uint8 slice);

cs_status ten_n10g_set_pohr_j1hys(cs_uint16 module_id,
                                  cs_uint8  slice, 
                                  cs_uint8  select, 
                                  cs_uint8  hysteresis);

cs_int16 ten_n10g_get_sdfr_rx_status(cs_uint16 module_id, cs_uint8 slice,
                                    cs_uint16 field);

cs_status ten_n10g_set_sdfr_lofcfg1(cs_uint16 module_id, cs_uint8 slice,
                                   cs_uint16 lofimou, cs_uint16 lofimin);

cs_status ten_n10g_set_sdfr_b1btber(cs_uint16 module_id, cs_uint8 slice,
                                   cs_uint16 b1btber);

cs_status ten_n10g_set_sdfr_b1blber(cs_uint16 module_id, cs_uint8 slice,
                                   cs_uint16 b1blber);

cs_status ten_n10g_set_sdfr_b2btber(cs_uint16 module_id, cs_uint8 slice,
                                   cs_uint16 b2btber0, cs_uint16 b2btber1);

cs_status ten_n10g_set_sdfr_b2blber(cs_uint16 module_id, cs_uint8 slice,
                                   cs_uint16 b2blber0, cs_uint16 b2blber1);

cs_status ten_n10g_sdfr_set_sdfcfg(cs_uint16 module_id, cs_uint8 slice,
                                  cs_uint16 scren, cs_uint16 oofhy,
                                  cs_uint16 fawwup, cs_uint16 fawwdw);

cs_status ten_n10g_sdfr_set_scren(cs_uint16 module_id,
                                  cs_uint8 slice, 
                                  cs_uint16 scren);

cs_status ten_n10g_cs_sdfr_set_sdfcfg(cs_uint16 module_id, cs_uint8 slice,
                                     cs_uint16 bfaen);

cs_status ten_n10g_sdfr_set_sdfcfg1(cs_uint16 module_id, cs_uint8 slice,
                                   cs_uint16 altscr);

cs_status ten_n10g_sdfr_select_global_timing_source(cs_uint16 module_id,
                                                   cs_uint8 slice,
                                                   cs_uint16 select);

cs_int16 ten_n10g_get_overhead_byte(cs_uint16 module_id, cs_uint8 slice,
                                  cs_uint16 ovrhd);

cs_int16 ten_n10g_get_mst_status(cs_uint16 module_id, cs_uint8 slice,
                                cs_uint16 field);

cs_status ten_n10g_sohr_set_byte_err_trans_mode(cs_uint16 module_id, cs_uint8 slice,
                                               cs_uint16 b1trans,
                                               cs_uint16 b2trans);
                                               
cs_status ten_n10g_sohr_k12cfg(cs_uint16 module_id, cs_uint8 slice, 
                           cs_uint16 raflen, 
                           cs_uint16 aaflen, 
                           cs_uint16 kmlen, 
                           cs_uint16 kaflen);
                           
cs_status ten_n10g_sohr_k12cfg_kmlen(cs_uint16 module_id, cs_uint8 slice, 
                           cs_uint16 kmlen);
                           
cs_status ten_n10g_sohr_set_kaflen(cs_uint16 module_id, cs_uint8 slice, 
                           cs_uint16 kaflen);

cs_status ten_n10g_sohr_set_kaflen(cs_uint16 module_id, cs_uint8 slice,
                                  cs_uint16 kaflen);

cs_int16 ten_n10g_sohr_get_pis0(cs_uint16 module_id, cs_uint8 slice,
                               cs_uint8 instance);

cs_status ten_n10g_set_sohr_j0cfg(cs_uint16 module_id,
                                  cs_uint8 slice, 
                                  cs_uint16 select, 
                                  cs_uint16 value);

cs_status ten_n10g_get_sohr_j0extr(cs_uint16 module_id,
                                   cs_uint8  slice,
                                   cs_char8 *str);
                                   
cs_status ten_n10g_print_sohr_j0extr(cs_uint16 module_id,
                                     cs_uint8 slice);

cs_status ten_n10g_set_sohr_j0hys(cs_uint16 module_id,
                                  cs_uint8  slice, 
                                  cs_uint8  select, 
                                  cs_uint8  hysteresis);
                                  
cs_status ten_n10g_sohr_dcccfg_m01mode(cs_uint16 module_id, cs_uint8 slice, 
                                       cs_uint16 m01mode);

cs_status ten_n10g_set_soh_byte(cs_uint16 module_id, cs_uint8 slice, cs_uint16 ovrhd,
                               cs_uint8 val);
                               
cs_status ten_n10g_set_soh_byte_ie(cs_uint16 module_id,
                                cs_uint8 slice,
                                cs_uint16 ovrhd,
                                cs_uint8 ie);

cs_status ten_n10g_set_poh_byte(cs_uint16 module_id, cs_uint8 slice, cs_uint16 ovrhd,
                               cs_uint8 val);
                               
cs_status ten_n10g_set_poh_byte_ie(cs_uint16 module_id,
                                cs_uint8 slice,
                                cs_uint16 ovrhd,
                                cs_uint8 ie);
                               
cs_status ten_n10g_soht_b2ie(cs_uint16 module_id, cs_uint8 slice, cs_uint8 instance, 
                          cs_uint16 b2ie);                               

cs_status ten_n10g_soht_set_ohben0(cs_uint16 module_id, cs_uint8 slice,
                                  cs_uint16 b1ie, cs_uint16 scren,
                                  cs_uint16 a1a2rsh, cs_uint16 a1a2ie);

cs_status ten_n10g_soht_set_scren(cs_uint16 module_id,
                                  cs_uint8 slice, 
                                  cs_uint16 scren);

cs_status ten_n10g_soht_set_ohben0_j0ie(cs_uint16 module_id, cs_uint8 slice,
                                       cs_uint16 j0ie);

cs_status ten_n10g_soht_set_ohben0_j0mode(cs_uint16 module_id,
                                          cs_uint8 slice, 
                                          cs_uint16 j0mode);

cs_status ten_n10g_soht_set_ohben0_defie(cs_uint16 module_id, cs_uint8 slice,
                                        cs_uint16 defie);
                                        
cs_status ten_n10g_soht_set_ohben0_nu1ie(cs_uint16 module_id, cs_uint8 slice, 
                           cs_uint16 nu1ie);                                        

cs_status ten_n10g_soht_set_ohben1(cs_uint16 module_id, cs_uint8 slice,
                                  cs_uint16 b2inv, cs_uint16 b1inv,
                                  cs_uint16 b2trans, cs_uint16 b1trans);

cs_status ten_n10g_soht_set_ohben1_k2ie(cs_uint16 module_id, cs_uint8 slice,
                                   cs_uint16 k2ie);

cs_status ten_n10g_soht_set_ohben1_k1ie(cs_uint16 module_id, cs_uint8 slice,
                                   cs_uint16 k1ie);

cs_status ten_n10g_soht_set_ohben2(cs_uint16 module_id, cs_uint8 slice,
                                  cs_uint16 m1ie, cs_uint16 m0ie);

cs_status ten_n10g_soht_set_ohben3(cs_uint16 module_id, cs_uint8 slice,
                                  cs_uint16 alt_scren);
                                  
cs_status ten_n10g_soht_ohben3_dis_a1a2_ais(cs_uint16 module_id, cs_uint8 slice, 
                                            cs_uint16 dis_a1a2_ais);
                                            
cs_status ten_n10g_soht_ohben3_dis_b1_ais(cs_uint16 module_id, cs_uint8 slice, 
                                          cs_uint16 dis_b1_ais);

cs_status ten_n10g_soht_set_b1errmsk(cs_uint16 module_id, cs_uint8 slice,
                                    cs_uint16 b1errmsk);

cs_status ten_n10g_soht_set_b2errmsk(cs_uint16 module_id, cs_uint8 slice,
                                    cs_uint16 b2errmsk);

cs_status ten_n10g_soht_j0strg0(cs_uint16 module_id,
                                cs_uint8 slice,
                                cs_uint8 instance, 
                                cs_uint16 j0strg0);

cs_status ten_n10g_soht_j0strg_ptr(cs_uint16 module_id,
                                   cs_uint8 slice,
                                   cs_uint16 str_size,
                                   cs_char8 *str);
                                   
cs_status ten_n10g_soht_get_j0strg(cs_uint16 module_id,
                                   cs_uint8 slice,
                                   cs_char8 *str);
                                   
cs_status ten_n10g_soht_print_j0strg(cs_uint16 module_id,
                                     cs_uint8 slice);

cs_status ten_n10g_soht_j1strg0(cs_uint16 module_id,
                                cs_uint8 slice,
                                cs_uint8 instance, 
                                cs_uint16 j1strg0);

cs_status ten_n10g_soht_j1strg_ptr(cs_uint16 module_id,
                                   cs_uint8 slice,
                                   cs_uint16 str_size,
                                   cs_char8 *str);
                                   
cs_status ten_n10g_soht_get_j1strg(cs_uint16 module_id,
                                   cs_uint8 slice,
                                   cs_char8 *str);
                                   
cs_status ten_n10g_soht_print_j1strg(cs_uint16 module_id,
                                     cs_uint8 slice);
                                     
cs_status ten_n10g_soht_pohben0(cs_uint16 module_id, cs_uint8 slice,
                                   cs_uint16 prbsie, cs_uint16 pohie);

cs_status ten_n10g_soht_set_pohben0_j1ie(cs_uint16 module_id, cs_uint8 slice,
                                        cs_uint16 j1ie);

cs_status ten_n10g_soht_set_pohben0_j1mode(cs_uint16 module_id,
                                           cs_uint8 slice, 
                                           cs_uint16 j1mode);

cs_status ten_n10g_soht_set_pohben0_c2ie(cs_uint16 module_id, cs_uint8 slice,
                                        cs_uint16 c2ie);

cs_status ten_n10g_soht_set_pohben0_b3ie(cs_uint16 module_id, cs_uint8 slice,
                                        cs_uint16 b3ie);

cs_status ten_n10g_soht_set_pohben1(cs_uint16 module_id, cs_uint8 slice,
                                   cs_uint16 ndfie);

cs_status ten_n10g_set_maismsk(cs_uint16 module_id, cs_uint8 slice,
                              cs_uint16 maismsk);

cs_status ten_n10g_soht_force_aisp(cs_uint16 module_id, cs_uint8 slice, cs_uint8 sts,
                                  cs_uint16 state);


cs_status ten_n10g_otnr_set_fs_mlen(cs_uint16 module_id, cs_uint8 slice, 
                                    cs_uint16 fs_mlen);

cs_status ten_n10g_otnr_set_fs_aflen(cs_uint16 module_id, cs_uint8 slice, 
                                     cs_uint16 fs_aflen);

cs_int16 ten_n10g_otnr_get_odwfsfilt(cs_uint16 module_id, cs_uint8 slice);

cs_status ten_n10g_set_sofr_j0_ram(cs_uint16 module_id,
                                   cs_uint8  slice,
                                   cs_uint16 str_size, 
                                   cs_char8 *str);

cs_status ten_n10g_get_sofr_j0_ram(cs_uint16 module_id,
                                   cs_uint8  slice,
                                   cs_char8 *str);
                                   
cs_status ten_n10g_print_sofr_j0_ram(cs_uint16 module_id,
                                   cs_uint8 slice);
                                   
cs_status ten_n10g_set_sofr_j1_ram(cs_uint16 module_id,
                                   cs_uint8  slice,
                                   cs_uint16 str_size, 
                                   cs_char8 *str);

cs_status ten_n10g_get_sofr_j1_ram(cs_uint16 module_id,
                                   cs_uint8  slice,
                                   cs_char8 *str);
                                   
cs_status ten_n10g_print_sofr_j1_ram(cs_uint16 module_id,
                                   cs_uint8 slice);

cs_status ten_n10g_gblr_loscfg0(cs_uint16 module_id, cs_uint8 slice,
                                cs_uint16 loscfg);

cs_status ten_n10g_gblr_loscfg1(cs_uint16 module_id, cs_uint8 slice,
                                cs_uint16 loscfg);

cs_status ten_n10g_gblr_loscfg2(cs_uint16 module_id, cs_uint8 slice,
                                cs_uint16 loscfg);

cs_status ten_n10g_gblr_loscfg3(cs_uint16 module_id, cs_uint8 slice,
                                cs_uint16 loscfg);

cs_status ten_n10g_otnt_set_ptie(cs_uint16 module_id, cs_uint8 slice, 
                                 cs_uint16 ptie);

cs_status ten_n10g_gblr_set_kpasel(cs_uint16 module_id,
                                   cs_uint8  slice,
                                   cs_uint16 kpasel);

cs_status ten_n10g_soht_set_a1a2ie(cs_uint16 module_id,
                                   cs_uint8 slice, 
                                   cs_uint16 a1a2ie);

cs_status ten_n10g_soht_prbsie(cs_uint16 module_id, cs_uint8 slice, 
                               cs_uint16 prbsie);

cs_status ten_n10g_soht_pohie(cs_uint16 module_id, cs_uint8 slice, 
                              cs_uint16 pohie);

cs_status ten_n10g_soht_set_b1ie(cs_uint16 module_id, cs_uint8 slice, 
                                 cs_uint16 b1ie);

cs_status ten_n10g_set_rdimsk(cs_uint16 module_id,
                              cs_uint8  slice, 
                              cs_uint16 rdimsk);

cs_status ten_n10g_set_mais(cs_uint16 module_id,
                            cs_uint8  slice, 
                            cs_uint16 mais);

cs_status ten_n10g_set_pohr_g1_config(cs_uint16 module_id,
                                      cs_uint8  slice, 
                                      cs_uint16 select, 
                                      cs_uint16 value);

cs_status ten_n10g_oohr_beiexs(cs_uint16 module_id, cs_uint8 slice, 
                               cs_uint16 layer,  
                               cs_uint16 bei_exs);

cs_int16 ten_n10g_get_expected_pti_byte(cs_uint16 module_id, 
                                        cs_uint8 slice);

cs_boolean ten_n10g_compare_pti_byte(cs_uint16 module_id, 
                                        cs_uint8 slice);
                                        
cs_status ten_n10g_otnr_oacfg0_dsyhyst(cs_uint16 module_id, cs_uint8 slice, 
                           cs_uint16 dsyhyst);
                           
cs_status ten_n10g_otnr_lofcfg_tdelon_tdeloff(cs_uint16 module_id, cs_uint8 slice, 
                                              cs_uint16 tdelon, cs_uint16 tdeloff);
 
cs_status ten_n10g_pn11_pattern_select_t41(cs_uint16 module_id,
                                           cs_uint8 slice,
                                           cs_uint16 pn11_type);
                                           
                                           
/**********************************************************************/
/* Prototypes for auto-gen code                                       */
/**********************************************************************/
cs_status ten_n10g_tx_bypass_t41(cs_uint16 module_id, cs_uint8  slice, cs_uint16 bypass);
cs_status ten_n10g_tx_gfec_t41(cs_uint16 module_id, cs_uint8  slice);
cs_status ten_n10g_tx_sm_bip_insertion_t41(cs_uint16 module_id, cs_uint8  slice);
cs_status ten_n10g_tx_nrows_t41(cs_uint16 module_id, cs_uint8  slice, cs_uint16 rows);
cs_status ten_n10g_tx_ncols_t41(cs_uint16 module_id, cs_uint8  slice, cs_uint16 columns);
cs_status ten_n10g_tx_npar_t41(cs_uint16 module_id, cs_uint8  slice, cs_uint16 parity);
cs_status ten_n10g_tx_nparb_t41(cs_uint16 module_id, cs_uint8  slice, cs_uint16 parity);
cs_status ten_n10g_tx_otu2_t41(cs_uint16 module_id, cs_uint8  slice);
cs_status ten_n10g_tx_odu2_t41(cs_uint16 module_id, cs_uint8  slice);
cs_status ten_n10g_tx_oduflex_t41(cs_uint16 module_id, cs_uint8  slice);
cs_status ten_n10g_tx_odu2aggr_t41(cs_uint16 module_id, cs_uint8  slice);
cs_status ten_n10g_tx_oduflex_aggr_t41(cs_uint16 module_id, cs_uint8  slice);
cs_status ten_n10g_tx_tcmbipinsertion_t41(cs_uint16 module_id, cs_uint8  slice);
cs_status ten_n10g_tx_pmbipinsertion_t41(cs_uint16 module_id, cs_uint8  slice);
cs_status ten_n10g_tx_opu2_t41(cs_uint16 module_id, cs_uint8  slice);
cs_status ten_n10g_tx_cbr10_t41(cs_uint16 module_id, cs_uint8  slice);
cs_status ten_n10g_tx_oc192_ftregen_t41(cs_uint16 module_id, cs_uint8  slice);
cs_status ten_n10g_tx_oc192_rsregen_t41(cs_uint16 module_id, cs_uint8  slice);
cs_status ten_n10g_tx_b2insertion_t41(cs_uint16 module_id, cs_uint8  slice);
cs_status ten_n10g_tx_oc192_msregen_t41(cs_uint16 module_id, cs_uint8  slice);
cs_status ten_n10g_tx_oc192_out_t41(cs_uint16 module_id, cs_uint8  slice);
cs_status ten_n10g_tx_vc4_64c_gen_t41(cs_uint16 module_id, cs_uint8  slice);
cs_status ten_n10g_tx_pkt_t41(cs_uint16 module_id, cs_uint8  slice);
cs_status ten_n10g_tx_circuit_t41(cs_uint16 module_id, cs_uint8  slice);
cs_status ten_n10g_tx_ufec_t41(cs_uint16 module_id, cs_uint8  slice);
cs_status ten_n10g_tx_b3insertion_t41(cs_uint16 module_id, cs_uint8  slice);
cs_status ten_n10g_tx_bmp_t41(cs_uint16 module_id, cs_uint8  slice);
cs_status ten_n10g_tx_amp_t41(cs_uint16 module_id, cs_uint8  slice);
cs_status ten_n10g_tx_amp_prop_t41(cs_uint16 module_id, cs_uint8  slice, cs_uint16 fixedstuff);
cs_status ten_n10g_tx_gmp_lo_t41(cs_uint16 module_id, cs_uint8  slice);
cs_status ten_n10g_tx_gmp_ho_t41(cs_uint16 module_id, cs_uint8  slice);
cs_status ten_n10g_tx_gmp_cm_cn_t41(cs_uint16 module_id, cs_uint8  slice, cs_uint16 cm, cs_uint16 cn_lo16, cs_uint16 cn_hibit);
cs_status ten_n10g_tx_amp_odtu_t41(cs_uint16 module_id, cs_uint8  slice);
cs_status ten_n10g_tx_amp_prop_odtu_t41(cs_uint16 module_id, cs_uint8  slice);
cs_status ten_n10g_tx_gmp_ho_odtu_t41(cs_uint16 module_id, cs_uint8  slice);
cs_status ten_n10g_tx_odtu_detamp_t41(cs_uint16 module_id, cs_uint8  slice);
cs_status ten_n10g_tx_gfp_mapping_t41(cs_uint16 module_id, cs_uint8  slice);
cs_status ten_n10g_tx_ufec7_t41(cs_uint16 module_id, cs_uint8  slice);
cs_status ten_n10g_tx_ufec10_t41(cs_uint16 module_id, cs_uint8  slice);
cs_status ten_n10g_tx_ufec15_t41(cs_uint16 module_id, cs_uint8  slice);
cs_status ten_n10g_tx_ufec20_t41(cs_uint16 module_id, cs_uint8  slice);
cs_status ten_n10g_tx_ufec26_t41(cs_uint16 module_id, cs_uint8  slice);
cs_status ten_n10g_tx_otn_scr_off_t41(cs_uint16 module_id, cs_uint8  slice);
cs_status ten_n10g_tx_oc192_scr_off_t41(cs_uint16 module_id, cs_uint8  slice);
cs_status ten_n10g_tx_fec_datapath_bypass_t41(cs_uint16 module_id, cs_uint8  slice);
cs_status ten_n10g_tx_g43md_t41(cs_uint16 module_id, cs_uint8  slice);
cs_status ten_n10g_tx_pkt_bypass_t41(cs_uint16 module_id, cs_uint8  slice);
cs_status ten_n10g_tx_pp40g_enable_t41(cs_uint16 module_id, cs_uint8  slice);
cs_status ten_n10g_tx_pp40g_disable_t41(cs_uint16 module_id, cs_uint8  slice);
cs_status ten_n10g_tx_circuit_bypass_t41(cs_uint16 module_id, cs_uint8  slice);
cs_status ten_n10g_tx_pp40g_circuit_bypass_t41(cs_uint16 module_id, cs_uint8  slice);
cs_status ten_n10g_tx_prbs_oc192_t41(cs_uint16 module_id, cs_uint8  slice, cs_uint16 pattern);
cs_status ten_n10g_tx_prbs_otu2_t41(cs_uint16 module_id, cs_uint8  slice, cs_uint16 pattern);
cs_status ten_n10g_tx_prbs_oc192_msregen_otu2_t41(cs_uint16 module_id, cs_uint8  slice, cs_uint16 pattern);
cs_status ten_n10g_tx_10ge_odu2_t41(cs_uint16 module_id, cs_uint8  slice);
cs_status ten_n10g_tx_10ge_odu2_odtu_t41(cs_uint16 module_id, cs_uint8  slice);
cs_status ten_n10g_tx_10ge_bmp_odu2e_t41(cs_uint16 module_id, cs_uint8  slice);
cs_status ten_n10g_tx_10ge_bmp_otu1e_t41(cs_uint16 module_id, cs_uint8  slice);
cs_status ten_n10g_tx_10ge_bmp_otu2e_t41(cs_uint16 module_id, cs_uint8  slice);
cs_status ten_n10g_tx_10ge_bmp_odu2e_odtu_t41(cs_uint16 module_id, cs_uint8  slice);
cs_status ten_n10g_tx_10ge_oc192_msregen_bmp_odu2_t41(cs_uint16 module_id, cs_uint8  slice);
cs_status ten_n10g_tx_10ge_oc192_msregen_bmp_odu2_odtu_t41(cs_uint16 module_id, cs_uint8  slice);
cs_status ten_n10g_tx_10gfc_odu2e_odtu_t41(cs_uint16 module_id, cs_uint8  slice);
cs_status ten_n10g_tx_cbr_bmp_odu2e_odtu_t41(cs_uint16 module_id, cs_uint8  slice);
cs_status ten_n10g_tx_10ge_odu2e_odtu_t41(cs_uint16 module_id, cs_uint8  slice);
cs_status ten_n10g_tx_10gfc_odu2e_t41(cs_uint16 module_id, cs_uint8  slice);
cs_status ten_n10g_tx_40gep_odu2e_t41(cs_uint16 module_id, cs_uint8  slice);
cs_status ten_n10g_tx_40gep_otu2e_t41(cs_uint16 module_id, cs_uint8  slice);
cs_status ten_n10g_tx_40gep_otu2e_26p_t41(cs_uint16 module_id, cs_uint8  slice);
cs_status ten_n10g_tx_40ge_odu2e_odtu_t41(cs_uint16 module_id, cs_uint8  slice);
cs_status ten_n10g_tx_40ge_odu2e_odtu_dt_t41(cs_uint16 module_id, cs_uint8  slice);
cs_status ten_n10g_tx_oc192_msregen_bmp_odu2_t41(cs_uint16 module_id, cs_uint8  slice);
cs_status ten_n10g_tx_opu2_odu2_odtu_t41(cs_uint16 module_id, cs_uint8  slice);
cs_status ten_n10g_tx_oc192_msregen_bmp_odu2_odtu_t41(cs_uint16 module_id, cs_uint8  slice);
cs_status ten_n10g_tx_4gfc_mon_bmp_oduflex_t41(cs_uint16 module_id, cs_uint8  slice);
cs_status ten_n10g_tx_8gfc_mon_bmp_oduflex_t41(cs_uint16 module_id, cs_uint8  slice);
cs_status ten_n10g_tx_5giba_mon_bmp_oduflex_t41(cs_uint16 module_id, cs_uint8  slice);
cs_status ten_n10g_tx_4gfc_mon_bmp_oduflex_odtu_t41(cs_uint16 module_id, cs_uint8  slice);
cs_status ten_n10g_tx_8gfc_mon_bmp_oduflex_odtu_t41(cs_uint16 module_id, cs_uint8  slice);
cs_status ten_n10g_tx_5giba_mon_bmp_oduflex_odtu_t41(cs_uint16 module_id, cs_uint8  slice);
cs_status ten_n10g_tx_odu2_otu2_t41(cs_uint16 module_id, cs_uint8  slice);
cs_status ten_n10g_tx_odu2_odtu_t41(cs_uint16 module_id, cs_uint8  slice);
cs_status ten_n10g_tx_odu1e_otu1e_t41(cs_uint16 module_id, cs_uint8  slice);
cs_status ten_n10g_tx_8gfc_mon_gmp_lo_odu2_t41(cs_uint16 module_id, cs_uint8  slice);
cs_status ten_n10g_tx_8gfc_mon_gmp_lo_odu2_odtu_t41(cs_uint16 module_id, cs_uint8  slice);
cs_status ten_n10g_tx_oduflex_gmp_ho_otu2_t41(cs_uint16 module_id, cs_uint8  slice);
cs_status ten_n10g_tx_oduflex_gmp_ho_otu2e_t41(cs_uint16 module_id, cs_uint8  slice);
cs_status ten_n10g_tx_8gfc_oduflex_gmp_ho_otu2_t41(cs_uint16 module_id, cs_uint8  slice);
cs_status ten_n10g_tx_4gfc_oduflex_gmp_ho_otu2e_t41(cs_uint16 module_id, cs_uint8  slice);
cs_status ten_n10g_tx_8gfc_oduflex_gmp_lo_otu2_t41(cs_uint16 module_id, cs_uint8  slice);
cs_status ten_n10g_tx_oc192_msregen_oc192_out_t41(cs_uint16 module_id, cs_uint8  slice);
cs_status ten_n10g_tx_prbs_out_t41(cs_uint16 module_id, cs_uint8  slice, cs_uint16 pattern);
cs_status ten_n10g_tx_prbs_odu2_t41(cs_uint16 module_id, cs_uint8  slice, cs_uint16 pattern);
cs_status ten_n10g_tx_prbs_oc192_odu2_t41(cs_uint16 module_id, cs_uint8  slice, cs_uint16 pattern);
cs_status ten_n10g_tx_oc192_msregen_otu2_t41(cs_uint16 module_id, cs_uint8  slice);
cs_status ten_n10g_tx_pkt_otu2_t41(cs_uint16 module_id, cs_uint8  slice);
cs_status ten_n10g_tx_pkt_oc192_t41(cs_uint16 module_id, cs_uint8  slice);
cs_status ten_n10g_tx_internal_bypass_t41(cs_uint16 module_id, cs_uint8  slice);
cs_status ten_n10g_tx_circuit_internal_bypass_t41(cs_uint16 module_id, cs_uint8  slice);
cs_status ten_n10g_tx_pkt_internal_bypass_t41(cs_uint16 module_id, cs_uint8  slice);
cs_status ten_n10g_tx_oc192_msregen_amp_odu2_dtamp_odtu_t41(cs_uint16 module_id, cs_uint8  slice);
cs_status ten_n10g_tx_oc192_rsregen_amp_odu2_dtamp_odtu_t41(cs_uint16 module_id, cs_uint8  slice);
cs_status ten_n10g_tx_oc192_ftregen_amp_odu2_dtamp_odtu_t41(cs_uint16 module_id, cs_uint8  slice);
cs_status ten_n10g_tx_odtu_detgmp_t41(cs_uint16 module_id, cs_uint8  slice);
cs_status ten_n10g_tx_oc192_msregen_amp_odu2_dtgmp_odtu_t41(cs_uint16 module_id, cs_uint8  slice);
cs_status ten_n10g_tx_oc192_rsregen_amp_odu2_dtgmp_odtu_t41(cs_uint16 module_id, cs_uint8  slice);
cs_status ten_n10g_tx_oc192_ftregen_amp_odu2_dtgmp_odtu_t41(cs_uint16 module_id, cs_uint8  slice);
cs_status ten_n10g_tx_oc192_rsregen_oc192_out_t41(cs_uint16 module_id, cs_uint8  slice);
cs_status ten_n10g_tx_oc192_ftregen_oc192_out_t41(cs_uint16 module_id, cs_uint8  slice);
cs_status ten_n10g_tx_oc192_rsregen_bmp_odu2_odtu_t41(cs_uint16 module_id, cs_uint8  slice);
cs_status ten_n10g_tx_oc192_bmp_odu2_odtu_t41(cs_uint16 module_id, cs_uint8  slice);
cs_status ten_n10g_tx_opu2_amp_odu2_odtu_t41(cs_uint16 module_id, cs_uint8  slice);
cs_status ten_n10g_tx_opu2_odu2_otu2_t41(cs_uint16 module_id, cs_uint8  slice);
cs_status ten_n10g_tx_opu2_odu2_gmp_odtu_t41(cs_uint16 module_id, cs_uint8  slice);
cs_status ten_n10g_tx_opu2_odu2_otu1e_t41(cs_uint16 module_id, cs_uint8  slice);
cs_status ten_n10g_tx_opu2_odu2_otu2v_t41(cs_uint16 module_id, cs_uint8  slice);
cs_status ten_n10g_tx_passthru_10gpkt_to_40gckt_t41(cs_uint16 module_id, cs_uint8  slice);
cs_status ten_n10g_rx_gfec_t41(cs_uint16 module_id, cs_uint8  slice);
cs_status ten_n10g_rx_ufec_t41(cs_uint16 module_id, cs_uint8  slice);
cs_status ten_n10g_rx_nrows_t41(cs_uint16 module_id, cs_uint8  slice, cs_uint16 rows);
cs_status ten_n10g_rx_ncols_t41(cs_uint16 module_id, cs_uint8  slice, cs_uint16 columns);
cs_status ten_n10g_rx_npar_t41(cs_uint16 module_id, cs_uint8  slice, cs_uint16 parity);
cs_status ten_n10g_rx_nparb_t41(cs_uint16 module_id, cs_uint8  slice, cs_uint16 parity);
cs_status ten_n10g_rx_otu2_t41(cs_uint16 module_id, cs_uint8  slice);
cs_status ten_n10g_rx_odu2_t41(cs_uint16 module_id, cs_uint8  slice);
cs_status ten_n10g_rx_oduflex_t41(cs_uint16 module_id, cs_uint8  slice);
cs_status ten_n10g_rx_odu2aggr_t41(cs_uint16 module_id, cs_uint8  slice);
cs_status ten_n10g_rx_monitor_opu2_prbs_t41(cs_uint16 module_id, cs_uint8  slice);
cs_status ten_n10g_rx_opu2_t41(cs_uint16 module_id, cs_uint8  slice);
cs_status ten_n10g_rx_cbr10_t41(cs_uint16 module_id, cs_uint8  slice);
cs_status ten_n10g_rx_oc192_ftregen_t41(cs_uint16 module_id, cs_uint8  slice);
cs_status ten_n10g_rx_oc192_rsregen_t41(cs_uint16 module_id, cs_uint8  slice);
cs_status ten_n10g_rx_oc192_msregen_t41(cs_uint16 module_id, cs_uint8  slice);
cs_status ten_n10g_rx_oc192_in_t41(cs_uint16 module_id, cs_uint8  slice);
cs_status ten_n10g_rx_vc4_64c_term_t41(cs_uint16 module_id, cs_uint8  slice);
cs_status ten_n10g_rx_cbr10in_t41(cs_uint16 module_id, cs_uint8  slice);
cs_status ten_n10g_rx_bmp_t41(cs_uint16 module_id, cs_uint8  slice);
cs_status ten_n10g_rx_amp_t41(cs_uint16 module_id, cs_uint8  slice);
cs_status ten_n10g_rx_amp_prop_t41(cs_uint16 module_id, cs_uint8  slice, cs_uint16 fs);
cs_status ten_n10g_rx_gmp_lo_t41(cs_uint16 module_id, cs_uint8  slice);
cs_status ten_n10g_rx_gmp_ho_t41(cs_uint16 module_id, cs_uint8  slice);
cs_status ten_n10g_rx_gmp_cn_t41(cs_uint16 module_id, cs_uint8  slice, cs_uint16 cn_lo16, cs_uint16 cn_hibit);
cs_status ten_n10g_rx_gfp_mapping_t41(cs_uint16 module_id, cs_uint8  slice);
cs_status ten_n10g_rx_ufec7_t41(cs_uint16 module_id, cs_uint8  slice);
cs_status ten_n10g_rx_ufec10_t41(cs_uint16 module_id, cs_uint8  slice);
cs_status ten_n10g_rx_ufec15_t41(cs_uint16 module_id, cs_uint8  slice);
cs_status ten_n10g_rx_ufec20_t41(cs_uint16 module_id, cs_uint8  slice);
cs_status ten_n10g_rx_ufec26_t41(cs_uint16 module_id, cs_uint8  slice);
cs_status ten_n10g_rx_otn_scr_off_t41(cs_uint16 module_id, cs_uint8  slice);
cs_status ten_n10g_rx_oc192_scr_off_t41(cs_uint16 module_id, cs_uint8  slice);
cs_status ten_n10g_rx_fec_datapath_bypass_t41(cs_uint16 module_id, cs_uint8  slice);
cs_status ten_n10g_rx_g43md_t41(cs_uint16 module_id, cs_uint8  slice);
cs_status ten_n10g_rx_oc192_prbs_t41(cs_uint16 module_id, cs_uint8  slice);
cs_status ten_n10g_rx_otu2_prbs_t41(cs_uint16 module_id, cs_uint8  slice);
cs_status ten_n10g_rx_otu2_oc192_msregen_prbs_t41(cs_uint16 module_id, cs_uint8  slice);
cs_status ten_n10g_rx_odu2_10ge_t41(cs_uint16 module_id, cs_uint8  slice);
cs_status ten_n10g_rx_odtu_odu2_10ge_t41(cs_uint16 module_id, cs_uint8  slice);
cs_status ten_n10g_rx_odu2e_bmp_10ge_t41(cs_uint16 module_id, cs_uint8  slice);
cs_status ten_n10g_rx_otu2e_bmp_10ge_t41(cs_uint16 module_id, cs_uint8  slice);
cs_status ten_n10g_rx_otu1e_bmp_10ge_t41(cs_uint16 module_id, cs_uint8  slice);
cs_status ten_n10g_rx_odtu_odu2e_bmp_10ge_t41(cs_uint16 module_id, cs_uint8  slice);
cs_status ten_n10g_rx_odtu_odu1e_bmp_10ge_t41(cs_uint16 module_id, cs_uint8  slice);
cs_status ten_n10g_rx_odu2_bmp_oc192_msregen_10ge_t41(cs_uint16 module_id, cs_uint8  slice);
cs_status ten_n10g_rx_odtu_odu2_bmp_oc192_msregen_10ge_t41(cs_uint16 module_id, cs_uint8  slice);
cs_status ten_n10g_rx_odtu_odu2e_10gfc_t41(cs_uint16 module_id, cs_uint8  slice);
cs_status ten_n10g_rx_odtu_odu2e_10ge_t41(cs_uint16 module_id, cs_uint8  slice);
cs_status ten_n10g_rx_odu2e_10gfc_t41(cs_uint16 module_id, cs_uint8  slice);
cs_status ten_n10g_rx_odu2e_40gep_t41(cs_uint16 module_id, cs_uint8  slice);
cs_status ten_n10g_rx_otu2e_40gep_t41(cs_uint16 module_id, cs_uint8  slice);
cs_status ten_n10g_rx_otu2e_40gep_26p_t41(cs_uint16 module_id, cs_uint8  slice);
cs_status ten_n10g_rx_odu2_bmp_oc192_msregen_t41(cs_uint16 module_id, cs_uint8  slice);
cs_status ten_n10g_rx_odtu_odu2_bmp_oc192_msregen_t41(cs_uint16 module_id, cs_uint8  slice);
cs_status ten_n10g_rx_oduflex_bmp_4gfc_t41(cs_uint16 module_id, cs_uint8  slice);
cs_status ten_n10g_rx_oduflex_bmp_8gfc_t41(cs_uint16 module_id, cs_uint8  slice);
cs_status ten_n10g_rx_oduflex_bmp_5giba_t41(cs_uint16 module_id, cs_uint8  slice);
cs_status ten_n10g_rx_odtu_oduflex_bmp_4gfc_t41(cs_uint16 module_id, cs_uint8  slice);
cs_status ten_n10g_rx_odtu_oduflex_bmp_8gfc_t41(cs_uint16 module_id, cs_uint8  slice);
cs_status ten_n10g_rx_odtu_oduflex_bmp_5giba_t41(cs_uint16 module_id, cs_uint8  slice);
cs_status ten_n10g_rx_otu2_odu2_t41(cs_uint16 module_id, cs_uint8  slice);
cs_status ten_n10g_rx_odtu_odu2_t41(cs_uint16 module_id, cs_uint8  slice);
cs_status ten_n10g_rx_otu1e_odu1e_t41(cs_uint16 module_id, cs_uint8  slice);
cs_status ten_n10g_rx_odu2_gmp_lo_8gfc_t41(cs_uint16 module_id, cs_uint8  slice);
cs_status ten_n10g_rx_odtu_gmp_lo_8gfc_t41(cs_uint16 module_id, cs_uint8  slice);
cs_status ten_n10g_rx_odtu_odu2_gmp_lo_8gfc_t41(cs_uint16 module_id, cs_uint8  slice);
cs_status ten_n10g_rx_otu2_gmp_ho_oduflex_t41(cs_uint16 module_id, cs_uint8  slice);
cs_status ten_n10g_rx_otu2e_gmp_ho_oduflex_t41(cs_uint16 module_id, cs_uint8  slice);
cs_status ten_n10g_rx_otu2_gmp_ho_oduflex_8gfc_t41(cs_uint16 module_id, cs_uint8  slice);
cs_status ten_n10g_rx_otu2e_gmp_ho_oduflex_4gfc_t41(cs_uint16 module_id, cs_uint8  slice);
cs_status ten_n10g_rx_otu2_gmp_lo_oduflex_8gfc_t41(cs_uint16 module_id, cs_uint8  slice);
cs_status ten_n10g_rx_oc192_in_oc192_msregen_t41(cs_uint16 module_id, cs_uint8  slice);
cs_status ten_n10g_rx_odu2_prbs_t41(cs_uint16 module_id, cs_uint8  slice);
cs_status ten_n10g_rx_odu2_oc192_msregen_prbs_t41(cs_uint16 module_id, cs_uint8  slice);
cs_status ten_n10g_rx_otu2_oc192_msregen_t41(cs_uint16 module_id, cs_uint8  slice);
cs_status ten_n10g_rx_bypass_40g_traffic_t41(cs_uint16 module_id, cs_uint8  slice);
cs_status ten_n10g_rx_bypass_external_t41(cs_uint16 module_id, cs_uint8  slice);
cs_status ten_n10g_rx_bypass_non_intrusive_pp10gmon_t41(cs_uint16 module_id, cs_uint8  slice);
cs_status ten_n10g_rx_bypass_10g_40g_traffic_t41(cs_uint16 module_id, cs_uint8  slice);
cs_status ten_n10g_rx_bypass_internal_t41(cs_uint16 module_id, cs_uint8  slice);
cs_status ten_n10g_rx_odu2_non_intrusive_monitoring_t41(cs_uint16 module_id, cs_uint8  slice);
cs_status ten_n10g_rx_oduflex_non_intrusive_monitoring_t41(cs_uint16 module_id, cs_uint8  slice);
cs_status ten_n10g_rx_otu1e_odu1e_bmp_with_non_intrusive_mon_t41(cs_uint16 module_id, cs_uint8  slice);
cs_status ten_n10g_rx_otu2e_odu2e_bmp_with_non_intrusive_mon_t41(cs_uint16 module_id, cs_uint8  slice);
cs_status ten_n10g_rx_odtu_odu1e_bmp_non_intrusive_mon_t41(cs_uint16 module_id, cs_uint8  slice);
cs_status ten_n10g_rx_odtu_odu2e_bmp_non_intrusive_mon_t41(cs_uint16 module_id, cs_uint8  slice);
cs_status ten_n10g_rx_odtu_odu2e_10ge_bmp_non_intrusive_mon_t41(cs_uint16 module_id, cs_uint8  slice);
cs_status ten_n10g_rx_odtu_odu1e_10ge_bmp_non_intrusive_mon_t41(cs_uint16 module_id, cs_uint8  slice);
cs_status ten_n10g_rx_odtu_odu2_amp_oc192_msregen_t41(cs_uint16 module_id, cs_uint8  slice);
cs_status ten_n10g_rx_odtu_odu2_amp_oc192_rsregen_t41(cs_uint16 module_id, cs_uint8  slice);
cs_status ten_n10g_rx_odtu_odu2_amp_oc192_t41(cs_uint16 module_id, cs_uint8  slice);
cs_status ten_n10g_rx_odtu_odu2_bmp_oc192_rsregen_t41(cs_uint16 module_id, cs_uint8  slice);
cs_status ten_n10g_rx_odtu_odu2_bmp_oc192_t41(cs_uint16 module_id, cs_uint8  slice);
cs_status ten_n10g_rx_oc192_in_oc192_rsregen_t41(cs_uint16 module_id, cs_uint8  slice);
cs_status ten_n10g_rx_oc192_in_oc192_t41(cs_uint16 module_id, cs_uint8  slice);
cs_status ten_n10g_rx_odtu_odu2_gmph0_oc192_msregen_t41(cs_uint16 module_id, cs_uint8  slice);
cs_status ten_n10g_rx_odtu_odu2_gmph0_oc192_rsregen_t41(cs_uint16 module_id, cs_uint8  slice);
cs_status ten_n10g_rx_odtu_odu2_gmph0_oc192_t41(cs_uint16 module_id, cs_uint8  slice);
cs_status ten_n10g_rx_otu2v_odu2_opu2_t41(cs_uint16 module_id, cs_uint8  slice);
cs_status ten_n10g_rx_odtu_odu2_opu2_t41(cs_uint16 module_id, cs_uint8  slice);
cs_status ten_n10g_rx_otu1e_odu2_opu2_t41(cs_uint16 module_id, cs_uint8  slice);
cs_status ten_n10g_rx_passthru_40gckt_to_pkt_t41(cs_uint16 module_id, cs_uint8  slice);
cs_status ten_n10g_global_release_sreset_t41(cs_uint16 module_id, cs_uint8  slice);
cs_status ten_n10g_global_sreset_t41(cs_uint16 module_id, cs_uint8  slice);
cs_status ten_n10g_otnr_intr_handler_enable (cs_uint16 module_id, cs_uint16 slice, cs_uint16 bitfield); /* Bugzilla 29751 */
cs_status ten_n10g_sdfr_sdfist_handler_enable (cs_uint16 module_id, cs_uint16 slice, cs_uint16 bitfield); /* Bugzilla 29751 */
cs_status ten_n10g_oohr_otu2_aps_pcc_handler_enable(cs_uint16 module_id, cs_uint16 slice, cs_uint16 event_type, cs_uint16 monitor_layer); /* Bugzilla 29997 */

cs_status ten_n10g_otnt_dmcfg1_gen_enable(cs_uint16 module_id, cs_uint8 slice, 
                                          cs_uint16 dm_select, cs_uint16 dm_gen_en);
                                          
cs_status ten_n10g_otnt_dmcfg2_insert_enable(cs_uint16 module_id, cs_uint8 slice, 
                                             cs_uint16 dm_select, cs_uint16 dm_insert_en);
                                             
cs_status ten_n10g_otnt_dmcsfcfg_auto_csf_enable(cs_uint16 module_id, cs_uint8 slice, 
                                                 cs_uint16 auto_csf_en);
                                                 
cs_status ten_n10g_otnt_dmcsfcfg_csf_force(cs_uint16 module_id, cs_uint8 slice, 
                                           cs_uint16 csf_force);
                                           
cs_status ten_n10g_otnt_dmcsfcfg_dm_trigger(cs_uint16 module_id, cs_uint8 slice);
 
cs_status ten_n10g_otnt_dmcsfcfg_sel(cs_uint16 module_id, cs_uint8 slice, 
                                     cs_uint16 dm_select);
                                     
cs_status ten_n10g_oohr_dmcsf_cfgdm(cs_uint16 module_id, cs_uint8 slice, 
                                    cs_uint16 cfgdm);
                                    
cs_status ten_n10g_oohr_dmcsf_dm_filt(cs_uint16 module_id, cs_uint8 slice, 
                                      cs_uint16 dm_filt);
                                      
cs_uint16 ten_n10g_oohr_get_dmcsf_stat_dmacpt(cs_uint16 module_id, cs_uint8 slice,
                                              cs_uint16 tcmpm);
                                              
cs_status ten_n10g_oohr_dmcsfint_idm(cs_uint16 module_id, cs_uint8 slice, cs_uint16 idm);

cs_status ten_n10g_otnt_statcfg(cs_uint16 module_id, cs_uint8 slice, 
                                cs_uint16 tcmpm, 
                                cs_uint16 tcmpmstat, 
                                cs_uint16 tcmpmstatinsmd);
                                
cs_status ten_n10g_otnt_cfg3_ms_oh_ins(cs_uint16 module_id, cs_uint8 slice, 
                                       cs_uint16 ms_oh_ins);

cs_status ten_n10g_oohr_bipcfg2_sfblk(cs_uint16 module_id, 
                                      cs_uint8 slice, 
                                      cs_uint16 sfblk);
                                      
cs_status ten_n10g_oohr_bipcfg2_bip_thsel(cs_uint16 module_id, 
                                cs_uint8 slice, 
                                cs_uint16 bip, 
                                cs_uint16 bip_thsel);
                                
cs_status ten_n10g_oohr_bipval(cs_uint16 module_id, cs_uint8 slice, 
                               cs_uint16 bip,
                               cs_uint32 bipval);
                               
cs_uint16 ten_n10g_get_gblr_dpcfg_sdhoff(cs_uint16 module_id,
                                         cs_uint8  slice);
                               
cs_status ten_n10g_gbl_bypcfg_rx_bypass_10g(cs_uint16 module_id,
                                            cs_uint8  slice); 
                                            
cs_status ten_n10g_otnt_cfg3_aps_ins_en(cs_uint16 module_id, cs_uint8 slice, 
                                        cs_uint8 aps_chan_num, 
                                        cs_uint16 aps_ins_en);

#ifdef __cplusplus
}
#endif
#endif
