#include<iostream>
using namespace std;
int main()
{
    int x,y,m,n,l,dx,dm;
    cin>>x>>y>>m>>n>>l;
    dx=x-y;
    dm=m-n;
    if(dm==0&&dx%l!=0)
        cout<<"Impossible"<<endl;
    else if(l%dm==0&&dx%dm!=0)
        cout<<"Impossible"<<endl;
    else
    {
        int i;
        //cout<<-dx/dm<<endl;
        //system("pause");
        if(dm<0)
        {
            dm=-dm;
            dx=-dx;
        }
        
        for(i=0;i<=dm;i++)
            if((i*l-dx)%dm==0&&(i*l-dx)/dm>=0)break;
        //cout<<i<<endl;
        //system("pause");
        
        if(i>dm)cout<<"Impossible"<<endl;
        else
            cout<<(i*l-dx)/dm<<endl;
    }
    //while(1);
    return 0;
}
