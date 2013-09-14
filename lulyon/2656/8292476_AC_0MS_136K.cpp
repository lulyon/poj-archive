#include<iostream>
using namespace std;
int main(){
	int n;
	while(1){
		scanf("%d",&n);
		if(n==0)break;
		
		int index=0, max=0;
		int a,b;
		for(int i=1; i<=n; ++i){
			scanf("%d%d",&a,&b);
			if(a+b>8 && max<a+b){
				index=i;
				max=a+b;
			}
		}
		printf("%d\n",index);
	}
	return 0;
}

