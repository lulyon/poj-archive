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
    while(1);
    return 0;
}
