#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define MAXSIZE 20
typedef struct node
{
	float num;
	struct node* lchild;
	struct node* rchild;
}BiNode,*BiTree;
typedef struct dusha
{
	BiTree StackData;
	struct dusha* next;
}Lnode,*LinkStack;
typedef struct 
{
	char ope[MAXSIZE];
	int top;
	int size;
}FloatStack,*FStack;
int InitStack(LinkStack* L)
{
	*L = new Lnode;
	(*L)->next = NULL;
	return 1;
}
int InitStack2(FStack* S)
{
	*S = (FStack)malloc(sizeof(FloatStack));
	(*S)->top = -1;
	(*S)->size = MAXSIZE;
	return 1;
}
int pop(LinkStack* L)
{
	if (!(*L)->next)return 0;
	Lnode* p = (*L)->next;
(*L)->next= p->next;
	free(p);
	return 1;
}
int pop2(FStack* S)
{
	if ((*S)->top == -1)return 0;
	(*S)->top--;
	return 1;
}
int push(LinkStack* L, BiTree x)
{
	Lnode* p = new Lnode;
	p->StackData = x;
	p->next = (*L)->next;
	(*L)->next = p;
	return 1;
}
int push2(FStack* S,char x)
{
	(*S)->ope[++(*S)->top] = x;
	return 1; 
}
int gettop(LinkStack* L, BiTree* e)
{
	if (!(*L)->next)return 0;
	*e = (*L)->next->StackData;
	return 1;
}
int gettop2(FStack* S, char* ope)
{
	if ((*S)->top == -1)return 0;
	*ope = (*S)->ope[(*S)->top];
	return 1;
}
int InitTree(BiTree* T)
{
	(*T) = new BiNode;
	(*T)->lchild = (*T)->rchild = NULL;
	printf("树创建成功!\n");
	return 1;
}
int prior(char x)
{
	if (x == '*' || x == '/')return 4;
	if (x == '+' || x == '-')return 3;
	if (x == '(')return 2;
	if (x == '#')return 1;
	else
		return 0;
}
int calculate(char x,LinkStack*L)
{   
	BiTree  p,q,r = new BiNode; r->lchild = r->rchild = NULL;
	gettop(L, &p); pop(L); gettop(L, &q); pop(L);
	if (x == '+')
	{
		r->num = q->num + p->num;
	}
	if (x == '-')
	{
		r->num = q->num - p->num;
	}
	if (x == '*')
	{
		r->num = q->num * p->num;
	}
	if (x == '/')
	{
		if (p->num != 0)r->num = q->num / p->num;
		else
		{
			printf("不能除以零");
			exit(0);
		}
	}
	r->lchild = q; r->rchild = p;
	push(L, r);
	return 1;
}
int judge_number(char famula[], int i,LinkStack* S2)
{
	float t = famula[i] - 48, q = 0; i++;
	while (famula[i] >= '0' && famula[i] <= '9')//整数部分
	{
		t = t * 10 + famula[i++] - 48;
	}
	if (famula[i] == '.')//小数部分
	{
		q = 0.1; i++;
		while (famula[i] >= '0' && famula[i] <= '9')
		{
			t += (famula[i++] - 48) * q;
			q *= 0.1;
		}
	}
	BiTree T = new BiNode; T->num = t; T->lchild = T->rchild = NULL;
	push(S2, T);
	return i;
}
int gettree(char famula[])
{   
	int i = 0; char ope; BiTree T=new BiNode;
	LinkStack* L = new LinkStack; FStack* S = new FStack;
	InitStack(L); InitStack2(S); push2(S, '#');
	while (famula[i] != '\0')
	{    
		if (famula[i] >= '0' && famula[i] <= '9')
		{
			i = judge_number(famula, i, L); continue;
		}
		if (famula[i] == '+' || famula[i] == '-' || famula[i] == '*' || famula[i] == '/') //运算符入栈
		{
			push2(S, famula[i++]); continue;
		}
		if (famula[i] == '(')
		{
			push2(S, famula[i++]); continue;  //直接将（入栈，并查看下一个
		}
		if (famula[i] == ')')
		{    
			gettop2(S, &ope);
			while (ope != '(')
			{
				calculate(ope, L);
			     pop2(S); gettop2(S, &ope);
			}
			pop2(S); i++; continue;
		}
		gettop2(S, &ope);
		if (prior(ope) >= prior(famula[i])) //栈顶元素大于运算符
		{
			pop2(S); calculate(ope, L); i++; continue;   //先出栈，计算并创建新节点
		}
		if (prior(ope) < prior(famula[i])) //栈顶元素小于运算符.
		{
			push2(S, famula[i++]); continue;
		}
	}
	gettop2(S, &ope);
	if ( ope== '#')
	{
		gettop(L, &T); pop(L);
	}
	printf("答案是%f", T->num);
	return 1;
}
int main()
{   
	char famula[20];
	BiTree* T = (BiTree*)malloc(sizeof(BiTree));
	InitTree(T);
	printf("请输入表达式(以#结尾)\n");
	scanf_s("%s", famula, 20);
	gettree(famula);
	return 0;
}