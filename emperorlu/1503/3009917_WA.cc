#include<iostream>
using namespace std;
int a[30],b[30],n;
char c[101];
int c2b()
{
    int tag=n-1,cn=0,sum=0,exp=1,flag=0;
    while(tag>=0)
    {
        sum+=exp*(c[tag]-'0');
        exp*=10;
        cn++;
        if(cn==8)
        {
            b[flag++]=sum;
            sum=0;
            exp=1;
            cn=0;
        }
        tag--;
    }
    b[flag++]=sum;
    return flag;
}
int main()   
{
    int i,j,m;
    memset(a,0,sizeof(a)); 
    while(1)
    {
        cin>>c;
        if(c[0]=='0')break;
        n=strlen(c);
        m=c2b();
        for(j=0;j<=m;j++)   
        {   
            a[j]+=b[j];
            if(a[j]>=100000000)   
            {   
                a[j+1]+=a[j]/100000000;   
                a[j]%=100000000;
            }
        }
    }
    for(i=30;;i--)   
        if(a[i]!=0)break;   
    printf("%d",a[i]);   
    i--;   
    for(;i>=0;i--)
        printf("%08d",a[i]);   
    printf("\n");
    return 0;   
} 
