#include<iostream>
using namespace std;
int main()
{
    unsigned __int64 u[5001],t[5001];
    int i,j,k,n;
    t[2]=1;
    for(k=3;k<=5000;k++)
    {
        u[k]=0;
        for(i=2;i<=k-1;i++)
            u[k]+=t[i]*t[k-i+1];
        t[k]=u[k];
        for(j=2;j<=k-2;j++)
            t[k]+=t[j]*u[k-j+1];
    }
    while(cin>>n)
        printf("%I64u\n",t[n]);
    return 0;
}
//好喜欢这段代码。。。