#include<iostream>
using namespace std;
int a[100000];
int f[100000];
int dp(int n)
{
    if(n==1)return 1;
    f[n-1]=1;
    for(int i=n-2;i>=0;--i)
    {
        f[i]=0;
        for(int j=n-1;j>i;--j)
        {
            if(a[i]>=a[j]&&f[i]<f[j])
                f[i]=f[j];
        }
        ++f[i];
    }
    for(int i=1;i<n;++i)
        if(f[i]>f[0])f[0]=f[i];
    
    return f[0];
}

int main()
{
    int flag=1;
    int n=0,tt=0;
    while(1)
    {
        scanf("%d",&a[n++]);
        if(a[n-1]==-1)
        {
            if(flag==1)
                break;
            else
            {
                flag=1;
                n--;
                printf("Test #%d:\n",++tt);
                printf("  maximum possible interceptions: %d\n\n",dp(n));
                n=0;
            }
        }
        else
        {
            flag=0;
        }
    }
    return 0;
}
