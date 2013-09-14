#include<iostream>
using namespace std;
int main()
{
    int n,m,k,a,b,c;
    while(scanf("%d%d",&n,&k)!=EOF)
    {
        if(k>n/2)k=n-k;
        if(k==0)
        {
            printf("1\n");
            continue;
        }
        m=n-k;
        a=b=c=0;
        while(n>>=1) a+=n;//统计n！的2的阶数
        while(m>>=1) b+=m;
        while(k>>=1) c+=k;
        if(a>b+c) printf("0\n");
        else printf("1\n");
        
    }
    return 0;
}
