#include<stdio.h>
#include<math.h>
int main()
{
    int t;
    long n,a,result;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%ld",&a);
        n=(long)((sqrt(1+8*a)-1)/2.0);
        if(a==n*(n+1)/2)n--;
        result=a-(n+1)*n/2;
        printf("%ld\n",result);
    }
    return 0;
}
