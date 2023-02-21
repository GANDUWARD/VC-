#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAXSIZE 20
typedef struct node
{
    char string[20];
	struct node* firstchild;
	struct node* nextsibling;
}CSNode, * CSTree;
typedef struct
{
	CSTree ElemData[MAXSIZE];
	int front;
	int rear;
	int QueueSize;
}Queue, * SqQueue;
typedef struct
{
	CSTree data[MAXSIZE];
	int top;
}Stack,*SqStack;
int InitStack(SqStack* S)
{   
	*S = new Stack;
	(*S)->top = -1;
	return 1;
}
int push(SqStack* S, CSTree x)
{
	(*S)->data[++(*S)->top] = x;
	return 1;
}
int pop(SqStack* S)
{    
	if ((*S)->top == -1)return 0;
	(*S)->top--;
	return 1;
}
int gettop(SqStack* S, CSTree* e)
{
	if ((*S)->top == -1)return 0;
	*e = (*S)->data[(*S)->top];
	return 1;
}
int InitQueue(SqQueue* Q)
{
	(*Q) = (SqQueue)malloc(sizeof(Queue));
	(*Q)->front = (*Q)->rear = 0;
	(*Q)->QueueSize = MAXSIZE;
	return 1;
}
int EnQueue(SqQueue* Q, CSTree x)
{
	(*Q)->ElemData[(*Q)->rear] = x;
	(*Q)->rear = ((*Q)->rear + 1) % (*Q)->QueueSize;
	return 1;
}
int DeQueue(SqQueue* Q)
{
	if ((*Q)->rear == (*Q)->front)return 0;
	(*Q)->front = ((*Q)->front + 1) % (*Q)->QueueSize;
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
	scanf_s("%s", (*T)->string,20);
	if (strcmp((*T)->string,"#")==0)
	{
		(*T) = NULL; return 0;
	}
	(*T)->nextsibling = (CSTree)malloc(sizeof(CSNode));
	(*T)->firstchild = (CSTree)malloc(sizeof(CSNode));
	printf("请输入下个兄弟值(#退出):");
	if ((*T)->nextsibling)write_in(&(*T)->nextsibling);
	printf("请输入第一个孩子值(#退出):");
	if ((*T)->firstchild)write_in(&(*T)->firstchild);
	return 1;
}
int print(CSTree* T)
{
	if (!*T)return 0;
	SqQueue* Q = (SqQueue*)malloc(sizeof(SqQueue));
	InitQueue(Q);
	CSTree p = (*T), q;
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
		printf("%s ", p->string);
		if (p->firstchild)    //若有下一层,优先将下一层的所有子树全入队
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
int inserttree(CSTree* T, CSTree* T1, char x[],int*u)
{        
	if (!*T)return 0;
	if (strcmp((*T)->string,x)==0)//注意，实施结点增加后应该即时返回，以免已插入子树的遍历
	{   
		*u = 1;
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
	inserttree(&(*T)->firstchild, T1, x,u);
	inserttree(&(*T)->nextsibling, T1, x,u);
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
int delete_bylevel(CSTree* T)
{
	if (!*T)return 0;
	char x[20];
	int  t = 1, i,u=0; printf("请输入你要删除的根节点的值");
	scanf_s("%s", &x,20);
	SqQueue* Q = (SqQueue*)malloc(sizeof(SqQueue));
	InitQueue(Q);
	CSTree p = (*T), q, s, r = new CSNode;
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
	if (strcmp((*T)->string,x)==0)//如果是根节点需要先把根节点置空
	{   
		u = 1;
		deleteNode(T); *T = NULL;
		return 0;
	}
	while ((*Q)->rear != (*Q)->front)
	{
		gethead(Q, &p);
		if (strcmp(p->string, x) == 0)//若该数为删除结点,就执行删除
		{    
			u = 1;
			s = new CSNode;
			gethead(Q, &s);
			i = 0;
			while (s->firstchild != p && s->nextsibling != p)
			{
				s = (*Q)->ElemData[i];
				i++;
			}
			if (s->firstchild == p)
			{
				s->firstchild = p->nextsibling;
				r = p;
				r->nextsibling = NULL;
				deleteNode(&r);
				printf("已删除!\n");
				t = 0;
			}
			else
			{
				s->nextsibling = p->nextsibling;
				r = p;
				r->nextsibling = NULL;
				deleteNode(&r);
				printf("已删除!\n");
				t = 0;
			}
		}
		if (strcmp(p->string, x) != 0)//若不是删除结点，则向下层次遍历
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
	if (u == 0)printf("未找到该位置!\n");
	return 1;
}	 
int plotprint(CSTree* T,int n)
{
	int i;
	if (!*T)return 0;
	for (i = 0; i < n; i++)
		printf("-");
	printf("%s\n", (*T)->string);
	plotprint(&(*T)->nextsibling, n);
	plotprint(&(*T)->firstchild, n+2);
	return 1;
}
int find_path(CSTree*T,int*u,SqStack*S,char x[])
{   
	if (!*T)return 0;
	push(S, *T);
	if (strcmp(x, (*T)->string) == 0)
	{
		int i = 0; *u = 1;
		for (i = 0; i <= (*S)->top; i++)
			printf("%s", (*S)->data[i]);
		return 0;
	}
	if (!(*T)->firstchild)//叶子结点，不需要往下层遍历
	{
		pop(S);
		find_path(&(*T)->nextsibling, u, S, x);
		return 0;
	}
	else
	{
		find_path(&(*T)->firstchild, u, S, x);
		find_path(&(*T)->nextsibling, u, S, x);
		pop(S);//一个结点使命完成了，就可以出栈
		return 0;
	}
}
int main()
{
	int num, i; int* u = new int;
	char x[20];
	CSTree* T = (CSTree*)malloc(sizeof(CSTree));
	InitTree(T);
	printf("请输入值(#退出):");
    write_in(T);
	while (1)
	{
		system("cls");
		printf("层次遍历树为:");
		print(T);
		printf("\n请执行你的操作:1 凹入表显示2 删除子树3 增加子树4 求路径\n");
		scanf_s("%d", &num);
		if (num == 1)
		{   
			i = 7;
			plotprint(T,i);
		}
		if (num == 2)
		{
			delete_bylevel(T);
		}
		if (num == 3)
		{
			*u = 0;
			CSTree* T1 = (CSTree*)malloc(sizeof(CSTree));
			InitTree(T1);
			printf("请输入值(#退出):");
			write_in(T1);
			printf("请输入你要插入的父节点值:");
			scanf_s("%s", &x,20);
			inserttree(T, T1, x,u);
			if (*u == 0)printf("未找到该位置！\n");
		}
		if (num == 4)
		{   
			*u = 0;
			printf("请输入结点的值");
			scanf_s("%s", &x, 20);
			SqStack* S = new SqStack; InitStack(S);
			find_path(T, u, S,x);
		}
		printf("\n按任意键继续操作\n");
		getchar(); getchar();
	}
	return 0;
}