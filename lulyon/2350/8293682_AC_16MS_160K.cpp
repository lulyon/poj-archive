#include<iostream>
using namespace std;

const int maxn=1010;
double score[maxn];

int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		int n;
		scanf("%d",&n);
		double sum=0;
		for(int i=0; i<n; ++i){
			scanf("%lf",&score[i]);
			sum += score[i];
		}
		sum = sum/n;
		int cnt=0;
		for(int i=0; i<n; ++i){
			if(score[i]>sum){
				cnt++;
			}
		}
		printf("%.3lf%%\n",(double)cnt/n*100.0);
	}
	return 0;
}

