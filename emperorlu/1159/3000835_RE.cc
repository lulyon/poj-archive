#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int minof(int a,int b)
{
    return a<b?a:b;
}
int main()
{
    int n;
    char a[n];
    int dp[n][n];
    memset(dp,0,sizeof(dp));
    scanf("%d",&n);
    scanf("%s",a+1);
    for(int i=n;i>0;i--)
    {
        for(int j=i;j<=n;j++)
        {
            if(a[i]==a[j])
                dp[i][j]=dp[i+1][j-1];
            else
                dp[i][j]=minof(dp[i+1][j],dp[i][j-1])+1;
        }
    }
    printf("%d\n",dp[1][n]);
    return 0;
}
