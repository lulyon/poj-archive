#include<iostream>
using namespace std;
double combine(int m,int n)
{
    double result=1;
    if(n<2*m)m=n-m;
    for(int i=1;i<=m;i++)
        result*=(n+1-i)/(double)i;
    return result;
}
int main()
{
    int n,m;
    while(1)
    {
        scanf("%d%d",&n,&m);
        if(!n&&!m)break;
        printf("%.0lf\n",combine(m,n));
    }
    return 0;
}
