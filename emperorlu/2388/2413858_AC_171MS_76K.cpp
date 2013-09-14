#include <stdio.h>
int main()
{
    int i,j,n,temp,sub;
    long a[10000];
    scanf("%d",&n);
    for(i=0;i<n;i++)
        scanf("%ld",a+i);
    for(i=0;i<=n/2;i++)
    {
        for(j=i+1,sub=i;j<n;j++)
            if(a[j]<a[sub])sub=j;
        temp=a[i];a[i]=a[sub];a[sub]=temp;
    }
    printf("%ld\n",a[n/2]);
    return 0;
}
