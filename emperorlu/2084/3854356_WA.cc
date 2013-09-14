#include<iostream>
using namespace std;

double calc(int n)
{
    double tmp=1.000000;
    for(int i=1;i<=n;++i)
    {
        tmp*=(n+i);
        tmp/=i;
    }
    return tmp/(n+1);
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

