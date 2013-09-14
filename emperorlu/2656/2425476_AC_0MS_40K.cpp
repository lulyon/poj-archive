#include <stdio.h>
int main()
{
    int i,n,x,y;
    leap:scanf("%d",&n);
    if(n!=0)
    {
        for(i=1;i<=n;i++)
        {
            scanf("%d%d",&x,&y);            
            if(x+y>8)
            {
                printf("%d\n",i);
                goto leap2;
            }
        }
        printf("0\n");
        goto leap;
        leap2:
            for(++i;i<=n;i++)
                scanf("%d%d",&x,&y);
        goto leap;
    }
    return 0;
}
