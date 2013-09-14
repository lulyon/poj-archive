#include<iostream>
using namespace std;

int transform(int n){
	if(n<=3)return n;
	else return n-1;
}

int main(){
	int n;
	while(1){
		scanf("%d",&n);
		if(n==0)break;
		
		printf("%d: ",n);
		int exp=1;
		int sum=0;
		while(n!=0){
			sum += exp*transform(n%10);
			exp *= 9;
			n /= 10;
		}
		printf("%d\n",sum);
	}
	
	return 0;
}

