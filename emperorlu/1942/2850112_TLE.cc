#include<stdio.h>
__int64 f(int m,int n)
{
    if(m==0||m==n)return 1;
    else if(m==1||m+1==n)return n;
    else return f(m,n-1)+f(m-1,n-1);
}
int main()
{
    __int64 m,n,ans;
    while(scanf("%I64d%I64d",&m,&n),m||n)
        printf("%I64d\n",f(m,m+n));
    return 0;
}