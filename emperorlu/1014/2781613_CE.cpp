#include<stdio.h>
#include<stdlib.h>
int a[7];
int cmp ( const void *a , const void *b )
{
     return *(int *)b - *(int *)a;
}

int main()
{
    int n=0;
    while(scanf("%d%d%d%d%d%d",a+1,a+2,a+3,a+4,a+5,a+6),a[1]||a[2]||a[3]||a[4]||a[5]||a[6])
    {
        n++;
        int s1=0,s2=0;
        for(int i=1;i<=6;i++)
            a[i]*=i;
        qsort(a+1,6,sizeof(a[1]),cmp);
        for(int i=1;i<=6;i++)
        {
            if(s1<s2)s1+=a[i];
            else s2+=a[i];
        }
        
        printf("Collection #%d:\n",n);
        if(s1==s2)printf("Can be divided.\n");
        else printf("Can't be divided.\n");
    }
    return 0;
}
