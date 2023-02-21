#include<stdio.h>
#define M 15
int fun(int a[],int b,int c)
{     int i,j=0;
      int x[M];
	  for(i=0;i<b;i++)
	  {
		  if(a[i]!=c)
		  {
			  x[j]=a[i];
			  j++;
		  }
	  }
	  for(i=0;i<=j;i++)
	      a[i]=x[i];
	  return(j);
}		 
int main()
{      int aa[M]={1,2,3,3,2,1,1,2,3,4,5,4,3,2,1}, n=15, y, k;
       scanf("%d",&y);
       n = fun(aa, n, y);
       for(k=0; k<n; k++ )
              printf("%d ",aa[k]);
         printf("\n");
return(0);
}