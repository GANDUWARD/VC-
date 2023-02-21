#include<stdio.h>
void main()
{   int a=0,n;
    printf("n=");
	scanf("%d",&n);
	for(;n>0;a++,n--)
		printf("%d ",a*2);
	printf("\n");
}