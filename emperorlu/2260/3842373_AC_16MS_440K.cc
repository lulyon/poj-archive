#include<iostream>
using namespace std;
int a[110][110];
int n;
bool check()
{
    int i,j;
    for(j=0;j<=n;++j)
            if(a[0][j]%2)break;
    if(j<=n)return 0;
        for(i=0;i<=n;++i)
            if(a[i][0]%2)break;
    if(i<=n)return 0;
    return 1;
}
int main()
{
    int i,j,ii,jj;
    while(1)
    {
        scanf("%d",&n);
        if(!n)break;
        for(j=0;j<=n;++j)
            a[0][j]=0;
        
        for(i=0;i<=n;++i)
            a[i][0]=0;
        
        for(i=1;i<=n;++i)
        {
            for(int j=1;j<=n;++j)
            {
                scanf("%d",&a[i][j]);
                a[i][0]+=a[i][j];
                a[0][j]+=a[i][j];
            }
        }

        if(check())
        {
            printf("OK\n");
            continue;
        }
        bool flag=0;
        for(ii=1;ii<=n;++ii)
        {
            for(jj=1;jj<=n;++jj)
            {
                if(a[ii][jj])
                {
                    --a[0][jj];
                    --a[ii][0];
                    if(check())
                    {
                        printf("Change bit (%d,%d)\n",ii,jj);
                        flag=1;
                        goto leap;
                    }
                    ++a[0][jj];
                    ++a[ii][0];
                }
                else
                {
                    ++a[0][jj];
                    ++a[ii][0];
                    if(check())
                    {
                        printf("Change bit (%d,%d)\n",ii,jj);
                        flag=1;
                        goto leap;
                    }
                    --a[0][jj];
                    --a[ii][0];
                }
            }
        }
        leap:;
        if(flag==0)
            printf("Corrupt\n");
        
    }
    return 0;
}
