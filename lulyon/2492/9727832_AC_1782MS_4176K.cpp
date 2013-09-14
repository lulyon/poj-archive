#include<iostream>
using namespace std;

const int maxn = 2012;
bool course[maxn][maxn];
int parent[maxn];
int visited[maxn];

bool done;
void dfs(int v, int n)
{
	if(done == 1)return;
	visited[v]=1;
	for(int i=1; i<=n; ++i){
		if(done==1)return;
		if(course[v][i]){
			if(visited[i]==0){
				parent[i] = v;
				dfs(i, n);
				if(done==1)return;
			}
			else if(visited[i]==1){
				if(parent[v]!=i){
					int count = 1;
					for(int j=v; j!=i; j=parent[j]){
						count ++;
					}
					if(count % 2 == 1){
						done = 1;
						return;
					}
				}
			}
		}
	}
	visited[v]=2;
}

int main(int argc, char** argv)
{
	int t;
	scanf("%d", &t);
	for(int k=1; k<=t; ++k){
		int n, m;
		scanf("%d%d", &n, &m);

		for(int i=1; i<=n; ++i){
			for(int j=1; j<=n; ++j){
				course[i][j] = 0;
			}
		}

		for(int i=1; i<=m; ++i){
			int vs, ve;
			scanf("%d%d", &vs, &ve);
			course[vs][ve] = 1;
			course[ve][vs] = 1;
		}

		for(int i=1; i<=n; ++i){
			course[i][i] = 0;
			visited[i] = 0;
			parent[i] = 0;
		}

		done = 0;
		for(int i=1; i<=n; ++i){
			if(visited[i] == 0){
				dfs(i, n);
				if(done==1)break;
			}
		}

		if(k>1)printf("\n");
		printf("Scenario #%d:\n", k);
		if(done==1){
			printf("Suspicious bugs found!\n");
		}
		else{
			printf("No suspicious bugs found!\n");
		}
	}
	return 0;
}


