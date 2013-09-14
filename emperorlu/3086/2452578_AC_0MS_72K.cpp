#include<stdio.h>
int main()
{
    long i,n,m,k,t,w;
    scanf("%ld",&m);
    for(i=1;i<=m;i++)
    {
        scanf("%ld",&n);
        for(k=1,w=0;k<=n;k++)
        {
            t=(k+2)*(k+1)/2;
            w+=k*t;
        }
        printf("%ld %ld %ld\n",i,n,w);
    }
    return 0;
}
