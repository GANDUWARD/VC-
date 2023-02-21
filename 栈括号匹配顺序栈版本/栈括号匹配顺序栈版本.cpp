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
int push(SqStack* S, char x)
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
int check_empty(SqStack* S)
{
	if (S->top == -1) { return 1; }
	else return 0;
}
int find(SqStack* S, char dusha[])
{
    int i, p; char c;
    char x;
    for (i = 0; dusha[i] != '\0'; i++)
    {
        if (dusha[i] == '(' || dusha[i] == '['||dusha[i]=='{')
        {
            x = dusha[i];
            push(S, x);
        }
        if (dusha[i] == ')' || dusha[i] == ']'||dusha[i]=='}')
        {
            c = S->data[S->top];
            if (dusha[i] == ')' && c == '(')
            {
                pop(S); continue;
            }
            if (dusha[i] == ']' && c == '[')
            {
                pop(S); continue;
            }
            if (dusha[i] == '}' && c == '{')
            {
                pop(S); continue;
            }
            else
            {
                printf("匹配不成功！（右括号剩余)");
                return 1;
            }
        }
    }
    if ((p = check_empty(S)) == 1)
    {
        printf("匹配成功!");
        return 1;
    }
    else
    {
        printf("匹配不成功！（左括号剩余)");
        return 1;
    }

}
int main()
{
	int i, x;
	SqStack* S = (SqStack*)malloc(sizeof(SqStack));
    printf("请输入括号式:（如()[]{}）");
	char dusha[20];
	scanf_s("%s", dusha, 20);
	InitSqStack(S);
    find(S, dusha);
	return 1;
}