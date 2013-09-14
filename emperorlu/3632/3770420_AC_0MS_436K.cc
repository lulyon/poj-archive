#include<iostream>
using namespace std;
int a[100];
int main()
{
    int t,n;
    cin>>t;
    while(t--)
    {
        cin>>n;
        int min=INT_MAX,max=-INT_MAX;
        for(int i=0;i<n;++i)
        {
            scanf("%d",a+i);
            if(min>a[i])min=a[i];
            if(max<a[i])max=a[i];
        }
        cout<<2*(max-min)<<endl;
    }
    return 0;
}
