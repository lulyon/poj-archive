#include <stdio.h>
int main()
{
    int i,j;
    float a[5],sum;
    for(i=0;i<5;i++)
        scanf("%f",a+i);
    printf("\n");
    for(i=0;i<5;i++)
        {   if(a[i]<0.01||a[i]>5.20)
                continue;
            for(j=1,sum=0;sum<=a[i];j++)
            {
                sum+=1.0/(j+1);
            }
            printf("%d card(s)\n",j-1);
        }
    return 0;
}
