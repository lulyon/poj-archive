#include<iostream>
using namespace std;
double a[1000][1000];
bool b[1000][1000];
double combine(int m,int n)
{
    double result=1;
    if(n<2*m)m=n-m;
    if(n>=1000)
    {
        if(m==0)return 1;
        else return combine(m-1,n-1)+combine(m,n-1);
    }
    else if(b[m][n])return a[m][n];
    else
    {
        if(m==0)a[m][n]=1;
        else a[m][n]=combine(m-1,n-1)+combine(m,n-1);
        b[m][n]=1;
        return a[m][n];
    }
}
int main()
{
    int n,m;
    while(1)
    {
        cin>>n>>m;
        if(!n&&!m)break;
        printf("%.0lf\n",combine(m,n));
    }
    return 0;
}
