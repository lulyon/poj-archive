#include<iostream>
#include<algorithm>
using namespace std;
int a[100];
int success;
int visited[100];
int findone;

void find(int length, int n, int sum){
	if(findone==1)return;
	
	if(sum==length){
		findone=1;
		return;
	}
	if(sum>length){
		return;
	}
	for(int i=0; i<n; ++i){
		if(visited[i]==0){
			visited[i]=1;
			sum += a[i];
			find(length, n, sum);
			if(findone)return;
			sum -= a[i];
			visited[i]=0;
		}
	}
}

void dfs(int length,int n,int num){
	if(num==0){
		success = 1;
		return;
	}
	
	while(1){
		if(num>0){
			int sum=0;
			findone=0;
			find(length,n,sum);
			if(findone==1){
				num--;
			}
			else{
				success=0;
				return;
			}
		}
		else{
			success=1;
			return;
		}
	}
}

int cmp(const int &a, const int &b){
	if(a>=b)return 1;
	else return 0;
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
		sort(a,a+n,cmp);
		
		int i,length,num;
		for(i=max;i<sum;++i){
			if(sum%i==0){
				length = i;
				num = sum/length;
				success = 0;
				
				for(int j=0; j<n; ++j){
					visited[j] = 0;
				}
				dfs(length,n,num);
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

