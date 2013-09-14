#include<stdio.h>
#include<string.h>
int main()
{
    int i,j,n,k,len,flag;
    char head,temp,a[100],b[100];
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        scanf("%s%s",a,b);
        head='0';
        if(strlen(a)>strlen(b))
        {
            len=strlen(b);
            for(j=0;j<strlen(a)-len;j++)
            {
                for(k=len+j;k>j;k--)
                {
                    b[k]=b[k-1];
                }
                b[j]='0';
            }
            b[strlen(a)]='\0';
        }
        if(strlen(a)<strlen(b))
        {
            len=strlen(a);
            for(j=0;j<strlen(b)-len;j++)
            {
                for(k=len+j;k>j;k--)
                {
                    a[k]=a[k-1];
                }
                a[j]='0';
            }
            a[strlen(b)]='\0';
        }
        for(j=strlen(a)-1;j>=0;j--)
        {
           temp=a[j];
           a[j]=(a[j]-'0'+b[j]-'0')%2+'0';
           if(j==0&&((temp-'0'+b[0]-'0')==3||(temp-'0'+b[0]-'0')==2))
            {
                head='1';break;
            }
            if(j==0)break;
           a[j-1]+=(temp-'0'+b[j]-'0')/2;
            
        }
        printf("%d ",i);
        if(head=='1')printf("%c",head);
        for(j=0,flag=0;j<strlen(a);j++)
        {
            if(a[j]!='0'||head=='1')flag=1;
            if(flag==1)printf("%c",a[j]);
         }
         printf("\n");
    }
    return 0;
}
