#include<iostream>
using namespace std;
long a[50010],Left[50010],Right[50010];
void Sum1(int n)
{
    int max=-1000000,sum=0;
    for(int i=0;i<n-1;++i)
    {
        if(sum>=0)sum += a[i];
        else sum = a[i];
        if(max<sum)max=sum;
        Left[i]=sum;
    }
}
void Sum2(int n)
{
    int max=-1000000,sum=0;
    for(int i=n-1;i>0;--i)
    {
        if(sum>=0)sum += a[i];
        else sum = a[i];
        if(max<sum)max=sum;
        Right[i]=max;
    }
}
long Sum(int n)
{
    int max=-1000000;
    for(int i=0;i<n-1;++i)
    {
        if(max<Left[i]+Right[i+1])
            max = Left[i]+Right[i+1];
    }
    return max;
}
int main()
{
    int t,n;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        for(int i=0;i<n;++i)
            scanf("%d",a+i);
        Sum1(n);
        Sum2(n);
        printf("%ld\n",Sum(n));
    }
    return 0;
}
