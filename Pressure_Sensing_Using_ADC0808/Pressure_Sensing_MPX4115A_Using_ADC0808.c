#include <reg51.h>
#define lcd P3 
#define output P1 
sbit rs=P2^0;
sbit e=P2^1;
sbit wr=P2^4;
sbit intr=P2^5;
sbit rd=P2^6;
sbit al=P2^7;
sbit add_a=P0^0;                    //SELECTING CHANNEL 0
sbit add_b=P0^1;
sbit add_c=P0^2;

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
{unsigned char var,tenth,unite;
	float a,b;
	    add_a=0;                    //SELECTING CHANNEL 0
      add_b=0;
      add_c=0;
      al=1;                       //ENABLING CHANNEL 0
      wr=1;                       //STARTING CONVERSION
      al=0;                         
      wr=0;                       //STOPING CONVERSION
      while(intr==1);             //WAITING FOR CONVERSION TO STOP
      while(intr==0);
      rd=1;                  //READING CONVERTED DATA
     b=output;                       //COPING CONVERTED DATA TO VARIABLE X
      rd=0;                       //STOP READING CONVERTED DATA
	   a=(5.0/256)*b;                  //PRESSURE FORMULA
     var=((a/5.0)+0.09)/0.009-1;       //PRESSURE FORMULA                               //FORMULA FOR TEMPRATURE SENSOR
     tenth=var/10;  
     tenth=tenth+0x30;   
     unite=var%10;
     unite=unite+0x30;	
		 cmd(0xc0);
	   display(tenth);
	   display(unite);
	   string(" C");
}

	void main()
	{init();
		output=0xff;
		intr=1;                     //INITIALIING ALL VALUES
    rd=0;
    wr=0;
    al=0;
		while(1)
		{ cmd(0x80);
			string("Pressure Sensing...");
		AdcConversion();}
	}