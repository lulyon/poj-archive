#include<iostream>
using namespace std;

bool a[100];

int main(){
	int k;
	while(1){
		scanf("%d",&k);
		if(k==0)break;
		
		for(int m=k+1;;++m){
			
			bool success = 1;
			for(int i=1;i<=2*k;++i){
				a[i]=0;
			}
			
			int index = 0;
			
			for(int i=0; i<k; ++i){
				for(int j=0; j<m; ++j){
					index++;
					if(index>2*k)index=index-2*k;
					while(a[index]==1){
						index++;
						if(index>2*k)index=index-2*k;
					}
					
				}
				
				a[index]=1;
				if(index<=k){
					success = 0;
					break;
				}
			}
			
			if(success){
				printf("%d\n",m);
				break;
			}
		}
	}
	return 0;
}

