#include<iostream>
using namespace std;
int main(){
	int n;
	scanf("%d",&n);
	int sum=0;
	for(int i=1;; ++i){
		sum+=i;
		if(sum>n &&(sum-n)%2==0){
			printf("%d\n",i);
			break;
		}
	}
	return 0;
}

