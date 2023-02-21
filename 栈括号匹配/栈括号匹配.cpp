#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
    char data;
    struct node* next;
}Lnode,*LinkStack;
int InitStack(LinkStack *LS)
{    
    (*LS) = (LinkStack)malloc(sizeof(Lnode));
    (*LS)->next = NULL;
    return 1;
}
char gettop(LinkStack* LS)
{   
    if ((*LS)->next == NULL) { printf("空栈！"); return 0; }
    LinkStack p =(*LS)->next;
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
int find(LinkStack* LS, char dusha[])
{   
    int i,p; char c;
    LinkStack x;
    for (i = 0; dusha[i] != '\0'; i++)
    {
        if (dusha[i] == '(' || dusha[i] == '[')
        {   
            x = (LinkStack)malloc(sizeof(Lnode));
            x->data = dusha[i];
            push(LS, x);
        }
        if (dusha[i] == ')' || dusha[i] == ']')
        {
            c = gettop(LS);
            if (dusha[i] == ')' && c == '(')
            {
                pop(LS); continue;
            }
            if (dusha[i] == ']' && c == '[')
            {
                pop(LS); continue;
            }
            else
            {
                printf("匹配不成功！（右括号剩余)");
                return 1;
            }
        }
    }
    if ((p = check_empty(LS)) == 1)
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
    LinkStack* LS=(LinkStack*)malloc(sizeof(LinkStack));
    char dusha[20];
    scanf_s("%s", dusha, 20);
    InitStack(LS);
    find(LS, dusha);
    return 1;
}