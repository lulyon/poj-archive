#include<iostream>
using namespace std;

char s[110][110];
bool visited[110][110];

void dfs(int h,int w,int is, int js){
	if(visited[is][js]==1 || s[is][js]=='#'){
		return;
	}	
	visited[is][js]=1;
	if(is-1>0)dfs(h, w, is-1, js);
	if(is+1<=h)dfs(h, w, is+1, js);
	if(js-1>0)dfs(h, w, is, js-1);
	if(js+1<=w)dfs(h, w, is, js+1);
	
}

int main(){
	int w,h;
	while(1){
		scanf("%d %d",&w,&h);
		if(w==0 && h==0)break;
		
		for(int i=1; i<=h; ++i){
			scanf("%s",&s[i][1]);
		}
		
		int istart, jstart;
		for(int i=1; i<=h; ++i){
		for(int j=1; j<=w; ++j){
			if(s[i][j]=='@'){
					istart = i;
					jstart = j;
				}
				visited[i][j]=0;
			}
		}
		
		dfs(h,w,istart, jstart);
		
		int cnt=0;
		for(int i=1; i<=h; ++i){
			for(int j=1; j<=w; ++j){
				if(visited[i][j])cnt++;
			}
		}
		printf("%d\n",cnt);
	}
	return 0;
}

