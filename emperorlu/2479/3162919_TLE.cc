#include<iostream>
using namespace std;
long a[50010];
long Sum(int m,int n)
{
    long max=-1000000,sum=0;
    for(int i=m;i<=n;++i)
    {
        if(sum>=0)sum+=a[i];
        else
            sum = a[i];
        if(max<sum)max = sum;
    }
    return max;
    
}
long dp(int left,int right)
{
    long max = -1000000,tmp;
    for(int i=left;i<right-1;i++)
    {
        tmp = Sum(left,i)+Sum(i+1,right);
        if(max<tmp)max = tmp;
    }
    return max;
}
int main()
{
    int n,t;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        for(int i=0;i<n;++i)
            scanf("%ld",a+i);
        printf("%ld\n",dp(0,n-1));
    }
    return 0;
}
