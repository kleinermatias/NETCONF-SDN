#include "gtest/gtest.h"
#include "fff.h"


extern "C"
{
#include "logger.h"
#include "parser.h"
#include "../../lib/txp/txp.h"
#include "../../lib/tmp/tmp.h"
#include "../../lib/ltc/ltc.h"
#include "../../lib/xfp/xfp.h"
#include "../../lib/qsfp/qsfp.h"
#include "../../lib/txp/txp.h"
}

DEFINE_FFF_GLOBALS;

int n_call;
float temp_chnl[] = {48.5,49.0,49.5,50.0, 50.5,51.0,51.5,52.0};
int xfp_los[] = {1,1,1,1};
int xfp_tx_power[] = {41, 42, 43, 44};
int xfp_rx_power[] = {45, 46, 47, 48};

/*
 * **************** *
 * *              * *
 * *    MOCKS     * *
 * *              * *
 * **************** *
*/

/* TMP Init */

FAKE_VALUE_FUNC(int, tmp_enable_extrange_mock);
int tmp_enable_extrange_mock_ret_ref_ok_ok(void) {
	return 0;
}

FAKE_VALUE_FUNC(int, tmp_celsius_to_ext_temp_regs_mock, float, temp_registers_t*);
int tmp_celsius_to_ext_temp_regs_mock_ret_ref_ok_ok(float temperature, temp_registers_t *temp_regs) {
	// in this mock temperature parameter not pass in, it is always cero here 
	if (temperature > 191.875) 
    {
        temp_regs->main_bits = 0xff;
        temp_regs->extended_bits = 0xe0;
        return -1;
    } 
    else if (temperature < -64.875)
    {
        temp_regs->main_bits = 0x00;
        temp_regs->extended_bits = 0xe0;
        return -1;
    }

    int decimal, fractional;
    temperature += 64;
    decimal = (int) temperature;
    fractional = (int)((temperature - decimal) / 0.125) << 5;

    temp_regs->main_bits = decimal;
    temp_regs->extended_bits = fractional;  
    return 0;
}

FAKE_VALUE_FUNC(int, tmp_set_alert_high_limit_reg_mock, int, int);
int tmp_set_alert_high_limit_reg_mock_ret_ref_ok_ok(int arg0, int arg1) {
	return 0;
}

FAKE_VALUE_FUNC(int, tmp_set_mask_alert_mock, int, int);
int tmp_set_mask_alert_mock_ret_ref_ok_ok(int arg0, int arg1) {
	return 0;
}

FAKE_VALUE_FUNC(int, tmp_set_overt_high_limit_reg_mock, int, int);
int tmp_set_overt_high_limit_reg_mock_ret_ref_ok_ok(int arg0, int arg1) {
	return 0;
}

FAKE_VALUE_FUNC(int, tmp_set_mask_overt_mock, int, int);
int tmp_set_mask_overt_mock_ret_ref_ok_ok(int arg0, int arg1) {
	return 0;
}

FAKE_VALUE_FUNC(int, tmp_set_alert_low_limit_reg_mock, int);
int tmp_set_alert_low_limit_reg_mock_ret_ref_ok_ok(int arg0) {
	return 0;
}

FAKE_VALUE_FUNC(int, tmp_set_alert_low_disable_bit_mock, int, int);
int tmp_set_alert_low_disable_bit_mock_ret_ref_ok_ok(int arg0, int arg1) {
	return 0;
}

/* TMP */

FAKE_VALUE_FUNC(int, tmp_get_alert_high_status_reg_mock, int*);
int tmp_get_alert_high_status_reg_mock_ret_ref_ok_ok(int *arg0) {
	*arg0 = 0xFF; // todos los canales
	return 0;
}

FAKE_VALUE_FUNC(int, tmp_get_ext_temp_mock, int, float*);
int tmp_get_ext_temp_mock_ret_ref_ok_ok(int arg0, float *arg1){
	*arg1 = temp_chnl[n_call % 8];
	n_call++;
	return 0;
}

FAKE_VALUE_FUNC(int, tmp_get_overt_status_reg_mock, int*);
int tmp_get_overt_status_reg_mock_ret_ref_ok_ok(int *arg0) {
	*arg0 = 0xFF; // todos los canales
	return 0;
}

FAKE_VALUE_FUNC(int, tmp_get_diode_fault_status_reg_mock, int*);
int tmp_get_diode_fault_status_reg_mock_ret_ref_ok_ok(int *arg0) {
	*arg0 = 0xFF; // todos los canales
	return 0;
}

FAKE_VALUE_FUNC(int, tmp_get_alert_low_status_reg_mock, int*);
int tmp_get_alert_low_status_reg_mock_ret_ref_ok_ok(int *arg0) {
	*arg0 = 0xFF; // todos los canales
	return 0;
}

/* HMD */

FAKE_VALUE_FUNC(int, hmd_disable_fast_conversion_mock);
int hmd_disable_fast_conversion_mock_ret_ref_ok_ok(void) {
	return 0;
}

FAKE_VALUE_FUNC(int, hmd_disable_heater_mock);
int hmd_disable_heater_mock_ret_ref_ok_ok(void) {
	return 0;
}

FAKE_VALUE_FUNC(int, hmd_get_temp_comp_humidity_mock, int*);
int hmd_get_temp_comp_humidity_mock_ret_ref_ok_ok(int *arg0) {
	*arg0 = 40; // todos los canales
	return 0;
}

/* XFP Init */

FAKE_VALUE_FUNC(int, ltc_enable_latch_mock);
int ltc_enable_latch_mock_ret_ref_ok_ok(void) {
	return 0;
}

FAKE_VALUE_FUNC(int, xfp_power_up_mock, int);
int xfp_power_up_mock_ret_ref_ok_ok(int arg0) {
	return 0;
}

FAKE_VALUE_FUNC(int, xfp_set_data_rate_mock, int);
int xfp_set_data_rate_mock_ret_ref_ok_ok(int arg0) {
	return 0;
}

FAKE_VALUE_FUNC(int, xfp_set_wavelength_mock, int, int);
int xfp_set_wavelength_mock_ret_ref_ok_ok(int arg0, int arg1) {
	return 0;
}

FAKE_VALUE_FUNC(int, xfp_set_threshold_mock, int, int, int);
int xfp_set_threshold_mock_ret_ref_ok_ok(int arg0, int arg1, int arg2) {
	return 0;	
}

/* XFP */

FAKE_VALUE_FUNC(int, xfp_get_loss_of_signal_status_mock, int, int*);
int xfp_get_loss_of_signal_status_mock_ret_ref_ok_ok(int arg0, int *arg1) {
	*arg1 = xfp_los[arg0]; 
	return 0;
}

FAKE_VALUE_FUNC(int, xfp_get_int_flag_mock, int, int, int, int*);
int xfp_get_int_flag_mock_ret_ref_ok_ok(int arg0, int arg1, int arg2, int* arg3) {
	*arg3 = 1;
	return 0;
}

FAKE_VALUE_FUNC(int, xfp_set_mask_mock, int, int, int, int);
int xfp_set_mask_mock_ret_ref_ok_ok(int arg0, int arg1, int arg2, int arg3) {	
	return 0;
}

FAKE_VALUE_FUNC(int, xfp_get_tx_power_mock, int, int*);
int xfp_get_tx_power_mock_ret_ref_ok_ok(int arg0, int *arg1) {
	*arg1 = xfp_tx_power[arg0]; 
	return 0;
}

FAKE_VALUE_FUNC(int, xfp_get_rx_power_mock, int, int*);
int xfp_get_rx_power_mock_ret_ref_ok_ok(int arg0, int *arg1) {
	*arg1 = xfp_rx_power[arg0]; 
	return 0;
}

/* QSFP Init */

FAKE_VALUE_FUNC(int, qsfp_set_control_mock, control_t, int);
int qsfp_set_control_mock_ret_ref_ok_ok(control_t arg0, int arg1) {
	return 0;
}

/* QSFP */

FAKE_VALUE_FUNC(int, qsfp_get_int_flags_mock, int, int*);
int qsfp_get_int_flags_mock_ret_ref_ok_ok(int arg0, int *arg1) {
	*arg1 = 0xFF; 
	return 0;
}

FAKE_VALUE_FUNC(int, qsfp_get_mod_monitor_mock, int, int*);
int qsfp_get_mod_monitor_mock_ret_ref_ok_ok(int arg0, int *arg1) {
	*arg1 = 0x40; 
	return 0;
}

FAKE_VALUE_FUNC(int, qsfp_get_chnl_monitor_mock, int, int*);
int qsfp_get_chnl_monitor_mock_ret_ref_ok_ok(int arg0, int *arg1) {
	*arg1 = 0x40; 
	return 0;
}

/* TXP Init */

FAKE_VALUE_FUNC(int, txp_jdsu_read_protected_mode_mock, int);
int txp_jdsu_read_protected_mode_mock_ret_ref_ok_ok(int arg0) {
	return 0;
}

FAKE_VALUE_FUNC(int, txp_enter_protected_mode_mock);
int txp_enter_protected_mode_mock_ret_ref_ok_ok(void) {
	return 0;
}

FAKE_VALUE_FUNC(int, txp_set_tx_cmd_reg_mock, tx_cmd_t);
int txp_set_tx_cmd_reg_mock_ret_ref_ok_ok(tx_cmd_t arg0) {
	return 0;
}

FAKE_VALUE_FUNC(int, txp_set_rx_cmd_reg_mock, rx_cmd_t);
int txp_set_rx_cmd_reg_mock_ret_ref_ok_ok(rx_cmd_t arg0) {
	return 0;
}

FAKE_VALUE_FUNC(int, txp_set_laser_itu_channel_mock, itu_channel_t);
int txp_set_laser_itu_channel_mock_ret_ref_ok_ok(itu_channel_t arg0) {
	return 0;
}

FAKE_VALUE_FUNC(int, txp_jdsu_set_rxpowalm_threshold_mock, int, int);
int txp_jdsu_set_rxpowalm_threshold_mock_ret_ref_ok_ok(int lvl2alarm, int lvl2idle) {
	return 0;
}

FAKE_VALUE_FUNC(int, txp_jdsu_set_modbiasalm_threshold_mock, int, int, int, int);
int txp_jdsu_set_modbiasalm_threshold_mock_ret_ref_ok_ok(int high2alarm, int low2alarm, int high2idle, int low2idle) {
	return 0;
}

FAKE_VALUE_FUNC(int, txp_jdsu_set_lolsbiasalm_threshold_mock, int, int);
int txp_jdsu_set_lolsbiasalm_threshold_mock_ret_ref_ok_ok(int curr2alarm, int curr2idle) {
	return 0;
}

FAKE_VALUE_FUNC(int, txp_jdsu_set_txptempalm_threshold_mock, int, int);
int txp_jdsu_set_txptempalm_threshold_mock_ret_ref_ok_ok(int temp2alarm, int temp2idle) {
	return 0;
}

FAKE_VALUE_FUNC(int, txp_jdsu_set_txpowalm_threshold_mock, int, int, int, int);
int txp_jdsu_set_txpowalm_threshold_mock_ret_ref_ok_ok(int high2alarm, int low2alarm, int high2idle, int low2idle) {
	return 0;
}

FAKE_VALUE_FUNC(int, txp_jdsu_set_rxpowalm_threshold_rxlos_rxs_mock, int, int, int, int);
int txp_jdsu_set_rxpowalm_threshold_rxlos_rxs_mock_ret_ref_ok_ok(int lvl2alarm_rxlos, int lvl2idle_rxlos, int lvl2alarm_rxs, int lvl2idle_rxs) {
	return 0;
}

FAKE_VALUE_FUNC(int, txp_jdsu_set_rxhighpowalm_threshold_mock, int, int);
int txp_jdsu_set_rxhighpowalm_threshold_mock_ret_ref_ok_ok(int hpl2alarm, int hpl2idle) {
	return 0;
}

FAKE_VALUE_FUNC(int, txp_jdsu_set_lsbiasalm_threshold_mock, int, int);
int txp_jdsu_set_lsbiasalm_threshold_mock_ret_ref_ok_ok(int lsb2alarm, int lsb2idle) {
	return 0;
}

FAKE_VALUE_FUNC(int, txp_jdsu_set_dsp_temp_mon_threshold_mock, int);
int txp_jdsu_set_dsp_temp_mon_threshold_mock_ret_ref_ok_ok(int temp_mon) {
	return 0;
}

/* TXP */

FAKE_VALUE_FUNC(int, txp_read_tx_alarm_status_register_mock, tx_alarm_t*);
int txp_read_tx_alarm_status_register_mock_ret_ref_ok_ok(tx_alarm_t *arg0) {
	
    arg0->eolalm = 0;
    arg0->modtempalm = 0;
    arg0->txooa = 0;
    arg0->txlofalm = 0;
    arg0->txdscerr = 0;
    arg0->lswavalm = 0;
    
    arg0->txalm = 0;
    arg0->lsbiasalm = 0;
    arg0->lstempalm = 0;
    arg0->txlockerr = 0;
    arg0->lspowalm = 0;
    arg0->modbiasalm = 0;
    arg0->txfifoerr = 0;

	return 0;
}

FAKE_VALUE_FUNC(int, txp_read_rx_alarm_status_register_mock, rx_alarm_t*);
int txp_read_rx_alarm_status_register_mock_ret_ref_ok_ok(rx_alarm_t *arg0) {
	arg0->rxalm = 0;
	arg0->rxpowalm = 0;
	arg0->rxlos = 0;
	arg0->rxlockerr = 0;
	arg0->rxs = 0;
	arg0->prbserrdet = 0;

	return 0;
}

FAKE_VALUE_FUNC(int, txp_read_power_supply_alarm_status_register_mock, supply_alarm_t*);
int txp_read_power_supply_alarm_status_register_mock_ret_ref_ok_ok(supply_alarm_t *arg0) {
	arg0->psummary = 0;
	arg0->p5vanalog = 0;
	arg0->n5v2analog = 0;
	arg0->p3p3vanalog = 0;
	arg0->p3p3vdigital = 0;
	arg0->lvdigital = 0;
	arg0->n5p2vdigital = 0;

	return 0;
}

FAKE_VALUE_FUNC(int, txp_read_summary_alarm_register_mock, summary_alarm_t*);
int txp_read_summary_alarm_register_mock_ret_ref_ok_ok(summary_alarm_t *arg0) {
    arg0->txalm = 0;
    arg0->rxalm = 0;
    arg0->psummary = 0;

	return 0;
}



/*
 * **************** *
 * *              * *
 * *    TESTS     * *
 * *              * *
 * **************** *
*/

TEST(NormalTest, test_default) {
	n_call = 0;
	config_t config;

	/* TMP Init */

	RESET_FAKE(tmp_enable_extrange_mock);
	RESET_FAKE(tmp_celsius_to_ext_temp_regs_mock);
	RESET_FAKE(tmp_set_alert_high_limit_reg_mock);
	RESET_FAKE(tmp_set_mask_alert_mock);

	RESET_FAKE(tmp_set_overt_high_limit_reg_mock);
	RESET_FAKE(tmp_set_mask_overt_mock);
	RESET_FAKE(tmp_set_alert_low_limit_reg_mock);
	RESET_FAKE(tmp_set_alert_low_disable_bit_mock);

	RESET_FAKE(tmp_get_alert_high_status_reg_mock);
	RESET_FAKE(tmp_get_ext_temp_mock);
	RESET_FAKE(tmp_get_overt_status_reg_mock);
	RESET_FAKE(tmp_get_diode_fault_status_reg_mock);
	RESET_FAKE(tmp_get_alert_low_status_reg_mock);
	
	RESET_FAKE(hmd_disable_fast_conversion_mock);
	RESET_FAKE(hmd_disable_heater_mock);
	RESET_FAKE(hmd_get_temp_comp_humidity_mock);
	
	/* XFP Init */

	RESET_FAKE(ltc_enable_latch_mock);
	RESET_FAKE(xfp_power_up_mock);
	RESET_FAKE(xfp_set_data_rate_mock);
	RESET_FAKE(xfp_set_wavelength_mock);
	RESET_FAKE(xfp_set_threshold_mock);

	/* XFP */

	RESET_FAKE(xfp_get_loss_of_signal_status_mock);
	RESET_FAKE(xfp_get_int_flag_mock);
	RESET_FAKE(xfp_set_mask_mock);
	RESET_FAKE(xfp_get_tx_power_mock);
	RESET_FAKE(xfp_get_rx_power_mock);

	/* QSFP Init */

	RESET_FAKE(qsfp_set_control_mock);

	/* QSFP */

	RESET_FAKE(qsfp_get_int_flags_mock);
	RESET_FAKE(qsfp_get_chnl_monitor_mock);

	/* TXP Init */

	RESET_FAKE(txp_jdsu_read_protected_mode_mock);
	RESET_FAKE(txp_enter_protected_mode_mock);
	RESET_FAKE(txp_set_tx_cmd_reg_mock);

	RESET_FAKE(txp_set_laser_itu_channel_mock);
	RESET_FAKE(txp_set_rx_cmd_reg_mock);
	RESET_FAKE(txp_jdsu_set_rxpowalm_threshold_mock);
	RESET_FAKE(txp_jdsu_set_modbiasalm_threshold_mock);
	RESET_FAKE(txp_jdsu_set_lolsbiasalm_threshold_mock);
	RESET_FAKE(txp_jdsu_set_txptempalm_threshold_mock);
	RESET_FAKE(txp_jdsu_set_txpowalm_threshold_mock);
	RESET_FAKE(txp_jdsu_set_rxpowalm_threshold_rxlos_rxs_mock);
	RESET_FAKE(txp_jdsu_set_rxhighpowalm_threshold_mock);
	RESET_FAKE(txp_jdsu_set_lsbiasalm_threshold_mock);
	RESET_FAKE(txp_jdsu_set_dsp_temp_mon_threshold_mock);

	/* TXP */

	RESET_FAKE(txp_read_tx_alarm_status_register_mock);
	RESET_FAKE(txp_read_rx_alarm_status_register_mock);
	RESET_FAKE(txp_read_summary_alarm_register_mock);
	RESET_FAKE(txp_read_power_supply_alarm_status_register_mock);

	FFF_RESET_HISTORY();

	/* TMP Init */

	tmp_enable_extrange_mock_fake.custom_fake = tmp_enable_extrange_mock_ret_ref_ok_ok;
	tmp_celsius_to_ext_temp_regs_mock_fake.custom_fake = tmp_celsius_to_ext_temp_regs_mock_ret_ref_ok_ok;
	tmp_set_alert_high_limit_reg_mock_fake.custom_fake = tmp_set_alert_high_limit_reg_mock_ret_ref_ok_ok;
	tmp_set_mask_alert_mock_fake.custom_fake = tmp_set_mask_alert_mock_ret_ref_ok_ok;
	tmp_set_overt_high_limit_reg_mock_fake.custom_fake = tmp_set_overt_high_limit_reg_mock_ret_ref_ok_ok;
	tmp_set_mask_overt_mock_fake.custom_fake = tmp_set_mask_overt_mock_ret_ref_ok_ok;
	tmp_set_alert_low_limit_reg_mock_fake.custom_fake = tmp_set_alert_low_limit_reg_mock_ret_ref_ok_ok;
	tmp_set_alert_low_disable_bit_mock_fake.custom_fake = tmp_set_alert_low_disable_bit_mock_ret_ref_ok_ok;

	/* TMP */

	tmp_get_alert_high_status_reg_mock_fake.custom_fake = tmp_get_alert_high_status_reg_mock_ret_ref_ok_ok;
	tmp_get_ext_temp_mock_fake.custom_fake = tmp_get_ext_temp_mock_ret_ref_ok_ok;
	tmp_get_overt_status_reg_mock_fake.custom_fake = tmp_get_overt_status_reg_mock_ret_ref_ok_ok;
	tmp_get_diode_fault_status_reg_mock_fake.custom_fake = tmp_get_diode_fault_status_reg_mock_ret_ref_ok_ok;
	tmp_get_alert_low_status_reg_mock_fake.custom_fake = tmp_get_alert_low_status_reg_mock_ret_ref_ok_ok;

	/* HMD Init */

	hmd_disable_heater_mock_fake.custom_fake = hmd_disable_heater_mock_ret_ref_ok_ok;
	hmd_disable_fast_conversion_mock_fake.custom_fake = hmd_disable_fast_conversion_mock_ret_ref_ok_ok;
	
	/* HMD */

	hmd_get_temp_comp_humidity_mock_fake.custom_fake = hmd_get_temp_comp_humidity_mock_ret_ref_ok_ok;

	/* XFP Init */

	ltc_enable_latch_mock_fake.custom_fake = ltc_enable_latch_mock_ret_ref_ok_ok;
	xfp_power_up_mock_fake.custom_fake = xfp_power_up_mock_ret_ref_ok_ok;
	xfp_set_data_rate_mock_fake.custom_fake = xfp_set_data_rate_mock_ret_ref_ok_ok;
	xfp_set_wavelength_mock_fake.custom_fake = xfp_set_wavelength_mock_ret_ref_ok_ok;
	xfp_set_threshold_mock_fake.custom_fake = xfp_set_threshold_mock_ret_ref_ok_ok;

	/* XFP */

	xfp_get_loss_of_signal_status_mock_fake.custom_fake = xfp_get_loss_of_signal_status_mock_ret_ref_ok_ok;
	xfp_get_int_flag_mock_fake.custom_fake = xfp_get_int_flag_mock_ret_ref_ok_ok;
	xfp_set_mask_mock_fake.custom_fake = xfp_set_mask_mock_ret_ref_ok_ok;
	xfp_get_tx_power_mock_fake.custom_fake = xfp_get_tx_power_mock_ret_ref_ok_ok;
	xfp_get_rx_power_mock_fake.custom_fake = xfp_get_rx_power_mock_ret_ref_ok_ok;
	//_fake.custom_fake = _ret_ref_ok_ok;

	/* QSFP Init */

	qsfp_set_control_mock_fake.custom_fake = qsfp_set_control_mock_ret_ref_ok_ok;
	
	/* QSFP */

	qsfp_get_int_flags_mock_fake.custom_fake = qsfp_get_int_flags_mock_ret_ref_ok_ok;
	qsfp_get_chnl_monitor_mock_fake.custom_fake = qsfp_get_chnl_monitor_mock_ret_ref_ok_ok;

	/* TXP Init */

	txp_jdsu_read_protected_mode_mock_fake.custom_fake = txp_jdsu_read_protected_mode_mock_ret_ref_ok_ok;
	txp_enter_protected_mode_mock_fake.custom_fake = txp_enter_protected_mode_mock_ret_ref_ok_ok;
	txp_set_tx_cmd_reg_mock_fake.custom_fake = txp_set_tx_cmd_reg_mock_ret_ref_ok_ok;
	txp_set_laser_itu_channel_mock_fake.custom_fake = txp_set_laser_itu_channel_mock_ret_ref_ok_ok;
	txp_set_rx_cmd_reg_mock_fake.custom_fake = txp_set_rx_cmd_reg_mock_ret_ref_ok_ok;
	txp_jdsu_set_rxpowalm_threshold_mock_fake.custom_fake = txp_jdsu_set_rxpowalm_threshold_mock_ret_ref_ok_ok;
	txp_jdsu_set_modbiasalm_threshold_mock_fake.custom_fake = txp_jdsu_set_modbiasalm_threshold_mock_ret_ref_ok_ok;
	txp_jdsu_set_lolsbiasalm_threshold_mock_fake.custom_fake = txp_jdsu_set_lolsbiasalm_threshold_mock_ret_ref_ok_ok;
	txp_jdsu_set_txptempalm_threshold_mock_fake.custom_fake = txp_jdsu_set_txptempalm_threshold_mock_ret_ref_ok_ok;
	txp_jdsu_set_txpowalm_threshold_mock_fake.custom_fake = txp_jdsu_set_txpowalm_threshold_mock_ret_ref_ok_ok;
	txp_jdsu_set_rxpowalm_threshold_rxlos_rxs_mock_fake.custom_fake = txp_jdsu_set_rxpowalm_threshold_rxlos_rxs_mock_ret_ref_ok_ok;
	txp_jdsu_set_rxhighpowalm_threshold_mock_fake.custom_fake = txp_jdsu_set_rxhighpowalm_threshold_mock_ret_ref_ok_ok;
	txp_jdsu_set_lsbiasalm_threshold_mock_fake.custom_fake = txp_jdsu_set_lsbiasalm_threshold_mock_ret_ref_ok_ok;
	txp_jdsu_set_dsp_temp_mon_threshold_mock_fake.custom_fake = txp_jdsu_set_dsp_temp_mon_threshold_mock_ret_ref_ok_ok;

	/* TXP */

	txp_read_tx_alarm_status_register_mock_fake.custom_fake = txp_read_tx_alarm_status_register_mock_ret_ref_ok_ok;
	txp_read_rx_alarm_status_register_mock_fake.custom_fake = txp_read_rx_alarm_status_register_mock_ret_ref_ok_ok;
	txp_read_summary_alarm_register_mock_fake.custom_fake = txp_read_summary_alarm_register_mock_ret_ref_ok_ok;
	txp_read_power_supply_alarm_status_register_mock_fake.custom_fake = txp_read_power_supply_alarm_status_register_mock_ret_ref_ok_ok;

	get_config("mond.conf", &config);

	ASSERT_EQ(0, init_tmp(&config.tmp));
	ASSERT_EQ(0, log_tmp(&config.tmp));

	ASSERT_EQ(0, init_hmd());
	ASSERT_EQ(0, log_hmd(&config.hmd));

	ASSERT_EQ(0, init_T41());
	ASSERT_EQ(0, log_otn());
	ASSERT_EQ(0, log_eth());

	ASSERT_EQ(0, init_xfp(&config.xfp));
	ASSERT_EQ(0, log_xfp());

	ASSERT_EQ(0, init_qsfp(&config.qsfp));
	ASSERT_EQ(0, log_qsfp(&config.qsfp));

	ASSERT_EQ(0, init_txp(&config.txp));
	ASSERT_EQ(0, log_txp());

}






/*
 * **************** *
 * *              * *
 * *     MAIN     * *
 * *              * *
 * **************** *
*/


int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}
