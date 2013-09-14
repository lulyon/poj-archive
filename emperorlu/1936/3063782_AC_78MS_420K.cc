#include<iostream>
using namespace std;
char a[100010],b[100010];
int main()
{
    int i,j,k;
    while(cin>>a>>b)
    {
        for(i=0,j=0;b[i]&&a[j];)
        {
            if(a[j]==b[i])
            {
                i++;
                j++;
            }
            else
            {
                i++;
            }
        }
        if(!b[i]&&a[j])
            cout<<"No"<<endl;
        else if(!a[j])
            cout<<"Yes"<<endl;
    }
    return 0;
}
