#include<stdio.h>
#include<math.h>
#include<stdlib.h>
int main()
{
    int n,v,t,total,min;
    while(scanf("%d",&n),n)
    {
        scanf("%d%d",&v,&t);
        min=(int)ceil((4.5/v)*3600)+t;
        for(int i=1;i<n;i++)
        {
            scanf("%d%d",&v,&t);
            total=(int)ceil((4.5/v)*3600)+t;
            if(min>total)min=total;
        }
        printf("%d\n",min);
    }
    return 0;
}
