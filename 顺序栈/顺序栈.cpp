#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE 20
typedef struct
{
	int* data;
	int top;
	int stackSize;
}SqStack;
int InitSqStack(SqStack* S)
{
	S->data = (int*)malloc(sizeof(int) * MAXSIZE);
	S->top = -1;
	S->stackSize = MAXSIZE;
	return 1;
}
int putstack(SqStack* S,int x)
{
	S->data[++S->top] = x;
	return 1;
}
int print(SqStack* S)
{    
	int i;
	if (S->top == -1) { printf("空栈！"); return 0; }
	for (i = 0; i <= S->top; i++)
		printf("%d ", S->data[i]);
	return 1;
}
int pop(SqStack* S)
{
	if (S->top == -1) { printf("空栈！"); return 0; }
	S->top--;
}
int main()
{
	int i,x;
	SqStack* S = (SqStack*)malloc(sizeof(SqStack));
	InitSqStack(S);
	for (i = 0; i < 4; i++)
	{
		scanf_s("%d", &x);
		putstack(S, x);
	}
	print(S);
}

