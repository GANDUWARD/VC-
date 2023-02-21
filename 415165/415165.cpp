#include<stdio.h>
#include<stdlib.h>
void main()
{
	FILE *fp;
	char name[20];
	char tel[10];
	char mobile[20];
	if((fp=fopen("d:\\f.txt","r"))==NULL)
	{
		printf("File open error!\n");
		exit(1);
	}
	while(!feof(fp))
	{
		fscanf(fp,"%s%s%s",name ,tel,mobile);
		printf("%s\t%s\t%s\n",name,tel,mobile);
	}
	if(fclose(fp))
	{
		printf("Can not close the file!\n");
		exit(1);
	}
}