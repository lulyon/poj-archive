#include<stdio.h>
int main()
{
    int i,n;
    double x,y,sum;
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        scanf("%lf%lf",&x,&y);
        sum=(x+y)*(y-x+1)/2;
        printf("Scenario #%d:\n%.0lf\n\n",i,sum);
    }
    return 0;
}
