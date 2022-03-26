#include<reg51.h>
#include<stdio.h>
sbit ButtonU=P1^2;                
sbit ButtonD=P1^5;

void TimerDelay()                //Generating 65535*1.085us=71.1ms delay
{ 
   TL0=0x00;                       //INITIAL VALUES ARE STARTING FROM ZERO
   TH0=0xEE;
   TR0=1;                         //STARTING TIMER
   while(TF0==0);                 //WAIT FOR OVER FLOWING TIMER
   TR0=0;                         //STOPING TIMER
   TF0=0;                         //FORCING OVER FLOWING
   }
	
	void main()
{ int i=-1,j=0;               //initialization
	int num[]={0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,0x7f,0x6f};
	ButtonU=0;                  //increment button
  ButtonD=0;                   //decrement button
	TMOD=0x01;                   //TIMER0 IN MODE 1(16BIT)   

while(1)                       //infinit loop
{  
	if (ButtonU==1)              // if buttonU is press increment by 1
		 {   
			 if(i>8)
		 {i=-1;}
			 i++; 
			 P2=num[i];
			for(j=0;j<80;j++)
			{TimerDelay() ;}
			}
		else if (ButtonD==1)     // if buttonD is press Decrement by 1
		 { if(i<=0)
		   {i=10;}
			 i--;
			 P2=num[i];
			for(j=0;j<80;j++)
			{TimerDelay() ;}
			}
	}
}