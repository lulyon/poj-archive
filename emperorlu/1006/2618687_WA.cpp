#include<stdio.h>
int main()
{
    int p,e,i,d,k,n=0;
    while(scanf("%d%d%d%d",&p,&e,&i,&d),p!=-1)
    {
        n++;
        k=p>e?(p>i?p:i):(e>i?e:i);
        k++;
        for(k;(k-p)%23||(k-e)%28||(k-i)%33;k++);
        k-=d;
        printf("Case %d: the next triple peak occurs in %d days.\n",n,k);
    }
    return 0;
}
