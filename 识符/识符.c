#include<stdio.h>
void main()
{     char c;
      printf("������һ���ַ�:");
	  c=getchar();
	  if(c>='0' && c<='9')
		  printf("%c������\n",c);
	  else if(c>='A' && c<='Z')
		  printf("%c�Ǵ�д��ĸ\n",c);
	  else if(c>='a' && c<='z')
		  printf("%c��Сд��ĸ\n",c);
}