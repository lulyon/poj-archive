#include <stdio.h>
int main()
{
    int p,e,i,d,k,t=0;
    while(scanf("%d%d%d%d",&p,&e,&i,&d),p+1)
    {
        t++;
        for(k=1;k<21253;k++)
        {
            if(!((k+d-p)%23)&&!((k+d-e)%28)&&!((k+d-i)%33)) break;
        }
        printf("Case %d: the next triple peak occurs in %d days.\n",t,k);
    }
    return 0;
}