#include "../../ADuC831.h"

#define MAXBASE 0xFF


unsigned char ReadMax(unsigned char __xdata *regnum)// +����� ������ �� ������
{
unsigned char oldDPP=DPP;
unsigned char val=0;

DPP=MAXBASE;
val=*regnum;
DPP=oldDPP;
return val;
}

void WriteMax(unsigned char __xdata *regnum, unsigned char val)// ������ � ������ �� ������
{
unsigned char oldDPP=DPP;

DPP=MAXBASE;
*regnum=val;
DPP=oldDPP;
}

//SIO
void Wsio(unsigned char ch)
{
TI=0;
SBUF=ch;
while(!TI);
}


void Type(char *s)
{
char n=0;
while(*s)
   Wsio(*s++);
}

void SIO_Init()//L���������ap�G ��aG �� ������ ���a��G�
{
T3CON = 0x83; //CD = 3
T3FD = 0x2D;
SCON = 0x52;
ES=0;
}

char GetKey(void)
{
char table[]="147*2580369#ABCD";
unsigned char row,col,rownum=0,colnum=0;
unsigned int i;
//while(srecv())Rsio();
EA=0;
while(1){
    col=0x1<<(colnum&0x3);
    if((col&0x0F)==0x00)col=0x1;
    WriteMax(0x00,~col);
    for(rownum=4; rownum<8; rownum++){
        row=(ReadMax(0x00))&(0x1<<rownum);
        if(row==0){
            for(i=0;i<10000;i++)continue;
            row=(ReadMax(0x00))&(0x1<<rownum);
//            if(row==0)
//                Wsio(table[4*(colnum&0x3) + rownum-4]);
		  return (table[4*(colnum&0x3) + rownum-4]);
            }
        }
    colnum++;
    //if(srecv())  if(Rsio()=='e')break;

    }
//EA=1;
//Type("\r\n");
 return 0;
}

void Light(int State)
{
WriteMax(0x08007, State);
}

void Delay(long int count)
{
 long int j;
 for(j=0;j<count;j++)10.4994/2.333;
}

void main(void)
{
 char ch = 0;
 int j;

Light(153);
Delay(10000);

 SIO_Init();
 
 while(1)
 {
  ch = GetKey();// ��������� ������� �������
  if(ch) Wsio(ch);// ����� ������� �� ���������
  if (ch =='1') Light(1);
  if (ch =='2') Light(3);
  if (ch =='3') Light(7);
  if (ch =='4') Light(15);
  if (ch =='5') Light(31);
  if (ch =='6') Light(63);
  if (ch =='7') Light(127);
  if (ch =='8') Light(255);
  if (ch =='9') Light(191);
  if (ch =='0') Light(175);
  Delay(5000);
 };
}