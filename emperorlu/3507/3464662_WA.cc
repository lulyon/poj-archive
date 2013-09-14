#include<iostream>
#include<math.h>
using namespace std;
int main()
{
	double a,b,c,d,e,f;
	while(1)
	{
		scanf("%lf%lf%lf%lf%lf%lf",&a,&b,&c,&d,&e,&f);
		if(!a && !b && !c && !d && !e && !f)break;
		printf("%g\n",(a+b+c+d+e+f)/6.0);
	}
    return 0;
}
