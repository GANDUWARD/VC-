#include<stdio.h>  /*˼·�������������ѭ������̭����ͬ������*/
 void main()
{   int x=1,y=1,z=1;
    for(x=1;x<=4;x++)
      for(y=1;y<=4;y++)
      for(z=1;z<=4;z++)
      if(x!=y&&y!=z&&x!=z)   /*ע���ж�Ӧ������for�����ɺ�ʼ*/
      printf("%d,%d,%d\n",x,y,z);
}