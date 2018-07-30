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
 * ten_hl_hsif.c
 *
 * API's for protocol high level configuration.
 *
 * $Id: ten_hl_hsif.c,v 1.158 2014/04/02 18:50:10 pptawade Exp $
 *
 */

#include "tenabo40.h"

const cs_char8 ten_hsif_gram_table_version[] = "126201041732PM";

/* xfi_ucode_release_126201041732PM.txt */
const cs_uint16 ten_hsif_gram_table[TEN_HSIF_GRAM_ROWS_MAX][TEN_HSIF_GRAM_COLS_MAX] =
{
 { 0x009F , 0xCF0F , 0x9000 },
 { 0x0091 , 0x0380 , 0x9001 },
 { 0x0083 , 0x0380 , 0x9002 },
 { 0x0083 , 0xB999 , 0x9003 },
 { 0x0003 , 0xB992 , 0x9004 },
 { 0x0083 , 0xB9FA , 0x9005 },
 { 0x0003 , 0xB99E , 0x9006 },
 { 0x0083 , 0xC195 , 0x9007 },
 { 0x0042 , 0x0000 , 0x9008 },
 { 0x0042 , 0x0000 , 0x9009 },
 { 0x0003 , 0xB9D5 , 0x900A },
 { 0x0098 , 0x9200 , 0x900B },
 { 0x0083 , 0x0392 , 0x900C },
 { 0x0003 , 0x4B84 , 0x900D },
 { 0x0083 , 0xB984 , 0x900E },
 { 0x0003 , 0x4A98 , 0x900F },
 { 0x0003 , 0x42D4 , 0x9010 },
 { 0x0083 , 0xD198 , 0x9011 },
 { 0x0083 , 0x408E , 0x9012 },
 { 0x0083 , 0x4191 , 0x9013 },
 { 0x0083 , 0xB9E1 , 0x9014 },
 { 0x0003 , 0xB986 , 0x9015 },
 { 0x0083 , 0xB9FA , 0x9016 },
 { 0x0003 , 0xB99E , 0x9017 },
 { 0x008C , 0x8500 , 0x9018 },
 { 0x0083 , 0xB982 , 0x9019 },
 { 0x0083 , 0xD3DB , 0x901A },
 { 0x0042 , 0x0000 , 0x901B },
 { 0x0042 , 0x0000 , 0x901C },
 { 0x0003 , 0xCF82 , 0x901D },
 { 0x0003 , 0xD098 , 0x901E },
 { 0x0083 , 0xCDDB , 0x901F },
 { 0x0042 , 0x0000 , 0x9020 },
 { 0x0042 , 0x0000 , 0x9021 },
 { 0x0083 , 0xCF98 , 0x9022 },
 { 0x0003 , 0x48DB , 0x9023 },
 { 0x0042 , 0x0000 , 0x9024 },
 { 0x0042 , 0x0000 , 0x9025 },
 { 0x0083 , 0x47F8 , 0x9026 },
 { 0x0003 , 0x44DB , 0x9027 },
 { 0x0042 , 0x0000 , 0x9028 },
 { 0x0042 , 0x0000 , 0x9029 },
 { 0x0083 , 0xBAB4 , 0x902A },
 { 0x0083 , 0xCDDB , 0x902B },
 { 0x0042 , 0x0000 , 0x902C },
 { 0x0042 , 0x0000 , 0x902D },
 { 0x0003 , 0x46F8 , 0x902E },
 { 0x0003 , 0x44DB , 0x902F },
 { 0x0042 , 0x0000 , 0x9030 },
 { 0x0042 , 0x0000 , 0x9031 },
 { 0x0003 , 0xBBB4 , 0x9032 },
 { 0x0083 , 0xCDDB , 0x9033 },
 { 0x0042 , 0x0000 , 0x9034 },
 { 0x0042 , 0x0000 , 0x9035 },
 { 0x0003 , 0xD2B4 , 0x9036 },
 { 0x0042 , 0x0000 , 0x9037 },
 { 0x0042 , 0x0000 , 0x9038 },
 { 0x0003 , 0xCBF8 , 0x9039 },
 { 0x0000 , 0x003C , 0x903A },
 { 0x0000 , 0x000A , 0x903B },
 { 0x0098 , 0xEF00 , 0x903C },
 { 0x0083 , 0x03EF , 0x903D },
 { 0x001F , 0xE50F , 0x903E },
 { 0x0097 , 0x03EF , 0x903F },
 { 0x00C1 , 0x007A , 0x9040 },
 { 0x0003 , 0xBAEF , 0x9041 },
 { 0x001B , 0x4CD6 , 0x9042 },
 { 0x0097 , 0xE303 , 0x9043 },
 { 0x00C1 , 0x005E , 0x9044 },
 { 0x009F , 0xFA0F , 0x9045 },
 { 0x009D , 0x03BA , 0x9046 },
 { 0x0003 , 0x03FA , 0x9047 },
 { 0x001F , 0xBC0F , 0x9048 },
 { 0x001B , 0x03FA , 0x9049 },
 { 0x0083 , 0x039E , 0x904A },
 { 0x001F , 0xBC0F , 0x904B },
 { 0x0017 , 0x03FA , 0x904C },
 { 0x00A1 , 0x004F , 0x904D },
 { 0x0083 , 0xBB9E , 0x904E },
 { 0x0084 , 0xFA2B , 0x904F },
 { 0x001B , 0x4CD5 , 0x9050 },
 { 0x0020 , 0x007A , 0x9051 },
 { 0x001F , 0xBC0F , 0x9052 },
 { 0x009E , 0xD503 , 0x9053 },
 { 0x0083 , 0x03D5 , 0x9054 },
 { 0x0003 , 0x44DB , 0x9055 },
 { 0x0042 , 0x0000 , 0x9056 },
 { 0x0042 , 0x0000 , 0x9057 },
 { 0x0003 , 0xD098 , 0x9058 },
 { 0x0083 , 0xCDDB , 0x9059 },
 { 0x0042 , 0x0000 , 0x905A },
 { 0x0042 , 0x0000 , 0x905B },
 { 0x0083 , 0xCF98 , 0x905C },
 { 0x0080 , 0x007A , 0x905D },
 { 0x001B , 0x4CD6 , 0x905E },
 { 0x0017 , 0x03E4 , 0x905F },
 { 0x00C1 , 0x007A , 0x9060 },
 { 0x009F , 0xFA0F , 0x9061 },
 { 0x0017 , 0x03CA , 0x9062 },
 { 0x0020 , 0x007A , 0x9063 },
 { 0x009F , 0xFA0F , 0x9064 },
 { 0x001C , 0x03BA , 0x9065 },
 { 0x0091 , 0x03BA , 0x9066 },
 { 0x0003 , 0x03FA , 0x9067 },
 { 0x001F , 0xBC0F , 0x9068 },
 { 0x001B , 0x03FA , 0x9069 },
 { 0x0083 , 0x039E , 0x906A },
 { 0x001F , 0xBC0F , 0x906B },
 { 0x0017 , 0x03FA , 0x906C },
 { 0x0021 , 0x006F , 0x906D },
 { 0x0083 , 0xBB9E , 0x906E },
 { 0x001F , 0xBC0F , 0x906F },
 { 0x0019 , 0xD503 , 0x9070 },
 { 0x0083 , 0x03D5 , 0x9071 },
 { 0x0003 , 0x44DB , 0x9072 },
 { 0x0042 , 0x0000 , 0x9073 },
 { 0x0042 , 0x0000 , 0x9074 },
 { 0x0003 , 0xD098 , 0x9075 },
 { 0x0083 , 0xCDDB , 0x9076 },
 { 0x0042 , 0x0000 , 0x9077 },
 { 0x0042 , 0x0000 , 0x9078 },
 { 0x0083 , 0xCF98 , 0x9079 },
 { 0x0005 , 0xE10A , 0x907A },
 { 0x0018 , 0xEE00 , 0x907B },
 { 0x0003 , 0x03EE , 0x907C },
 { 0x001F , 0xE60F , 0x907D },
 { 0x0017 , 0x03EE , 0x907E },
 { 0x00C1 , 0x0097 , 0x907F },
 { 0x0083 , 0xBAE1 , 0x9080 },
 { 0x001B , 0x4CD6 , 0x9081 },
 { 0x0011 , 0x034D , 0x9082 },
 { 0x0083 , 0x03D5 , 0x9083 },
 { 0x000F , 0xD90B , 0x9084 },
 { 0x001B , 0x4CD9 , 0x9085 },
 { 0x0020 , 0x0089 , 0x9086 },
 { 0x0017 , 0xE203 , 0x9087 },
 { 0x00C1 , 0x0097 , 0x9088 },
 { 0x001B , 0x4CD5 , 0x9089 },
 { 0x0020 , 0x0097 , 0x908A },
 { 0x001F , 0xBA0F , 0x908B },
 { 0x009E , 0xD503 , 0x908C },
 { 0x0083 , 0x03D5 , 0x908D },
 { 0x0080 , 0x0097 , 0x908E },
 { 0x001B , 0x4CD5 , 0x908F },
 { 0x0097 , 0x034C , 0x9090 },
 { 0x0020 , 0x0097 , 0x9091 },
 { 0x009F , 0xE20F , 0x9092 },
 { 0x0097 , 0x03D9 , 0x9093 },
 { 0x00C1 , 0x0097 , 0x9094 },
 { 0x0098 , 0xD500 , 0x9095 },
 { 0x0083 , 0x03D5 , 0x9096 },
 { 0x008B , 0x85DC , 0x9097 },
 { 0x0003 , 0xC486 , 0x9098 },
 { 0x0000 , 0x001E , 0x9099 },
 { 0x0042 , 0x0000 , 0x909A },
 { 0x0042 , 0x0000 , 0x909B },
 { 0x0042 , 0x0000 , 0x909C },
 { 0x0042 , 0x0000 , 0x909D },
 { 0x0042 , 0x0000 , 0x909E },
 { 0x0042 , 0x0000 , 0x909F },
 { 0x0042 , 0x0000 , 0x90A0 },
 { 0x0042 , 0x0000 , 0x90A1 },
 { 0x0042 , 0x0000 , 0x90A2 },
 { 0x0042 , 0x0000 , 0x90A3 },
 { 0x0042 , 0x0000 , 0x90A4 },
 { 0x0042 , 0x0000 , 0x90A5 },
 { 0x0042 , 0x0000 , 0x90A6 },
 { 0x0042 , 0x0000 , 0x90A7 },
 { 0x0042 , 0x0000 , 0x90A8 },
 { 0x0042 , 0x0000 , 0x90A9 },
 { 0x0042 , 0x0000 , 0x90AA },
 { 0x0042 , 0x0000 , 0x90AB },
 { 0x0042 , 0x0000 , 0x90AC },
 { 0x0042 , 0x0000 , 0x90AD },
 { 0x0042 , 0x0000 , 0x90AE },
 { 0x0042 , 0x0000 , 0x90AF },
 { 0x0042 , 0x0000 , 0x90B0 },
 { 0x0042 , 0x0000 , 0x90B1 },
 { 0x0042 , 0x0000 , 0x90B2 },
 { 0x0042 , 0x0000 , 0x90B3 },
 { 0x0042 , 0x0000 , 0x90B4 },
 { 0x0042 , 0x0000 , 0x90B5 },
 { 0x0042 , 0x0000 , 0x90B6 },
 { 0x0042 , 0x0000 , 0x90B7 },
 { 0x0042 , 0x0000 , 0x90B8 },
 { 0x0042 , 0x0000 , 0x90B9 },
 { 0x0042 , 0x0000 , 0x90BA },
 { 0x0042 , 0x0000 , 0x90BB },
 { 0x0042 , 0x0000 , 0x90BC },
 { 0x0042 , 0x0000 , 0x90BD },
 { 0x0042 , 0x0000 , 0x90BE },
 { 0x0042 , 0x0000 , 0x90BF },
 { 0x0042 , 0x0000 , 0x90C0 },
 { 0x0042 , 0x0000 , 0x90C1 },
 { 0x0042 , 0x0000 , 0x90C2 },
 { 0x0042 , 0x0000 , 0x90C3 },
 { 0x0042 , 0x0000 , 0x90C4 },
 { 0x0042 , 0x0000 , 0x90C5 },
 { 0x0042 , 0x0000 , 0x90C6 },
 { 0x0042 , 0x0000 , 0x90C7 },
 { 0x0042 , 0x0000 , 0x90C8 },
 { 0x0042 , 0x0000 , 0x90C9 },
 { 0x0042 , 0x0000 , 0x90CA },
 { 0x0042 , 0x0000 , 0x90CB },
 { 0x0042 , 0x0000 , 0x90CC },
 { 0x0042 , 0x0000 , 0x90CD },
 { 0x0042 , 0x0000 , 0x90CE },
 { 0x0042 , 0x0000 , 0x90CF },
 { 0x0042 , 0x0000 , 0x90D0 },
 { 0x0042 , 0x0000 , 0x90D1 },
 { 0x0042 , 0x0000 , 0x90D2 },
 { 0x0042 , 0x0000 , 0x90D3 },
 { 0x0042 , 0x0000 , 0x90D4 },
 { 0x0042 , 0x0000 , 0x90D5 },
 { 0x0042 , 0x0000 , 0x90D6 },
 { 0x0042 , 0x0000 , 0x90D7 },
 { 0x0042 , 0x0000 , 0x90D8 },
 { 0x0042 , 0x0000 , 0x90D9 },
 { 0x0042 , 0x0000 , 0x90DA },
 { 0x0042 , 0x0000 , 0x90DB },
 { 0x0042 , 0x0000 , 0x90DC },
 { 0x0042 , 0x0000 , 0x90DD },
 { 0x0042 , 0x0000 , 0x90DE },
 { 0x0042 , 0x0000 , 0x90DF },
 { 0x0042 , 0x0000 , 0x90E0 },
 { 0x0042 , 0x0000 , 0x90E1 },
 { 0x0042 , 0x0000 , 0x90E2 },
 { 0x0042 , 0x0000 , 0x90E3 },
 { 0x0042 , 0x0000 , 0x90E4 },
 { 0x0042 , 0x0000 , 0x90E5 },
 { 0x0042 , 0x0000 , 0x90E6 },
 { 0x0042 , 0x0000 , 0x90E7 },
 { 0x0042 , 0x0000 , 0x90E8 },
 { 0x0042 , 0x0000 , 0x90E9 },
 { 0x0042 , 0x0000 , 0x90EA },
 { 0x0042 , 0x0000 , 0x90EB },
 { 0x0042 , 0x0000 , 0x90EC },
 { 0x0042 , 0x0000 , 0x90ED },
 { 0x0042 , 0x0000 , 0x90EE },
 { 0x0042 , 0x0000 , 0x90EF },
 { 0x0042 , 0x0000 , 0x90F0 },
 { 0x0042 , 0x0000 , 0x90F1 },
 { 0x0042 , 0x0000 , 0x90F2 },
 { 0x0042 , 0x0000 , 0x90F3 },
 { 0x0042 , 0x0000 , 0x90F4 },
 { 0x0042 , 0x0000 , 0x90F5 },
 { 0x0042 , 0x0000 , 0x90F6 },
 { 0x0042 , 0x0000 , 0x90F7 },
 { 0x0042 , 0x0000 , 0x90F8 },
 { 0x0042 , 0x0000 , 0x90F9 },
 { 0x0042 , 0x0000 , 0x90FA },
 { 0x0042 , 0x0000 , 0x90FB },
 { 0x0042 , 0x0000 , 0x90FC },
 { 0x0042 , 0x0000 , 0x90FD },
 { 0x0042 , 0x0000 , 0x90FE },
 { 0x0042 , 0x0000 , 0x90FF },
 { 0x0042 , 0x0000 , 0x9100 },
 { 0x0042 , 0x0000 , 0x9101 },
 { 0x0042 , 0x0000 , 0x9102 },
 { 0x0042 , 0x0000 , 0x9103 },
 { 0x0042 , 0x0000 , 0x9104 },
 { 0x0042 , 0x0000 , 0x9105 },
 { 0x0042 , 0x0000 , 0x9106 },
 { 0x0042 , 0x0000 , 0x9107 },
 { 0x0042 , 0x0000 , 0x9108 },
 { 0x0042 , 0x0000 , 0x9109 },
 { 0x0042 , 0x0000 , 0x910A },
 { 0x0042 , 0x0000 , 0x910B },
 { 0x0042 , 0x0000 , 0x910C },
 { 0x0042 , 0x0000 , 0x910D },
 { 0x0042 , 0x0000 , 0x910E },
 { 0x0042 , 0x0000 , 0x910F },
 { 0x0042 , 0x0000 , 0x9110 },
 { 0x0042 , 0x0000 , 0x9111 },
 { 0x0042 , 0x0000 , 0x9112 },
 { 0x0042 , 0x0000 , 0x9113 },
 { 0x0042 , 0x0000 , 0x9114 },
 { 0x0042 , 0x0000 , 0x9115 },
 { 0x0042 , 0x0000 , 0x9116 },
 { 0x0042 , 0x0000 , 0x9117 },
 { 0x0042 , 0x0000 , 0x9118 },
 { 0x0042 , 0x0000 , 0x9119 },
 { 0x0042 , 0x0000 , 0x911A },
 { 0x0042 , 0x0000 , 0x911B },
 { 0x0042 , 0x0000 , 0x911C },
 { 0x0042 , 0x0000 , 0x911D },
 { 0x0042 , 0x0000 , 0x911E },
 { 0x0042 , 0x0000 , 0x911F },
 { 0x0042 , 0x0000 , 0x9120 },
 { 0x0042 , 0x0000 , 0x9121 },
 { 0x0042 , 0x0000 , 0x9122 },
 { 0x0042 , 0x0000 , 0x9123 },
 { 0x0042 , 0x0000 , 0x9124 },
 { 0x0042 , 0x0000 , 0x9125 },
 { 0x0042 , 0x0000 , 0x9126 },
 { 0x0042 , 0x0000 , 0x9127 },
 { 0x0042 , 0x0000 , 0x9128 },
 { 0x0042 , 0x0000 , 0x9129 },
 { 0x0042 , 0x0000 , 0x912A },
 { 0x0042 , 0x0000 , 0x912B },
 { 0x0042 , 0x0000 , 0x912C },
 { 0x0042 , 0x0000 , 0x912D },
 { 0x0042 , 0x0000 , 0x912E },
 { 0x0042 , 0x0000 , 0x912F },
 { 0x0042 , 0x0000 , 0x9130 },
 { 0x0042 , 0x0000 , 0x9131 },
 { 0x0042 , 0x0000 , 0x9132 },
 { 0x0042 , 0x0000 , 0x9133 },
 { 0x0042 , 0x0000 , 0x9134 },
 { 0x0042 , 0x0000 , 0x9135 },
 { 0x0042 , 0x0000 , 0x9136 },
 { 0x0042 , 0x0000 , 0x9137 },
 { 0x0042 , 0x0000 , 0x9138 },
 { 0x0042 , 0x0000 , 0x9139 },
 { 0x0042 , 0x0000 , 0x913A },
 { 0x0042 , 0x0000 , 0x913B },
 { 0x0042 , 0x0000 , 0x913C },
 { 0x0042 , 0x0000 , 0x913D },
 { 0x0042 , 0x0000 , 0x913E },
 { 0x0042 , 0x0000 , 0x913F },
 { 0x0042 , 0x0000 , 0x9140 },
 { 0x0042 , 0x0000 , 0x9141 },
 { 0x0042 , 0x0000 , 0x9142 },
 { 0x0042 , 0x0000 , 0x9143 },
 { 0x0042 , 0x0000 , 0x9144 },
 { 0x0042 , 0x0000 , 0x9145 },
 { 0x0042 , 0x0000 , 0x9146 },
 { 0x0042 , 0x0000 , 0x9147 },
 { 0x0042 , 0x0000 , 0x9148 },
 { 0x0042 , 0x0000 , 0x9149 },
 { 0x0042 , 0x0000 , 0x914A },
 { 0x0042 , 0x0000 , 0x914B },
 { 0x0042 , 0x0000 , 0x914C },
 { 0x0042 , 0x0000 , 0x914D },
 { 0x0042 , 0x0000 , 0x914E },
 { 0x0042 , 0x0000 , 0x914F },
 { 0x0042 , 0x0000 , 0x9150 },
 { 0x0042 , 0x0000 , 0x9151 },
 { 0x0042 , 0x0000 , 0x9152 },
 { 0x0042 , 0x0000 , 0x9153 },
 { 0x0042 , 0x0000 , 0x9154 },
 { 0x0042 , 0x0000 , 0x9155 },
 { 0x0042 , 0x0000 , 0x9156 },
 { 0x0042 , 0x0000 , 0x9157 },
 { 0x0042 , 0x0000 , 0x9158 },
 { 0x0042 , 0x0000 , 0x9159 },
 { 0x0042 , 0x0000 , 0x915A },
 { 0x0042 , 0x0000 , 0x915B },
 { 0x0042 , 0x0000 , 0x915C },
 { 0x0042 , 0x0000 , 0x915D },
 { 0x0042 , 0x0000 , 0x915E },
 { 0x0042 , 0x0000 , 0x915F },
 { 0x0042 , 0x0000 , 0x9160 },
 { 0x0042 , 0x0000 , 0x9161 },
 { 0x0042 , 0x0000 , 0x9162 },
 { 0x0042 , 0x0000 , 0x9163 },
 { 0x0042 , 0x0000 , 0x9164 },
 { 0x0042 , 0x0000 , 0x9165 },
 { 0x0042 , 0x0000 , 0x9166 },
 { 0x0042 , 0x0000 , 0x9167 },
 { 0x0042 , 0x0000 , 0x9168 },
 { 0x0042 , 0x0000 , 0x9169 },
 { 0x0042 , 0x0000 , 0x916A },
 { 0x0042 , 0x0000 , 0x916B },
 { 0x0042 , 0x0000 , 0x916C },
 { 0x0042 , 0x0000 , 0x916D },
 { 0x0042 , 0x0000 , 0x916E },
 { 0x0042 , 0x0000 , 0x916F },
 { 0x0042 , 0x0000 , 0x9170 },
 { 0x0042 , 0x0000 , 0x9171 },
 { 0x0042 , 0x0000 , 0x9172 },
 { 0x0042 , 0x0000 , 0x9173 },
 { 0x0042 , 0x0000 , 0x9174 },
 { 0x0042 , 0x0000 , 0x9175 },
 { 0x0042 , 0x0000 , 0x9176 },
 { 0x0042 , 0x0000 , 0x9177 },
 { 0x0042 , 0x0000 , 0x9178 },
 { 0x0042 , 0x0000 , 0x9179 },
 { 0x0042 , 0x0000 , 0x917A },
 { 0x0042 , 0x0000 , 0x917B },
 { 0x0042 , 0x0000 , 0x917C },
 { 0x0042 , 0x0000 , 0x917D },
 { 0x0042 , 0x0000 , 0x917E },
 { 0x0042 , 0x0000 , 0x917F },
 { 0x0042 , 0x0000 , 0x9180 },
 { 0x0042 , 0x0000 , 0x9181 },
 { 0x0042 , 0x0000 , 0x9182 },
 { 0x0042 , 0x0000 , 0x9183 },
 { 0x0042 , 0x0000 , 0x9184 },
 { 0x0042 , 0x0000 , 0x9185 },
 { 0x0042 , 0x0000 , 0x9186 },
 { 0x0042 , 0x0000 , 0x9187 },
 { 0x0042 , 0x0000 , 0x9188 },
 { 0x0042 , 0x0000 , 0x9189 },
 { 0x0042 , 0x0000 , 0x918A },
 { 0x0042 , 0x0000 , 0x918B },
 { 0x0042 , 0x0000 , 0x918C },
 { 0x0042 , 0x0000 , 0x918D },
 { 0x0042 , 0x0000 , 0x918E },
 { 0x0042 , 0x0000 , 0x918F },
 { 0x0042 , 0x0000 , 0x9190 },
 { 0x0042 , 0x0000 , 0x9191 },
 { 0x0042 , 0x0000 , 0x9192 },
 { 0x0042 , 0x0000 , 0x9193 },
 { 0x0042 , 0x0000 , 0x9194 },
 { 0x0042 , 0x0000 , 0x9195 },
 { 0x0042 , 0x0000 , 0x9196 },
 { 0x0042 , 0x0000 , 0x9197 },
 { 0x0042 , 0x0000 , 0x9198 },
 { 0x0042 , 0x0000 , 0x9199 },
 { 0x0042 , 0x0000 , 0x919A },
 { 0x0042 , 0x0000 , 0x919B },
 { 0x0042 , 0x0000 , 0x919C },
 { 0x0042 , 0x0000 , 0x919D },
 { 0x0042 , 0x0000 , 0x919E },
 { 0x0042 , 0x0000 , 0x919F },
 { 0x0042 , 0x0000 , 0x91A0 },
 { 0x0042 , 0x0000 , 0x91A1 },
 { 0x0042 , 0x0000 , 0x91A2 },
 { 0x0042 , 0x0000 , 0x91A3 },
 { 0x0042 , 0x0000 , 0x91A4 },
 { 0x0042 , 0x0000 , 0x91A5 },
 { 0x0042 , 0x0000 , 0x91A6 },
 { 0x0042 , 0x0000 , 0x91A7 },
 { 0x0042 , 0x0000 , 0x91A8 },
 { 0x0042 , 0x0000 , 0x91A9 },
 { 0x0042 , 0x0000 , 0x91AA },
 { 0x0042 , 0x0000 , 0x91AB },
 { 0x0042 , 0x0000 , 0x91AC },
 { 0x0042 , 0x0000 , 0x91AD },
 { 0x0042 , 0x0000 , 0x91AE },
 { 0x0042 , 0x0000 , 0x91AF },
 { 0x0042 , 0x0000 , 0x91B0 },
 { 0x0042 , 0x0000 , 0x91B1 },
 { 0x0042 , 0x0000 , 0x91B2 },
 { 0x0042 , 0x0000 , 0x91B3 },
 { 0x0042 , 0x0000 , 0x91B4 },
 { 0x0042 , 0x0000 , 0x91B5 },
 { 0x0042 , 0x0000 , 0x91B6 },
 { 0x0042 , 0x0000 , 0x91B7 },
 { 0x0042 , 0x0000 , 0x91B8 },
 { 0x0042 , 0x0000 , 0x91B9 },
 { 0x0042 , 0x0000 , 0x91BA },
 { 0x0042 , 0x0000 , 0x91BB },
 { 0x0042 , 0x0000 , 0x91BC },
 { 0x0042 , 0x0000 , 0x91BD },
 { 0x0042 , 0x0000 , 0x91BE },
 { 0x0042 , 0x0000 , 0x91BF },
 { 0x0042 , 0x0000 , 0x91C0 },
 { 0x0042 , 0x0000 , 0x91C1 },
 { 0x0042 , 0x0000 , 0x91C2 },
 { 0x0042 , 0x0000 , 0x91C3 },
 { 0x0042 , 0x0000 , 0x91C4 },
 { 0x0042 , 0x0000 , 0x91C5 },
 { 0x0042 , 0x0000 , 0x91C6 },
 { 0x0042 , 0x0000 , 0x91C7 },
 { 0x0042 , 0x0000 , 0x91C8 },
 { 0x0042 , 0x0000 , 0x91C9 },
 { 0x0042 , 0x0000 , 0x91CA },
 { 0x0042 , 0x0000 , 0x91CB },
 { 0x0042 , 0x0000 , 0x91CC },
 { 0x0042 , 0x0000 , 0x91CD },
 { 0x0042 , 0x0000 , 0x91CE },
 { 0x0042 , 0x0000 , 0x91CF },
 { 0x0042 , 0x0000 , 0x91D0 },
 { 0x0042 , 0x0000 , 0x91D1 },
 { 0x0042 , 0x0000 , 0x91D2 },
 { 0x0042 , 0x0000 , 0x91D3 },
 { 0x0042 , 0x0000 , 0x91D4 },
 { 0x0042 , 0x0000 , 0x91D5 },
 { 0x0042 , 0x0000 , 0x91D6 },
 { 0x0042 , 0x0000 , 0x91D7 },
 { 0x0042 , 0x0000 , 0x91D8 },
 { 0x0042 , 0x0000 , 0x91D9 },
 { 0x0042 , 0x0000 , 0x91DA },
 { 0x0042 , 0x0000 , 0x91DB },
 { 0x0042 , 0x0000 , 0x91DC },
 { 0x0042 , 0x0000 , 0x91DD },
 { 0x0042 , 0x0000 , 0x91DE },
 { 0x0042 , 0x0000 , 0x91DF },
 { 0x0042 , 0x0000 , 0x91E0 },
 { 0x0042 , 0x0000 , 0x91E1 },
 { 0x0042 , 0x0000 , 0x91E2 },
 { 0x0042 , 0x0000 , 0x91E3 },
 { 0x0042 , 0x0000 , 0x91E4 },
 { 0x0042 , 0x0000 , 0x91E5 },
 { 0x0042 , 0x0000 , 0x91E6 },
 { 0x0042 , 0x0000 , 0x91E7 },
 { 0x0042 , 0x0000 , 0x91E8 },
 { 0x0042 , 0x0000 , 0x91E9 },
 { 0x0042 , 0x0000 , 0x91EA },
 { 0x0042 , 0x0000 , 0x91EB },
 { 0x0042 , 0x0000 , 0x91EC },
 { 0x0042 , 0x0000 , 0x91ED },
 { 0x0042 , 0x0000 , 0x91EE },
 { 0x0042 , 0x0000 , 0x91EF },
 { 0x0042 , 0x0000 , 0x91F0 },
 { 0x0042 , 0x0000 , 0x91F1 },
 { 0x0042 , 0x0000 , 0x91F2 },
 { 0x0042 , 0x0000 , 0x91F3 },
 { 0x0042 , 0x0000 , 0x91F4 },
 { 0x0042 , 0x0000 , 0x91F5 },
 { 0x0042 , 0x0000 , 0x91F6 },
 { 0x0042 , 0x0000 , 0x91F7 },
 { 0x0042 , 0x0000 , 0x91F8 },
 { 0x0042 , 0x0000 , 0x91F9 },
 { 0x0042 , 0x0000 , 0x91FA },
 { 0x0042 , 0x0000 , 0x91FB },
 { 0x0042 , 0x0000 , 0x91FC },
 { 0x0042 , 0x0000 , 0x91FD },
 { 0x0042 , 0x0000 , 0x91FE },
 { 0x0042 , 0x0000 , 0x91FF },
 { 0x9111 , 0x1110 , 0x8000 },
 { 0x9113 , 0x1313 , 0x8001 },
 { 0x0400 , 0xB929 , 0x8002 },
 { 0x20BB , 0xA040 , 0x8003 },
 { 0x8000 , 0x000F , 0x8004 },
 { 0x0000 , 0x00FF , 0x8005 },
 { 0x0000 , 0x003A , 0x8006 },
 { 0x0000 , 0x0046 , 0x8007 },
 { 0x8001 , 0xF350 , 0x8008 },
 { 0x0000 , 0x0104 , 0x8009 },
 { 0x8000 , 0x1555 , 0x800A },
 { 0x0000 , 0x0020 , 0x800B },
 { 0x0000 , 0x007F , 0x800C },
 { 0x0000 , 0x0100 , 0x800D },
 { 0x0000 , 0x3000 , 0x800E },
 { 0x0000 , 0x0000 , 0x800F },
 { 0x0000 , 0x0000 , 0x8010 },
 { 0x0000 , 0x0000 , 0x8011 },
 { 0x0000 , 0x0000 , 0x8012 },
 { 0x0000 , 0x0000 , 0x8013 },
 { 0x0000 , 0x0000 , 0x8014 },
 { 0x0000 , 0x0000 , 0x8015 },
 { 0x0000 , 0x0000 , 0x8016 },
 { 0x0000 , 0x0000 , 0x8017 },
 { 0x0000 , 0x0000 , 0x8018 },
 { 0x0000 , 0x0000 , 0x8019 },
 { 0x0000 , 0x0000 , 0x801A },
 { 0x0000 , 0x0000 , 0x801B },
 { 0x0000 , 0x0000 , 0x801C },
 { 0x0000 , 0x0000 , 0x801D },
 { 0x0000 , 0x0000 , 0x801E },
 { 0x0000 , 0x0000 , 0x801F },
 { 0x0000 , 0x0000 , 0x8020 },
 { 0x0000 , 0x0000 , 0x8021 },
 { 0x0000 , 0x0000 , 0x8022 },
 { 0x0000 , 0x0000 , 0x8023 },
 { 0x0000 , 0x0000 , 0x8024 },
 { 0x0000 , 0x0000 , 0x8025 },
 { 0x0000 , 0x0000 , 0x8026 },
 { 0x0000 , 0x0000 , 0x8027 },
 { 0x0000 , 0x0000 , 0x8028 },
 { 0x0000 , 0x0000 , 0x8029 },
 { 0x0000 , 0x0000 , 0x802A },
 { 0x0000 , 0x0000 , 0x802B },
 { 0x0000 , 0x0000 , 0x802C },
 { 0x0000 , 0x0000 , 0x802D },
 { 0x0000 , 0x0000 , 0x802E },
 { 0x0000 , 0x0000 , 0x802F },
 { 0x0000 , 0x0000 , 0x8030 },
 { 0x0000 , 0x0000 , 0x8031 },
 { 0x0000 , 0x0000 , 0x8032 },
 { 0x0000 , 0x0000 , 0x8033 },
 { 0x0000 , 0x0000 , 0x8034 },
 { 0x0000 , 0x0000 , 0x8035 },
 { 0x0000 , 0x0000 , 0x8036 },
 { 0x0000 , 0x0000 , 0x8037 },
 { 0x0000 , 0x0000 , 0x8038 },
 { 0x0000 , 0x0000 , 0x8039 },
 { 0x0000 , 0x0000 , 0x803A },
 { 0x0000 , 0x0000 , 0x803B },
 { 0x0000 , 0x0000 , 0x803C },
 { 0x0000 , 0x0000 , 0x803D },
 { 0x0000 , 0x0000 , 0x803E },
 { 0x0000 , 0x0000 , 0x803F }
};

/********************************************************************/
/* $rtn_hdr_start  HIGH LEVEL HSIF ANALOG CONFIG                    */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : HIGH LEVEL                                          */
/* CHIP       : Tenabo                                              */
cs_status ten_hl_hsif_analog_cfg(cs_uint16 module_id,
                          cs_uint8 slice,
                          cs_uint8 protocol,
                          cs_uint8 timing_mode)
/* INPUTS     : o Module Id                                         */
/*              o Slice                                             */
/*              o Protocol                                          */
/*              o Timing Mode                                       */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Configures the 65nm Multirate SERDES Analog Settings.            */
/*                                                                  */
/* [slice]  Specified as TEN_SLICE0 (0), TEN_SLICE1 (1),            */
/*   TEN_SLICE2 (2), TEN_SLICE3 (3) or TEN_SLICE_ALL (0xFF)         */
/*                                                                  */
/* [protocol]  parameter is specified as:                           */
/*   TEN_HSIF_PROTOCOL_DISABLED  = 0                                */
/*   TEN_HSIF_PROTOCOL_SFI51     = 1                                */
/*   TEN_HSIF_PROTOCOL_SFI41     = 2                                */
/*   TEN_HSIF_PROTOCOL_SFI42_10G = 4                                */
/*   TEN_HSIF_PROTOCOL_SFI42_40G = 5                                */
/*   TEN_HSIF_PROTOCOL_XAUI      = 6                                */
/*                                                                  */
/* [timing_mode]  parameter is specified as:                        */
/*   TEN_HSIF_TIMING_MODE_LOCAL = 0                                 */
/*   TEN_HSIF_TIMING_MODE_LINE  = 1                                 */
/*   TEN_HSIF_TIMING_MODE_LOCAL_MR_PROTECT  = 2                     */
/*                                                                  */
/* NOTE:  For XFI Programming, see ten_hl_hsif_xfi_analog_cfg.      */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  cs_status ret_val           = CS_OK;
  cs_uint16 srx_phsel         = 0;
  cs_uint16 srx_cpcur         = 0;
  cs_uint16 srx_filtr         = 0;
  cs_uint16 stxp_cpcur        = 0;
  cs_uint16 stxp_filtr        = 0;
  cs_uint16 srx_eqadj         = 0;
  cs_uint16 stx_level         = 0;
 /* bugzilla #24261, handle THRES and VCOMAX in ten_hl_hsif_mr_ring_oscillator_fix   */
 /* bugzilla #24278, do not set redundant registers already set in hsif config APIS, */
 /*                  and update fine tuning settings from R2.05                      */
 
  CS_PRINT("ten_hl_hsif_analog_cfg: mod_id=%04X, slice=%d, prot=%d, timing_mode=%d\n",
           module_id, slice, protocol, timing_mode);
  
  switch (protocol) {
  case (TEN_HSIF_PROTOCOL_SFI51):
    CS_PRINT("SFI5.1\n");

    /*  # 6.4.4 2.48832Gb/s SFI5.1 line/local timing mode (8bit only)*/
    /*  (155.52MHz Reference/Pilot from SERDES_SFI5_REFCLK65nm,      */
    /*  622.08MHz into SFI5CKREFP/N)                                 */
    srx_phsel        = 0x0020;    /* SRX[]_PHSEL        = b100000    */
    srx_eqadj        = 0x000F;    /* SRX[]_EQADJ        = b1111      */
    /* Bugzilla #27593, TX level off during protection switching setup */
    if (timing_mode == TEN_HSIF_TIMING_MODE_LOCAL_MR_PROTECT) {
      stx_level      = 0;
    }
    else {
      stx_level      = 0x0030;    /* STX[]_LEVEL        = b110000    */
    }
    srx_cpcur        = 0x0003;    /* SRX[]_CPCUR        = b0011      */
    srx_filtr        = 0x0003;    /* SRX[]_FILTR        = b0011      */
    stxp_cpcur       = 0x0003;    /* STXP[]_CPCUR       = b011       */
    stxp_filtr       = 0x0007;    /* STXP[]_FILTR       = b0111      */
    /* bugzilla #24261, handle THRES and VCOMAX in ten_hl_hsif_mr_ring_oscillator_fix */
    break;

  case (TEN_HSIF_PROTOCOL_SFI42_10G):

    if (timing_mode == TEN_HSIF_TIMING_MODE_LOCAL) {
      CS_PRINT("SFI4.2 10G (local timing mode)\n");

      /*  # 6.4.2 2.56608Gb/s SFI4.2 local timing mode (77.76MHz ref)  */
      /*                                                               */
      srx_phsel        = 0x0020;    /* SRX[]_PHSEL        = b100000    */
      srx_eqadj        = 0x000F;    /* SRX[]_EQADJ        = b1111      */
      /* Bugzilla #27593, TX level off during protection switching setup */
      if (timing_mode == TEN_HSIF_TIMING_MODE_LOCAL_MR_PROTECT) {
        stx_level      = 0;
      } 
      else {
        stx_level      = 0x0030;    /* STX[]_LEVEL        = b110000    */
      }
      srx_cpcur        = 0x0003;    /* SRX[]_CPCUR        = b0011      */
      srx_filtr        = 0x0003;    /* SRX[]_FILTR        = b0011      */
      stxp_cpcur       = 0x0007;    /* STXP[]_CPCUR       = b111       */
      stxp_filtr       = 0x0007;    /* STXP[]_FILTR       = b0111      */
      /* bugzilla #24261, handle THRES and VCOMAX in ten_hl_hsif_mr_ring_oscillator_fix */
    }
    else
    {
      CS_PRINT("SFI4.2 10G (line timing mode)\n");

      /*  # 6.4.3 2.56608Gb/s SFI4.2 line timing mode (77.76MHz ref)  */
      srx_phsel        = 0x0020;    /* SRX[]_PHSEL        = b100000    */
      srx_eqadj        = 0x000F;    /* SRX[]_EQADJ        = b1111      */
      /* Bugzilla #27593, TX level off during protection switching setup */
      if (timing_mode == TEN_HSIF_TIMING_MODE_LOCAL_MR_PROTECT) {
        stx_level      = 0;
      }
      else {
        stx_level        = 0x0030;    /* STX[]_LEVEL        = b110000    */
      }
      srx_cpcur        = 0x0003;    /* SRX[]_CPCUR        = b0011      */
      srx_filtr        = 0x0003;    /* SRX[]_FILTR        = b0011      */
      stxp_cpcur       = 0x0007;    /* STXP[]_CPCUR       = b111       */
      stxp_filtr       = 0x0007;    /* STXP[]_FILTR       = b0111      */
      /* bugzilla #24261, handle THRES and VCOMAX in ten_hl_hsif_mr_ring_oscillator_fix */
    }
    break;

  case (TEN_HSIF_PROTOCOL_SFI42_40G):
    CS_PRINT("SFI4.2 40G\n");

    /*  # 6.4.5 2.56608Gb/s SFI4.2-40G line/local timing mode (10bit)*/
    /*  # (77.76MHz Reference-pad/Frac-n-Pilot from SERDES_SFI5_REFCLK65nm)*/
    /*                                                              */
    
    srx_phsel        = 0x0020;    /* SRX[]_PHSEL        = b100000    */
    srx_eqadj        = 0x000F;    /* SRX[]_EQADJ        = b1111      */
    /* Bugzilla #27593, TX level off during protection switching setup */
    if (timing_mode == TEN_HSIF_TIMING_MODE_LOCAL_MR_PROTECT) {
      stx_level      = 0;
    }
    else {
      stx_level      = 0x0030;    /* STX[]_LEVEL        = b110000    */
    }
    srx_cpcur        = 0x0003;    /* SRX[]_CPCUR        = b0011      */
    srx_filtr        = 0x0003;    /* SRX[]_FILTR        = b0011      */
    stxp_cpcur       = 0x0007;    /* STXP[]_CPCUR       = b111       */
    stxp_filtr       = 0x0007;    /* STXP[]_FILTR       = b0111      */
    /* bugzilla #24261, handle THRES and VCOMAX in ten_hl_hsif_mr_ring_oscillator_fix */
    break;

  case (TEN_HSIF_PROTOCOL_XAUI):
    CS_PRINT("TEN_HSIF_PROTOCOL_XAUI\n");

    /*  # 6.4.1 3.125Gb/s XAUI (156.25MHz ref)                       */
    /*                                                               */
    srx_phsel        = 0x0020;    /* SRX[]_PHSEL        = b011111    */
    srx_eqadj        = 0x000F;    /* SRX[]_EQADJ        = b1111      */
    /* Bugzilla #27593, TX level off during protection switching setup */
    if (timing_mode == TEN_HSIF_TIMING_MODE_LOCAL_MR_PROTECT) {
      stx_level      = 0;
    }
    else {
      stx_level      = 0x0030;    /* STX[]_LEVEL        = b11000     */
    }
    srx_cpcur        = 0x0003;    /* SRX[]_CPCUR        = b0011      */
    srx_filtr        = 0x0003;    /* SRX[]_FILTR        = b0011      */
    stxp_cpcur       = 0x0003;    /* STXP[]_CPCUR       = b011       */
    stxp_filtr       = 0x0007;    /* STXP[]_FILTR       = b0111      */
    /* bugzilla #24261, handle THRES and VCOMAX in ten_hl_hsif_mr_ring_oscillator_fix */
    break;

  default:
    CS_PRINT("Unsupported protocol selection!\n");
    ret_val = CS_ERROR;
    goto RTN_EXIT;
    break;
  }

  CS_PRINT("Provision HSIF analog...\n");

  if ((slice == TEN_SLICE0) || (slice == TEN_SLICE_ALL)) {

    ten_hsif_slc0_mr10x4_sds_common_srx0_rx_loop_filter(module_id,
                                                        TEN_INSTANCE_ALL, srx_filtr);

    ten_hsif_slc0_mr10x4_sds_common_srx0_rx_cpa(module_id,
                                                TEN_INSTANCE_ALL, srx_cpcur, srx_cpcur);

    ten_hsif_slc0_mr10x4_sds_common_srx0_rx_cpb(module_id, TEN_INSTANCE_ALL, srx_phsel);

    ten_hsif_slc0_mr10x4_sds_common_srx0_rx_misc(module_id, TEN_INSTANCE_ALL, srx_eqadj);

    /* bugzilla #24261, handle THRES and VCOMAX in ten_hl_hsif_mr_ring_oscillator_fix */

    ten_hsif_slc0_mr10x4_sds_common_stx0_tx_output_ctrla(module_id,
                                                         TEN_INSTANCE_ALL, stx_level);

    ten_hsif_slc0_mr10x4_sds_common_stxp0_tx_loop_filter(module_id, stxp_filtr);

    ten_hsif_slc0_mr10x4_sds_common_stxp0_tx_cp(module_id, stxp_cpcur, stxp_cpcur);
    /* bugzilla #24261, handle THRES and VCOMAX in ten_hl_hsif_mr_ring_oscillator_fix */
    
    ten_hsif_set_slc0_mr10x4_rxlockd0_data_lock(module_id, TEN_INSTANCE_ALL, 0);
  }
  /* Bugzilla #27277, allow TEN_SLICE_ALL parameter */
  if ((slice == TEN_SLICE2) || (slice == TEN_SLICE_ALL)) {

    ten_hsif_slc2_mr10x4_sds_common_srx0_rx_loop_filter(module_id,
                                                        TEN_INSTANCE_ALL, srx_filtr);

    ten_hsif_slc2_mr10x4_sds_common_srx0_rx_cpa(module_id,
                                                TEN_INSTANCE_ALL, srx_cpcur, srx_cpcur);

    ten_hsif_slc2_mr10x4_sds_common_srx0_rx_cpb(module_id, TEN_INSTANCE_ALL, srx_phsel);

    ten_hsif_slc2_mr10x4_sds_common_srx0_rx_misc(module_id, TEN_INSTANCE_ALL, srx_eqadj);

    /* bugzilla #24261, handle THRES and VCOMAX in ten_hl_hsif_mr_ring_oscillator_fix */

    ten_hsif_slc2_mr10x4_sds_common_stx0_tx_output_ctrla(module_id,
                                                         TEN_INSTANCE_ALL, stx_level);

    ten_hsif_slc2_mr10x4_sds_common_stxp0_tx_loop_filter(module_id, stxp_filtr);

    ten_hsif_slc2_mr10x4_sds_common_stxp0_tx_cp(module_id, stxp_cpcur, stxp_cpcur);

    /* bugzilla #24261, handle THRES and VCOMAX in ten_hl_hsif_mr_ring_oscillator_fix */
    
    ten_hsif_set_slc2_mr10x4_rxlockd0_data_lock(module_id, TEN_INSTANCE_ALL, 0);
  }
  
  if ((slice == TEN_SLICE1) || (slice == TEN_SLICE_ALL)) {

    ten_hsif_slc1_mr10x5_sds_common_srx0_rx_loop_filter(module_id,
                                                        TEN_INSTANCE_ALL, srx_filtr);

    ten_hsif_slc1_mr10x5_sds_common_srx0_rx_cpa(module_id,
                                                TEN_INSTANCE_ALL, srx_cpcur, srx_cpcur);

    ten_hsif_slc1_mr10x5_sds_common_srx0_rx_cpb(module_id, TEN_INSTANCE_ALL, srx_phsel);

    ten_hsif_slc1_mr10x5_sds_common_srx0_rx_misc(module_id, TEN_INSTANCE_ALL, srx_eqadj);

    /* bugzilla #24261, handle THRES and VCOMAX in ten_hl_hsif_mr_ring_oscillator_fix */

    ten_hsif_slc1_mr10x5_sds_common_stx0_tx_output_ctrla(module_id,
                                                         TEN_INSTANCE_ALL, stx_level);

    ten_hsif_slc1_mr10x5_sds_common_stxp0_tx_loop_filter(module_id, stxp_filtr);

    ten_hsif_slc1_mr10x5_sds_common_stxp0_tx_cp(module_id, stxp_cpcur, stxp_cpcur);

    /* bugzilla #24261, handle THRES and VCOMAX in ten_hl_hsif_mr_ring_oscillator_fix */
    ten_hsif_set_slc1_mr10x5_rxlockd0_data_lock(module_id, TEN_INSTANCE_ALL, 0);
  }
  
  if ((slice == TEN_SLICE3) || (slice == TEN_SLICE_ALL)) {

    ten_hsif_slc3_mr10x5_sds_common_srx0_rx_loop_filter(module_id,
                                                        TEN_INSTANCE_ALL, srx_filtr);

    ten_hsif_slc3_mr10x5_sds_common_srx0_rx_cpa(module_id,
                                                TEN_INSTANCE_ALL, srx_cpcur, srx_cpcur);

    ten_hsif_slc3_mr10x5_sds_common_srx0_rx_cpb(module_id, TEN_INSTANCE_ALL, srx_phsel);

    ten_hsif_slc3_mr10x5_sds_common_srx0_rx_misc(module_id, TEN_INSTANCE_ALL, srx_eqadj);

    /* bugzilla #24261, handle THRES and VCOMAX in ten_hl_hsif_mr_ring_oscillator_fix */

    ten_hsif_slc3_mr10x5_sds_common_stx0_tx_output_ctrla(module_id,
                                                         TEN_INSTANCE_ALL, stx_level);

    ten_hsif_slc3_mr10x5_sds_common_stxp0_tx_loop_filter(module_id, stxp_filtr);

    ten_hsif_slc3_mr10x5_sds_common_stxp0_tx_cp(module_id, stxp_cpcur, stxp_cpcur);

    /* bugzilla #24261, handle THRES and VCOMAX in ten_hl_hsif_mr_ring_oscillator_fix */
    ten_hsif_set_slc3_mr10x5_rxlockd0_data_lock(module_id, TEN_INSTANCE_ALL, 0);
  }

  CS_PRINT("HSIF Analog Configuration Complete.\n");

RTN_EXIT:
  return (ret_val);
}

/********************************************************************/
/* $rtn_hdr_start  HIGH LEVEL HSIF XFI ANALOG CONFIG                */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : HIGH LEVEL                                          */
/* CHIP       : Tenabo                                              */
cs_status ten_hl_hsif_xfi_analog_cfg(cs_uint16 module_id,
                          cs_uint8 slice,
                          cs_uint16 rate,
                          cs_uint16 div)
/* INPUTS     : o Module Id                                         */
/*              o Slice                                             */
/*              o Rate                                              */
/*              o Divided By Reference                              */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Provides a high level analog configuration of the XFI.           */
/*                                                                  */
/* [slice]  Specified as TEN_SLICE0 (0), TEN_SLICE1 (1),            */
/*   TEN_SLICE2 (2), TEN_SLICE3 (3) or TEN_SLICE_ALL (0xFF)         */
/*                                                                  */
/* [rate]  Specified as:  (supported div values)                    */
/*  TEN_HSIF_XFI_RATE_GBPS_9__95_TO_12__5  = 0,  Full Rate,         */
/*  TEN_HSIF_XFI_RATE_GBPS_4__97_TO_6__25  = 1,  1/2 Rate,          */
/*  TEN_HSIF_XFI_RATE_GBPS_2__48_TO_3__125 = 2,  1/4 Rate,          */
/*  TEN_HSIF_XFI_RATE_GBPS_1__24_TO_1__56  = 3,  1/8 Rate,          */
/*  TEN_HSIF_XFI_RATE_GBPS_8__5_FC         = 4,  Full Rate,         */
/*  TEN_HSIF_XFI_RATE_GBPS_4__25_FC        = 5,  1/2 Rate,          */
/*  TEN_HSIF_XFI_RATE_GBPS_2__125_FC       = 6,  1/4 Rate,          */
/*  TEN_HSIF_XFI_RATE_GBPS_1__0625_FC      = 7,  1/8 Rate,          */
/*  TEN_HSIF_XFI_RATE_GBPS_9__95328        = 8,  Full Rate,         */
/*  TEN_HSIF_XFI_RATE_GBPS_10__3125        = 9,  Full Rate,         */
/*  TEN_HSIF_XFI_RATE_GBPS_10__52          = 10, Full Rate,         */
/*  TEN_HSIF_XFI_RATE_GBPS_10__70          = 11, Full Rate,         */
/*  TEN_HSIF_XFI_RATE_GBPS_11__1           = 12, Full Rate,         */
/*  TEN_HSIF_XFI_RATE_GBPS_11__3           = 13, Full Rate,         */
/*  TEN_HSIF_XFI_RATE_GBPS_11__7           = 14, Full Rate,         */
/*  TEN_HSIF_XFI_RATE_GBPS_12__5           = 15  Full Rate,         */
/*  TEN_HSIF_XFI_RATE_GBPS_5_IB            = 16, 1/2 Rate,          */
/*  TEN_HSIF_XFI_RATE_GBPS_10_IB           = 17, Full Rate,         */
/*                                                                  */
/* [div]  Specified as:                                             */
/*  TEN_HSIF_XFI_DIV_BY_16_REF          = 0,                        */
/*  TEN_HSIF_XFI_DIV_BY_40_REF          = 1,                        */
/*  TEN_HSIF_XFI_DIV_BY_64_REF          = 2,                        */
/*  TEN_HSIF_XFI_DIV_BY_80_REF          = 3                         */
/*  TEN_HSIF_XFI_DIV_BY_16_AUX_LPTM_REF = 4,                        */
/*  TEN_HSIF_XFI_DIV_BY_40_AUX_LPTM_REF = 5,                        */
/*  TEN_HSIF_XFI_DIV_BY_64_AUX_LPTM_REF = 6,                        */
/*  TEN_HSIF_XFI_DIV_BY_80_AUX_LPTM_REF = 7,                        */
/*  TEN_HSIF_XFI_DIV_BY_32_REF          = 8,                        */
/*  TEN_HSIF_XFI_DIV_BY_66_REF          = 9,                        */
/*  TEN_HSIF_XFI_DIV_BY_32_AUX_LPTM_REF = 10,                       */
/*  TEN_HSIF_XFI_DIV_BY_66_AUX_LPTM_REF = 11.                       */
/*                                                                  */
/* NOTE:  XFI operations are available for Module B only.           */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  cs_status rtn = CS_OK;
  cs_uint16 xfi_analog_cfg = 1;
  
  /* initialize default values */
  cs_uint16 tmp_srx0_rx_clkdiv_ctrl_ctvdiv_sel = 0;
  cs_uint16 tmp_srx0_rx_clkdiv_ctrl_ddiv_sel = 0;
  cs_uint16 tmp_srx0_rx_clkdiv_ctrl_rdiv_sel = 2;
  cs_uint16 tmp_srx0_rx_config_fcen = 0;
  cs_uint16 tmp_stxp0_tx_clkdiv_ctrl_ctr_div = 0;
  cs_uint16 tmp_stxp0_tx_clkdiv_ctrl_ctv_div = 0;
  cs_uint16 tmp_stxp0_tx_clkdiv_ctrl_ddiv_sel = 0;
  cs_uint16 tmp_stxp0_tx_clkdiv_ctrl_rdiv_sel = 2;
  cs_uint16 tmp_stxp0_tx_config_fcen = 0;
  cs_uint16 tmp_stxp0_tx_config_pilot_sel = 0;
  /* Bugzilla 35199 Start */
  cs_uint16 tmp_stxp0_tx_spare = 0xD0;
  /* Bugzilla 35199 End */

  CS_PRINT("ten_hl_hsif_xfi_analog_cfg, mod=0x%04X, slice=%d, rate=%d, div=%d\n", 
            module_id, slice, rate, div);

  if (TEN_MOD_ID_TO_MOD_NUM(module_id) != TEN_MODULE_B) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": XFI only on Module B.");
    return (CS_ERROR);
  }

  /* Bugzilla #23872, add other divs, need 16,32,40,64,66 and 80 */
  if ((div == TEN_HSIF_XFI_DIV_BY_16_AUX_LPTM_REF) ||
      (div == TEN_HSIF_XFI_DIV_BY_32_AUX_LPTM_REF) ||
      (div == TEN_HSIF_XFI_DIV_BY_40_AUX_LPTM_REF) ||
      (div == TEN_HSIF_XFI_DIV_BY_64_AUX_LPTM_REF) ||
      (div == TEN_HSIF_XFI_DIV_BY_66_AUX_LPTM_REF) ||
      (div == TEN_HSIF_XFI_DIV_BY_80_AUX_LPTM_REF)) {
    tmp_stxp0_tx_config_pilot_sel = 1;
  }
  else {
    /* Bug #37397 - Clock bring-up sequence for 40G XFI clients with external CUPLL */
    /* can create microcode download issues */
    tmp_stxp0_tx_config_pilot_sel = 1;
  }

  switch (div) {
  case (TEN_HSIF_XFI_DIV_BY_16_REF):
    CS_PRINT("TEN_HSIF_XFI_DIV_BY_16\n");
    break;

  case (TEN_HSIF_XFI_DIV_BY_32_REF):
    CS_PRINT("TEN_HSIF_XFI_DIV_BY_32\n");
    break;

  case (TEN_HSIF_XFI_DIV_BY_40_REF):
    CS_PRINT("(TEN_HSIF_XFI_DIV_BY_40\n");
    break;
  
  case (TEN_HSIF_XFI_DIV_BY_64_REF):
    CS_PRINT("TEN_HSIF_XFI_DIV_BY_64\n");
    break;
  
  case (TEN_HSIF_XFI_DIV_BY_66_REF):
    CS_PRINT("TEN_HSIF_XFI_DIV_BY_66\n");
    break;

  case (TEN_HSIF_XFI_DIV_BY_80_REF):
    CS_PRINT("TEN_HSIF_XFI_DIV_BY_80\n");
    break;

  case (TEN_HSIF_XFI_DIV_BY_16_AUX_LPTM_REF):
    CS_PRINT("TEN_HSIF_XFI_DIV_BY_16_AUX_LPTM_REF\n");
    break;

  case (TEN_HSIF_XFI_DIV_BY_32_AUX_LPTM_REF):
    CS_PRINT("TEN_HSIF_XFI_DIV_BY_32_AUX_LPTM_REF\n");
    break;

  case (TEN_HSIF_XFI_DIV_BY_40_AUX_LPTM_REF):
    CS_PRINT("TEN_HSIF_XFI_DIV_BY_40_AUX_LPTM_REF\n");
    break;

  case (TEN_HSIF_XFI_DIV_BY_64_AUX_LPTM_REF):
    CS_PRINT("TEN_HSIF_XFI_DIV_BY_64_AUX_LPTM_REF\n");
    break;

  case (TEN_HSIF_XFI_DIV_BY_66_AUX_LPTM_REF):
    CS_PRINT("TEN_HSIF_XFI_DIV_BY_66_AUX_LPTM_REF\n");
    break;

  case (TEN_HSIF_XFI_DIV_BY_80_AUX_LPTM_REF):
    CS_PRINT("TEN_HSIF_XFI_DIV_BY_80_AUX_LPTM_REF\n");
    break;
    
  default:
    CS_PRINT("ERROR: Invalid TEN_HSIF_XFI_DIV\n");
    break;
  } 
  
  switch (rate) {

  case (TEN_HSIF_XFI_RATE_GBPS_9__95328):
  case (TEN_HSIF_XFI_RATE_GBPS_10__3125):
  case (TEN_HSIF_XFI_RATE_GBPS_10__52):
  case (TEN_HSIF_XFI_RATE_GBPS_10__70):
  case (TEN_HSIF_XFI_RATE_GBPS_11__1):
  case (TEN_HSIF_XFI_RATE_GBPS_11__3):
  case (TEN_HSIF_XFI_RATE_GBPS_11__7):
  case (TEN_HSIF_XFI_RATE_GBPS_12__5):
  case (TEN_HSIF_XFI_RATE_GBPS_9__95_TO_12__5):
  case (TEN_HSIF_XFI_RATE_GBPS_10_IB):
    if ((div == TEN_HSIF_XFI_DIV_BY_16_REF) || (div == TEN_HSIF_XFI_DIV_BY_16_AUX_LPTM_REF)) {
      tmp_srx0_rx_clkdiv_ctrl_rdiv_sel = 0;
      tmp_srx0_rx_clkdiv_ctrl_ctvdiv_sel = 2;
      tmp_stxp0_tx_clkdiv_ctrl_rdiv_sel = 0;
      tmp_stxp0_tx_clkdiv_ctrl_ctr_div = 2;
      tmp_stxp0_tx_clkdiv_ctrl_ctv_div = 2;
      
      tmp_srx0_rx_clkdiv_ctrl_ddiv_sel = 0;
      tmp_srx0_rx_config_fcen = 0;
      tmp_stxp0_tx_clkdiv_ctrl_ddiv_sel = 0;
      tmp_stxp0_tx_config_fcen = 0;
      /* Bugzilla 35199 Start */
      tmp_stxp0_tx_spare = 0x00D0;
      /* Bugzilla 35199 End */
    }
    else if ((div == TEN_HSIF_XFI_DIV_BY_64_REF) || (div == TEN_HSIF_XFI_DIV_BY_64_AUX_LPTM_REF)) {
      tmp_srx0_rx_clkdiv_ctrl_rdiv_sel = 2;
      tmp_srx0_rx_clkdiv_ctrl_ctvdiv_sel = 0;
      tmp_stxp0_tx_clkdiv_ctrl_rdiv_sel = 2;
      tmp_stxp0_tx_clkdiv_ctrl_ctr_div = 0;
      tmp_stxp0_tx_clkdiv_ctrl_ctv_div = 0;

      tmp_srx0_rx_clkdiv_ctrl_ddiv_sel = 0;
      tmp_srx0_rx_config_fcen = 0;
      tmp_stxp0_tx_clkdiv_ctrl_ddiv_sel = 0;
      tmp_stxp0_tx_config_fcen = 0;
      /* Bugzilla 35199 Start */
      tmp_stxp0_tx_spare = 0x00D0;
      /* Bugzilla 35199 End */
    }
    else if ((div == TEN_HSIF_XFI_DIV_BY_32_REF) || (div == TEN_HSIF_XFI_DIV_BY_32_AUX_LPTM_REF)) {
      tmp_srx0_rx_clkdiv_ctrl_rdiv_sel = 1;
      tmp_srx0_rx_clkdiv_ctrl_ctvdiv_sel = 1;
      tmp_stxp0_tx_clkdiv_ctrl_rdiv_sel = 1;
      tmp_stxp0_tx_clkdiv_ctrl_ctr_div = 1;
      tmp_stxp0_tx_clkdiv_ctrl_ctv_div = 1;

      tmp_srx0_rx_clkdiv_ctrl_ddiv_sel = 0;
      tmp_srx0_rx_config_fcen = 0;
      tmp_stxp0_tx_clkdiv_ctrl_ddiv_sel = 0;
      tmp_stxp0_tx_config_fcen = 0;
      /* Bugzilla 35199 Start */
      tmp_stxp0_tx_spare = 0x00D0;
      /* Bugzilla 35199 End */
    }
    else if ((div == TEN_HSIF_XFI_DIV_BY_40_REF) || (div == TEN_HSIF_XFI_DIV_BY_40_AUX_LPTM_REF)) {
      tmp_srx0_rx_clkdiv_ctrl_rdiv_sel = 4;
      tmp_srx0_rx_clkdiv_ctrl_ctvdiv_sel = 1;
      tmp_stxp0_tx_clkdiv_ctrl_rdiv_sel = 4;
      tmp_stxp0_tx_clkdiv_ctrl_ctr_div = 1;
      tmp_stxp0_tx_clkdiv_ctrl_ctv_div = 1;

      tmp_srx0_rx_clkdiv_ctrl_ddiv_sel = 0;
      tmp_srx0_rx_config_fcen = 0;
      tmp_stxp0_tx_clkdiv_ctrl_ddiv_sel = 0;
      tmp_stxp0_tx_config_fcen = 0;
      /* Bugzilla 35199 Start */
      tmp_stxp0_tx_spare = 0x00D0;
      /* Bugzilla 35199 End */
    }
    else if ((div == TEN_HSIF_XFI_DIV_BY_66_REF) || (div == TEN_HSIF_XFI_DIV_BY_66_AUX_LPTM_REF)) {
      tmp_srx0_rx_clkdiv_ctrl_rdiv_sel = 3;
      tmp_srx0_rx_clkdiv_ctrl_ctvdiv_sel = 0;
      tmp_stxp0_tx_clkdiv_ctrl_rdiv_sel = 3;
      tmp_stxp0_tx_clkdiv_ctrl_ctr_div = 0;
      tmp_stxp0_tx_clkdiv_ctrl_ctv_div = 0;

      tmp_srx0_rx_clkdiv_ctrl_ddiv_sel = 0;
      tmp_srx0_rx_config_fcen = 0;
      tmp_stxp0_tx_clkdiv_ctrl_ddiv_sel = 0;
      tmp_stxp0_tx_config_fcen = 0;
      /* Bugzilla 35199 Start */
      tmp_stxp0_tx_spare = 0x00D0;
      /* Bugzilla 35199 End */
    }
    else if ((div == TEN_HSIF_XFI_DIV_BY_80_REF) || (div == TEN_HSIF_XFI_DIV_BY_80_AUX_LPTM_REF)) {
      tmp_srx0_rx_clkdiv_ctrl_rdiv_sel = 5;
      tmp_srx0_rx_clkdiv_ctrl_ctvdiv_sel = 0;
      tmp_stxp0_tx_clkdiv_ctrl_rdiv_sel = 5;
      tmp_stxp0_tx_clkdiv_ctrl_ctr_div = 0;
      tmp_stxp0_tx_clkdiv_ctrl_ctv_div = 0;

      tmp_srx0_rx_clkdiv_ctrl_ddiv_sel = 0;
      tmp_srx0_rx_config_fcen = 0;
      tmp_stxp0_tx_clkdiv_ctrl_ddiv_sel = 0;
      tmp_stxp0_tx_config_fcen = 0;
      /* Bugzilla 35199 Start */
      tmp_stxp0_tx_spare = 0x00D0;
      /* Bugzilla 35199 End */
    }
    else {
      xfi_analog_cfg = 0;
      CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG,
                      ": XFI - this divided by reference is unsupported.");
    }
    break;

  case (TEN_HSIF_XFI_RATE_GBPS_5_IB):
  case (TEN_HSIF_XFI_RATE_GBPS_4__97_TO_6__25):
      if ((div == TEN_HSIF_XFI_DIV_BY_16_REF) || (div == TEN_HSIF_XFI_DIV_BY_16_AUX_LPTM_REF)) {
      tmp_srx0_rx_clkdiv_ctrl_rdiv_sel = 0;
      tmp_srx0_rx_clkdiv_ctrl_ctvdiv_sel = 2;
      tmp_stxp0_tx_clkdiv_ctrl_rdiv_sel = 0;
      tmp_stxp0_tx_clkdiv_ctrl_ctr_div = 2;
      tmp_stxp0_tx_clkdiv_ctrl_ctv_div = 2;
      
      tmp_srx0_rx_clkdiv_ctrl_ddiv_sel = 1;
      tmp_srx0_rx_config_fcen = 0;
      tmp_stxp0_tx_clkdiv_ctrl_ddiv_sel = 1;
      tmp_stxp0_tx_config_fcen = 0;
      /* Bugzilla 35199 Start */
      tmp_stxp0_tx_spare = 0x00D4;
      /* Bugzilla 35199 End */
    }
    else if ((div == TEN_HSIF_XFI_DIV_BY_64_REF) || (div == TEN_HSIF_XFI_DIV_BY_64_AUX_LPTM_REF)) {
      tmp_srx0_rx_clkdiv_ctrl_rdiv_sel = 2;
      tmp_srx0_rx_clkdiv_ctrl_ctvdiv_sel = 0;
      tmp_stxp0_tx_clkdiv_ctrl_rdiv_sel = 2;
      tmp_stxp0_tx_clkdiv_ctrl_ctr_div = 0;
      tmp_stxp0_tx_clkdiv_ctrl_ctv_div = 0;

      tmp_srx0_rx_clkdiv_ctrl_ddiv_sel = 1;
      tmp_srx0_rx_config_fcen = 0;
      tmp_stxp0_tx_clkdiv_ctrl_ddiv_sel = 1;
      tmp_stxp0_tx_config_fcen = 0;
      /* Bugzilla 35199 Start */
      tmp_stxp0_tx_spare = 0x00D4;
      /* Bugzilla 35199 End */
    }
    else if ((div == TEN_HSIF_XFI_DIV_BY_32_REF) || (div == TEN_HSIF_XFI_DIV_BY_32_AUX_LPTM_REF)) {
      tmp_srx0_rx_clkdiv_ctrl_rdiv_sel = 1;
      tmp_srx0_rx_clkdiv_ctrl_ctvdiv_sel = 1;
      tmp_stxp0_tx_clkdiv_ctrl_rdiv_sel = 1;
      tmp_stxp0_tx_clkdiv_ctrl_ctr_div = 1;
      tmp_stxp0_tx_clkdiv_ctrl_ctv_div = 1;

      tmp_srx0_rx_clkdiv_ctrl_ddiv_sel = 1;
      tmp_srx0_rx_config_fcen = 0;
      tmp_stxp0_tx_clkdiv_ctrl_ddiv_sel = 1;
      tmp_stxp0_tx_config_fcen = 0;
      /* Bugzilla 35199 Start */
      tmp_stxp0_tx_spare = 0x00D4;
      /* Bugzilla 35199 End */
    }
    else if ((div == TEN_HSIF_XFI_DIV_BY_40_REF) || (div == TEN_HSIF_XFI_DIV_BY_40_AUX_LPTM_REF)) {
      tmp_srx0_rx_clkdiv_ctrl_rdiv_sel = 4;
      tmp_srx0_rx_clkdiv_ctrl_ctvdiv_sel = 1;
      tmp_stxp0_tx_clkdiv_ctrl_rdiv_sel = 4;
      tmp_stxp0_tx_clkdiv_ctrl_ctr_div = 1;
      tmp_stxp0_tx_clkdiv_ctrl_ctv_div = 1;

      tmp_srx0_rx_clkdiv_ctrl_ddiv_sel = 1;
      tmp_srx0_rx_config_fcen = 0;
      tmp_stxp0_tx_clkdiv_ctrl_ddiv_sel = 1;
      tmp_stxp0_tx_config_fcen = 0;
      /* Bugzilla 35199 Start */
      tmp_stxp0_tx_spare = 0x00D4;
      /* Bugzilla 35199 End */
    }
    else if ((div == TEN_HSIF_XFI_DIV_BY_66_REF) || (div == TEN_HSIF_XFI_DIV_BY_66_AUX_LPTM_REF)) {
      tmp_srx0_rx_clkdiv_ctrl_rdiv_sel = 3;
      tmp_srx0_rx_clkdiv_ctrl_ctvdiv_sel = 0;
      tmp_stxp0_tx_clkdiv_ctrl_rdiv_sel = 3;
      tmp_stxp0_tx_clkdiv_ctrl_ctr_div = 0;
      tmp_stxp0_tx_clkdiv_ctrl_ctv_div = 0;
      
      tmp_srx0_rx_clkdiv_ctrl_ddiv_sel = 1;
      tmp_srx0_rx_config_fcen = 0;
      tmp_stxp0_tx_clkdiv_ctrl_ddiv_sel = 1;
      tmp_stxp0_tx_config_fcen = 0;
      /* Bugzilla 35199 Start */
      tmp_stxp0_tx_spare = 0x00D4;
      /* Bugzilla 35199 End */
    }
    else if ((div == TEN_HSIF_XFI_DIV_BY_80_REF) || (div == TEN_HSIF_XFI_DIV_BY_80_AUX_LPTM_REF)) {
      tmp_srx0_rx_clkdiv_ctrl_rdiv_sel = 5;
      tmp_srx0_rx_clkdiv_ctrl_ctvdiv_sel = 0;
      tmp_stxp0_tx_clkdiv_ctrl_rdiv_sel = 5;
      tmp_stxp0_tx_clkdiv_ctrl_ctr_div = 0;
      tmp_stxp0_tx_clkdiv_ctrl_ctv_div = 0;

      tmp_srx0_rx_clkdiv_ctrl_ddiv_sel = 1;
      tmp_srx0_rx_config_fcen = 0;
      tmp_stxp0_tx_clkdiv_ctrl_ddiv_sel = 1;
      tmp_stxp0_tx_config_fcen = 0;
      /* Bugzilla 35199 Start */
      tmp_stxp0_tx_spare = 0x00D4;
      /* Bugzilla 35199 End */
    }
    else {
      xfi_analog_cfg = 0;
      CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG,
                      ": XFI - this divided by reference is unsupported.");
    }
    break;
  
  case (TEN_HSIF_XFI_RATE_GBPS_2__48_TO_3__125):
    if ((div == TEN_HSIF_XFI_DIV_BY_16_REF) || (div == TEN_HSIF_XFI_DIV_BY_16_AUX_LPTM_REF)) {
      tmp_srx0_rx_clkdiv_ctrl_rdiv_sel = 0;
      tmp_srx0_rx_clkdiv_ctrl_ctvdiv_sel = 2;
      tmp_stxp0_tx_clkdiv_ctrl_rdiv_sel = 0;
      tmp_stxp0_tx_clkdiv_ctrl_ctr_div = 2;
      tmp_stxp0_tx_clkdiv_ctrl_ctv_div = 2;
      
      tmp_srx0_rx_clkdiv_ctrl_ddiv_sel = 2;
      tmp_srx0_rx_config_fcen = 0;
      tmp_stxp0_tx_clkdiv_ctrl_ddiv_sel = 2;
      tmp_stxp0_tx_config_fcen = 0;
      /* Bugzilla 35199 Start */
      tmp_stxp0_tx_spare = 0x00D4;
      /* Bugzilla 35199 End */
    }
    else if ((div == TEN_HSIF_XFI_DIV_BY_64_REF) || (div == TEN_HSIF_XFI_DIV_BY_64_AUX_LPTM_REF)) {
      tmp_srx0_rx_clkdiv_ctrl_rdiv_sel = 2;
      tmp_srx0_rx_clkdiv_ctrl_ctvdiv_sel = 0;
      tmp_stxp0_tx_clkdiv_ctrl_rdiv_sel = 2;
      tmp_stxp0_tx_clkdiv_ctrl_ctr_div = 0;
      tmp_stxp0_tx_clkdiv_ctrl_ctv_div = 0;

      tmp_srx0_rx_clkdiv_ctrl_ddiv_sel = 2;
      tmp_srx0_rx_config_fcen = 0;
      tmp_stxp0_tx_clkdiv_ctrl_ddiv_sel = 2;
      tmp_stxp0_tx_config_fcen = 0;
      /* Bugzilla 35199 Start */
      tmp_stxp0_tx_spare = 0x00D4;
      /* Bugzilla 35199 End */
    }
    else if ((div == TEN_HSIF_XFI_DIV_BY_32_REF) || (div == TEN_HSIF_XFI_DIV_BY_32_AUX_LPTM_REF)) {
      tmp_srx0_rx_clkdiv_ctrl_rdiv_sel = 1;
      tmp_srx0_rx_clkdiv_ctrl_ctvdiv_sel = 1;
      tmp_stxp0_tx_clkdiv_ctrl_rdiv_sel = 1;
      tmp_stxp0_tx_clkdiv_ctrl_ctr_div = 1;
      tmp_stxp0_tx_clkdiv_ctrl_ctv_div = 1;

      tmp_srx0_rx_clkdiv_ctrl_ddiv_sel = 2;
      tmp_srx0_rx_config_fcen = 0;
      tmp_stxp0_tx_clkdiv_ctrl_ddiv_sel = 2;
      tmp_stxp0_tx_config_fcen = 0;
      /* Bugzilla 35199 Start */
      tmp_stxp0_tx_spare = 0x00D4;
      /* Bugzilla 35199 End */
    }
    else if ((div == TEN_HSIF_XFI_DIV_BY_40_REF) || (div == TEN_HSIF_XFI_DIV_BY_40_AUX_LPTM_REF)) {
      tmp_srx0_rx_clkdiv_ctrl_rdiv_sel = 4;
      tmp_srx0_rx_clkdiv_ctrl_ctvdiv_sel = 1;
      tmp_stxp0_tx_clkdiv_ctrl_rdiv_sel = 4;
      tmp_stxp0_tx_clkdiv_ctrl_ctr_div = 1;
      tmp_stxp0_tx_clkdiv_ctrl_ctv_div = 1;

      tmp_srx0_rx_clkdiv_ctrl_ddiv_sel = 2;
      tmp_srx0_rx_config_fcen = 0;
      tmp_stxp0_tx_clkdiv_ctrl_ddiv_sel = 2;
      tmp_stxp0_tx_config_fcen = 0;
      /* Bugzilla 35199 Start */
      tmp_stxp0_tx_spare = 0x00D4;
      /* Bugzilla 35199 End */
    }
    else if ((div == TEN_HSIF_XFI_DIV_BY_66_REF) || (div == TEN_HSIF_XFI_DIV_BY_66_AUX_LPTM_REF)) {
      tmp_srx0_rx_clkdiv_ctrl_rdiv_sel = 3;
      tmp_srx0_rx_clkdiv_ctrl_ctvdiv_sel = 0;
      tmp_stxp0_tx_clkdiv_ctrl_rdiv_sel = 3;
      tmp_stxp0_tx_clkdiv_ctrl_ctr_div = 0;
      tmp_stxp0_tx_clkdiv_ctrl_ctv_div = 0;

      tmp_srx0_rx_clkdiv_ctrl_ddiv_sel = 2;
      tmp_srx0_rx_config_fcen = 0;
      tmp_stxp0_tx_clkdiv_ctrl_ddiv_sel = 2;
      tmp_stxp0_tx_config_fcen = 0;
      /* Bugzilla 35199 Start */
      tmp_stxp0_tx_spare = 0x00D4;
      /* Bugzilla 35199 End */
    }
    else if ((div == TEN_HSIF_XFI_DIV_BY_80_REF) || (div == TEN_HSIF_XFI_DIV_BY_80_AUX_LPTM_REF)) {
      tmp_srx0_rx_clkdiv_ctrl_rdiv_sel = 5;
      tmp_srx0_rx_clkdiv_ctrl_ctvdiv_sel = 0;
      tmp_stxp0_tx_clkdiv_ctrl_rdiv_sel = 5;
      tmp_stxp0_tx_clkdiv_ctrl_ctr_div = 0;
      tmp_stxp0_tx_clkdiv_ctrl_ctv_div = 0;

      tmp_srx0_rx_clkdiv_ctrl_ddiv_sel = 2;
      tmp_srx0_rx_config_fcen = 0;
      tmp_stxp0_tx_clkdiv_ctrl_ddiv_sel = 2;
      tmp_stxp0_tx_config_fcen = 0;
      /* Bugzilla 35199 Start */
      tmp_stxp0_tx_spare = 0x00D4;
      /* Bugzilla 35199 End */
    }
    else {
      xfi_analog_cfg = 0;
      CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG,
                      ": XFI - this divided by reference is unsupported.");
    }
    break;
  
  case (TEN_HSIF_XFI_RATE_GBPS_1__24_TO_1__56):
     if ((div == TEN_HSIF_XFI_DIV_BY_16_REF) || (div == TEN_HSIF_XFI_DIV_BY_16_AUX_LPTM_REF)) {
      tmp_srx0_rx_clkdiv_ctrl_rdiv_sel = 0;
      tmp_srx0_rx_clkdiv_ctrl_ctvdiv_sel = 2;
      tmp_stxp0_tx_clkdiv_ctrl_rdiv_sel = 0;
      tmp_stxp0_tx_clkdiv_ctrl_ctr_div = 2;
      tmp_stxp0_tx_clkdiv_ctrl_ctv_div = 2;
      
      tmp_srx0_rx_clkdiv_ctrl_ddiv_sel = 3;
      tmp_srx0_rx_config_fcen = 0;
      tmp_stxp0_tx_clkdiv_ctrl_ddiv_sel = 3;
      tmp_stxp0_tx_config_fcen = 0;
      /* Bugzilla 35199 Start */
      tmp_stxp0_tx_spare = 0x00D4;
      /* Bugzilla 35199 End */
    }
    else if ((div == TEN_HSIF_XFI_DIV_BY_64_REF) || (div == TEN_HSIF_XFI_DIV_BY_64_AUX_LPTM_REF)) {
      tmp_srx0_rx_clkdiv_ctrl_rdiv_sel = 2;
      tmp_srx0_rx_clkdiv_ctrl_ctvdiv_sel = 0;
      tmp_stxp0_tx_clkdiv_ctrl_rdiv_sel = 2;
      tmp_stxp0_tx_clkdiv_ctrl_ctr_div = 0;
      tmp_stxp0_tx_clkdiv_ctrl_ctv_div = 0;

      tmp_srx0_rx_clkdiv_ctrl_ddiv_sel = 3;
      tmp_srx0_rx_config_fcen = 0;
      tmp_stxp0_tx_clkdiv_ctrl_ddiv_sel = 3;
      tmp_stxp0_tx_config_fcen = 0;
      /* Bugzilla 35199 Start */
      tmp_stxp0_tx_spare = 0x00D4;
      /* Bugzilla 35199 End */
    }
    else if ((div == TEN_HSIF_XFI_DIV_BY_32_REF) || (div == TEN_HSIF_XFI_DIV_BY_32_AUX_LPTM_REF)) {
      tmp_srx0_rx_clkdiv_ctrl_rdiv_sel = 1;
      tmp_srx0_rx_clkdiv_ctrl_ctvdiv_sel = 1;
      tmp_stxp0_tx_clkdiv_ctrl_rdiv_sel = 1;
      tmp_stxp0_tx_clkdiv_ctrl_ctr_div = 1;
      tmp_stxp0_tx_clkdiv_ctrl_ctv_div = 1;

      tmp_srx0_rx_clkdiv_ctrl_ddiv_sel = 3;
      tmp_srx0_rx_config_fcen = 0;
      tmp_stxp0_tx_clkdiv_ctrl_ddiv_sel = 3;
      tmp_stxp0_tx_config_fcen = 0;
      /* Bugzilla 35199 Start */
      tmp_stxp0_tx_spare = 0x00D4;
      /* Bugzilla 35199 End */
    }
    else if ((div == TEN_HSIF_XFI_DIV_BY_40_REF) || (div == TEN_HSIF_XFI_DIV_BY_40_AUX_LPTM_REF)) {
      tmp_srx0_rx_clkdiv_ctrl_rdiv_sel = 4;
      tmp_srx0_rx_clkdiv_ctrl_ctvdiv_sel = 1;
      tmp_stxp0_tx_clkdiv_ctrl_rdiv_sel = 4;
      tmp_stxp0_tx_clkdiv_ctrl_ctr_div = 1;
      tmp_stxp0_tx_clkdiv_ctrl_ctv_div = 1;

      tmp_srx0_rx_clkdiv_ctrl_ddiv_sel = 3;
      tmp_srx0_rx_config_fcen = 0;
      tmp_stxp0_tx_clkdiv_ctrl_ddiv_sel = 3;
      tmp_stxp0_tx_config_fcen = 0;
      /* Bugzilla 35199 Start */
      tmp_stxp0_tx_spare = 0x00D4;
      /* Bugzilla 35199 End */
    }
    else if ((div == TEN_HSIF_XFI_DIV_BY_66_REF) || (div == TEN_HSIF_XFI_DIV_BY_66_AUX_LPTM_REF)) {
      tmp_srx0_rx_clkdiv_ctrl_rdiv_sel = 3;
      tmp_srx0_rx_clkdiv_ctrl_ctvdiv_sel = 0;
      tmp_stxp0_tx_clkdiv_ctrl_rdiv_sel = 3;
      tmp_stxp0_tx_clkdiv_ctrl_ctr_div = 0;
      tmp_stxp0_tx_clkdiv_ctrl_ctv_div = 0;

      tmp_srx0_rx_clkdiv_ctrl_ddiv_sel = 3;
      tmp_srx0_rx_config_fcen = 0;
      tmp_stxp0_tx_clkdiv_ctrl_ddiv_sel = 3;
      tmp_stxp0_tx_config_fcen = 0;
      /* Bugzilla 35199 Start */
      tmp_stxp0_tx_spare = 0x00D4;
      /* Bugzilla 35199 End */
    }
    else if ((div == TEN_HSIF_XFI_DIV_BY_80_REF) || (div == TEN_HSIF_XFI_DIV_BY_80_AUX_LPTM_REF)) {
      tmp_srx0_rx_clkdiv_ctrl_rdiv_sel = 5;
      tmp_srx0_rx_clkdiv_ctrl_ctvdiv_sel = 0;
      tmp_stxp0_tx_clkdiv_ctrl_rdiv_sel = 5;
      tmp_stxp0_tx_clkdiv_ctrl_ctr_div = 0;
      tmp_stxp0_tx_clkdiv_ctrl_ctv_div = 0;

      tmp_srx0_rx_clkdiv_ctrl_ddiv_sel = 3;
      tmp_srx0_rx_config_fcen = 0;
      tmp_stxp0_tx_clkdiv_ctrl_ddiv_sel = 3;
      tmp_stxp0_tx_config_fcen = 0;
      /* Bugzilla 35199 Start */
      tmp_stxp0_tx_spare = 0x00D4;
      /* Bugzilla 35199 End */
    }
    else {
      xfi_analog_cfg = 0;
      CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG,
                      ": XFI - this divided by reference is unsupported.");
    }
    break;

  case (TEN_HSIF_XFI_RATE_GBPS_8__5_FC):
     if ((div == TEN_HSIF_XFI_DIV_BY_16_REF) || (div == TEN_HSIF_XFI_DIV_BY_16_AUX_LPTM_REF)) {
      tmp_srx0_rx_clkdiv_ctrl_rdiv_sel = 0;
      tmp_srx0_rx_clkdiv_ctrl_ctvdiv_sel = 2;
      tmp_stxp0_tx_clkdiv_ctrl_rdiv_sel = 0;
      tmp_stxp0_tx_clkdiv_ctrl_ctr_div = 2;
      tmp_stxp0_tx_clkdiv_ctrl_ctv_div = 2;
      
      tmp_srx0_rx_clkdiv_ctrl_ddiv_sel = 0;
      tmp_srx0_rx_config_fcen = 1;
      tmp_stxp0_tx_clkdiv_ctrl_ddiv_sel = 0;
      tmp_stxp0_tx_config_fcen = 1;
      /* Bugzilla 35199 Start */
      tmp_stxp0_tx_spare = 0x00D0;
      /* Bugzilla 35199 End */
    }
    else if ((div == TEN_HSIF_XFI_DIV_BY_64_REF) || (div == TEN_HSIF_XFI_DIV_BY_64_AUX_LPTM_REF)) {
      tmp_srx0_rx_clkdiv_ctrl_rdiv_sel = 2;
      tmp_srx0_rx_clkdiv_ctrl_ctvdiv_sel = 0;
      tmp_stxp0_tx_clkdiv_ctrl_rdiv_sel = 2;
      tmp_stxp0_tx_clkdiv_ctrl_ctr_div = 0;
      tmp_stxp0_tx_clkdiv_ctrl_ctv_div = 0;

      tmp_srx0_rx_clkdiv_ctrl_ddiv_sel = 0;
      tmp_srx0_rx_config_fcen = 1;
      tmp_stxp0_tx_clkdiv_ctrl_ddiv_sel = 0;
      tmp_stxp0_tx_config_fcen = 1;
      /* Bugzilla 35199 Start */
      tmp_stxp0_tx_spare = 0x00D0;
      /* Bugzilla 35199 End */
    }
    else if ((div == TEN_HSIF_XFI_DIV_BY_32_REF) || (div == TEN_HSIF_XFI_DIV_BY_32_AUX_LPTM_REF)) {
      tmp_srx0_rx_clkdiv_ctrl_rdiv_sel = 1;
      tmp_srx0_rx_clkdiv_ctrl_ctvdiv_sel = 1;
      tmp_stxp0_tx_clkdiv_ctrl_rdiv_sel = 1;
      tmp_stxp0_tx_clkdiv_ctrl_ctr_div = 1;
      tmp_stxp0_tx_clkdiv_ctrl_ctv_div = 1;
      
      tmp_srx0_rx_clkdiv_ctrl_ddiv_sel = 0;
      tmp_srx0_rx_config_fcen = 1;
      tmp_stxp0_tx_clkdiv_ctrl_ddiv_sel = 0;
      tmp_stxp0_tx_config_fcen = 1;
      /* Bugzilla 35199 Start */
      tmp_stxp0_tx_spare = 0x00D0;
      /* Bugzilla 35199 End */
    }
    else if ((div == TEN_HSIF_XFI_DIV_BY_40_REF) || (div == TEN_HSIF_XFI_DIV_BY_40_AUX_LPTM_REF)) {
      tmp_srx0_rx_clkdiv_ctrl_rdiv_sel = 4;
      tmp_srx0_rx_clkdiv_ctrl_ctvdiv_sel = 0;
      tmp_stxp0_tx_clkdiv_ctrl_rdiv_sel = 4;
      tmp_stxp0_tx_clkdiv_ctrl_ctr_div = 0;
      tmp_stxp0_tx_clkdiv_ctrl_ctv_div = 0;

      tmp_srx0_rx_clkdiv_ctrl_ddiv_sel = 0;
      tmp_srx0_rx_config_fcen = 1;
      tmp_stxp0_tx_clkdiv_ctrl_ddiv_sel = 0;
      tmp_stxp0_tx_config_fcen = 1;
      /* Bugzilla 35199 Start */
      tmp_stxp0_tx_spare = 0x00D0;
      /* Bugzilla 35199 End */
    }
    else if ((div == TEN_HSIF_XFI_DIV_BY_66_REF) || (div == TEN_HSIF_XFI_DIV_BY_66_AUX_LPTM_REF)) {
      tmp_srx0_rx_clkdiv_ctrl_rdiv_sel = 3;
      tmp_srx0_rx_clkdiv_ctrl_ctvdiv_sel = 0;
      tmp_stxp0_tx_clkdiv_ctrl_rdiv_sel = 3;
      tmp_stxp0_tx_clkdiv_ctrl_ctr_div = 0;
      tmp_stxp0_tx_clkdiv_ctrl_ctv_div = 0;

      tmp_srx0_rx_clkdiv_ctrl_ddiv_sel = 0;
      tmp_srx0_rx_config_fcen = 1;
      tmp_stxp0_tx_clkdiv_ctrl_ddiv_sel = 0;
      tmp_stxp0_tx_config_fcen = 1;
      /* Bugzilla 35199 Start */
      tmp_stxp0_tx_spare = 0x00D0;
      /* Bugzilla 35199 End */
    }
    else if ((div == TEN_HSIF_XFI_DIV_BY_80_REF) || (div == TEN_HSIF_XFI_DIV_BY_80_AUX_LPTM_REF)) {
      tmp_srx0_rx_clkdiv_ctrl_rdiv_sel = 5;
      tmp_srx0_rx_clkdiv_ctrl_ctvdiv_sel = 0;
      tmp_stxp0_tx_clkdiv_ctrl_rdiv_sel = 5;
      tmp_stxp0_tx_clkdiv_ctrl_ctr_div = 0;
      tmp_stxp0_tx_clkdiv_ctrl_ctv_div = 0;

      tmp_srx0_rx_clkdiv_ctrl_ddiv_sel = 0;
      tmp_srx0_rx_config_fcen = 1;
      tmp_stxp0_tx_clkdiv_ctrl_ddiv_sel = 0;
      tmp_stxp0_tx_config_fcen = 1;
      /* Bugzilla 35199 Start */
      tmp_stxp0_tx_spare = 0x00D0;
      /* Bugzilla 35199 End */
    }
    else {
      xfi_analog_cfg = 0;
      CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG,
                      ": XFI - this divided by reference is unsupported.");
    }
    break;

  case (TEN_HSIF_XFI_RATE_GBPS_4__25_FC):
    if ((div == TEN_HSIF_XFI_DIV_BY_16_REF) || (div == TEN_HSIF_XFI_DIV_BY_16_AUX_LPTM_REF)) {
      tmp_srx0_rx_clkdiv_ctrl_rdiv_sel = 0;
      tmp_srx0_rx_clkdiv_ctrl_ctvdiv_sel = 2;
      tmp_stxp0_tx_clkdiv_ctrl_rdiv_sel = 0;
      tmp_stxp0_tx_clkdiv_ctrl_ctr_div = 2;
      tmp_stxp0_tx_clkdiv_ctrl_ctv_div = 2;
      
      tmp_srx0_rx_clkdiv_ctrl_ddiv_sel = 1;
      tmp_srx0_rx_config_fcen = 1;
      tmp_stxp0_tx_clkdiv_ctrl_ddiv_sel = 1;
      tmp_stxp0_tx_config_fcen = 1;
      /* Bugzilla 35199 Start */
      tmp_stxp0_tx_spare = 0x00D4;
      /* Bugzilla 35199 End */
    }
    else if ((div == TEN_HSIF_XFI_DIV_BY_64_REF) || (div == TEN_HSIF_XFI_DIV_BY_64_AUX_LPTM_REF)) {
      tmp_srx0_rx_clkdiv_ctrl_rdiv_sel = 2;
      tmp_srx0_rx_clkdiv_ctrl_ctvdiv_sel = 0;
      tmp_stxp0_tx_clkdiv_ctrl_rdiv_sel = 2;
      tmp_stxp0_tx_clkdiv_ctrl_ctr_div = 0;
      tmp_stxp0_tx_clkdiv_ctrl_ctv_div = 0;

      tmp_srx0_rx_clkdiv_ctrl_ddiv_sel = 1;
      tmp_srx0_rx_config_fcen = 1;
      tmp_stxp0_tx_clkdiv_ctrl_ddiv_sel = 1;
      tmp_stxp0_tx_config_fcen = 1;
      /* Bugzilla 35199 Start */
      tmp_stxp0_tx_spare = 0x00D4;
      /* Bugzilla 35199 End */
    }
    else if ((div == TEN_HSIF_XFI_DIV_BY_32_REF) || (div == TEN_HSIF_XFI_DIV_BY_32_AUX_LPTM_REF)) {
      tmp_srx0_rx_clkdiv_ctrl_rdiv_sel = 1;
      tmp_srx0_rx_clkdiv_ctrl_ctvdiv_sel = 1;
      tmp_stxp0_tx_clkdiv_ctrl_rdiv_sel = 1;
      tmp_stxp0_tx_clkdiv_ctrl_ctr_div = 1;
      tmp_stxp0_tx_clkdiv_ctrl_ctv_div = 1;
      
      tmp_srx0_rx_clkdiv_ctrl_ddiv_sel = 1;
      tmp_srx0_rx_config_fcen = 1;
      tmp_stxp0_tx_clkdiv_ctrl_ddiv_sel = 1;
      tmp_stxp0_tx_config_fcen = 1;
      /* Bugzilla 35199 Start */
      tmp_stxp0_tx_spare = 0x00D4;
      /* Bugzilla 35199 End */
    }
    else if ((div == TEN_HSIF_XFI_DIV_BY_40_REF) || (div == TEN_HSIF_XFI_DIV_BY_40_AUX_LPTM_REF)) {
      tmp_srx0_rx_clkdiv_ctrl_rdiv_sel = 4;
      tmp_srx0_rx_clkdiv_ctrl_ctvdiv_sel = 0;
      tmp_stxp0_tx_clkdiv_ctrl_rdiv_sel = 4;
      tmp_stxp0_tx_clkdiv_ctrl_ctr_div = 0;
      tmp_stxp0_tx_clkdiv_ctrl_ctv_div = 0;

      tmp_srx0_rx_clkdiv_ctrl_ddiv_sel = 1;
      tmp_srx0_rx_config_fcen = 1;
      tmp_stxp0_tx_clkdiv_ctrl_ddiv_sel = 1;
      tmp_stxp0_tx_config_fcen = 1;
      /* Bugzilla 35199 Start */
      tmp_stxp0_tx_spare = 0x00D4;
      /* Bugzilla 35199 End */
    }
    else if ((div == TEN_HSIF_XFI_DIV_BY_66_REF) || (div == TEN_HSIF_XFI_DIV_BY_66_AUX_LPTM_REF)) {
      tmp_srx0_rx_clkdiv_ctrl_rdiv_sel = 3;
      tmp_srx0_rx_clkdiv_ctrl_ctvdiv_sel = 0;
      tmp_stxp0_tx_clkdiv_ctrl_rdiv_sel = 3;
      tmp_stxp0_tx_clkdiv_ctrl_ctr_div = 0;
      tmp_stxp0_tx_clkdiv_ctrl_ctv_div = 0;

      tmp_srx0_rx_clkdiv_ctrl_ddiv_sel = 1;
      tmp_srx0_rx_config_fcen = 1;
      tmp_stxp0_tx_clkdiv_ctrl_ddiv_sel = 1;
      tmp_stxp0_tx_config_fcen = 1;
      /* Bugzilla 35199 Start */
      tmp_stxp0_tx_spare = 0x00D4;
      /* Bugzilla 35199 End */
    }
    else if ((div == TEN_HSIF_XFI_DIV_BY_80_REF) || (div == TEN_HSIF_XFI_DIV_BY_80_AUX_LPTM_REF)) {
      tmp_srx0_rx_clkdiv_ctrl_rdiv_sel = 5;
      tmp_srx0_rx_clkdiv_ctrl_ctvdiv_sel = 0;
      tmp_stxp0_tx_clkdiv_ctrl_rdiv_sel = 5;
      tmp_stxp0_tx_clkdiv_ctrl_ctr_div = 0;
      tmp_stxp0_tx_clkdiv_ctrl_ctv_div = 0;

      tmp_srx0_rx_clkdiv_ctrl_ddiv_sel = 1;
      tmp_srx0_rx_config_fcen = 1;
      tmp_stxp0_tx_clkdiv_ctrl_ddiv_sel = 1;
      tmp_stxp0_tx_config_fcen = 1;
      /* Bugzilla 35199 Start */
      tmp_stxp0_tx_spare = 0x00D4;
      /* Bugzilla 35199 End */
    }
    else {
      xfi_analog_cfg = 0;
      CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG,
                      ": XFI - this divided by reference is unsupported.");
    }
    break;
  
  case (TEN_HSIF_XFI_RATE_GBPS_2__125_FC):
     if ((div == TEN_HSIF_XFI_DIV_BY_16_REF) || (div == TEN_HSIF_XFI_DIV_BY_16_AUX_LPTM_REF)) {
      tmp_srx0_rx_clkdiv_ctrl_rdiv_sel = 0;
      tmp_srx0_rx_clkdiv_ctrl_ctvdiv_sel = 2;
      tmp_stxp0_tx_clkdiv_ctrl_rdiv_sel = 0;
      tmp_stxp0_tx_clkdiv_ctrl_ctr_div = 2;
      tmp_stxp0_tx_clkdiv_ctrl_ctv_div = 2;
      
      tmp_srx0_rx_clkdiv_ctrl_ddiv_sel = 2;
      tmp_srx0_rx_config_fcen = 1;
      tmp_stxp0_tx_clkdiv_ctrl_ddiv_sel = 2;
      tmp_stxp0_tx_config_fcen = 1;
      /* Bugzilla 35199 Start */
      tmp_stxp0_tx_spare = 0x00D4;
      /* Bugzilla 35199 End */
    }
    else if ((div == TEN_HSIF_XFI_DIV_BY_64_REF) || (div == TEN_HSIF_XFI_DIV_BY_64_AUX_LPTM_REF)) {
      tmp_srx0_rx_clkdiv_ctrl_rdiv_sel = 2;
      tmp_srx0_rx_clkdiv_ctrl_ctvdiv_sel = 0;
      tmp_stxp0_tx_clkdiv_ctrl_rdiv_sel = 2;
      tmp_stxp0_tx_clkdiv_ctrl_ctr_div = 0;
      tmp_stxp0_tx_clkdiv_ctrl_ctv_div = 0;

      tmp_srx0_rx_clkdiv_ctrl_ddiv_sel = 2;
      tmp_srx0_rx_config_fcen = 1;
      tmp_stxp0_tx_clkdiv_ctrl_ddiv_sel = 2;
      tmp_stxp0_tx_config_fcen = 1;
      /* Bugzilla 35199 Start */
      tmp_stxp0_tx_spare = 0x00D4;
      /* Bugzilla 35199 End */
    }
    else if ((div == TEN_HSIF_XFI_DIV_BY_32_REF) || (div == TEN_HSIF_XFI_DIV_BY_32_AUX_LPTM_REF)) {
      tmp_srx0_rx_clkdiv_ctrl_rdiv_sel = 1;
      tmp_srx0_rx_clkdiv_ctrl_ctvdiv_sel = 1;
      tmp_stxp0_tx_clkdiv_ctrl_rdiv_sel = 1;
      tmp_stxp0_tx_clkdiv_ctrl_ctr_div = 1;
      tmp_stxp0_tx_clkdiv_ctrl_ctv_div = 1;
      
      tmp_srx0_rx_clkdiv_ctrl_ddiv_sel = 2;
      tmp_srx0_rx_config_fcen = 1;
      tmp_stxp0_tx_clkdiv_ctrl_ddiv_sel = 2;
      tmp_stxp0_tx_config_fcen = 1;
      /* Bugzilla 35199 Start */
      tmp_stxp0_tx_spare = 0x00D4;
      /* Bugzilla 35199 End */
    }
    else if ((div == TEN_HSIF_XFI_DIV_BY_40_REF) || (div == TEN_HSIF_XFI_DIV_BY_40_AUX_LPTM_REF)) {
      tmp_srx0_rx_clkdiv_ctrl_rdiv_sel = 4;
      tmp_srx0_rx_clkdiv_ctrl_ctvdiv_sel = 0;
      tmp_stxp0_tx_clkdiv_ctrl_rdiv_sel = 4;
      tmp_stxp0_tx_clkdiv_ctrl_ctr_div = 0;
      tmp_stxp0_tx_clkdiv_ctrl_ctv_div = 0;

      tmp_srx0_rx_clkdiv_ctrl_ddiv_sel = 2;
      tmp_srx0_rx_config_fcen = 1;
      tmp_stxp0_tx_clkdiv_ctrl_ddiv_sel = 2;
      tmp_stxp0_tx_config_fcen = 1;
      /* Bugzilla 35199 Start */
      tmp_stxp0_tx_spare = 0x00D4;
      /* Bugzilla 35199 End */
    }
    else if ((div == TEN_HSIF_XFI_DIV_BY_66_REF) || (div == TEN_HSIF_XFI_DIV_BY_66_AUX_LPTM_REF)) {
      tmp_srx0_rx_clkdiv_ctrl_rdiv_sel = 3;
      tmp_srx0_rx_clkdiv_ctrl_ctvdiv_sel = 0;
      tmp_stxp0_tx_clkdiv_ctrl_rdiv_sel = 3;
      tmp_stxp0_tx_clkdiv_ctrl_ctr_div = 0;
      tmp_stxp0_tx_clkdiv_ctrl_ctv_div = 0;

      tmp_srx0_rx_clkdiv_ctrl_ddiv_sel = 2;
      tmp_srx0_rx_config_fcen = 1;
      tmp_stxp0_tx_clkdiv_ctrl_ddiv_sel = 2;
      tmp_stxp0_tx_config_fcen = 1;
      /* Bugzilla 35199 Start */
      tmp_stxp0_tx_spare = 0x00D4;
      /* Bugzilla 35199 End */
    }
    else if ((div == TEN_HSIF_XFI_DIV_BY_80_REF) || (div == TEN_HSIF_XFI_DIV_BY_80_AUX_LPTM_REF)) {
      tmp_srx0_rx_clkdiv_ctrl_rdiv_sel = 5;
      tmp_srx0_rx_clkdiv_ctrl_ctvdiv_sel = 0;
      tmp_stxp0_tx_clkdiv_ctrl_rdiv_sel = 5;
      tmp_stxp0_tx_clkdiv_ctrl_ctr_div = 0;
      tmp_stxp0_tx_clkdiv_ctrl_ctv_div = 0;

      tmp_srx0_rx_clkdiv_ctrl_ddiv_sel = 2;
      tmp_srx0_rx_config_fcen = 1;
      tmp_stxp0_tx_clkdiv_ctrl_ddiv_sel = 2;
      tmp_stxp0_tx_config_fcen = 1;
      /* Bugzilla 35199 Start */
      tmp_stxp0_tx_spare = 0x00D4;
      /* Bugzilla 35199 End */
    }
    else {
      xfi_analog_cfg = 0;
      CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG,
                      ": XFI - this divided by reference is unsupported.");
    }
    break;
  
  case (TEN_HSIF_XFI_RATE_GBPS_1__0625_FC):
    if ((div == TEN_HSIF_XFI_DIV_BY_16_REF) || (div == TEN_HSIF_XFI_DIV_BY_16_AUX_LPTM_REF)) {
      tmp_srx0_rx_clkdiv_ctrl_rdiv_sel = 0;
      tmp_srx0_rx_clkdiv_ctrl_ctvdiv_sel = 2;
      tmp_stxp0_tx_clkdiv_ctrl_rdiv_sel = 0;
      tmp_stxp0_tx_clkdiv_ctrl_ctr_div = 2;
      tmp_stxp0_tx_clkdiv_ctrl_ctv_div = 2;
      
      tmp_srx0_rx_clkdiv_ctrl_ddiv_sel = 3;
      tmp_srx0_rx_config_fcen = 1;
      tmp_stxp0_tx_clkdiv_ctrl_ddiv_sel = 3;
      tmp_stxp0_tx_config_fcen = 1;
      /* Bugzilla 35199 Start */
      tmp_stxp0_tx_spare = 0x00D4;
      /* Bugzilla 35199 End */
    }
    else if ((div == TEN_HSIF_XFI_DIV_BY_64_REF) || (div == TEN_HSIF_XFI_DIV_BY_64_AUX_LPTM_REF)) {
      tmp_srx0_rx_clkdiv_ctrl_rdiv_sel = 2;
      tmp_srx0_rx_clkdiv_ctrl_ctvdiv_sel = 0;
      tmp_stxp0_tx_clkdiv_ctrl_rdiv_sel = 2;
      tmp_stxp0_tx_clkdiv_ctrl_ctr_div = 0;
      tmp_stxp0_tx_clkdiv_ctrl_ctv_div = 0;

      tmp_srx0_rx_clkdiv_ctrl_ddiv_sel = 3;
      tmp_srx0_rx_config_fcen = 1;
      tmp_stxp0_tx_clkdiv_ctrl_ddiv_sel = 3;
      tmp_stxp0_tx_config_fcen = 1;
      /* Bugzilla 35199 Start */
      tmp_stxp0_tx_spare = 0x00D4;
      /* Bugzilla 35199 End */
    }
    else if ((div == TEN_HSIF_XFI_DIV_BY_32_REF) || (div == TEN_HSIF_XFI_DIV_BY_32_AUX_LPTM_REF)) {
      tmp_srx0_rx_clkdiv_ctrl_rdiv_sel = 1;
      tmp_srx0_rx_clkdiv_ctrl_ctvdiv_sel = 1;
      tmp_stxp0_tx_clkdiv_ctrl_rdiv_sel = 1;
      tmp_stxp0_tx_clkdiv_ctrl_ctr_div = 1;
      tmp_stxp0_tx_clkdiv_ctrl_ctv_div = 1;
      
      tmp_srx0_rx_clkdiv_ctrl_ddiv_sel = 3;
      tmp_srx0_rx_config_fcen = 1;
      tmp_stxp0_tx_clkdiv_ctrl_ddiv_sel = 3;
      tmp_stxp0_tx_config_fcen = 1;
      /* Bugzilla 35199 Start */
      tmp_stxp0_tx_spare = 0x00D4;
      /* Bugzilla 35199 End */
    }
    else if ((div == TEN_HSIF_XFI_DIV_BY_40_REF) || (div == TEN_HSIF_XFI_DIV_BY_40_AUX_LPTM_REF)) {
      tmp_srx0_rx_clkdiv_ctrl_rdiv_sel = 4;
      tmp_srx0_rx_clkdiv_ctrl_ctvdiv_sel = 0;
      tmp_stxp0_tx_clkdiv_ctrl_rdiv_sel = 4;
      tmp_stxp0_tx_clkdiv_ctrl_ctr_div = 0;
      tmp_stxp0_tx_clkdiv_ctrl_ctv_div = 0;

      tmp_srx0_rx_clkdiv_ctrl_ddiv_sel = 3;
      tmp_srx0_rx_config_fcen = 1;
      tmp_stxp0_tx_clkdiv_ctrl_ddiv_sel = 3;
      tmp_stxp0_tx_config_fcen = 1;
      /* Bugzilla 35199 Start */
      tmp_stxp0_tx_spare = 0x00D4;
      /* Bugzilla 35199 End */
    }
    else if ((div == TEN_HSIF_XFI_DIV_BY_66_REF) || (div == TEN_HSIF_XFI_DIV_BY_66_AUX_LPTM_REF)) {
      tmp_srx0_rx_clkdiv_ctrl_rdiv_sel = 3;
      tmp_srx0_rx_clkdiv_ctrl_ctvdiv_sel = 0;
      tmp_stxp0_tx_clkdiv_ctrl_rdiv_sel = 3;
      tmp_stxp0_tx_clkdiv_ctrl_ctr_div = 0;
      tmp_stxp0_tx_clkdiv_ctrl_ctv_div = 0;

      tmp_srx0_rx_clkdiv_ctrl_ddiv_sel = 3;
      tmp_srx0_rx_config_fcen = 1;
      tmp_stxp0_tx_clkdiv_ctrl_ddiv_sel = 3;
      tmp_stxp0_tx_config_fcen = 1;
      /* Bugzilla 35199 Start */
      tmp_stxp0_tx_spare = 0x00D4;
      /* Bugzilla 35199 End */
    }
    else if ((div == TEN_HSIF_XFI_DIV_BY_80_REF) || (div == TEN_HSIF_XFI_DIV_BY_80_AUX_LPTM_REF)) {
      tmp_srx0_rx_clkdiv_ctrl_rdiv_sel = 5;
      tmp_srx0_rx_clkdiv_ctrl_ctvdiv_sel = 0;
      tmp_stxp0_tx_clkdiv_ctrl_rdiv_sel = 5;
      tmp_stxp0_tx_clkdiv_ctrl_ctr_div = 0;
      tmp_stxp0_tx_clkdiv_ctrl_ctv_div = 0;

      tmp_srx0_rx_clkdiv_ctrl_ddiv_sel = 3;
      tmp_srx0_rx_config_fcen = 1;
      tmp_stxp0_tx_clkdiv_ctrl_ddiv_sel = 3;
      tmp_stxp0_tx_config_fcen = 1;
      /* Bugzilla 35199 Start */
      tmp_stxp0_tx_spare = 0x00D4;
      /* Bugzilla 35199 End */
    }
    else {
      xfi_analog_cfg = 0;
      CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG,
                      ": XFI - this divided by reference is unsupported.");
    }
    break;
  
  default:
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": Invalid mode selected.");
    xfi_analog_cfg = 0;
    rtn = CS_ERROR;
    break;
  }


  if (xfi_analog_cfg) {
   /* Bugzilla #19353, fix bus errors, set tmp_enable1_lsb_srx_filtr elsewhere */
    rtn |= ten_xfi32x1_srx0_rx_clkdiv_ctrl_ctvdiv_sel(module_id, slice, tmp_srx0_rx_clkdiv_ctrl_ctvdiv_sel);
    rtn |= ten_xfi32x1_srx0_rx_clkdiv_ctrl_ddiv_sel(module_id, slice, tmp_srx0_rx_clkdiv_ctrl_ddiv_sel);
    rtn |= ten_xfi32x1_srx0_rx_clkdiv_ctrl_rdiv_sel(module_id, slice, tmp_srx0_rx_clkdiv_ctrl_rdiv_sel);
    rtn |= ten_xfi32x1_srx0_rx_config_fcen(module_id, slice, tmp_srx0_rx_config_fcen);
    rtn |= ten_xfi32x1_stxp0_tx_clkdiv_ctrl_ctr_div(module_id, slice, tmp_stxp0_tx_clkdiv_ctrl_ctr_div);
    rtn |= ten_xfi32x1_stxp0_tx_clkdiv_ctrl_ctv_div(module_id, slice, tmp_stxp0_tx_clkdiv_ctrl_ctv_div);
    rtn |= ten_xfi32x1_stxp0_tx_clkdiv_ctrl_ddiv_sel(module_id, slice, tmp_stxp0_tx_clkdiv_ctrl_ddiv_sel);
    rtn |= ten_xfi32x1_stxp0_tx_clkdiv_ctrl_rdiv_sel(module_id, slice, tmp_stxp0_tx_clkdiv_ctrl_rdiv_sel);
    rtn |= ten_xfi32x1_stxp0_tx_config_fcen(module_id, slice, tmp_stxp0_tx_config_fcen);
    rtn |= ten_xfi32x1_stxp0_tx_config_pilot_sel(module_id, slice, tmp_stxp0_tx_config_pilot_sel);
    rtn |= ten_xfi32x1_stxp0_tx_spare(module_id, slice, tmp_stxp0_tx_spare);
    CS_PRINT("HSIF XFI Analog Configuration Complete.\n");
  }
  else {
      CS_PRINT("HSIF XFI Analog Configuration ERROR.\n");
      rtn = CS_ERROR;
  }
  return (rtn);
}

/********************************************************************/
/* $rtn_hdr_start  HIGH LEVEL HSIF XFI ANALOG CONFIG SRX FILTR      */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : HIGH LEVEL                                          */
/* CHIP       : Tenabo                                              */
cs_status ten_hl_hsif_xfi_analog_cfg_srx_filtr(cs_uint16 module_id,
                          cs_uint8 slice,
                          cs_uint16 rate,
                          cs_uint16 div)
/* INPUTS     : o Module Id                                         */
/*              o Slice                                             */
/*              o Rate                                              */
/*              o Divided By Reference                              */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Provides analog configuration of the XFI SRX FILTR.              */
/*                                                                  */
/* [slice]  Specified as TEN_SLICE0 (0), TEN_SLICE1 (1),            */
/*   TEN_SLICE2 (2), TEN_SLICE3 (3) or TEN_SLICE_ALL (0xFF)         */
/*                                                                  */
/* [rate]  Specified as:  (supported div values)                    */
/*  TEN_HSIF_XFI_RATE_GBPS_9__95_TO_12__5  = 0,  Full Rate          */
/*  TEN_HSIF_XFI_RATE_GBPS_4__97_TO_6__25  = 1,  1/2,                */
/*  TEN_HSIF_XFI_RATE_GBPS_2__48_TO_3__125 = 2,  1/4,                */
/*  TEN_HSIF_XFI_RATE_GBPS_1__24_TO_1__56  = 3,  1/8,                */
/*  TEN_HSIF_XFI_RATE_GBPS_8__5_FC         = 4,  Full,               */
/*  TEN_HSIF_XFI_RATE_GBPS_4__25_FC        = 5,  1/2,                */
/*  TEN_HSIF_XFI_RATE_GBPS_2__125_FC       = 6,  1/4,                */
/*  TEN_HSIF_XFI_RATE_GBPS_1__0625_FC      = 7,  1/8,                */
/*  TEN_HSIF_XFI_RATE_GBPS_9__95328        = 8,  Full,               */
/*  TEN_HSIF_XFI_RATE_GBPS_10__3125        = 9,  Full,               */
/*  TEN_HSIF_XFI_RATE_GBPS_10__52          = 10, Full,               */
/*  TEN_HSIF_XFI_RATE_GBPS_10__70          = 11, Full,               */
/*  TEN_HSIF_XFI_RATE_GBPS_11__1           = 12, Full,               */
/*  TEN_HSIF_XFI_RATE_GBPS_11__3           = 13, Full,               */
/*  TEN_HSIF_XFI_RATE_GBPS_11__7           = 14, Full,               */
/*  TEN_HSIF_XFI_RATE_GBPS_12__5           = 15  Full,               */
/*  TEN_HSIF_XFI_RATE_GBPS_5_IB            = 16, 1/2,                */
/*  TEN_HSIF_XFI_RATE_GBPS_10_IB           = 17, Full,              */
/*                                                                  */
/* [div]  Specified as:                                             */
/*  TEN_HSIF_XFI_DIV_BY_16_REF          = 0,                        */
/*  TEN_HSIF_XFI_DIV_BY_40_REF          = 1,                        */
/*  TEN_HSIF_XFI_DIV_BY_64_REF          = 2,                        */
/*  TEN_HSIF_XFI_DIV_BY_80_REF          = 3                         */
/*  TEN_HSIF_XFI_DIV_BY_16_AUX_LPTM_REF = 4,                        */
/*  TEN_HSIF_XFI_DIV_BY_40_AUX_LPTM_REF = 5,                        */
/*  TEN_HSIF_XFI_DIV_BY_64_AUX_LPTM_REF = 6,                        */
/*  TEN_HSIF_XFI_DIV_BY_80_AUX_LPTM_REF = 7,                        */
/*  TEN_HSIF_XFI_DIV_BY_32_REF          = 8,                        */
/*  TEN_HSIF_XFI_DIV_BY_66_REF          = 9,                        */
/*  TEN_HSIF_XFI_DIV_BY_32_AUX_LPTM_REF = 10,                       */
/*  TEN_HSIF_XFI_DIV_BY_66_AUX_LPTM_REF = 11.                       */
/*                                                                  */
/* NOTE:  XFI operations are available for Module B only.           */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  cs_status rtn = CS_OK;
  cs_uint16 xfi_analog_cfg = 1;
  cs_uint16 tmp_enable1_lsb_srx_filtr = 3; /* default value */

  CS_PRINT("Provision HSIF XFI analog SRX FILTR...\n");

  if (TEN_MOD_ID_TO_MOD_NUM(module_id) != TEN_MODULE_B) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": XFI only on Module B.");
    return (CS_ERROR);
  }

  /* Bugzilla #23872, add other divs */
  if (div >= TEN_HSIF_XFI_DIV_BY_MAX_PARM) {
      xfi_analog_cfg = 0;
      CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG,
                      ": XFI - this divided by reference is unsupported.");
      rtn = CS_ERROR;
  }

  switch (rate) {

  case (TEN_HSIF_XFI_RATE_GBPS_9__95328):
  case (TEN_HSIF_XFI_RATE_GBPS_10__3125):
  case (TEN_HSIF_XFI_RATE_GBPS_10__52):
  case (TEN_HSIF_XFI_RATE_GBPS_10__70):
  case (TEN_HSIF_XFI_RATE_GBPS_11__1):
  case (TEN_HSIF_XFI_RATE_GBPS_11__3):
  case (TEN_HSIF_XFI_RATE_GBPS_11__7):
  case (TEN_HSIF_XFI_RATE_GBPS_12__5):
  case (TEN_HSIF_XFI_RATE_GBPS_9__95_TO_12__5):
  case (TEN_HSIF_XFI_RATE_GBPS_10_IB):
    /* Bugzilla #23872, add other divs */
    tmp_enable1_lsb_srx_filtr = 3;
    break;

  case (TEN_HSIF_XFI_RATE_GBPS_5_IB):
  case (TEN_HSIF_XFI_RATE_GBPS_4__97_TO_6__25):
    /* Bugzilla #23872, add other divs */
    tmp_enable1_lsb_srx_filtr = 5;
    break;

  case (TEN_HSIF_XFI_RATE_GBPS_2__48_TO_3__125):
    /* Bugzilla #23872, add other divs */
    tmp_enable1_lsb_srx_filtr = 7;
    break;

  case (TEN_HSIF_XFI_RATE_GBPS_1__24_TO_1__56):
    /* Bugzilla #23872, add other divs */
    tmp_enable1_lsb_srx_filtr = 8;
    break;

  case (TEN_HSIF_XFI_RATE_GBPS_8__5_FC):
    tmp_enable1_lsb_srx_filtr = 3;
    break;

  case (TEN_HSIF_XFI_RATE_GBPS_4__25_FC):
    /* Bugzilla #23872, add other divs */
    tmp_enable1_lsb_srx_filtr = 5;
    break;

  case (TEN_HSIF_XFI_RATE_GBPS_2__125_FC):
    /* Bugzilla #23872, add other divs */
    tmp_enable1_lsb_srx_filtr = 7;
    break;

  case (TEN_HSIF_XFI_RATE_GBPS_1__0625_FC):
    /* Bugzilla #23872, add other divs */
    tmp_enable1_lsb_srx_filtr = 8;
    break;

  default:
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": Invalid mode selected.");
    xfi_analog_cfg = 0;
    rtn = CS_ERROR;
    break;
  }

  if (xfi_analog_cfg) {
    rtn |= ten_xfi32x1_enable1_lsb_srx_filtr(module_id, slice, tmp_enable1_lsb_srx_filtr);
    CS_PRINT("HSIF XFI Analog Configuration SRX FILTR Complete.\n");
  }
  else {
      CS_PRINT("HSIF XFI Analog Configuration ERROR.\n");
      rtn = CS_ERROR;
  }
  return (rtn);
}

/********************************************************************/
/* $rtn_hdr_start  HIGH LEVEL HSIF XFI DOWNLOAD MICROCODE           */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : HIGH LEVEL                                          */
/* CHIP       : Tenabo                                              */
cs_status ten_hl_hsif_xfi_download_micro_code(cs_uint16 module_id,
                                              cs_uint8 slice)
/* INPUTS     : o Module Id                                         */
/*              o Slice                                             */
/*              o Mode                                              */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Programs the microcode.  Perform this after all other XFI        */
/* Provisioning is complete.                                        */
/*                                                                  */
/* [slice]  Specified as TEN_SLICE0 (0), TEN_SLICE1 (1),            */
/*   TEN_SLICE2 (2), TEN_SLICE3 (3) or TEN_SLICE_ALL (0xFF)         */
/*                                                                  */
/* NOTE:  XFI operations are available for Module B only.           */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  cs_uint16 ii;
  cs_status ret_val = CS_OK;
  cs_uint16 tmp_dev_id;
  cs_uint16 sl;

  CS_PRINT("ten_hl_hsif_xfi_download_micro_code, slice=%d\n", slice);

  if (TEN_MOD_ID_TO_MOD_NUM(module_id) != TEN_MODULE_B) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": XFI only on Module B.");
    return (CS_ERROR);
  }

  if ((slice>=TEN_MAX_SLICES) && (slice != TEN_SLICE_ALL)) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": slice out of range.  s/b 0..3.");
    return(CS_ERROR);
  }

  tmp_dev_id = TEN_MOD_ID_TO_DEV_ID(module_id);
  
  #ifdef TEN_LOG_XFI_UCODE
  g_pTEN->drvr_flag |= TEN_DRVR_LOG_SUSPEND;
  #endif
  
  for (sl=0; sl<TEN_MAX_SLICES; sl++) {
    if ((slice == sl) || (slice == TEN_SLICE_ALL)) {

      ret_val |= ten_reg_write(tmp_dev_id, 0x03207+(sl*TEN_XFI32X1_SDS_STRIDE), 0x07FF);
      ret_val |= ten_reg_write(tmp_dev_id, 0x03219+(sl*TEN_XFI32X1_SDS_STRIDE), 0x0000);
      ret_val |= ten_reg_write(tmp_dev_id, 0x033DC+(sl*TEN_XFI32X1_SDS_STRIDE), 0xEDCF);
      ret_val |= ten_reg_write(tmp_dev_id, 0x03211+(sl*TEN_XFI32X1_SDS_STRIDE), 0xCCF3);
      ret_val |= ten_reg_write(tmp_dev_id, 0x033A1+(sl*TEN_XFI32X1_SDS_STRIDE), 0x0000);
      ret_val |= ten_reg_write(tmp_dev_id, 0x03212+(sl*TEN_XFI32X1_SDS_STRIDE), 0x8020);
      ret_val |= ten_reg_write(tmp_dev_id, 0x03213+(sl*TEN_XFI32X1_SDS_STRIDE), 0x8040);
      ret_val |= ten_reg_write(tmp_dev_id, 0x03214+(sl*TEN_XFI32X1_SDS_STRIDE), 0x8040);
      ret_val |= ten_reg_write(tmp_dev_id, 0x033A3+(sl*TEN_XFI32X1_SDS_STRIDE), 0x0100);
      ret_val |= ten_reg_write(tmp_dev_id, 0x033A4+(sl*TEN_XFI32X1_SDS_STRIDE), 0x00C0);
      ret_val |= ten_reg_write(tmp_dev_id, 0x033A2+(sl*TEN_XFI32X1_SDS_STRIDE), 0x2919);
      ret_val |= ten_reg_write(tmp_dev_id, 0x0320D+(sl*TEN_XFI32X1_SDS_STRIDE), 0x0C00);
      ret_val |= ten_reg_write(tmp_dev_id, 0x0304D+(sl*TEN_XFI32X1_SDS_STRIDE), 0x2001);
      ret_val |= ten_reg_write(tmp_dev_id, 0x03254+(sl*TEN_XFI32X1_SDS_STRIDE), 0x0020);
      ret_val |= ten_reg_write(tmp_dev_id, 0x03256+(sl*TEN_XFI32X1_SDS_STRIDE), 0x0020);
      ret_val |= ten_reg_write(tmp_dev_id, 0x03258+(sl*TEN_XFI32X1_SDS_STRIDE), 0x0010);
      ret_val |= ten_reg_write(tmp_dev_id, 0x0325A+(sl*TEN_XFI32X1_SDS_STRIDE), 0x0010);
      ret_val |= ten_reg_write(tmp_dev_id, 0x0325C+(sl*TEN_XFI32X1_SDS_STRIDE), 0x0020);
      ret_val |= ten_reg_write(tmp_dev_id, 0x0324F+(sl*TEN_XFI32X1_SDS_STRIDE), 0x0000);
      ret_val |= ten_reg_write(tmp_dev_id, 0x032D0+(sl*TEN_XFI32X1_SDS_STRIDE), 0x8004);
      ret_val |= ten_reg_write(tmp_dev_id, 0x03240+(sl*TEN_XFI32X1_SDS_STRIDE), 0x0008);

      for (ii=0; ii<TEN_HSIF_GRAM_ROWS_MAX; ii++) {
        ret_val |= ten_xfi32x1_set_gram_d1(module_id, sl, ten_hsif_gram_table[ii][0]);
        if (ret_val == CS_ERROR) {
          goto RTN_EXIT;
        }
        ret_val |= ten_xfi32x1_set_gram_d0(module_id, sl, ten_hsif_gram_table[ii][1]);
        if (ret_val == CS_ERROR) {
          goto RTN_EXIT;
        }
        ret_val |= ten_xfi32x1_set_gram_cr(module_id, sl, ten_hsif_gram_table[ii][2]);
        if (ret_val == CS_ERROR) {
          goto RTN_EXIT;
        }
      }

      ret_val |= ten_reg_write(tmp_dev_id, 0x032D0+(sl*TEN_XFI32X1_SDS_STRIDE), 0x0004);
      ret_val |= ten_reg_write(tmp_dev_id, 0x03243+(sl*TEN_XFI32X1_SDS_STRIDE), 0x0000);
      
      /* Bug #39354: Change to XFI microcode download and microcode check APIs.  */
      TEN_MDELAY(50);
      
      ret_val |= ten_reg_write(tmp_dev_id, 0x03240+(sl*TEN_XFI32X1_SDS_STRIDE), 0x0007);
    }
  }  
  #ifdef TEN_LOG_XFI_UCODE
  g_pTEN->drvr_flag &= ~TEN_DRVR_LOG_SUSPEND;
  #endif

RTN_EXIT:
  CS_PRINT("ten_hl_hsif_xfi_download_micro_code Complete.\n");
  return (ret_val);
}

/* Bugzilla #19410, add ucode verify and check APIs */
/* bugzilla #21921, split out verify and running check feature */
/********************************************************************/
/* $rtn_hdr_start  HIGH LEVEL HSIF XFI CONTROL MICROCODE VERIFY     */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : HIGH LEVEL                                          */
/* CHIP       : Tenabo                                              */
cs_status ten_hl_hsif_xfi_control_micro_code_verify(cs_ctl_t ctl)
/* INPUTS     : o Control                                           */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Controls whether or not the microcode is verified,               */
/* after the microcode download.                                    */
/*                                                                  */
/* The [ctl] parameter controls checking option:                    */
/*   0 = CS_DISABLE (do not verify microcode)                       */
/*   1 = CS_ENABLE (perform microcode verify.                       */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  if (TEN_DRVR_IS_LOADED()) {
    if (ctl == CS_DISABLE) {
      CS_PRINT("microcode verify DISABLED.\n");
      g_pTEN->ucode_flag = 0;
    }
    else {
      CS_PRINT("microcode verify ENABLED.\n");
      g_pTEN->ucode_flag = 1;
    }
  }
  else {
    return (CS_ERROR);
  }
  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  HIGH LEVEL HSIF XFI CONTROL MICROCODE RUNNING    */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : HIGH LEVEL                                          */
/* CHIP       : Tenabo                                              */
cs_status ten_hl_hsif_xfi_control_micro_code_running_check(cs_ctl_t ctl)
/* INPUTS     : o Control                                           */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Controls whether or not the microcode is checked for RUNNING,    */
/* after the microcode download.                                    */
/*                                                                  */
/* The [ctl] parameter controls checking option:                    */
/*   0 = CS_DISABLE (do not check microcode running)                */
/*   1 = CS_ENABLE (perform check for microcode running).           */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  if (TEN_DRVR_IS_LOADED()) {
    if (ctl == CS_DISABLE) {
      CS_PRINT("microcode running check DISABLED.\n");
      g_pTEN->ucode_running_flag = 0;
    }
    else {
      CS_PRINT("microcode running check ENABLED.\n");
      g_pTEN->ucode_running_flag = 1;
    }
  }
  else {
    return (CS_ERROR);
  }
  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  HIGH LEVEL HSIF XFI CHECK MICROCODE STATUS       */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : HIGH LEVEL                                          */
/* CHIP       : Tenabo                                              */
cs_int16 ten_hl_hsif_xfi_check_micro_code_status(cs_uint16 module_id,
                                                 cs_uint8 slice)
/* INPUTS     : o Module Id                                         */
/*              o Slice                                             */
/* OUTPUTS    : ----                                                */
/* RETURNS    : 1=RUNNING, 0=STOPPED or CS_ERROR                    */
/* DESCRIPTION:                                                     */
/* Checks status of xfi microcode, ie RUNNING or STOPPED.           */
/*                                                                  */
/* [slice]  Specified as TEN_SLICE0 (0), TEN_SLICE1 (1),            */
/*   TEN_SLICE2 (2), TEN_SLICE3 (3), or TEN_SLICE_ALL (0xFF).       */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  cs_uint16 sl;
  cs_uint16 ii;
  T41_t *pDev = NULL;
  cs_int16 rtn = 1;
  cs_uint16 changes = 0;
  cs_uint16 last_spare15_reg_lsb_value = 0;
  cs_uint16 tmp_spare15_lsb;
  cs_uint16 tmp_dev_id;
  cs_boolean ws_active;
  cs_uint16 dev_id;
  
  dev_id = TEN_MOD_ID_TO_DEV_ID(module_id);
  
  if (TEN_MOD_ID_TO_MOD_NUM(module_id) != TEN_MODULE_B) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": XFI only on Module B.");
    return (CS_ERROR);
  }

  if ((slice>=TEN_MAX_SLICES) && (slice != TEN_SLICE_ALL)) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": slice out of range.  s/b 0..3.");
    return (CS_ERROR);
  }

  tmp_dev_id = TEN_MOD_ID_TO_DEV_ID(module_id);

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  #ifdef TEN_LOG_XFI_UCODE
  g_pTEN->drvr_flag |= TEN_DRVR_LOG_SUSPEND;
  #endif
  
  /* Bugzilla #31756, use delays during warm start when checking microcode status  */
  ws_active = ten_dev_is_ws_in_progress(dev_id);
  if (ws_active) {
    ten_dev_stop_ws(dev_id);
  }
  
  for (sl=0; sl<TEN_MAX_SLICES; sl++) {
    if ((slice == sl) || (slice == TEN_SLICE_ALL)) {
    
      /* Bugzilla #25817, skip the check if no module is plugged in, just report CS_OK */
      if (ten_xfi32x1_rxlockd0_data_dets(module_id, sl)) {
        for (ii=0; ii<51;ii++) {
          tmp_spare15_lsb = ten_reg_read(tmp_dev_id, 0x0326e + (sl*TEN_XFI32X1_SDS_STRIDE));
          if (ii != 0) {
            if (tmp_spare15_lsb != last_spare15_reg_lsb_value) {
              changes++;
            }
            /* Bugzilla #21892, allow larger time window to check status */
            /* Bugzilla #28471, minimum delay */
            TEN_MDELAY(6);
          }
          last_spare15_reg_lsb_value = tmp_spare15_lsb;
        }
        CS_PRINT("Register changes, slice %d = %d/50\n", sl, changes);
        if (changes > 1) {
          rtn &= 1;  /* RUNNING */
          CS_PRINT("Microcode is RUNNING.\n");
        }
        else {
          rtn = 0;  /* STOPPED */
          CS_PRINT("Microcode is STOPPED.\n");
        }
        changes = 0;
      }
      else {
        CS_PRINT("Microcode status cannot be determined, optical module is not plugged in.\n");
        changes = 0;
        rtn &= 1;  /* Just report RUNNING if no module is plugged in */
      }
    }
  }
  
  #ifdef TEN_LOG_XFI_UCODE
  g_pTEN->drvr_flag &= ~TEN_DRVR_LOG_SUSPEND;
  #endif

   /* Bugzilla #31756, use delays during warm start when checking microcode status  */
  if (ws_active) {
    ten_dev_start_ws(dev_id, TEN_WS_METHOD_TOP_DOWN);
  }
  
  return (rtn);
}

/********************************************************************/
/* $rtn_hdr_start  HIGH LEVEL HSIF XFI VERIFY MICROCODE DOWNLOAD    */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : HIGH LEVEL                                          */
/* CHIP       : Tenabo                                              */
cs_status ten_hl_hsif_xfi_verify_micro_code_download(cs_uint16 module_id,
                                                     cs_uint8 slice)
/* INPUTS     : o Module Id                                         */
/*              o Slice                                             */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Verifies the microcode download was successful.  Returns CS_OK   */
/* if readback was successful or CS_ERROR if not.                   */
/*                                                                  */
/* [slice]  Specified as TEN_SLICE0 (0), TEN_SLICE1 (1),            */
/*   TEN_SLICE2 (2), TEN_SLICE3 (3), or TEN_SLICE_ALL (0xFF)        */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  cs_uint16 sl;
  cs_uint16 ii;
  T41_t *pDev = NULL;
  cs_int16 rtn = CS_OK;
  cs_uint16 tmp_dev_id;
  cs_uint16 gram_d1;
  cs_uint16 gram_d0;
  cs_uint16 match_cnt = 0;

  if (TEN_MOD_ID_TO_MOD_NUM(module_id) != TEN_MODULE_B) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": XFI only on Module B.");
    return (CS_ERROR);
  }

  if ((slice>=TEN_MAX_SLICES) && (slice != TEN_SLICE_ALL)) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": slice out of range.  s/b 0..3.");
    return( CS_ERROR);
  }

  tmp_dev_id = TEN_MOD_ID_TO_DEV_ID(module_id);
  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);

  #ifdef TEN_LOG_XFI_UCODE
  g_pTEN->drvr_flag |= TEN_DRVR_LOG_SUSPEND; 
  #endif

  for (sl=0; sl<TEN_MAX_SLICES; sl++) {
    if ((slice == sl) || (slice == TEN_SLICE_ALL)) {

      /* Forces all microsequencer clock branches on */
      ten_reg_write(tmp_dev_id, TEN_XFI32X1_SDS_SDS_DSP_DSP_MSEQCLKCTRL+(sl*TEN_XFI32X1_SDS_STRIDE), 0x8004);

      /* Stalls microsequencer */
      ten_reg_write(tmp_dev_id, TEN_XFI32X1_SDS_SDS_DSP_MSEQ_OPTIONS+(sl*TEN_XFI32X1_SDS_STRIDE), 0x000F);

      /* Selects bank 0 */
      ten_reg_write(tmp_dev_id, TEN_XFI32X1_SDS_SDS_DSP_MSEQ_BANKSELECT+(sl*TEN_XFI32X1_SDS_STRIDE), 0x0000);

      /* Read Program Store Memory (512 entries) and compare to values written in file xfi_ucode_release_*.txt */
      for (ii=0; ii<512; ii++)
      {
        /* indirect addressing of the program store, ii corresponds to the address */
        ten_reg_write(tmp_dev_id, TEN_XFI32X1_SDS_SDS_DSP_MSEQ_GRAM_CR+(sl*TEN_XFI32X1_SDS_STRIDE), 0x9800 + ii);
        /* Bug #29259: remove retry code from verify */ 
        
        /* Needs to compare the two reads below to the values written in file xfi_ucode_release_*.txt */
        /* at the same address, i.e. for XFI32X1_SDS_SDS_DSP_MSEQ_GRAM_CR set to 0x9000 + ii */
          gram_d1 = ten_reg_read(tmp_dev_id, TEN_XFI32X1_SDS_SDS_DSP_MSEQ_GRAM_D1+(sl*TEN_XFI32X1_SDS_STRIDE));
          gram_d0 = ten_reg_read(tmp_dev_id, TEN_XFI32X1_SDS_SDS_DSP_MSEQ_GRAM_D0+(sl*TEN_XFI32X1_SDS_STRIDE));
        if ((gram_d1 == ten_hsif_gram_table[ii][0]) &&
            (gram_d0 == ten_hsif_gram_table[ii][1])) {
          match_cnt++;
          /* CS_PRINT("Program Store, sl=%d, GRAM_D1: read=0x%04X, s/b=0x%04X, GRAM_D0: read=0x%04X, s/b=0x%04X\n", 
                    sl, gram_d1, ten_hsif_gram_table[ii][0],
                    gram_d0, ten_hsif_gram_table[ii][1]); */
        }
        else {
          CS_PRINT("Program Store MISMATCH, sl=%d, GRAM_D1: read=0x%04X, s/b=0x%04X, GRAM_D0: read=0x%04X, s/b=0x%04X\n", 
                    sl, gram_d1, ten_hsif_gram_table[ii][0],
                    gram_d0, ten_hsif_gram_table[ii][1]);
        }
      }

      /* Read Data Store Memory (64 entries) and compare to values written in file xfi_ucode_release_*.txt */
      for (ii=0; ii<64; ii++)
      {
        /* indirect addressing of the program store, ii corresponds to the address */
        ten_reg_write(tmp_dev_id, TEN_XFI32X1_SDS_SDS_DSP_MSEQ_GRAM_CR+(sl*TEN_XFI32X1_SDS_STRIDE), 0x8800 + ii);
        /* Bug #29259: remove retry code from verify */ 

        /* Needs to compare the two reads below to the values written in file xfi_ucode_release_*.txt */
        /* at the same address, i.e. for XFI32X1_SDS_SDS_DSP_MSEQ_GRAM_CR set to 0x8000 + ii */
          gram_d1 = ten_reg_read(tmp_dev_id, TEN_XFI32X1_SDS_SDS_DSP_MSEQ_GRAM_D1+(sl*TEN_XFI32X1_SDS_STRIDE));
          gram_d0 = ten_reg_read(tmp_dev_id, TEN_XFI32X1_SDS_SDS_DSP_MSEQ_GRAM_D0+(sl*TEN_XFI32X1_SDS_STRIDE));
        if ((gram_d1 == ten_hsif_gram_table[ii+512][0]) &&
            (gram_d0 == ten_hsif_gram_table[ii+512][1])) {
          match_cnt++;
          /*  CS_PRINT("Data Store, sl=%d, GRAM_D1: read=0x%04X, s/b=0x%04X, GRAM_D0: read=0x%04X, s/b=0x%04X\n", 
                    sl, gram_d1, ten_hsif_gram_table[ii+512][0],
                    gram_d0, ten_hsif_gram_table[ii+512][1]); */
        }
        else {
          CS_PRINT("Data Store MISMATCH, sl=%d, GRAM_D1: read=0x%04X, s/b=0x%04X, GRAM_D0: read=0x%04X, s/b=0x%04X\n", 
                    sl, gram_d1, ten_hsif_gram_table[ii+512][0],
                    gram_d0, ten_hsif_gram_table[ii+512][1]);
        }
      }
      
      if (match_cnt != 576) {
        CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": ten_hl_hsif_xfi_verify_micro_code_download failure %d/576.", match_cnt);
        rtn |= CS_ERROR;
      }
      CS_PRINT("Microcode addresses verified, slice=%d, %d/576\n", sl, match_cnt);
      match_cnt = 0;

      /* Disable microsequencer clock override */
      ten_reg_write(tmp_dev_id, TEN_XFI32X1_SDS_SDS_DSP_DSP_MSEQCLKCTRL+(sl*TEN_XFI32X1_SDS_STRIDE), 0x0004);

      /* Set program counter to 0 */
      ten_reg_write(tmp_dev_id, 0x03243+(sl*TEN_XFI32X1_SDS_STRIDE), 0x0000);

      /* Bug #39354: Change to XFI microcode download and microcode check APIs.  */
      TEN_MDELAY(50);

      /* Unstalls microsequencer */
      ten_reg_write(tmp_dev_id, TEN_XFI32X1_SDS_SDS_DSP_MSEQ_OPTIONS+(sl*TEN_XFI32X1_SDS_STRIDE), 0x0007);
    }
  }
  #ifdef TEN_LOG_XFI_UCODE
  g_pTEN->drvr_flag &= ~TEN_DRVR_LOG_SUSPEND;
  #endif
  CS_PRINT("ten_hl_hsif_xfi_verify_micro_code_download complete, rtn=%s\n", (rtn == CS_OK) ? "CS_OK" : "CS_ERROR");
  return (rtn);
}

/********************************************************************/
/* $rtn_hdr_start  TENABO SFI42 RESET FIX                           */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : HIGH LEVEL                                          */
/* CHIP       : Tenabo                                              */
cs_status ten_hl_hsif_sfi42_reset_fix(cs_uint16 dev_id)
/* INPUTS     : o Device Id                                         */
/* OUTPUTS    : ----                                                */
/* RETURNS    : 1: Done 0: NOT Done                                 */
/* DESCRIPTION:                                                     */
/* Give the sfi42 blocks a clock momentarily to propagate resets.   */
/* This routine saves states of affected registers to it should be  */
/* less sensitive to changes in the bringup sequence.               */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  cs_uint16 module_id = 0;
  cs_uint16 slc;
  cs_uint16 ii;
  TEN_HSIF_PROTOCOL_Datapath_Prov0_t     protocol_state[2][4];
  TEN_MPIF_GLOBAL_CLOCK_DISABLE_HSIF_A_t clockdis_state[2];
  TEN_MPIF_GLOBAL_CLOCK_DISABLE_HSIF_A_t tmp_global_clock_disable_hsif_a;
  TEN_MPIF_GLOBAL_RESET_GPLL_t            tmp_global_reset_gpll;
  TEN_GPLLX1_SDS_COMMON_STXP0_TX_PWRDN_t  pd_state[18];
  volatile cs_reg *tmp_addr;
  T41_t *pDev = NULL;

  TEN_DEV_COMMON_VALIDATE(dev_id, pDev, CS_ERROR);

  module_id = (dev_id & 0xFF) << 8;       /* Side A */
  TEN_MOD_LOCK(module_id, TEN_ID_HSIF);

  module_id = ((dev_id & 0xFF) << 8) + 1;  /* Side B */
  TEN_MOD_LOCK(module_id, TEN_ID_HSIF);

  TEN_DEV_LOCK(dev_id, TEN_ID_MPIF);
  TEN_DEV_LOCK(dev_id, TEN_ID_GPLLX1);

  for (module_id = 0; module_id < 2; module_id++) {
    for (slc=0; slc<4; slc++) {
      /* protocol set to sfi42_10g (save state)*/
      /*protocol_addr = TEN_HSIF_PROTOCOL_Datapath_Prov0 + $slc + $mod * TEN_HSIF_STRIDE; */
      /*$protocol_state[$mod*4+$slc] = tenabo_bf_read(DEV_ID,$protocol_addr,15,0);                    */

      /* Bugzilla #24439, fix klocwork warnings */
      tmp_addr = TEN_HSIF_REG_ADDR(pDev, 0, Datapath_Prov0);
      tmp_addr += (module_id & 0x0001) * TEN_HSIF_STRIDE;
      tmp_addr += slc * TEN_HSIF_PROTOCOL_Datapath_Prov0_STRIDE;
      
      protocol_state[module_id][slc].wrd =  TEN_REG_READ(tmp_addr);
      /*tenabo_bf_write(DEV_ID, $protocol_addr, 0x0044, 15, 0);*/
      TEN_REG_WRITE(tmp_addr, 0x0044);
    }
    /* remove clock disables to hsif (save state) */
    /*my $clockdis_addr = TEN_MPIF_GLOBAL_CLOCK_DISABLE_HSIF_A + $mod; */
    /*$clockdis_state[$mod] = tenabo_bf_read(DEV_ID,$clockdis_addr,7,0);     */
    clockdis_state[module_id].wrd = TEN_REG_READ(TEN_MPIF_REG_ADDR(pDev, GLOBAL_CLOCK_DISABLE_HSIF_A) + module_id);

    /*tenabo_bf_write(DEV_ID,$clockdis_addr,0x00,7,0);*/
    tmp_global_clock_disable_hsif_a.wrd = clockdis_state[module_id].wrd;
    tmp_global_clock_disable_hsif_a.bf.mr_tx = 0;
    tmp_global_clock_disable_hsif_a.bf.mr_rx = 0;
    TEN_REG_WRITE(TEN_MPIF_REG_ADDR(pDev, GLOBAL_CLOCK_DISABLE_HSIF_A) + module_id, tmp_global_clock_disable_hsif_a.wrd);
  }

  /* remove gpll resets (save state) */
  /*my $gpll_reset_state = tenabo_bf_read(DEV_ID,TEN_MPIF_GLOBAL_RESET_GPLL,15,0);*/
  /*tenabo_bf_write(DEV_ID,TEN_MPIF_GLOBAL_RESET_GPLL,0x0000,15,0);               */
  tmp_global_reset_gpll.wrd = TEN_REG_READ(TEN_MPIF_REG_ADDR(pDev, GLOBAL_RESET_GPLL));
  TEN_REG_WRITE(TEN_MPIF_REG_ADDR(pDev, GLOBAL_RESET_GPLL), 0x0000);


  /* power up gplls (save state) */
  for (ii=1; ii<TEN_GPLLX1_SDS_COUNT; ii++) {
    /*my $pd_addr = TEN_GPLLX1_SDS_COMMON_STXP0_TX_PWRDN + $i * TEN_GPLLX1_SDS_STRIDE;*/
    /*$pd_state[i] = tenabo_bf_read(DEV_ID, $pd_addr, 15, 0);                                     */
    /*tenabo_bf_write(DEV_ID,$pd_addr, 0x0000, 15, 0);                                            */
    pd_state[ii].wrd = TEN_REG_READ(TEN_GPLLX1_INST_REG_ADDR(pDev, STXP0_TX_PWRDN, ii));
    TEN_REG_WRITE(TEN_GPLLX1_INST_REG_ADDR(pDev, STXP0_TX_PWRDN, ii), 0x0000);
  }

  /* RESTORE STATES */
  for (module_id=0; module_id<2; module_id++) {
    for (slc=0; slc<4; slc++) {
      /* Bugzilla #24439, fix klocwork warnings */
      tmp_addr = TEN_HSIF_REG_ADDR(pDev, 0, Datapath_Prov0);
      tmp_addr += (module_id & 0x0001) * TEN_HSIF_STRIDE;
      tmp_addr += slc * TEN_HSIF_PROTOCOL_Datapath_Prov0_STRIDE;
      TEN_REG_WRITE(tmp_addr, protocol_state[module_id][slc].wrd);
    }
    /*my $clockdis_addr = TEN_MPIF_GLOBAL_CLOCK_DISABLE_HSIF_A + $mod;*/
    /*tenabo_bf_write(DEV_ID,$clockdis_addr,$clockdis_state[$mod],7,0);     */
    TEN_REG_WRITE(TEN_MPIF_REG_ADDR(pDev, GLOBAL_CLOCK_DISABLE_HSIF_A) + module_id, clockdis_state[module_id].wrd);
  }

  /* power up gplls (save state) */
  for (ii=1; ii<TEN_GPLLX1_SDS_COUNT; ii++)
  {
    /*my $pd_addr = TEN_GPLLX1_SDS_COMMON_STXP0_TX_PWRDN+$i*TEN_GPLLX1_SDS_STRIDE;*/
    /*tenabo_bf_write(DEV_ID,$pd_addr,$pd_state[$i],15,0);                                    */
    TEN_REG_WRITE(TEN_GPLLX1_INST_REG_ADDR(pDev, STXP0_TX_PWRDN, ii), pd_state[ii].wrd);
  }

  /*tenabo_bf_write(DEV_ID,TEN_MPIF_GLOBAL_RESET_GPLL,$gpll_reset_state,15,0);*/
  TEN_REG_WRITE(TEN_MPIF_REG_ADDR(pDev, GLOBAL_RESET_GPLL), tmp_global_reset_gpll.wrd);

  TEN_DEV_UNLOCK(dev_id, TEN_ID_GPLLX1);
  TEN_DEV_UNLOCK(dev_id, TEN_ID_MPIF);

  module_id = (dev_id & 0xFF) << 8;       /* Side A */
  TEN_MOD_UNLOCK(module_id, TEN_ID_HSIF);

  module_id = ((dev_id & 0xFF) << 8) + 1;  /* Side B */
  TEN_MOD_UNLOCK(module_id, TEN_ID_HSIF);

  return (CS_OK);
}

/********************************************************************/
/* ten_hsif_save_clock_protection_settings                          */
/* CHIP       : Tenabo                                              */
/* DESCRIPTION: Saves the clock protection settings before loopback */
/*              is initiated.                                       */
/********************************************************************/
cs_status ten_hsif_save_clock_protection_settings(cs_uint16 module_id,
                                                  cs_uint8 slice,
                                                  cs_uint8 active_sl,
                                                  ten_hsif_loopback_settings_t *settings)
{                                     
  cs_uint16 dev_id = TEN_MOD_ID_TO_DEV_ID(module_id);
  cs_uint16 module_num = TEN_MOD_ID_TO_MOD_NUM(module_id);
  cs_status rtn = CS_OK;

  CS_PRINT("ten_hsif_save_clock_protection_settings\n");
  
  if (!settings) {
    CS_HNDL_ERROR(dev_id, ETEN_MOD_INVALID_USER_ARG, ": Null pointer.");
    return (CS_ERROR);
  }
  
  if(module_num > TEN_MODULE_B) {
    CS_HNDL_ERROR(dev_id, ETEN_MOD_INVALID_USER_ARG, ": module_num out of range");
    return (CS_ERROR);
  }
  
  if (active_sl > TEN_SLICE3) {
    CS_HNDL_ERROR(dev_id, ETEN_MOD_INVALID_USER_ARG, ": slice out of range.  s/b 0..3.");
    return (CS_ERROR);
  }

  /* Bugzilla #26282: Loopback High-level API needs to disable all clock protection */
  settings->save_mpif_clock_switch_xlos_mr_tx[module_num][active_sl] = ten_mpif_get_clock_switch_xlos_mr(dev_id,
                                                                module_num, active_sl, CS_TX);
                                            
  settings->save_mpif_clock_switch_xlos_mr_rx[module_num][active_sl] = ten_mpif_get_clock_switch_xlos_mr(dev_id,
                                                                module_num, active_sl, CS_RX);
  
  if (module_num == TEN_MODULE_B) {
    settings->save_mpif_clock_switch_xlos_xfi_tx[module_num][active_sl] = ten_mpif_get_clock_switch_xlos_xfi(dev_id,
                                                                              active_sl, CS_TX);
    
    settings->save_mpif_clock_switch_xlos_xfi_rx[module_num][active_sl] = ten_mpif_get_clock_switch_xlos_xfi(dev_id,
                                                                              active_sl, CS_RX);
  }
  
  settings->save_mpif_clock_switch_lockdet_mr_tx[module_num][active_sl] = ten_mpif_get_clock_switch_lockdet_mr(dev_id,
                                                                   module_num, active_sl, CS_TX);
                                                                   
  settings->save_mpif_clock_switch_lockdet_mr_rx[module_num][active_sl] = ten_mpif_get_clock_switch_lockdet_mr(dev_id,
                                                                   module_num, active_sl, CS_RX);
  
  if (module_num == TEN_MODULE_B) {
    settings->save_mpif_clock_switch_lockdet_xfi_tx[module_num][active_sl] = ten_mpif_get_clock_switch_lockdet_xfi(dev_id,
                                                                                active_sl, CS_TX);
    
    settings->save_mpif_clock_switch_lockdet_xfi_rx[module_num][active_sl] = ten_mpif_get_clock_switch_lockdet_xfi(dev_id,
                                                                                active_sl, CS_RX);
  }
  /* Bug #37179 - MRB10G TEN_HSIF_LOOPBACK_FAR_END not disabling Tx clock protection */
  else { /* TEN_MODULE_A) */
    settings->save_mpif_clock_switch_lockdet_xfi_tx[module_num][active_sl] = 
              ten_mpif_get_clock_switch_lockdet_mrb2a(dev_id, active_sl, CS_TX);
    
    settings->save_mpif_clock_switch_lockdet_xfi_rx[module_num][active_sl] = 
              ten_mpif_get_clock_switch_lockdet_mrb2a(dev_id, active_sl, CS_RX);
  }
  
  settings->save_mpif_clock_switch_tx_cbrgenais_10g[module_num][active_sl] = ten_mpif_get_clock_switch_tx_cbrgenais_10g(dev_id,
                                                                                module_num, active_sl);

  if ((active_sl == 0) && (slice == TEN_SLICE_ALL)) {                                                                                  
    settings->save_mpif_clock_switch_tx_cbrgenais_40g[module_num] = ten_mpif_get_clock_switch_tx_cbrgenais_40g(dev_id,
                                                                       module_num);
  }

  settings->save_mpif_clock_switch_tx_pn11_10g[module_num][active_sl] = ten_mpif_get_clock_switch_tx_pn11_10g(dev_id,
                                                                           module_num, active_sl);
  if ((active_sl == 0) && (slice == TEN_SLICE_ALL)) {                                                                                  
    settings->save_mpif_clock_switch_tx_pn11_40g[module_num] = ten_mpif_get_clock_switch_tx_pn11_40g(dev_id,
                                                                   module_num);
  }
  
  settings->save_mpif_clock_switch_tx_ms_10g[module_num][active_sl] = ten_mpif_get_clock_switch_tx_ms_10g(dev_id,
                                                                          module_num, active_sl);

  if ((active_sl == 0) && (slice == TEN_SLICE_ALL)) {                                                                                  
    settings->save_mpif_clock_switch_tx_ms_40g[module_num] = ten_mpif_get_clock_switch_tx_ms_40g(dev_id, module_num);
  }

  settings->save_mpif_clock_switch_tx_msais[module_num][active_sl] = ten_mpif_get_clock_switch_tx_msais(dev_id,
                                                                         module_num, active_sl);
 
  /* disable all clock protection in loopback mode */
  rtn |= ten_mpif_set_clock_switch_xlos_mr(dev_id, module_num, active_sl, CS_TX, CS_DISABLE);
                                            
  rtn |= ten_mpif_set_clock_switch_xlos_mr(dev_id, module_num, active_sl, CS_RX, CS_DISABLE);
  
  if (module_num == TEN_MODULE_B) {
    rtn |= ten_mpif_set_clock_switch_xlos_xfi(dev_id, active_sl, CS_TX, CS_DISABLE);
    
    rtn |= ten_mpif_set_clock_switch_xlos_xfi(dev_id, active_sl, CS_RX, CS_DISABLE);
  }
  
  rtn |= ten_mpif_set_clock_switch_lockdet_mr(dev_id, module_num, active_sl, CS_TX, CS_DISABLE);
                                                                   
  rtn |= ten_mpif_set_clock_switch_lockdet_mr(dev_id, module_num, active_sl, CS_RX, CS_DISABLE);

  /* Bug #37179 - MRB10G TEN_HSIF_LOOPBACK_FAR_END not disabling Tx clock protection */
  if (module_num == TEN_MODULE_A) {
    rtn |= ten_mpif_set_clock_switch_lockdet_mrb2a(dev_id, active_sl, CS_TX, CS_DISABLE);
    rtn |= ten_mpif_set_clock_switch_lockdet_mrb2a(dev_id, active_sl, CS_RX, CS_DISABLE);
  }
   
  if (module_num == TEN_MODULE_B) {
    rtn |= ten_mpif_set_clock_switch_lockdet_xfi(dev_id, active_sl, CS_TX, CS_DISABLE);
    
    rtn |= ten_mpif_set_clock_switch_lockdet_xfi(dev_id, active_sl, CS_RX, CS_DISABLE);
  }
  
  rtn |= ten_mpif_set_clock_switch_tx_cbrgenais_10g(dev_id, module_num, active_sl, CS_DISABLE);

  if ((active_sl == 0) && (slice == TEN_SLICE_ALL)) {                                                                                  
    rtn |= ten_mpif_set_clock_switch_tx_cbrgenais_40g(dev_id, module_num, CS_DISABLE);
  }

  rtn |= ten_mpif_set_clock_switch_tx_pn11_10g(dev_id, module_num, active_sl, CS_DISABLE);
  
  if ((active_sl == 0) && (slice == TEN_SLICE_ALL)) {                                                                                  
    rtn |= ten_mpif_set_clock_switch_tx_pn11_40g(dev_id, module_num, CS_DISABLE);
  }
  
  rtn |= ten_mpif_set_clock_switch_tx_ms_10g(dev_id, module_num, active_sl, CS_DISABLE);

  if ((active_sl == 0) && (slice == TEN_SLICE_ALL)) {                                                                                  
    rtn |= ten_mpif_set_clock_switch_tx_ms_40g(dev_id, module_num, CS_DISABLE);
  }

  rtn |= ten_mpif_set_clock_switch_tx_msais(dev_id, module_num, active_sl, CS_DISABLE);
 
  return (rtn);
}

/********************************************************************/
/* ten_hsif_restore_clock_protection_settings                       */
/* CHIP       : Tenabo                                              */
/* DESCRIPTION: Restores the previously-saved clock protection      */
/*              settings before loopback was initiated.             */
/********************************************************************/
cs_status ten_hsif_restore_clock_protection_settings(cs_uint16 module_id,
                                                     cs_uint8 slice,
                                                     cs_uint8 active_sl,
                                                     ten_hsif_loopback_settings_t *settings)
{                                     
  cs_uint16 dev_id = TEN_MOD_ID_TO_DEV_ID(module_id);
  cs_uint16 module_num = TEN_MOD_ID_TO_MOD_NUM(module_id);
  cs_status rtn = CS_OK;
  
  CS_PRINT("ten_hsif_restore_clock_protection_settings\n");
  
  if (!settings) {
    CS_HNDL_ERROR(dev_id, ETEN_MOD_INVALID_USER_ARG, ": Null pointer.");
    return (CS_ERROR);
  }
  
  if(module_num > TEN_MODULE_B) {
    CS_HNDL_ERROR(dev_id, ETEN_MOD_INVALID_USER_ARG, ": module_num out of range");
    return (CS_ERROR);
  }
  
  if (active_sl > TEN_SLICE3) {
    CS_HNDL_ERROR(dev_id, ETEN_MOD_INVALID_USER_ARG, ": slice out of range.  s/b 0..3.");
    return (CS_ERROR);
  }
  
  /* Bugzilla #26282: Loopback High-level API needs to disable all clock protection */
  rtn |= ten_mpif_set_clock_switch_xlos_mr(dev_id, module_num, active_sl, CS_TX, 
             settings->save_mpif_clock_switch_xlos_mr_tx[module_num][active_sl]);
                                            
  rtn |= ten_mpif_set_clock_switch_xlos_mr(dev_id, module_num, active_sl, CS_RX, 
             settings->save_mpif_clock_switch_xlos_mr_rx[module_num][active_sl]);
             
  if (module_num == TEN_MODULE_B) {
    rtn |= ten_mpif_set_clock_switch_xlos_xfi(dev_id, active_sl, CS_TX, 
               settings->save_mpif_clock_switch_xlos_xfi_tx[module_num][active_sl]);
    
    rtn |= ten_mpif_set_clock_switch_xlos_xfi(dev_id, active_sl, CS_RX, 
               settings->save_mpif_clock_switch_xlos_xfi_rx[module_num][active_sl]);
  }
  
  rtn |= ten_mpif_set_clock_switch_lockdet_mr(dev_id, module_num, active_sl, CS_TX, 
             settings->save_mpif_clock_switch_lockdet_mr_tx[module_num][active_sl]);
                                                                   
  rtn |= ten_mpif_set_clock_switch_lockdet_mr(dev_id, module_num, active_sl, CS_RX,
            settings->save_mpif_clock_switch_lockdet_mr_rx[module_num][active_sl]);
  
  if (module_num == TEN_MODULE_B) {
    rtn |= ten_mpif_set_clock_switch_lockdet_xfi(dev_id, active_sl, CS_TX, 
               settings->save_mpif_clock_switch_lockdet_xfi_tx[module_num][active_sl]);
    
    rtn |= ten_mpif_set_clock_switch_lockdet_xfi(dev_id, active_sl, CS_RX, 
               settings->save_mpif_clock_switch_lockdet_xfi_rx[module_num][active_sl]);
  }
  else { /*  TEN_MODULE_A */
    /* Bug #37179 - MRB10G TEN_HSIF_LOOPBACK_FAR_END not disabling Tx clock protection */
    /* Bug #36548 - Loopback API backward compatibility feature */
    CS_PRINT("current structure value of ten_hsif_loopback_settings_struct_version_num = %d\n", settings->save_xfi32x1_stxp0_tx_lptime_sel[TEN_MODULE_A][0]);
    CS_PRINT("current software value of ten_hsif_loopback_settings_struct_version_num = %d\n", TEN_HSIF_LOOPBACK_SETTINGS_STRUCT_VERSION_NUM);
    
    /* only the structure of version 5100 and above has the mrb2a settings saved */
    /* do not try to restore these settings with old version of structure */
    if (settings->save_xfi32x1_stxp0_tx_lptime_sel[TEN_MODULE_A][0] >= TEN_HSIF_LOOPBACK_SETTINGS_STRUCT_VERSION_NUM_5100) {
      rtn |= ten_mpif_set_clock_switch_lockdet_mrb2a(dev_id, active_sl, CS_TX, 
                 settings->save_mpif_clock_switch_lockdet_xfi_tx[module_num][active_sl]);
      rtn |= ten_mpif_set_clock_switch_lockdet_mrb2a(dev_id, active_sl, CS_RX, 
                 settings->save_mpif_clock_switch_lockdet_xfi_rx[module_num][active_sl]);
    }
  }
  
  rtn |= ten_mpif_set_clock_switch_tx_cbrgenais_10g(dev_id, module_num, active_sl, 
             settings->save_mpif_clock_switch_tx_cbrgenais_10g[module_num][active_sl]);

  if ((active_sl == 0) && (slice == TEN_SLICE_ALL)) {                                                                                  
    rtn |= ten_mpif_set_clock_switch_tx_cbrgenais_40g(dev_id, module_num, 
               settings->save_mpif_clock_switch_tx_cbrgenais_40g[module_num]);
  }

  rtn |= ten_mpif_set_clock_switch_tx_pn11_10g(dev_id, module_num, active_sl, 
             settings->save_mpif_clock_switch_tx_pn11_10g[module_num][active_sl]);
             
  if ((active_sl == 0) && (slice == TEN_SLICE_ALL)) {                                                                                  
    rtn |= ten_mpif_set_clock_switch_tx_pn11_40g(dev_id, module_num,
               settings->save_mpif_clock_switch_tx_pn11_40g[module_num]);
  }
  
  rtn |= ten_mpif_set_clock_switch_tx_ms_10g(dev_id, module_num, active_sl,
             settings->save_mpif_clock_switch_tx_ms_10g[module_num][active_sl]);

  if ((active_sl == 0) && (slice == TEN_SLICE_ALL)) {                                                                                  
    rtn |= ten_mpif_set_clock_switch_tx_ms_40g(dev_id, module_num, settings->save_mpif_clock_switch_tx_ms_40g[module_num]);
  }

  rtn |= ten_mpif_set_clock_switch_tx_msais(dev_id, module_num, active_sl, settings->save_mpif_clock_switch_tx_msais[module_num][active_sl]);
                                                                         
  return (rtn);
}

/********************************************************************/
/* $rtn_hdr_start  HIGH LEVEL HSIF SET LOOPBACK SETTINGS VERSION NUM*/
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : HIGH LEVEL                                          */
/* CHIP       : Tenabo                                              */
cs_status ten_hl_hsif_set_loopback_settings_version_num_cb(cs_uint16 dev_id,
                                                           cs_uint16 ver_num)
/* INPUTS     : o Device Id                                         */
/*              o Version Number                                    */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Sets the version number for the loopback settings structure      */
/* in the control block.                                            */
/* Provided just in case the version number in the control block    */
/* needs overriding for any reason.                                 */
/*                                                                  */
/* [version_num]  parameter is specified as:                        */
/*   Previous to Release 5.10 = 0                                   */
/*   Release 5.10 = 5100                                            */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  T41_t *pDev = NULL;
  cs_status rtn = CS_OK;

  TEN_DEV_COMMON_VALIDATE(dev_id, pDev, CS_ERROR);

  rtn |= ten_hl_hsif_set_loopback_settings_version_num(dev_id, ver_num, 0);
  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  HIGH LEVEL HSIF SET LOOPBACK SETTINGS VERSION NUM*/
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : HIGH LEVEL                                          */
/* CHIP       : Tenabo                                              */
cs_status ten_hl_hsif_set_loopback_settings_version_num(cs_uint16 dev_id,
                                                        cs_uint16 ver_num,
                                                        ten_hsif_loopback_settings_t *settings)
/* INPUTS     : o Device Id                                         */
/*              o Version Number                                    */
/*              o Pointer to Settings Structure                     */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Sets the version number for the loopback settings structure.     */
/* Provided just in case the version number needs overriding        */
/* for any reason.                                                  */
/*                                                                  */
/* [version_num]  parameter is specified as:                        */
/*   Previous to Release 5.10 = 0                                   */
/*   Release 5.10 = 5100                                            */
/*                                                                  */
/* [settings]                                                       */
/*    pointer to user's allocated copy of                           */
/*    ten_hsif_loopback_settings_t.                                 */
/*    If null is used, then driver's own copy of this structure     */
/*    will be used for save/restore data.                           */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  ten_hsif_loopback_settings_t *saved;
  T41_t *pDev = NULL;

  TEN_DEV_COMMON_VALIDATE(dev_id, pDev, CS_ERROR);

  /* if no user-supplied buffer is provided, use internal one as scratch space instead */
  if (settings == 0) {
    saved = &(g_pTEN->p_dev_cb_tbl[dev_id]->saved_settings);
  }
  else {
    saved = settings;
  }
  
  CS_PRINT("current structure value of ten_hsif_loopback_settings_struct_version_num = %d\n", saved->save_xfi32x1_stxp0_tx_lptime_sel[TEN_MODULE_A][0]);
  CS_PRINT("current software value of ten_hsif_loopback_settings_struct_version_num = %d\n", TEN_HSIF_LOOPBACK_SETTINGS_STRUCT_VERSION_NUM);

  saved->save_xfi32x1_stxp0_tx_lptime_sel[TEN_MODULE_A][0] = ver_num;
  CS_PRINT("new structure value of ten_hsif_loopback_settings_struct_version_num = %d\n", saved->save_xfi32x1_stxp0_tx_lptime_sel[TEN_MODULE_A][0]);
  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  HIGH LEVEL HSIF CONTROL LOOPBACK USER SETTINGS   */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : HIGH LEVEL                                          */
/* CHIP       : Tenabo                                              */
cs_status ten_hl_hsif_control_loopback_with_user_settings(cs_uint16 module_id,
                                      cs_uint8 slice,
                                      cs_uint8 loopback,
                                      cs_ctl_t ctl,
                                      ten_hsif_loopback_settings_t *settings)
/* INPUTS     : o Module Id                                         */
/*              o Slice                                             */
/*              o Loopback                                          */
/*              o Pointer to Settings Structure                     */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Controls the major loopback modes for HSIF.                      */
/* The buffer space for the storage structure of settings required  */
/* to go out of loopback is provided by the user.                   */
/* NOTE:  The two XFI modes are available on Module B only.         */
/*                                                                  */
/* The [slice] parameter is specified as:                           */
/*   0x00 = TEN_SLICE0                                              */
/*   0x01 = TEN_SLICE1                                              */
/*   0x02 = TEN_SLICE2                                              */
/*   0x03 = TEN_SLICE3                                              */
/*   0xFF = TEN_SLICE_ALL (ALL 10G SLICES OR MR40G)                 */
/*                                                                  */
/* [loopback]  parameter is specified as:                           */
/*   TEN_HSIF_LOOPBACK_NONE           = 0                           */
/*   TEN_HSIF_LOOPBACK_FACILITY       = 1 (MR40G)                   */
/*   TEN_HSIF_LOOPBACK_FACILITY_EXT   = 2                           */
/*   TEN_HSIF_LOOPBACK_FACILITY_MR10G = 3 (MR10G)                   */
/*   TEN_HSIF_LOOPBACK_FAR_END        = 4                           */
/*   TEN_HSIF_LOOPBACK_MR_TX2RX       = 5                           */
/*   TEN_HSIF_LOOPBACK_MR_RX2TX       = 6                           */
/*   TEN_HSIF_LOOPBACK_XFI_TX2RX      = 7                           */
/*   TEN_HSIF_LOOPBACK_XFI_RX2TX      = 8                           */
/*   TEN_HSIF_LOOPBACK_MR_SERIAL        = 9 (TX2RX)                 */
/*   TEN_HSIF_LOOPBACK_FACILITY_XFI     = 10                        */
/*   TEN_HSIF_LOOPBACK_XFI_SERIAL_TX2RX = 11                        */
/*   TEN_HSIF_LOOPBACK_CFP_TX2RX        = 12,                       */
/*   TEN_HSIF_LOOPBACK_CFP_RX2TX        = 13,                       */
/*   TEN_HSIF_LOOPBACK_FACILITY_CFP     = 14                        */
/*                                                                  */
/*   RX2TX means that the input source for the TX datapath is       */
/*   RX loopback data.                                              */
/*                                                                  */
/*   TX2RX means that the input source for the RX datapath is       */
/*   TX loopback data.                                              */
/*                                                                  */
/*   See CS600x Datasheet (figures 92 and 93) for a diagram of      */
/*   these loopbacks.                                               */
/*                                                                  */
/*   NOTES:                                                         */ 
/*                                                                  */
/*        1. TEN_HSIF_LOOPBACK_MR_TX2RX will not work with SFI42,   */
/*        use TEN_HSIF_LOOPBACK_MR_SERIAL instead.                  */
/*                                                                  */
/*        2. For 10G TEN_HSIF_LOOPBACK_FACILITY_CFP and             */
/*        TEN_HSIF_LOOPBACK_CFP_RX2TX, only one facility loopback   */
/*        can be used at a time.                                    */
/*                                                                  */
/*        3. For CFP MR based loopbacks, when using CFP MR in       */
/*        protection switch mode, use side TEN_MODULE_A.            */ 
/*                                                                  */
/*        4. For TEN_HSIF_LOOPBACK_XFI_RX2TX, tx bit invert = '0'.  */
/*           Some setups may require tx bit invert = '1'.           */
/*                                                                  */
/* [ctl]  Controls loopback.                                        */
/*   0 = CS_DISABLE                                                 */
/*   1 = CS_ENABLE.                                                 */
/*                                                                  */
/* [settings]                                                       */
/*    pointer to user's allocated copy of                           */
/*    ten_hsif_loopback_settings_t.                                 */
/*    If null is used, then driver's own copy of this structure     */
/*    will be used for save/restore data.                           */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  cs_status rtn = CS_OK;
  cs_uint16 data_source;
  cs_uint16 div;
  cs_uint16 sl;
  T41_t *pDev = NULL;
  cs_uint16 tmp_mod_id;

  TEN_HSIF_MR_SLC0_MR10X4_SDS_COMMON_STXP0_TX_CLKDIV_CTRL_t tmp_slc0_mr10x4_sds_common_stxp0_tx_clkdiv_ctrl;
  TEN_HSIF_MR_SLC2_MR10X4_SDS_COMMON_STXP0_TX_CLKDIV_CTRL_t tmp_slc2_mr10x4_sds_common_stxp0_tx_clkdiv_ctrl;
  TEN_HSIF_MR_SLC1_MR10X5_SDS_COMMON_STXP0_TX_CLKDIV_CTRL_t tmp_slc1_mr10x5_sds_common_stxp0_tx_clkdiv_ctrl;
  TEN_HSIF_MR_SLC3_MR10X5_SDS_COMMON_STXP0_TX_CLKDIV_CTRL_t tmp_slc3_mr10x5_sds_common_stxp0_tx_clkdiv_ctrl;

  TEN_XFI32X1_SDS_XFI32X1_SDS_COMMON_STXP0_TX_CONFIG_t tmp_stxp0_tx_config;
  TEN_XFI32X1_SDS_XFI32X1_SDS_COMMON_STXP0_TX_CLKDIV_CTRL_t tmp_stxp0_tx_clkdiv_ctrl;
  TEN_HSIF_PROTOCOL_REFCLK_CFG_t tmp_refclk_cfg;

  TEN_HSIF_MR_SLC0_MR10X4_SDS_COMMON_SRX0_RX_CLKOUT_CTRL_t tmp_slc0_mr10x4_sds_common_srx0_rx_clkout_ctrl;
  TEN_HSIF_MR_SLC0_MR10X4_SDS_COMMON_STXP0_TX_CONFIG_t tmp_slc0_mr10x4_sds_common_stxp0_tx_config;
  TEN_HSIF_MR_SLC1_MR10X5_SDS_COMMON_SRX0_RX_CLKOUT_CTRL_t tmp_slc1_mr10x5_sds_common_srx0_rx_clkout_ctrl;
  TEN_HSIF_MR_SLC1_MR10X5_SDS_COMMON_STXP0_TX_CONFIG_t tmp_slc1_mr10x5_sds_common_stxp0_tx_config;
  TEN_HSIF_MR_SLC2_MR10X4_SDS_COMMON_SRX0_RX_CLKOUT_CTRL_t tmp_slc2_mr10x4_sds_common_srx0_rx_clkout_ctrl;
  TEN_HSIF_MR_SLC2_MR10X4_SDS_COMMON_STXP0_TX_CONFIG_t tmp_slc2_mr10x4_sds_common_stxp0_tx_config;
  TEN_HSIF_MR_SLC3_MR10X5_SDS_COMMON_SRX0_RX_CLKOUT_CTRL_t tmp_slc3_mr10x5_sds_common_srx0_rx_clkout_ctrl;
  TEN_HSIF_MR_SLC3_MR10X5_SDS_COMMON_STXP0_TX_CONFIG_t tmp_slc3_mr10x5_sds_common_stxp0_tx_config;

  TEN_HSIF_PROTOCOL_OK_CTRL_t tmp_ok_ctrl;
  TEN_HSIF_PROTOCOL_PSWTCH_OK_CTRL_t tmp_pswtch_ok_ctrl;
  TEN_HSIF_PROTOCOL_LBCFG_t tmp_lbcfg;

  TEN_HSIF_MR_SLC0_MR10X4_SDS_COMMON_TX0_Config_t tmp_slc0_mr10x4_sds_common_tx0_config;
  TEN_HSIF_MR_SLC1_MR10X5_SDS_COMMON_TX0_Config_t tmp_slc1_mr10x5_sds_common_tx0_config;
  TEN_HSIF_MR_SLC2_MR10X4_SDS_COMMON_TX0_Config_t tmp_slc2_mr10x4_sds_common_tx0_config;
  TEN_HSIF_MR_SLC3_MR10X5_SDS_COMMON_TX0_Config_t tmp_slc3_mr10x5_sds_common_tx0_config;

  TEN_HSIF_MR_SLC0_MR10X4_SDS_COMMON_RX0_Config_t tmp_slc0_mr10x4_sds_common_rx0_config;
  TEN_HSIF_MR_SLC1_MR10X5_SDS_COMMON_RX0_Config_t tmp_slc1_mr10x5_sds_common_rx0_config;
  TEN_HSIF_MR_SLC2_MR10X4_SDS_COMMON_RX0_Config_t tmp_slc2_mr10x4_sds_common_rx0_config;
  TEN_HSIF_MR_SLC3_MR10X5_SDS_COMMON_RX0_Config_t tmp_slc3_mr10x5_sds_common_rx0_config;

  TEN_XFI32X1_SDS_XFI32X1_SDS_COMMON_RX0_Config_t tmp_rx0_config;
  TEN_XFI32X1_SDS_XFI32X1_SDS_COMMON_TX0_Config_t tmp_tx0_config;
  TEN_XFI32X1_SDS_XFI32X1_SDS_COMMON_STXP0_TX_SPARE_t tmp_stxp0_tx_spare;

  TEN_CFP32X1_SDS_COMMON_RX0_Config_t tmp_cfp_rx0_config;
  TEN_CFP32X1_SDS_COMMON_TX0_Config_t tmp_cfp_tx0_config;
  TEN_CFP32X1_SDS_COMMON_RXLOCKD0_CONTROL_t tmp_cfp_rxlockd0_control;
  TEN_CFP32X1_SDS_COMMON_STXP0_TX_CONFIG_t tmp_cfp_stxp0_tx_config;
  TEN_CFP32X1_SDS_COMMON_STXP0_TX_CLKDIV_CTRL_t tmp_cfp_stxp0_tx_clkdiv_ctrl;
            
  TEN_HSIF_MR_SLC0_MR10X4_SDS_COMMON_STXP0_TX_CLKOUT_CTRL_t tmp_slc0_mr10x4_sds_common_stxp0_tx_clkout_ctrl;
  TEN_HSIF_MR_SLC1_MR10X5_SDS_COMMON_STXP0_TX_CLKOUT_CTRL_t tmp_slc1_mr10x5_sds_common_stxp0_tx_clkout_ctrl;
  TEN_HSIF_MR_SLC2_MR10X4_SDS_COMMON_STXP0_TX_CLKOUT_CTRL_t tmp_slc2_mr10x4_sds_common_stxp0_tx_clkout_ctrl;
  TEN_HSIF_MR_SLC3_MR10X5_SDS_COMMON_STXP0_TX_CLKOUT_CTRL_t tmp_slc3_mr10x5_sds_common_stxp0_tx_clkout_ctrl;

  TEN_HSIF_MR_SLC0_MR10X4_SDS_COMMON_SRX0_RX_SPARE_t tmp_slc0_mr10x4_sds_common_srx0_rx_spare;
  TEN_HSIF_MR_SLC1_MR10X5_SDS_COMMON_SRX0_RX_SPARE_t tmp_slc1_mr10x5_sds_common_srx0_rx_spare;
  TEN_HSIF_MR_SLC2_MR10X4_SDS_COMMON_SRX0_RX_SPARE_t tmp_slc2_mr10x4_sds_common_srx0_rx_spare;
  TEN_HSIF_MR_SLC3_MR10X5_SDS_COMMON_SRX0_RX_SPARE_t tmp_slc3_mr10x5_sds_common_srx0_rx_spare;

  ten_hsif_loopback_settings_t *saved;

  if ((slice>=TEN_MAX_SLICES) && (slice != TEN_SLICE_ALL)) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": slice out of range.  s/b 0..3 or 0xFF.");
    return(CS_ERROR);
  }

  if (ctl > CS_ENABLE) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": ctl out of range.");
    return (CS_ERROR);
  }

  if (loopback >= TEN_HSIF_LOOPBACK_MAX) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": loopback out of range.");
    return (CS_ERROR);
  }

  /* for MR40G, only TEN_SLICE_ALL is supported */
  if (loopback == TEN_HSIF_LOOPBACK_FACILITY) {
    slice = TEN_SLICE_ALL;
  }

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);

  /* if no user-supplied buffer is provided, use internal one as scratch space instead */
  if (settings == 0) {
    saved = &(g_pTEN->p_dev_cb_tbl[TEN_MOD_ID_TO_DEV_ID(module_id)]->saved_settings);
  }
  else {
    saved = settings;
  }

  switch (loopback)
  {
  case (TEN_HSIF_LOOPBACK_NONE):
    CS_PRINT_OUTPUT("TEN_HSIF_LOOPBACK_NONE\n");
    break;

  case (TEN_HSIF_LOOPBACK_FACILITY):
    CS_PRINT_OUTPUT("TEN_HSIF_LOOPBACK_FACILITY (MR40G)\n");
    break;

  case (TEN_HSIF_LOOPBACK_FACILITY_EXT):
    CS_PRINT_OUTPUT("TEN_HSIF_LOOPBACK_FACILITY_EXT\n");
    break;

  case (TEN_HSIF_LOOPBACK_FACILITY_MR10G):
    CS_PRINT_OUTPUT("TEN_HSIF_LOOPBACK_FACILITY_MR10G\n");
    break;

  case (TEN_HSIF_LOOPBACK_FAR_END):
    CS_PRINT_OUTPUT("TEN_HSIF_LOOPBACK_FAR_END\n");
    break;

  case (TEN_HSIF_LOOPBACK_MR_RX2TX):
    CS_PRINT_OUTPUT("TEN_HSIF_LOOPBACK_MR_RX2TX\n");
    break;

  case (TEN_HSIF_LOOPBACK_MR_TX2RX):
    CS_PRINT_OUTPUT("TEN_HSIF_LOOPBACK_MR_TX2RX\n");
    break;
    
  /* Bugzilla #26560, fix loopback message for XFI TX2RX */
  case (TEN_HSIF_LOOPBACK_XFI_TX2RX):
    CS_PRINT_OUTPUT("TEN_HSIF_LOOPBACK_XFI_TX2RX\n");
    break;

  case (TEN_HSIF_LOOPBACK_XFI_RX2TX):
    CS_PRINT_OUTPUT("TEN_HSIF_LOOPBACK_XFI_RX2TX\n");
    break;

  case (TEN_HSIF_LOOPBACK_MR_SERIAL):
    CS_PRINT_OUTPUT("TEN_HSIF_LOOPBACK_MR_SERIAL\n");
    break;

  case (TEN_HSIF_LOOPBACK_FACILITY_XFI):
    CS_PRINT_OUTPUT("TEN_HSIF_LOOPBACK_FACILITY_XFI\n");
    break;

  case (TEN_HSIF_LOOPBACK_XFI_SERIAL_TX2RX):
    CS_PRINT_OUTPUT("TEN_HSIF_LOOPBACK_XFI_SERIAL_TX2RX\n");
    break;
    
  case (TEN_HSIF_LOOPBACK_CFP_TX2RX):
    CS_PRINT_OUTPUT("TEN_HSIF_LOOPBACK_CFP_TX2RX\n");
    break;
    
  case (TEN_HSIF_LOOPBACK_CFP_RX2TX):
    CS_PRINT_OUTPUT("TEN_HSIF_LOOPBACK_CFP_RX2TX\n");
    break;
    
  case (TEN_HSIF_LOOPBACK_FACILITY_CFP):
    CS_PRINT_OUTPUT("TEN_HSIF_LOOPBACK_FACILITY_CFP\n");
    break;
    
  case (TEN_HSIF_LOOPBACK_CFP_SERIAL_TX2RX):
    CS_PRINT_OUTPUT("TEN_HSIF_LOOPBACK_CFP_SERIAL_TX2RX\n");
    break;
    
  default:
    CS_PRINT_OUTPUT("TEN_HSIF_LOOPBACK ???\n");
    break;
  }

  /* Bug #36548 - Loopback API backward compatibility feature */
  if (ctl == CS_ENABLE) {
    saved->save_xfi32x1_stxp0_tx_lptime_sel[TEN_MODULE_A][0] = TEN_HSIF_LOOPBACK_SETTINGS_STRUCT_VERSION_NUM;
    CS_PRINT("ten_hsif_loopback_settings_struct_version_num = %d\n", saved->save_xfi32x1_stxp0_tx_lptime_sel[TEN_MODULE_A][0]);
  }
  else {
    CS_PRINT("current structure value of ten_hsif_loopback_settings_struct_version_num = %d\n", saved->save_xfi32x1_stxp0_tx_lptime_sel[TEN_MODULE_A][0]);
    CS_PRINT("current software value of ten_hsif_loopback_settings_struct_version_num = %d\n", TEN_HSIF_LOOPBACK_SETTINGS_STRUCT_VERSION_NUM);
  }

  for (sl=0; sl<TEN_MAX_SLICES; sl++) {
    if ((slice == sl) || (slice == TEN_SLICE_ALL)) {

      switch (loopback)
      {
      case (TEN_HSIF_LOOPBACK_NONE):
        break;

      case (TEN_HSIF_LOOPBACK_FACILITY): /* MR40G */
        tmp_lbcfg.wrd = TEN_REG_READ(TEN_HSIF_REG_ADDR(pDev, module_id, LBCFG));

        /* check if loopback is already enabled */
        if (ctl == CS_ENABLE) {
          if ((sl == TEN_SLICE3) && (tmp_lbcfg.bf.rxtxlb3_en == 1)) {
            CS_PRINT_OUTPUT("Slice 3 is already in loopback.\n");
            break;
          }
          if ((sl == TEN_SLICE2) && (tmp_lbcfg.bf.rxtxlb2_en == 1)) {
            CS_PRINT_OUTPUT("Slice 2 is already in loopback.\n");
            break;
          }
          if ((sl == TEN_SLICE1) && (tmp_lbcfg.bf.rxtxlb1_en == 1)) {
            CS_PRINT_OUTPUT("Slice 1 is already in loopback.\n");
            break;
          }
          if ((sl == TEN_SLICE0) && (tmp_lbcfg.bf.rxtxlb0_en == 1)) {
            CS_PRINT_OUTPUT("Slice 0 is already in loopback.\n");
            break;
          }
        }

        /* check if loopback is already disabled */
        if (ctl == CS_DISABLE) {
          if ((sl == TEN_SLICE3) && (tmp_lbcfg.bf.rxtxlb3_en == 0)) {
            CS_PRINT_OUTPUT("Slice 3 is already out of loopback.\n");
            break;
          }
          if ((sl == TEN_SLICE2) && (tmp_lbcfg.bf.rxtxlb2_en == 0)) {
            CS_PRINT_OUTPUT("Slice 2 is already out of loopback.\n");
            break;
          }
          if ((sl == TEN_SLICE1) && (tmp_lbcfg.bf.rxtxlb1_en == 0)) {
            CS_PRINT_OUTPUT("Slice 1 is already out of loopback.\n");
            break;
          }
          if ((sl == TEN_SLICE0) && (tmp_lbcfg.bf.rxtxlb0_en == 0)) {
            CS_PRINT_OUTPUT("Slice 0 is already out of loopback.\n");
            break;
          }
        }

        /* Bugzilla #26282:  loopback API needs to disable all clock protection */
        if (ctl == CS_ENABLE) {
          /* save clock protection settings */
          rtn |= ten_hsif_save_clock_protection_settings(module_id, slice, sl, saved);
        }
        else {
          /* restore clock protection settings */
          rtn |= ten_hsif_restore_clock_protection_settings(module_id, slice, sl, saved);
        }
        
        rtn |= ten_hsif_facility_loopback(module_id, sl, ctl);
        
        /* Bugzilla #31876, fix 40G facility loopback for SFI4.2 mode */
        if (ten_hsif_is_sfi42_active(module_id, sl)) {
          if (ctl == CS_ENABLE) {
            /* enable loopback, save current state state */
            if (sl == TEN_SLICE0) {
              tmp_slc0_mr10x4_sds_common_stxp0_tx_clkout_ctrl.wrd = TEN_REG_READ(TEN_HSIF_SLC0_MR10X4_REG_ADDR(pDev,
                                                                    module_id, STXP0_TX_CLKOUT_CTRL));
              saved->save_slc0_mr10x4_sds_common_stxp0_tx_clkout_ctrl[TEN_MOD_ID_TO_MOD_NUM(module_id)][sl] = 
                     tmp_slc0_mr10x4_sds_common_stxp0_tx_clkout_ctrl.bf.STXP_TCLKIEN;
              rtn |= ten_hsif_slc0_mr10x4_sds_common_stxp0_tx_clkout_ctrl(module_id, 2);
              
              tmp_slc0_mr10x4_sds_common_srx0_rx_spare.wrd = TEN_REG_READ(TEN_HSIF_SLC0_MR10X4_REG_ADDR(pDev, 
                                                                          module_id, SRX0_RX_SPARE));
              /* set spare 6:  enable RXLP_CLK SFI4.2 line timing  */
              rtn |= ten_hsif_slc0_mr10x4_sds_common_srx0_rx_spare(module_id, TEN_INSTANCE_ALL, 
                         tmp_slc0_mr10x4_sds_common_srx0_rx_spare.wrd | 0x0040);
            }
            if (sl == TEN_SLICE1) {
              tmp_slc1_mr10x5_sds_common_stxp0_tx_clkout_ctrl.wrd = TEN_REG_READ(TEN_HSIF_SLC1_MR10X5_REG_ADDR(pDev,
                                                                     module_id, STXP0_TX_CLKOUT_CTRL));
              saved->save_slc1_mr10x5_sds_common_stxp0_tx_clkout_ctrl[TEN_MOD_ID_TO_MOD_NUM(module_id)][sl] = 
                     tmp_slc1_mr10x5_sds_common_stxp0_tx_clkout_ctrl.bf.STXP_TCLKIEN;
              rtn |= ten_hsif_slc1_mr10x5_sds_common_stxp0_tx_clkout_ctrl(module_id, 2);
              
              tmp_slc1_mr10x5_sds_common_srx0_rx_spare.wrd = TEN_REG_READ(TEN_HSIF_SLC1_MR10X5_REG_ADDR(pDev, 
                                                                          module_id, SRX0_RX_SPARE));
              /* set spare 6:  enable RXLP_CLK SFI4.2 line timing  */
              rtn |= ten_hsif_slc1_mr10x5_sds_common_srx0_rx_spare(module_id, TEN_INSTANCE_ALL, 
                         tmp_slc1_mr10x5_sds_common_srx0_rx_spare.wrd | 0x0040);
            }
            if (sl == TEN_SLICE2) {
              tmp_slc2_mr10x4_sds_common_stxp0_tx_clkout_ctrl.wrd = TEN_REG_READ(TEN_HSIF_SLC2_MR10X4_REG_ADDR(pDev, 
                                                                    module_id, STXP0_TX_CLKOUT_CTRL));
              saved->save_slc2_mr10x4_sds_common_stxp0_tx_clkout_ctrl[TEN_MOD_ID_TO_MOD_NUM(module_id)][sl] = 
                     tmp_slc2_mr10x4_sds_common_stxp0_tx_clkout_ctrl.bf.STXP_TCLKIEN;
              rtn |= ten_hsif_slc2_mr10x4_sds_common_stxp0_tx_clkout_ctrl(module_id, 2);
              
              tmp_slc2_mr10x4_sds_common_srx0_rx_spare.wrd = TEN_REG_READ(TEN_HSIF_SLC2_MR10X4_REG_ADDR(pDev, 
                                                                          module_id, SRX0_RX_SPARE));
              /* set spare 6:  enable  RXLP_CLK SFI4.2 line timing  */
              rtn |= ten_hsif_slc2_mr10x4_sds_common_srx0_rx_spare(module_id, TEN_INSTANCE_ALL, 
                         tmp_slc2_mr10x4_sds_common_srx0_rx_spare.wrd | 0x0040);
            }
            if (sl == TEN_SLICE3) {
              tmp_slc3_mr10x5_sds_common_stxp0_tx_clkout_ctrl.wrd = TEN_REG_READ(TEN_HSIF_SLC3_MR10X5_REG_ADDR(pDev,
                                                                        module_id, STXP0_TX_CLKOUT_CTRL));
              saved->save_slc3_mr10x5_sds_common_stxp0_tx_clkout_ctrl[TEN_MOD_ID_TO_MOD_NUM(module_id)][sl] = 
                     tmp_slc3_mr10x5_sds_common_stxp0_tx_clkout_ctrl.bf.STXP_TCLKIEN;
              rtn |= ten_hsif_slc3_mr10x5_sds_common_stxp0_tx_clkout_ctrl(module_id, 2);
              
              tmp_slc3_mr10x5_sds_common_srx0_rx_spare.wrd = TEN_REG_READ(TEN_HSIF_SLC3_MR10X5_REG_ADDR(pDev, 
                                                                          module_id, SRX0_RX_SPARE));
              /* set spare 6:  enable RXLP_CLK SFI4.2 line timing  */
              rtn |= ten_hsif_slc3_mr10x5_sds_common_srx0_rx_spare(module_id, TEN_INSTANCE_ALL, 
                         tmp_slc3_mr10x5_sds_common_srx0_rx_spare.wrd | 0x0040);
            }
          }
          else {
            /* disable loopback, restore the previously-saved state */                 
            if (sl == TEN_SLICE0) {
              rtn |= ten_hsif_slc0_mr10x4_sds_common_stxp0_tx_clkout_ctrl(module_id, 
                         saved->save_slc0_mr10x4_sds_common_stxp0_tx_clkout_ctrl[TEN_MOD_ID_TO_MOD_NUM(module_id)][sl]);
                         
              tmp_slc0_mr10x4_sds_common_srx0_rx_spare.wrd = TEN_REG_READ(TEN_HSIF_SLC0_MR10X4_REG_ADDR(pDev, 
                                                                          module_id, SRX0_RX_SPARE));
              /* spare 6:  clear RXLP_CLK SFI4.2 line timing  */
              rtn |= ten_hsif_slc0_mr10x4_sds_common_srx0_rx_spare(module_id, TEN_INSTANCE_ALL, 
                         tmp_slc0_mr10x4_sds_common_srx0_rx_spare.wrd & ~0x0040);          
            }
            if (sl == TEN_SLICE1) {
              rtn |= ten_hsif_slc1_mr10x5_sds_common_stxp0_tx_clkout_ctrl(module_id, 
                         saved->save_slc1_mr10x5_sds_common_stxp0_tx_clkout_ctrl[TEN_MOD_ID_TO_MOD_NUM(module_id)][sl]);
              tmp_slc1_mr10x5_sds_common_srx0_rx_spare.wrd = TEN_REG_READ(TEN_HSIF_SLC1_MR10X5_REG_ADDR(pDev, 
                                                                            module_id, SRX0_RX_SPARE));
              /*  spare 6:  clear RXLP_CLK SFI4.2 line timing  */
              rtn |= ten_hsif_slc1_mr10x5_sds_common_srx0_rx_spare(module_id, TEN_INSTANCE_ALL, 
                         tmp_slc1_mr10x5_sds_common_srx0_rx_spare.wrd & ~0x0040);
                         
            }
            if (sl == TEN_SLICE2) {
              rtn |= ten_hsif_slc2_mr10x4_sds_common_stxp0_tx_clkout_ctrl(module_id, 
                         saved->save_slc2_mr10x4_sds_common_stxp0_tx_clkout_ctrl[TEN_MOD_ID_TO_MOD_NUM(module_id)][sl]);
                         
              tmp_slc2_mr10x4_sds_common_srx0_rx_spare.wrd = TEN_REG_READ(TEN_HSIF_SLC2_MR10X4_REG_ADDR(pDev, 
                                                                          module_id, SRX0_RX_SPARE));
              /* spare 6:  clear RXLP_CLK SFI4.2 line timing  */
              rtn |= ten_hsif_slc2_mr10x4_sds_common_srx0_rx_spare(module_id, TEN_INSTANCE_ALL, 
                         tmp_slc2_mr10x4_sds_common_srx0_rx_spare.wrd & ~0x0040);
            }
            if (sl == TEN_SLICE3) {
              rtn |= ten_hsif_slc3_mr10x5_sds_common_stxp0_tx_clkout_ctrl(module_id,  
                         saved->save_slc3_mr10x5_sds_common_stxp0_tx_clkout_ctrl[TEN_MOD_ID_TO_MOD_NUM(module_id)][sl]);
                         
              tmp_slc3_mr10x5_sds_common_srx0_rx_spare.wrd = TEN_REG_READ(TEN_HSIF_SLC3_MR10X5_REG_ADDR(pDev, 
                                                                          module_id, SRX0_RX_SPARE));
              /* set spare 6:  enable for RXLP_CLK SFI4.2 line timing  */
              rtn |= ten_hsif_slc3_mr10x5_sds_common_srx0_rx_spare(module_id, TEN_INSTANCE_ALL, 
                         tmp_slc3_mr10x5_sds_common_srx0_rx_spare.wrd & ~0x0040);
            }
          }
        }
        else {
          /* SFI5.1 40G */
          /* Control LOOPCKSEL for slice 0 only since this parm is per module, not slice */
          if (sl == TEN_SLICE0) {
            if (ctl == CS_ENABLE) {
              tmp_refclk_cfg.wrd = TEN_REG_READ(TEN_HSIF_REG_ADDR(pDev, module_id, REFCLK_CFG));
              saved->save_hsif_set_refclk_cfg[TEN_MOD_ID_TO_MOD_NUM(module_id)] = tmp_refclk_cfg.bf.LOOPCKSEL;
              /* loop timing required - for 40G MR */
              rtn |= ten_hsif_set_refclk_cfg(module_id, TEN_HSIF_REFCLK_CFG_LOOPCKSEL, 1);
            }
            else {
              /* disable loopback, restore state */
              /* loop timing required - for 40G MR */
              rtn |= ten_hsif_set_refclk_cfg(module_id, TEN_HSIF_REFCLK_CFG_LOOPCKSEL,
                       saved->save_hsif_set_refclk_cfg[TEN_MOD_ID_TO_MOD_NUM(module_id)]);
            }
          }
        }
        
        break;

     case (TEN_HSIF_LOOPBACK_FACILITY_XFI):
        tmp_lbcfg.wrd = TEN_REG_READ(TEN_HSIF_REG_ADDR(pDev, module_id, LBCFG));

        /* check if loopback is already enabled */
        if (ctl == CS_ENABLE) {
          if ((sl == TEN_SLICE3) && (tmp_lbcfg.bf.rxtxlb3_en == 1)) {
            CS_PRINT_OUTPUT("Slice 3 is already in loopback.\n");
            break;
          }
          if ((sl == TEN_SLICE2) && (tmp_lbcfg.bf.rxtxlb2_en == 1)) {
            CS_PRINT_OUTPUT("Slice 2 is already in loopback.\n");
            break;
          }
          if ((sl == TEN_SLICE1) && (tmp_lbcfg.bf.rxtxlb1_en == 1)) {
            CS_PRINT_OUTPUT("Slice 1 is already in loopback.\n");
            break;
          }
          if ((sl == TEN_SLICE0) && (tmp_lbcfg.bf.rxtxlb0_en == 1)) {
            CS_PRINT_OUTPUT("Slice 0 is already in loopback.\n");
            break;
          }
        }

        /* check if loopback is already disabled */
        if (ctl == CS_DISABLE) {
          if ((sl == TEN_SLICE3) && (tmp_lbcfg.bf.rxtxlb3_en == 0)) {
            CS_PRINT_OUTPUT("Slice 3 is already out of loopback.\n");
            break;
          }
          if ((sl == TEN_SLICE2) && (tmp_lbcfg.bf.rxtxlb2_en == 0)) {
            CS_PRINT_OUTPUT("Slice 2 is already out of loopback.\n");
            break;
          }
          if ((sl == TEN_SLICE1) && (tmp_lbcfg.bf.rxtxlb1_en == 0)) {
            CS_PRINT_OUTPUT("Slice 1 is already out of loopback.\n");
            break;
          }
          if ((sl == TEN_SLICE0) && (tmp_lbcfg.bf.rxtxlb0_en == 0)) {
            CS_PRINT_OUTPUT("Slice 0 is already out of loopback.\n");
            break;
          }
        }
        
        if (ctl == CS_ENABLE) {
          /* Bugzilla #26282:  loopback API needs to disable all clock protection */
          /* save clock protection settings */
          rtn |= ten_hsif_save_clock_protection_settings(module_id, slice, sl, saved);
          rtn |= ten_hsif_facility_loopback(module_id, sl, ctl);
        
          /* enable loopback, saved->save state */
          /* Bug #38240: XFI Facility and rx2tx loopbacks need fix for XFI internal clock fanout mode. */
          tmp_stxp0_tx_config.wrd = TEN_REG_READ(TEN_XFI32X1_REG_ADDR(pDev, module_id, sl, STXP0_TX_CONFIG));
          saved->save_xfi32x1_stxp0_tx_lptime_sel[TEN_MOD_ID_TO_MOD_NUM(module_id)][sl] =
             tmp_stxp0_tx_config.bf.STXP_LPTIME_SEL | (tmp_stxp0_tx_config.bf.STXP_LPTIME_SEL_MSB << 2);

          tmp_stxp0_tx_clkdiv_ctrl.wrd = TEN_REG_READ(TEN_XFI32X1_REG_ADDR(pDev, module_id, sl, STXP0_TX_CLKDIV_CTRL));
          saved->save_xfi32x1_stxp0_tx_clkdiv_ctrl[TEN_MOD_ID_TO_MOD_NUM(module_id)][sl] =
             tmp_stxp0_tx_clkdiv_ctrl.wrd;

          /* loop timing required */
          rtn |= ten_xfi32x1_stxp0_tx_lptime_sel(module_id, sl, 2);
          /* must change RDIV to div16 (from div64) and CTVDIV to div4 (from div1) */

          /* Bug #38240: XFI Facility and rx2tx loopbacks need fix for XFI internal clock fanout mode. */
          rtn |= ten_xfi32x1_stxp0_tx_config_lptime_sel_msb_t41(module_id, sl, 0); 
          
          /* Bugzilla #28260, fix XFI facility loopback, 10G/40G */
          rtn |= ten_xfi32x1_stxp0_tx_clkdiv_ctrl_ctv_div(module_id, sl, 2);
          rtn |= ten_xfi32x1_stxp0_tx_clkdiv_ctrl_rdiv_sel(module_id, sl, 0);
         
          /* Bugzilla #36075 - fix TEN_HSIF_LOOPBACK_FACILITY_XFI fails with 4/2 GFC when using CUPLL */
          /* If CUPLL is enabled, apply additional setting for loopback */
          /* Bugzilla #36418 - T40 XFI Facility loopback has error message due to T41 addition */
          if (ten_dev_is_t41(TEN_MOD_ID_TO_DEV_ID(module_id))) {
            if (!ten_mpif_get_global_reset_cupll_mpif_t41(TEN_MOD_ID_TO_DEV_ID(module_id), sl)) {
              tmp_stxp0_tx_spare.wrd = TEN_REG_READ(TEN_XFI32X1_REG_ADDR(pDev, module_id, sl, STXP0_TX_SPARE));
              CS_PRINT("tmp_stxp0_tx_spare.bf.STXP_REFCLK_DIV_SEL = %d\n", tmp_stxp0_tx_spare.bf.STXP_REFCLK_DIV_SEL);
              saved->save_xfi32x1_stxp0_tx_spare_refclk_div_sel[TEN_MOD_ID_TO_MOD_NUM(module_id)][sl] =
                tmp_stxp0_tx_spare.bf.STXP_REFCLK_DIV_SEL;
              rtn |= ten_xfi32x1_stxp0_tx_spare_refclk_div_sel_t41(module_id, sl, 0);
            }
          }
        }
        else {
          rtn |= ten_hsif_facility_loopback(module_id, sl, ctl);
        
          /* disable loopback, restore state */
          /* loop timing required */
          rtn |= ten_xfi32x1_stxp0_tx_lptime_sel(module_id, sl,
                    (saved->save_xfi32x1_stxp0_tx_lptime_sel[TEN_MOD_ID_TO_MOD_NUM(module_id)][sl])&0x3);

          CS_PRINT("current structure value of ten_hsif_loopback_settings_struct_version_num = %d\n", saved->save_xfi32x1_stxp0_tx_lptime_sel[TEN_MODULE_A][0]);
          CS_PRINT("current software value of ten_hsif_loopback_settings_struct_version_num = %d\n", TEN_HSIF_LOOPBACK_SETTINGS_STRUCT_VERSION_NUM);
    
          /* only the structure of version 5110 and above has the lptime_sel_msb settings saved */
          /* do not try to restore these settings with old version of structure */
          if (saved->save_xfi32x1_stxp0_tx_lptime_sel[TEN_MODULE_A][0] >= TEN_HSIF_LOOPBACK_SETTINGS_STRUCT_VERSION_NUM_5110) {
            rtn |= ten_xfi32x1_stxp0_tx_config_lptime_sel_msb_t41(module_id, sl, 
                      (saved->save_xfi32x1_stxp0_tx_lptime_sel[TEN_MOD_ID_TO_MOD_NUM(module_id)][sl])>>2);
          }
                    
          /* must change RDIV to div16 (from div64) and CTVDIV to div4 (from div1) */
          /* rtn |= ten_xfi32x1_stxp0_tx_clkdiv_ctrl(module_id, slice, 3, 0, 2, 0, 0); */
          TEN_REG_WRITE(TEN_XFI32X1_REG_ADDR(pDev, module_id, sl, STXP0_TX_CLKDIV_CTRL),
            saved->save_xfi32x1_stxp0_tx_clkdiv_ctrl[TEN_MOD_ID_TO_MOD_NUM(module_id)][sl]);
            
          /* Bugzilla #36075 - fix TEN_HSIF_LOOPBACK_FACILITY_XFI fails with 4/2 GFC when using CUPLL */
          /* If CUPLL is enabled, apply additional setting for loopback */
          /* Bugzilla #36418 - T40 XFI Facility loopback has error message due to T41 addition */
          if (ten_dev_is_t41(TEN_MOD_ID_TO_DEV_ID(module_id))) {
            if (!ten_mpif_get_global_reset_cupll_mpif_t41(TEN_MOD_ID_TO_DEV_ID(module_id), sl)) {
              rtn |= ten_xfi32x1_stxp0_tx_spare_refclk_div_sel_t41(module_id, sl, 
                       saved->save_xfi32x1_stxp0_tx_spare_refclk_div_sel[TEN_MOD_ID_TO_MOD_NUM(module_id)][sl]);
                       
              ten_cupll_reset_t41(module_id, sl, TEN_XFI_CUPLL_RESET_CUPLL_DIG, CS_RESET_TOGGLE);
              ten_mpif_cupll_settle_force_t41(TEN_MOD_ID_TO_DEV_ID(module_id), sl, 2, CS_ENABLE);
              ten_mpif_cupll_settle_force_t41(TEN_MOD_ID_TO_DEV_ID(module_id), sl, 2, CS_DISABLE);
            }
          }
          
          /* restore clock protection settings */
          rtn |= ten_hsif_restore_clock_protection_settings(module_id, slice, sl, saved);
        }
        break;

      case (TEN_HSIF_LOOPBACK_FACILITY_EXT):
        tmp_lbcfg.wrd = TEN_REG_READ(TEN_HSIF_REG_ADDR(pDev, module_id, LBCFG));

        /* check if loopback is already enabled */
        if (ctl == CS_ENABLE) {
          if ((sl == TEN_SLICE3) && (tmp_lbcfg.bf.rxtxlb3_en == 1)) {
            CS_PRINT_OUTPUT("Slice 3 is already in loopback.\n");
            break;
          }
          if ((sl == TEN_SLICE2) && (tmp_lbcfg.bf.rxtxlb2_en == 1)) {
            CS_PRINT_OUTPUT("Slice 2 is already in loopback.\n");
            break;
          }
          if ((sl == TEN_SLICE1) && (tmp_lbcfg.bf.rxtxlb1_en == 1)) {
            CS_PRINT_OUTPUT("Slice 1 is already in loopback.\n");
            break;
          }
          if ((sl == TEN_SLICE0) && (tmp_lbcfg.bf.rxtxlb0_en == 1)) {
            CS_PRINT_OUTPUT("Slice 0 is already in loopback.\n");
            break;
          }
        }

        /* check if loopback is already disabled */
        if (ctl == CS_DISABLE) {
          if ((sl == TEN_SLICE3) && (tmp_lbcfg.bf.rxtxlb3_en == 0)) {
            CS_PRINT_OUTPUT("Slice 3 is already out of loopback.\n");
            break;
          }
          if ((sl == TEN_SLICE2) && (tmp_lbcfg.bf.rxtxlb2_en == 0)) {
            CS_PRINT_OUTPUT("Slice 2 is already out of loopback.\n");
            break;
          }
          if ((sl == TEN_SLICE1) && (tmp_lbcfg.bf.rxtxlb1_en == 0)) {
            CS_PRINT_OUTPUT("Slice 1 is already out of loopback.\n");
            break;
          }
          if ((sl == TEN_SLICE0) && (tmp_lbcfg.bf.rxtxlb0_en == 0)) {
            CS_PRINT_OUTPUT("Slice 0 is already out of loopback.\n");
            break;
          }
        }

        /* Bugzilla #26282:  loopback API needs to disable all clock protection */
        if (ctl == CS_ENABLE) {
          /* save clock protection settings */
          rtn |= ten_hsif_save_clock_protection_settings(module_id, slice, sl, saved);
        }
        else {
          /* restore clock protection settings */
          rtn |= ten_hsif_restore_clock_protection_settings(module_id, slice, sl, saved);
        }
        
        rtn |= ten_hsif_facility_loopback(module_id, sl, ctl);
        break;

      case (TEN_HSIF_LOOPBACK_FACILITY_MR10G):
        tmp_lbcfg.wrd = TEN_REG_READ(TEN_HSIF_REG_ADDR(pDev, module_id, LBCFG));

        /* check if loopback is already enabled */
        if (ctl == CS_ENABLE) {
          if ((sl == TEN_SLICE3) && (tmp_lbcfg.bf.rxtxlb3_en == 1)) {
            CS_PRINT_OUTPUT("Slice 3 is already in loopback.\n");
            break;
          }
          if ((sl == TEN_SLICE2) && (tmp_lbcfg.bf.rxtxlb2_en == 1)) {
            CS_PRINT_OUTPUT("Slice 2 is already in loopback.\n");
            break;
          }
          if ((sl == TEN_SLICE1) && (tmp_lbcfg.bf.rxtxlb1_en == 1)) {
            CS_PRINT_OUTPUT("Slice 1 is already in loopback.\n");
            break;
          }
          if ((sl == TEN_SLICE0) && (tmp_lbcfg.bf.rxtxlb0_en == 1)) {
            CS_PRINT_OUTPUT("Slice 0 is already in loopback.\n");
            break;
          }
        }

        /* check if loopback is already disabled */
        if (ctl == CS_DISABLE) {
          if ((sl == TEN_SLICE3) && (tmp_lbcfg.bf.rxtxlb3_en == 0)) {
            CS_PRINT_OUTPUT("Slice 3 is already out of loopback.\n");
            break;
          }
          if ((sl == TEN_SLICE2) && (tmp_lbcfg.bf.rxtxlb2_en == 0)) {
            CS_PRINT_OUTPUT("Slice 2 is already out of loopback.\n");
            break;
          }
          if ((sl == TEN_SLICE1) && (tmp_lbcfg.bf.rxtxlb1_en == 0)) {
            CS_PRINT_OUTPUT("Slice 1 is already out of loopback.\n");
            break;
          }
          if ((sl == TEN_SLICE0) && (tmp_lbcfg.bf.rxtxlb0_en == 0)) {
            CS_PRINT_OUTPUT("Slice 0 is already out of loopback.\n");
            break;
          }
        }
         
        /* Bugzilla #26282:  loopback API needs to disable all clock protection */
        if (ctl == CS_ENABLE) {
          /* save clock protection settings */
          rtn |= ten_hsif_save_clock_protection_settings(module_id, slice, sl, saved);
        }
        else {
          /* restore clock protection settings */
          rtn |= ten_hsif_restore_clock_protection_settings(module_id, slice, sl, saved);
        }
        
        /* can't use same routine as 40G MR */
        rtn |= ten_hsif_facility_loopback(module_id, sl, ctl);

        if (ctl == CS_ENABLE) {
          /* enable loopback */
          rtn |= ten_hsif_set_refclk_cfg(module_id, TEN_HSIF_REFCLK_CFG_LOOPCKSEL, 1);

          /* loop timing required for 10G MR - requires setting up the clkout divider to match the TX divider */
          /* so we need to read the TX divider to determine how to set the clkout divder */
          if (sl == TEN_SLICE0) {
            tmp_slc0_mr10x4_sds_common_stxp0_tx_clkdiv_ctrl.wrd = TEN_REG_READ(TEN_HSIF_SLC0_MR10X4_REG_ADDR(pDev, module_id, STXP0_TX_CLKDIV_CTRL));
            div = tmp_slc0_mr10x4_sds_common_stxp0_tx_clkdiv_ctrl.bf.STXP_RDIV_SEL + 0x30;

            tmp_slc0_mr10x4_sds_common_srx0_rx_clkout_ctrl.wrd = TEN_REG_READ(TEN_HSIF_SLC0_MR10X4_REG_ADDR(pDev, module_id, SRX0_RX_CLKOUT_CTRL));
            saved->save_hsif_slc0_mr10x4_sds_common_srx0_rx_clkout_ctrl_srx_tclko_sel[TEN_MOD_ID_TO_MOD_NUM(module_id)] =
               tmp_slc0_mr10x4_sds_common_srx0_rx_clkout_ctrl.bf.SRX_TCLKO_SEL;

            rtn |= ten_hsif_slc0_mr10x4_sds_common_srx0_rx_clkout_ctrl_srx_tclko_sel(module_id,
                                                                TEN_INSTANCE_ALL, div);
            /* enable looptiming */
            tmp_slc0_mr10x4_sds_common_stxp0_tx_config.wrd = TEN_REG_READ(TEN_HSIF_SLC0_MR10X4_REG_ADDR(pDev, module_id, STXP0_TX_CONFIG));
            saved->save_hsif_slc0_mr10x4_sds_common_stxp0_tx_config_lptime_sel[TEN_MOD_ID_TO_MOD_NUM(module_id)] =
                tmp_slc0_mr10x4_sds_common_stxp0_tx_config.bf.STXP_LPTIME_SEL;

            rtn |= ten_hsif_slc0_mr10x4_sds_common_stxp0_tx_config_lptime_sel(module_id, 1);
          }
          if (sl == TEN_SLICE1) {
            tmp_slc1_mr10x5_sds_common_stxp0_tx_clkdiv_ctrl.wrd = TEN_REG_READ(TEN_HSIF_SLC1_MR10X5_REG_ADDR(pDev, module_id, STXP0_TX_CLKDIV_CTRL));
            div = tmp_slc1_mr10x5_sds_common_stxp0_tx_clkdiv_ctrl.bf.STXP_RDIV_SEL + 0x30;

            tmp_slc1_mr10x5_sds_common_srx0_rx_clkout_ctrl.wrd = TEN_REG_READ(TEN_HSIF_SLC1_MR10X5_REG_ADDR(pDev, module_id, SRX0_RX_CLKOUT_CTRL));
            saved->save_hsif_slc1_mr10x5_sds_common_srx0_rx_clkout_ctrl_srx_tclko_sel[TEN_MOD_ID_TO_MOD_NUM(module_id)] =
                tmp_slc1_mr10x5_sds_common_srx0_rx_clkout_ctrl.bf.SRX_TCLKO_SEL;

            rtn |= ten_hsif_slc1_mr10x5_sds_common_srx0_rx_clkout_ctrl_srx_tclko_sel(module_id,
                                                                TEN_INSTANCE_ALL, div);

            tmp_slc1_mr10x5_sds_common_stxp0_tx_config.wrd = TEN_REG_READ(TEN_HSIF_SLC1_MR10X5_REG_ADDR(pDev, module_id, STXP0_TX_CONFIG));
            saved->save_hsif_slc1_mr10x5_sds_common_stxp0_tx_config_lptime_sel[TEN_MOD_ID_TO_MOD_NUM(module_id)] =
                tmp_slc1_mr10x5_sds_common_stxp0_tx_config.bf.STXP_LPTIME_SEL;
            /* enable looptiming */
            rtn |= ten_hsif_slc1_mr10x5_sds_common_stxp0_tx_config_lptime_sel(module_id, 1);
          }
          if (sl == TEN_SLICE2) {
            tmp_slc2_mr10x4_sds_common_stxp0_tx_clkdiv_ctrl.wrd = TEN_REG_READ(TEN_HSIF_SLC2_MR10X4_REG_ADDR(pDev, module_id, STXP0_TX_CLKDIV_CTRL));
            div = tmp_slc2_mr10x4_sds_common_stxp0_tx_clkdiv_ctrl.bf.STXP_RDIV_SEL + 0x30;

            tmp_slc2_mr10x4_sds_common_srx0_rx_clkout_ctrl.wrd = TEN_REG_READ(TEN_HSIF_SLC2_MR10X4_REG_ADDR(pDev, module_id, SRX0_RX_CLKOUT_CTRL));
            saved->save_hsif_slc2_mr10x4_sds_common_srx0_rx_clkout_ctrl_srx_tclko_sel[TEN_MOD_ID_TO_MOD_NUM(module_id)] =
                tmp_slc2_mr10x4_sds_common_srx0_rx_clkout_ctrl.bf.SRX_TCLKO_SEL;

            rtn |= ten_hsif_slc2_mr10x4_sds_common_srx0_rx_clkout_ctrl_srx_tclko_sel(module_id,
                                                                TEN_INSTANCE_ALL, div);

            tmp_slc2_mr10x4_sds_common_stxp0_tx_config.wrd = TEN_REG_READ(TEN_HSIF_SLC2_MR10X4_REG_ADDR(pDev, module_id, STXP0_TX_CONFIG));
            saved->save_hsif_slc2_mr10x4_sds_common_stxp0_tx_config_lptime_sel[TEN_MOD_ID_TO_MOD_NUM(module_id)] =
                tmp_slc2_mr10x4_sds_common_stxp0_tx_config.bf.STXP_LPTIME_SEL;
            /* enable looptiming */
            rtn |= ten_hsif_slc2_mr10x4_sds_common_stxp0_tx_config_lptime_sel(module_id, 1);
          }
          if (sl == TEN_SLICE3) {
            tmp_slc3_mr10x5_sds_common_stxp0_tx_clkdiv_ctrl.wrd = TEN_REG_READ(TEN_HSIF_SLC3_MR10X5_REG_ADDR(pDev, module_id, STXP0_TX_CLKDIV_CTRL));
            div = tmp_slc3_mr10x5_sds_common_stxp0_tx_clkdiv_ctrl.bf.STXP_RDIV_SEL + 0x30;

            tmp_slc3_mr10x5_sds_common_srx0_rx_clkout_ctrl.wrd = TEN_REG_READ(TEN_HSIF_SLC3_MR10X5_REG_ADDR(pDev, module_id, SRX0_RX_CLKOUT_CTRL));
            saved->save_hsif_slc3_mr10x5_sds_common_srx0_rx_clkout_ctrl_srx_tclko_sel[TEN_MOD_ID_TO_MOD_NUM(module_id)] =
                tmp_slc3_mr10x5_sds_common_srx0_rx_clkout_ctrl.bf.SRX_TCLKO_SEL;

            rtn |= ten_hsif_slc3_mr10x5_sds_common_srx0_rx_clkout_ctrl_srx_tclko_sel(module_id,
                                                                TEN_INSTANCE_ALL, div);
            tmp_slc3_mr10x5_sds_common_stxp0_tx_config.wrd = TEN_REG_READ(TEN_HSIF_SLC3_MR10X5_REG_ADDR(pDev, module_id, STXP0_TX_CONFIG));
            saved->save_hsif_slc3_mr10x5_sds_common_stxp0_tx_config_lptime_sel[TEN_MOD_ID_TO_MOD_NUM(module_id)] =
                tmp_slc3_mr10x5_sds_common_stxp0_tx_config.bf.STXP_LPTIME_SEL;

            /* enable looptiming */
            rtn |= ten_hsif_slc3_mr10x5_sds_common_stxp0_tx_config_lptime_sel(module_id, 1);
          }
        }
        else {
          /* disable loopback, restore state */

          /* loop timing required */
          rtn |= ten_hsif_set_refclk_cfg(module_id, TEN_HSIF_REFCLK_CFG_LOOPCKSEL, 0);

          /* loop timing required for 10G MR - requires setting up the clkout divider to match the TX divider */
          /* so we need to read the TX divider to determine how to set the clkout divder */
          if (sl == TEN_SLICE0) {
            rtn |= ten_hsif_slc0_mr10x4_sds_common_srx0_rx_clkout_ctrl_srx_tclko_sel(module_id,
                                                                TEN_INSTANCE_ALL,
                                                                saved->save_hsif_slc0_mr10x4_sds_common_srx0_rx_clkout_ctrl_srx_tclko_sel[TEN_MOD_ID_TO_MOD_NUM(module_id)]);
            /* enable looptiming */
            rtn |= ten_hsif_slc0_mr10x4_sds_common_stxp0_tx_config_lptime_sel(module_id,
                     saved->save_hsif_slc0_mr10x4_sds_common_stxp0_tx_config_lptime_sel[TEN_MOD_ID_TO_MOD_NUM(module_id)]);
          }
          if (sl == TEN_SLICE1) {
            rtn |= ten_hsif_slc1_mr10x5_sds_common_srx0_rx_clkout_ctrl_srx_tclko_sel(module_id,
                                                                TEN_INSTANCE_ALL,
                                                                saved->save_hsif_slc1_mr10x5_sds_common_srx0_rx_clkout_ctrl_srx_tclko_sel[TEN_MOD_ID_TO_MOD_NUM(module_id)]);
            /* enable looptiming */
            rtn |= ten_hsif_slc1_mr10x5_sds_common_stxp0_tx_config_lptime_sel(module_id,
                       saved->save_hsif_slc1_mr10x5_sds_common_stxp0_tx_config_lptime_sel[TEN_MOD_ID_TO_MOD_NUM(module_id)]);
          }
          if (sl == TEN_SLICE2) {
            rtn |= ten_hsif_slc2_mr10x4_sds_common_srx0_rx_clkout_ctrl_srx_tclko_sel(module_id,
                                                                TEN_INSTANCE_ALL,
                                                                saved->save_hsif_slc2_mr10x4_sds_common_srx0_rx_clkout_ctrl_srx_tclko_sel[TEN_MOD_ID_TO_MOD_NUM(module_id)]);

            /* enable looptiming */
            rtn |= ten_hsif_slc2_mr10x4_sds_common_stxp0_tx_config_lptime_sel(module_id,
                       saved->save_hsif_slc2_mr10x4_sds_common_stxp0_tx_config_lptime_sel[TEN_MOD_ID_TO_MOD_NUM(module_id)]);

          }
          if (sl == TEN_SLICE3) {
            rtn |= ten_hsif_slc3_mr10x5_sds_common_srx0_rx_clkout_ctrl_srx_tclko_sel(module_id,
                                                                TEN_INSTANCE_ALL,
                                                                saved->save_hsif_slc3_mr10x5_sds_common_srx0_rx_clkout_ctrl_srx_tclko_sel[TEN_MOD_ID_TO_MOD_NUM(module_id)]);

            /* enable looptiming */
            rtn |= ten_hsif_slc3_mr10x5_sds_common_stxp0_tx_config_lptime_sel(module_id,
                       saved->save_hsif_slc3_mr10x5_sds_common_stxp0_tx_config_lptime_sel[TEN_MOD_ID_TO_MOD_NUM(module_id)]);
          }
        }
        break;

      case (TEN_HSIF_LOOPBACK_FAR_END):
        tmp_lbcfg.wrd = TEN_REG_READ(TEN_HSIF_REG_ADDR(pDev, module_id, LBCFG));

        /* check if loopback is already enabled */
        if (ctl == CS_ENABLE) {
          if ((sl == TEN_SLICE3) && (tmp_lbcfg.bf.txrxlb3_en == 1)) {
            CS_PRINT_OUTPUT("Slice 3 already in loopback.\n");
            break;
          }
          if ((sl == TEN_SLICE2) && (tmp_lbcfg.bf.txrxlb2_en == 1)) {
            CS_PRINT_OUTPUT("Slice 2 already in loopback.\n");
            break;
          }

          if ((sl == TEN_SLICE1) && (tmp_lbcfg.bf.txrxlb1_en == 1)) {
            CS_PRINT_OUTPUT("Slice 1 already in loopback.\n");
            break;
          }

          if ((sl == TEN_SLICE0) && (tmp_lbcfg.bf.txrxlb0_en == 1)) {
            CS_PRINT_OUTPUT("Slice 0 already in loopback.\n");
            break;
          }
        }

        /* check if loopback is already disabled */
        if (ctl == CS_DISABLE) {
          if ((sl == TEN_SLICE3) && (tmp_lbcfg.bf.txrxlb3_en == 0)) {
            CS_PRINT_OUTPUT("Slice 3 is already out of loopback.\n");
            break;
          }

          if ((sl == TEN_SLICE2) && (tmp_lbcfg.bf.txrxlb2_en == 0)) {
            CS_PRINT_OUTPUT("Slice 2 is already out of loopback.\n");
            break;
          }

          if ((sl == TEN_SLICE1) && (tmp_lbcfg.bf.txrxlb1_en == 0)) {
            CS_PRINT_OUTPUT("Slice 1 is already out of loopback.\n");
            break;
          }

          if ((sl == TEN_SLICE0) && (tmp_lbcfg.bf.txrxlb0_en == 0)) {
            CS_PRINT_OUTPUT("Slice 0 is already out of loopback.\n");
            break;
          }
        }

        /* Bugzilla #26282:  loopback API needs to disable all clock protection */
        if (ctl == CS_ENABLE) {
          /* save clock protection settings */
          rtn |= ten_hsif_save_clock_protection_settings(module_id, slice, sl, saved);
        }
        else {
          /* restore clock protection settings */
          rtn |= ten_hsif_restore_clock_protection_settings(module_id, slice, sl, saved);
        }
        
        rtn |= ten_hsif_far_end_loopback(module_id, sl, ctl);
        rtn |= ten_mpif_clock_select_gpll_in(TEN_MOD_ID_TO_DEV_ID(module_id),
                                             TEN_MOD_ID_TO_MOD_NUM(module_id), sl, CS_RX, ctl);
        if (ctl == CS_ENABLE) {
          /* enable loopback, saved->save state */

          /* force OK to 1 since we don't care about the serdes status */
          tmp_ok_ctrl.wrd = TEN_REG_READ(TEN_HSIF_REG_ADDR(pDev, module_id, OK_CTRL));
  
          /* Bugzilla #23631, bitfields not broken out here, correct the shifting  */
          saved->save_hsif_set_ok_ctrl_xlos_en[TEN_MOD_ID_TO_DEV_ID(module_id)][sl] =
              ((tmp_ok_ctrl.bf.xlos_en & (1<<sl)) == (1<<sl));

          saved->save_hsif_set_ok_ctrl_lock_en[TEN_MOD_ID_TO_DEV_ID(module_id)][sl] =
              ((tmp_ok_ctrl.bf.lock_en & (1<<sl)) == (1<<sl));

          saved->save_hsif_set_ok_ctrl_datadet_en[TEN_MOD_ID_TO_DEV_ID(module_id)][sl] =
              ((tmp_ok_ctrl.bf.datadet_en & (1<<sl)) == (1<<sl));

          saved->save_hsif_set_ok_ctrl_synced_en[TEN_MOD_ID_TO_DEV_ID(module_id)][sl] =
              ((tmp_ok_ctrl.bf.synced_en & (1<<sl)) == (1<<sl));

          rtn |= ten_hsif_set_ok_ctrl(module_id, sl, TEN_HSIF_OK_CTRL_XLOS_EN,    0);
          rtn |= ten_hsif_set_ok_ctrl(module_id, sl, TEN_HSIF_OK_CTRL_LOCK_EN,    0);
          rtn |= ten_hsif_set_ok_ctrl(module_id, sl, TEN_HSIF_OK_CTRL_DATADET_EN, 0);
          rtn |= ten_hsif_set_ok_ctrl(module_id, sl, TEN_HSIF_OK_CTRL_SYNCED_EN,  0);

          /* Bug #41675: Save/Restore HSIF_PROTOCOL_PSWTCH_OK_CTRL during FAR END loopback */ 
          tmp_pswtch_ok_ctrl.wrd = TEN_REG_READ(TEN_HSIF_REG_ADDR(pDev, module_id, PSWTCH_OK_CTRL));
          saved->save_hsif_pswtch_ok_ctrl_xlos_en[TEN_MOD_ID_TO_DEV_ID(module_id)][sl] =
              ((tmp_pswtch_ok_ctrl.bf.xlos_en & (1<<sl)) == (1<<sl));

          saved->save_hsif_pswtch_ok_ctrl_lock_en[TEN_MOD_ID_TO_DEV_ID(module_id)][sl] =
              ((tmp_pswtch_ok_ctrl.bf.lock_en & (1<<sl)) == (1<<sl));

          saved->save_hsif_pswtch_ok_ctrl_datadet_en[TEN_MOD_ID_TO_DEV_ID(module_id)][sl] =
              ((tmp_pswtch_ok_ctrl.bf.datadet_en & (1<<sl)) == (1<<sl));

          saved->save_hsif_pswtch_ok_ctrl_synced_en[TEN_MOD_ID_TO_DEV_ID(module_id)][sl] =
              ((tmp_pswtch_ok_ctrl.bf.synced_en & (1<<sl)) == (1<<sl));
              
          rtn |= ten_hsif_pswtch_ok_ctrl_xlos_en(module_id, sl, 0);
          rtn |= ten_hsif_pswtch_ok_ctrl_lock_en(module_id, sl, 0);
          rtn |= ten_hsif_pswtch_ok_ctrl_datadet_en(module_id, sl, 0);
          rtn |= ten_hsif_pswtch_ok_ctrl_synced_en(module_id, sl, 0);
          /* Bugzilla #26282:  loopback API needs to disable all clock protection, this code put in subroutine */
        }
        else {
          /* disable loopback, restore state */
          rtn |= ten_hsif_set_ok_ctrl(module_id, sl, TEN_HSIF_OK_CTRL_XLOS_EN,
                     saved->save_hsif_set_ok_ctrl_xlos_en[TEN_MOD_ID_TO_DEV_ID(module_id)][sl]);

          rtn |= ten_hsif_set_ok_ctrl(module_id, sl, TEN_HSIF_OK_CTRL_LOCK_EN,
                     saved->save_hsif_set_ok_ctrl_lock_en[TEN_MOD_ID_TO_DEV_ID(module_id)][sl]);

          rtn |= ten_hsif_set_ok_ctrl(module_id, sl, TEN_HSIF_OK_CTRL_DATADET_EN,
                     saved->save_hsif_set_ok_ctrl_datadet_en[TEN_MOD_ID_TO_DEV_ID(module_id)][sl]);

          rtn |= ten_hsif_set_ok_ctrl(module_id, sl, TEN_HSIF_OK_CTRL_SYNCED_EN,
                     saved->save_hsif_set_ok_ctrl_synced_en[TEN_MOD_ID_TO_DEV_ID(module_id)][sl]);
                     
          /* Bug #41675: Save/Restore HSIF_PROTOCOL_PSWTCH_OK_CTRL during FAR END loopback */ 
          CS_PRINT("current structure value of ten_hsif_loopback_settings_struct_version_num = %d\n", saved->save_xfi32x1_stxp0_tx_lptime_sel[TEN_MODULE_A][0]);
          CS_PRINT("current software value of ten_hsif_loopback_settings_struct_version_num = %d\n", TEN_HSIF_LOOPBACK_SETTINGS_STRUCT_VERSION_NUM);
    
          /* only the structure of version 5120 and above has the pswtch settings saved */
          /* do not try to restore these settings with old version of structure */
          if (saved->save_xfi32x1_stxp0_tx_lptime_sel[TEN_MODULE_A][0] >= TEN_HSIF_LOOPBACK_SETTINGS_STRUCT_VERSION_NUM_5120) {
            rtn |= ten_hsif_pswtch_ok_ctrl_xlos_en(module_id, sl, saved->save_hsif_pswtch_ok_ctrl_xlos_en[TEN_MOD_ID_TO_DEV_ID(module_id)][sl]);
            rtn |= ten_hsif_pswtch_ok_ctrl_lock_en(module_id, sl, saved->save_hsif_pswtch_ok_ctrl_lock_en[TEN_MOD_ID_TO_DEV_ID(module_id)][sl]);
            rtn |= ten_hsif_pswtch_ok_ctrl_datadet_en(module_id, sl, saved->save_hsif_pswtch_ok_ctrl_datadet_en[TEN_MOD_ID_TO_DEV_ID(module_id)][sl]);
            rtn |= ten_hsif_pswtch_ok_ctrl_synced_en(module_id, sl, saved->save_hsif_pswtch_ok_ctrl_synced_en[TEN_MOD_ID_TO_DEV_ID(module_id)][sl]);
          }
        }
        break;

      case (TEN_HSIF_LOOPBACK_MR_RX2TX):

       /* THIS LOOPBACK DOES NOT WORK WITH SFI4.2  */
       if (ten_hsif_is_sfi42_active(module_id, sl)) { 
         CS_PRINT_OUTPUT("MR RX2TX loopback does not work with SFI4.2, use MR_FACILITY instead.\n");
         CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": MR RX2TX loopback does not work with SFI4.2");
         rtn = CS_ERROR;
         break;
       }
      
       /* check if loopback is already enabled */
       if (ctl == CS_ENABLE) {
         if (sl == TEN_SLICE3) {
            tmp_slc3_mr10x5_sds_common_tx0_config.wrd = TEN_REG_READ(TEN_HSIF_SLC3_MR10X5_REG_ADDR(pDev, module_id, TX0_Config));
            if (tmp_slc3_mr10x5_sds_common_tx0_config.bf.data_source == 2) {
              CS_PRINT_OUTPUT("Slice 3 is already in loopback.\n");
              break;
            }
          }
          if (sl == TEN_SLICE2) {
            tmp_slc2_mr10x4_sds_common_tx0_config.wrd = TEN_REG_READ(TEN_HSIF_SLC2_MR10X4_REG_ADDR(pDev, module_id, TX0_Config));
            if (tmp_slc2_mr10x4_sds_common_tx0_config.bf.data_source == 2) {
              CS_PRINT_OUTPUT("Slice 2 is already in loopback.\n");
              break;
            }
          }
          if (sl == TEN_SLICE1) {
            tmp_slc1_mr10x5_sds_common_tx0_config.wrd = TEN_REG_READ(TEN_HSIF_SLC1_MR10X5_REG_ADDR(pDev, module_id, TX0_Config));
            if (tmp_slc1_mr10x5_sds_common_tx0_config.bf.data_source == 2) {
              CS_PRINT_OUTPUT("Slice 1 is already in loopback.\n");
              break;
            }
          }
          if (sl == TEN_SLICE0) {
            tmp_slc0_mr10x4_sds_common_tx0_config.wrd = TEN_REG_READ(TEN_HSIF_SLC0_MR10X4_REG_ADDR(pDev, module_id, TX0_Config));
            if (tmp_slc0_mr10x4_sds_common_tx0_config.bf.data_source == 2) {
              CS_PRINT_OUTPUT("Slice 0 is already in loopback.\n");
              break;
            }
          }
        }

        /* check if loopback is already disabled */
        if (ctl == CS_DISABLE) {
          if (sl == TEN_SLICE3) {
            tmp_slc3_mr10x5_sds_common_tx0_config.wrd = TEN_REG_READ(TEN_HSIF_SLC3_MR10X5_REG_ADDR(pDev, module_id, TX0_Config));
            if (tmp_slc3_mr10x5_sds_common_tx0_config.bf.data_source == 0) {
              CS_PRINT_OUTPUT("Slice 3 is already out of loopback.\n");
              break;
            }
          }
          if (sl == TEN_SLICE2) {
            tmp_slc2_mr10x4_sds_common_tx0_config.wrd = TEN_REG_READ(TEN_HSIF_SLC2_MR10X4_REG_ADDR(pDev, module_id, TX0_Config));
            if (tmp_slc2_mr10x4_sds_common_tx0_config.bf.data_source == 0) {
              CS_PRINT_OUTPUT("Slice 2 is already out of loopback.\n");
              break;
            }
          }
          if (sl == TEN_SLICE1) {
            tmp_slc1_mr10x5_sds_common_tx0_config.wrd = TEN_REG_READ(TEN_HSIF_SLC1_MR10X5_REG_ADDR(pDev, module_id, TX0_Config));
            if (tmp_slc1_mr10x5_sds_common_tx0_config.bf.data_source == 0) {
              CS_PRINT_OUTPUT("Slice 1 is already out of loopback.\n");
              break;
            }
          }
          if (sl == TEN_SLICE0) {
            tmp_slc0_mr10x4_sds_common_tx0_config.wrd = TEN_REG_READ(TEN_HSIF_SLC0_MR10X4_REG_ADDR(pDev, module_id, TX0_Config));
            if (tmp_slc0_mr10x4_sds_common_tx0_config.bf.data_source == 0) {
              CS_PRINT_OUTPUT("Slice 0 is already out of loopback.\n");
              break;
            }
          }
        }

        /* Bugzilla #26282:  loopback API needs to disable all clock protection */
        if (ctl == CS_ENABLE) {
          /* save clock protection settings */
          rtn |= ten_hsif_save_clock_protection_settings(module_id, slice, sl, saved);
        }
        else {
          /* restore clock protection settings */
          rtn |= ten_hsif_restore_clock_protection_settings(module_id, slice, sl, saved);
        }
     
        if (ctl == CS_ENABLE) {
          data_source = 2;  /* 10 = RX Loopback Data */
        }
        else {
          data_source = 0;  /* 00 = DIG_TX_DIN */
        }

        if (sl == TEN_SLICE0) {
          rtn |= ten_hsif_slc0_mr10x4_sds_common_tx_config(module_id, TEN_INSTANCE_ALL, data_source);
        }
        if (sl == TEN_SLICE1) {
          rtn |= ten_hsif_slc1_mr10x5_sds_common_tx_config(module_id, TEN_INSTANCE_ALL, data_source);
        }
        if (sl == TEN_SLICE2) {
          rtn |= ten_hsif_slc2_mr10x4_sds_common_tx_config(module_id, TEN_INSTANCE_ALL, data_source);
        }
        if (sl == TEN_SLICE3) {
          rtn |= ten_hsif_slc3_mr10x5_sds_common_tx_config(module_id, TEN_INSTANCE_ALL, data_source);
        }
        
        /* loop timing required */
        if (ctl == CS_ENABLE) {
          /* Bugzilla #34893 - XAUI TEN_HSIF_LOOPBACK_MR_RX2TX has CRC errors */
          if (ten_hsif_is_xaui_active(module_id, sl)) {
            /* loop timing required for 10G MR - requires setting up the clkout divider to match the TX divider */
            /* so we need to read the TX divider to determine how to set the clkout divder */
            if (sl == TEN_SLICE0) {
              tmp_slc0_mr10x4_sds_common_stxp0_tx_clkdiv_ctrl.wrd = TEN_REG_READ(TEN_HSIF_SLC0_MR10X4_REG_ADDR(pDev, module_id, STXP0_TX_CLKDIV_CTRL));
              div = tmp_slc0_mr10x4_sds_common_stxp0_tx_clkdiv_ctrl.bf.STXP_RDIV_SEL + 0x30;

              tmp_slc0_mr10x4_sds_common_srx0_rx_clkout_ctrl.wrd = TEN_REG_READ(TEN_HSIF_SLC0_MR10X4_REG_ADDR(pDev, module_id, SRX0_RX_CLKOUT_CTRL));
              saved->save_hsif_slc0_mr10x4_sds_common_srx0_rx_clkout_ctrl_srx_tclko_sel[TEN_MOD_ID_TO_MOD_NUM(module_id)] =
                 tmp_slc0_mr10x4_sds_common_srx0_rx_clkout_ctrl.bf.SRX_TCLKO_SEL;

              rtn |= ten_hsif_slc0_mr10x4_sds_common_srx0_rx_clkout_ctrl_srx_tclko_sel(module_id,
                                                                  TEN_INSTANCE_ALL, div);
              tmp_slc0_mr10x4_sds_common_stxp0_tx_config.wrd = TEN_REG_READ(TEN_HSIF_SLC0_MR10X4_REG_ADDR(pDev, module_id, STXP0_TX_CONFIG));
              saved->save_hsif_slc0_mr10x4_sds_common_stxp0_tx_config_lptime_sel[TEN_MOD_ID_TO_MOD_NUM(module_id)] =
                  tmp_slc0_mr10x4_sds_common_stxp0_tx_config.bf.STXP_LPTIME_SEL;
              /* enable loop timing */
              rtn |= ten_hsif_slc0_mr10x4_sds_common_stxp0_tx_config_lptime_sel(module_id, 1);
            }
            if (sl == TEN_SLICE1) {
              tmp_slc1_mr10x5_sds_common_stxp0_tx_clkdiv_ctrl.wrd = TEN_REG_READ(TEN_HSIF_SLC1_MR10X5_REG_ADDR(pDev, module_id, STXP0_TX_CLKDIV_CTRL));
              div = tmp_slc1_mr10x5_sds_common_stxp0_tx_clkdiv_ctrl.bf.STXP_RDIV_SEL + 0x30;

              tmp_slc1_mr10x5_sds_common_srx0_rx_clkout_ctrl.wrd = TEN_REG_READ(TEN_HSIF_SLC1_MR10X5_REG_ADDR(pDev, module_id, SRX0_RX_CLKOUT_CTRL));
              saved->save_hsif_slc1_mr10x5_sds_common_srx0_rx_clkout_ctrl_srx_tclko_sel[TEN_MOD_ID_TO_MOD_NUM(module_id)] =
                  tmp_slc1_mr10x5_sds_common_srx0_rx_clkout_ctrl.bf.SRX_TCLKO_SEL;

              rtn |= ten_hsif_slc1_mr10x5_sds_common_srx0_rx_clkout_ctrl_srx_tclko_sel(module_id,
                                                                  TEN_INSTANCE_ALL, div);
                                                                  
              tmp_slc1_mr10x5_sds_common_stxp0_tx_config.wrd = TEN_REG_READ(TEN_HSIF_SLC1_MR10X5_REG_ADDR(pDev, module_id, STXP0_TX_CONFIG));
              saved->save_hsif_slc1_mr10x5_sds_common_stxp0_tx_config_lptime_sel[TEN_MOD_ID_TO_MOD_NUM(module_id)] =
                  tmp_slc1_mr10x5_sds_common_stxp0_tx_config.bf.STXP_LPTIME_SEL;
              /* enable loop timing */
              rtn |= ten_hsif_slc1_mr10x5_sds_common_stxp0_tx_config_lptime_sel(module_id, 1);
            }
            if (sl == TEN_SLICE2) {
              tmp_slc2_mr10x4_sds_common_stxp0_tx_clkdiv_ctrl.wrd = TEN_REG_READ(TEN_HSIF_SLC2_MR10X4_REG_ADDR(pDev, module_id, STXP0_TX_CLKDIV_CTRL));
              div = tmp_slc2_mr10x4_sds_common_stxp0_tx_clkdiv_ctrl.bf.STXP_RDIV_SEL + 0x30;

              tmp_slc2_mr10x4_sds_common_srx0_rx_clkout_ctrl.wrd = TEN_REG_READ(TEN_HSIF_SLC2_MR10X4_REG_ADDR(pDev, module_id, SRX0_RX_CLKOUT_CTRL));
              saved->save_hsif_slc2_mr10x4_sds_common_srx0_rx_clkout_ctrl_srx_tclko_sel[TEN_MOD_ID_TO_MOD_NUM(module_id)] =
                  tmp_slc2_mr10x4_sds_common_srx0_rx_clkout_ctrl.bf.SRX_TCLKO_SEL;

              rtn |= ten_hsif_slc2_mr10x4_sds_common_srx0_rx_clkout_ctrl_srx_tclko_sel(module_id,
                                                                  TEN_INSTANCE_ALL, div);
                                                                  
              tmp_slc2_mr10x4_sds_common_stxp0_tx_config.wrd = TEN_REG_READ(TEN_HSIF_SLC2_MR10X4_REG_ADDR(pDev, module_id, STXP0_TX_CONFIG));
              saved->save_hsif_slc2_mr10x4_sds_common_stxp0_tx_config_lptime_sel[TEN_MOD_ID_TO_MOD_NUM(module_id)] =
                  tmp_slc2_mr10x4_sds_common_stxp0_tx_config.bf.STXP_LPTIME_SEL;
              /* enable loop timing */
              rtn |= ten_hsif_slc2_mr10x4_sds_common_stxp0_tx_config_lptime_sel(module_id, 1);
            }
            if (sl == TEN_SLICE3) {
              tmp_slc3_mr10x5_sds_common_stxp0_tx_clkdiv_ctrl.wrd = TEN_REG_READ(TEN_HSIF_SLC3_MR10X5_REG_ADDR(pDev, module_id, STXP0_TX_CLKDIV_CTRL));
              div = tmp_slc3_mr10x5_sds_common_stxp0_tx_clkdiv_ctrl.bf.STXP_RDIV_SEL + 0x30;

              tmp_slc3_mr10x5_sds_common_srx0_rx_clkout_ctrl.wrd = TEN_REG_READ(TEN_HSIF_SLC3_MR10X5_REG_ADDR(pDev, module_id, SRX0_RX_CLKOUT_CTRL));
              saved->save_hsif_slc3_mr10x5_sds_common_srx0_rx_clkout_ctrl_srx_tclko_sel[TEN_MOD_ID_TO_MOD_NUM(module_id)] =
                  tmp_slc3_mr10x5_sds_common_srx0_rx_clkout_ctrl.bf.SRX_TCLKO_SEL;

              rtn |= ten_hsif_slc3_mr10x5_sds_common_srx0_rx_clkout_ctrl_srx_tclko_sel(module_id,
                                                                  TEN_INSTANCE_ALL, div);
                                                                  
              tmp_slc3_mr10x5_sds_common_stxp0_tx_config.wrd = TEN_REG_READ(TEN_HSIF_SLC3_MR10X5_REG_ADDR(pDev, module_id, STXP0_TX_CONFIG));
              saved->save_hsif_slc3_mr10x5_sds_common_stxp0_tx_config_lptime_sel[TEN_MOD_ID_TO_MOD_NUM(module_id)] =
                  tmp_slc3_mr10x5_sds_common_stxp0_tx_config.bf.STXP_LPTIME_SEL;
              /* enable loop timing */
              rtn |= ten_hsif_slc3_mr10x5_sds_common_stxp0_tx_config_lptime_sel(module_id, 1);
            }
           }
           else { /* 40G SFI5.1 */
             rtn |= ten_hsif_set_refclk_cfg(module_id, TEN_HSIF_REFCLK_CFG_LOOPCKSEL, 1);
           }
        }
        else { /* ctl == CS_DISABLE */
          if (ten_hsif_is_xaui_active(module_id, sl)) {
            /* disable loopback, restore state */

            /* loop timing required for 10G MR - requires setting up the clkout divider to match the TX divider */
            /* so we need to read the TX divider to determine how to set the clkout divder */
            if (sl == TEN_SLICE0) {
              rtn |= ten_hsif_slc0_mr10x4_sds_common_srx0_rx_clkout_ctrl_srx_tclko_sel(module_id,
                                                                  TEN_INSTANCE_ALL,
                                                                  saved->save_hsif_slc0_mr10x4_sds_common_srx0_rx_clkout_ctrl_srx_tclko_sel[TEN_MOD_ID_TO_MOD_NUM(module_id)]);
              rtn |= ten_hsif_slc0_mr10x4_sds_common_stxp0_tx_config_lptime_sel(module_id,
                       saved->save_hsif_slc0_mr10x4_sds_common_stxp0_tx_config_lptime_sel[TEN_MOD_ID_TO_MOD_NUM(module_id)]);
            }
            if (sl == TEN_SLICE1) {
              rtn |= ten_hsif_slc1_mr10x5_sds_common_srx0_rx_clkout_ctrl_srx_tclko_sel(module_id,
                                                                  TEN_INSTANCE_ALL,
                                                                  saved->save_hsif_slc1_mr10x5_sds_common_srx0_rx_clkout_ctrl_srx_tclko_sel[TEN_MOD_ID_TO_MOD_NUM(module_id)]);
              rtn |= ten_hsif_slc1_mr10x5_sds_common_stxp0_tx_config_lptime_sel(module_id, 
                        saved->save_hsif_slc1_mr10x5_sds_common_stxp0_tx_config_lptime_sel[TEN_MOD_ID_TO_MOD_NUM(module_id)]); 
            }
            if (sl == TEN_SLICE2) {
              rtn |= ten_hsif_slc2_mr10x4_sds_common_srx0_rx_clkout_ctrl_srx_tclko_sel(module_id,
                                                                  TEN_INSTANCE_ALL,
                                                                  saved->save_hsif_slc2_mr10x4_sds_common_srx0_rx_clkout_ctrl_srx_tclko_sel[TEN_MOD_ID_TO_MOD_NUM(module_id)]);

              rtn |= ten_hsif_slc2_mr10x4_sds_common_stxp0_tx_config_lptime_sel(module_id,
                         saved->save_hsif_slc2_mr10x4_sds_common_stxp0_tx_config_lptime_sel[TEN_MOD_ID_TO_MOD_NUM(module_id)]);

            }
            if (sl == TEN_SLICE3) {
              rtn |= ten_hsif_slc3_mr10x5_sds_common_srx0_rx_clkout_ctrl_srx_tclko_sel(module_id,
                                                                  TEN_INSTANCE_ALL,
                                                                  saved->save_hsif_slc3_mr10x5_sds_common_srx0_rx_clkout_ctrl_srx_tclko_sel[TEN_MOD_ID_TO_MOD_NUM(module_id)]);

              rtn |= ten_hsif_slc3_mr10x5_sds_common_stxp0_tx_config_lptime_sel(module_id,
                         saved->save_hsif_slc3_mr10x5_sds_common_stxp0_tx_config_lptime_sel[TEN_MOD_ID_TO_MOD_NUM(module_id)]);
            }
          }
          else { /* 40G SFI5.1 */
            rtn |= ten_hsif_set_refclk_cfg(module_id, TEN_HSIF_REFCLK_CFG_LOOPCKSEL, 0);
          }
        }
        break;

      case (TEN_HSIF_LOOPBACK_MR_TX2RX):
        /* Bugzilla #25699, fix MRTX2RX loopback */
        /* WILL NOT WORK with SFI42 (use mr_serial instead) */
        if (ten_hsif_is_sfi42_active(module_id, sl)) {
          CS_PRINT_OUTPUT("MR TX2RX loopback does not work with SFI4.2, use MR SERIAL instead.\n");
          CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": MR TX2RX loopback does not work with SFI4.2");
          rtn = CS_ERROR;
          break;
        }
        
        /* check if loopback is already enabled */
        if (ctl == CS_ENABLE) {
          if (sl == TEN_SLICE3) {
            tmp_slc3_mr10x5_sds_common_rx0_config.wrd = TEN_REG_READ(TEN_HSIF_SLC3_MR10X5_REG_ADDR(pDev, module_id, RX0_Config));

            if (tmp_slc3_mr10x5_sds_common_rx0_config.bf.data_source == 1) {
              CS_PRINT_OUTPUT("Slice 3 is already in loopback.\n");
              break;
            }
          }
          if (sl == TEN_SLICE2) {
            tmp_slc2_mr10x4_sds_common_rx0_config.wrd = TEN_REG_READ(TEN_HSIF_SLC2_MR10X4_REG_ADDR(pDev, module_id, RX0_Config));

            if (tmp_slc2_mr10x4_sds_common_rx0_config.bf.data_source == 1) {
              CS_PRINT_OUTPUT("Slice 2 is already in loopback.\n");
              break;
            }
          }
          if (sl == TEN_SLICE1) {
            tmp_slc1_mr10x5_sds_common_rx0_config.wrd = TEN_REG_READ(TEN_HSIF_SLC1_MR10X5_REG_ADDR(pDev, module_id, RX0_Config));

            if (tmp_slc1_mr10x5_sds_common_rx0_config.bf.data_source == 1) {
              CS_PRINT_OUTPUT("Slice 1 is already in loopback.\n");
              break;
            }
          }
          if (sl == TEN_SLICE0) {
            tmp_slc0_mr10x4_sds_common_rx0_config.wrd = TEN_REG_READ(TEN_HSIF_SLC0_MR10X4_REG_ADDR(pDev, module_id, RX0_Config));

            if (tmp_slc0_mr10x4_sds_common_rx0_config.bf.data_source == 1) {
              CS_PRINT_OUTPUT("Slice 0 is already in loopback.\n");
              break;
            }
          }
        }

        /* check if loopback is already disabled */
        if (ctl == CS_DISABLE) {

          if (sl == TEN_SLICE3) {
            tmp_slc3_mr10x5_sds_common_rx0_config.wrd = TEN_REG_READ(TEN_HSIF_SLC3_MR10X5_REG_ADDR(pDev, module_id, RX0_Config));

            if (tmp_slc3_mr10x5_sds_common_rx0_config.bf.data_source == 0) {
              CS_PRINT_OUTPUT("Slice 3 is already out of loopback.\n");
              break;
            }
          }
          if (sl == TEN_SLICE2) {
            tmp_slc2_mr10x4_sds_common_rx0_config.wrd = TEN_REG_READ(TEN_HSIF_SLC2_MR10X4_REG_ADDR(pDev, module_id, RX0_Config));

            if (tmp_slc2_mr10x4_sds_common_rx0_config.bf.data_source == 0) {
              CS_PRINT_OUTPUT("Slice 2 is already out of loopback.\n");
              break;
            }
          }
          if (sl == TEN_SLICE1) {
            tmp_slc1_mr10x5_sds_common_rx0_config.wrd = TEN_REG_READ(TEN_HSIF_SLC1_MR10X5_REG_ADDR(pDev, module_id, RX0_Config));

            if (tmp_slc1_mr10x5_sds_common_rx0_config.bf.data_source == 0) {
              CS_PRINT_OUTPUT("Slice 1 is already out of loopback.\n");
              break;
            }
          }
          if (sl == TEN_SLICE0) {
            tmp_slc0_mr10x4_sds_common_rx0_config.wrd = TEN_REG_READ(TEN_HSIF_SLC0_MR10X4_REG_ADDR(pDev, module_id, RX0_Config));

            if (tmp_slc0_mr10x4_sds_common_rx0_config.bf.data_source == 0) {
              CS_PRINT_OUTPUT("Slice 0 is already out of loopback.\n");
              break;
            }
          }
        }
        
        /* Bugzilla #26282:  loopback API needs to disable all clock protection */
        if (ctl == CS_ENABLE) {
          /* save clock protection settings */
          rtn |= ten_hsif_save_clock_protection_settings(module_id, slice, sl, saved);
        }
        else {
          /* restore clock protection settings */
          rtn |= ten_hsif_restore_clock_protection_settings(module_id, slice, sl, saved);
        }

        if (sl == TEN_SLICE0) {
          rtn |= ten_hsif_slc0_mr10x4_sds_common_rx_config(module_id, TEN_INSTANCE_ALL, ctl);
        }
        if (sl == TEN_SLICE1) {
          /* also set instance 4 for Lane/SerDes #16 (SFI-5.1 deskew channel). */
          rtn |= ten_hsif_slc1_mr10x5_sds_common_rx_config(module_id, TEN_INSTANCE_ALL, ctl);
        }
        if (sl == TEN_SLICE2) {
          rtn |= ten_hsif_slc2_mr10x4_sds_common_rx_config(module_id, TEN_INSTANCE_ALL, ctl);
        }
        if (sl == TEN_SLICE3) {
          /* Bugzilla #26617, need all instances for slice 3 after all */
          rtn |= ten_hsif_slc3_mr10x5_sds_common_rx_config(module_id, TEN_INSTANCE_ALL, ctl);
        }
        
        /* Set serial to fix clocking */
        if (sl == TEN_SLICE0) {
          /* switch serial loopback muxes */
          ten_hsif_slc0_mr10x4_sds_common_srx0_srx_lpbken(module_id, TEN_INSTANCE_ALL, ctl);
          ten_hsif_slc0_mr10x4_sds_common_stxp0_lpbken(module_id, ctl);
        }
        if (sl == TEN_SLICE1) {
          ten_hsif_slc1_mr10x5_sds_common_srx0_srx_lpbken(module_id, TEN_INSTANCE_ALL, ctl);
          ten_hsif_slc1_mr10x5_sds_common_stxp0_lpbken(module_id, ctl);
        }
        if (sl == TEN_SLICE2) {
          ten_hsif_slc2_mr10x4_sds_common_srx0_srx_lpbken(module_id, TEN_INSTANCE_ALL, ctl);
          ten_hsif_slc2_mr10x4_sds_common_stxp0_lpbken(module_id, ctl);
        }
        if (sl == TEN_SLICE3) {
          /* Bugzilla #26617, need all instances for slice 3 after all */
          ten_hsif_slc3_mr10x5_sds_common_srx0_srx_lpbken(module_id, TEN_INSTANCE_ALL, ctl);
          ten_hsif_slc3_mr10x5_sds_common_stxp0_lpbken(module_id, ctl);
        }
        break;

      case (TEN_HSIF_LOOPBACK_XFI_TX2RX):

        tmp_rx0_config.wrd = TEN_REG_READ(TEN_XFI32X1_REG_ADDR(pDev, module_id, sl, RX0_Config));

        /* check if loopback is already enabled */
        if (ctl == CS_ENABLE) {
          if ((sl == TEN_SLICE3) && (tmp_rx0_config.bf.data_source == 1)) {
            CS_PRINT_OUTPUT("Slice 3 is already in loopback.\n");
            break;
          }
          if ((sl == TEN_SLICE2) && (tmp_rx0_config.bf.data_source == 1)) {
            CS_PRINT_OUTPUT("Slice 2 is already in loopback.\n");
            break;
          }
          if ((sl == TEN_SLICE1) && (tmp_rx0_config.bf.data_source == 1)) {
            CS_PRINT_OUTPUT("Slice 1 is already in loopback.\n");
            break;
          }
          if ((sl == TEN_SLICE0) && (tmp_rx0_config.bf.data_source == 1)) {
            CS_PRINT_OUTPUT("Slice 0 is already in loopback.\n");
            break;
          }
        }

        /* check if loopback is already disabled */
        if (ctl == CS_DISABLE) {
          if ((sl == TEN_SLICE3) && (tmp_rx0_config.bf.data_source == 0)) {
            CS_PRINT_OUTPUT("Slice 3 is already out of loopback.\n");
            break;
          }
          if ((sl == TEN_SLICE2) && (tmp_rx0_config.bf.data_source == 0)) {
            CS_PRINT_OUTPUT("Slice 2 is already out of loopback.\n");
            break;
          }
          if ((sl == TEN_SLICE1) && (tmp_rx0_config.bf.data_source == 0)) {
            CS_PRINT_OUTPUT("Slice 1 is already out of loopback.\n");
            break;
          }
          if ((sl == TEN_SLICE0) && (tmp_rx0_config.bf.data_source == 0)) {
            CS_PRINT_OUTPUT("Slice 0 is already out of loopback.\n");
            break;
          }
        }

        /* Bugzilla #26282:  loopback API needs to disable all clock protection */
        if (ctl == CS_ENABLE) {
          /* save clock protection settings */
          rtn |= ten_hsif_save_clock_protection_settings(module_id, slice, sl, saved);
        }
        else {
          /* restore clock protection settings */
          rtn |= ten_hsif_restore_clock_protection_settings(module_id, slice, sl, saved);
        }
        
        /* Bugzilla #25699, fix for tx2rx loopback */
        rtn |= ten_xfi32x1_rx0_config(module_id, sl, ctl);
        rtn |= ten_xfi32x1_srx0_rx_config_lpbken(module_id, sl, ctl);
        rtn |= ten_xfi32x1_stxp0_tx_config_lpbken(module_id, sl, ctl);
        break;

      case (TEN_HSIF_LOOPBACK_XFI_RX2TX):

        tmp_tx0_config.wrd = TEN_REG_READ(TEN_XFI32X1_REG_ADDR(pDev, module_id, sl, TX0_Config));

        /* check if loopback is already enabled */
        if (ctl == CS_ENABLE) {
          if ((sl == TEN_SLICE3) && (tmp_tx0_config.bf.data_source == 2)) {
            CS_PRINT_OUTPUT("Slice 3 is already in loopback.\n");
            break;
          }
          if ((sl == TEN_SLICE2) && (tmp_tx0_config.bf.data_source == 2)) {
            CS_PRINT_OUTPUT("Slice 2 is already in loopback.\n");
            break;
          }
          if ((sl == TEN_SLICE1) && (tmp_tx0_config.bf.data_source == 2)) {
            CS_PRINT_OUTPUT("Slice 1 is already in loopback.\n");
            break;
          }
          if ((sl == TEN_SLICE0) && (tmp_tx0_config.bf.data_source == 2)) {
            CS_PRINT_OUTPUT("Slice 0 is already in loopback.\n");
            break;
          }
        }

        /* check if loopback is already disabled */
        if (ctl == CS_DISABLE) {
          if ((sl == TEN_SLICE3) && (tmp_tx0_config.bf.data_source == 0)) {
            CS_PRINT_OUTPUT("Slice 3 is already out of loopback.\n");
            break;
          }
          if ((sl == TEN_SLICE2) && (tmp_tx0_config.bf.data_source == 0)) {
            CS_PRINT_OUTPUT("Slice 2 is already out of loopback.\n");
            break;
          }
          if ((sl == TEN_SLICE1) && (tmp_tx0_config.bf.data_source == 0)) {
            CS_PRINT_OUTPUT("Slice 1 is already out of loopback.\n");
            break;
          }
          if ((sl == TEN_SLICE0) && (tmp_tx0_config.bf.data_source == 0)) {
            CS_PRINT_OUTPUT("Slice 0 is already out of loopback.\n");
            break;
          }
        }
        
        /* Bugzilla #26282:  loopback API needs to disable all clock protection */
        if (ctl == CS_ENABLE) {
          /* save clock protection settings */
          rtn |= ten_hsif_save_clock_protection_settings(module_id, slice, sl, saved);
        }
        else {
          /* restore clock protection settings */
          rtn |= ten_hsif_restore_clock_protection_settings(module_id, slice, sl, saved);
        }
        
        if (ctl == CS_ENABLE) {
          data_source = 2;  /* 10 = RX Loopback Data */

          /* enable loopback, saved->save state */
          /* Bug #38240: XFI Facility and rx2tx loopbacks need fix for XFI internal clock fanout mode. */
          tmp_stxp0_tx_config.wrd = TEN_REG_READ(TEN_XFI32X1_REG_ADDR(pDev, module_id, sl, STXP0_TX_CONFIG));
          saved->save_xfi32x1_stxp0_tx_lptime_sel[TEN_MOD_ID_TO_MOD_NUM(module_id)][sl] =
             tmp_stxp0_tx_config.bf.STXP_LPTIME_SEL | (tmp_stxp0_tx_config.bf.STXP_LPTIME_SEL_MSB << 2) ;
             
          tmp_stxp0_tx_clkdiv_ctrl.wrd = TEN_REG_READ(TEN_XFI32X1_REG_ADDR(pDev, module_id, sl, STXP0_TX_CLKDIV_CTRL));
          saved->save_xfi32x1_stxp0_tx_clkdiv_ctrl[TEN_MOD_ID_TO_MOD_NUM(module_id)][sl] =
             tmp_stxp0_tx_clkdiv_ctrl.wrd;

          tmp_tx0_config.wrd = TEN_REG_READ(TEN_XFI32X1_REG_ADDR(pDev, module_id, sl, TX0_Config));
          saved->save_xfi32x1_bit_invert[module_id][sl] = tmp_tx0_config.bf.bitinv;

          rtn |= ten_xfi32x1_tx0_config(module_id, sl, data_source);

          /* loop timing required */
          rtn |= ten_xfi32x1_stxp0_tx_lptime_sel(module_id, sl, 2);
          /* must change RDIV to div16 (from div64) and CTVDIV to div4 (from div1) */

          /* Bug #38240: XFI Facility and rx2tx loopbacks need fix for XFI internal clock fanout mode. */
          rtn |= ten_xfi32x1_stxp0_tx_config_lptime_sel_msb_t41(module_id, sl, 0); 

          /* Bugzilla #28260, fix XFI facility loopback, 10G/40G */
          /* rtn |= ten_xfi32x1_stxp0_tx_clkdiv_ctrl(module_id, sl, 3, 0, 2, 0, 0); */
          rtn |= ten_xfi32x1_stxp0_tx_clkdiv_ctrl_ctv_div(module_id, sl, 2);
          rtn |= ten_xfi32x1_stxp0_tx_clkdiv_ctrl_rdiv_sel(module_id, sl, 0);
          /* bit invert must be 0 in loopback due to SDS architecture - bit invert */
          /* isn't symmetrical in loopback - only TX bit inv is in the path        */
          /* so on a lane that ordinarily needs P/N swap, it needs to be           */
          /* disabled in loopback                                                  */

          /*  Bug #39352 - T41 near end RX2TX loopback */
          tmp_rx0_config.wrd = TEN_REG_READ(TEN_XFI32X1_REG_ADDR(pDev, module_id, sl, RX0_Config));
          if ((tmp_tx0_config.bf.bitinv ^ tmp_rx0_config.bf.bitinv) == 0) {
            rtn |= ten_xfi32x1_bit_invert(module_id, sl, 0);
          }
          else {
            rtn |= ten_xfi32x1_bit_invert(module_id, sl, 1);
          }
          
          /* Bugzilla #36075 - fix TEN_HSIF_LOOPBACK_FACILITY_XFI fails with 4/2 GFC when using CUPLL */
          /* If CUPLL is enabled, apply additional setting for loopback */
          /* Bugzilla #36418 - T40 XFI Facility loopback has error message due to T41 addition */
          if (ten_dev_is_t41(TEN_MOD_ID_TO_DEV_ID(module_id))) {
            if (!ten_mpif_get_global_reset_cupll_mpif_t41(TEN_MOD_ID_TO_DEV_ID(module_id), sl)) {
              tmp_stxp0_tx_spare.wrd = TEN_REG_READ(TEN_XFI32X1_REG_ADDR(pDev, module_id, sl, STXP0_TX_SPARE));
              CS_PRINT("tmp_stxp0_tx_spare.bf.STXP_REFCLK_DIV_SEL = %d\n", tmp_stxp0_tx_spare.bf.STXP_REFCLK_DIV_SEL);
              saved->save_xfi32x1_stxp0_tx_spare_refclk_div_sel[TEN_MOD_ID_TO_MOD_NUM(module_id)][sl] =
                tmp_stxp0_tx_spare.bf.STXP_REFCLK_DIV_SEL;
              rtn |= ten_xfi32x1_stxp0_tx_spare_refclk_div_sel_t41(module_id, sl, 0);
            }
          }
        }
        else {
          data_source = 0;  /* 00 = DIG_TX_DIN */
          rtn |= ten_xfi32x1_tx0_config(module_id, sl, data_source);

          /* disable loopback, restore state */
          /* remove loop timing */
          /* Bug #38240: XFI Facility and rx2tx loopbacks need fix for XFI internal clock fanout mode. */
          rtn |= ten_xfi32x1_stxp0_tx_lptime_sel(module_id, sl,
                    saved->save_xfi32x1_stxp0_tx_lptime_sel[TEN_MOD_ID_TO_MOD_NUM(module_id)][sl] & 0x3);

          CS_PRINT("current structure value of ten_hsif_loopback_settings_struct_version_num = %d\n", saved->save_xfi32x1_stxp0_tx_lptime_sel[TEN_MODULE_A][0]);
          CS_PRINT("current software value of ten_hsif_loopback_settings_struct_version_num = %d\n", TEN_HSIF_LOOPBACK_SETTINGS_STRUCT_VERSION_NUM);
    
          /* only the structure of version 5110 and above has the lptime_sel_msb settings saved */
          /* do not try to restore these settings with old version of structure */
          if (saved->save_xfi32x1_stxp0_tx_lptime_sel[TEN_MODULE_A][0] >= TEN_HSIF_LOOPBACK_SETTINGS_STRUCT_VERSION_NUM_5110) {
            rtn |= ten_xfi32x1_stxp0_tx_config_lptime_sel_msb_t41(module_id, sl,  
                     saved->save_xfi32x1_stxp0_tx_lptime_sel[TEN_MOD_ID_TO_MOD_NUM(module_id)][sl]>>2);
          }        
                    
          /* must change RDIV to div16 (from div64) and CTVDIV to div4 (from div1) */
          /* rtn |= ten_xfi32x1_stxp0_tx_clkdiv_ctrl(module_id, slice, 3, 0, 2, 0, 0); */
          TEN_REG_WRITE(TEN_XFI32X1_REG_ADDR(pDev, module_id, sl, STXP0_TX_CLKDIV_CTRL),
            saved->save_xfi32x1_stxp0_tx_clkdiv_ctrl[TEN_MOD_ID_TO_MOD_NUM(module_id)][sl]);

          ten_xfi32x1_bit_invert(module_id, sl, saved->save_xfi32x1_bit_invert[TEN_MOD_ID_TO_MOD_NUM(module_id)][sl]);
          
          /* Bugzilla #36075 - fix TEN_HSIF_LOOPBACK_FACILITY_XFI/XFI_RX2TX fails with 4/2 GFC when using CUPLL */
          /* If CUPLL is enabled, apply additional setting for loopback */
          /* Bugzilla #36418 - T40 XFI Facility loopback has error message due to T41 addition */
          if (ten_dev_is_t41(TEN_MOD_ID_TO_DEV_ID(module_id))) {
            if (!ten_mpif_get_global_reset_cupll_mpif_t41(TEN_MOD_ID_TO_DEV_ID(module_id), sl)) {
              rtn |= ten_xfi32x1_stxp0_tx_spare_refclk_div_sel_t41(module_id, sl, 
                       saved->save_xfi32x1_stxp0_tx_spare_refclk_div_sel[TEN_MOD_ID_TO_MOD_NUM(module_id)][sl]);
                       
              ten_cupll_reset_t41(module_id, sl, TEN_XFI_CUPLL_RESET_CUPLL_DIG, CS_RESET_TOGGLE);
              ten_mpif_cupll_settle_force_t41(TEN_MOD_ID_TO_DEV_ID(module_id), sl, 2, CS_ENABLE);
              ten_mpif_cupll_settle_force_t41(TEN_MOD_ID_TO_DEV_ID(module_id), sl, 2, CS_DISABLE);
            }
          }
        }
        break;

      case (TEN_HSIF_LOOPBACK_MR_SERIAL):
        /* SFI42 TX2RX loopback (will work for other protocols as well, but added for SFI42) */

        /* Bugzilla #26282:  loopback API needs to disable all clock protection */
        if (ctl == CS_ENABLE) {
          /* save clock protection settings */
          rtn |= ten_hsif_save_clock_protection_settings(module_id, slice, sl, saved);
        }
        else {
          /* restore clock protection settings */
          rtn |= ten_hsif_restore_clock_protection_settings(module_id, slice, sl, saved);
        }
        
        if (sl == TEN_SLICE0) {
          /* switch serial loopback muxes */
          ten_hsif_slc0_mr10x4_sds_common_srx0_srx_lpbken(module_id, TEN_INSTANCE_ALL, ctl);
          /* turn off use datadet, since it is not in the loopback path */
          /* bugzilla #24278 start*/
          /* ten_hsif_set_slc0_mr10x4_rxlockd0_data_lock(module_id, TEN_INSTANCE_ALL, !ctl); */
          /* bugzilla #24278 end*/
          /* turn on serial loopback drivers */
          ten_hsif_slc0_mr10x4_sds_common_stxp0_lpbken(module_id, ctl);
          
          /* Bugzilla #28789, fix for MR serial loopback */
          if (ten_dev_is_t41(TEN_MOD_ID_TO_DEV_ID(module_id))) {
            ten_hsif_slc0_mr10x4_rxlockd0_data_filtlock(module_id, TEN_INSTANCE_ALL, !ctl); 
          }
        }
        if (sl == TEN_SLICE1) {
          ten_hsif_slc1_mr10x5_sds_common_srx0_srx_lpbken(module_id, TEN_INSTANCE_ALL, ctl);
          /* bugzilla #24278 start*/
          /* ten_hsif_set_slc1_mr10x5_rxlockd0_data_lock(module_id, TEN_INSTANCE_ALL, !ctl); */
          /* bugzilla #24278 end*/
          ten_hsif_slc1_mr10x5_sds_common_stxp0_lpbken(module_id, ctl);
          
          /* Bugzilla #28789, fix for MR serial loopback */
          if (ten_dev_is_t41(TEN_MOD_ID_TO_DEV_ID(module_id))) {
            ten_hsif_slc1_mr10x5_rxlockd0_data_filtlock(module_id, TEN_INSTANCE_ALL, !ctl); 
          }
        }
        if (sl == TEN_SLICE2) {
          ten_hsif_slc2_mr10x4_sds_common_srx0_srx_lpbken(module_id, TEN_INSTANCE_ALL, ctl);
          /* bugzilla #24278 start*/
          /* ten_hsif_set_slc2_mr10x4_rxlockd0_data_lock(module_id, TEN_INSTANCE_ALL, !ctl); */
          /* bugzilla #24278 end*/
          ten_hsif_slc2_mr10x4_sds_common_stxp0_lpbken(module_id, ctl);
          
          /* Bugzilla #28789, fix for MR serial loopback */
          if (ten_dev_is_t41(TEN_MOD_ID_TO_DEV_ID(module_id))) {
            ten_hsif_slc2_mr10x4_rxlockd0_data_filtlock(module_id, TEN_INSTANCE_ALL, !ctl); 
          }
        }
        if (sl == TEN_SLICE3) {
          /* Bugzilla #26617, need all instances for slice 3 after all */
          ten_hsif_slc3_mr10x5_sds_common_srx0_srx_lpbken(module_id, TEN_INSTANCE_ALL, ctl);
          /* bugzilla #24278 start*/
          /* ten_hsif_set_slc3_mr10x5_rxlockd0_data_lock(module_id, TEN_INSTANCE_ALL, !ctl);  */
          /* bugzilla #24278 end*/
          ten_hsif_slc3_mr10x5_sds_common_stxp0_lpbken(module_id, ctl);
          
          /* Bugzilla #28789, fix for MR serial loopback */
          if (ten_dev_is_t41(TEN_MOD_ID_TO_DEV_ID(module_id))) {
            ten_hsif_slc3_mr10x5_rxlockd0_data_filtlock(module_id, TEN_INSTANCE_ALL, !ctl); 
          }
        }
        break;

      /* Bugzilla #21828, add XFI serial loopback */
      case (TEN_HSIF_LOOPBACK_XFI_SERIAL_TX2RX):

        /* Bugzilla #26282:  loopback API needs to disable all clock protection */
        if (ctl == CS_ENABLE) {
          /* save clock protection settings */
          rtn |= ten_hsif_save_clock_protection_settings(module_id, slice, sl, saved);
        }
        else {
          /* restore clock protection settings */
          rtn |= ten_hsif_restore_clock_protection_settings(module_id, slice, sl, saved);
        }
      
        /* need to turn on XFI serial loopback */
        if (sl == TEN_SLICE0) {
          ten_xfi32x1_srx0_rx_config_lpbken(module_id, sl, ctl);
          ten_xfi32x1_stxp0_tx_config_lpbken(module_id, sl, ctl);
        }
        if (sl == TEN_SLICE1) {
          ten_xfi32x1_srx0_rx_config_lpbken(module_id, sl, ctl);
          ten_xfi32x1_stxp0_tx_config_lpbken(module_id, sl, ctl);
        }
        if (sl == TEN_SLICE2) {
          ten_xfi32x1_srx0_rx_config_lpbken(module_id, sl, ctl);
          ten_xfi32x1_stxp0_tx_config_lpbken(module_id, sl, ctl);
        }
        if (sl == TEN_SLICE3) {
          ten_xfi32x1_srx0_rx_config_lpbken(module_id, sl, ctl);
          ten_xfi32x1_stxp0_tx_config_lpbken(module_id, sl, ctl);
        }
        break;
        
      case (TEN_HSIF_LOOPBACK_FACILITY_CFP):
      
        if (TEN_MOD_ID_TO_MOD_NUM(module_id) == TEN_MODULE_A) {
          tmp_mod_id = TEN_MOD_ID_TO_NEW_MOD_ID(module_id, TEN_MODULE_B);
        }
        else {
          tmp_mod_id = module_id;
        }
      
        tmp_lbcfg.wrd = TEN_REG_READ(TEN_HSIF_REG_ADDR(pDev, module_id, LBCFG));

        /* check if loopback is already enabled */
        if (ctl == CS_ENABLE) {
          if ((sl == TEN_SLICE3) && (tmp_lbcfg.bf.rxtxlb3_en == 1)) {
            CS_PRINT_OUTPUT("Slice 3 is already in loopback.\n");
            break;
          }
          if ((sl == TEN_SLICE2) && (tmp_lbcfg.bf.rxtxlb2_en == 1)) {
            CS_PRINT_OUTPUT("Slice 2 is already in loopback.\n");
            break;
          }
          if ((sl == TEN_SLICE1) && (tmp_lbcfg.bf.rxtxlb1_en == 1)) {
            CS_PRINT_OUTPUT("Slice 1 is already in loopback.\n");
            break;
          }
          if ((sl == TEN_SLICE0) && (tmp_lbcfg.bf.rxtxlb0_en == 1)) {
            CS_PRINT_OUTPUT("Slice 0 is already in loopback.\n");
            break;
          }
        }

        /* check if loopback is already disabled */
        if (ctl == CS_DISABLE) {
          if ((sl == TEN_SLICE3) && (tmp_lbcfg.bf.rxtxlb3_en == 0)) {
            CS_PRINT_OUTPUT("Slice 3 is already out of loopback.\n");
            break;
          }
          if ((sl == TEN_SLICE2) && (tmp_lbcfg.bf.rxtxlb2_en == 0)) {
            CS_PRINT_OUTPUT("Slice 2 is already out of loopback.\n");
            break;
          }
          if ((sl == TEN_SLICE1) && (tmp_lbcfg.bf.rxtxlb1_en == 0)) {
            CS_PRINT_OUTPUT("Slice 1 is already out of loopback.\n");
            break;
          }
          if ((sl == TEN_SLICE0) && (tmp_lbcfg.bf.rxtxlb0_en == 0)) {
            CS_PRINT_OUTPUT("Slice 0 is already out of loopback.\n");
            break;
          }
        }

        if (ctl == CS_ENABLE) {
          /* Bugzilla #26282:  loopback API needs to disable all clock protection */
          rtn |= ten_hsif_save_clock_protection_settings(tmp_mod_id, slice, sl, saved);
          
          rtn |= ten_hsif_facility_loopback(module_id, sl, CS_ENABLE);
        
          /* enable loopback, saved->save state */
          tmp_cfp_stxp0_tx_config.wrd = TEN_REG_READ(TEN_CFP32X1_REG_ADDR(pDev, module_id, sl, STXP0_TX_CONFIG));
          saved->save_cfp32x1_stxp0_tx_lptime_sel[TEN_MOD_ID_TO_MOD_NUM(module_id)][sl] =
             tmp_cfp_stxp0_tx_config.bf.STXP_LPTIME_SEL;

          tmp_cfp_stxp0_tx_clkdiv_ctrl.wrd = TEN_REG_READ(TEN_CFP32X1_REG_ADDR(pDev, module_id, sl, STXP0_TX_CLKDIV_CTRL));
          saved->save_cfp32x1_stxp0_tx_clkdiv_ctrl[TEN_MOD_ID_TO_MOD_NUM(module_id)][sl] =
             tmp_cfp_stxp0_tx_clkdiv_ctrl.wrd;

          /* loop timing required */
          /* Bugzilla #34892 - fix CFP_MR HSIF loopback failures */
          rtn |= ten_hsif_set_refclk_cfg(tmp_mod_id, TEN_HSIF_REFCLK_CFG_LOOPCKSEL, 1);
          
          if (slice == TEN_SLICE_ALL) {  /* 40G mode */
            rtn |= ten_cfp32x1_stxp0_tx_lptime_sel_t41(module_id, sl, 2);
            /* must change RDIV to div16 (from div64) and CTVDIV to div4 (from div1) */
            TEN_REG_WRITE(TEN_CFP32X1_REG_ADDR(pDev, module_id, sl, STXP0_TX_CLKDIV_CTRL), 0x3402);
          }
          else {  /* 10G mode */
             if (sl == TEN_SLICE1) {  
               tmp_cfp_stxp0_tx_config.wrd = TEN_REG_READ(TEN_CFP32X1_REG_ADDR(pDev, module_id, TEN_SLICE0, STXP0_TX_CONFIG));
               saved->save_cfp32x1_stxp0_tx_lptime_sel[TEN_MOD_ID_TO_MOD_NUM(module_id)][sl] =
                  tmp_cfp_stxp0_tx_config.bf.STXP_LPTIME_SEL;
               rtn |= ten_cfp32x1_stxp0_tx_lptime_sel_t41(module_id, TEN_SLICE0, 2);
             }
             else if (sl == TEN_SLICE3) {  
               tmp_cfp_stxp0_tx_config.wrd = TEN_REG_READ(TEN_CFP32X1_REG_ADDR(pDev, module_id, TEN_SLICE2, STXP0_TX_CONFIG));
               saved->save_cfp32x1_stxp0_tx_lptime_sel[TEN_MOD_ID_TO_MOD_NUM(module_id)][sl] =
                  tmp_cfp_stxp0_tx_config.bf.STXP_LPTIME_SEL;
               rtn |= ten_cfp32x1_stxp0_tx_lptime_sel_t41(module_id, TEN_SLICE2, 2);
             }
             else {
               rtn |= ten_cfp32x1_stxp0_tx_lptime_sel_t41(module_id, sl, 2);
             }
             /* Bugzilla #32193 - T41 10G CFP MR changes */
             TEN_REG_WRITE(TEN_CFP32X1_REG_ADDR(pDev, module_id, sl, STXP0_TX_CLKDIV_CTRL), 0x3402);
             rtn |= ten_hsif_set_clk_40g(tmp_mod_id, TEN_HSIF_CLK_40G_RXSEL, sl);
          }
        }
        else {
          /* disable loopback, restore state */
          rtn |= ten_hsif_facility_loopback(module_id, sl, CS_DISABLE);

          /* remove loop timing */
          rtn |= ten_hsif_set_refclk_cfg(tmp_mod_id, TEN_HSIF_REFCLK_CFG_LOOPCKSEL, 0);
          if (sl == TEN_SLICE1) {  
            rtn |= ten_cfp32x1_stxp0_tx_lptime_sel_t41(module_id, TEN_SLICE0, 
                      saved->save_cfp32x1_stxp0_tx_lptime_sel[TEN_MOD_ID_TO_MOD_NUM(module_id)][sl]);
          }
          else if (sl == TEN_SLICE3) {  
            rtn |= ten_cfp32x1_stxp0_tx_lptime_sel_t41(module_id, TEN_SLICE2, 
                      saved->save_cfp32x1_stxp0_tx_lptime_sel[TEN_MOD_ID_TO_MOD_NUM(module_id)][sl]);
          }
          else {
            rtn |= ten_cfp32x1_stxp0_tx_lptime_sel_t41(module_id, sl,
                    saved->save_cfp32x1_stxp0_tx_lptime_sel[TEN_MOD_ID_TO_MOD_NUM(module_id)][sl]);
          }

          /* must change RDIV to div16 (from div64) and CTVDIV to div4 (from div1) */
          /* rtn |= ten_xfi32x1_stxp0_tx_clkdiv_ctrl(module_id, slice, 3, 0, 2, 0, 0); */
          TEN_REG_WRITE(TEN_CFP32X1_REG_ADDR(pDev, module_id, sl, STXP0_TX_CLKDIV_CTRL),
            saved->save_cfp32x1_stxp0_tx_clkdiv_ctrl[TEN_MOD_ID_TO_MOD_NUM(module_id)][sl]);
            
          if (slice != TEN_SLICE_ALL) {  /* 10G mode */
            rtn |= ten_hsif_set_clk_40g(tmp_mod_id, TEN_HSIF_CLK_40G_RXSEL, 0);
          }
          
          /* restore clock protection settings */
          rtn |= ten_hsif_restore_clock_protection_settings(tmp_mod_id, slice, sl, saved);
        }
        break;
        
      case (TEN_HSIF_LOOPBACK_CFP_TX2RX):

        tmp_cfp_rx0_config.wrd = TEN_REG_READ(TEN_CFP32X1_REG_ADDR(pDev, module_id, sl, RX0_Config));

        /* check if loopback is already enabled */
        if (ctl == CS_ENABLE) {
          if ((sl == TEN_SLICE3) && (tmp_cfp_rx0_config.bf.data_source == 1)) {
            CS_PRINT_OUTPUT("Slice 3 is already in loopback.\n");
            break;
          }
          if ((sl == TEN_SLICE2) && (tmp_cfp_rx0_config.bf.data_source == 1)) {
            CS_PRINT_OUTPUT("Slice 2 is already in loopback.\n");
            break;
          }
          if ((sl == TEN_SLICE1) && (tmp_cfp_rx0_config.bf.data_source == 1)) {
            CS_PRINT_OUTPUT("Slice 1 is already in loopback.\n");
            break;
          }
          if ((sl == TEN_SLICE0) && (tmp_cfp_rx0_config.bf.data_source == 1)) {
            CS_PRINT_OUTPUT("Slice 0 is already in loopback.\n");
            break;
          }
        }

        /* check if loopback is already disabled */
        if (ctl == CS_DISABLE) {
          if ((sl == TEN_SLICE3) && (tmp_cfp_rx0_config.bf.data_source == 0)) {
            CS_PRINT_OUTPUT("Slice 3 is already out of loopback.\n");
            break;
          }
          if ((sl == TEN_SLICE2) && (tmp_cfp_rx0_config.bf.data_source == 0)) {
            CS_PRINT_OUTPUT("Slice 2 is already out of loopback.\n");
            break;
          }
          if ((sl == TEN_SLICE1) && (tmp_cfp_rx0_config.bf.data_source == 0)) {
            CS_PRINT_OUTPUT("Slice 1 is already out of loopback.\n");
            break;
          }
          if ((sl == TEN_SLICE0) && (tmp_cfp_rx0_config.bf.data_source == 0)) {
            CS_PRINT_OUTPUT("Slice 0 is already out of loopback.\n");
            break;
          }
        }

        /* Bugzilla #26282:  loopback API needs to disable all clock protection */
        if (ctl == CS_ENABLE) {
          /* save clock protection settings */
          rtn |= ten_hsif_save_clock_protection_settings(module_id, slice, sl, saved);
        }
        else {
          /* restore clock protection settings */
          rtn |= ten_hsif_restore_clock_protection_settings(module_id, slice, sl, saved);
        }
     
        if (ctl == CS_ENABLE)
        {
          rtn |= ten_cfp32x1_rx0_config_data_source_t41(module_id, sl, 1); /* 1 = TX Loopback Data */

          if (slice != TEN_SLICE_ALL) {  /* 10G mode */
            /* enable loopback, saved->save state */
            saved->save_cfp_rxlockd0_control[TEN_MOD_ID_TO_DEV_ID(module_id)][sl] =
                        TEN_REG_READ(TEN_CFP32X1_REG_ADDR(pDev, module_id, sl, RXLOCKD0_CONTROL));
            /* need to force RX out of lock so that we use the TX pilot.  SRX domain needs a good clock */
            rtn |= ten_cfp32x1_set_rxlockd0_pd_mode_t41(module_id, sl, 0);
            rtn |= ten_cfp32x1_set_rxlockd0_force_lock_t41(module_id, sl, 1);
            
            tmp_cfp_tx0_config.wrd = TEN_REG_READ(TEN_CFP32X1_REG_ADDR(pDev, module_id, sl, TX0_Config));
            saved->save_cfp32x1_bit_invert[module_id][sl] = tmp_cfp_tx0_config.bf.bitinv;
            rtn |= ten_cfp32x1_tx0_config_bitinv_t41(module_id, sl, 1);
          }
        }
        else
        {
          /* disable loopback, restore state */
          /* 0 = SRX_DOUT (Serdes data) */
          rtn |= ten_cfp32x1_rx0_config_data_source_t41(module_id, sl, 0); 
          if (slice != TEN_SLICE_ALL) {  /* 10G mode */
            tmp_cfp_rxlockd0_control.wrd = saved->save_cfp_rxlockd0_control[TEN_MOD_ID_TO_DEV_ID(module_id)][sl];

            /* need to force RX out of lock so that we use the TX pilot.  SRX domain needs a good clock */
            rtn |= ten_cfp32x1_set_rxlockd0_pd_mode_t41(module_id, slice, tmp_cfp_rxlockd0_control.bf.PD_MODE);
            rtn |= ten_cfp32x1_set_rxlockd0_force_lock_t41(module_id, slice, tmp_cfp_rxlockd0_control.bf.FORCE_LOCK);

            rtn |= ten_cfp32x1_tx0_config_bitinv_t41(module_id, sl, 
                      saved->save_cfp32x1_bit_invert[TEN_MOD_ID_TO_MOD_NUM(module_id)][sl]);
          }
        }
        break;

      case (TEN_HSIF_LOOPBACK_CFP_RX2TX):
      
        if (TEN_MOD_ID_TO_MOD_NUM(module_id) == TEN_MODULE_A) {
          tmp_mod_id = TEN_MOD_ID_TO_NEW_MOD_ID(module_id, TEN_MODULE_B);
        }
        else {
          tmp_mod_id = module_id;
        }

        tmp_cfp_tx0_config.wrd = TEN_REG_READ(TEN_CFP32X1_REG_ADDR(pDev, tmp_mod_id, sl, TX0_Config));

        /* check if loopback is already enabled */
        if (ctl == CS_ENABLE) {
          if ((sl == TEN_SLICE3) && (tmp_cfp_tx0_config.bf.data_source == 2)) {
            CS_PRINT_OUTPUT("Slice 3 is already in loopback.\n");
            break;
          }
          if ((sl == TEN_SLICE2) && (tmp_cfp_tx0_config.bf.data_source == 2)) {
            CS_PRINT_OUTPUT("Slice 2 is already in loopback.\n");
            break;
          }
          if ((sl == TEN_SLICE1) && (tmp_cfp_tx0_config.bf.data_source == 2)) {
            CS_PRINT_OUTPUT("Slice 1 is already in loopback.\n");
            break;
          }
          if ((sl == TEN_SLICE0) && (tmp_cfp_tx0_config.bf.data_source == 2)) {
            CS_PRINT_OUTPUT("Slice 0 is already in loopback.\n");
            break;
          }
        }

        /* check if loopback is already disabled */
        if (ctl == CS_DISABLE) {
          if ((sl == TEN_SLICE3) && (tmp_cfp_tx0_config.bf.data_source == 0)) {
            CS_PRINT_OUTPUT("Slice 3 is already out of loopback.\n");
            break;
          }
          if ((sl == TEN_SLICE2) && (tmp_cfp_tx0_config.bf.data_source == 0)) {
            CS_PRINT_OUTPUT("Slice 2 is already out of loopback.\n");
            break;
          }
          if ((sl == TEN_SLICE1) && (tmp_cfp_tx0_config.bf.data_source == 0)) {
            CS_PRINT_OUTPUT("Slice 1 is already out of loopback.\n");
            break;
          }
          if ((sl == TEN_SLICE0) && (tmp_cfp_tx0_config.bf.data_source == 0)) {
            CS_PRINT_OUTPUT("Slice 0 is already out of loopback.\n");
            break;
          }
        }
        
        if (ctl == CS_ENABLE) {
          /* save clock protection settings */
          /* Bugzilla #26282:  loopback API needs to disable all clock protection */
          rtn |= ten_hsif_save_clock_protection_settings(tmp_mod_id, slice, sl, saved);
          
          /* 10 = RX Loopback Data */
          rtn |= ten_cfp32x1_tx0_config_data_source_t41(module_id, sl, 2); 
          
          /* enable loopback, saved->save state */
          tmp_cfp_stxp0_tx_config.wrd = TEN_REG_READ(TEN_CFP32X1_REG_ADDR(pDev, module_id, sl, STXP0_TX_CONFIG));
          saved->save_cfp32x1_stxp0_tx_lptime_sel[TEN_MOD_ID_TO_MOD_NUM(module_id)][sl] =
             tmp_cfp_stxp0_tx_config.bf.STXP_LPTIME_SEL;

          tmp_cfp_stxp0_tx_clkdiv_ctrl.wrd = TEN_REG_READ(TEN_CFP32X1_REG_ADDR(pDev, module_id, sl, STXP0_TX_CLKDIV_CTRL));
          saved->save_cfp32x1_stxp0_tx_clkdiv_ctrl[TEN_MOD_ID_TO_MOD_NUM(module_id)][sl] =
             tmp_cfp_stxp0_tx_clkdiv_ctrl.wrd;
             
          tmp_cfp_tx0_config.wrd = TEN_REG_READ(TEN_CFP32X1_REG_ADDR(pDev, module_id, sl, TX0_Config));
          saved->save_cfp32x1_bit_invert[module_id][sl] = tmp_cfp_tx0_config.bf.bitinv;
       
          /* loop timing required */
          /* Bugzilla #34892 - fix CFP_MR HSIF loopback failures */
          rtn |= ten_hsif_set_refclk_cfg(tmp_mod_id, TEN_HSIF_REFCLK_CFG_LOOPCKSEL, 1);
          
          if (slice == TEN_SLICE_ALL) {  /* 40G mode */
            rtn |= ten_cfp32x1_stxp0_tx_lptime_sel_t41(module_id, sl, 2);
            /* must change RDIV to div16 (from div64) and CTVDIV to div4 (from div1) */
            TEN_REG_WRITE(TEN_CFP32X1_REG_ADDR(pDev, module_id, sl, STXP0_TX_CLKDIV_CTRL), 0x3402);
          }
          else {  /* 10G mode */
             if (sl == TEN_SLICE1) {  
               tmp_cfp_stxp0_tx_config.wrd = TEN_REG_READ(TEN_CFP32X1_REG_ADDR(pDev, module_id, TEN_SLICE0, STXP0_TX_CONFIG));
               saved->save_cfp32x1_stxp0_tx_lptime_sel[TEN_MOD_ID_TO_MOD_NUM(module_id)][sl] =
                  tmp_cfp_stxp0_tx_config.bf.STXP_LPTIME_SEL;
               rtn |= ten_cfp32x1_stxp0_tx_lptime_sel_t41(module_id, TEN_SLICE0, 2);
             }
             else if (sl == TEN_SLICE3) {  
               tmp_cfp_stxp0_tx_config.wrd = TEN_REG_READ(TEN_CFP32X1_REG_ADDR(pDev, module_id, TEN_SLICE2, STXP0_TX_CONFIG));
               saved->save_cfp32x1_stxp0_tx_lptime_sel[TEN_MOD_ID_TO_MOD_NUM(module_id)][sl] =
                  tmp_cfp_stxp0_tx_config.bf.STXP_LPTIME_SEL;
               rtn |= ten_cfp32x1_stxp0_tx_lptime_sel_t41(module_id, TEN_SLICE2, 2);
             }
             else {
               rtn |= ten_cfp32x1_stxp0_tx_lptime_sel_t41(module_id, sl, 2);
             }
             /* Bugzilla #32193 - T41 10G CFP MR changes */
             TEN_REG_WRITE(TEN_CFP32X1_REG_ADDR(pDev, module_id, sl, STXP0_TX_CLKDIV_CTRL), 0x3402);
             rtn |= ten_hsif_set_clk_40g(tmp_mod_id, TEN_HSIF_CLK_40G_RXSEL, sl);
             
             /* Bug #39352 - T41 near end RX2TX loopback */
             tmp_cfp_rx0_config.wrd = TEN_REG_READ(TEN_CFP32X1_REG_ADDR(pDev, module_id, sl, RX0_Config));
             if ((tmp_cfp_tx0_config.bf.bitinv ^ tmp_cfp_rx0_config.bf.bitinv) == 0) {
               rtn |= ten_cfp32x1_tx0_config_bitinv_t41(module_id, sl, 0);
             }
             else {
               rtn |= ten_cfp32x1_tx0_config_bitinv_t41(module_id, sl, 1);
             }
           }
        }
        else {
          /* disable loopback, restore state */
          rtn |= ten_cfp32x1_tx0_config_data_source_t41(module_id, sl, 0); 
          
          /* remove loop timing */
          rtn |= ten_hsif_set_refclk_cfg(tmp_mod_id, TEN_HSIF_REFCLK_CFG_LOOPCKSEL, 0);
          if (sl == TEN_SLICE1) {  
            rtn |= ten_cfp32x1_stxp0_tx_lptime_sel_t41(module_id, TEN_SLICE0, 
                      saved->save_cfp32x1_stxp0_tx_lptime_sel[TEN_MOD_ID_TO_MOD_NUM(module_id)][sl]);
          }
          else if (sl == TEN_SLICE3) {  
            rtn |= ten_cfp32x1_stxp0_tx_lptime_sel_t41(module_id, TEN_SLICE2, 
                      saved->save_cfp32x1_stxp0_tx_lptime_sel[TEN_MOD_ID_TO_MOD_NUM(module_id)][sl]);
          }
          else {
            rtn |= ten_cfp32x1_stxp0_tx_lptime_sel_t41(module_id, sl,
                    saved->save_cfp32x1_stxp0_tx_lptime_sel[TEN_MOD_ID_TO_MOD_NUM(module_id)][sl]);
          }

          /* must change RDIV to div16 (from div64) and CTVDIV to div4 (from div1) */
          /* rtn |= ten_xfi32x1_stxp0_tx_clkdiv_ctrl(module_id, slice, 3, 0, 2, 0, 0); */
          TEN_REG_WRITE(TEN_CFP32X1_REG_ADDR(pDev, module_id, sl, STXP0_TX_CLKDIV_CTRL),
            saved->save_cfp32x1_stxp0_tx_clkdiv_ctrl[TEN_MOD_ID_TO_MOD_NUM(module_id)][sl]);
            
          if (slice != TEN_SLICE_ALL) {  /* 10G mode */
            rtn |= ten_hsif_set_clk_40g(tmp_mod_id, TEN_HSIF_CLK_40G_RXSEL, 0);
            rtn |= ten_cfp32x1_tx0_config_bitinv_t41(module_id, sl, 
                   saved->save_cfp32x1_bit_invert[TEN_MOD_ID_TO_MOD_NUM(module_id)][sl]);
          }
          
          /* restore clock protection settings */
          rtn |= ten_hsif_restore_clock_protection_settings(tmp_mod_id, slice, sl, saved);
        }
        break;
        
     /* Bugzilla #34892 - CFP_MR HSIF loopbacks  */
     case (TEN_HSIF_LOOPBACK_CFP_SERIAL_TX2RX):
        CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": This loopback is not supported.");
        rtn = CS_ERROR;
        break;  
        
      default:
        CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": Invalid loopback selection.");
        rtn = CS_ERROR;
        break;
      }
    }
  }
  return (rtn);
}

/********************************************************************/
/* $rtn_hdr_start  HIGH LEVEL HSIF CONTROL LOOPBACK                 */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : HIGH LEVEL                                          */
/* CHIP       : Tenabo                                              */
cs_status ten_hl_hsif_control_loopback(cs_uint16 module_id,
                                      cs_uint8 slice,
                                      cs_uint8 loopback,
                                      cs_ctl_t ctl)
/* INPUTS     : o Module Id                                         */
/*              o Slice                                             */
/*              o Loopback                                          */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Controls the major loopback modes for HSIF.                      */
/* NOTE:  The two XFI modes are available on Module B only.         */
/*                                                                  */
/* The [slice] parameter is specified as:                           */
/*   0x00 = TEN_SLICE0                                              */
/*   0x01 = TEN_SLICE1                                              */
/*   0x02 = TEN_SLICE2                                              */
/*   0x03 = TEN_SLICE3                                              */
/*   0xFF = TEN_SLICE_ALL (ALL 10G SLICES OR MR40G)                 */
/*                                                                  */
/* [loopback]  parameter is specified as:                           */
/*   TEN_HSIF_LOOPBACK_NONE           = 0                           */
/*   TEN_HSIF_LOOPBACK_FACILITY       = 1 (MR40G)                   */
/*   TEN_HSIF_LOOPBACK_FACILITY_EXT   = 2                           */
/*   TEN_HSIF_LOOPBACK_FACILITY_MR10G = 3 (MR10G)                   */
/*   TEN_HSIF_LOOPBACK_FAR_END        = 4                           */
/*   TEN_HSIF_LOOPBACK_MR_TX2RX       = 5                           */
/*   TEN_HSIF_LOOPBACK_MR_RX2TX       = 6                           */
/*   TEN_HSIF_LOOPBACK_XFI_TX2RX      = 7                           */
/*   TEN_HSIF_LOOPBACK_XFI_RX2TX      = 8                           */
/*   TEN_HSIF_LOOPBACK_MR_SERIAL        = 9 (TX2RX)                 */
/*   TEN_HSIF_LOOPBACK_FACILITY_XFI     = 10                        */
/*   TEN_HSIF_LOOPBACK_XFI_SERIAL_TX2RX = 11                        */
/*   TEN_HSIF_LOOPBACK_CFP_TX2RX        = 12,                       */
/*   TEN_HSIF_LOOPBACK_CFP_RX2TX        = 13,                       */
/*   TEN_HSIF_LOOPBACK_FACILITY_CFP     = 14                        */
/*                                                                  */
/*   RX2TX means that the input source for the TX datapath is       */
/*   RX loopback data.                                              */
/*                                                                  */
/*   TX2RX means that the input source for the RX datapath is       */
/*   TX loopback data.                                              */
/*                                                                  */
/*   See CS600x Datasheet (figures 92 and 93) for a diagram of      */
/*   these loopbacks.                                               */
/*                                                                  */
/*   NOTES:                                                         */ 
/*                                                                  */
/*        1. TEN_HSIF_LOOPBACK_MR_TX2RX will not work with SFI42,   */
/*        use TEN_HSIF_LOOPBACK_MR_SERIAL instead.                  */
/*                                                                  */
/*        2. For 10G TEN_HSIF_LOOPBACK_FACILITY_CFP and             */
/*        TEN_HSIF_LOOPBACK_CFP_RX2TX, only one facility loopback   */
/*        can be used at a time.                                    */
/*                                                                  */
/*        3. For CFP MR based loopbacks, when using CFP MR in       */
/*        protection switch mode, use module TEN_MODULE_A.          */ 
/*                                                                  */
/*        4. For TEN_HSIF_LOOPBACK_XFI_RX2TX, tx bit invert = '0'.  */
/*           Some setups may require tx bit invert = '1'.           */
/*                                                                  */
/* [ctl]  Controls loopback.                                        */
/*   0 = CS_DISABLE                                                 */
/*   1 = CS_ENABLE.                                                 */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  cs_status rtn = CS_OK;

  rtn = ten_hl_hsif_control_loopback_with_user_settings(module_id,
                                                        slice,
                                                        loopback,
                                                        ctl,
                                                        0);
  return (rtn);
}

/********************************************************************/
/* $rtn_hdr_start  HIGH LEVEL HSIF MR SWITCH CLOCK                  */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : HIGH LEVEL                                          */
/* CHIP       : Tenabo                                              */
cs_status ten_hl_hsif_mr_switch_clock(cs_uint16 module_id,
                                      cs_uint8 slice)
/* INPUTS     : o Module Id                                         */
/*              o Slice                                             */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Performs MR switch clock.                                        */
/*                                                                  */
/* [slice]  Specified as TEN_SLICE0 (0), TEN_SLICE1 (1),            */
/*   TEN_SLICE2 (2), TEN_SLICE3 (3) or TEN_SLICE_ALL (0xFF).        */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  if ((slice>=TEN_MAX_SLICES) && (slice != TEN_SLICE_ALL)) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": slice out of range.  s/b 0..3.");
    return (CS_ERROR);
  }

  if ((slice == TEN_SLICE0) || (slice == TEN_SLICE_ALL)) {
    ten_hsif_set_slc0_mr10x4_rxlockd0_force_lock(module_id, TEN_INSTANCE_ALL, 0, 0);
  }
  if ((slice == TEN_SLICE2) || (slice == TEN_SLICE_ALL)) {
    ten_hsif_set_slc2_mr10x4_rxlockd0_force_lock(module_id, TEN_INSTANCE_ALL, 0, 0);
  }
  if ((slice == TEN_SLICE1) || (slice == TEN_SLICE_ALL)) {
    ten_hsif_set_slc1_mr10x5_rxlockd0_force_lock(module_id, TEN_INSTANCE_ALL, 0, 0);
  }
  if ((slice == TEN_SLICE3) || (slice == TEN_SLICE_ALL)) {
    ten_hsif_set_slc3_mr10x5_rxlockd0_force_lock(module_id, TEN_INSTANCE_ALL, 0, 0);
  }
  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  HIGH LEVEL HSIF CONFIG TABLE 15                  */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : HIGH LEVEL                                          */
/* CHIP       : Tenabo                                              */
cs_status ten_hl_hsif_config_table15(cs_uint16 module_id,
                                     cs_uint8 slice,
                                     cs_uint16 rate)
/* INPUTS     : o Module Id                                         */
/*              o Slice                                             */
/*              o Rate                                              */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Configures XFI table 15.                                         */
/*                                                                  */
/* [slice]  Specified as TEN_SLICE0 (0), TEN_SLICE1 (1),            */
/*   TEN_SLICE2 (2), TEN_SLICE3 (3) or TEN_SLICE_ALL (0xFF)         */
/*                                                                  */
/* [rate]  Specified as:                                            */
/*  TEN_HSIF_XFI_RATE_GBPS_9__95_TO_12__5  = 0,                     */
/*  TEN_HSIF_XFI_RATE_GBPS_4__97_TO_6__25  = 1,                     */
/*  TEN_HSIF_XFI_RATE_GBPS_2__48_TO_3__125 = 2,                     */
/*  TEN_HSIF_XFI_RATE_GBPS_1__24_TO_1__56  = 3,                     */
/*  TEN_HSIF_XFI_RATE_GBPS_8__5_FC         = 4,                     */
/*  TEN_HSIF_XFI_RATE_GBPS_4__25_FC        = 5,                     */
/*  TEN_HSIF_XFI_RATE_GBPS_2__125_FC       = 6,                     */
/*  TEN_HSIF_XFI_RATE_GBPS_1__0625_FC      = 7,                     */
/*  TEN_HSIF_XFI_RATE_GBPS_9__95328        = 8,                     */
/*  TEN_HSIF_XFI_RATE_GBPS_10__3125        = 9,                     */
/*  TEN_HSIF_XFI_RATE_GBPS_10__52          = 10,                    */
/*  TEN_HSIF_XFI_RATE_GBPS_10__70          = 11,                    */
/*  TEN_HSIF_XFI_RATE_GBPS_11__1           = 12,                    */
/*  TEN_HSIF_XFI_RATE_GBPS_11__3           = 13,                    */
/*  TEN_HSIF_XFI_RATE_GBPS_11__7           = 14,                    */
/*  TEN_HSIF_XFI_RATE_GBPS_12__5           = 15                     */
/*  TEN_HSIF_XFI_RATE_GBPS_5_IB            = 16,                    */
/*  TEN_HSIF_XFI_RATE_GBPS_10_IB           = 17,                    */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  /* Bugzilla #19873, set defaults explicitly.  This is for clarity  */
  /* in cases where the default value does not need to change.       */
  cs_uint16 rxvco_control = TEN_XFI32X1_SDS_XFI32X1_SDS_COMMON_RXVCO0_CONTROL_dft;
  cs_uint16 txvco_control = TEN_XFI32X1_SDS_XFI32X1_SDS_COMMON_TXVCO0_CONTROL_dft;
  cs_uint16 rxvco_thres0  = TEN_XFI32X1_SDS_XFI32X1_SDS_COMMON_RXVCO0_THRES0_dft;
  cs_uint16 txvco_thres0  = TEN_XFI32X1_SDS_XFI32X1_SDS_COMMON_TXVCO0_THRES0_dft;
  cs_uint16 rxvco_thres1  = TEN_XFI32X1_SDS_XFI32X1_SDS_COMMON_RXVCO0_THRES1_dft;
  cs_uint16 txvco_thres1  = TEN_XFI32X1_SDS_XFI32X1_SDS_COMMON_TXVCO0_THRES1_dft;
  cs_status rtn = CS_OK;

  CS_PRINT("ten_hl_hsif_config_table15, slice=%d, rate = %d\n", slice, rate);



  switch (rate) {
  case (TEN_HSIF_XFI_RATE_GBPS_8__5_FC):
  case (TEN_HSIF_XFI_RATE_GBPS_4__25_FC):
  case (TEN_HSIF_XFI_RATE_GBPS_2__125_FC):
  case (TEN_HSIF_XFI_RATE_GBPS_1__0625_FC):
  case (TEN_HSIF_XFI_RATE_GBPS_1__24_TO_1__56): /* Bugzilla 38871 */
    CS_PRINT("FC 8.5 Gbps and 4/2/1 subrates\n");
    rxvco_thres0  = 0x0142;
    rxvco_thres1  = 0x0142;
    txvco_thres0  = 0x0142;
    txvco_thres1  = 0x0142;
    break;

  case (TEN_HSIF_XFI_RATE_GBPS_5_IB):
  case (TEN_HSIF_XFI_RATE_GBPS_9__95328):
  case (TEN_HSIF_XFI_RATE_GBPS_10_IB):
    CS_PRINT("9.95328 Gbps, 10.0 Gbps\n");
    rxvco_control = 0x2002;
    rxvco_thres0  = 0x0134;
    rxvco_thres1  = 0x0134;
    txvco_control = 0x2002;
    txvco_thres0  = 0x0134;
    txvco_thres1  = 0x0134;
    break;

  case (TEN_HSIF_XFI_RATE_GBPS_10__3125):
    CS_PRINT("10.3125 Gbps\n");
    rxvco_control = 0x2002;
    rxvco_thres0  = 0x0136;
    rxvco_thres1  = 0x0136;
    txvco_control = 0x2002;
    txvco_thres0  = 0x0136;
    txvco_thres1  = 0x0136;
    break;

  case (TEN_HSIF_XFI_RATE_GBPS_10__52):
    CS_PRINT("10.52 Gbps\n");
    rxvco_control = 0x0002;
    rxvco_thres0  = 0x0142;
    rxvco_thres1  = 0x0142;
    txvco_control = 0x0002;
    txvco_thres0  = 0x0142;
    txvco_thres1  = 0x0142;
    break;

  case (TEN_HSIF_XFI_RATE_GBPS_10__70):
    CS_PRINT("10.70 Gbps\n");
    rxvco_control = 0x0002;
    rxvco_thres0  = 0x0140;
    rxvco_thres1  = 0x0140;
    txvco_control = 0x0002;
    txvco_thres0  = 0x0140;
    txvco_thres1  = 0x0140;
    break;

  case (TEN_HSIF_XFI_RATE_GBPS_11__1):
    CS_PRINT("11.1 Gbps\n");
    rxvco_control = 0x0002;
    rxvco_thres0  = 0x0142;
    rxvco_thres1  = 0x0142;
    txvco_control = 0x0002;
    txvco_thres0  = 0x0142;
    txvco_thres1  = 0x0142;
    break;

  case (TEN_HSIF_XFI_RATE_GBPS_11__3):
    CS_PRINT("11.3 Gbps\n");
    rxvco_control = 0x0002;
    rxvco_thres0  = 0x0142;
    rxvco_thres1  = 0x0142;
    txvco_control = 0x0002;
    txvco_thres0  = 0x0142;
    txvco_thres1  = 0x0142;
    break;

  case (TEN_HSIF_XFI_RATE_GBPS_11__7):
    CS_PRINT("11.7 Gbps\n");
    rxvco_control = 0x0002;
    rxvco_thres0  = 0x0144;
    rxvco_thres1  = 0x0144;
    txvco_control = 0x0002;
    txvco_thres0  = 0x0144;
    txvco_thres1  = 0x0144;
    break;

  case (TEN_HSIF_XFI_RATE_GBPS_12__5):
  case (TEN_HSIF_XFI_RATE_GBPS_2__48_TO_3__125): /* Bugzilla 39690 VCO run at full rate */
    CS_PRINT("12.5 Gbps and 3.072 Gbps subrate\n");
    rxvco_control = 0x0002;
    rxvco_thres0  = 0x0144;
    rxvco_thres1  = 0x0144;
    txvco_control = 0x0002;
    txvco_thres0  = 0x0144;
    txvco_thres1  = 0x0144;
    break;

  default:
    CS_PRINT("default VCO settings.\n");
    break;
  }

  /* Bugzilla #19873, set defaults too */
  rtn |= ten_xfi32x1_rxvco0_threshold(module_id, slice, rxvco_thres0, rxvco_thres1);
  rtn |= ten_xfi32x1_txvco0_threshold(module_id, slice, txvco_thres0, txvco_thres1);
  rtn |= ten_xfi32x1_rxvco0_control(module_id, slice, rxvco_control);
  rtn |= ten_xfi32x1_txvco0_control(module_id, slice, txvco_control);

  return (rtn);
}

/* Bugzilla #20306, add div parameter for config_xfi */
/********************************************************************/
/* $rtn_hdr_start  HIGH LEVEL CONFIG XFI                            */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : HIGH LEVEL                                          */
/* CHIP       : Tenabo                                              */
cs_status ten_hl_config_xfi(cs_uint16 module_id,
                            cs_uint8 slice,
                            cs_uint16 client,
                            cs_uint16 invert_dir,
                            cs_uint16 invert,
                            cs_uint32 sysclk_freq,
                            cs_uint16 prot,
                            cs_uint16 sync,
                            cs_uint16 aux_clk,
                            cs_uint16 waitfor_vcotune)
/* INPUTS     : o Module Id                                         */
/*              o Slice                                             */
/*              o Client Traffic Type                               */
/*              o Invert Direction                                  */
/*              o Invert                                            */
/*              o Sysclk Frequency                                  */
/*              o Protection                                        */
/*              o Sync                                              */
/*              o Aux Clock                                         */
/*              o Wait For VCO Tune                                 */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Provides top-most level configuration of XFI, including          */
/* waiting for lock.                                                */
/*                                                                  */
/* NOTE:  TEN_HSIF_XFI_DIV_BY_64_REF is used for the divided by     */
/* reference.  For other values, use the related API:               */
/* ten_hl_config_xfi_with_div.                                      */
/*                                                                  */
/* The [slice] parameter is specified as:                           */
/*   0x00 = TEN_SLICE0                                              */
/*   0x01 = TEN_SLICE1                                              */
/*   0x02 = TEN_SLICE2                                              */
/*   0x03 = TEN_SLICE3                                              */
/*   0xFF = TEN_SLICE_ALL                                           */
/*                                                                  */
/* [client]                                                         */
/*   TEN_TRAFFIC_TYPE_NONE = 0                                      */
/*   TEN_TRAFFIC_TYPE_OTU3 = 1                                      */
/*   TEN_TRAFFIC_TYPE_OTU3E = 2                                     */
/*   TEN_TRAFFIC_TYPE_OTU3P = 3                                     */
/*   TEN_TRAFFIC_TYPE_ODTU23 = 4                                    */
/*   TEN_TRAFFIC_TYPE_OTU2 = 5                                      */
/*   TEN_TRAFFIC_TYPE_OTU2E = 6                                     */
/*   TEN_TRAFFIC_TYPE_OTU1F = 7                                     */
/*   TEN_TRAFFIC_TYPE_OC192 = 8                                     */
/*   TEN_TRAFFIC_TYPE_10GE_WAN = 9                                  */
/*   TEN_TRAFFIC_TYPE_10GE_6_2 = 10                                 */
/*   TEN_TRAFFIC_TYPE_10GE_7_1 = 11                                 */
/*   TEN_TRAFFIC_TYPE_10GE_7_3 = 12                                 */
/*   TEN_TRAFFIC_TYPE_10GFC = 13                                    */
/*   TEN_TRAFFIC_TYPE_8GFC = 14                                     */
/*   TEN_TRAFFIC_TYPE_4GFC = 15                                     */
/*   TEN_TRAFFIC_TYPE_2GFC = 16                                     */
/*   TEN_TRAFFIC_TYPE_1GFC = 17                                     */
/*   TEN_TRAFFIC_TYPE_5GB_IB = 18                                   */
/*   TEN_TRAFFIC_TYPE_10GE_6_1 = 26                                 */
/*   TEN_TRAFFIC_TYPE_10GE_TC = 33                                  */
/*   TEN_TRAFFIC_TYPE_10GFC_TC             = 46                     */
/*   TEN_TRAFFIC_TYPE_8GFC_RA              = 47                     */
/*   TEN_TRAFFIC_TYPE_4GFC_RA              = 48                     */
/*   TEN_TRAFFIC_TYPE_2GFC_RA              = 49                     */
/*   TEN_TRAFFIC_TYPE_1GFC_RA              = 50                     */
/*   TEN_TRAFFIC_TYPE_8GFC_ENH             = 51                     */
/*   TEN_TRAFFIC_TYPE_4GFC_ENH             = 52                     */
/*   TEN_TRAFFIC_TYPE_2GFC_ENH             = 53                     */
/*   TEN_TRAFFIC_TYPE_1GFC_ENH             = 54                     */
/*   TEN_TRAFFIC_TYPE_10GFC_TC_G709        = 57                     */
/*   TEN_TRAFFIC_TYPE_10GFC_TC_RA          = 58                     */
/*   TEN_TRAFFIC_TYPE_2GISC                = 59                     */
/*   TEN_TRAFFIC_TYPE_1GE                  = 63                     */
/*                                                                  */
/* [invert_dir]                                                     */
/*   0 = CS_TX                                                      */
/*   1 = CS_RX                                                      */
/*   2 = CS_TX_AND_RX                                               */
/*                                                                  */
/* [invert]                                                         */
/*   0 = do not invert the bit polarity of all TX/RX data bits      */
/*   1 = invert the bit polarity of all TX/RX data bits             */
/*                                                                  */
/* [sysclk_freq]                                                    */
/*   Sys clock frequency in Hertz, ie 400000000                     */
/*                                                                  */
/* [prot]                                                           */
/*   0 = do not set up the receive protection clock                 */
/*   1 = set up the receive protection clock                        */
/*                                                                  */
/* [sync]                                                           */
/*   0 = async                                                      */
/*   1 = sync                                                       */
/*                                                                  */
/* [aux_clk]                                                        */
/*   0 = do not use auxillary clock                                 */
/*   1 = use auxillary clock                                        */
/*                                                                  */
/* [waitfor_vcotune]                                                */
/*   0 = do not wait for vcotune (not recommended)                  */
/*   1 = wait for vcotune (recommended).                            */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  return (ten_hl_config_xfi_with_div(module_id,
                                     slice,
                                     client,
                                     invert_dir,
                                     invert,
                                     sysclk_freq,
                                     prot,
                                     sync,
                                     aux_clk,
                                     waitfor_vcotune,
                                     TEN_HSIF_XFI_DIV_BY_64_REF));
}

/* Bugzilla #20306, add div parameter for config_xfi */
/********************************************************************/
/* $rtn_hdr_start  HIGH LEVEL CONFIG XFI WITH DIV                   */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : HIGH LEVEL                                          */
/* CHIP       : Tenabo                                              */
cs_status ten_hl_config_xfi_with_div(cs_uint16 module_id,
                            cs_uint8 slice,
                            cs_uint16 client,
                            cs_uint16 invert_dir,
                            cs_uint16 invert,
                            cs_uint32 sysclk_freq,
                            cs_uint16 prot,
                            cs_uint16 sync,
                            cs_uint16 aux_clk,
                            cs_uint16 waitfor_vcotune,
                            cs_uint16 div)
/* INPUTS     : o Module Id                                         */
/*              o Slice                                             */
/*              o Client Traffic Type                               */
/*              o Invert Direction                                  */
/*              o Invert                                            */
/*              o Sysclk Frequency                                  */
/*              o Protection                                        */
/*              o Sync                                              */
/*              o Aux Clock                                         */
/*              o Wait For VCO Tune                                 */
/*              o Div                                               */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Provides top-most level configuration of XFI, including          */
/* waiting for lock.                                                */
/*                                                                  */
/* The [slice] parameter is specified as:                           */
/*   0x00 = TEN_SLICE0                                              */
/*   0x01 = TEN_SLICE1                                              */
/*   0x02 = TEN_SLICE2                                              */
/*   0x03 = TEN_SLICE3                                              */
/*   0xFF = TEN_SLICE_ALL                                           */
/*                                                                  */
/* [client]                                                         */
/*   TEN_TRAFFIC_TYPE_NONE = 0                                      */
/*   TEN_TRAFFIC_TYPE_OTU3 = 1                                      */
/*   TEN_TRAFFIC_TYPE_OTU3E = 2                                     */
/*   TEN_TRAFFIC_TYPE_OTU3P = 3                                     */
/*   TEN_TRAFFIC_TYPE_ODTU23 = 4                                    */
/*   TEN_TRAFFIC_TYPE_OTU2 = 5                                      */
/*   TEN_TRAFFIC_TYPE_OTU2E = 6                                     */
/*   TEN_TRAFFIC_TYPE_OTU1F = 7                                     */
/*   TEN_TRAFFIC_TYPE_OC192 = 8                                     */
/*   TEN_TRAFFIC_TYPE_10GE_WAN = 9                                  */
/*   TEN_TRAFFIC_TYPE_10GE_6_2 = 10                                 */
/*   TEN_TRAFFIC_TYPE_10GE_7_1 = 11                                 */
/*   TEN_TRAFFIC_TYPE_10GE_7_3 = 12                                 */
/*   TEN_TRAFFIC_TYPE_10GFC = 13                                    */
/*   TEN_TRAFFIC_TYPE_8GFC = 14                                     */
/*   TEN_TRAFFIC_TYPE_4GFC = 15                                     */
/*   TEN_TRAFFIC_TYPE_2GFC = 16                                     */
/*   TEN_TRAFFIC_TYPE_1GFC = 17                                     */
/*   TEN_TRAFFIC_TYPE_5GB_IB = 18                                   */
/*   TEN_TRAFFIC_TYPE_10GE_6_1 = 26                                 */
/*   TEN_TRAFFIC_TYPE_10GE_TC = 33                                  */
/*   TEN_TRAFFIC_TYPE_10GFC_TC             = 46                     */
/*   TEN_TRAFFIC_TYPE_8GFC_RA              = 47                     */
/*   TEN_TRAFFIC_TYPE_4GFC_RA              = 48                     */
/*   TEN_TRAFFIC_TYPE_2GFC_RA              = 49                     */
/*   TEN_TRAFFIC_TYPE_1GFC_RA              = 50                     */
/*   TEN_TRAFFIC_TYPE_8GFC_ENH             = 51                     */
/*   TEN_TRAFFIC_TYPE_4GFC_ENH             = 52                     */
/*   TEN_TRAFFIC_TYPE_2GFC_ENH             = 53                     */
/*   TEN_TRAFFIC_TYPE_1GFC_ENH             = 54                     */
/*   TEN_TRAFFIC_TYPE_10GFC_STD            = 57                     */
/*   TEN_TRAFFIC_TYPE_10GFC_TC_RA          = 58                     */
/*   TEN_TRAFFIC_TYPE_2GISC                = 59                     */
/*   TEN_TRAFFIC_TYPE_1GE                  = 63                     */
/*                                                                  */
/* [invert_dir]                                                     */
/*   0 = CS_TX                                                      */
/*   1 = CS_RX                                                      */
/*   2 = CS_TX_AND_RX                                               */
/*                                                                  */
/* [invert]                                                         */
/*   0 = do not invert the bit polarity of all TX/RX data bits      */
/*   1 = invert the bit polarity of all TX/RX data bits             */
/*                                                                  */
/* [sysclk_freq]                                                    */
/*   Sys clock frequency in Hertz, ie 400000000                     */
/*                                                                  */
/* [prot]                                                           */
/*   0 = do not set up the receive protection clock                 */
/*   1 = set up the receive protection clock                        */
/*                                                                  */
/* [sync]                                                           */
/*   0 = async                                                      */
/*   1 = sync                                                       */
/*                                                                  */
/* [aux_clk]                                                        */
/*   0 = do not use auxillary clock                                 */
/*   1 = use auxillary clock                                        */
/*                                                                  */
/* [waitfor_vcotune]                                                */
/*   0 = do not wait for vcotune (not recommended)                  */
/*   1 = wait for vcotune (recommended).                            */
/*                                                                  */
/* [div]  Specified as:                                             */
/*  TEN_HSIF_XFI_DIV_BY_16_REF          = 0,                        */
/*  TEN_HSIF_XFI_DIV_BY_40_REF          = 1,                        */
/*  TEN_HSIF_XFI_DIV_BY_64_REF          = 2,                        */
/*  TEN_HSIF_XFI_DIV_BY_80_REF          = 3                         */
/*  TEN_HSIF_XFI_DIV_BY_16_AUX_LPTM_REF = 4,                        */
/*  TEN_HSIF_XFI_DIV_BY_40_AUX_LPTM_REF = 5,                        */
/*  TEN_HSIF_XFI_DIV_BY_64_AUX_LPTM_REF = 6,                        */
/*  TEN_HSIF_XFI_DIV_BY_80_AUX_LPTM_REF = 7,                        */
/*  TEN_HSIF_XFI_DIV_BY_32_REF          = 8,                        */
/*  TEN_HSIF_XFI_DIV_BY_66_REF          = 9,                        */
/*  TEN_HSIF_XFI_DIV_BY_32_AUX_LPTM_REF = 10,                       */
/*  TEN_HSIF_XFI_DIV_BY_66_AUX_LPTM_REF = 11.                       */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  CS_PRINT("ten_hl_config_xfi_with_div\n");
   
  /* Bugzilla #26738/28208, default xfi clock distribution to external */
  return (ten_hl_config_xfi_t41(module_id,
                                slice,
                                client,
                                invert_dir,
                                invert,
                                sysclk_freq,
                                prot,
                                sync,
                                aux_clk,
                                waitfor_vcotune,
                                div, 
                                1,
                                0,
                                0));
}

/* Bugzilla #26738/28208, add parameter for xfi clock distribution */

/********************************************************************/
/* $rtn_hdr_start  HIGH LEVEL CONFIG XFI T41                        */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : HIGH LEVEL                                          */
/* CHIP       : Tenabo                                              */
cs_status ten_hl_config_xfi_t41(cs_uint16 module_id,
                                cs_uint8 slice,
                                cs_uint16 client,
                                cs_uint16 invert_dir,
                                cs_uint16 invert,
                                cs_uint32 sysclk_freq,
                                cs_uint16 prot,
                                cs_uint16 sync,
                                cs_uint16 aux_clk,
                                cs_uint16 waitfor_vcotune,
                                cs_uint16 div,
                                cs_uint16 clock_distribution,
                                cs_uint16 ext1,
                                cs_uint16 ext2)
/* INPUTS     : o Module Id                                         */
/*              o Slice                                             */
/*              o Client Traffic Type                               */
/*              o Invert Direction                                  */
/*              o Invert                                            */
/*              o Sysclk Frequency                                  */
/*              o Protection                                        */
/*              o Sync                                              */
/*              o Aux Clock                                         */
/*              o Wait For VCO Tune                                 */
/*              o Div                                               */
/*              o Clock Distribution                                */
/*              o Extension 1                                       */
/*              o Extension 2                                       */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Provides top-most level configuration of XFI, including          */
/* waiting for lock.                                                */
/*                                                                  */
/* The [slice] parameter is specified as:                           */
/*   0x00 = TEN_SLICE0                                              */
/*   0x01 = TEN_SLICE1                                              */
/*   0x02 = TEN_SLICE2                                              */
/*   0x03 = TEN_SLICE3                                              */
/*   0xFF = TEN_SLICE_ALL                                           */
/*                                                                  */
/* [client]                                                         */
/*   TEN_TRAFFIC_TYPE_NONE = 0                                      */
/*   TEN_TRAFFIC_TYPE_OTU3 = 1                                      */
/*   TEN_TRAFFIC_TYPE_OTU3E = 2                                     */
/*   TEN_TRAFFIC_TYPE_OTU3P = 3                                     */
/*   TEN_TRAFFIC_TYPE_ODTU23 = 4                                    */
/*   TEN_TRAFFIC_TYPE_OTU2 = 5                                      */
/*   TEN_TRAFFIC_TYPE_OTU2E = 6                                     */
/*   TEN_TRAFFIC_TYPE_OTU1F = 7                                     */
/*   TEN_TRAFFIC_TYPE_OC192 = 8                                     */
/*   TEN_TRAFFIC_TYPE_10GE_WAN = 9                                  */
/*   TEN_TRAFFIC_TYPE_10GE_6_2 = 10                                 */
/*   TEN_TRAFFIC_TYPE_10GE_7_1 = 11                                 */
/*   TEN_TRAFFIC_TYPE_10GE_7_3 = 12                                 */
/*   TEN_TRAFFIC_TYPE_10GFC = 13                                    */
/*   TEN_TRAFFIC_TYPE_8GFC = 14                                     */
/*   TEN_TRAFFIC_TYPE_4GFC = 15                                     */
/*   TEN_TRAFFIC_TYPE_2GFC = 16                                     */
/*   TEN_TRAFFIC_TYPE_1GFC = 17                                     */
/*   TEN_TRAFFIC_TYPE_5GB_IB = 18                                   */
/*   TEN_TRAFFIC_TYPE_10GE_6_1 = 26                                 */
/*   TEN_TRAFFIC_TYPE_10GE_TC = 33                                  */
/*   TEN_TRAFFIC_TYPE_10G_IB               = 39                     */
/*   TEN_TRAFFIC_TYPE_10GFC_TC             = 46                     */
/*   TEN_TRAFFIC_TYPE_8GFC_RA              = 47                     */
/*   TEN_TRAFFIC_TYPE_4GFC_RA              = 48                     */
/*   TEN_TRAFFIC_TYPE_2GFC_RA              = 49                     */
/*   TEN_TRAFFIC_TYPE_1GFC_RA              = 50                     */
/*   TEN_TRAFFIC_TYPE_8GFC_ENH             = 51                     */
/*   TEN_TRAFFIC_TYPE_4GFC_ENH             = 52                     */
/*   TEN_TRAFFIC_TYPE_2GFC_ENH             = 53                     */
/*   TEN_TRAFFIC_TYPE_1GFC_ENH             = 54                     */
/*   TEN_TRAFFIC_TYPE_10GE_GFPF            = 56                     */
/*   TEN_TRAFFIC_TYPE_10GFC_STD            = 57                     */
/*   TEN_TRAFFIC_TYPE_10GFC_TC_RA          = 58                     */
/*   TEN_TRAFFIC_TYPE_2GISC                = 59                     */
/*   TEN_TRAFFIC_TYPE_1GE                  = 63                     */
/*   TEN_TRAFFIC_TYPE_FDR10_IB             = 64                     */
/*   TEN_TRAFFIC_TYPE_CBR_10G              = 67                     */
/*                                                                  */
/* [invert_dir]                                                     */
/*   0 = CS_TX                                                      */
/*   1 = CS_RX                                                      */
/*   2 = CS_TX_AND_RX                                               */
/*                                                                  */
/* [invert]                                                         */
/*   0 = do not invert the bit polarity of all TX/RX data bits      */
/*   1 = invert the bit polarity of all TX/RX data bits             */
/*                                                                  */
/* [sysclk_freq]                                                    */
/*   Sys clock frequency in Hertz, ie 400000000                     */
/*                                                                  */
/* [prot]                                                           */
/*   0 = do not set up the receive protection clock                 */
/*   1 = set up the receive protection clock                        */
/*                                                                  */
/* [sync]                                                           */
/*   0 = async                                                      */
/*   1 = sync                                                       */
/*                                                                  */
/* [aux_clk]                                                        */
/*   0 = do not use auxillary clock                                 */
/*   1 = use auxillary clock                                        */
/*                                                                  */
/* [waitfor_vcotune]                                                */
/*   0 = do not wait for vcotune (not recommended)                  */
/*   1 = wait for vcotune (recommended).                            */
/*                                                                  */
/* [div]  Specified as:                                             */
/*  TEN_HSIF_XFI_DIV_BY_16_REF          = 0,                        */
/*  TEN_HSIF_XFI_DIV_BY_40_REF          = 1,                        */
/*  TEN_HSIF_XFI_DIV_BY_64_REF          = 2,                        */
/*  TEN_HSIF_XFI_DIV_BY_80_REF          = 3                         */
/*  TEN_HSIF_XFI_DIV_BY_16_AUX_LPTM_REF = 4,                        */
/*  TEN_HSIF_XFI_DIV_BY_40_AUX_LPTM_REF = 5,                        */
/*  TEN_HSIF_XFI_DIV_BY_64_AUX_LPTM_REF = 6,                        */
/*  TEN_HSIF_XFI_DIV_BY_80_AUX_LPTM_REF = 7,                        */
/*  TEN_HSIF_XFI_DIV_BY_32_REF          = 8,                        */
/*  TEN_HSIF_XFI_DIV_BY_66_REF          = 9,                        */
/*  TEN_HSIF_XFI_DIV_BY_32_AUX_LPTM_REF = 10,                       */
/*  TEN_HSIF_XFI_DIV_BY_66_AUX_LPTM_REF = 11                        */
/*                                                                  */
/* [clock_distribution]  Specified as:                              */
/*   0 = internal, fan-out clock distribution                       */
/*   1 = external clock distribution                                */
/*                                                                  */
/* [ext1]  Specified as:                                            */
/*   k_value,  0..64 decimal                                        */
/*                                                                  */
/* [ext2]  Specified as:                                            */
/*   0 - future extension2, not presently used.                     */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  cs_uint16 dev_id = TEN_MOD_ID_TO_DEV_ID(module_id);
  cs_uint16 instance;
  cs_uint16 gpll_mode;
  cs_uint16 xfi_rate;
  cs_uint16 download_ucode = 1;
  cs_uint16 srx_phsel;
  cs_status rtn = CS_OK;
  cs_char8 *func = "ten_hl_config_xfi_t41";
  cs_uint16 tmp_ext2;
  cs_uint16 xfi_is_40g_traffic = 0;
  cs_uint16 tx_rdiv, tx_ctvdiv;

  if (TEN_MOD_ID_TO_MOD_NUM(module_id) != TEN_MODULE_B) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, "%s() XFI available only on Module B.", func);
    return (CS_ERROR);
  }

  if ((slice>=TEN_MAX_SLICES) && (slice != TEN_SLICE_ALL)) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, "%s() slice out of range.  s/b 0..3.", func);
    return (CS_ERROR);
  }

  if ((client == TEN_TRAFFIC_TYPE_NONE) || (client >= TEN_TRAFFIC_TYPE_MAX)) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, "%s() traffic type %d out of range.", func, client);
    return (CS_ERROR);
  }
  
  CS_PRINT("%s() %s, %s, %s, %s\n", 
           func,
           ten_module_strings[module_id&1],
           ten_slice_strings[slice],
           ten_hl_config_traffic_types_strings[client],
           ten_dir_strings[invert_dir]);
           
  CS_PRINT("invert=%d, sysclk_freq=%d, prot=%d, aux_clk=%d\n",
           invert,
           sysclk_freq,
           prot,
           aux_clk);
  
  CS_PRINT("waitfor_vcotune=%d, div=%d, clk_dist=%d, ext1/k_value=%d, ext2=%d\n",
           waitfor_vcotune,
           div,
           clock_distribution,
           ext1,
           ext2);
           
  /* variables for future extension */
  tmp_ext2 = ext2;
  
  /* Assert reset in case of dynamic reprovisioning and the clock rate has changed */
  if (ten_mpif_global_reset_sds_xfi(dev_id, slice, CS_TX_AND_RX, CS_RESET_ASSERT) != CS_OK) {    
    /* bugzilla #21921, increase error report resolution */
    rtn |= CS_ERROR;
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_OP, "%s() ten_mpif_global_reset_sds_xfi() failed 0x%2X", func, rtn);
  }

  /* This resets the microsequencer which can't be running when the port is reprovisioned */
  if (ten_mpif_global_reset_xfi_dsp(dev_id, slice, CS_RESET_ASSERT) != CS_OK) {
    rtn |= CS_ERROR;
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_OP, "%s() ten_mpif_global_reset_xfi_dsp() failed 0x%2X", func, rtn);
  }

  /* sleep 20ms; */
  TEN_MDELAY(20);

  download_ucode = 1;
  switch (client) {
  case (TEN_TRAFFIC_TYPE_OTU2): /* OTU2/otu2=10709.2253 */
    xfi_rate = TEN_HSIF_XFI_RATE_GBPS_10__70;
    break;

  case (TEN_TRAFFIC_TYPE_OTU2E): /* OTU2e/otu210geopu2e=11095.7278 */
  /* Bugzilla 20308 Start */
  case (TEN_TRAFFIC_TYPE_OTU1E): /* OTU1e/otu210geopu1e=11049.107143 */
  /* Bugzilla 20308 End */
    xfi_rate = TEN_HSIF_XFI_RATE_GBPS_11__1;
    break;

  case (TEN_TRAFFIC_TYPE_OTU1F): /* OTU1f/otu210gfcopu1e=11270.0893 */
    xfi_rate = TEN_HSIF_XFI_RATE_GBPS_11__3;
    break;

  case (TEN_TRAFFIC_TYPE_10GE_WAN):
  case (TEN_TRAFFIC_TYPE_OC192): /* OC192/oc192=9953.28 */
    xfi_rate = TEN_HSIF_XFI_RATE_GBPS_9__95328;
    break;

  case (TEN_TRAFFIC_TYPE_10GE):
  case (TEN_TRAFFIC_TYPE_10GE_6_1):
  case (TEN_TRAFFIC_TYPE_10GE_6_2):
  case (TEN_TRAFFIC_TYPE_10GE_7_1):
  /* Bugzilla 20308 Start */
  case (TEN_TRAFFIC_TYPE_10GE_7_2):
  case (TEN_TRAFFIC_TYPE_10GE_7_3):  /* 10GE/10gelan=10312.5 */
  case (TEN_TRAFFIC_TYPE_10GE_GFPF_OC192_ODU2):
  /* Bugzilla 20308 End */
  case (TEN_TRAFFIC_TYPE_10GE_RA): /* Bugzilla 22237 */
  case (TEN_TRAFFIC_TYPE_10GE_TC):
  case (TEN_TRAFFIC_TYPE_10GE_GFPF): /* Bugzilla 29991 */
  case (TEN_TRAFFIC_TYPE_FDR10_IB):  /* Bugzilla 39242 */
    xfi_rate = TEN_HSIF_XFI_RATE_GBPS_10__3125;
    break;

  case (TEN_TRAFFIC_TYPE_10GFC):  /* 10GFC/fc1200=10518.75 */
  case (TEN_TRAFFIC_TYPE_10GFC_TC_RA):
  case  TEN_TRAFFIC_TYPE_10GFC_TC:  /* Bugzilla 24360 */
  case  TEN_TRAFFIC_TYPE_10GFC_TC_G709: /* Bug 31054 */
    xfi_rate = TEN_HSIF_XFI_RATE_GBPS_10__52;
    break;

  case (TEN_TRAFFIC_TYPE_8GFC):  /* 8GFC/fc800=8500 */
  case (TEN_TRAFFIC_TYPE_8GFC_RA):  /* 8GFC/fc800=8500 */
  case (TEN_TRAFFIC_TYPE_8GFC_ENH):  /* 8GFC/fc800=8500 */
    xfi_rate = TEN_HSIF_XFI_RATE_GBPS_8__5_FC;
    /* Bugzilla # ,download microcode for 8GFC, not 4/2/1 though */
    break;

  case (TEN_TRAFFIC_TYPE_4GFC):
  case (TEN_TRAFFIC_TYPE_4GFC_RA):
  case (TEN_TRAFFIC_TYPE_4GFC_ENH):
    xfi_rate = TEN_HSIF_XFI_RATE_GBPS_4__25_FC;
    download_ucode = 0;
    break;

  case (TEN_TRAFFIC_TYPE_2GFC):
  case (TEN_TRAFFIC_TYPE_2GFC_RA):
  case (TEN_TRAFFIC_TYPE_2GFC_ENH):
  case (TEN_TRAFFIC_TYPE_2GISC):
    xfi_rate = TEN_HSIF_XFI_RATE_GBPS_2__125_FC;
    download_ucode = 0;
    break;

  case (TEN_TRAFFIC_TYPE_CPRI_4): /* Bugzilla 39690 */
    xfi_rate = TEN_HSIF_XFI_RATE_GBPS_2__48_TO_3__125;
    download_ucode = 0;
    break;

  case (TEN_TRAFFIC_TYPE_1GFC):
  case (TEN_TRAFFIC_TYPE_1GFC_RA):
  case (TEN_TRAFFIC_TYPE_1GFC_ENH):
    xfi_rate = TEN_HSIF_XFI_RATE_GBPS_1__0625_FC;
    download_ucode = 0;
    break;

  case (TEN_TRAFFIC_TYPE_1GE): /* Bugzilla 38871 - using 1GFC divider & filter settings */
    xfi_rate = TEN_HSIF_XFI_RATE_GBPS_1__24_TO_1__56;
    download_ucode = 0;
    break;

  case (TEN_TRAFFIC_TYPE_5GB_IB):
    xfi_rate = TEN_HSIF_XFI_RATE_GBPS_5_IB;
    download_ucode = 0;
    break;

  case (TEN_TRAFFIC_TYPE_10G_IB):
    xfi_rate = TEN_HSIF_XFI_RATE_GBPS_10_IB;
    /* download_ucode = 0; */
    break;



  case (TEN_TRAFFIC_TYPE_CBR_10G):              /* Bugzilla 43573 */
    xfi_rate = TEN_HSIF_XFI_RATE_GBPS_10__70;
    break;

  case (TEN_TRAFFIC_TYPE_OC768_OTU3):
  case (TEN_TRAFFIC_TYPE_OTU3):
    xfi_rate = TEN_HSIF_XFI_RATE_GBPS_10__70;
    xfi_is_40g_traffic = 1;
    break;
  
  case (TEN_TRAFFIC_TYPE_OTU3E):
  case (TEN_TRAFFIC_TYPE_OTU3P):
  /* case (TEN_TRAFFIC_TYPE_OTU3E1): */
  case (TEN_TRAFFIC_TYPE_OTU3E2):
  case (TEN_TRAFFIC_TYPE_OTU3E3):
  case (TEN_TRAFFIC_TYPE_OTU3P2):
    xfi_rate = TEN_HSIF_XFI_RATE_GBPS_11__1;
    xfi_is_40g_traffic = 1;
    break;

  case (TEN_TRAFFIC_TYPE_OC768):
    xfi_rate = TEN_HSIF_XFI_RATE_GBPS_9__95328;
    xfi_is_40g_traffic = 1;
    break;

  case (TEN_TRAFFIC_TYPE_40GELAN):
  case (TEN_TRAFFIC_TYPE_CBR40G_50188149150):
  case (TEN_TRAFFIC_TYPE_SERIAL_40GE):
  case (TEN_TRAFFIC_TYPE_PARALLEL_40GE):
  case (TEN_TRAFFIC_TYPE_TC_40GE):
  case (TEN_TRAFFIC_TYPE_S64_66_40GE):
    xfi_rate = TEN_HSIF_XFI_RATE_GBPS_10__3125;
    xfi_is_40g_traffic = 1;
    break;
    
  default:
    CS_PRINT("%s() client %d not found!\n",  func, client);
    xfi_rate = TEN_HSIF_XFI_RATE_GBPS_9__95_TO_12__5;
    break;
  }
  
  /* Bugzilla #37267: Powerup all slices in XFI 40G mode before configuring each individual slice */
  if ((xfi_is_40g_traffic) && (slice == TEN_SLICE0)) {
    ten_hl_hsif_powerdown_xfi(module_id, TEN_SLICE_ALL, CS_DISABLE);
  }

  if (ten_hl_hsif_config_xfi(module_id, slice, xfi_rate, div, 1) != CS_OK) {
    rtn |= CS_ERROR;
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_OP, "%s() ten_hl_hsif_config_xfi() failed 0x%2X", func, rtn);
  }

  /* Bugszila #26738, add selection for clock distribution */
  /* Bugzilla 26738 Start */
  /* Broadcast XFI master clock to the other 3 slices */
    switch (client) {
      case (TEN_TRAFFIC_TYPE_OC768_OTU3):
      case (TEN_TRAFFIC_TYPE_OTU3):
      case (TEN_TRAFFIC_TYPE_OTU3E):
      case (TEN_TRAFFIC_TYPE_OTU3P):
      case (TEN_TRAFFIC_TYPE_OTU3E2):
      case (TEN_TRAFFIC_TYPE_OTU3E3):
      case (TEN_TRAFFIC_TYPE_OTU3P2):
      case (TEN_TRAFFIC_TYPE_OC768):
      case (TEN_TRAFFIC_TYPE_40GELAN):
      case (TEN_TRAFFIC_TYPE_CBR40G_50188149150):
      case (TEN_TRAFFIC_TYPE_SERIAL_40GE):
      case (TEN_TRAFFIC_TYPE_PARALLEL_40GE):
      case (TEN_TRAFFIC_TYPE_TC_40GE):
      case (TEN_TRAFFIC_TYPE_S64_66_40GE):
      /*  Bug #37397 - Clock bring-up sequence for 40G XFI clients with external CUPLL */
      /*  can create microcode download issues                                         */
      if (clock_distribution == 0) {
        ten_xfi32x1_stxp0_tx_sfi52_clkrefouten_t41(module_id, 2, 1);
        ten_xfi32x1_stxp0_tx_sfi52_pilotouten_t41(module_id, 2, 1);
        ten_xfi32x1_stxp0_tx_config_lptime_sel_msb_t41(module_id, slice, 1);
      }
      ten_xfi32x1_stxp0_tx_config_pilot_sel(module_id, slice, 1);
      ten_xfi32x1_stxp0_tx_sfi52_pilotout_sel_t41(module_id, 2, 3);
      ten_xfi32x1_stxp0_tx_sfi52_pilotout_div_sel_t41(module_id, 2, 1);

      if (ext1 == 16) {  /* k_value */
        tx_rdiv = 0;
        tx_ctvdiv = 2; 
      }
      else if (ext1 == 32) { /* k_value */
        tx_rdiv = 1;
        tx_ctvdiv = 1; 
      }
      else { /* k_value=64 */
        tx_rdiv = 2;
        tx_ctvdiv = 0; 
      }
      rtn |= ten_xfi32x1_stxp0_tx_clkdiv_ctrl_rdiv_sel(module_id, slice, tx_rdiv); 
      rtn |= ten_xfi32x1_stxp0_tx_clkdiv_ctrl_ctv_div(module_id, slice, tx_ctvdiv);
      break;
    default:
        break;
    }
    /* Bugzilla 26738 End */
 
  /* Use the internal pilot */
  /* Bug 25232 Start */
  /* The "if" clause means that 1->0 writes are impossible */
  /* if (invert) { */
  /*     rtn |= ten_xfi32x1_invert(module_id, slice, invert_dir, invert); */
  /* } */
  /* Bug 25232 End */
  if (ten_xfi32x1_invert(module_id, slice, invert_dir, invert) != CS_OK) {
    rtn |= CS_ERROR;
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_OP, "%s() ten_xfi32x1_invert() failed 0x%2X", func, rtn);
  }

  if (aux_clk) {
    /*  stxp_lptime_sel = 1  */
    /* Bug 30295: Only stxp_lptime_sel needs to be set at this point.    */
    if (ten_xfi32x1_stxp0_tx_lptime_sel(module_id, slice, 1) != CS_OK) {
      rtn |= CS_ERROR;
      CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_OP, "%s() ten_xfi32x1_stxp0_tx_config() failed 0x%2X", func, rtn);
    }
  }

  if (waitfor_vcotune) {
    if (ten_hl_hsif_xfi_waitfor_vcotune(module_id, slice) != 1) {
      CS_PRINT("%s() ERROR: config_xfi: ten_hl_hsif_xfi_waitfor_vcotune failed for slice = %d\n", func, slice);
      rtn |= CS_ERROR;
    }
  }

  /* Bugzilla #36663 - XFI DSP register reset */
  rtn |= ten_mpif_global_reset_sds_xfi_dsp_t41(dev_id, slice, CS_RESET_TOGGLE);

  /* Bugzilla #19353, fix bus errors */
  /* Re-enable the DSP for microcode download */
  if (ten_mpif_global_reset_xfi_dsp(dev_id, slice, CS_RESET_DEASSERT) != CS_OK) {
    rtn |= CS_ERROR;
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_OP, "%s() ten_mpif_global_reset_xfi_dsp() failed 0x%2X", func, rtn);
  }
  
  /* Bugzilla #32555:  Fix XFI bus errors on first configuration after power-up */
  rtn |= ten_xfi32x1_mseqclkctrl_entiremspowerup(module_id, slice, 1);
  TEN_MDELAY(6);
  rtn |= ten_xfi32x1_mseqclkctrl_entiremspowerup(module_id, slice, 0);

  /* Section 8.28, CDR Phase Settings */
  switch (xfi_rate) {
  case (TEN_HSIF_XFI_RATE_GBPS_8__5_FC):
    srx_phsel = 0x1E;
    break;

  case (TEN_HSIF_XFI_RATE_GBPS_9__95328):
  case (TEN_HSIF_XFI_RATE_GBPS_10__3125):
  case (TEN_HSIF_XFI_RATE_GBPS_10__52):
  case (TEN_HSIF_XFI_RATE_GBPS_10__70):
    srx_phsel = 0x1F;
    break;

  case (TEN_HSIF_XFI_RATE_GBPS_11__1):
  case (TEN_HSIF_XFI_RATE_GBPS_11__3):
  case (TEN_HSIF_XFI_RATE_GBPS_11__7):
    srx_phsel = 0x20;
    break;

  case (TEN_HSIF_XFI_RATE_GBPS_12__5):
    srx_phsel = 0x21;
    break;

  /* Bugzilla #19873: set back to default for clarity */
  default:
    srx_phsel = TEN_XFI32X1_SDS_SDS_DSP_MSEQ_CAL_RX_PHSEL_dft;  /* 0x0020 */
    break;
  }
  if (ten_xfi32x1_cal_rx_phsel(module_id, slice, srx_phsel) != CS_OK) {
    rtn |= CS_ERROR;
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_OP, "%s() ten_xfi32x1_cal_rx_phsel() failed 0x%2X", func, rtn);
  }

  if (ten_hl_hsif_xfi_analog_cfg_srx_filtr(module_id, slice, xfi_rate, div) != CS_OK) {
    rtn |= CS_ERROR;
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_OP, "%s() ten_hl_hsif_xfi_analog_cfg_srx_filtr() failed 0x%2X", func, rtn);
  }
  
  /* Do not download microcode if the rate is 1/2/4GFC or    */
  /* 5GIB (i.e. not full-rate which includes 8GFC)           */
  /* bugzilla #21921, Don't return failures for microcode issues */
  if ((download_ucode) && (!ten_dev_is_ws_in_progress(dev_id))) {
    if (ten_hl_hsif_xfi_download_micro_code(module_id, slice) != CS_OK) {
        rtn |= CS_ERROR;
      CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_OP, "%s() ten_hl_hsif_xfi_download_micro_code() failed 0x%2X", func, rtn);
    }

    if (g_pTEN->ucode_flag) {
      if (ten_hl_hsif_xfi_verify_micro_code_download(module_id, slice) != CS_OK) {
        rtn |= CS_ERROR;
        CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_OP, "%s() ten_hl_hsif_xfi_verify_micro_code_download() failed 0x%2X", func, rtn);
      }
    }
    
    /* bugzilla #21921, split up verify and running flags */
    if (g_pTEN->ucode_running_flag) {
      /* return CS_ERROR is microcode is not RUNNING. */
      if (ten_hl_hsif_xfi_check_micro_code_status(module_id, slice) != 1) {
        CS_PRINT("%s() ten_hl_hsif_xfi_check_micro_code_status FAILED.\n", func);
        rtn |= CS_ERROR;
      }
    }
  }
   
  /* config_GPLL */
  if (TEN_MOD_ID_TO_MOD_NUM(module_id) == TEN_MODULE_B) {
    instance = 9;
  }
  else {
    instance = 1;
  }
  instance += slice;

  if ((client == TEN_TRAFFIC_TYPE_1GFC) ||
      (client == TEN_TRAFFIC_TYPE_1GFC_RA) ||
      (client == TEN_TRAFFIC_TYPE_1GFC_ENH) ||
      (client == TEN_TRAFFIC_TYPE_1GE)) { /* Bugzilla 38871 */
    gpll_mode = TEN_HL_GPLL_MODE_XFI_1GFC;
  }
  else if ((client == TEN_TRAFFIC_TYPE_2GFC) ||
           (client == TEN_TRAFFIC_TYPE_2GFC_RA) ||
           (client == TEN_TRAFFIC_TYPE_2GFC_ENH) ||
           (client == TEN_TRAFFIC_TYPE_2GISC) ||
           (client == TEN_TRAFFIC_TYPE_CPRI_4)) { /* Bugzilla 39690 Need full rate /4 */
    gpll_mode = TEN_HL_GPLL_MODE_XFI_2GFC;
  }
  else if ((client == TEN_TRAFFIC_TYPE_4GFC) ||
           (client == TEN_TRAFFIC_TYPE_4GFC_RA) ||
           (client == TEN_TRAFFIC_TYPE_4GFC_ENH) ||
           (client == TEN_TRAFFIC_TYPE_5GB_IB)) {
    gpll_mode = TEN_HL_GPLL_MODE_XFI_4GFC;
  }
  else {
    gpll_mode = TEN_HL_GPLL_MODE_DEFAULT;
  }

  /* Bugzilla #21799, check for CS_ERROR or not locked (0) */
  /* Receive GPLL */
  ten_hl_gpllx1_init(dev_id, instance, gpll_mode, 0);
  if (ten_hl_gpllx1_waitfor_vcotune(dev_id, instance) != 1) {
    CS_PRINT("%s() ten_hl_gpllx1_waitfor_vcotune FAILED.\n", func);
    rtn |= CS_ERROR;
  }

  /* Transmit GPLL */
  ten_hl_gpllx1_init(dev_id, instance+4, gpll_mode, 0);
  if (ten_hl_gpllx1_waitfor_vcotune(dev_id, instance+4) != 1) {
    CS_PRINT("%s() ten_hl_gpllx1_waitfor_vcotune FAILED.\n", func);
    rtn |= CS_ERROR;
  }
 
  /* Bugzilla #25165, add a toggle of resync to API */
  rtn |= ten_xfi32x1_txelst0_control_resync(module_id, slice, 1);
  rtn |= ten_xfi32x1_rxelst0_control_resync(module_id, slice, 1);
 
  rtn |= ten_xfi32x1_txelst0_control_resync(module_id, slice, 0);
  rtn |= ten_xfi32x1_rxelst0_control_resync(module_id, slice, 0);
 
  /* Set-up the receive protection clock */
  if (prot) {
    if (ten_mpif_set_clock_switch_lockdet_xfi(dev_id, slice, CS_RX, CS_ENABLE) != CS_OK) {
      rtn |= CS_ERROR;
      CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_OP, "%s() ten_mpif_set_clock_switch_lockdet_xfi() failed 0x%2X", func, rtn);
    }
  }

  /* Bugzilla #37228: Driver should perform ten_hl_hsif_check_xfi_filt_lock later in sequence */ 
  if (ten_hl_hsif_check_xfi_filt_lock(module_id, slice, CS_RX) == 1) {
    CS_PRINT("%s, sl=%d:  RX FILT_LOCKs==1 LOCKED!\n", func, slice);
  }
  else {
    CS_PRINT("%s, sl=%d:  RX FILT_LOCKs==0 NOT LOCKED!\n", func, slice);
  }

  if (ten_hl_hsif_check_xfi_filt_lock(module_id, slice, CS_TX) == 1) {
    CS_PRINT("%s, sl=%d:  TX FILT_LOCKs==1 LOCKED!\n", func, slice);
  }
  else {
    CS_PRINT("%s, sl=%d:  TX FILT_LOCKs==0 NOT LOCKED!\n", func, slice);
  }
  
  CS_PRINT("ten_hl_config_xfi_t41 complete, rtn = %s\n", ((rtn == CS_OK) ? "CS_OK" : "CS_ERROR"));
  return (rtn);
}

/* Change config xfi: Bugzilla #18791          */
/********************************************************************/
/* $rtn_hdr_start  HIGH LEVEL HSIF CONFIG XFI                       */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : HIGH LEVEL                                          */
/* CHIP       : Tenabo                                              */
cs_status ten_hl_hsif_config_xfi(cs_uint16 module_id,
                                 cs_uint8 slice,
                                 cs_uint16 rate,
                                 cs_uint16 div,
                                 cs_uint16 internal_pilot)
/* INPUTS     : o Module Id                                         */
/*              o Slice                                             */
/*              o Rate                                              */
/*              o Divided By Reference                              */
/*              o Internal Pilot                                    */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Configures XFI for the specified serdes rate, divided by ref,    */
/* and internal_pilot.                                              */
/*                                                                  */
/* [slice]  Specified as TEN_SLICE0 (0), TEN_SLICE1 (1),            */
/*   TEN_SLICE2 (2), TEN_SLICE3 (3) or TEN_SLICE_ALL (0xFF)         */
/*                                                                  */
/* [rate]  Specified as:  (supported div values)                    */
/*  TEN_HSIF_XFI_RATE_GBPS_9__95_TO_12__5  = 0,  Full               */
/*  TEN_HSIF_XFI_RATE_GBPS_4__97_TO_6__25  = 1,  1/2                */
/*  TEN_HSIF_XFI_RATE_GBPS_2__48_TO_3__125 = 2,  1/4                */
/*  TEN_HSIF_XFI_RATE_GBPS_1__24_TO_1__56  = 3,  1/8                */
/*  TEN_HSIF_XFI_RATE_GBPS_8__5_FC         = 4,  Full               */
/*  TEN_HSIF_XFI_RATE_GBPS_4__25_FC        = 5,  1/2                */
/*  TEN_HSIF_XFI_RATE_GBPS_2__125_FC       = 6,  1/4                */
/*  TEN_HSIF_XFI_RATE_GBPS_1__0625_FC      = 7,  1/8                */
/*  TEN_HSIF_XFI_RATE_GBPS_9__95328        = 8,  Full               */
/*  TEN_HSIF_XFI_RATE_GBPS_10__3125        = 9,  Full               */
/*  TEN_HSIF_XFI_RATE_GBPS_10__52          = 10, Full               */
/*  TEN_HSIF_XFI_RATE_GBPS_10__70          = 11, Full               */
/*  TEN_HSIF_XFI_RATE_GBPS_11__1           = 12, Full               */
/*  TEN_HSIF_XFI_RATE_GBPS_11__3           = 13, Full               */
/*  TEN_HSIF_XFI_RATE_GBPS_11__7           = 14, Full               */
/*  TEN_HSIF_XFI_RATE_GBPS_12__5           = 15  Full               */
/*  TEN_HSIF_XFI_RATE_GBPS_5_IB            = 16, 1/2                */
/*  TEN_HSIF_XFI_RATE_GBPS_10_IB           = 17, Full               */
/*                                                                  */
/* [div]  Specified as:                                             */
/*  TEN_HSIF_XFI_DIV_BY_16_REF          = 0,                        */
/*  TEN_HSIF_XFI_DIV_BY_40_REF          = 1,                        */
/*  TEN_HSIF_XFI_DIV_BY_64_REF          = 2,                        */
/*  TEN_HSIF_XFI_DIV_BY_80_REF          = 3                         */
/*  TEN_HSIF_XFI_DIV_BY_16_AUX_LPTM_REF = 4,                        */
/*  TEN_HSIF_XFI_DIV_BY_40_AUX_LPTM_REF = 5,                        */
/*  TEN_HSIF_XFI_DIV_BY_64_AUX_LPTM_REF = 6,                        */
/*  TEN_HSIF_XFI_DIV_BY_80_AUX_LPTM_REF = 7,                        */
/*  TEN_HSIF_XFI_DIV_BY_32_REF          = 8,                        */
/*  TEN_HSIF_XFI_DIV_BY_66_REF          = 9,                        */
/*  TEN_HSIF_XFI_DIV_BY_32_AUX_LPTM_REF = 10,                       */
/*  TEN_HSIF_XFI_DIV_BY_66_AUX_LPTM_REF = 11.                       */
/*                                                                  */
/* [internal_pilot]  Specified as:                                  */
/*    0 = do not use internal pilot                                 */
/*    1 = use internal pilot.                                       */
/*                                                                  */
/* NOTE:  Use the closest rate enumeration value instead of         */
/* these generic range enumeration values:                          */
/*   TEN_HSIF_XFI_RATE_GBPS_9__95_TO_12__5,                         */
/*   TEN_HSIF_XFI_RATE_GBPS_4__97_TO_6__25,                         */
/*   TEN_HSIF_XFI_RATE_GBPS_2__48_TO_3__125,                        */
/*   TEN_HSIF_XFI_RATE_GBPS_1__24_TO_1__56,                         */
/* These are for backwards compatibility only.  If used, some       */
/* values will be left at default.                                  */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  cs_status rtn = CS_OK;

  CS_PRINT("ten_hl_hsif_config_xfi, slice=%d, rate = %d\n", slice, rate);

  if (TEN_MOD_ID_TO_MOD_NUM(module_id) != TEN_MODULE_B) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": XFI only on Module B.");
    return (CS_ERROR);
  }

  if ((slice>=TEN_MAX_SLICES) && (slice != TEN_SLICE_ALL)) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": slice out of range.  s/b 0..3.");
    return (CS_ERROR);
  }

  /* power up the XFI serdes -- there is a delay after powering up in ten_hl_hsif_powerdown_xfi */
  rtn |= ten_hl_hsif_powerdown_xfi(module_id, slice, CS_DISABLE);
  
  if (rtn == CS_ERROR) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": ten_hl_hsif_powerdown_xfi failed");
  }
  
  /* Bugzilla #30768, Fix CFP_MR Protection with XFI on same port issues */
  rtn |= ten_hsif_provision_rx_xfiselect(module_id, slice, 1);
  rtn |= ten_hsif_provision_tx_xfiselect(module_id, slice, 1);

  if (rtn == CS_ERROR) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": ten_hsif_provision_rx_xfiselect failed");
  }
  
 
   /* Bugzilla #14253, in all cases, overwrite default of 1 to 0. */
   rtn |= ten_xfi32x1_srx0_rx_clkout_ctrl_clkinven(module_id, slice, 0);

  rtn |= ten_hl_hsif_xfi_analog_cfg(module_id, slice, rate, div);

  if (rtn == CS_ERROR) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": ten_hl_hsif_xfi_analog_cfg failed");
  }
  
  switch (rate) {
  case (TEN_HSIF_XFI_RATE_GBPS_5_IB):
  case (TEN_HSIF_XFI_RATE_GBPS_4__97_TO_6__25):
  {
    /* reassert sds rx/tx reset */
    ten_mpif_global_reset_sds_xfi(TEN_MOD_ID_TO_DEV_ID(module_id), slice,
                                  CS_TX_AND_RX, CS_RESET_ASSERT);

    /* Choose fractional divider output as pilot tone */
    if (internal_pilot) {
      /*  stxp_lptime_sel = 0  */
      /*  stxp_pilot_sel  = 1  */
      /*  stxp_fcen       = 0  */
      /*  stxp_buswidth   = 0  */
      /*  stxp_lpbken     = 0  */
      ten_xfi32x1_stxp0_tx_config(module_id, slice, 0, 1, 0, 0, 0);
      /* RX RDIV=div32 */
      rtn |= ten_xfi32x1_srx0_rx_clkdiv_ctrl_rdiv_sel(module_id, slice, 1);

      /* RX CTVDIV=div2 */
      rtn |= ten_xfi32x1_srx0_rx_clkdiv_ctrl_ctvdiv_sel(module_id, slice, 1);

      /* TX CTRDIV=div2 */
      rtn |= ten_xfi32x1_stxp0_tx_clkdiv_ctrl_ctr_div(module_id, slice, 1);
    }

    /* Force RX to lock to pilot tone */
    ten_xfi32x1_set_rxlockd0_force_lock(module_id, slice, 0, 1);
  }
  break;

  case (TEN_HSIF_XFI_RATE_GBPS_8__5_FC):
  case (TEN_HSIF_XFI_RATE_GBPS_4__25_FC):
  case (TEN_HSIF_XFI_RATE_GBPS_2__125_FC):
  case (TEN_HSIF_XFI_RATE_GBPS_1__0625_FC):
  {
    /* Force RX to lock to pilot tone */
    /* tenabo_bf_write(DEV_ID,TEN_XFI32X1_SDS_XFI32X1_SDS_COMMON_RXLOCKD0_CONTROL+$ch*TEN_XFI32X1_SDS_STRIDE,1,0,0); */
    /* Bug 21819 fix, configuration for pilot tone */
    if (internal_pilot) {
      /*  stxp_lptime_sel = 0  */
      /*  stxp_pilot_sel  = 1  */
      /*  stxp_fcen       = 1  */
      /*  stxp_buswidth   = 0  */
      /*  stxp_lpbken     = 0  */
      rtn |= ten_xfi32x1_stxp0_tx_config(module_id, slice, 0, 1, 1, 0, 0);

      /* RX RDIV=div32 */
      rtn |= ten_xfi32x1_srx0_rx_clkdiv_ctrl_rdiv_sel(module_id, slice, 1);

      /* RX CTVDIV=div2 */
      rtn |= ten_xfi32x1_srx0_rx_clkdiv_ctrl_ctvdiv_sel(module_id, slice, 1);

      /* TX CTRDIV=div2 */
      rtn |= ten_xfi32x1_stxp0_tx_clkdiv_ctrl_ctr_div(module_id, slice, 1);
    }
    /* Force RX to lock to pilot tone */
    rtn |= ten_xfi32x1_set_rxlockd0_force_lock(module_id, slice, 0, 1);
  }
  break;

  case (TEN_HSIF_XFI_RATE_GBPS_9__95_TO_12__5):
  case (TEN_HSIF_XFI_RATE_GBPS_9__95328):
  case (TEN_HSIF_XFI_RATE_GBPS_10__3125):
  case (TEN_HSIF_XFI_RATE_GBPS_10__52):
  case (TEN_HSIF_XFI_RATE_GBPS_10__70):
  case (TEN_HSIF_XFI_RATE_GBPS_11__1):
  case (TEN_HSIF_XFI_RATE_GBPS_11__3):
  case (TEN_HSIF_XFI_RATE_GBPS_11__7):
  case (TEN_HSIF_XFI_RATE_GBPS_12__5):
  case (TEN_HSIF_XFI_RATE_GBPS_10_IB):
  case (TEN_HSIF_XFI_RATE_GBPS_1__24_TO_1__56): /* Bugzilla 38871 */
  case (TEN_HSIF_XFI_RATE_GBPS_2__48_TO_3__125): /* Bugzilla 39690 */
  {
    /* Choose fractional divider output as pilot tone */
    if (internal_pilot) {
      /*  stxp_lptime_sel = 0  */
      /*  stxp_pilot_sel  = 1  */
      /*  stxp_fcen       = 0  */
      /*  stxp_buswidth   = 0  */
      /*  stxp_lpbken     = 0  */
      rtn |= ten_xfi32x1_stxp0_tx_config(module_id, slice, 0, 1, 0, 0, 0);

      /* RX RDIV=div32 */
      rtn |= ten_xfi32x1_srx0_rx_clkdiv_ctrl_rdiv_sel(module_id, slice, 1);

      /* RX CTVDIV=div2 */
      rtn |= ten_xfi32x1_srx0_rx_clkdiv_ctrl_ctvdiv_sel(module_id, slice, 1);

      /* TX CTRDIV=div2 */
      rtn |= ten_xfi32x1_stxp0_tx_clkdiv_ctrl_ctr_div(module_id, slice, 1);
    }
    /* Force RX to lock to pilot tone */
    rtn |= ten_xfi32x1_set_rxlockd0_force_lock(module_id, slice, 0, 1);
  }
  break;

  /* case (TEN_HSIF_XFI_RATE_GBPS_1__24_TO_1__56): */ /* Bugzilla 38871 */
  default:
    CS_PRINT("Non-supported/invalid XFI rate.\n");
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": Non-supported/invalid XFI rate.");
    return (CS_ERROR);

  }

  if (rtn == CS_ERROR) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": rate case statement failed");
  }
  
  rtn |= ten_hl_hsif_config_table15(module_id, slice, rate);

  if (rtn == CS_ERROR) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": ten_hl_hsif_config_table15 failed");
  }
  
  /* Bugzilla #19353, fix bus errors,                */
  /* perform this setting after DSP reset deasserted */

 
  /* Bugzilla #18137:  Change default from 2 to 3  */
 
  rtn |= ten_xfi32x1_rxlockd0_set_stable_period(module_id, slice, 3);

  /* remove sds rx/tx reset */
  rtn |= ten_mpif_global_reset_sds_xfi(TEN_MOD_ID_TO_DEV_ID(module_id),
                                       slice, CS_TX_AND_RX, CS_RESET_DEASSERT);

  /* enable global clock for HSIF */
  rtn |= ten_mpif_global_clock_disable_xfi_b(TEN_MOD_ID_TO_DEV_ID(module_id),
                                             slice, CS_TX_AND_RX, CS_ENABLE);

  /* Select Module B XFI SERDES Clock out of HSIF */
  rtn |= ten_mpif_clock_select_hsif_out(TEN_MOD_ID_TO_DEV_ID(module_id),
                                        TEN_MOD_ID_TO_MOD_NUM(module_id),
                                        slice, CS_TX_AND_RX, 1);

  if (rtn == CS_ERROR) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": ten_hl_hsif_config_xfi");
  }                                   
                                        
  CS_PRINT("ten_hl_hsif_config_xfi Complete.\n");
  return (rtn);
}

/* Bugzilla #35116                             */
/********************************************************************/
/* $rtn_hdr_start  HIGH LEVEL HSIF CONFIG XFI FOR SPARE CUPLL       */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : HIGH LEVEL                                          */
/* CHIP       : Tenabo                                              */
cs_status ten_hl_hsif_config_xfi_spare_cupll(cs_uint16 module_id,
                                             cs_uint8 slice,
                                             cs_uint16 rate,
                                             cs_uint16 div,
                                             cs_uint16 internal_pilot)
/* INPUTS     : o Module Id                                         */
/*              o Slice                                             */
/*              o Rate                                              */
/*              o Divided By Reference                              */
/*              o Internal Pilot                                    */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Configures XFI for the specified serdes rate, divided by ref,    */
/* and internal_pilot for spare CUPLL. This API differs from        */
/* ten_hl_hsif_config_xfi(..) in two aspects:                       */
/* - Since the port in use is using SFI4.1 interface and already    */
/*   carrying traffic, we just want to borrow the XFI SERDES on     */
/*   that port to tune and use the spare CUPLL. However the protocol*/
/*   selector is a mux and cannot be changed to XFI, as it will     */
/*   kill traffic on that port.                                     */
/* - The HSIF CLOCK OUT mux feeds the clock to TX and RX PLL, and   */
/*   cannot be disturbed as well since it will kill the traffic on  */
/*   that port.                                                     */
/*                                                                  */
/* [slice]  Specified as TEN_SLICE0 (0), TEN_SLICE1 (1),            */
/*   TEN_SLICE2 (2), TEN_SLICE3 (3) or TEN_SLICE_ALL (0xFF)         */
/*                                                                  */
/* [rate]  Specified as:  (supported div values)                    */
/*  TEN_HSIF_XFI_RATE_GBPS_9__95_TO_12__5  = 0,  Full               */
/*  TEN_HSIF_XFI_RATE_GBPS_4__97_TO_6__25  = 1,  1/2                */
/*  TEN_HSIF_XFI_RATE_GBPS_2__48_TO_3__125 = 2,  1/4                */
/*  TEN_HSIF_XFI_RATE_GBPS_1__24_TO_1__56  = 3,  1/8                */
/*  TEN_HSIF_XFI_RATE_GBPS_8__5_FC         = 4,  Full               */
/*  TEN_HSIF_XFI_RATE_GBPS_4__25_FC        = 5,  1/2                */
/*  TEN_HSIF_XFI_RATE_GBPS_2__125_FC       = 6,  1/4                */
/*  TEN_HSIF_XFI_RATE_GBPS_1__0625_FC      = 7,  1/8                */
/*  TEN_HSIF_XFI_RATE_GBPS_9__95328        = 8,  Full               */
/*  TEN_HSIF_XFI_RATE_GBPS_10__3125        = 9,  Full               */
/*  TEN_HSIF_XFI_RATE_GBPS_10__52          = 10, Full               */
/*  TEN_HSIF_XFI_RATE_GBPS_10__70          = 11, Full               */
/*  TEN_HSIF_XFI_RATE_GBPS_11__1           = 12, Full               */
/*  TEN_HSIF_XFI_RATE_GBPS_11__3           = 13, Full               */
/*  TEN_HSIF_XFI_RATE_GBPS_11__7           = 14, Full               */
/*  TEN_HSIF_XFI_RATE_GBPS_12__5           = 15  Full               */
/*  TEN_HSIF_XFI_RATE_GBPS_5_IB            = 16, 1/2                */
/*  TEN_HSIF_XFI_RATE_GBPS_10_IB           = 17, Full               */
/*                                                                  */
/* [div]  Specified as:                                             */
/*  TEN_HSIF_XFI_DIV_BY_16_REF          = 0,                        */
/*  TEN_HSIF_XFI_DIV_BY_40_REF          = 1,                        */
/*  TEN_HSIF_XFI_DIV_BY_64_REF          = 2,                        */
/*  TEN_HSIF_XFI_DIV_BY_80_REF          = 3                         */
/*  TEN_HSIF_XFI_DIV_BY_16_AUX_LPTM_REF = 4,                        */
/*  TEN_HSIF_XFI_DIV_BY_40_AUX_LPTM_REF = 5,                        */
/*  TEN_HSIF_XFI_DIV_BY_64_AUX_LPTM_REF = 6,                        */
/*  TEN_HSIF_XFI_DIV_BY_80_AUX_LPTM_REF = 7,                        */
/*  TEN_HSIF_XFI_DIV_BY_32_REF          = 8,                        */
/*  TEN_HSIF_XFI_DIV_BY_66_REF          = 9,                        */
/*  TEN_HSIF_XFI_DIV_BY_32_AUX_LPTM_REF = 10,                       */
/*  TEN_HSIF_XFI_DIV_BY_66_AUX_LPTM_REF = 11.                       */
/*                                                                  */
/* [internal_pilot]  Specified as:                                  */
/*    0 = do not use internal pilot                                 */
/*    1 = use internal pilot.                                       */
/*                                                                  */
/* NOTE:  Use the closest rate enumeration value instead of         */
/* these generic range enumeration values:                          */
/*   TEN_HSIF_XFI_RATE_GBPS_9__95_TO_12__5,                         */
/*   TEN_HSIF_XFI_RATE_GBPS_4__97_TO_6__25,                         */
/*   TEN_HSIF_XFI_RATE_GBPS_2__48_TO_3__125,                        */
/*   TEN_HSIF_XFI_RATE_GBPS_1__24_TO_1__56,                         */
/* These are for backwards compatibility only.  If used, some       */
/* values will be left at default.                                  */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  cs_status rtn = CS_OK;

  CS_PRINT("ten_hl_hsif_config_xfi_spare_cupll, slice=%d, rate = %d\n", slice, rate);

  if (TEN_MOD_ID_TO_MOD_NUM(module_id) != TEN_MODULE_B) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": XFI only on Module B.");
    return (CS_ERROR);
  }

  if ((slice>=TEN_MAX_SLICES) && (slice != TEN_SLICE_ALL)) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": slice out of range.  s/b 0..3.");
    return (CS_ERROR);
  }

  /* power up the XFI serdes */
  rtn |= ten_hl_hsif_powerdown_xfi(module_id, slice, CS_DISABLE);
  
  if (rtn == CS_ERROR) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": ten_hl_hsif_powerdown_xfi failed");
  }
  
  /* there is a delay after powering up in ten_hl_hsif_powerdown_xfi */
  

  /* Bugzilla #14253, in all cases, overwrite default of 1 to 0. */
  rtn |= ten_xfi32x1_srx0_rx_clkout_ctrl_clkinven(module_id, slice, 0);

  rtn |= ten_hl_hsif_xfi_analog_cfg(module_id, slice, rate, div);

  if (rtn == CS_ERROR) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": ten_hl_hsif_xfi_analog_cfg failed");
  }
  
  switch (rate) {
  case (TEN_HSIF_XFI_RATE_GBPS_5_IB):
  case (TEN_HSIF_XFI_RATE_GBPS_4__97_TO_6__25):
  {
    /* reassert sds rx/tx reset */
    ten_mpif_global_reset_sds_xfi(TEN_MOD_ID_TO_DEV_ID(module_id), slice,
                                  CS_TX_AND_RX, CS_RESET_ASSERT);

    /* Choose fractional divider output as pilot tone */
    if (internal_pilot) {
      /*  stxp_lptime_sel = 0  */
      /*  stxp_pilot_sel  = 1  */
      /*  stxp_fcen       = 0  */
      /*  stxp_buswidth   = 0  */
      /*  stxp_lpbken     = 0  */
      ten_xfi32x1_stxp0_tx_config(module_id, slice, 0, 1, 0, 0, 0);
      /* RX RDIV=div32 */
      /* tenabo_bf_write(DEV_ID,TEN_XFI32X1_SDS_XFI32X1_SDS_COMMON_SRX0_RX_CLKDIV_CTRL+$ch*TEN_XFI32X1_SDS_STRIDE,1,3,0); */
      rtn |= ten_xfi32x1_srx0_rx_clkdiv_ctrl_rdiv_sel(module_id, slice, 1);

      /* RX CTVDIV=div2 */
      /* tenabo_bf_write(DEV_ID,TEN_XFI32X1_SDS_XFI32X1_SDS_COMMON_SRX0_RX_CLKDIV_CTRL+$ch*TEN_XFI32X1_SDS_STRIDE,1,9,8); */
      rtn |= ten_xfi32x1_srx0_rx_clkdiv_ctrl_ctvdiv_sel(module_id, slice, 1);

      /* TX CTRDIV=div2 */
      /* tenabo_bf_write(DEV_ID,TEN_XFI32X1_SDS_XFI32X1_SDS_COMMON_STXP0_TX_CLKDIV_CTRL+$ch*TEN_XFI32X1_SDS_STRIDE,1,11,10); */
      rtn |= ten_xfi32x1_stxp0_tx_clkdiv_ctrl_ctr_div(module_id, slice, 1);
    }

    /* Force RX to lock to pilot tone */
    /* tenabo_bf_write(DEV_ID,main::TEN_XFI32X1_SDS_XFI32X1_SDS_COMMON_RXLOCKD0_CONTROL+$ch*main::TEN_XFI32X1_SDS_STRIDE,1,0,0); */
    ten_xfi32x1_set_rxlockd0_force_lock(module_id, slice, 0, 1);
  }
  break;

  case (TEN_HSIF_XFI_RATE_GBPS_8__5_FC):
  case (TEN_HSIF_XFI_RATE_GBPS_4__25_FC):
  case (TEN_HSIF_XFI_RATE_GBPS_2__125_FC):
  case (TEN_HSIF_XFI_RATE_GBPS_1__0625_FC):
  {
    /* Force RX to lock to pilot tone */
    /* tenabo_bf_write(DEV_ID,TEN_XFI32X1_SDS_XFI32X1_SDS_COMMON_RXLOCKD0_CONTROL+$ch*TEN_XFI32X1_SDS_STRIDE,1,0,0); */
    /* Bug 21819 fix, configuration for pilot tone */
    if (internal_pilot) {
      /*  stxp_lptime_sel = 0  */
      /*  stxp_pilot_sel  = 1  */
      /*  stxp_fcen       = 1  */
      /*  stxp_buswidth   = 0  */
      /*  stxp_lpbken     = 0  */
      rtn |= ten_xfi32x1_stxp0_tx_config(module_id, slice, 0, 1, 1, 0, 0);

      /* RX RDIV=div32 */
      /* tenabo_bf_write(DEV_ID,TEN_XFI32X1_SDS_XFI32X1_SDS_COMMON_SRX0_RX_CLKDIV_CTRL+$ch*TEN_XFI32X1_SDS_STRIDE,1,3,0); */
      rtn |= ten_xfi32x1_srx0_rx_clkdiv_ctrl_rdiv_sel(module_id, slice, 1);

      /* RX CTVDIV=div2 */
      /* tenabo_bf_write(DEV_ID,TEN_XFI32X1_SDS_XFI32X1_SDS_COMMON_SRX0_RX_CLKDIV_CTRL+$ch*TEN_XFI32X1_SDS_STRIDE,1,9,8); */
      rtn |= ten_xfi32x1_srx0_rx_clkdiv_ctrl_ctvdiv_sel(module_id, slice, 1);

      /* TX CTRDIV=div2 */
      /* tenabo_bf_write(DEV_ID,TEN_XFI32X1_SDS_XFI32X1_SDS_COMMON_STXP0_TX_CLKDIV_CTRL+$ch*TEN_XFI32X1_SDS_STRIDE,1,11,10); */
      rtn |= ten_xfi32x1_stxp0_tx_clkdiv_ctrl_ctr_div(module_id, slice, 1);
    }
    /* Force RX to lock to pilot tone */
    /* tenabo_bf_write(DEV_ID,TEN_XFI32X1_SDS_XFI32X1_SDS_COMMON_RXLOCKD0_CONTROL+$ch*TEN_XFI32X1_SDS_STRIDE,1,0,0); */
    rtn |= ten_xfi32x1_set_rxlockd0_force_lock(module_id, slice, 0, 1);
  }
  break;

  case (TEN_HSIF_XFI_RATE_GBPS_9__95_TO_12__5):
  case (TEN_HSIF_XFI_RATE_GBPS_9__95328):
  case (TEN_HSIF_XFI_RATE_GBPS_10__3125):
  case (TEN_HSIF_XFI_RATE_GBPS_10__52):
  case (TEN_HSIF_XFI_RATE_GBPS_10__70):
  case (TEN_HSIF_XFI_RATE_GBPS_11__1):
  case (TEN_HSIF_XFI_RATE_GBPS_11__3):
  case (TEN_HSIF_XFI_RATE_GBPS_11__7):
  case (TEN_HSIF_XFI_RATE_GBPS_12__5):
  case (TEN_HSIF_XFI_RATE_GBPS_10_IB):
  case (TEN_HSIF_XFI_RATE_GBPS_1__24_TO_1__56): /* Bugzilla 38871 */
  case (TEN_HSIF_XFI_RATE_GBPS_2__48_TO_3__125): /* Bugzilla 39690 */
  {
    /* Choose fractional divider output as pilot tone */
    if (internal_pilot) {
      /*  stxp_lptime_sel = 0  */
      /*  stxp_pilot_sel  = 1  */
      /*  stxp_fcen       = 0  */
      /*  stxp_buswidth   = 0  */
      /*  stxp_lpbken     = 0  */
      rtn |= ten_xfi32x1_stxp0_tx_config(module_id, slice, 0, 1, 0, 0, 0);

      /* RX RDIV=div32 */
      /* tenabo_bf_write(DEV_ID,TEN_XFI32X1_SDS_XFI32X1_SDS_COMMON_SRX0_RX_CLKDIV_CTRL+$ch*TEN_XFI32X1_SDS_STRIDE,1,3,0); */
      rtn |= ten_xfi32x1_srx0_rx_clkdiv_ctrl_rdiv_sel(module_id, slice, 1);

      /* RX CTVDIV=div2 */
      /* tenabo_bf_write(DEV_ID,TEN_XFI32X1_SDS_XFI32X1_SDS_COMMON_SRX0_RX_CLKDIV_CTRL+$ch*TEN_XFI32X1_SDS_STRIDE,1,9,8); */
      rtn |= ten_xfi32x1_srx0_rx_clkdiv_ctrl_ctvdiv_sel(module_id, slice, 1);

      /* TX CTRDIV=div2 */
      /* tenabo_bf_write(DEV_ID,TEN_XFI32X1_SDS_XFI32X1_SDS_COMMON_STXP0_TX_CLKDIV_CTRL+$ch*TEN_XFI32X1_SDS_STRIDE,1,11,10); */
      rtn |= ten_xfi32x1_stxp0_tx_clkdiv_ctrl_ctr_div(module_id, slice, 1);
    }
    /* Force RX to lock to pilot tone */
    /* tenabo_bf_write(DEV_ID,TEN_XFI32X1_SDS_XFI32X1_SDS_COMMON_RXLOCKD0_CONTROL+$ch*TEN_XFI32X1_SDS_STRIDE,1,0,0); */
    rtn |= ten_xfi32x1_set_rxlockd0_force_lock(module_id, slice, 0, 1);
  }
  break;

  /* case (TEN_HSIF_XFI_RATE_GBPS_1__24_TO_1__56): */ /* Bugzilla 38871 */
  default:
    CS_PRINT("Non-supported/invalid XFI rate.\n");
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": Non-supported/invalid XFI rate.");
    return (CS_ERROR);
  }

  if (rtn == CS_ERROR) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": rate case statement failed");
  }
  
  rtn |= ten_hl_hsif_config_table15(module_id, slice, rate);

  if (rtn == CS_ERROR) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": ten_hl_hsif_config_table15 failed");
  }
  
  /* Bugzilla #19353, fix bus errors,                */
  /* perform this setting after DSP reset deasserted */

  /* Bugzilla #18137:  Change default from 2 to 3  */
  rtn |= ten_xfi32x1_rxlockd0_set_stable_period(module_id, slice, 3);

  /* remove sds rx/tx reset */
  rtn |= ten_mpif_global_reset_sds_xfi(TEN_MOD_ID_TO_DEV_ID(module_id),
                                       slice, CS_TX_AND_RX, CS_RESET_DEASSERT);

  /* enable global clock for HSIF */
  rtn |= ten_mpif_global_clock_disable_xfi_b(TEN_MOD_ID_TO_DEV_ID(module_id),
                                             slice, CS_TX_AND_RX, CS_ENABLE);

  if (rtn == CS_ERROR) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": ten_hl_hsif_config_xfi_spare_cupll");
  }                                   
                                        
  CS_PRINT("ten_hl_hsif_config_xfi_spare_cupll Complete.\n");
  return (rtn);
}

/********************************************************************/
/* $rtn_hdr_start  HIGH LEVEL HSIF XFI WAIT FOR VCO TUNE            */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : HIGH LEVEL                                          */
/* CHIP       : Tenabo                                              */
cs_int16 ten_hl_hsif_xfi_waitfor_vcotune(cs_uint16 module_id,
                                          cs_uint8 slice)
/* INPUTS     : o Module Id                                         */
/*              o Slice                                             */
/* OUTPUTS    : ----                                                */
/* RETURNS    : 1=locked, 0=NOT locked or CS_ERROR                  */
/* DESCRIPTION:                                                     */
/* Wait for SerDes TX VCOTUNE & RX VCOTUNE & LOCK.                  */
/*                                                                  */
/* [slice]  Specified as TEN_SLICE0 (0), TEN_SLICE1 (1),            */
/*   TEN_SLICE2 (2) or TEN_SLICE3 (3).                              */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  cs_int16 rtn;
  cs_char8 *func = "ten_hl_hsif_xfi_waitfor_vcotune";  

  if (slice >= TEN_MAX_SLICES) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, "%s() slice out of range.  s/b 0..3.", func);
    return (CS_ERROR);
  }
  CS_PRINT("%s() %s, %s\n", func, ten_module_strings[module_id&1], ten_slice_strings[slice]);

  /* wait for SerDes TX VCOTUNE & RX VCOTUNE & LOCK  */
  rtn = ten_hl_hsif_check_xfi_vcotune(module_id, slice, CS_TX);

  if (rtn == CS_ERROR) {
    CS_PRINT("%s()  check tx xfi vco tune CS_ERROR, slice=%d\n", func, slice);
    return (CS_ERROR);
  }

  if (rtn == 0) {
    CS_PRINT("%s()  check tx xfi vco tune failed, slice=%d\n", func, slice);
    return (0);
  }

  rtn = ten_hl_hsif_check_xfi_vcotune(module_id, slice, CS_RX);

  if (rtn == CS_ERROR) {
    CS_PRINT("%s()  check rx xfi vco tune CS_ERROR, slice=%d\n", func, slice);
    return (CS_ERROR);
  }

  if (rtn == 0) {
    CS_PRINT("%s()  check rx xfi vco tune failed, slice=%d\n", func, slice);
    return (0);
  }

  /* Bugzilla #37228: Driver should perform ten_hl_hsif_check_xfi_filt_lock later in sequence */ 
 
  return (1);
}

/********************************************************************/
/* $rtn_hdr_start  HIGH LEVEL HSIF MR WAIT FOR VCO TUNE             */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : HIGH LEVEL                                          */
/* CHIP       : Tenabo                                              */
cs_int16 ten_hl_hsif_mr_waitfor_vcotune(cs_uint16 module_id,
                                          cs_uint8 slice)
/* INPUTS     : o Module Id                                         */
/*              o Slice                                             */
/* OUTPUTS    : ----                                                */
/* RETURNS    : 1=locked, 0=NOT locked or CS_ERROR                  */
/* DESCRIPTION:                                                     */
/* Wait for MR TX VCOTUNE & RX VCOTUNE & LOCK.                      */
/*                                                                  */
/* [slice]  Specified as TEN_SLICE0 (0), TEN_SLICE1 (1),            */
/*   TEN_SLICE2 (2) or TEN_SLICE3 (3).                              */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  cs_int16 rtn;

  if (slice >= TEN_MAX_SLICES) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, "slice out of range.  s/b 0..3.");
    return (CS_ERROR);
  }
  
  /* Bugzilla #36753: In Warm Start mode, disable API FAILURE */
  if (ten_dev_is_ws_in_progress(TEN_MOD_ID_TO_DEV_ID(module_id))) {
    CS_PRINT("Device is in warm start mode, report 1\n");
    return (1);
  }
  
  /* wait for SerDes TX VCOTUNE & RX VCOTUNE & LOCK  */
  rtn = ten_hl_hsif_check_mr_vcotune(module_id, slice, CS_TX);

  if (rtn == CS_ERROR) {
    CS_PRINT("check tx mr slice = %d vco tune CS_ERROR\n", slice);
    return (CS_ERROR);
  }

  if (rtn == 0) {
    CS_PRINT("check tx mr slice = %d vco tune failed\n", slice);
    return (0);
  }

  rtn = ten_hl_hsif_check_mr_vcotune(module_id, slice, CS_RX);

  if (rtn == CS_ERROR) {
    CS_PRINT("check rx mr slice = %d vco tune CS_ERROR\n", slice);
    return (CS_ERROR);
  }

  if (rtn == 0) {
    CS_PRINT("check rx mr slice = %d vco tune failed\n", slice);
    return (0);
  }

  rtn = ten_hl_hsif_check_mr_filt_lock(module_id, slice, CS_RX);

  if (rtn == CS_ERROR) {
    CS_PRINT("check rx mr slice %d filt lock CS_ERROR\n", slice);
    return (CS_ERROR);
  }

  if (rtn == 0) {
     /* Bugzilla #27499, change FILT_LOCKs failure to warning instead of error. */
     /* If loopback card not inserted or laser not enabled, this should not     */
     /* be considered a failure, ie keep provisioning.                          */
     CS_PRINT("WARNING:  check rx mr slice %d filt lock failed\n", slice);
     return (1);
  }
  return (1);
}

/********************************************************************/
/* $rtn_hdr_start  HIGH LEVEL HSIF POWERDOWN XFI                    */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : HIGH LEVEL                                          */
/* CHIP       : Tenabo                                              */
cs_status ten_hl_hsif_powerdown_xfi(cs_uint16 module_id,
                                    cs_uint8 slice,
                                    cs_ctl_t ctl)
/* INPUTS     : o Module Id                                         */
/*              o Slice                                             */
/*              o Powerdown Control                                 */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Controls XFI Powerdown.                                          */
/*                                                                  */
/* [slice]  Specified as TEN_SLICE0 (0), TEN_SLICE1 (1),            */
/*   TEN_SLICE2 (2), TEN_SLICE3 (3) or TEN_SLICE_ALL (0xFF)         */
/*                                                                  */
/* [ctl]  Powerdown Action:                                         */
/*   CS_DISABLE (0) = Power up, disable powerdown                   */
/*   CS_ENABLE (1)  = Power down, enable powerdown.                 */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  if (TEN_MOD_ID_TO_MOD_NUM(module_id) != TEN_MODULE_B) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": XFI only on Module B.");
    return (CS_ERROR);
  }

  if ((slice>=TEN_MAX_SLICES) && (slice != TEN_SLICE_ALL)) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": slice out of range.  s/b 0..3.");
    return (CS_ERROR);
  }

  if ((ctl != CS_DISABLE) && (ctl != CS_ENABLE)) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_RANGE_ERR, ": ctl out of range.");
    return (CS_ERROR);
  }

  if (ctl == CS_ENABLE) {
    /* setup tx and rx xfiselect to 0 */
    ten_hsif_provision_tx_xfiselect(module_id, slice, 0);
    /* Bugzilla #31356, fix issues with xfiselect bits */
    ten_hsif_provision_rx_xfiselect(module_id, slice, 0);
  }

  ten_xfi32x1_stxp0_tx_pwrdn_all(module_id, slice, ctl);
  
  /* Bugzilla #28476 - Need to power down unused HSIF SERDES lanes/slices  */
  if (ctl == CS_ENABLE) {  /* power down */
    ten_xfi32x1_stxp0_tx_pwrdn_pd_lane(module_id, TEN_SLICE_ALL, 0x1F);
  }
  else { /* power up */
    ten_xfi32x1_stxp0_tx_pwrdn_pd_lane(module_id, TEN_SLICE_ALL, 0);
  }
  
  ten_xfi32x1_srx0_rx_srx_pd(module_id, slice, ctl);

  /* Bugzilla #18777 */
  if (ctl == CS_DISABLE) {
    /* allow settling time for the SERDES to power up before proceeding */
    TEN_MDELAY(10);
  }

  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  HIGH LEVEL HSIF POWERDOWN MR                     */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : HIGH LEVEL                                          */
/* CHIP       : Tenabo                                              */
cs_status ten_hl_hsif_powerdown_mr(cs_uint16 module_id,
                                    cs_uint8 slice,
                                    cs_ctl_t ctl)
/* INPUTS     : o Module Id                                         */
/*              o Slice                                             */
/*              o Powerdown Control                                 */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Controls MR SERDES Powerdown.                                    */
/*                                                                  */
/* [slice]  Specified as TEN_SLICE0 (0), TEN_SLICE1 (1),            */
/*   TEN_SLICE2 (2), TEN_SLICE3 (3) or TEN_SLICE_ALL (0xFF)         */
/*                                                                  */
/* [ctl]  Powerdown Action:                                         */
/*   CS_DISABLE (0) = Power up, disable powerdown                   */
/*   CS_ENABLE (1)  = Power down, enable powerdown.                 */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  cs_uint16 cpcur = 0x3;
  
  if (ctl == CS_ENABLE) {
    ten_hsif_provision_mrprotocol(module_id, slice, CS_TX_AND_RX, 0);
  }

  if ((slice == TEN_SLICE0) || (slice == TEN_SLICE_ALL)) {
    ten_hsif_slc0_mr10x4_sds_common_stxp0_tx_pwrdn_all(module_id, ctl);
    
    /* Bugzilla #28476 - Need to power down unused HSIF SERDES lanes/slices  */
    if (ctl == CS_ENABLE) { /* power down */
      ten_hsif_slc0_mr10x4_sds_common_stxp0_tx_pwrdn_pd_lane(module_id, 0x1F);
    }
    else { /* power up */
      ten_hsif_slc0_mr10x4_sds_common_stxp0_tx_pwrdn_pd_lane(module_id, 0);
    }
  
    if (ctl == CS_DISABLE) { /* power up */
      ten_hsif_slc0_mr10x4_sds_common_stxp0_tx_cp(module_id, cpcur, cpcur);
    }
  }
  
  if ((slice == TEN_SLICE1) || (slice == TEN_SLICE_ALL)) {
    ten_hsif_slc1_mr10x5_sds_common_stxp0_tx_pwrdn_all(module_id, ctl);
    
    /* Bugzilla #28476 - Need to power down unused HSIF SERDES lanes/slices  */
    if (ctl == CS_ENABLE) { /* power down */
      ten_hsif_slc1_mr10x5_sds_common_stxp0_tx_pwrdn_pd_lane(module_id, 0x1F);
    }
    else { /* power up */
      ten_hsif_slc1_mr10x5_sds_common_stxp0_tx_pwrdn_pd_lane(module_id, 0);
    }
    
    if (ctl == CS_DISABLE) {
      ten_hsif_slc1_mr10x5_sds_common_stxp0_tx_cp(module_id, cpcur, cpcur);
    }
  }
  
  if ((slice == TEN_SLICE2) || (slice == TEN_SLICE_ALL)) {
    ten_hsif_slc2_mr10x4_sds_common_stxp0_tx_pwrdn_all(module_id, ctl);
    
    /* Bugzilla #28476 - Need to power down unused HSIF SERDES lanes/slices  */
    if (ctl == CS_ENABLE) { /* power down */
      ten_hsif_slc2_mr10x4_sds_common_stxp0_tx_pwrdn_pd_lane(module_id, 0x1F);
    }
    else { /* power up */
      ten_hsif_slc2_mr10x4_sds_common_stxp0_tx_pwrdn_pd_lane(module_id, 0);
    }
    
    if (ctl == CS_DISABLE) {
      ten_hsif_slc2_mr10x4_sds_common_stxp0_tx_cp(module_id, cpcur, cpcur);
    }
  }
  
  if ((slice == TEN_SLICE3) || (slice == TEN_SLICE_ALL)) {
    ten_hsif_slc3_mr10x5_sds_common_stxp0_tx_pwrdn_all(module_id, ctl);
    
    /* Bugzilla #28476 - Need to power down unused HSIF SERDES lanes/slices  */
    if (ctl == CS_ENABLE) { /* power down */
      ten_hsif_slc3_mr10x5_sds_common_stxp0_tx_pwrdn_pd_lane(module_id, 0x1F);
    }
    else { /* power up */
      ten_hsif_slc3_mr10x5_sds_common_stxp0_tx_pwrdn_pd_lane(module_id, 0);
    }
    
    if (ctl == CS_DISABLE) {
      ten_hsif_slc3_mr10x5_sds_common_stxp0_tx_cp(module_id, cpcur, cpcur);
    }
  }

  if ((slice == TEN_SLICE0) || (slice == TEN_SLICE_ALL)) {
    ten_hsif_slc0_mr10x4_sds_common_srx0_srx_pd(module_id, TEN_INSTANCE_ALL, ctl);
    if (ctl == CS_DISABLE) {
      ten_hsif_slc0_mr10x4_sds_common_srx0_rx_cpa(module_id, TEN_INSTANCE_ALL, cpcur, cpcur);
    }
  }
  
  if ((slice == TEN_SLICE1) || (slice == TEN_SLICE_ALL)) {
    ten_hsif_slc1_mr10x5_sds_common_srx0_srx_pd(module_id, TEN_INSTANCE_ALL, ctl);
    if (ctl == CS_DISABLE) {
      ten_hsif_slc1_mr10x5_sds_common_srx0_rx_cpa(module_id, TEN_INSTANCE_ALL, cpcur, cpcur);
    }
  }
  
  if ((slice == TEN_SLICE2) || (slice == TEN_SLICE_ALL)) {
    ten_hsif_slc2_mr10x4_sds_common_srx0_srx_pd(module_id, TEN_INSTANCE_ALL, ctl);
    if (ctl == CS_DISABLE) {
      ten_hsif_slc2_mr10x4_sds_common_srx0_rx_cpa(module_id, TEN_INSTANCE_ALL, cpcur, cpcur);
    }
  }
  
  if ((slice == TEN_SLICE3) || (slice == TEN_SLICE_ALL)) {
    ten_hsif_slc3_mr10x5_sds_common_srx0_srx_pd(module_id, TEN_INSTANCE_ALL, ctl);
    if (ctl == CS_DISABLE) {
      ten_hsif_slc3_mr10x5_sds_common_srx0_rx_cpa(module_id, TEN_INSTANCE_ALL, cpcur, cpcur);
    }
  }

  /* Bugzilla #18777                */
  if (ctl == CS_DISABLE) {
    /* allow settling time for the SERDES to power up before proceeding */
    TEN_MDELAY(10);
  }
  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  HIGH LEVEL HSIF XFI CHECK VCO TUNE               */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : HIGH LEVEL                                          */
/* CHIP       : Tenabo                                              */
cs_int16 ten_hl_hsif_check_xfi_vcotune(cs_uint16 module_id,
                                       cs_uint8 slice,
                                       cs_dir_t dir)
/* INPUTS     : o Module Id                                         */
/*              o Slice                                             */
/*              o Direction                                         */
/* OUTPUTS    : ----                                                */
/* RETURNS    : 1=locked, 0=NOT locked or CS_ERROR                  */
/* DESCRIPTION:                                                     */
/* Check XFI SERDES lock status.                                    */
/*                                                                  */
/* [slice] Specified as TEN_SLICE0 (0), TEN_SLICE1 (1),             */
/*   TEN_SLICE2 (2) or TEN_SLICE3 (3)                               */
/*                                                                  */
/* [dir] parameter is specified as:                                 */
/*   0 = CS_TX                                                      */
/*   1 = CS_RX.                                                     */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  cs_uint16 ii, tmp;
  cs_uint16 tuned = 0;
  cs_boolean short_filtpn;
  cs_char8 *func = "ten_hl_hsif_check_xfi_vcotune";  

  if (slice >= TEN_MAX_SLICES) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, "%s() slice out of range.  s/b 0..3.", func);
    return (CS_ERROR);
  }

  if (dir > CS_RX) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, "%s() Invalid dir.", func);
    return (CS_ERROR);
  }
  CS_PRINT("%s() %s, %s, %s\n", func, ten_module_strings[module_id&1], ten_slice_strings[slice], ten_dir_strings[dir]);
           


  for (ii=0; ii<60; ii++) {
    /* check status of SHORT_FILTPNs bit */
    short_filtpn = ten_xfi32x1_get_vco_tune_intstatus(module_id, slice, dir);
   /* CS_PRINT("%d:XFI dir=%d, SERDES slice=%d VCO Tune status = %d\n",
             ii, dir, slice, tuned); */

    /* The tuning process initially sets "SHORT_FILTPN" = ‘1’, */
    /* and clears this bit when the process completes.         */
    if (short_filtpn == FALSE) {
      /* VCO Tune FREQ value read only for information/debugging */
      if (dir == CS_TX) {
        /* ten_reg_read(DEV_ID,TEN_XFI32X1_SDS_XFI32X1_SDS_COMMON_TXVCO0_STATUS+$ch*TEN_XFI32X1_SDS_STRIDE); */
        tmp = ten_xfi32x1_txvco0_status(module_id, slice);
      }
      else {
        tmp = ten_xfi32x1_rxvco0_status(module_id, slice);
      }
      CS_PRINT("%d:XFI, dir=%s, SERDES slice=%d VCO Tune Freq value = %d\n", ii, ten_dir_strings[dir], slice, tmp); 
      if (tmp == 0x3F) {
        CS_PRINT("WARNING:  VCO Tuning completed with a FREQ value of 0x3F.\n");
        CS_PRINT("Divider settings may be misconfigured.\n");
      }
      tuned = 1;
      break;
    }
    /* Bugzilla #28471, minimum delay */
    TEN_MDELAY(20);
  }
  CS_PRINT("%d:XFI dir=%s, SERDES slice=%d VCO Tune status = %d\n", ii, ten_dir_strings[dir], slice, tuned);
  
  if (tuned) {
    CS_PRINT("%s() XFI VCO %s Tuned\n", func, ten_dir_strings[dir]); 
  } else {
    CS_PRINT("%s() XFI VCO %s DID NOT Tune!\n", func, ten_dir_strings[dir]); 
  }
  return (tuned);
}

/********************************************************************/
/* $rtn_hdr_start  HIGH LEVEL HSIF CHECK XFI FILT LOCK              */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : HIGH LEVEL                                          */
/* CHIP       : Tenabo                                              */
cs_int16 ten_hl_hsif_check_xfi_filt_lock(cs_uint16 module_id,
                                       cs_uint8 slice,
                                       cs_dir_t dir)
/* INPUTS     : o Module Id                                         */
/*              o Slice                                             */
/*              o Direction                                         */
/* OUTPUTS    : ----                                                */
/* RETURNS    : 1=locked, 0=NOT locked or CS_ERROR                  */
/* DESCRIPTION:                                                     */
/* Check XFI FILTER lock status.                                    */
/*                                                                  */
/* [slice] Specified as TEN_SLICE0 (0), TEN_SLICE1 (1),             */
/*   TEN_SLICE2 (2) or TEN_SLICE3 (3)                               */
/*                                                                  */
/* [dir] parameter is specified as:                                 */
/*   0 = CS_TX                                                      */
/*   1 = CS_RX.                                                     */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  cs_uint16 ii;
  cs_uint16 locked =0;
  cs_char8 *func = "ten_hl_hsif_check_xfi_filt_lock";  

  if (slice >= TEN_MAX_SLICES) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, "%s() slice out of range.  s/b 0..3.", func);
    return (CS_ERROR);
  }

  if (dir > CS_RX) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, "%s() Invalid dir.", func);
    return (CS_ERROR);
  }
  CS_PRINT("%s() %s, %s, %s\n", func, ten_module_strings[module_id&1], ten_slice_strings[slice], ten_dir_strings[dir]);

  for (ii=0; ii<5; ii++) {
    if (dir == CS_RX) {
      locked = ten_xfi32x1_rxlockd0_filt_lock(module_id, slice);
    }
    else {
      locked = ten_xfi32x1_txlockd0_filt_lock(module_id, slice);
    }
    CS_PRINT("XFI dir=%s SERDES slice=%d, lock filt status = %d\n", ten_dir_strings[dir], slice, locked);

    if (locked) {
      CS_PRINT("%s() XFI FILT Locked %s\n", func, ten_dir_strings[dir]); 
      break;
    } 
    else {
      CS_PRINT("%s() XFI FILT %s DID NOT Lock!\n", func, ten_dir_strings[dir]); 
    }
    TEN_MDELAY(6);
  }
  return (locked);
}

/********************************************************************/
/* $rtn_hdr_start  HIGH LEVEL HSIF CHECK XFI LOCK                   */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : HIGH LEVEL                                          */
/* CHIP       : Tenabo                                              */
cs_int16 ten_hl_hsif_check_xfi_lock(cs_uint16 module_id,
                                    cs_uint8 slice,
                                    cs_dir_t dir)
/* INPUTS     : o Module Id                                         */
/*              o Slice                                             */
/*              o Direction                                         */
/* OUTPUTS    : ----                                                */
/* RETURNS    : 1=locked, 0=NOT locked or CS_ERROR                  */
/* DESCRIPTION:                                                     */
/* Check XFI SERDES lock status.                                    */
/*                                                                  */
/* [slice] Specified as TEN_SLICE0 (0), TEN_SLICE1 (1),             */
/*   TEN_SLICE2 (2) or TEN_SLICE3 (3).                              */
/*                                                                  */
/* [dir] parameter is specified as:                                 */
/*   0 = CS_TX                                                      */
/*   1 = CS_RX.                                                     */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  cs_uint16 locked = 0;
  cs_uint16 ii;

  if (slice >= TEN_MAX_SLICES) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": slice out of range.  s/b 0..3.");
    return (CS_ERROR);
  }

  if (dir > CS_RX) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": Invalid dir.");
    return (CS_ERROR);
  }

  for (ii=0; ii<100; ii++) {
    /* $locked = ($dir eq 'tx') ? ten_xfi32x1_txlockd0_lock(MODULE_ID_B, $ch) : ten_xfi32x1_rxlockd0_lock(MODULE_ID_B, $ch); */
    if (dir == CS_TX) {
      locked = ten_xfi32x1_txlockd0_lock(module_id, slice);
    }
    else {
      locked = ten_xfi32x1_rxlockd0_lock(module_id, slice);
    }
  /*  CS_PRINT("%d:XFI dir=%d SERDES slice=%d, lock status = %d\n",
             ii, dir, slice, locked); */
    if (locked) {
      break;
    }
    
    /* Bugzilla #28471, minimum delay */
    TEN_MDELAY(20);
  }
  CS_PRINT("%d:XFI dir=%s SERDES slice=%d, lock status = %d\n", ii, ten_dir_strings[dir], slice, locked);
  return (locked);
}

/********************************************************************/
/* $rtn_hdr_start  HIGH LEVEL HSIF CHECK MR LOCK                    */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : HIGH LEVEL                                          */
/* CHIP       : Tenabo                                              */
cs_int16 ten_hl_hsif_check_mr_lock(cs_uint16 module_id,
                                   cs_uint8 slice,
                                   cs_dir_t dir)
/* INPUTS     : o Module Id                                         */
/*              o Slice                                             */
/*              o Direction                                         */
/* OUTPUTS    : ----                                                */
/* RETURNS    : 1=locked, 0=NOT locked or CS_ERROR                  */
/* DESCRIPTION:                                                     */
/* Check MR lock status.                                            */
/*                                                                  */
/* [slice] Specified as TEN_SLICE0 (0), TEN_SLICE1 (1),             */
/*   TEN_SLICE2 (2) or TEN_SLICE3 (3).                              */
/*                                                                  */
/* [dir] parameter is specified as:                                 */
/*   0 = CS_TX                                                      */
/*   1 = CS_RX.                                                     */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  cs_uint16  locked = 0;
  cs_uint16 ii;

  if (slice >= TEN_MAX_SLICES) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": slice out of range.  s/b 0..3.");
    return (CS_ERROR);
  }

  if (dir > CS_RX) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": Invalid dir.");
    return (CS_ERROR);
  }

  for (ii=0; ii<100; ii++) {

    if (slice == TEN_SLICE0) {
      if (dir == CS_TX) {
        locked = ten_hsif_slc0_mr10x4_get_sds_tx_lock_status(module_id);
      }
      else {
        locked = ten_hsif_slc0_mr10x4_get_sds_rx_lock_status(module_id, TEN_INSTANCE_ALL);
      }
    }
    else if (slice == TEN_SLICE1) {
      if (dir == CS_TX) {
        locked = ten_hsif_slc1_mr10x5_get_sds_tx_lock_status(module_id);
      }
      else {
        locked = ten_hsif_slc1_mr10x5_get_sds_rx_lock_status(module_id, TEN_INSTANCE_ALL);
      }
    }
    else if (slice == TEN_SLICE2) {
      if (dir == CS_TX) {
        locked = ten_hsif_slc2_mr10x4_get_sds_tx_lock_status(module_id);
      }
      else {
        locked = ten_hsif_slc2_mr10x4_get_sds_rx_lock_status(module_id, TEN_INSTANCE_ALL);
      }
    }
    else if (slice == TEN_SLICE3) {
      if (dir == CS_TX) {
        locked = ten_hsif_slc3_mr10x5_get_sds_tx_lock_status(module_id);
      }
      else {
        locked = ten_hsif_slc3_mr10x5_get_sds_rx_lock_status(module_id, TEN_INSTANCE_ALL);
      }
    }
    CS_PRINT("%d:MR dir=%d SERDES slice=%d, lock status = %d\n",
             ii, dir, slice, locked);

    if (locked) {
      break;
    }
    /* Bugzilla #28471, minimum delay */
    TEN_MDELAY(20);
  }
  return (locked);
}

/********************************************************************/
/* $rtn_hdr_start  HIGH LEVEL HSIF CHECK MR VCO TUNE                */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : HIGH LEVEL                                          */
/* CHIP       : Tenabo                                              */
cs_int16 ten_hl_hsif_check_mr_vcotune(cs_uint16 module_id,
                                   cs_uint8 slice,
                                   cs_dir_t dir)
/* INPUTS     : o Module Id                                         */
/*              o Slice                                             */
/*              o Direction                                         */
/* OUTPUTS    : ----                                                */
/* RETURNS    : 1=locked, 0=NOT locked or CS_ERROR                  */
/* DESCRIPTION:                                                     */
/* Check MR SERDES VCO Tune.                                        */
/*                                                                  */
/* [slice] Specified as TEN_SLICE0 (0), TEN_SLICE1 (1),             */
/*   TEN_SLICE2 (2) or TEN_SLICE3 (3).                              */
/*                                                                  */
/* [dir] parameter is specified as:                                 */
/*   0 = CS_TX                                                      */
/*   1 = CS_RX.                                                     */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  cs_uint16 filtpn = 0;
  cs_uint16 ii;

 if (slice >= TEN_MAX_SLICES) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": slice out of range.  s/b 0..3.");
    return (CS_ERROR);
  }

  if (dir > CS_RX) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": Invalid dir.");
    return (CS_ERROR);
  }

  if (dir == CS_TX) {
     for (ii=0; ii<60; ii++) {
       /* my $filtpn = tenabo_bf_read(DEV_ID,$regaddr,0,0); */
       filtpn = ten_hsif_get_vco_tune_intstatus(module_id, slice, CS_TX, 0);
       CS_PRINT("%d:MR dir=%d SERDES slice=%d, VCO Tune status = %d\n",
                ii, dir, slice, filtpn);

       if (filtpn == 0) {
         return 1;
       }
       /* Bugzilla #28471, minimum delay */
       TEN_MDELAY(20);
     }
  }
  else {
    for(ii=0; ii<60; ii++) {
      filtpn = ten_hsif_get_vco_tune_intstatus(module_id, slice, CS_RX,
                                               TEN_INSTANCE_ALL);
      CS_PRINT("%d:MR dir=%d SERDES slice=%d, VCO Tune status = %d\n",
            ii, dir, slice, filtpn);
      if (filtpn == 0) {
        return 1;
      }
      /* Bugzilla #28471, minimum delay */
      TEN_MDELAY(20);
    }
  }

  return (filtpn);
}

/********************************************************************/
/* $rtn_hdr_start  HIGH LEVEL HSIF CHECK MR FILT LOCK               */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : HIGH LEVEL                                          */
/* CHIP       : Tenabo                                              */
cs_int16 ten_hl_hsif_check_mr_filt_lock(cs_uint16 module_id,
                                        cs_uint8 slice,
                                        cs_dir_t dir)
/* INPUTS     : o Module Id                                         */
/*              o Slice                                             */
/*              o Direction                                         */
/* OUTPUTS    : ----                                                */
/* RETURNS    : 1=locked, 0=NOT locked or CS_ERROR                  */
/* DESCRIPTION:                                                     */
/* Check MR SERDES filt lock status.                                */
/*                                                                  */
/* [slice] Specified as TEN_SLICE0 (0), TEN_SLICE1 (1),             */
/*   TEN_SLICE2 (2) or TEN_SLICE3 (3).                              */
/*                                                                  */
/* [dir] parameter is specified as:                                 */
/*   0 = CS_TX                                                      */
/*   1 = CS_RX.                                                     */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  cs_uint16 ii;
  cs_uint16 locked = 0;
  cs_char8 *func = "ten_hl_hsif_check_mr_filt_lock";  

  if (slice >= TEN_MAX_SLICES) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, "%s() slice %d out of range.  s/b 0..3.", func, slice);
    return (CS_ERROR);
  }

  if (dir > CS_RX) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, "%s() dir %d Invalid .", func, dir);
    return (CS_ERROR);
  }
  
  /* Bugzilla #28330, allow configuration with dark fiber to complete faster */
  if (dir == CS_TX) {
    if (slice == TEN_SLICE0) {
      for (ii=0; ii<5; ii++) {
        locked = ten_hsif_slc0_mr10x4_get_sds_tx_filt_lock_status(module_id);
        CS_PRINT("%d:MR dir=%d SERDES slice=%d, lock filt status = %d\n",
                  ii, dir, slice, locked);
        if (locked) {
          break;
        }
        TEN_MDELAY(6);
      }
    }
    else if (slice == TEN_SLICE1) {
      for (ii=0; ii<5; ii++) {
        locked = ten_hsif_slc1_mr10x5_get_sds_tx_filt_lock_status(module_id);
        CS_PRINT("%d:MR dir=%d SERDES slice=%d, lock filt status = %d\n",
                  ii, dir, slice, locked);
        if (locked) {
          break;
        }
        TEN_MDELAY(6);
      }
    }
    else if (slice == TEN_SLICE2) {
      for (ii=0; ii<5; ii++) {
        locked = ten_hsif_slc2_mr10x4_get_sds_tx_filt_lock_status(module_id);
        CS_PRINT("%d:MR dir=%d SERDES slice=%d, lock filt status = %d\n",
                  ii, dir, slice, locked);
        if (locked) {
          break;
        }
        TEN_MDELAY(6);
      }
    }
    else if (slice == TEN_SLICE3) {
      for (ii=0; ii<5; ii++) {
        locked = ten_hsif_slc3_mr10x5_get_sds_tx_filt_lock_status(module_id);
        CS_PRINT("%d:MR dir=%d SERDES slice=%d, lock filt status = %d\n",
                  ii, dir, slice, locked);
        if (locked) {
          break;
        }
        TEN_MDELAY(6);
      }
    }
  }

  else {

    if (slice == TEN_SLICE0) {
      for(ii=0; ii<5; ii++) {
        locked = ten_hsif_slc0_mr10x4_get_sds_rx_filt_lock_status(module_id, TEN_INSTANCE_ALL);
        CS_PRINT("%d:MR dir=%d SERDES slice=%d, lock filt status = %d\n",
                  ii, dir, slice, locked);
        if (locked == 1) {
          break;
        }
        TEN_MDELAY(6);
      }
    }

    else if (slice == TEN_SLICE1) {
      for(ii=0; ii<5; ii++) {
        locked = ten_hsif_slc1_mr10x5_get_sds_rx_filt_lock_status(module_id, TEN_INSTANCE_ALL);
        CS_PRINT("%d:MR dir=%d SERDES slice=%d, lock filt status = %d\n",
                  ii, dir, slice, locked);
        if (locked == 1) {
          break;
        }
        TEN_MDELAY(6);
      }
    }

    else if (slice == TEN_SLICE2) {
      for(ii=0; ii<5; ii++) {
      locked = ten_hsif_slc2_mr10x4_get_sds_rx_filt_lock_status(module_id, TEN_INSTANCE_ALL);
        CS_PRINT("%d:MR dir=%d SERDES slice=%d, lock filt status = %d\n",
                 ii, dir, slice, locked);
        if (locked == 1) {
          break;
        }
        TEN_MDELAY(6);
      }
    }

    else if (slice == TEN_SLICE3) {
      for(ii=0; ii<5; ii++) {
        locked = ten_hsif_slc3_mr10x5_get_sds_rx_filt_lock_status(module_id, TEN_INSTANCE_ALL);
        CS_PRINT("%d:MR dir=%d SERDES slice=%d, lock filt status = %d\n",
                 ii, dir, slice, locked);
        if (locked == 1) {
          break;
        }
        TEN_MDELAY(6);
      }
    }
  }
  
  CS_PRINT("%s()  %s, %s, %s MR SERDESlock filt status = %s\n", 
            func, ten_module_strings[module_id&1],  ten_slice_strings[slice], ten_dir_strings[dir], locked?"LOCKED":"NOT LOCKED");    
 
  return (locked);
}

/********************************************************************/
/* $rtn_hdr_start  HIGH LEVEL HSIF CONFIG SFI42 40G TRANSPONDER     */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : HIGH LEVEL                                          */
/* CHIP       : Tenabo                                              */
cs_status ten_hl_config_sfi42_40g_transponder(cs_uint16 module_id,
                                              cs_uint16 divider,
                                              cs_uint16 internal_pilot,
                                              cs_uint16 mr_protect,
                                              cs_uint16 sync)
/* INPUTS     : o Module Id                                         */
/*              o Divider                                           */
/*              o Internal Pilot                                    */
/*              o MR protect                                        */
/*              o Sync                                              */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Configure an SFI-4.2 interface for 40G transponder.              */
/* Returns CS_OK if VCO tunes and CS_ERROR if VCO tuning fails.     */
/* Only the needed GPLLs are powered on.                            */
/*                                                                  */
/* [divider] parameter is specified as:                             */
/*   TEN_HSIF_CKREFDIV1 = 0,  (div1 to serdes)                      */
/*   TEN_HSIF_CKREFDIV2 = 1,  (div2 to serdes)                      */
/*   TEN_HSIF_CKREFDIV4 = 2   (div4 to serdes)                      */
/*                                                                  */
/* [internal_pilot] parameter is specified as:                      */
/*   0 = do not use internal pilot                                  */
/*   1 = use internal pilot                                         */
/*                                                                  */
/* [mr_protect] parameter is specified as:                          */
/*   0 = normal provisioning, tx output on                          */
/*   1 = use MR protect, tx output off                              */
/*   2 = normal provisioning, tx output off.                        */
/*                                                                  */
/* [sync] parameter is specified as:                                */
/*   TEN_MAP_AMP = 0x0000,                                          */
/*   TEN_MAP_BMP = 0x0001.                                          */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  cs_status rtn = CS_OK;
  cs_uint16 dev_id = TEN_MOD_ID_TO_DEV_ID(module_id);
  cs_uint16 instance;
  cs_uint16 ii;

  CS_PRINT("ten_hl_config_sfi42_40g_transponder:  ");
  CS_PRINT("mod_id=0x%04X, div=%d, internal_pilot=%d, mr_protect=%d, sync=%d\n", 
            module_id, divider, internal_pilot, mr_protect, sync);

  if (sync > TEN_MAP_BMP) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": invalid clk sync option");
    return (CS_ERROR);
  }         
            
  ten_hl_hsif_config_sfi42_40g(module_id, divider, internal_pilot, mr_protect);

  /* bugzilla #21799, check for CS_ERROR and lock failed */
  for (ii=0; ii<4; ii++) {
    if (ten_hl_hsif_mr_waitfor_vcotune(module_id, ii) != 1) {
      /* Bugzilla 22973 Start */
      CS_PRINT("ten_hl_gpllx1_waitfor_vcotune FAILED first time");
      rtn |= CS_ERROR;
      /* Bugzilla 22973 End */
    }
  }

  if (TEN_MOD_ID_TO_MOD_NUM(module_id) == TEN_MODULE_A) {
    instance = 1;
  }
  else {
    instance = 9;
  }

  for (ii=0; ii<8; ii++) {
  
    if (sync == TEN_MAP_AMP) {
      if ((ii != 0) && (ii != 3) &&
          (ii != 4) && (ii != 7)) {
        CS_PRINT("gpllx #%d not needed for async 40g trans, power down.\n", ii);
        /* power down un-needed GPLLs */
        ten_hl_gpllx1_init(dev_id, instance + ii, TEN_HL_GPLL_MODE_SFI42_40G, 1);
        continue;
      }
    }
  
    if (sync == TEN_MAP_BMP) {
      if ((ii != 0) && (ii != 4)) {
        CS_PRINT("gpllx #%d not needed for sync 40g trans, power down.\n", ii);
        /* power down un-needed GPLLs */
        ten_hl_gpllx1_init(dev_id, instance + ii, TEN_HL_GPLL_MODE_SFI42_40G, 1);
        continue;
      }
    }
  
    ten_hl_gpllx1_init(dev_id, instance + ii, TEN_HL_GPLL_MODE_SFI42_40G, 0x0 );
    /* bugzilla #21799, check for CS_ERROR and lock failed */
    if (ten_hl_gpllx1_waitfor_vcotune(dev_id, instance + ii) != 1) {
      /* Bugzilla 22973 Start */
      CS_PRINT("ten_hl_gpllx1_waitfor_vcotune FAILED second time");
      rtn |= CS_ERROR;
      /* Bugzilla 22973 End */
    }
  }
  
/* Bugzilla #25165, recommended to add a toggle of resync to the API. */
  rtn |= ten_hl_hsif_mr_resync(module_id, TEN_SLICE_ALL, CS_TX_AND_RX);

  CS_PRINT("ten_hl_config_sfi42_40g_transponder complete:  ");
  if (rtn == CS_OK) {
    CS_PRINT("CS_OK");
  }
  else {
      CS_PRINT("CS_ERROR");
  }
  return (rtn);
}

/********************************************************************/
/* $rtn_hdr_start  HIGH LEVEL HSIF CONFIG SFI42 40G                 */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : HIGH LEVEL                                          */
/* CHIP       : Tenabo                                              */
cs_status ten_hl_config_sfi42_40g(cs_uint16 module_id,
                                  cs_uint16 divider,
                                  cs_uint16 internal_pilot,
                                  cs_uint16 mr_protect)
/* INPUTS     : o Module Id                                         */
/*              o Divider                                           */
/*              o Internal Pilot                                    */
/*              o MR protect                                        */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Configure an SFI-4.2 interface for 40G. Returns CS_OK if         */
/* VCO tunes and CS_ERROR if VCO tuning fails.                      */
/*                                                                  */
/* [divider] parameter is specified as:                             */
/*   TEN_HSIF_CKREFDIV1 = 0,  (div1 to serdes)                      */
/*   TEN_HSIF_CKREFDIV2 = 1,  (div2 to serdes)                      */
/*   TEN_HSIF_CKREFDIV4 = 2   (div4 to serdes)                      */
/*                                                                  */
/* [internal_pilot] parameter is specified as:                      */
/*   0 = do not use internal pilot                                  */
/*   1 = use internal pilot                                         */
/*                                                                  */
/* [mr_protect] parameter is specified as:                          */
/*   0 = normal provisioning, tx output on                          */
/*   1 = use MR protect, tx output off                              */
/*   2 = normal provisioning, tx output off.                        */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  cs_status rtn = CS_OK;
  cs_uint16 dev_id = TEN_MOD_ID_TO_DEV_ID(module_id);
  cs_uint16 instance;
  cs_uint16 ii;

  CS_PRINT("ten_hl_config_sfi42_40g:  ");
  CS_PRINT("mod_id=0x%04X, div=%d, internal_pilot=%d, mr_protect=%d\n", 
            module_id, divider, internal_pilot, mr_protect);

  /* Bugzilla #36753: In Warm Start mode, disable API FAILURE */
  if (ten_dev_is_ws_in_progress(TEN_MOD_ID_TO_DEV_ID(module_id))) {
    CS_PRINT("Device is in warm start mode, report CS_OK\n");
    return (CS_OK);
  }          
            
  ten_hl_hsif_config_sfi42_40g(module_id, divider, internal_pilot, mr_protect);

  /* bugzilla #21799, check for CS_ERROR and lock failed */
  for (ii=0; ii<4; ii++) {
    if (ten_hl_hsif_mr_waitfor_vcotune(module_id, ii) != 1) {
      /* Bugzilla 22973 Start */
      CS_PRINT("ten_hl_gpllx1_waitfor_vcotune FAILED first time");
      rtn |= CS_ERROR;
      /* Bugzilla 22973 End */
    }
  }

  /*  my $rtn = config_gpll_40g($module_id, main::TEN_HL_GPLL_MODE_SFI42_40G); */

  if ((module_id & 1) == TEN_MODULE_A) {
    instance = 1;
  }
  else {
    instance = 9;
  }

  for (ii=0; ii<8; ii++) {
    ten_hl_gpllx1_init(dev_id, instance + ii, TEN_HL_GPLL_MODE_SFI42_40G, 0x0 );
    /* bugzilla #21799, check for CS_ERROR and lock failed */
    if (ten_hl_gpllx1_waitfor_vcotune(dev_id, instance + ii) != 1) {
      /* Bugzilla 22973 Start */
      CS_PRINT("ten_hl_gpllx1_waitfor_vcotune FAILED second time");
      rtn |= CS_ERROR;
      /* Bugzilla 22973 End */
    }
  }
  return (rtn);
}

/********************************************************************/
/* $rtn_hdr_start  HIGH LEVEL HSIF CONFIG SFI42 40G                 */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : HIGH LEVEL                                          */
/* CHIP       : Tenabo                                              */
cs_status ten_hl_hsif_config_sfi42_40g(cs_uint16 module_id,
                                       cs_uint16 divider,
                                       cs_uint16 internal_pilot,
                                       cs_uint16 mr_protect)
/* INPUTS     : o Module Id                                         */
/*              o Divider                                           */
/*              o Internal Pilot                                    */
/*              o MR protect                                        */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Configure HSIF and SFI42 40G SERDES.                             */
/*                                                                  */
/* [divider] parameter is specified as:                             */
/*   TEN_HSIF_CKREFDIV1 = 0,  (div1 to serdes)                      */
/*   TEN_HSIF_CKREFDIV2 = 1,  (div2 to serdes)                      */
/*   TEN_HSIF_CKREFDIV4 = 2   (div4 to serdes)                      */
/*                                                                  */
/* [internal_pilot] parameter is specified as:                      */
/*   0 = do not use internal pilot                                  */
/*   1 = use internal pilot                                         */
/*                                                                  */
/* [mr_protect] parameter is specified as:                          */
/*   0 = normal provisioning, tx output on                          */
/*   1 = use MR protect, tx output off                              */
/*   2 = normal provisioning, tx output off.                        */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  cs_uint16 val;
  cs_status rtn = CS_OK;

  CS_PRINT("ten_hl_hsif_config_sfi42_40g:  ");
  CS_PRINT("mod_id=0x%04X, div=%d, internal_pilot=%d, mr_protect=%d\n", 
            module_id, divider, internal_pilot, mr_protect);

  /* Bugzilla #36263 - mpif reset for all hsif interface */
  rtn |= ten_mpif_global_reset_sds_mr_mpif(TEN_MOD_ID_TO_DEV_ID(module_id), TEN_MOD_ID_TO_MOD_NUM(module_id),
                                           TEN_SLICE_ALL, CS_RESET_TOGGLE);
                                           
  /* Bugzilla #26742, fix backplane protection */
  if (mr_protect == 1) {            
    rtn |= ten_mpif_global_reset_hsif(TEN_MOD_ID_TO_DEV_ID(module_id),
                               TEN_MOD_ID_TO_MOD_NUM(module_id),
                               CS_TX_AND_RX, CS_RESET_ASSERT);
  }
       
  if ((mr_protect == 1) || (mr_protect == 2)) {            
    rtn |= ten_hl_hsif_control_mr_tx_output(module_id, TEN_SLICE_ALL, CS_DISABLE);
  }
    
  /* power up the SFI42 40G serdes */
  rtn |= ten_hl_hsif_powerdown_mr(module_id, TEN_SLICE_ALL, CS_DISABLE);

  /* Provision Datapath */
  if (mr_protect != 1) {
    /* Bugzilla #30768, fix protection switch on same port */
    rtn |= ten_hsif_provision_datapath_t41(module_id, TEN_INSTANCE_ALL, 
                                           0,                              /* tx_pswtchen   */
                                           TEN_HSIF_PROTOCOL_SFI42_40G,    /* tx_mrprotocol */
                                           0,                              /* rx_pswtchen   */
                                           TEN_HSIF_PROTOCOL_SFI42_40G);   /* rx_mrprotocol */
           
    /* Bugzilla #31356, fix issues with xfiselect bits */
    if (TEN_MOD_ID_TO_MOD_NUM(module_id) == TEN_MODULE_B) {
      rtn |= ten_hsif_provision_tx_xfiselect(module_id, TEN_SLICE_ALL, 0);
      rtn |= ten_hsif_provision_rx_xfiselect(module_id, TEN_SLICE_ALL, 0);                                      
    }
  } 
  else {
    /* rx_a2b      */
    rtn |= ten_mpif_clock_select_prot(TEN_MOD_ID_TO_DEV_ID(module_id), 1, 1, 0xF, 0xF);
    /* Bugzilla #30768, fix protection switch on same port */
    rtn |= ten_hsif_provision_datapath_t41(module_id, TEN_INSTANCE_ALL, 
                                           1,                              /* tx_pswtchen   */
                                           TEN_HSIF_PROTOCOL_SFI42_40G,    /* tx_mrprotocol */
                                           0,                              /* rx_pswtchen   */
                                           TEN_HSIF_PROTOCOL_SFI42_40G);   /* rx_mrprotocol */
                                           
    /* Bugzilla #31356, fix issues with xfiselect bits */
    if (TEN_MOD_ID_TO_MOD_NUM(module_id) == TEN_MODULE_B) {
      rtn |= ten_hsif_provision_tx_xfiselect(module_id, TEN_SLICE_ALL, 1);
      rtn |= ten_hsif_provision_rx_xfiselect(module_id, TEN_SLICE_ALL, 1);                                        
    }
  }

  /* JAM MR ring oscillator fix */
  rtn |= ten_hl_hsif_mr_ring_oscillator_fix(module_id, TEN_SLICE_ALL);

  /* tenabo_bf_write(DEV_ID,TEN_HSIF_MR_SLC0_MR10X4_SDS_COMMON_STXP0_TX_CLKOUT_CTRL+$hsif_id*TEN_HSIF_STRIDE, 1, 6, 6); */
  rtn |= ten_hsif_slc0_mr10x4_sds_common_stxp0_tx_clkout_ctrl_clkouten(module_id, 1);
  /* tenabo_bf_write(DEV_ID,TEN_HSIF_MR_SLC1_MR10X5_SDS_COMMON_STXP0_TX_CLKOUT_CTRL+$hsif_id*TEN_HSIF_STRIDE, 1, 6, 6); */
  rtn |= ten_hsif_slc1_mr10x5_sds_common_stxp0_tx_clkout_ctrl_clkouten(module_id, 1);
  /* tenabo_bf_write(DEV_ID,TEN_HSIF_MR_SLC2_MR10X4_SDS_COMMON_STXP0_TX_CLKOUT_CTRL+$hsif_id*TEN_HSIF_STRIDE, 1, 6, 6); */
  rtn |= ten_hsif_slc2_mr10x4_sds_common_stxp0_tx_clkout_ctrl_clkouten(module_id, 1);
  /* tenabo_bf_write(DEV_ID,TEN_HSIF_MR_SLC3_MR10X5_SDS_COMMON_STXP0_TX_CLKOUT_CTRL+$hsif_id*TEN_HSIF_STRIDE, 1, 6, 6); */
  rtn |= ten_hsif_slc3_mr10x5_sds_common_stxp0_tx_clkout_ctrl_clkouten(module_id, 1);

  /* SFI5CKREF (SFI5Pilot_sel=0,loopckel=0,ckrefdiv=2/1/0,spare=0xc) */
  if (divider == TEN_HSIF_CKREFDIV4) {
    /* ten_reg_write(DEV_ID,TEN_HSIF_PROTOCOL_REFCLK_CFG+$hsif_id*TEN_HSIF_STRIDE,0x2c); */
    rtn |= ten_hsif_set_refclk_cfg(module_id, TEN_HSIF_REFCLK_CFG_ALL, 0x2C);
  }
  else if (divider == TEN_HSIF_CKREFDIV2) {
    /* ten_reg_write(DEV_ID,TEN_HSIF_PROTOCOL_REFCLK_CFG+$hsif_id*TEN_HSIF_STRIDE,0x1c); */
    rtn |= ten_hsif_set_refclk_cfg(module_id, TEN_HSIF_REFCLK_CFG_ALL, 0x1C);
  }
  else if (divider == TEN_HSIF_CKREFDIV1) {
    /* ten_reg_write(DEV_ID,TEN_HSIF_PROTOCOL_REFCLK_CFG+$hsif_id*TEN_HSIF_STRIDE,0x0c); */
    rtn |= ten_hsif_set_refclk_cfg(module_id, TEN_HSIF_REFCLK_CFG_ALL, 0x0C);
  }
  else {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": Unsupported divider for SFI42 40G");
  }

  /* Choose fractional divider output as pilot tone */
  /* looptime_sel=0 (TX ref from local CLKREFP/N), pilot_sel=1 (0:CLKREF 1:AUXPILOTIN 2:AUXREFIN), buswidth=1 (10bit) */
  if (internal_pilot) {
    rtn |= ten_hsif_slc0_mr10x4_sds_common_stxp0_tx_config(module_id, 2, 1, 1);
    rtn |= ten_hsif_slc1_mr10x5_sds_common_stxp0_tx_config(module_id, 2, 1, 1);
    rtn |= ten_hsif_slc2_mr10x4_sds_common_stxp0_tx_config(module_id, 2, 1, 1);
    rtn |= ten_hsif_slc3_mr10x5_sds_common_stxp0_tx_config(module_id, 2, 1, 1);
  } else {
    rtn |= ten_hsif_slc0_mr10x4_sds_common_stxp0_tx_config(module_id, 2, 2, 1);
    rtn |= ten_hsif_slc1_mr10x5_sds_common_stxp0_tx_config(module_id, 2, 2, 1);
    rtn |= ten_hsif_slc2_mr10x4_sds_common_stxp0_tx_config(module_id, 2, 2, 1);
    rtn |= ten_hsif_slc3_mr10x5_sds_common_stxp0_tx_config(module_id, 2, 2, 1);
  }

  rtn |= ten_hsif_slc0_mr10x4_sds_common_srx0_rx_config(module_id, TEN_INSTANCE_ALL, 1);
  rtn |= ten_hsif_slc2_mr10x4_sds_common_srx0_rx_config(module_id, TEN_INSTANCE_ALL, 1);

  rtn |= ten_hsif_slc1_mr10x5_sds_common_srx0_rx_config(module_id, TEN_INSTANCE_ALL, 1);
  rtn |= ten_hsif_slc3_mr10x5_sds_common_srx0_rx_config(module_id, TEN_INSTANCE_ALL, 1);

  if (internal_pilot) {
    val = 0xb;
  }
  else {
    val = 0xa;
  }
  rtn |= ten_hsif_slc0_mr10x4_sds_common_srx0_rx_clkdiv_ctrl(module_id, TEN_INSTANCE_ALL, 0, val);
  rtn |= ten_hsif_slc2_mr10x4_sds_common_srx0_rx_clkdiv_ctrl(module_id, TEN_INSTANCE_ALL, 0, val);

  rtn |= ten_hsif_slc1_mr10x5_sds_common_srx0_rx_clkdiv_ctrl(module_id, TEN_INSTANCE_ALL, 0, val);
  rtn |= ten_hsif_slc3_mr10x5_sds_common_srx0_rx_clkdiv_ctrl(module_id, TEN_INSTANCE_ALL, 0, val);

  rtn |= ten_hsif_slc0_mr10x4_sds_common_stxp0_tx_clkdiv_ctrl(module_id, 0, 0x0a);
  rtn |= ten_hsif_slc1_mr10x5_sds_common_stxp0_tx_clkdiv_ctrl(module_id, 0, 0x0a);
  rtn |= ten_hsif_slc2_mr10x4_sds_common_stxp0_tx_clkdiv_ctrl(module_id, 0, 0x0a);
  rtn |= ten_hsif_slc3_mr10x5_sds_common_stxp0_tx_clkdiv_ctrl(module_id, 0, 0x0a);

  if (internal_pilot) {
    /* TX CTVDIV=div2 */
    /* tenabo_bf_write(DEV_ID,TEN_HSIF_MR_SLC0_MR10X4_SDS_COMMON_STXP0_TX_CLKDIV_CTRL+$hsif_id*TEN_HSIF_STRIDE, 1, 9, 8); */
    rtn |= ten_hsif_slc0_mr10x4_sds_common_stxp0_stxp_ctvdiv_sel(module_id, 1);
    /* tenabo_bf_write(DEV_ID,TEN_HSIF_MR_SLC1_MR10X5_SDS_COMMON_STXP0_TX_CLKDIV_CTRL+$hsif_id*TEN_HSIF_STRIDE, 1, 9, 8); */
    rtn |= ten_hsif_slc1_mr10x5_sds_common_stxp0_stxp_ctvdiv_sel(module_id, 1);
    /* tenabo_bf_write(DEV_ID,TEN_HSIF_MR_SLC2_MR10X4_SDS_COMMON_STXP0_TX_CLKDIV_CTRL+$hsif_id*TEN_HSIF_STRIDE, 1, 9, 8); */
    rtn |= ten_hsif_slc2_mr10x4_sds_common_stxp0_stxp_ctvdiv_sel(module_id, 1);
    /* tenabo_bf_write(DEV_ID,TEN_HSIF_MR_SLC3_MR10X5_SDS_COMMON_STXP0_TX_CLKDIV_CTRL+$hsif_id*TEN_HSIF_STRIDE, 1, 9, 8); */
    rtn |= ten_hsif_slc3_mr10x5_sds_common_stxp0_stxp_ctvdiv_sel(module_id, 1);
  }

  /* Force RX to lock to pilot tone */
  /* for(my $i=0; $i<4; $i++) { */
  /*  tenabo_bf_write(DEV_ID,TEN_HSIF_MR_SLC0_MR10X4_SDS_COMMON_RXLOCKD0_CONTROL+$hsif_id*TEN_HSIF_STRIDE+$i*TEN_HSIF_MR_SLC0_MR10X4_SDS_COMMON_RXLOCKD0_CONTROL_STRIDE,1,0,0); */
  /*  tenabo_bf_write(DEV_ID,TEN_HSIF_MR_SLC2_MR10X4_SDS_COMMON_RXLOCKD0_CONTROL+$hsif_id*TEN_HSIF_STRIDE+$i*TEN_HSIF_MR_SLC2_MR10X4_SDS_COMMON_RXLOCKD0_CONTROL_STRIDE,1,0,0); */
  /* } */
  /* for(my $i=0; $i<5; $i++) { */
  /*  tenabo_bf_write(DEV_ID,TEN_HSIF_MR_SLC1_MR10X5_SDS_COMMON_RXLOCKD0_CONTROL+$hsif_id*TEN_HSIF_STRIDE+$i*TEN_HSIF_MR_SLC1_MR10X5_SDS_COMMON_RXLOCKD0_CONTROL_STRIDE,1,0,0); */
  /*  tenabo_bf_write(DEV_ID,TEN_HSIF_MR_SLC3_MR10X5_SDS_COMMON_RXLOCKD0_CONTROL+$hsif_id*TEN_HSIF_STRIDE+$i*TEN_HSIF_MR_SLC3_MR10X5_SDS_COMMON_RXLOCKD0_CONTROL_STRIDE,1,0,0); */
  /* } */
  rtn |= ten_hsif_set_slc0_mr10x4_rxlockd0_force_lock(module_id, TEN_INSTANCE_ALL, 0, 1);
  rtn |= ten_hsif_set_slc1_mr10x5_rxlockd0_force_lock(module_id, TEN_INSTANCE_ALL, 0, 1);
  rtn |= ten_hsif_set_slc2_mr10x4_rxlockd0_force_lock(module_id, TEN_INSTANCE_ALL, 0, 1);
  rtn |= ten_hsif_set_slc3_mr10x5_rxlockd0_force_lock(module_id, TEN_INSTANCE_ALL, 0, 1);

  /* bugzilla #24278 */
  if (mr_protect) {     
    /* Bugzilla #27593 Feature Request: MRA/B Tx Output Enable */
    rtn |= ten_hl_hsif_analog_cfg(module_id, TEN_SLICE_ALL, TEN_HSIF_PROTOCOL_SFI42_40G, TEN_HSIF_TIMING_MODE_LOCAL_MR_PROTECT);
  }
  else {
    rtn |= ten_hl_hsif_analog_cfg(module_id, TEN_SLICE_ALL, TEN_HSIF_PROTOCOL_SFI42_40G, TEN_HSIF_TIMING_MODE_LOCAL);
  }
  
  /* remove sds rx/tx reset */
  rtn |= ten_mpif_global_reset_sds_mr(TEN_MOD_ID_TO_DEV_ID(module_id), TEN_MOD_ID_TO_MOD_NUM(module_id),
                               TEN_SLICE_ALL, CS_TX_AND_RX, CS_RESET_DEASSERT);

  /* enable global clock for HSIF */
  if (TEN_MOD_ID_TO_MOD_NUM(module_id) == TEN_MODULE_A) {
     rtn |= ten_mpif_global_clock_disable_mr_a(TEN_MOD_ID_TO_DEV_ID(module_id), TEN_SLICE_ALL, CS_TX_AND_RX, CS_ENABLE);
  }
  else {
     rtn |= ten_mpif_global_clock_disable_mr_b(TEN_MOD_ID_TO_DEV_ID(module_id), TEN_SLICE_ALL, CS_TX_AND_RX, CS_ENABLE);
     rtn |= ten_mpif_global_clock_disable_xfi_b(TEN_MOD_ID_TO_DEV_ID(module_id), TEN_SLICE_ALL, CS_TX_AND_RX, CS_ENABLE);
  }

  if (mr_protect != 1) {
    /* Select SERDES Clock out of HSIF */
    rtn |= ten_mpif_clock_select_hsif_out(TEN_MOD_ID_TO_DEV_ID(module_id),
                                   TEN_MOD_ID_TO_MOD_NUM(module_id),
                                   TEN_SLICE_ALL, CS_TX_AND_RX, 0);
  }
  
   /* Bugzilla #20950, set threshold to 8 instead of default 32. */
  rtn |= ten_hsif_sfi42_oos_threshold(module_id, TEN_INSTANCE_ALL, 8);

  /* Bugzilla #28764, remove resets simultaneously */
  rtn |= ten_hsif_reset(module_id, CS_RESET_DEASSERT, TEN_HSIF_RESET_TX_SFI42_0 |
                                               TEN_HSIF_RESET_TX_SFI42_1 |
                                               TEN_HSIF_RESET_TX_SFI42_2 |
                                               TEN_HSIF_RESET_TX_SFI42_3 |
                                               TEN_HSIF_RESET_RX_SFI42_0 |
                                               TEN_HSIF_RESET_RX_SFI42_1 | 
                                               TEN_HSIF_RESET_RX_SFI42_2 |
                                               TEN_HSIF_RESET_RX_SFI42_3);

  /* Bugzilla #26742, fix backplane protection */
  if (mr_protect == 1) {            
    rtn |= ten_mpif_global_reset_hsif(TEN_MOD_ID_TO_DEV_ID(module_id),
                               TEN_MOD_ID_TO_MOD_NUM(module_id),
                               CS_TX_AND_RX, CS_RESET_DEASSERT);
  }

  CS_PRINT("ten_hl_hsif_config_sfi42_40g Complete, rtn=%s.\n", (rtn == CS_OK) ? "CS_OK" : "CS_ERROR");
  return (rtn);
}

/* Bugzilla #  , backplane protection for MR modes */
/********************************************************************/
/* $rtn_hdr_start  HIGH LEVEL CONFIG SFI42 10G T41                  */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : HIGH LEVEL                                          */
/* CHIP       : Tenabo                                              */
cs_status ten_hl_config_sfi42_10g_t41(cs_uint16 module_id,
                                      cs_uint8 slice,
                                      cs_uint16 line,
                                      cs_uint32 sysclk_freq,
                                      cs_uint16 sync,
                                      cs_uint16 enhanced_deskew,
                                      cs_uint16 internal_pilot,
                                      cs_uint16 mr_protect)
/* INPUTS     : o Module Id                                         */
/*              o Slice                                             */
/*              o Line                                              */
/*              o Sys Clock Frequency                               */
/*              o Sync                                              */
/*              o Enhanced Deskew                                   */
/*              o Internal Pilot                                    */
/*              o MR Protect                                        */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Provides top-most level configuration of SFI42-10G, including    */
/* waiting for lock.                                                */
/*                                                                  */
/* [slice]  Specified as TEN_SLICE0 (0), TEN_SLICE1 (1),            */
/*   TEN_SLICE2 (2), TEN_SLICE3 (3) or TEN_SLICE_ALL (0xFF)         */
/*                                                                  */
/* [sysclk_freq] parameter is specified as:                         */
/*   unused parameter (set to 0)                                    */
/*                                                                  */
/* [sync] parameter is specified as:                                */
/*   unused parameter (set to 0)                                    */
/*                                                                  */
/* [line] parameter is specified as:                                */
/*   unused parameter (set to 0)                                    */
/*                                                                  */
/* [enhanced deskew] parameter is specified as:                     */
/*   0 = do not use enhanced deskew                                 */
/*   1 = use enhanced deskew                                        */
/*                                                                  */
/* [internal_pilot] parameter is specified as:                      */
/*   0 = do not use internal pilot                                  */
/*   1 = use internal pilot.                                        */
/*                                                                  */
/* [mr_protect] parameter is specified as:                          */
/*   0 = normal provisioning, tx output on                          */
/*   1 = use MR protect, tx output off                              */
/*   2 = normal provisioning, tx output off.                        */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  cs_uint16 dev_id = TEN_MOD_ID_TO_DEV_ID(module_id);
  cs_uint16 rx_sfi42;
  cs_uint16 instance;
  cs_uint16 gpll_mode;
  cs_uint16 ii;
  cs_uint16 resync;
  /* Bugzilla #27499, change MR sequence */
  cs_status rtn = CS_OK;
  cs_char8 *func = "ten_hl_config_sfi42_10g_t41";
  
  CS_PRINT("%s()  %s, slice=%d, line=%d, sysclk=%d, sync=%d, enh_ds=%d, int_pilot=%d, mr_prot=%d\n",
            func, ten_module_strings[module_id & 1], slice, line, sysclk_freq, sync, enhanced_deskew, internal_pilot, mr_protect);

            
  rtn |= ten_hl_hsif_config_sfi42_10g(module_id, slice, internal_pilot, mr_protect);
  
  /* SFI-4.2 enhancements, this approach works for individual slices   */
  /* Enhanced deskew is the device default, so this is for normal mode */
  if (!enhanced_deskew) {
    rx_sfi42 = 1 << (slice + 12);
    CS_PRINT("Standard deskew: 0x%04X\n", rx_sfi42);
    rtn |= ten_hsif_reset(module_id, CS_RESET_ASSERT, rx_sfi42);
    rtn |= ten_hsif_sfi42_slice_control(module_id, slice, 0, 0, 1, 1);
    rtn |= ten_hsif_reset(module_id, CS_RESET_DEASSERT, rx_sfi42);

    /* Resync the elastic store */
    for (ii=0; ii<2; ii++) {
      if (ii==0) {
        resync = 1;
      }
      else {
         resync = 0;
      }

      if (slice == 0) {
        rtn |= ten_hsif_slc0_mr10x4_sds_common_rxelst0_resync(module_id, TEN_INSTANCE_ALL, resync);
      }
      else if (slice == 1) {
        rtn |= ten_hsif_slc1_mr10x5_sds_common_rxelst0_resync(module_id, TEN_INSTANCE_ALL, resync);
      }
      else if (slice == 2) {
        rtn |= ten_hsif_slc2_mr10x4_sds_common_rxelst0_resync(module_id, TEN_INSTANCE_ALL, resync);
      }
      else if (slice == 3) {
        rtn |= ten_hsif_slc3_mr10x5_sds_common_rxelst0_resync(module_id, TEN_INSTANCE_ALL, resync);
      }
    }
  }
  
  /* Bugzilla #21799, check for CS_ERROR or not locked (0) */
  if (ten_hl_hsif_mr_waitfor_vcotune(module_id, slice) != 1) {
    /* Bugzilla #27499, change MR sequence */
    rtn |= CS_ERROR;
  }

  if ((module_id & 1) == TEN_MODULE_B) {
    instance = 9;
  }
  else {
    instance = 1;
  }
  instance += slice;

  gpll_mode = TEN_HL_GPLL_MODE_SFI42_10G;
  rtn |= ten_hl_gpllx1_init(dev_id, instance, gpll_mode, 0);

  /* Bugzilla #21799, check for CS_ERROR or not locked (0) */
  if (ten_hl_gpllx1_waitfor_vcotune(dev_id, instance) != 1) {
    CS_PRINT("%s()   inst=%d FAILED!\n", func, instance);
    rtn |= CS_ERROR;
  }

  rtn |= ten_hl_gpllx1_init(dev_id, instance+4, gpll_mode, 0);
  if (ten_hl_gpllx1_waitfor_vcotune(dev_id, instance+4) != 1) {
    CS_PRINT("%s()   inst+4=%d FAILED!\n", func, instance+4);
    rtn |= CS_ERROR;
  }

  /* Bugzilla #25165, recommended to add a toggle of resync. */
  rtn |= ten_hl_hsif_mr_resync(module_id, slice, CS_TX_AND_RX);

  /* Bugzilla 39690 Start */
  if ((line == TEN_TRAFFIC_TYPE_4GFC)
    ) {
    /* Overwrite DDIV=1 (divide by 2), FASTDIV=5 (divide by 4) */
    if ((slice == 0) || slice == TEN_SLICE_ALL) {
        rtn |= ten_hsif_slc0_mr10x4_sds_common_srx0_rx_clkdiv_ctrl(module_id, TEN_INSTANCE_ALL, 1, 0xb);
        rtn |= ten_hsif_slc0_mr10x4_sds_common_stxp0_tx_clkdiv_ctrl(module_id, 1, 0x0a);
    }
    if ((slice == 1) || slice == TEN_SLICE_ALL) {
        rtn |= ten_hsif_slc1_mr10x5_sds_common_srx0_rx_clkdiv_ctrl(module_id, TEN_INSTANCE_ALL, 1, 0xb);
        rtn |= ten_hsif_slc1_mr10x5_sds_common_stxp0_tx_clkdiv_ctrl(module_id, 1, 0x0a);
    }
    if ((slice == 2) || slice == TEN_SLICE_ALL) {
        rtn |= ten_hsif_slc2_mr10x4_sds_common_srx0_rx_clkdiv_ctrl(module_id, TEN_INSTANCE_ALL, 1, 0xb);
        rtn |= ten_hsif_slc2_mr10x4_sds_common_stxp0_tx_clkdiv_ctrl(module_id, 1, 0x0a);
    }
    if ((slice == 3) || slice == TEN_SLICE_ALL) {
        rtn |= ten_hsif_slc3_mr10x5_sds_common_srx0_rx_clkdiv_ctrl(module_id, TEN_INSTANCE_ALL, 1, 0xb);
        rtn |= ten_hsif_slc3_mr10x5_sds_common_stxp0_tx_clkdiv_ctrl(module_id, 1, 0x0a);
    }
    rtn |= ten_gpllx1_set_stxp0_tx_ddiv_sel(dev_id, instance,   1);
    rtn |= ten_gpllx1_set_stxp0_tx_ddiv_sel(dev_id, instance+4, 1);
  }
  if ((line == TEN_TRAFFIC_TYPE_2GFC) ||
      (line == TEN_TRAFFIC_TYPE_CPRI_4)) {
    /* Overwrite DDIV=2 (divide by 4), SRX_FILTR=5, FASTDIV=6 (divide by 8) */
    if ((slice == 0) || slice == TEN_SLICE_ALL) {
        rtn |= ten_hsif_slc0_mr10x4_sds_common_srx0_rx_clkdiv_ctrl(module_id, TEN_INSTANCE_ALL, 2, 0xb);
        rtn |= ten_hsif_slc0_mr10x4_sds_common_stxp0_tx_clkdiv_ctrl(module_id, 2, 0x0a);
        rtn |= ten_hsif_slc0_mr10x4_sds_common_srx0_rx_loop_filter(module_id, TEN_INSTANCE_ALL, 5);
    }
    if ((slice == 1) || slice == TEN_SLICE_ALL) {
        rtn |= ten_hsif_slc1_mr10x5_sds_common_srx0_rx_clkdiv_ctrl(module_id, TEN_INSTANCE_ALL, 2, 0xb);
        rtn |= ten_hsif_slc1_mr10x5_sds_common_stxp0_tx_clkdiv_ctrl(module_id, 2, 0x0a);
        rtn |= ten_hsif_slc1_mr10x5_sds_common_srx0_rx_loop_filter(module_id, TEN_INSTANCE_ALL, 5);
    }
    if ((slice == 2) || slice == TEN_SLICE_ALL) {
        rtn |= ten_hsif_slc2_mr10x4_sds_common_srx0_rx_clkdiv_ctrl(module_id, TEN_INSTANCE_ALL, 2, 0xb);
        rtn |= ten_hsif_slc2_mr10x4_sds_common_stxp0_tx_clkdiv_ctrl(module_id, 2, 0x0a);
        rtn |= ten_hsif_slc2_mr10x4_sds_common_srx0_rx_loop_filter(module_id, TEN_INSTANCE_ALL, 5);
    }
    if ((slice == 3) || slice == TEN_SLICE_ALL) {
        rtn |= ten_hsif_slc3_mr10x5_sds_common_srx0_rx_clkdiv_ctrl(module_id, TEN_INSTANCE_ALL, 2, 0xb);
        rtn |= ten_hsif_slc3_mr10x5_sds_common_stxp0_tx_clkdiv_ctrl(module_id, 2, 0x0a);
        rtn |= ten_hsif_slc3_mr10x5_sds_common_srx0_rx_loop_filter(module_id, TEN_INSTANCE_ALL, 5);
    }
    rtn |= ten_gpllx1_set_stxp0_tx_ddiv_sel(dev_id, instance,   2);
    rtn |= ten_gpllx1_set_stxp0_tx_ddiv_sel(dev_id, instance+4, 2);
  }
  /* Bugzilla 39690 End */
  return (rtn);
}

/********************************************************************/
/* $rtn_hdr_start  HIGH LEVEL CONFIG SFI42 10G                      */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : HIGH LEVEL                                          */
/* CHIP       : Tenabo                                              */
cs_status ten_hl_config_sfi42_10g(cs_uint16 module_id,
                            cs_uint8 slice,
                            cs_uint16 line,
                            cs_uint32 sysclk_freq,
                            cs_uint16 sync,
                            cs_uint16 enhanced_deskew)
/* INPUTS     : o Module Id                                         */
/*              o Slice                                             */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Provides top-most level configuration of SFI4.2-10G.             */
/*                                                                  */
/* [slice]  Specified as TEN_SLICE0 (0), TEN_SLICE1 (1),            */
/*   TEN_SLICE2 (2), TEN_SLICE3 (3) or TEN_SLICE_ALL (0xFF)         */
/*                                                                  */
/* [sysclk_freq] parameter is specified as:                         */
/*   unused parameter (set to 0)                                    */
/*                                                                  */
/* [sync] parameter is specified as:                                */
/*   unused parameter (set to 0)                                    */
/*                                                                  */
/* [line] parameter is specified as:                                */
/*   unused parameter (set to 0)                                    */
/*                                                                  */
/* [enhanced deskew] parameter is specified as:                     */
/*   0 = do not use enhanced deskew                                 */
/*   1 = use enhanced deskew                                        */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  return (ten_hl_config_sfi42_10g_t41(module_id,
                                      slice,
                                      line,
                                      sysclk_freq,
                                      sync,
                                      enhanced_deskew,
                                      1,   /*internal_pilot, */
                                      0));  /*mr_protect      */
}

/********************************************************************/
/* $rtn_hdr_start  HIGH LEVEL HSIF CONFIG SFI42 10G                 */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : HIGH LEVEL                                          */
/* CHIP       : Tenabo                                              */
cs_status ten_hl_hsif_config_sfi42_10g(cs_uint16 module_id,
                                       cs_uint8 slice,
                                       cs_uint16 internal_pilot,
                                       cs_uint16 mr_protect)
/* INPUTS     : o Module Id                                         */
/*              o Slice                                             */
/*              o Internal Pilot                                    */
/*              o MR Protect                                        */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Configure HSIF SFI42 10G SERDES.                                 */
/*                                                                  */
/* [slice] Specified as TEN_SLICE0 (0), TEN_SLICE1 (1),             */
/*   TEN_SLICE2 (2) or TEN_SLICE3 (3).                              */
/*                                                                  */
/* [internal_pilot] parameter is specified as:                      */
/*   0 = do not use internal pilot                                  */
/*   1 = use internal pilot.                                        */
/*                                                                  */
/* [mr_protect] parameter is specified as:                          */
/*   0 = normal provisioning, tx output on                          */
/*   1 = use MR protect, tx output off                              */
/*   2 = normal provisioning, tx output off.                        */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  cs_uint16 val;
  cs_status rtn = CS_OK;
  cs_uint16 dev_id;

  CS_PRINT("ten_hl_hsif_config_sfi42_10g, slice=%d...\n", slice);
  
  dev_id = TEN_MOD_ID_TO_DEV_ID(module_id);
  
  /* Bugzilla #36263 - mpif reset for all hsif interface */
  rtn |= ten_mpif_global_reset_sds_mr_mpif(dev_id, TEN_MOD_ID_TO_MOD_NUM(module_id),
                                           slice, CS_RESET_TOGGLE);
                                           
  if ((mr_protect == 1) || (mr_protect == 2)) {            
    rtn |= ten_hl_hsif_control_mr_tx_output(module_id, slice, CS_DISABLE);
  }
  
  /* power up the SFI42 10G serdes */
  rtn |= ten_hl_hsif_powerdown_mr(module_id, slice, CS_DISABLE);

  /* Bugzilla 20745 */
  /* Reset the SDS in case the interface rate is changing during dynamic reconfig */
  rtn |= ten_mpif_global_reset_sds_mr(dev_id, module_id & 1, slice, CS_TX_AND_RX, CS_RESET_ASSERT);
  /* Bugzilla 20745 end */

  /* Bugzilla #30768, fix protection switch on same port */
  rtn |= ten_hsif_provision_datapath_t41(module_id, slice, 
                                         0,                              /* tx_pswtchen   */
                                         TEN_HSIF_PROTOCOL_SFI42_10G,    /* tx_mrprotocol */
                                         0,                              /* rx_pswtchen   */
                                         TEN_HSIF_PROTOCOL_SFI42_10G);   /* rx_mrprotocol */
       
  /* Bugzilla #31356, fix issues with xfiselect bits */
  if (mr_protect != 1) {
    if (TEN_MOD_ID_TO_MOD_NUM(module_id) == TEN_MODULE_B) {
      rtn |= ten_hsif_provision_tx_xfiselect(module_id, slice, 0);
      rtn |= ten_hsif_provision_rx_xfiselect(module_id, slice, 0);

      /* Bug #39428: Regression failures due to dynamic reconfig of XFI to SFI4.2 with BMP config */
      rtn |= ten_mpif_global_reset_sds_xfi(dev_id, slice, CS_TX_AND_RX, CS_RESET_ASSERT);
      rtn |= ten_xfi32x1_stxp0_tx_pwrdn_all(module_id, slice, 1);
      rtn |= ten_xfi32x1_stxp0_tx_pwrdn_pd_lane(module_id, slice, 0x1F);
      rtn |= ten_xfi32x1_srx0_rx_srx_pd(module_id, slice, 1);
      rtn |= ten_mpif_set_clock_switch_lockdet_xfi(dev_id, slice, CS_TX_AND_RX, CS_DISABLE);
    }
  }                                                                           

  if ((ten_mpif_get_chip_jtag_id(TEN_MOD_ID_TO_DEV_ID(module_id)) == TEN_CHIP_ID_CS6004) ||
      (ten_mpif_get_chip_jtag_id(TEN_MOD_ID_TO_DEV_ID(module_id)) == TEN_CHIP_ID_CS6044)) {
    if (TEN_MOD_ID_TO_MOD_NUM(module_id) == TEN_MODULE_B) {
      if  ((slice == TEN_SLICE0) || (slice == TEN_SLICE1)) {
      
       /* Bugzilla #30768, fix protection switch on same port */
       rtn |= ten_hsif_provision_datapath_t41(module_id, slice, 
                                              1,                              /* tx_pswtchen   */
                                              TEN_HSIF_PROTOCOL_SFI42_10G,    /* tx_mrprotocol */
                                              0,                              /* rx_pswtchen   */
                                              TEN_HSIF_PROTOCOL_SFI42_10G);   /* rx_mrprotocol */
      
        /* enable A side MR protocol */
        rtn |= ten_hsif_provision_datapath_t41(module_id & 0xFF00, slice, 
                                               1,                              /* tx_pswtchen   */
                                               TEN_HSIF_PROTOCOL_SFI42_10G,    /* tx_mrprotocol */
                                               1,                              /* rx_pswtchen   */
                                               TEN_HSIF_PROTOCOL_SFI42_10G);   /* rx_mrprotocol */
    }
  }
  }

  /* JAM MR ring oscillator fix */
  rtn |= ten_hl_hsif_mr_ring_oscillator_fix(module_id, slice);

  if (internal_pilot) {
     val = 0xb;
   }
   else {
     val = 0xa;
  }

  if ((slice == TEN_SLICE0) || (slice == TEN_SLICE_ALL)) {

    rtn |= ten_hsif_slc0_mr10x4_sds_common_stxp0_tx_clkout_ctrl_clkouten(module_id, 1);

     /* Choose fractional divider output as pilot tone */
     /* loptime_sel=0 (TX ref from local CLKREFP/N), pilot_sel=1 (0:CLKREF 1:AUXPILOTIN 2:AUXREFIN), buswidth=1 (10bit) */
    rtn |= ten_hsif_slc0_mr10x4_sds_common_stxp0_tx_config(module_id, 0, internal_pilot, 1);
    rtn |= ten_hsif_slc0_mr10x4_sds_common_srx0_rx_config(module_id, TEN_INSTANCE_ALL, 1);
    rtn |= ten_hsif_slc0_mr10x4_sds_common_srx0_rx_clkdiv_ctrl(module_id, TEN_INSTANCE_ALL, 0, val);
    rtn |= ten_hsif_slc0_mr10x4_sds_common_stxp0_tx_clkdiv_ctrl(module_id, 0, 0x0a);

     if (internal_pilot) {
       /* TX CTVDIV=div2 */
      rtn |=  ten_hsif_slc0_mr10x4_sds_common_stxp0_stxp_ctvdiv_sel(module_id, 1);
     }

     /* Force RX to lock to pilot tone */
    rtn |= ten_hsif_set_slc0_mr10x4_rxlockd0_force_lock(module_id, TEN_INSTANCE_ALL, 0, 1);
  }

  if ((slice == TEN_SLICE1) || (slice == TEN_SLICE_ALL)) {
    rtn |= ten_hsif_slc1_mr10x5_sds_common_stxp0_tx_clkout_ctrl_clkouten(module_id, 1);
    rtn |= ten_hsif_slc1_mr10x5_sds_common_stxp0_tx_config(module_id, 0, internal_pilot, 1);
    rtn |= ten_hsif_slc1_mr10x5_sds_common_srx0_rx_config(module_id, TEN_INSTANCE_ALL, 1);
    rtn |= ten_hsif_slc1_mr10x5_sds_common_srx0_rx_clkdiv_ctrl(module_id, TEN_INSTANCE_ALL, 0, val);
    rtn |= ten_hsif_slc1_mr10x5_sds_common_stxp0_tx_clkdiv_ctrl(module_id, 0, 0x0a);

     if (internal_pilot) {
       /* TX CTVDIV=div2 */
      rtn |= ten_hsif_slc1_mr10x5_sds_common_stxp0_stxp_ctvdiv_sel(module_id, 1);
     }
    
    /* Force RX to lock to pilot tone */
    rtn |= ten_hsif_set_slc1_mr10x5_rxlockd0_force_lock(module_id, TEN_INSTANCE_ALL, 0, 1);
  }

  if ((slice == TEN_SLICE2) || (slice == TEN_SLICE_ALL)) {
    rtn |= ten_hsif_slc2_mr10x4_sds_common_stxp0_tx_clkout_ctrl_clkouten(module_id, 1);
    rtn |= ten_hsif_slc2_mr10x4_sds_common_stxp0_tx_config(module_id, 0, internal_pilot, 1);
    rtn |= ten_hsif_slc2_mr10x4_sds_common_srx0_rx_config(module_id, TEN_INSTANCE_ALL, 1);

    rtn |= ten_hsif_slc2_mr10x4_sds_common_srx0_rx_clkdiv_ctrl(module_id, TEN_INSTANCE_ALL, 0, val);
    rtn |= ten_hsif_slc2_mr10x4_sds_common_stxp0_tx_clkdiv_ctrl(module_id, 0, 0x0a);

     if (internal_pilot) {
      /* TX CTVDIV=div2 */
      rtn |= ten_hsif_slc2_mr10x4_sds_common_stxp0_stxp_ctvdiv_sel(module_id, 1);
     }
    /* Force RX to lock to pilot tone */
    rtn |=  ten_hsif_set_slc2_mr10x4_rxlockd0_force_lock(module_id, TEN_INSTANCE_ALL, 0, 1);
  }

  if ((slice == TEN_SLICE3) || (slice == TEN_SLICE_ALL)) {
    rtn |= ten_hsif_slc3_mr10x5_sds_common_stxp0_tx_clkout_ctrl_clkouten(module_id, 1);
    rtn |= ten_hsif_slc3_mr10x5_sds_common_stxp0_tx_config(module_id, 0, internal_pilot, 1);
    rtn |= ten_hsif_slc3_mr10x5_sds_common_srx0_rx_config(module_id, TEN_INSTANCE_ALL, 1);
    rtn |= ten_hsif_slc3_mr10x5_sds_common_srx0_rx_clkdiv_ctrl(module_id, TEN_INSTANCE_ALL, 0, val);
    rtn |= ten_hsif_slc3_mr10x5_sds_common_stxp0_tx_clkdiv_ctrl(module_id, 0, 0x0a);

     if (internal_pilot) {
       /*  TX CTVDIV=div2 */
      rtn |= ten_hsif_slc3_mr10x5_sds_common_stxp0_stxp_ctvdiv_sel(module_id, 1);
     }
    /* Force RX to lock to pilot tone */
    rtn |= ten_hsif_set_slc3_mr10x5_rxlockd0_force_lock(module_id, TEN_INSTANCE_ALL, 0, 1);
  }

  /* tx40g_en = 0, rx40g_en = 0 */
  rtn |= ten_hsif_sfi42_global_config(module_id, 0, 0);
  /* xbusreorder = 0 */
  /* enabo_bf_write(DEV_ID,TEN_HSIF_SFI42_GLOBAL_CONFIG+$hsif_id*TEN_HSIF_STRIDE,0,2,2); */
  /* xbusreorder = 0 */
  /* enabo_bf_write(DEV_ID,TEN_HSIF_SFI42_GLOBAL_CONFIG+$hsif_id*TEN_HSIF_STRIDE,0,3,3); */
  rtn |= ten_hsif_sfi42_busreorder(module_id, CS_TX_AND_RX, 0);

  /* bugzilla #24278 */
  /* Bugzilla #27277 */
   /* bugzilla #24278 */
  if (mr_protect) {     
    /* Bugzilla #27593 Feature Request: MRA/B Tx Output Enable */
    rtn |= ten_hl_hsif_analog_cfg(module_id, slice, TEN_HSIF_PROTOCOL_SFI42_10G, TEN_HSIF_TIMING_MODE_LOCAL_MR_PROTECT);
  }
  else {
    rtn |= ten_hl_hsif_analog_cfg(module_id, slice, TEN_HSIF_PROTOCOL_SFI42_10G, TEN_HSIF_TIMING_MODE_LOCAL);
  }
  
  /* remove sds rx/tx reset  */
  rtn |= ten_mpif_global_reset_sds_mr(TEN_MOD_ID_TO_DEV_ID(module_id),
                               TEN_MOD_ID_TO_MOD_NUM(module_id),
                               slice, CS_TX_AND_RX, CS_RESET_DEASSERT);

  /* enable global clock for HSIF  */
  if (TEN_MOD_ID_TO_MOD_NUM(module_id) == TEN_MODULE_A) {
    rtn |= ten_mpif_global_clock_disable_mr_a(TEN_MOD_ID_TO_DEV_ID(module_id),
                                        slice, CS_TX_AND_RX, CS_ENABLE);
  }
  else {
    rtn |= ten_mpif_global_clock_disable_mr_b(TEN_MOD_ID_TO_DEV_ID(module_id),
                                        slice, CS_TX_AND_RX, CS_ENABLE);
    rtn |= ten_mpif_global_clock_disable_xfi_b(TEN_MOD_ID_TO_DEV_ID(module_id),
                                         slice, CS_TX_AND_RX, CS_ENABLE);
  }

  if (mr_protect != 1) {
    /* Select SERDES Clock out of HSIF */
    rtn |= ten_mpif_clock_select_hsif_out(TEN_MOD_ID_TO_DEV_ID(module_id),
                                 TEN_MOD_ID_TO_MOD_NUM(module_id),
                                 slice, CS_TX_AND_RX, 0);
  }
  else {
    rtn |= ten_mpif_clock_select_prot_per_slice(TEN_MOD_ID_TO_DEV_ID(module_id), 0,
                                                slice,
                                                CS_TX_AND_RX, 1);

    /* Bugzilla #30768, fix protection switch on same port */
    rtn |= ten_hsif_provision_datapath_t41(module_id, slice, 
                                           1,                              /* tx_pswtchen   */
                                           TEN_HSIF_PROTOCOL_SFI42_10G,    /* tx_mrprotocol */
                                           0,                              /* rx_pswtchen   */
                                           TEN_HSIF_PROTOCOL_SFI42_10G);   /* rx_mrprotocol */
                                           
    /* Bugzilla #31356, fix issues with xfiselect bits */
    if (TEN_MOD_ID_TO_MOD_NUM(module_id) == TEN_MODULE_B) {
      rtn |= ten_hsif_provision_tx_xfiselect(module_id, slice, 1);
      rtn |= ten_hsif_provision_rx_xfiselect(module_id, slice, 1);                                      
    }                                       
  }

  /* if (T40_6004 && ($slice==4 || $slice == 5)) { */
  if ((ten_mpif_get_chip_jtag_id(TEN_MOD_ID_TO_DEV_ID(module_id)) == TEN_CHIP_ID_CS6004) ||
      (ten_mpif_get_chip_jtag_id(TEN_MOD_ID_TO_DEV_ID(module_id)) == TEN_CHIP_ID_CS6044)) {
    if (TEN_MOD_ID_TO_MOD_NUM(module_id) == TEN_MODULE_B) {
      if  ((slice == TEN_SLICE0) || (slice == TEN_SLICE1)) {
        rtn |= ten_mpif_clock_select_hsif_out(TEN_MOD_ID_TO_DEV_ID(module_id),
                                    TEN_MOD_ID_TO_MOD_NUM(module_id),
                                    slice, CS_TX_AND_RX, 1);
        rtn |= ten_mpif_global_clock_disable_mr_a(TEN_MOD_ID_TO_DEV_ID(module_id), slice,
                                        CS_TX_AND_RX, CS_ENABLE);
        rtn |= ten_mpif_clock_select_hsif_out(TEN_MOD_ID_TO_DEV_ID(module_id),
                                    TEN_MODULE_A, slice, CS_TX_AND_RX, 1);
      }
    }
  }
  
  /* Bugzilla #20950, set threshold to 8 instead of default 32. */
  if (slice == TEN_SLICE_ALL) {
    rtn |= ten_hsif_sfi42_oos_threshold(module_id, TEN_INSTANCE_ALL, 8);
  }
  else {
    rtn |= ten_hsif_sfi42_oos_threshold(module_id, slice, 8);
  }

  /* Bugzilla #28764, remove resets simultaneously */
  if ((slice == TEN_SLICE0) || (slice == TEN_SLICE_ALL)) {
    rtn |= ten_hsif_reset(module_id, CS_RESET_DEASSERT, TEN_HSIF_RESET_TX_SFI42_0 | TEN_HSIF_RESET_RX_SFI42_0);
  }
  if ((slice == TEN_SLICE1) || (slice == TEN_SLICE_ALL)) {
    rtn |= ten_hsif_reset(module_id, CS_RESET_DEASSERT, TEN_HSIF_RESET_TX_SFI42_1 | TEN_HSIF_RESET_RX_SFI42_1);
  }
  if ((slice == TEN_SLICE2) || (slice == TEN_SLICE_ALL)) {
    rtn |= ten_hsif_reset(module_id, CS_RESET_DEASSERT, TEN_HSIF_RESET_TX_SFI42_2 | TEN_HSIF_RESET_RX_SFI42_2);
  }
  if ((slice == TEN_SLICE3) || (slice == TEN_SLICE_ALL)) {
    rtn |= ten_hsif_reset(module_id, CS_RESET_DEASSERT, TEN_HSIF_RESET_TX_SFI42_3 | TEN_HSIF_RESET_RX_SFI42_3);
  }

  CS_PRINT("ten_hl_hsif_config_sfi42_10g Complete, rtn=%s.\n", rtn == CS_OK ? "CS_OK" : "CS_ERROR");
  return (rtn);
}

/********************************************************************/
/* $rtn_hdr_start  HIGH LEVEL CONFIG SFI51 40G TRANSPONDER          */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : HIGH LEVEL                                          */
/* CHIP       : Tenabo                                              */
cs_status ten_hl_config_sfi51_40g_transponder(cs_uint16 module_id,
                                              cs_uint16 sync)
/* INPUTS     : o Module Id                                         */
/*              o Sync                                              */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Configure an SFI-5.1 interface for 40G transponder application.  */
/* Returns CS_ERROR if waitfor_vcotune fails.                       */
/* Only the needed GPLLs are powered on.                            */
/*                                                                  */
/* [sync] parameter is specified as:                                */
/*  TEN_MAP_AMP = 0x0000,                                           */
/*  TEN_MAP_BMP = 0x0001.                                           */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  cs_uint16 dev_id = TEN_MOD_ID_TO_DEV_ID(module_id);
  cs_uint16 ii;
  cs_uint16 instance;
  cs_status rtn = CS_OK;

  CS_PRINT("ten_hl_config_sfi51_40g_transponder: module_id = 0x%04X, sync=%d\n",
            module_id, sync);

  if (sync > TEN_MAP_BMP) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": invalid clk sync option");
    return (CS_ERROR);
  }
  
  ten_hl_hsif_config_sfi51(module_id, TEN_HSIF_CKREFDIV4, 0x1, 0);
  for (ii=0; ii<4; ii++) {
  
    /* Bugzilla #21799, check for CS_ERROR or not locked (0) */
    if (ten_hl_hsif_mr_waitfor_vcotune(module_id, ii) != 1) {
      /* Bugzilla 22973 Start */
      CS_PRINT("ten_hl_gpllx1_waitfor_vcotune FAILED first time");
      rtn |= CS_ERROR;
      /* Bugzilla 22973 End */
    }
  }

  if (TEN_MOD_ID_TO_MOD_NUM(module_id) == TEN_MODULE_A) {
    instance = 1;
  }
  else {
    instance = 9;
  }

  for (ii=0; ii<8; ii++) {
  
   if (sync == TEN_MAP_AMP) {
      if ((ii != 0) && (ii != 3) &&
          (ii != 4) && (ii != 7)) {
        CS_PRINT("gpllx #%d not needed for async 40g trans, power down.\n", ii);
        /* power down un-needed GPLLs */
        ten_hl_gpllx1_init(dev_id, instance + ii, TEN_HL_GPLL_MODE_DEFAULT, 1);
        continue;
      }
    }
  
    if (sync == TEN_MAP_BMP) {
      if ((ii != 0) && (ii != 4)) {
        CS_PRINT("gpllx #%d not needed for sync 40g trans, power down.\n", ii);
        /* power down un-needed GPLLs */
        ten_hl_gpllx1_init(dev_id, instance + ii, TEN_HL_GPLL_MODE_DEFAULT, 1);
        continue;
      }
    }
    
    ten_hl_gpllx1_init(dev_id, instance + ii, TEN_HL_GPLL_MODE_DEFAULT, 0x0 );
    
    /* Bugzilla #21799, check for CS_ERROR or not locked (0) */
    if (ten_hl_gpllx1_waitfor_vcotune(dev_id, instance + ii) != 1) {
      /* Bugzilla 22973 Start */
      CS_PRINT("ten_hl_gpllx1_waitfor_vcotune FAILED second time");
      rtn |= CS_ERROR;
      /* Bugzilla 22973 End */
    }
  }

  /* Bugzilla #25165, recommended to add a toggle of resync to the API. */
  rtn |= ten_hl_hsif_mr_resync(module_id, TEN_SLICE_ALL, CS_TX_AND_RX);

  return (rtn);
}

/********************************************************************/
/* $rtn_hdr_start  HIGH LEVEL CONFIG SFI51 T41                      */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : HIGH LEVEL                                          */
/* CHIP       : Tenabo                                              */
cs_status ten_hl_config_sfi51_t41(cs_uint16 module_id,
                                  cs_uint16 divider,
                                  cs_uint16 internal_pilot,
                                  cs_uint16 mr_protect)
/* INPUTS     : o Module Id                                         */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Configure HSIF SFI51 SERDES.                                     */
/*                                                                  */
/* [divider] parameter is specified as:                             */
/*   TEN_HSIF_CKREFDIV1 = 0,  (div1 to serdes)                      */
/*   TEN_HSIF_CKREFDIV2 = 1,  (div2 to serdes)                      */
/*   TEN_HSIF_CKREFDIV4 = 2   (div4 to serdes)                      */
/*                                                                  */
/* [internal_pilot] parameter is specified as:                      */
/*   0 = do not use internal pilot                                  */
/*   1 = use internal pilot.                                        */
/*                                                                  */
/* [mr_protect] parameter is specified as:                          */
/*   0 = normal provisioning, tx output on                          */
/*   1 = use MR protect, tx output off                              */
/*   2 = normal provisioning, tx output off.                        */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  cs_uint16 dev_id = TEN_MOD_ID_TO_DEV_ID(module_id);
  cs_uint16 ii;
  cs_uint16 instance;
  cs_status rtn = CS_OK;

  CS_PRINT("ten_hl_config_sfi51_t41:  mod=0x%04X, divider=%d, internal_pilot=%d, mr_protect=%d\n",
           module_id, divider, internal_pilot, mr_protect);

  /* config_clocks(module_id, 0, $line, $sysclk_freq, 64, 'sfi51', 0); */
  ten_hl_hsif_config_sfi51(module_id, divider, internal_pilot, mr_protect);
  for (ii=0; ii<4; ii++) {
  
    /* Bugzilla #21799, check for CS_ERROR or not locked (0) */
    if (ten_hl_hsif_mr_waitfor_vcotune(module_id, ii) != 1) {
      /* Bugzilla 22973 Start */
      CS_PRINT("ten_hl_gpllx1_waitfor_vcotune FAILED first time");
      rtn |= CS_ERROR;
      /* Bugzilla 22973 End */
    }
  }

  if ((module_id & 1) == TEN_MODULE_A) {
    instance = 1;
  }
  else {
    instance = 9;
  }

  for (ii=0; ii<8; ii++) {
    ten_hl_gpllx1_init(dev_id, instance + ii, TEN_HL_GPLL_MODE_DEFAULT, 0x0 );
    
    /* Bugzilla #21799, check for CS_ERROR or not locked (0) */
    if (ten_hl_gpllx1_waitfor_vcotune(dev_id, instance + ii) != 1) {
      /* Bugzilla 22973 Start */
      CS_PRINT("ten_hl_gpllx1_waitfor_vcotune FAILED second time");
      rtn |= CS_ERROR;
      /* Bugzilla 22973 End */
    }
  }

  /* Bugzilla #25165, recommended to add a toggle of resync to the API. */
  rtn |= ten_hl_hsif_mr_resync(module_id, TEN_SLICE_ALL, CS_TX_AND_RX);
  
  CS_PRINT("ten_hl_config_sfi51_t41 complete, rtn=%s", (rtn == CS_OK) ? "CS_OK" : "CS_ERROR");
  
  return (rtn);
}

/********************************************************************/
/* $rtn_hdr_start  HIGH LEVEL CONFIG SFI51                          */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : HIGH LEVEL                                          */
/* CHIP       : Tenabo                                              */
cs_status ten_hl_config_sfi51(cs_uint16 module_id)
/* INPUTS     : o Module Id                                         */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Configure an SFI-5.1 interface.                                  */
/* Returns CS_ERROR if waitfor_vcotune fails.                       */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  return (ten_hl_config_sfi51_t41(module_id, TEN_HSIF_CKREFDIV4, 1, 0));
}

/********************************************************************/
/* $rtn_hdr_start  HIGH LEVEL HSIF CONFIG SFI51                     */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : HIGH LEVEL                                          */
/* CHIP       : Tenabo                                              */
cs_status ten_hl_hsif_config_sfi51(cs_uint16 module_id,
                                   cs_uint16 divider,
                                   cs_uint16 internal_pilot,
                                   cs_uint16 mr_protect)
/* INPUTS     : o Module Id                                         */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Configure HSIF SFI51 SERDES.                                     */
/*                                                                  */
/* [divider] parameter is specified as:                             */
/*   TEN_HSIF_CKREFDIV1 = 0,  (div1 to serdes)                      */
/*   TEN_HSIF_CKREFDIV2 = 1,  (div2 to serdes)                      */
/*   TEN_HSIF_CKREFDIV4 = 2   (div4 to serdes)                      */
/*                                                                  */
/* [internal_pilot] parameter is specified as:                      */
/*   0 = do not use internal pilot                                  */
/*   1 = use internal pilot.                                        */
/*                                                                  */
/* [mr_protect] parameter is specified as:                          */
/*   0 = normal provisioning, tx output on                          */
/*   1 = use MR protect, tx output off                              */
/*   2 = normal provisioning, tx output off.                        */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  cs_uint16 val = 0;
  cs_status rtn = CS_OK;

  CS_PRINT("ten_hl_hsif_config_sfi51, divider=%d, internal_pilot=%d, mr_protect=%d\n", 
            divider, internal_pilot, mr_protect);

  /* Bugzilla #36263 - mpif reset for all hsif interface */
  rtn |= ten_mpif_global_reset_sds_mr_mpif(TEN_MOD_ID_TO_DEV_ID(module_id), TEN_MOD_ID_TO_MOD_NUM(module_id),
                                           TEN_SLICE_ALL, CS_RESET_TOGGLE);
                                                  
  if (mr_protect == 1) {            
    rtn |= ten_mpif_global_reset_hsif(TEN_MOD_ID_TO_DEV_ID(module_id),
                               TEN_MOD_ID_TO_MOD_NUM(module_id),
                               CS_TX_AND_RX, CS_RESET_ASSERT);
  }
        
  if ((mr_protect == 1) || (mr_protect == 2)) {            
    rtn |= ten_hl_hsif_control_mr_tx_output(module_id, TEN_SLICE_ALL, CS_DISABLE);
  }
        
  /* power up the MR serdes */
  rtn |= ten_hl_hsif_powerdown_mr(module_id, TEN_SLICE_ALL, CS_DISABLE);

  /* # SFI5CKREF (SFI5Pilot_sel=0,loopckel=0,ckrefdiv=2/1/0,spare=0xc) */
  if (divider == TEN_HSIF_CKREFDIV4) {
    /* ten_reg_write(DEV_ID,TEN_HSIF_PROTOCOL_REFCLK_CFG+$hsif_id*TEN_HSIF_STRIDE,0x2c); */
    rtn |= ten_hsif_set_refclk_cfg(module_id, TEN_HSIF_REFCLK_CFG_ALL, 0x2C);
  }
  else if (divider == TEN_HSIF_CKREFDIV2) {
    /* ten_reg_write(DEV_ID,TEN_HSIF_PROTOCOL_REFCLK_CFG+$hsif_id*TEN_HSIF_STRIDE,0x1c); */
    rtn |= ten_hsif_set_refclk_cfg(module_id, TEN_HSIF_REFCLK_CFG_ALL, 0x1C);
  }
  else if (divider == TEN_HSIF_CKREFDIV1) {
    /* ten_reg_write(DEV_ID,TEN_HSIF_PROTOCOL_REFCLK_CFG+$hsif_id*TEN_HSIF_STRIDE,0x0c); */
    rtn |= ten_hsif_set_refclk_cfg(module_id, TEN_HSIF_REFCLK_CFG_ALL, 0x0C);
  }
  else {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": Unsupported divider for SFI5");
  }

  /* Provision Datapath:  */
  if (mr_protect != 1) {
    /* Bugzilla #30768, fix protection switch on same port */
    rtn |= ten_hsif_provision_datapath_t41(module_id, TEN_INSTANCE_ALL, 
                                           0,                          /* tx_pswtchen   */
                                           TEN_HSIF_PROTOCOL_SFI51,    /* tx_mrprotocol */
                                           0,                          /* rx_pswtchen   */
                                           TEN_HSIF_PROTOCOL_SFI51);   /* rx_mrprotocol */
                                           
    /* Bugzilla #31356, fix issues with xfiselect bits */
    if (TEN_MOD_ID_TO_MOD_NUM(module_id) == TEN_MODULE_B) {
      rtn |= ten_hsif_provision_tx_xfiselect(module_id, TEN_SLICE_ALL, 0);
      rtn |= ten_hsif_provision_rx_xfiselect(module_id, TEN_SLICE_ALL, 0);                                      
    }                                    
                                           
  }
  else {
    /* rx_a2b */
    rtn |= ten_mpif_clock_select_prot(TEN_MOD_ID_TO_DEV_ID(module_id), 1, 1, 0xF, 0xF);
    /* Provision Datapath B: */
    rtn |= ten_hsif_provision_datapath_t41(module_id, TEN_INSTANCE_ALL, 
                                           1,                          /* tx_pswtchen   */
                                           TEN_HSIF_PROTOCOL_SFI51,    /* tx_mrprotocol */
                                           0,                          /* rx_pswtchen   */
                                           TEN_HSIF_PROTOCOL_SFI51);   /* rx_mrprotocol */
                                           
    /* Bugzilla #31356, fix issues with xfiselect bits */
    if (TEN_MOD_ID_TO_MOD_NUM(module_id) == TEN_MODULE_B) {
      rtn |= ten_hsif_provision_tx_xfiselect(module_id, TEN_SLICE_ALL, 1);
      rtn |= ten_hsif_provision_rx_xfiselect(module_id, TEN_SLICE_ALL, 1);                                      
    }                                       
  }

  /* JAM MR ring oscillator fix */
  rtn |= ten_hl_hsif_mr_ring_oscillator_fix(module_id, TEN_SLICE_ALL);
  
  /* RX DDIV=0 and RDIV=7 */
  if (internal_pilot) {
    val = 0x6;
  }
  else {
    val = 0x7;
  }
  rtn |= ten_hsif_slc0_mr10x4_sds_common_srx0_rx_clkdiv_ctrl(module_id, TEN_INSTANCE_ALL, 0, val);
  rtn |= ten_hsif_slc2_mr10x4_sds_common_srx0_rx_clkdiv_ctrl(module_id, TEN_INSTANCE_ALL, 0, val);
  rtn |= ten_hsif_slc1_mr10x5_sds_common_srx0_rx_clkdiv_ctrl(module_id, TEN_INSTANCE_ALL, 0, val);
  rtn |= ten_hsif_slc3_mr10x5_sds_common_srx0_rx_clkdiv_ctrl(module_id, TEN_INSTANCE_ALL, 0, val);

  if (internal_pilot) {
    /*  # RX CTVDIV=div2 */
    rtn |= ten_hsif_slc0_mr10x4_sds_common_srx0_srx_ctvdiv_sel(module_id, TEN_INSTANCE_ALL, 1);
    rtn |= ten_hsif_slc2_mr10x4_sds_common_srx0_srx_ctvdiv_sel(module_id, TEN_INSTANCE_ALL, 1);
    rtn |= ten_hsif_slc1_mr10x5_sds_common_srx0_srx_ctvdiv_sel(module_id, TEN_INSTANCE_ALL, 1);
    rtn |= ten_hsif_slc3_mr10x5_sds_common_srx0_srx_ctvdiv_sel(module_id, TEN_INSTANCE_ALL, 1);
  }

    /*  # TX DDIV=0 and RDIV=0xe */
  rtn |= ten_hsif_slc0_mr10x4_sds_common_stxp0_tx_clkdiv_ctrl(module_id, 0, 0xe);
  rtn |= ten_hsif_slc1_mr10x5_sds_common_stxp0_tx_clkdiv_ctrl(module_id, 0, 0xe);
  rtn |= ten_hsif_slc2_mr10x4_sds_common_stxp0_tx_clkdiv_ctrl(module_id, 0, 0xe);
  rtn |= ten_hsif_slc3_mr10x5_sds_common_stxp0_tx_clkdiv_ctrl(module_id, 0, 0xe);

  if (internal_pilot) {
    /*  # TX CTRDIV=div2 */
    rtn |= ten_hsif_slc0_mr10x4_sds_common_stxp0_stxp_ctrdiv_sel(module_id, 1);
    rtn |= ten_hsif_slc1_mr10x5_sds_common_stxp0_stxp_ctrdiv_sel(module_id, 1);
    rtn |= ten_hsif_slc2_mr10x4_sds_common_stxp0_stxp_ctrdiv_sel(module_id, 1);
    rtn |= ten_hsif_slc3_mr10x5_sds_common_stxp0_stxp_ctrdiv_sel(module_id, 1);
  }

  /*  # TX buswidth=0 & LPTIME_SEL=2 & PILOT_SEL=1 */
  if (internal_pilot) {
    rtn |= ten_hsif_slc0_mr10x4_sds_common_stxp0_tx_config(module_id, 2, 1, 0);
    rtn |= ten_hsif_slc1_mr10x5_sds_common_stxp0_tx_config(module_id, 2, 1, 0);
    rtn |= ten_hsif_slc2_mr10x4_sds_common_stxp0_tx_config(module_id, 2, 1, 0);
    rtn |= ten_hsif_slc3_mr10x5_sds_common_stxp0_tx_config(module_id, 2, 1, 0);
  }
  else {
    rtn |= ten_hsif_slc0_mr10x4_sds_common_stxp0_tx_config(module_id, 2, 2, 0);
    rtn |= ten_hsif_slc1_mr10x5_sds_common_stxp0_tx_config(module_id, 2, 2, 0);
    rtn |= ten_hsif_slc2_mr10x4_sds_common_stxp0_tx_config(module_id, 2, 2, 0);
    rtn |= ten_hsif_slc3_mr10x5_sds_common_stxp0_tx_config(module_id, 2, 2, 0);
  }

  /*  # RX buswidth=0  */
  rtn |= ten_hsif_slc0_mr10x4_sds_common_srx0_rx_config(module_id, TEN_INSTANCE_ALL, 0);
  rtn |= ten_hsif_slc1_mr10x5_sds_common_srx0_rx_config(module_id, TEN_INSTANCE_ALL, 0);
  rtn |= ten_hsif_slc2_mr10x4_sds_common_srx0_rx_config(module_id, TEN_INSTANCE_ALL, 0);
  rtn |= ten_hsif_slc3_mr10x5_sds_common_srx0_rx_config(module_id, TEN_INSTANCE_ALL, 0);

  /*  # Force RX to lock to pilot tone */
  rtn |= ten_hsif_set_slc0_mr10x4_rxlockd0_force_lock(module_id, TEN_INSTANCE_ALL, 0, 1);
  rtn |= ten_hsif_set_slc2_mr10x4_rxlockd0_force_lock(module_id, TEN_INSTANCE_ALL, 0, 1);

  /*  #for(my $i=0; $i<5; $i++) { */
  rtn |= ten_hsif_set_slc1_mr10x5_rxlockd0_force_lock(module_id, TEN_INSTANCE_ALL, 0, 1);
  rtn |= ten_hsif_set_slc3_mr10x5_rxlockd0_force_lock(module_id, TEN_INSTANCE_ALL, 0, 1);

  if (mr_protect) {     
    rtn |= ten_hl_hsif_analog_cfg(module_id, TEN_SLICE_ALL, TEN_HSIF_PROTOCOL_SFI51, TEN_HSIF_TIMING_MODE_LOCAL_MR_PROTECT);
  }
  else {
    rtn |= ten_hl_hsif_analog_cfg(module_id, TEN_SLICE_ALL, TEN_HSIF_PROTOCOL_SFI51, TEN_HSIF_TIMING_MODE_LOCAL);
  }
  
  /*  # remove sds rx/tx reset  */
  rtn |= ten_mpif_global_reset_sds_mr(TEN_MOD_ID_TO_DEV_ID(module_id),
                               TEN_MOD_ID_TO_MOD_NUM(module_id),
                               TEN_SLICE_ALL, CS_TX_AND_RX, CS_RESET_DEASSERT);

  if (TEN_MOD_ID_TO_MOD_NUM(module_id) == TEN_MODULE_A) {
     rtn |= ten_mpif_global_clock_disable_mr_a(TEN_MOD_ID_TO_DEV_ID(module_id),
                                        TEN_SLICE_ALL, CS_TX_AND_RX, CS_ENABLE);
  }
  else {
    rtn |= ten_mpif_global_clock_disable_mr_b(TEN_MOD_ID_TO_DEV_ID(module_id),
                                        TEN_SLICE_ALL, CS_TX_AND_RX, CS_ENABLE);
    /* Bugzilla #26742, fix backplane protection */
    /* Bugzilla 26778 */
    rtn |= ten_mpif_global_clock_disable_xfi_b(TEN_MOD_ID_TO_DEV_ID(module_id),
                                         TEN_SLICE_ALL, CS_TX_AND_RX, CS_ENABLE);
  }  
  /*  enable sfi5 */
  rtn |= ten_hsif_reset(module_id, CS_RESET_DEASSERT, TEN_HSIF_RESET_TX_SFI5 | TEN_HSIF_RESET_RX_SFI5);
  
  if (mr_protect != 1) {
    /* Select SERDES Clock out of HSIF */
    rtn |= ten_mpif_clock_select_hsif_out(TEN_MOD_ID_TO_DEV_ID(module_id),
                                   TEN_MOD_ID_TO_MOD_NUM(module_id),
                                   TEN_SLICE_ALL, CS_TX_AND_RX, 0);
  }
  
  if (mr_protect == 1) {            
    rtn |= ten_mpif_global_reset_hsif(TEN_MOD_ID_TO_DEV_ID(module_id),
                               TEN_MOD_ID_TO_MOD_NUM(module_id),
                               CS_TX_AND_RX, CS_RESET_DEASSERT);
  }
  
  CS_PRINT("ten_hl_hsif_config_sfi51 Complete, rtn=%s.\n", (rtn == CS_OK) ? "CS_OK" : "CS_ERROR");

  return (rtn);
}

/********************************************************************/
/* $rtn_hdr_start  HIGH LEVEL CONFIG XAUI                           */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : HIGH LEVEL                                          */
/* CHIP       : Tenabo                                              */
cs_status ten_hl_config_xaui(cs_uint16 module_id,
                             cs_uint8 slice,
                             cs_uint16 internal_pilot,
                             cs_uint16 mr_protect)
/* INPUTS     : o Module Id                                         */
/*              o Slice                                             */
/*              o Use internal pilot                                */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Configure HSIF XAUI SERDES and GPLLX1.                           */
/*                                                                  */
/* [slice] Specified as TEN_SLICE0 (0), TEN_SLICE1 (1),             */
/*   TEN_SLICE2 (2), TEN_SLICE3 (3), or TEN_SLICE_ALL (0xFF).       */
/*                                                                  */
/* [internal_pilot] parameter is specified as:                      */
/*   0 = do not use internal pilot                                  */
/*   1 = use internal pilot.                                        */
/*                                                                  */
/* [mr_protect] parameter is specified as:                          */
/*   0 = normal provisioning, tx output on                          */
/*   1 = use MR protect, tx output off                              */
/*   2 = normal provisioning, tx output off                         */
/*   3 = MR protect, tx output on, perform the switch to side B.    */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  cs_uint16 dev_id = TEN_MOD_ID_TO_DEV_ID(module_id);
  cs_status rtn = CS_OK;
  cs_uint16 instance = 0;
  cs_uint16 gpll_mode;
  cs_uint16 mod_id_b;
  cs_uint16 mod_id_a;
  cs_uint16 xaui_mod_id;
  
  CS_PRINT("ten_hl_config_xaui:  ");
  CS_PRINT("mod_id=0x%04X, sl=%d, internal_pilot=%d, mr_protect=%d\n",
            module_id, slice, internal_pilot, mr_protect);
        
  mod_id_b = (dev_id << 8) | TEN_MODULE_B;
  mod_id_a = (dev_id << 8) | TEN_MODULE_A;
  
  if (mr_protect == 3) {
    /* protection switching, datapath is on side A, but HSIF is on side B */
    xaui_mod_id = mod_id_b;
  }
  else {
    xaui_mod_id = module_id;
  }

  rtn |= ten_hl_hsif_config_xaui(xaui_mod_id, slice, internal_pilot, mr_protect);
  if (rtn != CS_OK) {
    CS_PRINT("ten_hl_hsif_config_xaui FAILURE\n");
  }
                                 
  if (ten_hl_hsif_mr_waitfor_vcotune(xaui_mod_id, slice) != 1) {
    CS_PRINT("ten_hl_hsif_mr_waitfor_vcotune FAILURE\n");
    rtn |= CS_ERROR;
  }
  
  if (mr_protect == 3) {
    /* use GPLL A for xaui protection mode */
    instance = slice + 1;
  }
  else if ((TEN_MOD_ID_TO_MOD_NUM(module_id)) == TEN_MODULE_B) {
    instance = slice + 9;
  }
  else {
    instance = slice + 1;
  }

  gpll_mode = TEN_HL_GPLL_MODE_DEFAULT;
  ten_hl_gpllx1_init(dev_id, instance, gpll_mode, 0);

  if (ten_hl_gpllx1_waitfor_vcotune(dev_id, instance) != 1) {
    CS_PRINT("ten_hl_gpllx1_waitfor_vcotune inst=%d FAILED\n", instance);
    rtn |= CS_ERROR;
  }

  ten_hl_gpllx1_init(dev_id, instance+4, gpll_mode, 0);
  if (ten_hl_gpllx1_waitfor_vcotune(dev_id, instance+4) != 1) {
    CS_PRINT("ten_hl_gpllx1_waitfor_vcotune inst+4=%d FAILED\n", instance+4);
    rtn |= CS_ERROR;
  }

  /* Bugzilla #25165, recommended to add a toggle of resync to the API. */
  rtn |= ten_hl_hsif_mr_resync(xaui_mod_id, slice, CS_TX_AND_RX);
  
  CS_PRINT("ten_hl_config_xaui complete, rtn=%s.\n", 
           (rtn == CS_OK) ? "CS_OK" : "CS_ERROR");
  
  return (rtn);
}

/********************************************************************/
/* $rtn_hdr_start  HIGH LEVEL HSIF CONFIG XAUI                      */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : HIGH LEVEL                                          */
/* CHIP       : Tenabo                                              */
cs_status ten_hl_hsif_config_xaui(cs_uint16 module_id,
                                  cs_uint8 slice,
                                  cs_uint16 internal_pilot,
                                  cs_uint16 mr_protect)
/* INPUTS     : o Module Id                                         */
/*              o Slice                                             */
/*              o use internal pilot                                */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Configure HSIF XAUI SERDES.                                      */
/*                                                                  */
/* [slice] Specified as TEN_SLICE0 (0), TEN_SLICE1 (1),             */
/*   TEN_SLICE2 (2), TEN_SLICE3 (3), or TEN_SLICE_ALL (0xFF).       */
/*                                                                  */
/* [internal_pilot] parameter is specified as:                      */
/*   0 = do not use internal pilot                                  */
/*   1 = use internal pilot.                                        */
/*                                                                  */
/* [mr_protect] parameter is specified as:                          */
/*   0 = normal provisioning, tx output on                          */
/*   1 = use MR protect, tx output off                              */
/*   2 = normal provisioning, tx output off                         */
/*   3 = MR protect, tx output on, perform the switch to side B.    */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  cs_uint16 rx_a2b, tx_a2b;
  cs_uint16 val;
  cs_status rtn = CS_OK;
  cs_uint16 mod_id_b;
  cs_uint16 mod_id_a;
  cs_uint16 dev_id = TEN_MOD_ID_TO_DEV_ID(module_id);
  
  CS_PRINT("ten_hl_hsif_config_xaui:  ");
  CS_PRINT("mod_id=0x%04X, sl=%d, internal_pilot=%d, mr_protect=%d\n",
            module_id, slice, internal_pilot, mr_protect);
      
  mod_id_b = (dev_id << 8) | TEN_MODULE_B;
  mod_id_a = (dev_id << 8) | TEN_MODULE_A;
      
  /* Bugzilla #36263 - mpif reset for all hsif interface */
  rtn |= ten_mpif_global_reset_sds_mr_mpif(TEN_MOD_ID_TO_DEV_ID(module_id), TEN_MOD_ID_TO_MOD_NUM(module_id),
                                           slice, CS_RESET_TOGGLE);
      
  if ((mr_protect == 1) || (mr_protect == 2)) {            
    rtn |= ten_hl_hsif_control_mr_tx_output(module_id, slice, CS_DISABLE);
  }
  
  /* power up the MR serdes */
  rtn |= ten_hl_hsif_powerdown_mr(module_id, slice, CS_DISABLE);

  if ((ten_mpif_get_chip_jtag_id(TEN_MOD_ID_TO_DEV_ID(module_id)) == TEN_CHIP_ID_CS6004) ||
      (ten_mpif_get_chip_jtag_id(TEN_MOD_ID_TO_DEV_ID(module_id)) == TEN_CHIP_ID_CS6044)) {
    if (TEN_MOD_ID_TO_MOD_NUM(module_id) == TEN_MODULE_B) {
      if  ((slice == TEN_SLICE0) || (slice == TEN_SLICE1)) {
        /* Bugzilla #30768, fix protection switch on same port */
        rtn |= ten_hsif_provision_datapath_t41(module_id, slice, 
                                               1,                          /* tx_pswtchen   */
                                               TEN_HSIF_PROTOCOL_XAUI,     /* tx_mrprotocol */
                                               0,                          /* rx_pswtchen   */
                                               TEN_HSIF_PROTOCOL_XAUI);    /* rx_mrprotocol */

        /* # enable A side MR protocol */
         rtn |= ten_hsif_provision_datapath_t41(module_id & TEN_MODULE_A, slice, 
                                                0,                          /* tx_pswtchen   */
                                                TEN_HSIF_PROTOCOL_XAUI,     /* tx_mrprotocol */
                                                1,                          /* rx_pswtchen   */
                                                TEN_HSIF_PROTOCOL_XAUI);    /* rx_mrprotocol */
      }
    }
  }
  else {
    /* Provision Datapath: (Not CS6004/CS6044) */
    if (mr_protect == 1) {
      /* partially set up protection for later switching */
      rx_a2b = ten_mpif_get_clock_select_prot(TEN_MOD_ID_TO_DEV_ID(module_id), CS_RX) ;
      rx_a2b |= 1 << slice;
      tx_a2b = ten_mpif_get_clock_select_prot(TEN_MOD_ID_TO_DEV_ID(module_id), CS_TX);
      tx_a2b |= 1 << slice;
      ten_mpif_clock_select_prot(TEN_MOD_ID_TO_DEV_ID(module_id), 0, 0, tx_a2b, rx_a2b);

      rtn |= ten_hsif_provision_datapath_t41(mod_id_b, slice, 
                                             1,                          /* tx_pswtchen   */
                                             TEN_HSIF_PROTOCOL_XAUI,     /* tx_mrprotocol */
                                             0,                          /* rx_pswtchen   */
                                             TEN_HSIF_PROTOCOL_XAUI);    /* rx_mrprotocol */ 
                                             
      /* Bugzilla #31356, fix issues with xfiselect bits */
      rtn |= ten_hsif_provision_tx_xfiselect(mod_id_b, slice, 1);
      rtn |= ten_hsif_provision_rx_xfiselect(mod_id_b, slice, 1);                                      
    }
    else if (mr_protect == 3) {
      /* enable protection switch now */
      
      /* Setup side A GPLL input takes output from MRB */
      rtn |= ten_mpif_clock_select_hsif_out(dev_id, 0, slice, CS_TX_AND_RX, 1);
     
      /* Setup side B MR takes output from GPLL A */
      rtn |= ten_mpif_clock_select_prot_per_slice(dev_id, 0, slice, CS_TX_AND_RX, 1);
      
      rtn |= ten_mpif_clock_select_pilot_per_slice(dev_id, slice, 1);

      rtn |= ten_hsif_provision_datapath(mod_id_b, slice, 
                                         1,                          /* tx_xfiselect */
                                         1,                          /* rx_xfiselect */
                                         1,                          /* tx_pswtchen   */
                                         TEN_HSIF_PROTOCOL_XAUI,     /* tx_mrprotocol */
                                         0,                          /* rx_pswtchen   */
                                         TEN_HSIF_PROTOCOL_XAUI);    /* rx_mrprotocol */  
                                             
      rtn |= ten_hsif_provision_datapath(mod_id_a, slice, 
                                         0,                          /* tx_xfiselect */
                                         0,                          /* rx_xfiselect */
                                         0,                          /* tx_pswtchen   */
                                         TEN_HSIF_PROTOCOL_XAUI,     /* tx_mrprotocol */
                                         1,                          /* rx_pswtchen   */
                                         TEN_HSIF_PROTOCOL_XAUI);    /* rx_mrprotocol */ 
                                               
      /* Bugzilla #31356, fix issues with xfiselect bits */
      rtn |= ten_hsif_provision_tx_xfiselect(mod_id_b, slice, 1);
      rtn |= ten_hsif_provision_rx_xfiselect(mod_id_b, slice, 1);     
      
      rtn |= ten_hsif_pswtch_ok_ctrl_xlos_en(mod_id_b, slice, 0);
    }
    else {
      /* Normal provisioning */
      rtn |= ten_hsif_provision_datapath_t41(module_id, slice, 
                                             0,                          /* tx_pswtchen   */
                                             TEN_HSIF_PROTOCOL_XAUI,     /* tx_mrprotocol */
                                             0,                          /* rx_pswtchen   */
                                             TEN_HSIF_PROTOCOL_XAUI);    /* rx_mrprotocol */
                                             
      /* Bugzilla #31356, fix issues with xfiselect bits */
      if (TEN_MOD_ID_TO_MOD_NUM(module_id) == TEN_MODULE_B) {
        rtn |= ten_hsif_provision_tx_xfiselect(mod_id_b, slice, 0);
        rtn |= ten_hsif_provision_rx_xfiselect(mod_id_b, slice, 0); 

        /* Bug #39428: Regression failures due to dynamic reconfig of XFI to SFI4.2 with BMP config */
        rtn |= ten_mpif_global_reset_sds_xfi(dev_id, slice, CS_TX_AND_RX, CS_RESET_ASSERT);
        rtn |= ten_xfi32x1_stxp0_tx_pwrdn_all(module_id, slice, 1);
        rtn |= ten_xfi32x1_stxp0_tx_pwrdn_pd_lane(module_id, slice, 0x1F);
        rtn |= ten_xfi32x1_srx0_rx_srx_pd(module_id, slice, 1);
        rtn |= ten_mpif_set_clock_switch_lockdet_xfi(dev_id, slice, CS_TX_AND_RX, CS_DISABLE);
      }
    }
  }

  /* # JAM MR ring oscillator fix */
  rtn |= ten_hl_hsif_mr_ring_oscillator_fix(module_id, slice);

  /*  # RX DDIV=0 and RDIV=1 */
  if (internal_pilot) {
    val = 0;
  }
  else {
    val = 1;
  }

  if ((slice == TEN_SLICE0) || (slice == TEN_SLICE_ALL)) {
    rtn |= ten_hsif_slc0_mr10x4_sds_common_srx0_rx_clkdiv_ctrl(module_id, TEN_INSTANCE_ALL, 0, val);
  }
  if ((slice == TEN_SLICE1) || (slice == TEN_SLICE_ALL)) {
    rtn |= ten_hsif_slc1_mr10x5_sds_common_srx0_rx_clkdiv_ctrl(module_id, TEN_INSTANCE_ALL, 0, val);
  }
  if ((slice == TEN_SLICE2) || (slice == TEN_SLICE_ALL)) {
    rtn |= ten_hsif_slc2_mr10x4_sds_common_srx0_rx_clkdiv_ctrl(module_id, TEN_INSTANCE_ALL, 0, val);
  }
  if ((slice == TEN_SLICE3) || (slice == TEN_SLICE_ALL)) {
    rtn |= ten_hsif_slc3_mr10x5_sds_common_srx0_rx_clkdiv_ctrl(module_id, TEN_INSTANCE_ALL, 0, val);
  }
  if (internal_pilot) {
    /*    # RX CTVDIV=div2 */
    /*    #for(my $i=0; $i<4; $i++) { */
    /*    #  if ($slice==0) {tenabo_bf_write(DEV_ID,TEN_HSIF_MR_SLC0_MR10X4_SDS_COMMON_SRX0_RX_CLKDIV_CTRL+$hsif_id*TEN_HSIF_STRIDE+$i*TEN_HSIF_MR_SLC0_MR10X4_SDS_COMMON_SRX0_RX_CLKDIV_CTRL_STRIDE,1,9,8);} */
    /*    #  if ($slice==2) {tenabo_bf_write(DEV_ID,TEN_HSIF_MR_SLC2_MR10X4_SDS_COMMON_SRX0_RX_CLKDIV_CTRL+$hsif_id*TEN_HSIF_STRIDE+$i*TEN_HSIF_MR_SLC0_MR10X4_SDS_COMMON_SRX0_RX_CLKDIV_CTRL_STRIDE,1,9,8);} */
    /*    #} */
    if ((slice == TEN_SLICE0) || (slice == TEN_SLICE_ALL)) {
      rtn |= ten_hsif_slc0_mr10x4_sds_common_srx0_srx_ctvdiv_sel(module_id, TEN_INSTANCE_ALL, 1);
    }
    if ((slice == TEN_SLICE2) || (slice == TEN_SLICE_ALL)) {
      rtn |= ten_hsif_slc2_mr10x4_sds_common_srx0_srx_ctvdiv_sel(module_id, TEN_INSTANCE_ALL, 1);
    }
    /*    #for(my $i=0; $i<5; $i++) { */
    /*    #  if ($slice==1) {tenabo_bf_write(DEV_ID,TEN_HSIF_MR_SLC1_MR10X5_SDS_COMMON_SRX0_RX_CLKDIV_CTRL+$hsif_id*TEN_HSIF_STRIDE+$i*TEN_HSIF_MR_SLC0_MR10X4_SDS_COMMON_SRX0_RX_CLKDIV_CTRL_STRIDE,1,9,8);} */
    /*    #  if ($slice==3) {tenabo_bf_write(DEV_ID,TEN_HSIF_MR_SLC3_MR10X5_SDS_COMMON_SRX0_RX_CLKDIV_CTRL+$hsif_id*TEN_HSIF_STRIDE+$i*TEN_HSIF_MR_SLC0_MR10X4_SDS_COMMON_SRX0_RX_CLKDIV_CTRL_STRIDE,1,9,8);} */
    /*    #} */
    if ((slice == TEN_SLICE1) || (slice == TEN_SLICE_ALL)) {
      rtn |= ten_hsif_slc1_mr10x5_sds_common_srx0_srx_ctvdiv_sel(module_id, TEN_INSTANCE_ALL, 1);
    }
    if ((slice == TEN_SLICE3) || (slice == TEN_SLICE_ALL)) {
      rtn |= ten_hsif_slc3_mr10x5_sds_common_srx0_srx_ctvdiv_sel(module_id, TEN_INSTANCE_ALL, 1);
    }
  }

  /*  # TX DDIV=0 and RDIV=0x1 */
  if ((slice == TEN_SLICE0) || (slice == TEN_SLICE_ALL)) {
    rtn |= ten_hsif_slc0_mr10x4_sds_common_stxp0_tx_clkdiv_ctrl(module_id, 0, 0x1);
  }
  if ((slice == TEN_SLICE1) || (slice == TEN_SLICE_ALL)) {
    rtn |= ten_hsif_slc1_mr10x5_sds_common_stxp0_tx_clkdiv_ctrl(module_id, 0, 0x1);
  }
  if ((slice == TEN_SLICE2) || (slice == TEN_SLICE_ALL)) {
    rtn |= ten_hsif_slc2_mr10x4_sds_common_stxp0_tx_clkdiv_ctrl(module_id, 0, 0x1);
  }
  if ((slice == TEN_SLICE3) || (slice == TEN_SLICE_ALL)) {
    rtn |= ten_hsif_slc3_mr10x5_sds_common_stxp0_tx_clkdiv_ctrl(module_id, 0, 0x1);
  }

  if (internal_pilot) {
    /*  # TX CTRDIV=div2 */
    if ((slice == TEN_SLICE0) || (slice == TEN_SLICE_ALL)) {
      rtn |= ten_hsif_slc0_mr10x4_sds_common_stxp0_stxp_ctrdiv_sel(module_id, 1);
    }
    if ((slice == TEN_SLICE1) || (slice == TEN_SLICE_ALL)) {
      rtn |= ten_hsif_slc1_mr10x5_sds_common_stxp0_stxp_ctrdiv_sel(module_id, 1);
    }
    if ((slice == TEN_SLICE2) || (slice == TEN_SLICE_ALL)) {
      rtn |= ten_hsif_slc2_mr10x4_sds_common_stxp0_stxp_ctrdiv_sel(module_id, 1);
    }
    if ((slice == TEN_SLICE3) || (slice == TEN_SLICE_ALL)) {
      rtn |= ten_hsif_slc3_mr10x5_sds_common_stxp0_stxp_ctrdiv_sel(module_id, 1);
    }
  }

  /*  # TX LPTIME_SEL=0 & PILOT_SEL=1 & buswidth=1 */
  if ((slice == TEN_SLICE0) || (slice == TEN_SLICE_ALL)) {
    rtn |= ten_hsif_slc0_mr10x4_sds_common_stxp0_tx_config(module_id, 0, internal_pilot, 1);
  }
  if ((slice == TEN_SLICE1) || (slice == TEN_SLICE_ALL)) {
    rtn |= ten_hsif_slc1_mr10x5_sds_common_stxp0_tx_config(module_id, 0, internal_pilot, 1);
  }
  if ((slice == TEN_SLICE2) || (slice == TEN_SLICE_ALL)) {
    rtn |= ten_hsif_slc2_mr10x4_sds_common_stxp0_tx_config(module_id, 0, internal_pilot, 1);
  }
  if ((slice == TEN_SLICE3) || (slice == TEN_SLICE_ALL)) {
    rtn |= ten_hsif_slc3_mr10x5_sds_common_stxp0_tx_config(module_id, 0, internal_pilot, 1);
  }

  /*  # RX buswidth=1  */
  if ((slice == TEN_SLICE0) || (slice == TEN_SLICE_ALL)) {
    rtn |= ten_hsif_slc0_mr10x4_sds_common_srx0_rx_config(module_id, TEN_INSTANCE_ALL, 1);
  }
  if ((slice == TEN_SLICE1) || (slice == TEN_SLICE_ALL)) {
    rtn |= ten_hsif_slc1_mr10x5_sds_common_srx0_rx_config(module_id, TEN_INSTANCE_ALL, 1);
  }
  if ((slice == TEN_SLICE2) || (slice == TEN_SLICE_ALL)) {
    rtn |= ten_hsif_slc2_mr10x4_sds_common_srx0_rx_config(module_id, TEN_INSTANCE_ALL, 1);
  }
  if ((slice == TEN_SLICE3) || (slice == TEN_SLICE_ALL)) {
    rtn |= ten_hsif_slc3_mr10x5_sds_common_srx0_rx_config(module_id, TEN_INSTANCE_ALL, 1);
  }

  if ((slice == TEN_SLICE0) || (slice == TEN_SLICE_ALL)) {
    rtn |= ten_hsif_set_slc0_mr10x4_rxlockd0_force_lock(module_id, TEN_INSTANCE_ALL, 0, 1);
  }
  if ((slice == TEN_SLICE1) || (slice == TEN_SLICE_ALL)) {
    rtn |= ten_hsif_set_slc1_mr10x5_rxlockd0_force_lock(module_id, TEN_INSTANCE_ALL, 0, 1);
  }
  if ((slice == TEN_SLICE2) || (slice == TEN_SLICE_ALL)) {
    rtn |= ten_hsif_set_slc2_mr10x4_rxlockd0_force_lock(module_id, TEN_INSTANCE_ALL, 0, 1);
  }
  if ((slice == TEN_SLICE3) || (slice == TEN_SLICE_ALL)) {
    rtn |= ten_hsif_set_slc3_mr10x5_rxlockd0_force_lock(module_id, TEN_INSTANCE_ALL, 0, 1);
  }

  /* bugzilla #24278 */
  /* Bugzilla #27277 */
  if ((mr_protect == 1) || (mr_protect == 2)) {            
    /* Bugzilla #27593 Feature Request: MRA/B Tx Output Enable */
    rtn |= ten_hl_hsif_analog_cfg(module_id, slice, TEN_HSIF_PROTOCOL_XAUI, TEN_HSIF_TIMING_MODE_LOCAL_MR_PROTECT);
  }
  else {
    rtn |= ten_hl_hsif_analog_cfg(module_id, slice, TEN_HSIF_PROTOCOL_XAUI, TEN_HSIF_TIMING_MODE_LOCAL);
  }
  
  /*  # remove sds rx/tx reset  */
  rtn |= ten_mpif_global_reset_sds_mr(TEN_MOD_ID_TO_DEV_ID(module_id),
                               TEN_MOD_ID_TO_MOD_NUM(module_id), slice,
                               CS_TX_AND_RX, CS_RESET_DEASSERT);

  /*  # enable global clock for HSIF  */
  if (TEN_MOD_ID_TO_MOD_NUM(module_id) == TEN_MODULE_A) {
    rtn |= ten_mpif_global_clock_disable_mr_a(TEN_MOD_ID_TO_DEV_ID(module_id),
                                       slice, CS_TX_AND_RX, CS_ENABLE);
  }
  else {
     rtn |= ten_mpif_global_clock_disable_mr_b(TEN_MOD_ID_TO_DEV_ID(module_id),
                                        slice, CS_TX_AND_RX, CS_ENABLE);
     rtn |= ten_mpif_global_clock_disable_xfi_b(TEN_MOD_ID_TO_DEV_ID(module_id),
                                         slice, CS_TX_AND_RX, CS_ENABLE);
  }

  if (mr_protect == 3) {
    rtn |= ten_mpif_global_clock_disable_mr_a(TEN_MOD_ID_TO_DEV_ID(module_id),
                                              slice, CS_TX_AND_RX, CS_ENABLE);
  }
  
  if ((mr_protect != 1) && (mr_protect != 3)) {
    rtn |= ten_mpif_clock_select_hsif_out(TEN_MOD_ID_TO_DEV_ID(module_id),
                                          TEN_MOD_ID_TO_MOD_NUM(module_id), slice,
                                          CS_TX_AND_RX, 0);
  }

  if ((ten_mpif_get_chip_jtag_id(TEN_MOD_ID_TO_DEV_ID(module_id)) == TEN_CHIP_ID_CS6004) ||
      (ten_mpif_get_chip_jtag_id(TEN_MOD_ID_TO_DEV_ID(module_id)) == TEN_CHIP_ID_CS6044)) {
    if (TEN_MOD_ID_TO_MOD_NUM(module_id) == TEN_MODULE_B) {
      if  ((slice == TEN_SLICE0) || (slice == TEN_SLICE1)) {
        rtn |= ten_mpif_clock_select_hsif_out(TEN_MOD_ID_TO_DEV_ID(module_id),
                                      TEN_MOD_ID_TO_MOD_NUM(module_id),
                                      slice, CS_TX_AND_RX, 1);
        rtn |= ten_mpif_global_clock_disable_mr_a(TEN_MOD_ID_TO_DEV_ID(module_id),
                                          slice, CS_TX_AND_RX, CS_ENABLE);
        rtn |= ten_mpif_clock_select_hsif_out(TEN_MOD_ID_TO_DEV_ID(module_id),
                                      TEN_MODULE_A, slice, CS_TX_AND_RX, 1);
      }
    }
  }

  CS_PRINT("ten_hl_hsif_config_xaui complete, rtn=%s.\n", (rtn == CS_OK) ? "CS_OK" : "CS_ERROR");

  return (rtn);
}

/* Bugzilla #34232 - SFI-4.1 Rx, Tx clock polarity _ SW configures MRA, MRB differently  */
/********************************************************************/
/* $rtn_hdr_start  HIGH LEVEL CONFIG SFI 41 V2                      */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : HIGH LEVEL                                          */
/* CHIP       : Tenabo                                              */
cs_status ten_hl_config_sfi41_v2(cs_uint16 module_id,
                                 cs_uint8 slice,
                                 cs_uint16 internal_pilot,
                                 cs_uint16 launch_data_txclk,
                                 cs_uint16 launch_data_rxclk)
/* INPUTS     : o Module Id                                         */
/*              o Slice                                             */
/*              o Internal Pilot                                    */
/*              o Launch Data Txclk                                 */
/*              o Launch Data Rxclk                                 */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Configure HSIF SFI41, configure GPLL and check GPLL lock.        */
/*                                                                  */
/* [slice] Specified as TEN_SLICE0 (0), TEN_SLICE1 (1),             */
/*   TEN_SLICE2 (2), TEN_SLICE3 (3), or TEN_SLICE_ALL (0xFF).       */
/*                                                                  */
/* [internal_pilot] parameter is specified as:                      */
/*   0 = do not use internal pilot                                  */
/*   1 = use internal pilot.                                        */
/*                                                                  */
/* [launch_data_txclk] parameter is specified as:                   */
/*  launch TX on falling (0) or rising (1) edge                     */
/*                                                                  */
/* [launch_data_rxclk] parameter is specified as:                   */
/*  launch RX on falling (0) or rising (1) edge                     */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  cs_uint16 dev_id = TEN_MOD_ID_TO_DEV_ID(module_id);
  cs_status rtn = CS_OK;
  cs_uint16 instance;
  cs_uint16 gpll_mode;

  CS_PRINT("ten_hl_config_sfi41_v2, mod_id=0x%04X, sl=%d, internal_pilot=%d\n", 
            module_id, slice, internal_pilot);
  CS_PRINT("launch_data_txclk=%d, launch_data_rxclk=%d\n", 
            launch_data_txclk, launch_data_rxclk);
           
  rtn |= ten_hl_hsif_config_sfi41_v2(module_id, slice, internal_pilot,
                                     launch_data_txclk, launch_data_rxclk); 
  
  if ((TEN_MOD_ID_TO_MOD_NUM(module_id)) == TEN_MODULE_B) {
    instance = slice + 9;
  }
  else {
    instance = slice + 1;
  }
  gpll_mode = TEN_HL_GPLL_MODE_SFI41;
  ten_hl_gpllx1_init(dev_id, instance, gpll_mode, 0);

  if (ten_hl_gpllx1_waitfor_vcotune(dev_id, instance) != 1) {
    CS_PRINT("ten_hl_gpllx1_waitfor_vcotune inst=%d FAILED\n", instance);
    rtn |= CS_ERROR;
  }

  ten_hl_gpllx1_init(dev_id, instance+4, gpll_mode, 0);
  if (ten_hl_gpllx1_waitfor_vcotune(dev_id, instance+4) != 1) {
    CS_PRINT("ten_hl_gpllx1_waitfor_vcotune inst+4=%d FAILED\n", instance+4);
    rtn |= CS_ERROR;
  }

  CS_PRINT("ten_hl_config_sfi41_v2 complete, rtn=%s.\n", (rtn == CS_OK) ? "CS_OK" : "CS_ERROR");

  return (rtn);
}

/********************************************************************/
/* $rtn_hdr_start  HIGH LEVEL CONFIG SFI 41                         */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : HIGH LEVEL                                          */
/* CHIP       : Tenabo                                              */
cs_status ten_hl_config_sfi41(cs_uint16 module_id,
                              cs_uint8 slice,
                              cs_uint16 internal_pilot)
/* INPUTS     : o Module Id                                         */
/*              o Slice                                             */
/*              o Internal Pilot                                    */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Configure HSIF SFI41, configure GPLL and check GPLL lock.        */
/*                                                                  */
/* [slice] Specified as TEN_SLICE0 (0), TEN_SLICE1 (1),             */
/*   TEN_SLICE2 (2), TEN_SLICE3 (3), or TEN_SLICE_ALL (0xFF).       */
/*                                                                  */
/* [internal_pilot] parameter is specified as:                      */
/*   0 = do not use internal pilot                                  */
/*   1 = use internal pilot.                                        */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  cs_uint16 dev_id = TEN_MOD_ID_TO_DEV_ID(module_id);
  cs_status rtn = CS_OK;
  cs_uint16 instance;
  cs_uint16 gpll_mode;

  CS_PRINT("ten_hl_config_sfi41, mod_id=0x%04X, sl=%d, internal_pilot=%d\n", 
            module_id, slice, internal_pilot);
           
  rtn |= ten_hl_hsif_config_sfi41(module_id, slice, internal_pilot);
  
  if ((TEN_MOD_ID_TO_MOD_NUM(module_id)) == TEN_MODULE_B) {
    instance = slice + 9;
  }
  else {
    instance = slice + 1;
  }
  gpll_mode = TEN_HL_GPLL_MODE_SFI41;
  ten_hl_gpllx1_init(dev_id, instance, gpll_mode, 0);

  if (ten_hl_gpllx1_waitfor_vcotune(dev_id, instance) != 1) {
    CS_PRINT("ten_hl_gpllx1_waitfor_vcotune inst=%d FAILED\n", instance);
    rtn |= CS_ERROR;
  }

  ten_hl_gpllx1_init(dev_id, instance+4, gpll_mode, 0);
  if (ten_hl_gpllx1_waitfor_vcotune(dev_id, instance+4) != 1) {
    CS_PRINT("ten_hl_gpllx1_waitfor_vcotune inst+4=%d FAILED\n", instance+4);
    rtn |= CS_ERROR;
  }

  CS_PRINT("ten_hl_config_sfi41 complete, rtn=%s.\n", (rtn == CS_OK) ? "CS_OK" : "CS_ERROR");

  return (rtn);
}

/********************************************************************/
/* $rtn_hdr_start  HIGH LEVEL HSIF CONFIG SFI 41 V2                 */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : HIGH LEVEL                                          */
/* CHIP       : Tenabo                                              */
cs_status ten_hl_hsif_config_sfi41_v2(cs_uint16 module_id,
                                      cs_uint8 slice,
                                      cs_uint16 internal_pilot,
                                      cs_uint16 launch_data_txclk,
                                      cs_uint16 launch_data_rxclk)
/* INPUTS     : o Module Id                                         */
/*              o Slice                                             */
/*              o Internal Pilot                                    */
/*              o Launch Data Txclk                                 */
/*              o Launch Data Rxclk                                 */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Configure HSIF SFI41.                                            */
/* NOTE:  Specify launch_data_txclk and launch_data_rxclk per       */
/* specific application.                                            */
/*                                                                  */
/* [slice] Specified as TEN_SLICE0 (0), TEN_SLICE1 (1),             */
/*   TEN_SLICE2 (2), TEN_SLICE3 (3), or TEN_SLICE_ALL (0xFF).       */
/*                                                                  */
/* [internal_pilot] parameter is specified as:                      */
/*   0 = do not use internal pilot                                  */
/*   1 = use internal pilot.                                        */
/*                                                                  */
/* [launch_data_txclk] parameter is specified as:                   */
/*  launch TX on falling (0) or rising (1) edge                     */
/*                                                                  */
/* [launch_data_rxclk] parameter is specified as:                   */
/*  launch RX on falling (0) or rising (1) edge                     */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  cs_status rtn = CS_OK;
  cs_uint16 ln, slc, cnt;
  cs_uint16 rev_id;

  CS_PRINT("ten_hl_hsif_config_sfi41_v2, slice=%d\n", slice);

  /* remove SFI41 MPIF RESET so we can configure */
  rtn |= ten_mpif_global_reset_sfi41_mpif(TEN_MOD_ID_TO_DEV_ID(module_id),
                                   TEN_MOD_ID_TO_MOD_NUM(module_id),
                                   CS_RESET_DEASSERT);

  /* Bugzilla #36263 - mpif reset for all hsif interface */
  rtn |= ten_mpif_global_reset_sds_mr_mpif(TEN_MOD_ID_TO_DEV_ID(module_id), TEN_MOD_ID_TO_MOD_NUM(module_id),
                                           slice, CS_RESET_TOGGLE);
                                                                           
  /* remove soft resets in hsif - this done currently in config_HSIF (everything is released) */

  /* power up the MR serdes */
  rtn |= ten_hl_hsif_powerdown_mr(module_id, TEN_SLICE_ALL, CS_DISABLE);

  /* Bugzilla #30768, fix protection switch on same port */
  rtn |= ten_hsif_provision_datapath_t41(module_id, TEN_SLICE_ALL, 
                                         0,                           /* tx_pswtchen   */
                                         TEN_HSIF_PROTOCOL_SFI41,     /* tx_mrprotocol */
                                         0,                           /* rx_pswtchen   */
                                         TEN_HSIF_PROTOCOL_SFI41);    /* rx_mrprotocol */  

  /* Bugzilla #31356, fix issues with xfiselect bits */
  if (TEN_MOD_ID_TO_MOD_NUM(module_id) == TEN_MODULE_B) {
    rtn |= ten_hsif_provision_tx_xfiselect(module_id, slice, 0);
    rtn |= ten_hsif_provision_rx_xfiselect(module_id, slice, 0);                                      
  }

  for (slc=0; slc<4; slc++) {
    if ((slc==0) || (slc==2)) {
      cnt = 4;
    }
    else {
      cnt = 5;
    }
    for (ln=0; ln<cnt; ln++) {
      /*     # RX REGISTERS: */
      /*    # - SRX_EQADJ = 1111 */
      /*    #ten_reg_write (0,0x01088,0x0F1F); # SRX0_RX_MISC */
      /*    #my $reg        = eval("HSIF_MR_SLC${slc}_MR10X".$cnt[$slc]."_SDS_COMMON_SRX0_RX_MISC"); */
      /*    #my $reg_stride = eval("HSIF_MR_SLC${slc}_MR10X".$cnt[$slc]."_SDS_COMMON_SRX0_RX_MISC_STRIDE"); */
      /*    #ten_reg_write (DEV_ID,$reg+$ln*$reg_stride+$hsif_id*TEN_HSIF_STRIDE,0x0F1F); */
      /*    # Driver REGISTERS: */
      /*    # - set DRV_LOWER_CM=1000 */
      /*     # - set LVDS driver current to 12mA, STX_LEVEL=110000 */
      /*      # STX0_TX_OUTPUT_CTRLA */
      /*      #ten_reg_write (0,0x01108,0x0030);   # Assuming STX_DRV_LOWER_CM=0 */
      rtn |= ten_hsif_slc0_mr10x4_sds_common_stx0_tx_output_ctrla(module_id, 0, 0x30);

      /* #my $reg        = eval("TEN_HSIF_MR_SLC${slc}_MR10X".$cnt[$slc]."_SDS_COMMON_STX0_TX_OUTPUT_CTRLA"); */
      /* #my $reg_stride = eval("TEN_HSIF_MR_SLC${slc}_MR10X".$cnt[$slc]."_SDS_COMMON_STX0_TX_OUTPUT_CTRLA_STRIDE"); */
      /* #ten_reg_write (DEV_ID,$reg+$ln*$reg_stride+$hsif_id*TEN_HSIF_STRIDE,0x0030); */

      if (slc == TEN_SLICE0) {
        rtn |= ten_hsif_slc0_mr10x4_sds_common_stx0_tx_output_ctrla(module_id, ln, 0x0030);
      }
      if (slc == TEN_SLICE1) {
        rtn |= ten_hsif_slc1_mr10x5_sds_common_stx0_tx_output_ctrla(module_id, ln, 0x0030);
      }
      if (slc == TEN_SLICE2) {
        rtn |= ten_hsif_slc2_mr10x4_sds_common_stx0_tx_output_ctrla(module_id, ln, 0x0030);
      }
      if (slc == TEN_SLICE3) {
        rtn |= ten_hsif_slc3_mr10x5_sds_common_stx0_tx_output_ctrla(module_id, ln, 0x0030);
      }
    }

    /*    # turn on common mode feedback - bit 6 */
    /*    #my $reg = eval("TEN_HSIF_MR_SLC${slc}_MR10X".$cnt[$slc]."_SDS_COMMON_STXP0_TX_SPARE"); */
    /*    #tenabo_bf_write (DEV_ID,$reg+$hsif_id*TEN_HSIF_STRIDE,1,6,6); */

    if (slc == TEN_SLICE0) {
      rtn |= ten_hsif_slc0_mr10x4_sds_common_stxp0_tx_spare(module_id, 0x004F);
    }
    if (slc == TEN_SLICE1) {
      rtn |= ten_hsif_slc1_mr10x5_sds_common_stxp0_tx_spare(module_id, 0x004F);
    }
    if (slc == TEN_SLICE2) {
      rtn |= ten_hsif_slc2_mr10x4_sds_common_stxp0_tx_spare(module_id, 0x004F);
    }
    if (slc == TEN_SLICE3) {
      rtn |= ten_hsif_slc3_mr10x5_sds_common_stxp0_tx_spare(module_id, 0x004F);
    }
  }
   
  CS_PRINT("Configure launch bits\n");
  rtn |= ten_hsif_sfi41_cfg_spare_launch_data_rxclk(module_id, launch_data_rxclk);
  rtn |= ten_hsif_sfi41_cfg_spare_launch_data_txclk(module_id, launch_data_txclk);
  
  if (internal_pilot) {
    /*    # SWITCH_RX_SOURCE = 1 */
    rtn |= ten_mpif_set_clock_switch_rx_source(TEN_MOD_ID_TO_DEV_ID(module_id),
                                        TEN_MOD_ID_TO_MOD_NUM(module_id),
                                        slice, CS_ENABLE);
    /* tenabo_bf_write(TEN_MOD_ID_TO_DEV_ID(module_id)DEV_ID,TEN_MPIF_CLOCK_SWITCH_RX_SOURCE, 1, $ch, $ch); */
  }

  /*  # set reference to RXPLL to protect */
  /* tenabo_bf_write(DEV_ID,TEN_MPIF_CLOCK_SWITCH_RX_FORCE, 1, $ch, $ch); */
  rtn |= ten_mpif_set_clock_switch_force(TEN_MOD_ID_TO_DEV_ID(module_id),
                                       TEN_MOD_ID_TO_MOD_NUM(module_id),
                                       slice, CS_RX, CS_ENABLE);

  /*  # enable global clock for HSIF  */
  if (TEN_MOD_ID_TO_MOD_NUM(module_id) == TEN_MODULE_A) {
    rtn |= ten_mpif_global_clock_disable_mr_a(TEN_MOD_ID_TO_DEV_ID(module_id),
                                       slice, CS_TX_AND_RX, CS_ENABLE);
    if((rev_id = ten_mpif_get_chip_rev_id(TEN_MOD_ID_TO_DEV_ID(module_id))) == TEN_T41_REV_ID_2) { /* Bugzilla 35995 */
      if(slice == 1) {
        rtn |= ten_mpif_global_clock_disable_mr_a(TEN_MOD_ID_TO_DEV_ID(module_id),
                                                  0, CS_TX_AND_RX, CS_ENABLE);    
      }
    }
  }
  else {
    rtn |= ten_mpif_global_clock_disable_mr_b(TEN_MOD_ID_TO_DEV_ID(module_id),
                                       slice, CS_TX_AND_RX, CS_ENABLE);
    rtn |= ten_mpif_global_clock_disable_xfi_b(TEN_MOD_ID_TO_DEV_ID(module_id),
                                        slice, CS_TX_AND_RX, CS_ENABLE);
  }

  /*  # Select SERDES Clock out of HSIF */
  rtn |= ten_mpif_clock_select_hsif_out(TEN_MOD_ID_TO_DEV_ID(module_id),
                                 TEN_MOD_ID_TO_MOD_NUM(module_id),
                                 slice, CS_TX_AND_RX, 0);

  /*  # remove sds rx/tx reset  */
  /*  #ten_mpif_global_reset_sds_mr(DEV_ID, module_id, TEN_SLICE_ALL, CS_TX_AND_RX, CS_RESET_DEASSERT); */

  /*  # remove SFI41 tx/rx reset */
  rtn |= ten_mpif_global_reset_sfi41(TEN_MOD_ID_TO_DEV_ID(module_id),
                              TEN_MOD_ID_TO_MOD_NUM(module_id),
                              CS_TX_AND_RX, CS_RESET_DEASSERT);

  /*  # protocol reset released in toplevel script */
  /* Bugzilla #28764, remove resets simultaneously */
  rtn |= ten_hsif_reset(module_id, CS_RESET_DEASSERT, TEN_HSIF_RESET_TX_SFI41 | TEN_HSIF_RESET_RX_SFI41);
  
  CS_PRINT("ten_hl_hsif_config_sfi41_v2 complete, rtn=%s.\n", (rtn == CS_OK) ? "CS_OK" : "CS_ERROR");
  return (rtn);
}

/********************************************************************/
/* $rtn_hdr_start  HIGH LEVEL HSIF CONFIG SFI 41                    */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : HIGH LEVEL                                          */
/* CHIP       : Tenabo                                              */
cs_status ten_hl_hsif_config_sfi41(cs_uint16 module_id,
                                  cs_uint8 slice,
                                  cs_uint16 internal_pilot)
/* INPUTS     : o Module Id                                         */
/*              o Slice                                             */
/*              o Internal Pilot                                    */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Configure HSIF SFI41.                                            */
/* NOTE:  This API is hardcoded for electrical on Module A and      */
/* optical on Module B.                                             */
/*                                                                  */
/* The default settings use these APIs:                             */
/* On Module A:                                                     */
/* ten_hsif_sfi41_cfg_spare_launch_data_txclk(module_id, 1)         */
/*                                                                  */
/* On Module B:                                                     */
/*   ten_hsif_sfi41_cfg_spare_launch_data_rxclk(module_id, 0)       */
/*   ten_hsif_sfi41_cfg_spare_launch_data_txclk(module_id, 0)       */
/*                                                                  */
/* [slice] Specified as TEN_SLICE0 (0), TEN_SLICE1 (1),             */
/*   TEN_SLICE2 (2), TEN_SLICE3 (3), or TEN_SLICE_ALL (0xFF).       */
/*                                                                  */
/* [internal_pilot] parameter is specified as:                      */
/*   0 = do not use internal pilot                                  */
/*   1 = use internal pilot.                                        */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  cs_status rtn;
  CS_PRINT("ten_hl_hsif_config_sfi41, slice=%d\n", slice);

  CS_PRINT("configure launch bits\n");
  /*  # launch TX on falling (0) or rising (1) edge */
  if (TEN_MOD_ID_TO_MOD_NUM(module_id) == TEN_MODULE_A) {
    CS_PRINT("Configure HSIF RX A to launch data on falling edge of clk\n");
    /*    # rising required for lab use on Side A where we use LPBK card   */
    rtn = ten_hl_hsif_config_sfi41_v2(module_id, slice,
                                      internal_pilot, 1, 1);
    
  } 
  else {
    CS_PRINT("On B side, the SFI4.1 optic module launches data falling edge of clk\n");
    CS_PRINT("Configure HSIF RX B to capture data on rising edge of clk\n");
    /*    # Side B: latch rx data from optic module on rising edge of clk; optic module launches on falling edge of clk  */
    CS_PRINT("Configure HSIF TX B to launch data on rising edge of clk\n");
    rtn = ten_hl_hsif_config_sfi41_v2(module_id, slice,
                                      internal_pilot, 0, 0);
  }

  CS_PRINT("ten_hl_hsif_config_sfi41 complete, rtn=%s.\n", (rtn == CS_OK) ? "CS_OK" : "CS_ERROR");
  return (rtn);
}

/********************************************************************/
/* $rtn_hdr_start  HIGH LEVEL HSIF MR RING OSCILLATOR FIX           */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : HIGH LEVEL                                          */
/* CHIP       : Tenabo                                              */
cs_status ten_hl_hsif_mr_ring_oscillator_fix(cs_uint16 module_id,
                                             cs_uint8 slice)
/* INPUTS     : o Module Id                                         */
/*              o Slice                                             */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Perform MR ring oscillator fix (BUG #14178).                     */
/* This should be used by all protocols using the MR serdes.        */
/*                                                                  */
/* [slice] Specified as TEN_SLICE0 (0), TEN_SLICE1 (1),             */
/*   TEN_SLICE2 (2), TEN_SLICE3 (3), or TEN_SLICE_ALL (0xFF).       */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  cs_status rtn = CS_OK;

  CS_PRINT("ten_hl_hsif_mr_ring_oscillator_fix() module_id=%d, slice=%d\n", module_id, slice);

  /* Bugzilla #24261, set TX/RX thres0 to 0 per GS_SERDES 2.05 */
  /* Superceded by Bug #40945 - Change to GPLL and MR SERDES */

  if (ten_dev_is_t41(TEN_MOD_ID_TO_DEV_ID(module_id))) {
    CS_PRINT("T41 settings\n");
    if ((slice == TEN_SLICE0) || (slice == TEN_SLICE_ALL)) {
      rtn |= ten_hsif_set_slc0_mr10x4_sds_common_rxvco0_vcomax(module_id, TEN_INSTANCE_ALL, 0x0FFF);
      rtn |= ten_hsif_slc0_mr10x4_sds_common_rxvco0_thres0(module_id, TEN_INSTANCE_ALL, 0, 0xFF);
      rtn |= ten_hsif_slc0_mr10x4_sds_common_rxvco0_thres1(module_id, TEN_INSTANCE_ALL, 0, 0xFF);
      rtn |= ten_hsif_slc0_mr10x4_sds_common_txvco0_thres0(module_id, 0, 0xFF);
      rtn |= ten_hsif_slc0_mr10x4_sds_common_txvco0_thres1(module_id, 0, 0xFF);
    }
    if ((slice == TEN_SLICE1) || (slice == TEN_SLICE_ALL)) {
      rtn |= ten_hsif_set_slc1_mr10x5_sds_common_rxvco0_vcomax(module_id, TEN_INSTANCE_ALL, 0x0FFF);
      rtn |= ten_hsif_slc1_mr10x5_sds_common_rxvco0_thres0(module_id, TEN_INSTANCE_ALL, 0, 0xFF);
      rtn |= ten_hsif_slc1_mr10x5_sds_common_rxvco0_thres1(module_id, TEN_INSTANCE_ALL, 0, 0xFF);
      rtn |= ten_hsif_slc1_mr10x5_sds_common_txvco0_thres0(module_id, 0, 0xFF);
      rtn |= ten_hsif_slc1_mr10x5_sds_common_txvco0_thres1(module_id, 0, 0xFF);
    }
    if ((slice == TEN_SLICE2) || (slice == TEN_SLICE_ALL)) {
      rtn |= ten_hsif_set_slc2_mr10x4_sds_common_rxvco0_vcomax(module_id, TEN_INSTANCE_ALL, 0x0FFF);
      rtn |= ten_hsif_slc2_mr10x4_sds_common_rxvco0_thres0(module_id, TEN_INSTANCE_ALL, 0, 0xFF);
      rtn |= ten_hsif_slc2_mr10x4_sds_common_rxvco0_thres1(module_id, TEN_INSTANCE_ALL, 0, 0xFF);
      rtn |= ten_hsif_slc2_mr10x4_sds_common_txvco0_thres0(module_id, 0, 0xFF);
      rtn |= ten_hsif_slc2_mr10x4_sds_common_txvco0_thres1(module_id, 0, 0xFF);
    }
    if ((slice == TEN_SLICE3) || (slice == TEN_SLICE_ALL)) {
      rtn |= ten_hsif_set_slc3_mr10x5_sds_common_rxvco0_vcomax(module_id, TEN_INSTANCE_ALL, 0x0FFF);
      rtn |= ten_hsif_slc3_mr10x5_sds_common_rxvco0_thres0(module_id, TEN_INSTANCE_ALL, 0, 0xFF);
      rtn |= ten_hsif_slc3_mr10x5_sds_common_rxvco0_thres1(module_id, TEN_INSTANCE_ALL, 0, 0xFF);
      rtn |= ten_hsif_slc3_mr10x5_sds_common_txvco0_thres0(module_id, 0, 0xFF);
      rtn |= ten_hsif_slc3_mr10x5_sds_common_txvco0_thres1(module_id, 0, 0xFF);
    }
  }
  else {
    CS_PRINT("T40 settings\n");
  
    if ((slice == TEN_SLICE0) || (slice == TEN_SLICE_ALL)) {
      rtn |= ten_hsif_set_slc0_mr10x4_sds_common_rxvco0_vcomax(module_id, TEN_INSTANCE_ALL, 0x03ff);
      rtn |= ten_hsif_slc0_mr10x4_sds_common_rxvco0_thres0(module_id, TEN_INSTANCE_ALL, 0, 0);
      rtn |= ten_hsif_slc0_mr10x4_sds_common_rxvco0_thres1(module_id, TEN_INSTANCE_ALL, 0, 0x0091);
      rtn |= ten_hsif_set_slc0_mr10x4_sds_common_txvco0_vcomax(module_id, 0x03ff);
      rtn |= ten_hsif_slc0_mr10x4_sds_common_txvco0_thres0(module_id, 0, 0);
      rtn |= ten_hsif_slc0_mr10x4_sds_common_txvco0_thres1(module_id, 0, 0x0091);
    }
    if ((slice == TEN_SLICE1) || (slice == TEN_SLICE_ALL)) {
      rtn |= ten_hsif_set_slc1_mr10x5_sds_common_rxvco0_vcomax(module_id, TEN_INSTANCE_ALL, 0x03ff);
      rtn |= ten_hsif_slc1_mr10x5_sds_common_rxvco0_thres0(module_id, TEN_INSTANCE_ALL, 0, 0);
      rtn |= ten_hsif_slc1_mr10x5_sds_common_rxvco0_thres1(module_id, TEN_INSTANCE_ALL, 0, 0x0091);
      rtn |= ten_hsif_set_slc1_mr10x5_sds_common_txvco0_vcomax(module_id, 0x03ff);
      rtn |= ten_hsif_slc1_mr10x5_sds_common_txvco0_thres0(module_id, 0, 0);
      rtn |= ten_hsif_slc1_mr10x5_sds_common_txvco0_thres1(module_id, 0, 0x0091);
    }
    if ((slice == TEN_SLICE2) || (slice == TEN_SLICE_ALL)) {
      rtn |= ten_hsif_set_slc2_mr10x4_sds_common_rxvco0_vcomax(module_id, TEN_INSTANCE_ALL, 0x03ff);
      rtn |= ten_hsif_slc2_mr10x4_sds_common_rxvco0_thres0(module_id, TEN_INSTANCE_ALL, 0, 0);
      rtn |= ten_hsif_slc2_mr10x4_sds_common_rxvco0_thres1(module_id, TEN_INSTANCE_ALL, 0, 0x0091);
      rtn |= ten_hsif_set_slc2_mr10x4_sds_common_txvco0_vcomax(module_id, 0x03ff);
      rtn |= ten_hsif_slc2_mr10x4_sds_common_txvco0_thres0(module_id, 0, 0);
      rtn |= ten_hsif_slc2_mr10x4_sds_common_txvco0_thres1(module_id, 0, 0x0091);
    }
    if ((slice == TEN_SLICE3) || (slice == TEN_SLICE_ALL)) {
      rtn |= ten_hsif_set_slc3_mr10x5_sds_common_rxvco0_vcomax(module_id, TEN_INSTANCE_ALL, 0x03ff);
      rtn |= ten_hsif_slc3_mr10x5_sds_common_rxvco0_thres0(module_id, TEN_INSTANCE_ALL, 0, 0);
      rtn |= ten_hsif_slc3_mr10x5_sds_common_rxvco0_thres1(module_id, TEN_INSTANCE_ALL, 0, 0x0091);
      rtn |= ten_hsif_set_slc3_mr10x5_sds_common_txvco0_vcomax(module_id, 0x03ff);
      rtn |= ten_hsif_slc3_mr10x5_sds_common_txvco0_thres0(module_id, 0, 0);
      rtn |= ten_hsif_slc3_mr10x5_sds_common_txvco0_thres1(module_id, 0, 0x0091);
    }
  }

  CS_PRINT("ten_hl_hsif_mr_ring_oscillator_fix Complete. \n");

  if (rtn) {
   /*CS_PRINT("%s() ERROR!\n", func);*/
   CS_PRINT("ten_hl_hsif_mr_ring_oscillator_fix() ERROR!\n");
  } 
  return (rtn);
}

/********************************************************************/
/* $rtn_hdr_start  XFI CONFIG CLOCKMUX T41                          */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : HIGH LEVEL                                          */
/* CHIP       : Tenabo                                              */
cs_status ten_hl_xfi_config_clockmux_t41(cs_uint16 module_id, 
                                         cs_uint8  slice, 
                                         cs_uint16 aux_clk,
                                         cs_uint16 k_value,
                                         cs_uint16 stxp_pilot_sel,
                                         cs_uint16 cupll_in_use)
/* INPUTS     : o Module Id                                         */
/*              o Slice                                             */
/*              o aux_clk                                           */
/*              o k_value                                           */
/*              o stxp_pilot_sel                                    */ 
/*              o cupll_in_use                                      */ 
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Configure the CLOCKMUX for an XFI interface.                     */
/*                                                                  */
/*   [slice]  Specified as TEN_SLICE0 (0), TEN_SLICE1 (1),          */
/*     TEN_SLICE2 (2), TEN_SLICE3 (3), or TEN_SLICE_ALL (0xFF)      */
/*                                                                  */
/*   [aux_clk] is specified as:                                     */
/*     0 = clock on tx ref pin                                      */
/*     1 = clock on aux clk pin                                     */
/*                                                                  */
/*   [k_value] is specified as:                                     */
/*     0..64 decimal                                                */
/*                                                                  */
/*   [stxp_pilot_sel] is specified as:                              */
/*     Selects pilot tone clock to the receiver and the             */
/*     STXP_REF_LD signal.                                          */
/*     0x0 = use XFI0_TX_CLKREFP/N external pad                     */
/*     0x1 = use STXP_AUXPILOTIN from Fractional Divider            */
/*     100 = use XLAUI common internal reference                    */
/*     101 = use XLAUI common internal pilot                        */
/*     110 = use XFI0_TX_AUX_LPTIME_CLKREFP/N external pad          */
/*                                                                  */
/*   [cupll_in_use] is specified as:                                */
/*     0 = not in use                                               */
/*     1 = CUPLL is used for 10G interface                          */
/*     2 = CUPLL is used for 40G interface                          */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  cs_status rtn = CS_OK;
  cs_uint16 tmp_stxp_pilot_sel;
  cs_uint16 rx_rdiv = 0;
  cs_uint16 rx_ctvdiv = 0;
  cs_uint16 tx_ctrdiv = 0;
  cs_uint16 tx_ctvdiv = 0;
  cs_uint16 tx_rdiv = 0;
  cs_uint16 ii;
  
  CS_PRINT("ten_hl_xfi_config_clockmux_t41:  mod_id=0x%04X, sl=%d\n",
            module_id, slice);
  
  CS_PRINT("aux_clk = %d, k_value = %d, stxp_pilot_sel = %d, cupll_in_use = %d\n", 
            aux_clk, k_value, stxp_pilot_sel, cupll_in_use);

  /* Remove force lock of RX to pilot tone */
  rtn |= ten_xfi32x1_set_rxlockd0_force_lock(module_id, slice, 0x0, 0x0 );
   
  if (!ten_dev_is_t41(TEN_MOD_ID_TO_DEV_ID(module_id))) {
    /* T40 needs stxp_pilot_sel = 0, except for aux_clk */
    if (aux_clk == 0) {
      tmp_stxp_pilot_sel = 0;
    }
    else {
      tmp_stxp_pilot_sel = stxp_pilot_sel;
    }
  }
  else {
    /* For T41, use stxp_pilot_sel passed in */
    tmp_stxp_pilot_sel = stxp_pilot_sel;
  }
  
  if (k_value == 16) {
    rx_rdiv   = 0;
    rx_ctvdiv = 2;
    tx_rdiv = (cupll_in_use > 0) ? 12 : 0;
    tx_ctvdiv = 2; 
    tx_ctrdiv = 2;
  }
  else if (k_value == 32) {
    rx_rdiv   = 1;
    rx_ctvdiv = 1;

    tx_rdiv = (cupll_in_use > 0) ? 13 : 1;
    tx_ctvdiv = 1; 
    tx_ctrdiv = 1;  
  }
  else if (k_value == 64) {
    rx_rdiv   = 2;
    rx_ctvdiv = 0;

    tx_rdiv = (cupll_in_use > 0) ? 14 : 2;
    tx_ctvdiv = 0; 
    tx_ctrdiv = 0;  
  }
  else {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, "k value not supported.");
    rx_rdiv   = 2;
    rx_ctvdiv = 0;

    tx_rdiv = (cupll_in_use > 0) ? 14 : 2;
    tx_ctvdiv = 0; 
    tx_ctrdiv = 0;  
  }

  rtn |= ten_xfi32x1_stxp0_tx_config_pilot_sel(module_id, slice, tmp_stxp_pilot_sel); 
   
  if ((aux_clk == 0) && (cupll_in_use == 0)) {
     if (tmp_stxp_pilot_sel != 1) { 
       rtn |= ten_xfi32x1_srx0_rx_clkdiv_ctrl_rdiv_sel(module_id, slice, rx_rdiv);
       rtn |= ten_xfi32x1_srx0_rx_clkdiv_ctrl_ctvdiv_sel(module_id, slice, rx_ctvdiv);
       rtn |= ten_xfi32x1_stxp0_tx_clkdiv_ctrl_ctr_div(module_id, slice, tx_ctrdiv);
     }
  }
  
  /* autoswitch for RX DIV on lockdet */
  rtn |= ten_mpif_set_clock_switch_lockdet_xfi(TEN_MOD_ID_TO_DEV_ID(module_id),
                                               slice, CS_TX, CS_ENABLE );
                                               
  /* XFI and MR lockdet bits should never both be set for side B */
  rtn |= ten_mpif_set_clock_switch_lockdet_mr(TEN_MOD_ID_TO_DEV_ID(module_id),
                                              TEN_MOD_ID_TO_MOD_NUM(module_id),
                                              slice, CS_TX_AND_RX, CS_DISABLE );
                                              
  rtn |= ten_xfi32x1_stxp0_tx_clkdiv_ctrl_ctv_div(module_id, slice, tx_ctvdiv);
  rtn |= ten_xfi32x1_stxp0_tx_clkdiv_ctrl_rdiv_sel(module_id, slice, tx_rdiv); 

  /* Additional settings for CUPLL on 40G */
  if (cupll_in_use == 2) {
      /* Select external reference for master (slaves get internal) */
      ten_xfi32x1_stxp0_tx_config_lptime_sel_msb_t41(module_id, slice, 0);
      /* Enable XLAUI pilot clock outputs to the digital core */
      ten_xfi32x1_stxp0_tx_sfi52_pilotouten_t41(module_id, slice, 0);
      /* XLAUI ref clk: use VCO clock divided-by 16 */
      ten_xfi32x1_stxp0_tx_sfi52_clkrefout_sel_t41(module_id, slice, 4);
      /* XLAUI ref clk: divided by 4 */
      ten_xfi32x1_stxp0_tx_sfi52_clkrefout_div_sel_t41(module_id, slice, 2);
      
      /*  Bug 35741 - 40G Internal Cleanup PLL configuration with -auxclk option */
      if (aux_clk == 1) {
        for (ii=0;ii<TEN_MAX_SLICES;ii++) {
          if (slice!=ii) {
            rtn |= ten_xfi32x1_stxp0_tx_lptime_sel(module_id, ii, 0);
          }
        }
      }
  }                                          

  return (rtn);
}

/********************************************************************/
/* $rtn_hdr_start  XFI CONFIG CLOCKMUX                              */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : HIGH LEVEL                                          */
/* CHIP       : Tenabo                                              */
cs_status ten_hl_xfi_config_clockmux(cs_uint16 module_id, cs_uint8 slice, 
                                     cs_uint16 srx_rdiv_sel, 
                                     cs_uint16 srx_ctvdiv_sel, 
                                     cs_uint16 stxp_ctrdiv_sel,
                                     cs_uint16 aux_clk)
/* INPUTS     : o Module Id                                         */
/*              o Slice                                             */
/*              o srx rdiv sel                                      */
/*              o srx ctvdiv sel                                    */
/*              o stxp ctrdiv sel                                   */
/*              o aux_clk                                           */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Configure the CLOCKMUX for an XFI interface.                     */
/* Refer to the documentation for these functions for               */
/* more information:                                                */
/*   ten_xfi32x1_srx0_rx_clkdiv_ctrl_rdiv_sel                       */
/*   ten_xfi32x1_srx0_rx_clkdiv_ctrl_ctvdiv_sel                     */
/*   ten_xfi32x1_stxp0_tx_clkdiv_ctrl_ctr_div                       */
/*                                                                  */
/*   [slice]  Specified as TEN_SLICE0 (0), TEN_SLICE1 (1),          */
/*     TEN_SLICE2 (2), TEN_SLICE3 (3), or TEN_SLICE_ALL (0xFF)      */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  cs_status rtn = CS_OK;
  CS_PRINT("ten_hl_xfi_config_clockmux\n");
  
  /* Remove force lock of RX to pilot tone */
  rtn |= ten_xfi32x1_set_rxlockd0_force_lock(module_id, slice, 0x0, 0x0 );
   
  if (aux_clk == 0) {
    /* switch XFI internal pilot to external tx ref clock */
   rtn |= ten_xfi32x1_stxp0_tx_config_pilot_sel(module_id, slice, 0x0); 
   
   rtn |= ten_xfi32x1_srx0_rx_clkdiv_ctrl_rdiv_sel(module_id, slice, srx_rdiv_sel);
   rtn |= ten_xfi32x1_srx0_rx_clkdiv_ctrl_ctvdiv_sel(module_id, slice, srx_ctvdiv_sel);
   rtn |= ten_xfi32x1_stxp0_tx_clkdiv_ctrl_ctr_div(module_id, slice, stxp_ctrdiv_sel);
  }
  /* autoswitch for RX DIV on lockdet */
  rtn |= ten_mpif_set_clock_switch_lockdet_xfi(TEN_MOD_ID_TO_DEV_ID(module_id),
                                               slice, CS_TX, CS_ENABLE );
  /* Bug 23742 start, xfi & mr lockdet bits should never both be set for side B */
  rtn |= ten_mpif_set_clock_switch_lockdet_mr(TEN_MOD_ID_TO_DEV_ID(module_id),
                                              TEN_MOD_ID_TO_MOD_NUM(module_id),
                                              slice, CS_TX_AND_RX, CS_DISABLE );
  /* Bug 23742 end */

  return (rtn);
}

/********************************************************************/
/* $rtn_hdr_start  MR CONFIG CLOCKMUX                               */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : HIGH LEVEL                                          */
/* CHIP       : Tenabo                                              */
cs_status ten_hl_mr_config_clockmux(cs_uint16 module_id, cs_uint8 slice)
/* INPUTS     : o Module Id                                         */
/*              o Slice                                             */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Configure the CLOCKMUX for a multi-rate interface                */
/* i.e. SFI-5.1, SFI-4.2, SFI-4.1, XAUI                             */
/*                                                                  */
/*   [slice]  Specified as TEN_SLICE0 (0), TEN_SLICE1 (1),          */
/*     TEN_SLICE2 (2), TEN_SLICE3 (3), or TEN_SLICE_ALL (0xFF)      */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  cs_status rtn = CS_OK;
  CS_PRINT("ten_hl_mr_config_clockmux, slice=%d\n", slice);
  
  /* tenabo_hsif_mr_switch_clock */
  rtn |= ten_hl_hsif_mr_switch_clock(module_id, slice);
  
  /* autoswitch MR for RX DIV on lockdet */
  /* This doesn't apply to SFI-4.1; review config_CLOCKMUX in config.pm */
  /* Bugzilla #29143, Noticed during warm start test,                     */
  /* need lockdet RX enabled in case backplane/loopback card is not there */
  rtn |= ten_mpif_set_clock_switch_lockdet_mr(TEN_MOD_ID_TO_DEV_ID(module_id),
                                              TEN_MOD_ID_TO_MOD_NUM(module_id),
                                              slice, CS_TX_AND_RX, CS_ENABLE );
                                              
  /* Bug 23742 start, xfi & mr lockdet bits should never both be set for side B */
  if (TEN_MOD_ID_TO_MOD_NUM(module_id) == TEN_MODULE_B) {
    rtn |= ten_mpif_set_clock_switch_lockdet_xfi(TEN_MOD_ID_TO_DEV_ID(module_id),
                                                 slice, CS_TX_AND_RX, CS_DISABLE );
  }
  /* Bug 23742 end */

  return (rtn);                                             
}

/********************************************************************/
/* $rtn_hdr_start  MR40G CONFIG CLOCKMUX                            */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : HIGH LEVEL                                          */
/* CHIP       : Tenabo                                              */
cs_status ten_hl_mr_40g_config_clockmux(cs_uint16 module_id)
/* INPUTS     : o Module Id                                         */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Configure the CLOCKMUX for a 40G multi-rate interface, i.e.,     */
/* SFI-5.1 or 16-lane SFI-4.2.                                      */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  cs_status rtn = CS_OK;
  cs_uint16 ii;
  
  CS_PRINT("ten_hl_mr_40g_config_clockmux\n");

  for (ii=0; ii<4; ii++) {
    rtn |= ten_hl_mr_config_clockmux(module_id, ii);
  }
  return (rtn);
}

/* Bugzilla 23772 Start */
/****************************************************************/
/* $rtn_hdr_start  HIGH LEVEL CONFIG 10G HSIF KPGA              */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : HIGH LEVEL CONFIG                               */
/* CHIP       : Tenabo                                          */
cs_status ten_hl_config_10g_hsif_kpga (cs_uint16 module_id,
                                       cs_uint8  slice,
                                       cs_uint16 hsif,
                                       cs_uint16 invertPrbs,
                                       cs_uint16 pattern)
/* INPUTS     : o Module Id                                     */
/*              o Pattern                                       */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* Provision 10G portion of the HSIF for KPGA                   */
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
/* [hsif]  parameter is specified as:                           */
/*   0x03 = TEN_HSIF_PROTOCOL_XFI                               */
/*   0x06 = TEN_HSIF_PROTOCOL_XAUI                              */
/*   0x07 = TEN_HSIF_PROTOCOL_CPF                               */
/*                                                              */
/* The [invertPrbs] parameter is specified as:                  */
/*   0 = Do Not invert Rx PRBS                                  */
/*   1 = invert Rx PRBS                                         */
/*                                                              */
/* The [pattern] parameter is specified as:                     */
/*   0x00 = TEN_HSIF_PRBS_PN31                                  */
/*   0x01 = TEN_HSIF_PRBS_PN23                                  */
/*   0x02 = TEN_HSIF_PRBS_PN15                                  */
/*   0x03 = TEN_HSIF_PRBS_PN7                                   */
/*   0x04 = TEN_HSIF_PRBS_PN9                                   */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  T41_t *pDev = NULL;
  cs_uint16 module_num = module_id & 1;
  cs_char8 *func = "ten_hl_config_10g_hsif_kpga";  
 
  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  
  if ((slice >= TEN_MAX_SLICES) && (slice != TEN_SLICE_ALL)) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, "%s() slice %d out of range.  s/b 0..3, 255. ", func, slice);
    return (CS_ERROR);
  }

  if ((hsif != TEN_HSIF_PROTOCOL_XAUI) && (hsif != TEN_HSIF_PROTOCOL_XFI) && (hsif != TEN_HSIF_PROTOCOL_CFP)) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, "%s() hsif %d out of range.  s/b 3, 6, 7.", func, hsif);
    return (CS_ERROR);
  }

  if (invertPrbs > 1) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, "%s() invertPrbs %d out of range.  s/b 0..1.", func, invertPrbs);
    return (CS_ERROR);
  }

  if (pattern > TEN_HSIF_PRBS_PN9) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, "%s() pattern %d out of range.  s/b 0..3.", func, pattern);
    return (CS_ERROR);
  }
  
  CS_PRINT("%s()  %s, Slice %d, %s, invertPrbs = %d, %s\n",
           func,
           ten_module_strings[module_num],
           slice,
           ten_hsif_protocols_strings[hsif],
           invertPrbs,
           ten_hsif_prbs_pn_strings[pattern]);


  /* Provision HSIF PRBS */
  if (hsif == TEN_HSIF_PROTOCOL_XFI) {
    ten_xfi32x1_prbschk_enable (module_id, slice, 1);   /* Enable PRBS monitoring */
    ten_xfi32x1_prbschk_config (module_id, slice, pattern, invertPrbs);

    ten_xfi32x1_tx0_config (module_id, slice, 1);   /* Selects the input source for the TX  datapath for PRBS*/
    ten_xfi32x1_prbsgen_config (module_id, slice, pattern, invertPrbs, 0, 1);
  } 
  else if (hsif == TEN_HSIF_PROTOCOL_CFP) {
    ten_cfp32x1_prbsgen_config_t41(module_id, slice, pattern, invertPrbs, 0, 1);  /* prbs_mode, invertPrbs, fixed_pattern, prbs_enable */
    ten_cfp32x1_prbschk_config_t41(module_id, slice, pattern, invertPrbs);  /* prbs_mode, invertPrbs */
    ten_cfp32x1_prbschk_enable_t41(module_id, slice, 1);  /* enable */

    ten_cfp32x1_tx0_config_data_source_t41 (module_id, slice, 1); /*  data_source   01 = RX PRBS */
  }
  else {
    ten_hsif_mr10_sds_common_tx_config (module_id, slice, TEN_INSTANCE_ALL, TEN_HSIF_MR_DATASOURCE_PRBS);  
    ten_hsif_mr10_sds_common_prbsgen0_prbs_cfg (module_id, slice, TEN_INSTANCE_ALL, hsif, 1, 1, pattern);
    ten_hsif_mr10_sds_common_prbschk0_cfg (module_id, slice, TEN_INSTANCE_ALL, hsif, 1, 1, pattern);
  }
  
  return (CS_OK);
}

/****************************************************************/
/* $rtn_hdr_start  HIGH LEVEL CONFIG 40G HSIF KPGA              */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : HIGH LEVEL CONFIG                               */
/* CHIP       : Tenabo                                          */
cs_status ten_hl_config_40g_hsif_kpga (cs_uint16 module_id,
                                       cs_uint16 hsif,
                                       cs_uint16 invertPrbs,
                                       cs_uint16 pattern)
/* INPUTS     : o Module Id                                     */
/*              o Pattern                                       */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* Provision 40G portion of the HSIF for KPGA                   */
/*                                                              */
/* [module_id] specifies module ID                              */ 
/*   0xXX00 = Module A                                          */      
/*   0xXX01 = Module B                                          */
/*                                                              */      
/* [hsif]  parameter is specified as:                           */
/*   0x01 = TEN_HSIF_PROTOCOL_SFI51                             */
/*   0x03 = TEN_HSIF_PROTOCOL_XFI                               */
/*   0x07 = TEN_HSIF_PROTOCOL_CFP                               */
/*                                                              */
/* The [invertPrbs] parameter is specified as:                  */
/*   0 = Do Not invert Rx PRBS                                  */
/*   1 = invert Rx PRBS                                         */
/*                                                              */
/* The [pattern] parameter is specified as:                     */
/*   0x00 = TEN_HSIF_PRBS_PN31                                  */
/*   0x01 = TEN_HSIF_PRBS_PN23                                  */
/*   0x02 = TEN_HSIF_PRBS_PN15                                  */
/*   0x03 = TEN_HSIF_PRBS_PN7                                   */
/*   0x04 = TEN_HSIF_PRBS_PN9                                   */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  cs_uint16 i;
  T41_t *pDev = NULL;
  cs_uint16 dev_id = TEN_MOD_ID_TO_DEV_ID(module_id);
  cs_uint16 module_num = module_id & 1;
  cs_char8 *func = "ten_hl_config_40g_hsif_kpga";  
  
  TEN_MOD_COMMON_VALIDATE (module_id, pDev, CS_ERROR);
  
  /* Bugzilla 26403 Start */
  if ((hsif != TEN_HSIF_PROTOCOL_SFI51) && (hsif != TEN_HSIF_PROTOCOL_XFI) &&
      (hsif != TEN_HSIF_PROTOCOL_CFP)) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, "%s() hsif %d out of range.  s/b 1, 3, 7.", func, hsif);
    return (CS_ERROR);
  }
  /* Bugzilla 26403 End */

  if (invertPrbs > 1) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, "%s() invertPrbs %d out of range.  s/b 0..1.", func, invertPrbs);
    return (CS_ERROR);
  }

  if (pattern > TEN_HSIF_PRBS_PN9) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, "%s() pattern %d out of range.  s/b 0..3.", func, pattern);
    return (CS_ERROR);
  }
  
  CS_PRINT("%s()  %s, %s, invertPrbs = %d, %s\n",
           func,
           ten_module_strings[module_num],
           ten_hsif_protocols_strings[hsif],
           invertPrbs,
           ten_hsif_prbs_pn_strings[pattern]);

  /* Selects the datapath source to be the single 40G RX clock */
  ten_mpif_clock_select_40g_per_module (dev_id, module_id & 1, 1, 1);   /* Bugzilla 28482 */

  /* apply ring_oscillator fix */
  /* duplicate call -- already done during HSIF provisioning */
  /* ten_set_vco_coarse_tuning (dev_id, port + 1); */  /* Bugzilla #24261 */
  
  /* Supplied All GPLLs with the 40G source clock since slot 0 and 3 must be used for 40G Monolithic */
  /* Set tx pll clock and rx slice clock to slice 0 */
  ten_hsif_clk_40g (module_id, 0, 0, 0, 0);  /* tx_aggr_mode, txsel, rx_aggr_mode, rxsel */
    
  /* Bugzilla 26403 Start */
  /*if ((hsif == TEN_HSIF_PROTOCOL_SFI51) || (hsif == TEN_HSIF_PROTOCOL_SFI42_40G)) {*/
  if (hsif == TEN_HSIF_PROTOCOL_SFI51) {
    /* Provision HSIF PRBS */
    ten_hsif_mr10_sds_common_tx_config (module_id, TEN_SLICE_ALL, TEN_INSTANCE_ALL, TEN_HSIF_MR_DATASOURCE_PRBS);
    ten_hsif_mr10_sds_common_prbsgen0_prbs_cfg (module_id, TEN_SLICE_ALL, TEN_INSTANCE_ALL, hsif, 1, invertPrbs, pattern);
    ten_hsif_mr10_sds_common_prbschk0_cfg (module_id, TEN_SLICE_ALL, TEN_INSTANCE_ALL, hsif,1, invertPrbs, pattern);
  } 
  else if (hsif == TEN_HSIF_PROTOCOL_CFP) {
    ten_cfp32x1_prbsgen_config_t41 (module_id, TEN_SLICE_ALL, pattern, invertPrbs, 0, 1);  /* prbs_mode, invertPrbs, fixed_pattern, prbs_enable */
    ten_cfp32x1_prbschk_config_t41 (module_id, TEN_SLICE_ALL, pattern, invertPrbs);  /* prbs_mode, invertPrbs */
    ten_cfp32x1_prbschk_enable_t41 (module_id, TEN_SLICE_ALL, 1);  /* enable */

    /* Bugzilla #29142 - Fix CPF_MR and CFP_XFI KPGA/HSIF_KPGA failures with CEB board */
    ten_cfp32x1_tx0_config_data_source_t41 (module_id, TEN_SLICE_ALL, 1); /*  data_source   01 = RX PRBS */
    
    for (i=0; i<4;i++) {
      ten_cfp32x1_stxp0_tx_clkout_ctrl_clkouten_t41 (module_id, i, 1);     /* STXP_CLKOUTEN */
      ten_cfp32x1_stxp0_tx_clkout_ctrl_tclko_sel_t41 (module_id, i, 0);   /* STXP_TCLKO_SEL */
    }
  }
  else if (hsif == TEN_HSIF_PROTOCOL_XFI) {
    ten_xfi32x1_prbschk_enable (module_id, TEN_SLICE_ALL, 1);   /* Enable PRBS monitoring */
    ten_xfi32x1_prbschk_config (module_id, TEN_SLICE_ALL, pattern, invertPrbs);

    ten_xfi32x1_tx0_config (module_id, TEN_SLICE_ALL, 1);   /* Selects the input source for the TX  datapath for PRBS*/
    ten_xfi32x1_rx0_config (module_id, TEN_SLICE_ALL, 1);

    ten_xfi32x1_prbsgen_config (module_id, TEN_SLICE_ALL, pattern, invertPrbs, 0, 1);
    
    /* Bugzilla #29142 - Fix CPF_MR and CFP_XFI KPGA/HSIF_KPGA failures with CEB board */
    ten_xfi32x1_prbsgen_enable (module_id, TEN_SLICE_ALL, 1);

    for (i=0; i <4;i++) {
      ten_xfi32x1_stxp0_tx_clkout_ctrl_clkouten (module_id, i, 1);     /* STXP_CLKOUTEN */
      ten_xfi32x1_stxp0_tx_clkout_ctrl_tclko_sel (module_id, i, 0);   /* STXP_TCLKO_SEL */
    }
  }
  /* Bugzilla 26403 End */
  
  return (CS_OK);
}
/* Bugzilla 23772 End */

/****************************************************************/
/* $rtn_hdr_start  HIGH LEVEL HSIF CTL PROTECTION SWITCHING     */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : HIGH LEVEL CONFIG                               */
/* CHIP       : Tenabo                                          */
cs_status ten_hl_hsif_control_protection_switching(cs_uint16 module_id_a,
                                                   cs_uint8  module_id_b,
                                                   cs_uint8  slice,
                                                   cs_ctl_t  ctl)
/* INPUTS     : o Module Id A                                   */
/*              o Module Id B                                   */
/*              o Slice                                         */
/*              o Control                                       */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* Control 1+1 Protection switching.                            */
/*                                                              */
/* [module_id_a] specifies module ID A                          */
/*                                                              */
/* [module_id_b] specifies module ID B for protection           */
/*                                                              */
/* [inst]  specifies slice:                                     */
/*   0x00 = TEN_SLICE0                                          */
/*   0x01 = TEN_SLICE1                                          */
/*   0x02 = TEN_SLICE2                                          */
/*   0x03 = TEN_SLICE3                                          */
/*   0xFF = TEN_SLICE_ALL                                       */
/*                                                              */
/* The [ctl] parameter controls checking option:                */
/*   0 = CS_DISABLE                                             */
/*   1 = CS_ENABLE.                                             */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  T41_t *pDev = NULL;
  cs_status rtn = CS_OK;

  TEN_MOD_COMMON_VALIDATE (module_id_a, pDev, CS_ERROR);
  TEN_MOD_COMMON_VALIDATE (module_id_b, pDev, CS_ERROR);
  
  if ((ctl != CS_ENABLE) && (ctl!= CS_DISABLE)) {
    CS_HNDL_ERROR(module_id_a, ETEN_MOD_INVALID_USER_ARG, "ctl out of range.  s/b 0..1.");
    return (CS_ERROR);
  }

  /* Select Module B MR SERDES TX clock out of HSIF.                  */
  /* This option may be used in MR SERDES protection switching mode.  */
  ten_mpif_clock_select_hsif_out(TEN_MOD_ID_TO_DEV_ID(module_id_a),
                                 TEN_MOD_ID_TO_MOD_NUM(module_id_a),
                                 slice, CS_TX_AND_RX, ctl);
  
  if (slice == TEN_SLICE_ALL) {
    if (ctl) {
      rtn |= ten_mpif_clock_select_prot(TEN_MOD_ID_TO_DEV_ID(module_id_a), 0, 0, 0x0F, 0x0F);
    }
    else {
      rtn |= ten_mpif_clock_select_prot(TEN_MOD_ID_TO_DEV_ID(module_id_a), 0, 0, 0, 0);
    }
  } 
  else {
    if (ctl) {
      rtn |= ten_mpif_clock_select_prot(TEN_MOD_ID_TO_DEV_ID(module_id_a), 0, 0, 1<<slice, 1<<slice);
    }
    else {
      rtn |= ten_mpif_clock_select_prot(TEN_MOD_ID_TO_DEV_ID(module_id_a), 0, 0, 
                                        (~(1<<slice))&0x0F, 
                                        (~(1<<slice))&0x0F);
    }
  }

  /* RX Protection Switch Control */
  rtn |= ten_hsif_provision_pswtchen(module_id_a, slice, CS_RX, ctl);
                                     
   /* TX Protection Bridge Config */
  rtn |= ten_hsif_provision_pswtchen(module_id_b, slice, CS_TX, ctl);
  
  /* After switching to "protection", it is recommended to initialize     */
  /* the TX phase compensation FIFO.                                      */
  rtn |= ten_hsif_tx_protection_switching_elastic_store_control(module_id_b,
                                             slice, CS_RESET_TOGGLE);
   
   /* it is recommended to initialize the RX phase compensation FIFO.  */
  rtn |= ten_hsif_rx_protection_switching_elastic_store_control(module_id_a, 
                                             slice, CS_RESET_TOGGLE);
                                             
  return (rtn);
}

/* Bugzilla 26403 Start */
/********************************************************************/
/* $rtn_hdr_start  HIGH LEVEL HSIF XFI CHECK_KPGA                   */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : HIGH LEVEL                                          */
/* CHIP       : Tenabo                                              */
cs_status ten_hl_hsif_xfi_check_kpga (cs_uint16 module_id, 
                                      cs_uint8 slice)
/* INPUTS     : o Module Id                                         */
/*              o Slice                                             */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Checkes status of XFI HSIF KPGA                                  */
/*                                                                  */
/* [slice]  Specified as TEN_SLICE0 (0), TEN_SLICE1 (1),            */
/*   TEN_SLICE2 (2), TEN_SLICE3 (3) or TEN_SLICE_ALL (0xFF)         */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  cs_uint16 sl;
  cs_uint32 prbs_count;
  T41_t *pDev = NULL;
  cs_status rtn = CS_OK;
  cs_char8 *func = "ten_hl_hsif_xfi_check_kpga";  

  if ((slice>=TEN_MAX_SLICES) && (slice != TEN_SLICE_ALL)) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, "%S() slice out of range.  s/b 0..3 or 0xFF.", func);
    return (CS_ERROR);
  }
  
  if (slice == TEN_SLICE_ALL) {
    CS_PRINT("%s() SLICE_ALL\n", func);
  } else {  
    CS_PRINT("%s(), %s\n", func, ten_slice_strings[slice]);
  }  


  TEN_MOD_COMMON_VALIDATE(module_id, pDev, 0);
  for (sl=0; sl<TEN_MAX_SLICES; sl++) {
    if ((slice == sl) || (slice == TEN_SLICE_ALL)) {
      /* FILT_LOCKs and LOCKs */
      if (ten_xfi32x1_txlockd0_lock (module_id, sl) != 1) {
        rtn |= CS_ERROR;
        CS_PRINT ("%s() HSIF_KPGA test: %s TX not locked!\n", func, ten_slice_strings[sl]);
      }    
      if (ten_xfi32x1_txlockd0_filt_lock (module_id, sl) != 1) {
        rtn |= CS_ERROR;
        CS_PRINT ("%s() HSIF_KPGA test: %s TX not filt locked!\n", func, ten_slice_strings[sl]);
      }    
      if (ten_xfi32x1_txlockd0_data_dets (module_id, sl) != 1) {
        rtn |= CS_ERROR;
        CS_PRINT ("%s() HSIF_KPGA test: %s TX data not detected!\n", func, ten_slice_strings[sl]);
      }    

      if (ten_xfi32x1_rxlockd0_lock (module_id, sl) != 1) {
        rtn |= CS_ERROR;
        CS_PRINT ("%s() HSIF_KPGA test: %s RX not locked!\n", func, ten_slice_strings[sl]);
      }    
      if (ten_xfi32x1_rxlockd0_filt_lock (module_id, sl) != 1) {
        rtn |= CS_ERROR;
        CS_PRINT ("%s() HSIF_KPGA test: %s RX not filt locked!\n", func, ten_slice_strings[sl]);
      }    
      if (ten_xfi32x1_rxlockd0_data_dets (module_id, sl) != 1) {
        rtn |= CS_ERROR;
        CS_PRINT ("%s() HSIF_KPGA test: %s RX data not detected!\n", func, ten_slice_strings[sl]);
      }
      
      if (!ten_xfi32x1_prbschk_get_status (module_id, sl)) {
        rtn |= CS_ERROR;
        CS_PRINT ("%s() HSIF_KPGA test: %s PRBS not in sync!\n", func, ten_slice_strings[sl]);
      }
      
          
      /* Read prbs error count to clear it */
      prbs_count = ten_xfi32x1_rx0_get_prbsck0_count (module_id, sl);
CS_PRINT ("%s(%s) prbs_count = 0x%X\n", func, ten_slice_strings[sl], prbs_count);
      
      /* insertonebiterroronce.  Must be a transition from 0 to 1 */
      ten_xfi32x1_prbsgen_control (module_id, sl, 0, 0, 0, 0);
      ten_xfi32x1_prbsgen_control (module_id, sl, 0, 0, 0, 1);
      
      prbs_count = ten_xfi32x1_rx0_get_prbsck0_count (module_id, sl);
CS_PRINT ("%s(%s) prbs_count = 0x%X\n", func, ten_slice_strings[sl], prbs_count);
      if (prbs_count != 1) {
        rtn |= CS_ERROR;
        CS_PRINT ("%s() HSIF_KPGA test ERROR: slice %s error count = 0x%X!  it should = 1\n", func, ten_slice_strings[sl], prbs_count);
      }
    }
  }
  return (rtn);
}
/* Bugzilla 26403 End */

/********************************************************************/
/* $rtn_hdr_start  HIGH LEVEL HSIF MR RESYNC                        */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : HIGH LEVEL                                          */
/* CHIP       : Tenabo                                              */
cs_status ten_hl_hsif_mr_resync(cs_uint16 module_id, 
                                cs_uint8 slice,
                                cs_dir_t dir)
/* INPUTS     : o Module Id                                         */
/*              o Slice                                             */
/*              o Direction                                         */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Toggles the MR RX and TX resync.                                 */
/*                                                                  */
/* [slice]  Specified as TEN_SLICE0 (0), TEN_SLICE1 (1),            */
/*   TEN_SLICE2 (2), TEN_SLICE3 (3) or TEN_SLICE_ALL (0xFF)         */
/*                                                                  */
/* The [dir] parameter is specified as:                             */
/*   0 = CS_TX                                                      */
/*   1 = CS_RX                                                      */
/*   2 = CS_TX_AND_RX.                                              */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  cs_status rtn = CS_OK;
  cs_uint16 ii;
  cs_uint16 resync = 0;
  
  CS_PRINT("ten_hl_hsif_mr_resync:  mod_id=0x%04X, sl=%d, dir=%d\n", 
           module_id, slice, dir);
  
  if(dir > CS_TX_AND_RX) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": parm out of range."); 
    return (CS_ERROR);
  }
  
  /* Resync the RX and TX elastic stores */
  for (ii=0; ii<2; ii++) {
    if (ii==0) {
      resync = 1;
    }
    else {
      resync = 0;
    }
    
    if ((slice == 0) || (slice == TEN_SLICE_ALL)) {
      if ((dir == CS_RX) || (dir == CS_TX_AND_RX)) {
        ten_hsif_slc0_mr10x4_sds_common_rxelst0_resync(module_id, TEN_INSTANCE_ALL, resync);
      }
      if ((dir == CS_TX) || (dir == CS_TX_AND_RX)) {
        ten_hsif_slc0_mr10x4_sds_common_txelst0_resync(module_id, resync);
      }
    }
    if ((slice == 1) || (slice == TEN_SLICE_ALL)) {
      if ((dir == CS_RX) || (dir == CS_TX_AND_RX)) {
        ten_hsif_slc1_mr10x5_sds_common_rxelst0_resync(module_id, TEN_INSTANCE_ALL, resync);
      }
      if ((dir == CS_TX) || (dir == CS_TX_AND_RX)) {
        ten_hsif_slc1_mr10x5_sds_common_txelst0_resync(module_id, resync);
      }
    }
    if ((slice == 2) || (slice == TEN_SLICE_ALL)) {
      if ((dir == CS_RX) || (dir == CS_TX_AND_RX)) {
        ten_hsif_slc2_mr10x4_sds_common_rxelst0_resync(module_id, TEN_INSTANCE_ALL, resync);
      }
      if ((dir == CS_TX) || (dir == CS_TX_AND_RX)) {
        ten_hsif_slc2_mr10x4_sds_common_txelst0_resync(module_id, resync);
      }
    }
    if ((slice == 3) || (slice == TEN_SLICE_ALL)) {
      if ((dir == CS_RX) || (dir == CS_TX_AND_RX)) {
        ten_hsif_slc3_mr10x5_sds_common_rxelst0_resync(module_id, TEN_INSTANCE_ALL, resync);
      }
      if ((dir == CS_TX) || (dir == CS_TX_AND_RX)) {
        ten_hsif_slc3_mr10x5_sds_common_txelst0_resync(module_id, resync);
      }
    }
    TEN_MDELAY(TEN_HRESET_MSEC_DELAY);
  }
  return (rtn);
}

/********************************************************************/
/* $rtn_hdr_start  HIGH LEVEL HSIF CONTROL MR TX OUTPUT             */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : HIGH LEVEL                                          */
/* CHIP       : Tenabo                                              */
cs_status ten_hl_hsif_control_mr_tx_output(cs_uint16 module_id, 
                                           cs_uint8 slice,
                                           cs_ctl_t ctl)
/* INPUTS     : o Module Id                                         */
/*              o Slice                                             */
/*              o Control                                           */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Controls MR TX output.                                           */
/*                                                                  */
/* [slice]  Specified as TEN_SLICE0 (0), TEN_SLICE1 (1),            */
/*   TEN_SLICE2 (2), TEN_SLICE3 (3) or TEN_SLICE_ALL (0xFF)         */
/*                                                                  */
/* The [ctl] parameter specifies the control option:                */
/*   0 = CS_DISABLE (0) to disable tx output                        */
/*   1 = CS_ENABLE (1) to enable tx output.                         */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  cs_status rtn = CS_OK;
  CS_PRINT("ten_hl_hsif_control_mr_tx_output, mod_id=0x%04X, sl=%d, ctl=%d\n",
           module_id, slice, ctl);
  
  if ((ctl != CS_DISABLE) && (ctl != CS_ENABLE)) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_RANGE_ERR, ": ctl = 0x%04X\n", ctl);
    return (CS_ERROR);
  }

  if (ctl) {
    if ((slice == TEN_SLICE0) || (slice == TEN_SLICE_ALL)) {
      rtn |= ten_hsif_slc0_mr10x4_sds_common_stx0_tx_output_ctrla(module_id, TEN_INSTANCE_ALL, 0x30);
      rtn |= ten_hsif_slc0_mr10x4_sds_common_stx0_tx_output_ctrlb(module_id, TEN_INSTANCE_ALL,  0, 2);
    }
    if ((slice == TEN_SLICE1) || (slice == TEN_SLICE_ALL)) {
      rtn |= ten_hsif_slc1_mr10x5_sds_common_stx0_tx_output_ctrla(module_id, TEN_INSTANCE_ALL, 0x30);
      rtn |= ten_hsif_slc1_mr10x5_sds_common_stx0_tx_output_ctrlb(module_id, TEN_INSTANCE_ALL, 0, 2);
    }
    if ((slice == TEN_SLICE2) || (slice == TEN_SLICE_ALL)) {
      rtn |= ten_hsif_slc2_mr10x4_sds_common_stx0_tx_output_ctrla(module_id, TEN_INSTANCE_ALL, 0x30);
      rtn |= ten_hsif_slc2_mr10x4_sds_common_stx0_tx_output_ctrlb(module_id, TEN_INSTANCE_ALL,  0, 2);
    }
    if ((slice == TEN_SLICE3) || (slice == TEN_SLICE_ALL)) {
      rtn |= ten_hsif_slc3_mr10x5_sds_common_stx0_tx_output_ctrla(module_id, TEN_INSTANCE_ALL, 0x30);
      rtn |= ten_hsif_slc3_mr10x5_sds_common_stx0_tx_output_ctrlb(module_id, TEN_INSTANCE_ALL, 0, 2);
    }
  }                                                      
  else {                                                 
    if ((slice == TEN_SLICE0) || (slice == TEN_SLICE_ALL)) {
      rtn |= ten_hsif_slc0_mr10x4_sds_common_stx0_tx_output_ctrla(module_id, TEN_INSTANCE_ALL, 0);
      rtn |= ten_hsif_slc0_mr10x4_sds_common_stx0_tx_output_ctrlb(module_id, TEN_INSTANCE_ALL,  0, 0);
    }
    /* Bugzilla #31703, API ten_hl_hsif_control_mr_tx_output fix, use correct SLICE1, SLICE2, SLICE3 enums */
    if ((slice == TEN_SLICE1) || (slice == TEN_SLICE_ALL)) {
      rtn |= ten_hsif_slc1_mr10x5_sds_common_stx0_tx_output_ctrla(module_id, TEN_INSTANCE_ALL, 0);
      rtn |= ten_hsif_slc1_mr10x5_sds_common_stx0_tx_output_ctrlb(module_id, TEN_INSTANCE_ALL, 0, 0);
    }
    if ((slice == TEN_SLICE2) || (slice == TEN_SLICE_ALL)) {
      rtn |= ten_hsif_slc2_mr10x4_sds_common_stx0_tx_output_ctrla(module_id, TEN_INSTANCE_ALL, 0);
      rtn |= ten_hsif_slc2_mr10x4_sds_common_stx0_tx_output_ctrlb(module_id, TEN_INSTANCE_ALL,  0, 0);
    }
    if ((slice == TEN_SLICE3) || (slice == TEN_SLICE_ALL)) {
      rtn |= ten_hsif_slc3_mr10x5_sds_common_stx0_tx_output_ctrla(module_id, TEN_INSTANCE_ALL, 0);
      rtn |= ten_hsif_slc3_mr10x5_sds_common_stx0_tx_output_ctrlb(module_id, TEN_INSTANCE_ALL, 0, 0);
    }
  }
  return (rtn);
}

/* Bugzilla #28476 - Need to power down unused HSIF SERDES lanes/slices  */
/********************************************************************/
/* $rtn_hdr_start  HIGH LEVEL HSIF POWER DOWN SERDES                */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : HIGH LEVEL                                          */
/* CHIP       : Tenabo                                              */
cs_status ten_hl_hsif_power_down_serdes(cs_uint16 module_id)
/* INPUTS     : o Module Id                                         */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Powers down all Transmit and Receive Serdes for MR and XFI.      */
/* SERDES are automatically powered back up during                  */
/* HSIF initialization, as needed.                                  */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  cs_status rtn = CS_OK;

  /* power down TX and RX on all slices of MR */
  rtn |= ten_hsif_slc0_mr10x4_sds_common_stxp0_tx_pwrdn_all(module_id, 1);
  rtn |= ten_hsif_slc2_mr10x4_sds_common_stxp0_tx_pwrdn_all(module_id, 1);

  rtn |= ten_hsif_slc0_mr10x4_sds_common_stxp0_tx_pwrdn_pd_lane(module_id, 0x1F);
  rtn |= ten_hsif_slc2_mr10x4_sds_common_stxp0_tx_pwrdn_pd_lane(module_id, 0x1F);

  rtn |= ten_hsif_slc0_mr10x4_sds_common_srx0_srx_pd(module_id, TEN_INSTANCE_ALL, 1);
  rtn |= ten_hsif_slc2_mr10x4_sds_common_srx0_srx_pd(module_id, TEN_INSTANCE_ALL, 1);

  rtn |= ten_hsif_slc1_mr10x5_sds_common_stxp0_tx_pwrdn_all(module_id, 1);
  rtn |= ten_hsif_slc3_mr10x5_sds_common_stxp0_tx_pwrdn_all(module_id, 1);

  rtn |= ten_hsif_slc1_mr10x5_sds_common_stxp0_tx_pwrdn_pd_lane(module_id, 0x1F);
  rtn |= ten_hsif_slc3_mr10x5_sds_common_stxp0_tx_pwrdn_pd_lane(module_id, 0x1F);

  rtn |= ten_hsif_slc1_mr10x5_sds_common_srx0_srx_pd(module_id, TEN_INSTANCE_ALL, 1);
  rtn |= ten_hsif_slc3_mr10x5_sds_common_srx0_srx_pd(module_id, TEN_INSTANCE_ALL, 1);

  if (TEN_MOD_ID_TO_MOD_NUM(module_id) == TEN_MODULE_B) {
    /* power down XFI for module B */
    rtn |= ten_xfi32x1_stxp0_tx_pwrdn_all(module_id, TEN_SLICE_ALL, 1);
    rtn |= ten_xfi32x1_stxp0_tx_pwrdn_pd_lane(module_id, TEN_SLICE_ALL, 0x1F);
    rtn |= ten_xfi32x1_srx0_rx_srx_pd(module_id, TEN_SLICE_ALL, 1);
  }
  
  return (rtn);
}








