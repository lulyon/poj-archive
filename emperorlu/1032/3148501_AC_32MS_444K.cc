#include <iostream>
using namespace std;
int main(void)
{
    int n,i,t;
    cin>>n;
    for(i=2;n>=i;i++) n-=i;
    i--;
    if(i==n)
    {
        for(t=2;t<=i-1;t++) cout<<t+1<<' ';
        cout<<i+2<<' ';
    }
    else
    {
        for(t=2;t<=i;t++)
        {
            if(i-t<n)
                cout<<t+1<<' ';
            else
                cout<<t<<' ';
        }
    }
    cout<<endl;
    //system("pause");
    return 0;
}
