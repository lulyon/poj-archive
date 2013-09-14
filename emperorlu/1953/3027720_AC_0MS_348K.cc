#include<iostream>
using namespace std;
int C(int m,int n)
{
    double tmp=1;
    for(int i=1;i<=m;i++)
    {
        tmp*=n-m+i;
        tmp/=i;
    }
    return (int)tmp;
}

int main()
{
    int t,n,m;
    cin>>t;
    for(int i=1;i<=t;i++)
    {
        cin>>n;
        cout<<"Scenario #"<<i<<':'<<endl;
        if(n%2)m=n/2+1;
        else m=n/2;
        int sum=0;
        for(int i=0;i<=m;i++)
        {
            sum+=C(i,n-i+1);
            //cout<<sum<<endl;
            //system("pause");    
        }
        cout<<sum<<endl<<endl;
    }
    return 0;
}
