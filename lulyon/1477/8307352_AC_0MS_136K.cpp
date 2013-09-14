#include<iostream>
using namespace std;
int a[110];
int main(){
	int n;
	int t=0;
	while(1){
		scanf("%d",&n);
		if(n==0)break;
		
		printf("Set #%d\n",++t);
		int sum=0;
		for(int i=0; i<n; ++i){
			scanf("%d",&a[i]);
			sum += a[i];
		}
		sum/=n;
		int cnt=0;
		for(int i=0; i<n; ++i){
			if(a[i]>sum)cnt += (a[i]-sum);
		}
		printf("The minimum number of moves is %d.\n\n",cnt);
	}
	return 0;
}

