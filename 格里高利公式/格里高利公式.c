#include<stdio.h>
#include<math.h>
#define E 1e-5
void main()
{    double pi=0,item;
     int a=1,flag=1;
	 do
	 {    item=flag*1.0/a;
	      pi=pi+item;
		  a=a+2;
		  flag=-1*flag;
	 }while(fabs(item)>E);
	 pi=pi*4;
	 printf("pi=%lf\n",pi);
}