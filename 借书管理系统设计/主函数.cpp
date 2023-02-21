#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct book//结构体书籍//
{  int number;
   char bname[40];
   char author[40];
   char category[40];
   char chuban[40];
  char date [40];
   char price[40];
   char exist[20];
}allbook[100];
struct reader//结构体读者//
{
	char count[20];
	char classnumber[10];
	char name[20];
	char sex[10];
}allreader[100];
void menu();//开始，先声明菜单函数，统领作用//
void makein(FILE *fp,char name[],char sex[],char classnumber[],char count[])//借书人信息写入函数//
{
	fprintf(fp,"\n");
	fprintf(fp,"\t%s\t",name);
	fprintf(fp,"%s\t",sex);
	fprintf(fp,"%s\t",classnumber);
	fprintf(fp,"%s\t",count);
	fclose(fp);
}
void judge(int i,struct reader allreader[],char name[],char sex[],char classnumber[],char count[],FILE *fp)//判断借书人是否重复函数//
{   
	char ch;
	int j,x=1;
	for(j=0;j<i;j++)
	{
		x=strcmp(allreader[j].count,allreader[i].count);
		if(x==0)break;
	}
	if(x!=0)
	{
		printf("请查看是否正确？\n");
	printf("%s\t%s\t%s\t%s\n",allreader[i].name,allreader[i].sex,allreader[i].classnumber,allreader[i].count);
	printf("输入Y或N\n");
	scanf("%c",&ch);
	if(ch=='Y')
	{
	makein(fp,name,sex,classnumber,count);
	}
	else
		exit(0);
	}
	else
		printf("输入信息重复！");
}
void regist(struct reader allreader[])//借书人注册函数//
{   
	char name[20];
	char sex[10];
	char classnumber[10];
	char count[20];
	int i=0;
	FILE *fp;
	fp=fopen("C:\\Users\\pc\\Desktop\\VC\\借书管理系统设计\\借书人信息.txt","r+");
	while(!feof(fp))
	{
		fscanf(fp,"%s%s%s%s",allreader[i].name,allreader[i].sex,allreader[i].classnumber,allreader[i].count);
		printf("%s\t%s\t%s\t%s\n",allreader[i].name,allreader[i].sex,allreader[i].classnumber,allreader[i].count);
		i++;
	}
	printf("请输入注册人姓名:");
	gets(name);
	strcpy(allreader[i].name,name);
	printf("请输入注册人性别:");
	gets(sex);
	strcpy(allreader[i].sex,sex);
	printf("请输入注册人班级:");
	gets(classnumber);
	strcpy(allreader[i].classnumber,classnumber);
	printf("请输入注册人学号:");
	gets(count);
	strcpy(allreader[i].count,count);
	judge(i,allreader,name,sex,classnumber,count,fp);
	system("cls");
	menu();
}
void check(struct book allbook[])//图书信息查看函数//
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
	   menu();
   }
}
void bwrite(FILE *fp,int number,char bname[],char author[],char category[],char chuban[],char date[],char price[],char exist[])//图书信息录入函数//
{   
	fprintf(fp,"\n");
	fprintf(fp,"%d\t",number);
	fprintf(fp,"%s\t",bname);
	fprintf(fp,"%s\t",author);
	fprintf(fp,"%s\t",category);
	fprintf(fp,"%s\t",date);
	fprintf(fp,"%s\t",chuban);
	fprintf(fp,"%s\t",price);
	fprintf(fp,"%s",exist);
	fclose(fp);
}
void writein()//还书函数//
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
   {
	   bwrite(fp,number,bname,author,category,chuban,date,price,exist);
        system("cls");
         menu();
		 }
   else
   {   fclose(fp);
	   system("cls");
       menu();
   }
}
void bout(int k,struct book allbook[])//借还书信息录入函数//
{   
	FILE *sp;
	sp=fopen("C:\\Users\\pc\\Desktop\\VC\\借书管理系统设计\\图书信息.txt","w");
	int i=0;
	for(i=0;i<k;i++)
	{
		if(i!=0)
				fprintf(sp,"\n");               
	fprintf(sp,"%d\t",allbook[i].number);
	fprintf(sp,"%s\t",allbook[i].bname);
	fprintf(sp,"%s\t",allbook[i].author);
	fprintf(sp,"%s\t",allbook[i].category);
	fprintf(sp,"%s\t",allbook[i].date);
	fprintf(sp,"%s\t",allbook[i].chuban);
	fprintf(sp,"%s\t",allbook[i].price);
	fprintf(sp,"%s",allbook[i].exist);
	}
	fclose(sp);
}
void borrow()//借书函数//
{    
	int n,x,i=0,k;
	char c,ch;
	FILE *fp;
	char s[20]={"已借出"};
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
   k=i;
   fclose(fp);
   printf("请输入要借出书籍的编号:");
   scanf("%d",&n);
   ch=getchar();
   x=strcmp(allbook[n-1].exist,s);
   if(n<i+1&&x!=0)
   {
	       strcpy(allbook[n-1].exist,s);
           printf("%d\t%s\t%s\t%s\t%s\t%s\t%s\t%s\n",allbook[n-1].number,
		   allbook[n-1].bname,allbook[n-1].author,allbook[n-1].category,
		   allbook[n-1].chuban,allbook[n-1].date,allbook[n-1].price,allbook[n-1].exist);
		   printf("请确定是否执行借书手续（Y|N）");
		   scanf("%c",&c);
		   if(c=='Y')
		   {   
			   fclose(fp);
			   bout(k,allbook);
			   printf("借书成功!");
		   }
		   else
			   exit(0);
   }
   else
	   printf("错误");
   exit(0);
}
void back()//还书函数//
{    
	int n,x,i=0,k;
	char c,ch;
	FILE *fp;
	char s[20]={"未借出"};
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
   k=i;
   fclose(fp);
   printf("请输入要还书籍的编号:");
   scanf("%d",&n);
   ch=getchar();
   x=strcmp(allbook[n-1].exist,s);
   if(n<i+1&&x!=0)
   {
	       strcpy(allbook[n-1].exist,s);
           printf("%d\t%s\t%s\t%s\t%s\t%s\t%s\t%s\n",allbook[n-1].number,
		   allbook[n-1].bname,allbook[n-1].author,allbook[n-1].category,
		   allbook[n-1].chuban,allbook[n-1].date,allbook[n-1].price,allbook[n-1].exist);
		   printf("请确定是否执行还书手续（Y|N）");
		   scanf("%c",&c);
		   if(c=='Y')
		   {   
			   fclose(fp);
			   bout(k,allbook);
			   printf("还书成功!");
		   }
		   else
			   exit(0);
   }
   else
	   printf("错误");
   exit(0);
}
void menu()//菜单函数//
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
		check(allbook);
	if(n==1)
		writein();
	if(n==4)
		borrow();
	if(n==5)
		back();
}
void main()//先运行菜单函数//
{
	menu();
}