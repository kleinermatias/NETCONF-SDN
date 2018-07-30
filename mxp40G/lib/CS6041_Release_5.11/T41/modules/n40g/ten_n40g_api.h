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
 * ten_n40g_api.h 
 *
 * $Id: ten_n40g_api.h,v 1.30 2013/04/05 20:52:43 jccarlis Exp $
 *
 * API prototypes for N40G
 *
 */
 
#ifndef __TEN_N40G_API_H__
#define __TEN_N40G_API_H__

#ifdef __cplusplus
extern "C" {
#endif

cs_status ten_n40g_otnr4x_set_frame_format(cs_uint16 module_id, 
                                     cs_uint16 ncols, 
                                     cs_uint16 nrows,
                                     cs_uint16 nparb, 
                                     cs_uint16 npar);
                                     
cs_status ten_n40g_set_global_resets(cs_uint16 module_id, cs_reset_action_t act,
                                     cs_uint16 bitfield);

cs_uint16 ten_n40g_gbl4x_gblint (cs_uint16 module_id, cs_uint16 action, cs_uint16 bitfield);  /* Bugzilla 29751 */

cs_status ten_n40g_gblr4x_set_dpcfg0(cs_uint16 module_id, cs_uint16 kpasel,
                                     cs_uint16 bypcfg, cs_uint16 mdpcfg, cs_uint16 bysel,
                                     cs_uint16 oby, cs_uint16 sby);

cs_boolean ten_n40g_get_global_los_status(cs_uint16 module_id);

cs_status ten_n40g_set_gblr4x_phys(cs_uint16 module_id, cs_uint16 phys);

cs_status ten_n40g_set_gblr4x_pdhy(cs_uint16 module_id, cs_uint16 pdhy1, cs_uint16 pdhy0);

cs_uint16 ten_n40g_get_kpa_status(cs_uint16 module_id);

cs_status ten_n40g_config_kpa(cs_uint16 module_id, cs_uint16 fmm,
                              cs_uint16 prbs_stats_time_int,
                              cs_uint16 fixed_stats_time_int);
                              
cs_status ten_n40g_gblr4x_loscfg0(cs_uint16 module_id, 
                              cs_uint16 loscfg);

cs_status ten_n40g_gblr4x_loscfg1(cs_uint16 module_id, 
                              cs_uint16 los_ihys);
                              
cs_status ten_n40g_gblr4x_loscfg2(cs_uint16 module_id, 
                              cs_uint16 los_ohys);
                              
cs_status ten_n40g_gblr4x_loscfg3(cs_uint16 module_id, 
                              cs_uint16 los_step);
                              
cs_status ten_n40g_config_kpa_fmm(cs_uint16 module_id,
                                  cs_uint16 fmm);

cs_status ten_n40g_config_kpa_prbs_interval(cs_uint16 module_id,
                                            cs_uint16 prbs_stats_time_int);

cs_status ten_n40g_config_kpa_fixed_interval(cs_uint16 module_id,
                                             cs_uint16 fixed_stats_time_int);

cs_status ten_n40g_restart_kpa(cs_uint16 module_id);

cs_status ten_n40g_config_fixed_pattern_match(cs_uint16 module_id, cs_uint16 pattern,
                                              cs_uint16 parm7, cs_uint16 parm6,
                                              cs_uint16 parm5, cs_uint16 parm4,
                                              cs_uint16 parm3, cs_uint16 parm2,
                                              cs_uint16 parm1, cs_uint16 parm0);

cs_status ten_n40g_bypass_framer(cs_uint16 module_id, cs_ctl_t byp_enbl);

cs_status ten_n40g_gblt4x_set_cfg(cs_uint16 module_id, cs_uint16 kpgby, cs_uint16 sby,
                                  cs_uint16 oby, cs_uint16 mdpcfg);

cs_status ten_n40g_set_cbrstmaisins(cs_uint16 module_id, 
                                    cs_uint16 cbrstmaisins);

cs_status ten_n40g_set_dsbldskw(cs_uint16 module_id, 
                                    cs_uint16 dsbldskw);

cs_status ten_n40g_set_pn11auto(cs_uint16 module_id, 
                                    cs_uint16 pn11auto);

cs_status ten_n40g_config_kpg(cs_uint16 module_id, cs_uint16 kpg_bypass,
                              cs_uint16 kpg_auto, cs_uint16 pattern, cs_uint16 fpat7,
                              cs_uint16 fpat6, cs_uint16 fpat5, cs_uint16 fpat4,
                              cs_uint16 fpat3, cs_uint16 fpat2, cs_uint16 fpat1,
                              cs_uint16 fpat0);

cs_status ten_n40g_oohr_gendwnlfsf(cs_uint16 module_id, cs_uint16 sqgcc,
                                   cs_uint16 gensf_xlos, cs_uint16 gensf_los,
                                   cs_uint16 gensf_otuais, cs_uint16 gensf_lof,
                                   cs_uint16 gensf_feceed, cs_uint16 gensf_lom);

cs_status ten_n40g_oohr_gendwnlfsf_gensf_lol(cs_uint16 module_id, 
                                             cs_uint16 gensf_lol);
                                             
cs_status ten_n40g_oohr_gendwnlfsf_sqbiponlf(cs_uint16 module_id, 
                                             cs_uint16 sqbiponlf);
                                             
cs_status ten_n40g_oohr_gendwnlfsf_sqiaeonsmtti(cs_uint16 module_id, 
                                                cs_uint16 sqiaeonsmtti);
                                                
cs_status ten_n40g_oohr_gendwnlfsf_sqiaeonlf(cs_uint16 module_id, 
                                             cs_uint16 sqiaeonlf);
                                   
cs_status ten_n40g_oohr_gendwnpmsf(cs_uint16 module_id, cs_uint16 gensf_doduaisp,
                                   cs_uint16 gensf_dlckp, cs_uint16 gensf_docip,
                                   cs_uint16 gensf_dtimp, cs_uint16 gensf_dmsim,
                                   cs_uint16 gensf_dplm);

cs_status ten_n40g_oohr_gendwntcm1sf(cs_uint16 module_id, cs_uint16 gensf_doduaistcm,
                                     cs_uint16 gensf_dlcktcm, cs_uint16 gensf_docitcm,
                                     cs_uint16 gensf_dltc, cs_uint16 gensf_dtimtcm);

cs_status ten_n40g_oohr_gendwntcm2sf(cs_uint16 module_id, cs_uint16 gensf_doduaistcm,
                                     cs_uint16 gensf_dlcktcm, cs_uint16 gensf_docitcm,
                                     cs_uint16 gensf_dltc, cs_uint16 gensf_dtimtcm);

cs_status ten_n40g_oohr_gendwntcm3sf(cs_uint16 module_id, cs_uint16 gensf_doduaistcm,
                                     cs_uint16 gensf_dlcktcm, cs_uint16 gensf_docitcm,
                                     cs_uint16 gensf_dltc, cs_uint16 gensf_dtimtcm);

cs_status ten_n40g_oohr_gendwntcm4sf(cs_uint16 module_id, cs_uint16 gensf_doduaistcm,
                                     cs_uint16 gensf_dlcktcm, cs_uint16 gensf_docitcm,
                                     cs_uint16 gensf_dltc, cs_uint16 gensf_dtimtcm);

cs_status ten_n40g_oohr_gendwntcm5sf(cs_uint16 module_id, cs_uint16 gensf_doduaistcm,
                                     cs_uint16 gensf_dlcktcm, cs_uint16 gensf_docitcm,
                                     cs_uint16 gensf_dltc, cs_uint16 gensf_dtimtcm);

cs_status ten_n40g_oohr_gendwntcm6sf(cs_uint16 module_id, cs_uint16 gensf_doduaistcm,
                                     cs_uint16 gensf_dlcktcm, cs_uint16 gensf_docitcm,
                                     cs_uint16 gensf_dltc, cs_uint16 gensf_dtimtcm);

cs_status ten_n40g_oohr_gendwnais(cs_uint16 module_id, cs_uint16 genais_lf,
                                  cs_uint16 genais_sm, cs_uint16 genais_tcm6,
                                  cs_uint16 genais_tcm5, cs_uint16 genais_tcm4,
                                  cs_uint16 genais_tcm3, cs_uint16 genais_tcm2,
                                  cs_uint16 genais_tcm1, cs_uint16 genais_pm,
                                  cs_uint16 genais_py);

cs_status ten_n40g_oohr_gendwnok(cs_uint16 module_id, cs_uint16 genok_lf,
                                 cs_uint16 genok_sm, cs_uint16 genok_tcm6,
                                 cs_uint16 genok_tcm5, cs_uint16 genok_tcm4,
                                 cs_uint16 genok_tcm3, cs_uint16 genok_tcm2,
                                 cs_uint16 genok_tcm1, cs_uint16 genok_pm,
                                 cs_uint16 genok_py);

cs_status ten_n40g_oohr_cfg0(cs_uint16 module_id, cs_uint16 mfdsyh, cs_uint16 mfsyhy);

cs_status ten_n40g_set_oohr_cfg1(cs_uint16 module_id, cs_uint16 beidiv, cs_uint16 beiniv);

cs_status ten_n40g_set_oohr_cfg2(cs_uint16 module_id, cs_uint16 beintv, cs_uint16 beidtv);

cs_status ten_n40g_set_oohr_cfg3(cs_uint16 module_id, cs_uint16 bipdiv, cs_uint16 bipniv);

cs_status ten_n40g_set_oohr_cfg4(cs_uint16 module_id, cs_uint16 bipntv, cs_uint16 bipdtv);

cs_status ten_n40g_oohr_cfg5_bipmsk(cs_uint16 module_id, cs_uint16 bipmsk);

cs_status ten_n40g_oohr_cfg5_bipssel(cs_uint16 module_id, cs_uint16 bipssel);
                             
cs_status ten_n40g_oohr_cfg5_beissel(cs_uint16 module_id, cs_uint16 beissel);

cs_status ten_n40g_oohr_cfg5_mfalgne(cs_uint16 module_id, cs_uint16 mfalgne);                         
                             
cs_status ten_n40g_set_oohr_cfg6(cs_uint16 module_id, cs_uint16 sesiv, cs_uint16 sestv);

cs_status ten_n40g_set_oohr_cfg7(cs_uint16 module_id, cs_uint16 seuiv, cs_uint16 seutv);

cs_status ten_n40g_oohr_cfg11_msiext_cfg8_msicnt(cs_uint16 module_id, 
                                                 cs_uint16 msi_ext__msi_cnt);

cs_status ten_n40g_oohr_cfg8_msicnt(cs_uint16 module_id, 
                                    cs_uint16 msicnt);
                                    
cs_status ten_n40g_oohr_cfg8(cs_uint16 module_id, cs_uint16 msicnt, cs_uint16 stbldmsim,
                             cs_uint16 stbldplm, cs_uint16 stbldtm, cs_uint16 iaeflen,
                             cs_uint16 bdiflen, cs_uint16 biaeflen);

cs_status ten_n40g_oohr_cfg9(cs_uint16 module_id, cs_uint16 apsulen, cs_uint16 apsflen,
                             cs_uint16 statulen, cs_uint16 statflen);

cs_status ten_n40g_oohr_cfg10(cs_uint16 module_id, cs_uint16 msiulen, cs_uint16 msiflen,
                              cs_uint16 ptiulen, cs_uint16 ptiflen);

cs_status ten_n40g_oohr_cfg11_sps_mfdscr(cs_uint16 module_id, 
                                         cs_uint16 sps_mfdscr);
                                         
cs_status ten_n40g_oohr_cfg11_oh63sel(cs_uint16 module_id, 
                                      cs_uint16 oh63sel);
                                      
cs_status ten_n40g_oohr_cfg11_oh62sel(cs_uint16 module_id, 
                                      cs_uint16 oh62sel);
                                      
cs_status ten_n40g_oohr_cfg11_ohpp_bipsel(cs_uint16 module_id, 
                                          cs_uint16 ohpp_bipsel);

cs_status ten_n40g_oohr_cfg11_ohpp_eedsel(cs_uint16 module_id, 
                                          cs_uint16 ohpp_eedsel);
                                          
cs_status ten_n40g_oohr_cfg11_ohpp_msi_trbsel(cs_uint16 module_id, 
                                              cs_uint16 ohpp_msi_trbsel);
                                              
cs_status ten_n40g_oohr_cfg11_acc_msi_trbsel(cs_uint16 module_id, 
                                             cs_uint16 acc_msi_trbsel);

cs_status ten_n40g_oohr_cfg11_flomen(cs_uint16 module_id, 
                                     cs_uint16 flomen);
                                     
cs_status ten_n40g_oohr_cfg11_msi_ext(cs_uint16 module_id, 
                                      cs_uint16 msi_ext);

/* Bugzilla 31127 Start */
cs_status ten_n40g_oohr_lomcfg_tdelon_tdeloff(cs_uint16 module_id,   
                              cs_uint16 tdelon, cs_uint16 tdeloff);

cs_status ten_n40g_otnr4x_obfa2_lofcfg_tdelon_tdeloff(cs_uint16 module_id,
                                      cs_uint16 tdelon, cs_uint16 tdeloff);

cs_status ten_n40g_otnr4x_obfa2_lomcfg_tdelon_tdeloff(cs_uint16 module_id,
                                      cs_uint16 tdelon, cs_uint16 tdeloff);
/* Bugzilla 31127 End */

                                      
cs_status ten_n40g_set_expected_pti_byte(cs_uint16 module_id, cs_uint16 expti);

cs_status ten_n40g_set_expected_msi_string(cs_uint16 module_id, cs_uint16 msi7,
                                           cs_uint16 msi6, cs_uint16 msi5, cs_uint16 msi4,
                                           cs_uint16 msi3, cs_uint16 msi2, cs_uint16 msi1,
                                           cs_uint16 msi0);
                                           
cs_status ten_n40g_set_expected_msi_ext_string(cs_uint16 module_id, 
                                               cs_uint16 msi_ext7,
                                               cs_uint16 msi_ext6,
                                               cs_uint16 msi_ext5,
                                               cs_uint16 msi_ext4,
                                               cs_uint16 msi_ext3,
                                               cs_uint16 msi_ext2,
                                               cs_uint16 msi_ext1,
                                               cs_uint16 msi_ext0);
                                               
cs_int16 ten_n40g_get_accepted_pti_byte(cs_uint16 module_id);

cs_int16 ten_n40g_get_accepted_msi_string(cs_uint16 module_id, cs_uint8 index);

cs_status ten_n40g_otnt4x_cfg4(cs_uint16 module_id, 
                           cs_uint16 bipxor, 
                           cs_uint16 bipmsk);

cs_status ten_n40g_otnt4x_bipmsk(cs_uint16 module_id, 
                                 cs_uint16 bipmsk);

cs_int32 ten_n40g_oohr_get_aps_pcc(cs_uint16 module_id, cs_uint8 aps);

cs_status ten_n40g_set_oohr_bipvala(cs_uint16 module_id, cs_uint16 bipvala01,
                                    cs_uint16 bipvala00);

cs_status ten_n40g_set_oohr_bipvalb(cs_uint16 module_id, cs_uint16 bipvalb01,
                                    cs_uint16 bipvalb00);

cs_status ten_n40g_oohr_bipcfg(cs_uint16 module_id, cs_uint16 bip7exs, cs_uint16 bip7blk,
                               cs_uint16 bip6exs, cs_uint16 bip6blk, cs_uint16 bip5exs,
                               cs_uint16 bip5blk, cs_uint16 bip4exs, cs_uint16 bip4blk,
                               cs_uint16 bip3exs, cs_uint16 bip3blk, cs_uint16 bip2exs,
                               cs_uint16 bip2blk, cs_uint16 bip1exs, cs_uint16 bip1blk,
                               cs_uint16 bip0exs, cs_uint16 bip0blk);

cs_status ten_n40g_set_oohr_beivala(cs_uint16 module_id, cs_uint16 beivala1,
                                    cs_uint16 beivala0);

cs_status ten_n40g_set_oohr_beivalb(cs_uint16 module_id, cs_uint16 beivalb1,
                                    cs_uint16 beivalb0);

cs_status ten_n40g_oohr_beicfg(cs_uint16 module_id, 
                           cs_uint16 layer,  
                           cs_uint16 bei_blk);
                           
cs_int16 ten_n40g_oohr_get_sm_status(cs_uint16 module_id, cs_uint8 select);

cs_int16 ten_n40g_oohr_get_tcm1_status(cs_uint16 module_id, cs_uint8 select);

cs_int16 ten_n40g_oohr_get_tcm2_status(cs_uint16 module_id, cs_uint8 select);

cs_int16 ten_n40g_oohr_get_tcm3_status(cs_uint16 module_id, cs_uint8 select);

cs_int16 ten_n40g_oohr_get_tcm4_status(cs_uint16 module_id, cs_uint8 select);

cs_int16 ten_n40g_oohr_get_tcm5_status(cs_uint16 module_id, cs_uint8 select);

cs_int16 ten_n40g_oohr_get_tcm6_status(cs_uint16 module_id, cs_uint8 select);

cs_int16 ten_n40g_oohr_get_pm_status(cs_uint16 module_id, cs_uint8 select);

cs_status ten_n40g_oohr_mfmcfg(cs_uint16 module_id, cs_uint8 match_unit, cs_uint8 mfmcmp,
                               cs_uint8 mfmmsk);

cs_status ten_n40g_set_oohr_afths1(cs_uint16 module_id, cs_uint16 af1stv);

cs_status ten_n40g_set_oohr_afthu1(cs_uint16 module_id, cs_uint16 af1utv);

cs_status ten_n40g_set_oohr_afths2(cs_uint16 module_id, cs_uint16 af2stv);

cs_status ten_n40g_set_oohr_afthu2(cs_uint16 module_id, cs_uint16 af2utv);

cs_status ten_n40g_set_oohr_afths3(cs_uint16 module_id, cs_uint16 af3stv);

cs_status ten_n40g_set_oohr_afthu3(cs_uint16 module_id, cs_uint16 af3utv);

cs_status ten_n40g_set_oohr_afths4(cs_uint16 module_id, cs_uint16 af4stv);

cs_status ten_n40g_set_oohr_afthu4(cs_uint16 module_id, cs_uint16 af4utv);

cs_status ten_n40g_oohr_cmp_unit(cs_uint16 module_id, cs_uint8 unit, cs_uint16 cmp);

cs_status ten_n40g_oohr_gaf_cfg(cs_uint16 module_id, cs_uint8 unit, cs_uint16 afmsk,
                                cs_uint16 afts, cs_uint16 afcol, cs_uint16 afrow,
                                cs_uint16 afi, cs_uint16 afmf);

cs_status ten_n40g_oohr_gaf_cmp(cs_uint16 module_id, cs_uint8 unit, cs_uint16 gc_msk);

cs_int16 ten_n40g_oohr_get_gaf_status(cs_uint16 module_id, cs_uint8 unit,
                                      cs_uint8 select);

cs_status ten_n40g_oohr_config_string_extractor(cs_uint16 module_id, cs_uint8 unit,
                                                cs_uint16 se_mfe, cs_uint16 se_cnt,
                                                cs_uint16 se_col, cs_uint16 se_row,
                                                cs_uint16 se_cmp);
                                                
cs_status ten_n40g_oohr_config_string_extractor_cmp(cs_uint16 module_id, 
                             cs_uint8 unit, 
                             cs_uint16 se_cmp);
 
cs_status ten_n40g_oohr_set_string_extractor_dt_dis(cs_uint16 module_id, 
                                                    cs_uint8 unit,  
                                                    cs_uint16 se_dt_dis);
 
cs_status ten_n40g_oohr_set_string_extractor_dmm(cs_uint16 module_id, cs_uint8 unit,
                                                cs_uint16 se_dmm);
                                                
cs_status ten_n40g_oohr_set_string_extractor_off(cs_uint16 module_id, cs_uint8 unit,
                                                cs_uint16 se_off);

cs_int16 ten_n40g_oohr_get_string_extractor_unit_status0(cs_uint16 module_id,
                                                         cs_uint8 select);

cs_int16 ten_n40g_oohr_get_string_extractor_unit_status1(cs_uint16 module_id,
                                                         cs_uint8 select);

cs_int16 ten_n40g_oohr_get_defect_trace_identifier_status0(cs_uint16 module_id,
                                                           cs_uint8 select);

cs_int16 ten_n40g_oohr_get_defect_trace_identifier_status1(cs_uint16 module_id,
                                                           cs_uint8 select);

cs_status ten_n40g_oohr_config_string_inserter(cs_uint16 module_id, cs_uint8 unit,
                                            cs_uint16 sicnt, cs_uint16 simfe,
                                            cs_uint16 sicol, cs_uint16 sirow);
                                            
cs_status ten_n40g_oohr_set_string_inserter_ie(cs_uint16 module_id, cs_uint8 unit,
                                            cs_uint16 siie);

cs_status ten_n40g_oohr_string_insertion_update(cs_uint16 module_id, cs_uint8 unit);

cs_status ten_n40g_set_otnr4x_ofcfg0(cs_uint16 module_id, cs_uint16 ncols,
                                     cs_uint16 nrows);

cs_status ten_n40g_otnr4x_set_nparb_npar(cs_uint16 module_id, cs_uint16 nparb,
                                         cs_uint16 npar);

cs_status ten_n40g_otnr4x_set_odwcfg(cs_uint16 module_id, cs_uint16 fsomd,
                                     cs_uint16 stm64md, cs_uint16 stm256md,
                                     cs_uint16 aggrmod, cs_uint16 dw_enable);

cs_status ten_n40g_otnr4x_descrambling(cs_uint16 module_id, cs_uint16 postdscr,
                                       cs_uint16 predscr, cs_uint16 alen);

cs_uint16 ten_n40g_otnr4x_get_otu_framer_status(cs_uint16 module_id);

cs_int16 ten_n40g_otnr4x_get_ofstat(cs_uint16 module_id, 
                                 cs_uint16 select);
                                 
cs_status ten_n40g_otnr4x_set_c15res_en0(cs_uint16 module_id, cs_uint16 c15res_en0);

cs_status ten_n40g_otnr4x_set_c15res_en1(cs_uint16 module_id, cs_uint16 c15res_en1);

cs_status ten_n40g_otnr4x_set_c15res_en2(cs_uint16 module_id, cs_uint16 c15res_en2);

cs_status ten_n40g_otnr4x_set_c15res_en3(cs_uint16 module_id, cs_uint16 c15res_en3);

cs_status ten_n40g_otnr4x_set_c15res_en4(cs_uint16 module_id, cs_uint16 c15res_en4);

cs_status ten_n40g_otnr4x_set_c15res_en5(cs_uint16 module_id, cs_uint16 c15res_en5);

cs_status ten_n40g_otnr4x_set_c15res_en6(cs_uint16 module_id, cs_uint16 c15res_en6);

cs_status ten_n40g_otnr4x_set_c15res_en7(cs_uint16 module_id, cs_uint16 c15res_en7);

cs_status ten_n40g_otnr4x_set_c15res_en8(cs_uint16 module_id, cs_uint16 c15res_en8);

cs_status ten_n40g_otnr4x_set_c15res_en9(cs_uint16 module_id, cs_uint16 c15res_en9);

cs_status ten_n40g_otnr4x_set_c15res_en10(cs_uint16 module_id, cs_uint16 c15res_en10);

cs_status ten_n40g_otnr4x_set_c15res_en11(cs_uint16 module_id, cs_uint16 c15res_en11);

cs_status ten_n40g_otnr4x_set_c15res_en12(cs_uint16 module_id, cs_uint16 c15res_en12);

cs_status ten_n40g_otnr4x_set_c15res_en13(cs_uint16 module_id, cs_uint16 c15res_en13);

cs_status ten_n40g_otnr4x_set_c15res_en14(cs_uint16 module_id, cs_uint16 c15res_en14);

cs_status ten_n40g_otnr4x_set_c15res_en15(cs_uint16 module_id, cs_uint16 c15res_en15);

cs_status ten_n40g_otnr4x_set_aggrmod(cs_uint16 module_id, cs_uint16 aggrmod);

cs_status ten_n40g_otnr4x_set_dw_enable(cs_uint16 module_id, cs_uint16 dw_enable);

cs_status ten_n40g_otnr4x_set_jc_plus(cs_uint16 module_id, cs_uint16 jc_plus);

cs_status ten_n40g_otnr4x_set_jc_plus_per_slice(cs_uint16 module_id,  
                                                cs_uint8 slice, 
                                                cs_uint16 jc_plus);
                                                
cs_status ten_n40g_otnr4x_set_jc_enable(cs_uint16 module_id, cs_uint16 jc_enable);

cs_status ten_n40g_otnr4x_set_jc_enable_per_slice(cs_uint16 module_id,  
                                                  cs_uint8 slice, 
                                                  cs_uint16 jc_enable);
                                                  
cs_status ten_n40g_otnr4x_set_linkalm_jcnom(cs_uint16 module_id, 
                             cs_uint16 linkalm_jcnom);

cs_status ten_n40g_otnr4x_set_ncols(cs_uint16 module_id, cs_uint16 ncols);

cs_status ten_n40g_otnr4x_ocfg(cs_uint16 module_id, cs_boolean fecmd, cs_boolean fecen);

cs_status ten_n40g_otnsm_set_string_inserter(cs_uint16 module_id, cs_uint16 instance,
                                             cs_char8 *str);

cs_status ten_n40g_otnsm_get_string_extractor(cs_uint16 module_id,
                                             cs_uint16 instance, cs_char8 *str);
                                             
cs_status ten_n40g_otnsm_set_string_extractor(cs_uint16 module_id, 
                                             cs_uint16 instance, 
                                             cs_char8 *str);
                                             
cs_boolean ten_n40g_get_lom_status(cs_uint16 module_id);

cs_status ten_n40g_set_pti_byte(cs_uint16 module_id, cs_uint16 pti);

cs_status ten_n40g_set_otnt4x_wrpcfg0(cs_uint16 module_id, cs_uint16 ncols,
                                     cs_uint16 nrows);

cs_status ten_n40g_otnt4x_set_nparb_npar(cs_uint16 module_id, cs_uint16 nparb,
                                        cs_uint16 npar);

cs_status ten_n40g_otnt4x_set_wrpcfg3(cs_uint16 module_id, cs_uint16 stm256md,
                                     cs_uint16 stm64md, cs_uint16 aggrmod,
                                     cs_uint16 wrmd);

cs_status ten_n40g_otnt4x_scrambling(cs_uint16 module_id, cs_uint16 postscr,
                                    cs_uint16 prescr);
                                    
cs_status ten_n40g_otnt4x_mfmcfg(cs_uint16 module_id, 
                                 cs_uint8 match_unit, 
                                 cs_uint16 mfmcmp, 
                                 cs_uint16 mfmmsk);
                                    
cs_status ten_n40g_otnt4x_set_apspcc(cs_uint16 module_id, cs_uint8 channel,
                                    cs_uint16 apspcc1, cs_uint16 apspcc0);

cs_status ten_n40g_otnt4x_set_wrapper_onoff(cs_uint16 module_id, cs_uint16 wrmd);

cs_status ten_n40g_otnt4x_set_wrapper_aggrmod(cs_uint16 module_id,
                                             cs_uint16 aggrmod);

cs_status ten_n40g_otnt4x_set_wrpfs0(cs_uint16 module_id, cs_uint16 fs0);

cs_status ten_n40g_otnt4x_set_wrpfs1(cs_uint16 module_id, cs_uint16 fs1);

cs_status ten_n40g_otnt4x_set_wrpfs2(cs_uint16 module_id, cs_uint16 fs2);

cs_status ten_n40g_otnt4x_set_wrpfs3(cs_uint16 module_id, cs_uint16 fs3);

cs_status ten_n40g_otnt4x_set_wrpfs4(cs_uint16 module_id, cs_uint16 fs4);

cs_status ten_n40g_otnt4x_set_wrpfs5(cs_uint16 module_id, cs_uint16 fs5);

cs_status ten_n40g_otnt4x_set_wrpfs6(cs_uint16 module_id, cs_uint16 fs6);

cs_status ten_n40g_otnt4x_set_wrpfs7(cs_uint16 module_id, cs_uint16 fs7);

cs_status ten_n40g_otnt4x_set_wrpfs8(cs_uint16 module_id, cs_uint16 fs8);

cs_status ten_n40g_otnt4x_set_wrpfs9(cs_uint16 module_id, cs_uint16 fs9);

cs_status ten_n40g_otnt4x_set_wrpfs10(cs_uint16 module_id, cs_uint16 fs10);

cs_status ten_n40g_otnt4x_set_wrpfs11(cs_uint16 module_id, cs_uint16 fs11);

cs_status ten_n40g_otnt4x_set_wrpfs12(cs_uint16 module_id, cs_uint16 fs12);

cs_status ten_n40g_otnt4x_set_wrpfs13(cs_uint16 module_id, cs_uint16 fs13);

cs_status ten_n40g_otnt4x_set_wrpfs14(cs_uint16 module_id, cs_uint16 fs14);

cs_status ten_n40g_otnt4x_set_wrpfs15(cs_uint16 module_id, cs_uint16 fs15);

cs_status ten_n40g_otnt4x_set_c15res_en0(cs_uint16 module_id, cs_uint16 c15res_en0);

cs_status ten_n40g_otnt4x_set_c15res_en1(cs_uint16 module_id, cs_uint16 c15res_en1);

cs_status ten_n40g_otnt4x_set_c15res_en2(cs_uint16 module_id, cs_uint16 c15res_en2);

cs_status ten_n40g_otnt4x_set_c15res_en3(cs_uint16 module_id, cs_uint16 c15res_en3);

cs_status ten_n40g_otnt4x_set_c15res_en4(cs_uint16 module_id, cs_uint16 c15res_en4);

cs_status ten_n40g_otnt4x_set_c15res_en5(cs_uint16 module_id, cs_uint16 c15res_en5);

cs_status ten_n40g_otnt4x_set_c15res_en6(cs_uint16 module_id, cs_uint16 c15res_en6);

cs_status ten_n40g_otnt4x_set_c15res_en7(cs_uint16 module_id, cs_uint16 c15res_en7);

cs_status ten_n40g_otnt4x_set_c15res_en8(cs_uint16 module_id, cs_uint16 c15res_en8);

cs_status ten_n40g_otnt4x_set_c15res_en9(cs_uint16 module_id, cs_uint16 c15res_en9);

cs_status ten_n40g_otnt4x_set_c15res_en10(cs_uint16 module_id,
                                         cs_uint16 c15res_en10);

cs_status ten_n40g_otnt4x_set_c15res_en11(cs_uint16 module_id,
                                         cs_uint16 c15res_en11);

cs_status ten_n40g_otnt4x_set_c15res_en12(cs_uint16 module_id,
                                         cs_uint16 c15res_en12);

cs_status ten_n40g_otnt4x_set_c15res_en13(cs_uint16 module_id,
                                         cs_uint16 c15res_en13);

cs_status ten_n40g_otnt4x_set_c15res_en14(cs_uint16 module_id,
                                         cs_uint16 c15res_en14);

cs_status ten_n40g_otnt4x_set_c15res_en15(cs_uint16 module_id,
                                         cs_uint16 c15res_en15);

cs_status ten_n40g_otnt4x_set_wrpcfg4(cs_uint16 module_id, cs_uint16 jc_plus,
                                     cs_uint16 jcen);
                                     
cs_status ten_n40g_otnt4x_set_jc_plus(cs_uint16 module_id, 
                                      cs_uint16 jc_plus);

cs_status ten_n40g_otnt4x_set_wrpcfg4_jcen_per_slice(cs_uint16 module_id, 
                                      cs_uint8 slice, 
                                      cs_uint16 jcen);
                                      
cs_status ten_n40g_otnt4x_set_ncols(cs_uint16 module_id, cs_uint16 ncols);

cs_status ten_n40g_otnt4x_set_wrp0dh1(cs_uint16 module_id, cs_uint16 dthyst01);

cs_status ten_n40g_otnt4x_set_wrp0dh0(cs_uint16 module_id, cs_uint16 dthyst00);

cs_status ten_n40g_otnt4x_set_wrp1dh1(cs_uint16 module_id, cs_uint16 dthyst11);

cs_status ten_n40g_otnt4x_set_wrp1dh0(cs_uint16 module_id, cs_uint16 dthyst10);

cs_status ten_n40g_otnt4x_set_wrp2dh1(cs_uint16 module_id, cs_uint16 dthyst21);

cs_status ten_n40g_otnt4x_set_wrp2dh0(cs_uint16 module_id, cs_uint16 dthyst20);

cs_status ten_n40g_otnt4x_set_wrp3dh1(cs_uint16 module_id, cs_uint16 dthyst31);

cs_status ten_n40g_otnt4x_set_wrp3dh0(cs_uint16 module_id, cs_uint16 dthyst30);

/* Bugzilla 24628 Start */
cs_status ten_n40g_otnt4x_set_dthyst(cs_uint16 module_id, 
                                     cs_uint8  slice,
                                     cs_uint32 dthyst);
/* Bugzilla 24628 End */

cs_status ten_n40g_otnt4x_ocfg(cs_uint16 module_id, cs_boolean fecmd,
                              cs_boolean fecen);

cs_status ten_n40g_otnt4x_set_wrpcfg5(cs_uint16 module_id, 
                                      cs_uint16 stuffbt);

cs_int16 ten_n40g_get_sdfr_rx_status(cs_uint16 module_id, cs_uint16 field);

cs_status ten_n40g_set_sdfr_lofcfg1(cs_uint16 module_id, cs_uint16 lofimou,
                                   cs_uint16 lofimin);

cs_status ten_n40g_set_sdfr_b1btber(cs_uint16 module_id, cs_uint16 b1btber);

cs_status ten_n40g_set_sdfr_b1blber(cs_uint16 module_id, cs_uint16 b1blber);

cs_status ten_n40g_set_sdfr_b2btber(cs_uint16 module_id, cs_uint16 b2btber0,
                                   cs_uint16 b2btber1);

cs_status ten_n40g_set_sdfr_b2blber(cs_uint16 module_id, cs_uint16 b2blber0,
                                   cs_uint16 b2blber1);

cs_status ten_n40g_sdfr_enable_descrambler(cs_uint16 module_id, cs_uint16 scren);

cs_status ten_n40g_sdfr_set_sdfcfg(cs_uint16 module_id, cs_uint16 scren,
                                  cs_uint16 oofhy, cs_uint16 fawwup,
                                  cs_uint16 fawwdw);

cs_status ten_n40g_sdfr_set_sdfcfg_fawwup_fawwdw(cs_uint16 module_id, 
                                   cs_uint16 fawwup, 
                                   cs_uint16 fawwdw);
                                  
cs_status ten_n40g_sdfr_set_sdfcfg1(cs_uint16 module_id, cs_uint16 altscr);

cs_status ten_n40g_set_poh_byte(cs_uint16 module_id, cs_uint16 ovrhd, cs_uint8 val);

cs_status ten_n40g_st4x_set_ohie(cs_uint16 module_id, cs_uint16 b1inv,
                                cs_uint16 b1trans, cs_uint16 b1ie, cs_uint16 scren,
                                cs_uint16 a1a2rsh);

cs_status ten_n40g_st4x_set_b1errins(cs_uint16 module_id, cs_uint16 b1errmsk);

                                   
cs_status ten_n40g_otnr4x_select_global_timing_source(cs_uint16 module_id, 
                                                      cs_uint16 select);
                                                       
cs_status ten_n40g_sdfr_select_global_timing_source(cs_uint16 module_id, 
                                                    cs_uint16 select);

cs_status ten_n40g_otnr4x_set_fs_mlen(cs_uint16 module_id, 
                                      cs_uint16 fs_mlen);

cs_status ten_n40g_otnr4x_set_fs_aflen(cs_uint16 module_id, 
                                       cs_uint16 fs_aflen);

cs_status ten_n40g_otnr4x_set_odwfs(cs_uint16 module_id, 
                                    cs_uint16 fs,
                                    cs_uint16 timeslot);

cs_int16 ten_n40g_otnr4x_get_odwfsfilt(cs_uint16 module_id, 
                                       cs_uint16 timeslot);
                                       
cs_int16 ten_n40g_otnr4x_get_odwfs(cs_uint16 module_id, 
                                   cs_uint16 timeslot);

cs_int16 ten_n40g_otnr4x_get_fsusts(cs_uint16 module_id, 
                                    cs_uint16 timeslot);

cs_status ten_n40g_otnt4x_doaie(cs_uint16 module_id, 
                                cs_uint8  byte,
                                cs_uint16 insertion);

cs_status ten_n40g_otnt4x_set_fasie(cs_uint16 module_id,
                                    cs_uint16 fasie);

cs_status ten_n40g_otnt4x_set_ptie(cs_uint16 module_id,
                                   cs_uint16 ptie);

cs_status ten_n40g_set_oh_insertion_enables(cs_uint16 module_id, 
                                            cs_uint16 select, 
                                            cs_uint16 value);

cs_status ten_n40g_otnr4x_alen(cs_uint16 module_id, 
                               cs_uint16 alen);

cs_status ten_n40g_oohr_beiexs(cs_uint16 module_id, 
                               cs_uint16 layer,  
                               cs_uint16 bei_exs);

cs_int16 ten_n40g_get_expected_pti_byte(cs_uint16 module_id);

cs_boolean ten_n40g_compare_pti_byte(cs_uint16 module_id);

cs_status ten_n40g_otnr4x_oacfg0_dsyhyst(cs_uint16 module_id, 
                             cs_uint16 dsyhyst);
                             
/* Bugzilla 31209 Start */
cs_status ten_n40g_otnr4x_oacfg0_syhyst(cs_uint16 module_id,  
                                        cs_uint16 syhyst);

/* Bugzilla 31209 End */

cs_status ten_n40g_otnr4x_lofcfg_tdelon_tdeloff(cs_uint16 module_id, 
                              cs_uint16 tdelon, cs_uint16 tdeloff);

cs_status ten_n40g_gblr4x_set_kpasel(cs_uint16 module_id, 
                                     cs_uint16 kpasel);
                                     
cs_status ten_n40g_sdfr_lofcfg2_m0byte(cs_uint16 module_id, 
                            cs_uint16 m0byte);
 
cs_status ten_n40g_otnt4x_set_frame_format(cs_uint16 module_id, 
                                           cs_uint16 ncols, 
                                           cs_uint16 nrows,
                                           cs_uint16 nparb, 
                                           cs_uint16 npar);
 


/* Bugzilla 26198, autogen prototypes need cs_uint32 for GMP Cn arguments */
/* Bugzilla 26197, autogen prototypes updated with latest code gen, removes spaces surrounding parens */

/* Bugzilla 24360 Start */
cs_status ten_n40g_mldrx_mldr_scr_off_t41(cs_uint16 module_id);
cs_status ten_n40g_mldrx_mldr_set_lmfirlen_t41(cs_uint16 module_id, cs_uint16 val);
cs_status ten_n40g_mldrx_mldr_set_lmforlen_t41(cs_uint16 module_id, cs_uint16 val);
cs_status ten_n40g_mldrx_mldr_set_tdeloff_t41(cs_uint16 module_id, cs_uint16 val);
cs_status ten_n40g_mldrx_mld_es_release_sreset_t41(cs_uint16 module_id, cs_uint8  slice);
cs_status ten_n40g_mldrx_mld_es_es_iml_thresh_t41(cs_uint16 module_id, cs_uint8  slice, cs_uint16 val);
cs_status ten_n40g_mldrx_mld_es_es_upper_thresh_t41(cs_uint16 module_id, cs_uint8  slice, cs_uint16 val);
cs_status ten_n40g_mldrx_sadeco_release_sreset_t41(cs_uint16 module_id);
cs_status ten_n40g_mldrx_sadeco_sdc_on_t41(cs_uint16 module_id);
cs_status ten_n40g_mldrx_sadeco_rsymsk_t41(cs_uint16 module_id, cs_uint16 val);
cs_status ten_n40g_mldrx_sadeco_frame_word_length_t41(cs_uint16 module_id, cs_uint16 val);
cs_status ten_n40g_mldrx_sadeco_es_depth_t41(cs_uint16 module_id, cs_uint16 val);
cs_status ten_n40g_mldrx_sadeco_es_high_limit_t41(cs_uint16 module_id, cs_uint16 val);
cs_status ten_n40g_mldrx_sadeco_sdh16_mode_t41(cs_uint16 module_id, cs_uint16 val);
cs_status ten_n40g_tx_gfec_t41(cs_uint16 module_id);
cs_status ten_n40g_tx_ufec_t41(cs_uint16 module_id);
cs_status ten_n40g_tx_sm_bip_insertion_t41(cs_uint16 module_id);
cs_status ten_n40g_tx_nrows_t41(cs_uint16 module_id, cs_uint16 rows);
cs_status ten_n40g_tx_ncols_t41(cs_uint16 module_id, cs_uint16 columns);
cs_status ten_n40g_tx_npar_t41(cs_uint16 module_id, cs_uint16 parity);
cs_status ten_n40g_tx_nparb_t41(cs_uint16 module_id, cs_uint16 parity);
cs_status ten_n40g_tx_otu3_t41(cs_uint16 module_id);
cs_status ten_n40g_tx_odu3_t41(cs_uint16 module_id);
cs_status ten_n40g_tx_aggr_t41(cs_uint16 module_id);
cs_status ten_n40g_tx_tcmbipinsertion_t41(cs_uint16 module_id);
cs_status ten_n40g_tx_pmbipinsertion_t41(cs_uint16 module_id);
cs_status ten_n40g_tx_opu3_t41(cs_uint16 module_id);
cs_status ten_n40g_tx_cbr40_t41(cs_uint16 module_id);
cs_status ten_n40g_tx_oc768_msregen_t41(cs_uint16 module_id);
cs_status ten_n40g_tx_oc768_transparent_t41(cs_uint16 module_id);
cs_status ten_n40g_tx_oc768_out_t41(cs_uint16 module_id);
cs_status ten_n40g_tx_otl34_t41(cs_uint16 module_id);
cs_status ten_n40g_tx_stl256_t41(cs_uint16 module_id);
cs_status ten_n40g_tx_125g_ts_t41(cs_uint16 module_id);
cs_status ten_n40g_tx_25g_ts_t41(cs_uint16 module_id);
cs_status ten_n40g_tx_pt_enable_t41(cs_uint16 module_id, cs_uint16 pt);
cs_status ten_n40g_tx_pt_disable_t41(cs_uint16 module_id);
cs_status ten_n40g_tx_amp_lo_t41(cs_uint16 module_id);
cs_status ten_n40g_tx_amp_trib_t41(cs_uint16 module_id, cs_uint16 trib);
cs_status ten_n40g_tx_amp_trib_0_t41(cs_uint16 module_id);
cs_status ten_n40g_tx_amp_trib_1_t41(cs_uint16 module_id);
cs_status ten_n40g_tx_amp_trib_2_t41(cs_uint16 module_id);
cs_status ten_n40g_tx_amp_trib_3_t41(cs_uint16 module_id);
cs_status ten_n40g_tx_gmp_ho_trib_0_t41(cs_uint16 module_id, cs_uint32 cn_32bit);
cs_status ten_n40g_tx_gmp_ho_trib_1_t41(cs_uint16 module_id, cs_uint32 cn_32bit);
cs_status ten_n40g_tx_gmp_ho_trib_2_t41(cs_uint16 module_id, cs_uint32 cn_32bit);
cs_status ten_n40g_tx_gmp_ho_trib_3_t41(cs_uint16 module_id, cs_uint32 cn_32bit);
cs_status ten_n40g_tx_gmp_ho_tsen_t41(cs_uint16 module_id, cs_uint16 tsen0, cs_uint16 tsen1);
cs_status ten_n40g_tx_detamp_lo_t41(cs_uint16 module_id, cs_uint16 dthyst);
cs_status ten_n40g_tx_detamp_trib_0_t41(cs_uint16 module_id, cs_uint16 dthyst);
cs_status ten_n40g_tx_detamp_trib_1_t41(cs_uint16 module_id, cs_uint16 dthyst);
cs_status ten_n40g_tx_detamp_trib_2_t41(cs_uint16 module_id, cs_uint16 dthyst);
cs_status ten_n40g_tx_detamp_trib_3_t41(cs_uint16 module_id, cs_uint16 dthyst);
cs_status ten_n40g_tx_detgmp_ho_trib_0_t41(cs_uint16 module_id, cs_uint32 cn_32bit, cs_uint16 dthyst);
cs_status ten_n40g_tx_detgmp_ho_trib_1_t41(cs_uint16 module_id, cs_uint32 cn_32bit, cs_uint16 dthyst);
cs_status ten_n40g_tx_detgmp_ho_trib_2_t41(cs_uint16 module_id, cs_uint32 cn_32bit, cs_uint16 dthyst);
cs_status ten_n40g_tx_detgmp_ho_trib_3_t41(cs_uint16 module_id, cs_uint32 cn_32bit, cs_uint16 dthyst);
cs_status ten_n40g_tx_gmp_lo_t41(cs_uint16 module_id, cs_uint32 cn_32bit);
cs_status ten_n40g_tx_propmap_lo_t41(cs_uint16 module_id);
cs_status ten_n40g_tx_propmap_ho_t41(cs_uint16 module_id);
cs_status ten_n40g_tx_pkt_bypass_t41(cs_uint16 module_id);
cs_status ten_n40g_tx_ufec7_t41(cs_uint16 module_id);
cs_status ten_n40g_tx_ufec10_t41(cs_uint16 module_id);
cs_status ten_n40g_tx_ufec12_t41(cs_uint16 module_id);
cs_status ten_n40g_tx_ufec26_t41(cs_uint16 module_id);
cs_status ten_n40g_tx_ufec25_t41(cs_uint16 module_id);
cs_status ten_n40g_tx_otn_scr_off_t41(cs_uint16 module_id);
cs_status ten_n40g_tx_oc768_scr_off_t41(cs_uint16 module_id);
cs_status ten_n40g_tx_fec_datapath_bypass_t41(cs_uint16 module_id);
cs_status ten_n40g_tx_prbs_oc768_t41(cs_uint16 module_id, cs_uint16 pattern);
cs_status ten_n40g_tx_prbs_otu3_t41(cs_uint16 module_id, cs_uint16 pattern);
cs_status ten_n40g_tx_prbs_oc768_otu3_t41(cs_uint16 module_id, cs_uint16 pattern);
cs_status ten_n40g_tx_cbr_otu3_otl34_t41(cs_uint16 module_id);
cs_status ten_n40g_tx_odu3_otu3_t41(cs_uint16 module_id);
cs_status ten_n40g_tx_odu3e1_otu3e1_t41(cs_uint16 module_id);
cs_status ten_n40g_tx_odu3e2_otu3e2_t41(cs_uint16 module_id);
cs_status ten_n40g_tx_odu3_gmp_lo_otu3e2_t41(cs_uint16 module_id);
cs_status ten_n40g_tx_40ge_gmp_lo_otu3_t41(cs_uint16 module_id);
cs_status ten_n40g_tx_40ge_gmp_lo_odu3_t41(cs_uint16 module_id);
cs_status ten_n40g_tx_40ge_gmp_lo_otu3_25u_t41(cs_uint16 module_id);
cs_status ten_n40g_tx_40ge_gmp_lo_otu3_otl34_t41(cs_uint16 module_id);
cs_status ten_n40g_tx_40ge_gmp_lo_otu3e2_t41(cs_uint16 module_id);
cs_status ten_n40g_tx_40ge_gmp_lo_otu3e2_ppm_t41(cs_uint16 module_id);
cs_status ten_n40g_tx_40ge_gmp_lo_otu3e1_t41(cs_uint16 module_id);
cs_status ten_n40g_tx_40ge_propmap_lo_otu3e1_t41(cs_uint16 module_id);
cs_status ten_n40g_tx_40ge_fs96_otu3_t41(cs_uint16 module_id);
cs_status ten_n40g_tx_40ge_fs32_otu3_t41(cs_uint16 module_id);
cs_status ten_n40g_tx_125g_ts_odtu_otu3_t41(cs_uint16 module_id);
cs_status ten_n40g_tx_125g_ts_odtu_otu3e2_t41(cs_uint16 module_id);
cs_status ten_n40g_tx_25g_ts_odtu_otu3_t41(cs_uint16 module_id);
cs_status ten_n40g_tx_25g_ts_odtu_otu3e1_t41(cs_uint16 module_id);
cs_status ten_n40g_tx_25g_ts_odtu_otu3e1_dt_t41(cs_uint16 module_id);
cs_status ten_n40g_tx_25g_ts_odtu_otu310u_otl34_t41(cs_uint16 module_id);
cs_status ten_n40g_tx_125g_ts_odtu_otu310u_otl34_t41(cs_uint16 module_id);
cs_status ten_n40g_tx_25g_ts_odtu23p_otu3p_t41(cs_uint16 module_id);
cs_status ten_n40g_tx_oc768_stl256_t41(cs_uint16 module_id);
cs_status ten_n40g_tx_prbs_oc768_stl256_t41(cs_uint16 module_id, cs_uint16 pattern);
cs_status ten_n40g_tx_oc768_otu3_otl34_t41(cs_uint16 module_id);
cs_status ten_n40g_tx_prbs_oc768_otu3_otl34_t41(cs_uint16 module_id, cs_uint16 pattern);
cs_status ten_n40g_tx_odu3_otu3_otl34_t41(cs_uint16 module_id);
cs_status ten_n40g_tx_oc768_transparent_odu3_t41(cs_uint16 module_id);
cs_status ten_n40g_tx_prbs_out_t41(cs_uint16 module_id, cs_uint16 pattern);
cs_status ten_n40g_tx_prbs_odu3_t41(cs_uint16 module_id, cs_uint16 pattern);
cs_status ten_n40g_tx_prbs_oc768_odu3_t41(cs_uint16 module_id, cs_uint16 pattern);
cs_status ten_n40g_tx_oc768_odu3_t41(cs_uint16 module_id);
cs_status ten_n40g_tx_n10g_odu3aggr_otu3_t41(cs_uint16 module_id);
cs_status ten_n40g_tx_125g_ts_odtu_odu3_t41(cs_uint16 module_id);
cs_status ten_n40g_rx_gfec_t41(cs_uint16 module_id);
cs_status ten_n40g_rx_ufec_t41(cs_uint16 module_id);
cs_status ten_n40g_rx_nrows_t41(cs_uint16 module_id, cs_uint16 rows);
cs_status ten_n40g_rx_ncols_t41(cs_uint16 module_id, cs_uint16 columns);
cs_status ten_n40g_rx_npar_t41(cs_uint16 module_id, cs_uint16 parity);
cs_status ten_n40g_rx_nparb_t41(cs_uint16 module_id, cs_uint16 parity);
cs_status ten_n40g_rx_otu3_t41(cs_uint16 module_id);
cs_status ten_n40g_rx_odu3_t41(cs_uint16 module_id);
cs_status ten_n40g_rx_second_odu3_t41(cs_uint16 module_id);
cs_status ten_n40g_rx_aggr_t41(cs_uint16 module_id);
cs_status ten_n40g_rx_opu3_t41(cs_uint16 module_id);
cs_status ten_n40g_rx_oc768_in_t41(cs_uint16 module_id);
cs_status ten_n40g_rx_oc768_msregen_t41(cs_uint16 module_id);
cs_status ten_n40g_rx_oc768_transparent_t41(cs_uint16 module_id);
cs_status ten_n40g_rx_otl34_t41(cs_uint16 module_id);
cs_status ten_n40g_rx_stl256_t41(cs_uint16 module_id);
cs_status ten_n40g_rx_125g_ts_t41(cs_uint16 module_id);
cs_status ten_n40g_rx_25g_ts_t41(cs_uint16 module_id);
cs_status ten_n40g_rx_amp_lo_t41(cs_uint16 module_id);
cs_status ten_n40g_rx_amp_trib_t41(cs_uint16 module_id, cs_uint16 trib);
cs_status ten_n40g_rx_amp_trib_0_t41(cs_uint16 module_id);
cs_status ten_n40g_rx_amp_trib_1_t41(cs_uint16 module_id);
cs_status ten_n40g_rx_amp_trib_2_t41(cs_uint16 module_id);
cs_status ten_n40g_rx_amp_trib_3_t41(cs_uint16 module_id);
cs_status ten_n40g_rx_gmp_ho_trib_0_t41(cs_uint16 module_id, cs_uint32 cn_32bit);
cs_status ten_n40g_rx_gmp_ho_trib_1_t41(cs_uint16 module_id, cs_uint32 cn_32bit);
cs_status ten_n40g_rx_gmp_ho_trib_2_t41(cs_uint16 module_id, cs_uint32 cn_32bit);
cs_status ten_n40g_rx_gmp_ho_trib_3_t41(cs_uint16 module_id, cs_uint32 cn_32bit);
cs_status ten_n40g_rx_gmp_ho_tsen_t41(cs_uint16 module_id, cs_uint16 tsen0, cs_uint16 tsen1);
cs_status ten_n40g_rx_detamp_t41(cs_uint16 module_id);
cs_status ten_n40g_rx_gmp_lo_t41(cs_uint16 module_id, cs_uint32 cn_32bit);
cs_status ten_n40g_rx_propmap_lo_t41(cs_uint16 module_id);
cs_status ten_n40g_rx_propmap_ho_t41(cs_uint16 module_id);
cs_status ten_n40g_rx_n40g_bypass_t41(cs_uint16 module_id);
cs_status ten_n40g_rx_pkt_bypass_t41(cs_uint16 module_id);
cs_status ten_n40g_rx_ufec7_t41(cs_uint16 module_id);
cs_status ten_n40g_rx_ufec10_t41(cs_uint16 module_id);
cs_status ten_n40g_rx_ufec12_t41(cs_uint16 module_id);
cs_status ten_n40g_rx_ufec26_t41(cs_uint16 module_id);
cs_status ten_n40g_rx_ufec25_t41(cs_uint16 module_id);
cs_status ten_n40g_rx_otn_scr_off_t41(cs_uint16 module_id);
cs_status ten_n40g_rx_oc768_scr_off_t41(cs_uint16 module_id);
cs_status ten_n40g_rx_oc768_oof_hyst_t41(cs_uint16 module_id, cs_uint16 val);
cs_status ten_n40g_rx_fec_datapath_bypass_t41(cs_uint16 module_id);
cs_status ten_n40g_rx_generate_frame_pulses_t41(cs_uint16 module_id, cs_uint16 frame_pulse_len);
cs_status ten_n40g_rx_oc768_prbs_t41(cs_uint16 module_id);
cs_status ten_n40g_rx_otu3_prbs_t41(cs_uint16 module_id);
cs_status ten_n40g_rx_otu3_oc768_prbs_t41(cs_uint16 module_id);
cs_status ten_n40g_rx_otu3_odu3_t41(cs_uint16 module_id);
cs_status ten_n40g_rx_otu3e1_odu3e1_t41(cs_uint16 module_id);
cs_status ten_n40g_rx_otu3e2_odu3e2_t41(cs_uint16 module_id);
cs_status ten_n40g_rx_otu3e2_gmp_lo_odu3_t41(cs_uint16 module_id);
cs_status ten_n40g_rx_otu3e2_odu3e2_and_gmp_lo_40ge_mon_t41(cs_uint16 module_id);
cs_status ten_n40g_rx_otu3_gmp_lo_40ge_t41(cs_uint16 module_id);
cs_status ten_n40g_rx_odu3_gmp_lo_40ge_t41(cs_uint16 module_id);
cs_status ten_n40g_rx_otu3_25u_gmp_lo_40ge_t41(cs_uint16 module_id);
cs_status ten_n40g_rx_otl34_otu3_gmp_lo_40ge_t41(cs_uint16 module_id);
cs_status ten_n40g_rx_otu3e1_gmp_lo_40ge_t41(cs_uint16 module_id);
cs_status ten_n40g_rx_otu3e2_gmp_lo_40ge_t41(cs_uint16 module_id);
cs_status ten_n40g_rx_otu3e2_gmp_lo_40ge_ppm_t41(cs_uint16 module_id);
cs_status ten_n40g_rx_otu3e1_propmap_lo_40ge_t41(cs_uint16 module_id);
cs_status ten_n40g_rx_otu3_fs96_40ge_t41(cs_uint16 module_id);
cs_status ten_n40g_rx_otu3_fs32_40ge_t41(cs_uint16 module_id);
cs_status ten_n40g_rx_otu3_odtu_125g_ts_t41(cs_uint16 module_id);
cs_status ten_n40g_rx_otu3e2_odtu_125g_ts_t41(cs_uint16 module_id);
cs_status ten_n40g_rx_otu3e1_odtu_25g_ts_t41(cs_uint16 module_id);
cs_status ten_n40g_rx_otu3_odtu_25g_ts_t41(cs_uint16 module_id);
cs_status ten_n40g_rx_otl34_otu310u_odtu_25g_ts_t41(cs_uint16 module_id);
cs_status ten_n40g_rx_otl34_otu310u_odtu_125g_ts_t41(cs_uint16 module_id);
cs_status ten_n40g_rx_otu3p_odtu23p_25g_ts_t41(cs_uint16 module_id);
cs_status ten_n40g_rx_stl256_oc768_t41(cs_uint16 module_id);
cs_status ten_n40g_rx_stl256_oc768_prbs_t41(cs_uint16 module_id);
cs_status ten_n40g_rx_otl34_otu3_oc768_t41(cs_uint16 module_id);
cs_status ten_n40g_rx_otl34_otu3_oc768_prbs_t41(cs_uint16 module_id);
cs_status ten_n40g_rx_otl34_otu3_odu3_t41(cs_uint16 module_id);
cs_status ten_n40g_rx_otl34_otu3_prbs_t41(cs_uint16 module_id);
cs_status ten_n40g_rx_odu3_oc768_transparent_prbs_t41(cs_uint16 module_id);
cs_status ten_n40g_rx_cbr40in_t41(cs_uint16 module_id);
cs_status ten_n40g_rx_odu3_prbs_t41(cs_uint16 module_id);
cs_status ten_n40g_rx_odu3_oc768_prbs_t41(cs_uint16 module_id);
cs_status ten_n40g_rx_odu3_odtu_125g_ts_t41(cs_uint16 module_id);
cs_status ten_n40g_global_release_sreset_t41(cs_uint16 module_id);
cs_status ten_n40g_global_sreset_t41(cs_uint16 module_id);
/* Bugzilla 24360 End */
cs_status ten_n40g_pn11_pattern_select_t41(cs_uint16 module_id, 
                                           cs_uint16 pn11_type);

/* Bugzilla 27668 Start */
cs_status ten_n40g_mfas_translation_en (cs_uint16 module_id,
                                        cs_dir_t dir, 
                                        cs_ctl_t ctrl);
/* Bugzilla 27668 End */

/* Bugzilla 26908 Start */
cs_status  ten_n40g_sadeco_config(cs_uint16 module_id,
                                  cs_uint16 es_depth,
                                  cs_uint16 es_skew_length,
                                  cs_uint16 fp_type,
                                  cs_uint16 trib_stream);

cs_status ten_n40g_sadeco_enable_fp(cs_uint16 module_id, cs_ctl_t enable);

cs_status ten_n40g_sadeco_sdclen(cs_uint16 module_id, cs_uint16 sdclen);

cs_status ten_n40g_set_circuit_thresholds(cs_uint16 module_id, 
                                          cs_uint8 slice,
                                          cs_uint16 type, 
                                          cs_uint16 value);

cs_status ten_n40g_mldr_set_lmfirlen(cs_uint16 module_id, cs_uint16 lmfirlen);
/* Bugzilla 26908 End */

/* Bugzilla 27628 Start */
cs_status ten_n40g_mldrx_mld_es_set_sreset_t41 (cs_uint16 module_id,
                                                cs_uint8  slice,
                                                cs_uint16 reset);

cs_status ten_n40g_mldrx_sadeco_set_sreset_t41(cs_uint16 module_id, cs_uint16 swrst);
/* Bugzilla 27628 End */


/* Bugzilla 29751 Start */
void ten_n40g_otnr4x_intr_handler (ten_irq_handler_data_t handler_data);
cs_status ten_n40g_otnr4x_intr_handler_enable (cs_uint16 module_id, cs_uint16 bitfield);
void ten_n40g_sdfr_sdfist_handler (ten_irq_handler_data_t handler_data);
cs_status ten_n40g_sdfr_sdfist_handler_enable (cs_uint16 module_id, cs_uint16 bitfield);
/* Bugzilla 29751 End */

cs_status ten_n40g_otnt4x_wrpcfg1_t41(cs_uint16 module_id, 
                                      cs_uint16 jchyst);

 cs_status ten_n40g_otnt4x_dmcfg1_gen_enable(cs_uint16 module_id, 
                                            cs_uint16 dm_select, cs_uint16 dm_gen_en);
                                            
cs_status ten_n40g_otnt4x_dmcfg2_insert_enable(cs_uint16 module_id, 
                                               cs_uint16 dm_select, cs_uint16 dm_insert_en);
                                               
cs_status ten_n40g_otnt4x_dmcsfcfg_auto_csf_enable(cs_uint16 module_id, 
                                                   cs_uint16 auto_csf_en);
                                                   
cs_status ten_n40g_otnt4x_dmcsfcfg_csf_force(cs_uint16 module_id, 
                                             cs_uint16 csf_force);
                                             
cs_status ten_n40g_otnt4x_dmcsfcfg_dm_trigger(cs_uint16 module_id);

cs_status ten_n40g_otnt4x_dmcsfcfg_sel(cs_uint16 module_id, 
                                       cs_uint16 dm_select);                                     
 
cs_status ten_n40g_oohr_dmcsf_cfgdm(cs_uint16 module_id, 
                                    cs_uint16 cfgdm);
                                    
cs_status ten_n40g_oohr_dmcsf_dm_filt(cs_uint16 module_id, 
                                      cs_uint16 dm_filt);
                                      
cs_uint16 ten_n40g_oohr_get_dmcsf_stat_dmacpt(cs_uint16 module_id, cs_uint16 tcmpm);

cs_status ten_n40g_otnt_statcfg(cs_uint16 module_id,
                                cs_uint16 tcmpm, 
                                cs_uint16 tcmpmstat, 
                                cs_uint16 tcmpmstatinsmd);
                                
cs_status ten_n40g_otnt_cfg3_ms_oh_ins(cs_uint16 module_id, 
                                       cs_uint16 ms_oh_ins);

cs_status ten_n40g_oohr_bipcfg2_sfblk(cs_uint16 module_id, 
                                      cs_uint16 sfblk);
                                      
cs_status ten_n40g_oohr_bipcfg2_bip_thsel(cs_uint16 module_id, 
                                cs_uint16 bip, 
                                cs_uint16 bip_thsel);
                                
cs_status ten_n40g_oohr_bipval(cs_uint16 module_id, cs_uint8 slice, 
                               cs_uint16 bip,
                               cs_uint32 bipval);

cs_status ten_n40g_otnt_cfg3_aps_ins_en(cs_uint16 module_id,
                                        cs_uint8 aps_chan_num, 
                                        cs_uint16 aps_ins_en);
                               
#ifdef __cplusplus
}
#endif
#endif

