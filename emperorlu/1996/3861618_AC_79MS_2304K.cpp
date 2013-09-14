#include<iostream>
using namespace std;

int a[110],b[110],c[10100],y[110][10100];

int main()
{
    int m,n;
    int t;
    cin>>t;
    while(t--)
    {
        scanf("%d %d",&m,&n);
        
        for(int i=0;i<=m;++i)
            scanf("%d",a+i);
        
        for(int i=0;i<=n;++i)
        {
            scanf("%d",b+i);
            y[1][i]=b[i];
        }
        c[0]=a[0]+a[1]*b[0];
        for(int i=1;i<=n;++i)
        {
            c[i]=a[1]*b[i];
        }
        for(int i=n+1;i<=m*n;++i)
            c[i]=0;
        
        for(int i=2;i<=m;++i)
        {
            for(int j=0;j<=i*n;++j)
            {
                y[i][j]=0;
            }
            for(int j=0;j<=(i-1)*n;++j)
            {
                for(int k=0;k<=n;++k)
                {
                    y[i][j+k]+=y[i-1][j]*b[k];
                }
            }
            for(int j=0;j<=i*n;++j)
                c[j]+=a[i]*y[i][j];
        }
        int index;
        for(index=m*n;index>=0;--index)
            if(c[index])break;
        
        printf("%d",c[0]);
        for(int i=1;i<=index;++i)
        {
            printf(" %d",c[i]);
        }
        printf("\n");
        
    }
    return 0;
}

