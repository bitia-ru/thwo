#include <pic10f220.h>

// PIC10F220 Configuration Bit Settings

#include <xc.h>

// CONFIG
#pragma config IOSCFS = 4MHZ    // Internal Oscillator Frequency Select bit (8 MHz)
#pragma config MCPU = ON       // Master Clear Pull-up Enable bit (Pull-up disabled)
#pragma config WDTE = OFF        // Watchdog Timer Enable bit (WDT enabled)
#pragma config CP = OFF         // Code protection bit (Code protection off)
#pragma config MCLRE = ON       // GP3/MCLR Pin Function Select bit (GP3/MCLR pin function is MCLR)

void delay(unsigned char n)
{
    while(n--) {
        TMR0 = 70;
        while(TMR0);
    }
}

void main()
{
    unsigned char i;
    unsigned char temp;
    unsigned char fan = 0;

    OSCCAL &= 0xFE;
    OPTION = 0x95;
    TRIS = 0;
    ADCON0 = 0x41;
    TMR0 = 0xFF;

    while(1)
    {
        GPIO ^= 2;
        GO = 1;
        delay(17);
        delay(temp);
        temp = ADRES;

        if(temp < 18 && !fan) {
            fan = 1;
            GPIO |= 4;
        }

        if(temp > 20 && fan) {
            fan = 0;
            GPIO &= ~4;
        }
    }
}