
#include <stdlib.h>
#include "bigint.h"


char* BigIntToStringHex(BigInt_t* n, char* buffer)
{
    uint8_t i;
    uint8_t* p = &n->d[BIG_INT_SIZE-1];
    for (i = 0; i < BIG_INT_SIZE; i++)
        buffer = BigIntHexify(*p--, buffer);
    *buffer = '\0';
    return buffer;
}

