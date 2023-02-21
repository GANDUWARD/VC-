#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAXSIZE 5
typedef struct
{
	char name[20];
	int score;
}STD;
typedef struct
{
	STD* data;
	int listsize;
	int length;
}Sqlist;
Sqlist* create(Sqlist* L)
{
	if (L != NULL)
	{
		L->data = (STD*)malloc(sizeof(STD) * MAXSIZE);   /*为data分配空间*/
		if (L->data == NULL) { printf("空间申请失败！"); return NULL; }
		L->listsize = MAXSIZE;  L->length = 0;   /*写入顺序表的容量长度*/
		printf("顺序表创建成功!");
		return L;
	}
}
STD* write_in(Sqlist* L)        /*学生列表写入*/
{
	int num; STD* p = L->data;
	printf("请输入姓名：");
	scanf_s("%s", L->data->name, 20);
	printf("请输入分数:(输入999退出)");
	scanf_s("%d", &num);
	if (num == 999) { L->data = NULL; }
	else
		do
		{
			L->data->score = num;
			L->data++; L->length++;
			printf("请输入姓名：");
			scanf_s("%s", L->data->name, 20);
			printf("请输入分数:(输入999退出)");
			scanf_s("%d", &num);
			if (num == 999) { L->data->score = num; L->length++; break; }
		} while (1);
		return p;
}
void print(Sqlist* L,STD *head)      /*学生列表的打印*/
{
	int i = 0;
	while (head[i].score != 999&& i< L->length-1 )
	{
		printf("%s\t%d\n",head[i].name, head[i].score);
		i++;
	};
}
void delete_data(Sqlist*L,STD *p)
{
	int x, i;
	STD* q = p;
	printf("请输入要删除第几个:");
	scanf_s("%d", &x);
	for (i = x-1; i < L->length-1; i++) { q[i].score = q[i+1].score; strcpy_s(q[i ].name, q[i+1].name); }
    L->length--;
	print(L, p);
}
void insert_list(Sqlist* L,STD *p)
{
	int i,x;
	STD* d = (STD*)malloc(sizeof(STD));    //先创建结构体d，用于储存插入的数据
	printf("请输入你要插入的位置:");
	scanf_s("%d", &x);
	if (x > L->length || x < 1) { printf("插入位置错误"); exit(0); }
	else
	{
		printf("请输入该生姓名:");
		scanf_s("%s", d->name, 20);
		printf("请输入该生分数：");
		scanf_s("%d", &d->score);
		for (i = L->length; i >= x; i--) { p[i] = p[i - 1]; }//从最后一个数据后面开始往前，i数据被i-1数据赋值
		p[x - 1] = *d; L->length++;   //插入数据d，长度加一
		print(L, p);
	}
}
void data_check(Sqlist* L, STD* p)
{   
	char name[20];
	int i=0;
	printf("请输入你要查找的学生");
	scanf_s("%s", name, 20);
	while (i < L->length) 
	{
		if (strcmp(p[i].name, name) == 0) { printf("%s\t%d\n", p[i].name, p[i].score); }//如果发现名字一样，就输出
		i++;
	}
}
void data_update(Sqlist* L, STD* p)
{
	int i=0; 
	STD* d = (STD*)malloc(sizeof(STD));    //先创建结构体d，用于储存更改的数据
	printf("请输入你要更改的学生");
	scanf_s("%s", d->name, 20);
	printf("请输入更改后的成绩");
	scanf_s("%d",&d->score);
	while (i < L->length)
	{
		if (strcmp(p[i].name, d->name) == 0) { p[i] = *d; printf("修改后数据如下:\n"); print(L, p); }
		i++;
	}
	
}
int main()
{   
	int n;
	Sqlist *L = (Sqlist*)malloc(sizeof(Sqlist));   /*为L分配空间*/
    L = create(L);
	STD* p = write_in(L);
	print(L,p);
	printf("请执行你的操作：\n1、删除\n2、插入\n3、查询\n4、更改");
	scanf_s("%d", &n);
	if (n == 1) { delete_data(L, p); }
	if (n == 2) { insert_list(L, p); }
	if (n == 3) { data_check(L, p); }
	if (n == 4) { data_update(L, p); }
}