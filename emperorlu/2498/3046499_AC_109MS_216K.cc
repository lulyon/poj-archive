#include<stdio.h>
#include<stdlib.h>
char a[10];
int main()
{
    int t,i,j,cn=1;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%s",a);
        int sum = 0;
        int s;
        for(i=0;a[i];i++)
            if(a[i]=='?')s=i;
        i--;
        int ai,m;
        for(j=0;j<=i;j++)
        {
            ai = a[i-j]-'0';
            if(i-j==s)
            {
               if(j%3==0)m = 9;
               else if(j%3==1)m = 3;
               else if(j%3==2)m = 7;
            }
            else if(j%3==0)sum += ai*9;
            else if(j%3==1)sum += ai*3;
            else if(j%3==2)sum += ai*7;
        }
        for(i=0;i<=9;i++)
        {
            if((sum+i*m)%10==0)
            {
                a[s]=i+'0';
                break;
            }
        }
        printf("Scenario #%d:\n%s\n\n",cn++,a);
    }
    return 0;
}
