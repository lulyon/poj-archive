#include<iostream>
#include <stdlib.h>
#include <stdio.h>
using namespace std;
char a[9], b[9], c[9], tmp[9];
int main()
{
	int n, x, y, z, m;
	scanf("%d", &n);
	while (n--) {
		scanf("%s %s %s", a, b, c);
		m = 1;
		while (++m < 17) {
			x = strtol(a, NULL, m);
			y = strtol(b, NULL, m);
			z = strtol(c, NULL, m);
			if (x * y != z)
				continue;
			if (strcmp(a, itoa(x, tmp, m)))
				continue;
			if (strcmp(b, itoa(y, tmp, m)))
				continue;
			if (strcmp(c, itoa(z, tmp, m)))
				continue;
			break;
		}
		printf("%d\n", m < 17 ? m : 0);
	}
	return 0;
}