#include<iostream>
using namespace std;
int main()
{
    //freopen("in.dat","r",stdin);
    //freopen("out.dat","w",stdout);
    int t,n,q,d,m,p,tt=0;
    cin>>t;
    while(t--)
    {
        scanf("%d",&n);
        q=n/25;
        n%=25;
        d=n/10;
        n%=10;
        m=n/5;
        n%=5;
        p=n;
        printf("%d %d QUARTER(S), %d DIME(S), %d NICKEL(S), %d PENNY(S)\n",++tt,q,d,m,p);
    }
    return 0;
}
