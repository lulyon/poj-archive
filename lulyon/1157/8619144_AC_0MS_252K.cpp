#include<iostream>
using namespace std;
const int maxn = 110;

int a[maxn][maxn];
int dp[maxn][maxn];

/************************
s[1,1]=a[1,1];
s[i,i]=s[i-1,i-1]+a[i,i];
s[1,k]=max(s[1,k-1],a[1,k]);
s[i,k]=max(s[i-1,k-1]+a[i,k],s[i,k-1]);
**************************/

int max(int a, int b)
{
	if(a>b)return a;
	else return b;
}

int main(int argc, char **argv){
	int m,n;
	scanf("%d%d",&m, &n);
	for(int i=1; i<=m; ++i){
		for(int j=1; j<=n; ++j){
			scanf("%d",&a[i][j]);
		}
	}

	dp[1][1] = a[1][1];

	for(int k=2; k<=n; ++k){
		dp[1][k] = max(dp[1][k-1], a[1][k]);
	}

	for(int i=2; i<=m; ++i){
		for(int k=i; k<=n; ++k){
			dp[i][k] = max(dp[i-1][k-1]+a[i][k],dp[i][k-1]);
		}
	}
	
	printf("%d\n",dp[m][n]);
	return 0;
}
