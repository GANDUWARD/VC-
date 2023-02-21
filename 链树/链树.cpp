#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAXSIZE 20
typedef struct
{
	int num;
}Elemdata;
typedef struct node
{
	node* parent;
	node* lchild;
	node* rchild;
	Elemdata data;
}tree,*TR;
typedef struct
{
	TR tree;
	int task;
}StackData;
typedef struct
{
	StackData T[MAXSIZE];
	int top;
}SqStack;
typedef struct
{
	TR data[MAXSIZE];
	int front;
	int rear;
	int QueueSize;	
}Queue,*SqQueue;
int InitQueue(SqQueue* Q)
{
	*Q = (SqQueue)malloc(sizeof(Queue));
	(*Q)->rear = (*Q)->front = 0;
	(*Q)->QueueSize = MAXSIZE;
	return 1;
}
int EnQueue(SqQueue* Q,TR x)
{
	(*Q)->data[(*Q)->rear] = x;
	(*Q)->rear = ((*Q)->rear + 1) % (*Q)->QueueSize;
	return 1;
}
TR DeQueue(SqQueue* Q)
{   
	if ((*Q)->rear == (*Q)->front)return 0;
	TR x =(*Q)->data[(*Q)->front];
	(*Q)->front = ((*Q)->front +1) % (*Q)->QueueSize;
	return x;
}
int Inittree(TR* T)
{
	(*T)->data.num = 0;
	(*T)->lchild = NULL;
	(*T)->rchild = NULL;
	(*T)->parent = *T;
	return 1;
}
int write_in(TR* T)//单链创建树
{   
	TR p = *T,q=*T;
	int num,x;
	printf("请输入数字(0结束):");
	scanf_s("%d", &x);
	while (x!=0)
	{   
		p->data.num = x;
		p->lchild = (TR)malloc(sizeof(tree));
		p->rchild = (TR)malloc(sizeof(tree));
		printf("请输入你要迁移(1左子树|2右子树)：");
		scanf_s("%d", &num);
		if (num == 1)
		{   
			q = p;
			p->rchild = NULL;
			p = p->lchild;
			p->parent = q;
		}
		if (num == 2)
		{   
			q = p;
			p->lchild = NULL;
			p = p->rchild;
			p->parent = q;
		}
		printf("请输入数字(0结束):");
		scanf_s("%d", &x);
		if (x == 0)
		{
			p = p->parent;
			p->lchild = NULL;
			p->rchild = NULL;
		}
    }
	return 1;
}
int create_tree(TR* T) //先序遍历创造
{   
	if (*T)
	{   
		int x;
		printf("请输入值（0）退出：");
		scanf_s("%d", &x);
		if (x == 0) { *T = NULL; }
	    else
		{   
			(*T)->data.num = x;
			(*T)->lchild = (TR)malloc(sizeof(tree));
			(*T)->rchild = (TR)malloc(sizeof(tree));
			create_tree(&(*T)->lchild);
			create_tree(&(*T)->rchild);
		}
	}
	return 1;
}
int preorder(TR T)
{    
	if (T == NULL) { return 0; }
	printf("%d ", T->data.num);
	preorder(T->lchild);
	preorder(T->rchild);
	return 1;
}
int inorder(TR T)
{
	if (T == NULL) { return 0; }
	preorder(T->lchild);
	printf("%d ", T->data.num);
	preorder(T->rchild);
	return 1;
}
int postorder(TR T)
{
	if (T == NULL) { return 0; }
	preorder(T->lchild);
	preorder(T->rchild);
	printf("%d ", T->data.num);
	return 1;
}
int InitStack(SqStack* S)
{   
	S->top = -1;
	return 1;
}
int push(SqStack* S,StackData x)
{
	S->T[++S->top] = x;
	return 1;
}
StackData pop(SqStack* S)
{
	StackData x = S->T[S->top--];
	return x;
}
//int taskorder(TR *T)
//{
//	SqStack* S = (SqStack*)malloc(sizeof(SqStack));
//	InitStack(S);
//	StackData x1, x2, x3,q; TR p = *T;
//	x1.tree = p;
//	x1.task = 0;
//	x2.tree = p->lchild;
//	x2.task = 1;
//	x3.tree = p->rchild;
//	x3.task = 1;
//	push(S, x3);
//	push(S, x2);
//	push(S, x1);
//	while(S->top!=-1)
//	{    
//		q = S->T[S->top];
//		if (q.tree == NULL) 
//		{
//			pop(S); continue;
//		}
//		if(q.task == 0)
//		{
//			printf("%d ", pop(S).tree->data); continue;
//		}
//		if (q.task == 1)
//		{   
//			pop(S);
//			x1.tree = q.tree;
//			x1.task = 0;
//			x2.tree = q.tree->lchild;
//			x2.task = 1;
//			x3.tree = q.tree->rchild;
//			x3.task = 1;
//			push(S, x3);
//			push(S, x2);
//			push(S, x1);
//			continue;
//		}
//	}
//	return 1;
//}
int taskorder(TR* T)
{
	SqStack* S=(SqStack*)malloc(sizeof(SqStack));
	InitStack(S);
	StackData e,l,r; e.tree = *T;
	e.task = 1;
	push(S, e);
	while (S->top!=-1)
	{
		e = S->T[S->top]; pop(S); if (e.tree == NULL)break;
		l.tree = e.tree->lchild; r.tree = e.tree->rchild; 
		if (e.task == 0)
		{
			printf("%d ", e.tree->data);
		}
		else
		{   
			if(r.tree)
			{  
				r.task = 1; push(S, r);
			}
			if (l.tree)
			{
				l.task = 1; push(S, l);
			}
			e.task = 0; push(S, e);
		}
	}
	return 1;
}
int levelorder(TR* T)//根据队列层次遍历
{
	SqQueue* Q=(SqQueue*)malloc(sizeof(SqQueue));
	InitQueue(Q);
	TR*p = T,q;
	EnQueue(Q, *p);
	while (*p = DeQueue(Q))
	{
		
		printf("%d ", (*p)->data.num);
		if ((*p)->lchild)
		{
		
			EnQueue(Q, (*p)->lchild);
		}
		if ((*p)->rchild)
		{   
			EnQueue(Q, (*p)->rchild);
		}
	}
	return 1;
}
void NrPreOrder(TR *T)//路径
{
	TR p = *T; SqStack *S; InitStack(S);
	StackData e;
	if (T == NULL)return;
	while (p != NULL||S->top!=-1)
	{   
		while (p != NULL)
		{
			e.tree = p;
			printf("%d ", p->data);
			push(S, e);
			p = p->lchild;
		}
		if (S->top == -1)return;
		else
		{
			pop(S);
			p = p->rchild;
		}
	}
	printf("\n");
}
int levcre_tree(TR* T)//层次遍历创建树
{
	SqQueue* Q = (SqQueue*)malloc(sizeof(SqQueue));
	InitQueue(Q);
	TR p = *T, q;
	EnQueue(Q, p);
	int num,i=1;
	while (p = DeQueue(Q))
	{   
		/*printf("现在是二叉树的第%d层\n",i);*/
		printf("请输入值（0）退出:");
		scanf_s("%d", &num);
		if (num == 0) {  p->data.num = 0; p->lchild = p->rchild = NULL; p = NULL; }
		else
		{   
			p->lchild = (TR)malloc(sizeof(tree));
			p->rchild = (TR)malloc(sizeof(tree));
			p->data.num = num; i++;
			EnQueue(Q, p->lchild); EnQueue(Q, p->rchild);
		}
	}
	return 1;
}
int main()
{
	TR* T = (TR*)malloc(sizeof(TR));
	*T = (TR)malloc(sizeof(TR));
	Inittree(T);
	levcre_tree(T);
	/*preorder(*T);*/
	levelorder(T);
	return 1;
}