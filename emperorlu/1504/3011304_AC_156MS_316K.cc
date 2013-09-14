#include<iostream>
using namespace std;
int main()
{
    int t;
    __int64 m,n;
    int a[100],b[100],mtag,ntag;
    cin>>t;
    while(t--)
    {
        cin>>m>>n;
        while(1)
        {
            if(m%10)break;
            m/=10;
        }
        mtag=0;
        while(1)
        {
            if(m==0)break;
            a[mtag++]=m%10;
            m/=10;
        }
        while(1)
        {
            if(n%10)break;
            n/=10;
        }
        ntag=0;
        while(1)
        {
            if(n==0)break;
            b[ntag++]=n%10;
            n/=10;
        }
        int len;
        int plus;
        if(mtag<ntag)
        {
            plus=ntag-mtag;
            for(int i=ntag-1;i>=plus;i--)
                a[i]=a[i-plus];
            for(int i=0;i<plus;i++)
                a[i]=0;
            len=ntag;
        }
        else
        {
            plus=mtag-ntag;
            for(int i=mtag-1;i>=plus;i--)
                b[i]=b[i-plus];
            for(int i=0;i<plus;i++)
                b[i]=0;
            len=mtag;
        }
        /*
        for(int i=0;i<len;i++)
            cout<<a[i];
        cout<<endl;
        for(int i=0;i<len;i++)
            cout<<b[i];
        cout<<endl;
        system("pause");
        */
        int s=0,tmp;
        for(int i=len-1;i>=0;i--)
        {
            tmp=a[i];
            a[i]=(tmp+b[i]+s)%10;
            s=(tmp+b[i]+s)/10;
        }
        int i;
        for(i=len-1;;i--)
            if(a[i])break;
        for(;i>=0;i--)
            cout<<a[i];
        if(s)cout<<s;
        cout<<endl;
    }
    //system("pause");
    return 0;
}
