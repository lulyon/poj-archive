#include<stdio.h>
#include<string.h>
int main()
{
    int i,j,k,p,count,flag;
    char a[1000],b[1000];
    while((a[0]=getchar())!=EOF)
    {
        for(i=1;(a[i]=getchar())!=' ';i++);
        a[i]='\0';
        while((b[0]=getchar())==' ');
        for(i=1;(b[i]=getchar())!='\n';i++);
        b[i]='\0';
        count=0;
        for(i=0;i<strlen(b);i++)
        {
            flag=0;
            for(k=0;k<i;k++)
            {
                if(b[k]==b[i])
                {
                    flag=1;
                    break;
                }
            }
            if(flag==0)
            {
                for(j=0;j<strlen(a);j++)
                {
                    if(a[j]==b[i])
                    {
                        count++;
                        break;
                    }
                }
            }
        }
        printf("%d\n",count);
    }
    return 0;
}
