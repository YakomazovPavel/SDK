#include "../../ADuC831.h"

#define MAXBASE 0xFF

void WriteMax(unsigned char __xdata *regnum, unsigned char val)// ������ � ������ �� ������
{
 unsigned char oldDPP=DPP;

 DPP=MAXBASE;
 *regnum=val;
 DPP=oldDPP;
}

unsigned char ReadMax(unsigned char __xdata *regnum)// ������ ������ �� ������
{
 unsigned char oldDPP=DPP;
 unsigned char val=0;

 DPP=MAXBASE;
 val=*regnum;
 DPP=oldDPP;
 return val;
}

void Light(int State)//��������� �����������
{
 WriteMax(0x08007, State);
}

//��������
void Delay(long int count)
{
 long int j;
 for(j=0;j<count;j++);
}

void main(void)
{
 int Pause = 5000;


 Light(255);
 Delay(10000);

 while(1)
 {
 Light(129); Delay(Pause);
 Light(192); Delay(Pause);
 Light(96); Delay(Pause);
 Light(48); Delay(Pause);
 Light(24); Delay(Pause);
 Light(12); Delay(Pause);
 Light(6); Delay(Pause);
 Light(3); Delay(Pause);







  
 };
}