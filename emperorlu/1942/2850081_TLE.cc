#include<stdio.h>
int main()
{
    double m,n,ans;
    while(scanf("%lf%lf",&m,&n),m||n)
    {
        ans=1;
        for(int i=1;i<=(int)n;i++)
            ans*=(m+i)/i;
        printf("%.0lf\n",ans);
    }
    return 0;
}
