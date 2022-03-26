#include<reg51.h>
sbit Led1=P2^0;                
sbit Led2=P2^1;
sbit Led3=P2^2;
sbit Button1=P1^2;                
sbit Button2=P1^5;
sbit Button3=P1^7;

void main()
{ Button1=0;
  Button2=0;
  Button3=0;
  Led1=0;
  Led2=0;
  Led3=0;
  while(1)
  {if (Button1==1)
   {Led1=1;}
	 else
	 {Led1=0;}
   if (Button2==1)
   {Led2=1;}
	 else
	 {Led2=0;}
   if (Button3==1)
   {Led3=1;}
	 else
	 {Led3=0;}
  }
}