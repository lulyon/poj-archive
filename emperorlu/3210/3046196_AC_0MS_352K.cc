#include<iostream>
using namespace std;
int main()
{
    int n;
    while(true)
    {
        cin>>n;
        if(!n)break;
        if(n%2)
        {
            cout<<n-1<<endl;
        }
        else
        {
            cout<<"No Solution!"<<endl;
        }
    }
    return 0;
}
