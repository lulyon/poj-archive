#include<iostream>
#include<algorithm>
using namespace std;

int milk[10010];

int main(){
	int n;
	scanf("%d",&n);
	for(int i=0; i<n; ++i){
		scanf("%d",&milk[i]);
	}
	
	sort(milk, milk+n);
	printf("%d\n",milk[(n-1)/2]);
	return 0;
}

