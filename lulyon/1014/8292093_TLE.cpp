#include<iostream>
using namespace std;

const int maxn=6;
int num[10];

bool success;

void dfs(int n, int total, int sum, int pos){
	if(success==1){
		return;
	}
	
	if(sum==total){
		success=1;
		return;
	}
	
	for(int i=pos; i<=n; ++i){
		if(num[i]>0){
			if(sum+i>total)return;
			
			sum += i;
			num[i]--;
			dfs(n, total, sum, i);
			if(success==1)return;
			num[i]++;
			sum -= i;
		}
	}
}

int main(){
	int t = 0;
	while(1){
		int sum=0;
		for(int i=1; i<=maxn; ++i){
			scanf("%d",&num[i]);
			sum += num[i]*i;
		}
		if(sum==0)break;
		printf("Collection #%d:\n", ++t);
		if(sum%2==1){
			printf("Can't be divided.\n\n");
			continue;
		}
		
		sum/=2;
		success=0;
		dfs(maxn, sum, 0, 1);
		if(success==1)printf("Can be divided.\n\n");
		else printf("Can't be divided.\n\n");
	}
	return 0;
}

