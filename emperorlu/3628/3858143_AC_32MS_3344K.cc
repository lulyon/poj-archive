#include<iostream>
using namespace std;
long w[25],m[25][1000010];

long max(long a,long b)
{
    return a>b?a:b;
}

int main()
{
    int n;
    long b,sum=0;
    scanf("%d%ld",&n,&b);
    
    
    for(int i=1;i<=n;++i)
    {
        scanf("%ld",w+i);
        sum+=w[i];
    }
    b=sum-b;
    
    for(int j=1;j<w[n];++j)
        m[n][j]=0;
    
    for(int j=w[n];j<=b;++j)
        m[n][j]=w[n];
   
    
   for(int i=n-1;i>=1;--i)
   {
       for(int j=0;j<w[i];++j)
       {
           m[i][j]=m[i+1][j];
       }
       for(int j=w[i];j<=b;++j)
       {
           m[i][j]=max(m[i+1][j],m[i+1][j-w[i]]+w[i]);
       }
   }
    
    printf("%ld\n",b-m[1][b]);
    
    return 0;
}
