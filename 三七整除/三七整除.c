#include<stdio.h>
void main()
{    int i;
     for(i=100;i<1000;i++)
	 {    if(i%3!=0)continue;
	      if(i%7!=0)continue;
		  printf(" %d",i);
	 }
	 printf("\n");
}