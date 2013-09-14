#include<iostream>
using namespace std;
double a[100000];
void init()
{
    a[1]=1;
    for(int i=2;i<=99999;++i)
    {
        a[i]=a[i-1]+1.000000/i;
    }
}
int main()
{
    int n;
    init();
    printf("Cards  Overhang\n");
    while(scanf("%d",&n)!=EOF)
    {
        printf("%5d     %.3lf\n",n,a[n]/2);
    }
    
    return 0;
}