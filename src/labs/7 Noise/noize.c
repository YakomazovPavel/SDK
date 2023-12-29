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

// void light(int State) {
//     WriteMax(0x08007, State);
// }

void noize(int State) {
    WriteMax(0x08004, State);
}

// void Delay(long int count) {
//     long int j;
//     for(j=0;j<count;j++);
// }

void set_begin_param() {
    TMOD = 0x01;
}

void delay_05ms() {
    TH0 = 0xFB; 
    TL0 = 0xE6;
    TF0 = 0;
    TR0 = 0x01;
    while (!TF0) {;}
    TF0 = 0;
    TR0 = 0;
}

void main(void) {
    set_begin_param();
    while(1) {
        noize(0b00011100);
        delay_05ms();
        noize(0b00000000);
        delay_05ms();
    };
} 