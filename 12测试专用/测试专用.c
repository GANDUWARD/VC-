#define MAXSIZE 100
#include<stdio.h>
#include<stdlib.h>
float *array_create()
{
	float* p = (float*)malloc(sizeof(float) * MAXSIZE);
	return p;
}
int main()
{   
	float *p;
	p = array_create();
}