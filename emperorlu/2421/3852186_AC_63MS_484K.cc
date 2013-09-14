#include<iostream>
using  namespace std;
int n,m;
int w[110][110];
bool b[110];

int min_edge[110];

int main()
{
    cin>>n;
    for(int i=1;i<=n;++i)
    {
        for(int j=1;j<=n;++j)
        {
            scanf("%d",&w[i][j]);
        }
    }
    cin>>m;
    int p1,p2;
    while(m--)
    {
        scanf("%d%d",&p1,&p2);
        w[p1][p2]=w[p2][p1]=0;
    }
    
    memset(b,0,sizeof(b));
    int min=INT_MAX,ii,jj;
    for(int i=1;i<=n;++i)
    {
        for(int j=i+1;j<=n;++j)
        {
            if(min>w[i][j])
            {
                min=w[i][j];
                ii=i;
                jj=j;
            }
        }
    }
    b[ii]=1;
    b[jj]=1;
    
    int cost=min;
    
    
    for(int i=1;i<=n;++i)
    {
        if(!b[i])
        {
            min_edge[i]=w[i][ii]<w[i][jj]?w[i][ii]:w[i][jj];
        }
    }
    
    m=n-2;
    int index;
    while(m--)
    {
        min=INT_MAX;
        for(int i=1;i<=n;++i)
        {
            if(!b[i]&&min>min_edge[i])
            {
                min=min_edge[i];
                index=i;
            }
        }
        cost+=min;
        
        b[index]=1;
        
        for(int i=1;i<=n;++i)
        {
            if(!b[i]&&min_edge[i]>w[i][index])
            {
                min_edge[i]=w[i][index];
            }
        }
        
        
    }
    
    printf("%d\n",cost);
    
    return 0;
}
