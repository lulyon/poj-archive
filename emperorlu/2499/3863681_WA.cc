#include<iostream>
using namespace std;
typedef struct
{
    int  l,r;
}node;

long long gcd(long long a,long long b)
{
    if(b==0)return a;
    else return gcd(b,a%b);
}


node dfs(long long a,long long b)
{
    node info;
    if(a==1)
    {
        info.l=0;
        info.r=b-1;
        return info;
    }
    if(b==1)
    {
        info.l=a-1;
        info.r=0;
        return info;
    }
    
    if(a<b)
    {
        info = dfs(a,b%a);
        info.r+=b/a;
        return info;
    }
    else
    {
        info = dfs(a%b,b);
        info.l+=a/b;
        return info;
    }
}

int main()
{
    int t;
    long long a,b;
    node info;
    cin>>t;
    for(int i=1;i<=t;++i)
    {
        scanf("%lld%lld",&a,&b);
        if(gcd(a,b)!=1)
        {
            printf("00000000000\n");
            continue;
        }
        info = dfs(a,b);
        printf("Scenario #%d:\n",i);
        printf("%d %d\n\n",info.l,info.r);
    }
    return 0;
}


