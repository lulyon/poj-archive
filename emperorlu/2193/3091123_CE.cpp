#include<iostream>
using namespace std;
__int64 dp[11][2001];
int main()
{
    int tt,t,n,m,i,j;
    cin>>t;
    for(tt=1;tt<=t;tt++)
    {
        cin>>n>>m;
        printf("Case %d: n = %d, m = %d, # lists = ",tt,n,m);
        memset(dp,0,(n+1)*(m+1)*sizeof(int));
        for(i=1;i<=m;i++)
            dp[1][i]=i;
        for(i=2;i<=n;i++)
            for(j=2;j<=m;j++)
                dp[i][j]=dp[i][j-1]+dp[i-1][j/2];
        cout<<dp[n][m]<<endl;
    }
    return 0;
}
