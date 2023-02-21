#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define VNUM 10
typedef struct
{
    char string[20];
}Vertextype;
typedef struct
{
    Vertextype vex[VNUM];
    int arcs[VNUM][VNUM];
    int vexNum, arcNum;
}MGraph;
typedef struct node
{
    int place;
    struct node* prior;
    struct node* next;
}Linknode,*LinkQueue;
typedef struct
{
    LinkQueue front;
    LinkQueue rear;
}Queue;
typedef struct
{
    int place[VNUM];
    int top;
}Stack,*SqStack;
int InitStack(SqStack* S)
{
    *S = (SqStack)malloc(sizeof(Stack));
    (*S)->top = -1;
    return 1;
}
int push(SqStack* S, int x)
{
    (*S)->place[++(*S)->top] = x;
    return 1;
}
int pop(SqStack* S)
{
    if ((*S)->top == -1)return 0;
    (*S)->top--;
    return 1;
}
int gettop(SqStack* S, int* e)
{
    if ((*S)->top == -1)return 0;
    *e = (*S)->place[(*S)->top];
    return 1;
}
int output(SqStack*S,MGraph*M)
{
    int i;
    for (i = 0; i <= (*S)->top; i++)
        printf("%s ", M->vex[(*S)->place[i]]);
    return 1;
}
int InitQueue(Queue* Q)
{
    Q->front = (LinkQueue)malloc(sizeof(Linknode));
    Q->rear = Q->front;
    return 1;
}
int EnQueue(Queue* Q, int x)
{
    LinkQueue p= (LinkQueue)malloc(sizeof(Linknode));
    p->place = x;
    p->next = Q->rear->next;
    Q->rear->next = p;
    Q->rear = p;
    p->prior = Q->front->next;//记住将队头结点赋值给p的前驱
    return 1;
}
int DeQueue(Queue* Q)//注意这里出队不必free
{   
    if (Q->front == Q->rear)return 0;
    LinkQueue p = Q->front->next;
    Q->front->next = p->next;
    if (Q->rear == p)Q->rear = Q->front;
    /*free(p);*/
    return 1;
}
int getfront(Queue* Q,int *u)
{
    if (Q->front == Q->rear)return 0;
    *u = Q->front->next->place;//将队头下一个即第一个赋值给u
    return 1;
}
int write_in(MGraph* M)
{
    int i,j,a1,a2,l=0; 
    printf("请输入顶点个数:");
    scanf_s("%d", &(M)->vexNum);
    printf("请输入顶点信息:");
    for (i = 0; i < M->vexNum; i++)
        scanf_s("%s", M->vex[i].string,20);
    for (i = 0; i < M->vexNum; i++)
        for (j = 0; j < M->vexNum; j++)
            M->arcs[i][j] = 0;
    do
    {
        printf("请输入边数:");
        scanf_s("%d", &M->arcNum);
        if (M->arcNum >= 0 && M->arcNum <= M->vexNum * (M->vexNum - 1))
            break;
        else
            printf("输入边数有误!");
    } while (1);
    while(l<M->arcNum)
    {
        printf("请输入边:顶点号数1 顶点号数2:");
        scanf_s("%d %d", &a1, &a2);
        if (a1 >= 0 && a1 < M->vexNum && a1 >= 0 && a2 < M->vexNum&&a1!=a2)//两个顶点不能同一个并且范围适中
        {
            if (M->arcs[a1][a2] == 1)printf("该边已经输入!\n");
            else
            {
                M->arcs[a1][a2] = M->arcs[a2][a1] = 1;
                l++;
            }
        }
        else
            printf("输入信息有误!");
    }
    return 1;
}
int depth_print(MGraph* M, int v[], int* u)
{
    int i = 0; int t = *u;
    printf("%s ", M->vex[*u]);
    v[*u] = 1;
    while (i < M->vexNum)
    {
        if (M->arcs[*u][i] != 0 && v[i] == 0)
        {
            t = i;
            depth_print(M, v, &t);
        }
        i++;
    }
    return 1;
}
int level_print(MGraph* M)
{
    int v[VNUM] = { 0 }; int i; int* u = new int;
    Queue* Q = new Queue; *u = 0;
    InitQueue(Q);
    EnQueue(Q,0);
    while (Q->front != Q->rear)
    {   
        getfront(Q, u);      //获取队头顶点位置
        DeQueue(Q);
        printf("%s ", M->vex[*u].string);
        v[*u] = 1;      //标记访问位置
        for (i = 0; i < M->vexNum; i++)
        {
            if (M->arcs[*u][i] != 0 && v[i] == 0)
            {
                EnQueue(Q, i);
                v[i] = 1;                            //标记将要访问的结点
            }
        }
    }
    return 1;
}
int depth_find_path(MGraph* M,int k[],int*find,SqStack*S,char x[],int*u)
{
    push(S,*u);
    int t; k[*u] = 1; int i;
    if (strcmp(M->vex[*u].string, x) == 0)
    {
        output(S, M); *find = 1;
    }
    for (i = 0; i < M->vexNum; i++)
    {
        if (M->arcs[*u][i] != 0 && k[i] == 0)
        {
            t = i; depth_find_path(M, k, find, S, x, &t);
        }
    }
    if (*find == 0)
    {
        pop(S); k[*u] = 0;//如果没找到并跳出，说明路径错误，重置该点，出栈
    }
    return 1;
}
int print(MGraph* M, Queue* Q)
{
    char* a[10]; LinkQueue p = Q->front->next; int i; 
    for (i = 0; ; i++)//i负责计数
    {   
        a[i] = M->vex[p->place].string;
        p = p->prior;//p->不断回溯
        if (p->place == p->prior->place)
        { 
            a[++i] = M->vex[p->place].string;
            break;
        }
    }
    //补上初始结点
    for (int j = i; j >= 0; j--)
    {
        printf("%s ", a[j]);
    }
    return 1;
}
int LFSP(MGraph* M)
{
    int v[VNUM] = { 0 }; int i; int* u = new int; int* find = new int; *find = 0;
    char x[20];
    printf("请输入你要查找的值:");
    scanf_s("%s", x, 20);
    Queue* Q = new Queue; *u = 0;
    InitQueue(Q);
    EnQueue(Q, 0);
    while (Q->front != Q->rear)
    {
        getfront(Q, u);
        v[*u] = 1;   //访问了
        if (strcmp(x, M->vex[*u].string) == 0)//找到这个值了要及时中断
        {  
            *find = 1; break;
        }
        for (i = 0; i < M->vexNum; i++)
        {
            if (M->arcs[*u][i] == 1 && v[i] == 0)//有关系且访问到，入队
            {
                EnQueue(Q, i); v[i] = 1;
            }
        }
        DeQueue(Q);
    }
    if (*find == 0)printf("未找到!\n");
    else
    {   
        printf("路径如下:");
        print(M, Q);
    }
    return 0;
}
int main()
{   
    int num; char x[20];
    MGraph* M = (MGraph*)malloc(sizeof(MGraph));
    write_in(M);
    while (1)
    {   
        system("cls");
        int v[VNUM] = { 0 }; int* u = new int; *u = 0;
        printf("深度遍历结果如下:");
        depth_print(M, v, u);
        printf("广度遍历结果如下:");
        level_print(M);
        printf("\n请输入你的选择1 寻找初始点到某点的路径2 初始点到某点的最短路径\n");
        scanf_s("%d", &num);
        if (num == 1)
        {   
            SqStack* S = new SqStack; InitStack(S);
            int k[VNUM] = { 0 }; int* find = new int; *find = 0; *u = 0;
            printf("请输入该点的值");
            scanf_s("%s", x, 20);
            depth_find_path(M, k, find, S,x,u);
        }
        if (num == 2)
        {
            LFSP(M);
        }
        printf("按任意键继续!\n");
        getchar(); getchar();
    }
    return 0;
}