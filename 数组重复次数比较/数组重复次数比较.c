#include<stdio.h>
void main()
{   int a[10];  /*定义a数组储存输入的数值*/
int b[10];      /*定义b数组储存各数之后的重复次数*/
    int i,j,n=1,max=1;
    for(i=0;i<=9;i++)
    {   scanf("%d",&a[i]);
	}
 printf("a数组元素为:");
 for(i=0;i<=9;i++)
 {printf("%d ",a[i]);}
 for(i=0;i<=9;i++,n=1)   /*两个for循环，扫描整个a数组，并与后面的数比较是否相同，记录次数*/
 { for(j=i+1;j<=9;j++)
 { if(a[i]==a[j])
       {   n++;
        b[i]=n;       
 }}}
for(i=0;i<=9;i++)
{if(b[i]>max)
{    max=b[i];
     a[max]=a[i];
 }}
for(j=0;j<=9;j++)
{   if(b[j]==max&&b[j]!=1&&b[j]!=a[max])  /*重新找到一个数组数，若与最大次数相同，输出一次，并且保证之前a[max]不重复*/
{printf("\n数组a中出现频率最高的数是%d,出现次数为%d\n",a[j],max);}}
 if(max==1)
 {printf("\n没有重复出现的数\n");}
}