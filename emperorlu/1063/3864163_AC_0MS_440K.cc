#include<iostream>
using namespace std;
int main()
{
    int n,t,sum,tmp;
    cin>>t;
    while(t--)
    {
        scanf("%d",&n);
        sum=0;
        for(int i=1;i<=n;++i)
        {
            scanf("%d",&tmp);
            if(tmp)
            {
                if(i%2)sum++;
                else
                    sum--;
            }
        }
        //while(1);
        if(n%2)
            printf("YES\n");
        else
        {
            if(sum>-2&&sum<2)
                printf("YES\n");
            else
                printf("NO\n");
        }
    }
    return 0;
}
