#include<stdio.h>
#include<string>
#include<stdlib.h>
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
void check()
{   int i=0;
    char n;
   FILE *fp;
   fp=fopen("C:\\Users\\pc\\Desktop\\VC\\借书管理系统设计\\图书信息.txt","r+");
   while(!feof(fp))
   {
	   fscanf(fp,"%d%s%s%s%s%s%s%s",&allbook[i].number,
		   allbook[i].bname,allbook[i].author,allbook[i].category,
		   allbook[i].chuban,allbook[i].date,allbook[i].price,allbook[i].exist);
	   printf("%d\t%s\t%s\t%s\t%s\t%s\t%s\t%s\n",allbook[i].number,
		   allbook[i].bname,allbook[i].author,allbook[i].category,
		   allbook[i].chuban,allbook[i].date,allbook[i].price,allbook[i].exist);
	   i++;
   }
   printf("查阅完毕？（Y|N）:");
	   scanf("%c",&n);
   if(n=='Y')
   {
	   fclose(fp);
	   system("cls");
   }
}
   

void main()
{
    check();
}