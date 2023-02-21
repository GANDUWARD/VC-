#include<stdio.h>
long compose(long number)
{       int i,k,x=0,y=1,b=0;
        int a[20];
        long int s=number,j=number;
        for(i=0;s/10!=0;i++)
          s/=10;
		k=i+1;
 for(i=0;i<k;i++)
 { 
   if((j%10)%2==0) 
   { 
     a[x]=j%10;
     x++;
   }
      j/=10;
 }
 number=0;
 for(i=0;i<x;i++)
 { b=a[i]*y;
   number+=b;    
   y*=10;
 }
 return(number);
}
int main()
{
   long int n ;
   scanf("%ld",&n);
   printf("%ld\n",compose(n));
   return 0;
}