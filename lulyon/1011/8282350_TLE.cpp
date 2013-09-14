#include<iostream>
#include<algorithm>
using namespace std;
int a[100];
int success;
int visited[100];


void dfs(int length, int n, int sum, int num, int position){
	
	if(num==0){
		success = 1;
		return;
	}

	if(sum==length){
		num--;
		sum=0;
		position=0;
		dfs(length, n, sum, num, position);
		return;
	}
	if(sum>length){
		return;
	}
	for(int i=position; i<n; ++i){
		if(visited[i]==0 && sum+a[i]<=length){
			visited[i]=1;
			sum += a[i];
			dfs(length, n, sum, num, i);
			if(success==1)return;
			sum -= a[i];
			visited[i]=0;
		}
	}
}

int main(){
	int n;
	while(1){
		scanf("%d",&n);
		if(n==0)break;
		
		int sum,max;
		sum=0;
		max=-1;
		for(int i=0; i<n; ++i){
			scanf("%d",&a[i]);
			if(max<a[i])max=a[i];
			sum += a[i];
		}
		sort(a,a+n);
		
		int i,length,num;
		for(i=max;i<sum;++i){
			if(sum%i==0){
				length = i;
				num = sum/length;
				success = 0;
				
				for(int j=0; j<n; ++j){
					visited[j] = 0;
				}

				
				dfs(length,n,0,num,0);
				if(success==1){
					printf("%d\n",length);
					break;
				}
			}
		}
		if(i==sum){
			printf("%d\n",sum);
			continue;
		}
		
	}
	return 0;
}

