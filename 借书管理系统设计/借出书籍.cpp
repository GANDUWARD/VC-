#include<stdio.h>
#include<stdlib.h>
#include<string.h>
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
void borrowout(int k,struct book allbook[])
{   
	FILE *sp;
	sp=fopen("C:\\Users\\pc\\Desktop\\VC\\�������ϵͳ���\\ͼ����Ϣ����.txt","w");
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
void borrow()
{    
	int n,x,i=0,k;
	char c,ch;
	FILE *fp;
	char s[20]={"�ѽ��"};
   fp=fopen("C:\\Users\\pc\\Desktop\\VC\\�������ϵͳ���\\ͼ����Ϣ����.txt","r+");
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
			   borrowout(k,allbook);
			   printf("����ɹ�!");
		   }
		   else
			   exit(0);
   }
   else
	   printf("����!");
   exit(0);
}
void main()
   {
	   borrow();
   }

	