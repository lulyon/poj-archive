#include<iostream>
using namespace std;
int main()
{
    int n,sum,exp;
    while(cin>>n)
    {
        exp=1;
        sum=1;
        if(n==1)
        {
            cout<<'1'<<endl;
            continue;
        }
        int i;
        for(i=2;;i++)
        {
            exp=exp*10%n;
            sum+=exp;
            sum%=n;
            if(sum==0)break;
        }
        cout<<i<<endl;
    }
    return 0;
}
