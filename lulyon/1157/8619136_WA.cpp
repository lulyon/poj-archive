#include<iostream>
using namespace std;
const int maxn = 110;

int a[maxn][maxn];
int dp[maxn][maxn];

int main(int argc, char **argv){
	int m,n;
	scanf("%d%d",&m, &n);
	for(int i=1; i<=m; ++i){
		for(int j=1; j<=n; ++j){
			scanf("%d",&a[i][j]);
			dp[i][j] = a[i][j];
		}
	}
	
	for(int i=2; i <=m; ++i){
		for(int j=2; j<=n; ++j){
			if(j>=i){
				for(int k=1; k<j; ++k){
					if(dp[i][j]<dp[i-1][k]+a[i][j]){
						dp[i][j] = dp[i-1][k]+a[i][j];
					}
				}
			}
		}
	}
	
	printf("%d\n",dp[m][n]);
	return 0;
}
