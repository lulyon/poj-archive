#include <stdio.h>
#define PI 3.141593
#define N 10
int main()
{
    int cn=0,j,t;
    double x[10],y[10],area;
    scanf("%d",&t);
    while(t--)
    {
		cn++;
      	scanf("%lf%lf",x+i,y+i);
        area=(x[i]*x[i]+y[i]*y[i])*PI/2;
       	for(j=1;;j++)
	   		if(area>50.0*(j-1)&&area<=50.0*j)break;
       printf("Property %d: This property will begin eroding in year %d.\n",cn,j);
	}
    printf("END OF OUTPUT.\n");
    return 0;
}
