#include<iostream>
using namespace std;
int main()
{
    const double EPS=1e-6;
    long long i,n;
    double p;
    while(1)
    {
        scanf("%I64d",&n);
        if(!n)break;
        
        for(i=2;i<n;++i)
        {
            p = log((double)n)/log(double(i));
            if(fabs(p-(int)p)<EPS)
            {
                printf("%I64d\n",(long long)p);
                break;
            }
        }
        if(i==n)
        {
            printf("1\n");
        }
    }
    return 0;
}
