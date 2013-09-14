#include<iostream>
using namespace std;
char a[2010][10];
int num[2010][2010];
bool b[2010];
int q[2010];
int main()
{
    int n;
    while(1)
    {
        cin>>n;
        if(!n)break;
        scanf("%s",a[0]);
        b[0]=0;
        int ii,jj,min=10;
        for(int i=1;i<n;++i)
        {
            scanf("%s",a[i]);
            b[i]=0;
            for(int j=0;j<i;++j)
            {
                num[i][j]=0;
                for(int k=0;k<7;++k)
                {
                    if(a[i][k]!=a[j][k])
                        ++num[i][j];
                }
                num[j][i]=num[i][j];
                if(min>num[i][j])
                {
                    min=num[i][j];
                    ii=i;
                    jj=j;
                }
            }
        }
        int sum=min;
        q[0]=2;
        q[1]=ii;
        q[2]=jj;
        b[ii]=b[jj]=1;
        
        
        for(int t=2;t<n;++t)
        {
     
            int min=10;
            for(int i=1;i<=t;++i)
            {
                for(int j=0;j<n;++j)
                {
                    if(!b[j]&&min>num[q[i]][j])
                    {
                        min=num[q[i]][j];
                        jj=j;
                    }
                }
            }
            sum+=min;
            b[jj]=1;
            q[t+1]=jj;
        }
        printf("The highest possible quality is 1/%d.\n",sum);
    }
    return 0;
}