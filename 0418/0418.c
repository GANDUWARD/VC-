#include<stdio.h>

#include<stdlib.h>

#include<string.h>

#define MAXSIZE 20
typedef struct 

{

	int data;

	int* lchild;

	int* rchild;

}Treenode,*BiTree;

typedef struct

{  

  BiTree Elemdata[MAXSIZE];

  int front;

  int rear;

  int QueueSize;

}Queue,*SqQueue;



int InitQueue(SqQueue*Q)

{   

	(*Q)=(SqQueue)malloc(sizeof(Queue));

	(*Q)->front=(*Q)->rear=0;

	(*Q)->QueueSize=MAXSIZE;

	return 1;

}

int EnQueue(SqQueue*Q,BiTree x)

{

  (*Q)->Elemdata[(*Q)->rear]=x;

  (*Q)->rear=((*Q)->rear+1)%(*Q)->QueueSize;

  return 1;

}

int DeQueue(SqQueue*Q)

{   

	if((*Q)->front==(*Q)->rear)return 0;
	(*Q)->front=((*Q)->front+1)%(*Q)->QueueSize;
	return 1;

}

int getrear(SqQueue*Q,BiTree*e)

{

	if((*Q)->front==(*Q)->rear)return 0;

	*e=(*Q)->Elemdata[(*Q)->front];

	return 1;

}

int InitTree(BiTree*T)

{

	(*T)=(BiTree)malloc(sizeof(Treenode));

	(*T)->lchild=(*T)->rchild=NULL;

	return 1;

}

int Create(BiTree*T,int* i )

{   
	int fa,so,ta;
	SqQueue*Q=(SqQueue*)malloc(sizeof(SqQueue));
	InitQueue(Q);
	printf("请输入父节点（0为根）,节点数据(0结束输入),任务（0左1右）:");
	scanf("%d,%d,%d",&fa,&so,&ta);
	while(so!=0)
	{ 
	  BiTree q=(BiTree)malloc(sizeof(Treenode));
	  BiTree s=(BiTree)malloc(sizeof(Treenode));
	  q->data=so;q->lchild=q->rchild=NULL;   //划分新生成q结点为叶子结点
	  EnQueue(Q,q); 
	  if(fa==0){*T=q;*i=1;}
	  else
	  {   
		  getrear(Q,&s);
	      while(s->data!=fa)
		  {   
			  DeQueue(Q);
			  getrear(Q,&s);//注意要先看下队头是不是，不是再出栈，而不是一口气连续操作
		  }
	      if(s->data==fa)
		  {
		      if(ta==0)
			      s->lchild=q;
		      else
			      s->rchild=q;
		  }
	  }
	  printf("请输入父节点（0为根）,节点数据(0结束输入),任务（0左1右）:");
	  scanf("%d,%d,%d",&fa,&so,&ta);
	}
  return 1;

}
int print(BiTree*T)
{   
	BiTree p=*T;
	SqQueue*Q=(SqQueue*)malloc(sizeof(SqQueue));
	InitQueue(Q);
	if(*T==NULL)return 0;
	else
	{
		EnQueue(Q,p);
		while((*Q)->rear!=(*Q)->front)
		{   
			getrear(Q,&p);
		    DeQueue(Q);
			printf("%d ",p->data);
			if(p->lchild)EnQueue(Q,p->lchild);
			if(p->rchild)EnQueue(Q,p->rchild);
		}	
	}
	return 1;
}
int calculate_depth(BiTree*T)
{   
	int m=0,n=0;
	if(*T)
	{    
		if((*T)->lchild)m=calculate_depth(&(*T)->lchild);
		if((*T)->rchild)n=calculate_depth(&(*T)->rchild);
	}
	if(m>=n)return m+1;
	else return n+1;
}
int level_width(BiTree*T,int a[],int h)
{
	a[h]++;
	if((*T)->lchild)level_width(&(*T)->lchild,a,h+1);
	if((*T)->rchild)level_width(&(*T)->rchild,a,h+1);
}
int calculate_width(BiTree*T)
{   
	int i,h=0,max=0;int a[20]={0};
	if((*T)==NULL)return 0;
	level_width(T,a,h);
	for(i=0;i<20;i++)
	{ 
     if(a[i]>=max)max=a[i];
	}
	return max;
}
int sum_point(BiTree*T,SqQueue*Q)
{   
	if(!(*T)->lchild&&!(*T)->rchild)return 0;
	if((*T)->lchild&&!(*T)->rchild)EnQueue(Q,*T);
	if((*T)->rchild&&!(*T)->lchild)EnQueue(Q,*T);
	if((*T)->lchild)sum_point(&(*T)->lchild,Q);
	if((*T)->rchild)sum_point(&(*T)->rchild,Q);
}
int find_biggest(BiTree*T,int *b)
{   
	if((*T)->data>=*b)*b=(*T)->data;
	if((*T)->lchild)find_biggest(&(*T)->lchild,b);
	if((*T)->rchild)find_biggest(&(*T)->rchild,b);
}
int depth_and_width(BiTree*T,int*i,int*j)
{
	BiTree p=*T;int level;
	SqQueue*Q=(SqQueue*)malloc(sizeof(SqQueue));
	InitQueue(Q);*i=0;*j=1;
	if(*T==NULL)return 0;
	else
	{
		EnQueue(Q,p);level=(*Q)->rear;
		while((*Q)->rear!=(*Q)->front)
		{    
			getrear(Q,&p);
		      if(level==(*Q)->front)
			 {  
				if(*i<(*Q)->rear-(*Q)->front)
				{
					*i=(*Q)->rear-(*Q)->front;
				}
				level=(*Q)->rear;
				(*j)++;
			}
			DeQueue(Q);
			if(p->lchild)EnQueue(Q,p->lchild);
			if(p->rchild)EnQueue(Q,p->rchild);
		}	
	}
	return 1;
}
int main()
{   
	int a;int *b=(int*)malloc(sizeof(int));
	SqQueue*Q=(SqQueue*)malloc(sizeof(SqQueue));
	int *i=(int*)malloc(sizeof(int));
    int *j=(int*)malloc(sizeof(int));
	int *depth=(int*)malloc(sizeof(int));
	int *width=(int*)malloc(sizeof(int));
	BiTree *T=(BiTree*)malloc(sizeof(BiTree));
	*i=0;*j=0;
	InitQueue(Q);
	InitTree(T);
	Create(T,i);
	printf("树为:");
	print(T);
	*j=calculate_depth(T);
	*i=calculate_width(T);
	printf("\n深度是%d宽度是%d\n",*j,*i);
	depth_and_width(T,width,depth);
    printf("\n层次遍历深度是%d宽度是%d\n",*depth,*width);
	find_biggest(T,b);
	printf("最大结点是:%d\n",*b);
	sum_point(T,Q);
	if((*Q)->Elemdata[0]->data)
	{
	printf("树的奇数结点是:");
    for(a=0;a<20;a++)
		printf("%d ",(*Q)->Elemdata[a]->data);
	}
	if(!(*Q)->Elemdata[0]->data)
		printf("树无奇数结点");
	return 0;

}