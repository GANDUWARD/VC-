#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
	int data;
	struct node* pre;
	struct node* next;
}Dnode,*DLinkList;
int Init_list(DLinkList* L)
{
	if (*L == NULL) { printf("空链表"); return 0; }
	(*L)->next = (*L)->pre = (*L);
	printf("链表创建成功！\n");
	return 1;
}
int print(DLinkList* L)
{
	if ((*L)->next == (*L)->pre && (*L)->pre == *L) { printf("空链表！"); return 0; }
	Dnode* p = (*L)->next;
	while (p != *L)
	{
		printf("%d ", p->data);
		p = p->next;
	}
}
int write_in(DLinkList* L)
{
	int number; Dnode* p=(DLinkList)malloc(sizeof(Dnode));
	p->pre = p->next = *L; (*L)->next = p;
	printf("请输入数字：(999退出)");
	scanf_s("%d", &number);
	if (number != 999)
	{
		while (1)
		{
			p->data = number;
			printf("请输入数字：(999退出)");
			scanf_s("%d", &number);
			if (number == 999) { p->next = *L; break; }
			else
			{   
				p->next = (DLinkList)malloc(sizeof(Dnode));
				p->next->next = *L;  p->next->pre = p;
			    p = p->next; 
			}
		}
	}
	print(L);
	return 1;
}
int find_data(DLinkList* L)
{
	if ((*L)->next == (*L)->pre && (*L)->pre == *L) { printf("空链表！"); return 0; }
	Dnode* p = (*L)->next; int num,i=1;
	printf("请输入查找的数字:");
	scanf_s("%d", &num);
	while (1)
	{
		if (p->data == num) { printf("找到了，在%d个", i); break; }
		if (p == *L) { printf("找不到该数"); return 0; }
		i++; p = p->next;
	}
}
int find_length(DLinkList* L)
{
	if ((*L)->next == (*L)->pre && (*L)->pre == *L) { printf("空链表！"); return 0; }
	Dnode* p = (*L)->next; int i = 1;
	while (p != *L)
	{
		p = p->next; i++;
	}
	return i;
}
int insert_data(DLinkList* L)
{
	if ((*L)->next == (*L)->pre && (*L)->pre == *L) { printf("空链表！"); return 0; }
	Dnode* p = (*L)->next; Dnode* pt = p->pre; int num, i = 1, pos;
	printf("请输入你要插入的数:");
	scanf_s("%d", &num);
	printf("请输入你要插入的位置:");
	scanf_s("%d", &pos);
	if (pos >= find_length(L) || pos < 0) { printf("位置有误！"); return 0; }
	while (p != *L)
	{
		if (i == pos) 
		{ 
			pt->next = (DLinkList)malloc(sizeof(Dnode)); pt->next->data = num;
			p->pre = pt->next; pt->next->pre = pt; pt->next->next = p; 
			pt = pt->next;
		}
		i++;pt = pt->next; p = p->next;
	}
	print(L);
	return 1;
}
int delete_data(DLinkList* L)
{
	if ((*L)->next == (*L)->pre && (*L)->pre == *L) { printf("空链表！"); return 0; }
	Dnode* p = (*L); Dnode* pt = p->pre; int pos, i = 1; Dnode* q=(DLinkList)malloc(sizeof(Dnode));
	printf("请输入删除的位置:");
	scanf_s("%d", &pos);
	if (pos >= find_length(L) || pos < 0) { printf("位置有误！"); return 0; }
	while (1)
	{
		if (i == pos) 
		{ 
			q = p->next; p->next = q->next;
			q->next->pre = p; q->next = NULL; q->pre = NULL; free(q);
			break;
		}
		i++; p = p->next; pt = pt->next; 
	}
	print(L);
	return 1;
}
int main()
{   
	int n;
	DLinkList* L = (DLinkList*)malloc(sizeof(DLinkList));
	*L = (DLinkList)malloc(sizeof(Dnode));
	Init_list(L);
	write_in(L);
	printf("\n请执行你的操作:\n1 查找\n2 插入\n3 删除");
	scanf_s("%d", &n);
	if (n == 1)find_data(L);
	if (n == 2)insert_data(L);
	if (n == 3)delete_data(L);
}