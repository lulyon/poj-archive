#include<stdio.h>
int max(int a,int b)
{
    return a>b?a:b;
}
int main()
{
    int n;
    scanf("%d",&n);
    int a[n][n];
    for(int i=0;i<n;i++)
        for(int j=0;j<=i;j++)
            scanf("%d",&a[i][j]);
    for(int i=n-2;i>=0;i--)
        for(int j=0;j<=i;j++)
            a[i][j]+=max(a[i+1][j],a[i+1][j+1]);
    printf("%d\n",a[0][0]);
    //while(1);
    return 0;
}