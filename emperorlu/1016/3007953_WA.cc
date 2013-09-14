#include<stdio.h>
#include<string.h>
#include<stdlib.h>
void transfer(char a[],char b[])
{
    int num[10]={0};
    for(int i=0;a[i];i++)
	{
		if(a[i]>='0'&&a[i]<='9')
			num[a[i]-'0']++;
	}
    int tag=0;
    for(int i=0;i<10;i++)
    {
        if(num[i]>=10)
        {
            b[tag++]=num[i]/10+'0';
            b[tag++]=num[i]%10+'0';
            b[tag++]=i+'0';
        }
        else if(num[i]>0)
        {
            b[tag++]=num[i]+'0';
            b[tag++]=i+'0';
        }
    }
    b[tag]='\0';
    return;
}
int main()
{
    char a[100],b[15][100];
    while(1)
    {
		int flag=0;
        scanf("%s\n",a);
        if(a[0]=='-')break;
        transfer(a,b[0]);
        flag++;
        if(strcmp(a,b[0])==0)
        {
            printf("%s is self-inventorying\n",a);
            goto leap;
        }
        while(1)
        {
            transfer(b[flag-1],b[flag]);
            flag++;
            if(strcmp(a,b[flag-1])==0)
            {
                printf("%s is self-inventorying after %d steps\n",a,flag);
                goto leap;    
            }
            else
            {
                for(int i=flag-2;i>=0;i--)
                {
                    if(strcmp(b[i],b[flag-1])==0)
                    {
                        printf("%s enters an inventory loop of length %d\n",a,flag-i);
                        goto leap;
                    }
                }
            }
            if(flag>15)
            {
                printf("%s can not be classified after 15 iterations\n",a);
                goto leap;
            }
        }
        leap:
            ;
    }
    return 0;
}
