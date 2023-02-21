#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct reader
{
	char count[20];
	char classnumber[10];
	char name[20];
	char sex[10];
}allreader[100];
void makein(FILE *fp,char name[],char sex[],char classnumber[],char count[])
{
	fprintf(fp,"\n");
	fprintf(fp,"\t%s\t",name);
	fprintf(fp,"%s\t",sex);
	fprintf(fp,"%s\t",classnumber);
	fprintf(fp,"%s\t",count);
}
void judge(int i,struct reader allreader[],char name[],char sex[],char classnumber[],char count[],FILE *fp)
{   
	char ch;
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
void regist(struct reader allreader[])
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
	i++;
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
}

