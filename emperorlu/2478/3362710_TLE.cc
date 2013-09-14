#include<stdio.h>
#include<math.h>
double euler[1000010],f[1000010];
void init()
{
	long i,j,m;
	f[1]=0;
	f[2]=1;
	f[3]=3;
	f[4]=5;
	euler[1]=1;
	euler[2]=1;
	euler[3]=2;
	euler[4]=2;
	for(i=5;i<=1000000;++i)
	{
		m = (long)sqrt((double)i);
		for(j=2;j<=m;++j)
		{
			if(i%j==0)
			{
				euler[i]=euler[j]*euler[i/j];
				break;
			}
		}
		if(j>m)euler[i]=i-1;
		f[i]=euler[i]+f[i-1];
	}
}
int main()
{
	long n;
	init();
	while(scanf("%ld",&n)!=EOF)
		printf("%.0lf\n",f[n]);
    return 0;
}
