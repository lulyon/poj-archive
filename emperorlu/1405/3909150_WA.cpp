#include<iostream>
using namespace std;
long long a[20],b[20];
void init()
{
    a[1]=1;
    b[1]=2;
    for(int i=2;i<=18;++i)
    {
        a[i]=a[i-1]*b[i-1];
        b[i]=a[i]+1;
    }
}

int main()
{
    init();
    int n;
    scanf("%d",&n);
    
    for(int i=1;i<=n;++i)
        printf("%lld\n",b[i]);
    return 0;
}
