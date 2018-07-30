#ifndef __prbs_sfi51_H__
#define __prbs_sfi51_H__


#define RELEASE_PLATFORM
#define CS_LITTLE_ENDIAN
#define MAX_DEVICE  2

#include <stdio.h>
#include <getopt.h>
#include <string.h>
#include <stdlib.h>
#include <getopt.h>
#include "prbs_xfi.h"
#include "../../lib/xfp/xfp.h"
#include "../../lib/gpio/gpio.h"
#include "../../lib/txp/txp.h"
#include "../../lib/cs6041/cs6041.h"
#include "tenabo40.h"

T41_t Chips;

cs_uint16 dev_id;
cs_uint16 module_line;
cs_uint16 module_client;
cs_uint8 dyn_repro;

const char *nombre_programa;


int initialize();
int setup_xfp_module(int module_id, int loopback);


#endif
