#include<stdio.h>
void main()
{   float score;
    printf("请输入学生的成绩:");
	scanf("%f",&score);
	if(score>=90)
		printf("优秀\n");
	else if(score>=80)
		printf("良好\n");
	else if(score>=70)
		printf("中等\n");
	else if(score>=60)
		printf("及格\n");
	else
		printf("不及格\n");
}
