#include <stdio.h>

int a[51];
int i,j,m,n,cas=0;

bool have(int x)
{
    for(j=1;j<=n;j++)
        if(x==a[j])return true;
    return false;

}

int main()
{
    int now,max;
    while(1)
    {
        cas++;
        scanf("%d%d",&m,&n);
        if(m==0&&n==0)break;
        for(i=1;i<=n;i++)
            scanf("%d",&a[i]);
        now = 0; 
        max = 0;
        for(i=n*m;i>=1;i--)
        {
            if(have(i))
            {
                now++;
                if(max<now)max=now;
            }
            else now--;
        }
        printf("Case %d: %d\n",cas,max);
    }
    return 0;
}
