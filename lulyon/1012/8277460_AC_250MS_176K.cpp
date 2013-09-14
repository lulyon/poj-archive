#include<iostream>
using namespace std;

int result[14];

int main(){
	
	
	for(int k=1;k<14;++k){
		
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
				result[k] = m;
				break;
			}
		}
	}
	while(1){
		int n;
		scanf("%d",&n);
		if(n==0)break;
		printf("%d\n",result[n]);
	}
	return 0;
}

