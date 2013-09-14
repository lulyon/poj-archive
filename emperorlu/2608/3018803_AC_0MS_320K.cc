#include<iostream>
using namespace std;
char a[25];
char f[27]={"01230120022455012623010202"};
char stack[25];
int main()
{
    while(cin>>a+1)
    {
        int tag=0;
        a[0]=0;
        for(int i=1;a[i];i++)
            if(f[a[i]-'A']!=f[a[i-1]-'A'])stack[tag++]=a[i];
        for(int i=0;i<tag;i++)
            if(f[stack[i]-'A']!='0')cout<<f[stack[i]-'A'];
        cout<<endl;
    }
    return 0;
}
