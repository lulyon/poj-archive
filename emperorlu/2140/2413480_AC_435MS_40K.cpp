#include<stdio.h>
int main()
{
    long i,n,count=0;
    float aver;
    scanf("%d",&n);
    for(i=1;i<n/2;i++)
    {
        if(i%2!=0&&n%i==0&&n/i>i/2)count++;
        if(i%2==0&&(2*(n/i)+1)*i/2==n&n/i>i/2)count++;
            
    }
    printf("%d",count);
    return 0;    
}
