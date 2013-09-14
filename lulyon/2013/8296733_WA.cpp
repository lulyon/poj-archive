#include<iostream>
using namespace std;

int str[110][110];

int main(){
	int n;
	while(1){
		scanf("%d",&n);
		if(n==0)break;
		
		printf("SET %d\n",n);
		for(int i=0; i<n; ++i){
			scanf("%s",str[i]);
		}
		
		if(n%2){
			for(int i=0; i<n; i+=2){
				printf("%s\n",str[i]);
			}
			
			for(int i=n-2; i>0; i-=2){
				printf("%s\n",str[i]);
			}
		}
		else{
			for(int i=0; i<n; i+=2){
				printf("%s\n",str[i]);
			}
			
			for(int i=n-1; i>0; i-=2){
				printf("%s\n",str[i]);
			}
		}
	}
	return 0;
}

