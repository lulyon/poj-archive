#include<stdio.h>
#include<math.h>
#define pi 3.141593
int main()
{
    int t,n;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        n=(int)(0.5*log10(2*pi)+(n+0.5)*log10(n)-n/log(10));
        printf("%d\n",++n);
    }
    return 0;
}