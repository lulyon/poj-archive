#include<iostream>
using namespace std;

const int maxn=50;

char str[5];
bool edge[maxn][maxn];
bool closure[maxn][maxn];
bool visited[maxn];

int indegree[maxn];
int stack[maxn];

int main(){
	int n,m;
	while(1){
		scanf("%d %d",&n,&m);
		if(n==0 && m==0)break;
		
		
		for(int i=0; i<n; ++i){
			for(int j=0; j<n; ++j){
				edge[i][j]=0;
			}
		}
		
		bool done=0;
		for(int t=1;t<=m; ++t){
			scanf("%s",str);
			if(done)continue;
			if(edge[str[0]-'A'][str[2]-'A'])continue;
			edge[str[0]-'A'][str[2]-'A']=1;
			
			for(int i=0; i<n; ++i){
				for(int j=0; j<n; ++j){
					closure[i][j]= edge[i][j];
				}
			}
			
			for(int k=0; k<n; ++k){
				for(int i=0; i<n; ++i){
					for(int j=0; j<n; ++j){
						if(!closure[i][j] && closure[i][k] && closure[k][j]){
							closure[i][j]=1;
						}
					}
				}
			}
			for(int i=0; i<n; ++i){
				if(closure[i][i]){
					done=1;
					printf("Inconsistency found after %d relations.\n",t);
					break;
				}
			}
			if(done==1)continue;
			int cnt=0;
			for(int i=0; i<n; ++i){
				for(int j=0; j<n; ++j){
					if(closure[i][j]){
						cnt++;
					}
				}
			}
			if(cnt!=n*(n-1)/2)continue;
			for(int i=0; i<n; ++i){
				indegree[i] = 0;
				visited[i] = 0;
			}
			
			for(int i=0; i<n; ++i){
				for(int j=0; j<n; ++j){
					if(closure[i][j]){
						indegree[j]++;
					}
				}
			}
			
			for(int k=0; k<n; ++k){
				for(int i=0; i<n; ++i){
					if(!visited[i]){
						if(!indegree[i]){
							stack[k]=i;
							visited[i]=1;
							for(int j=0; j<n; ++j){
								if(closure[i][j]){
									indegree[j]--;
								}
							}
							break;
						}
					}
				}
			}
			printf("Sorted sequence determined after %d relations: ",t);
			for(int i=0; i<n; ++i){
				printf("%c", stack[i]+'A');
			}
			printf(".\n");
			done=1;
		}
		if(done==0){
			printf("Sorted sequence cannot be determined.\n");
		}
	}
	return 0;
}

