#include<iostream>
#include<algorithm>
using namespace std;
char a[100],b[100],c[100];

bool cmp(const char &aa,const char &bb)
{
    return aa>bb;
}

int main()
{
    while(1)
    {
        scanf("%s",a);
        if(a[0]=='-')break;
        
        printf("N=%s:\n",a);
       
        
        if(strlen(a)!=4)
        {
            printf("No!!\n");
            continue;
        }
        
        if(a[0]==a[1]&&a[0]==a[2]&&a[0]==a[3])
        {
            printf("No!!\n");
            continue;
        }
        
        int i;
        int len=4;
        for(i=0;strcmp(a,"0000")&&strcmp(a,"6174");++i)
        {
            int flag=-1;
            for(int j=0;j<len;++j)
            {
                if(a[j]!='0')
                {
                    flag=j;
                    break;
                }
            }
            for(int j=0;j<len;++j)
            {
                b[j]=a[j];
                c[j]=a[j];
            }
            sort(c+flag,c+len);
            sort(b+flag,b+len,cmp);
            
            a[len]=b[len]=c[len]=0;
            
            int flag1,flag2;
            flag1=flag2=-1;
            
            for(int j=0;j<len;++j)
            {
                if(b[j]!='0')
                {
                    flag1=j;
                    break;
                }
            }
            if(flag1==-1)
                printf("0");
            else
                printf("%s",b+flag1);
            
            printf("-");
            
            for(int j=0;j<len;++j)
            {
                if(c[j]!='0')
                {
                    flag2=j;
                    break;
                }
            }
            
            if(flag2==-1)
                printf("0");
            else
                printf("%s",c+flag2);
            
            printf("=");
            
            for(int j=len-1;j>=0;--j)
            {
                if(b[j]<c[j])
                {
                    b[j]+=10;
                    b[j-1]--;
                }
                a[j]=b[j]-c[j]+'0';
            }
            
            flag=-1;
            for(int j=0;j<len;++j)
            {
                if(a[j]!='0')
                {
                    flag=j;
                    break;
                }
            }
            if(flag==-1)
                printf("0\n");
            else
                printf("%s\n",a+flag);
        }
        printf("Ok!! %d times\n",i);
        
    }
    return 0;
}
