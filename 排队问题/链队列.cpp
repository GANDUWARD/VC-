#include<stdio.h>
#include<string.h>
#include<stdlib.h>
typedef struct node
{
    int data;
    struct node* next;
}Qnode, * LinkQueue;
typedef struct
{
    LinkQueue front;
    LinkQueue rear;
}LQueue;
int InitQueue(LQueue* LQ)
{
    LQ->front = LQ->rear = (LinkQueue)malloc(sizeof(Qnode));
    if (LQ->front == NULL) { printf("内存分配失败！"); return 0; }
    LQ->front->next = NULL;
    return 1;
}
int EmpQueue(LQueue* LQ)
{
    if (LQ->front == LQ->rear)return 1;
    else return 0;
}
int EnQueue(LQueue* LQ, int x)
{
    if (LQ->front == LQ->rear) { printf("空队列!"); return 0; }
    LinkQueue p = (LinkQueue)malloc(sizeof(Qnode));
    p->next = LQ->rear->next;
    p->data = x;
    LQ->rear->next = p;
    LQ->rear = p;
    return 1;

}
int DeQueue(LQueue* LQ)
{
    if (LQ->front == LQ->rear) { printf("空队列!"); return 0; }
    LinkQueue p = LQ->front->next;              //指向第一个结点
    LQ->front->next = p->next;                  //表头的第一个结点变成第二个
    if (LQ->rear == p) { LQ->rear = LQ->front; }  //如果队尾指向第一个，那么说明只有一个元素需要将rear指向front
    free(p);
    return 1;
}
int print(LQueue* LQ)
{
    if (LQ->front == LQ->rear) { printf("空队列!"); return 0; }
    LinkQueue p = LQ->front->next;
    while (p)
    {
        printf("%d ", p->data);
        p = p->next;
    }
}
int main()
{
    LQueue* LQ = (LQueue*)malloc(sizeof(LQueue));
    InitQueue(LQ);
}