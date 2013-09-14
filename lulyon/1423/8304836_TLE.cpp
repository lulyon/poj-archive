#include<iostream>
#include<math.h>
using namespace std;
int main(){
	int n,t;
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		if(n==1 || n==2){
			printf("1\n");
			continue;
		}
		
		double sum=0;
		for(int i=2;i<=n; ++i){
			sum += log10(i+0.0);
		}
		printf("%d\n",(int)sum+1);
	}
	return 0;
}

