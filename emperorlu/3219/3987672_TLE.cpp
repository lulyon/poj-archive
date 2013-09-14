#include<iostream>
using namespace std;
int main()
{
    int n,k;
    while(scanf("%d%d",&n,&k)!=EOF)
    {
        if(k>n/2)k=n-k;
        if(k==0)
        {
            printf("1\n");
            continue;
        }
        int cnt=0,tmp;
        for(int i=1,j=n-k+1;i<=k;++i,++j)
        {
            tmp=j;
            while(tmp%2==0)
            {
                ++cnt;
                tmp>>=1;
            }
            tmp=i;
            while(tmp%2==0)
            {
                --cnt;
                tmp>>=1;
            }
        }
        if(cnt==0)
            printf("1\n");
        else 
            printf("0\n");
    }
    return 0;
}
