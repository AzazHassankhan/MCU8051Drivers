#include <reg51.h>
sbit led1=P1^0;
sbit led2=P2^0;

void toggle() interrupt 1
{   TH0=0xF5;
	  TL0=0x33;
	  TR0=1;
    led2=~led2;}        //toggle led2


 void main()
 {  led1=0;
	  led2=0;
	  TMOD=0x01;  // Timer0 mode 1(16 Bit manual reload)
// 3ms timer
	  TH0=0xF5;   
	  TL0=0x33;
	  IE=0x82;   //Interrupt 1 
	  TR0=1;     // start timer0
	  while(1)    //infinte loop
	  {led1=~led1;}  //toggle led1
 }