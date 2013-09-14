#include<iostream>
using namespace std;
int main(){
	int t;
	int m,n;
	scanf("%d",&t);
	while(t--){
		scanf("%d%d",&m,&n);
		if(m<n || (m-n)%2==1){
			printf("impossible\n");
		}
		else{
			printf("%d %d\n", (m+n)/2, (m-n)/2);
		}
	}
	return 0;
}

