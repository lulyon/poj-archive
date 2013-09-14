#include<stdio.h>
#include<stdlib.h>
char a[5001];
int main()
{
    int n,i,j,sum;
    scanf("%d\n",&n);
    for(i=1;i<=n;i++)
        scanf("%c",a+i);
    sum=0;
    if(n%2)
    {
        i=n/2;
        j=i+2;
        for(;i>0;i--,j++)
            if(a[i]!=a[j])sum+=2;
    }
    else
    {
        i=n/2;
        j=i+1;
        for(;i>0;i--,j++)
            if(a[i]!=a[j])sum+=2;
    }
    printf("%d\n",sum);
    //system("pause");
    return 0;
}
