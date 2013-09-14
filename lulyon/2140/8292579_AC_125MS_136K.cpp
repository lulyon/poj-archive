#include<iostream>
using namespace std;
int main(){
	int n;
	scanf("%d",&n);
	int cnt=0;
	for(int i=1; i<=n; i+=2){
		if(n%i==0){
			cnt++;
		}
	}
	printf("%d\n",cnt);
	return 0;
}

