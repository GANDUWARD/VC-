#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int initstring(char stringA[], char stringC[])
{
	printf("请输入A串：");
	scanf_s("%s", stringA, 20);
	printf("请输入C串：");
	scanf_s("%s", stringC, 20);
	return 1;
}
//int find_next(char a[], char c[],int n[])
//{
//	int i=0, j=0,l1,l2;
//	l1 = strlen(a); l2 = strlen(c);
//	while (i < l1 - l2+1 && j < l2)
//	{
//		if (a[i] == c[j]) { i++; j++; }
//		else
//		{
//			i = i - j +1; j = 0;
//	    }
//	}
//	if (j > l2-1)return i - l2 + 1;
//	else return 0;
//}
//int to_next(char c[], int l, int n[])
//{
//	int i = 0, j = 1, k = 0;
//
//	while (i < l && j < l)
//	{
//		if (c[j] == c[i])
//		{
//			k = k + 1; i++; j++; continue;
//		}
//		if (c[j] != c[i] && i == 0) { j++; i = 0; k = 0; continue; }      //如果第一个不相等，就再往后错位，重新从第一个开始比
//		if (c[j] != c[i] && i != 0) { i = 0; k = 0; continue; }
//	}
//	return k + 1;
//
//} 
int get_next( char c[], int n[])
{
	int i = 0, j = 1; n[0] = 0;
	int l2 = strlen(c);
	while (i < l2&&j<l2)
	{
		if (c[i] == c[j] || i == 0)
		{
			i++;  j++; n[j-1] = i; //为下一个比较的位置的n赋值
		}
		if (i != 0 && c[i] != c[j]) 
		{
			i = n[i] - 1; continue;
		} //i回到i位置的next指向的位置
		if (i == 0 && c[i] != c[j])j++;
	}
	return 1;
}
//int find_next(char a[], char c[], int n[])   //kmp:通过模式串错位比较.
//{
//	int i = 0, j = 1, l2;
//	n[0] = 0; n[1] = 1;
//	l2 = strlen(c);
//	while (j < l2)
//	{
//		n[j] = to_next(c, j, n);
//		j++;
//	}
//	return 1;
//}
int cmp(char a[], char c[], int n[])
{
	int i = 0, j = 0, l1, l2;
	l1 = strlen(a); l2 = strlen(c);
	while (i < l1 && j < l2)
	{
		if (a[i] == c[j]) { i++; j++; continue; }
		if (a[i] != c[j] && j != 0)
		{
			j = n[j] - 1;  continue;
		}
		i++;
	}
	if (j > l2 - 1)return i - l2 + 1;
	else return 0;
}
int main()
{
	int x, i, l2;
	char stringA[100];
	char stringC[100];
	int next[100];
	initstring(stringA, stringC);
	l2 = strlen(stringC);
	/*find_next(stringA, stringC, next);*/
	get_next(stringC, next);
	printf("next串如下：");
	for (i = 0; i < l2; i++)
		printf("%d ", next[i]);
	x = cmp(stringA, stringC, next);
	printf("\n%d", x);
}
