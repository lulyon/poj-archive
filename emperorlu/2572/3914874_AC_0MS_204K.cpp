#include<iostream>
using namespace std;
char a[20],b[20],c[20],d[20];
char str[50];
int main()
{
    int i,j,k,kk,alen,blen,clen;
    while(scanf("%s",str)!=EOF)
    {
        for(i=0;;++i)
            if(str[i]=='+')break;
        for(k=0;k<i;++k)
            a[k]=str[k];
        a[k]=0;
        
        for(kk=k-1;kk>0&&a[kk]=='0';kk--);
        alen=kk;
        
        j=i+1;
        for(;;++j)
            if(str[j]=='=')break;
        
        for(k=0,kk=i+1;kk<j;++kk,++k)
            b[k]=str[kk];
        b[k]=0;
        for(kk=k-1;kk>0&&b[kk]=='0';kk--);
        blen=kk;
        
        
        for(kk=j+1,k=0;str[kk];++kk,k++)
            c[k]=str[kk];
        c[k]=0;
        for(kk=k-1;kk>0&&c[kk]=='0';kk--);
        clen=kk;
        c[clen+1]=0;
        
        
        
        
        int s=0;
        for(i=0;i<=alen&&i<=blen;++i)
        {
            d[i]=(a[i]-'0'+b[i]-'0'+s)%10+'0';
            s = (a[i]-'0'+b[i]-'0'+s)/10;
        }
        for(;i<=alen;++i)
        {
            d[i]=(a[i]-'0'+s)%10+'0';
            s = (a[i]-'0'+s)/10;
        }
        for(;i<=blen;++i)
        {
            d[i]=(b[i]-'0'+s)%10+'0';
            s = (b[i]-'0'+s)/10;
        }
        if(s)
        {
            d[i++]=s+'0';
            d[i]=0;
        }
        else
            d[i]=0;
        
        if(strcmp(c,d))
            printf("False\n");
        else
            printf("True\n");
    }
    return 0;
}


