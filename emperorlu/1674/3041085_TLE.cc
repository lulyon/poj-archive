#include<iostream>
using namespace std;
int a[10010];
int main()
{
    int t,n,tmp;
    cin>>t;
    while(t--)
    {
        cin>>n;
        for(int i=0;i<n;i++)
            cin>>a[i];
        int cn=0;
        for(int i=0;i<n-1;i++)
        {
            int min=a[i],s=i;
            for(int j=i+1;j<n;j++)
            {
                if(min>a[j])
                {
                    min=a[j];
                    s=j;
                }
            }
            if(s!=i)
            {
                tmp=a[i];
                a[i]=a[s];
                a[s]=tmp;
                cn++;
            }
        }
        cout<<cn<<endl;
    }
    return 0;
}
