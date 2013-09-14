#include<stdio.h>
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
	int c,n,a,b;
	scanf("%d%d",&c,&n);
	int sum=0;
	int tmp;
	for(int i=1;i<=n;i++)
	{
		scanf("%d%d",&a,&b);
		a%=c;
		tmp=1;
		for(int i=1;i<=b;i++)
		{
			tmp*=a;
			if(tmp>=c)tmp%=c;
		}
		sum+=tmp;
		sum%=c;
	}
	printf("%d\n",sum);
	}
	//while(1);
	return 0;
}
