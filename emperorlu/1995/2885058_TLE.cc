#include<stdio.h>
#include<math.h>
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
	int c,n,a,b;
	scanf("%d%d",&c,&n);
	int sum=0;
	int tmp,m,a1;
	for(int i=1;i<=n;i++)
	{
		scanf("%d%d",&a,&b);
		a%=c;
		a1=a;
		tmp=1;
		m=(int)(log(b)/log(2));
		for(int i=1;i<=m;i++)
			a=a*a%c;
		for(int i=1;i<=(b-(1<<m));i++)
			tmp=tmp*a1%c;
		tmp=a*tmp%c;
		sum+=tmp;
		sum%=c;
	}
	printf("%d\n",sum);
	}
	//while(1);
	return 0;
}
