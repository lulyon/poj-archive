#include<iostream>
using namespace std;
char a[2010][2010];
int num[2010][2010];
int mins[2010];
int minedge[2010];
int add[2010];
#define BIG 1000
int main()
{
    int n;
    while(1)
    {
        cin>>n;
        if(!n)break;
       scanf("%s",a[0]);
       add[0]=0;
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
            add[i]=0;
        }
        for(int i=0;i<n;++i)
            num[i][i]=0;
        int sum=0;
        for(int i=0;i<n;++i)
        {
            mins[i]=BIG;
            for(int j=0;j<n;++j)
            {
                if(i!=j&&num[i][j]&&mins[i]>num[i][j])
                {
                    mins[i]=num[i][j];
                    minedge[i]=j;
                }
            }
        }
     
        
        for(int t=1;t<=n-1;++t)
        {
            int min=BIG,ii,jj;
            for(int i=0;i<n;++i)
            {
                if((t==1||(t>1&&add[i]&&!add[minedge[i]]))&&mins[i]!=0&&min>mins[i])
                {
                    min=mins[i];
                    ii=i;
                }
            }
            jj=minedge[ii];
            sum+=min;
            num[ii][jj]=num[jj][ii]=0;
            add[ii]=add[jj]=1;
            int min1=BIG,min2=BIG;
            for(int j=0;j<n;++j)
            {
                if(num[ii][j]&&!add[j]&&min1>num[ii][j])
                {
                    min1=num[ii][j];
                    minedge[ii]=j;
                }
                if(num[jj][j]&&!add[j]&&min2>num[jj][j])
                {
                    min2=num[jj][j];
                    minedge[jj]=j;
                }
            }
            if(min1==BIG)
                mins[ii]=0;
            else
                mins[ii]=min1;
            if(min2==BIG)
                mins[jj]=0;
            else
                mins[jj]=min2;
            //cout<<min<<' '<<ii<<' '<<jj<<endl;
        }
        //cout<<sum<<endl;
        printf("The highest possible quality is 1/%d.\n",sum);
    }
    return 0;
}