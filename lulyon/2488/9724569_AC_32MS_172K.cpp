#include <iostream>
using namespace std;

const int maxn = 30;
bool board[maxn][maxn];
bool done;
int p,q;
typedef struct NODE{
	int row;
	int col;
}infoType;
infoType stack[maxn*maxn];

void dfs(int row, int col, int count)
{
	if(done == 1)return;
	if(!(row>=1 && row<=p && col>=1 && col<=q))return;
	if(board[row][col] == 0){
		board[row][col] = 1;
		stack[count].row = row;
		stack[count].col = col;

		if(count >= p*q){
			done = 1;
			for(int i=1; i<=p*q; ++i){
				printf("%c%d", 'A'+ stack[i].row - 1, stack[i].col);
			}
			printf("\n");
			return;
		}

		count = count + 1;
		int nr, nc;
		nr = row - 2;
		nc = col - 1;
		dfs(nr, nc, count);

		nr = row - 2;
		nc = col + 1;
		dfs(nr, nc, count);

		nr = row - 1;
		nc = col - 2;
		dfs(nr, nc, count);

		nr = row - 1;
		nc = col + 2;
		dfs(nr, nc, count);

		nr = row + 1;
		nc = col - 2;
		dfs(nr, nc, count);

		nr = row + 1;
		nc = col + 2;
		dfs(nr, nc, count);

		nr = row + 2;
		nc = col - 1;
		dfs(nr, nc, count);

		nr = row + 2;
		nc = col + 1;
		dfs(nr, nc, count);

		board[row][col] = 0;
	}
}

int main(int argc, char **argv)
{
	int n;
	scanf("%d", &n);
	for(int i=1; i<=n; ++i){
		if(i>1)printf("\n");
		printf("Scenario #%d:\n", i);
		scanf("%d%d", &q, &p);
		for (int i=1; i<=p; ++i){
			for (int j=1; j<=q; ++j){
				for (int ii=1; ii<=p; ++ii){
					for(int jj=1; jj<=q; ++jj){
						board[ii][jj]=0;
					}
				}
				done = 0;
				dfs(i, j, 1);
				if(done==1)goto leap;
			}
		}
		printf("impossible\n");
		leap:;
	}
	return 0;
}