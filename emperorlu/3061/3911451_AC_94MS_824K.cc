#include<iostream>
using namespace std;
int a[100010];
int main()
{
    int n,t,head,tail,len,ans;
    long long s,sum;
    cin>>t;
    while(t--)
    {
        scanf("%d%I64d",&n,&s);
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
                while(sum<s&&tail<n)
                {
                    sum+=a[tail++];
                    len++;
                }
                if(sum>=s&&ans>len)ans=len;
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
