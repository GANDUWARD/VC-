#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAXSIZE (10)
#define SIZE (100)
#define XXX   (999)
/*
8,8
北京
赤峰
大同
济南
石家庄
沈阳
太原
天津
大同
太原
北京
石家庄
北京
太原
北京
天津
北京
赤峰
天津
沈阳
天津
济南
石家庄
济南
1
北京
大同
2
赤峰
大同
3
4
*/
typedef struct
{
	int arcs[MAXSIZE][MAXSIZE];
	int VexNum, ArcNum;
	char* Vex[MAXSIZE];
}Graph,*MGraph;
typedef struct node
{ 
	int place;
	struct node* nextarc;
}side,*arc;
typedef struct
{
	char* data;
	int count;
	arc FirstArc;
}Vex;
typedef struct
{
	Vex adjlist[MAXSIZE];
	int ArcNum, VexNum;
}table,*ALGraph;
int find_place(MGraph* M,char s[])
{   
	int p = XXX;
	for (int i = 0; i < (*M)->VexNum; ++i)
	{
		if (strcmp((*M)->Vex[i], s) == 0)
		{
			p = i; break;
		}
	}
	return p;
}
int write(MGraph* M)
{
	do
	{
		printf("请输入边数和顶点数：(用逗号隔开)");
		scanf_s("%d,%d", &(*M)->ArcNum, &(*M)->VexNum);
		if ((*M)->ArcNum > 0 && (*M)->ArcNum < ((*M)->VexNum - 1) * (*M)->VexNum && (*M)->VexNum>0)break;
		else
			printf("输入有误！请重新输入\n");
	} while (1);
	for (int i = 0; i < (*M)->VexNum; ++i)
	{
		printf("请输入%d号顶点值:",i+1);
		(*M)->Vex[i] = (char*)malloc(sizeof(char) * SIZE);
		scanf_s("%s", (*M)->Vex[i], SIZE);
	}
	for(int i=0;i<(*M)->VexNum;++i)
		for (int j = i; j < (*M)->VexNum; ++j)
		{
			if (i == j)(*M)->arcs[i][j] = (*M)->arcs[j][i] = 0;
			else
				(*M)->arcs[i][j] = (*M)->arcs[j][i] = XXX;
		}
	for (int i = 0; i < (*M)->ArcNum; ++i)
	{   
		char p1[SIZE], p2[SIZE];
		printf("请输入第%d个边起始站1：",i+1); scanf_s("%s", p1, SIZE);
		printf("请输入第%d个边终点站2:",i+1); scanf_s("%s", p2, SIZE);
		int u1 = find_place(M, p1); int u2 = find_place(M, p2);
		(*M)->arcs[u1][u2] = (*M)->arcs[u2][u1] = 1;
	}
	return 1;
}
int out_put_Matrix(MGraph* M)
{
	printf("\n邻接矩阵如下:\n");
	for (int i = 0; i < (*M)->VexNum; ++i)
	{
		for (int j = 0; j < (*M)->VexNum; ++j)
		{
			printf("%d ", (*M)->arcs[i][j]);
		}
		printf("\n");
	}
	return 1;
}
int add_arc(MGraph* M)
{
	char p1[SIZE], p2[SIZE];
	printf("请输入起始站1："); scanf_s("%s", p1, SIZE);
	printf("请输入终点站2:"); scanf_s("%s", p2, SIZE);
	int u1 = find_place(M, p1); int u2 = find_place(M, p2);
	(*M)->arcs[u1][u2] = (*M)->arcs[u2][u1] = 1;
	(*M)->ArcNum++;
	return 1;
}
int find(MGraph* M, int u1, int u2,int *judge,int v[])
{
	if ((*M)->arcs[u1][u2] == 1)*judge = 1;
	for (int i = 0; i < (*M)->VexNum; ++i)
	{
		if ((*M)->arcs[u1][i] == 1 && v[i] == 0)
		{
			v[i] = 1; find(M, i, u2, judge, v);
		}
	}
	return 1;
}
int find_accessibility(MGraph* M)
{
	char p1[SIZE], p2[SIZE];
	printf("请输入起始站1："); scanf_s("%s", p1, SIZE);
	printf("请输入终点站2:"); scanf_s("%s", p2, SIZE);
	int u1 = find_place(M, p1); int u2 = find_place(M, p2);
	int* judge = new int; *judge = 0; int v[MAXSIZE] = { 0 };
	find(M, u1, u2, judge,v);
	if (*judge == 1)
		printf("可达！\n");
	else
		printf("不可达!\n");
	return 1;
}
int create_table(MGraph* M,ALGraph*AL)
{
	(*AL)->VexNum = (*M)->VexNum; (*AL)->ArcNum = (*M)->ArcNum;
	for (int i = 0; i < (*M)->VexNum; ++i)
	{
		(*AL)->adjlist[i].data = (*M)->Vex[i];
		(*AL)->adjlist[i].count = 0;
		(*AL)->adjlist[i].FirstArc = nullptr;
	}
	for(int i=0;i<(*M)->VexNum;++i)
		for (int j = i; j < (*M)->VexNum; ++j)
		{
			if ((*M)->arcs[i][j] == 1)
			{
				arc p1 = new side; arc p2 = new side;
				p1->place = j;
				p1->nextarc = (*AL)->adjlist[i].FirstArc; (*AL)->adjlist[i].FirstArc = p1;
				p2->place = i;
				p2->nextarc = (*AL)->adjlist[j].FirstArc; (*AL)->adjlist[j].FirstArc = p2;
				++(*AL)->adjlist[i].count; ++(*AL)->adjlist[j].count;
			}
		}
	for (int i = 0; i < (*AL)->VexNum; ++i)
	{
		arc q = (*AL)->adjlist[i].FirstArc;
		printf("%s-->", (*AL)->adjlist[i].data);
		while (q)
		{   
			printf("%d|%s-->",q->place,(*AL)->adjlist[q->place].data);
			q = q->nextarc;
		}
		printf("|owo|\n");
	}
	return 1;
}
int output_centercity(ALGraph* AL)
{
	int max = 0;
	for (int i = 0; i < (*AL)->VexNum; ++i)
	{
		if ((*AL)->adjlist[i].count > (*AL)->adjlist[max].count)max = i;
	}
	printf("交通最发达的城市是%s\n", (*AL)->adjlist[max].data);
	return 1;
}
int main()
{
	MGraph* M = new MGraph; *M = new Graph;
	write(M);
	out_put_Matrix(M);
	ALGraph* AL = new ALGraph; *AL = new table;
	while (1)
	{   
		/*system("cls");*/
		printf("请输入你的操作：1 增加新边2 判断可达3 输出邻接表4 输出交通枢纽\n"); int num;
		scanf_s("%d", &num);
		if (num == 1)add_arc(M);
		if (num == 2)find_accessibility(M);
		if (num == 3)create_table(M, AL);
		if (num == 4)output_centercity(AL);
	}
	return 1;
}