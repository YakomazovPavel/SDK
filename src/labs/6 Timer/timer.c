#include "../../ADuC831.h"

#define MAXBASE 0xFF

void WriteMax(unsigned char __xdata *regnum, unsigned char val) {
    unsigned char oldDPP = DPP;
    DPP = MAXBASE;
    *regnum = val;
    DPP = oldDPP;
}

// unsigned char ReadMax(unsigned char *regnum) {
//     unsigned char oldDPP = DPP;
//     unsigned char val = 0;
//     DPP = MAXBASE;
//     val = *regnum;
//     DPP = oldDPP;
//     return val;
// }

void light(int State) {
    WriteMax(0x08007, State);
}

// void Delay(long int count) {
//     long int j;
//     for(j=0;j<count;j++);
// }

void set_begin_param() {
    TMOD = 0x01;
}

void delay_20ms() {
    TH0 = 0x57; 
    TL0 = 0x0A;
    TF0 = 0;
    TR0 = 0x01;
    while (!TF0) {;}
    TF0 = 0;
    TR0 = 0;
}

void delay_5_sec() {
    unsigned i;
    for (i=0; i<250; i++) {
        delay_20ms();
    }
}

void main(void) {
    set_begin_param();
    while(1) {
        light(0b00000001);
        delay_5_sec();
        light(0b00000011);
        delay_5_sec();
        light(0b00000111);
        delay_5_sec();
        light(0b00001111);
        delay_5_sec();
        light(0b00011111);
        delay_5_sec();
        light(0b00111111);
        delay_5_sec();
        light(0b01111111);
        delay_5_sec();
        light(0b11111111);
        delay_5_sec();
    };
} 