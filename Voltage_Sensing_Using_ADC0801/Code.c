#include <reg51.h>
#define lcd P3 
#define output P1 
sbit rs=P2^0;
sbit e=P2^1;
sbit rd=P2^3;
sbit wr=P2^4;
sbit intr=P2^5;


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
	delay(5);
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
{   
	cmd(0x0c);                                     //display on
	cmd(0x38);                                     //use two lines
	cmd(0x01);                                     // Clearing of screen
	cmd(0x80); 
	}
void AdcConversion()
{unsigned char var;
	wr=0;
	wr=1;
	while(intr==1);
	rd=0;
	var=output;
	rd=1;
	var=5.02*var/256;                              //FORMULA FOR VOLTAGE SENSOR
		cmd(0xc0);
	display(var+0x30);
	string(" V");
}

	void main()
	{init();
		output=0xff;
		intr=1;
		rd=1;
		wr=1;
		while(1)
		{ cmd(0x80);
			string("Volatge Sensing...");

		AdcConversion();}
	}