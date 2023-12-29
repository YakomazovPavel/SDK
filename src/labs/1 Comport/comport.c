#include "../../ADuC831.h"

//�������� ������ �������
void Wsio(unsigned char ch)
{
TI=0;
SBUF=ch;
while(!TI);
}

//��������� ������� ����� ��� ����
unsigned char Rsio(void)
{
unsigned char ch;
while(!RI);
ch=SBUF;
RI=0;
return ch;
}


//�������� ������ ��������
void Type(char *s)
{
char n=0;
while(*s)
   Wsio(*s++);
}

//L������������ �������� ����v�
void SIO_Init()
{
T3CON = 0x83; //CD = 3
T3FD = 0x2D;
SCON = 0x52;
ES=0;
}

//�������� ������� ��������v
void main(void)
{
int j;
SIO_Init();//�������������

Wsio('>');//�������� ������ ������� '>'
Wsio('>');
Wsio('>');

Type("This is string of char.");//�������� ������ �� ��������


Type("Press 'e' key.");//�������� ������ �� ��������
if( Rsio() == 'e') Type("You press 'E'.");
else Type ("No");

Type("Press 'q' key.");//�������� ������ �� ��������
if( Rsio() == 'q') Type("You press 'Q'.");
else Type("No No");

while(1)
{
 Wsio(Rsio());
}
 


}