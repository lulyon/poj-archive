#include<iostream>
#include<algorithm>
using namespace std;
#define MAXN 250010


double a[MAXN];

int main()
{
    long n;
    cin>>n;
    for(long i=0;i<n;++i)
        scanf("%lf",a+i);
    
    sort(a,a+n);
    if(n%2)
    {
        printf("%.1lf\n",a[n/2]);
    }
    else
        printf("%.1lf\n",(a[n/2]+a[n/2-1])/2.0);
    
    return 0;
}
