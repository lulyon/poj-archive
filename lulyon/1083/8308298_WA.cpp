#include<iostream>
using namespace std;
int cnt[500];
int main(){
	int tt;
	scanf("%d",&tt);
	while(tt--){
		int n;
		scanf("%d",&n);
		for(int i=1; i<=400; ++i){
			cnt[i]=0;
		}
		int s,t;
		while(n--){
			scanf("%d%d",&s,&t);
			if(s>t)s^=t^=s^=t;
			for(int i=s; i<=t; ++i){
				cnt[i]++;
			}
		}
		int max=-1;
		for(int i=1; i<=400; ++i){
			if(max<cnt[i])max=cnt[i];
		}
		printf("%d\n",10*max);
	}
	return 0;
}

