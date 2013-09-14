#include<stdio.h>
int main()
{
    int n,i,k,a[10],sum;
    scanf("%d",&n);
    while(n--)
    {
        scanf("%d",&k);
        for(i=0,sum=0;i<k;i++)
        {
            scanf("%d",a+i);
            sum+=a[i];
        }
        sum-=k-1;
        printf("%d\n",sum);
    }
    return 0;
}
