#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#define MAXSIZE (20)
typedef struct node
{
	int data;
	struct node* lchild;
	struct node* rchild;
}BiNode,*BiTree;
typedef struct
{
	BiTree data[MAXSIZE];
	int front;
	int rear;
	int QueueSize;
}Queue, * SqQueue;
int InitTree(BiTree* T)
{
	*T = new BiNode;
	return 1;
}
int InitQueue(SqQueue* Q)
{
	*Q = (SqQueue)malloc(sizeof(Queue));
	(*Q)->rear = (*Q)->front = 0;
	(*Q)->QueueSize = MAXSIZE;
	return 1;
}
int EnQueue(SqQueue* Q,BiTree x)
{
	(*Q)->data[(*Q)->rear] = x;
	(*Q)->rear = ((*Q)->rear + 1) % (*Q)->QueueSize;
	return 1;
}
int EmptyQueue(SqQueue* Q)
{
	if ((*Q)->front == (*Q)->rear)return 1;
	else
		return 0;
}
int DeQueue(SqQueue* Q)
{
	if(EmptyQueue(Q))return 0;
	(*Q)->front = ((*Q)->front + 1) % (*Q)->QueueSize;
	return 1;
}
int getfront(SqQueue* Q, BiTree* e)
{
	if (EmptyQueue(Q))return 0;
	*e = (*Q)->data[(*Q)->front];
	return 1;
}
int level_write(BiTree* T)
{
	int fa, so, ta;
	SqQueue* Q = new SqQueue; InitQueue(Q);
	printf("请输入父节点值(0为根)，节点值(0结束)，任务（0左|1右）：");
	scanf_s("%d,%d,%d", &fa, &so, &ta);
	while (so!=0)
	{
		BiTree p = new BiNode;
		p->data = so; p->lchild = p->rchild = NULL;
		EnQueue(Q, p);
		if (fa == 0)*T = p;
		else
		{
			BiTree s = new BiNode;
			getfront(Q, &s);
			while (s->data != fa)
			{
				DeQueue(Q);
				getfront(Q, &s);
			}
			if (s->data == fa)
			{
				if (ta == 0)s->lchild = p;
				if (ta == 1)s->rchild = p;
			}
		}
		printf("请输入父节点值(0为根)，节点值(0结束)，任务（0左|1右）：");
		scanf_s("%d,%d,%d", &fa, &so, &ta);
	}
	return 1;
}
int level_print(BiTree* T)
{   
	if (!*T)return 0;
	SqQueue* Q = new SqQueue; InitQueue(Q);
	EnQueue(Q, *T); BiTree p = *T;
	int length = 2; int depth = 0; int flag = (*Q)->rear;
	while (!EmptyQueue(Q))
	{
		getfront(Q, &p);
		for (int i = 0; i < length; i++)
			printf("--");
		printf("%d\n", p->data);
		DeQueue(Q);
		if (p->lchild)EnQueue(Q, p->lchild);
		if (p->rchild)EnQueue(Q, p->rchild);
		if ((*Q)->front == flag)
		{
			flag = (*Q)->rear; length += 2;//每层结束加length值，并重置flag
			depth++; //深度加一
		}
	}
	return depth;
}
int calculate_leaf(BiTree* T,int* leaf,int *node)
{  
	if (!*T)return 0;
	(*node)++;
	if (!(*T)->lchild && !(*T)->rchild)(*leaf)++;
	if ((*T)->lchild)calculate_leaf(&(*T)->lchild, leaf, node);
	if ((*T)->rchild)calculate_leaf(&(*T)->rchild, leaf, node);
	return 1;
}
int find_data(BiTree* T,int x,int *find)
{   
	if ((*T)->data == x&&*T)
	{
		*find = 1;
		printf("找到了该结点%d\n", (*T)->data);
		return 1;
	}
	if ((*T)->lchild)find_data(&(*T)->lchild,x,find);
	if ((*T)->rchild)find_data(&(*T)->rchild,x,find);
	return 1;
}
int main()
{
	BiTree* T = new BiTree; InitTree(T);
	level_write(T); int num;
	while (1)
	{   
		system("cls");
		printf("树的凹入表如下:\n");
		int depth = level_print(T);
		int* leaf = new int; *leaf = 0;
		int* node = new int; *node = 0;
		printf("请输入你的操作:1 求叶子结点2 求深度3 求结点数4 查找\n");
		scanf_s("%d", &num);
		if (num ==1)
		{
			calculate_leaf(T, leaf, node);
			printf("叶子节点数是%d", *leaf);
		}
		if (num == 2)
		{
			printf("深度是%d\n", depth);
		}
		if (num == 3)
		{
			calculate_leaf(T, leaf, node);
			printf("节点数是%d", *node);
		}
		if (num == 4)
		{   
			int x; int* find = new int; *find = 0;
			printf("请输入要查找的值:");
			scanf_s("%d", &x);
			find_data(T, x, find);
			if (*find == 0)printf("没找到!\n");
		}
		printf("按任意键继续!\n");
		getchar(); getchar();
	}
	return 1;
}
