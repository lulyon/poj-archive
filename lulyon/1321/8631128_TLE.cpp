#include <iostream>

char str[10][10];

bool visited[10];

int count;

void dfs(int col, int n, int depth, int k){

	if(depth == k){
		count++;
		return;
	}

	for(int i=col; i<n; ++i){
		for(int j=0; j<n; ++j){
			if(str[i][j]=='#'){
				if(!visited[i]){
					visited[i] = 1;
					dfs(col+1, n, depth+1, k);
					visited[i] = 0;
				}
			}
		}
	}
}


int main(int argc, char ** argv){
	int n, k;

	while(1){
		scanf("%d%d", &n, &k);

		if(n==-1 && k==-1)break;

		for(int i=0; i<n; ++i){
			scanf("%s", str[i]);
		}

		memset(visited, 0, sizeof(visited));
		count=0;
		dfs(0, n, 0, k);
		printf("%d\n", count);
	}
	return 0;
}
