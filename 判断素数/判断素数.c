#include<stdio.h>
void main()
{  int n,i;
   printf("请输入一个整数:");
   scanf("%d",&n);
   for(i=2;i<=n-1;i++)
	   if(n%i==0)break;
	   if(i>n-1)
		   printf("%d是素数!\n",n);
	   else
		   printf("%d不是素数!\n",n);
}