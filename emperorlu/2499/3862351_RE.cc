#include<iostream>
using namespace std;
typedef struct
{
    int l,r;
}node;

node dfs(long a,long b)
{
    node info;
    if(a==1&&b==1)
    {
        info.l=0;
        info.r=0;
        return info;
    }
    if(a<b)
    {
        info = dfs(a,b-a);
        ++info.r;
        return info;
    }
    else
    {
        info = dfs(a-b,b);
        ++info.l;
        return info;
    }
}

int main()
{
    int t;
    long a,b;
    node info;
    cin>>t;
    for(int i=1;i<=t;++i)
    {
        scanf("%ld%ld",&a,&b);
        info = dfs(a,b);
        printf("Scenario #%d:\n",i);
        printf("%d %d\n\n",info.l,info.r);
    }
    return 0;
}
