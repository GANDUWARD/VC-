#include<stdio.h>
void main()
{ 
	int a[2][3],i,j,t;
	for(i=0;i<2;i++)
		for(j=0;j<3;j++)
			scanf("%d",*(a+i)+j);
	for(i=0;i<2;i++)
		for(j=i;j<3;j++)
		{   
			t=a[i][j];
			a[i][j]=a[j][i];
			a[j][i]=t;
		}
	for(i=0;i<3;i++)
		for(j=0;j<2;j++)
			printf("%d ",a[i][j]);
}