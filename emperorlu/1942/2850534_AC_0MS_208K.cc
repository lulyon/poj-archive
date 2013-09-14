#include<stdio.h>
int main()
{
    double m,n,ans,tmp;
    while(scanf("%lf%lf",&m,&n),m||n)
    {
        ans=1;
        if(m<n)
        {
            tmp=m;
            m=n;
            n=tmp;
        }
        for(int i=1;i<=n;i++)
            ans*=(m+i)/i;
        printf("%.0lf\n",ans);
    }
    return 0;
}
