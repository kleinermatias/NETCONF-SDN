/**
 * \file
 * \brief I2CRW API header.
 */
#ifndef __I2CRW_H__
#define __I2CRW_H__

/**
 * Maximum Block Length. 
 */
#define I2C_MAX_BLOCK_LEN   32

/**
 * Byte Data Size. 
 */
#define I2C_SMBUS_BYTE		    1

/**
 * Byte Data Size. 
 */
#define I2C_SMBUS_BYTE_DATA	    2 

/**
 * Byte Word Size. 
 */
#define I2C_SMBUS_WORD_DATA	    3

/**
 * Byte Block Size. 
 */
#define I2C_SMBUS_BLOCK_DATA	5

/**
 * \brief This function checks if module supports read operation.
 *
 * \param[in] file File Descriptor.
 * 
 * \param[in] size Data size. Either I2C_SMBUS_BLOCK_DATA, I2C_SMBUS_WORD_DATA, I2C_SMBUS_BYTE_DATA or I2C_SMBUS_BYTE.
 * 
 * \param[in] data_address Register Address.
 * 
 * \param[in] pec
 * 
 * \return This function returns -1 if an error occurs otherwise, it returns 0.
 */
int i2c_read_check_funcs(int file,int size,int data_address, int pec);
/**
 * \brief This function reads a value through i2c protocol in specified I2C Module.
 *
 * \param[in] i2c_bus_name I2C bus name.
 * 
 * \param[in] chip_address Module Address.
 * 
 * \param[in] data_address Register Address.
 * 
 * \param[in] size Data size. Either I2C_SMBUS_BLOCK_DATA, I2C_SMBUS_WORD_DATA, I2C_SMBUS_BYTE_DATA or I2C_SMBUS_BYTE.
 * 
 * \param[in] data Read data is written in this variable.
 * 
 * \param[in] length Length of Data.
 * 
 * \return This function returns -1 if an error occurs otherwise, it returns 0.
 */
int i2c_read(int i2c_bus_name,int chip_address,int data_address,int size,int *data,int length);

/**
 * \brief This function checks if module supports write operation.
 *
 * \param[in] file File Descriptor.
 * 
 * \param[in] size Data size. Either I2C_SMBUS_BLOCK_DATA, I2C_SMBUS_WORD_DATA, I2C_SMBUS_BYTE_DATA or I2C_SMBUS_BYTE.
 * 
 * \param[in] pec
 * 
 * \return This function returns -1 if an error occurs otherwise, it returns 0.
 */
int i2c_write_check_funcs(
    int file, 
    int size, 
    int pec);

int i2c_write_block_data(int i2c_bus_address, int chip_address, unsigned char *data, int length);

int i2c_read_block_data(int i2c_bus_address, int chip_address, unsigned char *data, int length);

/**
 * \brief This function writes a value through i2c protocol in specified I2C Module.
 *
 * \param[in] i2c_bus_name I2C bus name.
 * 
 * \param[in] chip_address Module Address
 * 
 * \param[in] data_address Register Address
 * 
 * \param[in] size Data size. Either I2C_SMBUS_BLOCK_DATA, I2C_SMBUS_WORD_DATA, I2C_SMBUS_BYTE_DATA or I2C_SMBUS_BYTE.
 * 
 * \param[in] data Data to write.
 * 
 * \param[in] length Length of Data.
 * 
 *  \return This function returns -1 if an error occurs otherwise, it returns 0.
 */
int i2c_write(int i2c_bus_name, int chip_address, int data_address, int size, int *data, int length);


#endif /* _I2C_H */
