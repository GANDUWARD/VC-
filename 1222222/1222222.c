
#include<stdio.h>
void main()
{     float score;
      printf("������ѧ���ĳɼ�:");
	  scanf("%f",&score);
	  if(score>=0 && score<=100)
		  switch((int)score/10)
	  {       default:printf("������\n");break;
			  case 10:
			  case  9:  printf("����\n");break;
			  case  8:  printf("����\n");break;
			  case  7:  printf("�е�\n");break;
              case  6:  printf("����\n");break;
				  }
	  else
		  printf("���ݴ���!\n");
}

       