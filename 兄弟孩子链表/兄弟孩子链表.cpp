#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAXSIZE 20
typedef struct node
{
	int data;
	struct node* firstchild;
	struct node* nextsibling;
}CSNode,*CSTree;
typedef struct 
{
	CSTree ElemData[MAXSIZE];
	int front;
	int rear;
	int QueueSize;
}Queue,*SqQueue;
int InitQueue(SqQueue* Q)
{
	(*Q) = (SqQueue)malloc(sizeof(Queue));
	(*Q)->front = (*Q)->rear = 0;
	(*Q)->QueueSize = MAXSIZE;
	return 1;
}
int EnQueue(SqQueue* Q,CSTree x)
{
	(*Q)->ElemData[(*Q)->rear] = x;
	(*Q)->rear = ((*Q)->rear + 1) % (*Q)->QueueSize;
	return 1;
}
int DeQueue(SqQueue* Q)
{    
	if ((*Q)->rear == (*Q)->front)return 0;
	(*Q)->front= ((*Q)->front + 1) % (*Q)->QueueSize;
	return 1;
}
int gethead(SqQueue* Q, CSTree* T)
{
	if ((*Q)->rear == (*Q)->front)return 0;
	*T = (*Q)->ElemData[(*Q)->front];
	return 1;
}
int InitTree(CSTree* T)
{
	(*T) = (CSTree)malloc(sizeof(CSNode));
	(*T)->firstchild = (*T)->nextsibling = NULL;
	printf("根节点创建成功!\n");
	return 1;
}
int write_in(CSTree* T)
{   
	if (!*T)return 0;
	scanf_s("%d", &(*T)->data);
	if ((*T)->data == 0)
	{
		(*T) = NULL; return 0;
	}
	(*T)->nextsibling = (CSTree)malloc(sizeof(CSNode));
	(*T)->firstchild = (CSTree)malloc(sizeof(CSNode));
	printf("请输入下个兄弟值(0退出):");
	if ((*T)->nextsibling)write_in(&(*T)->nextsibling);
	printf("请输入第一个孩子值(0退出):");
	if ((*T)->firstchild)write_in(&(*T)->firstchild);
	return 1;
}
int levelwrite(CSTree* T)//读边法创建树
{   
	int fa, so;
	CSTree p,s, r = new CSNode; SqQueue* Q = new SqQueue;
	InitQueue(Q);
	printf("请输入父结点值，该结点值(0退出):");
	scanf_s("%d,%d", &fa, &so);
	while (so != 0)
	{
		p = new CSNode;
		p->data = so; p->firstchild = p->nextsibling = NULL;
		EnQueue(Q, p);
		if (fa == 0)*T = p;
		else
		{
			s = new CSNode;
			gethead(Q, &s);
			while (s->data != fa)
			{
				DeQueue(Q);
				gethead(Q, &s);
			}
			if (!s->firstchild)
			{   
				s->firstchild = p;
				r = p;                
			}
			else
			{
				r->nextsibling = p;//由于刚创建的时候没有孩子，所以迭代后r永远指向最新孩子
				r = p;
			}
		}
		printf("请输入父结点值，该结点值(0退出):");
		scanf_s("%d,%d", &fa, &so);
	}
	return 1;
}
int print(CSTree* T)
{   
	if (!*T)return 0;
	SqQueue* Q = (SqQueue*)malloc(sizeof(SqQueue));
	InitQueue(Q);
	CSTree p = (*T),q;
	EnQueue(Q, p);  //该开始先初始化第一个根节点入队
	if (p->nextsibling)//若还有其他根节点，将所有根节点优先入队
	{   
		p = p->nextsibling;
		while (p)
		{   
			EnQueue(Q, p);
			p = p->nextsibling;
		}
	}
	while ((*Q)->rear != (*Q)->front)
	{
		gethead(Q, &p);
		printf("%d ", p->data);
		if(p->firstchild)    //若有下一层,优先将下一层的所有子树全入队
		{
			q = p->firstchild;
			EnQueue(Q, p->firstchild);
			if (q->nextsibling)
			{
				q = q->nextsibling;
				while (q)
				{
					EnQueue(Q, q);
					q = q->nextsibling;
				}
			}
		}
		DeQueue(Q);
	}
	return 1;
}
int preprint(CSTree* T)
{   
	if (!*T)return 0;
	printf("%d ", (*T)->data);
	if((*T)->firstchild)preprint(&(*T)->firstchild);
	if ((*T)->nextsibling)preprint(&(*T)->nextsibling);
	return 1;
}
int find_data(CSTree* T,SqQueue*Q, int x)
{
	if (*T == NULL)return 0;
	if ((*T)->data == x)EnQueue(Q, *T);
	if ((*T)->nextsibling)find_data(&(*T)->nextsibling, Q, x);
	if ((*T)->firstchild)find_data(&(*T)->firstchild, Q, x);
	return 1;
}
int deleteNode(CSTree* T)
{
	if (!*T)return 0;
	deleteNode(&(*T)->firstchild);
	deleteNode(&(*T)->nextsibling);
	free(*T); (*T) = NULL;
	return 1;
}
int delete_tree(CSTree* T,int x)
{   
	if (!*T)return 0;
	CSTree* p = new CSTree, * q = new CSTree;
	*p = (*T)->firstchild; *q = (*T)->nextsibling;
	if (*p && (*p)->data == x)//第一个孩子要被删除，就修改它第一个孩子的值
	{
		(*T)->firstchild = (*p)->nextsibling; (*p)->nextsibling = NULL;//将q孤立出来避免对兄弟删除
		printf("已删除!"); deleteNode(p); 
		return 1;
	}
	else if (*q&&(*q)->data == x )//下个兄弟被删除，就跳过它下个兄弟
	{   
		(*T)->nextsibling = (*q)->nextsibling; (*q)->nextsibling = NULL; 
		printf("已删除!"); deleteNode(q); 
		return 1;
	}
	else if ((*T)->data == x)
	{
		printf("已删除!"); deleteNode(q); deleteNode(T);
		*T = NULL;
		return 1;
	}
	else if((*T)->nextsibling)delete_tree(&(*T)->nextsibling, x);
	else if ((*T)->firstchild)delete_tree(&(*T)->firstchild, x);
	return 1;
}
int delete_bylevel(CSTree* T)
{   
	if (!*T)return 0;
	int x,t=1,i; printf("请输入你要删除的根节点的值");
	scanf_s("%d", &x);
	SqQueue* Q = (SqQueue*)malloc(sizeof(SqQueue));
	InitQueue(Q);
	CSTree p = (*T), q,s,r=new CSNode;
	EnQueue(Q, p);  //该开始先初始化第一个根节点入队
	if (p->nextsibling)//若还有其他根节点，将所有根节点优先入队
	{
		p = p->nextsibling;
		while (p)
		{
			EnQueue(Q, p);
			p = p->nextsibling;
		}
	}
	if ((*T)->data == x)//如果是根节点需要先把根节点置空
	{
		deleteNode(T); *T = NULL;
		return 0;
	}
	while ((*Q)->rear != (*Q)->front)
	{
		gethead(Q, &p);
		if(p->data==x)//若该数为删除结点,就执行删除
		{  
			s = new CSNode;
			gethead(Q, &s);
			i = 0;
			while (s->firstchild!=p&&s->nextsibling!=p)//在前面找p的前驱
			{
				s = (*Q)->ElemData[i];
				i++;
			}
			if (s->firstchild == p)//s->firstchild是p
			{
				s->firstchild = p->nextsibling;
				r = p;
				r->nextsibling = NULL;
				deleteNode(&r);
				printf("已删除!\n");
				t = 0;
			}
			else//s->nextsibling = p
			{
				s->nextsibling = p->nextsibling;
				r = p;
			    r->nextsibling = NULL;
				deleteNode(&r);
				printf("已删除!\n");
				t = 0;
			}
		}
		if (p->data != x)//若不是删除结点，则向下层次遍历
		{
			q = p->firstchild;
			if (t && q)    //若有下一层,优先将下一层的所有子树全入队
			{
				EnQueue(Q, q);
				if (q->nextsibling)
				{
					q = q->nextsibling;
					while (q)
					{
						EnQueue(Q, q);
						q = q->nextsibling;
					}
				}
			}
		}
		DeQueue(Q);
	}
	return 1;
}
int inserttree(CSTree* T, CSTree* T1,int x)
{    
	if (!*T)return 0;
	if ((*T)->data == x)//注意，实施结点增加后应该即时返回，以免已插入子树的遍历
	{
		CSTree r = new CSNode;
		r = (*T)->firstchild;
		if (!r)
		{
			(*T)->firstchild = *T1;
		}
		else
		{   
			while (r->nextsibling)r = r->nextsibling;
			r->nextsibling = *T1;
		}
		return 0;
	}
	inserttree(&(*T)->firstchild, T1, x);
	inserttree(&(*T)->nextsibling, T1, x);
	return 1;
}
int sort_down_byname(CSTree* T)
{
	if (!(*T)->firstchild)return 0;
	CSTree p = (*T)->firstchild; (*T)->firstchild = nullptr;
	while (p)
	{
		CSTree q = (*T)->firstchild;
		CSTree r = p->nextsibling;
		while (q && q->data>p->data)
		{
			q = q->nextsibling;
		}
		if (!q)
		{
			p->nextsibling = (*T)->firstchild; (*T)->firstchild = p;
		}
		else
		{
			p->nextsibling = q->nextsibling; q->nextsibling = p;
		}
		p = r;
	}
	return 1;
}
int main()
{   
	int num,x,i,fa,so;
	CSTree* T = (CSTree*)malloc(sizeof(CSTree));
	InitTree(T);
	/*printf("请输入值(0退出):");
	write_in(T);*/
	levelwrite(T);
	while (1)
	{   
		system("cls");
		printf("层次遍历树为:");
		print(T);
		printf("先根遍历树为:");
		preprint(T);
		printf("\n请执行你的操作:1 查找2 删除子树(层次版)3 增加子树4 递归删除\n");
		scanf_s("%d", &num);
		if (num == 1)
		{   
			SqQueue* Q = (SqQueue*)malloc(sizeof(SqQueue));
			InitQueue(Q);
			printf("请输入你要查找的值:");
			scanf_s("%d", &x);
			find_data(T,Q,x);
			for (i = 0; i <(*Q)->rear; i++)
				printf("%d ", (*Q)->ElemData[i]);
		}
		if (num == 2)
		{   
			/*printf("请输入你要删除的子树根节点的值:");
			scanf_s("%d", &x);
			CSTree* U = new CSTree; (*U) = new CSNode; 
			(*U)->firstchild = (*T); (*U)->nextsibling = NULL;
			delete_tree(U,x);*/
			delete_bylevel(T);
		}
		if (num == 3)
		{
			CSTree* T1 = (CSTree*)malloc(sizeof(CSTree));
			InitTree(T1);
			levelwrite(T1);
			printf("请输入你要插入的父节点值:");
			scanf_s("%d", &x);
			inserttree(T,T1,x);
		}
		if (num == 4)
		{
			printf("请输入你要删除的子树根节点的值:");
			scanf_s("%d", &x);
			delete_tree(T,x);
		}
		if (num == 5)
		{
			sort_down_byname(T);
		}
		printf("按任意键继续操作\n");
		getchar(); getchar();
	}
	return 0;
}