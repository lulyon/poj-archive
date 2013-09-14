#include<iostream>
using namespace std;
int main(){
	int n,t,tmp;
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		int sum=0;
		for(int i=0; i<n; ++i){
			scanf("%d",&tmp);
			sum += tmp;
		}
		printf("%d\n",sum-n+1);
	}
	return 0;
}

