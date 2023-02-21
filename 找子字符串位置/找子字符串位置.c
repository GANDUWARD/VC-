#include<stdio.h>
 int substring(char s[],char sub[])
 {    int i=0,j=0,p,f=0;
   while(sub[i]!='\0'&&s[j]!='\0')  /*不知道具体长度那就遍历完字符串*/
   {         p=0;        /*对p每次赋值0*/
       if(s[j]==sub[1])       /*先设定初值*/
		   f=j;                /*记下第一次出现位置*/
	   if(s[j]==sub[i])
	   {   
		  i++;
	      j++;             /*若满足匹配可能就两者同步加一，一一比对*/
		  p=1;
		  p*=p;
		   continue;      
	   }
	   p*=p;          /*保证字符串匹配字符连续*/
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
           printf("%s子串没有找到！",sub);
    else
           printf("子串%s在主串%s中第一次出现的位置是%d",sub,s,substring(s,sub));
}
