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
		printf("Property %d: This property will begin eroding in year %.0lf.\n", i, ceil(year));
	}
	printf("END OF OUTPUT.");

	return 0;
}
