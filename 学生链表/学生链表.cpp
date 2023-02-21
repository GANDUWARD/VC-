#include<stdio.h>
#include<string.h>
#include<stdlib.h>
typedef struct
{   
	int num;
	char name[20];
	char sex[4];
	int score;
}STD;
typedef struct Node
{
	STD data;
	struct Node* next;
}node,*linklist;

void print(node* head);
void list_create(node* head)
{
	node* p; int number;
	head->next = (node*)malloc(sizeof(node));
	p = head->next;
	printf("请输入号数：(0退出)");
	scanf_s("%d", &number);
	if (number != 0)
	{
		while (1)
		{
			p->data.num = number;
			printf("请输入姓名：");
			scanf_s("%s", p->data.name, 20);
			printf("请输入性别：");
			scanf_s("%s", p->data.sex, 4);
			printf("请输入分数：");
			scanf_s("%d", &p->data.score);
			printf("请输入号数:(0退出)");
			scanf_s("%d", &number);
			if (number == 0) { p->next = NULL; break; }
			else
			{
				p->next = (node*)malloc(sizeof(node));
				p = p->next;
			}
		}
	}
}
void print(node* head)
{
	node* p = head->next;
	if (p == NULL) { printf("空列表"); }
	else
		while (p != NULL)
		{
			printf("%d\t%s\t%s\t%d\n", p->data.num, p->data.name, p->data.sex, p->data.score);
			p = p->next;
		}
}
int calculate_length(node* L)
{
	int i=0;
	node*p = L->next;
	while (p != NULL)
	{   
		i++;
		p = p->next;
	}
	return i;
}
void insert_list(node* head)
{   
	int n,l=calculate_length(head),i=1;
	node* p = head->next;
	node* pt = head;
	STD* x = (STD*)malloc(sizeof(STD));
	printf("请输入你要插入的位置：");
	scanf_s("%d", &n);  //将位置序号赋值给a
	if (n > l && n < 0) 
	{
		printf("插入位置有误"); exit(0);
	}
	else
	{
		x->num = n;
		printf("请输入姓名：");
		scanf_s("%s", x->name, 20);
		printf("请输入性别：");
		scanf_s("%s", x->sex, 4);
		printf("请输入分数：");
		scanf_s("%d", &x->score);
	}
	while (p != NULL&&i<=l ) //遍历且位序小于l
	{
		if(i==n)
		{
			node* t = (node*)malloc(sizeof(node));
			t->data = *x;
			pt->next = t; t->next = p;  //插入操作
			break;
		}
		p = p->next; pt = pt->next; i++;	
	}
	while (p != NULL) { p->data.num++; p = p->next; pt = pt->next; }
}
int delete_list(node* head)
{   
	node* p = head->next;
	node* pt = head;
	STD* x=(STD*)malloc(sizeof(STD));
	char n[20];
	printf("请输入你要删除的（名字）");
	scanf_s("%s", n, 20);
	while(p)
	{  
		if (strcmp(p->data.name, n) == 0) 
		{ 
			pt->next = p->next; p->next = NULL; p->data = *x; free(p);//注意，free的地址一定是不能改动的地址
			while (pt->next != NULL) { pt->data.num--; pt = pt->next; } break;
		}
		p = p->next; pt = pt->next;
	}
	if (!pt) { printf("找不到该生"); return 0; }
	return 1;
}
void find_data(node* head)
{
	node* p = head->next;
	char n[20];
	printf("请输入你要查找的（名字）");
	scanf_s("%s", n, 20);
	while (p != NULL)
	{
		if (strcmp(p->data.name, n) == 0) { printf("%d\t%s\t%s\t%d\n", p->data.num, p->data.name, p->data.sex, p->data.score); break; }
		p = p->next; 
	}
	if (!p) { printf("找不到该生"); exit(0); }
}
void inverLink(node* head)
{
	node *p = head;
	node* q;
	p = p->next;
	head->next = NULL;
	while (p)
	{
		q = p->next;
		p->next = head->next;
		head->next = p;
		p = q;
	}
	print(head);
	
}
int sort(linklist head)
{
	linklist p = head->next;
	while (p->next)
	{
		linklist min = p; linklist q = p; STD t;
		while (q)
		{
			if (q->data.num < min->data.num)min = q;
			q = q->next;
		}
		t = p->data; p->data = min->data; min->data = t;
		p = p->next;
	}
	return 1;
}
int intergrate(linklist head, linklist head2)//相当于遍历表一表二，将表二拆开，插入到表一合适位置
{
	linklist p = head->next; linklist q = head2->next; linklist pt = p->next;
	while (pt && q)
	{   
		if (pt->data.num < q->data.num)p = p->next;
		else
		{  
			linklist r = q; q = r->next; p->next = r; r->next = pt;
		}
		p = pt; pt = p->next;
	}
	if (!pt&&q)p->next = q;
	return 1;
}
int main()
{
	int num;
	node* head=(node *)malloc(sizeof(node));
	list_create(head);
	while (1)
	{   
		system("cls");
		print(head);
		printf("请执行你的操作:1 插入\n2 删除\n3 查找\n4 逆置5 有序归并\n");
		scanf_s("%d", &num);
		if (num == 1)insert_list(head);
		if (num == 2)delete_list(head);
		if (num == 3)find_data(head);
		if (num == 4)inverLink(head);
		if (num == 5)
		{
			linklist head2 = new node; list_create(head2); 
			sort(head); 
			sort(head2);
			intergrate(head, head2);
		}
		printf("按任意键继续!\n");
		getchar(); getchar();
	}
	return(1);
}
/*
1
1
1
1
3
3
3
3
5
5
5
5
7
7
7
7
2
2
2
2
4
4
4
4
6
6
6
6
8
8
8
8

*/