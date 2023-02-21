#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define MAXSIZE 10
typedef struct
{
	int num;
	char name[20];
	char price[20];
}ElemType;
typedef struct
{
	ElemType* data;
	int length;
	int listsize;
}Sqlist;
Sqlist* create(Sqlist* L)
{
	if (L != NULL)
	{
		L->data = (ElemType*)malloc(sizeof(ElemType) * MAXSIZE);   /*为data分配空间*/
		if (L->data == NULL) { printf("空间申请失败！"); return NULL; }
		L->listsize = MAXSIZE;  L->length = 0;   /*写入顺序表的容量长度*/
		printf("顺序表创建成功!\n");
		return L;
	}
}
void menu(Sqlist* L);
void print(Sqlist* L)
{   
	system("cls");
	int i = 0;
	while (i < L->length)
	{
		printf("%d\t%s\t%s\n", L->data[i].num, L->data[i].name, L->data[i].price);
		i++;
	}
}
void write_in(Sqlist* L)
{    
	int i = 0;
	int num;
	printf("请输入号数(按0退出)");
	scanf_s("%d", &num);
	if (num != 0)
	 do
	{
		L->data[i].num = num;
		printf("请输入书名:");
		scanf_s("%s", L->data[i].name,20);
		printf("请输入价格：");
		scanf_s("%s", L->data[i].price, 20);
		i++; L->length++;
		printf("请输入号数(按0退出)");
		scanf_s("%d", &num);
	 } while (num != 0);
	 print(L);
}
void insert_list(Sqlist* L)
{
	int i,x;
	ElemType* d = (ElemType*)malloc(sizeof(ElemType));
	printf("请输入你要插入的位置：");
	scanf_s("%d", &x); d->num = x;
	if (x > L->length || x < 1) { printf("插入位置错误！"); }
	else
	{
		printf("请输入该书名称:");
		scanf_s("%s", d->name, 20);
		printf("请输入该书价格：");
		scanf_s("%s", d->price, 20);
		for (i = L->length; i >= x; i--) { L->data[i] = L->data[i - 1]; L->data[i].num++;}
		L->data[x - 1] = *d; L->length++; 
		print(L);
		menu(L);
	}
}
void delete_list1(Sqlist* L)
{
	int i,x,j,p=0; char n[20];
	printf("要删除哪本书:");
	scanf_s("%s", n, 20);
	for (i = 0; i < L->length; i++) 
	{
		if (strcmp(L->data[i].name, n) == 0) 
		{ 
			x = i; p = 1;
		for (j = x; j < L->length; j++) { L->data[j] = L->data[j + 1]; L->data[j].num--; }
		L->length--;
		}
	}
	if (p == 0) { printf("未找到\n"); exit(0); }
	print(L);
	menu(L);
}
void delete_list2(Sqlist* L)
{
	int x, i;
	printf("请输入要删除第几个:");
	scanf_s("%d", &x);
	for (i = x - 1; i < L->length - 1; i++) { L->data[i] = L->data[i + 1]; }
	L->length--;
	print(L);
	menu(L);
}
void check_list(Sqlist* L)
{
	int i,p=0; char n[20];
	printf("要查哪本书:");
	scanf_s("%s", n, 20);
	for (i = 0; i < L->length; i++)
	{
		if (strcmp(L->data[i].name, n) == 0)
		{   
			p = 1;
			printf("%d\t%s\t%s\n", L->data[i].num, L->data[i].name, L->data[i].price);
		}

	}
	if (p == 0) { printf("未找到\n"); exit(0); }
	menu(L);
}
void update_price(Sqlist* L)
{
	int i,p=0; char n[20]; char m[20];
	printf("要改哪本书:");
	scanf_s("%s", n, 20);
	printf("修改的价格为：");
	scanf_s("%s", m, 20);
	for (i = 0; i < L->length; i++)
	{
		if (strcmp(L->data[i].name, n) == 0)
		{   
			p = 1;
			strcpy_s(L->data[i].price, m);
		}
	}
	if (p == 0) { printf("未找到"); exit(0); }
	print(L);
	menu(L);
}
void menu(Sqlist* L)
{
	int a;
	printf("请操作:1 插入\n2 删除(按名称)\n3 删除(按号数)\n4 索引\n5 修改价格\n");
	scanf_s("%d", &a);
	system("cls");
	if (a == 1)insert_list(L);
	if (a == 2)delete_list1(L);
	if (a == 3)delete_list2(L);
	if (a == 4)check_list(L);
	if (a == 5)update_price(L);
}
int main()
{   
	int a;
	Sqlist* L = (Sqlist*)malloc(sizeof(Sqlist));
	L = create(L);
	write_in(L);
	menu(L);
}