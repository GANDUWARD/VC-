#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAXSIZE 30
typedef struct
{
	char*data;
	int top;
	int StackSize;
}SqStack;
typedef struct
{
	int* data;
	int top;
	int StackSize;
}IntStack;
int InitSqStack(SqStack* S)
{
	S->data = (char*)malloc(sizeof(char) * MAXSIZE);
	S->top = -1;
	S->StackSize = MAXSIZE;
	return 1;
}
int InitSqStack2(IntStack* S)
{
	S->data = (int*)malloc(sizeof(int) * MAXSIZE);
	S->top = -1;
	S->StackSize = MAXSIZE;
	return 1;
}
int ElmpStack(SqStack* S)
{
	if (S->top == -1)return 1;
	else return 0;
}
int push(SqStack* S, char x)
{
	S->data[++S->top] = x;
	return 1;
}
int push2(IntStack* S, int x)
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
	return 1;
}
int pop2(IntStack* S)
{
	if (S->top == -1) { printf("空栈！"); return 0; }
	S->top--;
	return 1;
}
int prior(char a)  //规定优先级乘除>加减>括号>尾#
{
	if (a == '#')return 1;
	if (a == '(')return 2;
	if (a == '+' || a == '-')return 3;
	if (a == '*' || a == '/')return 4;
	else return 0;
}
char gettop(SqStack* S)
{
	char ch = S->data[S->top];
	return ch;
}
int gettop2(IntStack* S)
{
	int i = S->data[S->top];
	return i;
}
char* find_Suffix(SqStack*S,char famula[])
{
	int i=0,j=0,l1=strlen(famula); char Suffix[50], ch;
	push(S, '#');         //给运算符栈进个#
	while (!ElmpStack(S) && i < l1 && j < l1)
	{
		if (famula[i] >= '0' && famula[i] <= '9') { Suffix[j++] = famula[i++]; continue; }//操作数
		if (famula[i] == '(')
		{
			push(S, famula[i++]); continue;  //直接将（入栈，并查看下一个
		}
		if (famula[i] == ')')
		{
			while (gettop(S) != '(')
			{
				Suffix[j++] = gettop(S); pop(S);    //将）之前的运算符依次出栈
			}
			pop(S); i++; continue;   //注意，结束后别忘了查看下一个原表达式
		}
		if (prior(ch = gettop(S)) >= prior(famula[i]) ) //栈顶元素大于运算符
		{
			Suffix[j++] = ch; pop(S); continue;   //先出栈，
		}
		if (prior(ch = gettop(S)) < prior(famula[i]) ) //栈顶元素小于运算符.
		{
			push(S, famula[i++]); continue;
		}
		if (famula[i] == '+' || famula[i] == '-' || famula[i] == '*' || famula[i] == '/') //运算符入栈
		{
			push(S, famula[i++]); continue;
		}
	}
	if (ch = gettop(S) == '#' && S->top != 0) { Suffix[j++] = '#'; pop(S); }//扫描到最后的#，输出#结束循环
	Suffix[j] = '\0';
	printf("后缀式：%s", Suffix);
	return Suffix;
}
int calculate_Suffix(char Suffix[])
{   
	int i = 0, a1, a2, t; char ch;
	IntStack* S2 = (IntStack*)malloc(sizeof(IntStack));
	InitSqStack2(S2);
	while (Suffix[i] != '\0')
	{
		if (Suffix[i] >= '0' && Suffix[i] <= '9') { a1 = Suffix[i] - 48; push2(S2, a1); i++; continue; }
		if (Suffix[i] == '+') 
		{
			a1 = gettop2(S2) ; pop2(S2);
			a2 = gettop2(S2) ; pop2(S2);
			t = a1 + a2; push2(S2, t); i++; continue;
		}
		if (Suffix[i] == '-')
		{
			a1 = gettop2(S2); pop2(S2);
			a2 = gettop2(S2); pop2(S2);
			t = a2-a1; push2(S2, t); i++; continue;
		}
		if (Suffix[i] == '*')
		{
			a1 = gettop2(S2); pop2(S2);
			a2 = gettop2(S2); pop2(S2);
			t = a2 * a1; push2(S2, t); i++; continue;
		}
		if (Suffix[i] == '/')
		{
			a1 = gettop2(S2); pop2(S2);
			a2 = gettop2(S2); pop2(S2);
			t = a2 / a1; push2(S2, t); i++; continue;
		}
		i++;
	}
	return gettop2(S2);
}
int main()
{
	char famula[50]; int x;
	SqStack* S = (SqStack*)malloc(sizeof(SqStack));
	InitSqStack(S);
	printf("请输入表达式：");
	scanf_s("%s", famula, 50);
	x=calculate_Suffix(find_Suffix(S,famula));
	printf("\n值为%d", x);
}