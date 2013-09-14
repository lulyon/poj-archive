#include<iostream>
using namespace std;

char str[10];

bool edge[50][50];

int cnt[50];

bool visited[50];
bool havecircle;

void checkcircle(int index, int n){
	if(havecircle)return;
	visited[index]=1;
	for(int j=0; j<n; ++j){
		if(edge[index][j]==1){
			if(!visited[j]){
				checkcircle(j,n);
			}
			else{
				havecircle=1;
			}
			if(havecircle)return;
		}
	}
	visited[index]=0;
	return;
}

bool havelongestpath(int length, int index, int n){
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
			for(int j=0; j<n; ++j){
				edge[i][j]=0;
			}
		}
		
		for(int i=0; i<n; ++i){
			cnt[i]=0;
		}
		
		bool done=0;
		for(int i=1; i<=m; ++i){
			scanf("%s",str);
			if(done==1)continue;
			
			edge[str[0]-'A'][str[2]-'A']=1;
			
			for(int j=0;j<n; ++j){
				visited[j]=0;
			}
			havecircle=0;
			checkcircle(str[0]-'A',n);
			if(havecircle){
				printf("Inconsistency found after %d relations.\n", i);
				done=1;
				continue;
			}
			
			for(int j=0;j<n; ++j){
				visited[j]=0;
			}
			cnt[str[2]-'A']++;
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
				for(int j=0; j<n; ++j){
					printf("%c",j+'A');
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

