#include<iostream>
#include<math.h>
using namespace std;
#define pi 3.141592653589793
double f(double x1,double y1,double x2,double y2)
{
	return sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
}
int main()
{
	double x1,y1,x2,y2,x3,y3,a,b,c;
	while(scanf("%lf%lf%lf%lf%lf%lf",&x1,&y1,&x2,&y2,&x3,&y3)!=EOF)
	{
		a = f(x2,y2,x3,y3);
		b = f(x1,y1,x3,y3);
		c = f(x1,y1,x2,y2);
		
		double cosa = (b*b+c*c-a*a)/(2*b*c);
		double sina = sqrt(1-cosa*cosa);
		
		double re = a*pi/sina;
		printf("%.2lf\n",re);
		
		
	}
    return 0;
}
