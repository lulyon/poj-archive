#include<iostream>
using namespace std;
char a[25][25];
bool b[25][25];
int cn,w,h;
void f(int m,int n)
{
    if(!b[m-1][n]&&a[m-1][n]=='.')
    {
        cn++;
        b[m-1][n]=1;
        f(m-1,n);
    }
    if(!b[m+1][n]&&a[m+1][n]=='.')
    {
        cn++;
        b[m+1][n]=1;
        f(m+1,n);
    }
    if(!b[m][n-1]&&a[m][n-1]=='.')
    {
        cn++;
        b[m][n-1]=1;
        f(m,n-1);
    }
    if(!b[m][n+1]&&a[m][n+1]=='.')
    {
        cn++;
        b[m][n+1]=1;
        f(m,n+1);
    }
    return;
}
int main()
{
    int ii,jj;
    while(1)
    {
        scanf("%d%d",&w,&h);
        if(!w&&!h)break;
        getchar();
        
        for(int j=0;j<=w+1;++j)
            b[0][j]=b[h+1][j]=1;
        for(int i=0;i<=h+1;++i)
            b[i][0]=b[i][w+1]=1;
            
        for(int i=1;i<=h;++i)
        {
            for(int j=1;j<=w;++j)
            {
                scanf("%c",&a[i][j]);
                if(a[i][j]=='@')
                {
                    ii=i;
                    jj=j;
                    b[i][j]=1;
                }
                else b[i][j]=0;
            }
            getchar();
        }
        cn=1;
        f(ii,jj);
        printf("%d\n",cn);
    }
    return 0;
}
