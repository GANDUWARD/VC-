#include<stdio.h>
void hanio(int n,char a,char b,char c);
void main()
{   int n;
    printf("���뺺ŵ�����ӵĸ���:");
	scanf("%d",&n);
	printf("�ƶ��Ĳ���Ϊ:\n");
	hanio(n,'a','b','c');
}
void hanio(int n, char a,char b,char c)
{   if(n==1)
        printf("%c-->%c\n",a,c);
    else
	{  hanio(n-1,a,c,b);
	   printf("%c-->%c\n",a,c);
	   hanio(n-1,b,a,c);
	   }
}