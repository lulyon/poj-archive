#include<iostream>
#include<math.h>
using namespace std;
#define EXP 1e-6
long f[5000];
int g(double x)
{
	double flag = x-floor(x)-0.14;
	int tmp;
	if(fabs(flag)<EXP || flag>0)tmp =1;
	else tmp = 0;
	return 2*((int)ceil(x)-4)+tmp;
}
void init()
{
	f[0]=1;
	f[1]=2;
	f[2]=2;
	f[3]=3;
	f[4]=3;
	f[5]=4;
	f[6]=4;
	f[7]=6;
	for(int i=7;i<=1000;++i)
	{
		f[g(i+0.1)] = (f[g(i+0.1-1)]+f[g(i+0.1-3.14)])%1000000007;
		f[g(i+0.5)] = (f[g(i+0.5-1)]+f[g(i+0.5-3.14)])%1000000007;
		
	}
}

void output(double a)
{
	if(a<-1e-6)printf("0\n");
	else if(a-3<-1e-6)printf("1\n");
	else printf("%ld\n",f[g(a)]);
}
int main()
{
	int t;
	init();
	double a;
	cin>>t;
	while(t--)
	{
		scanf("%lf",&a);
		output(a);
	}
	//getchar();getchar();
    return 0;
    
}