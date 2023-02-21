#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAXSIZE 30
typedef struct
{
	char* data;
	int top;
	int StackSize;
}SqStack;
typedef struct
{
	float* data;
	int top;
	int StackSize;
}FloatStack;
float calculate_Suffix(char Suffix[], FloatStack* S2);
int InitSqStack(SqStack* S)
{
	S->data = (char*)malloc(sizeof(char) * MAXSIZE);
	S->top = -1;
	S->StackSize = MAXSIZE;
	return 1;
}
int InitSqStack2(FloatStack* S)
{
	S->data = (float*)malloc(sizeof(float) * MAXSIZE);
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
int push2(FloatStack* S, float x)
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
int pop2(FloatStack* S)
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
float gettop2(FloatStack* S)
{
	float i = S->data[S->top];
	return i;
}
int judge_number(char famula[],int i,FloatStack*S2)
{
	float t = famula[i] - 48,q=0; i++;
	while (famula[i] >= '0' && famula[i] <= '9')//整数部分
	{
			t = t*10+famula[i++]-48;
	}
	if (famula[i] == '.')//小数部分
	{
		q = 0.1; i++;
		while (famula[i] >= '0' && famula[i] <= '9')
		{   
			t +=(famula[i++]-48) * q;
			q *= 0.1;
		}
	}
	push2(S2, t);
	return i;
}
char* find_Suffix(SqStack* S, char famula[],FloatStack*S2)
{
	int i = 0, j = 0, l1 = strlen(famula); char Suffix[50], ch; 
	push(S, '#');         //给运算符栈进个#
	while (!ElmpStack(S) && i < l1 && j < l1)
	{
		if (famula[i] == '@' || famula[i] == '.')  //@.也录入
		{
			Suffix[j++] = famula[i++]; continue;
		}
		if (famula[i] >= '0' && famula[i] <= '9') { Suffix[j++] = famula[i++]; continue; }//操作数
		if (famula[i] == '(')
		{
			push(S, famula[i++]); continue;  //直接将（入栈，并查看下一个
		}
		if (famula[i] == ')')
		{    
			while (gettop(S) != '(')
			{   
				Suffix[j++] = gettop(S);pop(S);    //将）之前的运算符依次出栈,将前面的式子先进行运算
			}
			pop(S); 
			i++; continue;   //注意，结束后别忘了查看下一个原表达式
		}
		if (prior(ch = gettop(S)) >= prior(famula[i])) //栈顶元素大于运算符
		{
			Suffix[j++] = ch; pop(S); continue;   //先出栈，
		}
		if (prior(ch = gettop(S)) < prior(famula[i])) //栈顶元素小于运算符.
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
float calculate_Suffix(char Suffix[], FloatStack*S2)
{
	int i = 0; char ch; float t, a1, a2;
	while (Suffix[i] != '#')
	{   
		if(Suffix[i]=='@')
		{
			i++;
			judge_number(Suffix, i, S2);
		}
		if (Suffix[i] == '+')
		{   
			a1 = gettop2(S2); pop2(S2);
			a2 = gettop2(S2); pop2(S2);
			t = a1 + a2;  i++; push2(S2, t); continue;
		}
		if (Suffix[i] == '-')
		{
			a1 = gettop2(S2); pop2(S2);
			a2 = gettop2(S2); pop2(S2);
			t = a2 - a1; push2(S2, t); i++; continue;
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
	char famula[50]; float x; 
	SqStack* S = (SqStack*)malloc(sizeof(SqStack));
	InitSqStack(S);
	FloatStack* S2 = (FloatStack*)malloc(sizeof(FloatStack));
	InitSqStack2(S2);
	printf("请输入表达式：(操作数之前加@，负数用0-):\n");
	scanf_s("%s", famula, 50);
	x = calculate_Suffix(find_Suffix(S, famula,S2),S2);
	printf("\n值为%f", x);
}