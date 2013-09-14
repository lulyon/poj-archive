#include<iostream>
#include<math.h>
using namespace std;
bool prime(int n)
{
    int m=(int)sqrt(n);
    for(int i=3;i<=m;i+=2)
        if(n%i==0)return 0;
    return 1;
}
int main()
{
    int n;
    while(1)
    {
        cin>>n;
        if(!n)break;
        int cn=0;
        if(n==4)cn=1;
        else
        {
            for(int i=2;i<=n/2;i+=2)
                if(prime(i)&&prime(n-i))cn++;
        }
        cout<<cn<<endl;
    }
    return 0;
}
