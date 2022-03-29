#include<reg51.h>
#define lcd P3 
sbit rs=P2^0;
//PIN FOR ENABLE
sbit e=P2^1;

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
{init ();
string("Starting...");
delay(200);
cmd(0x01);                                    
cmd(0x80);
string("Hey!");
cmd(0xc0);
string("I am Azaz");
delay(200);
cmd(0x01);                                    
cmd(0x80);
string("Thanks For Watching");
delay(200);
}

