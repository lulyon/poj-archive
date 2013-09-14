#include<iostream>
#include<math.h>
using namespace std;
long pm[100000];
bool prime[1000000];
bool isprime(int n)
{
    int m=(int)sqrt(n);
    for(int i=3;i<=m;i+=2)
        if(n%i==0)return 0;
    return 1;
}
void init()
{
    pm[0]=2;
    pm[1]=3;
    int flag=2;
    for(int i=5;i<=1000000;i+=2)
        if(isprime(i))pm[flag++]=i;
    pm[flag]=0;
    for(int i=0;pm[i]!=0;i++)
        prime[pm[i]]=1;
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
