#include "silabs.h"


int silabs_reset(unsigned int silabs_number)
{
	unsigned int reset_pin[2] = {SI5326_ONE_RESET, SI5326_TWO_RESET};

	CHECK_PARAM((silabs_number < 1 | silabs_number > 2) , LOG_ERR, TAG_SILABS,
        "Error in silabs_reset(): silabs_number out of range", LOG_LOCAL0);

	silabs_number -= 1;

	CHECK_PARAM(gpio_write_bit(reset_pin[silabs_number], CLK_RESET_PULSE_DOWN) < 0, LOG_ERR, TAG_SILABS,
        "Error in silabs_reset(): gpio_write_bit()", LOG_LOCAL0);

    usleep(CLK_T_RESET_INIT+1);

    CHECK_PARAM(gpio_write_bit(reset_pin[silabs_number], CLK_RESET_PULSE_UP) < 0, LOG_ERR, TAG_SILABS,
        "Error in silabs_reset(): gpio_write_bit()", LOG_LOCAL0);

    return 0;
}

int silabs_config(int silabs_number, char *file_name)
{
	FILE *fr;
	char line[100];
	int start = 0;
	int fin = 0;
	char value_hexa[1];
	int write_value = 0;
	int read_value = 0;
	int reg = 0;
	int flag = 0;
	int iterator = 0;

	int address[SILABS_TOTAL] = {SILABS1,SILABS2};
	int bus = 8;
	
	char file [100]= "/opt/bin/";
			
	strcat(file, file_name);

	fr = fopen(file, "r");
	start = 0;
	fin = 0;
	flag = 0;

	if (fr == NULL)
	{
		printf("File Cannot be opened file on server.\n");
		return -1;
	}

	else
	{
		while (fgets(line, 50, fr) != NULL)
		{

			if(strncmp(line,"#REGISTER_MAP",13) == 0)
			{
				start = 1;
			}

			if(strncmp(line,"#END_REGISTER_MAP",17) == 0)
			{
				fin = 1;
			}

			if(start && !fin)
			{
				if(flag>0)
				{
					value_hexa[0] = line[5];
					value_hexa[1] = line[6];

					write_value = (int)strtol(value_hexa, NULL, 16);
					reg = (int)strtol(line, NULL, 10);

					i2c_write(bus, address[silabs_number - 1], reg, I2C_SMBUS_BYTE_DATA, &write_value, 0);

					i2c_read(bus, address[silabs_number - 1], reg, I2C_SMBUS_BYTE_DATA, &read_value, 0);

					if(write_value != read_value && reg != 136)
					{
						printf("register: %d - write value: %d - read value: %d", reg, write_value, read_value);
					}
				}

				else
				{
					flag = 1;
				}
			}
		}
	}
	fclose(fr);

	printf("Silabs configured \n");
	return 0;
}
