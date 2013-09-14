#include<iostream>
#include<math.h>
using namespace std;


int a[55];
int gcd(int a,int b)
{
    if(b==0)return a;
    else return gcd(b,a%b);
}

int main()
{
    int n;
    while(1)
    {
        scanf("%d",&n);
        if(!n)break;
        
        for(int i=0;i<n;++i)
        {
            scanf("%d",a+i);
        }
        
        
        int cn=0;
        
        
        for(int i=0;i<n;++i)
        {
            for(int j=i+1;j<n;++j)
            {
                if(gcd(a[i],a[j])==1)
                    ++cn;
            }
        }
        if(cn)
            printf("%.6lf\n",sqrt(3*n*(n-1)/(cn+0.000000)));
        else
            printf("No estimate for this data set.\n");
    }
    return 0;
}
