#include<iostream>
using namespace std;
char a[50][50];
int n,cn;

void dfs(int i,int j)
{
    if(a[i][j]=='0')return;
    if(i==n-1&&j==n-1)
    {
        ++cn;
        return;
    }
    if(i+a[i][j]-'0'<n)
    {
        dfs(i+a[i][j]-'0',j);
    }
    if(j+a[i][j]-'0'<n)
    {
        dfs(i,j+a[i][j]-'0');
    }
}

int main()
{
    while(1)
    {
        scanf("%d",&n);
        if(n==-1)break;
        
        for(int i=0;i<n;++i)
            scanf("%s",a[i]);
        
        cn=0;
        dfs(0,0);
        printf("%d\n",cn);
    }
    return 0;
}
