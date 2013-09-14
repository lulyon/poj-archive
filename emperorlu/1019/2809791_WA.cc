#include<stdio.h>
#include<math.h>
int main()
{
    int t,n;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        for(int i=sqrt(2*n);;i--)
        {
            int tmp=n-(i+1)*i/2;            
            if(tmp>0)
            {
                printf("%d\n",tmp);
                break;
            }
        }
    }
    return 0;
}
