#include<iostream>
#include<math.h>
using namespace std;
int num[2050][15];
int step[2050];
int main()
{
    int t,n,m,i,j,ii,jj;
    cin>>t;
    for(int tt=1;tt<=t;tt++)
    {
        scanf("%d%d",&n,&m);
        printf("Data set %d: %d %d ",tt,n,m);
        step[1]=1;
        for(i=1;i<=m;i++)
            num[i][0]=1;
        int sum=0;
        for(i=2;i<=m;i++)
        {
            step[i]=1+(int)(log(i)/log(2));
            for(j=1;j<=i/2;j++)
                for(jj=0;jj<n&&jj<=step[j];jj++)
                    num[i][jj+1]+=num[j][jj];
            sum+=num[i][n-1];
        }
        printf("%d\n",sum);
    }
    return 0;
}
