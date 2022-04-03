#include<reg51.h>
sbit pin_1=P2^0;
sbit pin_2=P2^3;
sbit pin_3 =P2^6;
sbit pin_4=P3^1;
sbit pin_5=P3^4;
sbit pin_6=P3^7;

void delay (int d)                 //DELAY
{
	unsigned char i;
	for(;d>0;d--)
	{
		for(i=250;i>0;i--);
		for(i=248;i>0;i--);
	}
}
void Trafic_light()
{pin_1=1;
 pin_2=0;
 pin_3=0;
 pin_4=0;
 pin_5=0;
 pin_6=1;
	delay(500);
	pin_1=0;
  pin_2=1;
  pin_3=0;
	pin_4=0;
  pin_5=0;
  pin_6=1;
  delay(500);
	pin_4=1;
  pin_5=0;
  pin_6=0;
	pin_1=0;
  pin_2=0;
  pin_3=1;
delay(500);
	pin_4=0;
  pin_5=1;
  pin_6=0;
	pin_1=0;
  pin_2=0;
  pin_3=1;
delay(500);
 
}
void main()
{P2=0x00;
	P3=0x00;
	while(1)
	{
	Trafic_light();
	
	}
}