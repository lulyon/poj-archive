#include<stdio.h>
int main()
{
    long n,k,sub,temp,m,a[10000];
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
         for(i=0,sum=0;sum<total&&i<k;i++)
         {
            sum+=a[i];
         }
        if(i<k)printf("Scenario #%ld:\n%ld\n\n",m-n,i);
            else printf("Scenario #%ld:\nimpossible\n\n",m-n); 
    }
    return 0;
}
