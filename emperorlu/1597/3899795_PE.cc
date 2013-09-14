#include<iostream>
using namespace std;

int gcd(int m,int n)
{
    if(n==0)return m;
    else return gcd(n,m%n);
}

int main()
{
    int n,m;
    while(scanf("%d %d",&m,&n)!=EOF)
    {
        if(gcd(m,n)==1)
            printf("%10d%10d     Good Choice\n",m,n);
        else
            printf("%10d%10d    Bad Choice\n",m,n);
    } 
    return 0;
}
