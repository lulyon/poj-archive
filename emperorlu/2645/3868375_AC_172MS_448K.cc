#include<iostream>
#include<math.h>
using namespace std;
long long p,q;

long long gcd(long long x,long long y)
{
    if(y==0)return x;
    else return gcd(y,x%y);
}

int main()
{
    //freopen("/export/home/acm/Desktop/1","r",stdin);
    long long tmp;
    while(1)
    {
        cin>>p>>q;
        if(p==0&&q==0)break;
        
        tmp = gcd(p,q);
        p/=tmp;
        q/=tmp;
        if(p==0)
        {
            printf("0 2\n");
            continue;
        }
        if(p==q)
        {
            printf("2 0\n");
            continue;
        }
        long long x,y;
        for(x=2;x<=50000;++x)
        {
            tmp = q*x*(x-1);
            if(tmp%p==0)
            {
                y=(long long)sqrt((double)tmp/p)+1;
                if(y*(y-1)==tmp/p)
                {
                    y-=x;
                    if(y>0&&x+y<=50000)
                        break;
                }
            }
        }
        if(x<=50000)
            cout<<x<<' '<<y<<endl;
        else
            printf("impossible\n");
        
    }
    return 0;
}
