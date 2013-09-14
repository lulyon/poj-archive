/*************************************************************************
	> File Name: 1006.c
	> Author: luliang
	> Mail: lulyon@126.com 
	> Created Time: 2012年11月10日 星期六 19时58分26秒
 ************************************************************************/

#include<stdio.h>
#include<assert.h>

const int n1 = 23;
const int n2 = 28;
const int n3 = 33;

int compFactor(int m, int n) 
{
	for(int i = 1; i < n; ++i) {
		if(m * i % n == 1) return m * i;
	}
	assert(0);
}

int main(void)
{
	int m1 = n2 * n3;
	int m2 = n1 * n3;
	int m3 = n1 * n2;

	int c1 = compFactor(m1, n1);
	int c2 = compFactor(m2, n2);
	int c3 = compFactor(m3, n3);

	int caseNum = 1;
	while(1) {
		int p, e, i, d;
		scanf("%d%d%d%d", &p, &e, &i, &d);
		if(p == -1 && e == -1 && i == -1 && d == -1) break;

		int a = c1 * p + c2 * e + c3 * i - d;
		int totalMul = n1 * n2 * n3;
		while(a <= 0) a += totalMul;
		while(a > totalMul) a -= totalMul;

		printf("Case %d: the next triple peak occurs in %d days.\n", caseNum, a);
	}

	return 0;
}
