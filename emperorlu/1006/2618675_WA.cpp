#include<stdio.h>
int main()
{
    int p,e,i,d,k,n=0;
    while(scanf("%d%d%d%d",&p,&e,&i,&d),p!=-1)
    {
        n++;
        for(k=p+1;(k-p)%23||(k-e)%28||(k-i)%33;k++);
        k-=d;
        printf("Case %d: the next triple peak occurs in %d days.\n",n,k);
    }
    return 0;
}
