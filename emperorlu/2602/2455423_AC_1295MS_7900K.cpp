#include<stdio.h>
int main()
{
    long i,n;
    int a[1000000],b[1000000],temp;
    scanf("%ld",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d%d",a+i,b+i);
    }
    for(i=n-1;i>=0;i--)
    {
        temp=a[i];
        a[i]=(a[i]+b[i])%10;
        if(i==0)break;
        a[i-1]+=(temp+b[i])/10;
    }
    for(i=0;i<n;i++)
        printf("%d",a[i]);
    printf("\n");
    return 0;
}
