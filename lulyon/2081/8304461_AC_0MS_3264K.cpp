#include<iostream>
using namespace std;
bool visited[3012501];
int a[500001];
int main(){
	a[0]=0;
	visited[a[0]]=1;
	
	for(int k=1; k<500000; ++k){
		a[k]=a[k-1]-k;
		if(a[k]<=0 || visited[a[k]]){
			a[k] = a[k]+k+k;
		}
		visited[a[k]]=1;
	}
	
	int n;
	while(1){
		scanf("%d",&n);
		if(n==-1)break;
		
		printf("%d\n",a[n]);
	}
	return 0;
}

