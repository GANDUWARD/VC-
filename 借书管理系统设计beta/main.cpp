#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"����.h"
#include"����.h"
#include"ע��.h"
#include"����鼮.h"
#include"¼��.h"
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
	printf("1��ͼ����Ϣ¼��\n");
	printf("2��ͼ����Ϣ��ѯ\n");
	printf("3��������ע��\n");
	printf("4�������������\n");
	printf("5������������");
	printf("\n��ִ����Ĳ���:");
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
