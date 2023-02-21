#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct student
{
    char name[20];
    int number;
    struct student* next;
};
void create(struct student *p,struct student*head)
{
    int num;
    char ch;
    printf("请输入号数(按0退出)");
    scanf_s("%d", &num);
    ch = getchar();
    if (num != 0)
        do
        {
            p->number = num;
            printf("请输入姓名：");
            gets_s(p->name);
            printf("请输入号数(按0退出)");
            scanf_s("%d", &num);
            ch = getchar();
            if (num == 0)
            {
                p->next = NULL;
                break;
            }
            else
            {
                p->next = (struct student*)malloc(sizeof(struct student));
                p = p->next;
            }
        } while (1);
}
void print(struct student* p)
{
    while (p != NULL)
    {
        printf("%d\t%s\n", p->number, p->name);
        p = p->next;
    }
}
int main()
{
    struct student* p, * head;
    p = (struct student*)malloc(sizeof(struct student));
    head = p;
    create(p, head);
    print(head);
}
