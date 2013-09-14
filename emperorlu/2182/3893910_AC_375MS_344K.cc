#include <stdio.h>
int n,a[9000];
int main()
{
    int i,j;
    scanf("%d",&n);
    a[1]=0;
    for(i=2;i<=n;++i)
    {
        scanf("%d",a+i);
        for(j=1;j<i;++j)
        {
            if(a[j]>=a[i])
                ++a[j];
        }
    }
    for(i=1;i<=n;i++)
        printf("%d\n",a[i]+1);
    return 0;
}
