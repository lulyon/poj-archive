#include<iostream>
using namespace std;
#define N 110
char a[N][N];
bool b[N][N];
void visit(int i,int j)
{
    b[i][j]=1;
    if(!b[i-1][j]&&a[i-1][j]=='@')
    {
   
        visit(i-1,j);
    }
    if(!b[i+1][j]&&a[i+1][j]=='@')
    {
 
        visit(i+1,j);
    }
    if(!b[i][j-1]&&a[i][j-1]=='@')
    {
  
        visit(i,j-1);
    }
    if(!b[i][j+1]&&a[i][j+1]=='@')
    {
  
        visit(i,j+1);
    }
    if(!b[i-1][j-1]&&a[i-1][j-1]=='@')
    {
 
        visit(i-1,j-1);
    }
    if(!b[i+1][j-1]&&a[i+1][j-1]=='@')
    {
        

        visit(i+1,j-1);
    }
    if(!b[i+1][j+1]&&a[i+1][j+1]=='@')
    {
        visit(i+1,j+1);
    }
    if(!b[i-1][j+1]&&a[i-1][j+1]=='@')
    {
 
        visit(i-1,j+1);
    }
}

int main()
{
    //freopen("in.dat","r",stdin);
    //freopen("out.dat","w",stdout);
    int m,n;
    while(1)
    {
        scanf("%d%d",&m,&n);
        if(!m&&!n)break;
        for(int i=1;i<=m;++i)
        {
            scanf("%s",&a[i][1]);
            for(int j=1;j<=n;++j)
                b[i][j]=0;
            b[i][0]=b[i][n+1]=1;
        }
        for(int j=0;j<=n+1;++j)
        {
            b[0][j]=b[m+1][j]=1;
        }
        int cn=0;
        for(int i=1;i<=m;++i)
        {
            for(int j=1;j<=n;++j)
            {
                if(!b[i][j]&&a[i][j]=='@')
                {
                    ++cn;
                    visit(i,j);
                }
            }
        }
        printf("%d\n",cn);
        
    }
    return 0;
}