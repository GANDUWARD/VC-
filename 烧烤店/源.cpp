#include<stdio.h>
#include<iostream>
#include<string.h>
#include"ÉÕ¿¾.h"
int main()
{   

	barbecue i= barbecue();
	strcpy_s(i.name, i.Initname(i.name));
	i.benifit = i.Initbenifit(i.benifit);
	i.print(i.name, i.benifit);
	return 0;
}