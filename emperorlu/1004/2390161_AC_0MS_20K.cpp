#include<stdio.h>
int main()
{
    double sum=0,temp,n=0;
    
    while(scanf("%lf",&temp)!=EOF)
    {
        sum+=temp;
        n++;
    }
    printf("$%.2lf\n",sum/n);
   
    return 0;
}
