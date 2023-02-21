#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define VNUM 10
#define NONE 999
typedef struct ArcNode
{
	int adjvex;
	int weight;
	struct ArcNode* nextarc;
}ArcNode;
typedef struct
{   
	int count;     //储存入度
	char data[20];
	ArcNode* firstArc;
}VertexNode;
typedef struct Graph
{
	VertexNode adjlist[VNUM];
	int vexNum, arcNum;
}ALGraph;
typedef struct node
{
	int place;
	struct node* next;
	struct node* prior;
}Lnode,*LinkQueue;
typedef struct
{
	LinkQueue front;
	LinkQueue rear;
}Queue;
typedef struct
{
	int flag;
	int lowcost;
}Edge;
typedef struct
{
	int place[VNUM];
	int top;
}Stack,*SqStack;
typedef struct
{
	int ve;
	int vl;
}activity;
int InitStack(SqStack* S)
{
	*S = new Stack;
	(*S)->top = -1;
	return 1;
}
int push(SqStack* S, int x)
{
	(*S)->place[++(*S)->top] = x;
	return 1;
}
int gettop(SqStack* S, int* place)
{
	if ((*S)->top == -1)return 0;
	*place = (*S)->place[(*S)->top];
	return 1;
}
int pop(SqStack* S)
{
	if ((*S)->top == -1)return 0;
	(*S)->top--;
	return 1;
}
int InitQueue(Queue* Q)
{
	Q->front = (LinkQueue)malloc(sizeof(Lnode));
	Q->front->next = NULL;
	Q->rear = Q->front;
	return 1;
}
int EnQueue(Queue* Q, int x)
{
	LinkQueue p = (LinkQueue)malloc(sizeof(Lnode));
	p->place = x;
	p->next = Q->rear->next;
	Q->rear->next = p;
	Q->rear = p;
	p->prior = Q->front->next;//记住将队头结点赋值给p的前驱
	return 1;
}
int DeQueue(Queue* Q)//注意这里出队不必free
{
	if (Q->front == Q->rear)return 0;
	LinkQueue p = Q->front->next;
	Q->front->next = p->next;
	if (Q->rear == p)Q->rear = Q->front;
	/*free(p);*/
	return 1;
}
int getfront(Queue* Q, int* u)
{
	if (Q->front == Q->rear)return 0;
	*u = Q->front->next->place;//将队头下一个即第一个赋值给u
	return 1;
}
int depth_print(ALGraph* AL, int* u, int v[])
{   
	printf("%s ", AL->adjlist[*u].data);
	v[*u] = 1;
	for (int i=0;i<AL->vexNum;i++)
	{   
		ArcNode* p = AL->adjlist[*u].firstArc;
		while (p)
		{   
			if(v[p->adjvex]!=1)depth_print(AL, &p->adjvex, v);
			p = p->nextarc;
		}
		*u = i;
	}
	return 1;
}
int level_print(ALGraph* AL,int*u)
{
	int v[VNUM] = { 0 }; int i, k = 0;
	Queue* Q = new Queue;
	InitQueue(Q);
	EnQueue(Q, *u);//0也可以改成其他值
	while (k < AL->vexNum)
	{
		while (Q->front != Q->rear)
		{
			getfront(Q, u);      //获取队头顶点位置
			DeQueue(Q);
			printf("%s ", AL->adjlist[*u].data);
			v[*u] = 1;      //标记访问位置
			ArcNode* p = AL->adjlist[*u].firstArc;
			while (p)
			{
				if (v[p->adjvex] != 1)
				{
					EnQueue(Q, p->adjvex);
					v[p->adjvex] = 1;
				}
				p = p->nextarc;
			}
		}
		if (v[k] == 0)EnQueue(Q, k);//如果找到一次广度遍历都没有标记的点，说明不属于同一连通分量，入队
		k++;
	}
	return 1;
}
int write_in(ALGraph* AL)
{
	int i, j, a1, a2, a3, l = 0;
	printf("请输入顶点个数:");
	scanf_s("%d", &(AL)->vexNum);
	printf("请输入顶点信息:");
	for (i = 0; i < AL->vexNum; i++)
	{
		scanf_s("%s", AL->adjlist[i].data, 20);
		AL->adjlist[i].firstArc = NULL;
		AL->adjlist[i].count = 0;      //初始化入度为零
	}
	while (1)
	{
		printf("请输入边数(方向):");
		scanf_s("%d", &AL->arcNum);
		if (AL->arcNum >= 0 && AL->arcNum <= AL->vexNum * (AL->vexNum - 1))break;
		else
			printf("输入边数有误!");
	}
	for (i = 0; i < AL->arcNum; i++)
	{
		printf("请输入起点号数 终点号数 权重:");
		scanf_s("%d %d %d", &a1, &a2, &a3);
		if (a1 >= 0 && a2 < AL->vexNum && a1 != a2 && a2 >= 0 && a2 < AL->vexNum)
		{
			ArcNode* p = new ArcNode; p->nextarc = AL->adjlist[a1].firstArc;
			AL->adjlist[a1].firstArc = p;
			p->adjvex = a2; p->weight = a3;
			AL->adjlist[a2].count++;   //边多加一边，相应入度加一
		}
		else
			printf("输入信息有误，请重新输入!\n");
	}
	return 1;
}
int output_matrix(ALGraph* AL,int arcs[][VNUM])
{   
	printf("邻接矩阵如下:\n");
	for(int i=0;i<AL->vexNum;i++)
		for (int j = 0; j < AL->vexNum; j++)
		{
			if (i == j)arcs[i][j] = 0;
			else
				arcs[i][j] = NONE;
		}
	for (int k = 0; k < AL->vexNum; k++)
	{  
		ArcNode* p = AL->adjlist[k].firstArc;
		while (p)
		{   
			arcs[k][p->adjvex] = p->weight;
			p = p->nextarc;
		}
	}
	for (int i = 0; i < AL->vexNum; i++)
		for (int j = 0; j < AL->vexNum; j++)
		{
			printf("%d ",arcs[i][j]);
			if (j == AL->vexNum - 1)
				printf("\n");
		}
	return 1;
}
int output_ALGraph(ALGraph* AL)
{  
	printf("邻接表如下:\n");
	for (int k = 0; k < AL->vexNum; k++)
	{   
		printf("%s", AL->adjlist[k].data);
		ArcNode* p = AL->adjlist[k].firstArc;
		while (p)
		{
			printf("---->%d||%d", p->adjvex, p->weight);
			p = p->nextarc;
		}
		printf("\n");
	}
	return 1;
}
int Initedges(ALGraph* AL, Edge edges[],int u)
{   
	for (int i = 0; i < AL->vexNum; i++)//初设999和0
	{
		if (i == u)edges[i].lowcost = 0;
		else
			edges[i].lowcost = 999;
	}
	ArcNode* p = AL->adjlist[u].firstArc; //初始化为与u号点直接相连边的权重
	while (p)
	{
		edges[p->adjvex].lowcost = p->weight;
		p = p->nextarc;
	}
	return 1;
}
int Dijkstra(ALGraph* AL,Edge edges[],int u)
{   
	Initedges(AL,edges,u);
	for (int i=0; i<AL->vexNum; i++)//访问所有的点，数学归纳得出，后一新得较小值是继承之前得小值得来,算法可行
	{
		ArcNode* p = AL->adjlist[i].firstArc; //遍历所有边
		while (p)
		{
			if (edges[i].lowcost + p->weight < edges[p->adjvex].lowcost)edges[p->adjvex].lowcost = edges[i].lowcost + p->weight;
			p = p->nextarc;
		}
	}
	return 1;
}
int Initarrays(ALGraph* AL, int dis[][VNUM], int path[][VNUM])
{
	for (int i = 0; i < AL->vexNum; i++)
		for (int j = 0; j < AL->vexNum; j++)
		{
			if (i == j)dis[i][j] = 0;
			else
				dis[i][j] = NONE;
		}
	for (int k = 0; k < AL->vexNum; k++)
	{
		ArcNode* p = AL->adjlist[k].firstArc;
		while (p)
		{
			dis[k][p->adjvex] = p->weight;
			p = p->nextarc;
		}
	}
	for (int i = 0; i < AL->vexNum; i++)
		for (int j = 0; j < AL->vexNum; j++)
		{
			if (dis[i][j] != 0 && dis[i][j] != NONE)path[i][j] = i;
			else
				path[i][j] = -1;
		}
	return 1;
}
int FLoyd(ALGraph* AL, int dis[][VNUM], int path[][VNUM])
{
	Initarrays(AL, dis, path);
	for(int k=0;k<AL->vexNum;k++)
		for(int i=0;i<AL->vexNum;i++)
			for (int j = 0; j < AL->vexNum; j++)
			{
				if (dis[i][k] + dis[k][j] < dis[i][j])
				{
					dis[i][j] = dis[i][k] + dis[k][j];
					path[i][j] = k;
				}
			}
	return 1;
}
int Initcounts(ALGraph* AL)
{   
	for (int i = 0; i < AL->vexNum; i++)
		AL->adjlist[i].count = 0;
	for (int k = 0; k < AL->vexNum; k++)
	{
		ArcNode* p = AL->adjlist[k].firstArc;
		while (p)
		{
			AL->adjlist[p->adjvex].count++;
			p = p->nextarc;
		}
	}
	return 1;
}
int Topological_Sorting(ALGraph* AL)
{
	SqStack* S = new SqStack; InitStack(S); int j = 0;//j记录出栈个数
	Initcounts(AL);    //初始化所有入度
	for (int i = 0; i < AL->vexNum; i++)  //初始化进入起点
	{
		if (AL->adjlist[i].count == 0)push(S, i);
	}
	while ((*S)->top != -1)
	{   
		int k;
		gettop(S, &k);       //获取栈顶
		printf("%s ", AL->adjlist[k].data);   //输出栈顶元素
		pop(S);        //出栈
		j++;
		for (ArcNode* q = AL->adjlist[k].firstArc; q; q = q->nextarc)//在图中"删除"该元素
		{
			AL->adjlist[q->adjvex].count--;
			if (AL->adjlist[q->adjvex].count == 0)//删除后发现新的起点,入栈
			{
				push(S, q->adjvex);
			}
		}
	}
	if (j == AL->vexNum)   
	{
		printf("该序列为拓扑排序\n");
		/*print_sorting(S);*/
	}
	else
		printf("无拓扑排序!\n");
	return 1;
}
int find_Topo(ALGraph* AL,int Topo[])
{
	SqStack* S = new SqStack; InitStack(S); int j = 0;//j记录出栈个数
	Initcounts(AL);    //初始化所有入度
	for (int i = 0; i < AL->vexNum; i++)  //初始化进入起点
	{
		if (AL->adjlist[i].count == 0)push(S, i);
	}
	while ((*S)->top != -1)
	{
		int k;
		gettop(S, &k);       //获取栈顶
		Topo[j] = k;
		pop(S);        //出栈
		j++;
		for (ArcNode* q = AL->adjlist[k].firstArc; q; q = q->nextarc)//在图中"删除"该元素
		{
			AL->adjlist[q->adjvex].count--;
			if (AL->adjlist[q->adjvex].count == 0)//删除后发现新的起点,入栈
			{
				push(S, q->adjvex);
			}
		}
	}
	if (j == AL->vexNum)
	{
		return 1;
	}
	else
		return 0;
}
int key_activities(ALGraph* AL)
{
	int Topo[VNUM]; activity acts[VNUM];
	for (int i = 0; i < AL->vexNum; i++)//初始化ve
		acts[i].ve = 0;
	if (!find_Topo(AL, Topo))
	{
		printf("该图有环！\n");
	}//获取拓扑排序
	for (int i = 0; i < AL->vexNum; i++)   //根据拓扑排序正向遍历
		for (ArcNode* q = AL->adjlist[Topo[i]].firstArc; q; q = q->nextarc)
		{
			if (acts[Topo[i]].ve + q->weight > acts[q->adjvex].ve)acts[q->adjvex].ve = acts[Topo[i]].ve + q->weight;//修改q->adjvex号顶点的ve为较大的值
		}
	for (int i = 0; i < AL->vexNum; i++)  //初始化vl
	{
		acts[i].vl = acts[AL->vexNum - 1].ve;
	}
	for (int i = AL->vexNum - 1; i >= 0; i--)//根据拓扑排序逆向遍历
		for (ArcNode* q = AL->adjlist[Topo[i]].firstArc; q; q = q->nextarc)
		{
			if (acts[q->adjvex].vl - q->weight < acts[Topo[i]].vl)acts[Topo[i]].vl = acts[q->adjvex].vl - q->weight;//修改q->adjvex号顶点的vl为较小的值
	    }
	printf("关键路径:");
	for (int i = 0; i < AL->vexNum; i++)
	{
		if (acts[Topo[i]].ve == acts[Topo[i]].vl)
			printf("%s-->",AL->adjlist[Topo[i]].data);
	}
	printf("||");
	return 1;
}
int main()
{
	ALGraph* AL = new ALGraph; int num;
	write_in(AL);
	int arcs[VNUM][VNUM];
	while (1)
	{   
		system("cls");
		output_matrix(AL, arcs);
		output_ALGraph(AL);
		printf("\n请输入你的选择1 深度遍历2 广度遍历3 迪杰斯特拉算法求最短路径4 弗洛伊德算法求最短路径5 构建拓扑排序6 求关键路径\n");
		scanf_s("%d", &num);
		if (num == 1)
		{
			int* u = new int; int v[VNUM] = { 0 };
			printf("请输入起始点:");
			scanf_s("%d", u);
			printf("深度遍历如下:");
			depth_print(AL, u, v);
		}
		if (num == 2)
		{
			int* u = new int; *u = 0;
			printf("请输入初始点号数:");
			scanf_s("%d", u);
			printf("广度遍历结果如下:");
			level_print(AL, u);
		}
		if (num == 3)
		{
			int flag[VNUM] = { 0 }; Edge edges[VNUM]; int u;
			printf("请输入初始点的号数:");
			scanf_s("%d", &u);
			Dijkstra(AL, edges,u);
			for (int i = 0; i < AL->vexNum; i++)
			{
				if (edges[i].lowcost != 0&&edges[i].lowcost!=999)
					printf("%s边到%s边的最短路径长度为%d\n", AL->adjlist[u].data, AL->adjlist[i].data, edges[i].lowcost);
				if (edges[i].lowcost == 999)
					printf("%s边到%s边没有路径!\n", AL->adjlist[u].data, AL->adjlist[i].data);
			}
		}
		if (num == 4)
		{
			int dis[VNUM][VNUM],path[VNUM][VNUM];
			FLoyd(AL, dis, path);
			for(int i = 0;i<AL->vexNum;i++)
				for (int j = 0; j < AL->vexNum; j++)
				{   
					if (i != j)
					{
						printf("%s边到%s边的最短路径长度为%d\n", AL->adjlist[i].data, AL->adjlist[j].data, dis[i][j]);
					}
				}
		}
		if (num == 5)
		{
			Topological_Sorting(AL);
		}
		if (num == 6)
		{
			key_activities(AL);
		}
		printf("按任意键继续!\n");
		getchar(); getchar();
	}
}