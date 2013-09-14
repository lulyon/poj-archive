#include<iostream>
#define MAXN 80010
using namespace std;
long long stack[MAXN];
long long a[MAXN];
long long num[MAXN];

int main()
{
    int i,j,n;
    int top=0;
    cin>>n;
    for(i=0;i<n;++i)
        scanf("%lld",a+i);
    
    num[n-1]=0;
    stack[top++]=n-1;
    long long sum=0;
    int begin,end,mid;
    for(i=n-2;i>=0;--i)
    {
        begin = 0;
        end = top-1;
        mid = (begin+end)/2;
        
        if(a[i]<=a[stack[end]])
        {
            num[i]=0;
            stack[top++]=i;
        }
        else  if(a[i]>a[stack[begin]])
        {
            num[i]=num[stack[begin]]+stack[begin]-i;
            stack[begin]=i;
            top=1;
        }
        else
        {
            while(begin+1<end)
            {
                if(a[i]>a[stack[mid]])
                {
                    end = mid;
                    mid = (begin+end)/2;
                }
                else if(a[i]<=a[stack[mid+1]])
                {
                    begin = mid;
                    mid = (begin+end)/2;
                }
                else
                    break;
            }
            num[i]=num[stack[mid+1]]+stack[mid+1]-i;
            stack[mid+1]=i;
            top=mid+2;
        }
        //cout<<top<<' '<<num[i]<<endl;
        sum+=num[i];
    }
    printf("%lld\n",sum);
    return 0;
}
