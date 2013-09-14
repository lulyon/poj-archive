#include<iostream>
using namespace std;
int main(){
	int m;
	while(1){
		scanf("%d",&m);
		if(m==0)break;
		printf("%d ",m);
		
		if(m==1){
			printf("1\n");
			continue;
		}
		
		int n;
		for(n=1;;++n){
			if(n*(n+1)/2<m && m<=(n+1)*(n+2)/2)break;
		}
		
		int money = n*(n+1)*(2*n+1)/6 + (n+1)*(m-n*(n+1)/2);
		printf("%d\n",money);
	}
	return 0;
}

