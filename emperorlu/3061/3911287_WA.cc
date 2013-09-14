#include<iostream>
using namespace std;
int a[100010];
int main()
{
    int n,s,t,head,tail,sum,len,ans;
    cin>>t;
    while(t--)
    {
        scanf("%d%d",&n,&s);
        for(int i=0;i<n;++i)
            scanf("%d",a+i);
        sum=0;
        head=len=tail=0;
        
        while(sum<s&&tail<n)
        {
            sum+=a[tail++];
            len++;
        }
        if(sum<s)
        {
            printf("0\n");
            continue;
        }
        ans=len;
        while(1)
        {
            sum-=a[head++];
            len--;
            if(sum<s)
            {
                if(tail==n)break;
                sum-=head++;
                len--;
                while(sum<s&&tail<n)
                {
                    sum+=a[tail++];
                    len++;
                }
                if(sum>=s)
                    if(ans>len)ans=len;
            }
            else
            {
                if(ans>len)ans=len;
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
