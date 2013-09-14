#include<stdio.h>

int main()
{
	int n,sum,i,t;

	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		for(sum=0,i=5;i<=n;i*=5)
			sum+=n/i;
		printf("%d\n",sum);
	}

	return 0;
}

