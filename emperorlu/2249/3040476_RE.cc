#include<iostream>
using namespace std;
double a[10000][10000];
void init()
{
    for(int i=1;i<2000;i++)
        a[0][i]=a[0][i]=1;
    for(int i=0;i<2000;i++)
    {
        for(int j=1;j<=i/2;j++)
            a[j][i]=a[j][i-1]+a[j-1][i-1];
        for(int j=i/2+1;j<=i;j++)
            a[j][i]=a[i-j][i];
    }
}
double combine(int m,int n)
{
    if(n<2*m)return combine(n-m,n);
    if(n>=2000)
    {
        if(m==0)return 1;
        else if(m==1)return n;
        else return combine(m-1,n-1)+combine(m,n-1);
    }
    else return a[m][n];
}
int main()
{
    int n,m;
    init();
    while(1)
    {
        cin>>n>>m;
        if(!n&&!m)break;
        printf("%.0lf\n",combine(m,n));
    }
    return 0;
}
