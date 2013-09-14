#include<iostream>
using namespace std;
int n,m;

char a[110][110];
bool visited[110][110];

void dfs(int is,int js){
	if(visited[is][js]==1 || a[is][js]!='W')return;
	visited[is][js]=1;
	
	if(is-1>=1)dfs(is-1,js);
	if(is+1<=n)dfs(is+1,js);
	
	if(js-1>=1)dfs(is,js-1);
	if(js+1<=m)dfs(is,js+1);
	
	if(is-1>=1 && js-1>=1)dfs(is-1, js-1);
	if(is-1>=1 && js+1<=m)dfs(is-1, js+1);
	if(is+1<=n && js-1>=1)dfs(is+1, js-1);
	if(is+1<=n && js+1<=m)dfs(is+1, js+1);
}

int main(){
	scanf("%d%d",&n,&m);
	for(int i=1; i<=n; ++i){
		scanf("%s",&a[i][1]);
	}
	
	int cnt=0;
	for(int i=1; i<=n; ++i){
		for(int j=1; j<=m; ++j){
			if(visited[i][j]==0 && a[i][j]=='W'){
				cnt++;
				dfs(i,j);
			}
		}
	}
	printf("%d\n",cnt);
	//system("pause");
	return 0;
}

