#include "logger.h"
#include "../../lib/tmp/tmp.h"
#include "../../lib/hmd/hmd.h"
#include "../../lib/ltc/ltc.h"
#include "../../lib/xfp/xfp.h"
#include "../../lib/qsfp/qsfp.h"
#include "../../lib/txp/txp.h"
#include "../../lib/bitman/bitman.h"
#include <sys/syslog.h>
#include "parser.h"
#include <util.h>

#define RELEASE_PLATFORM
#define CS_LITTLE_ENDIAN

#include "tenabo40.h"

T41_t Chips;
cs_uint16 dev_id;
cs_uint16 module_line;
cs_uint16 module_client;

const char* pname = "mond";

int init_tmp(tmp_t *ptmp) {

    temp_registers_t temp_regs;
    temp_regs.main_bits = 0;
    temp_regs.extended_bits = 0;    
    int offset;

#ifdef TESTING
    tmp_enable_extrange_mock();
#else
    tmp_enable_extrange();
#endif

    // High Threshold Limits

    for (offset = 0; offset <= 7; offset++)
    {

#ifdef TESTING
        tmp_celsius_to_ext_temp_regs_mock(
            (float)(ptmp->wrng_high_tmp[offset]),
            &temp_regs);
#else
        tmp_celsius_to_ext_temp_regs(
            (float)(ptmp->wrng_high_tmp[offset]),
            &temp_regs);
#endif

#ifdef TESTING
        tmp_set_alert_high_limit_reg_mock(
            TMP_REMOTE_1_ALERT_HIGH_LIMIT_REG + offset, 
            temp_regs.main_bits); 
#else
        tmp_set_alert_high_limit_reg(
            TMP_REMOTE_1_ALERT_HIGH_LIMIT_REG + offset, 
            temp_regs.main_bits); 
#endif

#ifdef TESTING
        tmp_set_mask_alert_mock(offset, 0);  // unmasked (default)
#else
        tmp_set_mask_alert(offset, 0);  // unmasked (default)
#endif

    }    

    // OVERT Threshold Limits

    for (offset = 0; offset <= 7; offset++)
    {

#ifdef TESTING
        tmp_celsius_to_ext_temp_regs_mock(
            (float)(ptmp->wrng_overt_tmp[offset]),
            &temp_regs);
#else
        tmp_celsius_to_ext_temp_regs(
            (float)(ptmp->wrng_overt_tmp[offset]),
            &temp_regs);
#endif

#ifdef TESTING
        tmp_set_overt_high_limit_reg_mock(
            TMP_LOCAL_OVERT_HIGH_LIMIT_REG + offset, 
            temp_regs.main_bits); 
#else
        tmp_set_overt_high_limit_reg(
            TMP_LOCAL_OVERT_HIGH_LIMIT_REG + offset, 
            temp_regs.main_bits); 
#endif

#ifdef TESTING
        tmp_set_mask_overt_mock(offset, 0);  // unmasked (default)
#else
        tmp_set_mask_overt(offset, 0);  // unmasked (default)
#endif

    }

    // Low Threshold Limits

#ifdef TESTING
    tmp_celsius_to_ext_temp_regs_mock(
        (float)(ptmp->wrng_low_tmp),
        &temp_regs);
#else
    tmp_celsius_to_ext_temp_regs(
        (float)(ptmp->wrng_low_tmp),
        &temp_regs);
#endif

#ifdef TESTING
    tmp_set_alert_low_limit_reg_mock(temp_regs.main_bits); 
#else
    tmp_set_alert_low_limit_reg(temp_regs.main_bits); 
#endif

    for (offset = 0; offset <= 7; offset++)
    {

#ifdef TESTING
        tmp_set_alert_low_disable_bit_mock(offset, 0);  // alert low enable
#else
        tmp_set_alert_low_disable_bit(offset, 0);  // alert low enable
#endif

//       openlog("Hola", LOG_PID|LOG_CONS, LOG_USER);
//        syslog(LOG_CRIT, "main_bits = %X, extended_bits = %X, celcius = %d", 
//            temp_regs.main_bits, temp_regs.extended_bits, 
//            pconfig->wrng_high_tmp[offset]);
//        closelog();

    }
    
    return 0;
}

int log_tmp(tmp_t *ptmp) {

    int alert_high_status_reg;
    int overt_status_reg;
    int diode_fault_status_reg;
    int alert_low_status_reg;

#ifdef TESTING
    tmp_get_alert_high_status_reg_mock(&alert_high_status_reg);
#else
    tmp_get_alert_high_status_reg(&alert_high_status_reg);
#endif

    int flg_pos;
    int flg_value;

    int main_bits;
    int extended_bits;
    float celsius_temp;

    for (flg_pos = 0; flg_pos <= 7; flg_pos++)
    {
        get_bit(alert_high_status_reg, flg_pos, &flg_value);

        if (flg_value) 
        {

#ifdef TESTING
            tmp_get_ext_temp_mock(TMP_REMOTE_1_REG + flg_pos, &celsius_temp);
#else
            tmp_get_ext_temp(TMP_REMOTE_1_REG + flg_pos, &celsius_temp);
#endif

            if (celsius_temp < ptmp->crit_high_tmp[flg_pos])
            { 
                openlog("TMP", LOG_PID|LOG_CONS, LOG_USER);
                syslog(LOG_WARNING, TMP_ALERT, "Warn",flg_pos+1, celsius_temp);
                closelog();
            }
            else
            { 
                openlog("TMP", LOG_PID|LOG_CONS, LOG_USER);
                syslog(LOG_CRIT, TMP_ALERT, "Crit",flg_pos+1, celsius_temp);
                closelog();
            }
        }            
    }


#ifdef TESTING
    tmp_get_overt_status_reg_mock(&overt_status_reg);
#else
    tmp_get_overt_status_reg(&overt_status_reg);
#endif

    for (flg_pos = 0; flg_pos <= 7; flg_pos++)
    {
        get_bit(overt_status_reg, flg_pos, &flg_value);
        if (flg_value)
        {

#ifdef TESTING
            tmp_get_ext_temp_mock(TMP_REMOTE_1_REG + flg_pos, &celsius_temp);
#else
            tmp_get_ext_temp(TMP_REMOTE_1_REG + flg_pos, &celsius_temp);
#endif

            if (celsius_temp < ptmp->crit_overt_tmp[flg_pos]) 
            {
                openlog("TMP", LOG_PID|LOG_CONS, LOG_USER);
                syslog(LOG_WARNING, TMP_OVERT, "Warn",flg_pos+1, celsius_temp);
                closelog();
            }
            else
            {
                openlog("TMP", LOG_PID|LOG_CONS, LOG_USER);
                syslog(LOG_CRIT, TMP_OVERT, "Crit",flg_pos+1, celsius_temp);
                closelog();
            }
        }            
    }


#ifdef TESTING
    tmp_get_diode_fault_status_reg_mock(&diode_fault_status_reg);
#else
    tmp_get_diode_fault_status_reg(&diode_fault_status_reg);
#endif

    for (flg_pos = 0; flg_pos <= 7; flg_pos++)
    {
        get_bit(diode_fault_status_reg, flg_pos, &flg_value);
        if (flg_value) {
            openlog("TMP", LOG_PID|LOG_CONS, LOG_USER);
            syslog(LOG_CRIT, TMP_DIODEFAULT, "Crit",flg_pos+1);
            closelog();
        }            
    }


#ifdef TESTING
    tmp_get_alert_low_status_reg_mock(&alert_low_status_reg);
#else
    tmp_get_alert_low_status_reg(&alert_low_status_reg);
#endif

    for (flg_pos = 0; flg_pos <= 7; flg_pos++)
    {
        get_bit(alert_low_status_reg, flg_pos, &flg_value);
        if (flg_value) {

#ifdef TESTING
            tmp_get_ext_temp_mock(TMP_REMOTE_1_REG + flg_pos, &celsius_temp);
#else
            tmp_get_ext_temp(TMP_REMOTE_1_REG + flg_pos, &celsius_temp);
#endif

            if (celsius_temp < ptmp->crit_low_tmp) 
            {
                openlog("TMP", LOG_PID|LOG_CONS, LOG_USER);
                syslog(LOG_WARNING, TMP_ALERTLOW, "Warn",flg_pos+1, celsius_temp);
                closelog();
            }
            else
            {
                openlog("TMP", LOG_PID|LOG_CONS, LOG_USER);
                syslog(LOG_CRIT, TMP_ALERTLOW, "Crit",flg_pos+1, celsius_temp);
                closelog();
            }
        }            
    }

    return 0;
}

int init_hmd(void) {

#ifdef TESTING
    hmd_disable_fast_conversion_mock();
#else
    hmd_disable_fast_conversion();
#endif

#ifdef TESTING
    hmd_disable_heater_mock();
#else
    hmd_disable_heater();
#endif

    return 0;
}

int log_hmd(hmd_t *phmd) {

    int temp_comp_humidity;

#ifdef TESTING
    hmd_get_temp_comp_humidity_mock(&temp_comp_humidity);
#else
    hmd_get_temp_comp_humidity(&temp_comp_humidity);
#endif

    if (temp_comp_humidity < phmd->crit_hmd) 
    {
        openlog("HMD", LOG_PID|LOG_CONS, LOG_USER);
        syslog(LOG_WARNING, HMD_ALERT, "Warn", temp_comp_humidity);
        closelog();
    }
    else
    {
        openlog("HMD", LOG_PID|LOG_CONS, LOG_USER);
        syslog(LOG_CRIT, HMD_ALERT, "Crit",temp_comp_humidity);
        closelog();
    }
    return 0;
}

int init_xfp(xfp_t *pxfp) {

    int xfp_mod;

#ifdef TESTING
    ltc_enable_latch_mock();
#else
    ltc_enable_latch();
#endif
    
    for (xfp_mod = 0; xfp_mod < 4; xfp_mod++) {

#ifdef TESTING
        xfp_power_up_mock(xfp_mod);
#else
        xfp_power_up(xfp_mod);
#endif

#ifdef TESTING
        xfp_set_data_rate_mock(xfp_mod);
#else
        xfp_set_data_rate(xfp_mod,6);
#endif

#ifdef TESTING
        xfp_set_wavelength_mock(xfp_mod, XFP_WL_1310NM);
#else
        xfp_set_wavelength(xfp_mod, XFP_WL_1310NM);
#endif

#ifdef TESTING
        xfp_set_threshold_mock(xfp_mod, XFP_TX_POWER_HIGH_ALARM, 8912);   // 8912 [0.1 uW]
#else
        xfp_set_threshold(xfp_mod, XFP_TX_POWER_HIGH_ALARM, 8912);   // 8912 [0.1 uW]
#endif

#ifdef TESTING        
        xfp_set_threshold_mock(xfp_mod, XFP_TX_POWER_LOW_ALARM, 2238);    // 2238 [0.1 uW]
#else
        xfp_set_threshold(xfp_mod, XFP_TX_POWER_LOW_ALARM, 2238);    // 2238 [0.1 uW]
#endif

#ifdef TESTING
        xfp_set_threshold_mock(xfp_mod, XFP_TX_POWER_HIGH_WARNING, 7943); // 7943 [0.1 uW]
#else
        xfp_set_threshold(xfp_mod, XFP_TX_POWER_HIGH_WARNING, 7943); // 7943 [0.1 uW]
#endif

#ifdef TESTING
        xfp_set_threshold_mock(xfp_mod, XFP_TX_POWER_LOW_WARNING, 2511);  // 2511 [0.1 uW]
#else
        xfp_set_threshold(xfp_mod, XFP_TX_POWER_LOW_WARNING, 2511);  // 2511 [0.1 uW]
#endif

#ifdef TESTING
        xfp_set_threshold_mock(xfp_mod, XFP_RX_POWER_HIGH_ALARM, 12589);   // 12589 [0.1 uW]
#else
        xfp_set_threshold(xfp_mod, XFP_RX_POWER_HIGH_ALARM, 12589);   // 12589 [0.1 uW]
#endif        

#ifdef TESTING
        xfp_set_threshold_mock(xfp_mod, XFP_RX_POWER_LOW_ALARM, 323);      // 323 [0.1 uW]
#else
        xfp_set_threshold(xfp_mod, XFP_RX_POWER_LOW_ALARM, 323);      // 323 [0.1 uW]
#endif

#ifdef TESTING
        xfp_set_threshold_mock(xfp_mod, XFP_RX_POWER_HIGH_WARNING, 11220); // 11220 [0.1 uW]
#else
        xfp_set_threshold(xfp_mod, XFP_RX_POWER_HIGH_WARNING, 11220); // 11220 [0.1 uW]
#endif

#ifdef TESTING
        xfp_set_threshold_mock(xfp_mod, XFP_RX_POWER_LOW_WARNING, 363);    // 363 [0.1 uW]
#else
        xfp_set_threshold(xfp_mod, XFP_RX_POWER_LOW_WARNING, 363);    // 363 [0.1 uW]
#endif

    }

    return 0;
}

int log_xfp(void) {

    int xfp_mod;
    int xfp_los;
    int tx_power;
    int rx_power;
    int bit_val;

    for (xfp_mod = 0; xfp_mod < 4; xfp_mod++) {

#ifdef TESTING
        xfp_get_loss_of_signal_status_mock(xfp_mod, &xfp_los);
#else
        xfp_get_loss_of_signal_status(xfp_mod, &xfp_los);
#endif

        if (xfp_los != 0)
        {
            openlog("XFP", LOG_PID|LOG_CONS, LOG_USER);
            syslog(LOG_CRIT, XFP_RxLOS,xfp_mod, "Crit");
            closelog();
        }

#ifdef TESTING
        xfp_get_int_flag_mock(xfp_mod, L_TEMP_TX_BIAS_POWER_ALARM, 1, &bit_val);
#else
        xfp_get_int_flag(xfp_mod, L_TEMP_TX_BIAS_POWER_ALARM, 1, &bit_val);
#endif

        if (bit_val == 1)
        {

#ifdef TESTING
            xfp_get_tx_power_mock(xfp_mod, &tx_power);
#else
            xfp_get_tx_power(xfp_mod, &tx_power);
#endif

            openlog("XFP", LOG_PID|LOG_CONS, LOG_USER);
            syslog(LOG_CRIT, XFP_TxPWR,xfp_mod, "Crit", tx_power);
            closelog();
        }

#ifdef TESTING
        xfp_get_int_flag_mock(xfp_mod, L_TEMP_TX_BIAS_POWER_WARNING, 1, &bit_val);
#else
        xfp_get_int_flag(xfp_mod, L_TEMP_TX_BIAS_POWER_WARNING, 1, &bit_val);
#endif

        if (bit_val == 1)
        {

#ifdef TESTING
            xfp_get_tx_power_mock(xfp_mod, &tx_power);
#else
            xfp_get_tx_power(xfp_mod, &tx_power);
#endif

            openlog("XFP", LOG_PID|LOG_CONS, LOG_USER);
            syslog(LOG_WARNING, XFP_TxPWR, xfp_mod, "Warn",tx_power);
            closelog();
        }

#ifdef TESTING
        xfp_get_int_flag_mock(xfp_mod, L_RX_POWER_AUX12_ALARM, 7, &bit_val);
#else
        xfp_get_int_flag(xfp_mod, L_RX_POWER_AUX12_ALARM, 7, &bit_val);
#endif

        if (bit_val == 1)
        {

#ifdef TESTING
            xfp_get_rx_power_mock(xfp_mod, &rx_power);
#else
            xfp_get_rx_power(xfp_mod, &rx_power);
#endif

            openlog("XFP", LOG_PID|LOG_CONS, LOG_USER);
            syslog(LOG_CRIT, XFP_TxPWR, xfp_mod, "Crit", rx_power);
            closelog();
        }

#ifdef TESTING
        xfp_get_int_flag_mock(xfp_mod, M_RX_POWER_AUX12_WARNING, 7, &bit_val);
#else
        xfp_get_int_flag(xfp_mod, M_RX_POWER_AUX12_WARNING, 7, &bit_val);
#endif

        if (bit_val == 1)
        {

#ifdef TESTING
            xfp_get_rx_power_mock(xfp_mod, &rx_power);
#else
            xfp_get_rx_power(xfp_mod, &rx_power);
#endif

            openlog("XFP", LOG_PID|LOG_CONS, LOG_USER);
            syslog(LOG_WARNING, XFP_TxPWR, xfp_mod, "Warn", rx_power);
            closelog();
        }
    }

    return 0;
}

int init_qsfp(qsfp_t *pqsfp) {

    control_t ctrl;

    ctrl = txn_disable;
#ifdef TESTING    
    qsfp_set_control_mock(ctrl, 0); // enabled
#else
    qsfp_set_control(ctrl, 0); // enabled
#endif

    ctrl = rxn_rate_select;
#ifdef TESTING
    qsfp_set_control_mock(ctrl, 0xAA); // Optimized for 6.6 Gb/s data rates and above
#else
    qsfp_set_control(ctrl, 0xAA); // Optimized for 6.6 Gb/s data rates and above
#endif

    ctrl = txn_rate_select;
#ifdef TESTING
    qsfp_set_control_mock(ctrl, 0xAA); 
#else
    qsfp_set_control(ctrl, 0xAA); 
#endif

    return 0;
}

int log_qsfp(qsfp_t *pqsfp) {

    flg_reg_t flg_reg;
    int int_flags;
    int flg_pos;
    int flg_value;

    mod_mon_t mod_mon_reg;
    int qsfp_temp;

    chnl_mon_t chnl_mon_reg;
    int rx_power;
    int tx_bias;

    flg_reg = channel_los_3; 

#ifdef TESTING
    qsfp_get_int_flags_mock(flg_reg, &int_flags);
#else
    qsfp_get_int_flags(flg_reg, &int_flags);
#endif

    for (flg_pos = 0; flg_pos <= 3; flg_pos++)
    {
        get_bit(flg_reg, flg_pos, &flg_value);
        if (flg_value) {
            openlog("QSFP", LOG_PID|LOG_CONS, LOG_USER);
            syslog(LOG_CRIT, QSFP_RxLOS, "Crit", flg_pos+1);
            closelog();
        }            
    }

    for (flg_pos = 4; flg_pos <= 7; flg_pos++)
    {
        get_bit(flg_reg, flg_pos, &flg_value);
        if (flg_value) {
            openlog("QSFP", LOG_PID|LOG_CONS, LOG_USER);
            syslog(LOG_CRIT, QSFP_TxLOS, "Crit", flg_pos+1);
            closelog();
        }            
    }

    flg_reg = channel_fault_4; 

#ifdef TESTING
    qsfp_get_int_flags_mock(flg_reg, &int_flags);
#else
    qsfp_get_int_flags(flg_reg, &int_flags);
#endif

    for (flg_pos = 0; flg_pos <= 3; flg_pos++)
    {
        get_bit(flg_reg, flg_pos, &flg_value);
        if (flg_value) {
            openlog("QSFP", LOG_PID|LOG_CONS, LOG_USER);
            syslog(LOG_CRIT, QSFP_TxFault, "Crit",  flg_pos+1);
            closelog();
        }            
    }

    mod_mon_reg = temp_msb;

#ifdef TESTING
    qsfp_get_mod_monitor_mock(mod_mon_reg, &qsfp_temp);
#else
    qsfp_get_mod_monitor(mod_mon_reg, &qsfp_temp);
#endif

    if (qsfp_temp > pqsfp->crit_temp) 
    {
        openlog("QSFP", LOG_PID|LOG_CONS, LOG_USER);
        syslog(LOG_CRIT, QSFP_TempHighAlm, "Crit", qsfp_temp);
        closelog();
    }
    else if (qsfp_temp > pqsfp->wrng_temp)
    {
        openlog("QSFP", LOG_PID|LOG_CONS, LOG_USER);
        syslog(LOG_WARNING, QSFP_TempHighAlm, "Warn", qsfp_temp);
        closelog();
    }

    flg_reg = module_temp_6;

#ifdef TESTING
    qsfp_get_int_flags_mock(flg_reg, &int_flags);
#else
    qsfp_get_int_flags(flg_reg, &int_flags);
#endif

    get_bit(flg_reg, 7, &flg_value);
    if (flg_value) {
        openlog("QSFP", LOG_PID|LOG_CONS, LOG_USER);
        syslog(LOG_CRIT, QSFP_TempHighAlm, "Crit", qsfp_temp);
        closelog();
    }            

    get_bit(flg_reg, 6, &flg_value);
    if (flg_value) {
        openlog("QSFP", LOG_PID|LOG_CONS, LOG_USER);
        syslog(LOG_CRIT, QSFP_TempLowAlm,"Crit",  qsfp_temp);
        closelog();
    }   

    get_bit(flg_reg, 5, &flg_value);
    if (flg_value) {
        openlog("QSFP", LOG_PID|LOG_CONS, LOG_USER);
        syslog(LOG_WARNING, QSFP_TempHighWng, "Warn", qsfp_temp);
        closelog();
    }   

    get_bit(flg_reg, 4, &flg_value);
    if (flg_value) {
        openlog("QSFP", LOG_PID|LOG_CONS, LOG_USER);
        syslog(LOG_WARNING, QSFP_TempLowWng, "Warn", qsfp_temp);
        closelog();
    }   

    chnl_mon_reg = tx1_bias_msb;

#ifdef TESTING
    qsfp_get_chnl_monitor_mock(chnl_mon_reg, &tx_bias);
#else
    qsfp_get_chnl_monitor(chnl_mon_reg, &tx_bias);
#endif

    if (tx_bias > pqsfp->crit_tx_bias) 
    {
        openlog("QSFP", LOG_PID|LOG_CONS, LOG_USER);
        syslog(LOG_CRIT, QSFP_Tx1BiasHighAlm, "Crit");
        closelog();
    }
    else if (tx_bias > pqsfp->wrng_tx_bias)
    {
        openlog("QSFP", LOG_PID|LOG_CONS, LOG_USER);
        syslog(LOG_WARNING, QSFP_Tx1BiasHighAlm,"Warn");
        closelog();
    }

    chnl_mon_reg = tx2_bias_msb;

#ifdef TESTING
    qsfp_get_chnl_monitor_mock(chnl_mon_reg, &tx_bias);
#else
    qsfp_get_chnl_monitor(chnl_mon_reg, &tx_bias);
#endif

    if (tx_bias > pqsfp->crit_tx_bias) 
    {
        openlog("QSFP", LOG_PID|LOG_CONS, LOG_USER);
        syslog(LOG_CRIT, QSFP_Tx2BiasHighAlm, "Crit");
        closelog();
    }
    else if (tx_bias > pqsfp->wrng_tx_bias) 
    {
        openlog("QSFP", LOG_PID|LOG_CONS, LOG_USER);
        syslog(LOG_WARNING, QSFP_Tx2BiasHighAlm, "Warn");
        closelog();
    }

    chnl_mon_reg = tx3_bias_msb;

#ifdef TESTING
    qsfp_get_chnl_monitor_mock(chnl_mon_reg, &tx_bias);
#else
    qsfp_get_chnl_monitor(chnl_mon_reg, &tx_bias);
#endif

    if (tx_bias > pqsfp->crit_tx_bias) 
    {
        openlog("QSFP", LOG_PID|LOG_CONS, LOG_USER);
        syslog(LOG_CRIT, QSFP_Tx3BiasHighAlm, "Crit");
        closelog();
    }
    else if (tx_bias > pqsfp->wrng_tx_bias)
    {
        openlog("QSFP", LOG_PID|LOG_CONS, LOG_USER);
        syslog(LOG_WARNING, QSFP_Tx3BiasHighAlm, "Warn");
        closelog();
    }

    chnl_mon_reg = tx4_bias_msb;

#ifdef TESTING
    qsfp_get_chnl_monitor_mock(chnl_mon_reg, &tx_bias);
#else
    qsfp_get_chnl_monitor(chnl_mon_reg, &tx_bias);
#endif

    if (tx_bias > pqsfp->crit_tx_bias) 
    {
        openlog("QSFP", LOG_PID|LOG_CONS, LOG_USER);
        syslog(LOG_CRIT, QSFP_Tx4BiasHighAlm, "Crit");
        closelog();
    }
    else if (tx_bias > pqsfp->wrng_tx_bias)
    {
        openlog("QSFP", LOG_PID|LOG_CONS, LOG_USER);
        syslog(LOG_WARNING, QSFP_Tx4BiasHighAlm, "Warn");
        closelog();
    }

#ifdef TESTING
    qsfp_get_chnl_monitor_mock(chnl_mon_reg, &rx_power);
#else
    qsfp_get_chnl_monitor(chnl_mon_reg, &rx_power);
#endif

    if (rx_power > pqsfp->crit_rx_power) 
    {
        openlog("QSFP", LOG_PID|LOG_CONS, LOG_USER);
        syslog(LOG_CRIT, QSFP_Rx1PwrAlm, "Crit");
        closelog();
    }
    else if (rx_power > pqsfp->wrng_rx_power)
    {
        openlog("QSFP", LOG_PID|LOG_CONS, LOG_USER);
        syslog(LOG_WARNING, QSFP_Rx1PwrAlm, "Warn");
        closelog();
    }

chnl_mon_reg = rx2_pwr_msb;

#ifdef TESTING
    qsfp_get_chnl_monitor_mock(chnl_mon_reg, &rx_power);
#else
    qsfp_get_chnl_monitor(chnl_mon_reg, &rx_power);
#endif

    if (rx_power > pqsfp->crit_rx_power) 
    {
        openlog("QSFP", LOG_PID|LOG_CONS, LOG_USER);
        syslog(LOG_CRIT, QSFP_Rx2PwrAlm, "Crit");
        closelog();
    }
    else if (rx_power > pqsfp->wrng_rx_power)
    {
        openlog("QSFP", LOG_PID|LOG_CONS, LOG_USER);
        syslog(LOG_WARNING, QSFP_Rx2PwrAlm, "Warn");
        closelog();
    }

chnl_mon_reg = rx3_pwr_msb;

#ifdef TESTING
    qsfp_get_chnl_monitor_mock(chnl_mon_reg, &rx_power);
#else
    qsfp_get_chnl_monitor(chnl_mon_reg, &rx_power);
#endif

    if (rx_power > pqsfp->crit_rx_power)
    {
        openlog("QSFP", LOG_PID|LOG_CONS, LOG_USER);
        syslog(LOG_CRIT, QSFP_Rx3PwrAlm, "Crit");
        closelog();
    }
    else if (rx_power > pqsfp->wrng_rx_power)
    {
        openlog("QSFP", LOG_PID|LOG_CONS, LOG_USER);
        syslog(LOG_WARNING, QSFP_Rx3PwrAlm, "Warn");
        closelog();
    }

        

chnl_mon_reg = rx4_pwr_msb;

#ifdef TESTING
    qsfp_get_chnl_monitor_mock(chnl_mon_reg, &rx_power);
#else
    qsfp_get_chnl_monitor(chnl_mon_reg, &rx_power);
#endif

    if (rx_power > pqsfp->crit_rx_power) 
    {
        openlog("QSFP", LOG_PID|LOG_CONS, LOG_USER);
        syslog(LOG_CRIT, QSFP_Rx4PwrAlm, "Crit");
        closelog();
    }
    else if (rx_power > pqsfp->wrng_rx_power)
    {
        openlog("QSFP", LOG_PID|LOG_CONS, LOG_USER);
        syslog(LOG_WARNING, QSFP_Rx4PwrAlm, "Warn");
        closelog();
    }

    return 0;
}

int init_txp(txp_t* ptxp) {

    int mode;      
/*
#ifdef TESTING    
    CHECK_PARAM(txp_jdsu_read_protected_mode_mock(&mode) < 0, LOG_ERR, pname, 
        "Error in init_txp(): txp_jdsu_read_protected_mode()");
#else
    CHECK_PARAM(txp_jdsu_read_protected_mode(&mode) < 0, LOG_ERR, pname, 
        "Error in init_txp(): txp_jdsu_read_protected_mode()");
#endif

    if(!mode) 
    { */  

#ifdef TESTING        
        CHECK_PARAM(txp_enter_protected_mode_mock() < 0, LOG_ERR, pname, 
            "Error in init_txp(): txp_enter_protected_mode()");
#else
        CHECK_PARAM(txp_enter_protected_mode() < 0, LOG_ERR, pname, 
            "Error in init_txp(): txp_enter_protected_mode()");
#endif

    //}
            
    tx_cmd_t tx;
    tx.prbsen = 1;
    tx.prbspat0 = 1;
    tx.prbspat1 = 1; 
    tx.txdeskewen = 1;                  
    tx.txdcksel = 0;
    tx.txlinetimsel = 1; 
    tx.txlloopenb =1;
    tx.txreset = 1;                 
    tx.txfifores = 1;               
    tx.autotxfifores = 0;
    tx.sctxreset = 1;               
    tx.txmutemonclk = 1;
    tx.lsenable  = 1;
    tx.txratesel0 = 1;              
    tx.txratesel1 = 1;              
    tx.txrefsel = 0;          

#ifdef TESTING
    CHECK_PARAM(txp_set_tx_cmd_reg_mock(tx) < 0, LOG_ERR, pname, 
        "Error in init_txp(): txp_set_tx_cmd_reg()");
#else
    CHECK_PARAM(txp_set_tx_cmd_reg(tx) < 0, LOG_ERR, pname, 
        "Error in init_txp(): txp_set_tx_cmd_reg()");
#endif

    rx_cmd_t rx;
    rx.rxmute = 1;
    rx.rxdloopenb = 1;
    rx.scrxreset = 1; 
    rx.prbsen = 1;
    rx.prbspat0 = 1;
    rx.prbspat1 = 1;
    rx.rxratesel0 = 1; 
    rx.rxratesel1 = 0;
    rx.rxrefsel = 0;
    rx.rxlckref = 1;
    rx.rxmonclksel = 0; 
    rx.rxreset = 1;
    rx.rxmutemonclk = 1;

#ifdef TESTING
    CHECK_PARAM(txp_set_rx_cmd_reg_mock(rx) < 0, LOG_ERR, pname, 
        "Error in init_txp(): txp_set_rx_cmd_reg()");
#else
    CHECK_PARAM(txp_set_rx_cmd_reg(rx) < 0, LOG_ERR, pname, 
        "Error in init_txp(): txp_set_rx_cmd_reg()");
#endif

    itu_channel_t itu;

    itu.band = 0x4C; // L
    itu.channel = 0;

#ifdef TESTING
    CHECK_PARAM(txp_set_laser_itu_channel_mock(itu) < 0, LOG_ERR, pname, 
        "Error in init_txp(): txp_set_laser_itu_channel()");
#else
    CHECK_PARAM(txp_set_laser_itu_channel(itu) < 0, LOG_ERR, pname, 
        "Error in init_txp(): txp_set_laser_itu_channel()");
#endif

/**
 * Note that on power-up any alarms may be set until 
 * the module completes initialization. Therefore,
 * the host should read this register as part of 
 * module initialization to clear those alarms.
 **/

    tx_alarm_t tx_alarm;
    rx_alarm_t rx_alarm;
    supply_alarm_t pwr_sup_alarm;

#ifdef TESTING
    txp_read_tx_alarm_status_register_mock(&tx_alarm);
#else
    txp_read_tx_alarm_status_register(&tx_alarm);
#endif

#ifdef TESTING
    txp_read_rx_alarm_status_register_mock(&rx_alarm);
#else
    txp_read_rx_alarm_status_register(&rx_alarm);
#endif

#ifdef TESTING
    txp_read_power_supply_alarm_status_register_mock(&pwr_sup_alarm);
#else
    txp_read_power_supply_alarm_status_register(&pwr_sup_alarm);
#endif

/* End of clearing of alarms */

#ifdef TESTING
    txp_jdsu_set_rxpowalm_threshold_mock(
        ptxp->rx_pow_alm,   // 0.1 dBm 
        ptxp->rx_pow_idle); // 0.1 dBm 
#else
    txp_oclaro_set_rxpowalm_threshold(
        ptxp->rx_pow_alm); // 0.1 dBm 
#endif

#ifdef TESTING
    txp_jdsu_set_modbiasalm_threshold_mock(
        ptxp->mod_bias_high_alm,    // 0.1 V
        ptxp->mod_bias_low_alm,     // 0.1 V
        ptxp->mod_bias_high_idle,   // 0.1 V
        ptxp->mod_bias_low_idle);   // 0.1 V
#else
   /* txp_jdsu_set_modbiasalm_threshold(
        ptxp->mod_bias_high_alm,    // 0.1 V
        ptxp->mod_bias_low_alm,     // 0.1 V
        ptxp->mod_bias_high_idle,   // 0.1 V
        ptxp->mod_bias_low_idle);   // 0.1 V*/
#endif
    
#ifdef TESTING
    txp_jdsu_set_lolsbiasalm_threshold_mock(
        ptxp->lo_ls_bias_alm,       // 0.1 mA
        ptxp->lo_ls_bias_idle);     // 0.1 mA
#else
   /* txp_jdsu_set_lolsbiasalm_threshold(
        ptxp->lo_ls_bias_alm,       // 0.1 mA
        ptxp->lo_ls_bias_idle);     // 0.1 mA*/
#endif

#ifdef TESTING
    txp_jdsu_set_txptempalm_threshold_mock(
        ptxp->temp_idle,    // 0.1 degre C  // Storage case temperature range 0°C 70°C
        ptxp->temp_alm);    // 0.1 degre C
#else
    /*txp_jdsu_set_txptempalm_threshold(
        ptxp->temp_idle,    // 0.1 degre C  // Storage case temperature range 0°C 70°C
        ptxp->temp_alm);    // 0.1 degre C*/
#endif

#ifdef TESTING
    txp_jdsu_set_txpowalm_threshold_mock(
        ptxp->tx_pow_high_alm,  // 0.1 dBm
        ptxp->tx_pow_low_alm,   // 0.1 dB 
        ptxp->tx_pow_high_idle, // 0.1 dBm
        ptxp->tx_pow_low_idle); // 0.1 dB 
#else
    /*txp_jdsu_set_txpowalm_threshold(
        ptxp->tx_pow_high_alm,  // 0.1 dBm
        ptxp->tx_pow_low_alm,   // 0.1 dB 
        ptxp->tx_pow_high_idle, // 0.1 dBm
        ptxp->tx_pow_low_idle); // 0.1 dB*/
#endif

#ifdef TESTING
    txp_jdsu_set_rxpowalm_threshold_rxlos_rxs_mock(
        ptxp->rx_pow_alm_rxlos, // 0.1 dBm  // Activation level -24 dBm
        ptxp->rx_pow_idle_rxlos,// 0.1 dBm  // Deactivation level -23.5 dBm
        ptxp->rx_pow_alm_rxs,   // 0.1 dBm
        ptxp->rx_pow_idle_rxs); // 0.1 dBm
#else
   /* txp_jdsu_set_rxpowalm_threshold_rxlos_rxs(
        ptxp->rx_pow_alm_rxlos, // 0.1 dBm  // Activation level -24 dBm
        ptxp->rx_pow_idle_rxlos,// 0.1 dBm  // Deactivation level -23.5 dBm
        ptxp->rx_pow_alm_rxs,   // 0.1 dBm
        ptxp->rx_pow_idle_rxs); // 0.1 dBm*/
#endif

#ifdef TESTING
    txp_jdsu_set_rxhighpowalm_threshold_mock(
        ptxp->rx_pow_high_alm,   // 0.1 dBm 
        ptxp->rx_pow_high_idle); // 0.1 dBm
#else
    /*txp_jdsu_set_rxhighpowalm_threshold(
        ptxp->rx_pow_high_alm,   // 0.1 dBm 
        ptxp->rx_pow_high_idle); // 0.1 dBm*/
#endif

#ifdef TESTING
    txp_jdsu_set_lsbiasalm_threshold_mock(
        ptxp->ls_bias_alm,       // 0.1 mA
        ptxp->ls_bias_idle);     // 0.1 mA
#else
   /* txp_jdsu_set_lsbiasalm_threshold(
        ptxp->ls_bias_alm,       // 0.1 mA
        ptxp->ls_bias_idle);     // 0.1 mA*/
#endif

#ifdef TESTING
    txp_jdsu_set_dsp_temp_mon_threshold_mock(
        ptxp->dsp_temp_mon);     // tenths of C
#else
   /* txp_jdsu_set_dsp_temp_mon_threshold(
        ptxp->dsp_temp_mon);     // tenths of C*/
#endif

    return 0;
}

int log_txp(void) {

    tx_alarm_t tx_alarm;
    rx_alarm_t rx_alarm;
    supply_alarm_t pwr_sup_alarm;
    summary_alarm_t sum_alarm;

#ifdef TESTING
    txp_read_tx_alarm_status_register_mock(&tx_alarm);
#else
    txp_read_tx_alarm_status_register(&tx_alarm);
#endif

    if (tx_alarm.eolalm == 0) {
        openlog(pname, LOG_PID|LOG_CONS, LOG_USER);
        syslog(LOG_CRIT, EOLALM, "Crit");
        closelog();
    }

    if (tx_alarm.modtempalm == 0) {
        openlog(pname, LOG_PID|LOG_CONS, LOG_USER);
        syslog(LOG_CRIT, ModTEMPALM, "Crit");
        closelog();
    }
    
    if (tx_alarm.txooa == 0) {
        openlog(pname, LOG_PID|LOG_CONS, LOG_USER);
        syslog(LOG_CRIT, TxOOA, "Crit");
        closelog();
    }
    
    if (tx_alarm.txlofalm == 0) {
        openlog(pname, LOG_PID|LOG_CONS, LOG_USER);
        syslog(LOG_CRIT, TxLOFALM, "Crit");
        closelog();
    }

    if (tx_alarm.txdscerr == 0) {
        openlog(pname, LOG_PID|LOG_CONS, LOG_USER);
        syslog(LOG_CRIT, TxDSCERR, "Crit");
        closelog();
    }

    if (tx_alarm.lswavalm == 0) {
        openlog(pname, LOG_PID|LOG_CONS, LOG_USER);
        syslog(LOG_CRIT, LsWAVALM, "Crit");
        closelog();
    }
    
    if (tx_alarm.txalm == 0) {
        openlog(pname, LOG_PID|LOG_CONS, LOG_USER);
        syslog(LOG_CRIT, TxALM_INT, "Crit");
        closelog();
    }

    if (tx_alarm.lsbiasalm == 0) {
        openlog(pname, LOG_PID|LOG_CONS, LOG_USER);
        syslog(LOG_CRIT, LsBIASALM, "Crit");
        closelog();
    }

    if (tx_alarm.lstempalm == 0) {
        openlog(pname, LOG_PID|LOG_CONS, LOG_USER);
        syslog(LOG_CRIT, LsTEMPALM, "Crit");
        closelog();
    }

    if (tx_alarm.txlockerr == 0) {
        openlog(pname, LOG_PID|LOG_CONS, LOG_USER);
        syslog(LOG_CRIT, TxLOCKERR, "Crit");
        closelog();
    }
    if (tx_alarm.lspowalm == 0) {
        openlog(pname, LOG_PID|LOG_CONS, LOG_USER);
        syslog(LOG_CRIT, LsPOWALM, "Crit");
        closelog();
    }

    if (tx_alarm.modbiasalm == 0) {
        openlog(pname, LOG_PID|LOG_CONS, LOG_USER);
        syslog(LOG_CRIT, ModBIASALM, "Crit");
        closelog();
    }

    if (tx_alarm.txfifoerr == 0) {
        openlog(pname, LOG_PID|LOG_CONS, LOG_USER);
        syslog(LOG_CRIT, TxFIFOERR, "Crit");
        closelog();
    }

#ifdef TESTING
    txp_read_rx_alarm_status_register_mock(&rx_alarm);
#else
    txp_read_rx_alarm_status_register(&rx_alarm);
#endif

    if (rx_alarm.rxalm == 0) {
        openlog(pname, LOG_PID|LOG_CONS, LOG_USER);
        syslog(LOG_CRIT, RxALM_INT, "Crit");
        closelog();
    }    

    if (rx_alarm.rxpowalm == 0) {
        openlog(pname, LOG_PID|LOG_CONS, LOG_USER);
        syslog(LOG_CRIT, RxPOWALM, "Crit");
        closelog();
    }    
    
    if (rx_alarm.rxlos == 0) {
        openlog(pname, LOG_PID|LOG_CONS, LOG_USER);
        syslog(LOG_CRIT, RxLOS, "Crit");
        closelog();
    }    
    
    if (rx_alarm.rxlockerr == 0) {
        openlog(pname, LOG_PID|LOG_CONS, LOG_USER);
        syslog(LOG_CRIT, RxLOCKERR, "Crit");
        closelog();
    }    
    
    if (rx_alarm.rxs == 0) {
        openlog(pname, LOG_PID|LOG_CONS, LOG_USER);
        syslog(LOG_CRIT, RXS, "Crit");
        closelog();
    }
    
    if (rx_alarm.prbserrdet == 0) {
        openlog(pname, LOG_PID|LOG_CONS, LOG_USER);
        syslog(LOG_CRIT, PRBSERRDET, "Crit");
        closelog();
    }

#ifdef TESTING
    txp_read_power_supply_alarm_status_register_mock(&pwr_sup_alarm);
#else
    txp_read_power_supply_alarm_status_register(&pwr_sup_alarm);
#endif

    if (pwr_sup_alarm.psummary == 0) {
        openlog(pname, LOG_PID|LOG_CONS, LOG_USER);
        syslog(LOG_CRIT, PSUMMARY, "Crit");
        closelog();
    }

    if (pwr_sup_alarm.p5vanalog == 0) {
        openlog(pname, LOG_PID|LOG_CONS, LOG_USER);
        syslog(LOG_CRIT, P5VANALOG, "Crit");
        closelog();
    }

    if (pwr_sup_alarm.n5v2analog == 0) {
        openlog(pname, LOG_PID|LOG_CONS, LOG_USER);
        syslog(LOG_CRIT, N5V2ANALOG, "Crit");
        closelog();
    }

    if (pwr_sup_alarm.p3p3vanalog == 0) {
        openlog(pname, LOG_PID|LOG_CONS, LOG_USER);
        syslog(LOG_CRIT, P3P3VANALOG, "Crit");
        closelog();
    }

    if (pwr_sup_alarm.p3p3vdigital == 0) {
        openlog(pname, LOG_PID|LOG_CONS, LOG_USER);
        syslog(LOG_CRIT, P3P3VDIGITAL, "Crit");
        closelog();
    }

    if (pwr_sup_alarm.lvdigital == 0) {
        openlog(pname, LOG_PID|LOG_CONS, LOG_USER);
        syslog(LOG_CRIT, LVDIGITAL, "Crit");
        closelog();
    }

    if (pwr_sup_alarm.n5p2vdigital == 0) {
        openlog(pname, LOG_PID|LOG_CONS, LOG_USER);
        syslog(LOG_CRIT, N5P2VDIGITAL, "Crit");
        closelog();
    }

#ifdef TESTING
    txp_read_summary_alarm_register_mock(&sum_alarm);
#else
    txp_read_summary_alarm_register(&sum_alarm);
#endif

    if (sum_alarm.txalm == 0) {
        openlog(pname, LOG_PID|LOG_CONS, LOG_USER);
        syslog(LOG_CRIT, TxALM_INT, "Crit");
        closelog();
    }

    if (sum_alarm.rxalm == 0) {
        openlog(pname, LOG_PID|LOG_CONS, LOG_USER);
        syslog(LOG_CRIT, RxALM_INT, "Crit");
        closelog();
    }

    if (sum_alarm.psummary == 0) {
        openlog(pname, LOG_PID|LOG_CONS, LOG_USER);
        syslog(LOG_CRIT, PSUMMARY, "Crit");
        closelog();
    }

    return 0;
}

int log_otn(void) {
    
    int port;

    for (port = 0; port < 4; port++) {

        if (CS_OK == ten_n10g_get_global_losf_status(module_client, port)) {
            openlog(pname, LOG_PID|LOG_CONS, LOG_USER);
            syslog(LOG_CRIT, T41_OTU_GLOBAL_STATUS_LOSF, "Crit", port);
            closelog();
        }

        if (CS_OK == ten_n10g_get_otu_framer_status(module_client, port, TEN_NX0G_OTNR_OFSTAT_SLOF)) {
            openlog(pname, LOG_PID|LOG_CONS, LOG_USER);
            syslog(LOG_CRIT, T41_OTU_OFSTAT_SLOF, "Crit", port);
            closelog();
        }

        if (CS_OK == ten_n10g_oohr_get_sm_status(module_client, port, TEN_NX0G_OOHR_SM_STATUS_LOM)) {
            openlog(pname, LOG_PID|LOG_CONS, LOG_USER);
            syslog(LOG_CRIT, T41_OTU_SM_STATUS_LOM, "Crit", port);
            closelog();
        }

        if (CS_OK == ten_n10g_oohr_get_sm_status(module_client, port, TEN_NX0G_OOHR_SM_STATUS_DBDI)) {
            openlog(pname, LOG_PID|LOG_CONS, LOG_USER);
            syslog(LOG_CRIT, T41_OTU_SM_STATUS_DBDI, "Crit", port);
            closelog();
        }
        
        if (CS_OK == ten_n10g_oohr_get_sm_status(module_client, port, TEN_NX0G_OOHR_SM_STATUS_DIAE)) {
            openlog(pname, LOG_PID|LOG_CONS, LOG_USER);
            syslog(LOG_CRIT, T41_OTU_SM_STATUS_DIAE, "Crit", port);
            closelog();
        }

        if (CS_OK == ten_n10g_oohr_get_sm_status(module_client, port, TEN_NX0G_OOHR_SM_STATUS_BIPSDS)) {
            openlog(pname, LOG_PID|LOG_CONS, LOG_USER);
            syslog(LOG_CRIT, T41_SM_STATUS_BIPSDS, "Crit", port);
            closelog();
        }

        if (CS_OK == ten_n10g_oohr_get_sm_status(module_client, port, TEN_NX0G_OOHR_SM_STATUS_BEISDS)) {
            openlog(pname, LOG_PID|LOG_CONS, LOG_USER);
            syslog(LOG_CRIT, T41_OTU_SM_STATUS_BEISDS, "Crit", port);
            closelog();
        }

        if (CS_OK == ten_n10g_oohr_get_pm_status(module_client, port, TEN_NX0G_OOHR_PM_STATUS_DAIS)) {
            openlog(pname, LOG_PID|LOG_CONS, LOG_USER);
            syslog(LOG_CRIT, T41_ODU_PM_STATUS_DAIS, "Crit", port);
            closelog();
        }

        if (CS_OK == ten_n10g_oohr_get_pm_status(module_client, port, TEN_NX0G_OOHR_PM_STATUS_DBDI)) {
            openlog(pname, LOG_PID|LOG_CONS, LOG_USER);
            syslog(LOG_CRIT, T41_ODU_PM_STATUS_DBDI, "Crit", port);
            closelog();
        }

        if (CS_OK == ten_n10g_oohr_get_pm_status(module_client, port, TEN_NX0G_OOHR_PM_STATUS_DOCI)) {
            openlog(pname, LOG_PID|LOG_CONS, LOG_USER);
            syslog(LOG_CRIT, T41_ODU_PM_STATUS_DOCI, "Crit", port);
            closelog();
        }

        if (CS_OK == ten_n10g_oohr_get_pm_status(module_client, port, TEN_NX0G_OOHR_PM_STATUS_DLCK)) {
            openlog(pname, LOG_PID|LOG_CONS, LOG_USER);
            syslog(LOG_CRIT, T41_ODU_PM_STATUS_DLCK, "Crit", port);
            closelog();
        }

        if (CS_OK == ten_n10g_oohr_get_pm_status(module_client, port, TEN_NX0G_OOHR_PM_STATUS_BIPSDS)) {
            openlog(pname, LOG_PID|LOG_CONS, LOG_USER);
            syslog(LOG_CRIT, T41_ODU_PM_STATUS_BIPSDS, "Crit", port);
            closelog();
        }

        if (CS_OK == ten_n10g_oohr_get_pm_status(module_client, port, TEN_NX0G_OOHR_PM_STATUS_BEISDS)) {
            openlog(pname, LOG_PID|LOG_CONS, LOG_USER);
            syslog(LOG_CRIT, T41_ODU_PM_STATUS_BEISDS, "Crit", port);
            closelog();
        }
    }
    
}

int log_eth(void) {

    int port;

    for (port = 0; port < 4; port++) {

        if (CS_OK == ten_pp10g_pcs_rx_status(module_client, port, TEN_PP10G_PCS_RX_SYNCDETS)) {
            openlog(pname, LOG_PID|LOG_CONS, LOG_USER);
            syslog(LOG_CRIT, T41_ETHOTN_PCS_RX_SYNCDETS, "Crit", port);
            closelog();
        }

        if (CS_OK == ten_pp10g_pcs_rx_status(module_client, port, TEN_PP10G_PCS_RX_BERHIGHS)) {
            openlog(pname, LOG_PID|LOG_CONS, LOG_USER);
            syslog(LOG_CRIT, T41_ETHOTN_PCS_RX_BERHIGHS, "Crit", port);
            closelog();
        }

        if (CS_OK == ten_pp10g_pcs_rx_status(module_client, port, TEN_PP10G_PCS_RX_PATSYNCS)) {
            openlog(pname, LOG_PID|LOG_CONS, LOG_USER);
            syslog(LOG_CRIT, T41_ETHOTN_PCS_RX_PATSYNCS, "Crit", port);
            closelog();
        }

        if (CS_OK == ten_pp10g_rs_rx_get_status(module_client, port, TEN_PP10G_RS_RX_STATUS_RFS)) {
            openlog(pname, LOG_PID|LOG_CONS, LOG_USER);
            syslog(LOG_CRIT, T41_ETHOTN_RS_RX_STATUS_RFS, "Crit", port);
            closelog();
        }

        if (CS_OK == ten_pp10g_rs_rx_get_status(module_client, port, TEN_PP10G_RS_RX_STATUS_LFS)) {
            openlog(pname, LOG_PID|LOG_CONS, LOG_USER);
            syslog(LOG_CRIT, T41_ETHOTN_RS_RX_STATUS_LFS, "Crit", port);
            closelog();
        }

        if (CS_OK == ten_pp10g_rs_rx_get_status(module_client, port, TEN_PP10G_RS_RX_STATUS_UNKNOWNORDS)) {
            openlog(pname, LOG_PID|LOG_CONS, LOG_USER);
            syslog(LOG_CRIT, T41_ETHOTN_RS_RX_STATUS_UNKNOWNORDS, "Crit", port);
            closelog();
        }

        if (CS_OK == ten_pp10g_rs_rx_get_status(module_client, port, TEN_PP10G_RS_RX_STATUS_REMOTEORDS)) {
            openlog(pname, LOG_PID|LOG_CONS, LOG_USER);
            syslog(LOG_CRIT, T41_ETHOTN_RS_RX_STATUS_REMOTEORDS, "Crit", port);
            closelog();
        }
    
        if (CS_OK == ten_pp10g_rs_rx_get_status(module_client, port, TEN_PP10G_RS_RX_STATUS_LOCALORDS)) {
            openlog(pname, LOG_PID|LOG_CONS, LOG_USER);
            syslog(LOG_CRIT, T41_ETHOTN_RS_RX_STATUS_LOCALORDS, "Crit", port);
            closelog();
        }

        if (CS_OK == ten_pp10g_xaui_rx_get_status(module_client, port, TEN_PP10G_XAUI_RX_LOCALFAULT)) {
            openlog(pname, LOG_PID|LOG_CONS, LOG_USER);
            syslog(LOG_CRIT, T41_ETHOTN_XAUI_RX_LOCALFAULT, "Crit", port);
            closelog();
        }

        if (CS_OK == ten_pp10g_xaui_rx_get_status(module_client, port, TEN_PP10G_XAUI_RX_REMOTEFAULT)) {
            openlog(pname, LOG_PID|LOG_CONS, LOG_USER);
            syslog(LOG_CRIT, T41_ETHOTN_XAUI_RX_REMOTEFAULT, "Crit", port);
            closelog();
        }

        if (CS_OK == ten_pp10g_xaui_rx_get_status(module_client, port, TEN_PP10G_XAUI_RX_XGXS_CPAT_LOCK)) {
            openlog(pname, LOG_PID|LOG_CONS, LOG_USER);
            syslog(LOG_CRIT, T41_ETHOTN_XAUI_RX_XGXS_CPAT_LOCK, "Crit", port);
            closelog();
        }

        if (CS_OK == ten_pp10g_xaui_rx_get_status(module_client, port, TEN_PP10G_XAUI_RX_XGXS_ALIGN_DET)) {
            openlog(pname, LOG_PID|LOG_CONS, LOG_USER);
            syslog(LOG_CRIT, T41_ETHOTN_XAUI_RX_XGXS_ALIGN_DET, "Crit", port);
            closelog();
        }

        if (CS_OK == ten_pp10g_xaui_rx_get_status(module_client, port, TEN_PP10G_XAUI_RX_SYNCDET3)) {
            openlog(pname, LOG_PID|LOG_CONS, LOG_USER);
            syslog(LOG_CRIT, T41_ETHOTN_XAUI_RX_SYNCDET3, "Crit", port);
            closelog();
        }

        if (CS_OK == ten_pp10g_xaui_rx_get_status(module_client, port, TEN_PP10G_XAUI_RX_SYNCDET2)) {
            openlog(pname, LOG_PID|LOG_CONS, LOG_USER);
            syslog(LOG_CRIT, T41_ETHOTN_XAUI_RX_SYNCDET2, "Crit", port);
            closelog();
        }

        if (CS_OK == ten_pp10g_xaui_rx_get_status(module_client, port, TEN_PP10G_XAUI_RX_SYNCDET1)) {
            openlog(pname, LOG_PID|LOG_CONS, LOG_USER);
            syslog(LOG_CRIT, T41_ETHOTN_XAUI_RX_SYNCDET1,  "Crit",port);
            closelog();
        }

        if (CS_OK == ten_pp10g_xaui_rx_get_status(module_client, port, TEN_PP10G_XAUI_RX_SYNCDET0)) {
            openlog(pname, LOG_PID|LOG_CONS, LOG_USER);
            syslog(LOG_CRIT, T41_ETHOTN_XAUI_RX_SYNCDET0, "Crit", port);
            closelog();
        }
    }        

    return 0;

}

int init_T41(void)
{
    
    //Cargamos el Driver.   
    if (ten_drvr_load() != CS_OK)
    {
        openlog(pname, LOG_PID|LOG_CONS, LOG_USER);
        syslog(LOG_CRIT, "Error al cargar el driver");
        closelog();
        return -1;
    }
    
    ten_drvr_ctl_stats_hex_format(1);

    //establecemos los valores iniciales:
    Chips.mpif.CHIP_ID_LSB.wrd = TEN_MPIF_CHIP_ID_LSB_dft; 
    Chips.mpif.CHIP_ID_MSB.wrd = TEN_MPIF_CHIP_ID_MSB_dft;
    dev_id = 0; 
    module_line = dev_id <<8;
    module_client = module_line | 1;
        
    //Registramos el Device.:   
    if(ten_dev_register(dev_id,(cs_uint32)&Chips) != CS_OK)
    {
        openlog(pname, LOG_PID|LOG_CONS, LOG_USER);
        syslog(LOG_CRIT, "CS604x device registration failed; provisioning aborted");
        closelog();
        return -1;
    }
    
    // Initialize the device driver 
    if (ten_dev_main_init(dev_id) != CS_OK) 
    {
        openlog(pname, LOG_PID|LOG_CONS, LOG_USER);
        syslog(LOG_CRIT, "CS604x device initialization failed; provisioning aborted");
        closelog();
        // la funcion tira un error inesperado
        return -1;
    }
    ten_mpif_get_chip_jtag_id(dev_id);
        
    ten_mpif_scratch_pad2(dev_id, 0xAA55);
    ten_mpif_read_scratch_pad2(dev_id);
    
    module_client = ten_mod_main_init( dev_id, TEN_MODULE_A );
    module_line = ten_mod_main_init( dev_id, TEN_MODULE_B );
                
    ten_hl_config_global( dev_id, 0, 1, 0, 1, 1 );
    ten_hl_ohpp_and_shadow_ram_init(dev_id);
        
    // Config Top level    

    ten_hl_config_global(
                        dev_id,                     //Device ID 
                        TEN_GLOBAL_MODE_S_40G,      //Line Mode
                        TEN_GLOBAL_MODE_QUAD_10G,   //Client Mode
                        0,                          //mbclksel
                        1,                          //Multi-Rate Mode not SFI41 Line
                        1                           //Multi-Rate Mode not SFI41 Client
                        );
    
    ten_hsif_provision_datapath(module_line,            // module_id 
                                TEN_INSTANCE_ALL,           // instance: Specified as 0..3 or TEN_INSTANCE_ALL 
                                1,                      // tx_xfiselect: 1 = XFI or 0 = protocol selected by rx_mrprotocol (default)
                                1,                      // rx_xfiselect: 1 = XFI or 0 = protocol selected by rx_mrprotocol (default)
                                0,                      // tx_pswtchen: 1 = Disable or 0 = Enabled:  Data is driven from remote interface 
                                0,                      // tx_mrprotocol: XAUI, SFI4. 2 (40G), SFI4. 2 (10G), SFI4. 1, SFI5 (default), disabled
                                0,                          // rx_pswtchen: 1 = Disable or 0 = Enabled:  Data is driven from remote interface
                                0);
                                                                    // rx_mrprotocol: XAUI, SFI4. 2 (40G), SFI4. 2 (10G), SFI4. 1, SFI5 (default), disabled
        
    ten_hsif_provision_datapath(module_client,          // module_id
                                            TEN_INSTANCE_ALL,       // instance: Specified as 0..3 or TEN_INSTANCE_ALL
                                            1,                      // tx_xfiselect: 1 = XFI or 0 = protocol selected by rx_mrprotocol (default)
                                            1,                      // rx_xfiselect: 1 = XFI or 0 = protocol selected by rx_mrprotocol (default)
                                            0,                      // tx_pswtchen: 0 = Disable or 1 = Enabled:  Data is driven from remote interface 
                                            0,                      // tx_mrprotocol: XAUI, SFI4. 2 (40G), SFI4. 2 (10G), SFI4. 1, SFI5 (default), disabled
                                            0,                          // rx_pswtchen: 0 = Disable or 1 = Enabled:  Data is driven from remote interface
                                            0);                     // rx_mrprotocol: XAUI, SFI4. 2 (40G), SFI4. 2 (10G), SFI4. 1, SFI5 (default), disabled

    
        //no hace control de errores, siempre devuelve ok
    ten_hl_hsif_powerdown_mr(module_client,         // module_id
                            TEN_SLICE_ALL,      // slice
                            CS_ENABLE);         // ctl
    

    ten_hl_n40g_config(module_line,                     // module_id: module_id_a, module_id_b
                        TEN_N40G_RX_OTU3_ODTU23,            // mode_rx: Table 9, row 2 -> TEN_N40G_RX_OTU3_ODTU23 = 7
                        TEN_N40G_TX_ODTU2_OTU3);            // mode_tx: Table 10, row 2 -> TEN_N40G_TX_ODTU2_OTU3 = 11
                            
                            
                            
    


    ten_hl_config_otu2v_otu3v_t41(
                                 module_line,           //Line Module Id
                                 TEN_SLICE1,                //Line Slice
                                 TEN_SLICE1,                //Client Slice
                                 TEN_INITIAL_CONFIG,        //Dynamic Reprovision Type
                                 TEN_TRAFFIC_TYPE_OTU3,     //TEN_TRAFFIC_TYPE_OTU3E4,  //Traffic Type Line
                                 TEN_FEC_MODE_ZEROFEC,      //FEC Type Line
                                 TEN_TRAFFIC_TYPE_OTU2,     //Traffic Type Client
                                 TEN_FEC_MODE_NOFEC,        //FEC Type Client
                                 TEN_OTU_TERM_SECTION,      //Term OTU
                                 CS_DISABLE,                //TCM Line      
                                 CS_DISABLE,                //TCM Client    
                                 CS_ENABLE,                 //MLD Line      
                                 TEN_MAP_AMP,           //Mapping Method ODTU
                                 TEN_MAP_AMP,               //Mapping Method OXUV
                                 8,                         //Timeslots
                                 1                          //GMP Timeslot Mask
                                 );


    ten_hl_config_10ge_otu3v_t41(
                                module_line,            //Line Module Id
                                TEN_SLICE0,                 //Line Slice
                                TEN_SLICE0,                 //Client Slice
                                TEN_INITIAL_CONFIG,         //Dynamic Reprovision Type
                                TEN_TRAFFIC_TYPE_OTU3,      //Traffic Type Line
                                TEN_FEC_MODE_NOFEC,         //FEC Type Line
                                TEN_TRAFFIC_TYPE_10GE_7_1,  //Traffic Type Client
                                400,                        //System Clock
                                CS_DISABLE,                 //TCM Line
                                CS_ENABLE,                  //MLD Line
                                TEN_MAP_GMP_HO,             //Mapping Method ODTU
                                TEN_MAP_BMP,                //Mapping Method OXUV
                                8,                          //Timeslots
                                0,                          //GMP Frame Format
                                2                           //Flow Control Mode
                                );
                          
        return 0;
}
