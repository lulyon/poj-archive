#include<iostream>
#include<math.h>
using namespace std;
int b[50010];
int a[100][50010];
int c[100][50010];
int min(int a,int b)
{
    if(a>b)return b;
    else return a;
}

int max(int a,int b)
{
    if(a>b)return a;
    else return b;
}

int MakeRMQMin(int n)
{
    int i,j,m;
    for(i=0;i<n;i++)
        c[0][i]=b[i];
    m=(int)ceil(log(n+0.0)/log(2.0));
    for(i=1;i<=m;i++)
        for(j=0;j<n;j++)
        {
            if(j+(1<<(i-1))<n)
                c[i][j]=min(c[i-1][j],c[i-1][j+(1<<(i-1))]);
            else
                c[i][j]=-1;
        }
    return m;
}

int MakeRMQMax(int n)
{
    int i,j,m;
    for(i=0;i<n;i++)
        a[0][i]=b[i];
    m=(int)ceil(log(n+0.0)/log(2.0));
    for(i=1;i<=m;i++)
        for(j=0;j<n;j++)
        {
            if(j+(1<<(i-1))<n)
                a[i][j]=max(a[i-1][j],a[i-1][j+(1<<(i-1))]);
            else
                a[i][j]=-1;
        }
    return m;
}

int FindMin(int m,int n)
{
    int d=n-m+1;
    int len;
    if(d==1)return c[0][m];
    else
    {
        len = (int)ceil(log(d+0.0)/log(2.0))-1;
        return min(c[len][m],c[len][n-(1<<len)+1]);
    }
}

int FindMax(int m,int n)
{
    int d=n-m+1;
    int len;
    if(d==1)return a[0][m];
    else
    {
        len = (int)ceil(log(d+0.0)/log(2.0))-1;
        return max(a[len][m],a[len][n-(1<<len)+1]);
    }
}

int main()
{
    //to do
    int n,Q;
    scanf("%d%d",&n,&Q);
    for(int i=0;i<n;i++)
        scanf("%d",b+i);
    MakeRMQMax(n);
    MakeRMQMin(n);
    int A,B;
    while(Q--)
    {
        scanf("%d%d",&A,&B);
        printf("%d\n",FindMax(A-1,B-1)-FindMin(A-1,B-1));
    }
    return 0;
}
