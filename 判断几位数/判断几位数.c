#include<stdio.h>
void main()
{       long number;
        int count=0;
		printf("������һ������:");
		scanf("%ld",&number);
		if(number<0)
			number=-1*number;
		do
		{  number=number/10;
		   count++;
		}while(number!=0);
		printf("��������%dλ����\n",count);
}