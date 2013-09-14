#include<iostream>
using namespace std;
int table[10000];
int main(){
	int n, cycle;
	for(int i=1; i<10000; ++i){
		n = i;
		cycle = 0;
		while(1){
			cycle++;
			if(n==1)break;
			
			if(n%2)n = 3*n + 1;
			else n = n/2;
		}
		
		table[i] = cycle;
	}
	
	int a,b;
	while(scanf("%d%d",&a,&b)!=EOF){
		printf("%d %d ",a,b);
		
		if(a>b){
			a^=b^=a^=b;
		}
		int max=-1;
		for(int i=a; i<=b; ++i){
			if(max<table[i])max=table[i];
		}
		printf("%d\n",max);
	}
	return 0;
}

