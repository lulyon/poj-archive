#include<iostream>
using namespace std;

int s[20], t[20];

int main(){
	int n;
	while(1){
		scanf("%d",&n);
		if(n==-1)break;
		
		for(int i=0; i<n; ++i){
			scanf("%d %d", &s[i], &t[i]);
		}
		
		int sum = s[0] * t[0];
		for(int i=1; i<n; ++i){
			sum += s[i]*(t[i]-t[i-1]);
		}
		printf("%d miles\n", sum);
	}
	return 0;
}

