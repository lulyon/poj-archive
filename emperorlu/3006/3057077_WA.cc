#include<iostream>
#include<math.h>
using namespace std;
bool prime[1000000];

bool isprime(long n)
{
    int m=(int)sqrt((double)n);
    if(n==2)return 1;
    else if(n%2==0)return 0;
    else if(n==3)return 1;
    
    for(int i=3;i<=m;i+=2)
        if(n%i==0)return 0; 
    return 1;
}

int main()
{
    long a,d,n;
    while(1)
    {
        cin>>a>>d>>n;
        if(!a&&!d&&!n)break;
        long sum=a;
        int cn=0;
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
