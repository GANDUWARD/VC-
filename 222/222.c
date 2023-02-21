#include<stdio.h>
void main()
{  int c,x=0,y=-5;
   printf("!x*y=%d,x&&y=%d\n",!x*y,x&&y);
   c=(x=1)||(y=1);
   printf("x=%d,y=%d,c=%d\n",x,y,c);
   c=(x=0)&&(y=0);
   printf("x=%d,y=%d,c=%d\n",x,y,c);
}