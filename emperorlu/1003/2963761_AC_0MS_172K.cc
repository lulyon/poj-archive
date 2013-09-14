#include <stdio.h>
int main()
{
    int i,j;
    double a,sum;
    while(scanf("%lf",&a),a)
    {
        for(j=1,sum=0;;j++)
	{
            sum+=1.0/(j+1);
	    if(sum>=a)break;
	}
        printf("%d card(s)\n",j);
    }
    return 0;
}