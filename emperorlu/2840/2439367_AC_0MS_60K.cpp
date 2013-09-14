#include<stdio.h>
#include<string.h>
int main()
{
    int t,n,i,r;
    char a[5];
    scanf("%d\n",&t);
    while(t--)
    {
        for(i=0;i<5;i++)
        {
            scanf("%c",a+i);
            if(a[1]==':'&&i==3)
            {
                a[4]=a[3];
                a[3]=a[2];
                a[2]=':';
                a[1]=a[0];
                a[0]='0';
                getchar();
                goto leap;
            }
        } 
        getchar();
        leap:r=10*(a[0]-'0')+a[1]-'0';
        if(a[3]!='0'||a[4]!='0')n=0;
        if(a[3]=='0'&&a[4]=='0'&&r<=12)n=r+12;
        if(a[3]=='0'&&a[4]=='0'&&r>12) n=r-12;
        printf("%d\n",n);
    }
    return 0;
}
