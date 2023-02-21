#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
    char data;
    struct node* next;
}Qnode,*LinkQueue;
typedef struct Node
{
    char data;
    struct Node* next;
}Lnode,*LinkStack;
typedef struct
{
    LinkQueue front;
    LinkQueue rear;
}LQueue;
int InitQueue(LQueue*LQ)
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
int EnQueue(LQueue* LQ,char x)
{
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
    while(p)
    {
        printf("%c ", p->data);
        p = p->next;
    }
}
int InitStack(LinkStack* LS)
{
    (*LS) = (LinkStack)malloc(sizeof(Lnode));
    (*LS)->next = NULL;
    return 1;
}
char gettop(LinkStack* LS)
{
    if ((*LS)->next == NULL) { printf("空栈！"); return 0; }
    LinkStack p = (*LS)->next;
    return p->data;
}
int push(LinkStack* LS,LinkStack x)
{
    x->next = (*LS)->next;
    (*LS)->next = x;
    return 1;
}
int pop(LinkStack* LS)
{
    if ((*LS)->next == NULL) { printf("空栈！"); return 0; }
    LinkStack p = (*LS)->next;
    (*LS)->next = p->next;
    free(p);
    return 1;
}
int check_empty(LinkStack* LS)
{
    if ((*LS)->next == NULL) { return 1; }
    else return 0;
}
int getin(LQueue* LQ, LinkStack* LS,char famula[])
{  
    int i = 0;
    while (famula[i] != '\0')
    {   
        LinkStack x = (LinkStack)malloc(sizeof(Lnode));
        EnQueue(LQ, famula[i]);
        x->data = famula[i];
        push(LS, x);
        i++;
    }
    return 1;
}
int judge(LQueue* LQ, LinkStack* LS)
{   
    char a1, a2;
    while (!check_empty(LS))
    {   
        a1 = gettop(LS); a2 = LQ->front->next->data;
        if (a1 != a2)
        {
            printf("不回文！"); return 0;
        }
        pop(LS); DeQueue(LQ);
    }
    printf("回文！");
    return 1;
}
int main()
{   
    char famula[20];
    LQueue* LQ = (LQueue*)malloc(sizeof(LQueue));
    InitQueue(LQ);
    LinkStack* LS = (LinkStack*)malloc(sizeof(LinkStack));
    InitStack(LS);
    printf("请输入字符串：");
    scanf_s("%s", famula, 20);
    getin(LQ, LS,famula);
    judge(LQ, LS);
    

}