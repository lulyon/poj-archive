#include<iostream>
using namespace std;
bool b[55][55];
int a[55][55];

int cn;

void dfs(int i,int j)
{
    b[i][j]=1;
    ++cn;
    if(a[i][j]%2==0)
    {
        if(!b[i][j-1])dfs(i,j-1);
    }
    a[i][j]/=2;
    if(a[i][j]%2==0)
    {
        if(!b[i-1][j])dfs(i-1,j);
    }
    a[i][j]/=2;
    if(a[i][j]%2==0)
    {
        if(!b[i][j+1])dfs(i,j+1);
    }
    a[i][j]/=2;
    if(a[i][j]%2==0)
    {
        if(!b[i+1][j])dfs(i+1,j);
    }
    
}

int main()
{
    int i,j,m,n;
    cin>>m>>n;
    for(i=1;i<=m;++i)
    {
        for(j=1;j<=n;++j)
        {
            scanf("%d",&a[i][j]);
            b[i][j]=0;
        }
        b[i][0]=b[i][n+1]=1;
    }
    for(j=0;j<=n+1;++j)
        b[0][j]=b[m+1][j]=1;
    
    int max=-1,num=0;
    for(i=1;i<=m;++i)
        for(j=1;j<=n;++j)
        {
            if(!b[i][j])
            {
                ++num;
                cn=0;
                dfs(i,j);
                if(max<cn)max=cn;
            }
        }
    printf("%d\n%d\n",num,max);
    
    return 0;
}
