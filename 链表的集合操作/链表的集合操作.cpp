#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
	int data;
	struct node* next;
}Dnode, * DLinkList;
int menu(DLinkList* L, DLinkList* L2);
int return_menu(DLinkList* L, DLinkList* L2);
int Init_list(DLinkList* L)
{
	if (*L == NULL) { printf("空链表"); return 0; }
	(*L)->next = NULL;
	printf("链表创建成功！\n");
	return 1;
}
int print(DLinkList* L)
{
	if ((*L)== NULL ) { printf("空链表！"); return 0; }
	Dnode* p = (*L)->next;
	while (p != NULL)
	{
		printf("%d ", p->data);
		p = p->next;
	}
}
int write_in(DLinkList* L)
{
	int number; Dnode* p = (DLinkList)malloc(sizeof(Dnode));
      (*L)->next=p;
	printf("请输入数字：(999退出)");
	scanf_s("%d", &number);
	if (number != 999)
	{
		while (1)
		{
			p->data = number;
			printf("请输入数字：(999退出)");
			scanf_s("%d", &number);
			if (number == 999) { p->next = NULL; break; }
			else
			{
				p->next = (DLinkList)malloc(sizeof(Dnode));
				p->next->next = NULL; 
				p = p->next;
			}
		}
	}
	printf("链表如下：");
	print(L);
	printf("\n");
	return 1;
}
int clean_all(DLinkList* L)
{
	DLinkList p = (*L)->next, q;
	while (p)
	{
		q = p->next;
		free(p);
		p = q;
	}
	(*L)->next = NULL;
	if ((*L)->next == NULL)
	{
		printf("空链表");
		return 0;
	}
	return 1;
}
int calculate_length(DLinkList* L)
{   
	int i=0;
	Dnode* p = (*L)->next;
	if (!p)return 0;
	while (p != NULL)
	{
		i++; p = p->next;
	}
	return i;
}
int common(DLinkList* L,DLinkList*L2)
{   
	Dnode* p1 = (*L)->next; Dnode* p2 = (*L2)->next;
	printf("交集链表如下：");
	while (p1 != NULL)
	{
		p2 = (*L2)->next;
		while (p2 != NULL)
		{
			if (p1->data == p2->data)printf("%d ", p1->data);
			p2 = p2->next;
		}
		p1 = p1->next;
	}
	return_menu(L, L2);
	return 1;
}
int sum(DLinkList* L,DLinkList*L2)
{
	Dnode* p1 = (*L)->next; Dnode* p2 = (*L2)->next;
	printf("\n并集链表如下:");
	while (p1 != NULL && p2 != NULL)  //1,2都不为空，就把他们相等的部分一一匹配显示
	{   
		if (p1->data == p2->data) { printf("%d ", p2->data); p1 = p1->next; p2 = p2->next; continue; }
		printf("%d ", p1->data);
		p1 = p1->next;
	}
	if(p1 == NULL && p2 != NULL)//1空，2未空，就将2的剩下元素与1的所有元素比较，若无相同的，则显示
	{
		while (p2!=NULL)
		{
			p1 = (*L)->next;
			while (p2 != NULL && p1 != NULL)
			{
				if (p1->data == p2->data) { p2 = p2->next; break; }
				p1 = p1->next;
			}
			if (p1 == NULL)
			{
				printf("%d ", p2->data); p2 = p2->next;
			}
		}
		return 1;
	}
	if(p2 == NULL && p1 != NULL)//2空，1未空，就将1的剩下元素与2的所有元素比较，若无相同的，则显示
	{   
		while (p1!=NULL)
		{
			p2 = (*L2)->next;
			while (p2 != NULL && p1 != NULL)
			{
				if (p1->data == p2->data) { p1 = p1->next; break; }
				p2 = p2->next;
			}
			if (p2 == NULL)
			{
				printf("%d ", p1->data);
				p1 = p1->next;
			}
		}
	}
	return_menu(L, L2);
}
int deduct(DLinkList* L,DLinkList *L2)
{
	Dnode* p1 = (*L)->next; Dnode* p2 = (*L2)->next;
	printf("差集链表如下：");
	while (p1 != NULL)
	{
		p2 = (*L2)->next;
		while (p2 != NULL)
		{
			if (p1->data == p2->data)break;
			p2 = p2->next;
		}
		if (p2 == NULL)printf("%d ", p1->data);
		p1 = p1->next;
	}
	return_menu(L, L2);
	return 1;
}
int insert_data(DLinkList* L, DLinkList* L2)
{
	if ((*L)==NULL) { printf("空链表！"); return 0; }
	Dnode* p = (*L)->next; Dnode* pt =*L; int num, i = 1, pos;
	printf("请输入你要插入的数:");
	scanf_s("%d", &num);
	printf("请输入你要插入的位置:");
	scanf_s("%d", &pos);
	if (pos > calculate_length(L) || pos < 0) { printf("位置有误！"); return 0; }
	while (p != NULL)
	{
		if (i == pos)
		{
			pt->next = (DLinkList)malloc(sizeof(Dnode)); pt->next->data = num;
		    pt->next->next = p;
			pt = pt->next;
		}
		i++; pt = pt->next; p = p->next;
	}
	print(L);
	return_menu(L, L2);
	return 1;
}
int delete_data(DLinkList* L,DLinkList *L2)
{
	if ((*L) == NULL) { printf("空链表！"); return 0; }
	int num;
	Dnode* p = (*L)->next; Dnode* pt = *L;  Dnode* q = (DLinkList)malloc(sizeof(Dnode));
	printf("请输入删除的数:");
	scanf_s("%d", &num);
	while (p->next != NULL)
	{
		if (p->next->data == num)
		{
			q = p->next; p->next = q->next;
			q->next = NULL; free(q);
			break;
		}
		p = p->next; pt = pt->next;
	}
	if (p->next == NULL) { printf("找不到该数!"); return 0; }
	print(L);
	return_menu(L, L2);
	return 1;
}
int menu(DLinkList*L,DLinkList*L2)
{    
	printf("\n请执行你对集合的操作：\n1 清空\n2 交集\n3 插入\n4 删除\n5 并集\n6 差集\n");
	int n;
	scanf_s("%d", &n);
	if (n == 1)clean_all(L);
	if (n == 2)common(L,L2);
	if (n == 3)insert_data(L,L2);
	if (n == 4)delete_data(L,L2);
	if (n == 5)sum(L,L2);
	if (n == 6)deduct(L,L2);
	return 1;
}
int return_menu(DLinkList* L, DLinkList* L2)
{   
	int n;
	printf("请执行要哪个集合操作：(该集合（1）或另一个集合（2）");
	scanf_s("%d", &n);
	if (n == 1)
	{
		menu(L, L2);
	}
	if (n == 2)
	{
		menu(L2, L);
	}
	return 1;
}
int main()
{
	int n;
	DLinkList* L = (DLinkList*)malloc(sizeof(DLinkList));
	*L = (DLinkList)malloc(sizeof(Dnode));
	DLinkList* L2 = (DLinkList*)malloc(sizeof(DLinkList));
	*L2 = (DLinkList)malloc(sizeof(Dnode));
	printf("请输入集合1：\n");
	Init_list(L);
	write_in(L);
	printf("请输入集合2：\n");
	Init_list(L2);
	write_in(L2);
	return_menu(L, L2);
	return  1;
}
