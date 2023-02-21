#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define MAXSIZE 20
typedef struct
{
	int data;
}Verxtype;
typedef struct
{
	int data[MAXSIZE];
	int front;
	int rear;
	int QueueSize;
}Queue,*SqQueue;
int InitQueue(SqQueue* Q)
{   
	if (!Q)return 0;
	*Q = (SqQueue)malloc(sizeof(Queue));
	(*Q)->front = (*Q)->rear = 0;
	(*Q)->QueueSize = MAXSIZE;
	return 1;
}
int EmptyQueue(SqQueue* Q)
{
	if ((*Q)->front == (*Q)->rear)return 1;
	else
		return 0;
}
int getfront(SqQueue* Q, int* x)
{
	if (EmptyQueue(Q))return 0;
	*x = (*Q)->data[(*Q)->front];
	return 1;
}
int EnQueue(SqQueue* Q, int x)
{
	(*Q)->data[(*Q)->rear] = x;
	(*Q)->rear = (*Q)->rear + 1 % (*Q)->QueueSize;
	return 1;
}
int DeQueue(SqQueue* Q)
{
	if (EmptyQueue(Q))return 0;
	(*Q)->front = (*Q)->front + 1 % (*Q)->QueueSize;
	return 1;
}
int FullQueue(SqQueue* Q)
{
	if (((*Q)->rear - (*Q)->front + 1) == (*Q)->QueueSize)return 1;
	else
		return 0;
}
int 集合划分(SqQueue* Q,int 集合[][5],int 关系[][5])//默认五个点
{
	int a = 0; int elem; int flag; int 访问[5]={0};
	for (int i = 1; i <= 5; i++)
		EnQueue(Q, i);
	flag = (*Q)->data[(*Q)->rear-1];
	集合[a][0] = 1;
	while (!EmptyQueue(Q))
	{
		getfront(Q, &elem); 
		DeQueue(Q);
		int p = 0; int q = 0; int k = 1;
		for (int i = 0; i < 5; i++)//看当今集合有没有它
		{
			if (集合[a][elem-1] != 0)p = 1;
		}
		if (p == 0 )
		{
			EnQueue(Q, elem);//没有的话就再次入队
			for (int i = 0; i < 5; i++)//判断是不是孤立
			{
				if (关系[elem - 1][i] != 0)q = 1;
			}
			if (q == 0)//是孤立单独一个集合
			{
				a++; 集合[a][elem - 1] = 1; 访问[elem - 1] = 1;
			}
		}
		else//有的话就补充这个集合
		{   
			访问[elem - 1] = 1;
			for (int i = 0; i < 5; i++)//将该元素的所有集合
			{
				if (关系[elem - 1][i] != 0)集合[a][i] = 1;
			}
		}
		if (elem == flag)//一层结束后
		{
			a++;//跳转到下一个集合
			flag = (*Q)->data[(*Q)->rear-1];//重新赋值flag为队尾元素
			getfront(Q, &elem); 集合[a][elem - 1] = 1;//初始化下一集合
		}
		for (int i = 0; i < 5; i++)//看点数有没有都访问了，
			if (访问[i] == 0)k = 0;
		if (k)break;//如果都访问了，就终止队列
	}
	return 1;
}
int main()
{
	SqQueue* Q = new SqQueue;
	InitQueue(Q);
	int 关系[5][5] = { {0,0,1,0,0},{0,0,0,1,0},{1,0,0,0,0},{0,1,0,0,0},{0,0,0,0,0} };
	int 集合[5][5] = { 0 };
	集合划分(Q,集合,关系);
	return 1;
}