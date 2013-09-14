#include<iostream>
#include<math.h>
using namespace std;
int main()
{
	double D,d,s;
	int t;
	cin>>t;
	while(t--)
	{
		scanf("%lf %lf %lf",&D,&d,&s);
		
		printf("%.0lf\n",floor(2*acos(0.000000)/asin((s+d)/(D-d))));
	}
    return 0;
}
