#include<reg51.h>
#define lcd P3 
sbit rs=P2^0;
//PIN FOR ENABLE
sbit e=P2^1;
sbit sensor1=P1^0;
sbit sensor2=P1^2;
sbit sensor3=P1^4;
sbit sensor4=P1^6;


void delay (int d)                 //DELAY
{
	unsigned char i;
	for(;d>0;d--)
	{
		for(i=250;i>0;i--);
		for(i=248;i>0;i--);
	}
}
void cmd (char c)                 //COMMAND FUNCTION FOR LCD
{
	lcd=c;
	rs=0;
	e=1;
	delay(5);
	e=0;
}
void display (char c)             //DISPLAY FUNCTION FOR LCD
{
	lcd=c;
	rs=1;
	e=1;
	delay(1);
	e=0;
}
void string (char *p)             //STRING FUNCTION FOR LCD
{
	while(*p)
	{
		display(*p++);
	}
}
void init (void)                  //LCD INITIALIZATION
{       unsigned char x;
	cmd(0x0c);                                     //display on
	cmd(0x38);                                     //use two lines
	cmd(0x01);                                     // Clearing of screen
	cmd(0x80); 
	}
void main()
{int i=0;
	P1=0x00;
	init ();
string("Starting...");
delay(200);
cmd(0x01);                                    
cmd(0x80);
	while(1)
	{string("Number of Cars");
cmd(0xc0);
string("Parked:");

 if (sensor1==1)
 {i++;}
  if (sensor2==1)
 {i++;}
  if (sensor3==1)
 {i++;}
  if (sensor4==1)
 {i++;}
	display(0x30+i);
cmd(0x80);
	 i=0;}


}

