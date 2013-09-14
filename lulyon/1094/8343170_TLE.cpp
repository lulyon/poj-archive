#include<iostream>
using namespace std;

char str[10];

bool edge[50][50];

int cnt[50];

bool vertex[50];

bool visited[50];

int output[50];

bool checkcircle(int index, int n){
	visited[index]=1;
	for(int j=0; j<n; ++j){
		if(edge[index][j]==1){
			if(visited[j] || checkcircle(j,n)){
				visited[index]=0;
				return 1;
			}
		}
	}
	visited[index]=0;
	return 0;
}

bool havelongestpath(int length, int index, int n){
	output[length] = index;
	if(length==n)return 1;
	
	visited[index]=1;
	for(int j=0; j<n; ++j){
		if(edge[index][j]==1){
			if(!visited[j]){
				if(havelongestpath(length+1, j, n)){
					visited[index]=0;
					return 1;
				}
			}
		}
	}
	visited[index]=0;
	return 0;
}

int main(){
	int n,m;
	while(1){
		scanf("%d%d",&n,&m);
		if(n==0 && m==0)break;
		
		
		for(int i=0; i<n; ++i){
			cnt[i]=0;
			for(int j=0; j<n; ++j){
				edge[i][j]=0;
			}
		}
		
		bool done=0;
		for(int i=0; i<n; ++i){
			vertex[i]=0;
		}
		
		for(int i=1; i<=m; ++i){
			scanf("%s",str);
			if(done==1)continue;
			
			if(edge[str[0]-'A'][str[2]-'A'])continue;
			edge[str[0]-'A'][str[2]-'A']=1;
			cnt[str[2]-'A']++;
			vertex[str[0]-'A']=1;
			vertex[str[2]-'A']=1;
			
			int sum=0;
			for(int j=0;j<n; ++j){
				visited[j]=0;
				if(vertex[j])sum++;
			}
			if(checkcircle(str[0]-'A',n)){
				printf("Inconsistency found after %d relations.\n", i);
				done=1;
				continue;
			}
			
			
			if(sum<n)continue;
			bool havelp=0;
			for(int j=0; j<n; ++j){
				if(cnt[j]==0){
					if(havelongestpath(1,j,n)){
						havelp=1;
						break;
					}
				}
			}
			if(havelp){
				printf("Sorted sequence determined after %d relations: ",i);
				for(int j=1; j<=n; ++j){
					printf("%c",output[j]+'A');
				}
				printf(".\n");
				done=1;
				continue;
			}
		}
		if(done==0){
			printf("Sorted sequence cannot be determined.\n");
		}
	}
	return 0;
}

