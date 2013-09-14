#include <stdio.h>
void main()
{
    int i,n,x[5],y[5];
    scanf("%d",&n);
    for(i=0;i<n;i++)
    scanf("%d%d",x+i,y+i);
    for(i=0;i<n;i++)
        if(x[i]>=y[i])printf("MMM BRAINS\n");
        else printf("NO BRAINS\n"); 
}
