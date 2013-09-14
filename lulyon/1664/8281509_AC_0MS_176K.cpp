#include<iostream>
using namespace std;
int cnt[20];
int way;

void dfs(int m, int n, int position){
	if(m==0){
		way++;
		return;
	}
	if(position==1){
		cnt[1]++;
		dfs(m-1,n, 1);
		cnt[1]--;
	}
	for(int i=2; i<=n; ++i){
		if(cnt[i-1]>cnt[i] && i>=position){
			cnt[i]++;
			dfs(m-1,n, i);
			cnt[i]--;
		}
	}
}

int main(){
	int m,n,t;
	scanf("%d",&t);
	while(t--){
		scanf("%d%d",&m,&n);
		for(int i=1; i<=n; ++i){
			cnt[i] = 0;
		}
		
		way=0;
		dfs(m,n,1);
		
		printf("%d\n",way);
	}
	
	return 0;
}

