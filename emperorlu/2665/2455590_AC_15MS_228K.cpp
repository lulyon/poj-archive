#include<stdio.h>
int main()
{
    __int64 le,res,i,n,b[10000],e[10000],sum;
    while((scanf("%I64d%I64d",&le,&n),le)!=0)
    {
        for(i=0;i<n;i++)
        {
            scanf("%I64d%I64d",b+i,e+i);
        }
        for(i=0,sum=0;i<n;i++)
        {
            sum+=e[i]-b[i]+1;
        }
        res=le+1-sum;
        printf("%I64d\n",res);
    }
    return 0;
}
