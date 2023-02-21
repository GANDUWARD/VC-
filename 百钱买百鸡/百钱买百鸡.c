#include<stdio.h>
void main()
{     int x,y,z,n=0;
      printf("ÐòºÅ ¹«¼¦ Ä¸¼¦ Ð¡¼¦\n");
	  for(x=0;x<=20;x++)
		  for(y=0;y<=33;y++)
		  {    z=100-x-y;
		       if(15*x+9*y+z==300)
				   printf("%4d %4d %4d %4d\n",++n,x,y,z);
		  }
}
