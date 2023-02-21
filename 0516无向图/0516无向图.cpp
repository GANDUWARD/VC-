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
}Linknode, * LinkQueue;
typedef struct
{
    LinkQueue front;
    LinkQueue rear;
}Queue;
typedef struct
{
    int place[VNUM];
    int top;
}Stack, * SqStack;
typedef struct
{
    int near_point_place;
    int lowcost;
}lowpoint;
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
int output(SqStack* S, MGraph* M)
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
    LinkQueue p = (LinkQueue)malloc(sizeof(Linknode));
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
int getfront(Queue* Q, int* u)
{
    if (Q->front == Q->rear)return 0;
    *u = Q->front->next->place;//将队头下一个即第一个赋值给u
    return 1;
}
int write_in(MGraph* M)
{
    int i, j, a1, a2, a3, l = 0;
    printf("请输入顶点个数:");
    scanf_s("%d", &(M)->vexNum);
    printf("请输入顶点信息:");
    for (i = 0; i < M->vexNum; i++)
        scanf_s("%s", M->vex[i].string, 20);
    for (i = 0; i < M->vexNum; i++)
        for (j = 0; j < M->vexNum; j++)
        {
            if (i == j)M->arcs[i][j] = 0;
            else
                M->arcs[i][j] = 999;   //初始化标识999表示不存在邻接关系
        }
    do
    {
        printf("请输入边数:");
        scanf_s("%d", &M->arcNum);
        if (M->arcNum >= 0 && M->arcNum <= M->vexNum * (M->vexNum - 1))
            break;
        else
            printf("输入边数有误!");
    } while (1);
    while (l < M->arcNum)
    {
        printf("请输入边:顶点号数1 顶点号数2 该边权数(999除外):");
        scanf_s("%d %d %d", &a1, &a2, &a3);
        if (a1 >= 0 && a1 < M->vexNum && a1 >= 0 && a2 < M->vexNum && a1 != a2 && a3 != 999)//两个顶点不能同一个并且范围适中
        {
            if (M->arcs[a1][a2] != 999)printf("该边已经输入!\n");
            else
            {
                M->arcs[a1][a2] = M->arcs[a2][a1] = a3;   //赋权值
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
    printf("%s ", M->vex[*u].string);
    v[*u] = 1;
    while (*u < M->vexNum)
    {
        while (i < M->vexNum)
        {
            if (M->arcs[*u][i] != 0 && v[i] == 0)
            {
                t = i;
                depth_print(M, v, &t);
            }
            i++;
        }
        (*u)++;
    }
    return 1;
}
int level_print(MGraph* M,int *u)
{
    int v[VNUM] = { 0 }; int i,k=0; 
    Queue* Q = new Queue; 
    InitQueue(Q);
    EnQueue(Q, *u);//0也可以改成其他值
    while (k < M->vexNum)
    {
        while (Q->front != Q->rear)
        {
            getfront(Q, u);      //获取队头顶点位置
            DeQueue(Q);
            printf("%s ", M->vex[*u].string);
            v[*u] = 1;      //标记访问位置
            for (i = 0; i < M->vexNum; i++)
            {
                if (M->arcs[*u][i] != 999 && M->arcs[*u][i] != 0 && v[i] == 0)
                {
                    EnQueue(Q, i);
                    v[i] = 1;                            //标记将要访问的结点
                }
            }
        }
        if(v[k]==0)EnQueue(Q, k);//如果找到一次广度遍历都没有标记的点，说明不属于同一连通分量，入队
        k++;
    }
    return 1;
}
int depth_find_path(MGraph* M, int k[], int* find, SqStack* S, char x[], int* u)
{
    push(S, *u);
    int t; k[*u] = 1; int i;
    if (strcmp(M->vex[*u].string, x) == 0)
    {
        output(S, M); /**find = 1;*/
        printf("\n");              //如果这里停止标记找到，就会一直找下去
    }
    for (i = 0; i < M->vexNum; i++)
    {
        if (M->arcs[*u][i] != 999 && M->arcs[*u][i] != 0 && k[i] == 0)
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
            if (M->arcs[*u][i] != 999 && M->arcs[*u][i] != 0 && v[i] == 0)//有关系且访问到，入队
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
int Init_points(lowpoint points[])
{
    for (int i = 0; i < VNUM; i++)//初始化points
    {
        points[i].lowcost = 999;
        points[i].near_point_place = -1;
    }
    return 1;
}
int find_minimum(lowpoint points[], int flag[])
{
    int in = 0;
    for (int i = 0; i < VNUM; i++)
    {
        if (points[i].lowcost < points[in].lowcost && flag[i] == 0)in = i;
    }
    return in;
}
int flag_full(int flag[], MGraph* M)
{
    int p = 1;
    for (int i = 0; i < M->vexNum; i++)
    {
        if (flag[i] == 0)p = 0;
    }
    return p;
}
int Prim(MGraph* M, lowpoint points[], int flag[])
{
    Queue* Q = new Queue; int* u = new int; int i, in, p;
    InitQueue(Q);
    printf("请输入起始点号数:");
    scanf_s("%d", u);
    EnQueue(Q, *u);
    Init_points(points);
    while (Q->front != Q->rear)
    {
        getfront(Q, u);      //获取队头顶点位置
        flag[*u] = 1;        //访问即选上
        for (i = 0; i < M->vexNum; i++)
        {
            if (M->arcs[*u][i] != 999 && M->arcs[*u][i] != 0 && flag[i] == 0)
            {
                if (points[i].lowcost > M->arcs[*u][i])//每次替换为更小的权值边
                {
                    points[i].near_point_place = *u;
                    points[i].lowcost = M->arcs[*u][i];
                }
            }
        }
        in = find_minimum(points, flag);
        EnQueue(Q, in);//每次选取最小权边的结点入队
        DeQueue(Q);
        if (flag_full(flag, M))break;//判断所有点都已经选上后算法结束
    }
    return 1;
}
int output_matrix(MGraph* M)
{
    for(int i=0;i<M->vexNum;i++)
        for (int j = 0; j < M->vexNum; j++)
        {
            printf("%d ", M->arcs[i][j]);
            if (j == M->vexNum - 1)
                printf("\n");
        }
    return 1;
}
int main()
{
    int num; char x[20];
    MGraph* M = (MGraph*)malloc(sizeof(MGraph));
    write_in(M);
    while (1)
    {  
        int* u = new int;
        system("cls");
        printf("邻接矩阵：\n");
        output_matrix(M);
        printf("\n请输入你的选择1 寻找初始点到某点的路径2 初始点到某点的最短路径3 普利姆算法求最小生成树4 深度遍历5 广度遍历\n");
        scanf_s("%d", &num);
        if (num == 1)
        {
            SqStack* S = new SqStack; InitStack(S);
            int k[VNUM] = { 0 }; int* find = new int; *find = 0; *u = 0;
            printf("请输入该点的值");
            scanf_s("%s", x, 20);
            depth_find_path(M, k, find, S, x, u);
        }
        if (num == 2)
        {
            LFSP(M);
        }
        if (num == 3)
        {
            lowpoint points[VNUM]; int flag[VNUM] = { 0 };
            Prim(M, points, flag);
            for (int i = 0; i < M->vexNum; i++)
            {
                if (points[i].near_point_place != -1)
                    printf("%s边的权是%d,邻接点是%s\n", M->vex[i].string, points[i].lowcost, M->vex[points[i].near_point_place].string);
            }
        }
        if (num == 4)
        {
            int v[VNUM] = { 0 }; int* u = new int; *u = 0;
            printf("请输入初始点号数:");
            scanf_s("%d", u);
            printf("深度遍历结果如下:");
            depth_print(M, v, u);
        }
        if (num == 5)
        {  
            int* u = new int; *u = 0;
            printf("请输入初始点号数:");
            scanf_s("%d", u);
            printf("广度遍历结果如下:");
            level_print(M,u);
        }
        printf("按任意键继续!\n");
        getchar(); getchar();
    }
    return 0;
}