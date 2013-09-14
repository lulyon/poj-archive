#include<iostream>
using namespace std;
int a[20000];
void init()
{
    a[1]=1;
    int n;
    for(int i=2;i<=10000;++i)
    {
        n=i;
        n*=a[i-1];
        while(n%10==0)
            n/=10;
        n%=10000;
        a[i]=n;
    }
}
int main()
{
    init();
    int n;
    while(scanf("%d",&n)!=EOF)
    {
        printf("%5d -> %d\n",n,a[n]%10);
    }
    return 0;
}
