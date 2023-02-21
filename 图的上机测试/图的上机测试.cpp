#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define MAXSIZE (10)
#define NONE (999)
/*
8
北京
太原
大同
天津
赤峰
石家庄
济南
沈阳
8
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

北京
大同

北京
大同
*/
typedef struct
{
	int arcs[MAXSIZE][MAXSIZE];
	int VexNum, ArcNum;
	char* Vexs[MAXSIZE];
}Graph,*MGraph;
typedef struct node
{
	int place;
	struct node* next;
}side,*arc;
typedef struct 
{
	char* data;
	arc firstarc;
	int count;
}adj;
typedef struct
{
	adj adjlist[MAXSIZE];
	int VexNum, ArcNum;
}G, * ALGraph;
typedef struct
{
	int data[MAXSIZE];
	int rear, front;
	int QueueSize;
}Queue,*SqQueue;
int InitQueue(SqQueue* Q)
{
	(*Q) = new Queue;
	(*Q)->front = (*Q)->rear = 0;
	(*Q)->QueueSize = MAXSIZE;
	return 1;
}
int EnQueue(SqQueue* Q, int x)
{
	(*Q)->data[(*Q)->rear] = x;
	(*Q)->rear = ((*Q)->rear + 1) % (*Q)->QueueSize;
	return 1;
}
int DeQueue(SqQueue* Q, int* x)
{
	*x=(*Q)->data[(*Q)->front];
	(*Q)->front = ((*Q)->front + 1) % (*Q)->QueueSize;
	return 1;
}
int find_position(MGraph* M, char s[])
{   
	int p = NONE;
	for (int i = 0; i < (*M)->VexNum; i++)
	{
		if (strcmp((*M)->Vexs[i], s) == 0)
		{
			p = i;
		}
	}
	return p;
}
int write_in(MGraph* M)
{
	printf("请输入顶点数:");
	scanf_s("%d", &(*M)->VexNum);
	for (int i = 0; i < (*M)->VexNum; ++i)
	{  
		printf("请输入顶点的值：");
		(*M)->Vexs[i] = (char*)malloc(sizeof(char) * 100);
		scanf_s("%s",(*M)->Vexs[i], 100);
	}
	do
	{
		printf("请输入边数:");
		scanf_s("%d", &(*M)->ArcNum);
		if ((*M)->ArcNum > 0 && (*M)->ArcNum <= (*M)->VexNum * ((*M)->VexNum - 1))
			break;
		else
			printf("边数有误!");
	} while (1);
	for (int i = 0; i < (*M)->VexNum; ++i)
	{
		for (int j = 0; j < (*M)->VexNum; ++j)
		{
			if (i == j)(*M)->arcs[i][j] = 0;
			else
				(*M)->arcs[i][j] = NONE;
		}
	}
	for (int i = 0; i < (*M)->ArcNum; ++i)
	{
		printf("请输入边:"); char a1[100], a2[100];
		scanf_s("%s", a1,100);
		scanf_s("%s", a2, 100);
		int v1 = find_position(M, a1),v2 = find_position(M, a2);
		(*M)->arcs[v1][v2] = (*M)->arcs[v2][v1] = 1;
	}
	return 1;
}
int add_arcs(MGraph* M)
{
	printf("请输入新边信息:"); char a1[100], a2[100];
	scanf_s("%s", a1, 100);
	scanf_s("%s", a2, 100);
	int v1 = find_position(M, a1), v2 = find_position(M, a2);
	(*M)->arcs[v1][v2] = (*M)->arcs[v2][v1] = 1;
	++(*M)->ArcNum;
	return 1;
}
int create_and_output_table(MGraph* M,ALGraph*AL)
{ 
	(*AL)->ArcNum = (*M)->ArcNum; (*AL)->VexNum = (*M)->VexNum;
	for (int i = 0; i < (*AL)->VexNum; ++i)
	{
		(*AL)->adjlist[i].data = (*M)->Vexs[i];
		(*AL)->adjlist[i].count = 0;
		(*AL)->adjlist[i].firstarc = NULL;
	}
	for (int i = 0; i < (*M)->VexNum; ++i)
		for (int j = i; j < (*M)->VexNum; ++j)
		{
			if ((*M)->arcs[i][j] != 0 && (*M)->arcs[i][j]!=NONE)
			{    
				arc q = new side; q->next = (*AL)->adjlist[i].firstarc;
				q->place = j;
				arc p = new side;p->next = (*AL)->adjlist[j].firstarc;
				p->place = i;
				(*AL)->adjlist[i].firstarc = q; (*AL)->adjlist[j].firstarc = p;
				(*AL)->adjlist[i].count++; (*AL)->adjlist[j].count++;
			}
		}
	for (int i = 0; i < (*AL)->VexNum; ++i)
	{
		printf("%s", (*AL)->adjlist[i].data);
		printf("-->");
		arc u = (*AL)->adjlist[i].firstarc;
		while (u)
		{
			printf("%s", (*AL)->adjlist[u->place].data);
			printf("-->");
			u = u->next;
		}
		printf("||\n");
	}
	return 1;
}
int depth(MGraph* M, int v[], int u)
{
	printf("%s ", (*M)->Vexs[u]); v[u] = 1;
	for (int i = 0; i < (*M)->VexNum; ++i)
	{
		if (v[i] == 0 && (*M)->arcs[u][i] != 0 && (*M)->arcs[u][i] != NONE)
			depth(M, v, i);
	}
	return 1;
}
int depth_travel(MGraph* M)
{
	printf("请输入起始地名:"); char name[100];
	scanf_s("%s", name, 100); int v[MAXSIZE] = { 0 };
	int u=find_position(M, name);
	depth(M, v, u);
	for (int i = 0; i < (*M)->VexNum; ++i)
	{
		if (v[i] == 0)
			depth(M, v, i);
	}
	return 1;
}
int level(MGraph* M, int v[], int u)
{
	SqQueue* Q = new SqQueue; InitQueue(Q);
	EnQueue(Q, u); v[u] = 1; int place;
	while ((*Q)->rear != (*Q)->front)
	{
		DeQueue(Q, &place);
		printf("%s ", (*M)->Vexs[place]);
		for (int i = 0; i < (*M)->VexNum; ++i)
		{
			if (v[i] == 0 && (*M)->arcs[u][i] != 0 && (*M)->arcs[u][i] != NONE)
			{
				v[i] = 1; EnQueue(Q, i);
			}
		}
	}
	return 1;
}
int level_travel(MGraph* M)
{
	printf("请输入起始地名:"); char name[100];
	scanf_s("%s", name, 100); int v[MAXSIZE] = { 0 };
	int u = find_position(M, name);
	level(M, v, u);
	for (int i = 0; i < (*M)->VexNum; ++i)
	{
		if (v[i] == 0)
			level(M, v, i);
	}
	return 1;
}
int main()
{  
	MGraph* M = new MGraph; *M = new Graph;
	write_in(M);
	add_arcs(M);
	printf("邻接表如图:\n");
	ALGraph* AL = new ALGraph; *AL = new G;
	create_and_output_table(M, AL); int best=0;
	for (int i = 0; i < (*AL)->VexNum; ++i)
	{
		if ((*AL)->adjlist[best].count < (*AL)->adjlist[i].count)
			best = i;
	}
	printf("交通最发达的城市是%s", (*AL)->adjlist[best].data);
	printf("请输入两个城市");
	char a1[100], a2[100];
	scanf_s("%s", a1, 100);
	scanf_s("%s", a2, 100);
	int v1 = find_position(M, a1), v2 = find_position(M, a2);
	if ((*M)->arcs[v1][v2] == NONE || (*M)->arcs[v1][v2] == NONE)printf("不可达！\n");
	else
		printf("可达！\n");
	depth_travel(M);
	level_travel(M);
	return 1;
}