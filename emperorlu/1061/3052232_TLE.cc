#include<iostream>
using namespace std;
int main()
{
    long long x,y,m,n,l,dx,dm;
    cin>>x>>y>>m>>n>>l;
    dx=x-y;
    dm=m-n;
    if(dm<0)
    {
        dm=-dm;
        dx=-dx;
    }
    long long i;
    for(i=1;i<l;i++)
        if((dx+(i%l)*(dm%l))%l==0)break;
    if(i==l)cout<<"Impossible"<<endl;
    else cout<<i<<endl;
    //system("pause");
    return 0;
}
