#ifndef __CONFIG_H__
#define __CONFIG_H__


#define RELEASE_PLATFORM
#define CS_LITTLE_ENDIAN
#define MAX_DEVICE  2

//define RESET       "\033[0m"
#define BLACK       "\033[30m"          /* Black */
#define RED         "\033[31m"          /* Red */
#define GREEN       "\033[32m"          /* Green */
#define YELLOW      "\033[33m"          /* Yellow */
#define BLUE        "\033[34m"          /* Blue */
#define MAGENTA     "\033[35m"          /* Magenta */
#define CYAN        "\033[36m"          /* Cyan */
#define WHITE       "\033[37m"          /* White */
#define BOLDBLACK   "\033[1m\033[30m"   /* Bold Black */
#define BOLDRED     "\033[1m\033[31m"   /* Bold Red */
#define BOLDGREEN   "\033[1m\033[32m"   /* Bold Green */
#define BOLDYELLOW  "\033[1m\033[33m"   /* Bold Yellow */
#define BOLDBLUE    "\033[1m\033[34m"   /* Bold Blue */
#define BOLDMAGENTA "\033[1m\033[35m"   /* Bold Magenta */
#define BOLDCYAN    "\033[1m\033[36m"   /* Bold Cyan */
#define BOLDWHITE   "\033[1m\033[37m"   /* Bold White */

#include "tenabo40.h"
#include "../../lib/txp/txp.h"
#include "../../lib/xfp/xfp.h"
T41_t Chips;

cs_uint16 dev_id;
cs_uint16 module_id_line;
cs_uint16 module_id_client;
cs_uint8 dyn_repro;

const char *nombre_programa;

struct entry_s {
	char *key;
	char *value;
	struct entry_s *next;
};
 
typedef struct entry_s entry_t;
 
struct hashtable_s {
	int size;
	struct entry_s **table;	
};
 
typedef struct hashtable_s hashtable_t;
 
 
int initialize();
void print_status(const char *msg, cs_status status);
void print_defects(const char *msg, cs_status status);
void doc();
int getChannel(char *arg);
int getBand(char *arg);
int charToInt(char *opt);
void configT41();
int configJDSU(); 
void print_xfp_info(int port);
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
int initJDSU();
int configJdsuChannel(unsigned char channel, float wl, int side) ;
void configEDFA();
hashtable_t *ht_create( int size );
int ht_hash( hashtable_t *hashtable, char *key );
entry_t *ht_newpair( char *key, char *value );
void ht_set( hashtable_t *hashtable, char *key, char *value ); 
char *ht_get( hashtable_t *hashtable, char *key );
void crear_tabla();
#endif
