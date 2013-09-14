#include<iostream>
using namespace std;
char str[100];
int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		scanf("%s",str);
		
		for(int i=0; i<4; ++i){
			int sum=0,exp=128;
			for(int j=0; j<8; ++j){
				if(str[i*8+j]=='1'){
					sum += exp;
				}
				exp/=2;
			}
			printf("%d",sum);
			if(i==3)printf("\n");
			else printf(".");
		}
	}
	return 0;
}

