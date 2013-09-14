#include <stdio.h>
int main()
{
    int i,n,x,y;
    leap:scanf("%d",&n);
    while(n)
    {
        for(i=1;i<=n;i++)
        {
            scanf("%d%d",&x,&y);
            if(x+y>8)
            {
                printf("%d\n",i);
                goto leap;
            }
        }
        printf("0\n");
        
    }
    return 0;
}
