#include<iostream>
#define MAXN 1000010
using namespace std;
int a[MAXN],f[MAXN];
int dp(int n)
{
    f[1]=a[1];
    int i,j;
    for(i=1;i<=n;++i)
    {
        int max=0;
        for(j=1;j<i;++j)
        {
            if(a[j]<a[i]&&max<f[j])max=f[j];
        }
        f[i]=max+1;
    }
    int max=f[1];
    for(i=2;i<=n;++i)
        if(max<f[i])max=f[i];
    return max;
}
int main()
{
    int n,t;
    cin>>t;
    while(t--)
    {
        scanf("%d",&n);
        for(int i=1;i<=n;++i)
            scanf("%d",a+i);
        
        printf("%d\n",dp(n));
    }
    return 0;
}
