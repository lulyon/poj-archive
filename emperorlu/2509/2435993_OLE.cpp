#include <stdio.h>
int main()
{
    int x,y,sum;
    while((scanf("%d",&x),x)!=EOF)
    {
        scanf("%d",&y);
        for(sum=x;x>=y;)
        {
           sum+=x/y;
           x=x%y+x/y;  
        }
        printf("%d\n",sum);
    }
    return 0;
    
}
