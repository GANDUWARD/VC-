#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define MAXSIZE (30)
#define EQ(a,b)    (!strcmp((a),(b)))
#define LQ(a,b)    (strcmp((a),(b))<0)
#define RQ(a,b)     (strcmp((a),(b))>0)
typedef struct node
{
	char* string;
	struct node* lchild;
	struct node* rchild;
}BSNode,*BSTree;
int InitTree(BSTree* T)
{
	*T = new BSNode;
	(*T)->string = (char*)malloc(sizeof(char)*MAXSIZE);
	(*T)->lchild = (*T)->rchild = NULL;
	return 1;
}
//int depth_write(BSTree* T,int *count,int l)
//{   
//	(*count)++;
//	if ((*count) == l)
//	{
//		return 0;
//	}
//	char s[MAXSIZE];
//	scanf_s("%s", s, MAXSIZE);
//	if (EQ(s, (*T)->string))
//	{
//		printf("主键重复，插入失败!\n");
//		return 1;
//	}
//	if (LQ(s, (*T)->string))
//	{   
//		InitTree(&(*T)->lchild);
//		strcpy_s((*T)->lchild->string, MAXSIZE, s);
//		depth_write(&(*T)->lchild, count,l);
//	}
//	if (RQ(s, (*T)->string))
//	{
//		InitTree(&(*T)->rchild);
//		strcpy_s((*T)->rchild->string, MAXSIZE, s);
//		depth_write(&(*T)->rchild, count,l);
//	}
//	return 1;
//}
int insert_data(BSTree* T, char x[])
{
	if (!*T)
	{
		InitTree(T);
		strcpy_s((*T)->string, MAXSIZE, x);
		return 1;
	}
	if (LQ(x, (*T)->string))
	{
		insert_data(&(*T)->lchild, x);
	}
	if (RQ(x, (*T)->string))
	{
		insert_data(&(*T)->rchild, x);
	}
	if (EQ(x, (*T)->string))
	{
		printf("主键重复，插入失败!\n");
		return 1;
	}
	return 1;
}
int write_in(BSTree* T)
{   
	int* count = new int; *count = 0; int l;
	printf("请输入你要输入的个数:");
	scanf_s("%d", &l);
	printf("请输入值:");
	scanf_s("%s", (*T)->string, MAXSIZE);
	for (int i = 1; i < l; i++)
	{   
		char x[MAXSIZE];
		printf("请输入你要插入的值:");
		scanf_s("%s",x, MAXSIZE);
		insert_data(T, x);
	}
	return 1;
}
int depth_print(BSTree* T)
{   
	if (!(*T))return 0;
	printf("%s ", (*T)->string);
	depth_print(&(*T)->lchild);
	depth_print(&(*T)->rchild);
	return 1;
}
BSTree* find_s(BSTree* T)
{   
	if (!(*T))return 0;
	if ((*T)->lchild)return find_s(&(*T)->lchild);
	if ((*T)->rchild)return find_s(&(*T)->lchild);
	return T;
}
int delete_data(BSTree*T,char x[],int *find,BSTree*s)
{
	if ((*find) == 1)return 1;
	if (!(*T))return 0;
	if (EQ(x, (*T)->string))
	{   
		BSTree q = (*T);
		if (!(*T)->lchild && !(*T)->rchild)//叶子结点
		{
			free(q);
			(*T) = NULL;   //注意是*T置空而不是工作指针p
			return 1;
		}
		if ((*T)->lchild && !(*T)->rchild)//只有左子树
		{   
			q = (*T);
			(*T) = q->lchild;//将q的子树值赋值给该点
			free(q); (q) = NULL; //并将该点改成叶子结点
			return 1;
		}
		if (!(*T)->lchild && (*T)->rchild)//只有右子树，同理
		{   
			q = (*T);
			(*T) = q->rchild;
			free(q); q = NULL; /*(*T)->rchild = NULL;*/
			return 1;
		}
		if ((*T)->lchild && (*T)->rchild)//都有
		{    
			s = find_s(&(*T)->lchild);    //注意，这个要单独写一个BSTree*类型函数才能记忆中序遍历的直接前驱,或者用循环语句，直接找左子树的最右下的结点
 			strcpy_s((*T)->string, MAXSIZE, (*s)->string);
			free(*s);  *s = NULL; s = NULL;
			return 1;
		}
		(*find) = 1;
	}
	if (LQ(x,(*T)->string))delete_data(&(*T)->lchild, x, find,s);
	if (RQ(x, (*T)->string))delete_data(&(*T)->rchild, x, find,s);
	return 1;
}
int delete_data2(BSTree* T, char x[], int* find, BSTree* s)
{
	if ((*find) == 1)return 1;
	if (!(*T))return 0;
	if (EQ(x, (*T)->string))
	{
		BSTree q=(*T);
		if (!(*T)->lchild && !(*T)->rchild)//叶子结点
		{
			free(q);
			(*T) = NULL;   //注意是*T置空而不是工作指针p
			return 1;
		}
		if ((*T)->lchild && !(*T)->rchild)//只有左子树
		{
			q = (*T);
			(*T) = q->lchild;//将q的子树值赋值给该点
			free(q); (q) = NULL; //并将该点改成叶子结点
			return 1;
		}
		if (!(*T)->lchild && (*T)->rchild)//只有右子树，同理
		{
			q = (*T);
			(*T) = q->rchild;
			free(q); q = NULL; /*(*T)->rchild = NULL;*/
			return 1;
		}
		if ((*T)->lchild && (*T)->rchild)//都有
		{
			q = *T; *s = q->lchild;//s 指向被删节点的中序前驱,q指向*s的双亲
			while ((*s)->rchild) //找到最右下的点，就是前驱
			{
				q = *s;
				*s = (*s)->rchild;
			}
			strcpy_s(q->string, MAXSIZE, (*s)->string);//将s值赋值给q
			if (q != *T)q->rchild = (*s)->lchild;//将删除结点的另一子树接上去
			else//如果q->lchild只有*s一个,就把它的左子树续接
			{
				q->lchild = (*s)->lchild;
			}
			free(*s);
			return 1;
		}
		(*find) = 1;
	}
	if (LQ(x, (*T)->string))delete_data2(&(*T)->lchild, x, find, s);
	if (RQ(x, (*T)->string))delete_data2(&(*T)->rchild, x, find, s);
	return 1;
}
BSTree findout(BSTree* T, int* find,char x[])
{   
	if (EQ(x, (*T)->string))
	{
		*find = 1;
		return *T;
	}
	if (LQ(x, (*T)->string))
	{
		return findout(&(*T)->lchild, find, x);
	}
	if (RQ(x, (*T)->string))
	{
		return findout(&(*T)->rchild, find, x);
	}
}
int main()
{   
	int num;
	BSTree* T = (BSTree*)malloc(sizeof(BSTree));
	InitTree(T);
	write_in(T);
	while (1)
	{
		system("cls");
		if (!*T)
		{
			printf("空表!按任意键退出!\n");
			getchar();exit(0);
		}
		else
		{  
			depth_print(T);
			printf("请输入你的操作:1 插入数据2 删除数据3 查找数据4删除数据教材方法\n");
			scanf_s("%d", &num);
			if (num == 1)
			{
				char x[MAXSIZE];
				printf("请输入你要插入的值:");
				scanf_s("%s", x, MAXSIZE);
				insert_data(T, x);
			}
			if (num == 2)
			{
				char x[MAXSIZE]; int* find = new int; *find = 0; BSTree* s = new BSTree;
				printf("请输入你要删除的值:");
				scanf_s("%s", x, MAXSIZE);
				delete_data(T, x, find, s);
			}
			if (num == 3)
			{
				char x[MAXSIZE]; int* find = new int; *find = 0; BSTree* s = new BSTree;
				BSTree u = new BSNode;
				printf("请输入你要查找的值:");
				scanf_s("%s", x, MAXSIZE);
				u = findout(T, find, x);
				if (*find == 1)printf("找到了，值为%s", u->string);
			}
			if (num == 4)
			{
				char x[MAXSIZE]; int* find = new int; *find = 0; BSTree* s = new BSTree;
				printf("请输入你要删除的值:");
				scanf_s("%s", x, MAXSIZE);
				delete_data2(T, x, find, s);
			}
			printf("按任意键继续!\n");
			getchar(); getchar();
		}
	}
	return 1;
}