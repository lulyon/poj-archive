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
    long long i,tmp;
    for(i=0;i<=dm;i++)
    {
        tmp=i*l-dx;
        if(tmp%dm==0&&tmp>=0)break;
    }
    //cout<<i<<endl;
    if(i>dm)cout<<"Impossible"<<endl;
    else cout<<tmp/dm<<endl;
    //system("pause");
    return 0;
}
