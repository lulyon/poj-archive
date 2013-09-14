#include<stdio.h>
#include<math.h>
#define pi 3.141593
int main()
{
    int t;
    double R,n,r;
    scanf("%d",&t);
    for(int i=1;i<=t;i++)
    {
        scanf("%lf%lf",&R,&n);
        r=R/(1+1/sin(pi/n));
        printf("Scenario #%d:\n%.3lf\n",i,r);
    }
    return 0;
}