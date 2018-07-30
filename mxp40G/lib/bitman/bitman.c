#include <stdio.h>
#include "bitman.h"


#include "../util/util.h"


int set_range(unsigned int *word,
              unsigned int pos_lo,
              unsigned int pos_hi)
{
    unsigned int mask = 0;
    unsigned int i;

    CHECK_PARAM(word == NULL, LOG_ERR, TAG_BMAN, 
        "Error in set_range(): word mem area not allocated!", LOG_LOCAL0);
    
    CHECK_PARAM(pos_hi >= BITMAN_MAX_WORD_SIZE, LOG_ERR, TAG_BMAN, 
        "Error in set_range(): bit high position exceeds word size!", LOG_LOCAL0);

    CHECK_PARAM(pos_hi < pos_lo, LOG_ERR, TAG_BMAN, 
        "Error in set_range(): LSB higher than MSB!", LOG_LOCAL0);

    for (i = 0; i < pos_hi; ++i) {
        if ( i < (pos_hi - pos_lo + 1) ) {
            mask  |= 1;
        }
        mask <<= 1;
    }

    *word |= mask;

    return 0;
}


int set_bit(unsigned int *word,
            unsigned int pos)
{
    CHECK_PARAM(pos >= BITMAN_MAX_WORD_SIZE, LOG_ERR, TAG_BMAN, 
        "Error in set_bit(): bit position exceeds word size!", LOG_LOCAL0);

    return set_range(word, pos, pos);
}


int clear_range(unsigned int *word,
                unsigned int pos_lo,
                unsigned int pos_hi)
{
    unsigned int mask = 0;
    unsigned int i;

    CHECK_PARAM(word == NULL, LOG_ERR, TAG_BMAN, 
        "Error in clear_range(): word mem area not allocated!", LOG_LOCAL0);
    
    CHECK_PARAM(pos_hi >= BITMAN_MAX_WORD_SIZE, LOG_ERR, TAG_BMAN, 
        "Error in clear_range(): bit high position exceeds word size!", LOG_LOCAL0);

    CHECK_PARAM(pos_hi < pos_lo, LOG_ERR, TAG_BMAN, 
        "Error in clear_range(): LSB higher than MSB!", LOG_LOCAL0);

    /*
    for (i = BITMAN_MAX_WORD_SIZE-1; i >= 0; --i) {
        mask <<= 1;
        if ( (i > pos_hi) || (i < pos_lo) ) {
            mask  |= 1;
        }
    }
    */

    for (i = 0; i <= BITMAN_MAX_WORD_SIZE-1; ++i) {
        mask <<= 1;
        if ( (BITMAN_MAX_WORD_SIZE-1 - i > pos_hi) 
            || (BITMAN_MAX_WORD_SIZE-1 - i < pos_lo) ) {

            mask  |= 1;
        }
    }

    *word &= mask;

    return 0;
}


int clear_bit(unsigned int *word,
              unsigned int pos)
{
    CHECK_PARAM(pos >= BITMAN_MAX_WORD_SIZE, LOG_ERR, TAG_BMAN, 
        "Error in clear_bit(): bit position exceeds word size!", LOG_LOCAL0);

    return clear_range(word, pos, pos);
}


int swap_range(unsigned int word,
               unsigned int size,
               unsigned int pos,
               unsigned int *res)
{
    unsigned int mask_lsb = 0;
    unsigned int mask_msb = 0;
    unsigned int i;

    CHECK_PARAM(size >= BITMAN_MAX_WORD_SIZE, LOG_ERR, TAG_BMAN, 
        "Error in swap_range(): word size exceeds limits!", LOG_LOCAL0);

    CHECK_PARAM(pos > size - 1, LOG_ERR, TAG_BMAN, 
        "Error in swap_range(): position exceeds word size!", LOG_LOCAL0);

    CHECK_PARAM(res == NULL, LOG_ERR, TAG_BMAN, 
        "Error in swap_range(): mem area for result was not allocated!", LOG_LOCAL0);

    for (i = 0; i < size; ++i) {
        if ((size-pos) > i) {
            mask_msb <<= 1;
            mask_msb  |= 1;
        } else {
            mask_msb <<= 1;
            mask_lsb <<= 1;
            mask_lsb  |= 1;
        }
    }

    *res  = 0;
    *res |= (word & mask_msb) >> pos;
    *res |= (word & mask_lsb) << (size - pos);

    return 0;
}


int swap_range_on_place(unsigned int *word,
                        unsigned int size,
                        unsigned int pos)
{
    unsigned int res;

    CHECK_PARAM(size >= BITMAN_MAX_WORD_SIZE, LOG_ERR, TAG_BMAN, 
        "Error in swap_range_on_place(): word size exceeds limits!", LOG_LOCAL0);

    CHECK_PARAM(pos > size - 1, LOG_ERR, TAG_BMAN, 
        "Error in swap_range_on_place(): position exceeds word size!", LOG_LOCAL0);

    CHECK_PARAM(swap_range(*word, size, pos, &res) < 0, LOG_ERR, TAG_BMAN, 
        "Error in swap_range_on_place(): there was an error in swap_range!", LOG_LOCAL0);

    *word = res;
    return 0;
}


int get_bit(unsigned int word,
            unsigned int pos,
            unsigned int *res)
{
    CHECK_PARAM(pos >= BITMAN_MAX_WORD_SIZE, LOG_ERR, TAG_BMAN, 
        "Error in get_bit(): bit position exceeds word size!", LOG_LOCAL0);

    *res = (word >> pos) & 1;

    return 0;
}


int set_bit_val(unsigned int *word, 
                unsigned int pos, 
                unsigned int val)
{
    CHECK_PARAM(pos >= BITMAN_MAX_WORD_SIZE, LOG_ERR, TAG_BMAN, 
        "Error in set_bit_val(): bit position exceeds word size!", LOG_LOCAL0);

    switch (val) {
    case 0:
        return clear_bit(word, pos);
    case 1:
        return set_bit(word, pos);
    default:
        CHECK_PARAM(val > 1, LOG_ERR, TAG_BMAN, 
            "Error in set_bit_val(): bit value to set is incorrect!", LOG_LOCAL0);
    }

    return 0;
}
