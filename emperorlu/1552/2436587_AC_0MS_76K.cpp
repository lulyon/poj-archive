#include<stdio.h>
int main()
{
    int i,j,n,a[10000],temp,sub,count;
    leap:scanf("%d",a);
        if(a[0]==-1)goto leap1;
        for(i=0;a[i++]!=0;)
            scanf("%d",a+i);
    n=--i;
    if(a[0]!=-1)
    {
        for(i=0;i<n;i++)
        {
            for(j=i+1,sub=i;j<n;j++)
            {
                if(a[j]<a[sub])sub=j;
            }
            temp=a[i];
            a[i]=a[sub];
            a[sub]=temp;
        }
        //for(i=0;i<n;i++)
         //  printf("%d ",a[i]);
        for(i=1,count=0;i<n;i++)
        {
            for(j=0;j<i;j++)
            {
                if(a[i]==2*a[j])
                {
                    count++;
                    break;
                }
                
            }
        }
        printf("%d\n",count);
        goto leap;
    }
    leap1:return 0;
    
    
}
