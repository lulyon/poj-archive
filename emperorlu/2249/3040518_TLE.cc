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
    int n,m;
    while(1)
    {
        scanf("%d%d",&n,&m);
        if(!n&&!m)break;
        printf("%.0lf\n",combine(m,n));
    }
    return 0;
}
