#include<stdio.h>
void hanio(int n,char a,char b,char c);
void main()
{   int n;
    printf("输入汉诺塔盘子的个数:");
	scanf("%d",&n);
	printf("移动的步骤为:\n");
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