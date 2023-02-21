#include<stdio.h>
#include<string>
#include<stdlib.h>
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
void bwrite(FILE *fp,int number,char bname[],char author[],char category[],char chuban[],char date[],char price[],char exist[])
{   
	fprintf(fp,"\n");
	fprintf(fp,"%d\t",number);
	fprintf(fp,"%s\t",bname);
	fprintf(fp,"%s\t",author);
	fprintf(fp,"%s\t",category);
	fprintf(fp,"%s\t",date);
	fprintf(fp,"%s\t",chuban);
	fprintf(fp,"%s\t",price);
	fprintf(fp,"%s\t",exist);
	fclose(fp);
}
void writein()
{   int i=0;
    char n;
	int number;
   char bname[40];
   char author[40];
   char category[40];
   char chuban[40];
   char date[40];
   char price[10];
   char exist[20]={"未借出"};
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
   number=i+1;
   allbook[i].number=i+1;
   printf("请输入书名:");
   gets(bname);
   strcpy(allbook[i].bname,bname);
   printf("请输入作者:");
   gets(author);
   strcpy(allbook[i].author,author);
   printf("请输入类别:");
   gets(category);
   strcpy(allbook[i].category,category);
   printf("请输入出版时间:");
   gets(date);
   strcpy(allbook[i].date,date);
   printf("请输入出版社:");
   gets(chuban);
   strcpy(allbook[i].chuban,chuban);
   printf("请输入书本价格:");
   gets(price);
   strcpy(allbook[i].price,price);
   strcpy(allbook[i].exist,exist);
   printf("%d\t%s\t%s\t%s\t%s\t%s\t%s\t%s\n",allbook[i].number,
		   allbook[i].bname,allbook[i].author,allbook[i].category,
		   allbook[i].date,allbook[i].chuban,allbook[i].price,allbook[i].exist);
   printf("请检查是否正确（Y|N）");
   scanf("%c",&n);
   if(n=='Y')
       bwrite(fp,number,bname,author,category,chuban,date,price,exist);
   else
	   exit(0);
   system("cls");
   
}
   
