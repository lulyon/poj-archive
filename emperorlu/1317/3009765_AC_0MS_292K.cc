#include<iostream>
using namespace std;
int n;
int k;
char a[80];
int b[80],c[80];
void alpha2num()
{
    for(int i=0;i<n;i++)
    {
        if(a[i]=='_')b[i]=0;
        else if(a[i]>='a'&&a[i]<='z')
            b[i]=a[i]-'a'+1;
        else if(a[i]=='.')b[i]=27;
    }
    return;
}
void num2num()
{
    int tmp;
    for(int i=0;i<n;i++)
    {
        tmp=b[i]+i;
        while(1)
        {
            if(tmp>=0&&tmp<=27)
            {
                c[k*i%n]=tmp;
                break;
            }
            else if(tmp<0)
                tmp+=28;
            else if(tmp>27)
                tmp-=28;
        }
    }
    return;
}
void num2alpha()
{
    for(int i=0;i<n;i++)
    {
        if(c[i]==0)a[i]='_';
        else if(c[i]>=1&&c[i]<=26)
            a[i]=c[i]+'a'-1;
        else if(c[i]==27)a[i]='.';
    }
    return;
}
int main()
{
    while(1)
    {
        cin>>k;
        if(k==0)break;
        cin>>a;
        n=strlen(a);
        alpha2num();
        num2num();
        num2alpha();
        cout<<a<<endl;
    }
    return 0;
}
