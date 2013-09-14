/*************************************************************************
	> File Name: 1005.c
	> Author: luliang
	> Mail: lulyon@126.com 
	> Created Time: 2012年11月09日 星期五 14时24分52秒
 ************************************************************************/

#include <stdio.h>
#include <math.h>

const double speed = 50;
const double pi = 3.1415926;

int main(void)
{
	int n;
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i) {
		double x, y;
		scanf("%lf%lf", &x, &y);
		double r2 = x * x + y * y;
		double year = 0.5 * pi * r2 / speed;
		printf("Property %d: This property will begin eroding in year %d.\n", i, (int)year + 1);
	}
	printf("END OF OUTPUT.\n");

	return 0;
}
