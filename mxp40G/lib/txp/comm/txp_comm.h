/**
 * \file
 * \brief TXP_COMM API header.
 */
#ifndef _TXP_COMM_H
#define _TXP_COMM_H

/**
 * Oclaro module address.
 */
#define OCLARO_ADDRESS 0x40
/**
 * I2C module bus address.
 */
#define OCLARO_BUS 0x07

int oclaro_request(unsigned char cmd, unsigned char request_data_length, unsigned char *request_data);

int oclaro_reply(unsigned char length, unsigned char *reply_data);

unsigned char check_byte(unsigned char *data, unsigned char length);

#endif /* _TXP_COMM_H */
