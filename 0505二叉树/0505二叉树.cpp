#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAXSIZE 20
typedef struct node
{
	char string[20];
	struct node* lchild;
	struct node* rchild;
}Treenode, * BiTree;
typedef struct
{
	BiTree Elemdata[MAXSIZE];
	int front;
	int rear;
	int QueueSize;
}Queue, * SqQueue;
int InitQueue(SqQueue* Q)
{
	(*Q) = (SqQueue)malloc(sizeof(Queue));
	(*Q)->front = (*Q)->rear = 0;
	(*Q)->QueueSize = MAXSIZE;
	return 1;
}

int EnQueue(SqQueue* Q, BiTree x)
{
	(*Q)->Elemdata[(*Q)->rear] = x;
	(*Q)->rear = ((*Q)->rear + 1) % (*Q)->QueueSize;
	return 1;
}
int DeQueue(SqQueue* Q)
{
	if ((*Q)->front == (*Q)->rear)return 0;
	(*Q)->front = ((*Q)->front + 1) % (*Q)->QueueSize;
	return 1;
}
int gethead(SqQueue* Q, BiTree* e)
{
	if ((*Q)->front == (*Q)->rear)return 0;
	*e = (*Q)->Elemdata[(*Q)->front];
	return 1;
}
int InitTree(BiTree* T)
{
	(*T) = (BiTree)malloc(sizeof(Treenode));
	(*T)->lchild = (*T)->rchild = NULL;
	return 1;
}
int Create(BiTree* T)
{
	char fa[20], so[20];
	int ta;
	SqQueue* Q = (SqQueue*)malloc(sizeof(SqQueue));
	InitQueue(Q);
	printf("请输入父节点（#为根）:");
	scanf_s("%s", fa,20);
	printf("请输入节点数据(#结束输入):");
	scanf_s("%s", so,20);
	printf("请输入任务（0左1右）:");
	scanf_s("%d",&ta);
	while (strcmp(so,"#")!=0)
	{
		BiTree q = (BiTree)malloc(sizeof(Treenode));
		BiTree s = (BiTree)malloc(sizeof(Treenode));
		strcpy_s(q->string,20,so); q->lchild = q->rchild = NULL;   //划分新生成q结点为叶子结点
		EnQueue(Q, q);
		if (strcmp(fa, "#") == 0) { *T = q; }
		else
		{
			gethead(Q, &s);
			while (strcmp(s->string,fa)!=0)
			{
				DeQueue(Q);
				gethead(Q, &s);//注意要先看下队头是不是，不是再出栈，而不是一口气连续操作
			}
			if (strcmp(s->string, fa) == 0)
			{
				if (ta == 0)
					s->lchild = q;
				else
					s->rchild = q;
			}
		}
		printf("请输入父节点（#为根）:");
		scanf_s("%s", fa, 20);
		printf("请输入节点数据(#结束输入):");
		scanf_s("%s", so, 20);
		printf("请输入任务（0左1右）:");
		scanf_s("%d", &ta);
	}
	return 1;
}
int print(BiTree* T)
{   
	int level,max,i=0;
	SqQueue* Q = (SqQueue*)malloc(sizeof(SqQueue));
	InitQueue(Q);
	BiTree *p = new BiTree;
	EnQueue(Q, *T);
	level = (*Q)->rear; max = level;
	while ((*Q)->rear!=(*Q)->front)
	{
		gethead(Q, p);
		DeQueue(Q);
		printf("%s ", (*p)->string);
		i++;
		if ((*p)->lchild)
		{

			EnQueue(Q, (*p)->lchild);
		}
		if ((*p)->rchild)
		{
			EnQueue(Q, (*p)->rchild);
		}
		if (level == (*Q)->front)
		{   
			if (max < i)max = i;
			level = (*Q)->rear;
			i = 0;
		}
	}
	printf("宽度是%d", max);
	return 1;
}
int judge(BiTree* T)//重点在于判断不饱和结点
{
	SqQueue* Q = (SqQueue*)malloc(sizeof(SqQueue));
	InitQueue(Q); EnQueue(Q, *T);
	BiTree e = new Treenode; 
	int judge = 1; int q = 1;//judge是判断是否完全二叉树，q用来判断是不是检测到第一类不饱和结点
	while ((*Q)->front != (*Q)->rear)
	{
		gethead(Q, &e);
		DeQueue(Q);
		if (e->lchild || e->rchild&&q==0)//作为第一类不饱和结点之后的结点并且有孩子
		{
			judge = 0; break;
		}
	    if(e->lchild&&!e->rchild||!e->lchild&&!e->rchild)//只有左子树或叶子结点
		{ 
			//看它下一个结点有没有孩子,做个标记
			q = 0;
		}
		if (e->rchild && !e->lchild)//只有右子树，直接pass
		{
			judge = 0; break;
		}
		if(e->lchild)EnQueue(Q, e->lchild);
		if(e->rchild)EnQueue(Q, e->rchild);
	}
	if (judge == 0)printf("不是完全二叉树！\n");
	else
		printf("是完全二叉树!\n");
	return 1;
}
int judge2(BiTree* T)
{
	SqQueue* Q = (SqQueue*)malloc(sizeof(SqQueue));
	InitQueue(Q); EnQueue(Q, *T);
	BiTree e = new Treenode;
	int judge = 1; int q = 1;//judge是判断是否完全二叉树，q用来判断是不是检测到第一类不饱和结点
	while ((*Q)->front != (*Q)->rear)
	{
		gethead(Q, &e);
		DeQueue(Q);
		if (!e)break;//遇到空结点跳出队伍
		EnQueue(Q, e->lchild);
		EnQueue(Q, e->rchild);
	}
	while ((*Q)->front != (*Q)->rear)
	{
		gethead(Q, &e);
		DeQueue(Q);
		if (e)
		{
			judge = 0;//后面的结点非空就非完全
			break;
		}
	}
	if (judge == 0)printf("不是完全二叉树！\n");
	else
		printf("是完全二叉树!\n");
	return 1;
}
int main()
{   
	BiTree* T = new BiTree;
	InitTree(T);
	Create(T);
	print(T);
	judge(T);
	judge2(T);
	return 0;
}