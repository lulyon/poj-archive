#include<stdio.h>
int main()
{
    int i;
    char a[10000];
    while((a[0]=getchar())!=EOF)
    {
        for(i=1;(a[i]=getchar())!='\n';i++)
        {
            if(a[i]>a[0])a[0]=a[i];
        }
        if(a[0]>='0'&&a[0]<='9')
        {
            printf("%d\n",a[0]+1-'0');
        }
        else if(a[0]>='A'&&a[0]<='Z')
        {
            printf("%d\n",a[0]-'A'+11);
        }
        else if(a[0]>='a'&&a[0]<='z')
        {
            printf("%d\n",a[0]-'z'+62);
        }
        else printf("such number is impossible!\n");
    }
    return 0;
}
