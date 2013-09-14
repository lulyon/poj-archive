#include<stdio.h>
#include<stdlib.h>
int main()
{
    int n,i,sum=0;
    scanf("%d",&n);
    for(i=1;;i++)
    {
        sum+=i;
        if(sum>=n&&(sum-n)%2==0)break;
    }
    printf("%d\n",i);
//    system("pause");
    return 0;
}