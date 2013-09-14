#include <stdio.h>
#define PI 3.141593
#define N 10
int main()
{
    int i,j,n;
    float x[10],y[10],area;
    scanf("%d",&n);
    for(i=0;i<n;i++)
       scanf("%f%f",&x[i],&y[i]);
    for(i=0;i<n;i++)
    {  
        area=(x[i]*x[i]+y[i]*y[i])*PI/2;
       for(j=1;!(area>50.0*(j-1)&&area<=50.0*j);j++);
       printf("property %d: This property will begin eroding in year %d.\n",i+1,j);
    }
    printf("END OF OUTPUT.\n");
    return 0;
}
