#include<stdio.h>
#include<math.h>
#include<stdlib.h>
int main()
{
    int n,v,t,total,min;
    while(scanf("%d",&n),n)
    {
        scanf("%d%d",&v,&t);
        min=ceil((4.5/v)*3600)+time;
        for(int i=1;i<n;i++)
        {
            total=ceil((4.5/v)*3600)+time;
            if(min>total)min=total;
        }
        printf("%d\n",min);
    }
    return 0;
}