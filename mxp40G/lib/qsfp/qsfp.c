#include "qsfp.h"
#include "../i2c/i2crw.h"
#include "../gpio/gpio.h"
#include "../ltc/ltc.h"
#include "../bitman/bitman.h"
#include <unistd.h>
#include "../util/util.h"
#include <ctype.h>
#include <stdio.h>

int qsfp_read(int data_address, int size, int *data)
{
    unsigned int comm_sts;
     
#ifdef TESTING
    CHECK_PARAM(qsfp_get_communication_status_mock(&comm_sts) < 0, LOG_ERR, TAG_QSFP, 
        "Error in qsfp_read(): qsfp_get_communication_status()");
#else
    CHECK_PARAM(qsfp_get_communication_status(&comm_sts) < 0, LOG_ERR, TAG_QSFP, 
        "Error in qsfp_read(): qsfp_get_communication_status()", LOG_LOCAL0);
#endif
    
    CHECK_PARAM(comm_sts == QSFP_COMM_DISABLED, LOG_ERR, TAG_QSFP, 
        "Error in qsfp_read(): Communication is disabled.", LOG_LOCAL0);

    CHECK_PARAM(size != I2C_SMBUS_BYTE_DATA, LOG_ERR, TAG_QSFP, 
        "Error in qsfp_read(): Size is Out of Range", LOG_LOCAL0);

    CHECK_PARAM(data_address < 0 || data_address > 0xff, LOG_ERR, TAG_QSFP, 
        "Error in qsfp_read(): Data Address is Out of Range", LOG_LOCAL0);

    CHECK_PARAM(i2c_read(QSFP_BUS, QSFP_SLAVE_ADDRESS, data_address, size,
            data, 0) < 0, LOG_ERR, TAG_QSFP, 
        "Error in qsfp_read(): i2c_read()", LOG_LOCAL0);

    return 0;
}

int qsfp_write(int data_address, int size, int *data)
{
    unsigned int comm_sts;
     
#ifdef TESTING
    CHECK_PARAM(qsfp_get_communication_status_mock(&comm_sts) < 0, LOG_ERR, TAG_QSFP, 
        "Error in qsfp_write(): qsfp_get_communication_status()", LOG_LOCAL0);
#else
    CHECK_PARAM(qsfp_get_communication_status(&comm_sts) < 0, LOG_ERR, TAG_QSFP, 
        "Error in qsfp_write(): qsfp_get_communication_status()", LOG_LOCAL0);
#endif
    
    CHECK_PARAM(comm_sts == QSFP_COMM_DISABLED, LOG_ERR, TAG_QSFP, 
        "Error in qsfp_write(): Communication is disabled.", LOG_LOCAL0);

    CHECK_PARAM(size != I2C_SMBUS_BYTE_DATA, LOG_ERR, TAG_QSFP, 
        "Error in qsfp_write(): Size is Out of Range", LOG_LOCAL0);

    CHECK_PARAM(data_address < 0 || data_address > 0xff, LOG_ERR, TAG_QSFP, 
        "Error in qsfp_write(): Data Address is Out of Range", LOG_LOCAL0);

    CHECK_PARAM(i2c_write(QSFP_BUS, QSFP_SLAVE_ADDRESS, data_address, size,
        data, 0) < 0, LOG_ERR, TAG_QSFP, 
        "Error in qsfp_write(): i2c_write()", LOG_LOCAL0);

    return 0;
}

int qsfp_set_page(int page)
{
    unsigned int comm_sts;
     
#ifdef TESTING
    CHECK_PARAM(qsfp_get_communication_status_mock(&comm_sts) < 0, LOG_ERR, TAG_QSFP, 
        "Error in qsfp_set_page(): qsfp_get_communication_status()");
#else
    CHECK_PARAM(qsfp_get_communication_status(&comm_sts) < 0, LOG_ERR, TAG_QSFP, 
        "Error in qsfp_set_page(): qsfp_get_communication_status()", LOG_LOCAL0);
#endif
    
    CHECK_PARAM(comm_sts == QSFP_COMM_DISABLED, LOG_ERR, TAG_QSFP, 
        "Error in qsfp_set_page(): Communication is disabled.", LOG_LOCAL0);

    CHECK_PARAM(page < 0 || page > 3, LOG_ERR, TAG_QSFP, 
        "Error in qsfp_set_page(): Page Out of Range", LOG_LOCAL0);

    CHECK_PARAM(i2c_write(QSFP_BUS, QSFP_SLAVE_ADDRESS, QSFP_PAGE_SELECT_BYTE, I2C_SMBUS_BYTE_DATA,
        &page, 0) < 0, LOG_ERR, TAG_QSFP, 
        "Error in qsfp_set_page(): i2c_write()", LOG_LOCAL0);

    return 0;
}

int qsfp_get_page(int *page)
{
    unsigned int comm_sts;
     
#ifdef TESTING
    CHECK_PARAM(qsfp_get_communication_status_mock(&comm_sts) < 0, LOG_ERR, TAG_QSFP, 
        "Error in qsfp_get_page(): qsfp_get_communication_status()", LOG_LOCAL0);
#else
    CHECK_PARAM(qsfp_get_communication_status(&comm_sts) < 0, LOG_ERR, TAG_QSFP, 
        "Error in qsfp_get_page(): qsfp_get_communication_status()", LOG_LOCAL0);
#endif
    
    CHECK_PARAM(comm_sts == QSFP_COMM_DISABLED, LOG_ERR, TAG_QSFP, 
        "Error in qsfp_get_page(): Communication is disabled.", LOG_LOCAL0);

    CHECK_PARAM(i2c_read(QSFP_BUS, QSFP_SLAVE_ADDRESS, QSFP_PAGE_SELECT_BYTE, I2C_SMBUS_BYTE_DATA,
            page, 0) < 0, LOG_ERR, TAG_QSFP, 
        "Error in qsfp_get_page(): i2c_read()", LOG_LOCAL0);

    return 0;
}

int qsfp_get_id(int *ident)
{
    unsigned int comm_sts;
     
#ifdef TESTING
    CHECK_PARAM(qsfp_get_communication_status_mock(&comm_sts) < 0, LOG_ERR, TAG_QSFP, 
        "Error in qsfp_get_id(): qsfp_get_communication_status()");
#else
    CHECK_PARAM(qsfp_get_communication_status(&comm_sts) < 0, LOG_ERR, TAG_QSFP, 
        "Error in qsfp_get_id(): qsfp_get_communication_status()", LOG_LOCAL0);
#endif
    
    CHECK_PARAM(comm_sts == QSFP_COMM_DISABLED, LOG_ERR, TAG_QSFP, 
        "Error in qsfp_get_id(): Communication is disabled.", LOG_LOCAL0);

    CHECK_PARAM(i2c_read(QSFP_BUS, QSFP_SLAVE_ADDRESS, QSFP_ID, I2C_SMBUS_BYTE_DATA,
            ident, 0) < 0, LOG_ERR, TAG_QSFP, 
        "Error in qsfp_get_id(): i2c_read()", LOG_LOCAL0);

    return 0;
}

int qsfp_get_status(int *status)
{
    unsigned int comm_sts;
     
#ifdef TESTING
    CHECK_PARAM(qsfp_get_communication_status_mock(&comm_sts) < 0, LOG_ERR, TAG_QSFP, 
        "Error in qsfp_get_status(): qsfp_get_communication_status()", LOG_LOCAL0);
#else
    CHECK_PARAM(qsfp_get_communication_status(&comm_sts) < 0, LOG_ERR, TAG_QSFP, 
        "Error in qsfp_get_status(): qsfp_get_communication_status()", LOG_LOCAL0);
#endif
    
    CHECK_PARAM(comm_sts == QSFP_COMM_DISABLED, LOG_ERR, TAG_QSFP, 
        "Error in qsfp_get_status(): Communication is disabled.", LOG_LOCAL0);

    CHECK_PARAM(i2c_read(QSFP_BUS, QSFP_SLAVE_ADDRESS, QSFP_STATUS, I2C_SMBUS_BYTE_DATA,
            status, 0) < 0, LOG_ERR, TAG_QSFP, 
        "Error in qsfp_get_status(): i2c_read()", LOG_LOCAL0);

    return 0;
}

int qsfp_get_int_flags(flg_reg_t freg, int *flags)
{
    unsigned int comm_sts;
     
#ifdef TESTING
    CHECK_PARAM(qsfp_get_communication_status_mock(&comm_sts) < 0, LOG_ERR, TAG_QSFP, 
        "Error in qsfp_get_int_flags(): qsfp_get_communication_status()", LOG_LOCAL0);
#else
    CHECK_PARAM(qsfp_get_communication_status(&comm_sts) < 0, LOG_ERR, TAG_QSFP, 
        "Error in qsfp_get_int_flags(): qsfp_get_communication_status()", LOG_LOCAL0);
#endif
    
    CHECK_PARAM(comm_sts == QSFP_COMM_DISABLED, LOG_ERR, TAG_QSFP, 
        "Error in qsfp_get_int_flags(): Communication is disabled.", LOG_LOCAL0);

    *flags = 0x00;

    switch (freg) {
        case channel_los_3:
        case channel_mon_9:
        case channel_mon_10:
        case channel_mon_11:
        case channel_mon_12:
            CHECK_PARAM(i2c_read(QSFP_BUS, QSFP_SLAVE_ADDRESS, freg, 
                    I2C_SMBUS_BYTE_DATA, flags, 0) < 0, LOG_ERR, TAG_QSFP, 
                "Error in qsfp_get_int_flags(): i2c_read()", LOG_LOCAL0);
            break;            
        case channel_fault_4:
            CHECK_PARAM(i2c_read(QSFP_BUS, QSFP_SLAVE_ADDRESS, freg, 
                    I2C_SMBUS_BYTE_DATA, flags, 0) < 0, LOG_ERR, TAG_QSFP, 
                "Error in qsfp_get_int_flags(): i2c_read()", LOG_LOCAL0);
            *flags &= 0x0F;
            break;
        case channel_sts_5:
        case channel_mon_13:
        case channel_mon_14:
        case channel_mon_15:
        case channel_mon_16:
        case channel_mon_17:
        case channel_mon_18:
            LOG_AND_EXIT(LOG_ERR, TAG_QSFP, 
                "Error in qsfp_get_int_flags(): Register is RSVD.", LOG_LOCAL0);
            break;
        case module_temp_6:
            CHECK_PARAM(i2c_read(QSFP_BUS, QSFP_SLAVE_ADDRESS, freg, 
                    I2C_SMBUS_BYTE_DATA, flags, 0) < 0, LOG_ERR, TAG_QSFP, 
                "Error in qsfp_get_int_flags(): i2c_read()", LOG_LOCAL0);
            *flags &= 0xF1;
            break;
        case module_mon_7:
            CHECK_PARAM(i2c_read(QSFP_BUS, QSFP_SLAVE_ADDRESS, freg, 
                    I2C_SMBUS_BYTE_DATA, flags, 0) < 0, LOG_ERR, TAG_QSFP, 
                "Error in qsfp_get_int_flags(): i2c_read()", LOG_LOCAL0);
            *flags &= 0xF0;
            break;
        case module_mon_8:
        case channel_mon_19:
        case channel_mon_20:
        case channel_mon_21:
            LOG_AND_EXIT(LOG_ERR, TAG_QSFP, 
                "Error in qsfp_get_int_flags(): Register is Vendor Specific.", LOG_LOCAL0);
            break;
        default:
            LOG_AND_EXIT(LOG_ERR, TAG_QSFP, 
                "Error in qsfp_get_int_flags(): Register Address is Out of Range.", LOG_LOCAL0);
            break;
    }

    return 0;
}

int qsfp_get_mod_monitor(mod_mon_t mreg, int *value)
{
    unsigned int comm_sts;
     
#ifdef TESTING
    CHECK_PARAM(qsfp_get_communication_status_mock(&comm_sts) < 0, LOG_ERR, TAG_QSFP, 
        "Error in qsfp_get_mod_monitor(): qsfp_get_communication_status()", LOG_LOCAL0);
#else
    CHECK_PARAM(qsfp_get_communication_status(&comm_sts) < 0, LOG_ERR, TAG_QSFP, 
        "Error in qsfp_get_mod_monitor(): qsfp_get_communication_status()", LOG_LOCAL0);
#endif
    
    CHECK_PARAM(comm_sts == QSFP_COMM_DISABLED, LOG_ERR, TAG_QSFP, 
        "Error in qsfp_get_mod_monitor(): Communication is disabled.", LOG_LOCAL0);

    *value = 0x00;
    
    switch (mreg) {   
        case temp_msb:
        case voltage_msb:
            CHECK_PARAM(i2c_read(QSFP_BUS, QSFP_SLAVE_ADDRESS, mreg, 
                    I2C_SMBUS_WORD_DATA, value, 0) < 0, LOG_ERR, TAG_QSFP, 
                "Error in qsfp_get_mod_monitor(): i2c_read()", LOG_LOCAL0);
            break; 
        case rsvd_24:
        case rsvd_25:
        case rsvd_28:
        case rsvd_29:
            LOG_AND_EXIT(LOG_ERR, TAG_QSFP, 
                "Error in qsfp_get_mod_monitor(): Register is RSVD.", LOG_LOCAL0);
            break;
        case vendor_30:
        case vendor_31:
        case vendor_32:
        case vendor_33:
            LOG_AND_EXIT(LOG_ERR, TAG_QSFP, 
                "Error in qsfp_get_mod_monitor(): Register is Vendor Specific.", LOG_LOCAL0);
            break;
        default:
            LOG_AND_EXIT(LOG_ERR, TAG_QSFP, 
                "Error in qsfp_get_mod_monitor(): Register Address is Out of Range.", LOG_LOCAL0);
            break;
    }

    return 0;
}

int qsfp_get_chnl_monitor(chnl_mon_t creg, int *value)
{
    unsigned int comm_sts;
     
#ifdef TESTING
    CHECK_PARAM(qsfp_get_communication_status_mock(&comm_sts) < 0, LOG_ERR, TAG_QSFP, 
        "Error in qsfp_get_chnl_monitor(): qsfp_get_communication_status()", LOG_LOCAL0);
#else
    CHECK_PARAM(qsfp_get_communication_status(&comm_sts) < 0, LOG_ERR, TAG_QSFP, 
        "Error in qsfp_get_chnl_monitor(): qsfp_get_communication_status()", LOG_LOCAL0);
#endif
    
    CHECK_PARAM(comm_sts == QSFP_COMM_DISABLED, LOG_ERR, TAG_QSFP, 
        "Error in qsfp_get_chnl_monitor(): Communication is disabled.", LOG_LOCAL0);

    *value = 0x00;

    switch (creg) {
        case rx1_pwr_msb:
        case rx2_pwr_msb:
        case rx3_pwr_msb:
        case rx4_pwr_msb:
        case tx1_bias_msb:
        case tx2_bias_msb:
        case tx3_bias_msb:
        case tx4_bias_msb:
            CHECK_PARAM(i2c_read(QSFP_BUS, QSFP_SLAVE_ADDRESS, creg, 
                    I2C_SMBUS_WORD_DATA, value, 0) < 0, LOG_ERR, TAG_QSFP, 
                "Error in qsfp_get_chnl_monitor(): i2c_read()", LOG_LOCAL0);
            break; 
        default:
            if (creg >= 50 && creg <= 65) {
                LOG_AND_EXIT(LOG_ERR, TAG_QSFP, 
                    "Error in qsfp_get_chnl_monitor(): Register is RSVD.", LOG_LOCAL0);
            } else if (creg >= 66 && creg <= 81) {
                LOG_AND_EXIT(LOG_ERR, TAG_QSFP, 
                    "Error in qsfp_get_chnl_monitor(): Register is Vendor Specific.", LOG_LOCAL0);
            } else {
                LOG_AND_EXIT(LOG_ERR, TAG_QSFP, 
                    "Error in qsfp_get_chnl_monitor(): Register Address is Out of Range.", LOG_LOCAL0);
            }
            break;
    }

    return 0;
}

int qsfp_get_control(control_t ctrl, int *value)
{
    unsigned int comm_sts;
     
#ifdef TESTING
    CHECK_PARAM(qsfp_get_communication_status_mock(&comm_sts) < 0, LOG_ERR, TAG_QSFP, 
        "Error in qsfp_get_control(): qsfp_get_communication_status()", LOG_LOCAL0);
#else
    CHECK_PARAM(qsfp_get_communication_status(&comm_sts) < 0, LOG_ERR, TAG_QSFP, 
        "Error in qsfp_get_control(): qsfp_get_communication_status()", LOG_LOCAL0);
#endif
    
    CHECK_PARAM(comm_sts == QSFP_COMM_DISABLED, LOG_ERR, TAG_QSFP, 
        "Error in qsfp_get_control(): Communication is disabled.", LOG_LOCAL0);

    *value = 0x00;

    switch (ctrl) {
        case txn_disable:
        case rxn_rate_select:
        case txn_rate_select:
        case rx4_app_select:
        case rx3_app_select:
        case rx2_app_select:
        case rx1_app_select:
        case tx4_app_select:
        case tx3_app_select:
        case tx2_app_select:
        case tx1_app_select:
            CHECK_PARAM(i2c_read(QSFP_BUS, QSFP_SLAVE_ADDRESS, ctrl, 
                    I2C_SMBUS_WORD_DATA, value, 0) < 0, LOG_ERR, TAG_QSFP, 
                "Error in qsfp_get_control(): i2c_read()", LOG_LOCAL0);
            break;
        case power:
            CHECK_PARAM(i2c_read(QSFP_BUS, QSFP_SLAVE_ADDRESS, ctrl, 
                    I2C_SMBUS_WORD_DATA, value, 0) < 0, LOG_ERR, TAG_QSFP, 
                "Error in qsfp_get_control(): i2c_read()", LOG_LOCAL0);
            *value |= 0x03; 
            break;
        default:
            if (ctrl >= 98 && ctrl <= 99) {
                LOG_AND_EXIT(LOG_ERR, TAG_QSFP, 
                    "Error in qsfp_get_control(): Register is RSVD.", LOG_LOCAL0);
            } else {
                LOG_AND_EXIT(LOG_ERR, TAG_QSFP, 
                    "Error in qsfp_get_control(): Register Address is Out of Range.", LOG_LOCAL0);
            }
            break;
    }

    return 0;
}

int qsfp_set_control(control_t ctrl, int value)
{
    unsigned int comm_sts;
     
#ifdef TESTING
    CHECK_PARAM(qsfp_get_communication_status_mock(&comm_sts) < 0, LOG_ERR, TAG_QSFP, 
        "Error in qsfp_set_control(): qsfp_get_communication_status()", LOG_LOCAL0);
#else
    CHECK_PARAM(qsfp_get_communication_status(&comm_sts) < 0, LOG_ERR, TAG_QSFP, 
        "Error in qsfp_set_control(): qsfp_get_communication_status()", LOG_LOCAL0);
#endif
    
    CHECK_PARAM(comm_sts == QSFP_COMM_DISABLED, LOG_ERR, TAG_QSFP, 
        "Error in qsfp_set_control(): Communication is disabled.", LOG_LOCAL0);

    CHECK_PARAM(value > 0xFF || value < 0, LOG_ERR, TAG_QSFP, 
        "Error in qsfp_set_control(): Register Value out of range", LOG_LOCAL0);

    switch (ctrl) {
        case txn_disable:
        case rxn_rate_select:
        case txn_rate_select:
        case rx4_app_select:
        case rx3_app_select:
        case rx2_app_select:
        case rx1_app_select:
        case tx4_app_select:
        case tx3_app_select:
        case tx2_app_select:
        case tx1_app_select:
            CHECK_PARAM(i2c_write(QSFP_BUS, QSFP_SLAVE_ADDRESS, ctrl, 
                    I2C_SMBUS_BYTE_DATA, &value, 0) < 0, LOG_ERR, TAG_QSFP, 
                "Error in qsfp_set_control(): i2c_write()", LOG_LOCAL0);
            break;
        case power:
            value |= 0x03;
            CHECK_PARAM(i2c_write(QSFP_BUS, QSFP_SLAVE_ADDRESS, ctrl, 
                    I2C_SMBUS_BYTE_DATA, &value, 0) < 0, LOG_ERR, TAG_QSFP, 
                "Error in qsfp_set_control(): i2c_write()", LOG_LOCAL0);
            break;
        default:
            if (ctrl >= 98 && ctrl <= 99) {
                LOG_AND_EXIT(LOG_ERR, TAG_QSFP, 
                    "Error in qsfp_set_control(): Register is RSVD.", LOG_LOCAL0);
            } else {
                LOG_AND_EXIT(LOG_ERR, TAG_QSFP, 
                    "Error in qsfp_set_control(): Register Address is Out of Range.", LOG_LOCAL0);
            }
            break;
    }

    return 0;
}

int qsfp_set_mask(reg_mask_t reg_adrs, int bit_pos, int bit_value)
{
    unsigned int comm_sts;
     
#ifdef TESTING
    CHECK_PARAM(qsfp_get_communication_status_mock(&comm_sts) < 0, LOG_ERR, TAG_QSFP, 
        "Error in qsfp_set_mask(): qsfp_get_communication_status()");
#else
    CHECK_PARAM(qsfp_get_communication_status(&comm_sts) < 0, LOG_ERR, TAG_QSFP, 
        "Error in qsfp_set_mask(): qsfp_get_communication_status()", LOG_LOCAL0);
#endif
    
    CHECK_PARAM(comm_sts == QSFP_COMM_DISABLED, LOG_ERR, TAG_QSFP, 
        "Error in qsfp_set_mask(): Communication is disabled.", LOG_LOCAL0);

    int value;
    int rsvd_mask;

    CHECK_PARAM(bit_pos < 0 || bit_pos > 7, LOG_ERR, TAG_QSFP, 
        "Error in qsfp_set_mask(): Bit Position is Out of Range.", LOG_LOCAL0);

    CHECK_PARAM(bit_value < 0 || bit_value > 1, LOG_ERR, TAG_QSFP, 
        "Error in qsfp_set_mask(): Bit Value Out of Range.", LOG_LOCAL0);

    switch (reg_adrs) {
        case mod_los:
            rsvd_mask = 0xFF;
            break;
        case mod_fault:
            rsvd_mask = 0x0F;
            break;
        case mod_temp:
            rsvd_mask = 0xF1;
            break;
        case mod_alarm:
            rsvd_mask = 0xF0;
            break;
        case rsvd_102:
            LOG_AND_EXIT(LOG_ERR, TAG_QSFP, 
                "Error in qsfp_set_mask(): Register 102 is RSVD.", LOG_LOCAL0);
            break;
        case vendor_105:
        case vendor_106: 
            LOG_AND_EXIT(LOG_ERR, TAG_QSFP, 
                "Error in qsfp_set_mask(): Register 105 and 106 are Vendor Specific.", LOG_LOCAL0);
            break;
        default:
            LOG_AND_EXIT(LOG_ERR, TAG_QSFP, 
                "Error in qsfp_set_mask(): Register Address is Out of Range.", LOG_LOCAL0);
            break;
    } 

    CHECK_PARAM(i2c_read(QSFP_BUS, QSFP_SLAVE_ADDRESS, reg_adrs, 
            I2C_SMBUS_WORD_DATA, &value, 0) < 0, LOG_ERR, TAG_QSFP, 
        "Error in qsfp_set_mask(): i2c_read()", LOG_LOCAL0);

    value |= rsvd_mask;

    CHECK_PARAM(set_bit_val((unsigned int*)&value, bit_pos, bit_value) < 0, LOG_ERR, TAG_QSFP, 
        "Error in qsfp_set_mask(): set_bit_val()", LOG_LOCAL0);

    CHECK_PARAM(i2c_write(QSFP_BUS, QSFP_SLAVE_ADDRESS, reg_adrs, 
            I2C_SMBUS_BYTE_DATA, &value, 0) < 0, LOG_ERR, TAG_QSFP, 
        "Error in qsfp_set_mask(): i2c_write()", LOG_LOCAL0);

    return 0;
}

int qsfp_get_mask(reg_mask_t reg_adrs, int bit_pos, int *bit_value)
{
    unsigned int comm_sts;
     
#ifdef TESTING
    CHECK_PARAM(qsfp_get_communication_status_mock(&comm_sts) < 0, LOG_ERR, TAG_QSFP, 
        "Error in qsfp_get_mask(): qsfp_get_communication_status()", LOG_LOCAL0);
#else
    CHECK_PARAM(qsfp_get_communication_status(&comm_sts) < 0, LOG_ERR, TAG_QSFP, 
        "Error in qsfp_get_mask(): qsfp_get_communication_status()", LOG_LOCAL0);
#endif
    
    CHECK_PARAM(comm_sts == QSFP_COMM_DISABLED, LOG_ERR, TAG_QSFP, 
        "Error in qsfp_get_mask(): Communication is disabled.", LOG_LOCAL0);

    int rsvd_mask, value;
    *bit_value = 0x00;

    CHECK_PARAM(bit_pos < 0 || bit_pos > 7, LOG_ERR, TAG_QSFP, 
        "Error in qsfp_get_mask(): Bit position out of range.", LOG_LOCAL0);

    switch (reg_adrs) {
        case mod_los:
            rsvd_mask = 0xFF;
            break;
        case mod_fault:
            rsvd_mask = 0x0F;
            break;
        case mod_temp:
            rsvd_mask = 0xF1;
            break;
        case mod_alarm:
            rsvd_mask = 0xF0;
            break;
        case rsvd_102:
            LOG_AND_EXIT(LOG_ERR, TAG_QSFP, 
                "Error in qsfp_get_mask(): Register 102 is RSVD.", LOG_LOCAL0);
            break;
        case vendor_105:
        case vendor_106:
            LOG_AND_EXIT(LOG_ERR, TAG_QSFP, 
                "Error in qsfp_get_mask(): Register 105 and 106 are Vendor Specific.", LOG_LOCAL0);
            break;
        default:
            LOG_AND_EXIT(LOG_ERR, TAG_QSFP, 
                "Error in qsfp_get_mask(): Register Address is Out of Range.", LOG_LOCAL0);
            break;
    } 

    CHECK_PARAM(i2c_read(QSFP_BUS, QSFP_SLAVE_ADDRESS, reg_adrs, 
            I2C_SMBUS_WORD_DATA, &value, 0) < 0, LOG_ERR, TAG_QSFP, 
        "Error in qsfp_get_mask(): i2c_read()", LOG_LOCAL0);

    value |= rsvd_mask;

    CHECK_PARAM(get_bit(value, bit_pos, (unsigned int*)bit_value) < 0, LOG_ERR, TAG_QSFP, 
        "Error in qsfp_get_mask(): get_bit()", LOG_LOCAL0);

    return 0;
}

int qsfp_change_passwd(int current_passwd, int new_passwd) 
{
    unsigned int comm_sts;
     
#ifdef TESTING
    CHECK_PARAM(qsfp_get_communication_status_mock(&comm_sts) < 0, LOG_ERR, TAG_QSFP, 
        "Error in qsfp_change_passwd(): qsfp_get_communication_status()", LOG_LOCAL0);
#else
    CHECK_PARAM(qsfp_get_communication_status(&comm_sts) < 0, LOG_ERR, TAG_QSFP, 
        "Error in qsfp_change_passwd(): qsfp_get_communication_status()", LOG_LOCAL0);
#endif
    
    CHECK_PARAM(comm_sts == QSFP_COMM_DISABLED, LOG_ERR, TAG_QSFP, 
        "Error in qsfp_change_passwd(): Communication is disabled.", LOG_LOCAL0);

    CHECK_PARAM(current_passwd > QSFP_HOST_MANUFACTURER_PASSWD_MASK || current_passwd < 0, LOG_ERR, TAG_QSFP, 
        "Error in qsfp_change_passwd(): Register current_passwd Out of Range", LOG_LOCAL0);

    CHECK_PARAM(new_passwd > QSFP_HOST_MANUFACTURER_PASSWD_MASK || new_passwd < 0, LOG_ERR, TAG_QSFP, 
        "Error in qsfp_change_passwd(): Register new_passwd Out of Range", LOG_LOCAL0);

    CHECK_PARAM(i2c_write(QSFP_BUS, QSFP_SLAVE_ADDRESS, QSFP_CURRENT_PASSWD, 
            I2C_SMBUS_BLOCK_DATA, &current_passwd, 4) < 0, LOG_ERR, TAG_QSFP, 
        "Error in qsfp_change_passwd(): i2c_write()", LOG_LOCAL0);

    new_passwd |= QSFP_HOST_MANUFACTURER_PASSWD_MASK;

    CHECK_PARAM(i2c_write(QSFP_BUS, QSFP_SLAVE_ADDRESS, QSFP_NEW_PASSWD, 
            I2C_SMBUS_BLOCK_DATA, &new_passwd, 4) < 0, LOG_ERR, TAG_QSFP, 
        "Error in qsfp_change_passwd(): i2c_write()", LOG_LOCAL0);

    return 0;
}

int qsfp_set_passwd(int current_passwd) 
{
    unsigned int comm_sts;
     
#ifdef TESTING
    CHECK_PARAM(qsfp_get_communication_status_mock(&comm_sts) < 0, LOG_ERR, TAG_QSFP, 
        "Error in qsfp_set_passwd(): qsfp_get_communication_status()", LOG_LOCAL0);
#else
    CHECK_PARAM(qsfp_get_communication_status(&comm_sts) < 0, LOG_ERR, TAG_QSFP, 
        "Error in qsfp_set_passwd(): qsfp_get_communication_status()", LOG_LOCAL0);
#endif
    
    CHECK_PARAM(comm_sts == QSFP_COMM_DISABLED, LOG_ERR, TAG_QSFP, 
        "Error in qsfp_set_passwd(): Communication is disabled.", LOG_LOCAL0);

    CHECK_PARAM(current_passwd > QSFP_HOST_MANUFACTURER_PASSWD_MASK || current_passwd < 0, LOG_ERR, TAG_QSFP, 
        "Error in qsfp_set_passwd(): Register current_passwd Out of Range", LOG_LOCAL0);

    current_passwd |= QSFP_HOST_MANUFACTURER_PASSWD_MASK;

    CHECK_PARAM(i2c_write(QSFP_BUS, QSFP_SLAVE_ADDRESS, QSFP_CURRENT_PASSWD, 
            I2C_SMBUS_BLOCK_DATA, &current_passwd, 4) < 0, LOG_ERR, TAG_QSFP, 
        "Error in qsfp_set_passwd(): i2c_write()", LOG_LOCAL0);

    return 0;
}

int qsfp_get_page0_reg(page0_t reg, int *value) 
{
    unsigned int comm_sts;
     
#ifdef TESTING
    CHECK_PARAM(qsfp_get_communication_status_mock(&comm_sts) < 0, LOG_ERR, TAG_QSFP, 
        "Error in qsfp_get_page0_reg(): qsfp_get_communication_status()", LOG_LOCAL0);
#else
    CHECK_PARAM(qsfp_get_communication_status(&comm_sts) < 0, LOG_ERR, TAG_QSFP, 
        "Error in qsfp_get_page0_reg(): qsfp_get_communication_status()", LOG_LOCAL0);
#endif
    
    CHECK_PARAM(comm_sts == QSFP_COMM_DISABLED, LOG_ERR, TAG_QSFP, 
        "Error in qsfp_get_page0_reg(): Communication is disabled.", LOG_LOCAL0);

    int page;
    int size = 1;
    value = 0x00;

#ifdef TESTING
    CHECK_PARAM(qsfp_get_page_mock(&page) < 0, LOG_ERR, TAG_QSFP, 
        "Error in qsfp_get_page0_reg(): qsfp_get_page()", LOG_LOCAL0);
#else
    CHECK_PARAM(qsfp_get_page(&page) < 0, LOG_ERR, TAG_QSFP, 
        "Error in qsfp_get_page0_reg(): qsfp_get_page()", LOG_LOCAL0);
#endif

    CHECK_PARAM(page != 0, LOG_ERR, TAG_QSFP, 
        "Error in qsfp_get_page0_reg(): page is not 0", LOG_LOCAL0);

    switch(reg) {
        case id:
        case ext_id:
        case connector:
        case ethernet:
        case sonet:
        case sas_sata:
        case gb_ethernet:
        case fibre_chn_link1:
        case fibre_chn_link2:
        case fibre_chn_trans:
        case fibre_chn_speed:
        case encoding:
        case br_nominal:
        case ext_ratesel_comp:
        case length_smf:
        case length_om3:
        case length_om2:
        case length_om1:
        case lenght_copper:
        case device_tech:
        case ext_module:
        case max_case_temp:
        case cc_base:
        case diag_mon_type:
        case enhanced_options:
        case cc_ext:
            size = 1;
            break;
        case rev_level:
        case wavelength:
        case wl_tolerance:
            size = 2;
            break;
        case vendor_oui:
            size = 3;
            break;
        case options:
            size = 4;
            break;
        case date_code:
            size = 8;
            break;
        case vendor_name:
        case part_number:
        case serial_number:
            size = 16;
            break;
        case eeprom:
            size = 32;
            break;
        case rsvd_222:
            LOG_AND_EXIT(LOG_ERR, TAG_QSFP, 
                "Error in qsfp_get_page0_reg(): Register 222 is RSVD.", LOG_LOCAL0);
            break;
        default:
            LOG_AND_EXIT(LOG_ERR, TAG_QSFP, 
                "Error in qsfp_get_page0_reg(): Register Address is Out of Range.", LOG_LOCAL0);
            break;
    }

    CHECK_PARAM(i2c_read(QSFP_BUS, QSFP_SLAVE_ADDRESS, reg, 
            I2C_SMBUS_BLOCK_DATA, value, size) < 0, LOG_ERR, TAG_QSFP, 
        "Error in qsfp_get_page0_reg(): i2c_read()", LOG_LOCAL0);

    return 0;
}

int qsfp_get_thresholds(thresholds_t reg_adrs, int *value) 
{
    unsigned int comm_sts;
     
#ifdef TESTING
    CHECK_PARAM(qsfp_get_communication_status_mock(&comm_sts) < 0, LOG_ERR, TAG_QSFP, 
        "Error in qsfp_get_thresholds(): qsfp_get_communication_status()");
#else
    CHECK_PARAM(qsfp_get_communication_status(&comm_sts) < 0, LOG_ERR, TAG_QSFP, 
        "Error in qsfp_get_thresholds(): qsfp_get_communication_status()", LOG_LOCAL0);
#endif
    
    CHECK_PARAM(comm_sts == QSFP_COMM_DISABLED, LOG_ERR, TAG_QSFP, 
        "Error in qsfp_get_thresholds(): Communication is disabled.", LOG_LOCAL0);

    int page;
    int size = 2;
    value = 0x00;

#ifdef TESTING
    CHECK_PARAM(qsfp_get_page_mock(&page) < 0, LOG_ERR, TAG_QSFP, 
        "Error in qsfp_get_thresholds(): qsfp_get_page()");
#else
    CHECK_PARAM(qsfp_get_page(&page) < 0, LOG_ERR, TAG_QSFP, 
        "Error in qsfp_get_thresholds(): qsfp_get_page()", LOG_LOCAL0);
#endif

    CHECK_PARAM(page != 3, LOG_ERR, TAG_QSFP, 
        "Error in qsfp_get_thresholds(): page is not 3", LOG_LOCAL0);

    switch (reg_adrs) {
        case temp_high_alarm:
        case temp_low_alarm:
        case temp_high_warning:
        case temp_low_warning:
        case vcc_high_alarm:
        case vcc_low_alarm:
        case vcc_high_warning:
        case vcc_low_warning:
        case rx_power_high_alarm:
        case rx_power_low_alarm:
        case rx_power_high_warning:
        case rx_power_low_warning:
        case tx_bias_high_alarm:
        case tx_bias_low_alarm:
        case tx_bias_high_warning:
        case tx_bias_low_warning:
            CHECK_PARAM(i2c_read(QSFP_BUS, QSFP_SLAVE_ADDRESS, reg_adrs, 
                    I2C_SMBUS_BLOCK_DATA, value, size) < 0, LOG_ERR, TAG_QSFP, 
                "Error in qsfp_get_thresholds(): i2c_read()", LOG_LOCAL0);
            break;
        default:
            if ((reg_adrs >= 136 && reg_adrs <= 143)
                    || (reg_adrs >= 152 && reg_adrs <= 159) 
                    || (reg_adrs >= 192 && reg_adrs <= 207)) {

                LOG_AND_EXIT(LOG_ERR, TAG_QSFP, 
                    "Error in qsfp_get_thresholds(): Register is RSVD.", LOG_LOCAL0);

            } else if ((reg_adrs >= 160 && reg_adrs <= 175)
                    || (reg_adrs >= 208 && reg_adrs <= 223)) {

                LOG_AND_EXIT(LOG_ERR, TAG_QSFP, 
                    "Error in qsfp_get_thresholds(): Register is Vendor Specific.", LOG_LOCAL0);
            } else {

                LOG_AND_EXIT(LOG_ERR, TAG_QSFP, 
                    "Error in qsfp_get_thresholds(): Register Address is Out of Range.", LOG_LOCAL0);
            }                  
            break;
    }

    return 0;

}

int qsfp_get_vso_control(vso_control_t reg_adrs, int *value) 
{
    unsigned int comm_sts;
     
#ifdef TESTING
    CHECK_PARAM(qsfp_get_communication_status_mock(&comm_sts) < 0, LOG_ERR, TAG_QSFP, 
        "Error in qsfp_get_vso_control(): qsfp_get_communication_status()");
#else
    CHECK_PARAM(qsfp_get_communication_status(&comm_sts) < 0, LOG_ERR, TAG_QSFP, 
        "Error in qsfp_get_vso_control(): qsfp_get_communication_status()", LOG_LOCAL0);
#endif
    
    CHECK_PARAM(comm_sts == QSFP_COMM_DISABLED, LOG_ERR, TAG_QSFP, 
        "Error in qsfp_get_vso_control(): Communication is disabled.", LOG_LOCAL0);

    int page;
    value = 0x00;

#ifdef TESTING
    CHECK_PARAM(qsfp_get_page_mock(&page) < 0, LOG_ERR, TAG_QSFP, 
        "Error in qsfp_get_vso_control(): qsfp_get_page()", LOG_LOCAL0);
#else
    CHECK_PARAM(qsfp_get_page(&page) < 0, LOG_ERR, TAG_QSFP, 
        "Error in qsfp_get_vso_control(): qsfp_get_page()", LOG_LOCAL0);
#endif

    CHECK_PARAM(page != 3, LOG_ERR, TAG_QSFP, 
        "Error in qsfp_get_vso_control(): page is not 3", LOG_LOCAL0);

    switch (reg_adrs) {
        case rx12_out_amp:
        case rx34_out_amp:
        case rx_tx_sq_disable:
        case rx_out_disable:
            CHECK_PARAM(i2c_read(QSFP_BUS, QSFP_SLAVE_ADDRESS, reg_adrs, 
                    I2C_SMBUS_BYTE_DATA, value, 0) < 0, LOG_ERR, TAG_QSFP, 
                "Error in qsfp_get_vso_control(): i2c_read()", LOG_LOCAL0);
            break;
        default:
            if (reg_adrs >= 226 && reg_adrs <= 237) {
                LOG_AND_EXIT(LOG_ERR, TAG_QSFP, 
                    "Error in qsfp_get_vso_control(): Register is Vendor Specific.", LOG_LOCAL0);
            } else {
                LOG_AND_EXIT(LOG_ERR, TAG_QSFP, 
                    "Error in qsfp_get_vso_control(): Register Address is Out of Range.", LOG_LOCAL0);
            }
            break;
    }

    return 0;
}

int qsfp_set_vso_control(vso_control_t reg_adrs, int value) 
{
    unsigned int comm_sts;
     
#ifdef TESTING
    CHECK_PARAM(qsfp_get_communication_status_mock(&comm_sts) < 0, LOG_ERR, TAG_QSFP, 
        "Error in qsfp_set_vso_control(): qsfp_get_communication_status()", LOG_LOCAL0);
#else
    CHECK_PARAM(qsfp_get_communication_status(&comm_sts) < 0, LOG_ERR, TAG_QSFP, 
        "Error in qsfp_set_vso_control(): qsfp_get_communication_status()", LOG_LOCAL0);
#endif
    
    CHECK_PARAM(comm_sts == QSFP_COMM_DISABLED, LOG_ERR, TAG_QSFP, 
        "Error in qsfp_set_vso_control(): Communication is disabled.", LOG_LOCAL0);

    int page;

    CHECK_PARAM(value > 0xFF || value < 0, LOG_ERR, TAG_QSFP, 
        "Error in qsfp_set_vso_control(): Register Value out of range", LOG_LOCAL0);

#ifdef TESTING
    CHECK_PARAM(qsfp_get_page_mock(&page) < 0, LOG_ERR, TAG_QSFP, 
        "Error in qsfp_set_vso_control(): qsfp_get_page()", LOG_LOCAL0);
#else
    CHECK_PARAM(qsfp_get_page(&page) < 0, LOG_ERR, TAG_QSFP, 
        "Error in qsfp_set_vso_control(): qsfp_get_page()", LOG_LOCAL0);
#endif

    CHECK_PARAM(page != 3, LOG_ERR, TAG_QSFP, 
        "Error in qsfp_set_vso_control(): page is not 3", LOG_LOCAL0);

    switch (reg_adrs) {
        case rx12_out_amp:
        case rx34_out_amp:
        case rx_tx_sq_disable:
        case rx_out_disable:
            CHECK_PARAM(i2c_write(QSFP_BUS, QSFP_SLAVE_ADDRESS, reg_adrs, 
                    I2C_SMBUS_BYTE_DATA, &value, 0) < 0, LOG_ERR, TAG_QSFP, 
                "Error in qsfp_set_vso_control(): i2c_write()", LOG_LOCAL0);
            break;
        default:
            if (reg_adrs >= 226 && reg_adrs <= 237) {
                LOG_AND_EXIT(LOG_ERR, TAG_QSFP, 
                    "Error in qsfp_set_vso_control(): Register is Vendor Specific.", LOG_LOCAL0);
            } else {
                LOG_AND_EXIT(LOG_ERR, TAG_QSFP, 
                    "Error in qsfp_set_vso_control(): Register Address is Out of Range.", LOG_LOCAL0);
            }
            break;
    }

    return 0;
}

int qsfp_set_chnl_mon_mask(chnl_mon_mask_t reg_adrs, int bit_pos, int bit_value)
{
    unsigned int comm_sts;
     
#ifdef TESTING
    CHECK_PARAM(qsfp_get_communication_status_mock(&comm_sts) < 0, LOG_ERR, TAG_QSFP, 
        "Error in qsfp_set_chnl_mon_mask(): qsfp_get_communication_status()", LOG_LOCAL0);
#else
    CHECK_PARAM(qsfp_get_communication_status(&comm_sts) < 0, LOG_ERR, TAG_QSFP, 
        "Error in qsfp_set_chnl_mon_mask(): qsfp_get_communication_status()", LOG_LOCAL0);
#endif
    
    CHECK_PARAM(comm_sts == QSFP_COMM_DISABLED, LOG_ERR, TAG_QSFP, 
        "Error in qsfp_set_chnl_mon_mask(): Communication is disabled.", LOG_LOCAL0);

    int value, page;

    CHECK_PARAM(bit_pos < 0 || bit_pos > 7, LOG_ERR, TAG_QSFP, 
        "Error in qsfp_set_chnl_mon_mask(): Bit Position is Out of Range.", LOG_LOCAL0);

    CHECK_PARAM(bit_value < 0 || bit_value > 1, LOG_ERR, TAG_QSFP, 
        "Error in qsfp_set_chnl_mon_mask(): Bit Value Out of Range.", LOG_LOCAL0);

#ifdef TESTING
    CHECK_PARAM(qsfp_get_page_mock(&page) < 0, LOG_ERR, TAG_QSFP, 
        "Error in qsfp_set_chnl_mon_mask(): qsfp_get_page()", LOG_LOCAL0);
#else
    CHECK_PARAM(qsfp_get_page(&page) < 0, LOG_ERR, TAG_QSFP, 
        "Error in qsfp_set_chnl_mon_mask(): qsfp_get_page()", LOG_LOCAL0);
#endif

    CHECK_PARAM(page != 3, LOG_ERR, TAG_QSFP, 
        "Error in qsfp_set_chnl_mon_mask(): page is not 3", LOG_LOCAL0);

    switch (reg_adrs) {
        case mrx12:
        case mrx34:
        case mtx12:
        case mtx34:
            CHECK_PARAM(i2c_read(QSFP_BUS, QSFP_SLAVE_ADDRESS, reg_adrs, 
                    I2C_SMBUS_WORD_DATA, &value, 0) < 0, LOG_ERR, TAG_QSFP, 
                "Error in qsfp_set_chnl_mon_mask(): i2c_read()", LOG_LOCAL0);
            break;
        default:
            LOG_AND_EXIT(LOG_ERR, TAG_QSFP, 
                "Error in qsfp_set_chnl_mon_mask(): Register Address is Out of Range", LOG_LOCAL0);
            break;
    } 

    CHECK_PARAM(set_bit_val((unsigned int*)&value, bit_pos, bit_value) < 0, LOG_ERR, TAG_QSFP, 
        "Error in qsfp_set_chnl_mon_mask(): set_bit_val()", LOG_LOCAL0);

    CHECK_PARAM(i2c_write(QSFP_BUS, QSFP_SLAVE_ADDRESS, reg_adrs, 
            I2C_SMBUS_BYTE_DATA, &value, 0) < 0, LOG_ERR, TAG_QSFP, 
        "Error in qsfp_set_chnl_mon_mask(): i2c_write()", LOG_LOCAL0);

    return 0;
}

int qsfp_get_chnl_mon_mask(chnl_mon_mask_t reg_adrs, int bit_pos, int *bit_value)
{
    unsigned int comm_sts;
     
#ifdef TESTING
    CHECK_PARAM(qsfp_get_communication_status_mock(&comm_sts) < 0, LOG_ERR, TAG_QSFP, 
        "Error in qsfp_get_chnl_mon_mask(): qsfp_get_communication_status()");
#else
    CHECK_PARAM(qsfp_get_communication_status(&comm_sts) < 0, LOG_ERR, TAG_QSFP, 
        "Error in qsfp_get_chnl_mon_mask(): qsfp_get_communication_status()", LOG_LOCAL0);
#endif
    
    CHECK_PARAM(comm_sts == QSFP_COMM_DISABLED, LOG_ERR, TAG_QSFP, 
        "Error in qsfp_get_chnl_mon_mask(): Communication is disabled.", LOG_LOCAL0);

    int value, page;
    *bit_value = 0x00;

    CHECK_PARAM(bit_pos < 0 || bit_pos > 7, LOG_ERR, TAG_QSFP, 
        "Error in qsfp_get_chnl_mon_mask(): Bit Position is Out of Range.", LOG_LOCAL0);

#ifdef TESTING
    CHECK_PARAM(qsfp_get_page_mock(&page) < 0, LOG_ERR, TAG_QSFP, 
        "Error in qsfp_get_chnl_mon_mask(): qsfp_get_page()");
#else
    CHECK_PARAM(qsfp_get_page(&page) < 0, LOG_ERR, TAG_QSFP, 
        "Error in qsfp_get_chnl_mon_mask(): qsfp_get_page()", LOG_LOCAL0);
#endif

    CHECK_PARAM(page != 3, LOG_ERR, TAG_QSFP, 
        "Error in qsfp_get_chnl_mon_mask(): page is not 3", LOG_LOCAL0);

    switch (reg_adrs) {
        case mrx12:
        case mrx34:
        case mtx12:
        case mtx34:
            CHECK_PARAM(i2c_read(QSFP_BUS, QSFP_SLAVE_ADDRESS, reg_adrs, 
                    I2C_SMBUS_WORD_DATA, &value, 0) < 0, LOG_ERR, TAG_QSFP, 
                "Error in qsfp_get_chnl_mon_mask(): i2c_read()", LOG_LOCAL0);
            break;
        default:
            LOG_AND_EXIT(LOG_ERR, TAG_QSFP, 
                "Error in qsfp_get_chnl_mon_mask(): Register Address is Out of Range", LOG_LOCAL0);
            break;
    } 

    CHECK_PARAM(get_bit(value, bit_pos, (unsigned int*)bit_value) < 0, LOG_ERR, TAG_QSFP, 
        "Error in qsfp_get_chnl_mon_mask(): get_bit()", LOG_LOCAL0);

    return 0;
}

int qsfp_enable_communication(void)
{
    int latch;
    
    CHECK_PARAM(ltc_get_latch_status(&latch) < 0, LOG_ERR, TAG_QSFP, 
        "Error in qsfp_enable_communication(): xfp_get_latch_status()", LOG_LOCAL0);
    
    CHECK_PARAM(latch == LTC_DISABLED, LOG_ERR, TAG_QSFP, 
        "Error in qsfp_enable_communication(): Latch is disabled", LOG_LOCAL0);

    CHECK_PARAM(gpio_write_bit(QSFP_MODSELL, QSFP_COMM_ENABLED) < 0, LOG_ERR, TAG_QSFP, 
        "Error in qsfp_enable_communication(): gpio_write_bit()", LOG_LOCAL0);

    return 0;  
}

int qsfp_disable_communication(void)
{
    int latch;
    
    CHECK_PARAM(ltc_get_latch_status(&latch) < 0, LOG_ERR, TAG_QSFP, 
        "Error in qsfp_disable_communication(): xfp_get_latch_status()", LOG_LOCAL0);
    
    CHECK_PARAM(latch == LTC_DISABLED, LOG_ERR, TAG_QSFP, 
        "Error in qsfp_disable_communication(): Latch is disabled", LOG_LOCAL0);

    CHECK_PARAM(gpio_write_bit(QSFP_MODSELL, QSFP_COMM_DISABLED) < 0, LOG_ERR, TAG_QSFP, 
        "Error in qsfp_disable_communication(): gpio_write_bit()", LOG_LOCAL0);

    return 0;  
}

int qsfp_get_communication_status(unsigned int *status)
{
    int latch;
    
    CHECK_PARAM(ltc_get_latch_status(&latch) < 0, LOG_ERR, TAG_QSFP, 
        "Error in qsfp_get_communication_status(): xfp_get_latch_status()", LOG_LOCAL0);
    
    CHECK_PARAM(latch == LTC_DISABLED, LOG_ERR, TAG_QSFP, 
        "Error in qsfp_get_communication_status(): Latch is disabled", LOG_LOCAL0);

    CHECK_PARAM(gpio_read_bit(QSFP_MODSELL, status) < 0, LOG_ERR, TAG_QSFP, 
        "Error in qsfp_get_communication_status(): gpio_read_bit()", LOG_LOCAL0);

    return 0;
}

int qsfp_get_presence_status(unsigned int *status)
{
    CHECK_PARAM(gpio_read_bit(QSFP_MODPRSL, status) < 0, LOG_ERR, TAG_QSFP, 
        "Error in qsfp_get_presence_status(): gpio_read_bit()", LOG_LOCAL0);
  
    return 0;
}

int qsfp_read_interruption(unsigned int *status)
{
    CHECK_PARAM(gpio_read_bit(QSFP_INTL, status) < 0, LOG_ERR, TAG_QSFP, 
        "Error in qsfp_read_interruption(): gpio_read_bit()", LOG_LOCAL0);
    
    return 0;
}

int qsfp_set_low_power_mode(void)
{
    int latch;
    
    CHECK_PARAM(ltc_get_latch_status(&latch) < 0, LOG_ERR, TAG_QSFP, 
        "Error in qsfp_set_low_power_mode(): xfp_get_latch_status()", LOG_LOCAL0);
    
    CHECK_PARAM(latch == LTC_DISABLED, LOG_ERR, TAG_QSFP, 
        "Error in qsfp_set_low_power_mode(): Latch is disabled", LOG_LOCAL0);

    CHECK_PARAM(gpio_write_bit(QSFP_LPMODE, QSFP_LOW_POWER_MODE) < 0, LOG_ERR, TAG_QSFP, 
        "Error in qsfp_set_low_power_mode(): gpio_write_bit()", LOG_LOCAL0);

    return 0;  
}

int qsfp_set_high_power_mode(void)
{
    int latch;
    
    CHECK_PARAM(ltc_get_latch_status(&latch) < 0, LOG_ERR, TAG_QSFP, 
        "Error in qsfp_set_high_power_mode(): xfp_get_latch_status()", LOG_LOCAL0);
    
    CHECK_PARAM(latch == LTC_DISABLED, LOG_ERR, TAG_QSFP, 
        "Error in qsfp_set_high_power_mode(): Latch is disabled", LOG_LOCAL0);

    CHECK_PARAM(gpio_write_bit(QSFP_LPMODE, QSFP_HIGH_POWER_MODE) < 0, LOG_ERR, TAG_QSFP, 
        "Error in qsfp_set_high_power_mode(): gpio_write_bit()", LOG_LOCAL0);

    return 0;  
}

int qsfp_get_power_mode_status(unsigned int *status)
{
    int latch;
    
    CHECK_PARAM(ltc_get_latch_status(&latch) < 0, LOG_ERR, TAG_QSFP, 
        "Error in qsfp_get_power_mode_status(): xfp_get_latch_status()", LOG_LOCAL0);
    
    CHECK_PARAM(latch == LTC_DISABLED, LOG_ERR, TAG_QSFP, 
        "Error in qsfp_get_power_mode_status(): Latch is disabled", LOG_LOCAL0);

    CHECK_PARAM(gpio_read_bit(QSFP_LPMODE, status) < 0, LOG_ERR, TAG_QSFP, 
        "Error in qsfp_get_power_mode_status(): gpio_read_bit()", LOG_LOCAL0);

    return 0;
}

int qsfp_reset(void)
{
    int latch;
    
    CHECK_PARAM(ltc_get_latch_status(&latch) < 0, LOG_ERR, TAG_QSFP, 
        "Error in qsfp_reset(): xfp_get_latch_status()", LOG_LOCAL0);
    
    CHECK_PARAM(latch == LTC_DISABLED, LOG_ERR, TAG_QSFP, 
        "Error in qsfp_reset(): Latch is disabled", LOG_LOCAL0);

    CHECK_PARAM(gpio_write_bit(QSFP_RESETL, QSFP_RESET_PULSE_DOWN) < 0, LOG_ERR, TAG_QSFP, 
        "Error in qsfp_reset(): gpio_write_bit()", LOG_LOCAL0);

    usleep(QSFP_T_RESET_INIT+1);

    CHECK_PARAM(gpio_write_bit(QSFP_RESETL, QSFP_RESET_PULSE_UP) < 0, LOG_ERR, TAG_QSFP, 
        "Error in qsfp_reset(): gpio_write_bit()", LOG_LOCAL0);

    return 0;  
}

int qsfp_get_vendor_name(void){

    unsigned int comm_sts;
    int i,reg_dir;
    int reg_value;
    char name[16];
    reg_dir = 148;
     
#ifdef TESTING
    CHECK_PARAM(qsfp_get_communication_status_mock(&comm_sts) < 0, LOG_ERR, TAG_QSFP, 
        "Error in qsfp_get_vendor_name(): qsfp_get_communication_status()", LOG_LOCAL0);
#else
    CHECK_PARAM(qsfp_get_communication_status(&comm_sts) < 0, LOG_ERR, TAG_QSFP, 
        "Error in qsfp_get_vendor_name(): qsfp_get_communication_status()", LOG_LOCAL0);
#endif
    
    CHECK_PARAM(comm_sts == QSFP_COMM_DISABLED, LOG_ERR, TAG_QSFP, 
        "Error in qsfp_get_vendor_name(): Communication is disabled.", LOG_LOCAL0);

    for(i=0;i<16;i++) {
        CHECK_PARAM(i2c_read(QSFP_BUS, QSFP_SLAVE_ADDRESS, reg_dir, I2C_SMBUS_BYTE_DATA,
                &reg_value, 0) < 0, LOG_ERR, TAG_QSFP, "Error in qsfp_get_vendor_name(): i2c_read()", LOG_LOCAL0);
        
        if(isalpha((char)reg_value) || isdigit((char)reg_value) || (char)reg_value=='-')
            name[i] = (char)reg_value;
            
        reg_dir++;
    }
    printf("%s",name);
    return 0;
}

int qsfp_get_vendor_oui(void){
    unsigned int comm_sts;
    int reg_value;
    int i,reg_dir;
    int number[3];
    reg_dir = 165;
        
    #ifdef TESTING
    CHECK_PARAM(qsfp_get_communication_status_mock(&comm_sts) < 0, LOG_ERR, TAG_QSFP, 
        "Error in qsfp_get_vendor_pn(): qsfp_get_communication_status()", LOG_LOCAL0);
#else
    CHECK_PARAM(qsfp_get_communication_status(&comm_sts) < 0, LOG_ERR, TAG_QSFP, 
        "Error in qsfp_get_vendor_pn(): qsfp_get_communication_status()", LOG_LOCAL0);
#endif
    
    CHECK_PARAM(comm_sts == QSFP_COMM_DISABLED, LOG_ERR, TAG_QSFP, 
        "Error in qsfp_get_vendor_pn(): Communication is disabled.", LOG_LOCAL0);
            
    for(i=0;i<3;i++) {
    
    CHECK_PARAM(i2c_read(QSFP_BUS, QSFP_SLAVE_ADDRESS, reg_dir, I2C_SMBUS_BYTE_DATA,
                &reg_value, 0) < 0, LOG_ERR, TAG_QSFP, "Error in qsfp_get_vendor_oui(): i2c_read()", LOG_LOCAL0);
    reg_dir++;
    number[i] = reg_value;
       
    }
    
    printf("%x-%x-%x",number[0],number[1],number[2]);
    return 0;
}

int qsfp_get_vendor_pn(void){
    unsigned int comm_sts;
    int i,reg_dir;
    int reg_value;
    char name[16];
    reg_dir = 168;
     
#ifdef TESTING
    CHECK_PARAM(qsfp_get_communication_status_mock(&comm_sts) < 0, LOG_ERR, TAG_QSFP, 
        "Error in qsfp_get_vendor_pn(): qsfp_get_communication_status()", LOG_LOCAL0);
#else
    CHECK_PARAM(qsfp_get_communication_status(&comm_sts) < 0, LOG_ERR, TAG_QSFP, 
        "Error in qsfp_get_vendor_pn(): qsfp_get_communication_status()", LOG_LOCAL0);
#endif
    
    CHECK_PARAM(comm_sts == QSFP_COMM_DISABLED, LOG_ERR, TAG_QSFP, 
        "Error in qsfp_get_vendor_pn(): Communication is disabled.", LOG_LOCAL0);

    for(i=0;i<16;i++) {
        CHECK_PARAM(i2c_read(QSFP_BUS, QSFP_SLAVE_ADDRESS, reg_dir, I2C_SMBUS_BYTE_DATA,
                &reg_value, 0) < 0, LOG_ERR, TAG_QSFP, "Error in qsfp_get_vendor_pn(): i2c_read()", LOG_LOCAL0);
        if(isalpha((char)reg_value) || isdigit((char)reg_value) || (char)reg_value=='-')
            name[i] = (char)reg_value;
        reg_dir++;
    }
    printf("%s",name);
    return 0;
}

int qsfp_get_vendor_rev(void){
    unsigned int comm_sts;
    int i,reg_dir;
    int reg_value;
    char name[2];
    reg_dir = 184;
     
#ifdef TESTING
    CHECK_PARAM(qsfp_get_communication_status_mock(&comm_sts) < 0, LOG_ERR, TAG_QSFP, 
        "Error in qsfp_get_vendor_rev(): qsfp_get_communication_status()", LOG_LOCAL0);
#else
    CHECK_PARAM(qsfp_get_communication_status(&comm_sts) < 0, LOG_ERR, TAG_QSFP, 
        "Error in qsfp_get_vendor_rev(): qsfp_get_communication_status()", LOG_LOCAL0);
#endif
    
    CHECK_PARAM(comm_sts == QSFP_COMM_DISABLED, LOG_ERR, TAG_QSFP, 
        "Error in qsfp_get_vendor_rev(): Communication is disabled.", LOG_LOCAL0);

    for(i=0;i<2;i++) {
        CHECK_PARAM(i2c_read(QSFP_BUS, QSFP_SLAVE_ADDRESS, reg_dir, I2C_SMBUS_BYTE_DATA,
                &reg_value, 0) < 0, LOG_ERR, TAG_QSFP, "Error in qsfp_get_vendor_rev(): i2c_read()", LOG_LOCAL0);
    
        name[i] = (char)reg_value;
        reg_dir++;
    }
    printf("%s",name);
    return 0;
}

int qsfp_get_vendor_sn(void){
    
    unsigned int comm_sts;
    int i,reg_dir;
    int reg_value;
    char name[16];
    reg_dir = 196;
     
#ifdef TESTING
    CHECK_PARAM(qsfp_get_communication_status_mock(&comm_sts) < 0, LOG_ERR, TAG_QSFP, 
        "Error in qsfp_get_vendor_sn(): qsfp_get_communication_status()");
#else
    CHECK_PARAM(qsfp_get_communication_status(&comm_sts) < 0, LOG_ERR, TAG_QSFP, 
        "Error in qsfp_get_vendor_sn(): qsfp_get_communication_status()", LOG_LOCAL0);
#endif
    
    CHECK_PARAM(comm_sts == QSFP_COMM_DISABLED, LOG_ERR, TAG_QSFP, 
        "Error in qsfp_get_vendor_sn(): Communication is disabled.", LOG_LOCAL0);

    for(i=0;i<16;i++) {
        CHECK_PARAM(i2c_read(QSFP_BUS, QSFP_SLAVE_ADDRESS, reg_dir, I2C_SMBUS_BYTE_DATA,
                &reg_value, 0) < 0, LOG_ERR, TAG_QSFP, "Error in qsfp_get_vendor_sn(): i2c_read()", LOG_LOCAL0);
        
        if(isalpha((char)reg_value) || isdigit((char)reg_value) || (char)reg_value=='-')
            name[i] = (char)reg_value;
        reg_dir++;
    }
    printf("%s",name);
    return 0;
}

int qsfp_get_vendor_date_code(void){
    
    unsigned int comm_sts;
    int i,reg_dir;
    int reg_value;
    char name[8];
    reg_dir = 196;
     
#ifdef TESTING
    CHECK_PARAM(qsfp_get_communication_status_mock(&comm_sts) < 0, LOG_ERR, TAG_QSFP, 
        "Error in qsfp_get_date_code(): qsfp_get_communication_status()");
#else
    CHECK_PARAM(qsfp_get_communication_status(&comm_sts) < 0, LOG_ERR, TAG_QSFP, 
        "Error in qsfp_get_date_code(): qsfp_get_communication_status()", LOG_LOCAL0);
#endif
    
    CHECK_PARAM(comm_sts == QSFP_COMM_DISABLED, LOG_ERR, TAG_QSFP, 
        "Error in qsfp_get_date_code(): Communication is disabled.", LOG_LOCAL0);

    for(i=0;i<8;i++) {
        CHECK_PARAM(i2c_read(QSFP_BUS, QSFP_SLAVE_ADDRESS, reg_dir, I2C_SMBUS_BYTE_DATA,
                &reg_value, 0) < 0, LOG_ERR, TAG_QSFP, "Error in qsfp_get_date_code(): i2c_read()", LOG_LOCAL0);
        
        if(isalpha((char)reg_value) || isdigit((char)reg_value) || (char)reg_value=='-')
            name[i] = (char)reg_value;
        reg_dir++;
    }
    printf("%s",name);
    return 0;
}
