#include <stdio.h>
#define PI 3.141593
#define N 10
int main()
{
    int i,j,n,flag=1;
    float x,y,area;
    scanf("%d",&n);
    while(n--)
    {
        scanf("%f%f",&x,&y);
        area=(x*x+y*y)*PI/2;
        for(j=1;!(area>50.0*(j-1)&&area<=50.0*j);j++);
        printf("Property %d: This property will begin eroding in year %d.\n",flag++,j);
    }
    printf("END OF OUTPUT.\n");
    return 0;
}
