#include<stdio.h>
#include<string.h>
int main()
{
    int i,j,n,k,flag;
    char head,temp,a[100],b[100];
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        scanf("%s%s",a,b);
        head='0';
        for(j=strlen(a)-1,k=strlen(b)-1;j>=0&&k>=0;j--,k--)
        {
           temp=a[j];
           a[j]=(a[j]-'0'+b[k]-'0')%2+'0';
           if(a[0]=='0'||(j==0&&(temp-'0'+b[k]-'0')==3))
            {
                head='1';break;
            }
            if(j==0)break;
           a[j-1]+=(temp-'0'+b[k]-'0')/2;
            
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
