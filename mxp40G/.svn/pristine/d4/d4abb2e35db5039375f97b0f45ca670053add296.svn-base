/**
 * \file
 * \brief BITMAN API header.
 */
#ifndef __BITMAN_H__
#define __BITMAN_H__

/**
 * Maximum Word Size.
 */
#define BITMAN_MAX_WORD_SIZE    32


/**
 * \brief This Function Swaps the position of *word* bits from [0,pos-1] to [pos,size] and viceversa.
 * 
 * \param[in] word Initial data to swap.
 * 
 * \param[in] size Number of bits to be swapped.
 * 
 * \param[in] pos Position of bits rotation
 * 
 * \param[out] res Swap value is written in this variable.
 * 
 * \return This function returns -1 if an error occurs otherwise, it returns 0.
 */
int swap_range(unsigned int word, unsigned int size, unsigned int pos, unsigned int *res);

/**
 * \brief This Function Swaps the position of *word* bits from [0,pos-1] to [pos,size] and  viceversa.
 * 
 * \param[inout] word Swap value is written in this variable.
 * 
 * \param[in] size Number of bits to be swapped.
 * 
 * \param[in] pos Position of bits rotation
 * 
 * \return This function returns -1 if an error occurs otherwise, it returns 0.
 */
 int swap_range_on_place(unsigned int *word, unsigned int size, unsigned int pos);

/**
 * \brief This Function Sets the bit range [pos_lo,pos_hi] of *word* to 1.
 * 
 * \param[inout] word Data source and destination.
 * 
 * \param[in] pos_lo Lowest bit position to set.
 * 
 * \param[in] pos_hi Highest bit position to set.
 * 
 * \return This function returns -1 if an error occurs otherwise, it returns 0.
 */
 int set_range(unsigned int *word, unsigned int pos_lo, unsigned int pos_hi);


/**
 * \brief This Function Sets bit no. *pos* to 1.
 * 
 * \param[inout] word Data source and destination.
 * 
 * \param[in] pos Lowest bit position to set.
 * 
 * \return This function returns -1 if an error occurs otherwise, it returns 0.
 */
int set_bit(unsigned int *word, unsigned int pos);

/**
 * \brief This Function Sets the bit range [pos_lo,pos_hi] of *word* to 0.
 * 
 * \param[inout] pos_lo Lowest bit position to clear.
 * 
 * \param[in] pos_hi Highest bit position to clear.
 * 
 * \return This function returns -1 if an error occurs otherwise, it returns 0.
 */
int clear_range(unsigned int *word, unsigned int pos_lo, unsigned int pos_hi);

/**
 * \brief This Function Sets bit no. *pos* to 0.
 * 
 * \param[inout] word Data source and destination.
 * 
 * \param[in] pos Position of the bit to clear.
 * 
 * \return This function returns -1 if an error occurs otherwise, it returns 0.
 */
int clear_bit(unsigned int *word, unsigned int pos);


/**
 * \brief This function returns the value of the bit at a certain position *pos* of *word*.
 * 
 * \param[inout] word Data source.
 * 
 * \param[in] pos Bit position to read.
 * 
 * \param[in] res The value of the bit.
 * 
 * \return This function returns -1 if an error occurs otherwise, it returns 0.
 */
int get_bit(unsigned int word, unsigned int pos,  unsigned int *res);            


/**
 * \brief This function sets the value of the bit at a certain position *pos* of *word*, to a given value *val*.
 * 
 * \param[inout] word Data source and destination.
 * 
 * \param[in] pos Lowest bit position to set.
 * 
 * \param[in] val The new value of the bit.
 * 
 * \return This function returns -1 if an error occurs otherwise, it returns 0.
 */
int set_bit_val(unsigned int *word, unsigned int pos, unsigned int val);          


#endif
