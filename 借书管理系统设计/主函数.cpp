#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct book//�ṹ���鼮//
{  int number;
   char bname[40];
   char author[40];
   char category[40];
   char chuban[40];
  char date [40];
   char price[40];
   char exist[20];
}allbook[100];
struct reader//�ṹ�����//
{
	char count[20];
	char classnumber[10];
	char name[20];
	char sex[10];
}allreader[100];
void menu();//��ʼ���������˵�������ͳ������//
void makein(FILE *fp,char name[],char sex[],char classnumber[],char count[])//��������Ϣд�뺯��//
{
	fprintf(fp,"\n");
	fprintf(fp,"\t%s\t",name);
	fprintf(fp,"%s\t",sex);
	fprintf(fp,"%s\t",classnumber);
	fprintf(fp,"%s\t",count);
	fclose(fp);
}
void judge(int i,struct reader allreader[],char name[],char sex[],char classnumber[],char count[],FILE *fp)//�жϽ������Ƿ��ظ�����//
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
		printf("��鿴�Ƿ���ȷ��\n");
	printf("%s\t%s\t%s\t%s\n",allreader[i].name,allreader[i].sex,allreader[i].classnumber,allreader[i].count);
	printf("����Y��N\n");
	scanf("%c",&ch);
	if(ch=='Y')
	{
	makein(fp,name,sex,classnumber,count);
	}
	else
		exit(0);
	}
	else
		printf("������Ϣ�ظ���");
}
void regist(struct reader allreader[])//������ע�ắ��//
{   
	char name[20];
	char sex[10];
	char classnumber[10];
	char count[20];
	int i=0;
	FILE *fp;
	fp=fopen("C:\\Users\\pc\\Desktop\\VC\\�������ϵͳ���\\��������Ϣ.txt","r+");
	while(!feof(fp))
	{
		fscanf(fp,"%s%s%s%s",allreader[i].name,allreader[i].sex,allreader[i].classnumber,allreader[i].count);
		printf("%s\t%s\t%s\t%s\n",allreader[i].name,allreader[i].sex,allreader[i].classnumber,allreader[i].count);
		i++;
	}
	printf("������ע��������:");
	gets(name);
	strcpy(allreader[i].name,name);
	printf("������ע�����Ա�:");
	gets(sex);
	strcpy(allreader[i].sex,sex);
	printf("������ע���˰༶:");
	gets(classnumber);
	strcpy(allreader[i].classnumber,classnumber);
	printf("������ע����ѧ��:");
	gets(count);
	strcpy(allreader[i].count,count);
	judge(i,allreader,name,sex,classnumber,count,fp);
	system("cls");
	menu();
}
void check(struct book allbook[])//ͼ����Ϣ�鿴����//
{   int i=0;
    char n;
   FILE *fp;
   fp=fopen("C:\\Users\\pc\\Desktop\\VC\\�������ϵͳ���\\ͼ����Ϣ.txt","r+");
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
   printf("������ϣ���Y|N��:");
	   scanf("%c",&n);
   if(n=='Y')
   {
	   fclose(fp);
	   system("cls");
	   menu();
   }
}
void bwrite(FILE *fp,int number,char bname[],char author[],char category[],char chuban[],char date[],char price[],char exist[])//ͼ����Ϣ¼�뺯��//
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
void writein()//���麯��//
{   int i=0;
    char n;
	int number;
   char bname[40];
   char author[40];
   char category[40];
   char chuban[40];
   char date[40];
   char price[10];
   char exist[20]={"δ���"};
   FILE *fp;
   fp=fopen("C:\\Users\\pc\\Desktop\\VC\\�������ϵͳ���\\ͼ����Ϣ.txt","r+");
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
   printf("����������:");
   gets(bname);
   strcpy(allbook[i].bname,bname);
   printf("����������:");
   gets(author);
   strcpy(allbook[i].author,author);
   printf("���������:");
   gets(category);
   strcpy(allbook[i].category,category);
   printf("���������ʱ��:");
   gets(date);
   strcpy(allbook[i].date,date);
   printf("�����������:");
   gets(chuban);
   strcpy(allbook[i].chuban,chuban);
   printf("�������鱾�۸�:");
   gets(price);
   strcpy(allbook[i].price,price);
   strcpy(allbook[i].exist,exist);
   printf("%d\t%s\t%s\t%s\t%s\t%s\t%s\t%s\n",allbook[i].number,
		   allbook[i].bname,allbook[i].author,allbook[i].category,
		   allbook[i].date,allbook[i].chuban,allbook[i].price,allbook[i].exist);
   printf("�����Ƿ���ȷ��Y|N��");
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
void bout(int k,struct book allbook[])//�軹����Ϣ¼�뺯��//
{   
	FILE *sp;
	sp=fopen("C:\\Users\\pc\\Desktop\\VC\\�������ϵͳ���\\ͼ����Ϣ.txt","w");
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
void borrow()//���麯��//
{    
	int n,x,i=0,k;
	char c,ch;
	FILE *fp;
	char s[20]={"�ѽ��"};
   fp=fopen("C:\\Users\\pc\\Desktop\\VC\\�������ϵͳ���\\ͼ����Ϣ.txt","r+");
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
   printf("������Ҫ����鼮�ı��:");
   scanf("%d",&n);
   ch=getchar();
   x=strcmp(allbook[n-1].exist,s);
   if(n<i+1&&x!=0)
   {
	       strcpy(allbook[n-1].exist,s);
           printf("%d\t%s\t%s\t%s\t%s\t%s\t%s\t%s\n",allbook[n-1].number,
		   allbook[n-1].bname,allbook[n-1].author,allbook[n-1].category,
		   allbook[n-1].chuban,allbook[n-1].date,allbook[n-1].price,allbook[n-1].exist);
		   printf("��ȷ���Ƿ�ִ�н���������Y|N��");
		   scanf("%c",&c);
		   if(c=='Y')
		   {   
			   fclose(fp);
			   bout(k,allbook);
			   printf("����ɹ�!");
		   }
		   else
			   exit(0);
   }
   else
	   printf("����");
   exit(0);
}
void back()//���麯��//
{    
	int n,x,i=0,k;
	char c,ch;
	FILE *fp;
	char s[20]={"δ���"};
   fp=fopen("C:\\Users\\pc\\Desktop\\VC\\�������ϵͳ���\\ͼ����Ϣ.txt","r+");
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
   printf("������Ҫ���鼮�ı��:");
   scanf("%d",&n);
   ch=getchar();
   x=strcmp(allbook[n-1].exist,s);
   if(n<i+1&&x!=0)
   {
	       strcpy(allbook[n-1].exist,s);
           printf("%d\t%s\t%s\t%s\t%s\t%s\t%s\t%s\n",allbook[n-1].number,
		   allbook[n-1].bname,allbook[n-1].author,allbook[n-1].category,
		   allbook[n-1].chuban,allbook[n-1].date,allbook[n-1].price,allbook[n-1].exist);
		   printf("��ȷ���Ƿ�ִ�л���������Y|N��");
		   scanf("%c",&c);
		   if(c=='Y')
		   {   
			   fclose(fp);
			   bout(k,allbook);
			   printf("����ɹ�!");
		   }
		   else
			   exit(0);
   }
   else
	   printf("����");
   exit(0);
}
void menu()//�˵�����//
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
		check(allbook);
	if(n==1)
		writein();
	if(n==4)
		borrow();
	if(n==5)
		back();
}
void main()//�����в˵�����//
{
	menu();
}