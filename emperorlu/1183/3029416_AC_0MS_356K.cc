#include<iostream>
using namespace std;
int main()
{
    __int64 a,n,i;
    cin>>a;
    n=a*a+1;
    for(i=2*a;;i--)
        if(n%(i-a)==0)
        {
            cout<<a+i+n/(i-a)<<endl;
            break;
        }
    return 0;
}