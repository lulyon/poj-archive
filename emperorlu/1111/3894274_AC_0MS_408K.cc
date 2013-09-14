#include<iostream>
using namespace std;
char a[25][25];
bool b[25][25];

int cn;

void dfs(int i,int j)
{
    b[i][j]=1;
    if(!b[i][j-1])
    {
        if(a[i][j-1]=='.')
        {
            ++cn;
        }
        else
        {
            dfs(i,j-1);
        }
    }
    
    if(!b[i][j+1])
    {
        if(a[i][j+1]=='.')
        {
            ++cn;
        }
        else
        {
            dfs(i,j+1);
        }
    }
    
    if(!b[i-1][j])
    {
        if(a[i-1][j]=='.')
        {
            ++cn;
        }
        else
        {
            dfs(i-1,j);
        }
    }
    if(!b[i+1][j])
    {
        if(a[i+1][j]=='.')
        {
            ++cn;
        }
        else
        {
            dfs(i+1,j);
        }
    }
    
    if(!b[i-1][j-1])
    {
        if(a[i-1][j-1]=='X')
        {
            dfs(i-1,j-1);
        }
    }
    if(!b[i+1][j+1])
    {
        if(a[i+1][j+1]=='X')
        {
            dfs(i+1,j+1);
        }
    }
    if(!b[i+1][j-1])
    {
        if(a[i+1][j-1]=='X')
        {
            dfs(i+1,j-1);
        }
    }
    if(!b[i-1][j+1])
    {
        if(a[i-1][j+1]=='X')
        {
            dfs(i-1,j+1);
        }
    }
    
}

int main()
{
    int n,m,r,c;
    while(1)
    {
        scanf("%d %d %d %d",&n,&m,&r,&c);
        if(!n&&!m&&!r&&!c)break;
        
        for(int i=1;i<=n;++i)
        {
            scanf("%s",&a[i][1]);
            for(int j=0;j<=m+1;++j)
                b[i][j]=0;
            a[i][0]=a[i][m+1]='.';
        }
        for(int j=0;j<=m+1;++j)
        {
            b[0][j]=b[n+1][j]=0;
            a[0][j]=a[n+1][j]='.';
        }
        
        if(a[r][c]=='.')
        {
            printf("0\n");
            continue;
        }
        cn=0;
        dfs(r,c);
        printf("%d\n",cn);
        
        
    }
    
    return 0;
}
