#include<iostream>
using namespace std;
int num[30][30];
char ch[30][30];

void dfs(int i,int j)
{
    if(ch[i][j]=='E')
    {
        if(num[i][j+1]==INT_MAX)
        {
            printf("%d step(s) to exit\n",num[i][j]);
            return;
        }
        else if(num[i][j+1]==0)
        {
            num[i][j+1]=num[i][j]+1;
            dfs(i,j+1);
        }
        else
        {
            printf("%d step(s) before a loop of %d step(s)\n",num[i][j+1]-1,num[i][j]-num[i][j+1]+1);
            return;
        }
    }
    
    if(ch[i][j]=='W')
    {
        if(num[i][j-1]==INT_MAX)
        {
            printf("%d step(s) to exit\n",num[i][j]);
            return;
        }
        else if(num[i][j-1]==0)
        {
            num[i][j-1]=num[i][j]+1;
            dfs(i,j-1);
        }
        else
        {
            printf("%d step(s) before a loop of %d step(s)\n",num[i][j-1]-1,num[i][j]-num[i][j-1]+1);
            return;
        }
    }
    
    if(ch[i][j]=='N')
    {
        if(num[i-1][j]==INT_MAX)
        {
            printf("%d step(s) to exit\n",num[i][j]);
            return;
        }
        else if(num[i-1][j]==0)
        {
            num[i-1][j]=num[i][j]+1;
            dfs(i-1,j);
        }
        else
        {
            printf("%d step(s) before a loop of %d step(s)\n",num[i-1][j]-1,num[i][j]-num[i-1][j]+1);
            return;
        }
    }
    
    if(ch[i][j]=='S')
    {
        if(num[i+1][j]==INT_MAX)
        {
            printf("%d step(s) to exit\n",num[i][j]);
            return;
        }
        else if(num[i+1][j]==0)
        {
            num[i+1][j]=num[i][j]+1;
            dfs(i+1,j);
        }
        else
        {
            printf("%d step(s) before a loop of %d step(s)\n",num[i+1][j]-1,num[i][j]-num[i+1][j]+1);
            return;
        }
    }
}

int main()
{
    int n,m,enter;
    while(1)
    {
        scanf("%d%d%d",&n,&m,&enter);
        if(!n&&!m&&!enter)break;
        
        getchar();
        for(int j=0;j<=m+1;++j)
            num[0][j]=num[n+1][j]=INT_MAX;
        
        for(int i=1;i<=n;++i)
        {
            for(int j=1;j<=m;++j)
            {
                ch[i][j]=getchar();
                num[i][j]=0;
            }
            getchar();
            num[i][0]=num[i][m+1]=INT_MAX;
        }
        num[1][enter]=1;
        dfs(1,enter);
    }
    return 0;
}
