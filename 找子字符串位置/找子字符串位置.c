#include<stdio.h>
 int substring(char s[],char sub[])
 {    int i=0,j=0,p,f=0;
   while(sub[i]!='\0'&&s[j]!='\0')  /*��֪�����峤���Ǿͱ������ַ���*/
   {         p=0;        /*��pÿ�θ�ֵ0*/
       if(s[j]==sub[1])       /*���趨��ֵ*/
		   f=j;                /*���µ�һ�γ���λ��*/
	   if(s[j]==sub[i])
	   {   
		  i++;
	      j++;             /*������ƥ����ܾ�����ͬ����һ��һһ�ȶ�*/
		  p=1;
		  p*=p;
		   continue;      
	   }
	   p*=p;          /*��֤�ַ���ƥ���ַ�����*/
	   j++;
   }
	           
			if(p!=0&&f!=0)
				p=f;
			else
				p=-1;
		return(p);
 }
void main(void)
{
   char s[99],sub[99];
    gets(s);
    gets(sub);
    if(substring(s,sub)==-1)
           printf("%s�Ӵ�û���ҵ���",sub);
    else
           printf("�Ӵ�%s������%s�е�һ�γ��ֵ�λ����%d",sub,s,substring(s,sub));
}
