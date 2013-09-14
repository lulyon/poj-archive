#include <stdio.h>
#define PI 3.141593
#define N 10
int main()
{
    int cn=0,year,t;
    double x,y,area;
    scanf("%d",&t);
    while(t--)
    {
		cn++;
      	scanf("%lf%lf",&x,&y);
        area=(x*x+y*y)*PI/2;
       	year=area/50.0+1;
        printf("Property %d: This property will begin eroding in year %d.\n",cn,year);
	}
    printf("END OF OUTPUT.\n");
    return 0;
}

