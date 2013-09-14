#include<stdio.h>
#include<string.h>
int main()
{
    int i,n,count=0;
    char a[15][30],b[15][30];
    while((scanf("%d",&n),n)!=0)
    {
        count++;
        for(i=0;i<n;i++)
        {
            scanf("%s",a+i);
        }
        //for(i=0;i<n;i++)
        //{
          //  printf("%s\n",a[i]);
       // }
        for(i=0;i<n;i++)
        {
            if(i%2==0)strcpy(b[i/2],a[i]);
            else strcpy(b[n-1-i/2],a[i]);
        }
        printf("SET %d\n",count);
        for(i=0;i<n;i++)
        {
            printf("%s\n",b[i]);
        }
    }
    return 0;
}
