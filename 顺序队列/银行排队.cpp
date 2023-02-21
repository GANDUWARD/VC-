#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAXSIZE 20
typedef struct
{
	char type[20];
	char window[20];
	int number;
}VIST;
typedef struct
{
	int front;
	int rear;
	int Queuesize;
	VIST data[MAXSIZE];
}SqQueue;
int InitQueue(SqQueue* Q)
{
	Q->front = Q->rear = 0; Q->Queuesize = MAXSIZE;
	return 1;
}
int EmpQueue(SqQueue* Q)
{
	if (Q->front == Q->rear)return 1;
	else return 0;
}
int find_length(SqQueue* Q)
{
	return (Q->rear - Q->front + Q->Queuesize) % Q->Queuesize;
}
VIST getfront(SqQueue* Q)
{   
	if(Q->front!=Q->rear)
	return Q->data[Q->front];
}
int EnSqQueue(SqQueue* Q,char window[],int a)
{    
	VIST x;
	if ((Q->rear + 1) % Q->Queuesize == Q->front)return 0;
	else
	{   
		x.number = a;
		printf("请输入服务类型:");
	    scanf_s("%s", x.type,20);
		strcpy_s(x.window, window);
		Q->data[Q->rear] = x; Q->rear = (Q->rear + 1) % Q->Queuesize;
	}
	return 1;
}
int DeSqQueue(SqQueue* Q)
{
	if ((Q->rear + 1) % Q->Queuesize == Q->front)return 0;
	else
	{
	    Q->front = (Q->front + 1) % Q->Queuesize;
	}
	return 1;
}
int print(SqQueue* Q)
{   
	if (Q->front == Q->rear) 
	{
		printf("队列空！"); return 0;
	}
	int i = 0;
	while (i <Q->rear)
	{
		printf("%d\t%s\t%s\n", Q->data[i].number,Q->data[i].type,Q->data[i].window);
		i = (i + 1) % Q->Queuesize;
	}
	return 1;
}
int menu()
{
	int num; 
	while (1)
	{
		/*system("cls");*/
		printf("****** * 银行挂号模拟系统****** * \n");
		printf("1.挂号\t2.窗口1叫号\n");
		printf("3.窗口2叫号\t4.显示\n");
		printf("0.退出\n");
		printf("**********************************\n");
		printf("请选择\n"); scanf_s("%d", &num); getchar();
		if (num >= 0 && num <= 4)return num;
		else
		{
			printf("输入内容有误，请重新输入数字继续！\n");
			scanf_s("%d",&num);
		}
	}
}
int main()
{   
	int n, a1 = 0, a2 = 0; char window[20]; VIST x;
	SqQueue* Q1 = (SqQueue*)malloc(sizeof(SqQueue));
	InitQueue(Q1);
	SqQueue* Q2 = (SqQueue*)malloc(sizeof(SqQueue));
	InitQueue(Q2);
	while (1)
	{   
		n = menu();
		switch (n)
		{
		case 1:printf("请输入窗口:");
			scanf_s("%s", window, 20);
			getchar();
			if (strcmp(window, "窗口1") == 0)
			{
				a1++; EnSqQueue(Q1, window, a1);
			}
			if (strcmp(window, "窗口2") == 0)
			{
				a2++; EnSqQueue(Q2, window, a1);
			}
			printf("按任意键继续！\n");
			getchar();
			   break;
		case 2:x = getfront(Q1);
			   DeSqQueue(Q1);
			   printf("请%d号客户到%s办理%s业务!", x.number, x.window, x.type);
			   printf("按任意键继续！\n");
			   getchar();
			   break;
		case 3:x = getfront(Q2);
			   DeSqQueue(Q2);
			   printf("请%d号客户到%s办理%s业务!", x.number, x.window, x.type);
			   printf("按任意键继续！\n");
			   getchar();
			   break;
		case 4:x = getfront(Q1);
			   printf("现在是%d号客户在%s办理%s业务!，还有%d位客户在等待！\n", x.number, x.window, x.type,find_length(Q1) - 1);
			   x = getfront(Q2);
			   printf("现在是%d号客户在%s办理%s业务!，还有%d位客户在等待！\n", x.number, x.window, x.type, find_length(Q2) - 1);
			   printf("按任意键继续！\n");
			   getchar();
			   break;
		case 0: exit(0);
		}
	}
}
