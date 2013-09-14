#include<stdio.h>
#include<string.h>
int main()
{
    long i,j,k,count,flag;
    char a[100000],b[100000];
    while((a[0]=getchar())!=EOF)
    {
        for(i=1;(a[i]=getchar())!=' ';i++);
        a[i]='\0';
        while((b[0]=getchar())==' ');
        for(i=1;(b[i]=getchar(),b[i]!='\n'&&b[i]!=' ');i++);
        b[i]='\0';
        count=0;
        flag=0;
        for(i=0;b[i]!='\0';i++)
        {
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
                for(j=0;a[j]!='\0';j++)
                {
                    if(a[j]==b[i])
                    {
                        count++;
                        break; 
                    }
                }
            }
        }
        printf("%ld\n",count);
    }
    return 0;
}
