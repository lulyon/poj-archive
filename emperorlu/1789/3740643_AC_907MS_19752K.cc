#include<iostream>
using namespace std;
#define BIG INT_MAX
#define N 2010
int num[N][N];
char a[N][N];
bool b[N];
int mins[N];
int main()
{
    int n;
    while(1)
    {
       cin>>n;
       if(!n)break;
       int min=BIG,ii,jj;
       scanf("%s",a[0]);
        for(int i=1;i<n;++i)
        {
            scanf("%s",a[i]);
            for(int j=0;j<i;++j)
            {
                num[i][j]=0;
                for(int k=0;k<7;++k)
                {
                    if(a[i][k]!=a[j][k])
                        ++num[i][j];
                }
                num[j][i]=num[i][j];
            }
        }
        for(int i=0;i<n;++i)
        {
            for(int j=0;j<n;++j)
            {
                if(i!=j&&min>num[i][j])
                {
                    min=num[i][j];
                    ii=i;
                    jj=j;
                }
            }
            b[i]=0;
        }
        b[ii]=1;
        b[jj]=1;
        int sum=min;
        for(int i=0;i<n;++i)
        {
            if(i!=ii&&i!=jj)
            {
                if(num[i][ii]<num[i][jj])
                    mins[i]=num[i][ii];
                else
                    mins[i]=num[i][jj];
            }
        }
        for(int t=2;t<n;++t)
        {
            int s;
            min=BIG;
            for(int i=0;i<n;++i)
            {
                if(!b[i])
                {
                    if(min>mins[i])
                    {
                        min=mins[i];
                        s=i;
                    }
                }
            }
            sum+=min;
            b[s]=1;
            for(int i=0;i<n;++i)
            {
                if(!b[i])
                {
                    if(mins[i]>num[i][s])
                        mins[i]=num[i][s];
                }
            }
        }
        printf("The highest possible quality is 1/%d.\n",sum);
    }
    return 0;
}