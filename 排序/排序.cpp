#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define MAXSIZE (11)
typedef struct
{
	int low, high;
	int task;
}Elem;
typedef struct
{
	Elem data[MAXSIZE];
	int top;
}Stack,*SqStack;
int InitStack(SqStack* S)
{
	*S = (SqStack)malloc(sizeof(Stack));
	(*S)->top = -1;
	return 1;
}
int push(SqStack* S,Elem e)
{
	(*S)->data[++(*S)->top] = e;
	return 1;
}
int Elmpty(SqStack* S)
{
	if ((*S)->top == -1)return 1;
	else
		return 0;
}
int gettop(SqStack* S, Elem* e)
{   
	if (Elmpty(S))return 0;
	*e = (*S)->data[(*S)->top];
	return 1;
}
int pop(SqStack* S)
{
	if (Elmpty(S))return 0;
	(*S)->top--;
	return 1;
}
int 直接插入排序(int 数表[])
{  
	for (int i = 2; i < MAXSIZE; i++)
	{
		数表[0] = 数表[i]; int j;
		for (j = i-1;数表[j]>数表[0]; j--)
		{
			数表[j+1] = 数表[j];
	    }
		数表[j+1] = 数表[0];   //注意越界问题
	}
	return 1;
}
int 折半插入排序(int 数表[])
{   
	for (int i = 2; i < MAXSIZE; i++)
	{
		int low = 1, high = i-1; 数表[0] = 数表[i];
		int j; int mid;
		while (low<=high)//折半查找
		{
			mid = (low + high) / 2;
			if (数表[mid] > 数表[0])
				high = mid-1;//逐渐放缩
			if (数表[mid] < 数表[0])
				low = mid + 1;
		}
		for (j = i-1;j>high; j--)
		{
			数表[j + 1] = 数表[j];
		}
		数表[j+1] = 数表[0];   //注意越界问题
	}
	return 1;
}
int 折半插入排序改(int 数表[])
{
	for (int i = 2; i < MAXSIZE; i++)
	{
		int low = 1, high = i - 1; 数表[0] = 数表[i];
		int j; int mid;
		while (low != high)//折半查找,没有放缩会导致一个弊端，查找后high对应的数有时候比插入数大有时候小
		{
			mid = (low + high) / 2;
			if (mid == low)break;
			if (数表[mid] > 数表[0])
				high = mid;
			if (数表[mid] < 数表[0])
				low = mid;
		}
		if (数表[high] < 数表[0])
		{
			for (j = i - 1; j > high; j--)
			{
				数表[j + 1] = 数表[j];
			}
		}
		if (数表[high] > 数表[0])
		{
			for (j = i - 1; j >= high; j--)
			{
				数表[j + 1] = 数表[j];
			}
		}
		数表[j + 1] = 数表[0];   //注意越界问题
	}
	return 1;
}
int shell(int 数表[], int d)
{
	for (int i = 1; i < MAXSIZE; i++)
	{
		for (int k = i+d; k < MAXSIZE; k+=d)//分组插入排序
		{
			数表[0] = 数表[k]; int j;
			for (j = k - d; j>=0&&数表[j] > 数表[0]; j-=d)//注意j>=0
			{
				数表[j + d] = 数表[j];
			}
			数表[j + d] = 数表[0];   //注意越界问题
	    }
	}
	return 1;
}
int 希尔排序(int 数表[])//这个复杂度是O(n4)
{   
	int d = (MAXSIZE - 1) / 2;
	for (int i = 1; d >0; i++)
	{
		shell(数表, d);
		d /= 2;
	}
	return 1;
}
int xua_sort(int 数表[], int d)
{
	for (int k = 1 + d; k < MAXSIZE; k++)//分组插入排序
	{
		数表[0] = 数表[k]; int j;
		for (j = k - d; j >= 0 && 数表[j] > 数表[0]; j -= d)//注意j>=0
		{
			数表[j + d] = 数表[j];
		}
		数表[j + d] = 数表[0];   //注意越界问题
	}
	return 1;
}
int Shell_Sort(int 数表[])
{
	int d = (MAXSIZE - 1) / 2;
	for (int i = 1; d > 0; i++)
	{
		xua_sort(数表, d);
		d /= 2;
	}
	return 1;
}
int fast_sorting(int 数表[], int low, int high)
{  
	数表[0] = 数表[low];
	while (high > low)
	{
		while (low < high && 数表[0] <= 数表[high])//注意每次寻找时要保证low<high
		{
			high--;
		}
		数表[low] = 数表[high];
		while (low < high && 数表[0] >= 数表[low])
		{
			low++;
		}
		数表[high] = 数表[low];
	}
	数表[high] = 数表[0];
	return high;
}
int QuickSorting(int 数表[])
{
	SqStack* S = (SqStack*)malloc(sizeof(SqStack)); InitStack(S);
	Elem e;  e.task = 1; e.low = 1, e.high = MAXSIZE - 1;
	push(S, e);
	while (!Elmpty(S))
	{
		gettop(S, &e);
		pop(S);
		int low = e.low;
		if (e.low < e.high)
		{
			int temp = fast_sorting(数表, e.low, e.high);
			e.low = temp+1; push(S, e);
			e.low = low;
			e.high = temp-1; push(S, e);
		}
	}
	return 1;
}
int fast(int 数表[],int low,int high)
{   
	if (low<high)//每次要检查low<high
	{   
		int temp = fast_sorting(数表, low, high);
		fast(数表, low, temp-1);
		fast(数表, temp+1, high);
	}
	return 1;
}
int optional_sorting(int 数表[])
{   
	for (int i = 1; i < MAXSIZE - 2; i++)
	{
		int min = i,t;
		for (int j = i; j < MAXSIZE - 1; j++)
		{
			if (数表[j] < 数表[min])
				min =j;
		}
		t = 数表[i];
		数表[i] = 数表[min];
		数表[min] = t;
	}
	return 1;
}
int bubble_sorting(int 数表[])
{   
	int exchange = MAXSIZE - 1;
	while (exchange)
	{
		int bound = exchange; exchange = 0;
		for (int i = 1; i < bound; i++)
		{
			if (数表[i] > 数表[i + 1])
			{
				数表[0] = 数表[i];
				数表[i] = 数表[i + 1];
				数表[i + 1] = 数表[0];
				exchange = i;
			}
	   }
	}
	return 1;
}
int heap_adjust(int 数表[], int end)
{
	int i; int j = end;
	while (j)
	{
		i = j / 2;        //i记忆的是大根堆头
		if (数表[i] < 数表[j])//发现大根堆头比它小，就交换元素
		{
			数表[0] = 数表[i];
			数表[i] = 数表[j];
			数表[j] = 数表[0];
		}
		j--;
	}
	return 1;
}
int heap_sorting(int 数表[])
{
	int end;
	for (end = MAXSIZE - 1; end > 1; end--)
	{
		heap_adjust(数表, end);
		数表[0] = 数表[1];       //交换堆顶元素
		数表[1] = 数表[end];
		数表[end] = 数表[0];
	}
	return 1;
}
int heap_adjust2(int 数表[], int begin, int end)
{   
	int i;
	数表[0] = 数表[begin];   //暂存堆顶元素
	for (i = 2 * begin; i <= end; i *= 2)//沿着较大的孩子结点向下筛选
	{
		if (i < end && 数表[i] < 数表[i + 1])i++;//如果右边更大就倾到右边找
		if (数表[0] >= 数表[i])break;     //此时应该插入到begin位置
		数表[begin] = 数表[i];       //每次都把下面元素往上挪
		begin = i;    //向下移动
	}
	数表[begin] = 数表[0];       //插入
	return 1;
}
int heap_sorting2(int 数表[])
{
	int i;
	for (i = (MAXSIZE - 1) / 2; i > 0; --i)//从最远的根堆向上调整
		heap_adjust2(数表, i,MAXSIZE-1);
	for (i = MAXSIZE - 1; i > 1; --i)
	{
		数表[0] = 数表[1];       //交换堆顶元素
		数表[1] = 数表[i];
		数表[i] = 数表[0];
		heap_adjust2(数表, 1, i - 1);
	}
	return 1;
}
int main()
{
	int 数表[MAXSIZE] = { 0 }; int num;
	printf("请输入10个数字:\n");
	for (int i = 1; i < MAXSIZE; i++)
		scanf_s("%d", &数表[i]);
	while(1)
    {  
		system("cls");
		for (int i = 1; i < MAXSIZE; i++)
			printf("%d ", 数表[i]);
		printf("\n请输入你的操作:1 直接插入排序2 折半插入排序3 希尔排序4 快速排序非递归\n\t5 快速排序递归6 选择排序7 冒泡排序8 堆排序9 堆排序教材版\n");
		scanf_s("%d", &num);
		if (num == 1)
		{
			直接插入排序(数表);
		}
		if (num == 2)
		{
			折半插入排序(数表);
		}
		if (num == 3)
		{
			Shell_Sort(数表);
		}
		if (num == 4)
		{
			QuickSorting(数表);
		}
		if (num == 5)
		{   
			int low = 1, high = MAXSIZE - 1;
			fast(数表,low,high);
		}
		if (num == 6)
		{
			optional_sorting(数表);
		}
		if (num == 7)
		{
			bubble_sorting(数表);
		}
		if (num == 8)
		{
			heap_sorting(数表);
		}
		if (num == 9)
		{
			heap_sorting2(数表);
		}
		printf("按任意键继续！\n");
		getchar(); getchar();
	}
}