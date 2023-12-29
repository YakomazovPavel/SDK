#include <string.h>
//#include <math.h>
#include "../../ADuC831.h"
//              LCD DEFINE SYMBOLS
//--COMMAND CONSTANTS
#define CLEAR		0x01	//requires delay cylce of min 57 NOPs
#define HOME		0x02
#define ENTRY_MODE	0x04
#define DISPLAY_CTRL	0x08
#define SHIFT		0x10
#define FUNCTION_SET	0x20
#define RAM_CG		0x40
#define RAM_DD		0x80
#define BF_AC		0x80	//Read Busy flag (DB7) and AC (DB6-0)
//--COMMAND OPTIONS
#define INCR		0x02
#define DISPLAY_SHIFT	0x01
#define DISPLAY_ON	0x04
#define CURSOR_ON	0x02
#define BLINK		0x01
#define DISPLAY		0x08
#define RIGHT		0x04
#define EIGHT_BITS	0x10
#define TWO_LINE	0x08



void LCD_GotoXY(int x, __bit y);

#define MAXBASE 0xFF

void WriteMax(unsigned char __xdata *regnum, unsigned char val)
{
 unsigned char oldDPP=DPP;

 DPP=MAXBASE;
 *regnum=val;
 DPP=oldDPP;
}

static __bit CurPosCtrl=1;

void SwitchCurPosControl(__bit o)//Switches on/off the current
//position control when symbols are put through LCD_Putch()
{
 CurPosCtrl=o;
}

void Strobe(char c)
{
 unsigned int i;
 WriteMax(0x6,c|0x1);
 WriteMax(0x6,c&0xFE);
 for (i=0;i<300;i++)continue;
}

void LCD_SwitchCursor(__bit cursor, __bit blink)
{
unsigned char i=0;
WriteMax(0x1,DISPLAY_CTRL|DISPLAY_ON|((cursor)?CURSOR_ON:0)|((blink)?BLINK:0));
Strobe(0x8);
for(; i<200; i++)continue;
}

void LCD_Clear(void)
{
        int i;
        WriteMax(0x1,CLEAR);
        Strobe(0x8); //clear
  for(i=0; i<1600; i++)continue;
}

void LCD_InitDefault(void)
{
  unsigned int i;
  char c=0,cmd=0;
  for(i=0; i<40000; i++)continue;
  cmd = 0x30;  //
  WriteMax(0x1,cmd);
  Strobe(c);
  for(i=0; i<10000; i++)continue;
  cmd = 0x30;  //
  WriteMax(0x1,cmd);
  Strobe(c);
  for(i=0; i<1000; i++)continue;
  cmd = 0x30;  //
  WriteMax(0x1,cmd);
  Strobe(c);
  for(i=0; i<100; i++)continue;
  cmd = 0x38;  //
  WriteMax(0x1,cmd);
  Strobe(c);
  cmd = 0x08;  //
  WriteMax(0x1,cmd);
  Strobe(c);
  cmd = 0x01;  //
  WriteMax(0x1,cmd);
  Strobe(c);
  for(i=0; i<1600; i++)continue;
  cmd = ENTRY_MODE|INCR;  //
  WriteMax(0x1,cmd);
  Strobe(c);
  cmd = 0x0F;  //Display ON
  WriteMax(0x1,cmd);
  Strobe(c);
  WriteMax(0x6,0x8); //Switching off the VLO - for 64MAX only
}

void LCD_Putch(char ch)
{
 static char curpos=0;//0-15
 static __bit y=0;
 char c=0x0C;

 //LCD_GotoXY(curpos,y);
 if(curpos>15)curpos=0,y=~y;

 WriteMax(0x1,ch);
 Strobe(c);

 if(CurPosCtrl) curpos++;
}

void LCD_GotoXY(int x, __bit y)
{
 char ch=0x8;
 WriteMax(0x1,RAM_DD|(x+((y)?0x40:0)));
 Strobe(ch); //set ram
}

void LCD_Type(char* s)
{
 __bit OldCurPos = CurPosCtrl;
 CurPosCtrl = 1;
 while(*s) LCD_Putch(*s++);
 CurPosCtrl = OldCurPos;
}

void Delay(long int count)
{
 long int j;
 for(j=0;j<count;j++)10.4994/2.333;
}

// �������� ������� ���������
void main(void)
{
 LCD_InitDefault();// ������������� �������
 LCD_Clear();// ������� �������

 LCD_Putch('>');// ����� �������
 LCD_Type("Information");// ����� �������


 while(1)
 {
  LCD_GotoXY(1,1);
  LCD_Type("The first string");
  Delay(10000);

  LCD_GotoXY(1,1);
  LCD_Type("You are crazy!");
  Delay(10000);

  LCD_GotoXY(1,1);
  LCD_Type("Third String.");
  Delay(10000);
 };// ������������
}