#include<iostream>
using namespace std;
int a[500001];
bool b[100000001];
void creat()
{
    a[0]=0;
    for(int i=1;i<=500000;i++)
    {
        a[i]=a[i-1]-i;
        if(a[i]<=0||b[a[i]])a[i]+=2*i;
        b[a[i]]=1;
    }
    return;
}
int main()
{
    int n;
    creat();
    while(1)
    {
        cin>>n;
        if(!(n+1))break;
        cout<<a[n]<<endl;
    }
    return 0;
}
