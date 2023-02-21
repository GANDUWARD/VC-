
#include<stdio.h>
void main()
{    int n=0;
     printf("请输入一个字符串:");
	 for(;getchar()!='\n';n++);
	 printf("该字符有%d个字符\n",n);
}