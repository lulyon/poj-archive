#include<stdio.h>
int main()
{
    double i,n,x,y,sum;
    scanf("%lf",&n);
    for(i=1;i<=n;i++)
    {
        scanf("%lf%lf",&x,&y);
        sum=(x+y)*(y-x+1)/2;
        printf("Scenario #%.0lf:\n%.0lf\n\n",i,sum);
    }
    return 0;
}
