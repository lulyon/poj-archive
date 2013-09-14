#include <stdio.h>
int main()
{
    int k,i,j,n,a[101],count;
    scanf("%d",&k);
    while(k--)
    {
        scanf("%d",&n);
        for(i=1;i<=n;i++)
            a[i]=0;
        for(i=1,j=1;j<=n;)
        {
            a[i]=~a[i];
            i+=j;
            if(i>n)
            {
                j++;
                i=j;
            }
        }
       for(i=1,count=0;i<=n;i++)
       {
          if(a[i]==-1)count++;
       }
        printf("%d\n",count);
    }
    return 0;
}
