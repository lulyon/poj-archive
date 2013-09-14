#include<iostream>
using namespace std;
int a[5];
int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		for(int i=0; i<4; ++i){
			scanf("%d",&a[i]);
			printf("%d ",a[i]);
		}
		
		if(a[0]+a[2]== a[1]+a[1]){
			printf("%d\n",a[3]+a[3]-a[2]);
		}
		else{
			printf("%d\n",a[3]*a[3]/a[2]);
		}
	}
	return 0;
}

