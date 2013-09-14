#include<iostream>
using namespace std;
int main()
{
    int t,n,num;
    cin>>t;
    while(t--)
    {
        cin>>n;
        num=n/2;
        if(n%2)
            num=num*(num-1)/2+(num+1)*num/2;
        else
            num=num*(num-1);
        cout<<num<<endl;
    }
    return 0;
}
