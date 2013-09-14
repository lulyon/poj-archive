#include<iostream>
using namespace std;
int a[10010];
int main()
{
    int t,n,i,j;
    cin>>t;
    while(t--)
    {
        cin>>n;
        int cn=0;
        for(i=0;i<n;i++)
        {
            cin>>a[i];
            for(j=0;j<i;j++)
                if(a[j]>a[i])cn++;
        }
        cout<<cn<<endl;
    }
    return 0;
}
