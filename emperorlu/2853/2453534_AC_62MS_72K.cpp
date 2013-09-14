#include<stdio.h>
int main()
{
    int t,n,cnt;
    __int64 i,lim;
    scanf("%d",&n);
    while(n--)
    {
        scanf("%d%I64d",&t,&lim);
        for(i=2,cnt=0;lim-i*(i+1)/2>=0;i++)
        {
            if((lim-i*(i+1)/2)%i==0)
                cnt++;
        }
        printf("%d %d\n",t,cnt);
    }
    return 0;
}
