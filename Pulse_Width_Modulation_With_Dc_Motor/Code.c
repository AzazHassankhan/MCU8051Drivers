#include<reg51.h>
#define lcd P3 
sbit rs=P2^0;
//PIN FOR ENABLE
sbit e=P2^1;
sbit motor1=P1^0;
sbit motor2=P1^1;
sbit en=P1^2;
sbit pin1=P1^3;
sbit pin2=P1^4;
sbit direction=P1^5;
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
	direction=0;
	en=1;
  pin1=0;
	pin2=0;
	while(1)
{ if (direction==0)
	{
		if (pin1==1 &&  pin2==0)
		{motor1=0;
     motor2=1;
			delay(25);
			motor2=0;
			delay(75);
		}
		else if (pin1==0 && pin2==1)
		{motor1=0;
     motor2=1;
			delay(50);
			motor2=0;
			delay(50);
		}
		else if (pin1==1 &&  pin2==1)
		{motor1=0;
     motor2=1;
			delay(75);
			motor2=0;
			delay(25);
		}
		else
		{motor1=0;
     motor2=1;}
}
		else
		{if (pin1==1 &&  pin2==0)
		{motor1=1;
     motor2=0;
			delay(25);
			motor1=0;
			delay(75);
		}
		else if (pin1==0 && pin2==1)
		{motor1=1;
     motor2=0;
			delay(50);
			motor1=0;
			delay(50);
		}
		else if (pin1==1 &&  pin2==1)
		{motor1=1;
     motor2=0;
			delay(75);
			motor1=0;
			delay(25);
		}
		else
		{motor1=1;
     motor2=0;}
		}
}
}
