//#include<stdio.h>
//#include<stdlib.h>
//typedef struct node
//{
//	int data;
//	struct node* lchild;
//	struct node* rchild;
//}BiNode,*BiTree;
//int InitTree(BiTree* T)
//{
//	*T = new BiNode;
//	(*T)->lchild = (*T)->rchild = NULL;
//	return 1;
//}
//int write(BiTree* T)
//{
//	printf("请输入值：");
//	scanf_s("%d", &(*T)->data);
//	if ((*T)->data == 0)
//	{
//		*T = NULL; return 0;
//	}
//	InitTree(&(*T)->lchild); InitTree(&(*T)->rchild);
//	printf("开始输入%d的左子树,", (*T)->data); write(&(*T)->lchild);
//	printf("开始输入%d的右子树,", (*T)->data); write(&(*T)->rchild);
//	return 1;
//}
//int calculate_node(BiTree* T, int* node)
//{
//	if (!*T)return 0;
//	(*node)++;
//	calculate_node(&(*T)->lchild, node);
//	calculate_node(&(*T)->rchild, node);
//	return 1;
//}
//int calculate_leaf(BiTree* T, int* leaf)
//{
//	if (!*T)return 0;
//	if(!(*T)->lchild&&!(*T)->rchild)(*leaf)++;
//	calculate_leaf(&(*T)->lchild, leaf);
//	calculate_leaf(&(*T)->rchild, leaf);
//	return 1;
//}
//int table_show(BiTree* T, int space)
//{
//	if (!*T)return 0;
//	for (int i = 0; i < space; i++)
//		printf("--");
//	printf("%d\n", (*T)->data);
//	table_show(&(*T)->lchild, space + 2);
//	table_show(&(*T)->rchild, space + 2);
//	return 1;
//}
//int calculate_depth(BiTree* T)
//{   
//	if (!*T)return 0;
//	int m, n = 0;
//	m = calculate_depth(&(*T)->lchild);
//	n = calculate_depth(&(*T)->rchild);
//	if (m < n)return n + 1;
//	else
//		return m + 1;
//}
//int find_out(BiTree* T, int x,int *find)
//{
//	if (!*T)return 0;
//	if ((*T)->data == x)
//	{
//		printf("找到了%d,地址是%x",(*T)->data, *T);
//		*find = 1;
//	}
//	find_out(&(*T)->lchild, x,find);
//	find_out(&(*T)->rchild, x,find);
//	return 1;
//}
//int main()
//{
//	BiTree* T = new BiTree; InitTree(T);
//	write(T);
//	table_show(T, 2);
//	int* node = new int; *node = 0; 
//	calculate_node(T, node); printf("结点数是%d\n", *node);
//	int* leaf = new int; *leaf = 0;
//	calculate_leaf(T, leaf); printf("叶子结点数是%d\n", *leaf);
//	int depth = calculate_depth(T); printf("深度是%d\n", depth);
//	int x; printf("请输入要查找的值"); scanf_s("%d", &x);
//	int* find = new int; *find = 0;
//	find_out(T, x, find); if (!*find)printf("未找到%d",x);
//	return 1;
//}
int Init_SqList(SqList* SL)
{
	(*SL) = (SqList)malloc(sizeof(List));
	(*SL)->size = MAXSIZE;
	(*SL)->length = 0;
	return 1;
}
int insert_SqList(SqList* SL, int i, elemdata x)
{  
	if (i < 0 || i>(*SL)->length)return 0;
	(*SL)->data[i] = x;
	(*SL)->length++;
	return 1;
}
int find_place(SqList* SL, elemdata x)
{   
	if ((*SL)->length == 0)return 0;
	for (int i = 0; i < (*SL)->length; i++)
		if ((*SL)->data[i] == x)return i;
	return MAXSIZE;
}
int delete_node(SqList* SL, elemdata x)
{
	int pos = find_place(SL, x);
	if (pos == MAXSIZE)return 0;
	for (int i = pos; i < (*SL)->lengh - 1; i++)
		(*SL)->data[i] = (*SL)->data[i + 1];
	(*SL)->length--;
	return 1;
}
int change(SqList* SL, int pos, elemdata x)
{   
	if ((*SL)->length == 0)return 0;
	(*SL)->data[pos] = x;
	return 1;
}
int print(SqList* SL)
{
	for (int i = 0; i < (*SL)->length; i++)
		printf((*SL)->data[i]);
	return 1;
}
int sum(SqList* SL,SqList*SL2)
{
	SqList* SL3=(SqList*)malloc(sizeof(SqList)); Init_SqList(SL3);
	int t1 = t2 = t3 = 0;
	while (t1 != (*SL)->length && t2 != (*SL2)->length)
	{
		if ((*SL)->data[t1] < (*SL)->data[t2])
			(*SL3)->data[t3++] = (*SL)->data[t1++];
		else
			(*SL3)->data[t3++] = (*SL2)->data[t2++];
	}
	if (t1 == (*SL)->length && t2 != (*SL2)->length)
	{
		for (int i = 0; i < (*SL2)->length; i++)
			(*SL3)->data[t3++] = (*SL2)->data[i];
	}
	if (t2 == (*SL2)->length && t1 != (*SL)->length)
	{
		for (int i = 0; i < (*SL)->length; i++)
			(*SL3)->data[t3++] = (*SL)->data[i];
	}
	return 1;
}
______________________________________________________________________________________________________________
int InitStack(SqStack* S)
{
	(*S) = new Stack;
	(*S)->top = -1;
	return 1;
}
int fullStack(SqStack* S)
{
	if ((*S)->top + 1 = MAXSIZE)return 1;
	else
		return 0;
}
int push(SqStack* S, elemdata x)
{   
	if (fullStack(S))return 0;
	(*S)->data[++top] = x;
	return 1;
}
int EmptyStack(SqStack* S)
{
	if ((*S)->top = -1)return 1;
	else
		return 0;
}
int pop(SqStack* S)
{
	if (EmptyStack(S))return 0;
	(*S)->top--;
	return 1;
}
int getttop(SqStack* S,elemdata*e)
{   
	if (EmptyStack(S))return 0;
	*e = (*S)->data[top];
	return 1;
}
int print(SqStack* S)
{   
	if (EmptyStack(S))return 0;
	for (int i = (*S)->top; i != -1; i--)
		printf((*S)->data[i]);
	return 1
}
______________________________________________________________________________________________________
int InitQueue(SqQueue* Q)
{
	*Q = new Queue;
	(*Q)->size = MAXSIZE-1;
	(*Q)->front = (*Q)->rear = 0;
	return 1;
}
int FullQueue(SqQueue* Q)
{
	if (((*Q)->rear + 1) % (*Q)->size == (*Q)->front)return 1;
	else
		return 0;
}
int EnQueue(SqQueue* Q,elemdata x)
{
	if (FullQueue(Q))return 0;
	(*Q->data[(*Q)->rear] = x;
	(*Q)->rear = ((*Q)->rear + 1) & (*Q)->size;
	return 1
}
int EmptyQueue(SqQueue* Q)
{
	if ((*Q)->front == (*Q)->rear)return 1;
	else
		return 0;
}
int DeQueue(SqQueue* Q, elemdata *e)
{
	if (EmptyQueue(Q))return 0;
	*e=(*Q->data[(*Q)->front];
	(*Q)->front = ((*Q)->front + 1) & (*Q)->size;
	return 1
}
int Queue_Length(SqQueue* Q)
{
	return ((*Q)->rear - (*Q)->front+(*Q)->size) % (*Q)->size;
}
_______________________________________________________________________________________________
int create_tree(BiTree* T)
{
	scanf_s(elemdata x);
	if (x == '#')*T = NULL;
	else
	{
		(*T)->lchild = new BiNode; (*T)->rchild = new BiNode;
		create_tree(&(*T)->lchild);
		create_tree(&(*T)->rchild);
	}
}
int postorder(BiTree* T)
{
	if ((*T)->lchild)postorder(&(*T)->lchild);
	if ((*T)->rchild)postorder(&(*T)->rchild);
	if(!*T)visit(*T);
	return 1;
}
int level_order(BiTree* T)
{
	SqQueue* Q = new SqQueue; InitQueue(Q);
	EnQueue(Q, *T);
	while (!EmptyQueue(Q))
	{
		BiTree e = new BiNode; DeQueue(Q, e);
		visit(e);
		if (e->lchild)EnQueue(Q, e->lchild);
		if (e->rchild)EnQueue(Q, e->rchild);
	}
	return 1;
}
___________________________________________________________________________________
int create_matrix(MGraph* GL)
{
	scanf_s((*GL)->VexNum, (*GL)->ArcNum);
	for (int i = 0; i < (*GL)->vexNum; i++)
		scanf_s((*GL)->Vex[i]);
	for (int i = 0; i < (*GL)->VexNum; i++)
		for (int j = 0; j < (*GL)->VexNum; j++)
			(*GL)->Arcs[i][j] = 0
	for (int i = 0; i < (*GL)->ArcNum; i++)
	{
		scanf_s(v0, vt);
		Arcs[i - 1][j - 1] = Arcs[j - 1][i - 1] = 1;
	}
	return 1;
}
int depth_find(MGraph* GL,int v[],int u)
{	
	visit(u,GL); v[u] = 1;
	for (int i = 0; i < (*GL)->VexNum; i++)
	{
		if (v[i] == 0 && (*GL)->Arcs[u][i] != 0)
			depth_find(GL, v, i);
	}
}
int depth(MGraph* GL,int start)
{
	int v[MAXSIZE] = { 0 };
	depth_find(GL, v, start);
	for (int i = 0; i < (*GL)->VexNum; i++)
		depth_find(GL, v, i);
	return 1;
}
int Breadth_traversal(MGraph* GL, int start, int v[])
{
	SqQueue* Q = new SqQueue; InitQueue(Q);
	v[start] = 1; printf((*GL)->Vex[start]); EnQueue(Q, start);
	while (!EmptyQueue)
	{
		int x; DeQueue(Q, x);
		for (int i = 0; i < (*GL)->VexNum; i++)
		{
			if (v[i] == 0 && (*GL)->Arcs[x][i] != 0)
				v[i] = 1; visit(i, GL); EnQueue(Q, i);
		}
	}
}
int Breadth(MGraph*GL,int start)
{
	int v[MAXSIZE] = { 0 };
	Breadth_traversal(GL, start, v);
	for (int i = 0; i < (*GL)->VexNum; i++)
		Breadth_traversal(GL, i, v);
	return 1;
}
________________________________________________________________________________________
int create_table(ALGraph* AL)
{
	scanf_s((*AL)->VexNum, (*AL)->ArcNum);
	for (int i = 0; i < (*AL)->VexNum; i++)
		scanf_s((*AL)->adjvex[i].data);
	for (int i = 0; i < (*AL)->VexNum; i++)
		(*AL)->adjvex[i].next = NULL;
	for (int i = 0; i < ArcNum; i++)
	{
		scanf_s(v0, vt);
		ArcNode e; e.adjvex = vt;
		e->nextArc = (*AL)->adjvex[v0]->firstArc;
		(*AL)->adjvex[v0]->firstArc = e;
	}
	return 1;
}
int depth_find(ALGraph* AL, int v[], int u)
{
	visit(u, AL); v[u] = 1;
	for (ArcNode*p=(*AL)->firstArc;p; p=p->nextArc)
	{
		if (v[i] == 0)
			depth_find(AL, v, i);
	}
}
int depth(MGraph* GL, int start)
{
	int v[MAXSIZE] = { 0 };
	depth_find(AL, v, start);
	for (ArcNode* p = (*AL)->firstArc; p; p = p->nextArc)
	{
		if (v[i] == 0)
			depth_find(AL, v, i);
	}
	return 1;
}
int Breadth_traversal(ALGraph* AL, int start, int v[])
{
	SqQueue* Q = new SqQueue; InitQueue(Q);
	v[start] = 1; printf((*AL)->adjvex[start].data); EnQueue(Q, start);
	while (!EmptyQueue)
	{
		int x; DeQueue(Q, x);
		for (ArcNode* p = (*AL)->firstArc; p; p = p->nextArc)
		{
			if (v[i] == 0)
				v[i] = 1; visit(AL, i); EnQueue(Q, i);
		}
	}
}
int Breadth(ALGraph* AL, int start)
{
	int v[MAXSIZE] = { 0 };
	Breadth_traversal(AL, start, v);
	for (ArcNode* p = (*AL)->firstArc; p; p = p->nextArc)
	{
		if (v[i] == 0)
			Breadth_traversal(AL,start,v)
	}
	return 1;
}
_______________________________________________________________