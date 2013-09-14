#include<iostream>
#include<algorithm>
#include<math.h>
using  namespace std;
#define MAXN 760
#define MAX 1000000.000000
int n,m;

double x[MAXN],y[MAXN];

double w[MAXN][MAXN];
bool b[MAXN];

struct
{
    int other;
    double data;
    
}min_edge[MAXN];


bool connect[MAXN][MAXN];

typedef struct 
{
    int x,y;
}pp;
pp point[10*MAXN*MAXN];


int main()
{
    cin>>n;
    
    for(int i=1;i<=n;++i)
    {
        scanf("%lf%lf",x+i,y+i);
        w[i][i]=0;
    }
    
    
    
    
    for(int i=1;i<=n;++i)
    {
        for(int j=i+1;j<=n;++j)
        {
            w[i][j]=w[j][i]=sqrt((x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j]));
        }
    }
    cin>>m;
    int p1,p2;
    while(m--)
    {
        scanf("%d%d",&p1,&p2);
        w[p1][p2]=w[p2][p1]=0;
        connect[p1][p2]=connect[p2][p1]=1;
    }
    
    if(n==1)
    {
        return 0;
    }
    
    double min=MAX;
    int ii,jj;
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
    
    int top=0;
    if(!connect[ii][jj])
    {
        point[top].x=ii;
        point[top].y=jj;
        top++;
    }
    
    
    for(int i=1;i<=n;++i)
    {
        if(!b[i])
        {
            if(w[i][ii]<w[i][jj])
            {
                min_edge[i].data=w[i][ii];
                min_edge[i].other=ii;
            }
            else
            {
                min_edge[i].data=w[i][jj];
                min_edge[i].other=jj;
            }
        }
    }
    
    int k=n-2;
    int index,other;
    while(k--)
    {
        min=MAX;
        for(int i=1;i<=n;++i)
        {
            if(!b[i]&&min>min_edge[i].data)
            {
                min=min_edge[i].data;
                index=i;
                other=min_edge[i].other;
            }
        }
        
        
        b[index]=1;
        
        if(!connect[index][other])
        {                
            point[top].x=index;
            point[top].y=other;
            top++;
        }
        
        for(int i=1;i<=n;++i)
        {
            if(!b[i]&&min_edge[i].data>w[i][index])
            {
                min_edge[i].data=w[i][index];
                min_edge[i].other=index;
            }
        }
           
    }
    
    for(int i=0;i<top;++i)
    {
        printf("%d %d\n",point[i].x,point[i].y);
    }
    
    return 0;
}

