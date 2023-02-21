#include<stdio.h>
#include<string.h>
#include<stdlib.h>
typedef struct 
{
	char time[20];
	char topic[20];
    int readnum;
	int likes;
}Elemdata;
typedef struct node
{
	Elemdata data;
	node *next;
}Lnode,*LinkList;
int InitList(LinkList*L)
{
   *L=(LinkList)malloc(sizeof(Lnode));
   (*L)->next=NULL;
   printf("创建链表成功!\n");
   return 1;
}
LinkList find_position(LinkList*L,Elemdata x)
{
	if((*L)->next==NULL){return (*L);}
	LinkList p=(*L)->next;
	while(p)
	{
		if(x.likes>p->data.likes&&p->next!=NULL){p=p->next;}
		else break;
	}
	return p;
}
int print(LinkList*L)
{ 
	if((*L)->next==NULL){printf("空表！");return 0;}
	LinkList p = (*L)->next;
	while(p)
	{
		printf("%s\t%s\t%d\t%d\n",p->data.time,p->data.topic,p->data.readnum,p->data.likes);
		p=p->next;
	}
	return 1;
}
int check(LinkList*L)
{   
	if((*L)->next==NULL){printf("空表！");return 0;}
	char str[20];
	printf("请输入关键词：");
	scanf("%s",str);
	LinkList p=(*L)->next;
	while(p)
	{
		if(strstr(p->data.topic,str)!=NULL)break;
		p=p->next;
	}
	if(p==NULL){printf("找不到！");return 0;}
	printf("%s\t%s\t%d\t%d\n",p->data.time,p->data.topic,p->data.readnum,p->data.likes);
	return 1;
}
int insertdata(LinkList*L)
{  
	char ch;
	do
	{
    Elemdata x;
	printf("请输入时间、主题、阅读量、点击量(空格隔开):");
	scanf("%s %s %d %d",x.time,x.topic,&x.readnum,&x.likes);
	LinkList p=find_position(L,x);
	if(p==NULL){printf("error!");return 0;}
	LinkList q=(LinkList)malloc(sizeof(Lnode));
	q->next=p->next;p->next=q;
	q->data=x;
	printf("是否继续输入？Y|N");
	getchar();
	scanf("%c",&ch);
	}while(ch=='Y');
	print(L);
	return 1;
}
int delete_data(LinkList*L)
{
	if((*L)->next==NULL){printf("空表！");return 0;}
	char str[20];
	printf("请输入关键词：");
	scanf("%s",str);
	LinkList p=(*L),q;
	while(p->next)
	{
		if(strcmp(p->next->data.topic,str)==0)break;
		p=p->next;
	}
	if(p->next==NULL){printf("找不到！");return 0;}
	q=p->next;p->next=q->next;
	free(q);
	printf("删除成功\n");
	print(L);
	return 1;
}
int calculate_length(LinkList*L)
{
	if((*L)->next==NULL){printf("空表！");return 0;}
	LinkList p = (*L)->next; int i=0;
	while(p)
	{
	   p=p->next;
	   i++;
	 }
    return i;
}
int order(LinkList*L)
{
    if((*L)->next==NULL){printf("空表！");return 0;}
	LinkList p = (*L)->next,q,r=NULL;
	Elemdata x;
	int l=calculate_length(L),i=0,j=0;
    /*for(q=(*L)->next;q->next!=NULL;q=q->next)
	  for(p=(*L)->next;p!=q;p=p->next)
	  {   
		  if(p->data.likes>p->next->data.likes)
		  {
	      x=p->data;
		  p->data=p->next->data;
		  p->next->data=x;
		  }
	  }*/
	for(p=(*L)->next;p->next!=NULL;p=p->next)
		for(q=(*L)->next;q->next!=r;q=q->next)
		{
         if(q->data.likes>q->next->data.likes)
		  {
	      x=q->data;
		  q->data=q->next->data;
		  q->next->data=x;
		  }
		 if(q->next==r){r=q;}
		}
	  print(L);
	  return 1;
}
int main()
{   
	int num;
    LinkList*L=(LinkList*)malloc(sizeof(LinkList));
	InitList(L);
	while(1)
	{
	printf("请执行你的操作:1 插入 2 查找3 退出4 删除5 排序\n");
	scanf("%d",&num);
	if(num==1)insertdata(L);
	if(num==2)check(L);
	if(num==3)exit(0);
	if(num==4)delete_data(L);
	if(num==5)order(L);
	}
	return 1;
}
