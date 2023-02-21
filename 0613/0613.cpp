#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE (10)
/*
测试样例:
0,2,0
2,7,0
2,14,1
7,19,0
14,78,1
14,62,0
19,40,1
19,0,0 

*/
typedef struct node
{
	int data;
	struct node* lchild;
	struct node* rchild;
}TreeNode,*BiTree;
typedef struct
{
	BiTree data[MAXSIZE];
	int front;
	int rear;
	int QueueSize;
}Queue,*SqQueue;
int InitQueue(SqQueue* Q)
{
	*Q = new Queue;
	(*Q)->rear = (*Q)->front = 0;
	(*Q)->QueueSize = MAXSIZE - 1;
	return 1;
}
int EmptyQueue(SqQueue* Q)
{
	if ((*Q)->rear == (*Q)->front)return 1;
	else
		return 0;
}
int EnQueue(SqQueue* Q, BiTree x)
{
	(*Q)->data[(*Q)->rear] = x;
	(*Q)->rear = ((*Q)->rear + 1) % (*Q)->QueueSize;
	return 1;
}
int DeQueue(SqQueue* Q)
{   
	if (EmptyQueue(Q))return 0;
	(*Q)->front = ((*Q)->front + 1) % (*Q)->QueueSize;
	return 1;
}
int getfront(SqQueue* Q, BiTree* e)
{   
	if (EmptyQueue(Q))return 0;
	*e = (*Q)->data[(*Q)->front];
	return 1;
}
int InitTree(BiTree* T)
{
	*T = new TreeNode;
	(*T)->lchild = (*T)->rchild = NULL;
	return 1;
}
int level_write(BiTree* T)
{
	SqQueue* Q = new SqQueue; InitQueue(Q); int fa, so, ta;
	printf("请输入父亲值(0是根),结点值(0退出),任务值(0左1右):");
	scanf_s("%d,%d,%d", &fa, &so, &ta);
	while (so != 0)
	{
		BiTree x ; InitTree(&x); x->data = so; EnQueue(Q, x);
		if (fa == 0)*T = x;
		else
		{
			BiTree s=new TreeNode; getfront(Q, &s);
			while (s->data != fa)
			{
				DeQueue(Q);
				getfront(Q, &s);
			}
			if (s->data == fa)
			{
				if (ta == 0)s->lchild = x;
				if (ta == 1)s->rchild = x;
			}
		}
		printf("请输入父亲值(0是根),结点值(0退出),任务值(0左1右):");
		scanf_s("%d,%d,%d", &fa, &so, &ta);
	}
	return 1;
}
int table_show(BiTree* T,int space)
{
	if (!*T)return 0;
	for (int i = 0; i < space; i++)
		printf("----");
	printf("%d\n", (*T)->data);
	table_show(&(*T)->lchild, space +1);
	table_show(&(*T)->rchild, space +1);
	return 1;
}
int calculate_depth(BiTree* T)
{
	if (!*T)return 0;
	int m =0,n=0;
	m = calculate_depth(&(*T)->lchild);
	n = calculate_depth(&(*T)->rchild);
	if (m > n)return m + 1;
	else
		return n + 1;
}
int calculate_strench(BiTree* T,int *st)
{
	if (!*T)return 0;
	if (!(*T)->lchild && !(*T)->rchild)return 0;//叶子结点不算
	else//非叶子结点才参与计数
	{
		(*st)++;
	}
	calculate_strench(&(*T)->lchild, st);
	calculate_strench(&(*T)->rchild, st);
	return 1;
}
int calculate_node(BiTree* T, int* node)
{
	if (!*T)return 0;
	(*node)++;
	calculate_node(&(*T)->lchild, node);
	calculate_node(&(*T)->rchild, node);
	return 1;
}
int find_out(BiTree* T, int x,int* find,int *node)
{
	if (!*T||*find==1)return 0;
	if ((*T)->data == x)
	{
		*find = 1; calculate_node(T, node);//找到该子根就开始计算其子树结点总数
	}
	find_out(&(*T)->lchild, x, find,node);
	find_out(&(*T)->rchild, x, find,node);
	return 1;
}
int level_find_and_print(BiTree* T, int x, int* find, int* width)
{
	SqQueue* Q = new SqQueue; InitQueue(Q);
	EnQueue(Q, *T); int level = (*Q)->rear; int u = 0; int first = (*Q)->front;
	BiTree e; InitTree(&e);//level是层次标签,first代表该层第一个元素号数，u代表宽度计算值
	while (!EmptyQueue(Q))
	{   
		getfront(Q,&e);
		DeQueue(Q); u++;
		if (e->data == x)
		{
			*find = 1;//找到先将标签置为1
		}
		if (e->lchild)EnQueue(Q, e->lchild);
		if (e->rchild)EnQueue(Q, e->rchild);
		if ((*Q)->front == level)//当一层结束后
		{
			if (*find == 1)//如果是已经找到的点说明要输出该层次
			{
				*width = u;//记忆宽度
				for (int i = first; i != level; i = (i + 1) % (*Q)->QueueSize)
					printf("%d ", (*Q)->data[i]->data);
				break;//要注意即时跳出
			}
			level = (*Q)->rear;//重新将层次标签初始化
			u = 0; first = (*Q)->front;//将宽度计算值重置为0，将首元素号数初始化
		}
	}
	return 1;
}
int arc_tree(BiTree* T, BiTree* T2)
{
	if (!*T)
	{
		(*T2) = NULL; return 0;//将T2该位置子点也置空
    }
	(*T2)->data = (*T)->data;//值的拷贝
	InitTree(&(*T2)->lchild); InitTree(&(*T2)->rchild);//先初始化左右子树
	arc_tree(&(*T)->lchild, &(*T2)->rchild);//注意赋值的反向性，故实参传入方向相反
	arc_tree(&(*T)->rchild, &(*T2)->lchild);
	return 1;
}
int back_print(BiTree* T)
{
	if (!*T)return 0;
	back_print(&(*T)->lchild);
	back_print(&(*T)->rchild);
	printf("%d ", (*T)->data);
	return 1;
}
int find_level(BiTree* T, int x, int* find, int* level)//非递归层次查找，也可以通过求深度的函数换皮得到
{
	SqQueue* Q = new SqQueue; InitQueue(Q);
	EnQueue(Q, *T); int send = (*Q)->rear; //u代表深度计算值，send代表层次标签
	BiTree e; InitTree(&e); int u = 1;
	while (!EmptyQueue(Q))
	{
		getfront(Q, &e);
		DeQueue(Q);
		if (e->data == x)
		{
			*find = 1; *level = u;//找到了x值，就完成给定level的赋值
		}
		if (e->lchild)EnQueue(Q, e->lchild);
		if (e->rchild)EnQueue(Q, e->rchild);
		if ((*Q)->front == send)//一层结束后加一
		{   
			u++;
			send = (*Q)->rear;
		}
	}
	return 1;
}
int main()
{
	BiTree* T = new BiTree; InitTree(T);
	level_write(T); int num;
	while (1)
	{   
		system("cls");
		printf("凹入法显示如图:\n");
		table_show(T,0);
		printf("请输入你的操作:1 求深度2 求分支结点个数3 给值查找，并输出结点数\n4 给值查找输出该层元素及个数5 创造镜像树并将其后序输出6 给值查找输出层次7 退出程序8 重构该树\n");
		scanf_s("%d", &num);
		if (num == 1)
		{
			int depth = calculate_depth(T);
			printf("深度是%d\n", depth);
		}
		if (num == 2)
		{
			int* st = new int; *st = 0;
			calculate_strench(T, st); printf("分支结点数是%d", *st);
		}
		if (num == 3)
		{
			int* find = new int; *find = 0; int* node = new int; *node = 0;
			int x; printf("请输入要查找值:");
			scanf_s("%d", &x); find_out(T, x, find,node);
			if (*find == 0)printf("未找到该点！\n");
			else
				printf("找到了以%d为根的子树，结点数为%d", x, *node);
		}
		if (num == 4)
		{
			int* search = new int; *search = 0; int* width = new int; *width = 0;
			int x; printf("请输入要查找值:");
			scanf_s("%d", &x); level_find_and_print(T, x, search, width);
			if (*search == 0)printf("未找到该点！\n");
			else
				printf("找到了以%d所在层次，结点数为%d", x, *width);
		}
		if (num == 5)
		{   
			BiTree* T2 = new BiTree; InitTree(T2);
			arc_tree(T, T2); printf("镜像树的后序输出如下:");
			back_print(T2);
		}
		if (num == 6)
		{
			int* find = new int; *find = 0; int* level = new int; *level = 0;
			int x; printf("请输入要查找值:");
			scanf_s("%d", &x); find_level(T, x, find, level);
			if (*find == 0)printf("未找到该点！\n");
			else
				printf("找到了%d的结点，层数为%d", x, *level);
		}
		if (num == 7)exit(0);
		if (num == 8)
		{
			InitTree(T); level_write(T);
		}
		printf("按任意键继续!");
		getchar(); getchar();
	}
	return 1;
}