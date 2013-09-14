// 
// File:   newmain.cc
// Author: acm
//
// Created on 2008年7月28日, 上午11:40
//
#include<iostream>
using namespace std;
long long a[20010];
int main()
{
    int n;
    long long b;
    cin>>n>>b;
    for(int i=0;i<n;++i)
        scanf("%lld",a+i);
    sort(a,a+n);
    long long sum=0;
    for(int i=n-1,j=1;i>=0;--i,++j)
    {
        sum+=a[i];
        if(sum>=b)
        {
            cout<<j<<endl;
            break;
        }
    }
    return 0;
}