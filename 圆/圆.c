#include<stdio.h>
#define PI 3.1415926
void main()
{   float r,circum,area;
    float get_circum(float r);
	float get_area(float r);
	printf("请输入圆的半径:");
	scanf("%f",&r);
	circum=get_circum(r);
	area=get_area(r);
	printf("圆的周长为%.2f,圆的面积为%.2f\n",circum,area);
}
float get_circum(float r)
{
	return(2*PI*r);
}
float get_area(float r)
{
	return(PI*r*r);
}