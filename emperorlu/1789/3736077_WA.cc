#include<iostream>
using namespace std;
char a[2010][2010];
int num[2010][2010];
int mins[2010];
int minedge[2010];
int main()
{
    int n;
    while(1)
    {
        cin>>n;
        if(!n)break;
        scanf("%s",a[0]);
        for(int i=1;i<n;++i)
        {
            scanf("%s",a[i]);
            int min=10;
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
            mins[i]=10;
            for(int j=0;j<n;++j)
            {
                if(i!=j&&num[i][j]&&mins[i]>num[i][j])
                {
                    mins[i]=num[i][j];
                    minedge[i]=j;
                }
            }
        }
        int sum=0;
        for(int t=1;t<=n-1;++t)
        {
            int min=10,ii,jj;
            for(int i=0;i<n;++i)
            {
                if(mins[i]!=0&&min>mins[i])
                {
                    min=mins[i];
                    ii=i;
                }
            }
            jj=minedge[ii];
            sum+=min;
            num[ii][jj]=num[jj][ii]=0;
            int min1=10,min2=10;
            for(int j=0;j<n;++j)
            {
                if(num[ii][j]&&min1>num[ii][j])
                {
                    min1=num[ii][j];
                    minedge[ii]=j;
                }
                if(num[jj][j]&&min2>num[jj][j])
                {
                    min2=num[jj][j];
                    minedge[jj]=j;
                }
            }
            if(min1==10)
                mins[ii]=0;
            else
                mins[ii]=min1;
            if(min2==10)
                mins[jj]=0;
            else
                mins[jj]=min2;
        }
        printf("The highest possible quality is 1/%d.",sum);
    }
    return 0;
}