#include<iostream>
#include<math.h>
using namespace std;
bool prime[1000000];
void isprime(int n)
{
    int m=(int)sqrt(n);
    for(int i=3;i<=m;i+=2)
        if(n%i==0)return;
    prime[n]=1;
    return;
}
void init()
{
    prime[2]=1;
    prime[3]=1;
    for(int i=5;i<=1000000;i+=2)
        isprime(i);
}
int main()
{
    long a,d,n;
    init();
    while(1)
    {
        cin>>a>>d>>n;
        if(!a&&!d&&!n)break;
        long sum=a;
        int cn=0;
        while(1)
        {
            if(prime[sum])
                cn++;
            if(cn==n)break;
            sum+=d;
        }
        cout<<sum<<endl;
    }
    return 0;
} 
