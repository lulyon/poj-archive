#include<stdio.h>
int main()
{
    int i,n,k,j,sub,temp,m,a[10000];
    long sum,total;
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
    return 0;
}
