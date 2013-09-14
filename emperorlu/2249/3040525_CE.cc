#include<stdio.h>
double combine(int m,int n)
{
    double result=1;
    int i;
    if(n<2*m)m=n-m;
    for(i=1;i<=m;i++)
        result=result*(n+1-i)/i;
    return result;
}
int main()
{
    usigned long n,m;
    while(1)
    {
        scanf("%ld%ld",&n,&m);
        if(!n)break;
        printf("%.0f\n",combine(m,n));
    }
    return 0;
}