#include<iostream>
using namespace std;
int main()
{
    int t;
    char a[1000],b[1000],c[1000];
    cin>>t;
    while(t--)
    {
        cin>>a>>b;
        int lena,lenb;
        lena=strlen(a);
        lenb=strlen(b);
        int i;
        if(lena<lenb)
        {
            for(i=lena;i<lenb;i++)
                a[i]='0';
            a[i]='\0';
        }
        else
        {
            for(i=lenb;i<lena;i++)
                b[i]='0';
            b[i]='\0';
        }
        int s=0,tmp;
        for(i=0;a[i];i++)
        {
            tmp=a[i];
            a[i]=(tmp-'0'+b[i]-'0'+s)%10+'0';
            s=(tmp-'0'+b[i]-'0'+s)/10;
        }
        a[i++]=s+'0';
        a[i]='\0';
        for(i=lena;;i--)
            if(a[i]!='0')break;
        a[i+1]='\0';
            cout<<a<<endl;
    }
    return 0;
}
