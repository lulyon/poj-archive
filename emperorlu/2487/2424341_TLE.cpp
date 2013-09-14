#include<stdio.h>
int main()
{
    int n,k,sub,temp,m,a[1000];
    long i,j,sum,total;
    scanf("%d",&n);
    m=n;
    while(n--)
    {
        scanf("%ld%d",&total,&k);
        for(i=0;i<k;i++)
            scanf("%d",a+i);
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
        if(i<k)printf("Scenario #%d:\n%d\n\n",m-n,i);
            else printf("Scenario #%d:\nimpossible\n\n",m-n);   
    }
    while(1);
    return 0;
}
