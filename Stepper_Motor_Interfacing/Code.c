#include<reg51.h>

sbit winding1=P1^0;
sbit winding2=P1^1;
sbit winding3=P1^2;
sbit winding4=P1^3;
sbit button1=P1^4;
sbit button2=P1^5;

	
void main()
{button1=0;
	button2=0;
	while(1)
{ if (button1==0 && button2==0)
	 {winding1=1;
   winding2=0;
   winding3=0;
   winding4=1;}
	else if (button1==1 && button2==0)
	{
	 winding1=0;
   winding2=0;
   winding3=0;
   winding4=1;
	}
	else if (button1==0 && button2==1)
	{
	 winding1=0;
   winding2=0;
   winding3=1;
   winding4=1;
	}
	else if (button1==1 && button2==1)
	{
	 winding1=0;
   winding2=0;
   winding3=1;
   winding4=0;
	}
	else
	{winding1=1;
   winding2=0;
   winding3=0;
   winding4=1;}
}
}
