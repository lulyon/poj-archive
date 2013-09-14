#include<iostream>
using namespace std;

int a[50010];
int b[50010];
int c[50010];

int main(){
	int n,t;
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		for(int i=1; i<=n; ++i){
			scanf("%d",a+i);
		}
		
		for(int i=1; i<=n; ++i){
			if(i==1){
				b[i]=a[i];
			}
			else{
				if(b[i-1]>0){
					b[i] = a[i]+b[i-1];
				}
				else{
					b[i]=a[i];
				}
			}
		}
		
		for(int i=2;i<=n; ++i){
			if(b[i]<b[i-1])b[i]=b[i-1];
		}
		
		for(int i=n; i>=1; --i){
			if(i==n)c[i]=a[i];
			else{
				if(c[i+1]>0){
					c[i]=c[i+1]+a[i];
				}
				else{
					c[i]=a[i];
				}
			}
		}
		
		for(int i=n-1; i>=1; --i){
			if(c[i]<c[i+1])c[i]=c[i+1];
		}
		
		int max=b[1]+c[2];
		for(int i=2; i+1<=n; ++i){
			if(max<b[i]+c[i+1])max=b[i]+c[i+1];
		}
		printf("%d\n",max);
	}
	return 0;
}

