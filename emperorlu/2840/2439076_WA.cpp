#include<stdio.h>
#include<string.h>
int main()
{
    int t,n,i,r;
    char a[5];
    scanf("%d\n",&t);
    while(t--)
    {
        gets(a);
        r=10*(a[0]-'0')+a[1]-'0';
        if(a[3]!='0'||a[4]!='0')n=0;
        else if(r<=12)n=r+12;
        else n=r-12;
        printf("%d\n",n);
    }
    return 0;
}
