#include<stdio.h>
#include<math.h>
int main()
{
    int t;
    __int64 n;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%I64d",&n);
        for(__int64 i=sqrt(2*n);;i--)
        {
            __int64 tmp=n-(i+1)*i/2;            
            if(tmp>0)
            {
                printf("%d\n",tmp);
                break;
            }
        }
    }
    return 0;
}
