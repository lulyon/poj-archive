#include <stdio.h>
int main()
{
    int i,r,y;
    long m;
    double p;
    scanf("%d%ld%d",&r,&m,&y);
    p=m;
    for(i=1;i<=y;i++)
    {
        p*=(1+r/100.0);
    }
    m=p;
    printf("%ld\n",m);
    return 0;
}
