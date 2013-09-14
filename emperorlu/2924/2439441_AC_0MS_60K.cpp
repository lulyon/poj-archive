#include<stdio.h>
int main()
{
    int i,n;
    __int64 x,y,sum;
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        scanf("%I64d%I64d",&x,&y);
        sum=(x+y)*(y-x+1)/2;
        printf("Scenario #%d:\n%I64d\n\n",i,sum);
    }
    return 0;
}
