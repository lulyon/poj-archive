#include<iostream>
#include<math.h>
using namespace std;
int main()
{
    int t,m,n,k,left,right;
    cin>>t;
    while(t--)
    {
        cin>>k;
        for(m=1;;m++)
        {
            if(k%2)
            {
                n=(k+1)/2;
                break;
            }
            k>>=1;
        }
        int tpow=(int)pow(2,m-1);
        left=tpow*(n-1)+1;
        right=tpow*n;
        cout<<2*left-1<<' '<<2*right-1<<endl;
    }
    return 0;
}
