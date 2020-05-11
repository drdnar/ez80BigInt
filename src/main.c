#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <tice.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <graphx.h>
#include <fontlibc.h>
#include "bigint.h"


/* 0x12345678901234567890123456789012 */
BigInt_t n1[] = { { 0x12, 0x90, 0x78, 0x56, 0x34, 0x12, 0x90, 0x78, 0x56, 0x34, 0x12, 0x90, 0x78, 0x56, 0x34, 0x12, } };
/* 0x11111111111111111111111111111111 */
BigInt_t n2[] = { { 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, } };
/* 0x123456789ABCDEF0123456789ABCDEF0 */
BigInt_t n3[] = { { 0xF0, 0xDE, 0xBC, 0x9A, 0x78, 0x56, 0x34, 0x12, 0xF0, 0xDE, 0xBC, 0x9A, 0x78, 0x56, 0x34, 0x12, } };
/* 0x1DEADBEEF4C0FFEE */
BigInt_t n4[] = { { 0xEE, 0xFF, 0xC0, 0xF4, 0xEE, 0xDB, 0xEA, 0x1D, 0, 0, 0, 0, 0, 0, 0, 0, } };

/* 0xDEADBEEF */
BigInt_t n5[] = { { 0xEF, 0xBE, 0xAD, 0xDE, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, } };

/* 0x41COFFEE */
BigInt_t n6[] = { { 0xEE, 0xFF, 0xC0, 0x41, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, } };

BigInt_t neg1[] = { { 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, } };

BigInt_t out;
BigInt_t out2;

char buffer[100];

/* Main Function */
void main(void) {
    uint8_t r;
    
    if (!fontlib_SetFont(fontlib_GetFontByStyle("Courier", 13, 13, 0, 255, 0, 0), 0))
    {
        os_ClrHome();
        os_PutStrFull("Failed to load Courier 13 font.");
        while (!os_GetCSC());
        return;
    }
    
    gfx_Begin();
    /* Erase the screen to black */
    gfx_FillScreen(gfx_black);

/*    fontlib_DrawString("n1 = 0x");
    BigIntToStringHex(&n1, buffer);
    fontlib_DrawString(buffer);
    fontlib_Newline();
    fontlib_DrawString("n2 = 0x");
    BigIntToStringHex(&n2, buffer);
    fontlib_DrawString(buffer);
    fontlib_Newline();
    fontlib_DrawString("n3 = 0x");
    BigIntToStringHex(&n3, buffer);
    fontlib_DrawString(buffer);
    fontlib_Newline();
    fontlib_DrawString("n4 = 0x");
    BigIntToStringHex(&n4, buffer);
    fontlib_DrawString(buffer);
    fontlib_Newline();*/
    
    fontlib_DrawString("n1+n2 = ");
    BigIntCopyFromTo(&n1, &out);
    BigIntAdd(&out, &n2);
    BigIntToStringHex(&out, buffer);
    fontlib_DrawString(buffer);
    fontlib_Newline();
    
    fontlib_DrawString("n3+n2 = ");
    BigIntCopyFromTo(&n3, &out);
    BigIntAdd(&out, &n2);
    BigIntToStringHex(&out, buffer);
    fontlib_DrawString(buffer);
    fontlib_Newline();
    
    fontlib_DrawString("n1-n2 = ");
    BigIntCopyFromTo(&n1, &out);
    BigIntSubtract(&out, &n2);
    BigIntToStringHex(&out, buffer);
    fontlib_DrawString(buffer);
    fontlib_Newline();
    
    fontlib_DrawString("n3-n2 = ");
    BigIntCopyFromTo(&n3, &out);
    BigIntSubtract(&out, &n2);
    BigIntToStringHex(&out, buffer);
    fontlib_DrawString(buffer);
    fontlib_Newline();
    
    fontlib_DrawString("prod = ");
    BigIntMultiply(&n5, &n6, &out);
    BigIntToStringHex(&out, buffer);
    fontlib_DrawString(buffer);
    fontlib_Newline();
/*    fontlib_DrawString("expect:00000000000000003931FE67F8F79332");
    fontlib_Newline();*/

    fontlib_DrawString("-n3 = ");
    BigIntCopyFromTo(&n3, &out);
    BigIntNegate(&out);
    BigIntToStringHex(&out, buffer);
    fontlib_DrawString(buffer);
    fontlib_Newline();
    
    fontlib_DrawString("IsZero(n4): ");
    fontlib_DrawInt(BigIntIsZero(n4), 1);
    fontlib_DrawString("  IsNonZero(n4): ");
    fontlib_DrawInt(BigIntIsNonZero(n4), 1);
    fontlib_Newline();
    
    fontlib_DrawString("IsZero(0): ");
    fontlib_DrawInt(BigIntIsZero(&BigIntZero), 1);
    fontlib_DrawString("  IsNonZero(0): ");
    fontlib_DrawInt(BigIntIsNonZero(&BigIntZero), 1);
    fontlib_Newline();
    
    fontlib_DrawString("sign(n1): ");
    fontlib_DrawInt(BigIntGetSign(n1), 1);
    fontlib_DrawString("  sign(0): ");
    fontlib_DrawInt(BigIntGetSign(&BigIntZero), 1);
    fontlib_DrawString("  sign(-1): ");
    fontlib_DrawInt(BigIntGetSign(&neg1), 1);
    fontlib_Newline();
    
    fontlib_DrawString("compare(n1,n2): ");
    fontlib_DrawInt(BigIntCompare(n1, n2), 1);
    fontlib_DrawString(" (n2,n1): ");
    fontlib_DrawInt(BigIntCompare(n2, n1), 1);
    fontlib_DrawString(" (n1,n1): ");
    fontlib_DrawInt(BigIntCompare(n1, n1), 1);
    fontlib_Newline();
    
    fontlib_DrawString("n1>>1 = ");
    BigIntCopyFromTo(&n1, &out);
    BigIntShiftRight(&out);
    BigIntToStringHex(&out, buffer);
    fontlib_DrawString(buffer);
    fontlib_Newline();
    
    fontlib_DrawString("n1<<1 = ");
    BigIntCopyFromTo(&n1, &out);
    BigIntShiftLeft(&out);
    BigIntToStringHex(&out, buffer);
    fontlib_DrawString(buffer);
    fontlib_Newline();
    
    fontlib_DrawString("get(n1,11): ");
    fontlib_DrawInt(BigIntGetBit(&n1, 11), 1);
    fontlib_DrawString("  get(n1,12): ");
    fontlib_DrawInt(BigIntGetBit(&n1, 12), 1);
    fontlib_Newline();
    
    fontlib_DrawString("s n1,11:");
    BigIntCopyFromTo(&n1, &out);
    BigIntSetBit(&out, 11, 1);
    BigIntToStringHex(&out, buffer);
    fontlib_DrawString(buffer);
    fontlib_Newline();
    
    fontlib_DrawString("r n1,21:");
    BigIntCopyFromTo(&n1, &out);
    BigIntSetBit(&out, 21, 0);
    BigIntToStringHex(&out, buffer);
    fontlib_DrawString(buffer);
    fontlib_Newline();
    
    /* Expect 0x9BC5FD16010E833C */
    fontlib_DrawString("n3/n4 = ");
    BigIntDivide(&n3, &n4, &out, &out2);
    BigIntToStringHex(&out, buffer);
    fontlib_DrawString(buffer);
    fontlib_Newline();
    
    /* Expect 0x18ED2B368D861928 */
    fontlib_DrawString("n3%n4 = ");
    BigIntToStringHex(&out2, buffer);
    fontlib_DrawString(buffer);
    fontlib_Newline();
    
    fontlib_DrawString("n6dec = ");
    BigIntToString(&n6, buffer);
    fontlib_DrawString(buffer);
    fontlib_Newline();
    
    
    /* Pause */
    while (!os_GetCSC());

    /* Finish the graphics */
    gfx_End();
}
