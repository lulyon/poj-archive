#include <stdio.h>
#include<stdlib.h>

int cmp(const void *a,const void *b)
{
    return *(long *)a > *(long *)b;
}

int main()
{
    int i,j,n,temp,sub;
    long a[10000];
    scanf("%d",&n);
    for(i=0;i<n;i++)
        scanf("%ld",a+i);
    qsort(a,n,sizeof(long),cmp);
    printf("%ld\n",a[n/2]);
    return 0;
}
