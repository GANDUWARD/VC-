#include<stdio.h>
#define PI 3.1415926
  void main()
{    float r,h,l,s,sq,v,vz;
     float get_l(float r);
     float get_s(float r);
     float get_sq(float r);
     float get_v(float r);
     float get_vz(float r,float h);
     scanf("%f,%f",&r,&h);
	 l=get_l(r);
	 s=get_s(r);
	 sq=get_sq(r);
	 v=get_v(r);
	 vz=get_vz(r,h);
     printf("Բ�ܳ�Ϊ:l=%.2f\nԲ���Ϊ:s=%.2f\nԲ������Ϊ:sq=%.2f\nԲ�����Ϊ:v=%.2f\nԲ�����Ϊ:vz=%.2f\n",l,s,sq,v,vz);
}
float get_l(float r)
{    return(PI*r*2);
}
float get_s(float r)
{     return(r*PI*r);
}
float get_sq(float r)
{     return(4.0*PI*r*r);
             }
float get_v(float r)
{       return((4.0/3.0)*PI*r*r*r);
}
float get_vz(float r,float h)
{      return(PI*r*r*h);
}