#include<iostream>
using namespace std;
double a[10000][10000];
void init()
{
    for(int i=1;i<2000;i++)
        a[0][i]=a[i][i]=1;
    for(int i=0;i<2000;i++)
    {
        for(int j=1;j<=i/2;j++)
            a[j][i]=a[j][i-1]+a[j-1][i-1];
        for(int j=i/2+1;j<i;j++)
            a[j][i]=a[i-j][i];
    }
}
int main()
{
    int n,m;
    init();
    while(1)
    {
        cin>>n>>m;
        if(!n&&!m)break;
        printf("%.0lf\n",a[m][n]);
    }
    return 0;
}