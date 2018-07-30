#include "clk.h"
#include "../i2c/i2crw.h"
#include "../gpio/gpio.h"
#include <unistd.h>
#include "../util/util.h"

int clk_read(int data_address, int size, int *data)
{
    CHECK_PARAM(size != I2C_SMBUS_BYTE_DATA, LOG_ERR, TAG_CLK, 
        "Error in clk_read(): Size out of range", LOG_LOCAL0);

    CHECK_PARAM(data_address < 0 || data_address > 0xff, LOG_ERR, TAG_CLK, 
        "Error in clk_read(): Data address out of range", LOG_LOCAL0);

    CHECK_PARAM(i2c_read(CLK_BUS, CLK_SLAVE_ADDRESS, data_address, size, 
        data, 0) < 0, LOG_ERR, TAG_CLK, 
        "Error in clk_read(): i2c_read()", LOG_LOCAL0);

    return 0;
}

int clk_write(int data_address, int size, int *data)
{
    CHECK_PARAM(size != I2C_SMBUS_BYTE_DATA, LOG_ERR, TAG_CLK, 
        "Error in clk_write(): Size out of range", LOG_LOCAL0);

    CHECK_PARAM(data_address < 0 || data_address > 0xff, LOG_ERR, TAG_CLK, 
        "Error in clk_write(): Data address out of range", LOG_LOCAL0);

    CHECK_PARAM(i2c_write(CLK_BUS, CLK_SLAVE_ADDRESS, data_address, size, 
        data, 0) < 0, LOG_ERR, TAG_CLK, 
        "Error in clk_write(): i2c_write()", LOG_LOCAL0);

    return 0;
}

int clk_set_clock_select_active_clock(unsigned int cl_ac)
{
    CHECK_PARAM(cl_ac != CLK_CKIN1 && cl_ac != CLK_CKIN2, LOG_ERR, TAG_CLK, 
        "Error in clk_set_clock_select_active_clock(): cl_ac out of range", LOG_LOCAL0);

    CHECK_PARAM(gpio_write_bit(CLK_CK_CS, cl_ac) < 0, LOG_ERR, TAG_CLK, 
        "Error in clk_set_clock_select_active_clock(): gpio_write_bit()", LOG_LOCAL0);

    return 0;
}

int clk_get_pll_los_of_lock_indicator(unsigned int *status)
{
    //CHECK_PARAM(gpio_read_bit(CLK_LOL, status) < 0, LOG_ERR, TAG_CLK,
        //"Error in clk_get_pll_los_of_lock_indicator(): gpio_read_bit()");

    return 0;
}

int clk_get_ckin2_invalid_indicator(unsigned int *status)
{
    CHECK_PARAM(gpio_read_bit(CLK_C2B, status) < 0, LOG_ERR, TAG_CLK, 
        "Error in clk_get_ckin2_invalid_indicator(): gpio_read_bit()", LOG_LOCAL0);

    return 0; 
}

int clk_set_osc_400_mhz(unsigned int enable)
{
    CHECK_PARAM(enable != CLK_ENABLED && enable != CLK_ENABLED,
        LOG_ERR, TAG_CLK, "Error in clk_set_osc_400mhz(): enable out of range", LOG_LOCAL0);

    CHECK_PARAM(gpio_write_bit(CLK_OSC_400MHZ_EN, enable) < 0, LOG_ERR, TAG_CLK,
        "Error in clk_set_osc_400mhz(): gpio_write_bit()", LOG_LOCAL0);

    return 0;
}

int clk_set_osc_684_28_mhz(unsigned int enable)
{
    CHECK_PARAM(enable != CLK_DISABLED && enable != CLK_ENABLED,
        LOG_ERR, TAG_CLK, "Error in clk_set_osc_684_28_mhz(): enable out of range", LOG_LOCAL0);

    CHECK_PARAM(gpio_write_bit(CLK_OSC_684MHZ_EN, enable) < 0, LOG_ERR, TAG_CLK,
        "Error in clk_set_osc_684_28_mhz(): gpio_write_bit()", LOG_LOCAL0);

    return 0;
}

int clk_set_mux_b(unsigned int value)
{
    CHECK_PARAM(value != MUX_SELECT_IN0 && value != MUX_SELECT_IN1, LOG_ERR, TAG_CLK, "Error in clk_set_mux_b(): value out of range", LOG_LOCAL0);

    CHECK_PARAM(gpio_write_bit(CLK_MUX_B_SEL, value) < 0, LOG_ERR, TAG_CLK, "Error in clk_set_mux_b(): gpio_write_bit()", LOG_LOCAL0);

    return 0;
}

int clk_set_mux_a(unsigned int value)
{
    CHECK_PARAM(value != MUX_SELECT_IN0 && value != MUX_SELECT_IN1, LOG_ERR, TAG_CLK, "Error in clk_set_mux_a(): value out of range", LOG_LOCAL0);

    CHECK_PARAM(gpio_write_bit(CLK_MUX_A_SEL, value) < 0, LOG_ERR, TAG_CLK, "Error in clk_set_mux_a(): gpio_write_bit()", LOG_LOCAL0);

    return 0;
}

int clk_set_select_multiplexer_input(unsigned int input)
{
    CHECK_PARAM(input != CLK_INPUT_0 && input != CLK_INPUT_1, LOG_ERR, TAG_CLK,
        "Error in clk_set_select_multiplexer_input(): input out of range", LOG_LOCAL0);

    CHECK_PARAM(gpio_write_bit(CLK_MUX_A_SEL, input) < 0, LOG_ERR, TAG_CLK, 
        "Error in clk_set_select_multiplexer_input(): gpio_write_bit()", LOG_LOCAL0);

    return 0;
}

int clk_get_100mhz_diff_p(unsigned int *status)
{
    CHECK_PARAM(gpio_read_bit(CLK_100MHZ, status) < 0, LOG_ERR, TAG_CLK, 
        "Error in clk_get_100mhz_diff_p(): gpio_read_bit()", LOG_LOCAL0);

    return 0; 
}

int clk_get_100mhz_diff_n(unsigned int *status)
{
    CHECK_PARAM(gpio_read_bit(CLK_100MHZ, status) < 0, LOG_ERR, TAG_CLK, 
        "Error in clk_get_100mhz_diff_n(): gpio_read_bit()", LOG_LOCAL0);

    return 0; 
}
