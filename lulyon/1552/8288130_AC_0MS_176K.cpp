#include<iostream>
#include<algorithm>
using namespace std;
int a[20];
int main(){
	while(1){
		scanf("%d",&a[0]);
		if(a[0]==-1)break;
		if(a[0]==0){
			printf("0\n");
			continue;
		}
		int n;
		for(int i=1; ;++i){
			scanf("%d",&a[i]);
			if(a[i]==0){
				n=i;
				break;
			}
		}
		
		sort(a, a+n);

		
		int cnt=0;
		for(int i=0; i<n; ++i){
			for(int j=i+1; j<n; ++j){
				if(a[i]+a[i]==a[j]){
					cnt++;
					break;
				}
				else if(a[i]+a[i]<a[j]){
					break;
				}
			}
		}
		printf("%d\n",cnt);
	}
	return 0;
}

