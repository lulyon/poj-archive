/*************************************************************************
	> File Name: 1003.c
	> Author: luliang
	> Mail: lulyon@126.com 
	> Created Time: 2012年11月09日 星期五 13时13分06秒
 ************************************************************************/

#include <stdio.h>
#include <math.h>

#define EXP 1e-6

int main(void)
{
	double realNumber;
	while(1) {
		scanf("%lf", &realNumber);
		if(fabs(realNumber) < EXP) break;

		int counter = 1;
		int mother = 2;
		double sum = 0;

		while(1) {
			sum += 1.0 / mother;
			if(sum >= realNumber) break;

			counter++;
			mother++;
		}

		printf("%d card(s)\n", counter);
	}
	return 0;
}
