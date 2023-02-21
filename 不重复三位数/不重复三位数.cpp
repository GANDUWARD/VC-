#include<stdio.h>  /*思路：运用三组变量循环，淘汰掉相同数即可*/
 void main()
{   int x=1,y=1,z=1;
    for(x=1;x<=4;x++)
      for(y=1;y<=4;y++)
      for(z=1;z<=4;z++)
      if(x!=y&&y!=z&&x!=z)   /*注意判断应在所有for语句完成后开始*/
      printf("%d,%d,%d\n",x,y,z);
}