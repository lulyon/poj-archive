#include<stdio.h>
int main()
{
    int n,m;
    while(1)
    {
        scanf("%d%d",&n,&m);
        if(!n)break;
        double result=1;
        if(n<2*m)m=n-m;
        for(int i=1;i<=m;i++)
            result=result*(n+1-i)/i;
        printf("%.0lf\n",result);
    }
    return 0;
}
