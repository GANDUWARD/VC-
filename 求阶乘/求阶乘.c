#include<stdio.h>
void main()
{   int i,fact,n;
    printf("«Î ‰»În:");
	scanf("%d",&n);
	for(fact=1,i=1;i<=n;i++)
		fact=fact*i;
	printf("%d!=%d\n",n,fact);
}