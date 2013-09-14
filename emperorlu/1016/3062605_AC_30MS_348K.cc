#include<iostream>
using namespace std;
char a[20][100];
int num[10];
int main()
{
    int i,j,k;
    while(1)
    {
        cin>>a[0];
        if(a[0][0] == '-')break;
        for(i=1;i<=16;i++)
        {
            memset(num,0,sizeof(num));
            for(j=0;a[i-1][j];j++)
                num[a[i-1][j]-'0']++;
            int flag=0;
            for(j=0;j<10;j++)
                if(num[j]>=10)
                {
                    a[i][flag++]=num[j]/10+'0';
                    a[i][flag++]=num[j]%10+'0';
                    a[i][flag++]=j+'0';
                }
                else if(num[j]>0)
                {
                    a[i][flag++]=num[j]+'0';
                    a[i][flag++]=j+'0';
                }
            a[i][flag]='\0';
        }
        if(strcmp(a[0],a[1])==0)
        {
            cout<<a[0]<<" is self-inventorying"<<endl;
            continue;
        }
        for(i=1;i<=15;i++)
            if(strcmp(a[i],a[i+1])==0)
            {
                cout<<a[0]<<" is self-inventorying after "<<i<<" steps"<<endl;
                break;
            }
        if(i<=15)continue;
        for(k=2;k<=15;k++)
            for(i=0,j=k;j<=15;i++,j++)
                if(strcmp(a[i],a[j])==0)
                {
                    cout<<a[0]<<" enters an inventory loop of length "<<k<<endl;
                    goto leap;
                }
        leap:if(k<=15)continue;
        cout<<a[0]<<" can not be classified after 15 iterations"<<endl;
    }
    return 0;
}
