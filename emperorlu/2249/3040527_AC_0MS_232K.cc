#include<stdio.h>
int main()
{
    unsigned long n,m;
    while(1)
    {
        scanf("%ld%ld",&n,&m);
        if(!n)break;
        double result=1;
        int i;
        if(n<2*m)m=n-m;
        for(i=1;i<=m;i++)
            result=result*(n+1-i)/i;
        printf("%.0lf\n",result);
    }
    return 0;
}
