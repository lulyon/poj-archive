#include<iostream>
using namespace std;
int a[150010];
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;++i)
        scanf("%d",a+i);
    if(n==1)
    {
        printf("%d",a[0]);
        return 0;
    }
    int p1=0,p2=1,sum=0;
    while(1)
    {
        while(p2<n&&a[p1]<=a[p2])
        {
            p1++;
            p2++;
        }
        if(p2==n)
        {
            sum += a[p1];
            
            break;
        }
        else
        {
            sum += a[p1];
        }
        while(p2<n&&a[p1]>=a[p2])
        {
            p1++;
            p2++;
        }
        if(p2==n)
        {
            break;
        }
        else
        {
            sum -= a[p1];
        }
    }
    
    printf("%d\n",sum);
    
    return 0;
}

