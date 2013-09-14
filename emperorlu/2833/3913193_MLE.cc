#include<iostream>
#include<algorithm>
using namespace std;
double a[5000010];
int main()
{
    int n1,n2,n;
    while(1)
    {
        scanf("%d%d%d",&n1,&n2,&n);
        if(!n1&&!n2&&!n)break;
        
        
        for(int i=0;i<n;++i)
            scanf("%lf",a+i);
        
        sort(a,a+n);
        double sum=0;
        for(int i=n2;i<n-n1;++i)
        {
            sum+=a[i];
        }
        sum/=n-n1-n2;
        printf("%.6lf\n",sum);
    }
    return 0;
}
