#include<iostream>
using namespace std;
long a[50010];
long Sum(int m,int n)
{
    long max=-1000000,min=1000000,sum1=0,sum2=0;
    int left=m,right=n;
    for(int i=m;i<=n;++i)
    {
        if(sum1>=0)
        {
            sum1+=a[i];
            if(max<sum1)
            {
                max = sum1;
                right = i;
            }
        }
        else
        {
            sum1 = a[i];
            if(max<sum1)
            {
                max = sum1;
                left = i;
            }
        }
    }
    
    //cout<<left<<' '<<right<<endl;
    //system("pause");
    
    for(int i=left;i<=right;++i)
    {
        if(sum2<=0)sum2 += a[i];
        else sum2=a[i];
        if(min>sum2)
            min =sum2;
    }
    return max-min;    
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
        printf("%ld\n",Sum(0,n-1));
    }
    return 0;
}
