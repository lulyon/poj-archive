#include <iostream>
using namespace std;

const int maxn = 110;
char grid[maxn][maxn];
bool visited[maxn][maxn];

int m, n;
void dfs(int row, int col)
{
    if(!(row>=1 && row<=m && col>=1 && col<=n))return;
    if(visited[row][col])return;
    if(grid[row][col]!='@')return;
    visited[row][col]=1;
    for(int i=-1; i<=1; ++i){
	for(int j=-1; j<=1; ++j){
	    dfs(row + i, col + j);
	}
    }
}

int main()
{
	while(1){
		scanf("%d%d", &m, &n);
		if(!m && !n)break;

		for (int i=1; i<=m; ++i){
		    scanf("%s", &grid[i][1]);
		}

		for(int i=1; i<=m; ++i){
		    for(int j=1; j<=n; ++j){
			visited[i][j] = 0;
		    }
		}
		int count = 0;
		for(int i=1; i<=m; ++i){
		    for(int j=1; j<=n; ++j){
			if(grid[i][j]=='@' && visited[i][j]==0){
			    count ++;
			    dfs(i, j);
			}
		    }
		}
		printf("%d\n",count);
	}
	return 0;
}

