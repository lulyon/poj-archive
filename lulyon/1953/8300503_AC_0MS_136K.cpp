#include<iostream>
using namespace std;

int fib[110];

int main(){
	fib[1]=2;
	fib[2]=3;
	for(int i=3; i<45;++i){
		fib[i] = fib[i-1]+fib[i-2];
	}
	int t,n;
	scanf("%d",&t);
	for(int i=1; i<=t; ++i){
		printf("Scenario #%d:\n",i);
		scanf("%d",&n);
		printf("%d\n\n",fib[n]);
	}
	return 0;
}

