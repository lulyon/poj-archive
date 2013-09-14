#include<iostream>
#include<math.h>
using namespace std;

bool isprime(long long n)
{
    long m=(long)sqrt((double)n);
    if(n==1)return 0;
    else if(n==2)return 1;
    else if(n==3)return 1;
    else if(n%2==0)return 0;
    
    for(long i=3;i<=m;i+=2)
        if(n%i==0)return 0; 
    return 1;
}

int main()
{
    long long a,d,n;
    while(1)
    {
        cin>>a>>d>>n;
        if(!a&&!d&&!n)break;
        long long sum=a;
        long long cn=0;
        while(1)
        {
            if(isprime(sum))
                cn++;
            if(cn==n)break;
            sum+=d;
        }
        cout<<sum<<endl;
    }
    return 0;
} 
