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
		if(a.end < b.end)return 0;
		else return 1;
	}
}

int main(){
	int n,d, t=0;
	while(1){
		scanf("%d%d", &n, &d);
		if(n==0 || d==0)break;

		int x,y,tmp;
		double offset;
		bool flag = 0;
		for(int i=0; i<n; ++i){
			scanf("%d%d", &x, &y);
			tmp = d*d-y*y;
			if(tmp<0 || flag==1){
				flag=1;
				continue;
			}
			offset = sqrt(tmp+0.0);
			interval[i].begin = x - offset;
			interval[i].end = x + offset;
		}
		if(flag==1){
			printf("Case %d: -1\n", ++t);
			continue;
		}

		std::sort(interval, interval+n, cmp);
		double end = interval[0].begin-1;
		int count = 0;
		for(int i=0; i<n; ++i){
			if(interval[i].begin>end){
				count++;
				end = interval[i].end;
			}
			else{
				if(end > interval[i].end)
					end = interval[i].end;
			}
		}
		printf("Case %d: %d\n", ++t, count);
	}
	return 0;
}
