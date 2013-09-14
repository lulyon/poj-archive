#include <stdio.h>
int main()
{
    int i,t,a[5];
    scanf("%d",&t);
    while(t--)
    {
        for(i=0;i<4;i++)
        {
            scanf("%d",a+i);
        }
        if(a[0]+a[2]==2*a[1])
        {
            a[4]=2*a[3]-a[2];
        }
        if(a[0]*a[2]==a[1]*a[1])
        {
            a[4]=a[3]*a[3]/a[2];
        }
        for(i=0;i<5;i++)
        {
            printf("%d ",a[i]);
        }
        printf("\n");
    }
    return 0;
}
