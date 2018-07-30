#include <stdlib.h>
#include <string.h>
#include <ini.h>
#include <sys/syslog.h>
#include "parser.h"

static int handler(void* user, const char* section, const char* name,
                   const char* value)
{
    config_t* pconfig = (config_t*)user;

    #define MATCH(s, n) strcmp(section, s) == 0 && strcmp(name, n) == 0
    #define MATCH_S(s) strcmp(section, s) == 0
    #define MATCH_N(n) strcmp(name, n) == 0

    if (MATCH_S("wrng_high_tmp")) {
        if (MATCH_N("remote1")) {    
            pconfig->tmp.wrng_high_tmp[0] = atoi(value);
        } else if (MATCH_N("remote2")) {
            pconfig->tmp.wrng_high_tmp[1] = atoi(value);
        } else if (MATCH_N("remote3")) {
            pconfig->tmp.wrng_high_tmp[2] = atoi(value);
        } else if (MATCH_N("remote4")) {
            pconfig->tmp.wrng_high_tmp[3] = atoi(value);
        } else if (MATCH_N("remote5")) {
            pconfig->tmp.wrng_high_tmp[4] = atoi(value);
        } else if (MATCH_N("remote6")) {
            pconfig->tmp.wrng_high_tmp[5] = atoi(value);
        } else if (MATCH_N("local")) {
            pconfig->tmp.wrng_high_tmp[6] = atoi(value);
        } else if (MATCH_N("remote7")) {
            pconfig->tmp.wrng_high_tmp[7] = atoi(value);
        } else {
            openlog("mond", LOG_PID|LOG_CONS, LOG_USER);
            syslog(LOG_ERR, "unknown name: %s in section: %s", name, section);
            closelog();
            return 0;  // unknown name, error
        }        
    } else if (MATCH_S("crit_high_tmp")) {
        if (MATCH_N("remote1")) {    
            pconfig->tmp.crit_high_tmp[0] = atoi(value);
        } else if (MATCH_N("remote2")) {
            pconfig->tmp.crit_high_tmp[1] = atoi(value);
        } else if (MATCH_N("remote3")) {
            pconfig->tmp.crit_high_tmp[2] = atoi(value);
        } else if (MATCH_N("remote4")) {
            pconfig->tmp.crit_high_tmp[3] = atoi(value);
        } else if (MATCH_N("remote5")) {
            pconfig->tmp.crit_high_tmp[4] = atoi(value);
        } else if (MATCH_N("remote6")) {
            pconfig->tmp.crit_high_tmp[5] = atoi(value);
        } else if (MATCH_N("local")) {
            pconfig->tmp.crit_high_tmp[6] = atoi(value);
        } else if (MATCH_N("remote7")) {
            pconfig->tmp.crit_high_tmp[7] = atoi(value);
        } else {
            openlog("mond", LOG_PID|LOG_CONS, LOG_USER);
            syslog(LOG_ERR, "unknown name: %s in section: %s", name, section);
            closelog();
            return 0;  // unknown name, error
        }        
    } else if (MATCH_S("wrng_overt_tmp")) {
        if (MATCH_N("local")) {    
            pconfig->tmp.wrng_overt_tmp[6] = atoi(value);
        } else if (MATCH_N("remote1")) {
            pconfig->tmp.wrng_overt_tmp[0] = atoi(value);
        } else if (MATCH_N("remote2")) {
            pconfig->tmp.wrng_overt_tmp[1] = atoi(value);
        } else if (MATCH_N("remote3")) {
            pconfig->tmp.wrng_overt_tmp[2] = atoi(value);
        } else if (MATCH_N("remote4")) {
            pconfig->tmp.wrng_overt_tmp[3] = atoi(value);
        } else if (MATCH_N("remote5")) {
            pconfig->tmp.wrng_overt_tmp[4] = atoi(value);
        } else if (MATCH_N("remote6")) {
            pconfig->tmp.wrng_overt_tmp[5] = atoi(value);
        } else if (MATCH_N("remote7")) {
            pconfig->tmp.wrng_overt_tmp[7] = atoi(value);
        } else {
            openlog("mond", LOG_PID|LOG_CONS, LOG_USER);
            syslog(LOG_ERR, "unknown name: %s in section: %s", name, section);
            closelog();
            return 0;  // unknown name, error
        }        
    } else if (MATCH_S("crit_overt_tmp")) {
        if (MATCH_N("local")) {    
            pconfig->tmp.crit_overt_tmp[6] = atoi(value);
        } else if (MATCH_N("remote1")) {
            pconfig->tmp.crit_overt_tmp[0] = atoi(value);
        } else if (MATCH_N("remote2")) {
            pconfig->tmp.crit_overt_tmp[1] = atoi(value);
        } else if (MATCH_N("remote3")) {
            pconfig->tmp.crit_overt_tmp[2] = atoi(value);
        } else if (MATCH_N("remote4")) {
            pconfig->tmp.crit_overt_tmp[3] = atoi(value);
        } else if (MATCH_N("remote5")) {
            pconfig->tmp.crit_overt_tmp[4] = atoi(value);
        } else if (MATCH_N("remote6")) {
            pconfig->tmp.crit_overt_tmp[5] = atoi(value);
        } else if (MATCH_N("remote7")) {
            pconfig->tmp.crit_overt_tmp[7] = atoi(value);
        } else {
            openlog("mond", LOG_PID|LOG_CONS, LOG_USER);
            syslog(LOG_ERR, "unknown name: %s in section: %s", name, section);
            closelog();
            return 0;  // unknown name, error
        }        
    } else if (MATCH_S("wrng_low_tmp")) {
        if (MATCH_N("allchannels")) {    
            pconfig->tmp.wrng_low_tmp = atoi(value);
        } else {
            openlog("mond", LOG_PID|LOG_CONS, LOG_USER);
            syslog(LOG_ERR, "unknown name: %s in section: %s", name, section);
            closelog();
            return 0;  // unknown name, error
        }
    } else if (MATCH_S("crit_low_tmp")) {
        if (MATCH_N("allchannels")) {    
            pconfig->tmp.crit_low_tmp = atoi(value);
        } else {
            openlog("mond", LOG_PID|LOG_CONS, LOG_USER);
            syslog(LOG_ERR, "unknown name: %s in section: %s", name, section);
            closelog();
            return 0;  // unknown name, error
        }
    } else if (MATCH_S("hmd")) {
        if (MATCH_N("wrng_hmd")) {
            pconfig->hmd.wrng_hmd = atoi(value);
        } else if (MATCH_N("crit_hmd")) {
            pconfig->hmd.crit_hmd = atoi(value);
        } else {
            openlog("mond", LOG_PID|LOG_CONS, LOG_USER);
            syslog(LOG_ERR, "unknown name: %s in section: %s", name, section);
            closelog();
            return 0;  // unknown name, error
        }    
    } else if (MATCH_S("xfp")) {
        if (MATCH_N("wrng_tx_power")) {
            pconfig->xfp.wrng_tx_power = atoi(value);
        } else if (MATCH_N("crit_tx_power")) {
            pconfig->xfp.crit_tx_power = atoi(value);
        } else if (MATCH_N("wrng_rx_power")) {
            pconfig->xfp.wrng_rx_power = atoi(value);
        } else if (MATCH_N("crit_rx_power")) {
            pconfig->xfp.crit_tx_power = atoi(value);
        } else {
            openlog("mond", LOG_PID|LOG_CONS, LOG_USER);
            syslog(LOG_ERR, "unknown name: %s in section: %s", name, section);
            closelog();
            return 0;  // unknown name, error
        }    
    } else if (MATCH_S("qsfp")) {
        if (MATCH_N("crit_temp")) {
            pconfig->qsfp.crit_temp = atoi(value);
        } else if (MATCH_N("wrng_temp")) {
            pconfig->qsfp.wrng_temp = atoi(value);
        } else if (MATCH_N("crit_tx_bias")) {
            pconfig->qsfp.crit_tx_bias = atoi(value);
        } else if (MATCH_N("wrng_tx_bias")) {
            pconfig->qsfp.wrng_tx_bias = atoi(value);
        } else if (MATCH_N("crit_rx_power")) {
            pconfig->qsfp.crit_rx_power = atoi(value);
        } else if (MATCH_N("wrng_rx_power")) {
            pconfig->qsfp.wrng_rx_power = atoi(value);
        } else {
            openlog("mond", LOG_PID|LOG_CONS, LOG_USER);
            syslog(LOG_ERR, "unknown name: %s in section: %s", name, section);
            closelog();
            return 0;  // unknown name, error
        }    
    } else if (MATCH_S("txp")) {
        if (MATCH_N("rx_pow_alm")) {
            pconfig->txp.rx_pow_alm = atoi(value);
        } else if (MATCH_N("rx_pow_idle")) {
            pconfig->txp.rx_pow_idle = atoi(value);
        } else if (MATCH_N("mod_bias_high_alm")) {
            pconfig->txp.mod_bias_high_alm = atoi(value);
        } else if (MATCH_N("mod_bias_low_alm")) {
            pconfig->txp.mod_bias_low_alm = atoi(value);
        } else if (MATCH_N("mod_bias_high_idle")) {
            pconfig->txp.mod_bias_high_idle = atoi(value);
        } else if (MATCH_N("mod_bias_low_idle")) {
            pconfig->txp.mod_bias_low_idle = atoi(value);
        } else if (MATCH_N("lo_ls_bias_alm")) {
            pconfig->txp.lo_ls_bias_alm = atoi(value);
        } else if (MATCH_N("lo_ls_bias_idle")) {
            pconfig->txp.lo_ls_bias_idle = atoi(value);
        } else if (MATCH_N("temp_idle")) {
            pconfig->txp.temp_idle = atoi(value);
        } else if (MATCH_N("temp_alm")) {
            pconfig->txp.temp_alm = atoi(value);
        } else if (MATCH_N("tx_pow_high_alm")) {
            pconfig->txp.tx_pow_high_alm = atoi(value);
        } else if (MATCH_N("tx_pow_low_alm")) {
            pconfig->txp.tx_pow_low_alm = atoi(value);
        } else if (MATCH_N("tx_pow_high_idle")) {
            pconfig->txp.tx_pow_high_idle = atoi(value);
        } else if (MATCH_N("tx_pow_low_idle")) {
            pconfig->txp.tx_pow_low_idle = atoi(value);
        } else if (MATCH_N("rx_pow_alm_rxlos")) {
            pconfig->txp.rx_pow_alm_rxlos = atoi(value);
        } else if (MATCH_N("rx_pow_idle_rxlos")) {
            pconfig->txp.rx_pow_idle_rxlos = atoi(value);
        } else if (MATCH_N("rx_pow_alm_rxs")) {
            pconfig->txp.rx_pow_alm_rxs = atoi(value);
        } else if (MATCH_N("rx_pow_idle_rxs")) {
            pconfig->txp.rx_pow_idle_rxs = atoi(value);
        } else if (MATCH_N("rx_pow_high_alm")) {
            pconfig->txp.rx_pow_high_alm = atoi(value);
        } else if (MATCH_N("rx_pow_high_idle")) {
            pconfig->txp.rx_pow_high_idle = atoi(value);
        } else if (MATCH_N("ls_bias_alm")) {
            pconfig->txp.ls_bias_alm = atoi(value);
        } else if (MATCH_N("ls_bias_idle")) {
            pconfig->txp.ls_bias_idle = atoi(value);
        } else if (MATCH_N("dsp_temp_mon")) {
            pconfig->txp.dsp_temp_mon = atoi(value);
        } else {
            openlog("mond", LOG_PID|LOG_CONS, LOG_USER);
            syslog(LOG_ERR, "unknown name: %s in section: %s", name, section);
            closelog();
            return 0;  // unknown name, error
        }    
    } else {
        openlog("mond", LOG_PID|LOG_CONS, LOG_USER);
        syslog(LOG_ERR, "unknown section: %s", section);
        closelog();
        return 0; // unknown section, error
    }
    //printf("Parse: %s %s\n", section, name);
    return 1;

}

int get_config(const char *filename, config_t *config) 
{
    if (ini_parse(filename, handler, config) < 0) {
        openlog("mond", LOG_PID|LOG_CONS, LOG_USER);
        syslog(LOG_ERR, "Can't load '%s'", filename);
        closelog();
        return 1;
    }

    openlog("mond", LOG_PID|LOG_CONS, LOG_USER);
    syslog(LOG_ERR, "Config loaded from '%s'", filename);
    closelog();
    return 0;
}

/*
int main(int argc, char* argv[])
{
    config_t config;

    get_config("mond.conf", &config);

    int i;
    for (i = 0; i < 8; i++){
        printf("config.crit_high_tmp[%d] = %d\n",i,config.crit_high_tmp[i]);
    }

    for (i = 0; i < 8; i++){
        printf("config.crit_overt_tmp[%d] = %d\n",i,config.crit_overt_tmp[i]);
    }

    for (i = 0; i < 8; i++){
        printf("config.crit_low_tmp[%d] = %d\n",i,config.crit_low_tmp[i]);
    }
    return 0;
}
*/
