#include<stdio.h>
int main()
{
    int i,a[3];
    for(i=0;i<3;i++)
        scanf("%d",a+i);
    for(i=1;i<3;i++)
    {
        if(a[i]<=168)
        {
            printf("CRASH %d\n",a[i]);
            goto leap;
        }
    }
    printf("NO CRASH\n");
    leap:return 0;
}
