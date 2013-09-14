#include <stdio.h>
#include <math.h>
int prime(long x)
{
    long i;
    for(i=2;i<pow(x,0.5);i++)
        if(x%i==0)return 0;
    return 1;    
}
int main()
{
    long i,j,n;
    leap:scanf("%ld",&n);
    while(n)
    {
        for(i=2;i<=n/2;i++)
        {
            if(prime(i)==1)
            {
                j=n-i;
                if(prime(j)==1)
                {
                    printf("%ld = %ld + %ld\n",n,i,j);
                    goto leap;
                }
            }
        }
        printf("Goldbach's conjecture is wrong.\n");       
    }
    return 0;
}
