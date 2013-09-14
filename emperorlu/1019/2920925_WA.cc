#include<stdio.h>
#include<math.h>
int main()
{
    int t;
    long n;
    const double exp=0.000001;
    double a,result;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%lf",&a);
        n=(long)((sqrt(1+8*a)-1)/2.0);
        if(fabs(a-n*(n+1)/2)<exp)n--;
        result=a-(n+1)*n/2;
        printf("%.0lf\n",result);
    }
    return 0;
}
