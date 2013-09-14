/*************************************************************************
	> File Name: 1004.cpp
	> Author: luliang
	> Mail: lulyon@126.com 
	> Created Time: 2012年11月09日 星期五 13时32分56秒
 ************************************************************************/

#include<stdio.h>

#define MONTH 12

float salary[MONTH + 1];

int main(void)
{
	for(int i = 1; i <= MONTH; ++i)
		scanf("%f", &salary[i]);

	float sum = 0;
	for(int i = 1; i <= MONTH; ++i)
		sum += salary[i];

	printf("$%.2f\n", sum / MONTH);
	return 0;
}
