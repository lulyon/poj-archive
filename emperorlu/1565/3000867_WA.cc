#include<stdio.h>
#include<string.h>
main()
{
    char a[100];
    int i,j,len;
    __int64 sum,tmp;
    while(1)
    {
        scanf("%s",a);
        if(a[0]=='0')break;
        sum=0;
        len=strlen(a);
        tmp=1;
        for(j=len-1;j>=0;j--)
        {
            tmp<<2;
            sum+=(a[j]-'0')*(tmp-1);
        }
        printf("%I64d\n",sum);
    }
    return 0;
}
