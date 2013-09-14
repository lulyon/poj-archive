#include<stdio.h>
int main()
{
    int i,fac=1;
    double sum=0.0;
    printf("n e\n- -----------\n");
    for(i=0;i<=9;i++)
    {
        i>0?fac*=i:fac=1;
        sum+=1/(double)fac;
        if(i==0||i==1)
            printf("%d %.0f\n",i,sum);
        else if(i==2)
            printf("%d %.1f\n",i,sum);
        else printf("%d %.9f\n",i,sum);
    }
    return 0;
}
