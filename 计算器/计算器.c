#include<stdio.h>
#include<math.h>
void main()
{  float a,b;
   char c;
   printf("��������ʽ��������<�����>������):");
   scanf("%f%c%f",&a,&c,&b);
   switch(c)
   {   case '+': printf("%f\n",a+b);break;
       case '-': printf("%f\n",a-b);break;
	   case '*': printf("%f\n",a*b);break;
	   case '/': if(fabs(b)<=1e-6)
		   printf("���ݴ��󣬳�������Ϊ0!\n");
		   else
			   printf("%f\n",a/b);
		   break;
	   default:printf("�����ֻ����+��-��*��/!\n");
   }
}