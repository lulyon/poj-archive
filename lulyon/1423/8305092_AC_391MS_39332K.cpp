#include<iostream>
#include<math.h>
using namespace std;
const int maxn=10000000;
double sum[5000000+1];
int main(){
	sum[0]=0;
	for(int i=1;i<5000000; ++i){
		sum[i] = sum[i-1] + log10(i+i+0.0)+log10(i+i+1.0);
	}
	
	int n,t;
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		if(n%2){
			printf("%d\n", (int)sum[(n-1)/2]+1);
		}
		else{
			printf("%d\n",(int)(sum[n/2-1]+log10(n+0.0))+1);
		}
	}
	return 0;
}

