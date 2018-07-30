#ifndef __gccethrx_H__
#define __gccethrx_H__

#define RELEASE_PLATFORM
#define CS_LITTLE_ENDIAN

#include "tenabo40.h"
#include "../../lib/cs6041/cs6041.h"

typedef struct length_fields {
   unsigned short low : 8;
   unsigned short high : 8;
   unsigned short full : 16;
};

union length_union
{
	unsigned char length;
	struct length_fields fields;
};


#endif
