#include <stdio.h>
int main()
{
    int i,j;
    float a,sum;
    while(scanf("%f",&a),a!=0)
    {
        for(j=1,sum=0;sum<=a;j++)
                sum+=1.0/(j+1);
        printf("%d card(s)\n",j-1);
    }
    return 0;
}
