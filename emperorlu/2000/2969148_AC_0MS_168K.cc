#include <stdio.h>
int main()
{
    int i,j,k,n,sum;
    for(i=0;i<21;i++)
    {
        scanf("%d",&n);
        if(n==0)break;
        for(k=1;;k++)
			if(n<=k*(k+1)/2)break;
        for(j=1,sum=0;j<k;j++)
        {
            sum+=j*j;
        }
        sum+=(n-(k-1)*k/2)*k;
        printf("%d %d\n",n,sum);
    }
    return 0;
}
