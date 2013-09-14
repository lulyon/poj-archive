#include<iostream>
using namespace std;

int main(){
	int k;
	while(1){
		scanf("%d",&k);
		if(k==0)break;
		
		for(int m=k+1;;++m){
			
			bool success = 1;
			
			int index = 1;
			int length = 2*k;
			
			for(int i=0; i<k; ++i){
				
				index = (index+m-1)%length;
				if(index==0)index = length;
				
				if(index<=k){
					success = 0;
					break;
				}
				length--;
			}
			
			if(success){
				printf("%d\n",m);
				break;
			}
		}
	}
	return 0;
}

