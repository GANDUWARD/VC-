#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct node
{
	FILE* fp;
	char place[100];
	struct node* firstchild;
	struct node* nextsibling;
}CSNode,*CSTree;
int InitTree(CSTree* T)
{
	*T = new CSNode;
	(*T)->firstchild = (*T)->nextsibling = NULL; 
	strcpy_s((*T)->place,100,"C:\\Users\\pc\\Desktop\\VC\\资源管理器\\内容文件\\test.txt");
	fopen_s(&(*T)->fp,(*T)->place, "w+");
	printf("初始文件创建成功!");
	fclose((*T)->fp);
	return 1;
}
int just_open(CSTree* T)
{
	if (!*T)
	{
		printf("文件为空!"); return 0;
	}
	system((*T)->place);
	return 1;
}
int level_show(CSTree* T)
{
	if (!*T)return 0;
}
int main()
{   
	CSTree* T = new CSTree;
	InitTree(T);
	return 0;
}