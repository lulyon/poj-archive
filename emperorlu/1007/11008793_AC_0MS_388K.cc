/*************************************************************************
	> File Name: 1007.cpp
	> Author: luliang
	> Mail: lulyon@126.com 
	> Created Time: 2012年11月12日 星期一 14时51分03秒
 ************************************************************************/

#include <stdio.h>

#include<algorithm>

const int maxn = 60;
const int maxm = 110;

typedef struct {
	int rank;
	int unsortedness;
	char *sequence;
}infoType;

char str[maxm][maxn];
infoType info[maxm];

bool cmp(const infoType &a, const infoType &b)
{
	if(a.unsortedness < b.unsortedness) return 1;
	else if(a.unsortedness > b.unsortedness) return 0;
	else{
		if(a.rank < b.rank) return 1;
		else return 0;
	}
}

int main(void) 
{
	int n, m;
	scanf("%d%d", &n, &m);

	for(int i = 0; i < m; ++i) {
		scanf("%s", str[i]);
		info[i].sequence = str[i];
		info[i].rank = i;

		int sum = 0;
		for(int j = 0; j < n; ++j) {
			for(int k = j + 1; k < n; ++k) {
				if(str[i][j] > str[i][k]) sum++;
			}
		}
		info[i].unsortedness = sum;
	}

	std::sort(info, info + m, cmp);

	for(int i = 0; i < m; ++i) {
		printf("%s\n", info[i].sequence);
	}

	return 0;
}
