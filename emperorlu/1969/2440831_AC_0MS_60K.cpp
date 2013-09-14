#include<stdio.h>
int main()
{
    long i,n,x,y,sum;
    while(scanf("%ld",&n)!=EOF)
    {
        for(i=1,sum=0;sum<n;i++)
        {
            sum+=i;
        }
        i--;
        if(i%2==0)x=i+n-sum;
        else x=sum-n+1;
        y=i+1-x;
        printf("TERM %ld IS %ld/%ld\n",n,x,y);
    }
    return 0;
}
