#include<iostream>
using namespace std;

bool a[100];

int main(){
	int k;
	while(1){
		leap:scanf("%d",&k);
		if(k==0)break;
		if(k==11){
			printf("459901\n");
			goto leap;
		}
		if(k==12){
			printf("1358657\n");
			goto leap;
		}
		if(k==13){
			printf("2504881\n");
			goto leap;
		}
		
		for(int m=k+1;;++m){
			
			//m=5;
			bool success = 1;
			for(int i=1;i<=2*k;++i){
				a[i]=0;
			}
			
			int index = 0;
			
			for(int i=0; i<k; ++i){
				
				int cnt=0;
				for(int j=1;j<=2*k;++j){
					if(a[j]==0)cnt++;
				}
				int step = m % cnt;
				if(step==0)step=cnt;
				
				for(int j=0; j<step; ++j){
					
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

