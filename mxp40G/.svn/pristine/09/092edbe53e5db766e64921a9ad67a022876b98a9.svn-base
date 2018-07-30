#include "txp_comm.h"
#include <stdio.h>
#include <util.h>
#include <unistd.h>
#include "../../i2c/i2crw.h"

int oclaro_request(unsigned char cmd, unsigned char request_data_length, unsigned char *request_data)
{

	int data_length = 3 + request_data_length;
	unsigned char data[data_length];
	int i;

	data[0] = cmd;
	data[1] = request_data_length;

	for(i = 0; i < request_data_length; i++)
	{
		data[i + 2] = request_data[i];
	}

	data[data_length - 1] = check_byte(data, data_length-1);

	i2c_write_block_data(OCLARO_BUS, OCLARO_ADDRESS, data, data_length);

return 0;
}

int oclaro_reply(unsigned char length, unsigned char *reply_data)
{



return 0;
}

unsigned char check_byte(unsigned char *data, unsigned char length)
{
    int i;
    unsigned char data_chk = 0x00;

    for (i = 2; i <= length+1; i++)
    {
    	data_chk ^= data[i];
    }

    data[data[1]+2] = (OCLARO_ADDRESS ^ data[0] ^ data[1] ^ data_chk ) - 1;

    printf("data[data[1]+2]: %x\n", data[data[1]+2]);

	return 0;
}
