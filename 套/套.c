#include<stdio.h>
void main()
{  int a,b,c,t;
   printf("������������:");
   scanf("%d%d%d",&a,&b,&c);
   if(b>a)
   {   t=a;
       a=b;
	   b=t;
   }
   if(c>a)
   {   t=a;
       a=c;
	   c=t;
   }
   if(c>b)
   {  t=b;
      b=c;
	  c=t;
   }
   printf("�������ɴ�С:%d,%d,%d\n",a,b,c);
}