#include<stdio.h>
#include<string.h>
void swap(char s1[],char s2[],char s3[])
{
	int i,j=0,k=0,l,p,q,r;
	char str[100];
	q=strlen(s3);
	r=strlen(s2);
	for(i=0;s1[i]!='\0';i++)
	{  
		p=0;
		if(s1[i]==s2[j])
		{   
			p=1;
			j++;
		}
		if(j==r)
		{
			j=0;	
		   for(l=0;l<q;l++)
		   {   str[k]=s3[l];
			   k++;
		   }

		}
		if(p==0)
		{   
			str[k]=s1[i];
			k++;
		}
	}
	str[k]='\0';
     strcpy(s1,str);
}


void main()
{   
   char s1[100];
   char s2[50];
   char s3[50];
   gets(s1);
   gets(s2);
   gets(s3);
   swap(s1,s2,s3);
   puts(s1);
}