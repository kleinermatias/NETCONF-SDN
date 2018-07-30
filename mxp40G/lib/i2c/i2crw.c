#include <errno.h>
#include <string.h>
#include <stdlib.h>
#include <linux/i2c-dev.h>
#include <linux/types.h>
#include "../bitman/bitman.h"
#include "../util/util.h"
#include <stdarg.h>
#include "i2crw.h"
#include "i2cbusses.h"

int i2c_read_check_funcs(
    int file, 
    int size, 
    int data_address,
    int pec)
{
    unsigned long funcs;

    CHECK_PARAM(file < 0, LOG_ERR, TAG_I2C,
        "Error in i2c_read_check_funcs(): Wrong input file descriptor!", LOG_LOCAL0);
    
    // Check adapter functionality 
    if (ioctl(file, I2C_FUNCS, &funcs) < 0) {
        LOG_VAR_1(LOG_ERR, TAG_I2C,
            "Error in i2c_read_check_funcs(): over temperature"
            "Could not get the adapter functionality matrix: %s"
            , strerror(errno), LOG_LOCAL0);
        return -1;
    }

    switch (size) {
    case I2C_SMBUS_BYTE:
        if (!(funcs & I2C_FUNC_SMBUS_READ_BYTE)) {
            LOG_VAR_1(LOG_ERR, TAG_I2C, MISSING_FUNC_FMT, "SMBus receive byte", LOG_LOCAL0);
            return -1;
        }
        if (data_address >= 0 && !(funcs & I2C_FUNC_SMBUS_WRITE_BYTE)) {
            LOG_VAR_1(LOG_ERR, TAG_I2C, MISSING_FUNC_FMT, "SMBus send byte", LOG_LOCAL0);
            return -1;
        }
        break;
    case I2C_SMBUS_BYTE_DATA:
        if (!(funcs & I2C_FUNC_SMBUS_READ_BYTE_DATA)) {
            LOG_VAR_1(LOG_ERR, TAG_I2C, MISSING_FUNC_FMT, "SMBus read byte", LOG_LOCAL0);
            return -1;
        }
        break;
    case I2C_SMBUS_WORD_DATA:
        if (!(funcs & I2C_FUNC_SMBUS_READ_WORD_DATA)) {
            LOG_VAR_1(LOG_ERR, TAG_I2C, MISSING_FUNC_FMT, "SMBus read word", LOG_LOCAL0);
            return -1;
        }
        break;
    case I2C_SMBUS_BLOCK_DATA:
        if (!(funcs & I2C_FUNC_SMBUS_READ_BLOCK_DATA)) {
            LOG_VAR_1(LOG_ERR, TAG_I2C, MISSING_FUNC_FMT, "SMBus read block", LOG_LOCAL0);
            return -1;
        }
        break;
    default:
        JUST_LOG(LOG_ERR, TAG_I2C, "Error (i2c::i2c_read_check_funcs): "
                "unknown data size provided!", LOG_LOCAL0);
        return -1;
    }

    if (pec && !(funcs & (I2C_FUNC_SMBUS_PEC | I2C_FUNC_I2C))) {
        JUST_LOG(LOG_ERR, TAG_I2C, "Warning (i2c::i2c_read_check_funcs): "
                "Adapter does not seem to support PEC", LOG_LOCAL0);
        return -1;
    }

    return 0;
}


int i2c_read(int i2c_bus_name, int chip_address, int data_address, int size, int *data, int length)
{
    int res;
    int file;
    char filename[20];
    int pec = 0;
    int force = 0;
    
    LOG_I2C(i2c_bus_name < 0 || i2c_bus_name > 0xff, LOG_ERR, TAG_I2C,  "Error in i2c_read(): I2C bus out of range (0-255)!",i2c_bus_name,chip_address, LOG_LOCAL0);

/*    LOG_I2C(chip_address < 0x03 || chip_address > 0x77, LOG_ERR, TAG_I2C,
        "Error in i2c_read(): Chip address out of range (0x03-0x77)!");*/

    LOG_I2C(data_address < -1 || data_address > 0xff, LOG_ERR, TAG_I2C, "Error in i2c_read(): Data address invalid!",i2c_bus_name,chip_address, LOG_LOCAL0);

    LOG_I2C(data == NULL, LOG_ERR, TAG_I2C, "Error in i2c_read(): Destination buffer not allocated!", i2c_bus_name,chip_address,LOG_LOCAL0);

    LOG_I2C((length > I2C_MAX_BLOCK_LEN) || (length < 1 && size == I2C_SMBUS_BLOCK_DATA), LOG_ERR, TAG_I2C, "Error in i2c_read(): Incorrect I2C block's length!",i2c_bus_name,chip_address, LOG_LOCAL0);

    file = open_i2c_dev(i2c_bus_name, filename, 0);

    if (file < 0)
    {
    	LOG_I2C(1,LOG_ERR, TAG_I2C, "Error in i2c_read(): open_i2c_dev",i2c_bus_name,chip_address, LOG_LOCAL0);
    }

    /*if (i2c_read_check_funcs(file, size, data_address, pec) < 0) 
    {
        JUST_LOG(LOG_ERR, TAG_I2C, "Error in i2c_read(): i2c_read_check_funcs");
    } */

    if (set_slave_addr(file, chip_address, force)<0)
    {
    	LOG_I2C(1,LOG_ERR, TAG_I2C, "Error in i2c_read(): set_slave_addr",i2c_bus_name,chip_address, LOG_LOCAL0);
    	return -1;
    }

    switch (size)
    {
    	case I2C_SMBUS_WORD_DATA:
			#ifdef TESTING
    			res = i2c_smbus_read_word_data_mock(file, data_address);
			#else
    				res = i2c_smbus_read_word_data(file, data_address);
    		#endif
    			break;

    	case I2C_SMBUS_BYTE_DATA:
			#ifdef TESTING
    			res = i2c_smbus_read_byte_data_mock(file, data_address);
			#else
    				res = i2c_smbus_read_byte_data(file, data_address);

			#endif
    			break;

    	case I2C_SMBUS_BLOCK_DATA:
    		if (data_address == -1)
    		{/*
				#ifdef TESTING
            		res = i2c_smbus_read_block_data_no_cmd_mock(file, data);
				#else
            		res = i2c_smbus_read_block_data_no_cmd(file, (__u8*) data);
				#endif*/
    				i2c_smbus_read_i2c_block_data(file, data_address, length, (__u8*) data);
    		}
    		else
    		{
    			#ifdef TESTING
    				res = i2c_smbus_read_block_data_mock(file, data_address, data);
				#else
    					res = i2c_smbus_read_block_data(file, data_address, (__u8*) data);
				#endif
    		}
    			break;
    	default:
    		LOG_I2C(1,LOG_ERR, TAG_I2C, "Error in i2c_read(): unknown data size provided!",i2c_bus_name,chip_address, LOG_LOCAL0);
    		break;
    }

    if (res < 0)
    {
        close(file);
        LOG_I2C(1,LOG_ERR, TAG_I2C, "Error in i2c_read(): Read failed!", i2c_bus_name,chip_address,LOG_LOCAL0);
    }

    if (size == I2C_SMBUS_WORD_DATA)
    {
        LOG_I2C(swap_range_on_place((unsigned int*)&res, 16, 8), LOG_ERR, TAG_I2C, "Error in i2c_read(): Could not swap bytes!",i2c_bus_name,chip_address, LOG_LOCAL0);
    }

    close(file);

    if ( (res >= 0 && res <= 0xffff) && (size == I2C_SMBUS_BYTE_DATA || size == I2C_SMBUS_WORD_DATA) )
    {
        *data = res;
        return 0;
    }

    else if (res >= 0 && size == I2C_SMBUS_BLOCK_DATA)
    {
        return 0;
    }
    else
    {
        return -1;
    }
}


int i2c_write_check_funcs(
    int file, 
    int size, 
    int pec)
{
    unsigned long funcs;

    
    CHECK_PARAM(file < 0, LOG_ERR, TAG_I2C,
        "Error (i2c::i2c_write_check_funcs): Wrong input file descriptor", LOG_LOCAL0);

    // Check adapter functionality
    if (ioctl(file, I2C_FUNCS, &funcs) < 0) {
        LOG_VAR_1(LOG_ERR, TAG_I2C, "Error (i2c::i2c_write_check_funcs): "
                "Could not get the adapter functionality matrix: %s", 
                strerror(errno), LOG_LOCAL0);
        return -1;
    }

    switch (size) {
    case I2C_SMBUS_BYTE:
        if (!(funcs & I2C_FUNC_SMBUS_WRITE_BYTE)) {
            LOG_VAR_1(LOG_ERR, TAG_I2C, MISSING_FUNC_FMT, "SMBus send byte", LOG_LOCAL0);
            return -1;
        }
        break;
    case I2C_SMBUS_BYTE_DATA:
        if (!(funcs & I2C_FUNC_SMBUS_WRITE_BYTE_DATA)) {
            LOG_VAR_1(LOG_ERR, TAG_I2C, MISSING_FUNC_FMT, "SMBus write byte", LOG_LOCAL0);
            return -1;
        }
        break;
    case I2C_SMBUS_WORD_DATA:
        if (!(funcs & I2C_FUNC_SMBUS_WRITE_WORD_DATA)) {
            LOG_VAR_1(LOG_ERR, TAG_I2C, MISSING_FUNC_FMT, "SMBus write word", LOG_LOCAL0);
            return -1;
        }
        break;
    case I2C_SMBUS_BLOCK_DATA:
        if (!(funcs & I2C_FUNC_SMBUS_WRITE_BLOCK_DATA)) {
            LOG_VAR_1(LOG_ERR, TAG_I2C, MISSING_FUNC_FMT, "SMBus write block", LOG_LOCAL0);
            return -1;
        }
        break;
    default:
        JUST_LOG(LOG_ERR, TAG_I2C, "Error (i2c::i2c_write_check_funcs): "
                "unknown data size provided!", LOG_LOCAL0);
        return -1;
    }

    if (pec && !(funcs & (I2C_FUNC_SMBUS_PEC | I2C_FUNC_I2C))) {
        JUST_LOG(LOG_ERR, TAG_I2C, "Warning (i2c::i2c_write_check_funcs): "
                "Adapter does not seem to support PEC.", LOG_LOCAL0);
        return -1;
    }

    return 0;
}

int i2c_write_block_data(int i2c_bus_address, int chip_address, unsigned char *data, int length)
{
	int file;
	char filename[20];
	int force = 0;
	int i = 0;
	int status = 0;

	file = open_i2c_dev(i2c_bus_address, filename, 0);

	if(file < 0 || set_slave_addr(file, chip_address, force))
	{
		 return -1;
	}

	i2c_smbus_write_i2c_block_data(file, data[0], length - 1 , &data[1]);

	close(file); //agregado por nico

	return 0;
}

int i2c_read_block_data(int i2c_bus_address, int chip_address, unsigned char *data, int length)
{
	int file;
	char filename[20];
	int force = 0;
	int i = 0;

	file = open_i2c_dev(i2c_bus_address, filename, 0);

	if(file < 0 || set_slave_addr(file, chip_address, force))
	{
		return -1;
	}

	i2c_smbus_read_i2c_block_data(file, 0, length, data);

	close(file); //agregado por nico

	return 0;
}

int i2c_write(int i2c_bus_name, int chip_address, int data_address, int size, int *data, int length)
{
    int res;
    int file;
    char filename[20];
    int pec = 0;
    int force = 0;
    int i;
    
    
    LOG_I2C(i2c_bus_name < 0 || i2c_bus_name > 0xff, LOG_ERR, TAG_I2C,
        "Error in i2c_write(): I2C bus_name out of range [0-255]!", i2c_bus_name,chip_address,LOG_LOCAL0);

/*    LOG_I2C(chip_address < 0x03 || chip_address > 0x77, LOG_ERR, TAG_I2C,
        "Error in i2c_write(): Chip address out of range [0x03-0x77]!");*/

    LOG_I2C(data_address < 0 || data_address > 0xff, LOG_ERR, TAG_I2C,
        "Error in i2c_write(): Data address invalid!",i2c_bus_name,chip_address, LOG_LOCAL0);

    LOG_I2C((size == I2C_SMBUS_BYTE_DATA && (unsigned int) *data > 0xff) ||
        (size == I2C_SMBUS_WORD_DATA && (unsigned int) *data > 0xffff), LOG_ERR, TAG_I2C, 
        "Error in i2c_write(): Data size invalid!",i2c_bus_name,chip_address, LOG_LOCAL0);

    LOG_I2C((length > I2C_MAX_BLOCK_LEN ||
         (length < 1 && size == I2C_SMBUS_BLOCK_DATA)), LOG_ERR, TAG_I2C, 
        "Error in i2c_write(): Incorrect I2C block's length!", i2c_bus_name,chip_address,LOG_LOCAL0);

    file = open_i2c_dev(i2c_bus_name, filename, 0);

    if (file < 0 ||
#ifdef TESTING
        i2c_write_check_funcs_mock(file, size, pec) || 
#else
        i2c_write_check_funcs(file, size, pec) || 
#endif
        set_slave_addr(file, chip_address, force)) {
        return -1;
    }


    switch (size)
    {
		case I2C_SMBUS_BYTE:

			for(i = 0; i < length; i++)
			{
				i2c_smbus_write_byte(file, (unsigned char)data[i]);
			}
			break;

    	case I2C_SMBUS_BYTE_DATA:

			#ifdef TESTING
					res = i2c_smbus_write_byte_data_mock(file, data_address, (__u8) *data);
			#else
					res = i2c_smbus_write_byte_data(file, data_address, (__u8) *data);
			#endif
					break;
    	case I2C_SMBUS_WORD_DATA:

    		#ifdef TESTING
					res = i2c_smbus_write_word_data_mock(file, data_address, (__u16) *data);
			#else
					res = i2c_smbus_write_word_data(file, data_address, (__u16) *data);
			#endif
					break;

		case I2C_SMBUS_BLOCK_DATA:

			#ifdef TESTING
					res = i2c_smbus_write_block_data_mock(file, data_address, length, (__u8*) data);
			#else
						  // antes usaba esta: i2c_smbus_write_block_data
					res = i2c_smbus_write_i2c_block_data(file, data_address, length, (__u8*) data);
			#endif
					break;
		default:
			LOG_I2C(1,LOG_ERR, TAG_I2C, "Error in i2c_write(): unknown data size provided!",i2c_bus_name,chip_address, LOG_LOCAL0);
			break;
    }

    close(file);

    LOG_I2C(res < 0, LOG_ERR, TAG_I2C, "Error in i2c_write(): I2C write failed!",i2c_bus_name,chip_address, LOG_LOCAL0);

    return 0;
}

