#include<iostream>
using namespace std;

int main(){

	int t;
	scanf("%d",&t);
	int x,y;
	while(t--){
		scanf("%d%d",&x,&y);
		if(x==0 && y==0){
			printf("0\n");
			continue;
		}
		if(x==y){
			if(x%2){
				printf("%d\n", x+x-1);
			}
			else{
				printf("%d\n", x+y);
			}
		}
		else if(x==y+2){
			if(x%2){
				printf("%d\n", x+x-1);
			}
			else{
				printf("%d\n", x+y);
			}
		}
		else{
			printf("No Number\n");
		}
	}
	return 0;
}

