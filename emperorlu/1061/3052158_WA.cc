#include<iostream>
using namespace std;
int main()
{
    int x,y,m,n,l,dx,dm;
    cin>>x>>y>>m>>n>>l;
    dx=x-y;
    dm=m-n;
    if(dm<0)
    {
        dm=-dm;
        dx=-dx;
    }
    int i;
    for(i=0;i<l;i++)
        if((dx+i*dm)%l==0)break;
    if(i==l)cout<<"Impossible"<<endl;
    else cout<<i<<endl;
    //while(1);
    return 0;
}
