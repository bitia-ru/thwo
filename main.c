#define _XTAL_FREQ 4000000

#include <xc.h>
#include <pic10f220.h>

void main()
{
    TRIS = 9; // b1001

    while(1)
    {
        GP2 = 0;
        __delay_ms(1000);
        GP2 = 1;
        __delay_ms(1000);
    }
}