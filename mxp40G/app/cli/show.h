#ifndef __SHOW_H__
#define __SHOW_H__

#define RELEASE_PLATFORM
#define CS_LITTLE_ENDIAN

#include "tenabo40.h"
#include "../../lib/txp/txp.h"
#include "../../lib/edfa/edfa.h"
#include "../../lib/gpio/gpio.h"
#include "../../lib/clk/clk.h"
#include "../../lib/fan/fan.h"
#include "../../lib/tmp/tmp.h"
#include "../../lib/hmd/hmd.h"
#include "../../lib/xfp/xfp.h"
#include "../../lib/qsfp/qsfp.h"

T41_t Chips;
cs_uint16 dev_id;
cs_uint16 module_line;
cs_uint16 module_client;


int charToInt(char *opt);
void show_optics_parameters(int port);
void show_fec(int port);
void show_eth(int port);
void show_otn(int port);
void showJDSU();
void showEdfa();
void doc();
int initialize();
void print_status(const char* msg, cs_status status);
void print_defects(const char* msg, cs_status status);
void showConditions();
void showStatus(int side,int port);
void showInfo();
#endif
