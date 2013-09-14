#include<iostream>
using namespace std;
int main()
{
    long a,n;
    cin>>a;
    n=a*a+1;
    for(int i=2*a;;i--)
        if(n%(i-a)==0)
        {
            cout<<a+i+n/(i-a)<<endl;
            break;
        }
    return 0;
}