#include<iostream>
#include<cstring>
using namespace std;
char a[50],b[50],c[100];
int calc()
{
    int s,add,tmp,max=0;
    int La=strlen(a),Lb=strlen(b);
    for(int i=La-1;i>=0;i--)
        for(int j=Lb-1;j>=0;j--)
        {
            s=La+Lb-i-j-2;
            add=0;
            while(1)
            {
                if(add)tmp=add+c[s]-'0';
                else
                    tmp=add+c[s]-'0'+(a[i]-'0')*(b[j]-'0');
                c[s]=tmp%10+'0';
                if(tmp<10)break;
                add=tmp/10;
                s++;
            }
            if(max<s)max=s;
        }
    return max;
}
int main()
{
    cin>>a>>b;
    memset(c,'0',sizeof(c));
    int max=calc();
    for(int i=max;i>=0;i--)
        cout<<c[i];
    cout<<endl;
    //system("pause");
    return 0;
}
