#include<iostream>
using namespace std;

double calc(int n)
{
    double tmp=1.000000/(n+1);
    for(int i=1;i<=n;++i)
    {
        tmp*=(n+i);
        tmp/=i;
    }
    return tmp;
}


int main()
{
    int n;
    while(1)
    {
        scanf("%d",&n);
        if(n==-1)break;
        
        printf("%.0lf\n",calc(n));
    }
    return 0;
}
