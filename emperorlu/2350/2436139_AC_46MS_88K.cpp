#include <stdio.h>
int main()
{
    int i,count,k,n;
    float sum,a[10000],aver,per;
    scanf("%d",&n);
    while(n--)
    {
        scanf("%d",&k);
        for(i=0,sum=0;i<k;i++)
        {
            scanf("%f",a+i);
            sum+=a[i];
        }
        aver=sum/k;
        for(i=0,count=0;i<k;i++)
        {
            if(a[i]>aver)count++;
        }
        per=count/(float)k*100.0;
        printf("%.3f%%\n",per);
    }
    return 0;
}
