#include<stdio.h>
void main()
{
	int a[5][5];
	int b[9]={0},c[9]={0},d[9]={0};
	int i,j,k,max,min,sum=0,q=0,p;
	for(i=0;i<5;i++)
		for(j=0;j<5;j++)
			scanf("%d",*(a+i)+j);
	max=a[0][0];
	min=a[0][0];
	for(j=-4;j<=0;j++)
	{                            
	 max=a[4][4+j];  
	for(i=4;i+j<5&&i+j>=0;i--) 
	{
		if(a[i][i+j]>max)
		  max=a[i][i+j];
	}
	  b[j+4]=max;
	}
    for(j=1;j<5;j++)
	{
	 max=a[0][0+j];  
	for(i=0;i+j<5&&i+j>=0;i++) 
	{
		if(a[i][i+j]>max)
		  max=a[i][i+j];
	}
	  b[j+4]=max;

	}
	for(j=4;j>=0;j--)
	{  
		min=a[0][4-j];
		for(i=0;4-i-j>=0&&4-i-j<5;i++)
		{
			if(a[i][4-i-j]<min)
				min=a[i][4-i-j];
		}
		c[4-j]=min;
	}
	for(j=-1;j>=-4;j--)        
	{  
		min=a[4][-j];
		for(i=4;4-i-j>=0&&4-i-j<5;i--)   
		{
			if(a[i][4-i-j]<min)
				min=a[i][4-i-j];
		}
		c[4-j]=min;
	}	
	   for(i=0;i<9;i++)
		for(j=0;j<9;j++)
		{   
		if(b[i]==c[j])
		{   p=0;
			for(k=0;k<9;k++)
			{
				if(b[i]==d[k])
				{
				    p=1;
					break;
				}
			}
			if(p==0)
			{
			d[q]=b[i];
			q++;
			break;
			}
		}
		}
	for(i=0;i<9;i++)
		sum+=d[i];
	printf("%d",sum);
}

	