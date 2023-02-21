#include<stdio.h>
#include<math.h>
void main()
{float a,b,c,s,area;
  printf("请输入三角形的三边:\n");
  scanf("%f%f%f",&a,&b,&c);
  if(a+b>c && fabs(a-b)<c)
  { s=(a+b+c)/2;
       area=sqrt(s*(s-a)*(s-b)*(s-c));
	   printf("area=%f\n",area);
  }
  else
	  printf("输入数据错误!\n");
}