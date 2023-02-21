#include<stdio.h>
#include<string.h>
#include<stdlib.h>
typedef struct 
{
	int date;
	char name[20];
	char symbol[20];
	int people;
}party;
typedef struct node
{
	party data;
	struct node* next;
}Lnode,*LinkList;
int calculate_length(LinkList* L)
{
	int i = 0;
	Lnode* p = (*L)->next;
	while (p != NULL)
	{
		i++;
		p = p->next;
	}
	return i;
}
void print(LinkList* L)
{  
	if ((*L)->next == NULL) { printf("空列表"); exit(0); }
	Lnode* p = (*L)->next;
	if((*L)!=NULL)
		while (p != NULL)
		{
			printf("%d年\t%s\t%s\t%d人\n", p->data.date, p->data.name, p->data.symbol, p->data.people);
			p = p->next;
		}
}
void list_create(LinkList* L)
{
	Lnode* p; int number;
	p = (*L)->next;
	printf("请输入年份：(0退出)");
	scanf_s("%d", &number);
	if (number != 0)
	{
		while (1)
		{
			p->data.date = number;
			printf("请输入会名：");
			scanf_s("%s", p->data.name, 20);
			printf("请输入代表名：");
			scanf_s("%s", p->data.symbol, 20);
			printf("请输入人数：");
			scanf_s("%d", &p->data.people);
			printf("请输入年份:(0退出)");
			scanf_s("%d", &number);
			if (number == 0) { p->next = NULL; break; }
			else
			{
				p->next = (LinkList)malloc(sizeof(Lnode));
				p = p->next;
			}
		}
	}
	print(L);
}
void insert_list(LinkList* L)
{
	int n, l = calculate_length(L), i = 1;
	printf("%d", l);
	Lnode* p = (*L)->next;
	Lnode* pt = *L;
	party* x = (party*)malloc(sizeof(party));
	printf("请输入你要插入的位置：");
	scanf_s("%d", &n);  //将位置序号赋值给a
	if (n > l || n < 0)
	{
		printf("插入位置有误"); exit(0);
	}
	else
	{
		printf("请输入年份：");
		scanf_s("%d", &x->date);
		printf("请输入会名：");
		scanf_s("%s", x->name, 20);
		printf("请输入代表：");
		scanf_s("%s", x->symbol, 20);
		printf("请输入人数：");
		scanf_s("%d", &x->people);
	}
	while (p != NULL && i <= l) //遍历且位序小于l
	{
		if (i == n)
		{
			Lnode* t = (LinkList)malloc(sizeof(Lnode));
			t->data = *x;
			pt->next = t; t->next = p;  //插入操作
			break;
		}
		p = p->next; pt = pt->next; i++;
	}
	print(L);
}
void check_list(LinkList*L)
{
Lnode* p = (*L)->next;
Lnode* pt = *L;
char n[20];
printf("请输入会议的代表（名字）");
scanf_s("%s", n, 20);
while (p)
{
	if (strcmp(p->data.symbol, n) == 0)
	{
	printf("%d年\t%s\t%s\t%d人\n", p->data.date, p->data.name, p->data.symbol, p->data.people);
	}
	p = p->next; 
}
if (!pt) { printf("找不到该数据"); exit(0); }
}
void update_list(LinkList* L)
{
	Lnode* p = (*L)->next;
	Lnode* pt = *L;
	party* x = (party*)malloc(sizeof(party));
	printf("请输入年份:");
	scanf_s("%d", &x->date);
	printf("请输入会名：");
	scanf_s("%s", x->name, 20);
	printf("请输入代表名：");
	scanf_s("%s", x->symbol, 20);
	printf("请输入人数：");
	scanf_s("%d", &x->people);
	while (p)
	{
		if (p->data.date== x->date)
		{
			p->data = *x;
		}
		p = p->next;
	}
	if (!pt) { printf("找不到该数据"); exit(0); }
	print(L);
}
void free_all(LinkList* L)
{
	LinkList p = (*L)->next,q;
	while (p)
	{
		q = p->next;
		free(p);
		p = q;
	}
	(*L)->next = NULL;
	print(L);
}
int main()
{
	int num;
	LinkList* L = (LinkList*)malloc(sizeof(LinkList));
	*L = (LinkList)malloc(sizeof(Lnode));
	(*L)->next = (LinkList)malloc(sizeof(Lnode));
	list_create(L);
	printf("请输入你的操作：\n1 插入\n2 查找\n3 修改\n4 清空");
	scanf_s("%d", &num);
	if (num == 1)insert_list(L);
	if (num == 2)check_list(L);
	if (num == 3)update_list(L);
	if (num == 4)free_all(L);

}