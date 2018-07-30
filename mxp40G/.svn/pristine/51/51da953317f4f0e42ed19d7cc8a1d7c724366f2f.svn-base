/**
 * \file
 * \brief QSFP API header.
 * 
 */
#ifndef _QSFP_H_
#define _QSFP_H_

/**
 * I2C Module Bus
 */
#define QSFP_BUS 0x05

/**
 * I2C Module Address
 */
#define QSFP_SLAVE_ADDRESS  0x50

/**
 * Identifier Register Address.
 */
#define QSFP_ID 0

/**
 * QSFP Status.
 */
#define QSFP_STATUS 2
/**
 * QSFP Interrupted.
 */
#define QSFP_INTERRUPTED 0
/**
 * QSFP Low Power Mode.
 */
#define QSFP_LOW_POWER_MODE 1
/**
 * QSFP High Power Mode.
 */
#define QSFP_HIGH_POWER_MODE 0
/**
 * QSFP Reset Pulse DOWN.
 */
#define QSFP_RESET_PULSE_DOWN 0
/**
 * QSFP Reset Pulse UP..
 */
#define QSFP_RESET_PULSE_UP 1
/**
 * QSFP Reset Init Time (uSec).
 */
#define QSFP_T_RESET_INIT 2 //uSecond

/**
 * Communication Enabled Value.
 */
#define QSFP_COMM_ENABLED 0
/**
 * Communication Disabled Value.
 */
#define QSFP_COMM_DISABLED 1

/**
 * Interrupt Flags Registers.
 */
typedef enum {
   /**Latched TX LOS indicator.*/
   channel_los_3 = 3,
   
   /**Latched TX fault indicator.*/
   channel_fault_4 = 4,
   
   /**Reserved.*/
   channel_sts_5 = 5, 
   
   /**Latched Temperature alarms and warnings.*/
   module_temp_6 = 6,
   
   /**Latched high supply voltage alarms and warnings.*/
   module_mon_7 = 7,
   
   /**Reserved flag.*/
   module_mon_8 = 8, 
   
   /** Latched RX1-2 power alarms and warnings*/
   channel_mon_9 = 9,
   
   /** Latched RX3-4 power alarms and warnings*/
   channel_mon_10 = 10,
   
   /** Latched TX1-2 bias alarms and warnings*/
   channel_mon_11 = 11,
   
   /** Latched TX3-4 bias alarms and warnings*/
   channel_mon_12 = 12,
   
   /**Reserved flag.*/
   channel_mon_13 = 13, 
   
   /**Reserved flag.*/
   channel_mon_14 = 14, 
   
   /**Reserved flag.*/
   channel_mon_15 = 15, 
   
   /**Reserved flag.*/
   channel_mon_16 = 16, 
   
   /**Reserved flag.*/
   channel_mon_17 = 17, 
   
   /**Reserved flag.*/
   channel_mon_18 = 18, 
   
   /**Vendor Specific flag.*/
   channel_mon_19 = 19, 
   
   /**Vendor Specific flag.*/
   channel_mon_20 = 20, 
   
   /**Vendor Specific flag.*/
   channel_mon_21 = 21 
} flg_reg_t;

/**
 * Module Monitors Registers.
 */
typedef enum {
    
   /** Internally measured module temperature.*/
   temp_msb = 22,
   
   /** Reserved Flag.*/
   rsvd_24 = 24, // RSVD
   
   /** Reserved Flag.*/
   rsvd_25 = 25, // RSVD
   
   /**Internally measured module supply voltage.*/
   voltage_msb = 26,
   
   /** Reserved Flag.*/
   rsvd_28 = 28, // RSVD
   
   /** Reserved Flag.*/
   rsvd_29 = 29, // RSVD
   
   /** Vendor Specific Flag.*/
   vendor_30 = 30, // Vendor Specific
   
   /** Vendor Specific Flag.*/
   vendor_31 = 31, // Vendor Specific
   
   /** Vendor Specific Flag.*/
   vendor_32 = 32, // Vendor Specific
   
   /** Vendor Specific Flag.*/
   vendor_33 = 33 // Vendor Specific
} mod_mon_t;

/**
 * Channel Monitors Registers.
 */
typedef enum {
    
   /** Internally measured RX1 input power.*/
   rx1_pwr_msb = 34,
   
   /** Internally measured RX2 input power.*/
   rx2_pwr_msb = 36,
   
   /** Internally measured RX3 input power.*/
   rx3_pwr_msb = 38,
   
   /** Internally measured RX4 input power.*/
   rx4_pwr_msb = 40,
   
   /** Internally measured TX1 bias.*/
   tx1_bias_msb = 42,
   
   /** Internally measured TX2 bias.*/
   tx2_bias_msb = 44,
   
   /** Internally measured TX3 bias.*/
   tx3_bias_msb = 46,
   
   /** Internally measured TX4 bias.*/
   tx4_bias_msb = 48
   
} chnl_mon_t;

/* from 82 to 85 are RSVD */

/**
 * Control Registers.
 */
typedef enum {
    
   /** Tx1-4 Disable */
   txn_disable = 86,
   
   /** RX1-4 Software Rate Select */
   rxn_rate_select = 87,
   
   /** TX1-4 Software Rate Select */
   txn_rate_select = 88,
   
   /**RX4 Software Application Select per SFF-8079*/
   rx4_app_select = 89,
   
   /**RX3 Software Application Select per SFF-8079*/   
   rx3_app_select = 90,
   
   /**RX2 Software Application Select per SFF-8079*/
   rx2_app_select = 91,
   
   /**RX1 Software Application Select per SFF-8079*/
   rx1_app_select = 92,
   
   /**Power Register*/
   power = 93,
   
   /**TX4 Software Application Select per SFF-8079*/
   tx4_app_select = 94,
   
   /**TX3 Software Application Select per SFF-8079*/
   tx3_app_select = 95,
   
   /**TX2 Software Application Select per SFF-8079*/
   tx2_app_select = 96,
   
   /**TX1 Software Application Select per SFF-8079*/
   tx1_app_select = 97
   
} control_t;

/**
 * Module and Channel Masks Registers.
 */
typedef enum {
  
   /** Masking bit for TX1-4 LOS indicator.*/
   mod_los = 100,
   
   /**Masking bit for TX1-4 fault indicator.*/
   mod_fault = 101,
   
   /**Reserved.*/
   rsvd_102 = 102, /* 102 RSVD */
   
   /**Masking bit for high Temperature alarms and warnings.*/
   mod_temp = 103,
   
   /** Masking bit for Vcc alarms and warnings.*/
   mod_alarm = 104,
   
   /** Reserved.*/
   vendor_105 = 105,
   
   /** Reserved.*/
   vendor_106 = 106 /* 105 and 106 are Vendor Specific */
} reg_mask_t;


/**
 * QSFP New Password Address Register.
 */
#define QSFP_NEW_PASSWD 119

/**
 * QSFP Current Password Address Register.
 */

#define QSFP_CURRENT_PASSWD 123

/* From 123 to 126 Password Entry Area */
/**
 * Manufacturer Password Mask
 */
#define QSFP_HOST_MANUFACTURER_PASSWD_MASK 0x7FFFFFFF

/**
 * QSFP Page select Byte.
 */
#define QSFP_PAGE_SELECT_BYTE 127

typedef enum {
    
   /**Identifier Type of serial transceiver Register Address.*/
   id = 128,
   /**Extended Identifier Type of serial transceiver Register Address.*/
   ext_id = 129,
   
   /**Code for connector type Register Address.*/
   connector = 130,
   
   /**10 Gigabit Ethernet Compliance Codes Register Address.*/
   ethernet = 131,
   
    /**SONET Compliance Codes Register Address.*/
   sonet = 132,
   
    /**SATA Register Address.*/
   sas_sata = 133,
   
    /**Gigabit Ethernet Compliance Codes Register Address.*/
   gb_ethernet = 134,
   
    /**Fibre Channel link length Register Address.*/
   fibre_chn_link1 = 135,
   
    /**Fibre Channel transmitter technology Register Address.*/
   fibre_chn_link2 = 136,
   
    /**Fiber Channel transmission media Register Address.*/
   fibre_chn_trans = 137,
   
    /**Fibre Channel Speed Register Address.*/
   fibre_chn_speed = 138,
   
    /** Code for serial encoding algorithm Register Address.*/
   encoding = 139,
   
    /** Nominal bit rate Register Address.*/
   br_nominal = 140,
   
    /** Tags for Extended RateSelect compliance Register Address.*/
   ext_ratesel_comp = 141,
   
    /** Link length supported for SMF fiber Register Address.*/
   length_smf = 142,
   
    /**Link length supported for EBW 50/125 μm fiber Register Address.*/
   length_om3 = 143,
   
    /**Link length supported for 50/125 μm fiber Register Address.*/
   length_om2 = 144,
   
    /**Link length supported for 62.5/125 μm fiber Register Address.*/
   length_om1 = 145,
   
    /**Link length supported for copper Register Address.*/
   lenght_copper = 146,
   
    /**Device technology Register Address.*/
   device_tech = 147,
   
    /**QSFP vendor name Register Address.*/
   vendor_name = 148,
   
    /**Extended Transceiver Codes for InfiniBand Register Address.*/
   ext_module = 164,
   
    /**QSFP vendor IEEE company ID Register Address.*/
   vendor_oui = 165,
   
    /**Part number provided by QSFP vendor Register Address.*/
   part_number = 168,
   
    /**Revision level for part number provided by vendor Register Address.*/
   rev_level = 184,
   
    /**Nominal laser wavelength Register Address.*/
   wavelength = 186,
   
    /**Guaranteed range of laser wavelength (+/- value) from Nominal wavelength Register Address.*/
   wl_tolerance = 188,
   
    /**Maximum Case Temperature Register Address.*/
   max_case_temp = 190,
   
    /**Check code for Base ID Fields Register Address.*/
   cc_base = 191,
   
    /**Options Register Address.*/
   options = 192,
   
    /**Serial number provided by vendor Register Address.*/
   serial_number = 196,
   
    /**Vendor's manufacturing date code Register Address.*/
   date_code = 212,
   
    /**Diagnostic Monitoring Type Register Address.*/
   diag_mon_type = 220,
   
    /**Enhanced Options Register Address.*/
   enhanced_options = 221,
   
    /**Reserved*/
   rsvd_222 = 222,
   
    /**Check code for the Extended ID Fields Register Address.*/
   cc_ext = 223,
   
    /** Vendor Specific EEPROM Register Address.*/
   eeprom = 224
} page0_t;

/**
 * Upper Memory Map Page 01h.
 */
typedef enum {
  
   /**Check code for the AST Register Address.*/  
   cc_apps = 128,
   
   /**AST Table Length Register Address.*/
   table_length = 129,
   
   /**Application code 0 Register Address.*/
   app_code_0 = 130
   
} page1_t;

/**
 *Upper Memory Map Page 02h
 */
typedef enum {
    
   /** */
   clei_code = 128
} page2_t;

/**
 * The upper memory map page 03h contains module thresholds.
 */
typedef enum {
    
   /** High Temperature Alarms Register Address*/ 
   temp_high_alarm = 128,
   
    /**Low Temperature Alarms Register Address*/
   temp_low_alarm = 130,
   
     /** High Temperature Warning Register Address*/ 
   temp_high_warning = 132,
   
     /**Low Temperature Warning Register Address*/
   temp_low_warning = 134,
   
    /** High VCC Alarms Register Address*/ 
   vcc_high_alarm = 144,
   
     /** Low VCC Alarms Register Address*/ 
   vcc_low_alarm = 146,
   
   /** High VCC Warning Register Address*/ 
   vcc_high_warning = 148,
   
   /** Low VCC Warning Register Address*/ 
   vcc_low_warning = 150,
   
   /** High RX Power Alarm Register Address*/ 
   rx_power_high_alarm = 176,
   
  /** Low RX Power Alarm Register Address*/ 
   rx_power_low_alarm = 178,
   
     /** High RX power Warning Register Address*/ 
   rx_power_high_warning = 180,
   
    /** Low RX power Warning Register Address*/ 
   rx_power_low_warning = 182,
   
   /** High Bias Alarm Register Address*/ 
   tx_bias_high_alarm = 184,
   
  /** Low Bias Alarm Register Address*/ 
   tx_bias_low_alarm = 186,
   
     /** High TX bias Warning Register Address*/ 
   tx_bias_high_warning = 188,
   
    /** Low Tx bias Warning Register Address*/ 
   tx_bias_low_warning = 190
   
} thresholds_t;


typedef enum {
   /** Register Address*/
   rx12_out_amp = 238,
   
   /** Register Address*/
   rx34_out_amp = 239,
   
   /** Rx1-4 Tx1-4 Squelch Disable Register Address*/
   rx_tx_sq_disable = 240,
   
   /** Rx1-4 Output Disable Register Address*/
   rx_out_disable = 241
} vso_control_t;

/**
 * Channel Monitor Masks.
 */
typedef enum {
   /** Masking bits for high RX1-2 Power alarms.*/ 
   mrx12 = 242,
   /** Masking bits for high RX3-4 Power alarms*/ 
   mrx34 = 243,
   /** Masking bits for high TX1-2 Power alarms*/ 
   mtx12 = 244,
   /** Masking bits for high TX3-4 Power alarms*/ 
   mtx34 = 245
} chnl_mon_mask_t;

/**
 * \brief This function is a wrapper of the i2c_read function 
 *
 * This wrapper has a restriction, you only can read a byte
 *
 * \param[in] data_address = the address of register
 * \param[in] size = only can be 2 or I2C_SMBUS_BYTE_DATA
 * \param[out] data = the byte been read
 *
 * \return This function returns -1 if an error occurs otherwise, it returns 0.
 */
int qsfp_read(int data_address, int size, int *data);

/**
 * \brief This function is a wrapper of the i2c_write function 
 *
 * This wrapper has a restriction, you only can write a byte
 *
 * \param[in] data_address = the address of the register
 * \param[in] size = only can be 2 or I2C_SMBUS_BYTE_DATA
 * \param[out] data = the byte been written
 *
 * \return This function returns -1 if an error occurs otherwise, it returns 0.
 */
int qsfp_write(int data_address, int size, int *data);

/**
 * \brief This function is used for change the page number of the upper 
 * multipage memory space  
 *
 * \param[in] page = the page number: 0, 1, 2, 3 
 *
 * \return This function returns -1 if an error occurs otherwise, it returns 0.
 */
int qsfp_set_page(int page);

/**
 * \brief This function is used for query the page number of the currently upper
 * multipage memory space  
 *
 * \param[out] page = the currently page number: 0, 1, 2, 3 
 *
 * \return This function returns -1 if an error occurs otherwise, it returns 0.
 */
int qsfp_get_page(int *page);

/**
 * \brief This function is used to get the id of the QSFP module  
 *
 * \param[out] id = the id of the QSFP module 
 *
 * \return This function returns -1 if an error occurs otherwise, it returns 0.
 */
int qsfp_get_id(int *ident);

/**
 * \brief This function is used to get the status of the QSFP module  
 *
 * \param[out] status = the status of the QSFP module 
 *
 * \return This function returns -1 if an error occurs otherwise, it returns 0.
 */
int qsfp_get_status(int *status);

/**
 * \brief This function is used to get interrupt flags of a given interrupt flag
 * register address 
 *
 * \param[in] freg = interrupt flag register address
 * \param[out] flags = the status of the interrupt flag register
 *
 * \return This function returns -1 if an error occurs otherwise, it returns 0.
 */
int qsfp_get_int_flags(flg_reg_t freg, int *flags);

/**
 * \brief This function is used to get module monitoring values of a given 
 * module monitoring address 
 *
 * \param[in] mreg = module monitoring address
 * \param[out] value = module monitoring values
 *
 * \return This function returns -1 if an error occurs otherwise, it returns 0.
 */
int qsfp_get_mod_monitor(mod_mon_t mreg, int *value);

/**
 * \brief This function is used to get channel monitoring values of a given
 * channel monitoring address 
 *
 * \param[in] creg = channel monitoring address
 * \param[out] value = channel monitoring values
 *
 * \return This function returns -1 if an error occurs otherwise, it returns 0.
 */
int qsfp_get_chnl_monitor(chnl_mon_t creg, int *value);

/**
 * \brief This function is used to get control byte values of a given control
 * byte address 
 *
 * \param[in] ctrl = control byte address
 * \param[out] value = control byte values
 *
 * \return This function returns -1 if an error occurs otherwise, it returns 0.
 */
int qsfp_get_control(control_t ctrl, int *value);

/**
 * \brief This function is used to set control byte values of a given control 
 * byte address 
 *
 * \param[in] ctrl = control byte address
 * \param[in] value = control byte values
 *
 * \return This function returns -1 if an error occurs otherwise, it returns 0.
 */
int qsfp_set_control(control_t ctrl, int value);

/**
 * \brief This function is used to set module and channel mask bit values of a 
 * given module and channel mask address 
 *
 * \param[in] reg_adrs = module and channel mask address
 * \param[in] bit_pos = bit position in the mask
 * \param[in] bit_value = bit value to be set
 *
 * \return This function returns -1 if an error occurs otherwise, it returns 0.
 */
int qsfp_set_mask(reg_mask_t reg_adrs, int bit_pos, int bit_value);

/**
 * \brief This function is used to get module and channel mask bit values of a 
 * given module and channel mask address 
 *
 * \param[in] reg_adrs = module and channel mask address
 * \param[in] bit_pos = bit position in the mask
 * \param[out] bit_value = bit value to be get
 *
 * \return This function returns -1 if an error occurs otherwise, it returns 0.
 */
int qsfp_get_mask(reg_mask_t reg_adrs, int bit_pos, int *bit_value);

/**
 * \brief This function is used to change the host manufacturer password 
 *
 * \param[in] current_passwd = current password
 * \param[in] new_passwd = new password to be set
 *
 * \return This function returns -1 if an error occurs otherwise, it returns 0.
 */
int qsfp_change_passwd(int current_passwd, int new_passwd);

/**
 * \brief This function is used to set the current host manufacturer password 
 *
 * \param[in] current_passwd = current password
 *
 * \return This function returns -1 if an error occurs otherwise, it returns 0.
 */
int qsfp_set_passwd(int current_passwd);

/**
 * \brief This function is used to get page0 register values of a given page0 
 * register address 
 *
 * \param[in] reg = page0 register address
 * \param[out] value = page0 register value
 *
 * \return This function returns -1 if an error occurs otherwise, it returns 0.
 */
int qsfp_get_page0_reg(page0_t reg, int *value); 

/**
 * \brief This function is used to get the Module and Channel threshold register
 * values of a given Module and Channel threshold register address 
 *
 * \param[in] reg_adrs = threshold register address
 * \param[out] value = threshold register value
 *
 * \return This function returns -1 if an error occurs otherwise, it returns 0.
 */
int qsfp_get_thresholds(thresholds_t reg_adrs, int *value);

/**
 * \brief This function is used to get the Vendor Specific and Optional Channel
 * Control register values of a given Vendor Specific and Optional Channel
 * Control register address 
 *
 * \param[in] reg_adrs = Vendor S. and Optional Channel Control register address
 * \param[out] value = Vendor S. and Optional Channel Control register value
 *
 * \return This function returns -1 if an error occurs otherwise, it returns 0.
 */
int qsfp_get_vso_control(vso_control_t reg_adrs, int *value);

/**
 * \brief This function is used to set the Vendor Specific and Optional Channel 
 * Control register values of a given Vendor Specific and Optional Channel 
 * Control register address 
 *
 * \param[in] reg_adrs = Vendor S. and Optional Channel Control register address
 * \param[in] value = Vendor S. and Optional Channel Control register value
 *
 * \return This function returns -1 if an error occurs otherwise, it returns 0.
 */
int qsfp_set_vso_control(vso_control_t reg_adrs, int value);

/**
 * \brief This function is used to set channel monitor mask bit values of a 
 * given channel monitor mask address 
 *
 * \param[in] reg_adrs = channel monitor mask address
 * \param[in] bit_pos = bit position in the mask
 * \param[in] bit_value = bit value to be set
 *
 * \return This function returns -1 if an error occurs otherwise, it returns 0.
 */
int qsfp_set_chnl_mon_mask(chnl_mon_mask_t reg_adrs, int bit_pos, int bit_value);

/**
 * \brief This function is used to get channel monitor mask bit values of a 
 * given channel monitor mask address 
 *
 * \param[in] reg_adrs = channel monitor mask address
 * \param[in] bit_pos = bit position in the mask
 * \param[out] bit_value = bit value to be get
 *
 * \return This function returns -1 if an error occurs otherwise, it returns 0.
 */
int qsfp_get_chnl_mon_mask(chnl_mon_mask_t reg_adrs, int bit_pos, int *bit_value);

/**
 * \brief This function allows to QSFP module answer to bus i2c.
 * 
 * \return This function returns -1 if an error occurs, 0 otherwise.
 */
int qsfp_enable_communication(void);

/**
 * \brief This function disable to QSFP module answer to bus i2c.
 * 
 * \return This function returns -1 if an error occurs, 0 otherwise.
 */
int qsfp_disable_communication(void);


/**
 * \brief This function returns the state of QSFP communication.
 *
 * \param[out] status Communication status is stored in this variable.
 * 
 * \return This function returns -1 if an error occurs otherwise, it returns 0.
 */
int qsfp_get_communication_status(unsigned int *status);

/**
 * \brief This function returns the presence status.
 *
 * \param[out] status Presence status is stored in this variable.
 * 
 * \returnThis function returns -1 if an error occurs otherwise, it returns 0.
 */
int qsfp_get_presence_status(unsigned int *status);


/**
 * \brief This function returns the interruption status.
 *
 * \param[out] status Interruption status is stored in this variable.
 * 
 * \return This function returns -1 if an error occurs otherwise, it returns 0.
 */
int qsfp_read_interruption(unsigned int *status);

/**
 * \brief This function sets the module in low power mode.
 *
 * \return This function returns -1 if an error occurs otherwise, it returns 0.
 */
int qsfp_set_low_power_mode(void);

/**
 * \brief This function sets the module in high power mode.
 *
 * \return This function returns -1 if an error occurs otherwise, it returns 0.
 */
int qsfp_set_high_power_mode(void);


/**
 * \brief This function returns the power mode status.
 *
 * \param[out] status power Mode status is stored in this variable.
 * 
 * \return This function returns -1 if an error occurs otherwise, it returns 0.
 */
int qsfp_get_power_mode_status(unsigned int *status);



/**
 * \brief This function resets the QSFP module.
 *
 * \return This function returns -1 if an error occurs otherwise, it returns 0.
 */
int qsfp_reset(void);


/**
 * \brief This function prints the QSFP Vendor name. 
 *
 * \return This function returns -1 if an error occurs otherwise, it returns 0.
 */
int qsfp_get_vendor_name(void);

/**
 * \brief This function prints the QSFP Vendor organizationally unique Identifier.. 
 *
 * \return This function returns -1 if an error occurs otherwise, it returns 0.
 */
int qsfp_get_vendor_oui(void);
/**
 * \brief This function prints the QSFP Part number. 
 *
 * \return This function returns -1 if an error occurs otherwise, it returns 0.
 */
int qsfp_get_vendor_pn(void);

/**
 * \brief This function prints the QSFP Vendor revision. 
 *
 * \return This function returns -1 if an error occurs otherwise, it returns 0.
 */
int qsfp_get_vendor_rev(void);

/**
 * \brief This function prints the QSFP Vendor serial number. 
 *
 * \return This function returns -1 if an error occurs otherwise, it returns 0.
 */
int qsfp_get_vendor_sn(void);

/**
 * \brief This function prints the QSFP Vendor date code. 
 *
 * \return This function returns -1 if an error occurs otherwise, it returns 0.
 */
int qsfp_get_vendor_date_code(void);


#endif /* _QSFP_H_ */
