#include <stdio.h>
int main()
{
    int n,x,y;
    float a,b;
    scanf("%d",&n);
    while(n--)
    {
        scanf("%d%d",&x,&y);
        a=(x+y)/2.0;
        b=(x-y)/2.0;       
        if(x>y&&a==(int)a&&b==(int)b)printf("%d %d\n",a,b);
        else printf("impossible\n");
    }
    return 0;
}
