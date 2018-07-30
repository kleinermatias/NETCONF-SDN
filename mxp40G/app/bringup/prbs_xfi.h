#ifndef __prbs_xfi_H__
#define __prbs_xfi_H__


#define RELEASE_PLATFORM
#define CS_LITTLE_ENDIAN
#define MAX_DEVICE  2

#include "tenabo40.h"
#include "../../lib/txp/txp.h"
#include "../../lib/cs6041/cs6041.h"

int setup_xfp_module(int module_id, int loopback);
void get_ber(cs_uint16 module_client, int port);

void eth10g (
    cs_uint16 dev_id,
    cs_uint8  slice_line,
    cs_uint8  slice_client,
    cs_uint16 sysrefclk,        /* freq in MHz */
    cs_uint8  dyn_repro,        /* 0 = static, 1 = DR client only, 2 = DR line and client */
    cs_uint8  auxclk,           /* 0 = don't use auxclk, 1 = use auxclk */
    cs_uint8  xfi_clk_dist );
    
int otu2_gfec_transparent_bmp_amp_xfi_b_ccupll_400_otu3_gfec_sfi5_1_a_k_64 (
    cs_uint16 dev_id,
    cs_uint8  slice_line,
    cs_uint8  slice_client,
    cs_uint16 sysrefclk,        /* freq in MHz */
    cs_uint8  dyn_repro,        /* 0 = static, 1 = DR client only, 2 = DR line and client */
    cs_uint8  auxclk,           /* 0 = don't use auxclk, 1 = use auxclk */
    cs_uint8  xfi_clk_dist );

#endif
