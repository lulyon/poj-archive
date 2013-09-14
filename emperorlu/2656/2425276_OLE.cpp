#include <stdio.h>
int main()
{
    int i,n,x[8],y[8];
    leap:scanf("%d",&n);
    while(n)
    {
        for(i=1;i<=n;i++)
        {
            scanf("%d%d",&x[i],&y[i]);
        } 
        for(i=1;i<=n;i++)
        {
            if(x[i]+y[i]>8)
            {
                printf("%d\n",i);
                goto leap;
            }
        }
        printf("0\n");
    }
    return 0;
}
