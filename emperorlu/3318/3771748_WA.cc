#include<iostream>
using namespace std;
int a[510][510],b[510][510],c[510][510];
int w[510],x[510],y[510],z[510];
int main()
{
    int i,j,n;
    while(scanf("%d",&n)!=EOF)
    {
        for(i=0;i<n;++i)
            for(j=0;j<n;++j)
                scanf("%d",&a[i][j]);
        for(i=0;i<n;++i)
            for(j=0;j<n;++j)
                scanf("%d",&b[i][j]);
        for(i=0;i<n;++i)
            for(j=0;j<n;++j)
                scanf("%d",&c[i][j]);
        for(i=0;i<n;++i)
        {
            w[i]=i;
        }
        for(i=0;i<n;++i)
        {
            x[i]=0;
            for(j=0;j<n;++j)
            {
                x[i]+=w[i]*a[j][i];
            }
        }
        for(i=0;i<n;++i)
        {
            y[i]=0;
            for(j=0;j<n;++j)
            {
                y[i]+=x[i]*b[j][i];
            }
        }
        for(i=0;i<n;++i)
        {
            z[i]=0;
            for(j=0;j<n;++j)
            {
                z[i]+=w[i]*c[j][i];
            }
        }
        for(i=0;i<n;++i)
        {
            if(y[i]!=z[i])
            {
                printf("NO\n");
                break;
            }
        }
        if(i==n)printf("YES\n");
    }
    return 0;
}