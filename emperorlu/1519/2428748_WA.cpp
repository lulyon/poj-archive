#include <stdio.h>
int main()
{
    long n,sum;
    while((scanf("%ld",&n),n)!=0)
    {
        for(sum=0;(n/10)!=0;)
        {
            sum+=n%10;
            n/=10;
        }
        sum+=n;
        for(;sum>9;)
        {
            sum-=9;
        }
        printf("%ld\n",sum);
    }
    return 0;    
}
