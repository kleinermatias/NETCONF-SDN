#ifdef DEBUG
#undef DEBUG
#endif
#define DEBUG 1

#define I2C_SMBUS_BYTE_DATA     2 
#include "../../lib/clk/clk.h"
#include "../../lib/tmp/tmp.h"
#include "../../lib/hmd/hmd.h"
#include "../../lib/ltc/ltc.h"
#include "../../lib/xfp/xfp.h"
#include "../../lib/qsfp/qsfp.h"
#include "../../lib/txp/txp.h"
#include "../../lib/edfa/edfa.h"
#include "../../lib/led/led.h"
#include <stdio.h>

#define RELEASE_PLATFORM
#define CS_LITTLE_ENDIAN
#include "tenabo40.h"

int check_T41(void);
int check_Clock_System(void);
int check_EDFA(void);
int check_FAN(void);
int check_Humidity(void);
int check_LED(void);
int check_Latch(void);
int check_QSFP(void);
int check_Temperature(void);
int check_Transponder(void);
int check_XFP(void);
int check_XFPN(int bus_address);
int check_XFP0(void);
int check_XFP1(void);
int check_XFP2(void);
int check_XFP3(void);
void run_test(const char *testname, int (*test_fc)(void));

T41_t Chips;
cs_uint16 dev_id;
cs_uint16 module_line;
cs_uint16 module_client;

int main()
{

    run_test("T41", check_T41);
    run_test("Clock System", check_Clock_System);
    run_test("EDFA", check_EDFA);
    run_test("Humidity", check_Humidity);
    run_test("LED", check_LED);
    run_test("Latch", check_Latch);
    run_test("QSFP", check_QSFP);
    run_test("Temperature", check_Temperature);
    run_test("Transponder", check_Transponder);
    run_test("XFP0", check_XFP0);
    run_test("XFP1", check_XFP1);
    run_test("XFP2", check_XFP2);
    run_test("XFP3", check_XFP3);

    return 0;
}

void run_test(const char *testname, int (*test_fc)(void))
{

    printf("[----------] %s\n", testname);
    printf("[ RUN      ] %s\n", testname);

    int fn_call = (*test_fc)();

    if (fn_call == 0) {
        printf("[       OK ] %s\n", testname);
    } else {
        printf("[  FAILED  ] %s\n", testname);    
    }
    printf("[----------] %s\n", testname);
    
}

int check_T41(void){
    //Cargamos el Driver.   
    if (ten_drvr_load() != CS_OK)
    {
        printf("Error al cargar el driver");
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
        printf("CS604x device registration failed; provisioning aborted\n");
        return -1;
    }
    
    // Initialize the device driver 
    if (ten_dev_main_init(dev_id) != CS_OK) 
    {
        printf("CS604x device initialization failed; provisioning aborted\n");
        // la funcion tira un error inesperado
        return -1;
    }
    ten_mpif_get_chip_jtag_id(dev_id);
        
    ten_mpif_scratch_pad2(dev_id, 0xAA55);

    if(ten_mpif_read_scratch_pad2(dev_id) == 0xAA55)
        return 0;
    else
        return -1;
}

int check_Clock_System(void){

    int w_data = 0xFF;
    int r_data = 0;

    clk_write(0x32, I2C_SMBUS_BYTE_DATA, &w_data);

    clk_read(0x32, I2C_SMBUS_BYTE_DATA, &r_data);

#ifdef DEBUG 
    printf("r_data: %d\n", r_data);
#endif

    if (w_data == r_data)
        return 0;
    else 
        return -1;
}

int check_EDFA(void){

    int w_baud = EDFA_BAUD_38400;
    int r_baud = 0;

    edfa_set_baud_rate(w_baud);

    edfa_get_baud_rate(&r_baud);

#ifdef DEBUG 
    printf("r_baud: %d\n", r_baud);
#endif

    if (w_baud == r_baud)
        return 0;
    else
        return -1;
}

int check_Humidity(void){

    int r_heater_status = 0;

    hmd_enable_heater();

    hmd_get_heater_status(&r_heater_status);

#ifdef DEBUG 
    printf("r_heater_status: %d\n", r_heater_status);
#endif

    if (r_heater_status == 1) 
        return 0;
    else 
        return -1;
}

int check_LED(void){

    led_turn_on_all();

    sleep(1);

    led_turn_off_all();

    return 0;
}

int check_Latch(void){

    int r_latch_value = LTC_DISABLED;

    ltc_enable_latch(); 

    ltc_get_latch_status(&r_latch_value);

#ifdef DEBUG 
    printf("r_latch_value: %d\n", r_latch_value);
#endif

    if (r_latch_value == LTC_ENABLED)
        return 0;
    else
        return -1;
}

int check_QSFP(void){

    // need latch enable

    int w_page = 1;
    int r_page = 0;

    qsfp_set_page(w_page);

    qsfp_get_page(&r_page);

#ifdef DEBUG 
    printf("r_page: %d\n", r_page);
#endif

    if (r_page == w_page)
        return 0;
    else
        return -1;
}

int check_Temperature(void){

    int w_reg_value = 0xF0;
    int r_reg_value = 0;
    
    tmp_set_alert_high_limit_reg(TMP_REMOTE_1_ALERT_HIGH_LIMIT_REG, w_reg_value);

    tmp_get_alert_high_limit_reg(TMP_REMOTE_1_ALERT_HIGH_LIMIT_REG, &r_reg_value);

#ifdef DEBUG    
    printf("r_reg_value: %d\n", r_reg_value);
#endif

    if (r_reg_value == w_reg_value)
        return 0;
    else
        return -1;
}

int check_Transponder(void){

    rx_interrupt_alarm_mask_t w_data;

    w_data.rxpowalm = 1;
    w_data.rxlos = 1;
    w_data.rxlockerr = 1;
    w_data.rxs = 1;
    w_data.prbserrdet = 1;

    rx_interrupt_alarm_mask_t r_data;

    txp_set_rx_interrupt_alarm_mask_register(w_data);

    txp_read_rx_interrupt_alarm_mask_register(&r_data);

#ifdef DEBUG
    printf("r_data.rxpowalm: %d\n",r_data.rxpowalm);
    printf("r_data.rxlos: %d\n",r_data.rxlos); 
    printf("r_data.rxlockerr: %d\n",r_data.rxlockerr); 
    printf("r_data.rxs: %d\n",r_data.rxs); 
    printf("r_data.prbserrdet: %d\n",r_data.prbserrdet);
#endif


    if (r_data.rxpowalm == 1 
        && r_data.rxlos == 1 
        && r_data.rxlockerr == 1 
        && r_data.rxs == 1 
        && r_data.prbserrdet == 1)

        return 0;
    else
        return -1;
}

int check_XFP0(void) {
    return check_XFPN(XFP_MOD_0);
}

int check_XFP1(void) {
    return check_XFPN(XFP_MOD_1);
}

int check_XFP2(void) {
    return check_XFPN(XFP_MOD_2);
}

int check_XFP3(void) {
    return check_XFPN(XFP_MOD_3);
}

int check_XFPN(int bus_address) {

    xfp_enable_communication(bus_address);

    int first_read_reg = 0;
    int second_read_reg = 0;
    int exp_reg = 9;

    xfp_read(bus_address, 224, 2, &first_read_reg);
#ifdef DEBUG
    printf("first_read_reg: %X\n", first_read_reg);
#endif

    first_read_reg &= 0xFF;        
    exp_reg = (first_read_reg + 1) & 0xFF;
#ifdef DEBUG
    printf("exp_reg: %X\n", exp_reg);
#endif

    xfp_write(bus_address, 224, 2, &exp_reg);

    xfp_read(bus_address, 224, 2, &second_read_reg);
#ifdef DEBUG
    printf("second_read_reg: %X\n", second_read_reg);
#endif

    xfp_write(bus_address, 224, 2, &first_read_reg);

    if (exp_reg != second_read_reg) 
        return -1;
    else
        return 0;
}