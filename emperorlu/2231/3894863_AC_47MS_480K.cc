#include<iostream>
#include<algorithm>
using namespace std;
long long a[10010];
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;++i)
        scanf("%I64d",a+i);
    
    sort(a,a+n);
    
    
    
    long long sum=0;
    for(int i=0;i<n;++i)
    {
        sum+=((i<<1)+1-n)*a[i];
    }
    printf("%I64d\n",sum<<1);
    return 0;
}
