#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#define MAXSIZE 50
#define maxlen  30
#define EQ(a,b)    (!strcmp((a),(b)))
#define LQ(a,b)    (strcmp((a),(b))<0)
#define RQ(a,b)     (strcmp((a),(b))>0)
typedef struct
{
	char **elem;
	int length;
	int size;
}SSTable;
typedef struct
{
	int firstplace[MAXSIZE];
	char max[MAXSIZE][maxlen];
	int length;
	int count;
}IndexTable;
int InitIndex(SSTable* S,IndexTable*I)
{
	if (S->length == 0)return 0;
	int count = sqrt(S->length);//确认每组个数
	int ax; I->count = count; I->length = S->length / count;
	for (int k = 0; k < I->length; k++)
	{   
		ax = k * count+1;
		I->firstplace[k] = ax;
		strcpy_s(I->max[k], maxlen+1, S->elem[ax+I->count]); //修改该组的max值
	}
	return 1;
}
int Inittable(SSTable* S)
{   
	S->size = MAXSIZE;
	S->length = 0;
	return 1;
}
int write_in(SSTable* S)
{   
	printf("请输入你要储存的数据个数:");
	scanf_s("%d", &S->length);
	S->elem = (char**)malloc(sizeof(char*) * (S->length + 1));
	printf("请输入数据(用空格隔开)");  //从1号开始储存
	for (int i = 1; i < S->length + 1; i++)
	{   
		S->elem[i] = (char*)malloc(sizeof(char) * (maxlen + 1));
		scanf_s("%s", S->elem[i],maxlen);
	}
	return 1;
}
int print(SSTable* S)
{   
	if (S->length == 0)return 0;
	for (int i = 1; i < S->length + 1; i++)
		printf("%s ", S->elem[i]);
	return 1;
}
int swap(SSTable*S)
{   
	char t[maxlen];
	if (S->length == 0)return 0;
	for(int i=1;i<S->length;i++)
		for (int j = i; j < S->length; j++)
		{
			if (RQ(S->elem[j], S->elem[j + 1]))
			{
				strcpy_s(t, S->elem[j]);
				strcpy_s(S->elem[j],maxlen+1, S->elem[j + 1]);
				strcpy_s(S->elem[j + 1],maxlen+1, t);
			}
		}
	return 1;
}
int Sqfind(SSTable*S)
{
	if (S->length == 0)
	{
		printf("表为空!\n");
		return 0;
	}
	char k[maxlen]; int i;
	printf("请输入你想要查找的值:");
	scanf_s("%s", k,maxlen);
	S->elem[0] = (char*)malloc(sizeof(char) * (maxlen + 1));
	strcpy_s(S->elem[0],maxlen+1, k);
	for (i = S->length; i > 0; i--)
	{
		if (EQ(S->elem[i], k))
		{
			printf("找到了%s，是第%d号记录！\n", S->elem[i],i);
			break;
		}
	}
	if (i == 0)printf("没找到!\n");
	return 1;
}
int Binary_lookup(SSTable* S,char k[],int low,int high)
{   
	int mid = (low + high) / 2;
	if (EQ(S->elem[mid], k))
	{
		printf("找到了%s，是第%d号记录！\n", S->elem[mid], mid);
		return 1;
	}
	if (LQ(k, S->elem[mid]))
	{
		Binary_lookup(S, k, low, mid);
	}
	if (RQ(k, S->elem[mid]))
	{
		Binary_lookup(S, k, mid, high);
	}
	else
		printf("没找到!\n");
	return 1;
}
int Index_lookup(SSTable* S)
{
	if (S->length == 0)return 0;
	IndexTable* I = (IndexTable*)malloc(sizeof(IndexTable));
	InitIndex(S, I);
	char k[maxlen]; int i; int find = 0;
	printf("请输入你想要查找的值:");
	scanf_s("%s", k, maxlen);
	for (int j = 0; j < I->length; j++)
	{
		if (LQ(k, I->max[j]))
		{
			for (int l = I->firstplace[j]; l < I->firstplace[j] + I->count; l++)
			{
				if (EQ(S->elem[l], k))
				{
					printf("找到了%s，是第%d号记录！\n", S->elem[l], l);
					find = 1;
					return 1;
				}
			}
		}
		if (EQ(k, I->max[j]))
		{
			printf("找到了%s，是第%d号记录！\n", S->elem[I->firstplace[j]+I->count], I->firstplace[j] + I->count);
			find = 1;
			return 1;
		}
	}
	if(!find)printf("没找到!\n");
	return 1;
}
int main()
{  
	int num;
	SSTable* S=(SSTable*)malloc(sizeof(SSTable));
	Inittable(S);
	write_in(S);
	while (1)
	{   
		system("cls");
		printf("表元素:");
		print(S);
		printf("请输入你的操作:1 排序2 顺序查找3 二分查找4 索引查找\n");
		scanf_s("%d", &num);
		if (num == 1)
		{
			swap(S);
		}
		if (num == 2)
		{
			Sqfind(S);
		}
		if (num == 3)
		{   
			if (S->length == 0)
			{
				printf("表为空!\n");
				return 0;
			}
			else
			{   
				swap(S);//先进行从小到大排序
				char k[maxlen]; int i;
				printf("请输入你想要查找的值:");
				scanf_s("%s", k, maxlen);
				Binary_lookup(S, k,1,S->length);
			}
		}
		if (num == 4)
		{
			swap(S);//先进行从小到大排序
			Index_lookup(S);
		}
		printf("\n按任意键退出!\n");
		getchar(); getchar();
	}
	return 0;
}