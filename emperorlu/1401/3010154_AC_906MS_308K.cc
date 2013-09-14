#include<iostream>
using namespace std;
int main()
{
    int t;
    __int64 n,sum,tmp;
    cin>>t;
    while(t--)
    {
        cin>>n;
        sum=0;
        tmp=1;
        for(int i=1;;i++)
        {
            tmp*=5;
            sum+=n/tmp;
            if(n/tmp==0)break;
        }
        cout<<sum<<endl;
    }
    return 0;
}
