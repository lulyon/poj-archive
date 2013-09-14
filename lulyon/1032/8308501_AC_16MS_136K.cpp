#include<iostream>
using namespace std;
int main(){
	int n;
	scanf("%d",&n);
	int sum=0;
	int end;
	for(int i=2;; ++i){
		sum += i;
		if(sum>=n){
			sum-=n;
			end=i;
			break;
		}
	}
	if(sum==1){
		for(int i=3; i<end; ++i){
			printf("%d ",i);
		}
		printf("%d\n",end+1);
	}
	else{
		for(int i=2; i<end; ++i){
			if(sum!=i)printf("%d ",i);
		}
		printf("%d\n",end);
	}	
	return 0;
}

