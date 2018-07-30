#ifndef __10GE_H__
#define __10GE_H__


#define RELEASE_PLATFORM
#define CS_LITTLE_ENDIAN

#include "tenabo40.h"

#include "cs_types.h"


T41_t Chips;

void eth10g (
    cs_uint16 dev_id,
    cs_uint8  slice_line,
    cs_uint8  slice_client,
    cs_uint16 sysrefclk,        /* freq in MHz */
    cs_uint8  dyn_repro,        /* 0 = static, 1 = DR client only, 2 = DR line and client */
    cs_uint8  auxclk,           /* 0 = don't use auxclk, 1 = use auxclk */
    cs_uint8  xfi_clk_dist );


#endif
