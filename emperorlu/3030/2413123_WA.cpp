#include <stdio.h>
int main()
{
    int n;
    long a,b,c;
    scanf("%d",&n);
    while(n--)
    {
        scanf("%d%d%d",&a,&b,&c);
        if(a<c-b)printf("advertise\n");
        else if(a>c-b)printf("do not advertise\n");
       else printf("does not matter\n");
    }
    return 0;
}
