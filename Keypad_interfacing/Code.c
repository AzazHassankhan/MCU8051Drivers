#include<reg51.h>
#define lcd P3 
sbit rs=P2^0;
//PIN FOR ENABLE
sbit e=P2^1;
sbit col1=P1^1;
sbit col2=P1^2;
sbit col3 =P1^3;
sbit row1=P1^4;
sbit row2=P1^5;
sbit row3 =P1^6;
sbit row4 =P1^7;
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
void keypad()
{unsigned char a; 
	cmd(0xc0);
	     col1=0,col2=1,col3=1;                  //ENABLING COLOUME 1
	
if(row1==0)                                   //IF KEY 1 IS PRESSED SEND 'V' TO SLAVE
   {   	
	     string("3");                                  
	 } 
		
if (row2==0)                                  //IF KEY4 IS PRESSED SEND 'P' TO SLAVE
   {   
	     string("6"); 
	 }
if (row3==0)                                  //IF KEY7 IS PRESSED SEND 'T' TO SLAVE
    {  
       string("9"); 
		}
if (row4==0)                                  //IF KEY 2 IS PRESSED ON STREET LIGHTS
 {     
	 string("#"); 
 }
 col1=1,col2=0,col3=1;                  //ENABLING COLOUME 2
if(row1==0)                                   //IF KEY 1 IS PRESSED SEND 'V' TO SLAVE
   {   	
	     string("2");                                  
	 } 
		
if (row2==0)                                  //IF KEY4 IS PRESSED SEND 'P' TO SLAVE
   {   
	     string("5"); 
	 }
if (row3==0)                                  //IF KEY7 IS PRESSED SEND 'T' TO SLAVE
    {  
       string("8"); 
		}
if (row4==0)                                  //IF KEY 2 IS PRESSED ON STREET LIGHTS
 {     
	 string("0"); 
 }
 
 col1=1,col2=1,col3=0;                  //ENABLING COLOUME 2
if(row1==0)                                   //IF KEY 1 IS PRESSED SEND 'V' TO SLAVE
   {   	
	     string("1");                                  
	 } 
		
if (row2==0)                                  //IF KEY4 IS PRESSED SEND 'P' TO SLAVE
   {   
	     string("4"); 
	 }
if (row3==0)                                  //IF KEY7 IS PRESSED SEND 'T' TO SLAVE
    {  
       string("7"); 
		}
if (row4==0)                                  //IF KEY 2 IS PRESSED ON STREET LIGHTS
 {     
	 string("*"); 
 }
}
void main()
{init ();
	string("Press any Key...");
	while(1)
{ keypad();
}
}
