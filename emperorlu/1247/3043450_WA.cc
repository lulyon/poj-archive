#include<iostream>
using namespace std;
int a[100];
int main()
{
    int n,i;
    while(1)
    {
        cin>>n;
        if(!n)break;
        int sum=0;
        for(i=0;i<n;i++)
        {
            cin>>a[i];
            sum+=a[i];
        }
        if(sum%2)
        {
            cout<<"No equal partitioning."<<endl;
            continue;
        }
        sum/=2;
        for(i=0;i<n;i++)
        {
            sum-=a[i];
            if(sum==0)break;
        }
        if(i==n)
        {
            cout<<"No equal partitioning."<<endl;
            continue;
        }
        cout<<"Sam stops at position "<<i<<" and Ella stops at position "<<i+1<<"."<<endl;
    }
    return 0;
}
