#include<stdio.h>
  void main()
{  int max=0,i,j;  
  int a[10];
      for(i=0;i<=9;i++)
    {   scanf("%d",&a[i]);}
 for(i=0;i<=9;i++)
 { 
   if(a[i]>max)
      {  max=a[i];
            }
  }

  printf("最大值是%d,其在数组中位置是",max);

 for(j=0;j<=9;j++)
 {    if(a[j]==max)
 {     printf(" %d",j);}
 }
}