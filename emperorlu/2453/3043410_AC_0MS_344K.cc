#include<iostream>
using namespace std;
int a[100],len;
void ntoa(int n)
{
    int flag=0;
    while(1)
    {
        if(n==0)break;
        a[flag++] = n%2;
        n>>=1;
    }
    a[flag] = 0;
    len = flag;
    //cout<<"flag= "<<flag<<endl;
    //system("pause");
}
void tran()
{
    int i,j,tmp;
    for(i=0;i<len;i++)
        if(a[i]==1&&a[i+1]==0)break;
    tmp=a[i];
    a[i]=a[i+1];
    a[i+1]=tmp;
    int cn=0;
    for(j=i-1;j>=0;j--)
        if(a[j]==1)cn++;
    for(j=0;j<cn;j++)
        a[j]=1;
    for(j=cn;j<i;j++)
        a[j]=0;
}
long aton()
{
    long exp=1,sum=0;
    for(int i=0;i<=len;i++)
    {
        sum+=exp*a[i];
        exp<<=1;
    }
    return sum;
}
int main()
{
    long n;
    while(1)
    {
        cin>>n;
        if(!n)break;
        ntoa(n);
        /*
        for(int i=len;i>=0;i--)
            cout<<a[i];
        cout<<endl<<len<<endl;
        system("pause");
        */
        
        tran();
        
        /*
        for(int i=len;i>=0;i--)
            cout<<a[i];
        cout<<endl<<len<<endl;
        system("pause");
        */
        cout<<aton()<<endl;
    }
    return 0;
}
