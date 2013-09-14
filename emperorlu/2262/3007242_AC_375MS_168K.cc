#include<stdio.h>
#include<math.h>
bool prime(long n)
{
    long m=(long)sqrt(n);
    for(long i=2;i<=m;i++)
        if(n%i==0)return 0;
    return 1;
}
int main()
{
    long n;
    while(scanf("%ld",&n),n)
    {
        for(long i=2;i<=n/2;i++)
        {
            if(prime(i)&&prime(n-i))
            {
                printf("%ld = %d + %ld\n",n,i,n-i);
                break;
            }
        }
    }
    return 0;
}