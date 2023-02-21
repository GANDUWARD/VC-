#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAXSIZE 20
#define EQ(a,b) (!strcmp((a),(b)))
#define LQ(a,b) (strcmp((a),(b))<0)
#define RQ(a,b)  (strcmp((a),(b))>0)
typedef struct
{
	char* data[20];
	int length;
	int size ;
}List,*SqList;
int InitList(SqList* L)
{
	(*L) = (SqList)malloc(sizeof(List));
	(*L)->length = 0;
	(*L)->size = MAXSIZE;
	return 1;
}
int insert_and_sort(SqList* L, char*x)
{   
	int place = 0; int i = (*L)->length;
	if (i > MAXSIZE - 1)return 0;
	while (place<(*L)->length)
	{
		if (LQ(x, (*L)->data[place]))
			break;
		place++;
	}
	while (i > place)
	{
		(*L)->data[i] = (*L)->data[i-1];
		i--;
	}
	(*L)->data[i] = x; (*L)->length++;
	return 1;
}
int write_in(SqList* L)
{   
	int length;
	printf("请输入表长:\n");
	scanf_s("%d", &length);
	for (int i = 0; i < length; i++)
	{  
		char* x = (char*)malloc(sizeof(char) * 21);
		printf("请输入:");
		scanf_s("%s", x, 20);
		insert_and_sort(L, x);
	}
	return 1;
}
int print(SqList* L)
{   
	if ((*L)->length == 0)
	{
		printf("空表!\n"); return 0;
	}
	for (int i = 0; i < (*L)->length; i++)
		printf("%s ", (*L)->data[i]);
	return 1;
}
int delete_node(SqList* L)
{   
	if ((*L)->length == 0)
	{
		printf("空表!\n"); return 0;
	}
	char x[20]; int i = 0;
	printf("请输入你要删除的点:");
	scanf_s("%s", x, 20);
	while (i < (*L)->length)
	{   
		if (EQ(x, (*L)->data[i]))break;
		i++;
	}
	if (i == (*L)->length)printf("删除失败！未找到!\n");
	else
	{
		for (int j = i; j + 1 < (*L)->length; j++)
			(*L)->data[j] = (*L)->data[j + 1];
		(*L)->length--;
	}
	return 1;
}
int main()
{
	SqList* L = new SqList; InitList(L);
	write_in(L);
	print(L);
	delete_node(L);
	return 1;
}