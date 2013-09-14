#include <stdio.h>
#include <math.h>
int main()
{
    int i,j,n,sum;
    char a[32];
    scanf("%d",&n);
    while(n--)
    {
        scanf("%s",a);
        for(i=0;i<4;i++)
            {
                for(j=0,sum=0;j<7;j++)
                {
                    sum+=(a[j+8*i]-'0')*pow(2,7-j);
                }
                printf("%d.",sum);
            }    
            
        printf("\b \n");
    }
    return 0;
    
}
