#include<stdio.h>
#include<math.h>
double euler[1000010],f[1000010];

int p[1000010];

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
	
	p[0]=2;
	p[1]=3;
	int top=2;
	bool flag;
	
	for(i=5;i<=1000000;++i)
	{
		flag=0;
		for(j=0;j<top&&p[j]*p[j]<i;++j)
		{
			if(i%p[j]==0)
			{
				flag=1;
				euler[i]=euler[p[j]]*euler[i/p[j]];
				break;
			}
		}
		if(flag==0)
		{
			euler[i]=i-1;
			p[top++]=i;
		}
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

