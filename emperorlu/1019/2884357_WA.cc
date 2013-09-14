#include<stdio.h>
#include<math.h>
int main()
{
    int t,a,n,result;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&a);
        n=(int)((sqrt(1+8*a)-1)/2.0);
        if(a==n*(n+1)/2)n--;
        result=a-(n+1)*n/2;
        printf("%d\n",result);
    }
    return 0;
}
