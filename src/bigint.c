
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

/*
uint8_t BigIntMultiply(BigInt_t* n1, BigInt_t* n2, BigInt_t* out)
{
    uint16_t p;
    uint8_t i, i1, i2, c, of, a, b;
    BigInt_t t;
    of = 0;
    BigIntSetToZero(out);
    for (i2 = 0; i2 < BIG_INT_SIZE; i2++)
    {
        c = 0;
        BigIntSetToZero(t);
        for (i1 = 0; i1 < (BIG_INT_SIZE - i2); i1++)
        {
            p = n1->d[i1] * n2->d[i2] + c;
            t.[i2 + i1] = (uint8_t)(p & 0xFF);
            c = (uint8_t)(p >> 8);
        }
        of |= BigIntAdd(out, t);
        /* Check if continuing the multiply to a full double-precision size would generate an overflow *
        if (!of && !n2->d[i2])
            for (; i1 < BIG_INT_SIZE; i1++)
                if (!n1->d[i1])
                {
                    of = 1;
                    break;
                }
    }
    return of;
}*/


void BigIntDivide(BigInt_t* n, BigInt_t* d, BigInt_t* q, BigInt_t* r)
{
    int i;
    BigIntSetToZero(q);
    BigIntSetToZero(r);
    for (i = (BIG_INT_SIZE * 8) - 1; i >= 0; i--)
    {
        BigIntShiftLeft(r);
        BigIntSetBit(r, 0, BigIntGetBit(n, i));
        if (BigIntCompare(r, d) >= 0)
        {
            BigIntSubtract(r, d);
            BigIntSetBit(q, i, 1);
        }
    }
}
