#include<stdio.h>
void main()
{   float score;
    printf("������ѧ���ĳɼ�:");
	scanf("%f",&score);
	if(score>=90)
		printf("����\n");
	else if(score>=80)
		printf("����\n");
	else if(score>=70)
		printf("�е�\n");
	else if(score>=60)
		printf("����\n");
	else
		printf("������\n");
}
