#include<iostream>
using namespace std;
double calc(int n,int m)
{
    double re=1.00000000000;
    for(int i=1;i<=m;++i)
    {
        re*=(n-i+1)/(double)i;
    }
    return re;
}
int main()
{
    int m,n;
    while(1)
    {
        scanf("%d %d",&n,&m);
        if(!n&&!m)break;
        
        printf("%d things taken %d at a time is %.0lf exactly.\n",n,m,calc(n,m));
    }
    return 0;
}
