#include<iostream>
using namespace std;
int a[1000000];
int b[250][2];
int main()
{
    int t,n;
    cin>>t;
    while(t--)
    {
        cin>>n;
        int min=1000000,max=0;
        for(int i=0;i<n;i++)
            for(int j=0;j<2;j++)
            {
                cin>>b[i][j];
                b[i][j]=(b[i][j]+1)/2;
                if(max<b[i][j])max=b[i][j];
                if(min>b[i][j])min=b[i][j];
            }
        
        memset(a,0,(max+10)*sizeof(int));
        for(int i=0;i<n;i++)
        {
            if(b[i][0]<=b[i][1])
                for(int j=b[i][0];j<=b[i][1];j++)
                    a[j]++;
            else
                for(int j=b[i][1];j<=b[i][0];j++)
                    a[j]++;
        }
        /*
        for(int i=min;i<=max;i++)
            cout<<a[i]<<endl;
        system("pause");
        */
        int cn=0;
        for(int i=min;i<=max;i++)
            if(cn<a[i])cn=a[i];
        cout<<cn<<'0'<<endl;
    }
    return 0;
}
