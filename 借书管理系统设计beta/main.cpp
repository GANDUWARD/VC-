#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"查阅.h"
#include"还书.h"
#include"注册.h"
#include"借出书籍.h"
#include"录入.h"
struct book
{  int number;
   char bname[40];
   char author[40];
   char category[40];
   char chuban[40];
  char date [40];
   char price[40];
   char exist[20];
}allbook[100];
struct reader
{
	char count[20];
	char classnumber[10];
	char name[20];
	char sex[10];
}allreader[100];
void menu()
{   int n;
    char ch;
	printf("1、图书信息录入\n");
	printf("2、图书信息查询\n");
	printf("3、借书人注册\n");
	printf("4、办理借书手续\n");
	printf("5、办理还书手续");
	printf("\n请执行你的操作:");
	scanf("%d",&n);
	ch=getchar();
	if(n==3)
	    regist(allreader);
	if(n==2)
		check();
	if(n==1)
		writein();
	if(n==4)
		borrow();
	if(n==5)
		back();
}
void main()
{
	menu();
}
