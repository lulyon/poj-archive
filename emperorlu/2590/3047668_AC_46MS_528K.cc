#include<iostream>
using namespace std;
long n[100000];
void init()
{
    n[0]=0;
    for(int i=1;;i++)
    {
        if(i%2)
            n[i]=(i+1)*(i+1)/4;
        else
            n[i]=i*(i+2)/4;
        if(n[i]>2147483648)break;
    }
}
int main()
{
    int t,x,y,d;
    init();
    cin>>t;
    while(t--)
    {
        cin>>x>>y;
        d = y-x;
        if( d == 0)
        {
            cout<<'0'<<endl;
            continue;
        }
        int i;
        for(i=0;n[i]<d;i++);
        cout<<i<<endl;
    }
    return 0;
}
