#include<iostream>
#include<algorithm>
using namespace std;
int a[5000010];
int main()
{
    int n1,n2,n;
    while(1)
    {
        scanf("%d%d%d",&n1,&n2,&n);
        if(!n1&&!n2&&!n)break;
        
        
        for(int i=0;i<n;++i)
            scanf("%d",a+i);
        
        sort(a,a+n);
        long long sum=0;
        for(int i=n2;i<n-n1;++i)
        {
            sum+=a[i];
        }
        printf("%.6lf\n",sum/(double)(n-n1-n2));
    }
    return 0;
}
