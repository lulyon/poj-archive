#include<stdio.h>
int main()
{
    int t;
    __int64 n,sum,tmp;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%I64d",&n);
        sum=0;
        tmp=1;
        while(1)
        {
            tmp*=5;
            sum+=n/tmp;
            if(n/tmp==0)break;
        }
        printf("%I64d\n",sum);
    }
    return 0;
}
