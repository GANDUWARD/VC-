#include<stdio.h>
#include<string.h>
#include<stdlib.h>
typedef struct
{
	char name[20];
	int number;
}STD;
typedef struct node
{
	STD data;
	node* next;
}Lnode, * LinkList;
int print(LinkList* L);
int initCirLink(LinkList* L)
{
	*L = (LinkList)malloc(sizeof(Lnode));
	if (*L == NULL)exit(0);
	(*L)->next = *L;
	return 1;
}
int write_in(LinkList* L)
{   
	int num; 
	Lnode* p = (LinkList)malloc(sizeof(Lnode));  //为工作指针p分配空间
	Lnode* q;
	p->next = (*L)->next; p=(*L);      //将工作指针p作为头节点插入L
	if (*L == 0) { printf("表为空"); exit(0); }
	else
	{
		printf("请输入号数(0退出)");
		scanf_s("%d", &num);
		if (num != 0)
			while (1)
			{  
				p->data.number = num;
				printf("请输入姓名:");
				scanf_s("%s",p->data.name, 20);
				printf("请输入号数(0退出):");
				scanf_s("%d", &num);
				if (num == 0)
				{
					p->next = *L; break;
				}
				else
				{   q= (LinkList)malloc(sizeof(Lnode));
				    q->next = p->next; p->next = q;
					p = p->next;
				}
			}
		print(L);
		return 1;
	}
}
int print(LinkList*L)
{
	Lnode* p = (*L);//工作指针p指向头节点
	while (p != NULL)
	{
		printf("%d\t%s\n", p->data.number, p->data.name);
		p = p->next;
		if (p == (*L))break;//如果重新回到头节点，停止打印
	}
	return 1;
}
Lnode* find_last(LinkList* L)
{
	Lnode* p = *L;
	while (1)
	{
		p = p->next;
		if (p->next == *L)break;
	}
	return p;
}
int calculate_length(LinkList* L)
{
	int i=1;
	Lnode* p = (*L)->next;
	while (1)
	{
		i++;
		p = p->next;
		if (p == *L)break;
	}
	return i;
}
int insert_list(LinkList* L)
{
	STD x;  int num,l,i=0;
	Lnode* p = *L;
	Lnode* q = (LinkList)malloc(sizeof(Lnode));
	printf("请输入号数：");
	scanf_s("%d", &x.number);
	printf("请输入姓名：");
	scanf_s("%s", x.name, 20);
	printf("请输入位置:");
	scanf_s("%d", &num);
	l = calculate_length(L);
	if (num > l + 1|| num < 1) { printf("插入位置有误"); exit(0); } //判断条件可以用循环累加i后的值不等于num替代（i>num-1||i<num+1)
	while (1)
	{
		if (i == num - 2) { q->data = x; q->next = p->next; p->next = q; break; }
		p = p->next; i++;
		if (p == *L)break;
	}
	print(L);
	return 1;
}
int delete_list(LinkList* L)
{
	char name[20];
	Lnode* pt = *L;
	Lnode* p = (*L)->next;     //p为头节点后的第一结点;
    Lnode* q;
	printf("请输入要删除的学生姓名：");
	scanf_s("%s", name, 20);
	while (1)
	{
		if (strcmp(name, p->data.name) == 0)
		{
			if (p == *L) { *L = p->next;}
				pt->next = p->next; p->next = NULL;   break;
		}
		p = p->next; pt = pt->next;
		if (pt == *L) { printf("找不到该生！"); return 0; }
	}
	print(L);
	return 1;
}
int main()
{   
	int n;
	LinkList* L = (LinkList*)malloc(sizeof(LinkList));
	* L = (LinkList)malloc(sizeof(Lnode));
	initCirLink(L);
	write_in(L);
	printf("请输入你的操作：1 插入\n2 删除\n");
	scanf_s("%d", &n);
	if (n == 1)insert_list(L);
	if (n == 2)delete_list(L);
}