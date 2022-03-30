#include <reg51.h>
#define lcd P1 
sbit rs=P2^0;
//PIN FOR ENABLE
sbit e=P2^1;
sbit a=P2^3;
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
void Serial() interrupt 4
{    
	   while (RI==0); 	               //RECIVING DATA FROM SLAVE AND STORING IN SBUF
		 string(SBUF);
	   RI=0; }        //toggle led2


 void main()
 {  a=0;
	 init();
	  string("Starting ");
	 delay(200);
	  TMOD=0x20;                             //TIMER1 IN MODE 2(8 BIT AUTORELOAD) AND TIMER 1 IN MODE 1(16BIT)
    TH1=0xFD;                             //BAUD RATE OF 9600
    SCON=0x50;                            //SCON REGISTER WITH MODE 2(8 DATA BITS AND 2 STOP AND START BIT)
//3ms timer
		IE=0x90;          //enable interrupts
	  TR1=1;                   //start timer 1
	  while(1);        //infinte loop
 }