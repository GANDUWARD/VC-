#include<stdio.h>
void main()
{   int n,t,number=20;
    float a=2,b=1,s=0;
	for(n=1;n<=number;n++)
	{  s=s+a/b;
	   t=a;a=a+b;b=t;
	   }
	printf("数列的和是:%9.6f\n",s);
}