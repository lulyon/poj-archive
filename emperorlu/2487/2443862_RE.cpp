#include<stdio.h>
int main()
{
    int n,k,sub,temp,m,a[10000];
    long i,j,sum,total;
    scanf("%d",&n);
    m=n;
    while(n--)
    {
        scanf("%ld%ld",&total,&k);
        for(i=0;i<k;i++)
            scanf("%ld",a+i);
        for(i=0;i<k;i++)
        {
            for(j=i+1,sub=i;j<k;j++)
                if(a[j]>a[sub])sub=j;
            temp=a[i];a[i]=a[sub];a[sub]=temp;
        }
        for(i=0,sum=0;i<k;i++)
         {
            sum+=a[i];
            if(sum>=total)goto leap;
         }
        printf("Scenario #%d:\nimpossible\n\n",m-n);
        continue;
        leap:printf("Scenario #%d:\n%ld\n\n",m-n,i+1);
    }
    return 0;
}
