#include<iostream>
#include<math.h>
using namespace std;
const int maxn=10000000;
double sum[maxn+1];
int main(){
	sum[1]=0;
	for(int i=2;i<=maxn; ++i){
		sum[i] = sum[i-1] + log10(i+0.0);
	}
	
	int n,t;
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);	
		printf("%d\n",(int)sum[n]+1);
	}
	return 0;
}

