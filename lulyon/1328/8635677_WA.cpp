#include<iostream>
#include<algorithm>
#include<math.h>

typedef struct{
	double begin, end;
}Type;

Type interval[1010];

bool cmp(const Type &a, const Type &b){
	if(a.begin < b.begin)return 1;
	else if(a.begin > b.begin)return 0;
	else{
		if(a.end <= b.end)return 1;
		else return 0;
	}
}

int main(){
	int n,d, t=0;
	while(1){
		scanf("%d%d", &n, &d);
		if(n==0 || d==0)break;

		int x,y;
		double offset;
		for(int i=0; i<n; ++i){
			scanf("%d%d", &x, &y);
			offset = sqrt(d*d-y*y+0.0);
			interval[i].begin = x - offset;
			interval[i].end = x + offset;
		}

		std::sort(interval, interval+n, cmp);
		int end = interval[0].begin-1;
		int count = 0;
		for(int i=0; i<n; ++i){
			if(interval[i].begin>end){
				count++;
				end = interval[i].end;
			}
		}
		printf("Case %d: %d\n", ++t, count);
	}
	return 0;
}
