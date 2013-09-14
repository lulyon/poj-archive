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
        int sa,sb;
        for(sa=0;;sa++)
            if(a[sa]!='0')break;
        for(sb=0;;sb++)
            if(b[sb]!='0')break;
        lena=strlen(a+sa);
        lenb=strlen(b+sb);
        int i;
        if(lena<lenb)
        {
            for(i=sa+lena;i<sb+lenb;i++)
                a[i]='0';
            a[i]='\0';
        }
        else
        {
            for(i=sb+lenb;i<sa+lena;i++)
                b[i]='0';
            b[i]='\0';
        }
       /* cout<<a<<endl;
        cout<<b<<endl;
        system("pause");
        */
        int s=0,tmp;
        for(i=0;a[i+sa];i++)
        {
            tmp=a[i+sa];
            a[i+sa]=(tmp-'0'+b[i+sb]-'0'+s)%10+'0';
            s=(tmp-'0'+b[i]-'0'+s)/10;
        }
        a[sa+i++]=s+'0';
        a[sa+i]='\0';
        /*
        cout<<a<<endl;
        system("pause");
        */
        for(i=sa+lena;;i--)
            if(a[i]!='0')break;
        a[i+1]='\0';
        for(i=sa;;i++)
            if(a[i]!='0')break;
        cout<<a+i<<endl;
    }
    return 0;
}
