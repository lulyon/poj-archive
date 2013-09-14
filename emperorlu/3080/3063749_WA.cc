#include<iostream>
using namespace std;
char a[10][70];
int main()
{
    int t,num,i,j,k,m,n,l;
    cin>>t;
    while(t--)
    {
        cin>>num;
        for(i=0;i<num;i++)
            cin>>a[i];
        for(i=60;i>=3;i--)
        {
            for(j=0;i+j-1<60;j++)
            {
                for(k=1;k<num;k++)
                {
                    for(n=0;n+i-1<60;n++)
                    {
                        for(m=j,l=n;m<i+j&&a[0][m]==a[k][l];m++,l++);
                        if(m==i+j)break;
                    }
                    if(n+i-1==60)break;
                }
                if(k==num)
                {
                    for(m=j;m<i+j;m++)
                        cout<<a[0][m];
                    cout<<endl;
                    break;
                }
            }
            if(k==num)break;
        }
        if(i<3)
            cout<<"no significant commonalities"<<endl;
    }
    return 0;
}
