#include<iostream>
#include<math.h>
using namespace std;
int main()
{
	double d,t,dis,v;
	int r,cn=0;
	const double pi = 3.1415927;
	while(scanf("%lf%d%lf",&d,&r,&t)!=EOF)
	{
		if(!r)break;
		dis = d*pi*r/12/5280;
		v = dis*3600/t;
		//system("pause");
		printf("Trip #%d: %.2lf %.2lf\n",++cn,dis,v);
	}
    return 0;
}
