#include<stdio.h>
int main()
{
    long i,m,n,flag,count,max;
    while(scanf("%ld%ld",&m,&n)!=EOF)
    {
        for(i=m,max=0;i<=n;i++)
        {
            count=0;
            flag=i;
            leap:
            count++;
            if(flag==1)
            {
                if(count>max)max=count;
                continue;
            }
            if(flag%2==1)flag=3*flag+1;
                else flag=flag/2;
            goto leap;
        }
        printf("%ld %ld %ld\n",m,n,max);
    }
    return 0;
}
