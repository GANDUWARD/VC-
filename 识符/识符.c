#include<stdio.h>
void main()
{     char c;
      printf("请输入一个字符:");
	  c=getchar();
	  if(c>='0' && c<='9')
		  printf("%c是数字\n",c);
	  else if(c>='A' && c<='Z')
		  printf("%c是大写字母\n",c);
	  else if(c>='a' && c<='z')
		  printf("%c是小写字母\n",c);
}