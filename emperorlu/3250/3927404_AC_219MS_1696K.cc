#include<iostream>
#define MAXN 80010
using namespace std;
int stack[MAXN];
long long a[MAXN];
long long num[MAXN];

int main()
{
    int i,j,n;
    int top=0;
    cin>>n;
    for(i=0;i<n;++i)
        scanf("%I64d",a+i);
    
    num[n-1]=0;
    stack[top++]=n-1;
    long long sum=0;
    for(i=n-2;i>=0;--i)
    {
        for(j=0;j<top;++j)
        {
            if(a[i]>a[stack[j]])
            {
                num[i]=num[stack[j]]+stack[j]-i;
                stack[j]=i;
                top=j+1;
                break;
            }
        }
        if(j==top)
        {
            num[i]=0;
            stack[top++]=i;
        }
        sum+=num[i];
    }
    printf("%I64d\n",sum);
    return 0;
}
