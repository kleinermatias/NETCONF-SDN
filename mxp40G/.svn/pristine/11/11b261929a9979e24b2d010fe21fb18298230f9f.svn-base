/**
 * \file
 * \brief GPIO API header.
 *
 *  
 */
#ifndef __GPIO_H__
#define __GPIO_H__


/*-------------------------MMAP--------------------*/
#define MMAP_GPIO   1
/* #define MMAP_DEBUG  1 */
#define FATAL do { fprintf(stderr, "Error at line %d, file %s (%d) [%s]\n", \
  __LINE__, __FILE__, errno, strerror(errno)); exit(1); } while(0)

#define MAP_SIZE 4096UL
#define MAP_MASK (MAP_SIZE - 1)

struct pio_parameters
{
	void *address;
	unsigned int avalon_address;
    int file_descriptor;
    char filename[32];
	unsigned int error_code;
};

/*----------------------------------------------------*/
#define GPIO_ADDRESS_MAX_WIDTH   0xffff
#define GPIO_BUS_MAX_WIDTH   0xffff
#define GPIO_VALUE_MAX_WIDTH   0xffff
#define GPIO_BASE   0
#define GPIO_LIMIT  255
#define GPIO_MAX    255
/*-------------------------MAD T41--------------------*/
#define GPIO_T41_MAX_TIME 2
#define IE_T41_TIME_OUT 10
/*-GPIO-OUT-----------------LED-----------------------*/
#define LED_POWER_2	199
#define LED_POWER_1	197
#define LED_HARDWARE	196
#define LED_SOFTWARE	198
#define LED_FAN_1	195
#define LED_TEMP	194
#define LED_XFP_1_RED	193
#define LED_XFP_1_GREEN	192
#define LED_XFP_2_RED	191
#define LED_XFP_2_GREEN	190
#define LED_XFP_3_RED	189
#define LED_XFP_3_GREEN	188
#define LED_XFP_4_RED	187
#define LED_XFP_4_GREEN	186
#define LED_QSFP_RED	185
#define LED_QSFP_GREEN	184
/*-GPIO-OUT-----------------LTC-----------------------*/
#define LTC_BIT_STATUS	183 //OPTICAL_MODULES_LATCH_ENABLE 183
#define LTC_ENABLE		1
#define LTC_DISABLE		0
/*-GPIO-OUT-----------------EDFA----------------------*/
#define EDFA_PIN_LOSS_INPUT	182
#define EDFA_PIN_RESET		181
#define EDFA_PIN_SHUTDOWN	180
/*-GPIO-OUT-----------------TMP-----------------------*/
#define TMP_OVERT_PIN	179
#define TMP_ALERT_PIN	178
/*-GPIO-OUT---------------- HMD ----------------------*/
#define HMD_CHIP_SELECT	177 //SI7005_CS 177
/*-GPIO-OUT-----------------XFP-----------------------*/
#define XFP0_MOD_DESEL	176
#define XFP0_INTERRUPT	175
#define XFP0_TX_DIS	174
#define XFP0_MOD_NR	173
#define XFP0_RX_LOS	172
#define XFP0_P_DOWN_RST	171
#define XFP1_MOD_DESEL	170
#define XFP1_INTERRUPT	169
#define XFP1_TX_DIS	168
#define XFP1_MOD_NR	167
#define XFP1_RX_LOS	166
#define XFP1_P_DOWN_RST	165
#define XFP2_MOD_DESEL	164
#define XFP2_INTERRUPT	163
#define XFP2_TX_DIS	162
#define XFP2_MOD_NR	161
#define XFP2_RX_LOS	160
#define XFP2_P_DOWN_RST	159
#define XFP3_MOD_DESEL	158
#define XFP3_INTERRUPT	157
#define XFP3_TX_DIS	156
#define XFP3_MOD_NR	155
#define XFP3_RX_LOS	154
#define XFP3_P_DOWN_RST	153
/*-GPIO-OUT----------------MAD T41--------------------*/
#define	O_IE_NIOS_DATA_15	152
#define	O_IE_NIOS_DATA_14	151
#define	O_IE_NIOS_DATA_13	150
#define	O_IE_NIOS_DATA_12	149
#define	O_IE_NIOS_DATA_11	148
#define	O_IE_NIOS_DATA_10	147
#define	O_IE_NIOS_DATA_9	146
#define	O_IE_NIOS_DATA_8	145
#define	O_IE_NIOS_DATA_7	144
#define	O_IE_NIOS_DATA_6	143
#define	O_IE_NIOS_DATA_5 	142
#define	O_IE_NIOS_DATA_4 	141
#define	O_IE_NIOS_DATA_3 	140
#define	O_IE_NIOS_DATA_2 	139
#define	O_IE_NIOS_DATA_1 	138
#define	O_IE_NIOS_DATA_0 	137
#define	O_IE_NIOS_ADDR_16	136
#define	O_IE_NIOS_ADDR_15	135
#define	O_IE_NIOS_ADDR_14	134
#define	O_IE_NIOS_ADDR_13 	133
#define	O_IE_NIOS_ADDR_12	132
#define	O_IE_NIOS_ADDR_11	131
#define	O_IE_NIOS_ADDR_10	130
#define	O_IE_NIOS_ADDR_9	129
#define	O_IE_NIOS_ADDR_8	128
#define	O_IE_NIOS_ADDR_7	127
#define	O_IE_NIOS_ADDR_6	126
#define	O_IE_NIOS_ADDR_5	125
#define	O_IE_NIOS_ADDR_4	124
#define	O_IE_NIOS_ADDR_3	123
#define	O_IE_NIOS_ADDR_2	122
#define	O_IE_NIOS_ADDR_1	121
#define	O_IE_NIOS_ADDR_0	120
/*-GPIO-OUT---------------GPIO------------------------*/
#define CS6041_GPIO_15	119
#define CS6041_GPIO_14	118
#define CS6041_GPIO_13	117
#define CS6041_GPIO_12	116
#define CS6041_GPIO_11	115
#define CS6041_GPIO_10	114
#define CS6041_GPIO_9	113
#define CS6041_GPIO_8	112
#define CS6041_GPIO_7	111
#define CS6041_GPIO_6	110
#define CS6041_GPIO_5	109
#define CS6041_GPIO_4	108
#define CS6041_GPIO_3	107
#define CS6041_GPIO_2	106
#define CS6041_GPIO_1	105
#define CS6041_GPIO_0	104
/*-GPIO-OUT---------------FAN-------------------------*/
#define FAN1_CLEAR	103
#define FAN2_CLEAR	102
#define FAN3_CLEAR	101
#define FAN4_CLEAR	100
#define FAN5_CLEAR	99
#define FAN1_ALERT	98
#define FAN2_ALERT	97
#define FAN3_ALERT	96
#define FAN4_ALERT	95
#define FAN5_ALERT	94
/*-GPIO-OUT---------------POWER-----------------------*/
#define PWR_1_V_EN	93
#define PWR_2_5_V_EN	92
#define PWR_1_8_V_EN	91
/*-GPIO-OUT-----------------40-G-MODULE---------------*/
#define MOD_40G_Tx_LINETIMSEL_LATCH	90
#define MOD_40G_LS_ENABLE_LATCH		89
#define MOD_40G_MOD_RESET_LATCH		88
#define MOD_40G_REG_RESET_LATCH		87
#define MOD_40G_CFG_ALM			86
#define MOD_40G_STAT_INT		85
#define MOD_40G_RxS			84
#define MOD_40G_LOS			83
#define MOD_40G_LATCH_ENABLE		82
/*-GPIO-OUT-------Serial Communication Channel--------*/
#define CC_RDA_0	81
#define CC_RDA_1	80
#define CC_RDA_2	79
#define CC_RDA_3	78
#define CC_RDA_4	77
#define CC_TDA_0	76
#define CC_TDA_1	75
#define CC_TDA_2	74
#define CC_TDA_3	73
#define CC_TDA_4	72
#define CC_RCLKA_0	71
#define CC_RCLKA_1	70
#define CC_RCLKA_2	69
#define CC_RCLKA_3	68
#define CC_RCLKA_4	67
#define CC_TCLKA_0	66
#define CC_TCLKA_1	65
#define CC_TCLKA_2	64
#define CC_TCLKA_3	63
#define CC_TCLKA_4	62
#define CC_RDB_0	61
#define CC_RDB_1	60
#define CC_RDB_2	59
#define CC_RDB_3	58
#define CC_RDB_4	57
#define CC_TDB_0	56
#define CC_TDB_1	55
#define CC_TDB_2	54
#define CC_TDB_3	53
#define CC_TDB_4	52
#define CC_RCLKB_0      214
#define CC_RCLKB_1      213
#define CC_RCLKB_2      212
#define CC_RCLKB_3      211
#define CC_RCLKB_4      210
#define CS6041_RSTN	47
#define CC_TCLKB_0	46
#define CC_TCLKB_1	45
#define CC_TCLKB_2	44
#define CC_TCLKB_3	43
#define CC_TCLKB_4	42
#define CC_RFP_0A	41
#define CC_TFP_0A	40
#define CC_RFP_0B	39
#define CC_TFP_0B	38
/*-GPIO-OUT---------------PRBS------------------------*/
#define CS6041_PRBS_TXB 37
#define CS6041_PRBS_TXA 36
#define CS6041_PRBS_RXB 35
#define CS6041_PRBS_RXA 34
/*-GPIO-OUT-------------------------------------------*/
#define CS6041_FMRCLK	33
#define CS6041_FSIG	32
/*-GPIO-OUT---------------CLK - SI5326----------------*/
#define SI5326_ONE_RESET	31//SI5326_ONE_RESET	31
#define CLK_CK_CS	30//SI5326_ONE_CK_CS	30
#define SI5326_TWO_RESET	29//SI5326_TWO_RESET	29
#define CLK_C2B		28//SI5326_TWO_CK_CS	28
/*-GPIO-OUT------------------CLK----------------------*/
#define CLK_OSC_684MHZ_EN	24
#define CLK_MUX_A_SEL		25
#define CLK_OSC_400MHZ_EN	26
#define CLK_MUX_B_SEL		27
/*-GPIO-OUT-------------------------------------------*/
#define FPGA_USB_RESET 23
/*-GPIO-OUT---SONET Path Overhead Serial Interface----*/
#define SPOH_TFP	22
#define SPOH_TD		21
#define SPOH_TCLK	20
#define SPOH_RFP	19
#define SPOH_RD		18
#define SPOH_RCLK	17
#define SPOH_QFP	16
#define SPOH_QD		15
/*-GPIO-OUT---------------MRA/MRB---------------------*/
#define MRB_EXT_LOS_1	14
#define MRB_EXT_LOS_2	13
#define MRB_EXT_LOS_3	12
#define MRB_EXT_LOS_4	11
#define MRA_EXT_LOS_1	10
#define MRA_EXT_LOS_2	9
#define MRA_EXT_LOS_3	8
#define MRA_EXT_LOS_4	7
/*-GPIO-OUT----------------MAD T41--------------------*/
#define O_IE_NIOS_READ_WRITE 6
/*-GPIO-OUT---------------QSFP------------------------*/
#define QSFP_MODSELL	5//QSFP_MOD_SEL	5
#define QSFP_RESETL	4//QSFP_RESET_LATCH 4
#define QSFP_MODPRSL	3//QSFP_MOD_PRSL 3
#define QSFP_INTL	2
#define QSFP_LPMODE	1//  QSFP_LPMODE_LATCH	1
/*-GPIO-OUT----------------MAD T41--------------------*/
#define O_IE_NIOS_START	0
/*-GPIO-IN-----------------XFP------------------------*/
#define XFP0_MOD_ABS	255
#define XFP1_MOD_ABS	254
#define XFP2_MOD_ABS	253
#define XFP3_MOD_ABS	252
/*-GPIO-IN------------------CLK-----------------------*/
#define CLK_100MHZ	251// RESERVED_IN_34 251
/*-GPIO-IN-------------------RTC----------------------*/
#define RTC_IRQ		250
/*-GPIO-IN---------------POWER------------------------*/
#define PWR_5_V_PGOOD	249
#define PWR_3_3_V_PGOOD	248
#define PWR_2_5_V_PGOOD	247
#define PWR_1_8_V_PGOOD	246
#define PWR_1_V_PGOOD	245
/*-GPIO-IN--------------------------------------------*/
#define FPGA_USB_VCFG		244
#define FPGA_USB_SUSPEND	243
/*-GPIO-IN---------------POWER------------------------*/
#define PWR_1_2_V_PGOOD 242
/*-GPIO-IN----------------MAD T41---------------------*/
#define I_IE_NIOS_DATA_15 241
#define I_IE_NIOS_DATA_14 240
#define I_IE_NIOS_DATA_13 239
#define I_IE_NIOS_DATA_12 238
#define I_IE_NIOS_DATA_11 237
#define I_IE_NIOS_DATA_10 236
#define I_IE_NIOS_DATA_9 235
#define I_IE_NIOS_DATA_8 234
#define I_IE_NIOS_DATA_7 233
#define I_IE_NIOS_DATA_6 232
#define I_IE_NIOS_DATA_5 231
#define I_IE_NIOS_DATA_4 230
#define I_IE_NIOS_DATA_3 229
#define I_IE_NIOS_DATA_2 228
#define I_IE_NIOS_DATA_1 227
#define I_IE_NIOS_DATA_0 226
/*-GPIO-IN----------------MAD T41---------------------*/
#define I_IE_NIOS_STATUS_2 225
#define I_IE_NIOS_STATUS_1 224
#define I_IE_NIOS_STATUS_0 223
/*----------------------------------------------------*/

#define SI5326_ONE_LOL 222
#define SI5326_ONE_C2B 221
#define SI5326_ONE_INT_C1B 220
#define SI5326_TWO_LOL 219
#define SI5326_TWO_C2B 218
#define SI5326_TWO_INT_C1B 217
#define STDBY_48V_ONE 216
#define STDBY_48V_TWO 215

#define JDSU_TX_LINETIMSEL 1
#define JDSU_LS_ENABLE 1
#define JDSU_LOS 1
#define JDSU_RXS 1
#define JDSU_STAT_INT 1
#define JDSU_CFG_ALM 1
#define JDSU_MOD_RESET 1

#define GPIO_OUT_DATA 16
#define GPIO_INPUT_DATA 16
#define GPIO_ADDRESS 17
#define GPIO_STATUS 3

static int fd_upie;

int pio_init(void);
int pio_open(struct pio_parameters *pio_data,unsigned int avalon_address);
int pio_write(struct pio_parameters *pio_data, unsigned int pin, unsigned int value);
int pio_read(struct pio_parameters *pio_data, unsigned int pin, unsigned int *value);
int pio_close(struct pio_parameters *pio_data);



/**
 * \brief gpio_write_bit - This function writes a GPIO bit.
 *
 * \param[in]   port    Port ID.
 *                      Ranges from 0 to 255.
 * \param[in]   value   Value to write into the port.
 *                      Either 0 or 1.         
 * 
 * \return This function returns -1 if an error occurs, 0 otherwise.
 */
int gpio_write_bit(int port, unsigned int value);

/**
 * \brief gpio_read_bit - This function reads a GPIO bit.
 *
 * \param[in]   port    Port ID.
 *                      Ranges from 0 to 255.
 * \param[out]  value   Value read from port.
 *                      Either 0 or 1.
 * 
 * \return This function returns -1 if an error occurs, 0 otherwise.
 */
int gpio_read_bit(unsigned int port, unsigned int *value);

/**
 * \brief gpio_write_bus - This function writes a whole value into several GPIO ports.
 *
 * \param[in]   base    Base of GPIO ID's to write.
 *                      Ranges from 0 to 255.            
 * \param[in]   limit   Maximum offset from **base**. 
 *                      It must not be higher than 63, and 
 *                      <b>base</b>+<b>limit</b> should not be higher than 255.
 * \param[in]   value   The set of bits to be written into the GPIO
 *                      ports. **value**\<i\> will be written into the GPIO
 *                      port with ID **base**\+i.
 *
 * \return This function returns -1 if an error occurs, 0 otherwise.
 */
int gpio_write_bus(unsigned int base, unsigned int limit, unsigned long long value);


/**
 * \brief gpio_read_bus - This function reads a whole value from several GPIO ports.
 *
 * \param[in]   base    Base of GPIO ID's to write.
 *                      Ranges from 0 to 255.            
 * \param[in]   limit   Maximum offset from **base**. 
 *                      It must not be higher than 63, and 
 *                      <b>base</b>+<b>limit</b> should not be higher than 255.
 * \param[out]  value   The set of bits read from the GPIO ports.
 *                      **value**\<i\> corresponds to the current value
 *                      of the GPIO port with ID **base**\+i.
 *
 * \return This function returns -1 if an error occurs, 0 otherwise.
 */
int gpio_read_bus(unsigned int base, unsigned int limit, unsigned long long *value);

/**
 * \brief gpio_init_ports - This function initializes several consecutive GPIO ports with the specified direction.
 *
 * \param[in]   low_limit   Lower GPIO port ID in the range.
 * \param[in]   high_limit  Higher GPIO port ID in the range.
 * \param[in]   direction   Direction of the GPIO ports in the range.
 *                          The direction will be the same for all of the GPIO
 *                          ports. Either "in" or "out".
 *
 * \return This function returns -1 if an error occurs, 0 otherwise.
 */



int gpio_init_ports(unsigned int low_limit, unsigned int high_limit, const char* direction);

/**
 * \brief register_write - Writes data into a CS6041 register.
 * 
 * \param[in]   address	CS6041 register address.
 * \param[in]   data	The data to write into **address**.
 * 
 * \return This function returns -1 if an error occurs, 0 otherwise.
 */
int register_write(unsigned int address, unsigned short data);

/**
 * \brief gpio_t41_parallel_write - Writes data into a CS6041 register in parallel.
 * 
 * \param[in]   address	CS6041 register address.
 * \param[in]   data	The data to write into **address**.
 * 
 * \return This function returns the transaction status.
 */
int gpio_t41_parallel_write(unsigned int address, unsigned short data);

/**
 * \brief register_read - Reads data from a CS6041 register.
 *
 * \param[in]   address	CS6041 register address.
 *
 * \return This function returns the read data.
 */
unsigned short register_read(unsigned int address);

/**
 * \brief gpio_t41_parallel_read - Reads data from a CS6041 register in parallel.
 * 
 * \param[in]   address	CS6041 register address.
 * \param[in]   data	The read data.
 * 
 * \return This function returns the transaction status.
 */
unsigned short gpio_t41_parallel_read(unsigned int address, unsigned short *data);

/**
 *
 * \brief print_status_error - This function prints the status of a transaction.
 *
 */
void print_status_error(unsigned int status);

/**
 * \brief wait_for_ack - Wait for ack from the cs6041 chip.
 *
 * \return This function returns the transaction status.
 */
unsigned int wait_for_ack(void);

/**
 *
 * \brief start_transaction - Sends the start sequence to the cs6041 chip.
 *
 */
void start_transaction(void);

/**
 *
 * \brief reset - Performs a hardware reset of the cs6041 chip.
 *
 */
void reset(void);

/**
 *
 * \brief open_gpio_files - Open the GPIO ports involved in the communication with the cs6041 chip.
 *
 */
void open_gpio_files(void);

/**
 *
 * \brief close_gpio_files - Close the GPIO ports involved in the communication with the cs6041 chip.
 *
 */
void close_gpio_files(void);

/**
 * \brief get_file_descriptor - Gets a file descriptor of a port.
 *
 * \param[in]   port	The GPIO port.
 *
 * \return This function returns the file descriptor of a port.
 */
int get_file_descriptor(int port);

void open_upie(void);

void close_upie(void);

int close_file_descriptor(int port, int fd);


int parallel_write(unsigned long int address, unsigned long int data);

/**
 * \brief parallel_write - Concurrent data write of CS6041 registers.
 *
 * \param[in]   address	CS6041 register address.
 * \param[in]   data	The data to write into **address**.
 *
 * \return This function returns -1 if an error occurs, 0 otherwise.
 */

unsigned long int parallel_read(unsigned long int address);

/**
 * \brief parallel_read - Concurrent data read of CS6041 registers.
 *
 * \param[in]   address	CS6041 register address.
 *
 * \return This function return the read data.
 */

#endif /* _GPIO_H */
