#include<stdio.h>
#include<stdlib.h>
struct student
{     int num;
      char name[20];
	  struct student *next;
};
struct student *create()
{      struct student *p,*head;
       int num;
	   p=(struct student *)malloc(sizeof(struct student));
	   head=p;
	   printf("请输入学号(输入0退出):");
	   scanf("%d",&num);
	   if(num==0)
		   return NULL;
	   else
		   do
		   {   p->num=num;
		       printf("请输入学生姓名:");
			   scanf("%s",p->name);
			   printf("请输入学号(输入0退出):");
			   scanf("%d",&num);
			   if(num!=0)
			   {     p->next=(struct student *)malloc(sizeof(struct student));
			         p=p->next;
			   }
			   else
			   {   p->next=NULL;
			       return head;
			   }
		   }while(1);
}
void print(struct student *head)
{         struct student *p=head;
          while(p!=NULL)
		  {     printf("%d %s\n",p->num,p->name);
		        p=p->next;
		  }
		  return;
}
void main()
{    struct student *head;
     head=create();
	 print(head);
}
