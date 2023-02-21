#include<stdio.h>
void main()
{       long number;
        int count=0;
		printf("请输入一个整数:");
		scanf("%ld",&number);
		if(number<0)
			number=-1*number;
		do
		{  number=number/10;
		   count++;
		}while(number!=0);
		printf("该数字是%d位数。\n",count);
}