#include<iostream>
#include<cstring>
using namespace std;
char a[15];
int main()
{
    gets(a);
    int sum=0;
    int flag,i;
    if(a[10]!='\0')
    {
        cout<<"-1"<<endl;
        return 0;
    }
    for(i=0;i<10;i++)
    {
        if(a[i]<='9'&&a[i]>='0')
            sum+=(a[i]-'0')*(10-i);
        else if(a[i]=='X'&&i==9)sum+=10*(10-i);
        else if(a[i]=='?')flag=i;
        else
        {
            cout<<"-1"<<endl;
            return 0;
        }
    }
    if(flag==9)
    {
        for(i=0;i<=10;i++)
            if((sum+i*(10-flag))%11==0)
            {
                if(i==10)a[flag]='X';
                else a[flag]=i+'0';
            }
        if(i==11)
        {
            cout<<"-1"<<endl;
            return 0;
        }
    }
    else
    {
        for(i=0;i<10;i++)
            if((sum+i*(10-flag))%11==0)
                a[flag]='0'+i;
        if(i==10)
        {
            cout<<"-1"<<endl;
            return 0;
        }
    }
    cout<<a[flag]<<endl;
    return 0;
}
