#include <stdio.h>
int main()
{
    int i,n,s[10],t[10],sum;
    leap:scanf("%d",&n);
    while(n!=-1)
    {
        scanf("%d%d",s,t);
        sum=s[0]*t[0];
        for(i=1;i<n;i++)
        {
            scanf("%d%d",s+i,t+i);
            sum+=s[i]*(t[i]-t[i-1]);
        }
        printf("%d miles\n",sum);
        goto leap;
    }
    return 0;
    
}
