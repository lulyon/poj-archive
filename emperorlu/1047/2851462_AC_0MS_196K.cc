#include<stdio.h>
#include<string.h>
#include<stdlib.h>
char a[65],b[65];
int l;
int add()
{
    int s=0,tmp;
    for(int i=l-1;i>=0;i--)
    {
        tmp=b[i];
        b[i]=(a[i]-'0'+b[i]-'0'+s)%10+'0';
        s=(a[i]-'0'+tmp-'0'+s)/10;
    }
    //printf("%s",b);
    //system("pause");
    return s;
}
int check()
{
    int tag=0;
    for(int i=0;i<l;i++)
    {
        if(a[i]==b[0])
        {
            int flag=0;
            for(int j=1,k=(j+i)%l;j<l;j++,k=(++k)%l)
                if(a[k]!=b[j])
                {
                    flag=1;
                    break;
                }
            if(!flag)
            {
                tag=1;
                break;
            }
        }
    }
    if(tag)return 1;
    else return 0;
}
int main()
{
    while(scanf("%s",a)!=EOF)
    {
        l=strlen(a);
        strcpy(b,a);
        //printf("%s",a);
        //system("pause");
        int flag=0,tag;
        for(int i=2;i<=l;i++)
        {
            tag=add();
            if(tag)
            {
                flag=1;
                break;
            }
            if(check())continue;
            flag=1;
            break;
        }
        if(flag)printf("%s is not cyclic\n",a);
        else printf("%s is cyclic\n",a);
    }
}
