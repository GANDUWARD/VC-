#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE 50
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
	scanf_s("%s", L->data->name,20);
	printf("请输入分数:(输入999退出)");
	scanf_s("%d", &num);
	if (num == 999) { L->data = NULL; }
	else
		do
		{
			L->data->score = num;
			L->data++; L->length++;
			printf("请输入姓名：");
			scanf_s("%s", L->data->name,20);
			printf("请输入分数:(输入999退出)");
			scanf_s("%d", &num);
			if (num == 999) { L->data->score = num; break; }
		} while (1);
		return p;
}
void print(STD*head,Sqlist *L)      /*学生列表的打印*/
{   
	int i=0;
	while (head[i].score != 999 &&i-1<=L->length)
	{
		printf("%s\t%d\n", head[i].name, head[i].score);
		i++;
	};
	exit(0);
}
int main()
{
	Sqlist* L; STD* p;    /*初始化指针L与头指针head*/
	L = (Sqlist*)malloc(sizeof(Sqlist));   /*为L分配空间*/ 
	L = create(L);     
	p = L->data;
	p = write_in(L);
	print(p,L);
} 
