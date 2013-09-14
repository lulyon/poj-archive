#include <stdio.h>
int main()
{
    int n,x,y;
    scanf("%d",&n);
    while(n--)
    {
        scanf("%d%d",&x,&y);
        if(x>y)printf("%d %d\n",(x+y)/2,(x-y)/2);
        else printf("impossible\n");
    }
    return 0;
}
