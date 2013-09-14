#include<iostream>
#include<algorithm>
using namespace std;

int a[10010];

int main()
{
    int n,t;
    cin>>t;
    while(t--)
    {
        scanf("%d",&n);
        for(int i=0;i<n;++i)
            scanf("%d",a+i);
        
        sort(a,a+n);
        int max=-INT_MAX;
        for(int i=n-1;i>=0;--i)
        {
            if(max<(n-i)*a[i])
                max=(n-i)*a[i];
        }
        printf("%d\n",max);
    }
    return 0;
}
