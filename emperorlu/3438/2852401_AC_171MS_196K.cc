#include<stdio.h>
#include<stdlib.h>
#include<memory.h>
int main()
{
    int t,b[1001];
    char a[1001];
    scanf("%d\n",&t);
    while(t--)
    {
        scanf("%s",a);
        //printf("%s",a);
        //system("pause");
        int j=0;
        memset(b,0,sizeof(b));
        for(int i=0;a[i];i++)
        {
           
            b[j]++;
            for(;a[i]==a[i+1];i++)
                b[j]++;
            
            //printf("%d",b[j]);
            //system("pause");
            b[j]=a[i]-'0'+10*b[j];
            //printf("a[%d]=%d b[%d]=%d",i,a[i]-'0',j,b[j]);
            //system("pause");
            j++;
        }
        for(int i=0;i<j;i++)
            printf("%d",b[i]);
        putchar('\n');
    }
    return 0;
}
