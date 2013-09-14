#include <stdio.h>
int main()
{
    long n,m,p,c;
    leap:scanf("%ld%ld%ld%ld",&n,&m,&p,&c);
    while(n)
    {
        printf("%ld\n",n+p-m);
        goto leap;        
    }
    return 0;
}
