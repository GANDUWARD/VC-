#include<stdio.h>
#include<string.h>
#include<stdlib.h>
typedef struct
{
	char number[20];
	char name[20];
	float price;
	char date[20];
	int buys;
}Elemdata;
typedef struct node
{
	Elemdata data;
	node* next;
}Lnode,*LinkList;
int InitList(LinkList* L)
{
	(*L) = (LinkList)malloc(sizeof(Lnode));
	(*L)->next = NULL;
	printf("链表创建成功！\n");
	return 1;
}
int writein(LinkList* L)
{   
	Elemdata x;LinkList p=(*L);
	printf("请输入书号(0退出)：");
	scanf_s("%s", x.number,20);
	printf("请输入书名：");
	scanf_s("%s", x.name, 20);
	printf("请输入价格：");
	scanf_s("%f",&x.price);
	printf("请输入日期：");
	scanf_s("%s", x.date, 20);
	printf("请输入销量:");
	scanf_s("%d", &x.buys);
	while (strcmp(x.number, "0") != 0)
	{    
		LinkList q =(LinkList)malloc(sizeof(Lnode));
		q->next = p->next; q->data = x; p->next = q;
		p = p->next;
		printf("请输入书号(0退出)：");
		scanf_s("%s", x.number, 20);
		printf("请输入书名：");
		scanf_s("%s", x.name, 20);
		printf("请输入价格：");
		scanf_s("%f", &x.price);
		printf("请输入日期：");
		scanf_s("%s", x.date, 20);
		printf("请输入数量:");
		scanf_s("%d", &x.buys);
	}
	return 1;
}
int print(LinkList* L)
{
	if ((*L)->next == NULL)return 0;
	LinkList p =(*L)->next;
	while (p)
	{
		printf("%s\t%s\t%.2f元\t%s\t%d本\n", p->data.number, p->data.name, p->data.price, p->data.date, p->data.buys);
		p = p->next;
	}
}
int find_dear(LinkList* L)
{
	if ((*L)->next == NULL)return 0;
	LinkList p = (*L)->next,max=(*L)->next;
	while (p)
	{
		if (p->data.price > max->data.price)max = p;
		p = p->next;
	}
	printf("最贵的书是%s\n", max->data.name);
	return 1;
}
int check(LinkList* L)
{
	if ((*L)->next == NULL)return 0;
	LinkList p = (*L)->next;
	char name[20]; int q = 0;
	printf("请输入名称：");
	scanf_s("%s", name, 20);
	while (p)
	{
		if (strcmp(p->data.name, name)==0) { q = 1; printf("%s\t%s\t%.2f元\t%s\t%d本\n", p->data.number, p->data.name, p->data.price, p->data.date, p->data.buys); }
		p = p->next;
	}
	if (q == 0)printf("未找到该书！");
	return 1;
}
int find_year(LinkList* L)
{
	if ((*L)->next == NULL)return 0;
	LinkList p = (*L),r;
	char date[20]; int q = 0;
	printf("请输入日期：");
	scanf_s("%s", date, 20);
	while (p->next)
	{
		if (strcmp(p->next->data.date, date) < 0) { q = 1; r = p->next; p->next = r->next; free(r); continue; }
		p = p->next;
	}
	if (q == 0)printf("未找到该书！");
	return 1;
}
int change_buys(LinkList* L)
{
	if ((*L)->next == NULL)return 0;
	LinkList p = (*L)->next;
	char name[20]; int q = 0,b=0;
	printf("请输入名称：");
	scanf_s("%s", name, 20);
	printf("请输入修改数量:");
	scanf_s("%d", &b);
	while (p)
	{
		if (strcmp(p->data.name, name) == 0) 
		{ 
			q = 1; 
			printf("之前的信息是%s\t%s\t%.2f元\t%s\t%d本\n", p->data.number, p->data.name, p->data.price, p->data.date, p->data.buys);
			p->data.buys = b;
			printf("之后的信息是%s\t%s\t%.2f元\t%s\t%d本\n", p->data.number, p->data.name, p->data.price, p->data.date, p->data.buys);
		}
		p = p->next;
	}
	if (q == 0)printf("未找到该书！");
	return 1;
}
int insert_list(LinkList* L)
{
	Elemdata x; LinkList p = (*L);
	int i = 0,pos,k=0;
	printf("请输入书号(0退出)：");
	scanf_s("%s", x.number, 20);
	printf("请输入书名：");
	scanf_s("%s", x.name, 20);
	printf("请输入价格：");
	scanf_s("%f", &x.price);
	printf("请输入日期：");
	scanf_s("%s", x.date, 20);
	printf("请输入销量:");
	scanf_s("%d", &x.buys);
	printf("请输入你要插入的位置：");
	scanf_s("%d", &pos);
	while (p->next)
	{   
		if(i==pos)
		{   
			k = 1;
			LinkList q = (LinkList)malloc(sizeof(Lnode));
			q->next = p->next; q->data = x; p->next = q;
		}
		p = p->next; i++;
	}
	if (k == 0)printf("插入位置错误！");
	return 1;
}
int main()
{   
	int num;
	LinkList* L = (LinkList*)malloc(sizeof(LinkList));
	InitList(L);
	writein(L);
	while (1)
	{   
		system("cls");
		print(L);
		printf("请执行你的操作:1 找最贵的书2 按书名查找3 删除某年份之前图书4 根据书名修改数量5 按位置插入图书\n");
		scanf_s("%d", &num);
		if (num == 1)find_dear(L);
		if (num == 2)check(L);
		if (num == 3)find_year(L);
		if (num == 4)change_buys(L);
		if (num == 5)insert_list(L);
		printf("按回车键退出"); getchar(); getchar();
	}
	return 0;
}