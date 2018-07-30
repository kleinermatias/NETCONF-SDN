#ifndef _MOND_H_
#define _MOND_H_

typedef struct {
    int wrng_high_tmp[8];
    int crit_high_tmp[8];
    int wrng_overt_tmp[8];
    int crit_overt_tmp[8];
    int wrng_low_tmp;
    int crit_low_tmp;
} tmp_t;

typedef struct {
    int wrng_hmd;
    int crit_hmd;
} hmd_t;

typedef struct {
    int crit_tx_power;
    int wrng_tx_power;
    int crit_rx_power;
    int wrng_rx_power;
} xfp_t;

typedef struct {
    int crit_temp;
    int wrng_temp;
    int crit_tx_bias;
    int wrng_tx_bias;
    int crit_rx_power;
    int wrng_rx_power;
} qsfp_t;

typedef struct {
    int rx_pow_alm;           // 0.1 dBm 
    int rx_pow_idle;          // 0.1 dBm
    int mod_bias_high_alm;     // 0.1 V
    int mod_bias_low_alm;      // 0.1 V
    int mod_bias_high_idle;    // 0.1 V
    int mod_bias_low_idle;     // 0.1 V
    int lo_ls_bias_alm;        // 0.1 mA
    int lo_ls_bias_idle;       // 0.1 mA
    int temp_idle;        // 0.1 degre C  // Storage case temperature range -40°C 85°C
    int temp_alm;         // 0.1 degre C
    int tx_pow_high_alm;       // 0.1 dBm
    int tx_pow_low_alm;        // 0.1 dB 
    int tx_pow_high_idle;      // 0.1 dBm
    int tx_pow_low_idle;       // 0.1 dB 
    int rx_pow_alm_rxlos;     // 0.1 dBm  // Activation level -24 dBm
    int rx_pow_idle_rxlos;    // 0.1 dBm  // Deactivation level -23.5 dBm
    int rx_pow_alm_rxs;       // 0.1 dBm
    int rx_pow_idle_rxs;      // 0.1 dBm
    int rx_pow_high_alm;       // 0.1 dBm 
    int rx_pow_high_idle;      // 0.1 dBm
    int ls_bias_alm;          // 0.1 mA
    int ls_bias_idle;         // 0.1 mA
    int dsp_temp_mon;       // tenths of C
} txp_t;

typedef struct {
    tmp_t tmp;
    hmd_t hmd;
    xfp_t xfp;
    qsfp_t qsfp;
    txp_t txp;
} config_t;

#endif /* _MOND_H_ */
