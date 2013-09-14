#include<iostream>
using namespace std;
#define MAXN 10000
double c[MAXN];
int main()
{
    int i,n;
    double a0,an1,re;
    cin>>n>>a0>>an1;
    for(i=1;i<=n;++i)
        scanf("%lf",c+i);
    re=n*a0+an1;
    for(i=1;i<=n;++i)
        re-=2*(n-i+1)*c[i];
    printf("%.2lf\n",re/(n+1));
    return 0;
}
