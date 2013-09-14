#include<stdio.h>
int yuesefu(int n,int m)
{
   int i,r=0;
   for (i=2;i<=n;i++) r=(r+m)%i;
   return r;
}

int main(void)
{
    int n,m,k;
    int ch;

    while(scanf("%d %d %d",&n,&k,&m)!=EOF)
    {
        if(n==0&&k==0&&m==0)
        break;
        ch=yuesefu(n-1,k)+m+1;
        if(ch>n)
        ch-=n;
        printf("%d\n",ch);
    }
    return 0;
}
