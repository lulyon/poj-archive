#include <stdio.h>
#define N 10
int main()
{
    int i,n,x[N],y[N];
    scanf("%d",&n);
    for(i=0;i<n;i++)
    scanf("%d%d",x+i,y+i);
    for(i=0;i<n;i++)
        if(x[i]>=y[i])printf("MMM BRAINS\n");
        else printf("NO BRAINS\n");
    while(1);
    return 0;
    
}
