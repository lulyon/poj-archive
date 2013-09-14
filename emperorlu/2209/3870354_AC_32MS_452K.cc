#include<iostream>
#include<math.h>
using namespace std;
int main()
{
    int n,k;
    double tmp,sum=0;
    cin>>n>>k;
    if(k%2)
    {
        for(int i=0;i<n;++i)
        {
            scanf("%lf",&tmp);
            if(tmp>0)
                sum += pow(tmp,k);
        }
        printf("%.0lf\n",sum);
    }
    else
    {
        for(int i=0;i<n;++i)
        {
            scanf("%lf",&tmp);
            sum += pow(tmp,k);
        }
        printf("%.0lf\n",sum);
    }
    
    return 0;
}
