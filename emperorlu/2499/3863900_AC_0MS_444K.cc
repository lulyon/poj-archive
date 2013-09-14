#include<iostream>
using namespace std;
typedef struct
{
    __int64  l,r;
}node;

__int64 gcd(__int64 a,__int64 b)
{
    if(b==0)return a;
    else return gcd(b,a%b);
}


node dfs(__int64 a,__int64 b)
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
    __int64 a,b;
    node info;
    cin>>t;
    for(int i=1;i<=t;++i)
    {
        scanf("%I64d%I64d",&a,&b);
       
        info = dfs(a,b);
        printf("Scenario #%d:\n",i);
        printf("%I64d %I64d\n\n",info.l,info.r);

    }
    return 0;
}


