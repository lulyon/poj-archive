#include<stdio.h>
#include<string.h>
int main()
{
    int i,j,sum;
    char a[10000];
    while((scanf("%s",a),a[0])!='0')
    {
        i=strlen(a);
        for(j=1,sum=a[0]-'0';j<i;j++)
        {
            sum+=a[j]-'0';
            if(sum>9)sum-=9;
        }
        printf("%d\n",sum);
    }
    return 0;
}
