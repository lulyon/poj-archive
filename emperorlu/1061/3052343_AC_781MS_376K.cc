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
    dm%=l;
    dx%=l;
    long long i,tmp;
    if(dm==0)
    {
        if(dx%l==0)cout<<0<<endl;
        else cout<<"Impossible"<<endl;
        return 0;
    }
    for(i=0;i<=dm;i++)
    {
        tmp=i*l-dx;
        if(tmp%dm==0&&tmp>=0)break;
    }
    if(i>dm)cout<<"Impossible"<<endl;
    else cout<<tmp/dm<<endl;
    return 0;
}
