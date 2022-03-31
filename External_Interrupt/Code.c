#include <reg51.h>
#define lcd P1 
sbit led=P2^7;
sbit rs=P2^0;
//PIN FOR ENABLE
sbit e=P2^1;
int count=0;
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
void AsciiConv (unsigned char value)
{
unsigned char x, d1, d2, d3;
x= value/10;
d1=value%10; // Calculating MSB
d2=x%10;
d3=x/10; // Calculating LSB
display(d3+0x30); // LSB
display(d2+0x30);
display(d1+0x30); // MSB
delay(10);
}
void INTR1 () interrupt 0 // Using IE.0 which External Interrupt 1 , K3 is interrupted
{ cmd(0x80); 
	string("Clock Pulses:");
	led=~led;
  count++;
	cmd(0xc0);  
	AsciiConv (count);
}
 void main()
 { 
	 init();
	 led=0;
	IE=0x81;          //enable external Interrupt 0
	  
	  while(1) ;       //infinite loop
		
		
 }