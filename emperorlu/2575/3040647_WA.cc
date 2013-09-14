#include<iostream>
using namespace std;
long a[3010];
bool b[3010];
int main()
{
    long n,ab,tmp;
    while(cin>>n)
    {
        long i;
        for(i=0;i<n;i++)
        {
            cin>>a[i];
            b[i]=0;
        }
        if(n==1)
        {
            cout<<"Jolly"<<endl;
            continue;
        }
                
        for(i=0;i<n-1;i++)
        {
            tmp=a[i]-a[i+1];
            ab=tmp>0?tmp:-tmp;
            if(ab>0&&ab<n)b[ab]=1;
        }
        int flag=0;
        for(int i=1;i<n;i++)
        {
            if(!b[ab])
            {
                flag=1;
                break;
            }
        }
        if(flag)cout<<"Not jolly"<<endl;
        else cout<<"Jolly"<<endl;
    }
    return 0;
}
