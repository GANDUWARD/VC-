#include<stdio.h>
void main()
{
	float a[3][4] = { 0 }; int i, j, k;
	float max = 0;
	for (i = 0; i < 3; i++)
	{
		max = 0;
		for (j = 0; j < 4; j++)
		{
			scanf("%f", &a[i][j]);
			if (a[i][j] > max)max = a[i][j];
		}
		for (k = 0; k < 4; k++)
			a[i][k] /= max;
	}
	for (i = 0; i < 3; i++)
	{	
		for (j = 0; j < 4; j++)
			printf("%.2f ", a[i][j]);
		printf("\n");
	}
}